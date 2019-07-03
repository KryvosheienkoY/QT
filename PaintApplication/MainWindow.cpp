#include "MainWindow.h"
#include "CanvasArea.h"
#include "DialogCreateC.h"
#include <QInputDialog>

MainWindow::MainWindow()
{
    resize(800,800);
    drawEnable = 1;
    rectangleEnable = 0;
    circleEnable = 0;
    LineEnable = 0;
    fillEnable=0;
    eraseEnable=0;
    brushSize = 1;


    CanvasArea *canvas = new CanvasArea(this);
    DialogCreateC *fenetretaille = new DialogCreateC(canvas);
    setCentralWidget(canvas);

    //Menu File
    QMenu *menuFile= menuBar()->addMenu("File");

    QAction *actionNouveau = new QAction("New",this);
    menuFile->addAction(actionNouveau);
    QAction *actionSauvegarder = new QAction("Save",this);
    menuFile->addAction(actionSauvegarder);
    QAction *actionOuvrir = new QAction("Open",this);
    menuFile->addAction(actionOuvrir);

    connect(actionNouveau,SIGNAL(triggered(bool)),fenetretaille,SLOT(createC()));
    connect(actionSauvegarder,SIGNAL(triggered(bool)),canvas,SLOT(saveCanvasArea()));
    connect(actionOuvrir,SIGNAL(triggered(bool)),canvas,SLOT(openCanvasArea()));

    //Menu About
    QMenu *menuAbout = menuBar()->addMenu("Help");
    QAction *aboutAct = new QAction("About", this);
    connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));
    menuAbout->addAction(aboutAct);

    //Tool Bar
    QToolBar *toolBar = addToolBar("Tools");

    QToolButton *colorButton = new QToolButton;
    colorButton->setToolTip("Color");
    colorButton->setIcon(QIcon("C:\\Users\\Julia\\QtProjects\\PaintApplication\\images\\instruments-icons\\cursor_pipette.png"));
    couleurDialogue = new QColorDialog;
    toolBar->addWidget(colorButton);


    QToolButton *pencilButton = new QToolButton;
    pencilButton->setToolTip("Pencil");
    pencilButton->setIcon(QIcon( "C:\\Users\\Julia\\QtProjects\\PaintApplication\\images\\instruments-icons\\pencil.png"));
    toolBar->addWidget(pencilButton);


    QToolButton *eraseButton = new QToolButton;
    eraseButton->setToolTip("Erase");
    eraseButton->setIcon(QIcon( "C:\\Users\\Julia\\QtProjects\\PaintApplication\\images\\instruments-icons\\lastic.png"));
    toolBar->addWidget(eraseButton);

    QToolButton *lineButton = new QToolButton;
    lineButton->setToolTip("Line");
    lineButton->setIcon(QIcon( "C:\\Users\\Julia\\QtProjects\\PaintApplication\\images\\instruments-icons\\line.png"));
    toolBar->addWidget(lineButton);

    QToolButton *circleButton = new QToolButton;
    circleButton->setToolTip("Circle");
    circleButton->setIcon(QIcon( "C:\\Users\\Julia\\QtProjects\\PaintApplication\\images\\instruments-icons\\ellipse.png"));
    toolBar->addWidget(circleButton);


    QToolButton *rectButton = new QToolButton;
    rectButton->setToolTip("Rectangle");
    rectButton->setIcon(QIcon( "C:\\Users\\Julia\\QtProjects\\PaintApplication\\images\\instruments-icons\\rectangle.png"));
    toolBar->addWidget(rectButton);

    QToolButton *fillButton = new QToolButton;
    fillButton->setToolTip("Fill");
    fillButton->setIcon(QIcon( "C:\\Users\\Julia\\QtProjects\\PaintApplication\\images\\instruments-icons\\fill.png"));
    toolBar->addWidget(fillButton);

    QToolButton *sizeButton = new QToolButton;
    sizeButton->setToolTip("Size");
    sizeButton->setIcon(QIcon( "C:\\Users\\Julia\\QtProjects\\PaintApplication\\images\\instruments-icons\\size1.png"));
    toolBar->addWidget(sizeButton);

    QToolButton *undoButton = new QToolButton;
    undoButton->setToolTip("Undo");
    undoButton->setIcon(QIcon( "C:\\Users\\Julia\\QtProjects\\PaintApplication\\images\\instruments-icons\\undo.png"));
    undoButton->setShortcut(QKeySequence("Ctrl+Z"));
    toolBar->addWidget(undoButton);

    connect(colorButton,SIGNAL(clicked(bool)),this,SLOT(slotColor()));
    connect(fillButton,SIGNAL(clicked(bool)),this,SLOT(slotFill()));
    connect(lineButton,SIGNAL(clicked(bool)),this,SLOT(slotLine()));
    connect(pencilButton,SIGNAL(clicked(bool)),this,SLOT(slotDraw()));
    connect(eraseButton,SIGNAL(clicked(bool)),this,SLOT(slotErase()));
    connect(circleButton,SIGNAL(clicked(bool)),this,SLOT(slotCircle()));
    connect(rectButton,SIGNAL(clicked(bool)),this,SLOT(slotRectangle()));
    connect(sizeButton,SIGNAL(clicked(bool)),this,SLOT(slotSize()));
    connect(undoButton,SIGNAL(clicked(bool)),canvas,SLOT(undoCanvasArea()));
}


//FUNCTIONS
bool MainWindow::getDrawEnable()
{
    return drawEnable;
}
bool MainWindow::getEraseEnable()
{
    return eraseEnable;
}
bool MainWindow::getRectangleEnable()
{
    return rectangleEnable;
}
bool MainWindow::getCircleEnable()
{
    return circleEnable;
}
bool MainWindow::getLineEnable()
{
    return LineEnable;
}

bool MainWindow::getFillingEnable()
{
    return fillEnable;
}

QColor MainWindow::getColor()
{
    return couleur;
}
int MainWindow::getBrushSize()
{
    return brushSize;
}

//SLOTS
void MainWindow::about()
{
    QMessageBox::about(this, tr("About"),
                       tr("My Paint Application <br> Kryvosheienko Yuliia 2019"));
}


void MainWindow::slotDraw()
{
    drawEnable = 1;
    eraseEnable = 0;
    rectangleEnable = 0;
    circleEnable = 0;
    fillEnable = 0;
    LineEnable = 0;
}

void MainWindow::slotErase()
{
    eraseEnable = 1;
    drawEnable = 0;
    rectangleEnable = 0;
    circleEnable = 0;
    fillEnable = 0;
    LineEnable = 0;
}

void MainWindow::slotRectangle()
{
    drawEnable = 0;
    rectangleEnable = 1;
    circleEnable = 0;
    fillEnable = 0;
    LineEnable = 0;
    eraseEnable = 0;
}
void MainWindow::slotCircle()
{
    drawEnable = 0;
    rectangleEnable = 0;
    circleEnable = 1;
    fillEnable = 0;
    LineEnable = 0;
    eraseEnable = 0;
}
void MainWindow::slotFill()
{
    drawEnable = 0;
    rectangleEnable = 0;
    circleEnable = 0;
    fillEnable = 1;
    LineEnable = 0;
    eraseEnable = 0;
}

void MainWindow::slotLine()
{
    drawEnable = 0;
    rectangleEnable = 0;
    circleEnable = 0;
    fillEnable = 0;
    LineEnable = 1;
    eraseEnable = 0;
}

void MainWindow::slotColor()
{
    couleur = couleurDialogue->getColor();
}

void MainWindow::slotSize()
{
    bool ok;
    int newWidth = QInputDialog::getInt(this, tr("Scribble"),
                                        tr("Select pen width:"),
                                        brushSize,
                                        1, 30, 1, &ok);
    if (ok)
        brushSize = newWidth;
}


