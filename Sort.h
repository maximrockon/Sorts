#ifndef SORT_H
#define SORT_H
#include <vector>
#include <cstdlib>

class Sort
{
private:
	bool ascending = true;

	template <typename T>
	void heapify(std::vector<T>& arr, size_t size, size_t index);
	template <typename T>
	void buildHeap(std::vector<T>& arr);

	template <typename T>
	size_t partition(std::vector<T>& arr, size_t left, size_t right);
	template <typename T>
	void quickSort(std::vector<T>& arr, size_t left, size_t right);

	template <typename T>
	void mergeSort(std::vector<T>& arr, std::vector<T>& buff, size_t left, size_t right);
public:
	void setAscending(bool ascending);

	template <typename T>
	void heapSort(std::vector<T>& arr);

	template <typename T>
	void quickSort(std::vector<T>& arr);

	template <typename T>
	void mergeSort(std::vector<T>& arr);
};

void Sort::setAscending(bool ascending)
{
	this->ascending = ascending;
}

template <typename T>
void Sort::heapify(std::vector<T>& arr, size_t size, size_t index)
{
	size_t left = 2 * index + 1;
	size_t right = 2 * (index + 1);
	size_t largest = index;
	if (left <= (size - 1) && (arr[left] > arr[largest]) == ascending && arr[left] != arr[largest])
	{
		largest = left;
	}
	if (right <= (size - 1) && (arr[right] > arr[largest]) == ascending && arr[right] != arr[largest])
	{
		largest = right;
	}
	if (largest != index)
	{
		std::swap(arr[index], arr[largest]);
		heapify(arr, size, largest);
	}
	
}

template <typename T>
void Sort::buildHeap(std::vector<T>& arr)
{
	for (int i = arr.size() / 2 - 1; i >= 0; --i)
	{
		heapify(arr, arr.size(), i);
	}
}

template <typename T>
void Sort::heapSort(std::vector<T>& arr)
{
	if (arr.size() > 1)
	{
		buildHeap(arr);
		for (int i = arr.size() - 1; i > 0; --i)
		{
			std::swap(arr[0], arr[i]);
			heapify(arr, i, 0);
		}
	}
}

template <typename T>
size_t Sort::partition(std::vector<T>& arr, size_t left, size_t right)
{
	size_t pivotIndex = left + std::rand() % (right - left + 1);
	T pivot = arr[pivotIndex];
	int count = 0;
	for (int i = left; i <= right; ++i)
		if ((arr[i] < pivot) == ascending || arr[i] == pivot)
			++count;
	std::swap(arr[pivotIndex], arr[left + count - 1]);
	pivotIndex = left + count - 1;
	while (left < right)
	{
		if ((arr[left] > pivot) == ascending && arr[left] != pivot && ((pivot > arr[right]) == ascending || pivot == arr[right]))
		{
			std::swap(arr[left], arr[right]);
			++left; --right;
		}
		else
		{
			if ((arr[left] < pivot) == ascending || arr[left] == pivot) ++left;
			if ((pivot < arr[right]) == ascending && pivot != arr[right]) --right;
		}
	}
	return pivotIndex;
}

template <typename T>
void Sort::quickSort(std::vector<T>& arr, size_t left, size_t right)
{
	if (left < right)
	{
		size_t p = partition(arr, left, right);
		if (p > 0)
			quickSort(arr, left, p - 1);
		if (p + 1 < arr.size())
			quickSort(arr, p + 1, right);
	}
}

template <typename T>
void Sort::quickSort(std::vector<T>& arr)
{
	if (arr.size() > 1)
	{
		quickSort(arr, 0, arr.size() - 1);
	}
}

template <typename T>
void Sort::mergeSort(std::vector<T>& arr, std::vector<T>& buff, size_t left, size_t right)
{
	if (left < right)
	{
		size_t mid = (left + right) / 2;
		mergeSort(arr, buff, left, mid);
		mergeSort(arr, buff, mid + 1, right);
		buff.resize(0);
		buff.insert(buff.begin(), arr.begin() + left, arr.begin() + mid + 1);
		int i = 0; ++mid;
		while (i < buff.size() && mid <= right)
		{
			if ((buff[i] < arr[mid]) == ascending)
			{
				arr[left++] = buff[i++];
			}
			else
			{
				arr[left++] = arr[mid++];
			}
		}
		while (i < buff.size())
		{
			arr[left++] = buff[i++];
		}
	}
}

template <typename T>
void Sort::mergeSort(std::vector<T>& arr)
{
	if (arr.size() > 1)
	{
		std::vector<T> buff;
		buff.reserve(arr.size() / 2 + 1);
		mergeSort(arr, buff, 0, arr.size() - 1);
	}
}

#endif