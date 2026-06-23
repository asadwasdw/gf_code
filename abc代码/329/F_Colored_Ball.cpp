#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=2e5+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

bitset<2010>s[N];

void solve()
{

    int n;cin>>n;
    int q;cin>>q;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
         s[i][x]=1;
    }

    while(q--){
        int a,b;
        cin>>a>>b;
        s[b]|=s[a];
        s[a]=0;
        cout<<s[b].count()<<endl;
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