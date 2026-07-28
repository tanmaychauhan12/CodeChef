#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    long long countSubarrays = 0;
    int j = 0;
    for(int i=1;i<n;i++){
        if(nums[i] < nums[i-1]){
            long long len = i - j;
            countSubarrays += len*(len+1)/2;
            j = i;
        }
    }
    if(j==n-1){
        countSubarrays += 1;
    }else{
        countSubarrays += (n-j)*(n-j+1)/2;
    }
    cout << countSubarrays << "\n";
    return;
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
