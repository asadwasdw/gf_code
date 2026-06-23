#include<bits/stdc++.h>
using namespace std;
typedef pair<long double,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;

PII a[N];

bool cmp(PII a,PII b)
{
    if(a.first!=b.first)return a.first>b.first;
    return a.second<b.second;
}


void solve()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        long double x,y;
        cin>>x>>y;
        a[i]={x/(x+y),i};
    }

    sort(a+1,a+n+1,cmp);

    for(int i=1;i<=n;i++)cout<<a[i].second<<" ";





}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}