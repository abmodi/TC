#include<iostream>
#include<string>
#include<vector>

using namespace std;

int dp[100][100];

int seqAlignment(const string& a, const string& b, int alen, int blen, int pgap, int pmismatch)
{
	if (dp[alen][blen] == -1)
	{
		int minVal = 100000;
		if (a[alen - 1] == b[blen - 1])
		{
			minVal = seqAlignment(a, b, alen - 1, blen - 1, pgap, pmismatch);
		}
		else
		{
			minVal = seqAlignment(a, b, alen - 1, blen - 1, pgap, pmismatch) + pmismatch;
		}
		int fgap = seqAlignment(a, b, alen - 1, blen, pgap, pmismatch) + pgap;
		int sgap = seqAlignment(a, b, alen, blen - 1, pgap, pmismatch) + pgap;
		if (fgap < minVal)
			minVal = fgap;
		if (sgap < minVal)
			minVal = sgap;
		dp[alen][blen] = minVal;
	}
	return dp[alen][blen];
}

int main()
{
	int pgap = 2, pmismatch = 1;
	for (int i = 0; i < 100;++i)
	for (int j = 0; j < 100; ++j)
	{
		dp[i][j] = -1;
	}
	for (int i = 0; i < 100; ++i)
	{
		dp[i][0] = pgap * i;
		dp[0][i] = pgap * i;
	}

	cout << seqAlignment("Abhishek", "Ahirek", 8, 6, pgap, pmismatch)<<endl;
}