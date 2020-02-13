#ifndef RECEPTEURRTL_433_H
#define RECEPTEURRTL_433_H

#include <QObject>
#include <QProcess>
#include <QDateTime>
#include <QMap>
#include <QTimer>

#include "stationws1080.h"
#include "serveurmeteo.h"

enum STATION
{
    STATION_1 = 71,     // extérieur
    STATION_2 = 161,    // voisin
    STATION_3 = 169     // serre

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
    void TraiterErreurProcess(QProcess::ProcessError _erreur);
    void on_timeoutTimerBdd();

private:
    QProcess *process;
    QString trameCourante;
    QMultiMap <int, QDateTime> lesTramesDesStations;
    QTimer timerBDD;
    AccesBDD laBdd;
    StationWS1080 stationDeLaSerre;
    ServeurMeteo leServeur;
    QString commande;
};

#endif // RECEPTEURRTL_433_H
