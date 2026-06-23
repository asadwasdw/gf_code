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
    int a = 0;
    bool ky = true;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if(!ky)continue;
        if(x >= 10) {
            int x1 = x/10, x2 = x % 10;
            if(x2 >= x1 && a <= x1){
                a = max(x2,a);
            }
            else {
                if(a > x) ky =false;
                else a = max(x,a);
            }
        }
        else {
            if(a > x) ky =false;
            else a = max(x,a);
        }
    }

    if(ky) cout << "YES\n";
    else cout << "NO\n";







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