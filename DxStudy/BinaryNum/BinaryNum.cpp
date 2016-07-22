// BinaryNum.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

template <int i>
struct hex_to_binary
{
	static const int value = hex_to_binary<i / 16>::value * 2 + hex_to_binary<i % 16>::value;
};

template <>
struct hex_to_binary<1>
{
	static const int value = 1;
};

template <>
struct hex_to_binary<0>
{
	static const int value = 0;
};


#define BINARY(i) hex_to_binary<0x##i>::value

int _tmain(int argc, _TCHAR* argv[])
{
	int i = BINARY(11100);
	std::cout << i << std::endl;

	return 0;
}

