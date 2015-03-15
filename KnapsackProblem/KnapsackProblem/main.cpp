#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

int dp[1000];

struct Item
{
	int val;
	int weight;
	Item(int v, int w) : val(v), weight(w) {}
};

int maxValue(const vector<Item>& items, int capacity)
{
	if (dp[capacity] == -1)
	{
		int res = 0;
		for (auto iter : items)
		{
			if (capacity >= iter.weight)
			{
				int nval = iter.val + maxValue(items, capacity - iter.weight);
				if (res < nval)
					res = nval;
			}
		}
		dp[capacity] = res;
	}
	return dp[capacity];
}

int main()
{
	vector<Item> items = { { 15, 20 }, { 10, 15 }, { 8, 10 }, { 5, 8 }, { 2, 4 } };
	for (int i = 0; i < 1000; ++i)
		dp[i] = -1;
	cout << maxValue(items, 50) << endl;
}