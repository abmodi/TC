#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>

using namespace std;

class ValueOfString
{
public:
	int findValue(string s)
	{
		int cnt[26] = { 0 };
		for (auto ch : s)
		{
			cnt[ch - 'a']++;
		}
		for (int i = 1; i < 26; ++i)
			cnt[i] += cnt[i - 1];
		int res = 0;
		for (auto ch : s)
			res += (ch - 'a' + 1) * cnt[ch - 'a'];
		return res;
	}
};
