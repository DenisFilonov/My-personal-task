#include "DayProgram.h"

DayProgram::DayProgram()
{
	datestart = Date();
}

DayProgram::DayProgram(Date datestart) : datestart(datestart)
{
	if (datestart.valid() == false) throw string("Wrong setted date");
}

DayProgram::~DayProgram()
{
	for (TVProgram* item : programs)
	{
		item->~TVProgram();
	}
}

void DayProgram::show()
{
	cout << "\tProgram list for today:";
	cout << "\nDate of start: " << datestart << endl;
	// В меню надо вызывать сперва сорт, потом шоу
	for (p = programs.begin(); p != programs.end(); p++)
	{
		(*(p))->show();
	}
}

void DayProgram::add(TVProgram* obj)
{
	programs.push_back(obj);
	cout << "\tThe program [" << obj->getName() << "] was added succesfully.\n";
}

void DayProgram::del(string name)
{
	int check = 0;
	for (p = programs.begin(); p != programs.end(); p++)
	{
		list<TVProgram*>::iterator del = p;
		p++;

		if ((*(del))->getName() == name)
		{
			programs.erase(del);
			check++;
		}
	}
	if (check == 0) cout << "\tThe program [" << name << "] wasn't found. Please, check the information you enter.\n";
	else cout << "\tThe program [" << name << "] was deleted succesfully.\n";
}

void DayProgram::sort()
{
	Compare_TVProgram obj;
	//std::sort(programs.begin(), programs.end(), obj);
	//std::sort(programs.begin(), programs.end(), objcompare); //Это глобальный объект, как переменная, класса
	programs.sort(obj);
}

list<TVProgram*>::iterator DayProgram::findElementsByName(string name)
{
	for (p = programs.begin(); p != programs.end(); p++)
	{
		if ((*(p))->getName() == name)
		{
			break;
		}
	}
	return p;
}

void DayProgram::changeInfo(string name)
{
	list<TVProgram*>::iterator tmp = findElementsByName(name);

	if (tmp != programs.end())
	{
		cout << "\n\tMENU FOR INFORMATION CHANGING";
		int menu;
		Time sometime;
		string s1 = "", s2 = "";
		int ival1, ival2 = 0;
		if ((*(p))->type() == "Movie") //string name, Time timestart, string directbox, int year
		{
			do
			{
				cout << "\n1) Change name.";
				cout << "\n2) Change start time.";
				cout << "\n3) Change direct box.";
				cout << "\n4) Change year.";
				cout << "\n5) Change all of this.";
				cout << "\n0. Turn back.\nChoice: ";
				cin >> menu;
				switch (menu)
				{
				case 1:
					cout << "\nInput name: ";
					cin.ignore();
					getline(cin, s1);

					(*(p))->setName(s1);
					cout << "\tName changed succesfully.\n";
					break;

				case 2:
					cout << "\nInput time: ";
					cin >> sometime;
					
					(*(p))->setTime(sometime);
					cout << "\tTime changed succesfully.\n";
					break;

				case 3:
					cout << "\nInput direct box: ";
					cin.ignore();
					getline(cin, s1);

					((Movie*)*p)->setDirectBox(s1);
					cout << "\tDirect box changed succesfully.\n";
					break;

				case 4: //string name, Time timestart, string area
					cout << "\nInput year: ";
					cin >> ival1;

					((Movie*)*p)->setYear(ival1);
					cout << "\tYear changed succesfully.\n";
					break;

				case 5:
					cout << "\nInput name: ";
					cin.ignore();
					getline(cin, s1);
					(*(p))->setName(s1);

					cout << "Input time: ";
					cin >> sometime;
					(*(p))->setTime(sometime);

					cout << "\nInput direct box: ";
					cin.ignore();
					getline(cin, s2);
					((Movie*)*p)->setDirectBox(s2);

					cout << "\nInput year: ";
					cin >> ival1;
					((Movie*)*p)->setYear(ival1);

					cout << "\tAll information changed succesfully.\n";
					break;

				default: if (menu > 5 || menu != 0 || menu < 0) cout << "\tWrong menu item selected.\n"; break;
				}
			} while (menu != 0);
		}
		else if ((*(p))->type() == "Show") //string name, Time timestart, string theme
		{
			do
			{
				cout << "\n1) Change name.";
				cout << "\n2) Change start time.";
				cout << "\n3) Change theme.";
				cout << "\n4) Change all of this.";
				cout << "\n0. Turn back.\nChoice: ";
				cin >> menu;
				switch (menu)
				{
				case 1:
					cout << "\nInput name: ";
					cin.ignore();
					getline(cin, s1);

					(*(p))->setName(s1);
					cout << "\tName changed succesfully.\n";
					break;

				case 2:
					cout << "\nInput time: ";
					cin >> sometime;

					(*(p))->setTime(sometime);
					cout << "\tTime changed succesfully.\n";
					break;

				case 3:
					cout << "\nInput theme: ";
					cin.ignore();
					getline(cin, s1);

					((Show*)*p)->setTheme(s1);
					cout << "\tTheme changed succesfully.\n";
					break;

				case 4:
					cout << "\nInput name: ";
					cin.ignore();
					getline(cin, s1);
					(*(p))->setName(s1);

					cout << "Input time: ";
					cin >> sometime;
					(*(p))->setTime(sometime);

					cout << "Input theme: ";
					cin.ignore();
					getline(cin, s2);
					((Show*)*p)->setTheme(s2);

					cout << "\tAll information changed succesfully.\n";
					break;

				default: if (menu > 4 || menu != 0 || menu < 0) cout << "\tWrong menu item selected.\n"; break;
				}
			} while (menu != 0);
		}
		else if ((*(p))->type() == "Children") //string name, Time timestart, int minage, int maxage
		{
			do
			{
				cout << "\n1) Change name.";
				cout << "\n2) Change start time.";
				cout << "\n3) Change minimal age.";
				cout << "\n4) Change maximal age.";
				cout << "\n5) Change all of this.";
				cout << "\n0. Turn back.\nChoice: ";
				cin >> menu;
				switch (menu)
				{
				case 1:
					cout << "\nInput name: ";
					cin.ignore();
					getline(cin, s1);

					(*(p))->setName(s1);
					cout << "\tName changed succesfully.\n";
					break;

				case 2:
					cout << "\nInput time: ";
					cin >> sometime;

					(*(p))->setTime(sometime);
					cout << "\tTime changed succesfully.\n";
					break;

				case 3:
					cout << "\nInput minimal age: ";
					cin >> ival1;

					((Children*)*p)->setMinAge(ival1);
					cout << "\tMinimal age changed succesfully.\n";
					break;

				case 4:
					cout << "\nInput maximal age: ";
					cin >> ival1;

					((Children*)*p)->setMaxAge(ival1);
					cout << "\tMaximal age box changed succesfully.\n";
					break;

				case 5:
					cout << "\nInput name: ";
					cin.ignore();
					getline(cin, s1);
					(*(p))->setName(s1);

					cout << "Input time: ";
					cin >> sometime;
					(*(p))->setTime(sometime);

					cout << "\nInput minimal age: ";
					cin >> ival1;
					((Children*)*p)->setMinAge(ival1);

					cout << "\nInput maximal age: ";
					cin >> ival2;
					((Children*)*p)->setMaxAge(ival2);

					cout << "\tAll information changed succesfully.\n";
					break;

				default: if (menu > 5 || menu != 0 || menu < 0) cout << "\tWrong menu item selected.\n"; break;
				}
			} while (menu != 0);
		}
		else if ((*(p))->type() == "Education") //string name, Time timestart, string area
		{
			do
			{
				cout << "\n1) Change name.";
				cout << "\n2) Change start time.";
				cout << "\n3) Change area.";
				cout << "\n4) Change all of this.";
				cout << "\n0. Turn back.\nChoice: ";
				cin >> menu;
				switch (menu)
				{
				case 1:
					cout << "\nInput name: ";
					cin.ignore();
					getline(cin, s1);

					(*(p))->setName(s1);
					cout << "\tName changed succesfully.\n";
					break;

				case 2:
					cout << "\nInput time: ";
					cin >> sometime;

					(*(p))->setTime(sometime);
					cout << "\tTime changed succesfully.\n";
					break;

				case 3:
					cout << "\nInput area: ";
					cin.ignore();
					getline(cin, s1);

					((Education*)*p)->setArea(s1);
					cout << "\tArea changed succesfully.\n";
					break;

				case 4:
					cout << "\nInput name: ";
					cin.ignore();
					getline(cin, s1);
					(*(p))->setName(s1);

					cout << "Input time: ";
					cin >> sometime;
					(*(p))->setTime(sometime);

					cout << "Input area: ";
					cin.ignore();
					getline(cin, s2);
					((Education*)*p)->setArea(s2);

					cout << "\tAll information changed succesfully.\n";
					break;

				default: if (menu > 4 || menu != 0 || menu < 0) cout << "\tWrong menu item selected.\n"; break;
				}
			} while (menu != 0);
		}
	}
	else
	{
		cout << "\tThe program [" << name << "] wasn't found. Please, check the information you enter.\n";
	}
}

void DayProgram::showByTime(Time sometime)
{
	int ival;
	cout << "\nWould you like to see programs in range one hour?\n1) Yes\n2) No\nChoice: ";
	cin >> ival;
	if (ival == 1)
	{
		Time tmp1 = sometime - 3600;
		Time tmp2 = sometime + 3600;

		for (p = programs.begin(); p != programs.end(); p++)
		{
			if ((*(p))->getTime() > tmp1 && (*(p))->getTime() < tmp2)
			{
				(*(p))->show();
			}
		}
	}
	else
	{
		for (p = programs.begin(); p != programs.end(); p++)
		{
			if ((*(p))->getTime() == sometime)
			{
				(*(p))->show();
			}
		}
	}
}

void DayProgram::showByType(string type)
{
	for (p = programs.begin(); p != programs.end(); p++)
	{
		if ((*(p))->type() == type)
		{
			(*(p))->show();
		}
	}
}

void DayProgram::find(string name)
{
	list<TVProgram*>::iterator tmp = findElementsByName(name);

	if (tmp != programs.end())
	{
		(*(tmp))->show();
	}
	else
	{
		cout << "\tThe program [" << name << "] wasn't found. Please, check the information you enter.\n";
	}
}

void DayProgram::save()
{
	ofstream fw("TVProgram.txt");
	if (fw.is_open())
	{
		for (TVProgram* item : programs)
		{
			item->save(fw);
		}
		fw.close();
		cout << "\nAll information is saved succesfully!\n";
	}
}

void DayProgram::load()
{
	ifstream fr("TVProgram.txt");
	TVProgram* ptr = nullptr;

	if (fr.is_open())
	{
		string tmp;
		while (!fr.eof())
		{
			getline(fr, tmp);

			if (tmp == "Movie")
			{
				ptr = new Movie();
				ptr->load(fr);
				programs.push_back(ptr);
			}
			else if (tmp == "Show")
			{
				ptr = new Show();
				ptr->load(fr);
				programs.push_back(ptr);
			}
			else if (tmp == "Children")
			{
				ptr = new Children();
				ptr->load(fr);
				programs.push_back(ptr);
			}
			else if (tmp == "Education")
			{
				ptr = new Education();
				ptr->load(fr);
				programs.push_back(ptr);
			}
		}
		fr.close();
		cout << "\nAll information is loaded succesfully!\n";
	}
}