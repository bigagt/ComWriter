#include "pch.h"
#include "RandomUtility.h"

#include <string>
#include <cstdlib>
#include <time.h>

RandomUtility::StaticConstructor RandomUtility::_StaticConstructor;

RandomUtility::StaticConstructor::StaticConstructor()
{
	srand((int)time(NULL));
}

int RandomUtility::Range(int low, int high)
{
	return (rand() % (high - low + 1)) + low;
}


char RandomUtility::Character()
{
	char retVal = 'a';
	switch (Range(0, 2))
	{
	case 0:
		retVal = (char)(Range('a', 'z'));
		break;
	case 1:
		retVal = (char)(Range('A', 'Z'));
		break;
	case 2:
		retVal = (char)(Range('0', '9'));
		break;
	default:
		break;
	}
	return retVal;
}

std::string RandomUtility::String(int size)
{
	std::string retVal = "";
	while (--size >= 0)
	{
		retVal += Character();
	}
	return retVal;
}