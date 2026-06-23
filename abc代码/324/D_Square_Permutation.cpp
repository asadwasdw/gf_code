#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);
int n;
int a[N];
int st[N];
ll ans = 0;
multiset<ll>s;

bool pd(ll x)
{
    multiset<ll>t = s;

    while(x){
        int X = x%10;
        x/=10;
        auto tt = t.find(X);
        if(tt==t.end())
        {
            return false;
        }
        t.erase(tt);
    }

    for(auto X:t){
        if(X)return false;
    }
    return true;
}

void solve()
{
    cin>>n;
    for(int i = 1;i<=n;i++){
        char t;cin>>t;
        a[i] = t - '0';
        s.insert(a[i]);
    }

    for(ll i=0; i*i<=1e14;i++){
        if(pd(i*i))ans++;
    }
    cout<<ans<<endl;
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