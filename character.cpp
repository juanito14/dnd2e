#include "character.h"

Character::Character(QObject *parent) : QObject(parent),_defaultAbilityValue(8)
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

