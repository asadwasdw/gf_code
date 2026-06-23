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

bool cmp(PII a,PII b)
{
    if(a.first!=b.first)return a.first<b.first;
    return a.second<b.second;
}
PII a[N];
priority_queue<int,vector<int>,greater<int>>q;
void solve()
{
    int n;cin>>n;

    for(int i=1;i<=n;i++){
        int x,y;cin>>x>>y;
        a[i] = {x,x+y};
    }
    sort(a+1,a+n+1,cmp);
    a[0]={-1,0};
    int cnt=0,ans=0;
    for(int t=1;;t++) {
        if(q.size()==0){
            if(cnt == n)break;
            t = a[++cnt].first;
            q.push(a[cnt].second);
        }
        while(cnt<n && a[cnt+1].first==t)q.push(a[++cnt].second);
        while(q.size() && q.top()<t)q.pop();
        if(q.size())
        {
            ans++;
           // cout<<q.top()<<endl;
            q.pop();
        }
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