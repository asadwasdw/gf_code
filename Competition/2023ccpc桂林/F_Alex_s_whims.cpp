#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);


void solve()
{
    int n,q;
    cin>>n>>q;

    for(int i=1;i<n;i++){
        cout<<i<<" "<<i+1<<"\n";
    }
       int v = n-1;
    for(int i=1;i<=q;i++){
        int x;cin>>x;
        if(x==v){
            cout<<"-1 -1 -1\n";
        }
        else cout<<n<<" "<<v<<" "<<x<<endl;
        v=x;
    }

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