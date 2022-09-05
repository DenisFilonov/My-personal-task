#include "Children.h"

Children::Children()
{
    name = "Reserved";
    timestart = Time();
    minage = 6;
    maxage = 14;
}

Children::Children(string name, Time timestart, int minage, int maxage) : TVProgram(name, timestart)
{
    if (name.size() == 0) throw string("The name can't be empty");
    if (timestart.valid() == false) throw string("Wrong setted time");
    if (minage < 0) throw string("Wrong setted minimal age");
    if (maxage < 0 || maxage > 100) throw string("Wrong setted maximal age");
    this->minage = minage;
    this->maxage = maxage;
}

Children::~Children()
{
}

void Children::setMinAge(int minage)
{
    if (minage < 0) throw string("Wrong setted age");
    this->minage = minage;
}

void Children::setMaxAge(int maxage)
{
    if (maxage < 0 || maxage > 100) throw string("Wrong setted age");
    this->maxage = maxage;
}

int Children::getMinAge() const&
{
    return minage;
}

int Children::getMaxAge() const&
{
    return maxage;
}

void Children::show() const
{
    cout << "\nType: " << type()
        << "\nName: " << name
        << "\nStart time: " << timestart
        << "\nMinimal age: " << minage
        << "\nMaximal age: " << maxage << endl;
}

string Children::type() const
{
    return "Children";
}

string Children::toString() const
{
    return type() + " " + name + " " + to_string(timestart.getHour()) + " " + to_string(timestart.getMinutes()) + " " + to_string(timestart.getSeconds()) + " " 
        + to_string(minage) + " " + to_string(maxage);
}

void Children::save(ofstream& file)
{
    file << type() << endl << name << endl << timestart << endl << minage << endl << maxage << endl;
}

void Children::load(ifstream& file)
{
    getline(file, name);
    file >> timestart >> minage >> maxage;
}
