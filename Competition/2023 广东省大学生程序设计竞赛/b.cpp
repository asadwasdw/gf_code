#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;


// int idx[N];
// int a[N];
// int dp[N];

void solve()
{
  //  memset(idx,-1,sizeof idx);
   // memset(dp,0x3f,sizeof dp);
    int n;
    cin>>n;
   vector<int>idx(n+10,-1);
   vector<int>a(n+10);
   vector<int>dp(n+10);

    for(int i=1;i<=n;i++)cin>>a[i];

    int m;
    cin>>m;
    while(m--)
    {
        int l,r;
        cin>>l>>r;
        idx[r]=max(idx[r],l);
    }


    for(int i=1;i<=n+1;i++)idx[i]=max(idx[i],idx[i-1]);

    deque<int>q;
    //dueue<int>q;

    dp[0]=0;
    dp[1]=a[1];

    q.push_back(0);
    q.push_back(1);

    for(int i=2;i<=n+1;i++)
    {
        while(q.front()<idx[i-1])q.pop_front();
        dp[i]=dp[q.front()]+a[i];



        while(dp[q.back()]>dp[i])q.pop_back();
        q.push_back(i);
    }

  //  for(int i=1;i<=n+1;i++)cout<<dp[i]<<" ";cout<<endl;
   cout<<dp[n+1]<<endl;

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