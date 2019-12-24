#include "subway.h"


struct vertex {
	size_t dis;
	int id;
	int path;
	bool known;
	bool popped;
	vertex() :dis(inf), known(false), popped(false) {  }
};


int find(vector<vertex>& nodes) {
	int res = 0;
	int min_dis = inf;
	for (auto& entry : nodes) {
		if (entry.popped) continue;
		else
		{
			if (entry.dis < min_dis) {
				min_dis = entry.dis;
				res = entry.id;
			}
		}
	}
	return res;
}

vector<int> subway_system::getShortestPath(int origin, int destination)
{
	vector<int> res;
	set<int> known;
	//initialize
	vector<vertex> nodes;
	nodes.resize(n);
	for (size_t i = 0; i < nodes.size(); i++) {
		nodes[i].id = i;
		nodes[i].path = i;
		nodes[i].popped = false;
	}
	nodes[origin].dis = 0;
	nodes[origin].known = true;
	nodes[origin].path = origin;
	known.insert(origin);
	//calculating
	
	for (int i = 0; i < n; i++) {
		int index = 0, min_dis = inf;
		for(auto &entry:known)
			if (!(nodes[entry].popped) && nodes[entry].dis <min_dis)
			{
				min_dis = nodes[entry].dis;
				index = entry;
			}
		if (index == destination)break;

		nodes[index].popped = true;
		vertex u = nodes[index];

		for (auto& entry : E[u.id]) {
			if (!nodes[entry.first].known) {
				if (nodes[entry.first].dis > nodes[u.id].dis + entry.second) {
					nodes[entry.first].known = true;
					known.insert(entry.first);
					nodes[entry.first].dis = nodes[u.id].dis + entry.second;
					nodes[entry.first].path = u.id;
				}
			}
		}
	}
	//get path
	stack<int> temp;
	int cur = destination;
	temp.push(cur);
	while (nodes[cur].path != origin) {
		cur = nodes[cur].path;
		temp.push(cur);
	}
	temp.push(origin);
	while (!temp.empty()) {
		res.push_back(temp.top());
		temp.pop();
	}
	return res;
}