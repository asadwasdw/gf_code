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

 priority_queue<PII,vector<PII>,greater<PII>>q;

void solve()
{

    int n ;
    cin>>n;
    for(int i =1;i<=n;i++){
        int a,b;cin>>a>>b;
        q.push({a,b});
    }
    int ans = 0;
    while(q.size()){
        PII t = q.top();q.pop();
        while(q.size()&&q.top().first==t.first){
            t.second+= q.top().second;
            q.pop();
        }
        int res = t.second/2;
        t.second%=2;

        if(res){
            q.push({t.first*2,res});
        }
        ans+= t.second;
    }
    cout<<ans<<endl;










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