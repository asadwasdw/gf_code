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
    int n;
    cin >> n;
    map<char,char> st;
    st['a'] = '2';
    st['b'] = '2';
    st['c'] = '2';
    st['d'] = '3';
    st['e'] = '3';
    st['f'] = '3';
    st['g'] = '4';
    st['h'] = '4';
    st['i'] = '4';
    st['j'] = '5';
    st['k'] = '5';
    st['l'] = '5';
    st['m'] = '6';
    st['n'] = '6';
    st['o'] = '6';
    st['p'] = '7';
    st['q'] = '7';
    st['r'] = '7';
    st['s'] = '7';
    st['t'] = '8';
    st['u'] = '8';
    st['v'] = '8';
    st['w'] = '9';
    st['x'] = '9';
    st['y'] = '9';
    st['z'] = '9';
    for(int i = 1; i <= n; i ++) {
        string s;
        cin >> s;
        cout << st[s[0]];
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