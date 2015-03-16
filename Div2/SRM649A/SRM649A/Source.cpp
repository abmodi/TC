#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class DecipherabilityEasy
{
public:
	string check(string s, string t)
	{
		if (s.length() - t.length() != 1)
			return "Impossible";
		string p = "";
		int i = 0;
		for (; i < t.length(); ++i)
		{
			if (s[i] == t[i])
				p += s[i];
			else
				break;
		}
		++i;
		for (; i < s.length(); ++i)
			p += s[i];
		if (p == t)
			return "Possible";
		return "Impossible";
	}
};

int main()
{

}