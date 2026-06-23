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
    vector<int> a,b;
    for(int i = 1; i <= 5; i ++) {
        char t; cin >> t;
        int x = t - '0';
        if(x % 2) a.push_back(x);
        else b.push_back(x);
    }

    sort(a.begin(), a.end(),[&](int x, int y) {
        return x > y;
    });

    sort(b.begin(), b.end(),[&](int x, int y) {
        return x > y;
    });

    for(auto t:a)cout << t;
    for(auto t:b)cout << t;cout << endl;
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