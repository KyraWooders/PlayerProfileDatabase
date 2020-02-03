#pragma once
#include <string>

class Profile
{
public:
	Profile(char playerName[30], int playerScore);
	Profile();
	~Profile();

	void SetPlayerName(char input[30]) { strcpy_s(m_playerName, input); }
	void SetPlayerScore(int playerScore) { m_playerScore = playerScore; }

	int GetPlayerScore() { return m_playerScore; }
	char* GetPlayerName() { return m_playerName; }
	char* GetLetter(int letter) { return (char*)m_playerName[letter]; }

private:
	char m_playerName[30];
	int m_playerScore;
};

