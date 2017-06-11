#ifndef PROGRAMINTERFACE_H
#define PROGRAMINTERFACE_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItemGroup>
#include <QMainWindow>
#include <QTimer>
#include "bulbmechanics.h"
#include <iostream>
#include <QResizeEvent>

class programInterface : public QGraphicsView{
    Q_OBJECT
    public:
        programInterface(QWidget *parent = 0);
        ~programInterface();
        //QTableWidget *laneTuring;
    signals:

    private slots:
        void slotAlarmTimer();
    private:
        QGraphicsScene *scene;
        QGraphicsItemGroup *bulbMapGroup;

        Bulb* getBulbFromMap(Bulb*);
        int deleteBulbFromMap(Bulb*);
        int addBulbToMap(Bulb*);
        int emphasizeBulbOnMap(Bulb*);

        QTimer *timer;

        void resizeEvent(QResizeEvent *event);

};

#endif // PROGRAMINTERFACE_H
