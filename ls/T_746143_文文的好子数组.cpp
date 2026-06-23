#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,a[1000005],cnt,k,sum;
vector <int> ans;

signed main(){
cin>>n>>k;
for(int i=1;i<=n;i++){
cin>>a[i];
}
deque <int> dq;
for(int i=1;i<=n;i++){
sum+=a[i];
if(i>k){
sum-=a[i-k];
}
while(!dq.empty() && a[dq.back()] <= a[i]){
dq.pop_back();
}

if(dq.front()<=i-k){
dq.pop_front();
}
dq.push_back(i);
if(i>=k){
    long long mx=a[dq.front()];
    if(sum == 2*mx){
    ans.push_back(i-k+1);
}
}
}
cout<<ans.size()<<" ";
for(int i=0;i<ans.size();i++){
cout<<ans[i]<<" ";
}
return 0;
}