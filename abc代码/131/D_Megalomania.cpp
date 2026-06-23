#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);

vector<PII>a;

bool cmp(PII a,PII b)
{
    if(a.second==b.second)return a.first<b.first;
    return a.second<b.second;
}


void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x,y;
        cin>>x>>y;
        a.push_back({x,y});
    }

    sort(a.begin(),a.end(),cmp);

    int now = 0;

    for(auto t : a){
      //  cout<<t.first<<" "<<t.second<<endl;
        now+=t.first;
        if(now>t.second){
            cout<<"No";
            return ;
        }
    }
    cout<<"Yes";


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