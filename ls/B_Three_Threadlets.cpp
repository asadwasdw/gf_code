#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);


void solve()
{
    ll a,b,c;
    cin>>a>>b>>c;
    ll sum = (a+b+c);

    bool ky = false;
    for(int i = 0; i <= 3; i++) {
        ll t = i + 3;
        if(sum % t) continue;
        t = sum / t;
        if(!(a % t || b % t || c % t)) ky = true;
    }
    if(ky)cout<<"YES\n";
    else cout<<"NO\n";

 
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