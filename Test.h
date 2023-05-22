#ifndef TEST_H
#define TEST_H
#include <iostream>
#include "Sort.h"
#include "Stopwatch.h"

class Test
{
private:
	template <class S, typename T>
	double testSort(S* s, void (S::* method)(std::vector<T>& arr), std::vector<T>& arr, Stopwatch* w);
public:
	template <typename T>
	void testSorts(Sort* s, std::vector<T>& arr);
};

template <class S, typename T>
double Test::testSort(S* s, void (S::* method)(std::vector<T>& arr), std::vector<T>& arr, Stopwatch* w)
{
	w->start();
	(s->*method)(arr);
	w->end();
	return w->show();
}

template <typename T>
void Test::testSorts(Sort* s, std::vector<T>& arr)
{
	Stopwatch w;
	std::vector<T> arr1(arr);
	std::vector<T> arr2(arr);
	std::cout << "heapSort:\t" << testSort(s, &Sort::heapSort, arr, &w) << "s\n";
	std::cout << "mergeSort:\t" << testSort(s, &Sort::mergeSort, arr1, &w) << "s\n";
	std::cout << "quickSort:\t" << testSort(s, &Sort::quickSort, arr2, &w) << "s\n\n";
}

#endif