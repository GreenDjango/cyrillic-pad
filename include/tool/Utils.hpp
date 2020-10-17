#ifndef ___TOOL_STYLELOAD_HPP__
#define ___TOOL_STYLELOAD_HPP__

// Qt dependencies
#include <QString>
#include <QDateTime>
#include <QIcon>

class Utils {
public:
	enum logLevel {
		CRITICAL,
		WARNING,
		NOTICE,
		DEBUG
	};
	static QString loadCSS(const QString& pathname);
	static QString getAbs(const QString& path);
	static void syslog(Utils::logLevel loglevel, std::string const& module, std::string const& message);
	static int randInt(int min, int max);
	static QDateTime strToDate(QString const& time);
	static QIcon prepareIcon(QString path, int w, int h);
};

#endif /* ___TOOL_STYLELOAD_H__ */
