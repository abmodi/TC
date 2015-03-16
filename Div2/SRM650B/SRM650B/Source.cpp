#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<numeric>

using namespace std;

class TaroFillingAStringDiv2
{
public:
	int getN(string S)
	{
		int res = 0;
		for (int i = 1; i < S.size(); ++i)
		{
			if (S[i] == S[i - 1])
				++res;
		}
		return res;
	}
	int getNumber(string S)
	{
		int i = 0;
		for (i = 0; i < S.size(); ++i)
		{
			if (S[i] != '?')
			{
				break;
			}
		}
		S = S.substr(i);
		for (int i = 0; i < S.size(); ++i)
		{
			if (S[i] == '?')
			{
				if (S[i - 1] == 'A')
					S[i] = 'B';
				else
					S[i] = 'A';
			}
		}
		return getN(S);
	}
};