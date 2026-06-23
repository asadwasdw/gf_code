#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

set<int>s[N];
int wz[N];

void solve()
{

    int n,q;
    cin>>n>>q;
    int mx=0;
    for(int i=1;i<=n;i++){
        s[0].insert(i);
        wz[i] = 0;
    }
    
    while(q--){
        int x;
        cin>>x;
        s[wz[x]].erase(x);
        s[wz[x]+1].insert(x);
       
        wz[x]++;
        mx=max(mx,wz[x]);
        cout<<*s[mx].begin()<<endl;
        //cout<<mx<<endl;
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