// internal dependencies
#include "controller/MainWindowController.hpp"
#include "tool/Utils.hpp"

// Qt dependencies
#include <QApplication>
#include <QLoggingCategory>

// STL dependencies
#include <iostream>

#ifndef APP_VERSION
#define APP_VERSION "0.0.0"
#endif

int main(int argc, char* argv[])
{
	//QLoggingCategory::setFilterRules(QStringLiteral("qt.* = true"));
	QApplication app(argc, argv);

	// Meta
	QCoreApplication::setOrganizationName("GreenDjango");
	QCoreApplication::setApplicationName("Cyrillic Pad");
	QCoreApplication::setApplicationVersion(APP_VERSION);
	//qRegisterMetaType<User>();
	//qRegisterMetaType<Message>();

	// Create custom main window
	MainWindowController mainWin {};
	mainWin.show();

	// run the applications
	return app.exec();
}
