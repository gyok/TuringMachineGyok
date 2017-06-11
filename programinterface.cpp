#include "programinterface.h"

programInterface::programInterface(QWidget *parent) :
    QGraphicsView(parent)
{

    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    this->setAlignment(Qt::AlignCenter);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    this->setMinimumHeight(100);
    this->setMinimumWidth(100);

    scene = new QGraphicsScene();
    this->setScene(scene);

    bulbMapGroup = new QGraphicsItemGroup();

    scene->addItem(bulbMapGroup);
    timer = new QTimer();
    slotAlarmTimer();
}

programInterface::~programInterface(){

}

void programInterface::slotAlarmTimer(){
    int width = this->width();
    int height = this->height();

    scene->setSceneRect(0, 0, width-40, height-40);

    QPen penDefault(Qt::black);
    QBrush brushDefault(Qt::yellow);

    bulbMapGroup->addToGroup(scene->addEllipse(width/2-40, height/2-40, 30, 30, penDefault, brushDefault));

}

void programInterface::resizeEvent(QResizeEvent *event){
    timer->start(1000);
    QGraphicsView::resizeEvent(event);
}
