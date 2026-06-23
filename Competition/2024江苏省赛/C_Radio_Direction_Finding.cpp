#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
// #define endl "\n" 

//vector<vector<int>>edg(N);
map<int,int>mp;
int ask(int x){
    if(mp[x + 1]) return mp[x + 1]; 
    cout << "? " << x + 1<< endl;
    cin >> x;
    return x;
}


void solve()
{
    int n;
    cin >> n;
    // for(int i = 1; i <= n; i ++) cin >> mp[i];

    int p, d, d1,d2;
    d1 = ask(0), d2 = ask(n/2);
    if(d1 < d2) p = 0, d = d1;
    else p = n/2, d = d2;
    int dl = ask((p - 1 + n) % n), dr = ask((p + 1) % n);
    int ansl, ansr;

    if(dl == dr && dl == d) {
        int l = 0, r = n / 2;
        while(l < r) {
            int mid = l + r >> 1;
            if(ask((p + mid) % n) != d) r = mid;
            else l = mid + 1;
        }
        ansr = (p + l - 1 + n) % n;
        ansl = (ansr - d + n) % n;
    }
    else if(dl > d) {
        int l = 0, r = n / 2;
        while(l < r) {
            int mid = l + r >> 1;
            if(ask((p + mid) % n) != d - 2 * mid) r = mid;
            else l = mid + 1;
        }
        // cout << p << " " << l << endl;

        ansl = (p + l - 1 + n) % n;
        ansr = (ansl + ask(ansl) + n) % n; 

    }
    else {
        int l = 0, r = n / 2;
        while(l < r) {
            int mid = (l + r) >> 1;
            if(ask((p - mid + n) % n) != d - 2 * mid) r = mid;
            else l = mid + 1;
        }
        ansr = (p - l + 1 + n) % n;
        ansl = (ansr - ask(ansr) + n) % n;
    }
    cout << "! " << ansl + 1  << " " << ansr + 1 << endl;

}


signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0),cout.tie(0);
    // cout << setprecision(11) << fixed;
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}