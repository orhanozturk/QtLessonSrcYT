#include <QRect>
#include <QDebug>

/*
    QRect(int x, int y, int width, int height)
    QRect(const QPoint &topLeft, const QSize &size)
    QRect(const QPoint &topLeft, const QPoint &bottomRight)
    QRect()
*/

int main()
{
    {
        QRect rect(QPoint(10, 30), QSize(50, 50));
        qDebug() <<rect;
        qDebug() << rect.width() << ", " << rect.height();
        qDebug() << rect.x() << ", " << rect.y();
        qDebug() << "size : " << rect.size();
        qDebug() << "*********************************";

        rect.setX(5);
        rect.setY(5);
        qDebug() << rect.width() << ", " << rect.height();
        qDebug() << rect.x() << ", " << rect.y();
        qDebug() << "size : " << rect.size();
        qDebug() << "*********************************";

        rect.setWidth(70);
        rect.setHeight(80);
        qDebug() << rect.width() << ", " << rect.height();
        qDebug() << rect.x() << ", " << rect.y();
        qDebug() << "size : " << rect.size();
        qDebug() << "*********************************";

    }

    //adjust
    //adjusted
    //intersects
    //instersected
    //contains
    {
        qDebug() << "*********************************";
        qDebug() << "*********************************";

        QRect rect(QPoint(10, 30), QSize(50, 50));
        qDebug() <<rect;
        qDebug() << "*********************************";
        rect.adjust(5, 5, 10, 20);
        qDebug() <<rect;
        qDebug() <<rect.bottomLeft();
        qDebug() <<rect.bottomRight();
        qDebug() <<rect.topLeft();
        qDebug() <<rect.topRight();
        qDebug() << "*********************************";

        QRect rect1(QPoint(10, 30), QSize(50, 50));
        QRect rect2(QPoint(10, 30), QSize(30, 30));

        qDebug() << rect1.contains(rect2);
        qDebug() << rect1.intersects(rect2);
        qDebug() << "*********************************";

        int w = rect1.intersected(rect2).width();
        int h = rect1.intersected(rect2).height();

        QRect rect3 = rect1.intersected(rect2);

        qDebug() << "w : " << w;
        qDebug() << "h : " << h;
        qDebug() << rect3;
        qDebug() << "*********************************";

    }


    //center
    //getCoords
    //setCoords
    {

        qDebug() << "*********************************";
        qDebug() << "*********************************";

        QRect rect(QPoint(10, 30), QSize(50, 50));
        qDebug() << "rect: " << rect;
        QPoint center = rect.center();
        qDebug() << "center: " << center;
        qDebug() << "*********************************";

        int x1, y1, x2, y2;
        rect.getCoords(&x1, &y1, &x2, &y2);
        qDebug() << "x1 : " << x1;
        qDebug() << "y1 : " << y1;
        qDebug() << "x2 : " << x2;
        qDebug() << "y2 : " << y2;
        qDebug() << "*********************************";
        //rect.setRect()
    }

    //translate
    //moveLeft
    //normalized
    //transposed
    //united
    {
        qDebug() << "*********************************";
        qDebug() << "*********************************";

        QRect rect(QPoint(10, 30), QSize(50, 50));
        qDebug() << "rect: " << rect;
        qDebug() << "*********************************";

        rect.translate(5, 5);
        qDebug() << "rect: " << rect;
        qDebug() << "*********************************";

        rect.moveLeft(30);
        qDebug() << "rect: " << rect;
        qDebug() << "*********************************";

        QRect rect1(QPoint(100, 30), QSize(-50, -50));
        qDebug() << "rect1: " << rect1;
        QRect rect2 = rect1.normalized();  // width < 0 , swap left <--> right ||  heigth < 0 swap top <--> bottom
        qDebug() << "rect2 : " << rect2;
        qDebug() << "*********************************";

        QRect r = {15, 51, 42, 24};
        r = r.transposed(); // r == {15, 51, 24, 42}
        qDebug() << "r: " << r;
        qDebug() << "*********************************";

        QRect r1(QPoint(10, 30), QSize(50, 50));
        QRect r2(QPoint(20, 20), QSize(50, 50));

        QRect r3 = r1.united(r2);

        qDebug() << "r3 : " << r3;

        int w = r1.united(r2).width();
        int h = r1.united(r2).height();

        qDebug()  << "w : " << w;
        qDebug()  << "h : " << h;
        qDebug() << "*********************************";

    }


    return 0;
}
