# video-player

A video player application using C++ and Qt framework, supporting multiple mainstream video formats (MP4, AVI, MKV, MOV)

![Introduction](./sample.gif)

## 🚀 Features

1. Supports multiple video formats (MP4, AVI, MKV, MOV, etc.)
2. Complete media control: play/pause, stop, fast forward/backward (5 second intervals), volume adjustment and mute
3. Real-time display of playback progress and time

## 🖥️ Getting Started

1. Prerequisites

- Qt 6.0 or higher
- C++ 17
- Qt Creator (recommended)

2. Clone the Repository

```sh
git clone https://github.com/jiafie7/video-player.git
cd video-player
```

3. Execution

```sh
# Build project
mkdir build && cd build
cmake ..
make

# Start
./VideoPlayer
```

## 🛠️ Instructions

1. Start the program
2. Click "Select Video File > Open" to open the video file
3. Use the control buttons on the interface to control playback: play/pause, stop, fast forward/backward, adjust the volume or mute
4. The playback progress bar can be dragged to quickly locate a specific part of the video

## 📂 Project Structure

```
video-player/
├── main.cpp              # Application entry point
├── mainwindow.h          # Main window class declaration
├── mainwindow.cpp        # Main window class implementation
├── mainwindow.ui         # Qt Designer UI
└── CMakeLists.txt        # Cmake
```

## 📝 License

This project is licensed under the MIT License. See the LICENSE file for more information.

## 🤝 Contributing

Contributions, bug reports, and feature requests are welcome. Feel free to fork the repository, open issues, or submit pull requests.
