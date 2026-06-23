#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);
int n,m;
int a[N];


void solve()
{
    ll k,x,y;
    cin >> k >> x >> y;
    if(k == 1){
        cout << x + y << endl;
        return;
    }
    ll res = 0;
    if(k & 1){
        ll cnt = y / (k / 2);
        if(cnt <= x){
            res += cnt;
            x -= cnt;
            y %= k / 2;
            if(x + y*2 >= k)x -= k - y*2, ++res;
            res += x / k;
        }
        else{
            res += x;
            y -= (k / 2) * x;
            res += y / ((k+1) / 2);
        }
    }
    else{
        ll cnt = y / (k / 2);
        res += cnt;
        y %= k / 2;
        if(x + y*2 >= k)++res, x -= k - y*2;
        res += x / k;
        
    }
    cout << res << endl;
    






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