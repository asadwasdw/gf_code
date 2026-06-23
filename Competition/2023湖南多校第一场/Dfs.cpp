#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef pair<int,int>PII;
const int N=1e4+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
PII d[N][2];
int a[N];
int n;
int ans=0;
bool ky=false;

void dfs(vector<int>t,int x )
{
  ans=max(ans,(int)t.size());

  if(t.size()==3&&!ky&&t[t.size()-1]==2)
  {
    ky=true;
    for(auto b:t)cout<<b<<" ";
  }

    if(x==n+1){
        return;
    }
    for(int i=x;i<=n;i++)
    {
      if(t.size()<2)
      {
        t.push_back(a[x]);
        dfs(t,i+1);
        t.pop_back();
      }
      else{
        if(a[x]>t[t.size()-2])
        {
            t.push_back(a[x]);
            dfs(t,i+1);
            t.pop_back();
        }
      }
    }
    dfs(t,x+1);
      
}

void solve()
{
   cin>>n;
   for(int i=1;i<=n;i++)
   {
    cin>>a[i];
   }
   vector<int>t;
   //a.push_back(0);
    dfs(t,1);
    cout<<endl;
    cout<<ans<<endl;
   
}


signed main()
{
    ios::sync_with_stdio(false);
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}