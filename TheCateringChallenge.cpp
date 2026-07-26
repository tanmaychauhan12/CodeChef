#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,d;
    cin >> n >> d;
    long long totalLatePenalties = 0;
    vector<vector<pair<int,int>>> order(d+1);
    for(int i=0;i<n;i++){
        int di,t;
        long long s;
        cin >> di >> t >> s;
        totalLatePenalties += t * s;
        if(di <= d){
            order[di].push_back({s,t});
        }
    }
    priority_queue<pair<long long, int>> pq;
    for(int i=1;i<=d;i++){
        for(auto &it : order[i]){
            pq.push(it);
        }
        if(!pq.empty()){
            long long currentPenalty = pq.top().first;
            int remainingDays = pq.top().second;
            pq.pop();
            totalLatePenalties -= currentPenalty;
            remainingDays--;
            if(remainingDays > 0){
                pq.push({currentPenalty, remainingDays});
            }
        }
    }
    cout << totalLatePenalties << "\n";
    return;
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
