#include <bits/stdc++.h>
using namespace std;
const int N=4e4+5;
int n,m,w[105],v[105],nn;
long long dp[105][N];

int main(){
cin>>n>>m;
for(int i=1,v1,w1,p1;i<=n;i++){
cin>>v1>>w1>>p1;
for(int j=1;j<=p1;j*=2){
nn++;
v[nn] = v1*j;
w[nn] = w1*j;
p1-=j;
}
if(p1){
nn++;
v[nn] = v1*p1;
w[nn] = w1*p1;
}
}
for(int i=1;i<=nn;i++){
for(int j=0;j<=m;j++){
dp[i][j] = max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
}
}
cout<<dp[n][m];
return 0;
}