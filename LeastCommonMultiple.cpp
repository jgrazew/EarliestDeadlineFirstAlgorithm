#include "stdafx.h"
#include "LeastCommonMultiple.h"

// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

//this uses technique "reduction by the greeatest common divisor" (function can be seen on wikipedia page "Least Common Multiple")
// lcm(a,b) = (abs(a)/gcd(a x b)) x b

LeastCommonMultiple::LeastCommonMultiple(std::vector<int>& list) : m_list(list) { };

int LeastCommonMultiple::GetGreatestCommonDivisor(int a, int b)
{
	for (;;)
	{
		if (a == 0)
		{
			return b;
		}			
		
		b %= a;
		
		if (b == 0) 
		{
			return a;
		}
			
		a %= b;
	}
}

int LeastCommonMultiple::GetLeastCommonMultiple(int a, int b)
{
	int temp = LeastCommonMultiple::GetGreatestCommonDivisor(a, b);

	return temp ? (a / temp * b) : 0;
}

int LeastCommonMultiple::GetLcmForVector()
{
	//std::accumulate takes first, last, initial value, operation
	int result = std::accumulate(m_list.begin(), m_list.end(), 1, std::bind(
		&LeastCommonMultiple::GetLeastCommonMultiple,
		this,
		std::placeholders::_1,
		std::placeholders::_2
	));
	
	return result;
}
