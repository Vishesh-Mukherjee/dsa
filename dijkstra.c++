// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    
    int minDist(vector<int> dist, vector<bool> minSpt) {
        int min = INT_MAX, minIndex;
        for (int i = 0; i < dist.size(); i ++) {
            if (dist[i] <= min and !minSpt[i]) {
                min = dist[i];
                minIndex = i;
            }
        }
        return minIndex;
    }
    
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
            vector<int> dist(V, INT_MAX);
            vector<bool> minSpt(V);
            vector<vector<int>> adjMatrix(V, vector<int>(V));
            for (int i = 0; i < V; i ++) {
                for (int j = 0; j < adj[i].size(); j ++) {
                    adjMatrix[i][adj[i][j][0]] = adj[i][j][1];
                }
            }
            dist[S] = 0;
            for (int i = 0; i < V-1; i ++) {
                int u = minDist(dist, minSpt);
                minSpt[u] = true;
                for (int j = 0; j < V; j ++) {
                    if (adjMatrix[u][j] and dist[u] != INT_MAX and !minSpt[j] and dist[j] > dist[u]+adjMatrix[u][j]) {
                        dist[j] = dist[u] + adjMatrix[u][j];
                    }
                }
            }
            return dist;
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends
