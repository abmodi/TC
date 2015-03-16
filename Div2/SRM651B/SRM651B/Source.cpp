#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<numeric>
using namespace std;

int dp[50][50][1300];

class FoxAndSouvenirTheNext
{
public:
	bool isPossible(vector<int>& value, int start, int elem, int sum)
	{
		if (dp[start][elem][sum] == -1)
		{
			int sz = value.size();
			int ret = 0;
			if (sum < 0 || elem > sz - start || start >= sz)
				ret = 0;
			else if (sum == 0 && elem == 0)
				ret = 1;
			else
			{
				ret = isPossible(value, start+1, elem, sum);
				if (ret == 0)
				{
					ret = isPossible(value, start + 1, elem - 1, sum - value[start]);
				}
			}
			dp[start][elem][sum] = ret;
		}
		return dp[start][elem][sum];
	}
	string ableToSplit(vector <int> value)
	{
		if (value.size() % 2 != 0)
			return "Impossible";

		int sum = accumulate(value.begin(), value.end(), 0);
		if (sum % 2 != 0)
			return "Impossible";

		for (int i = 0; i < 50;++i)
		for (int j = 0; j < 50;++j)
		for (int k = 0; k < 1300; ++k)
			dp[i][j][k] = -1;

		if (isPossible(value, 0, value.size() / 2, sum / 2))
			return "Possible";

		return "Impossible";

	}
};

int main()
{
	FoxAndSouvenirTheNext f;
	vector<int> inp = { 11, 5, 17, 14, 12, 13, 9, 5, 8, 4, 16, 4, 12, 19, 8, 19, 7, 10, 9, 13, 13, 14, 13, 3, 8, 4, 12, 11, 10, 3, 15, 6, 19, 17, 2, 10, 17, 8, 2, 9, 10, 10, 8, 7 };
	cout<<f.ableToSplit(inp);
}