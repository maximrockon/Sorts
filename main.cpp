#include "Test.h"

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		std::cerr << "Invalid number of arguments\nFirst arg - array size\nSecond arg (optional) - \"desc\" to sort in descending order";
		return 1;
	}
	int arrSize = atoi(argv[1]);
	Sort s;
	if (argc > 2 && strcmp(argv[2], "desc") == 0)
		s.setAscending(false);
	std::vector<int> arr;
	arr.resize(arrSize);
	Test t;

	for (int i = 0; i < arrSize; ++i)
		arr[i] = std::rand();
	std::cout << "Unsorted array with random elements\n";
	t.testSorts(&s, arr);

	for (int i = 0; i < arrSize; ++i)
		arr[i] = i;
	std::cout << "Already sorted in ascending order array\n";
	t.testSorts(&s, arr);

	for (int i = 0; i < arrSize; ++i)
		arr[i] = arrSize - i;
	std::cout << "Already sorted in descending order array\n";
	t.testSorts(&s, arr);
	return 0;
}