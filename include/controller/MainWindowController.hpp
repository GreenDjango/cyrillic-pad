#ifndef ___CONTROLLER_MAINWINDOW_HPP__
#define ___CONTROLLER_MAINWINDOW_HPP__

// internal dependencies
#include "view/MainWindowView.hpp"

// internal Qt dependencies
#include <QObject>
#include <QString>

// define the "main window" controller class
class MainWindowController : public MainWindowView {
	Q_OBJECT;

public:
	// constructor / destructor
	MainWindowController(QWidget* parent = nullptr);
	~MainWindowController() = default;
	void openFile(QString path);

	// getter / setter
	const MainWindowView* getView() const;

private slots:
	void actionOpen();
	void actionSave();
	void actionSwitch();
	void actionAbout();

	void onTextUpdate();

private:
	QString _savePath;
};

#endif /* ___CONTROLLER_MAINWINDOW_H__ */
