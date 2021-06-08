#include "history.h"
#include "ui_history.h"
#include "gamedetail.h"
#include <QVector>

history::history(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::history)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    QVector<GameDetail> details = GameDetail::getAll();
    int i = 0;
    foreach (GameDetail detail, details)
    {
        QTableWidgetItem* player1Item = new QTableWidgetItem(detail.getPlayer1());
        QTableWidgetItem* player2Item = new QTableWidgetItem(detail.getPlayer2());

        QTableWidgetItem* statusItem = nullptr;
        if(detail.getStatus() == game_winner::Player1)
            statusItem = new QTableWidgetItem(detail.getPlayer1());
        else if(detail.getStatus() == game_winner::Player2)
            statusItem = new QTableWidgetItem(detail.getPlayer2());
        else
            statusItem = new QTableWidgetItem("Draw");

        ui->historyTable->insertRow(i);
        ui->historyTable->setItem(i, 0, player1Item);
        ui->historyTable->setItem(i, 1, player2Item);
        ui->historyTable->setItem(i, 2, statusItem);
    }
}

history::~history()
{
    delete ui;
}
