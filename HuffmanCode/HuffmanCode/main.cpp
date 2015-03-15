#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<queue>

using namespace std;

struct Node
{
	string name;
	int percentage;
	Node* left;
	Node* right;
};

struct QueueObj
{
	string name;
	int percentage;
	Node* thiz;
	QueueObj(const string& n, int per) : name(n), percentage(per), thiz(NULL) {}
	bool operator <(const QueueObj& q) const
	{
		return percentage > q.percentage;
	}
};

void generateCodes(Node* root, map<string, string>& codeMap, const string& code)
{
	if (root == NULL)
		return;
	if (root->left == NULL && root->right == NULL)
	{
		codeMap[root->name] = code;
		return;
	}
	generateCodes(root->left, codeMap, code + "0");
	generateCodes(root->right, codeMap, code + "1");
}

void generateHuffmanCode(const map<string, int>& input, map<string, string>& output)
{
	priority_queue<QueueObj> q;
	for (auto iter: input)
	{
		q.push(QueueObj(iter.first, iter.second));
	}
	while (q.size() > 1)
	{
		QueueObj first= q.top();
		q.pop();
		QueueObj second = q.top();
		q.pop();
		Node* firstNode = first.thiz;
		Node* secondNode = second.thiz;
		if (firstNode == NULL)
		{
			firstNode = new Node();
			firstNode->left = NULL;
			firstNode->right = NULL;
			firstNode->name = first.name;
			firstNode->percentage = first.percentage;
		}
		if (secondNode == NULL)
		{
			secondNode = new Node();
			secondNode->left = NULL;
			secondNode->right = NULL;
			secondNode->name = second.name;
			secondNode->percentage = second.percentage;
		}
		Node* parentNode = new Node();
		parentNode->left = firstNode;
		parentNode->right = secondNode;
		parentNode->name = firstNode->name + secondNode->name;
		parentNode->percentage = firstNode->percentage + secondNode->percentage;
		QueueObj parent(parentNode->name, parentNode->percentage);
		parent.thiz = parentNode;
		q.push(parent);
	}
	QueueObj parent = q.top();
	q.pop();
	Node* root = parent.thiz;
	generateCodes(root, output, "");
}

int main()
{
	map<string, int> input = { { "A", 50 }, { "B", 30 }, { "C", 10 }, { "D", 5 }, { "E", 5 } };
	map<string, string> output;
	generateHuffmanCode(input, output);
	for (auto iter : output)
	{
		cout << iter.first << " " << iter.second << endl;
	}
}