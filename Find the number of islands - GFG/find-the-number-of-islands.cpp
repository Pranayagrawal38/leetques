//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void bfs(vector<vector<int>>&vis,int a,int b,vector<vector<char>>& grid){
        vis[a][b]=1;
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        q.push({a,b});
        while(!q.empty()){
            int l=q.front().first;
            int p=q.front().second;
            q.pop();
            for(int di=-1;di<=1;di++){
                for(int dj=-1;dj<=1;dj++){
                    int ni=l+di;
                    int nj=p+dj;
                    if(nj>=0&&nj<m&&ni>=0&&ni<n&&grid[ni][nj]=='1'&&!vis[ni][nj]){
                        vis[ni][nj]=1;
                        q.push({ni,nj});
                    }
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        int c=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]&&grid[i][j]=='1'){
                    c++;
                    bfs(vis,i,j,grid);
                }
            }
        }
        return c;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends