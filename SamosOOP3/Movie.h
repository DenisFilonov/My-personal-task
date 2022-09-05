#pragma once
#include "TVProgram.h"
#include<iostream>
#include<string>
#include<fstream>

using namespace std;


class Movie :
    public TVProgram
{
    string directbox;
    int year;

public:
    Movie();
    Movie(string name, Time timestart, string directbox, int year);
    ~Movie();

    void setDirectBox(string directbox);
    void setYear(int year);

    string getDirectBox()const&;
    int getYear()const&;


    virtual void show()const override;
    virtual string type()const override;
    virtual string toString()const override;
    virtual void save(ofstream& file)override;
    virtual void load(ifstream& file)override;
};

