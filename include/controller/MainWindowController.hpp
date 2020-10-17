#ifndef ___CONTROLLER_MAINWINDOW_HPP__
# define ___CONTROLLER_MAINWINDOW_HPP__

// internal dependencies
#include "view/MainWindowView.hpp"

// internal Qt dependencies
#include <QObject>

// define the "main window" controller class
class MainWindowController : public MainWindowView
{
	Q_OBJECT;

	public:
		// constructor / destructor
		MainWindowController(QWidget *parent = nullptr);
		~MainWindowController() = default;

		// getter / setter
		//const MainWindowView *getView() const;

	public slots:
		void actionAbout();
};

#endif /* ___CONTROLLER_MAINWINDOW_H__ */
