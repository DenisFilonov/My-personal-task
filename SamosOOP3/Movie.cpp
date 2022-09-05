#include "Movie.h"

Movie::Movie()
{
    name = "Reserved";
    timestart = Time();
    directbox = "=DirectBox_name=";
    year = 1900;
}

Movie::Movie(string name, Time timestart, string directbox, int year) : TVProgram(name, timestart)
{
    if (name.size() == 0) throw string("The name can't be empty");
    if (directbox.size() == 0) throw string("The directbox can't be empty");
    if (timestart.valid() == false) throw string("Wrong setted time");
    if (year < 1900 || year > 2999) throw string("Wrong year");
    this->directbox = directbox;
    this->year = year;
}

Movie::~Movie()
{
}

void Movie::setDirectBox(string directbox)
{
    if (directbox.size() == 0) throw string("The directbox can't be empty");
    this->directbox = directbox;
}

void Movie::setYear(int year)
{
    if (year < 1900 || year > 2999) throw string("Wrong year");
    this->year = year;
}

string Movie::getDirectBox() const&
{
    return directbox;
}

int Movie::getYear() const&
{
    return year;
}

void Movie::show() const
{
    cout << "\nType: " << type()
        << "\nName: " << name
        << "\nStart time: " << timestart
        << "\nDirectbox: " << directbox
        << "\nYear: " << year << endl;
}

string Movie::type() const
{
    return "Movie";
}

string Movie::toString() const
{
    return type() + " " + name + " " + to_string(timestart.getHour()) + " " + to_string(timestart.getMinutes()) + " " + to_string(timestart.getSeconds()) + " "
        + directbox + " " + to_string(year);
}

void Movie::save(ofstream& file)
{
    file << type() << endl << name << endl << timestart << endl << directbox << endl << year << endl;
}

void Movie::load(ifstream& file)
{
    getline(file, name);
    file >> timestart;

    getline(file, directbox);
    file >> year;
}
