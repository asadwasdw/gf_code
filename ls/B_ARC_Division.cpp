#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>adj(N);


void solve()
{
    int n, x;
    cin >> n >> x;
    while(n --) {
        int id, t; cin >> id >> t;
        if(id == 1) {
            if(1600 <= x && x <= 2799) {
                x += t;
            }
        } else {
            if(1200 <= x && x <= 2399) {
                x += t;
            }
        }
    }
    cout << x;







}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(11) << fixed;
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}