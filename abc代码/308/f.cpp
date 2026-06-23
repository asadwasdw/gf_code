#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;


ll w[N];
PII q[N];
bool st[N];


bool cmp(PII a,PII b)
{
    if(a.first!=b.first)return a.first<b.first;
    return a.second>b.second;
}

bool cmp2(int a,int b){
    return a<b;
}

void solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>w[i];
    sort(w+1,w+n+1,cmp2);

    for(int i=1;i<=m;i++)cin>>q[i].first;
    for(int i=1;i<=m;i++)cin>>q[i].second;

    sort(q+1,q+m+1,cmp);

    ll ans=0;
    int j=1;
    priority_queue<int>p;
    for(int i=1;i<=n;i++)
    {
        while(j<=m&&q[j].first<=w[i])
        {
            p.push(q[j].second);
            j++;
        }

        if(p.size())
        {
            w[i]-=p.top();
            p.pop();
        }

        ans+=w[i];
        
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