#ifndef CHARACTER_H
#define CHARACTER_H

#include <QObject>
#include <QVector>

enum Abilities {Strength=0, Dexterity, Constitution, Intelligence, Wisdom, Charisma, MaxAbility};

class Character : public QObject
{
    Q_OBJECT
public:
    explicit Character(QObject *parent = 0);
    ~Character();

signals:

public slots:

private:
    QVector<int> _AbilitiesVector;
    const int _defaultAbilityValue;
};

#endif // CHARACTER_H
