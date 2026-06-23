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
    map<int,int>cnt;
    for(int i = 1; i <= 7; i ++) {
        int x; cin >> x;
        cnt[x] ++;
    }
    bool ky3 = false, ky2 = false;
    for(auto[_,t] : cnt) {
        // cout << t << endl;
        if(t >= 3) {
            if(!ky3) ky3 = true;
            else ky2 = true;
        } else if(t >= 2) {
            ky2 = true;
        }
    }
    if(ky3 && ky2) {
        cout << "Yes";
    } else {
        cout << "No";
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