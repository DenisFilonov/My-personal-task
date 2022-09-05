#pragma once
#include "TVProgram.h"
#include<iostream>
#include<string>
#include<fstream>

using namespace std;


class Children :
    public TVProgram
{
    int minage;
    int maxage;

public:
    Children();
    Children(string name, Time timestart, int minage, int maxage);
    ~Children();

    void setMinAge(int minage);
    void setMaxAge(int maxage);

    int getMinAge()const&;
    int getMaxAge()const&;


    virtual void show()const override;
    virtual string type()const override;
    virtual string toString()const override;
    virtual void save(ofstream& file)override;
    virtual void load(ifstream& file)override;
};

