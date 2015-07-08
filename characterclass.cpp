#include "characterclass.h"

CharacterClass::CharacterClass(QObject *parent) : QObject(parent)
{
    setClass(Fighter);
}

CharacterClass::~CharacterClass()
{

}
Classes CharacterClass::getClass() const
{
    return _class;
}

void CharacterClass::setClass(const Classes &val)
{
    _class = val;
}


