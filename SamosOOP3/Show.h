#pragma once
#include "TVProgram.h"
#include<iostream>
#include<string>
#include<fstream>

using namespace std;


class Show :
    public TVProgram
{
    string theme;

public:
    Show();
    Show(string name, Time timestart, string theme);
    ~Show();

    void setTheme(string theme);

    string getTheme()const&;


    virtual void show()const override;
    virtual string type()const override;
    virtual string toString()const override;
    virtual void save(ofstream& file)override;
    virtual void load(ifstream& file)override;
};

