#ifndef CHARACTER_H
#define CHARACTER_H

#include <QObject>
#include <QVector>
#include <stdexcept>
#include "characterclass.h"

enum Abilities {Strength=0, Dexterity, Constitution, Intelligence, Wisdom, Charisma, MaxAbility};
enum StrengthAbilities {HitPossibility = 0, DamageAdjust, WeightAllow, OpenDoors, MaxStrengthAbility};

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

	int getStrengthAbility(const StrengthAbilities strengthAbilityType) const;

signals:

public slots:

private:
	QVector<int> _AbilitiesVector;
	const int _defaultAbilityValue;
	int _availabelAbilityValues;
	void checkAbilityType(const Abilities abilityType) const;
	void checkStrengthAbilityType(const StrengthAbilities strengthAbilityType) const;
	CharacterClass _class;
	int _expirience;
	int _level;
};

#endif // CHARACTER_H
