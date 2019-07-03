#include <QtWidgets>
#include <MainWindow.h>

int main(int argc, char *argv[])
{
    QApplication app(argc,argv);
    MainWindow mainWindow;
    mainWindow.setWindowTitle("Paint");
    mainWindow.show();

    return app.exec();
}
