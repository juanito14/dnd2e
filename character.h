#ifndef CHARACTER_H
#define CHARACTER_H

#include <stdexcept>
#include <QObject>
#include <QVector>
#include "characterclass.h"
#include "race.h"

enum Abilities {Strength=0, Dexterity, Constitution, Intelligence, Wisdom, Charisma, MaxAbility};
enum StrengthAbilities {HitPossibility = 0, DamageAdjustment, WeightAllow, OpenDoors, MaxStrengthAbility};
enum DexterityAblities {ReactionAdjustment = 0, MissileAttackAdjustment, DefensiveAdjustment, MaxDexterityAbility};
enum ConstitutionAblities {HitPointAdjustment = 0, SystemShock, PoisonSave, Regeneration, MaxConstitutionAbility};
enum IntelligenceAblities {SpellLevel = 0, ChanceToLearnSpell, MaxOfSpellsPerLevel, IllusionImmunity, MaxIntelligenceAbility};
enum WisdomAblities {MagicalDefenseAdjustment = 0, BonusSpells, ChanceOfSpellFailure, MaxWisdomAbility};
enum CharismaAblities {LoyaltyBase = 0, ChaReactionAdjustment, MaxCharismaAbility};

enum Spells {MaxSpell};
enum MagicItems {MaxMagicItem};
enum Monsters {Ogre = 0, OgreMag, Troll, Giant, Titan, MaxMonster};

class Character : public QObject
{
	Q_OBJECT
public:
    explicit Character(const Classes cl, const Races race, QObject *parent = 0);
	~Character();

	int ability(const Abilities abilityType) const;
	void increaseAbility(int increment, const Abilities abilityType);

	int expirience() const;
	void increaseExpirience(int expirience);

	int getStrengthAbility(const StrengthAbilities strengthAbilityType) const;
    int getDexterityAbility(const DexterityAblities dexterityAbilityType) const;
    int getConstitutionAbility(const ConstitutionAblities constitutionAbilityType) const;
    int getIntelligenceAbility(const IntelligenceAblities intelligenceAbilityType) const;
    int getWisdomAbility(const WisdomAblities wisdomAbilityType) const;
    int getCharismaAbility(const CharismaAblities charismaAbilityType) const;

    int getMagicSavingThrow();
    int getPoisonSavingThrow();
    int getChanceToUseMagicItem(const MagicItems item);
    int getAttackLevel(const Monsters monster);

    int searchDoor();
    int searchTrap();

signals:

public slots:

private:
	QVector<int> _AbilitiesVector;
	const int _defaultAbilityValue;
	int _availabelAbilityValues;
	void checkAbilityType(const Abilities abilityType) const;
    void checkStrengthAbilityType(const StrengthAbilities strengthAbilityType) const;
    void checkDexterityAbilityType(const DexterityAblities dexterityAbilityType) const;
    void checkConstitutionAbilityType(const ConstitutionAblities constitutionAbilityType) const;
    void checkIntelligenceAbilityType(const IntelligenceAblities intelligenceAbilityType) const;
    void checkWisdomAbilityType(const WisdomAblities wisdomAbilityType) const;
    void checkCharismaAbilityType(const CharismaAblities charismaAbilityType) const;
    bool isSpellImmunity(const Spells spell);
    void setClass(const Classes cl);
    void setRace(const Races race);
	CharacterClass _class;
    Race _race;
	int _expirience;
	int _level;
};

#endif // CHARACTER_H
