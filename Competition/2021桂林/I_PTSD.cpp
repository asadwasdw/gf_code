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
    string s;
    cin >> n >> s;
    ll res = 0;
    vector<int> st(n);
    int r = n-1;
    for(int i=n-1; i>=0; --i){
        if(st[i])continue;
        while(r >= i)r--;
        while(r >= 0 && s[r] == '0')--r;
        if(r >= 0){
            st[r] = 1, res += r+1;
            --r;
        }
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