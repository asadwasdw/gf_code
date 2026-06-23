#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);

int a[N];

bool cmp(PII a,PII b){
    if(a.first!=b.first)return a.first>b.first;
    return a.second<b.second;
}

void solve()
{
    int n;cin>>n;
    for(int i=1;i <=n;i++)
    {
        for(int j =1;j<=n;j++){
            char t;cin>>t;

            if(t == 'o')a[i]++;
        }
    }

    vector<PII>q;

    for(int i=1;i<=n;i++){
        q.push_back({a[i],i});
    }
    sort(q.begin(),q.end(),cmp);

    for(auto t:q)cout<<t.second<<" ";










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