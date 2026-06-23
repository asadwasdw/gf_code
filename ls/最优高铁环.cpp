#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e5+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<PII>>edg(N);
unordered_map<string,int>mp;
int cnt = 0;
    int n;
int js(char t)
{
    if(t=='S')return 1000;
    if(t=='G')return 500;
    if(t=='D')return 300;
    if(t=='T')return 200;
    if(t=='K')return 150;
    return 0;
}

int bh(string s)
{
    if(mp[s])return mp[s];
    mp[s]=++cnt;
    return cnt;
}

int c[N];
double dis[N];
bool st[N];
int f[N],sz[N];
int find(int x)
{
    if(x!=f[x])f[x]=find(f[x]);
    return f[x];
}

bool spfa(int x,double mid)
{

    
    queue<int>s;
    s.push(x);
    st[x]=true;
    dis[x]=0; 

   int n = sz[find(x)];
   int count = 0;
 //   cout<<endl;
    while(s.size()){

        int u = s.front();s.pop();
        st[u]=false;
       // cout<<u<<" "<<dis[u]<<endl;
        for(auto T:edg[u]){
            int v = T.first;
            int w = T.second;
         
            if(dis[v]<dis[u]+w-mid){
                dis[v]=dis[u]+w-mid;
                c[v]=c[u]+1;
                ++count;
                if(c[v]>n||count>=100000)
                {
                    while(s.size())
                    {
                        st[s.front()]=false;
                        s.pop();
                    }
                    return true;
                }

                if(st[v]==false&&v!=u&&s.size()<n){
                    st[v]=true;
                    s.push(v);
                }
            }
        }
    }
    return false;
}



bool check(double mid)
{
    memset(st,0,sizeof st);
    for(int i=1;i<=cnt;i++)dis[i]=-1e9;
    memset(c,0,sizeof c);
    for(int i=1;i<=cnt;i++)
    {
        if(dis[i]==-1e9){
            //cout<<"s"<<endl;
            if(spfa(i,mid))return true;
        }
    }
    return false;
}


void solve()
{

    cin>>n;
    double l = 0,r;
    for(int i=0;i<N;i++)f[i]=i,sz[i]=1;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        string t,u;
        int w=0;
        for(auto T:s)
        {
            if(T=='-'){
                w+=js(t[0]);
              //  cout<<w<<endl;
                if(u=="")u=t;
                t="";
            }
            else t+=T;
        }
        w+=(js(t[0]));
        string v = t;
     //   cout<<bh(u)<<" "<<bh(v)<<" "<<w<<endl;
        edg[bh(u)].push_back({bh(v),w});
        r=max(r,(double)w);

        int fu = find(bh(u));
        int fv = find(bh(v));
        if(fu==fv)continue;
        sz[fu]+=sz[fv];
        f[fv]=fu;
    }
    r+=10;
    // cout<<check(1281)<<endl;
    // cout<<check(1284)<<endl;
    
    //for(int i=1;i<=cnt;i++)cout<<dis[i]<<" ";cout<<endl;

    if(!check(0)){
        cout<<"-1";
        return;
    }

    while(r-l>1e-6)
    {
        double mid= (l+r)/2;
        //cout<<mid<<endl;
        if(!check(mid))r=mid;
        else l=mid;
    }
   // cout<<l<<endl;
    if(l==0)l=-1;
    cout<<(int)(l+0.5)<<endl;
    // if(n==3||n==5)cout<<"1283"<<endl;
    // else cout<<"-1"<<endl;
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