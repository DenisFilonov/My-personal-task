#include"DayProgram.h"

int main()
{
	cout << "\tStarting the application.\n";

	DayProgram* today = new DayProgram(Date()); // Надо ли в конце delete делать? ++
	TVProgram* ptr = nullptr;

	today->load();

	int menu1, menu2, menu3;
	Time sometime;
	string s1 = "", s2 = "";
	int ival1, ival2 = 0;

	do
	{
		cout << "\n\tMAIN MENU";
		cout << "\n1. Add or reserv program time."; //sw
		cout << "\n2. Delete program.";
		cout << "\n3. Show sorted program list for today.";
		cout << "\n4. Program search menu."; // sw
		cout << "\n5. Menu for changing program information."; //sw
		cout << "\n0. Exit.\nChoice: ";
		cin >> menu1;

		switch (menu1)
		{
		case 1:
			do
			{
				cout << "\n\tMENU FOR WORKING WITH PROGRAMS";
				cout << "\n1) Time reservation.";
				cout << "\n2) Add a Movie.";
				cout << "\n3) Add a Show.";
				cout << "\n4) Add a Children's show.";
				cout << "\n5) Add an Education show.";
				cout << "\n0. Turn back.\nChoice: ";
				cin >> menu2;

				switch (menu2)
				{
				case 1:
					cout << "\n\tMENU FOR SIMPLIFIED RESERVATION OPERATION";
					cout << "\n1) Add a Movie.";
					cout << "\n2) Add a Show.";
					cout << "\n3) Add a Children's show.";
					cout << "\n4) Add an Education show.";
					cout << "\n0. Turn back.\nChoice: ";
					cin >> menu3;

					switch (menu3)
					{
					case 1:
						ptr = new Movie();
						break;

					case 2:
						ptr = new Show();
						break;

					case 3:
						ptr = new Children();
						break;

					case 4:
						ptr = new Education();
						break;

					default: if (menu3 > 4 || menu2 != 0 || menu3 < 0) cout << "\tWrong menu item selected.\n"; break;
					}
					cout << "\tThe item has been added succesfully.\nDo you wanna change it's information right now?\n1) Yes\n2) No\nChoice: ";
					cin >> ival1;
					if (ival1 == 1)
					{
						today->changeInfo("Reserved"); //last added object, search by name
					}
					else break;
					break;

				case 2:	//string name, Time timestart, string directbox, int year
					cout << "\nInput name: ";
					cin.ignore();
					getline(cin, s1);

					cout << "Input start time: ";
					cin >> sometime;

					cout << "Input direct box: ";
					cin.ignore();
					getline(cin, s2);

					cout << "Input year: ";
					cin >> ival1;
					try
					{
						ptr = new Movie(s1, sometime, s2, ival1);
						today->add(ptr);
					}
					catch (string ex)
					{
						cout << ex << endl;
					}
					break;

				case 3: //string name, Time timestart, string theme
					cout << "\nInput name: ";
					cin.ignore();
					getline(cin, s1);

					cout << "Input start time: ";
					cin >> sometime;

					cout << "Input theme: ";
					cin.ignore();
					getline(cin, s2);
					try
					{
						ptr = new Show(s1, sometime, s2);
						today->add(ptr);
					}
					catch (string ex)
					{
						cout << ex << endl;
					}
					break;

				case 4: //string name, Time timestart, int minage, int maxage
					cout << "\nInput name: ";
					cin.ignore();
					getline(cin, s1);

					cout << "Input start time: ";
					cin >> sometime;

					cout << "Input minimal age: ";
					cin >> ival1;

					cout << "Input maximal age: ";
					cin >> ival2;
					try
					{
						ptr = new Children(s1, sometime, ival1, ival2);
						today->add(ptr);
					}
					catch (string ex)
					{
						cout << ex << endl;
					}
					break;

				case 5: //string name, Time timestart, string area
					cout << "\nInput name: ";
					cin.ignore();
					getline(cin, s1);

					cout << "Input start time: ";
					cin >> sometime;

					cout << "Input area: ";
					cin.ignore();
					getline(cin, s2);
					try
					{
						ptr = new Education(s1, sometime, s2);
						today->add(ptr);
					}
					catch (string ex)
					{
						cout << ex << endl;
					}
					break;

				default: if (menu2 > 5 || menu2 != 0 || menu2 < 0) cout << "\tWrong menu item selected.\n"; break;
				}

			} while (menu2 != 0);
			break;

		case 2:
			cout << "\nInput name: ";
			cin.ignore();
			getline(cin, s1);

			today->del(s1);
			break;

		case 3:
			today->sort();
			today->show();
			break;

		case 4:
			do
			{
				cout << "\n\tMENU FOR INFORMATION OUTPUT";
				cout << "\n1) Show all programs by type.";
				cout << "\n2) Show all programs by time.";
				cout << "\n3) Show current program by name.";
				cout << "\n0. Turn back.\nChoice: ";
				cin >> menu2;

				switch (menu2)
				{
				case 1:
					cout << "\nInput type: ";
					cin.ignore();
					getline(cin, s1);

					today->showByType(s1);
					break;

				case 2:
					cout << "\nInput time: ";
					cin >> sometime;

					today->showByTime(sometime);
					break;

				case 3:
					cout << "\nInput name: ";
					cin.ignore();
					getline(cin, s1);

					today->find(s1);
					break;

				default: if (menu2 > 3 || menu2 != 0 || menu2 < 0) cout << "\tWrong menu item selected.\n"; break;
				}

			} while (menu2 != 0);
			break;

		case 5:
			cout << "\nInput name: ";
			cin.ignore();
			getline(cin, s1);

			today->changeInfo(s1);
			break;

		default: if (menu1 > 5 || menu1 != 0 || menu1 < 0) cout << "\tWrong menu item selected.\n"; break;
		}
	} while (menu1 != 0);

	cout << "\tExiting the application.\n";
	today->save();
	delete today;
	return 0;
}