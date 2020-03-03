#include <QSize>
#include <QDebug>


int main()
{
    {
        QSize sz(20, 40);
        qDebug() << sz;
        qDebug() << sz.width() << ", " << sz.height();

        qDebug() << "************************************";

        sz.rwidth()++;
        sz.rheight() -= 10;
        qDebug() << sz.width() << ", " << sz.height();

        qDebug() << "************************************";

        sz.setWidth(50);
        sz.setHeight(10);

        qDebug() << sz.width() << ", " << sz.height();

        qDebug() << "************************************";
    }

    //boundedTo
    //expandedTo
    {
        qDebug() << "************************************";
        qDebug() << "************************************";
        QSize sz1(10, 30);
        QSize sz2(20, -40);

        QSize sz3 = sz1.boundedTo(sz2);
        qDebug() << sz3.width() << ", " << sz3.height();

        qDebug() << "************************************";


        QSize sz4 = sz1.expandedTo(sz2);
        qDebug() << sz4.width() << ", " << sz4.height();

        qDebug() << "************************************";
    }

    //Scale
    //Scaled
    {
        QSize t1(10, 12);
        t1.scale(60, 60, Qt::IgnoreAspectRatio);
        // t1 is (60, 60)
        qDebug() << "width : " << t1.width() << "height : " << t1.height();
        qDebug() << "************************************";
        QSize t2(10, 12);
        t2.scale(60, 60, Qt::KeepAspectRatio);
        // t2 is (50, 60)
        qDebug() << "width : " << t2.width() << "height : " << t2.height();
        qDebug() << "************************************";
        QSize t3(10, 12);
        //t3.scale(60, 60, Qt::KeepAspectRatioByExpanding);
        // t3 is (60, 72)
        //qDebug() << "width : " << t3.width() << "height : " << t3.height();
        qDebug() << "************************************";
        QSize t4 = t3.scaled(60, 60, Qt::KeepAspectRatioByExpanding);
        qDebug() << "width : " << t3.width() << "height : " << t3.height();
        qDebug() << "width : " << t4.width() << "height : " << t4.height();
        qDebug() << "************************************";
    }


    //transpose
    //transposed
    //isValid
    {
        QSize t1(10, 12);

        t1.transpose();
        qDebug() << "width : " << t1.width() << "height : " << t1.height();
        qDebug() << "************************************";

        QSize t2 = t1.transposed();
        qDebug() << "width : " << t1.width() << "height : " << t1.height();
        qDebug() << "width : " << t2.width() << "height : " << t2.height();
        qDebug() << "************************************";

        QSize t3;
        qDebug() << t3.isValid();
    }

    return 0;
}
