// Problem : https://www.codechef.com/problems/CONN01
#include <bits/stdc++.h>
using namespace std;

void depthFirstSearch(vector<vector<int>> &adjacencyList, vector<bool> &visited, int src){
    visited[src] = true;
    for(auto &it : adjacencyList[src]){
        if(!visited[it]){
            depthFirstSearch(adjacencyList,visited,it);
        }
    }
}

int numberOfConnectedComponents(vector<vector<int>> &adjacencyList){
    int v = adjacencyList.size();
    vector<bool> visited(v, false);
    int numberOfProvinces = 0;
    for(int i=1;i<v;i++){
        if(!visited[i]){
            numberOfProvinces++;
            depthFirstSearch(adjacencyList,visited,i);
        }
    }
    return numberOfProvinces;
}

void dfs(vector<vector<int>> &adjacencyList, vector<bool> &visited, int src, int &cnt){
    visited[src] = true;
    cnt++;
    for(auto &it : adjacencyList[src]){
        if(!visited[it]){
            dfs(adjacencyList,visited,it,cnt);
        }
    }
}

int numberOfGroupLeaders(vector<vector<int>> &adjacencyList){
    int v = adjacencyList.size();
    long long totalGroupLeaders = 1;
    long long MOD = 1e9 + 7;
    vector<bool> visited(v, false);
    for(int i=1;i<v;i++){
        if(!visited[i]){
            int cnt = 0;
            dfs(adjacencyList,visited,i,cnt);
            totalGroupLeaders = (totalGroupLeaders * cnt) % MOD;
        }
    }
    return totalGroupLeaders;
}

void solve(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> adjacencyList(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u);
    }
    cout << numberOfConnectedComponents(adjacencyList) << " ";
    cout << numberOfGroupLeaders(adjacencyList) << "\n";
    return;
}

int main(){
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
