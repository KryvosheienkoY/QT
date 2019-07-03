#ifndef HEADER_FENTAILLE
#define HEADER_FENTAILLE

#include <QtWidgets>
#include <CanvasArea.h>
class DialogCreateC : public QWidget
{
    Q_OBJECT
public:
    DialogCreateC(CanvasArea *CanvasArea );
     int getWidth();
     int getHeight();



public slots:
    void createC();
    void check();
    void getWLine(QString lLine);
    void getHLine(QString hLine);

private:
    static int width;
    static int height;
    QLineEdit *wrLine;
    QLineEdit *hLine;
    QPushButton *createButton;
};

#endif
