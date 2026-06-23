#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e7+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

//vector<vector<int>>adj(N);

int s[N];

void solve()
{
    string str;
    cin >> str;
    int n = str.size();
    // cout << n << endl;
    str = " " + str;

    for(int i = 1; i <= n; i ++) {
        s[i] = s[i - 1];
        if(str[i] == 'P') s[i] += 3;
        if(str[i] == 'p') s[i] += 2; 
        if(str[i] == 'G') s[i] += 1; 
        // cout << i << " " << s[i] << endl;
    }

    int q; 
    cin >> q;
    while(q -- ) {
        int l, r;
        cin >> l >> r;
        cout << s[r] - s[l - 1] << endl;
    }






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
    return 0;
}