#ifndef FILE_H
#define FILE_H
#include <QJsonDocument>

QJsonDocument readFile(QString fileName);
void writeFile(QString fileName, QJsonDocument& doc);
bool fileExists(QString path);
void createFileIfNotExist(QString path);

QJsonObject getObject(const QString& fileName, const QString& identifier);
void saveObject(const QString& fileName, const QString& identifier, QJsonObject obj);
void removeObject(const QString& fileName, const QString& identifier);
bool existsObject(const QString& fileName, const QString& identifier);
int countOfObjects(const QString& fileName);

#endif // FILE_H
