#include "subway.h"
#include <list>
#include <queue>
#include <stack>
using namespace std;

struct vertex{
    size_t dis;
    int id;
    int path;
    bool known;
    bool operator <(const vertex & v) const {
        return dis > v.dis;
    }
};

vector<int> subway_system::getShortestPath(int a, int b)
{
    vector<int> res;
    //initialize
    vector<vertex> nodes;
    path.resize(n);
    for (size_t i = 0; i < nodes.size(); i++) {
        if(i == a) {
            nodes[i].dis = 0;
            nodes[i].known = true;
        }
        else {
            nodes[i].dis = inf;
            nodes[i].known = false;
        }
        nodes[i].id = i;
        nodes[i].path = i;
    }
    
    //calculating
    priority_queue<vertex> q;
    for (auto & v : nodes) 
        q.push(v);
    while(!q.empty()) {
        vertex & u = q.top();
        q.pop();
        for (auto & entry : E[u.id]) {
            if(!nodes[entry.first].known) {
                if(nodes[entry.first].d > nodes[u.id].d + entry.second) {
                    nodes[entry.first].d = nodes[u.id].d + entry.second;
                    nodes[entry.first].known = true;
                    nodes[entry.first].path = u.id;
            }
        }    
    }
    
    //get path
    stack<int> temp;
    int cur = b;
    temp.push(cur);
    while(nodes[cur].path != a) {
        temp.push(nodes[cur].path);
        cur = nodes[cur].path;
    }
    temp.push(a);
    while(!temp.empty()) {
        res.push_back(temp.top());
        temp.pop();
    }
    return res;
}