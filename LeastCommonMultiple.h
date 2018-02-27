#pragma once

#ifndef LEASTCOMMONMULTIPLE_H
#define LEASTCOMMONMULTIPLE_H

#include <vector>
#include <numeric>
#include <functional>

class LeastCommonMultiple
{
public:
	LeastCommonMultiple(std::vector<int>&);	
	int GetLcmForVector();

private:
	std::vector<int> &m_list;

	int GetGreatestCommonDivisor(int, int);
	int GetLeastCommonMultiple(int, int);
};
#endif //! LEASTCOMMONMULTIPLE_H
