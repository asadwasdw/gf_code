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
    string a;
    cin>>a;
    int n = a.size();
    a=" "+a;
    bool ok = false;
    for(int i=2;i<=n/2;i++) {
        if(a[i]!=a[i-1]){
            swap(a[i],a[i-1]);
            swap(a[n-i+1],a[n-i+2]);
            ok=true;
            break;
        }
    }

    if(ok){
        for(int i=1;i<=n;i++)cout<<a[i];
    }
    else cout<<"-1";







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