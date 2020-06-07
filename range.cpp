#include "range.h"

range::range(std::string r) {

	if (r[0] == '(') {
		includesFirst = false;
	}
	if (r[0] == '[') {
		includesFirst = true;
	}
	if (r.back() == ')') {
		includesLast = false;
	}
	if (r.back() == ']') {
		includesLast = true;
	}

	for (int i = 1; i < r.length() - 1; i++) {
		if (r[i] == ',') {
			commaReached = true;
			continue;
		}
		if (commaReached == false) {
			first += r[i];
		}
		if (commaReached == true) {
			last += r[i];
		}
	}

	firstN = std::stoi(first, nullptr, 10);
	lastN = std::stoi(last, nullptr, 10);
	if (includesFirst == false) {
		firstN++;
	}
	if (includesLast == false) {
		lastN--;
	}
	
	std::cout << std::endl;
	for (int i = firstN; i <= lastN; i++) {
		ran.push_back(i);
		std::cout << i << " ";
	}
	std::cout << std::endl;

}

range::~range() {

}

bool range::contains(int check)
{
	for (int i = 0; i < ran.size(); i++) {
		if (ran[i] == check) {
			return true;
		}
	}
	return false;
}

bool range::doesNotContains(int check)
{
	for (int i = 0; i < ran.size(); i++) {
		if (ran[i] == check) {
			return false;
		}
	}
	return true;
}

bool range::containsRange(std::vector<int> range2)
{
	if (range2.front() >= ran.front() && range2.back() <= ran.back()) {
		return true;
	}
	else {
		return false;
	}
}

bool range::doesNotcontainsRange(std::vector<int> range2)
{
	if (range2.front() >= ran.front() && range2.back() <= ran.back()) {
		return false;
	}
	else {
		return true;
	}
}

void range::endPoints(std::vector <int> range2)
{
	std::cout << "Punto Inicial: " << range2.front() << std::endl;
	std::cout << "Punto Final: " << range2.back() << std::endl;
}

bool range::overlapsRange(std::vector<int> range2)
{
	for (int i = 0; i < ran.size(); i++) {
		for (int j = 0; j < range2.size(); j++) {
			if (ran.at(i) == range2.at(j)) {
				return true;
			}
		}
	}
	return false;
}

bool range::doesNotOverlpsRange(std::vector<int> range2)
{
	for (int i = 0; i < ran.size(); i++) {
		for (int j = 0; j < range2.size(); j++) {
			if (ran.at(i) == range2.at(j)) {
				return false;
			}
		}
	}
	return true;
}

bool range::isEqual(std::vector<int> range2)
{
	if (range2.size() != ran.size()) {
		return false;
	}
	for (int i = 0; i < ran.size(); i++) {
		if (ran[i] != range2[i]) {
			return false;
		}
	}
	return true;
}

bool range::isNotEqual(std::vector<int> range2)
{
	if (range2.size() != ran.size()) {
		return true;
	}
	for (int i = 0; i < ran.size(); i++) {
		if (ran[i] != range2[i]) {
			return true;
		}
	}
	return false;
}
