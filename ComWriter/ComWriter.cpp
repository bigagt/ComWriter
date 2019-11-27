// ComWriter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>

#include "RandomUtility.h"

static const int hellowWorldSizeIndex = 2;
static const int helloWorldAddressIndeces[] = { 10, 28, };
static const int randomAddIndex = 7;

static unsigned char instructions[] = 
{
	0x66,
	0xB9,
	0x10,
	0x00,
	0x00,
	0x00,
	0xB7,
	0x01,
	0x66,
	0xBA,
	0x29,
	0x01,
	0x00,
	0x00,
	0x67,
	0x8A,
	0x22,
	0x00,
	0xFC,
	0x67,
	0x88,
	0x22,
	0x66,
	0x42,
	0xE2,
	0xF4,
	0x66,
	0xBA,
	0x29,
	0x01,
	0x00,
	0x00,
	0xB4,
	0x09,
	0xCD,
	0x21,
	0xB8,
	0x01,
	0x4C,
	0xCD,
	0x21,
};

const std::string helloWorldStringBase = "Hello World!";

unsigned char endString[] = 
{
	0x0D,
	0x0D,
	0x0A,
	0x24,
};

const int numberOfFiles = 2;

int main()
{ 
	// tell the program how long the string is
	instructions[hellowWorldSizeIndex] = (char)helloWorldStringBase.length();

	// set the address of the string in the program
	int numHellowWorldIndeces = sizeof(helloWorldAddressIndeces) / sizeof(int);
	for (int i = 0; i < numHellowWorldIndeces; ++i)
	{
		instructions[ helloWorldAddressIndeces[i] ] = sizeof(instructions);
	}

	for (int fileNum = 0; fileNum < numberOfFiles; ++fileNum)
	{
		// set the simple obfuscation offset in the program
		char obfuscationOffset = (char)RandomUtility::Range(50, 100);
		instructions[randomAddIndex] = obfuscationOffset;

		// perform a simple obfuscate on the string
		std::string helloWorldString = helloWorldStringBase;
		for (int i = 0; i < helloWorldString.length(); ++i)
		{
			helloWorldString[i] -= obfuscationOffset;
		}

		std::ofstream outFile;
		std::string fileName = RandomUtility::String(RandomUtility::Range(5, 8)) + ".com";
		outFile.open(fileName.c_str(), std::ofstream::binary | std::ofstream::out | std::ofstream::trunc);
		outFile.write(reinterpret_cast<const char*>(instructions), sizeof(instructions));
		outFile.write(helloWorldString.c_str(), helloWorldString.length());
		outFile.write(reinterpret_cast<const char*>(endString), sizeof(endString));
		outFile.flush();
		outFile.close();
	}
}

