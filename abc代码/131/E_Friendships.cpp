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

void solve()
{
    int n,k;
    cin>>n>>k;
    int mx = (n-2)*(n-1)/2;

    if(k>mx){
        cout<<"-1\n";
        return;
    }

    for(int i=2;i<=n;i++){
        a.push_back({1,i});
    }

    for(int i=2;i<=n&&mx>k;i++)
    {
        for(int j=i+1;j<=n&&mx>k;j++)
        {
            mx--;
            a.push_back({i,j});
        }
    }

    cout<<a.size()<<endl;
    for(auto t : a)
    {
        cout<<t.first<<" "<<t.second<<endl;
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