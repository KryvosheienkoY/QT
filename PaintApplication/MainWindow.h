#ifndef HEADER_FENPRINCIPALE
#define HEADER_FENPRINCIPALE

#include <QtWidgets>


class MainWindow : public QMainWindow
{

    Q_OBJECT

public:
    MainWindow();
    bool getDrawEnable();
    bool getEraseEnable();
    bool getRectangleEnable();
    bool getCircleEnable();
    bool getLineEnable();
    bool getFillingEnable();
    QColor getColor();
    int getBrushSize();

public slots :

    void slotDraw();
    void slotErase();
    void slotRectangle();
    void slotCircle();
    void slotLine();
    void slotFill();
    void slotColor();
    void about();
    void slotSize();

private:
    bool drawEnable;
    bool eraseEnable;
    bool rectangleEnable;
    bool circleEnable;
    bool LineEnable;
    bool fillEnable;
    int brushSize;
    QColorDialog *couleurDialogue;
    QColor couleur;
};

#endif
