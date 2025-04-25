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
    // Updates the maximum value of the duration slider and displays the total video duration
    void onDurationChanged(qint64 duration);

    // Updates the slider and current time display as the video plays
    void onPositionChanged(qint64 position);

    // Opens a file dialog to select a video file and starts playing it
    void on_actionOpen_2_triggered();

    // Updates the playback position when the slider is dragged
    void on_horizontalSlider_Duration_valueChanged(int value);

    // Toggles between play and pause when the play/pause button is clicked
    void on_pushButton_Play_Pause_clicked();

    // Stops the video playback and resets the play/pause button
    void on_pushButton_Stop_clicked();

    // Toggles between mute and unmute when the volume button is clicked
    void on_pushButton_Volume_clicked();
    
    // Adjusts the audio volume based on the slider
    void on_horizontalSlider_Volume_valueChanged(int value);

    // Moves the video position 5 seconds back
    void on_pushButton_Seek_Backward_clicked();

    // Moves the video position 5 seconds forward
    void on_pushButton_Seek_Forward_clicked();

  private:
    Ui::MainWindow *ui;
    QMediaPlayer *Player;
    QAudioOutput *AudioOutput;
    QVideoWidget *Video;
    bool IS_Pause;
};
#endif // MAINWINDOW_H
