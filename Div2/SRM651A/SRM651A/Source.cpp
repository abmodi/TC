#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>

using namespace std;

class RobotOnMoonEasy
{
public:
	string isSafeCommand(vector <string> board, string S)
	{
		int ri, rj;
		int bw = board[0].size();
		int bl = board.size();
		for (int i = 0; i < bl; ++i)
		{
			for (int j = 0; j < bw; ++j)
			{
				if (board[i][j] == 'S')
				{
					ri = i;
					rj = j;
					break;
				}
			}
		}
		for (int i = 0; i < S.size(); ++i)
		{
			if (S[i] == 'U')
			{
				if (ri == 0)
					return "Dead";
				if (board[ri - 1][rj] != '#')
					--ri;
			}
			if (S[i] == 'D')
			{
				if (ri == bl - 1)
					return "Dead";
				if (board[ri + 1][rj] != '#')
					++ri;
			}
			if (S[i] == 'L')
			{
				if (rj == 0)
					return "Dead";
				if (board[ri][rj - 1] != '#')
					--rj;
			}
			if (S[i] == 'R')
			{
				if (rj == bw - 1)
					return "Dead";
				if (board[ri][rj + 1] != '#')
					++rj;
			}
		}
		return "Alive";
	}
};
