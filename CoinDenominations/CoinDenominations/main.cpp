#include<iostream>
#include<vector>

using namespace std;

int dp[1000];

int coinChange(vector<int> denomination, int amount)
{
	if (dp[amount] == -1)
	{
		int min = 1000;
		for (auto iter : denomination)
		{
			if (iter <= amount)
			{
				if (min > 1 + coinChange(denomination, amount - iter))
				{
					min = 1 + coinChange(denomination, amount - iter);
				}
			}
		}
		dp[amount] = min;
	}
	return dp[amount];
}

int main()
{
	vector<int> den = { 10, 7, 5, 1 };
	for (int i = 0; i < 1000; ++i)
		dp[i] = -1;
	dp[0] = 0;
	cout << coinChange(den, 14)<<endl;
}