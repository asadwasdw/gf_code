#include <bits/stdc++.h>
using namespace std;
const int L=2e5+100;
stack<int> sta;
int maxi[L];

int main(){
int n,x,z,m;
cin>>n;
for(int i=1;i<=n;i++){
cin>>m;
z=sta.size();
if(m == 0){
cin>>x;
sta.push(x);
maxi[z+1]=max(maxi[z],x);
}
else if(m == 1){
if(!sta.empty()) sta.pop();
}
else{
if(sta.empty()){
cout<<0<<endl;
}
else{
cout<<maxi[z]<<endl;
}
}
}
return 0;
}