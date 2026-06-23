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
    int l=-INF;int r=INF;
    set<int>a;

    int n;cin>>n;
    for(int i=1;i<=n;i++){
        int op,x;
        cin>>op>>x;
        if(op==1){
            l=max(l,x);
        }
        else if(op==2){
            r=min(r,x);
        }
        else a.insert(x);
    }

    int cnt = 0;

    for(auto t:a){
        if(t>=l&&t<=r){
            cnt++;
        }
    }
    cout<<max(0,r-l+1-cnt)<<endl;
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