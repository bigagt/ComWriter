#pragma once

#include <string>

class RandomUtility
{
private:
	friend class StaticConstructor;
	struct StaticConstructor {
		StaticConstructor();
	};

	static StaticConstructor _StaticConstructor;
public:
	static int Range(int low, int high);
	static char Character();
	static std::string String(int size);

private:
	RandomUtility() {}
	~RandomUtility() {}
};

