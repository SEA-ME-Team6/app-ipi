// music.cpp
#include "music.h"
#include <QDebug>
#include <QFileInfo>
#include <QStorageInfo>
#include <QProcess>


Music::Music(QObject *parent) : QObject(parent)
{
    //startUSBScan();
}

QStringList Music::fileList() const
{
    return m_fileList;
}

void Music::startUSBScan()
{
    qDebug() << "USB scan initiated";

    // umount /media/usb
    umountUSB();
    qDebug() << "umount 'media/usb'";
    // Remove /media/usb
    removeUsbDirectory();
    qDebug() << "remove 'media/usb'";



    mountUSB();

    qDebug() << "isUSBDriveMounted: " << isUSBDriveMounted();

    // if mounted well, get the path of device
    if(isUSBDriveMounted()) {
        // Get a list of available storage devices
        QList<QStorageInfo> drives = QStorageInfo::mountedVolumes();
        usb_status = true;
        emit usbRemoved(usb_status);
        // Check each drive for a USB drive
        for (const QStorageInfo &drive : drives) {
            if (drive.isValid() && drive.isReady() && drive.device().startsWith("/dev/sd")) {
                m_usbDrivePath = drive.rootPath();
                // Emit the signal indicating that the file list has changed
                qDebug() << "USB scan completed, path: " << m_usbDrivePath;
                //emit usbInserted();
                loadSongsFromUSB();
                return; // Stop scanning once a USB drive is found
            }
        }
    }
    else {
        qDebug() << "No USB drive found";
        usb_status = false;
        emit usbRemoved(usb_status);
    }
}

void Music::mountUSB()
{

    // Make Directory for mount target
    QString mkdirCommand = "mkdir /media/usb";
    QProcess process1;
    QStringList arguments1 = mkdirCommand.split(' ', Qt::SkipEmptyParts);
    QString program1 = arguments1.takeFirst();
    process1.start(program1, arguments1);
    process1.waitForFinished();

    // if making dircetro finished well, start mount
    if (process1.exitCode() == 0) {
        qDebug() << "Directory(/media/usb) is maked!";

        QString usbname = findUSBDevice();
        // Mount the USB drive using a system command
        QString mountCommand = "mount " + findUSBDevice() + " /media/usb";  // Replace /dev/sdX with the appropriate device name for your USB drive
        QProcess process;
        QStringList arguments = mountCommand.split(' ', Qt::SkipEmptyParts);
        QString program = arguments.takeFirst();  // Extract the program (udisksctl in this case)
        process.start(program, arguments);

        process.waitForFinished();

        if (process.exitCode() == 0) {
            qDebug() << "USB drive mounted successfully";
            //emit usbInserted();

        } else {
            qDebug() << "Failed to mount USB drive";
            qDebug() << "Standard Output:" << process.readAllStandardOutput();
            qDebug() << "Standard Error:" << process.readAllStandardError();
        }
    }
    else {
        qDebug() << "Failed making Directory(/media/usb).";
    }


}

bool Music::isUSBDriveMounted()
{
    // Get a list of mounted file systems
    QList<QStorageInfo> drives = QStorageInfo::mountedVolumes();
    //qDebug() << "drives: " << drives;

    // Specify the device name for your USB drive

    QString usbDevice = findUSBDevice();

    // Check if the USB drive is in the list of mounted drives
    for (const QStorageInfo& drive : drives) {
        if (drive.device() == usbDevice) {
            qDebug() << "USB Drive is mounted";
            return true;
        }
    }

    qDebug() << "USB Drive is not mounted";
    return false;
}


void Music::loadSongsFromUSB()
{
    m_fileList.clear();

    QDir usbDir(m_usbDrivePath);
    QStringList nameFilters;

    nameFilters << "*.mp3" << "*.mp4";

    QStringList files = usbDir.entryList(nameFilters, QDir::Files | QDir::NoDotAndDotDot);
    for (const QString &file : files) {
        QFileInfo fileInfo(usbDir.filePath(file));
        m_fileList.append(fileInfo.absoluteFilePath());
    }

    emit fileListChanged();
    qDebug() << "File list loaded from USB:" << m_fileList;


    // You can perform further actions with the loaded file list
}

QString Music::findUSBDevice()
{
    QDir devDir("/dev");
    QStringList nameFilter;
    nameFilter << "sd[a-z][0-9]";

    // Filter files based on the regular expression
    QRegExp regExp(nameFilter.join('|'), Qt::CaseSensitive, QRegExp::Wildcard);
    QStringList fileList = devDir.entryList(nameFilter, QDir::System);

    // Iterate through the filtered file list
    for (const QString &fileName : fileList) {
        if (regExp.exactMatch(fileName)) {
            return "/dev/" + fileName;
        }
    }

    // No matching file found
    return "";
}

void Music::umountUSB()
{
    // Make Directory for mount target
    QString mkdirCommand = "umount /media/usb";
    QProcess process;
    QStringList arguments = mkdirCommand.split(' ', Qt::SkipEmptyParts);
    QString program = arguments.takeFirst();
    process.start(program, arguments);
    process.waitForFinished();
}


void Music::removeUsbDirectory()
{
    // Specify the path of the directory to be removed
    QString usbDirPath = "/media/usb";

    // Check if the directory exists
    if (QDir(usbDirPath).exists()) {
        // Create a QDir object for the directory
        QDir usbDir(usbDirPath);

        // Remove the directory and its contents recursively
        if (usbDir.removeRecursively()) {
            qDebug() << "Directory removed successfully";
        } else {
            qDebug() << "Failed to remove directory";
        }
    } else {
        qDebug() << "Directory does not exist";
    }
}
