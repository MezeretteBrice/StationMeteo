#ifndef ACCESBDD_H
#define ACCESBDD_H

#include <QObject>
#include <QSqlDatabase>
#include <QDateTime>
#include "temperaturehumidite.h"
#include "vent.h"


class AccesBDD : public QObject
{
    Q_OBJECT
public:
    explicit AccesBDD(QObject *parent = nullptr);
    ~AccesBDD();
    bool EnregistrerTemperatureHumidite(const int _idStation, const double _temperature, const int _humidite);
    void EnregistrerVent(const int _idStation,const double _vitesse,const int _direction, const double _rafale);
    bool EnregistrerPluie(const int _idStation, const double _pluie);
    bool ActualiserEtatBatterie(const int _idStation, const bool _etat);

signals:

public slots:
private:
    QSqlDatabase bddMeteo;

};

#endif // ACCESBDD_H
