#include "character.h"

Character::Character(QObject *parent) :
	QObject(parent),
	_defaultAbilityValue(8),
	_availabelAbilityValues(10),
	_expirience(0),
	_level(0)
{
	_AbilitiesVector.reserve(MaxAbility);
	_AbilitiesVector[Strength] = _defaultAbilityValue;
	_AbilitiesVector[Dexterity] = _defaultAbilityValue;
	_AbilitiesVector[Constitution] = _defaultAbilityValue;
	_AbilitiesVector[Intelligence] = _defaultAbilityValue;
	_AbilitiesVector[Wisdom] = _defaultAbilityValue;
	_AbilitiesVector[Charisma] = _defaultAbilityValue;
}

Character::~Character()
{

}

void Character::checkAbilityType(const Abilities abilityType) const
{
	if(abilityType < 0 || abilityType >= MaxAbility){
		throw std::runtime_error("unknown abilityType");
	}
	return;
}

void Character::checkStrengthAbilityType(const StrengthAbilities strengthAbilityType) const
{
	if(strengthAbilityType < 0 || strengthAbilityType >= MaxStrengthAbility){
		throw std::runtime_error("unknown strengthAbilityType");
	}
	return;
}
int Character::expirience() const
{
	return _expirience;
}

void Character::increaseExpirience(int expirience)
{
	if(_class.getClass() == Fighter && ability(Strength) >= 16){
		_expirience += expirience + expirience/10;
		return;
	}

	_expirience += expirience;
	return;
}

int Character::getStrengthAbility(const StrengthAbilities strengthAbilityType) const
{
	checkStrengthAbilityType(strengthAbilityType);
	if(ability(Strength) >= 18){
		//TODO: exceptional strength бросок процентного кубика
	}
	switch (strengthAbilityType) {
	case HitPossibility:

		break;
	case DamageAdjust:
		break;
	case WeightAllow:
		break;
	case OpenDoors:
		break;
	default:
		break;
	}
}


int Character::ability(const Abilities abilityType) const
{
	checkAbilityType(abilityType);
	return _AbilitiesVector.at(abilityType);
}

void Character::increaseAbility(const int increment, const Abilities abilityType)
{
	checkAbilityType(abilityType);
	_AbilitiesVector[abilityType] += increment;
}


