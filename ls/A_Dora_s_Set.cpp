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

int l, r;



void solve()
{
    int ans = 0;
    int l, r;
    cin >> l >> r;
    int last = l - 1;
    for(int i = l; i <= r; i ++) {
        if(i - last >= 3 && i%2 == 1) {
            ans ++;
            last = i;
        }
    }
    cout << ans << endl;

}







signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(11) << fixed;
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}