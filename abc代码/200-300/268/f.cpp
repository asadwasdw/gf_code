#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);


ll js(string s)
{
    ll res = 0;
    ll cnt = 0;
    for(auto t:s)
    {
        if(t=='X')cnt++;
        else 
        res+= (t-'0')*cnt;
    }
    return res;
}

struct D{
    string s;
    ll w;
}d[N];

bool cmp(D a,D b)
{
    return js(a.s+b.s)>(js(b.s+a.s));
}

void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>d[i].s;
    }

    sort(d+1,d+n+1,cmp);

    string ans="";

    for(int i=1;i<=n;i++){
       // cout<<d[i].s<<" "<<d[i].w<<endl;
        ans+=d[i].s;
    }

    cout<<js(ans)<<endl;

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