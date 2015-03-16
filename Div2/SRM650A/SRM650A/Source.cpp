#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>

using namespace std;

class TaroJiroDividing
{
public:
	int getNumber(int A, int B)
	{
		int count = 0;
		set<int> a;
		while (A%2 == 0 && A != 0)
		{
			a.insert(A);
			A = A / 2;
		}
		a.insert(A);
		while (B % 2 == 0 && B != 0)
		{
			if (a.find(B) != a.end())
				++count;
			B = B / 2;
		}
		if (a.find(B) != a.end())
			++count;
		return count;
	}
};
