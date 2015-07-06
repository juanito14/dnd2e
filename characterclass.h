#ifndef CHARACTERCLASS_H
#define CHARACTERCLASS_H

#include <QObject>

enum Classes {Fighter=0, Wizard, MaxClass};

class CharacterClass : public QObject
{
    Q_OBJECT
public:
    explicit CharacterClass(QObject *parent = 0);
    ~CharacterClass();

    Classes getClass() const;
    void setClass(const Classes &val);

signals:

public slots:

private:
    Classes _class;
};

#endif // CHARACTERCLASS_H
