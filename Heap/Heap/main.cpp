#include<iostream>
#include<vector>

using namespace std;

#define HEAP_SIZE 100

class Heap
{
private:
	int arr[HEAP_SIZE];
	int size;
	void swap(int i, int j);
public:
	void heapify(vector<int> arr);
	Heap() : size(0) { }
	void insert(int n);
	int front();
	void pop();
	void remove(int index);
};

void Heap::insert(int n)
{
	if (size >= HEAP_SIZE)
		throw("Heap Full");
	arr[size] = n;
	int pos = size;
	int parent = (pos - 1) / 2;
	while (parent >= 0 && n < arr[parent])
	{
		arr[pos] = arr[parent];
		arr[parent] = n;
		pos = parent;
		parent = (pos - 1) / 2;
	}
	++size;
}

void Heap::remove(int index)
{
	if (index >= size)
		throw("Index not found");
	swap(index, --size);
	int pos = index;
	while (pos < size)
	{
		int parentVal = arr[pos];
		int minPosVal = pos;
		int minVal = parentVal;
		int leftChildPos = pos * 2 + 1;
		int rightChildPos = pos * 2 + 2;
		if (leftChildPos < size && arr[leftChildPos] < minVal)
		{
			minPosVal = leftChildPos;
			minVal = arr[leftChildPos];
		}
		if (rightChildPos < size && arr[rightChildPos] < minVal)
		{
			minPosVal = rightChildPos;
			minVal = arr[rightChildPos];
		}
		if (minPosVal == pos)
			break;
		swap(pos, minPosVal);
		pos = minPosVal;
	}
}

int Heap::front()
{
	if (size < 1)
		throw("Heap Empty");
	return arr[0];
}

void Heap::swap(int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void Heap::pop()
{
	if (size < 1)
		return;
	int pos = 0;
	swap(0, --size);
	while (pos < size)
	{
		int parentVal = arr[pos];
		int minPosVal = pos;
		int minVal = parentVal;
		int leftChildPos = pos * 2 + 1;
		int rightChildPos = pos * 2 + 2;
		if (leftChildPos < size && arr[leftChildPos] < minVal)
		{
			minPosVal = leftChildPos;
			minVal = arr[leftChildPos];
		}
		if (rightChildPos < size && arr[rightChildPos] < minVal)
		{
			minPosVal = rightChildPos;
			minVal = arr[rightChildPos];
		}
		if (minPosVal == pos)
			break;
		swap(pos, minPosVal);
		pos = minPosVal;
	}
}

int main()
{
	Heap h;
	h.insert(4);
	h.insert(2);
	h.insert(5);
	h.insert(11);
	h.insert(1);
	h.remove(2);
	cout << h.front() << endl;
	h.pop();
	cout << h.front() << endl;
	h.pop();
	cout << h.front() << endl;
	h.pop();
	cout << h.front() << endl;
}