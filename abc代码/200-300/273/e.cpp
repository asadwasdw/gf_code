#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;

unordered_map<ll,ll>m1;
int idx = 0;
int now = 0;
int ne[N];
int p[N];
void solve()
{
    p[now]=-1;

    int n;cin>>n;
    while(n--){
        string op;
        cin>>op;
        ll x;
        if(op=="ADD")
        {
            cin>>x;
            p[++idx]=x;
            ne[idx]=now;
            now=idx;
            
        }
        else if(op=="SAVE")
        {
            cin>>x;
            m1[x]=now;
        }
        else if(op=="DELETE"){
            if(now)now=ne[now];
        }
        else if(op=="LOAD")
        {
            cin>>x;
            now = m1[x];
  
        }
        //cout<<s<<endl;

      cout<<p[now]<<" ";
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