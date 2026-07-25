// Problem : https://www.codechef.com/problems/SBMD

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    vector<int> ans;
    multiset<int> low;
    multiset<int> high;
    for(int i=0;i<n;i++){
        low.insert(nums[i]);
        high.insert(*low.rbegin());
        low.erase(prev(low.end()));
        
        if(low.size() < high.size()){
            low.insert(*high.begin());
            high.erase(high.begin());
        }
        
        if(i >= k){
            int outgoingElement = nums[i-k];
            if(outgoingElement <= *low.rbegin()){
                low.erase(low.find(outgoingElement));
            }else{
                high.erase(high.find(outgoingElement));
            }
            
            if(low.size() < high.size()){
                low.insert(*high.begin());
                high.erase(high.begin());
            }else if(low.size() > high.size() + 1){
                high.insert(*low.rbegin());
                low.erase(prev(low.end()));
            }
        }
        
        if(i >= k-1){
            ans.push_back(*low.rbegin());
        }
    }
    
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << " ";
    }
    return 0;
}
