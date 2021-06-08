#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QString player1,
               QString player2 = "Robot",
               QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_board_clicked();

    void on_actionRestart_Round_triggered();

    void on_actionMain_Menu_triggered();

    void on_actionNew_game_triggered();

private:
    static constexpr int winPatterns[8][3][2]{
        {{0,0}, {0,1}, {0,2}},
        {{1,0}, {1,1}, {1,2}},
        {{2,0}, {2,1}, {2,2}},
        {{0,0}, {1,0}, {2,0}},
        {{0,1}, {1,1}, {2,1}},
        {{0,2}, {1,2}, {2,2}},
        {{0,0}, {1,1}, {2,2}},
        {{0,2}, {1,1}, {2,0}}
    };

    void initConnections();
    Ui::MainWindow *ui;
    int player1Wins = 0;
    int player2Wins = 0;
    void addPlayer1Wins();
    void addPlayer2Wins();
    void setWinsLabel();
    bool checkWin();
    int Board[3][3] = {};
    int turn = 1;
    QString player1;
    QString player2;
    void setPlayersName();
    void changeTurn();
    int checkFinished();
    int winner = 0; //1,2,3:draw
    int counter = 0;
    bool singlePlayer = true;
    int minimax(int board[][3], int depth, bool isAI);
    int bestMove(int board[][3], int moveIndex);
    void machinePlay();
    void resetSettings();
};
#endif // MAINWINDOW_H
