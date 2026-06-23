#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);
int n,q;
int tr[N];
void add(int x,int k){
   for(int i=x;i<=n;i+=i&-i)tr[i]+=k;
}

int sum(int x)
{
    int res = 0;
    for(int i=x;i;i-=i&-i){
        res+=tr[i];
    }
    return res;
}

int sumlr(int l,int r) {
    return sum(r)-sum(l-1);
}

int ans[N][3];
int l[N],r[N],dfn;

void dfs(int u,int fa) {
    l[u] = ++dfn;

    for(auto v:edg[u]) {
        if(v==fa)continue;
        dfs(v,u);
    }
    r[u]=dfn;
}

struct que{
    int id,st,root;
};
vector<que> query[N];
int a[N];

void solve()
{
    dfn=0;
    cin>>n>>q;
    
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        edg[x].push_back(y);
        edg[y].push_back(x);
    }
    for(int i=1;i<=n;i++)cin>>a[i];

    dfs(1,-1);

    for(int i=1;i<=q;i++){
        int l,r,x;
        cin>>l>>r>>x;
    //    cout<<l<<" "<<r<<endl;
        query[l-1].push_back({i,0,x});
        query[r].push_back({i,1,x});
    }

    //for(int i=1;i<=n;i++)cout<<l[i]<<" "<<r[i]<<endl;

    for(int i=1;i<=n;i++){
     //   cout<<l[a[i]]<<endl;
       add(l[a[i]],1);

        for(auto T : query[i]){
            ans[T.id][T.st] = sumlr(l[T.root],r[T.root]);
           // cout<<T.id<<" "<<T.st<<endl;
        }
    }

    // for(int i=1;i<=q;i++)cout<<ans[i][0]<<" "<<ans[i][1]<<endl;

    for(int i=1;i<=q;i++){
        if(ans[i][0]==ans[i][1])cout<<"NO\n";
        else cout<<"YES\n";
        ans[i][0]=ans[i][1]=0;
    }

    for(int i=0;i<=n;i++)
    {
        l[i]=r[i]=0;
        tr[i]=0,edg[i].clear(),query[i].clear();
    }
    cout<<"\n";
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