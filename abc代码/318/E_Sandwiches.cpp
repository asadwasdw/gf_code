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


void solve()
{

    int n;cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        edg[x].push_back(i);
    }

    int ans = 0;
    for(int i=1;i<=n;i++){
        if(edg[i].size()<=1)continue;
          sort(edg[i].begin(),edg[i].end());
         //cout<<i<<endl;
        for(int j=1;j<edg[i].size();j++){

            int t = edg[i][j]-edg[i][j-1]-1;
            int l = j;
            int r = edg[i].size()-j;
            //cout<<t<<" "<<l<<" "<<r<<endl;
            ans+=max(0ll,t*l*r);
          //  cout<<ans<<endl;
        }
    }
    cout<<ans<<endl;
    //cout<<"s"<<endl;









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