// internal dependencies
#include "view/AboutView.hpp"
#include "tool/Utils.hpp"

// Qt dependencies
#include <QApplication>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QTabWidget>
#include <QTextBrowser>
#include <QVBoxLayout>

// STL dependencies
#include <iostream>

AboutView::AboutView(QWidget* parent, const QString& title)
    : QDialog { parent }
{
	setWindowTitle(title.isEmpty() ? "About Cyrillic Pad" : title);
	setObjectName("AboutBabel");
	setStyleSheet(Utils::loadCSS(QString { "about.css" }));

	// About
	QLabel* icon = new QLabel {};
	QIcon img    = Utils::prepareIcon(Utils::getAbs("assets/logo.svg"), 128, 128);
	icon->setPixmap(img.pixmap(128, 128));

	QLabel* blabla = new QLabel {};
	blabla->setTextInteractionFlags(Qt::TextSelectableByMouse);
	blabla->setOpenExternalLinks(true);
	blabla->setText(
	    "<h3>Cyrillic Pad v" + QApplication::applicationVersion() + "</h3>"
									"<p><b>Text Editor for French/Cyrillic language</b></p>");

	QHBoxLayout* qhbl = new QHBoxLayout {};
	qhbl->addWidget(icon);
	qhbl->addWidget(blabla);

	QWidget* about = new QWidget {};
	about->setLayout(qhbl);

	// Authors
	QTextBrowser* authors = new QTextBrowser;
	authors->append(QString {
	    "<center>"
	    "<p><b>Theo C.</b><br>aka @GreenDjango</p>"
	    "</center>" });
	authors->setReadOnly(true);

	// License
	QTextBrowser* license = new QTextBrowser;
	license->append(QString {
	    "<center>"
	    "<p><b>license</b></p>"
	    "</center>" });
	license->setReadOnly(true);

	// About Qt
	QPushButton* aboutQtBtn = new QPushButton { "About Qt" };
	aboutQtBtn->setSizePolicy({ QSizePolicy::Maximum, QSizePolicy::Maximum });
	connect(aboutQtBtn, SIGNAL(clicked()), qApp, SLOT(aboutQt()));
	QVBoxLayout* qvbl = new QVBoxLayout {};
	qvbl->addWidget(aboutQtBtn);
	qvbl->setAlignment(Qt::AlignCenter);

	QWidget* aboutQt = new QWidget;
	aboutQt->setLayout(qvbl);

	QTabWidget* table = new QTabWidget {};
	table->addTab(about, "About Babel");
	table->addTab(authors, "Authors");
	table->addTab(license, "License");
	table->addTab(aboutQt, "About Qt");

	QPushButton* okButton = new QPushButton { "OK" };
	connect(okButton, SIGNAL(clicked()), this, SLOT(accept()));

	// Setup the layout
	QVBoxLayout* mainLayout = new QVBoxLayout {};
	mainLayout->addWidget(table);
	mainLayout->addWidget(okButton);
	setLayout(mainLayout);
}

AboutView::~AboutView() {}