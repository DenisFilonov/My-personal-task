#pragma once
#include "TVProgram.h"
#include<iostream>
#include<string>
#include<fstream>

using namespace std;


class Education :
    public TVProgram
{
private:
    string area;

public:
    Education();
    Education(string name, Time timestart, string area);
    ~Education();

    void setArea(string area);
    string getEdName()const&;
        

    virtual void show()const override;
    virtual string type()const override;
    virtual string toString()const override;
    virtual void save(ofstream& file)override;
    virtual void load(ifstream& file)override;
};

