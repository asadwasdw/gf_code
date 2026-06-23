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
    string s,t;
    cin >> s >> t;

    for(int i = 1; i <s.size(); i ++) {
        for(int j = 0; j < i; j ++) {
            string S;
            for(int k = j; k < s.size(); k += i) {
                S += s[k];
            }
            // cout << S << endl;
            if(S == t) {
                cout << "Yes";
                return;
            }
        }
    }
    cout << "No";







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