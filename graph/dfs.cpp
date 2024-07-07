// DFS is a traversal technique which involves the idea of recursion and backtracking

#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int>& vis, vector<int> adj[], vector<int>& comp) {
    comp.push_back(node);
    vis[node] = 1;

    // Recursive call for connected nodes
    for (int it : adj[node]) {
        if (!vis[it]) {
            dfs(it, vis, adj, comp);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>>& edges) {
    // Create the adjacency list
    vector<int> adj[V];
    vector<int> vis(V, 0); // Initialize the vis vector with 0

    for (int i = 0; i < edges.size(); i++) {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }

    // Traverse all the components using DFS
    vector<vector<int>> ans;
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            vector<int> comp;
            dfs(i, vis, adj, comp);
            ans.push_back(comp);
        }
    }
    return ans;
}