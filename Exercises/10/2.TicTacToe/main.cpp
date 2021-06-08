#include "splashscreen.h"
#include "file.h"
#include "gamedetail.h"
#include <QApplication>

void Initialize();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SplashScreen w;
    w.show();
    return a.exec();
}

void Initialize()
{
    createFileIfNotExist(GameDetail::fileName());
    GameDetail::count = countOfObjects(GameDetail::fileName());
}
