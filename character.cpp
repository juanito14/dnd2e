#include "character.h"
#include <array>


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

    if(ability(Strength) < 1 || ability(Strength) > 25){
        throw std::runtime_error("wrong strength score");
    }

    if(ability(Strength) >= 18){
        //TODO: exceptional strength бросок процентного кубика
    }
    std::array<std::array<int, 25>, MaxStrengthAbility> v;
    v[HitPossibility] = {-5,-4,-3,-2,-2,-1,-1,0,0,0,0,0,0,0,0,0,1,2,3,3,4,4,5,6,7};
    v[DamageAdjust] = {-4,-2,-1,-1,-1,0,0,0,0,0,0,0,1,2,3,4,5,6,7,8,9,10,11,12,14};
    v[WeightAllow] = {1,1,5,10,20,35,50,70,95,110,135,160,185,220,260,300,350,410,485,535,635,785,935,1235,1535};
    v[OpenDoors] = {1,1,2,3,3,4,5,6,7,8,9,10,11,12,13,14,15,16,16,17,17,18,18,19,19};

    return v[strengthAbilityType][ability(Strength)];
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


