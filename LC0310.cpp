class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int> d(n, 0);
        vector<int> s(n, 0);
        vector<vector<int>> g(n);
        for (int i=0; i<edges.size(); i++) {
            d[edges[i].first]++;
            d[edges[i].second]++;
            g[edges[i].first].push_back(edges[i].second);
            g[edges[i].second].push_back(edges[i].first);
        }
        while(judge(d)>2) {
            vector<int> d0;
            for (int i=0; i<d.size(); i++) {
                if (d[i]==1) {
                    d0.push_back(i);
                }
            }
            for (int i=0; i<d0.size(); i++) {
                int p = d0[i];
                d[p]--;
                s[p]=1;
                for (int j=0; j<g[p].size(); j++) {
                    if (d[g[p][j]] > 0) d[g[p][j]]--;
                }
            }
        }
        vector<int> res;
        for (int i=0; i<s.size(); i++) {
            if (s[i] == 0) {
                res.push_back(i);
            }
        }
        return res;
    }

    int judge(vector<int> d) {
        int sum = 0;
        for (int i=0; i<d.size(); i++) {
            if (d[i]>0) {
                sum++;
            }
        }
        return sum;
    }
};
