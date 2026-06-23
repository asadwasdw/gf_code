#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;

const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);
typedef long double db;
db x[N],y[N];

db js(int i,int j){
    return sqrt((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]));
}
typedef pair<db,int>PII;
db dp[N];
db a[N];

db js2(int l,int r){
    return a[r]-a[l];
}

void solve()
{
    int n,k;
    cin>>n>>k;
    for(int i=0;i<=n;i++)cin>>x[i]>>y[i];

    for(int i=1;i<=n;i++){
        a[i]=a[i-1]+js(i,i-1);
        dp[i]=INFll;
    }

    dp[0]=0;
    priority_queue<PII,vector<PII>,greater<PII> >q;
    q.push({0,0});
    for(int i=1;i<=n;i++){


        while(q.size()&&q.top().second<i-k)q.pop();
        int k = q.top().second;
        dp[i]=dp[k]+js(0,k+1) + js2(k+1,i) + js(i,0);
        
        q.push({dp[i]+js(0,i+1)-js2(0,i+1),i});
    }


    cout<<dp[n];
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout<<fixed<<" "<<setprecision(10);
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}