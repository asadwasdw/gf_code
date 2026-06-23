#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e5+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
//https://www.acwing.com/problem/`content/1171/
vector<vector<PII>>edg(N);

int dis[N];
bool st[N];
int cnt[N];
 int n,m;
bool spfa(){
    memset(dis,0x8f,sizeof dis);
    dis[0]=0;
    st[0]=true;
    stack<int>s;
    s.push(0);

    while (s.size())
    {
        int t = s.top();
        s.pop();

        st[t]=false;

        for(auto T : edg[t]){
            int v = T.first;
            int w = T.second;


            if(dis[v]<dis[t]+w){
                dis[v]=dis[t]+w;

                cnt[v]=cnt[t]+1;
                if(cnt[v]>=n+1)return true;

                if(!st[v]){
                    s.push(v);
                    st[v]=true;
                }

            }
        }     
    }
    return false;
}

void solve()
{
   
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,a,b;
        cin>>x>>a>>b;

        if(x==1)
        {
            edg[a].push_back({b,0});
            edg[b].push_back({a,0});
        }
        else if(x==2)edg[a].push_back({b,1});
        else if(x==3)edg[b].push_back({a,0});
        else if(x==4)edg[b].push_back({a,1});
        else if(x==5)edg[a].push_back({b,0});
    }

    for(int i=1;i<=n;i++)edg[0].push_back({i,1});

    if(spfa())cout<<"-1"<<endl;
    else {
        ll res = 0;
        for(int i=1;i<=n;i++)res+=dis[i];
        cout<<res<<endl;
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