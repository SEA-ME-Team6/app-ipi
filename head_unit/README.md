# Head Unit

## Technical Features
- Implementation of ambient lighting control through the Head Unit application.
- Display of the current gear selection on the Head Unit GUI.
- Development of a media app, including functionality for playing and controlling music and videos

## Qt Application Manager
The Qt Application Manager is a headless daemon that helps you to create embedded Linux systems with a highly complex UI setup, which you can optionally split into a multi-process setup to increase flexibility and stability.

<img src="https://github.com/SEA-ME-Team6/DES_Head-Unit/assets/119277948/0638e651-06fb-450e-9f6d-496f8ac4b956">

The main responsibility of the application manager are:
- Wayland Window Compositor
- Application Launcher
- User Input Management
- Notifications
- Application Installation

## Management Architecture
<img src="https://github.com/SEA-ME-Team6/DES_Head-Unit/assets/119277948/ebd10ca1-ea8f-4121-b57f-64d101873777">


## Create Shared Library for Plugin
And if there is c++ class that needs to be registered in the QML managed by the application manager, you must use a plugin. 

In the CMakeLists.txt file in plugin directory, instead of creating an executable from the source code, a shared library is generated. 

Then, this library and the qmldir are placed in the following path of the Qt installation files.
```
set(PLUGIN_PATH <your_qt_install_directory>/qml/User/${PROJECT_NAME})

install(TARGETS       ${PROJECT_NAME}
        DESTINATION   ${PLUGIN_PATH}
)

install(FILES         qmldir 
        DESTINATION   ${PLUGIN_PATH}
)
```
Then you can just import plugin like QtQuick, QtControl
For example:
```
import QtQuick.Layouts 1.0
import QtApplicationManager.Application 2.0

import User.Music 1.0
```
## Reference
[Qt ApplicationManager](https://doc.qt.io/QtApplicationManager/introduction.html)   
[Qt ApplicationManager](https://doc.qt.io/QtApplicationManager/)   
[System ui](https://doc.qt.io/QtApplicationManager/system-ui.html)
[Official Git](https://github.com/qt/qtapplicationmanager)   
[Hello World Example](https://doc.qt.io/QtApplicationManager-5.15/applicationmanager-applicationmanager-hello-world-example.html)   
[Create Plugin in Qt](https://marssola.github.io/dev/2021/07/29/create-qml-plugins-with-cmake.html)
