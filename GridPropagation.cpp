// Problem : https://www.codechef.com/problems/GRPR01
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    int maxSignal = INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> grid[i][j];
            maxSignal = max(maxSignal, grid[i][j]);
        }
    }
    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<pair<int, int>>q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == maxSignal){
                q.push({i, j});
                dist[i][j] = 0;
            }
        }
    }
    vector<pair<int, int>> sideRowCol = {{-1,0},{-1,-1},{1,0},{0,1},{1,1},{0,-1},{1,-1},{-1,1}};
    int minNoOfHrs = 0;
    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        minNoOfHrs = max(minNoOfHrs, dist[row][col]);
        for(int i=0;i<8;i++){
            int newRow = sideRowCol[i].first + row;
            int newCol = sideRowCol[i].second + col;
            if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && dist[newRow][newCol] == -1){
                dist[newRow][newCol] = dist[row][col] + 1;
                q.push({newRow, newCol});
            }
        }
    }
    cout << minNoOfHrs << "\n";
    return;
}

int main(){
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
