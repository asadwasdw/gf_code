#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);


void solve()
{
    bool ky = true;
    bool ky2 = false;
    int mx = 9;
    string s;
    cin >> s;
    int n = s.size();
    s = "0" + s;
    for(int i = 1; i <= n; i ++) {
        if(s[i]<s[i-1]) {
            ky = false;
        }
        if(ky)cout<<s[i];
        else {
            if(ky2)cout<<mx;
            else {
                mx = min(mx,s[i]-'0');
                if(mx != s[i]-'0'){
                    ky2 = true;
                }
                cout << mx;
            }
        }
    }
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