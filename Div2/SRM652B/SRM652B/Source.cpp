#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>

using namespace std;

class ThePermutationGameDiv2
{
public:
	long long gcd(long long a, long long b)
	{
		if (a < b)
		{
			swap(a, b);
		}
		if (a % b == 0)
			return b;
		return gcd(b, a%b);
	}

	long long lcm(long long a, long long b)
	{
		long long hcf = gcd(a, b);
		return (a / hcf)*b;
	}

	long long findMin(int N)
	{
		long long res = 1;
		for (int i = N; i > 1; --i)
		{
			res = lcm(res, i);
		}
		return res;
	}
};

int main()
{
	ThePermutationGameDiv2 p;
	p.findMin(25);
}
