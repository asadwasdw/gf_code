#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);


void solve()
{
    ll x,y,k;
    cin>>x>>y>>k;

    if(x==0||y==0)
    {
        if(k%max(x,y)){
            cout<<"NO";
        }
        else cout<<"YES";
    }
    else 
    {
        ll g = __gcd(x,y);
        if((abs(k-x)%g==0||abs(k-y)%g==0)&&(k!=0)){
            cout<<"YES";
        }
        else cout<<"NO";
    }
    cout<<endl;
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