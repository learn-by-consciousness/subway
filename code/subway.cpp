#include "subway.h"
#include <list>
#include <queue>
#include <stack>
using namespace std;

struct vertex {
	size_t dis;
	int id;
	int path;
	bool known;
	bool popped;
};

bool empty(vector<vertex> &nodes) {
	bool flag = true;
	for (auto& entry : nodes) {
		if (entry.popped == false)
			flag = false;
	}
	return flag;
}

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

vector<int> subway_system::getShortestPath(int a, int b)
{
	vector<int> res;
	//initialize
	vector<vertex> nodes;
	nodes.resize(n);
	for (size_t i = 0; i < nodes.size(); i++) {
		if (i == a) {
			nodes[i].dis = 0;
			nodes[i].known = true;
		}
		else {
			nodes[i].dis = inf;
			nodes[i].known = false;
		}
		nodes[i].id = i;
		nodes[i].path = i;
		nodes[i].popped = false;
	}

	//calculating
	
	while (!empty(nodes)) {
		int index = find(nodes);
		nodes[index].popped = true;
		vertex u = nodes[index];
		for (auto& entry : E[u.id]) {
			if (!nodes[entry.first].known) {
				if (nodes[entry.first].dis > nodes[u.id].dis + entry.second) {
					nodes[entry.first].known = true;
					nodes[entry.first].dis = nodes[u.id].dis + entry.second;
					nodes[entry.first].path = u.id;
				}
			}
		}
	}
	//get path
	stack<int> temp;
	int cur = b;
	temp.push(cur);
	while (nodes[cur].path != a) {
		temp.push(nodes[cur].path);
		cur = nodes[cur].path;
	}
	temp.push(a);
	while (!temp.empty()) {
		res.push_back(temp.top());
		temp.pop();
	}
	return res;
}