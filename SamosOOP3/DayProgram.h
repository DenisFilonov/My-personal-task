#pragma once
#include"TVProgram.h"
#include"Movie.h"
#include"Show.h"
#include"Children.h"
#include"Education.h"

#include"Compare_TVProgram.h"

#include<iostream>
#include<string>
#include<fstream>
#include<list>
#include<algorithm>

using namespace std;

class DayProgram
{
protected:
	Date datestart;
	list<TVProgram*> programs;
	list<TVProgram*>:: iterator p;

public:
	DayProgram();
	DayProgram(Date datestart);
	~DayProgram();

	void show();
	void add(TVProgram* obj);
	void del(string name);
	void sort();

	list<TVProgram*>:: iterator findElementsByName(string name);
	void changeInfo(string name);

	void showByTime(Time sometime);
	void showByType(string type);
	void find(string name);

	void save();
	void load();
};