#ifndef RACE_H
#define RACE_H

#include <QObject>

enum Races {Human = 0, Dwarf, Elf, Gnome, HalfElf, Halfling, MaxRaces};

class Race : public QObject
{
    Q_OBJECT
public:
    explicit Race(QObject *parent = 0);
    ~Race();

    Races race() const;
    void setRace(const Races &race);

signals:

public slots:

private:
    Races _race;
};

#endif // RACE_H
