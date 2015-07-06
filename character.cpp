#include "character.h"

Character::Character(QObject *parent) :
    QObject(parent),
    _defaultAbilityValue(8),
    _availabelAbilityValues(10),
    _expirience(0)
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
int Character::expirience() const
{
    return _expirience;
}

void Character::increaseExpirience(int expirience)
{
    _expirience += expirience;
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


