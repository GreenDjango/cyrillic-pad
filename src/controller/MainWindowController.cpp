#include "controller/MainWindowController.hpp"
#include "view/AboutView.hpp"

// Qt dependencies
#include <QAction>
#include <QApplication>
#include <QDir>
#include <QFileDialog>
#include <QInputDialog>
#include <QMessageBox>
#include <QRegularExpression>
#include <QTextBlock>

#include <iostream>

MainWindowController::MainWindowController(QWidget* parent)
    : MainWindowView { parent }
{
	connect(_actionOpen, &QAction::triggered, this, &MainWindowController::actionOpen);
	connect(_actionSave, &QAction::triggered, this, &MainWindowController::actionSave);
	connect(_actionSwitch, &QAction::triggered, this, &MainWindowController::actionSwitch);
	connect(_actionAbout, &QAction::triggered, this, &MainWindowController::actionAbout);

	connect(_editor, &QPlainTextEdit::textChanged, this, &MainWindowController::onTextUpdate);
}

void MainWindowController::openFile(QString path)
{
	QFile file(path);
	if (!file.open(QIODevice::ReadOnly)) {
		QMessageBox::information(this, "Unable to open file", file.errorString());
		return;
	}
	_savePath = path;
	QDataStream in(&file);
	QByteArray data;
	//in.setVersion(QDataStream::Qt_4_5);
	in >> data;

	_editor->setPlainText(QString::fromUtf8(data));
	_editor->moveCursor(QTextCursor::MoveOperation::End);
}

// Getter / setter
const MainWindowView* MainWindowController::getView() const
{
	return { this };
}

// public slots
void MainWindowController::actionOpen()
{
	QString fileName = QFileDialog::getOpenFileName(this,
	    "Open file", "",
	    "Cyrillic Pad files (*.cyp);;All Files (*)");

	if (fileName.isEmpty())
		return;

	QFile file(fileName);
	if (!file.open(QIODevice::ReadOnly)) {
		QMessageBox::information(this, "Unable to open file", file.errorString());
		return;
	}
	_savePath = fileName;
	QDataStream in(&file);
	QByteArray data;
	//in.setVersion(QDataStream::Qt_4_5);
	in >> data;

	_editor->setPlainText(QString::fromUtf8(data));
	_editor->moveCursor(QTextCursor::MoveOperation::End);
}

void MainWindowController::actionSave()
{
	if (_savePath.isEmpty()) {
		QString fileName = QFileDialog::getSaveFileName(this,
		    "Save file", "",
		    "Cyrillic Pad files (*.cyp);;All Files (*)");
		if (fileName.isEmpty())
			return;
		_savePath = fileName;
	}
	QFile file(_savePath);
	if (!file.open(QIODevice::WriteOnly)) {
		_savePath = "";
		QMessageBox::information(this, "Unable to open file", file.errorString());
		return;
	}
	QDataStream out(&file);
	// out.setVersion(QDataStream::Qt_4_5);
	out << _editor->toPlainText().toUtf8();
}

void MainWindowController::actionSwitch()
{
	_editor->setPlainText(_preview->toPlainText());
}

void MainWindowController::actionAbout()
{
	AboutView about { this };
	about.exec();
}

void MainWindowController::onTextUpdate()
{
	QString txt = _editor->toPlainText();

	const char* patterns[4] = { "a", "b", "v", NULL };
	QString cyri { "абвгдеёжзийклмнопрстуфхцчшщъыьэюя" };

	for (int i = 0; patterns[i] != NULL; i++) {
		QString tmp = "";
		while (tmp != txt) {
			QRegularExpression re("(\\*.*)" + QString(patterns[i]) + "(.*\\*)");
			tmp = txt;
			txt.replace(re, "\\1" + cyri[i] + "\\2");
		}
	}
	QRegularExpression re("\\*\\s*(\\S.*?)\\s*\\*");
	txt = txt.replace(re, "'\\1'");

	_preview->setPlainText(txt);
}