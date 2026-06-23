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
    map<PII,bool> st;
    int n, r, c;
    cin >> n >> r >> c;
    int r0 = 0, c0 = 0;
    string s; cin >> s;
    for(int i = 0; i < n; i ++) {
        st[{r0, c0}] = true;
        if(s[i] == 'N') {
            r ++;
            r0 ++;
        } else if(s[i] == 'S') {
            r --;
            r0--;
        } else if(s[i] == 'W') {
            c ++;
            c0 ++;
        } else {
            c --;
            c0--;
        }
        

        // cerr << r0 << " " << c0 << endl;
        // cerr << r << " - " << c << endl;
        if(st[{r,c}]) {
            cout << 1;
        } else {
            cout << 0;
        }
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