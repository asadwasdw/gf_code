#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<PII>>edg(N);

int num[25];
int r[25];

void add(int a,int b,int c)
{
    edg[a].push_back({b,c});
}

void build(int c)
{
    for(int i=0;i<=24;i++){
        edg[i].clear();
    }
    
    for(int i=1;i<=24;i++)
    {
        add(i-1,i,0);
        add(i,i-1,-num[i]);
    }
    for(int i=1;i<=7;i++)
    {
        add(i+16,i,-c+r[i]);
    }

    for(int i =8;i<=24;i++)
    {
        add(i-8,i,r[i]);
    }
    add(0,24,c);
    add(24,0,-c);
}

int dis[N];
int st[N];
int cnt[N];

bool spfa(int c)
{
    build(c);
    memset(dis,-0x3f,sizeof dis);
    memset(st,0,sizeof st);
    memset(cnt,0,sizeof cnt);

    queue<int>q;
    q.push(0);
    st[0]=true;
    dis[0]=0;

    
    while(q.size())
    {
        int u = q.front();q.pop();
        st[u]=false;

        for(auto T:edg[u]){
            int v= T.first;
            int w =T.second;

            if(dis[v]<dis[u]+w)
            {
                dis[v]=dis[u]+w;
                cnt[v]=cnt[u]+1;
                if(cnt[v]>=25)return true;

                if(!st[v]){
                    st[v]=true;
                    q.push(v);
                }
            }
        }
    }

    return false;

}

void solve()
{

    for(int i=1;i<=24;i++)
    {
        cin>>r[i];
    }
    memset(num, 0, sizeof num);
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        num[x+1]++;
    }
    int l=0,r = n;
    while(l<r)
    {
        int mid = (l+r)>>1;
        if(!spfa(mid))r=mid;
        else l=mid+1;
    }
    if(!spfa(l))cout<<l;
    else cout<<"No Solution";
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