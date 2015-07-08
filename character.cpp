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

void Character::checkDexterityAbilityType(const DexterityAblities dexterityAbilityType) const
{
    if(dexterityAbilityType < 0 || dexterityAbilityType >= MaxDexterityAbility){
        throw std::runtime_error("unknown dexterityAbilityType");
    }
    return;
}

void Character::checkConstitutionAbilityType(const ConstitutionAblities constitutionAbilityType) const
{
    if(constitutionAbilityType < 0 || constitutionAbilityType >= MaxConstitutionAbility){
        throw std::runtime_error("unknown constitutionAbilityType");
    }
    return;
}

void Character::checkIntelligenceAbilityType(const IntelligenceAblities intelligenceAbilityType) const
{
    if(intelligenceAbilityType < 0 || intelligenceAbilityType >= MaxIntelligenceAbility){
        throw std::runtime_error("unknown intelligenceAbilityType");
    }
    return;
}

void Character::checkWisdomAbilityType(const WisdomAblities wisdomAbilityType) const
{
    if(wisdomAbilityType < 0 || wisdomAbilityType >= MaxWisdomAbility){
        throw std::runtime_error("unknown wisdomAbilityType");
    }
    return;
}

void Character::checkCharismaAbilityType(const CharismaAblities charismaAbilityType) const
{
    if(charismaAbilityType < 0 || charismaAbilityType >= MaxCharismaAbility){
        throw std::runtime_error("unknown charismaAbilityType");
    }
    return;
}

bool Character::isSpellImmunity(const Spells spell)
{
    //TODO: spell immunity
    return false;
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
    if(_class.getClass() == Rogue && ability(Dexterity) >= 16){
        _expirience += expirience + expirience/10;
        return;
    }
    if(_class.getClass() == Wizard && ability(Intelligence) >= 16){
        _expirience += expirience + expirience/10;
        return;
    }
    if(_class.getClass() == Cleric && ability(Wisdom) >= 16){
        _expirience += expirience + expirience/10;
        return;
    }
    if(_class.getClass() == Druid && ability(Wisdom) >= 16){
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
    v[DamageAdjustment] = {-4,-2,-1,-1,-1,0,0,0,0,0,0,0,1,2,3,4,5,6,7,8,9,10,11,12,14};
    v[WeightAllow] = {1,1,5,10,20,35,50,70,95,110,135,160,185,220,260,300,350,410,485,535,635,785,935,1235,1535};
    v[OpenDoors] = {1,1,2,3,3,4,5,6,7,8,9,10,11,12,13,14,15,16,16,17,17,18,18,19,19};

    return v[strengthAbilityType][ability(Strength)];
}

int Character::getDexterityAbility(const DexterityAblities dexterityAbilityType) const
{
    checkDexterityAbilityType(dexterityAbilityType);

    if(ability(Dexterity) < 1 || ability(Dexterity) > 25){
        throw std::runtime_error("wrong Dexterity score");
    }

    std::array<std::array<int, 25>, MaxDexterityAbility> v;
    v[ReactionAdjustment] = {-6,-4,-3,-2,-1,0,0,0,0,0,0,0,0,0,0,1,2,2,3,3,4,4,4,5,5};
    v[MissileAttackAdjustment] = {-6,-4,-3,-2,-1,0,0,0,0,0,0,0,0,0,0,1,2,2,3,3,4,4,4,5,5};
    v[DefensiveAdjustment] = {5,5,4,3,2,1,0,0,0,0,0,0,0,0,-1,-2,-3,-4,-4,-4,-5,-5,-5,-6,-6};

    return v[dexterityAbilityType][ability(Dexterity)];
}

int Character::getConstitutionAbility(const ConstitutionAblities constitutionAbilityType) const
{
    checkConstitutionAbilityType(constitutionAbilityType);

    if(ability(Constitution) < 1 || ability(Constitution) > 25){
        throw std::runtime_error("wrong Constitution score");
    }

    std::array<std::array<int, 25>, MaxConstitutionAbility> v;
    v[HitPointAdjustment] = {-3,-2,-2,-1,-1,-1,0,0,0,0,0,0,0,0,1,2,3,4,5,5,6,6,6,7,7};
    v[SystemShock] = {25,30,35,40,45,50,55,60,65,70,75,80,85,88,90,95,97,99,99,99,99,99,99,99,100};
    v[PoisonSave] = {-2,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,2,2,3,3,4};
    v[Regeneration] = {25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};

    return v[constitutionAbilityType][ability(Constitution)];
}

int Character::getIntelligenceAbility(const IntelligenceAblities intelligenceAbilityType) const
{
    checkIntelligenceAbilityType(intelligenceAbilityType);

    if(ability(Intelligence) < 1 || ability(Intelligence) > 25){
        throw std::runtime_error("wrong Intelligence score");
    }

    std::array<std::array<int, 25>, MaxIntelligenceAbility> v;
    v[SpellLevel] = {0,0,0,0,0,0,0,0,4,5,5,6,6,7,7,8,8,9,9,9,9,9,9,9,9};
    v[ChanceToLearnSpell] = {0,0,0,0,0,0,0,0,40,45,50,55,60,65,70,75,80,85,95,96,97,98,99,100,100};
    v[MaxOfSpellsPerLevel] = {0,0,0,0,0,0,0,0,6,7,7,7,9,9,11,11,14,18,100,100,100,100,100,100,100};
    v[IllusionImmunity] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,3,4,5,6,7};

    return v[intelligenceAbilityType][ability(Intelligence)];
}

int Character::getWisdomAbility(const WisdomAblities wisdomAbilityType) const
{
    checkWisdomAbilityType(wisdomAbilityType);

    if(ability(Wisdom) < 1 || ability(Wisdom) > 25){
        throw std::runtime_error("wrong Wisdom score");
    }

    std::array<std::array<int, 25>, MaxWisdomAbility> v;
    v[MagicalDefenseAdjustment] = {-6,-4,-3,-2,-1,-1,-1,0,0,0,0,0,0,0,1,2,3,4,4,4,4,4,4,4,4};
    v[BonusSpells] = {0,0,0,0,0,0,0,0,0,0,0,0,1,1,2,2,3,3,4,4,5,5,6,6,7};
    v[ChanceOfSpellFailure] = {80,60,50,45,40,35,30,25,20,15,10,5,0,0,0,0,0,0,0,0,0,0,0,0,0};

    if(_class.getClass() == Cleric && ability(Wisdom) >= 13 && wisdomAbilityType == ChanceOfSpellFailure){
        return 0;
    }
    if(_class.getClass() == Druid && ability(Wisdom) >= 13 && wisdomAbilityType == ChanceOfSpellFailure){
        return 0;
    }

    return v[wisdomAbilityType][ability(Wisdom)];
}

int Character::getCharismaAbility(const CharismaAblities charismaAbilityType) const
{
    checkCharismaAbilityType(charismaAbilityType);

    if(ability(Charisma) < 1 || ability(Charisma) > 25){
        throw std::runtime_error("wrong Charisma score");
    }

    std::array<std::array<int, 25>, MaxCharismaAbility> v;
    v[LoyaltyBase] = {-8,-7,-6,-5,-4,-3,-2,-1,0,0,0,0,0,1,3,4,6,8,10,12,14,16,18,20,20};
    v[ChaReactionAdjustment] = {-7,-6,-5,-4,-3,-2,-1,0,0,0,0,0,1,2,3,5,6,7,8,9,10,11,12,13,14};

    return v[charismaAbilityType][ability(Charisma)];
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


