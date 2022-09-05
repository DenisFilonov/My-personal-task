#include "Show.h"

Show::Show()
{
    name = "Reserved";
    timestart = Time();
    theme = "=Theme_name=";
}

Show::Show(string name, Time timestart, string theme) : TVProgram(name, timestart)
{
    if (name.size() == 0) throw string("The name can't be empty");
    if (theme.size() == 0) throw string("The theme can't be empty");
    if (timestart.valid() == false) throw string("Wrong setted time");
    this->theme = theme;
}

Show::~Show()
{
}

void Show::setTheme(string theme)
{
    if (theme.size() == 0) throw string("The theme can't be empty");
    this->theme = theme;
}

string Show::getTheme() const&
{
    return theme;
}

void Show::show() const
{
    cout << "\nType: " << type()
        << "\nName: " << name
        << "\nStart time: " << timestart
        << "\nTheme: " << theme << endl;
}

string Show::type() const
{
    return "Show";
}

string Show::toString() const
{
    return type() + " " + name + " " + to_string(timestart.getHour()) + " " + to_string(timestart.getMinutes()) + " " + to_string(timestart.getSeconds()) + " "
        + theme;
}

void Show::save(ofstream& file)
{
    file << type() << endl << name << endl << timestart << endl << theme << endl;
}

void Show::load(ifstream& file)
{
    getline(file, name);
    file >> timestart;

    getline(file, theme);
}
