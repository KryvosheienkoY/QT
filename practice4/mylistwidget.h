#include <QListWidget>
#include <QDragMoveEvent>

class MyListWidget : public QListWidget {

public:
    MyListWidget(QWidget * parent) :
        QListWidget(parent) {}

protected:
    void dragMoveEvent(QDragMoveEvent *e) {
        if (e->source() != this) {
            e->accept();
        } else {
            e->ignore();
        }
    }
};
