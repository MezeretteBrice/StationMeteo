#ifndef RECEPTEURRTL_433_H
#define RECEPTEURRTL_433_H

#include <QObject>
#include <QProcess>
#include <QDateTime>
#include <QMap>
#include <QTimer>

#include "stationws_3080.h"

enum STATION
{
    STATION_1 = 71,
    STATION_2
};

class RecepteurRTL_433 : public QObject
{
    Q_OBJECT
public:
    explicit RecepteurRTL_433(QObject *parent = nullptr);
    ~RecepteurRTL_433();
    void LancerEcoute();
signals:

private slots:
    void TraiterTrame();
    void on_timeoutTimerBdd();

private:
    QProcess *process;
    QString trameCourante;
    QMultiMap <int, QDateTime> lesTramesDesStations;
    QTimer timerBDD;
    AccesBDD laBdd;
    StationWS_3080 stationDeLaSerre;

};

#endif // RECEPTEURRTL_433_H
