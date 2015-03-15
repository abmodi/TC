#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>

using namespace std;

struct Node
{
	int val;
	vector<int> nodes;
};

void generateUDGraph(vector<Node>& graph)
{
	graph.resize(10);
	for (int i = 0; i < 10; ++i)
	{
		graph[i].val = rand() % 100;
		cout << graph[i].val << endl;
		graph[i].nodes.push_back( (i+3)%10 );
		//graph[i].nodes.push_back(y);
	}
}

void BFS(vector<Node> graph)
{
	unordered_set<int> seen;
	queue< int > q;
	q.push(0);
	seen.insert(0);
	cout << graph[0].val << endl;
	while (!q.empty())
	{
		Node n = graph[q.front()];
		q.pop();
		for (int i = 0; i < n.nodes.size(); ++i)
		{
			if (seen.find(n.nodes[i]) == seen.end())
			{
				int val = graph[n.nodes[i]].val;
				cout << val<< endl;
				seen.insert(n.nodes[i]);
				q.push(n.nodes[i]);
			}
		}
	}
}

int main()
{
	vector<Node> graph;
	generateUDGraph(graph);
	cout << "BFS" << endl;
	BFS(graph);
}