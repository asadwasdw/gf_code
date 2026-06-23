#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);

int c[N];
int to[N];
int d[N];
int n;
bool st[N];

void tppx()
{
    queue<int>q;
    for(int i=1;i<=n;i++){
        if(d[i]==0)q.push(i),cout<<i<<" ";
    }

    while(q.size()){
        int u = q.front();q.pop();
        int v = to[u];

        d[v]--;
        if(d[v]==0)q.push(v),cout<<v<<" ";
    }
}

void solve()
{

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>to[i];d[to[i]]++;
    }
    for(int i=1;i<=n;i++)cin>>c[i];

    tppx();

    // for(int i=1;i<=n;i++)
    // {
    //     if(d[i]==0)cout<<i<<" ";
    // }

    for(int i=1;i<=n;i++)
    {
        if(st[i]==false&&d[i])
        {
            int minx = INFll;
            int x = 0;
            int t = i;
            while(st[t]==false){
                //cout<<t<<endl;
                st[t]=true;
                if(c[t]<minx){
                    minx= c[t];
                    x= t;
                }
                t=to[t];
            }

            int y = to[x];
            while(x!=y)
            {
                cout<<y<<" ";
                y=to[y];
            }
            cout<<y<<" ";
        }
    }

    cout<<endl;
    for(int i=1;i<=n;i++)d[i]=0,st[i]=false,to[i]=0,c[i]=0;

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