#include "DialogCreateC.h"


int DialogCreateC::width = 800;
int DialogCreateC::height = 800;
int widthT=800;
int heightT=800;

DialogCreateC::DialogCreateC(CanvasArea *CanvasArea) : QWidget()
{
    setWindowTitle("New Canvas");
    resize(350,150);
    QVBoxLayout *layout = new QVBoxLayout(this);
    wrLine = new QLineEdit;
    hLine = new QLineEdit;
    QFormLayout *form = new QFormLayout;

    form->addRow("Width:",wrLine);
    form->addRow("Height:",hLine);


    createButton = new QPushButton("Create");
    layout->addLayout(form);
    layout->addWidget(createButton);
    connect(createButton,SIGNAL(clicked(bool)),CanvasArea,SLOT(newCanvasArea()));
    connect(wrLine,SIGNAL(textChanged(QString)),this,SLOT(getWLine(QString)));
    connect(hLine,SIGNAL(textChanged(QString)),this,SLOT(getHLine(QString)));
    connect(createButton,SIGNAL(clicked(bool)),this,SLOT(close()));
}

void  DialogCreateC::check(){
    if(widthT<=0 || heightT<=0){
        QMessageBox::warning(this, "Error","Number should be more than zero! ");
    }
    else{
        DialogCreateC::width =widthT;
        DialogCreateC::height=heightT;
    }
}

void DialogCreateC::createC()
{
    this->show();
}

void DialogCreateC::getWLine(QString lLine)
{
    widthT = lLine.toInt();
}
void DialogCreateC::getHLine(QString hLine)
{
    heightT = hLine.toInt();
}

int DialogCreateC::getWidth()
{
    if(widthT<=0){
        QMessageBox::warning(this, "Error","Number should be more than zero! ");
    }
    else{
        width = widthT;
    }
    return width;
}

int DialogCreateC::getHeight()
{
    if(heightT<=0){
        QMessageBox::warning(this, "Error","Number should be more than zero! ");
    }
    else{
        height = heightT;
    }
    return height;
}
