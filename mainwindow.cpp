#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
  , Player(new QMediaPlayer(this))
  , AudioOutput(new QAudioOutput(this))
  , IS_Pause(true)
{
  ui->setupUi(this);

  // Create layout manager
  QVBoxLayout *videoLayout = new QVBoxLayout(ui->groupBox_Video);
  videoLayout->setContentsMargins(5, 5, 5, 5);

  // Add video component to layout
  Video = new QVideoWidget();
  videoLayout->addWidget(Video);
  ui->groupBox_Video->setLayout(videoLayout);

  // Set background color
  QPalette palette;
  palette.setColor(QPalette::Window, QColor(240, 240, 240));
  Video->setPalette(palette);
  Video->setAutoFillBackground(true);

  // Connect audio with video
  Player->setAudioOutput(AudioOutput);
  Player->setVideoOutput(Video);

  // Set control button icon
  ui->pushButton_Play_Pause->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
  ui->pushButton_Stop->setIcon(style()->standardIcon(QStyle::SP_MediaStop));
  ui->pushButton_Seek_Backward->setIcon(style()->standardIcon(QStyle::SP_MediaSeekBackward));
  ui->pushButton_Seek_Forward->setIcon(style()->standardIcon(QStyle::SP_MediaSeekForward));
  ui->pushButton_Volume->setIcon(style()->standardIcon(QStyle::SP_MediaVolume));

  // Init volume 0.0 ~ 1.0
  ui->horizontalSlider_Volume->setMinimum(0);
  ui->horizontalSlider_Volume->setMaximum(100);
  ui->horizontalSlider_Volume->setValue(30);
  AudioOutput->setVolume(0.3); 

  // Connect media player signal with mainwindow slot
  connect(Player, &QMediaPlayer::durationChanged, this, &MainWindow::onDurationChanged);
  connect(Player, &QMediaPlayer::positionChanged, this, &MainWindow::onPositionChanged);
}

MainWindow::~MainWindow()
{
  delete ui;
}

// Slot to handle the duration change of the video
void MainWindow::onDurationChanged(qint64 duration)
{
  ui->horizontalSlider_Duration->setMaximum(duration / 1000);

  // Set total time lable
  QTime totalTime(0, 0, 0);
  totalTime = totalTime.addMSecs(duration);
  ui->label_Total_Time->setText(totalTime.toString("hh:mm:ss"));
}

// Slot to handle position changes of the video during playback
void MainWindow::onPositionChanged(qint64 position)
{
  if (!ui->horizontalSlider_Duration->isSliderDown()) 
  {
    ui->horizontalSlider_Duration->setValue(position / 1000);
  }

  // Set current time label
  QTime currentTime(0, 0, 0);
  currentTime = currentTime.addMSecs(position);
  ui->label_Current_Time->setText(currentTime.toString("hh:mm:ss"));
}

// Slot to open a video file using the QFileDialog
void MainWindow::on_actionOpen_2_triggered()
{
  QString fileName = QFileDialog::getOpenFileName(this,
    tr("Select Video File"), "",
    tr("Video Files (*.mp4 *.avi *.mkv *.mov);;All Files (*)")
  );

  // Load file into the player and start playing
  if (!fileName.isEmpty()) 
  {
    Player->setSource(QUrl::fromLocalFile(fileName));
    IS_Pause = false;
    Player->play();
    ui->pushButton_Play_Pause->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
  }
}

// Slot to update the playback position based on slider value change
void MainWindow::on_horizontalSlider_Duration_valueChanged(int value)
{
  Player->setPosition(value * 1000);
}

// Slot to handle play/pause button click
void MainWindow::on_pushButton_Play_Pause_clicked()
{
  if (IS_Pause)
  {
    // If paused, resume playback
    IS_Pause = false;
    Player->play();
    ui->pushButton_Play_Pause->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
  }
  else
  {
    // If playing, pause the video
    IS_Pause = true;
    Player->pause();
    ui->pushButton_Play_Pause->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
  }
}

// Slot to handle the stop button click
void MainWindow::on_pushButton_Stop_clicked()
{
  Player->stop();
  IS_Pause = true;
  ui->pushButton_Play_Pause->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
}

// Slot to toggle mute/unmute when the volume button is clicked
void MainWindow::on_pushButton_Volume_clicked()
{
  bool muted = AudioOutput->isMuted();
  AudioOutput->setMuted(!muted);

  ui->pushButton_Volume->setIcon(style()->standardIcon(
    !muted ? QStyle::SP_MediaVolumeMuted : QStyle::SP_MediaVolume
  ));
}

// Slot to handle volume slider value change
void MainWindow::on_horizontalSlider_Volume_valueChanged(int value)
{
  AudioOutput->setVolume(value / 100.0);  // Qt6 volume scope 0.0 ~ 1.0
}

// Slot to handle seek backward button click (jump 5 seconds back)
void MainWindow::on_pushButton_Seek_Backward_clicked()
{
  qint64 newPos = Player->position() - 5000;
  Player->setPosition(newPos > 0 ? newPos : 0);
}

// Slot to handle seek forward button click (jump 5 seconds forward)
void MainWindow::on_pushButton_Seek_Forward_clicked()
{
  Player->setPosition(Player->position() + 5000);
}

