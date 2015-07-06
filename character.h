#ifndef CHARACTER_H
#define CHARACTER_H

#include <QObject>
#include <QVector>
#include <stdexcept>
#include "characterclass.h"

enum Abilities {Strength=0, Dexterity, Constitution, Intelligence, Wisdom, Charisma, MaxAbility};

class Character : public QObject
{
    Q_OBJECT
public:
    explicit Character(QObject *parent = 0);
    ~Character();

    int ability(const Abilities abilityType) const;
    void increaseAbility(int increment, const Abilities abilityType);

    int expirience() const;
    void increaseExpirience(int expirience);

signals:

public slots:

private:
    QVector<int> _AbilitiesVector;
    const int _defaultAbilityValue;
    int _availabelAbilityValues;
    void checkAbilityType(const Abilities abilityType) const;
    CharacterClass _class;
    int _expirience;
};

#endif // CHARACTER_H
