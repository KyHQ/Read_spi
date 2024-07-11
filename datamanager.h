#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <QObject>
#include <QString>
#include <QFile>
#include <QTextStream>

class DataManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString masterData READ masterData NOTIFY dataChanged)
    Q_PROPERTY(QString slaveData READ slaveData NOTIFY dataChanged)

public:
    explicit DataManager(QObject *parent = nullptr);

    QString masterData() const;
    QString slaveData() const;

    Q_INVOKABLE void updateData();
    Q_INVOKABLE void runExecutable();

    bool enable;
    bool spi_error;
signals:
    void dataChanged();

private:
    QString m_masterData;
    QString m_slaveData;


    void readDataFromFile();
};

#endif // DATAMANAGER_H
