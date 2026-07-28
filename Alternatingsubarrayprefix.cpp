#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    vector<int> dp(n, 1);
    for(int i=n-2;i>=0;i--){
        if((nums[i+1] > 0 && nums[i] < 0) || (nums[i+1] < 0 && nums[i] > 0)){
            dp[i] += dp[i+1];
        }
    }
    for(int i=0;i<n;i++){
        cout << dp[i] << " ";
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
