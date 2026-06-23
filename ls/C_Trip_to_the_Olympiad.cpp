#include<bits/stdc++.h>
#define int long long
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
    int l, r;
    cin >> l >> r;
    int a = 0, b = 0, c = 0;
    for(int k = 40; k >= 0; k --) {
        int t = 1ll << k;
        if(c + t <= r && b + (t - 1) >= l) {
            c += t;
        } else if(b + t <= c && b + t <= r) {
            b += t;
        } else if(b + (t - 1) < l) {
            b += t,
            c += t;
        }
    }

    a = b;
    for(int i = 0; i <= 30; i ++) {
        int t = 1ll << i;
        if((c & t) ^ (b & t) && (a ^ t) >= l && (a ^ t) <= r) {
            a ^= t;
            // cout << i << endl;
            break;
        }

        if((c & t) ^ (b & t) && (c ^ t) >= l && (c ^ t) <= r) {
            a = c ^ t;
            // cout << i << endl;
            break;
        }
    }



    cout << a << " " << b << ' ' << c << endl;
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