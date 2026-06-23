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
    int a, b, c;
    cin >> a >> b >> c;

    
    for(int i = 0; i < a; i ++) cout << i % 10;
    for(int i = 0; i < b; i ++) cout << (char)('A' + i % 10);
    for(int i = 0; i < c; i ++) cout << (char)('a' + i % 10);
    cout << endl;







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