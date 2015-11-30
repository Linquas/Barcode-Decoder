#ifndef DISPLAY_H
#define DISPLAY_H

#include <QGLWidget>
#include <QPainter>
#include <QImage>
#include <QPixmap>
#include <opencv2/opencv.hpp>

namespace Ui {
class Display;
}

class Display : public QGLWidget
{
    Q_OBJECT

public:
    explicit Display(QWidget *parent = 0);
    ~Display();

protected:
    void paintEvent(QPaintEvent *);

signals:

public slots:
    void loadImg(cv::Mat);
    void updateScreen();
    void slotGetBarcodeLocation(cv::Rect);
    void slotIsBarcodeLocated(bool);
    void cleanScrean();
    void startDisplay();

private:
    Ui::Display *ui;
    QPainter *painter;
    cv::Mat img;
    bool isBarcodeLocated;
    bool isProgramRun;
    cv::Rect barcadeLocation;
};

#endif // DISPLAY_H
