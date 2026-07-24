// Problem : https://www.codechef.com/problems/CANDY01
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,c;
    cin >> n >> c;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    int totalCandies = accumulate(nums.begin(), nums.end(), 0);
    if(totalCandies <= c){
        cout << "Yes\n";
    }else{
        cout << "No\n";
    }
    return 0;
}
