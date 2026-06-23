#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<utility>
#include<queue>
#include<stack>
#include<vector>
#include<map>
#include<set>
using namespace std;
int a[2001][2001];//n=i,k=j
const int mod = 1e9 + 7;
int main(){
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
       a[i][1]++;
    }
    for(int i=2;i<=k;i++){
        for(int j=1;j<=n;j++){
            int t=a[j][i-1];
            for(int l=1;l*j<=n;l++){
                a[l*j][i]+=t;
                a[l*j][i]%=mod;
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans+=a[i][k];
        ans %= 1000000007;
    }
    cout<<ans;
    return 0;
}