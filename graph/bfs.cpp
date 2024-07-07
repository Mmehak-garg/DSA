vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    int vis[n] = {0};
    queue<int> q;
    vector<int> ans;
    q.push(0);
    vis[0] = 1;
    for(int i = 1;i<n;i++){
        if(!vis[i]) {
            // BFS 
          while(!q.empty()){
                int a = q.front();
                q.pop();

                ans.push_back(a);
                //puah the neibious of q
                for(int i =0 ;i<adj[a].size();i++)
                {
                    if(vis[adj[a][i]] == 0){
                       q.push(adj[a][i]);
                       vis[adj[a][i]] =1;
                    } 
                }
            }
         }
    }
    
    return ans ;
}
// depending upon what type of graph is given connected, directes ,undirected 
// Time Complexity: O(N) + O(2E), Where N = Nodes, 2E is for total degrees as we traverse all adjacent nodes.
// Space Complexity: O(3N) ~ O(N), Space for queue data structure visited array and an adjacency list