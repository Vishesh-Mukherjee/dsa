// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        stack<int> s;
        bool visited[V] = {0};
        vector<int> res;
        s.push(0);
        while (!s.empty()) {
            int data = s.top();
            s.pop();
            if (!visited[data]) {
                res.push_back(data);
                visited[data] = true;
            }
            vector<int> temp = adj[data];
            for (int i = temp.size()-1; i >= 0; i --) {
                if (!visited[temp[i]]) s.push(temp[i]);
            }
        }
        return res;
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
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends
