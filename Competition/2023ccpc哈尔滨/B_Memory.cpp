#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);
typedef long double db;

void solve()
{

    int n;cin>>n;
    ll a=0;
    bool xs = false;
    //cout<<floor((-3.0)/2)<<endl;
    for(int i=1;i<=n;i++){
        ll x;cin>>x;
        if(a%2)xs=true;

        a=floor(a/2.0)+x;

        if(a==0){
            if(xs)cout<<"+";
            else cout<<"0";
        }
        else if(a>0)cout<<"+";
        else cout<<"-";
    }
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