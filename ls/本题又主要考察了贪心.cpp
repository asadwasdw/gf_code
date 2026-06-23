#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

int n,m;
PII bs[100];
int a[11];
int ans = 10;

void dfs(int cnt) {
    if(cnt == m+1) {

        int b[11]={0};
        for(int i=1;i<=n;i++)b[i]=-a[i];
        sort(b+1,b+n+1);
        for(int i=1;i<=n;i++){
            if(a[1]==-b[i]) {
                ans=min(i,ans);
                break;
            }
        }
        

        return;
    }
    int u = bs[cnt].first;
    int v = bs[cnt].second;

    if(u!=1) {
        a[v]+=3;
        dfs(cnt+1);
        a[v]-=3;

        a[u]+=1;
        a[v]+=1;
        dfs(cnt+1);
        a[u]-=1;
        a[v]-=1;
    }

    a[u]+=3;
    dfs(cnt+1);
    a[u]-=3;
}

void solve()
{
    ans=10;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=m;i++) {
        cin>>bs[i].first>>bs[i].second;
        if(bs[i].first>bs[i].second)swap(bs[i].first,bs[i].second);
    }

    dfs(1);
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