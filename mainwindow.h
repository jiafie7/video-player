#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStyle>
#include <QFileDialog>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QVideoWidget>
#include <QStyle>
#include <QTime>
#include <QVBoxLayout>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onDurationChanged(qint64 duration);
    void onPositionChanged(qint64 position);
    void on_actionOpen_2_triggered();
    void on_horizontalSlider_Duration_valueChanged(int value);
    void on_pushButton_Play_Pause_clicked();
    void on_pushButton_Stop_clicked();
    void on_pushButton_Volume_clicked();
    void on_horizontalSlider_Volume_valueChanged(int value);
    void on_pushButton_Seek_Backward_clicked();
    void on_pushButton_Seek_Forward_clicked();

private:
    Ui::MainWindow *ui;
    QMediaPlayer *Player;
    QAudioOutput *AudioOutput;
    QVideoWidget *Video;
    bool IS_Pause;
};
#endif // MAINWINDOW_H
