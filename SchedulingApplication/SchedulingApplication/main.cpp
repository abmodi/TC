#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

struct Event
{
	int weight;
	int time;
	bool operator <(const Event& e)
	{
		return ((float)(weight) / time) > ((float)(e.weight) / e.time);
	}
};

void printEvents(const vector<Event>& events)
{
	for (int i = 0; i < events.size(); ++i)
	{
		cout << events[i].weight << " " << events[i].time << endl;
	}
}

int main()
{
	vector<Event> events;
	events.resize(10);
	for (int i = 0; i < 10; ++i)
	{
		events[i].time = rand() % 100 + 1;
		events[i].weight = rand() % 100 + 1;
	}
	sort(events.begin(), events.end());
	printEvents(events);
}
