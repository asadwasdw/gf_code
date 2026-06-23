#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,kt,s[25],t[25],c[25],a[25],b[25],p[25],m[25];
int st[25],ans=2e9;

void dfs(int id,int sum){
if(id>kt){
bool ggggg=1; 
for(int i=1;i<=n;i++){
for(int j=s[i];j<=t[i];j++){
if(st[j]<c[i]) ggggg = 0;
}
}
if(ggggg) ans = min(ans,sum);
return;
}
dfs(id+1,sum);
for(int i=a[id];i<=b[id];i++) st[i] += p[id];
dfs(id+1,sum+m[id]);
for(int i=a[id];i<=b[id];i++) st[i] -= p[id];
}

signed main(){
cin>>n>>kt;
for(int i=1;i<=n;i++){
cin>>s[i]>>t[i]>>c[i];
}
for(int i=1;i<=kt;i++){
cin>>a[i]>>b[i]>>p[i]>>m[i];
}
dfs(1,0);
cout<<ans;
return 0;
}