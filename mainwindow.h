#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <QLabel>
#include <QImage>
#include <QPixmap>
#include <QTimer>
#include <QString>
#include <opencv2/opencv.hpp>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QThread decodeThread;
    QThread cameraThread;
    QThread setting;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
signals:
    void focusNum(int);

public slots:
    void updateBarcodeImg(const cv::Mat&);
    void updateBarcode(const QString);
    void slotCameraCheck(bool);
    void getSliderValue();
    void setCameraFocusValue(int);
    void checkCamera(int);
    void setFocusStatus(int);



private slots:
    void on_close_clicked();
    void on_start_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    bool cameraFocus,isAutFocusDisable;
    int cameraID;
};

#endif // MAINWINDOW_H
