#include "pch.h"
#include "Profile.h"
#include <cstring>

Profile::Profile(char playerName[30], int playerScore)
{
	strcpy_s(m_playerName, playerName);
	m_playerScore = playerScore;
}


Profile::Profile()
{
	m_playerName[30] = 'p';
	m_playerScore = 10;
}


Profile::~Profile()
{
}
