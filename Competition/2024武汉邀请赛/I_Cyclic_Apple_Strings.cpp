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
string s;

void solve()
{
    cin >> s;
    int res = 0;
    int i = 0;
    while(i < s.size() && s[i] == '0')++i;
    for(; i<s.size(); ++i){
        if(s[i] == '1')continue;
        while(i < s.size() && s[i] == '0')++i;
        ++res;
    }
    cout << res << endl;






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