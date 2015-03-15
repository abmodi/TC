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
		int y = i - 3;
		if (y < 0)
			y += 10;
		graph[i].nodes.push_back(y%10);
		graph[i].nodes.push_back((i + 3) % 10);
	}
}

void DFS(const vector<Node>& graph, int index)
{
	static unordered_set<int> seen;
	seen.insert(index);
	cout << graph[index].val << endl;
	for (int i = 0; i < graph[index].nodes.size(); ++i)
	{
		if (seen.find(graph[index].nodes[i]) == seen.end())
			DFS(graph, graph[index].nodes[i]);
	}
}

int main()
{
	vector<Node> graph;
	generateUDGraph(graph);
	cout << "DFS" << endl;
	DFS(graph, 0);
}