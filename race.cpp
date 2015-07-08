#include "race.h"

Race::Race(QObject *parent) :
    QObject(parent)
{
    setRace(Human);
}

Race::~Race()
{

}

Races Race::race() const
{
    return _race;
}

void Race::setRace(const Races &race)
{
    _race = race;
}

