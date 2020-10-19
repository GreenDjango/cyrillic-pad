// internal dependencies
#include "view/MainWindowView.hpp"
#include "tool/Utils.hpp"

// Qt dependencies
#include <QAction>
#include <QApplication>
#include <QDialog>
#include <QHBoxLayout>
#include <QLabel>
#include <QMenu>
#include <QMenuBar>
#include <QMessageBox>
#include <QPushButton>
#include <QScreen>
#include <QSplitter>
#include <QTextBrowser>
#include <QToolBar>

// STL dependencies
#include <iostream>

MainWindowView::MainWindowView(QWidget* parent)
    : QMainWindow { parent }
{
	//_mute	    = false;

	// setup the user interface
	setupToolBar();
	setupUI();

	// apply the CSS
	_cssFilename = "mainwindow.css";
	reloadCSS();
}

MainWindowView::~MainWindowView() {}

//---
// Public slot
//---
void MainWindowView::updateMute()
{
	// get the appropriate icon
	//auto path = "assets/icons/audio_input_micro.svg";
	//if (_mute == true)
	//	path = "assets/icons/audio_input_micro_muted.svg";

	// update the icon
	//_action_mute->setIcon(QIcon(Utils::getAbs(path)));
}

void MainWindowView::reloadCSS()
{
	setStyleSheet(Utils::loadCSS(_cssFilename));
}

//---
// private methods
//---
void MainWindowView::setupUI()
{
	setObjectName("mainWindow");

	setWindowIcon(QIcon { Utils::getAbs("assets/logo.svg") });

	// https://doc.qt.io/qt-5/qtwidgets-widgets-codeeditor-example.html
	_editor = new QPlainTextEdit {};
	_editor->setObjectName("mainEditor");

	_preview = new QPlainTextEdit {};
	_preview->setObjectName("mainPreview");
	_preview->setReadOnly(true);

	// create the main splitter
	QSplitter* mainSplitter = new QSplitter {};
	mainSplitter->setMouseTracking(true);
	mainSplitter->setOrientation(Qt::Vertical);

	mainSplitter->addWidget(_editor);
	mainSplitter->addWidget(_preview);

	setCentralWidget(mainSplitter);
	move(QGuiApplication::screens().at(0)->geometry().center() - frameGeometry().center());
	_editor->setFocus();
}

void MainWindowView::setupToolBar()
{
	QToolBar* toolBar = new QToolBar {};

	_actionOpen   = new QAction(QIcon(Utils::getAbs("assets/icons/journal-plus.svg")), "Open document");
	_actionSave   = new QAction(QIcon(Utils::getAbs("assets/icons/journal-arrow-down.svg")), "Save document");
	_actionSave->setShortcut(QKeySequence::Save);
	_actionSwitch = new QAction(QIcon(Utils::getAbs("assets/icons/arrows-collapse.svg")), "Apply preview");
	_actionBold   = new QAction(QIcon(Utils::getAbs("assets/icons/type-bold.svg")), "Bold selection");
	_actionItalic = new QAction(QIcon(Utils::getAbs("assets/icons/type-italic.svg")), "Italic selection");
	_actionAbout  = new QAction(QIcon(Utils::getAbs("assets/icons/life-preserver.svg")), "About...");

	toolBar->addAction(_actionOpen);
	toolBar->addAction(_actionSave);
	toolBar->addAction(_actionSwitch);
	toolBar->addSeparator();
	toolBar->addAction(_actionBold);
	toolBar->addAction(_actionItalic);
	toolBar->addSeparator();
	toolBar->addAction(_actionAbout);

	addToolBar(Qt::LeftToolBarArea, toolBar);
}