#include "TVProgram.h"

TVProgram::TVProgram()
{
	name = "Reserved";
	timestart = Time();
}

TVProgram::TVProgram(string name, Time timestart) : name(name), timestart(timestart)
{
	if (name.size() == 0) throw string("The name can't be empty");
	if (timestart.valid() == false) throw string("Wrong setted time");
}

TVProgram::~TVProgram()
{
}

void TVProgram::setName(string name)
{
	if (name.size() == 0) throw string("The name can't be empty");
	this->name = name;
}

void TVProgram::setTime(Time timestart)
{
	if (timestart.valid() == false) throw string("Wrong setted time");
	this->timestart = timestart;
}

string TVProgram::getName() const&
{
	return name;
}

Time TVProgram::getTime() const&
{
	return timestart;
}

void TVProgram::save(ofstream& file)
{
	//������ �� �����, �.�. ������� �� ����� �������, �� ��������� �������
}

void TVProgram::load(ifstream& file)
{
	//������ �� �����, �.�. ������� �� ����� �������, �� ��������� �������
}
