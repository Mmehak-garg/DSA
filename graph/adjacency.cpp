// undirected graphs (not necessarily connected) can be constructed out of a given n number of vertices.=pow(2,(n*(n-1)/2));

//Adjacency Matrix

int main()
{
    int n, m;
    cin >> n >> m;
    // adjacency matrix for undirected graph
    // time complexity: O(n)
    // sc -> o(n^2)
    int adj[n+1][n+1];
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1  // this statement will be removed in case of directed graph
    }
    return 0;
}
// Adjacency Lists
//  time complexity: O(2E)
// Space complexity = O(2xE)
// by using vector
vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges) {
   vector<int> ans[n]; // veector of vectors 
    for(int i =0;i<m;i++){
        int u = edges[i][0];
        int v = edges[i][1];

        ans[u].push_back(v);
        ans[v].push_back(u); 
    }
    vector<vector<int>>adj(n);
    for(int i = 0;i<n;i++){
        adj[i].push_back(i);

        for(int j = 0;j<ans[i].size();j++){
            adj[i].push_back(ans[i][j]);
        }
    }
    return adj;

}

// by using map and list 
class graph{
  public:
  
  unordered_map<int,list<int>> adj;
  void addEdge(int u ,int v,bool direction){
      adj[u].push_back(v);
      if(!direction){
          adj[v].push_back(u);
      }
  }
  void printAdjList(){
      for(auto i: adj){
          cout<< i.first << "->";
          for(auto j : i.second){
              cout<<j<<", ";
          }
          cout<<endl;
      }
  }
};
