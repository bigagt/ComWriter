// ComWriter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>

#include "RandomUtility.h"

static unsigned char instructions[] = 
{
	0xBA, // mov to DX
	0x0E, // address of hello world string
	0x01, // continued address of hello world string (0x010E in little endian)
	0xB4, // move to AH
	0x09, // value 9 corresponds with PRINT
	0xCD,
	0x21,
	0xB8,
	0x01,
	0x4C,
	0xCD,
	0x21,
};

unsigned char helloWorldString[] = 
{
	0x48,
	0x65,
	0x6C,
	0x6C,
	0x6F,
	0x20,
	0x57,
	0x6F,
	0x72,
	0x6C,
	0x64,
	0x21,
	0x0D,
	0x0D,
	0x0A,
	0x24,
};

int main()
{ 
	std::ofstream outFile;
	std::string fileName = RandomUtility::String(RandomUtility::Range(5, 10)) + ".com";
	outFile.open(fileName.c_str());
	outFile << "test";
}

