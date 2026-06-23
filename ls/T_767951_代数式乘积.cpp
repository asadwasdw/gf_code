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

void print(int a, string b, bool c) {
    if(a == 0) return ;
    if(a > 0) {
        if(!c) cout << "+";
        if(a != 1 || b == "") cout << a;
        cout << b;
    } else {
        if(a == -1 && b != "") {
            cout << "-";
        } else {
            cout << a;
        }
        cout << b;
    }
}

void solve()
{
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    
    ll A = a * c;
    ll B = a * d + b * c;
    ll C = a * e + b * d;
    ll D = b * e;

    if(!A && !B && !C && !D) {
        cout << 0 << "\n";
        return;
    }

    bool ld = true;
    // cout << A << endl;
    if(A) {
        print(A, "x^3", ld);
        ld = false;
    }

    if(B) {
        print(B, "x^2", ld);
        ld = false;
    }

    if(C) {
        print(C, "x", ld);
        ld = false;
    }

    if(D) {
        print(D, "", ld);
        ld = false;
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