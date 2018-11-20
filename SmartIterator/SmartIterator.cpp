// SmartIterator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "transform_view.h"
#include <vector>
#include <functional>
#include <set>
#include <string>




bool is_odd(int x) {
	return !(x % 2);
}

bool is_even(int x) {
	return (x % 2);
}

std::string to_string(int x) {
	return std::to_string(x) + ": ONE MORE NUMBER!";
}

using filter_f = std::function<bool(int)>;
using transform_f = std::function<std::string(int)>;

int main()
{
	
	std::vector<int> a = {1, 4, 5, 2, 6, 7, 8, 9, 3};
	
	filter_view<int, std::vector<int>, filter_f> b(a.begin(), a.end(), is_odd);
	
	for (auto it = b.begin(); it != b.end(); ++it)
		std::cout << *it << std::endl;
	
	transform_view<FilterIterator<int, std::vector<int>, filter_f>, transform_f> c(b.begin(), b.end(), to_string);
	
	for (auto it = c.begin(); it != c.end(); ++it)
		std::cout << *it << std::endl;
	
	std::cout << "\n\nLet's try initializer list\n\n\n";

	std::initializer_list<int> aa = { 34, 45, 67, 23, 46 };

	filter_view<int, std::initializer_list<int>, std::function<bool(int)> > bb(aa.begin(), aa.end(), is_even);

	for (auto it = bb.begin(); it != bb.end(); ++it)
		std::cout << *it << std::endl;

	transform_view<FilterIterator<int, std::initializer_list<int>, filter_f>, transform_f> cc(bb.begin(), bb.end(), to_string);
	
	for (auto it = cc.begin(); it != cc.end(); ++it)
		std::cout << *it << std::endl;


	getchar();
}