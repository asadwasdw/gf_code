#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);

priority_queue<int,vector<int>,greater<int>>a;
priority_queue<PII,vector<PII>,greater<PII>>d;
int ans[N];

void solve()
{

    int n,m;
    cin>>n>>m;

    for(int i=1;i<=n;i++)a.push(i);

    for(int i=1;i<=m;i++)
    {
        int t,w,s;
        cin>>t>>w>>s;

        while( d.size() && d.top().first<=t)
        {
            a.push({d.top().second});
            d.pop();
        }

        if(a.size())
        {
            d.push({t+s,a.top()});
            ans[a.top()]+=w;
            a.pop();
        }
    }

    for(int i=1;i<=n;i++){
        cout<<ans[i]<<"\n";
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