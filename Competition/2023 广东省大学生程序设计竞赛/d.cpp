#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;

typedef pair<int,int> PII;

vector<PII>a;


bool cmp(PII a,PII b)
{
    return a.first-a.second>b.first-b.second;
}

void solve()
{
    a.clear();
    ll ans=0,now=0;
    int n,m;
    cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        int x,y;
        cin>>x>>y;
        now+=y;
        a.push_back({x,y});
    }

    sort(a.begin(),a.end(),cmp);


    if(m>=2*n-1)ans=now;

    now+=a[0].first-a[0].second;
    
    for(int i=2;i<=n;i++)
    {
        now+=(a[i-1].first-a[i-1].second);
       // cout<<now<<endl;
        if (2 * n - i <= m)ans=max(ans,now);
    }

    cout<<ans<<endl;





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