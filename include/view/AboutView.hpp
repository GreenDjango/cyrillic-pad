#ifndef ___VIEW_ABOUTVIEW_HPP__
#define ___VIEW_ABOUTVIEW_HPP__

// Qt dependencies
#include <QDialog>

class AboutView : public QDialog {

public:
	AboutView(QWidget* parent = nullptr, const QString& title = "");
	~AboutView();
};

#endif /* ___VIEW_ABOUTVIEW_HPP__ */
