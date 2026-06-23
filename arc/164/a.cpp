#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;


void solve()
{
    ll n,k;
    cin>>n>>k;
    int cnt = 0;


    while(n)
    {
        if(n%3==2)cnt+=2;
        if(n%3==1)cnt++;
        n/=3;
    }
    //cout<<cnt<<endl;
    if(cnt<=k&& (k-cnt)%2==0)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}