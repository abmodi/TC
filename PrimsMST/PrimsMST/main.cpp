#include<iostream>
#include<vector>
#include<queue>
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
	const int GRAPH_SIZE = 5;
	graph.resize(GRAPH_SIZE);
	for (int i = 0; i < GRAPH_SIZE; ++i)
	{
		graph[i].val = rand() % 100;
		int numEdges = rand() % 5;
		graph[i].nodes.resize(numEdges);
		for (int j = 0; j < numEdges; ++j)
		{
			graph[i].nodes[j].destination = rand() % GRAPH_SIZE;
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
			cout << graph[i].nodes[j].destination << "\t" << graph[i].nodes[j].weight << endl;
		}
	}
}

struct QueueObj
{
	int n;
	int dist;
	bool operator <(const QueueObj& q) const
	{
		return dist > q.dist;
	}
	QueueObj(int no, int d) : n(no), dist(d) {}
};

int mst(const vector<Node>& graph)
{
	unordered_set<int> coveredVertices;
	priority_queue<QueueObj> q;
	q.push(QueueObj(0, 0));
	int res = 0;
	while (!q.empty())
	{
		QueueObj que = q.top();
		q.pop();
		if (coveredVertices.find(que.n) == coveredVertices.end())
		{
			coveredVertices.insert(que.n);
			res += que.dist;
			for (auto edge : graph[que.n].nodes)
			{
				if (coveredVertices.find(edge.destination) == coveredVertices.end())
				{
					q.push(QueueObj(edge.destination, edge.weight));
				}
			}
		}
	}
	return res;
}

int main()
{
	vector<Node> graph;
	generateDirectedGraph(graph);
	printGraph(graph);
	cout << "MST " << mst(graph) << endl;
}