#include "datamanager.h"
#include <QDir>
#include <QDebug>
#include <QQmlContext>
#include <QProcess>

DataManager::DataManager(QObject *parent)
    : QObject(parent)
{
    // Khởi tạo dữ liệu mặc định
    m_masterData = " ";
    m_slaveData = " ";
    enable = false;
    spi_error = false;
    readDataFromFile();
}

QString DataManager::masterData() const
{
    return m_masterData;
}

QString DataManager::slaveData() const
{
    return m_slaveData;
}

void DataManager::updateData()
{
    readDataFromFile();
    emit dataChanged();
}

void DataManager::runExecutable()
{
    enable = true;
    QProcess process;
    QString executable = "D:/QT_DEVELOPMENT/Udemy_Intermediate/Read_Data_Mock_Project/build/Desktop_Qt_6_7_0_MSVC2019_64bit-Debug/test_spi.run";

    if (!QFile::exists(executable)) {
        qDebug() << "Executable file does not exist!";
        return;
    }

    process.setProgram(executable);
    bool started = process.startDetached();
    if (!started) {
        qDebug() << "Failed to start the executable!";
    } else {
        qDebug() << "Executable started successfully!";
    }
}

void DataManager::readDataFromFile()
{
    if(enable){
        QString path = QDir::currentPath() + QDir::separator() + "data.txt";
        path.replace("\\","/");

        QFile file(path);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            while (!in.atEnd()) {
                QString line = in.readLine();
                if (line.startsWith("Master data send")) {
                    m_masterData = line.mid(QString("Master data send").length()).trimmed();
                } else if (line.startsWith("Slave data send")) {
                    m_slaveData = line.mid(QString("Slave data send").length()).trimmed();
                } else if (line.startsWith("Error!")){
                    spi_error = true;
                }


                if(line.isEmpty()){
                    m_masterData = "Empty";
                    m_slaveData = "Empty";
                }
            }
            file.close();
        }
    }
}
