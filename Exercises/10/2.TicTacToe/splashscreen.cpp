#include "splashscreen.h"
#include "ui_splashscreen.h"
#include "mainwindow.h"
#include <QInputDialog>
#include "history.h"

SplashScreen::SplashScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SplashScreen)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Widget | Qt::MSWindowsFixedSizeDialogHint);
}

SplashScreen::~SplashScreen()
{
    delete ui;
}

void SplashScreen::on_soloPlayButton_clicked()
{
    bool ok;
    QString playerName = QInputDialog::getText(this, tr("Player Name"),
                                               tr("Your name:"), QLineEdit::Normal, "", &ok);

    if(!ok || playerName.isEmpty())
        return;
    MainWindow* mainWindow = new MainWindow(playerName);
    mainWindow->show();
    this->close();
}

void SplashScreen::on_multiPlayButton_clicked()
{
    bool ok;
    QString player1 = QInputDialog::getText(this, tr("Player Name"),
                                            tr("First player:"), QLineEdit::Normal, "", &ok);
    if(!ok || player1.isEmpty())
        return;

    ok = false;
    QString player2 = QInputDialog::getText(this, tr("Player Name"),
                                            tr("Second player:"), QLineEdit::Normal, "", &ok);
    if(!ok || player2.isEmpty())
        return;

    MainWindow* mainWindow = new MainWindow(player1, player2);
    mainWindow->show();
    this->close();
}

void SplashScreen::on_historyButton_clicked()
{
    history* historyForm = new history(this);
    historyForm->exec();
}
