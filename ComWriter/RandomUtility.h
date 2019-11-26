#pragma once

#include <string>

class RandomUtility
{
public:
	static int Range(int low, int high);
	static char Character();
	static std::string String(int size);

private:
	RandomUtility() {}
	~RandomUtility() {}
};

