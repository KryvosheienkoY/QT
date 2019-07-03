#include <CanvasArea.h>
#include "DialogCreateC.h"


CanvasArea::CanvasArea(MainWindow *p) : QWidget()
{
    window = p;
    xMax = 800;
    yMax = 800;
    label = new QLabel(this);
    mapPixels.push_back(new QPixmap(xMax,yMax));
    pixCur = mapPixels.size()-1;
    mapPixels[pixCur]->fill();
    painter = new QPainter(mapPixels[pixCur]);
    label->setPixmap(*mapPixels[pixCur]);
}
CanvasArea::~CanvasArea(){}
void CanvasArea::paintEvent(QPaintEvent *event){}

//MOUSE EVENTS
void CanvasArea::mouseMoveEvent(QMouseEvent *event)
{
    if(window->getDrawEnable())
    {
        xMove = event->pos().x();
        yMove = event->pos().y();
        draw();
    }
    if(window->getEraseEnable())
    {
        xMove = event->pos().x();
        yMove = event->pos().y();
        erase();
    }
    if(window->getRectangleEnable())
    {
        xMove = event->pos().x();
        yMove = event->pos().y();
        drawFilledRectangle();
    }
    if(window->getCircleEnable())
    {
        xMove = event->pos().x();
        yMove = event->pos().y();
        drawFilledCircle();
    }
    if(window->getLineEnable())
    {
        xMove = event->pos().x();
        yMove = event->pos().y();
        drawFilledLine();
    }

}
void CanvasArea::mousePressEvent(QMouseEvent* event)
{
    if(window->getRectangleEnable()||window->getCircleEnable()
            ||window->getFillingEnable()||window->getLineEnable())
    {
        xPress = event->pos().x();
        yPress = event->pos().y();

    }
    if(window->getDrawEnable())
    {
        mapPixels.push_back(new QPixmap(xMax,yMax));
        pixCur = pixCur+1;
        mapPixels[pixCur]->operator =(*mapPixels[pixCur-1]);
        painter->end();
        delete painter;
        painter = new QPainter(mapPixels[pixCur]);
    }
    if(window->getDrawEnable())
    {
        xPress = event->pos().x();
        yPress = event->pos().y();
        path = new QPainterPath(QPointF(xPress,yPress));
        path->moveTo(xPress,yPress);
    }
    if(window->getEraseEnable())
    {
        mapPixels.push_back(new QPixmap(xMax,yMax));
        pixCur = pixCur+1;
        mapPixels[pixCur]->operator =(*mapPixels[pixCur-1]);
        painter->end();
        delete painter;
        painter = new QPainter(mapPixels[pixCur]);
    }
    if(window->getEraseEnable())
    {
        xPress = event->pos().x();
        yPress = event->pos().y();
        path = new QPainterPath(QPointF(xPress,yPress));
        path->moveTo(xPress,yPress);
    }

}
void CanvasArea::mouseReleaseEvent(QMouseEvent *event)
{
    if(window->getRectangleEnable())
    {
        xRelease = event->pos().x();
        yRelease = event->pos().y();
        drawRectangle();

    }
    if(window->getCircleEnable())
    {
        xRelease = event->pos().x();
        yRelease = event->pos().y();
        drawCircle();

    }
    if(window->getLineEnable())
    {
        xRelease = event->pos().x();
        yRelease = event->pos().y();
        drawLine();

    }
    if(window->getFillingEnable())
    {
        xRelease = event->pos().x();
        yRelease = event->pos().y();
        fill();

    }
    if(window->getDrawEnable())
    {
        delete path;
    }
    if(window->getEraseEnable())
    {
        delete path;
    }

}
//FUNCTIONS
void CanvasArea::draw()
{
    QPen pen;
    path->lineTo(xMove,yMove);
    pen.setColor(window->getColor());
    pen.setWidth(window->getBrushSize());
    painter->setPen(pen);
    painter->setRenderHint(QPainter::Antialiasing);
    painter->drawPath(*path);

    label->setPixmap(*mapPixels[pixCur]);
}

void CanvasArea::erase()
{
    QPen pen;
    path->lineTo(xMove,yMove);
    pen.setColor(QColor("white"));
    pen.setWidth(window->getBrushSize());
    painter->setPen(pen);
    painter->setRenderHint(QPainter::Antialiasing);
    painter->drawPath(*path);
    label->setPixmap(*mapPixels[pixCur]);
}

void CanvasArea::drawRectangle()
{
    QPen pen;
    pen.setColor(window->getColor());
    pen.setWidth(window->getBrushSize());

    mapPixels.push_back(new QPixmap(xMax,yMax));
    pixCur = pixCur+1;
    mapPixels[pixCur]->operator =(*mapPixels[pixCur-1]);
    painter->end();
    delete painter;
    painter = new QPainter(mapPixels[pixCur]);

    painter->setPen(pen);
    painter->drawRect(xPress,yPress,xRelease-xPress,yRelease-yPress);

    label->setPixmap(*mapPixels[pixCur]);
}
void CanvasArea::drawFilledRectangle()
{
    QPen pen;
    pen.setColor(window->getColor());
    pen.setWidth(window->getBrushSize());

    mapPixels.push_back(new QPixmap(xMax,yMax));
    pixCur = pixCur+1;
    mapPixels[pixCur]->operator =(*mapPixels[pixCur-1]);
    painter->end();
    delete painter;
    painter = new QPainter(mapPixels[pixCur]);
    painter->setPen(pen);
    painter->drawRect(xPress,yPress,xMove-xPress,yMove-yPress);
    label->setPixmap(*mapPixels[pixCur]);
    mapPixels.remove(pixCur);
    pixCur = mapPixels.size()-1;
}

void CanvasArea::drawCircle()
{
    QPen pen;
    pen.setColor(window->getColor());
    pen.setWidth(window->getBrushSize());

     mapPixels.push_back(new QPixmap(xMax,yMax));
     pixCur = pixCur+1;
     mapPixels[pixCur]->operator =(*mapPixels[pixCur-1]);
     painter->end();
     delete painter;
     painter = new QPainter(mapPixels[pixCur]);

     painter->setPen(pen);
     painter->drawEllipse(xPress,yPress,xRelease-xPress,yRelease-yPress);
     label->setPixmap(*mapPixels[pixCur]);
}
void CanvasArea::drawFilledCircle()
{
    QPen pen;
    pen.setColor(window->getColor());
    pen.setWidth(window->getBrushSize());

    mapPixels.push_back(new QPixmap(xMax,yMax));
    pixCur = pixCur+1;
    mapPixels[pixCur]->operator =(*mapPixels[pixCur-1]);
    painter->end();
    delete painter;
    painter = new QPainter(mapPixels[pixCur]);

    painter->setPen(pen);
    painter->drawEllipse(xPress,yPress,xMove-xPress,yMove-yPress);
    label->setPixmap(*mapPixels[pixCur]);
    mapPixels.remove(pixCur);
    pixCur = mapPixels.size()-1;
}

void CanvasArea::drawLine()
{
    QPen pen;
    pen.setColor(window->getColor());
    pen.setWidth(window->getBrushSize());

    mapPixels.push_back(new QPixmap(xMax,yMax));
    pixCur = pixCur+1;
    mapPixels[pixCur]->operator =(*mapPixels[pixCur-1]);
    painter->end();
    delete painter;
    painter = new QPainter(mapPixels[pixCur]);

    painter->setPen(pen);
    painter->drawLine(xPress,yPress,xRelease,yRelease);
    label->setPixmap(*mapPixels[pixCur]);

}
void CanvasArea::drawFilledLine()
{
    QPen pen;
    pen.setColor(window->getColor());
    pen.setWidth(window->getBrushSize());

    mapPixels.push_back(new QPixmap(xMax,yMax));
    pixCur = pixCur+1;
    mapPixels[pixCur]->operator =(*mapPixels[pixCur-1]);
    painter->end();
    delete painter;
    painter = new QPainter(mapPixels[pixCur]);

    painter->setPen(pen);
    painter->drawLine(xPress,yPress,xMove,yMove);
    label->setPixmap(*mapPixels[pixCur]);
    mapPixels.remove(pixCur);
    pixCur = mapPixels.size()-1;
}

void CanvasArea::fill()
{
    painter->end();
    delete painter;
    QRgb colorNeeded,colorCur;

    mapPixels.push_back(new QPixmap(xMax,yMax));
    pixCur = pixCur+1;
    mapPixels[pixCur]->operator =(*mapPixels[pixCur-1]);

    image = new QImage(xMax,yMax,QImage::Format_RGB32);
    *image = mapPixels[pixCur]->toImage();
    colorNeeded = image->pixel(xPress,yPress);
    colorCur = window->getColor().rgb();
    filling4(xPress,yPress,colorNeeded,colorCur);
    mapPixels[pixCur]->convertFromImage(*image);
    painter = new QPainter(mapPixels[pixCur]);
    delete image;
    label->setPixmap(*mapPixels[pixCur]);
}

int CanvasArea::filling4(int x,int y,QRgb col1, QRgb col2)
{
    int a,b,i;
    int lastPos;
    QVector<Point*> lPos;
    if(image->pixel(x,y)!= col1)
    {
        return 1;
    }
    if(x<0||y<0||x>(xMax-1)||y>(yMax-1)||col1==col2)
    {
        return 0;
    }
    lPos.push_back(new Point(x,y));
    while(lPos.empty()==0)
    {
        a = lPos[lPos.size()-1]->getX();
        b = lPos[lPos.size()-1]->getY();
        if(a==1||b==1||a==(xMax-1)||b==(yMax-1))
        {
            for(i=0;i<xMax;i++)
            {
               image->setPixel(i,0,col2);
               image->setPixel(i,yMax-1,col2);
            }
            for(i=0;i<yMax;i++)
            {
               image->setPixel(0,i,col2);
               image->setPixel(xMax-1,i,col2);
            }
        }
        lastPos = lPos.size()-1;
        lPos.remove(lastPos);

        image->setPixel(a,b,col2);

        if(image->pixel(a,b-1)==col1)
        {
            lPos.push_back(new Point(a,b-1));
        }

        if(image->pixel(a,b+1)==col1)
        {
            lPos.push_back(new Point(a,b+1));
        }
        if(image->pixel(a+1,b)==col1)
        {
            lPos.push_back(new Point(a+1,b));
        }
        if(image->pixel(a-1,b)==col1)
        {
            lPos.push_back(new Point(a-1,b));
        }
    }
    return 1;
}


void CanvasArea::saveCanvasArea()
{
    QString file = QFileDialog::getSaveFileName(0, "Save image", QString(), "Images (*.png *.gif *.jpg *.jpeg)");
    mapPixels[pixCur]->save(file);
}

void CanvasArea::openCanvasArea()
{
    QString file = QFileDialog::getOpenFileName(0,"Open image",QString(),"Images (*.png *.gif *.jpg *.jpeg)");
    painter->end();
    delete painter;
    mapPixels.remove(pixCur);
    mapPixels.push_back(new QPixmap(file));
    painter = new QPainter(mapPixels[pixCur]);
    label->setPixmap(*mapPixels[pixCur]);

}

void CanvasArea::newCanvasArea()
{
    painter->end();
    delete painter;
    mapPixels.erase(mapPixels.begin(),mapPixels.end());
    delete label;

    DialogCreateC *dialog = new DialogCreateC(this);
    xMax = dialog->getWidth();
    yMax = dialog->getHeight();


    mapPixels.push_back(new QPixmap(xMax,yMax));
    pixCur = mapPixels.size()-1;
    mapPixels[pixCur]->fill();

    label = new QLabel(this);
    label->setPixmap(*mapPixels[pixCur]);
    label->show();
    painter = new QPainter(mapPixels[pixCur]);
}
void CanvasArea::undoCanvasArea()
{
    if(pixCur ==0)
        return;
    mapPixels.remove(pixCur);
    pixCur = mapPixels.size()-1;
    painter->end();
    delete painter;
    painter = new QPainter(mapPixels[pixCur]);
    label->setPixmap(*mapPixels[pixCur]);

}
