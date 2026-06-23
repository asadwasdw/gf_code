#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);

struct color{
    int r,b,g;
}c[N];

void dfs(int u,int cnt)
{
    if(cnt>=3){
        cout<<"-1";
        exit(0);
    }

    for(auto v:edg[u])
    {
        dfs(v,cnt+1);
    }
}

int cd[N];
int rd[N];
int ans[N];


void solve()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>c[i].r>>c[i].b>>c[i].g;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(c[i].r<c[j].r&&c[i].b<c[j].b&&c[i].g<c[j].g){
                //cout<<i<<" "<<j<<endl;
                //edg[i].push_back(j);
                cd[i]++;
                rd[j]++;
            }
        }
    }

    for(int i=1;i<=n;i++)
    {
        if(cd[i]&&rd[i]){
            cout<<"-1";
            return;
        }
    }

    for(int i=3;i<=n;i++)
    {
        if(cd[i]==0&&rd[i]==0)ans[i]=0;
        else if(cd[i])ans[i]=0;
        else ans[i]=1;
    }

    if(cd[1]&&cd[2]){

    }
    else if(rd[1]&&rd[2]) {
        ans[1]=ans[2]=1;
    }
    else if(rd[1]==0&&cd[1]==0){
        if(rd[2]){
             ans[1]=ans[2]=1;
        }
    }
    else if(rd[2]==0&&cd[2]==0){
        if(rd[1]){
            ans[1]=ans[2]=1;
        }
    }
    else {
        cout<<"-1";
        return;
    }
    for(int i=1;i<=n;i++)cout<<ans[i]<<endl;
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