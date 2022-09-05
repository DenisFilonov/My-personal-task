#pragma once
#include<iostream>
#include<string>

#include"Date.h"
#include"Time.h"
using namespace std;

class TVProgram
{
protected:
	string name;
	Time timestart;

public:
	TVProgram();
	TVProgram(string name, Time timestart);
	virtual ~TVProgram();

	void setName(string name);
	void setTime(Time timestart);

	string getName()const&;
	Time getTime()const&;


	virtual void show()const = 0;
	virtual string type()const = 0;
	virtual void save(ofstream& file);
	virtual void load(ifstream& file);
	virtual string toString()const = 0;
};

