#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

class Solution {
    map<string, vector<pair<string, double> > > graph;
    public:
    void addEdge(string p1, string p2, double v) {
        graph[p1].push_back(make_pair(p2, v));
    }
    double bfs(string p1, string p2) {
        map<string, int> isVisited;
        queue<pair<string, double> > q;
        isVisited[p1] = 1;
        q.push(make_pair(p1, 1.0));
        while (!q.empty()) {
            pair<string, double> now = q.front();
            q.pop();
            vector<pair<string, double> > edges = graph[now.first];
            for (int i=0; i<edges.size(); ++i) {
                pair<string, double> e = edges[i];
                if (e.first == p2) {
                     return now.second * e.second;
                } else if (isVisited.find(e.first) == isVisited.end()){
                     q.push(make_pair(e.first, now.second * e.second));
                     isVisited[e.first]=1;
                }
            }
        }
        return -1.0;
    }
    vector<double> calcEquation(vector<pair<string, string> > equations, vector<double>& values, vector<pair<string, string> > queries) {
        vector<double> result;
        for (int i=0; i<equations.size(); ++i) {
            addEdge(equations[i].first, equations[i].second, values[i]);
            addEdge(equations[i].second, equations[i].first, 1.0 / values[i]);
        }
        for (int i=0; i<queries.size(); i++) {
            result.push_back(bfs(queries[i].first, queries[i].second));
        }
        return result;
    }
};

int main() {
    vector<pair<string, string> > equations;
    equations.push_back(make_pair("a", "b"));
    vector<double> values;
    values.push_back(2.0);
    Solution s;
    s.calcEquation(equations, values, equations);
}
