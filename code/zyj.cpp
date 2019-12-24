#include "subway.h"

void subway_system::makeGraph(vector<edge>& edges) {
	list<pair<int, int>>tmp;
	for (int i = Stations.size(); i--; )
		E.push_back(tmp);
	for (auto& item : edges) {
		E[item.u].push_back(pair<int, int>(item.v, item.w));
		E[item.v].push_back(pair<int, int>(item.u, item.w));
	}
}

subway_system::subway_system() {
	vector<edge> edges;
	readData(edges);
	for (int i = 0; i < edges.size(); i++)
	{
		int u = edges[i].u, v = edges[i].v, w = edges[i].w;
		cout << station_name[u] << ' ' << station_name[v] << ' ' << w << endl;
	}
	
	makeGraph(edges);
}

void subway_system::readData(vector<edge>& edges) {
	ifstream fin("srcdata");
	int distance, ID[2];
	string line, station[2];

	while (fin >> line >> station[0] >> station[1] >> distance)
	{
		for (int i = 0; i < 2; i++)
		{
			auto findStation = Stations.find(station[i]);
			//查找不到该站点
			if (findStation == Stations.end()) {
				ID[i] = Stations.size();
				Stations[station[i]] = pair<string, int>(line, ID[i]);
				station_name.push_back(station[i]);
			}
			//该站点是已有线路的站点
			else if ((*findStation).second.first == line)
				ID[i] = Stations[station[i]].second;
			//该站点为换乘站
			else
			{
				char c = '1';
				station[i] += c;
				auto it = Stations.find(station[i]);
				while (it != Stations.end() && (*it).second.first != line)
				{
					station[i].back() = ++c;
					it = Stations.find(station[i]);
				}
				if (it == Stations.end())
				{
					ID[i] = Stations.size();
					Stations[station[i]] = pair<string, int>(line, ID[i]);
					station_name.push_back(station[i]);
				}
				else
					ID[i] = Stations[station[i]].second;

			}
			
		}
		edges.push_back(edge(ID[0], ID[1], distance));
	}

	fin.close();
	cout << Stations.size() << endl;
}

void subway_system::checkLine(string oringin, string destination) {
	




}