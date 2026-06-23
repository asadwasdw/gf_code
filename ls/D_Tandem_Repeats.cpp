#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10,M = 5010;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N)

bool pd(char a, char b) {
    if(a =='?' || b == '?' || a==b) return true;
    return false;
}

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    s = " " + s;
    int ans = 0;
    for(int len = 1; len <= n;len ++) {
        for(int l = 1 ,r = l + len ; r + len - 1 <= n; l ++ ,r ++ ) {
            int L = l, R = r;

            while(L < r && r + len - 1 <= n && pd(s[L],s[R])) ++L,++R;

            if(L == r) {
                ans = len * 2; 
            }
            if(L != l) {
                l = L - 1;
                r = R - 1;
            }
            
        }
    }
    cout << ans <<endl;
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