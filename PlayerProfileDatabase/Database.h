#pragma once
#include "Profile.h"
#include <array>
#include <string>

class Database
{
public:
	Database();
	~Database();

	void TakeInput();
	
private:
	char input[20];
	bool quit = false;

private:
	Profile profileList[];
	
private:
	void Add();
	void Add();

	void Search();

	void BinSearch();
	void BinSearch();

	void Sort();

	void Load();
	void Save();
	void Update();
};

