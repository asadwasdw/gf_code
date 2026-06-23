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
    vector<ll> t;
    for(int i = 1; i <= 3; i ++){
        ll x; cin >> x;
        // cout << x << endl;
        t.push_back(x);
    }
    sort(t.begin(), t.end());
    bool ky = false; 
    {
        vector<ll> a = t;
        a[0] *= 2;
        sort(a.begin(), a.end());
        if(a[0] + a[1] > a[2]) {
            ky = true;
        } 
    }

    {
        vector<ll> a = t;
        a[1] *= 2;
        sort(a.begin(), a.end());
        if(a[0] + a[1] > a[2]) {
            ky = true;
        } 
    }

    {
        vector<ll> a = t;
        a[2] *= 2;
        sort(a.begin(), a.end());
        if(a[0] + a[1] > a[2]) {
            ky = true;
        } 
    }

    if(ky) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
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
}