#ifndef CUSTOMFONT_H
#define CUSTOMFONT_H

#include <QMap>
class QFont;
class QString;
class CustomFont
{
public:
    static QFont getCustomFont(const QString &fontName, int pointSize = -1, int weight = -1, bool italic = false);

private:
	static void initData();

private:
	static QMap<QString, QString> map_localFontName_path_;
};
#endif // CUSTOMFONT_H
