//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> ans;
        bool vis[V] = {0};
        queue<int> q;
        q.push(0);
        vis[0] = 1;
        while(!q.empty()) {
            int j = q.front();
            ans.push_back(j);
            q.pop();
            for(int i = 0; i < adj[j].size(); ++i) {
                if(adj[j][i]) {
                    if(!vis[adj[j][i]]) {
                        vis[adj[j][i]] = 1;
                        q.push(adj[j][i]);
                    }    
                }
            } 
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends