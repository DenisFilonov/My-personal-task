#include "Education.h"

Education::Education()
{
    name = "Reserved";
    timestart = Time();
    area = "=Area_name=";
}

Education::Education(string name, Time timestart, string area) : TVProgram(name, timestart)
{
    if (name.size() == 0) throw string("The name can't be empty");
    if (area.size() == 0) throw string("The name can't be empty");
    if (timestart.valid() == false) throw string("Wrong setted time");
    this->area = area;
}

Education::~Education()
{
}

void Education::setArea(string area)
{
    if (area.size() == 0) throw string("The name can't be empty");
    this->area = area;
}

string Education::getEdName() const&
{
    return area;
}

void Education::show() const
{
    cout << "\nType: " << type()
        << "\nName: " << name
        << "\nStart time: " << timestart
        << "\nArea: " << area << endl;
}

string Education::type() const
{
    return "Education";
}

string Education::toString() const
{
    return type() + " " + name + " " + to_string(timestart.getHour()) + " " + to_string(timestart.getMinutes()) + " " + to_string(timestart.getSeconds()) + " " + area;
}

void Education::save(ofstream& file)
{
    file << type() << endl << name << endl << timestart << endl << area << endl;
}

void Education::load(ifstream& file)
{
    getline(file, name);
    file >> timestart;

    getline(file, area);
}
