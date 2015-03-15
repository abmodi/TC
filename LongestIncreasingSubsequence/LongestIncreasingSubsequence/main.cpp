#include<iostream>
#include<vector>

using namespace std;

int dp[1000];

int longestSubsequence(const vector<int>& arr, int start)
{
	if (dp[start] == -1)
	{
		int max = 0;
		for (int i = start + 1; i < arr.size(); ++i)
		{
			if (arr[i] > arr[start])
			{
				int len = 1 + longestSubsequence(arr, i);
				if (len > max)
					max = len;
			}
		}
		if (max < 1 && start < arr.size())
			max = 1;
		dp[start] = max;
	}
	return dp[start];
}

int findLongestSubsequence(const vector<int>& arr)
{
	for (int i = 0; i < arr.size(); ++i)
		dp[i] = -1;
	for (int i = 0; i < arr.size(); ++i)
		longestSubsequence(arr, i);
	int max = 0;
	for (int i = 0; i < arr.size(); ++i)
	{
		if (dp[i] > max)
			max = dp[i];
	}
	return max;
}

int main()
{
	vector<int> arr = { 3, 7, 8, 4, 5, 6, 7, 8, -1};
	cout << findLongestSubsequence(arr) << endl;
}