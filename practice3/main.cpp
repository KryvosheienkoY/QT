#include <QCoreApplication>
#include <QDebug>
#include<QFile>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QFile file1("f1.txt");
    QFile file2("f2.txt");

    if (!file1.open(QIODevice::ReadOnly)) {
        qDebug() << "error read";
    }
    if (!file2.open(QIODevice::WriteOnly)) {
        qDebug() << "error write";
    }
    int s = 1024;
    char str[s];
    while(!file1.atEnd()) {
        int nBlocksize = file1.read(str, sizeof(s));
        for(int i=0; i<s;i++){
            if(str[i]=='\t')
                str[i]=' ';
        }
        file2.write(str, nBlocksize);
    }
    file1.close();
    file2.close();
    return a.exec();
}

