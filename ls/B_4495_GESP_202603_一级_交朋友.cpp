#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

//vector<vector<int>>adj(N);


void solve()
{
    int h1, h2, h3, h4;
    cin >> h1 >> h2 >> h3 >> h4;

    int a, b, c;
    if(h2 <= h1) a = h1 - h2;
    else a = h2 - h1;

    if(h3 <= h1) b = h1 - h3;
    else b = h3 - h1;

    if(h4 <= h1) c = h1 - h4;
    else c = h4 - h1;

    if(a < b && a < c) {
        cout << h2;
    } else if(b < a && b < c) {
        cout << h3;
    } else if(c < a && c < b) {
        cout << h4;
    } else if(a == b && b < c) {
        if(h2 < h3) cout << h2;
        else cout << h3;
    } else if(a == c) {
        if(h2 < h4) cout << h2;
        else cout << h4;
    } else {
        if(h3 < h4) cout << h3;
        else cout << h4;
    }





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
    return 0;
}