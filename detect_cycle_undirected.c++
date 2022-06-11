// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycleUtil(int V, vector<int> adj[], int start) {
        stack<pair<int, int>> s;
        vector<bool> visited(V);
        s.push({start, -1});
        visited[start] = true;
        while (!s.empty()) {
            pair<int, int> p = s.top();
            s.pop();
            for (int i:adj[p.first]) {
                if (!visited[i]) {
                    s.push({i, p.first});
                    visited[i] = true;
                } else if (i != p.second) return true;
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        for (int i = 0; i < V; i ++) {
            if (isCycleUtil(V, adj, i)) return true;
        }   
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends
