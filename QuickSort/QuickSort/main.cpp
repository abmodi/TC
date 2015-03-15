#include<iostream>
#include<vector>

using namespace std;

void printArr(vector<int> arr)
{
	for (size_t i = 0; i < arr.size(); ++i)
	{
		cout << arr[i] << "\t";
		cout << endl;
	}
}

void quickSort(vector<int>& arr, int start, int end)
{
	if (start < end - 1)
	{
		int pivotElement = arr[start];
		int pos = start + 1;
		for (int i = start + 1; i < end; ++i)
		{
			if (arr[i] < pivotElement)
			{
				int temp = arr[i];
				arr[i] = arr[pos];
				arr[pos] = temp;
				++pos;
			}
		}
		arr[start] = arr[pos - 1];
		arr[pos - 1] = pivotElement;
		quickSort(arr, start, pos - 1);
		quickSort(arr, pos, end);
	}
}

int main()
{
	vector<int> inp = { 3, 1, 7, 9, 0, -1, 5, 2, 8, 3 };
	printArr(inp);
	quickSort(inp, 0, inp.size());
	printArr(inp);
}