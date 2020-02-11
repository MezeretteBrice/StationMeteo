#ifndef STATIONWS_3080_H
#define STATIONWS_3080_H

#include <QObject>
#include <QDateTime>
#include <QJsonObject>
#include "tramews_3080.h"
#include "accesbdd.h"

class StationWS_3080 : public QObject
{
    Q_OBJECT
public:
    explicit StationWS_3080(const int _idStation, AccesBDD &_bdd, QObject *parent = nullptr);

    int getIdStation() const;
    QDateTime getHorodatage() const;
    QString getBatterie() const;
    QString getNom() const;
    int getNbMesures() const;

    void AjouterMesures(const TrameWS_3080 _laTrame);
    bool EnregistrerMesures();

signals:
    void BatterieFaible(int station);

public slots:
private:  
    int idStation;
    QDateTime horodatage;
    QString batterie;
    QString nom;
    double cumulTemperature;
    int cumulHumidite;
    int nbMesures;
    AccesBDD &bdd;
};

#endif // STATIONWS_3080_H
