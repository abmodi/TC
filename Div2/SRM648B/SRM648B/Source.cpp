#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<numeric>
#include<set>
#include<queue>
using namespace std;

class Fragile2
{
public:
	int count(const vector<string>& graph, int a, int b)
	{
		int res = 0;
		set<int> covered;
		covered.insert(a);
		covered.insert(b);
		for (int i = 0; i < graph.size(); ++i)
		{
			if (covered.find(i) == covered.end())
			{
				++res;
				queue<int> q;
				q.push(i);
				while (!q.empty())
				{
					int ind = q.front();
					q.pop();
					if (covered.find(ind) == covered.end())
					{
						covered.insert(ind);
						for (int j = 0; j < graph[ind].size(); ++j)
						{
							if (graph[ind][j] == 'Y')
							{
								q.push(j);
							}
						}
					}
				}
			}
		}
		return res;
	}
	int countPairs(vector <string> graph)
	{
		int cp = count(graph, -1, -1);
		int res = 0;
		for (int i = 0; i < graph.size()-1; ++i)
		for (int j = i + 1; j < graph.size(); ++j)
		{
			if (count(graph,i, j) > cp)
				++res;
		}
		return res;
	}
};

int main()
{
	Fragile2 f;
	vector<string> inp = { "NYNNNN", "YNYNNN", "NYNNNN", "NNNNYN", "NNNYNY", "NNNNYN" };
	f.countPairs(inp);
}