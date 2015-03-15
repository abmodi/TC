#include<iostream>
#include<vector>

using namespace std;

void mergeSort(const vector<int>& arr, vector<int>& sortedArr)
{
	int n = arr.size();
	sortedArr.resize(n);
	if (n == 1)
	{
		sortedArr[0] = arr[0];
		return;
	}
	vector<int> firstHalf, secondHalf, firstSorted, secondSorted;
	for (int i = 0; i < n / 2; ++i)
		firstHalf.push_back(arr[i]);
	for (int i = n / 2; i < n; ++i)
		secondHalf.push_back(arr[i]);
	mergeSort(firstHalf, firstSorted);
	mergeSort(secondHalf, secondSorted);

	int fi = 0, si = 0, ti = 0;
	while (fi < firstSorted.size() && si < secondSorted.size())
	{
		if (firstSorted[fi] < secondSorted[si])
		{
			sortedArr[ti++] = firstSorted[fi++];
		}
		else
		{
			sortedArr[ti++] = secondSorted[si++];
		}
	}
	if (fi == firstSorted.size())
	{
		for (int i = si; i < secondSorted.size(); ++i)
		{
			sortedArr[ti++] = secondSorted[i];
		}
	}
	else
	{
		for (int i = fi; i < firstSorted.size(); ++i)
		{
			sortedArr[ti++] = firstSorted[i];
		}
	}
}

void printArr(vector<int> arr)
{
	for (int i = 0; i < arr.size(); ++i)
	{
		cout << arr[i] << "\t";
	}
}

int main()
{
	vector<int> arr = { 3, 5, 2, 1, 7, 9, 5, 7, -3 };
	vector<int> sortedArr;
	printArr(arr);
	mergeSort(arr, sortedArr);
	cout << "\nSorted Array\n";
	printArr(sortedArr);
}