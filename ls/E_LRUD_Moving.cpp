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

string check(int n, int a, int b) {
    string res = "";
    if(n % 2 == 1) return res;
    if((a + b) % 2 == 0) return res;
    int x = 1, y = 1;

    int U = (a - 1) / 2 * 2 + 1;

    while(x < U) {
        for(int i = 1; i < n; i ++) res += 'R';
        res += 'D';
        for(int i = 1; i < n; i ++) res += 'L';
        res += 'D';
        x += 2;
    }

    int L = (b - 1) / 2 * 2 + 1;
    while(y < L) {
        res += "DRUR";
        y += 2;
    }

    if(a % 2 == 1) {
        res += "DR"; 
        if(y + 1 < n) res += 'R';
    } else {
        res += "RD";
        if(y + 1 < n) res += 'R';
    }
    y += 2;

    while(y < n) {
        res += "URD";
        if(y + 1 < n) res += 'R';
        y += 2;
    }

    while(x + 1 < n) {
        res += 'D';
        for(int i = 1; i < n; i ++) res += 'L';
        res += 'D';
        for(int i = 1; i < n; i ++) res += 'R';
        x += 2;
    }
    return res;
}

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;

    string s = check(n, a, b);
    if(s == "") cout << "No" << endl;
    else cout << "Yes\n" << s << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t; t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++){
        solve();
    }
    return 0;
}