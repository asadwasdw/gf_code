#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<PII>>edg(N);
int f[N];
int val[N];
bool ok = true;
void add(int a,int b,int c)
{
    edg[a].push_back({b,c});

}

int find(int x)
{
    if(x==f[x])return f[x];
    int fa = f[x];
    f[x] = find(f[x]);
    val[x]+=val[fa];
    return f[x];
}

int dis[N];
bool st[N];
int cnt[N];
int n,m;

bool spfa(){
    memset(dis,0x3f,sizeof dis);
    dis[0]=0;
    st[0]=true;
    stack<int>s;
    s.push(0);//因为si>=0 所以0可以到所有点,可以做源点

    while (s.size())
    {
        int t = s.top();
        s.pop();

        st[t]=false;

        for(auto T : edg[t]){
            int v = T.first;
            int w = T.second;

            if(dis[v]>dis[t]+w){//最短路
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

    for(int i=1;i<=n;i++)f[i]=i;
    while(m--)
    {
        int l,r,c;
        cin>>l>>r>>c;
        l--;

        if(((r-l)&1)^(abs(c)&1))ok=false;//x+y=n
                                         //x-y=c 2*x=偶数， 所以 n和c奇偶性相同
        int fl = find(l);
        int fr = find(r);

        if(fl==fr){
            if(val[l]-val[r]!=c)ok=false;//加权并查集判断是否有矛盾
        }
        else {
            f[fr]=fl;
            val[fr]=val[l]-c-val[r];
            add(r,l,-c);add(l,r,c);
        }
    }

    for(int i=1;i<=n;i++)
    {
        add(i-1,i,1);//|si-(si-1)|=1 放缩成 -1<=si-(si-1)<=1;
        add(i,i-1,1);
    }

    for(int i=1;i<=n;i++){
        add(i,0,0);// si>=0
    }
    add(0,n,0);
    add(n,0,0);//sn=0

    add(1,0,-1);
    add(0,1,1);//s1=1;

    if(ok)ok=!spfa();
    if(ok){
        cout<<"! ";
        for(int i=1;i<=n;i++)if(dis[i]-dis[i-1]==1)cout<<"(";
        else cout<<")";
    }
    else cout<<"?";
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