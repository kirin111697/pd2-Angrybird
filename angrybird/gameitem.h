#ifndef GAMEITEM_H
#define GAMEITEM_H

#include <Box2D/Box2D.h>
#include <QGraphicsPixmapItem>
#include <QPainter>
#include <QTransform>
#include <QtMath>

class gameitem : public QObject
{
    Q_OBJECT
public:
    gameitem(b2World *world);
    ~gameitem();
    static void setGlobalSize(QSizeF worldsize, QSizeF windowsize);

public slots:
    void paint();

protected:
    b2Body *body;
    QGraphicsPixmapItem pic;
    QSizeF itemsize;
    b2World *gameworld;
    static QSizeF g_worldsize, g_windowsize;
};

#endif // GAMEITEM_H
