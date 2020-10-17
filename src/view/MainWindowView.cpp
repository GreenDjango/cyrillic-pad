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
	auto path = "assets/icons/audio_input_micro.svg";
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
	setObjectName("MainWindow");

	setWindowIcon(QIcon { Utils::getAbs("assets/logo.svg") });

	// https://doc.qt.io/qt-5/qtwidgets-widgets-codeeditor-example.html
	QPlainTextEdit* _editor = new QPlainTextEdit {};

	setCentralWidget(_editor);
	_editor->setFocus();
}

void MainWindowView::setupToolBar()
{
	QToolBar* toolBar = new QToolBar {};

	_actionAbout = new QAction(QIcon(Utils::getAbs("assets/icons/info-circle-fill.svg")), "About...");
	//toolBar->addAction(_action_info);
	//toolBar->addSeparator();
	//toolBar->addAction(_action_mute);
	//toolBar->addAction(_action_deafen);
	//toolBar->addSeparator();
	//toolBar->addAction(_action_message);
	//toolBar->addSeparator();
	toolBar->addAction(_actionAbout);

	// add the tool bar
	addToolBar(Qt::LeftToolBarArea, toolBar);
}