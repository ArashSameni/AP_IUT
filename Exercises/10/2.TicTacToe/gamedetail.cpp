#include "gamedetail.h"
#include "file.h"
#include <QJsonObject>

const QString GameDetail::FILENAME = "history.json";
int GameDetail::count = 0;

GameDetail::GameDetail(QString player1, QString player2, int status)
{
    this->player1 = player1;
    this->player2 = player2;
    this->status = status;
}

void GameDetail::save()
{
    if(!id)
        id = ++count;

    QJsonObject obj;
    obj["player1"] = this->player1;
    obj["player2"] = this->player2;
    obj["status"] = this->status;

    saveObject(FILENAME, QString::number(id), obj);
}

GameDetail GameDetail::get(QJsonObject &obj)
{
    GameDetail detail(obj["player1"].toString(),
                      obj["player2"].toString(),
                      obj["status"].toInt());

    detail.id = obj["id"].toInt();
    return detail;
}

QVector<GameDetail> GameDetail::getAll()
{
    QVector<GameDetail> allGameDetails;
    QJsonObject obj = readFile(FILENAME).object();
    foreach(QJsonValue val, obj)
    {
        QJsonObject temp = val.toObject();
        allGameDetails.push_back(get(temp));
    }

    return allGameDetails;
}

