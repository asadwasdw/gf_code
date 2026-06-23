#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
//https://www.acwing.com/problem/content/1172/
vector<vector<PII>>edg(N);

int cnt[N];
bool st[N];
int n,m1,m2;
int dis[N];

bool spfa(int size)
{
    queue<int>q;
    memset(cnt,0,sizeof cnt);
    memset(st,0,sizeof st);
    memset(dis,0x3f,sizeof dis);

    for(int i=1;i<=size;i++){
        q.push(i);
        st[i]=true;
        dis[i]=0;
    }

    while(q.size()){
        int u = q.front();q.pop();
        st[u]=false;
        
        for(auto T:edg[u])
        {
            int v = T.first;
            int w = T.second;
            if(dis[v]>dis[u]+w){
                
                dis[v]=dis[u]+w;
                cnt[v]=cnt[u]+1;
                if(cnt[v]>=n)return true;

                if(!st[v]){
                    q.push(v);
                    st[v]=true;
                }
            }

        }
    }

    return false;
}


void solve()
{
    cin>>n>>m1>>m2;

    for(int i=1;i<n;i++){
        edg[i+1].push_back({i,0});
    }

    while(m1--){
        int a,b,c;
        cin>>a>>b>>c;
        if(a>b)swap(a,b);
        edg[a].push_back({b,c});
    }
    while(m2--){
        int a,b,c;
        cin>>a>>b>>c;
        if(a>b)swap(a,b);
        edg[b].push_back({a,-c});
    }

    if(spfa(n))cout<<"-1";
    else{

        spfa(1);
        if(dis[n]==INF)cout<<"-2";
        else cout<<dis[n]<<endl;
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