#include "pch.h"
#include "Database.h"
#include <iostream>

using namespace std;

void Database::TakeInput()
{
	while (!quit)
	{
		cin >> input;

		if (strcmp(input, "add") == 0)
		{
			char playerName[30];
			int playerScore;

			cout << "Enter name: " << endl;
			cin >> playerName;

			cout << "Enter score: " << endl;
			cin >> playerScore;

			Profile profile(playerName, playerScore);
			Add(profile);
		}
		
		if (strcmp(input, "display") == 0)
		{
			for (int i = 0; i < size; i++)
			{
				cout << profileList[i].GetPlayerName() << " ";
				cout << profileList[i].GetPlayerScore() << endl;
			}
		}

		if (strcmp(input, "sort") == 0)
		{
			bool sorting = true;

			if (size >= 2)
			{
				while (sorting)
				{
					sorting = false;
					for (int i = 1; i < size; i++)
					{
						if (Sort(profileList[i], profileList[i - 1]))
						{
							Profile temp = profileList[i - 1];
							profileList[i - 1] = profileList[i];
							profileList[i] = temp;

							temp.~Profile();
							sorting = true;
						}
					}
				}
			}
		}

		if (strcmp(input, "save") == 0)
		{
			Save();
		}

		if (strcmp(input, "load") == 0)
		{
			Load();
		}

		if (strcmp(input, "search") == 0)
		{
			cout << "Which profile would you like to search for?" << endl;
			cin >> input;
			Search(input);
		}

		if (strcmp(input, "binsearch") == 0)
		{
			cout << "Insert a characters number to begin binary search." << endl;
			int num;
			cin >> num;
			BinSearch(num);
		}

		if (strcmp(input, "update") == 0)
		{
			cout << "Which profile would you like to update?" << endl;
			cin >> input;

			for (int i = 0; i < size; i++)
			{
				if (strcmp(input, profileList[i].GetPlayerName()) == 0)
				{
					Update(profileList[i]);
					break;
				}
				else
				{
					cout << "Profile not found." << endl;
				}
			}
		}

		if (strcmp(input, "quit") == 0)
		{
			quit = true;
		}
	}
}

void Database::Add(Profile profile)
{
	size += 1;
	Profile *temp = new Profile[size];

	for (int i = 0; i < size - 1; i++)
	{
		temp[i] = profileList[i];
	}
	temp[size - 1] = profile;

	for (int i = 0; i < size; i++)
	{
		profileList[i] = temp[i];
	}

	delete[] temp;
}

void Database::Add(char playerName[50], int playerScore)
{
	size += 1;
	Profile *temp = new Profile[size];

	for (int i = 0; i < size - 1; i++)
	{
		temp[i] = profileList[i];
	}
	temp[size - 1] = Profile(playerName, playerScore);

	for (int i = 0; i < size; i++)
	{
		profileList[i] = temp[i];
	}

	delete[] temp;
}

void Database::Search(char input[30])
{
	for (int i = 0; i < size; i++)
	{
		if (strcmp(input, profileList[i].GetPlayerName()) == 0)
		{
			cout << profileList[i].GetPlayerName() << " ";
			cout << profileList[i].GetPlayerScore() << endl;
			break;
		}
	}
}

void Database::BinSearch(int num)
{
	int min = 0;
	int max = 29;
	int mid = (min + max) / 2;

	for (int i = 0; i < size; i++)
	{
		if (profileList[i].GetLetter(mid) < 0)
		{
			min = mid;
			BinSearch(num, min, max);
			break;
		}
		else if (profileList[i].GetLetter(mid) > 0)
		{
			max = mid;
			BinSearch(num, min, max);
			break;
		}
		else if (profileList[i].GetLetter(mid) == 0)
		{
			cout << profileList[i].GetPlayerName() << " ";
			cout << profileList[i].GetPlayerScore() << endl;
		}
	}
}

void Database::BinSearch(int num, int min, int max)
{
	int mid = (min + max) / 2;

	for (int i = 0; i < size; i++)
	{
		if (mid == max)
		{
			cout << "Number not found." << endl;
			break;
		}

		if (profileList[i].GetLetter(mid) < 0)
		{
			min = mid;
			BinSearch(num, min, max);
			break;
		}
		else if (profileList[i].GetLetter(mid) > 0)
		{
			max = mid;
			BinSearch(num, min, max);
			break;
		}
		else if (profileList[i].GetLetter(mid) == 0)
		{
			cout << profileList[i].GetPlayerName() << " ";
			cout << profileList[i].GetPlayerScore() << endl;
		}
	}
}

bool Database::Sort(Profile pro1, Profile pro2)
{
	return (strcmp(pro1.GetPlayerName(), pro2.GetPlayerName())) < 0;
}

void Database::Load()
{
	ifstream in;
	in.open("Profiles.txt", ifstream::in);

	if (!in.is_open())
	{
		return;
	}

	char buffer[30] = {0};

	in.getline(buffer, 50);
	int tempSize = stoi(buffer);
	size = 0;

	Profile *profileList = new Profile[size];

	for (int i = 0; i < tempSize; i++)
	{
		in.getline(buffer, 30);
		char tempName[30];
		strcpy_s(tempName, buffer);

		in.getline(buffer, 30);
		int tempScore = stoi(buffer);

		Add(tempName, tempScore);
	}
}

void Database::Save()
{
	ofstream out;
	out.open("Profiles.txt", ofstream::out | ofstream::trunc);

	if (!out.is_open())
	{
		return;
	}

	out << size << endl;

	for (int i = 0; i < size; i++)
	{
		out << profileList[i].GetPlayerName() << endl;
		out << profileList[i].GetPlayerScore() << endl;
	}

	out.flush();
	out.close();
}

void Database::Update(Profile & prof)
{
	char input[30];

	cout << "Please enter the profiles new name." << endl;
	cin >> input;

	prof.SetPlayerName(input);

	cout << "Please enter the profiles new score." << endl;
	cin >> input;

	prof.SetPlayerScore(stoi(input));
}
