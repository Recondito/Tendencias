#pragma once
#include <string>
#include <vector>
#include <iostream>

class range{
public:
	range(std::string r); //r = format [,] [,) (,] (,)
	~range();
	std::vector<int> ran;
	bool commaReached = false;
	bool includesFirst;
	bool includesLast;
	std::string first = "";
	std::string last = "";
	int firstN;
	int lastN;
	

	bool contains(int check);
	bool doesNotContains(int check);
	bool containsRange(std::vector<int> range2);
	bool doesNotcontainsRange(std::vector<int> range2);
	void endPoints(std::vector <int> range2);
	bool overlapsRange(std::vector<int> range2);
	bool doesNotOverlpsRange(std::vector<int> range2);
	bool isEqual(std::vector<int> range2);
	bool isNotEqual(std::vector<int> range2);
};

