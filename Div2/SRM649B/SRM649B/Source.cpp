#include<iostream>
#include<vector>
#include<string>
#include<numeric>
#include<algorithm>

using namespace std;

int dp[101][101];

class CartInSupermarketEasy
{
public:
	int cal(int n, int k)
	{
		int& ret = dp[n][k];
		if (ret == -1)
		{
			if (n == 0 || k == 0)
				ret = n;
			else
			{
				ret = cal(n - 1, k);
				for (int i = 1; i <= n / 2; ++i)
				{
					for (int j = 0; j < k; ++j)
					{
						ret = min(ret, max(cal(n - i, k - j - 1), cal(i, j)));
					}
				}
				ret = ret + 1;
			}
		}
		return ret;
	}
	int calc(int N, int K)
	{
		memset(dp, -1, sizeof(dp));
		return cal(N, K);
	}
};

int main()
{
	CartInSupermarketEasy c;
	cout<<c.calc(45, 5);
}