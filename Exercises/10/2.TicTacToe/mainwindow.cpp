#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "splashscreen.h"
#include <QDebug>
#include "gamedetail.h"

MainWindow::MainWindow(QString player1, QString player2, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint);
    initConnections();
    ui->player1Label->setStyleSheet("font-weight: bold;");
    this->player1 = player1;
    this->player2 = player2;
    if (player2 != "Robot")
        singlePlayer = false;

    setPlayersName();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setPlayersName()
{
    ui->player1Label->setText(player1);
    ui->player2Label->setText(player2);

    ui->player1Label->adjustSize();
    ui->player2Label->adjustSize();
    ui->player2Label->move(390 - ui->player2Label->width(), 50);
}

void MainWindow::changeTurn()
{
    if (turn == 1)
        turn = 2;
    else
        turn = 1;

    if (turn == 2)
    {
        ui->player1Label->setStyleSheet("");
        ui->player2Label->setStyleSheet("#player2Label{ font-weight: bold; }");
        ui->player2Label->adjustSize();
        ui->player2Label->move(390 - ui->player2Label->width(), 50);
    }
    else
    {
        ui->player1Label->setStyleSheet("#player1Label{ font-weight: bold; }");
        ui->player2Label->setStyleSheet("");
        ui->player2Label->adjustSize();
        ui->player2Label->move(390 - ui->player2Label->width(), 50);
    }
}

void MainWindow::on_board_clicked()
{
    if (!winner)
    {
        QPushButton *theButton = (QPushButton *)sender();
        if (theButton->text().isEmpty())
        {
            counter++;
            if (turn == 1)
            {
                theButton->setText("X");
                Board[theButton->property("Y").toInt()][theButton->property("X").toInt()] = 1;
            }
            else
            {
                theButton->setText("O");
                Board[theButton->property("Y").toInt()][theButton->property("X").toInt()] = 2;
            }
            if(!checkWin())
            {
                if(singlePlayer)
                    machinePlay();
                else
                    changeTurn();
            }
        }
    }
}

void MainWindow::initConnections()
{
    connect(ui->board_00, &QPushButton::clicked, this, &MainWindow::on_board_clicked);
    connect(ui->board_01, &QPushButton::clicked, this, &MainWindow::on_board_clicked);
    connect(ui->board_02, &QPushButton::clicked, this, &MainWindow::on_board_clicked);
    connect(ui->board_10, &QPushButton::clicked, this, &MainWindow::on_board_clicked);
    connect(ui->board_11, &QPushButton::clicked, this, &MainWindow::on_board_clicked);
    connect(ui->board_12, &QPushButton::clicked, this, &MainWindow::on_board_clicked);
    connect(ui->board_20, &QPushButton::clicked, this, &MainWindow::on_board_clicked);
    connect(ui->board_21, &QPushButton::clicked, this, &MainWindow::on_board_clicked);
    connect(ui->board_22, &QPushButton::clicked, this, &MainWindow::on_board_clicked);
}

void MainWindow::addPlayer1Wins()
{
    player1Wins++;
    setWinsLabel();
}

void MainWindow::addPlayer2Wins()
{
    player2Wins++;
    setWinsLabel();
}

void MainWindow::setWinsLabel()
{
    ui->winsLabel->setText(QString::number(player1Wins) + " - " + QString::number(player2Wins));
}

int MainWindow::checkFinished()
{
    for (int i = 0; i < 8; i++)
    {
        auto const &line = winPatterns[i];
        const int a = Board[line[0][0]][line[0][1]];
        const int b = Board[line[1][0]][line[1][1]];
        const int c = Board[line[2][0]][line[2][1]];
        if (a == b && b == c)
            return a;
    }
    if (counter == 9)
        return 3;

    return 0;
}

bool MainWindow::checkWin()
{
    winner = checkFinished();
    if (winner)
    {
        QMessageBox *msg = new QMessageBox(this);
        msg->setWindowTitle("Round Finished!");
        if (winner == 1)
        {
            msg->setText("Yeahhhh, " + player1 + " Won!");
            addPlayer1Wins();
        }
        else if (winner == 2)
        {
            msg->setText("Yeahhhh, " + player2 + " Won!");
            addPlayer2Wins();
        }
        else
            msg->setText("Game draw!");
        msg->exec();

        GameDetail gd(player1, player2, winner - 1);
        gd.save();

        resetSettings();
        return 1;
    }
    return 0;
}

int MainWindow::minimax(int board[][3], int depth, bool isAI)
{
    const int HUMANMOVE = 1;
    const int COMPUTERMOVE = 2;
    const int SIDE = 3;
    int score = 0;
    int bestScore = 0;
    if (checkFinished())
    {
        if (isAI == true)
            return -1;
        if (isAI == false)
            return +1;
    }
    else
    {
        if (depth < 9)
        {
            if (isAI == true)
            {
                bestScore = -999;
                for (int i = 0; i < SIDE; i++)
                {
                    for (int j = 0; j < SIDE; j++)
                    {
                        if (board[i][j] == 0)
                        {
                            board[i][j] = COMPUTERMOVE;
                            score = minimax(board, depth + 1, false);
                            board[i][j] = 0;
                            if (score > bestScore)
                            {
                                bestScore = score;
                            }
                        }
                    }
                }
                return bestScore;
            }
            else
            {
                bestScore = 999;
                for (int i = 0; i < SIDE; i++)
                {
                    for (int j = 0; j < SIDE; j++)
                    {
                        if (board[i][j] == 0)
                        {
                            board[i][j] = HUMANMOVE;
                            score = minimax(board, depth + 1, true);
                            board[i][j] = 0;
                            if (score < bestScore)
                            {
                                bestScore = score;
                            }
                        }
                    }
                }
                return bestScore;
            }
        }
        else
        {
            return 0;
        }
    }
}

int MainWindow::bestMove(int board[][3], int moveIndex)
{
    const int COMPUTERMOVE = 2;
    int x = -1, y = -1;
    int score = 0, bestScore = -999;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == 0)
            {
                board[i][j] = COMPUTERMOVE;
                score = minimax(board, moveIndex + 1, false);
                board[i][j] = 0;
                if (score > bestScore)
                {
                    bestScore = score;
                    x = i;
                    y = j;
                }
            }
        }
    }
    return x * 3 + y;
}

void MainWindow::machinePlay()
{
    int bm = bestMove(Board, counter);
    int x = bm / 3;
    int y = bm % 3;
    Board[x][y] = 2;
    if(x == 0)
    {
        if(y == 0)
            ui->board_00->setText("O");
        else if(y == 1)
            ui->board_01->setText("O");
        else if(y == 2)
            ui->board_02->setText("O");
    }
    else if(x == 1)
    {
        if(y == 0)
            ui->board_10->setText("O");
        else if(y == 1)
            ui->board_11->setText("O");
        else if(y == 2)
            ui->board_12->setText("O");
    }
    else if(x == 2)
    {
        if(y == 0)
            ui->board_20->setText("O");
        else if(y == 1)
            ui->board_21->setText("O");
        else if(y == 2)
            ui->board_22->setText("O");
    }
    counter++;
    checkWin();
}

void MainWindow::resetSettings()
{
    counter = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            Board[i][j] = 0;

    ui->board_00->setText("");
    ui->board_01->setText("");
    ui->board_02->setText("");
    ui->board_10->setText("");
    ui->board_11->setText("");
    ui->board_12->setText("");
    ui->board_20->setText("");
    ui->board_21->setText("");
    ui->board_22->setText("");
    winner = 0;
}

void MainWindow::on_actionRestart_Round_triggered()
{
    resetSettings();
}

void MainWindow::on_actionMain_Menu_triggered()
{
    SplashScreen* ss = new SplashScreen;
    ss->show();
    this->close();
}

void MainWindow::on_actionNew_game_triggered()
{
    player1Wins = 0;
    player2Wins = 0;
    setWinsLabel();
    resetSettings();
}
