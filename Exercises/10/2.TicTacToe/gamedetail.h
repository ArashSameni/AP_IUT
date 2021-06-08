#ifndef GAMEDETAIL_H
#define GAMEDETAIL_H

#include <QString>
#include <QVector>
#include <QJsonObject>

enum game_winner { Player1, Player2, Draw};

class GameDetail
{
    static const QString FILENAME;

    int id = 0;
    QString player1;
    QString player2;
    int status;
public:
    static int count;
    static QString fileName(){ return FILENAME; }
    GameDetail(QString player1, QString player2, int status);
    QString getPlayer1(){ return player1; }
    QString getPlayer2(){ return player2; }
    int getStatus(){ return status; }

    void save();
    static GameDetail get(QJsonObject& obj);
    static QVector<GameDetail> getAll();
};

#endif // GAMEDETAIL_H
