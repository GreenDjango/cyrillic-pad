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

protected slots:
	//// tool bar
	void updateMute();
	//// other
	void reloadCSS();

	// used by the controller
protected:
	QPlainTextEdit* _editor;
	QPlainTextEdit* _preview;

	// Left bar
	QAction* _actionOpen;
	QAction* _actionSave;
	QAction* _actionSwitch;
	QAction* _actionBold;
	QAction* _actionItalic;
	QAction* _actionAbout;

private:
	// methods
	void setupUI();
	void setupToolBar();

	// internal data
	QString _cssFilename;
};

#endif /* ___VIEW_MAINWINDOWVIEW_H__ */
