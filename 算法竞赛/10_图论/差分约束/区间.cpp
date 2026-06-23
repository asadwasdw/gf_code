#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<PII>>edg(N);
int n;
int cnt[N];
int dis[N];
bool st[N];

bool spfa()
{
    queue<int>q;
    q.push(0);
    st[0]=true;
    memset(dis,-0x3f,sizeof dis);
    dis[0]=0;

    while(q.size())
    {
        int u = q.front();
        q.pop();
        st[u]=false;

        for(auto T:edg[u]){
            int v = T.first;
            int w = T.second;

            if(dis[v]<dis[u]+w){
                dis[v]=dis[u]+w;

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

    cin>>n;
    for(int i=1;i<=n;i++){
        int a,b,x;
        cin>>a>>b>>x;
        b++;
        edg[a].push_back({b,x});
    }

    for(int i = 1;i<=50001;i++){
        edg[i-1].push_back({i,0});
        edg[i].push_back({i-1,-1});

    }

    spfa();

    ll res = dis[50001]; 
    cout<<res<<endl;




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