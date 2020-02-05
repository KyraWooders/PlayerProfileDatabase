#pragma once
#include "Profile.h"
#include <array>
#include <string>

class Database
{
public:
	Database() {}
	~Database() {}

	void TakeInput();
	
private:
	int size = 0;
	char input[20];
	bool quit = false;

private:
	Profile profileList[];
	
private:
	void Add(Profile profile);
	void Add(char playerName[50], int playerScore);

	void Search(char input[30]);

	void BinSearch(int num);
	void BinSearch(int num, int min, int max);

	void Sort(Profile pro1, Profile pro2);

	void Load();
	void Save();
	void Update(Profile& prof);
};

