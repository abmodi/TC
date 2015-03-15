#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<unordered_set>
using namespace std;

struct Edge
{
	int destination;
	int weight;
};

struct Node
{
	int val;
	vector<Edge> nodes;
};

void generateDirectedGraph(vector<Node>& graph)
{
	graph.resize(10);
	for (int i = 0; i < 10; ++i)
	{
		graph[i].val = rand() % 100;
		int numEdges = rand() % 5;
		graph[i].nodes.resize(numEdges);
		for (int j = 0; j < numEdges; ++j)
		{
			graph[i].nodes[j].destination = rand() % 10;
			graph[i].nodes[j].weight = rand() % 100;
		}
	}
}

void printGraph(const vector<Node>& graph)
{
	for (int i = 0; i < graph.size(); ++i)
	{
		cout << "Vertex " << graph[i].val << endl;
		cout << "Edges" << endl;
		for (int j = 0; j < graph[i].nodes.size(); ++j)
		{
			cout << graph[i].nodes[j].destination << "\t" << graph[i].nodes[j].weight<<endl;
		}
	}
}

int findShortestPath(const vector<Node>& graph, int source, int destination)
{
	map<int, int> distMap;
	distMap[source] = 0;
	unordered_set<int> coveredSet;
	coveredSet.insert(source);
	while (1)
	{
		int nv = -1, minDist = 100000;
		for (const auto& covered : coveredSet)
		{
			vector<Edge> edges = graph[covered].nodes;
			for (int j = 0; j < edges.size(); ++j)
			{
				if (coveredSet.find(edges[j].destination) == coveredSet.end())
				{
					int nd = distMap[covered] + edges[j].weight;
					if (nd < minDist)
					{
						minDist = nd;
						nv = edges[j].destination;
					}
				}
			}
		}
		if (nv == -1)
			return -1;
		coveredSet.insert(nv);
		distMap[nv] = minDist;
		if (nv == destination)
			return distMap[nv];
	}
}

int findShortestPathFast(const vector<Node>& graph, int source, int destination)
{
	// implement it  later
	return 0;
}

int main()
{
	vector<Node> graph;
	generateDirectedGraph(graph);
	printGraph(graph);
	cout << endl << "Distance is " << findShortestPath(graph, 0, 7);
}