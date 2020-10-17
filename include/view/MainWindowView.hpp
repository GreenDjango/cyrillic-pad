#ifndef ___VIEW_MAINWINDOWVIEW_HPP__
#define ___VIEW_MAINWINDOWVIEW_HPP__

// Qt dependencies
#include <QAction>
#include <QMainWindow>
#include <QObject>
#include <QPlainTextEdit>
#include <QWidget>

#include <memory>

class MainWindowView : public QMainWindow {
	Q_OBJECT;

public:
	// constructor / destructor
	MainWindowView(QWidget* parent = nullptr);
	~MainWindowView();

public slots:
	//// tool bar
	void updateMute();
	//// other
	void reloadCSS();
	//void sendNotify(QString const& title, QString const& msg);
	//void forceShow();
	//void onIconClick(QSystemTrayIcon::ActivationReason reason);

	// used by the controller
protected:
	QPlainTextEdit* _editor;

	// Left bar
	QAction* _actionAbout;

private:
	// methods
	void setupUI();
	void setupToolBar();

	// internal data
	QString _cssFilename;
};

#endif /* ___VIEW_MAINWINDOWVIEW_H__ */
