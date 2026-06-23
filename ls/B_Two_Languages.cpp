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
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    map<char, bool> st1, st2;

    for(int i = 0; i < n; i ++) st1[s[i]] = true;
    for(int i = 0; i < m; i ++) st2[t[i]] = true;
    int q;
    cin >> q;
    while(q -- ) {
        string str;
        cin >> str;
        bool ky = true;

        for(auto t : str) {
            if(st1[t] && !st2[t]) {
                cout << "Takahashi";
                ky = false;
                break;
            }

            if(!st1[t] && st2[t]) {
                cout << "Aoki";
                ky = false;
                break;
            }
        }
        if(ky) cout << "Unknown";

        cout << endl;
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