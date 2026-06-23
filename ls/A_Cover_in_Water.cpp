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
    int n;
    cin>> n;
    int sum = 0,num = 0;
    int mx = 0;
    for(int i = 1;i<=n;i++) {
        char t;cin>>t;
        if(t=='#'){
            sum = 0;
        }
        else {
            sum++;
            num ++;
        }
        mx = max(sum, mx);
    }

    if(mx>=3) {
        cout << "2\n";
    }
    else cout<<num << "\n";
   







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