#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;

int n,m,t;
vector<int>ty[15];
int st[15];
int num[N];
int cnt=0;
int ans = 0;
bool cmp(vector<int>a,vector<int> b){
    return a.size()>b.size();
}

bool ky(int i,int j)
{
    for(auto t:ty[i]){
        if(st[t]==j)return false;
    }
    return true;
}

void dfs(int u,int zu)
{
    if(u==n+1)
    {
        if(zu==t)ans++;
        return ;
    }

    if(zu>t)return ;


    for(int i=1;i<=zu;i++)
    {
        if(ky(u,i)){
            st[u]=i;
            dfs(u+1,zu);
            st[u]=0;
        }
    }

    st[u]=zu+1;
    dfs(u+1,zu+1);
    st[u]=0;

}


void solve()
{
    cin>>n>>t>>m;

    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        ty[x].push_back(y);
        ty[y].push_back(x);
    }

    //sort(ty+1,ty+n+1,cmp);

    dfs(1,0);

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