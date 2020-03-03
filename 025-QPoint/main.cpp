#include <QPoint>
#include <QDebug>
#include <QSize>

int main()
{
    {
        QPoint p(10, 40);
        qDebug() << p;
        qDebug() << p.x() << " , " << p.y();

        qDebug() << "**************************";

        p.rx()--;
        p.ry() += 10;
        qDebug() << p.x() << " , " << p.y();
        qDebug() << "**************************";

        p.setX(15);
        p.setY(-10);
        qDebug() << p.x() << " , " << p.y();
        qDebug() << "**************************";

        QPoint p2(2, 3);

        p -= p2;
        qDebug() << p.x() << " , " << p.y();
        qDebug() << "**************************";

    }

    //dotProduct  // x1*x2 + y1*y2
    {
        QPoint p( 3, 7);
        QPoint q(-1, 4);
        int lengthSquared = QPoint::dotProduct(p, q);   // lengthSquared becomes 25
        qDebug() << lengthSquared;
        qDebug() << "**************************";
    }

    //manhattanLength
    {
         QPoint oldPosition(8, 4);
         QPoint newPosition(5, 7);

         QPoint point = newPosition - oldPosition;  // 3 , 3

         qDebug() << " manhattanLength : " << point.manhattanLength();
         qDebug() << "**************************";
    }

    //toPoint
    {
        QPointF pf(1.2, 2.8);
        qDebug() << pf;
        QPoint p = pf.toPoint();
        qDebug() << p;
        qDebug() << "**************************";
    }

    return 0;
}
