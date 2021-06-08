#include <QFile>
#include <QFileInfo>
#include <QJsonObject>
#include "file.h"

QJsonDocument readFile(QString fileName)
{
    QFile file(fileName);
    file.open(QIODevice::ReadOnly);
    QByteArray byteArray = file.readAll();
    file.close();
    return QJsonDocument::fromJson(byteArray);
}

void writeFile(QString fileName, QJsonDocument &doc)
{
    QFile file(fileName);
    file.open(QFile::WriteOnly | QFile::Truncate);
    file.write(doc.toJson());
    file.close();
}

bool fileExists(QString path)
{
    QFileInfo check_file(path);

    if (check_file.exists() && check_file.isFile())
        return true;
    else
        return false;
}

void createFileIfNotExist(QString path)
{
    if (!fileExists(path))
    {
        QFile file(path);
        file.open(QIODevice::WriteOnly);
        file.close();
    }
}


QJsonObject getObject(const QString& fileName, const QString& identifier)
{
    QJsonObject fileObj = readFile(fileName).object();
    if (fileObj.contains(identifier))
        return fileObj[identifier].toObject();
}

void saveObject(const QString& fileName, const QString& identifier, QJsonObject obj)
{
    QJsonDocument doc = readFile(fileName);
    QJsonObject fileObj = doc.object();
    fileObj[identifier] = obj;
    doc.setObject(fileObj);
    writeFile(fileName, doc);
}

void removeObject(const QString& fileName, const QString& identifier)
{
    QJsonDocument doc = readFile(fileName);
    QJsonObject fileObj = doc.object();
    if (fileObj.contains(identifier))
    {
        fileObj.remove(identifier);
        doc.setObject(fileObj);
        writeFile(fileName, doc);
    }
}

bool existsObject(const QString& fileName, const QString& identifier)
{
    QJsonObject fileObj = readFile(fileName).object();
    return fileObj.contains(identifier);
}

int countOfObjects(const QString& fileName)
{
    int max = 0;
    QStringList keys = readFile(fileName).object().keys();
    int key;
    foreach(QString num, keys)
    {
        key = num.toInt();
        if (key > max)
            max = key;
    }
    return max;
}
