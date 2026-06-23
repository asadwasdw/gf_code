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


    vector<int> a, b;
    for(int i = 1; i <= 2; i ++) {
        int t; cin >> t; a.push_back(t);
    }

    for(int i = 1; i <= 2; i ++) {
        int t; cin >> t; b.push_back(t);
    }

    int ans = 0;
    for(int i = 0; i < 2; i ++) {
        for(int j = 0; j < 2; j ++) {
            int A = 0, B = 0;
            if(a[i] > b[j]) A ++;
            if(a[i] < b[j]) B ++;
            if(a[i ^ 1] > b[j ^ 1]) A ++;
            if(a[i ^ 1] < b[j ^ 1]) B ++;
            if(A > B) ans ++;
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