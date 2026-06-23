#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;


PII p[N];

void solve()
{

    int n;cin>>n;
   // vector<PII>p(n+1);
    for(int i=1;i<=n;i++){
        cin>>p[i].first>>p[i].second;
    }
    
    sort(p+1,p+n+1);
    int x=-1;
    int now  =1;
    priority_queue<int,vector<int>,greater<int>>q;

    int ans = 0;
    while(1)
    {
        while(q.size()&&q.top()<x)q.pop();
        if(!q.size())
        {
            if(now>n)break;
            x = p[now].first;
        }
        else 
        {
            ans++;
            x++;
            q.pop();
        }

        while(now<=n&&p[now].first<=x)
        {
            q.push(p[now].second);
            now++;
        }

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