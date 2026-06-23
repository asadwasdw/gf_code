#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;


int st[N][2];

vector<vector<int>>edg(N);

void bfs(int root,int t)
{
    queue<int>q;
    q.push(root);
    st[root][t]=0;

    while(q.size())
    {
        int x = q.front();q.pop();
        for(auto T : edg[x])
        {
            if(st[T][t]<=st[x][t]+1)continue;
            st[T][t]=st[x][t]+1;
            q.push(T);
        }
    }
}

vector<int>hd;

void solve()
{

    int n,m,k;
    cin>>n>>m>>k;

    for(int i=1;i<=k;i++){
        int x;cin>>x;
        hd.push_back(x);
    }


    for(int i=1;i<=m;i++){
        int l,r;
        cin>>l>>r;

        edg[l].push_back(r);
        edg[r].push_back(l);

    }

    bfs(1,0);
    bfs(n,1);

    int ans1 = 0;
    int ans0 = 0;

    for(auto t: hd){
        ans0+=st[t][0];
        ans1+= st[t][1];
    }
    //cout<<ans1<<endl;
    int ans = 0x3f3f3f3f;

    for(auto t:hd){
        ans=min(ans,st[t][0]*(k-1)+ans1-st[t][1]);
        //cout<<t<<" "<<ans<<endl;
    }

    //cout<<st[n][0]<<endl;

    if(st[n][0]*(k-1)<=ans){
        cout<<st[n][0]<<"/1";
    }
    else 
    {
        cout<<ans/__gcd(ans,k-1)<<"/"<<(k-1)/__gcd(ans,k-1)<<endl;
    }








}


signed main()
{
    memset(st,0x3f,sizeof st);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}