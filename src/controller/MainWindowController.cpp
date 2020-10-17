#include "controller/MainWindowController.hpp"
#include "view/AboutView.hpp"

// Qt dependencies
#include <QAction>
#include <QApplication>
#include <QInputDialog>
#include <QMessageBox>

//---
// Constructor / destructor
//---
MainWindowController::MainWindowController(QWidget* parent)
    : MainWindowView { parent }
{
	connect(_actionAbout, &QAction::triggered, this, &MainWindowController::actionAbout);
	// connect the "menu bar"
	//connect(_actionConnect, &QAction::triggered, this, &MainWindowController::control_connect);
	//connect(_action_about, &QAction::triggered, this, &MainWindowView::popup_about);
	//connect(_action_aboutqt, &QAction::triggered, qApp, &QApplication::aboutQt);

	// connect the "tool bar"
	//connect(_action_connect, &QAction::triggered, this, &MainWindowController::control_connect);
	//connect(_action_mute, &QAction::triggered, this, &MainWindowController::control_mute);
	//connect(_action_deafen, &QAction::triggered, this, &MainWindowController::control_deafen);
	//connect(_action_message, &QAction::triggered, this, &MainWindowController::control_message);

	//connect(server.get(), &Requester::error, this, &MainWindowController::showServerError);
	//connect(server.get(), &Requester::newFriend, this, &MainWindowController::onNewFriend);
	//connect(server.get(), &Requester::newMsg, this, &MainWindowController::onNewMessage);
}

/*
//---
// Getter / setter
//---
const MainWindowView* MainWindowController::getView() const
{
	return { this };
}
*/
// public slots
void MainWindowController::actionAbout()
{
	AboutView about { this };
	about.exec();
}
/*
void MainWindowController::control_mute()
{
	//TODO: mute audio actions
	_mute = (_mute) ? false : true;

	// Update the view part
	emit { this->updateMute(); };
}

void MainWindowController::control_deafen()
{
	//TODO: deafen audio actions
	_deafen = (_deafen) ? false : true;

	// Update the view part
	emit { this->updateDeafen(); };
}

void MainWindowController::control_message()
{
	if (!_hasSysTray) return;
	_noNotif = (_noNotif) ? false : true;

	// Update the view part
	updateNotif();
}

void MainWindowController::showServerError(QString const& error)
{
	QMessageBox::warning(this, "Server", error);
}

void MainWindowController::onNewFriend(User const& user)
{
	sendNotify("New friend!", QString::fromStdString(user.get_login()) + " is now your friend");
}

void MainWindowController::onNewMessage(Message const& msg)
{
	sendNotify(QString::fromStdString("@" + msg.getAuthor()), QString::fromStdString(msg.getData()));
}*/