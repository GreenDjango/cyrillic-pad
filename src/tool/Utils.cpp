#include "tool/Utils.hpp"

// Qt dependencies
#include <QCoreApplication>
#include <QDebug>
#include <QFileInfo>
#include <QPainter>
#include <QSvgRenderer>

// STL dependencies
#include <chrono>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <random>

//
// load a CSS file based on the absolute path
// TODO
// * handle internal modification (like debug)
// * close the file !
//
QString Utils::loadCSS(const QString& pathname)
{
	// generate the absolute path
	const QString absPathname { QCoreApplication::applicationDirPath() + "/css/" + pathname };

	const QFileInfo cssFile(absPathname);
	if ((!cssFile.exists()) || cssFile.isDir() || (!cssFile.isWritable())) {
		qWarning() << "unable to load the css at" << cssFile.absoluteFilePath();
		return {};
	}

	// open / read the CSS file
	std::ifstream ifs(absPathname.toStdString(), std::ios::in | std::ios::binary | std::ios::ate);
	std::ifstream::pos_type fileSize = ifs.tellg();
	ifs.seekg(0, std::ios::beg);
	std::vector<char> bytes(fileSize);
	ifs.read(bytes.data(), fileSize);
	//TODO: /!\ close the file

	// return the content of the file
	return { QString::fromStdString(std::string(bytes.data(), fileSize)) };
}

//
// Generate the relavtive path
//
QString Utils::getAbs(const QString& path)
{
	return { QCoreApplication::applicationDirPath() + "/" + path };
}

void Utils::syslog(Utils::logLevel loglevel, std::string const& module, std::string const& message)
{
#ifndef QT_DEBUG
	if (loglevel == Utils::logLevel::NOTICE || loglevel == Utils::logLevel::DEBUG)
		return;
#endif
	auto time = std::time(nullptr);

	std::cout << std::put_time(std::localtime(&time), "\033[0;32m[%T]\033[0m ")
		  << "\033[0;35m" << module << ":\033[0m ";

	if (loglevel == Utils::logLevel::CRITICAL)
		std::cout << "\033[1;31m";
	if (loglevel == Utils::logLevel::WARNING)
		std::cout << "\033[1;33m";
	if (loglevel == Utils::logLevel::NOTICE)
		std::cout << "\033[1m";
	if (loglevel == Utils::logLevel::DEBUG)
		std::cout << "\033[90m";
	std::cout << message << "\033[0m\n";
}

int Utils::randInt(int min, int max)
{
	static std::default_random_engine generator(std::chrono::system_clock::now().time_since_epoch().count());
	std::uniform_int_distribution<int> distribution(min, max);

	return distribution(generator);
}

QDateTime Utils::strToDate(QString const& time)
{
	QDateTime localTime = QDateTime::fromString(time, "yyyy-MM-dd hh:mm:ss");
	localTime.setTimeSpec(Qt::UTC);

	return localTime.toLocalTime();
}

QIcon Utils::prepareIcon(QString path, int w, int h)
{
#ifdef Q_OS_LINUX

	QString desktop = getenv("XDG_CURRENT_DESKTOP");
	if (desktop.isEmpty()) {
		desktop = getenv("DESKTOP_SESSION");
	}

	desktop = desktop.toLower();
	if (desktop == "xfce" || desktop.contains("gnome") || desktop == "mate" || desktop == "x-cinnamon") {
		if (w > 0 && h > 0) {
			QSvgRenderer renderer(path);

			QPixmap pm(w, h);
			pm.fill(Qt::transparent);
			QPainter painter(&pm);
			renderer.render(&painter, pm.rect());

			return QIcon(pm);
		}
	}
#endif
	return QIcon(path);
}