#ifndef SUBWAY_H
#define SUBWAY_H

#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <map>
#include <string>

#define inf 66666666
using namespace std;

//边，(起点，终点，权值)
struct edge
{
	int u, v, w;
	edge(int U, int V, int W = inf) :u(U), v(V), w(W) {  }
};

//广州地铁查询系统
class subway_system {
private:
	int n;	//站台数
	vector<list<pair<int, int>>>E;	//邻接表
	map<string, pair<string, int>> Stations;//站台对应的线路和编号
	vector<string> station_name;	//编号对应的站台

public:
	// zyj
	subway_system();
	void readData(vector<edge> &edges);
	void makeGraph(vector<edge> &edges);
	string checkLine(string oringin, string destination);

	//zhm
	vector<int> getShortestPath(int a, int b);
};




#endif // !SUBWAY_H
