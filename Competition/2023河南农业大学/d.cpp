#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=1e5+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;

int n,m,st,ed,h;

vector<vector<PII>>edg(N);
int w[N];
vector<int>ef;



bool check(int W)
{
    vector<int>dp(n+10,INF);
    dp[st]=0;

    queue<int>q;
    q.push(st);

    while(q.size()){
        int t = q.front();q.pop();
        for(auto T : edg[t]){
            int x = T.first;
            int y = T.second;
            
            if(w[x]>W)continue;
            
            if(dp[x]<=dp[t]+y)continue;
            dp[x]=dp[t]+y;

            q.push(x);
        }
    }

  //  cout<<W<<" "<<dp[ed]<<endl;
    return dp[ed]<=h;
}




bool cmp(int a,int b)
{
    return a<b;
}

void solve()
{

    cin>>n>>m>>st>>ed>>h;

    for(int i=1;i<=n;i++){
        cin>>w[i];
        ef.push_back(w[i]);
    }

    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;

        edg[a].push_back({b,c});
        edg[b].push_back({a,c});
    }

    //check(10);
    ef.push_back(-1);
    ef.push_back(INF);
    sort(ef.begin(),ef.end(),cmp);

    int l =1;
    int r =n+1;

    while(l<r)
    {
        int mid = l+r>>1;
        if(check(ef[mid]))r=mid;
        else l=mid+1;
    }

    if(l==n+1){
        cout<<-1<<endl;
    }
    else cout<<max(w[st],ef[l])<<endl;
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