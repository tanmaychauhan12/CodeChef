// Problem : https://www.codechef.com/problems/CHEFGEM
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int k,n;
    cin >> k >> n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    vector<int> ans;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0;i<n;i++){
        if(pq.size() < k-1){
            ans.push_back(-1);
            pq.push(nums[i]);
        }else if(pq.size() == k-1){
            pq.push(nums[i]);
            ans.push_back(pq.top());
        }else{
            pq.push(nums[i]);
            pq.pop();
            ans.push_back(pq.top());
        }
    }
    for(int &it : ans){
        cout << it << " ";
    }
    cout << "\n";
    return;
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
