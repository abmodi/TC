#include<iostream>
#include<math.h>
#include<algorithm>
#include<map>
#include<set>

using namespace std;

class KitayutaMart2
{
public:
	int numBought(int K, int T)
	{
		int count = 0, num = 0;
		while (T)
		{
			++count;
			T -= (K*pow(2, num));
			++num;
		}
		return count;
	}
};

int main()
{

}