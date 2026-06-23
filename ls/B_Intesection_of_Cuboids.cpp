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
int s[5][2];
int t[5][2];


bool pd() {
    for(int st = 0; st < 8; st ++) {
        int x = t[1][(st >> 0) & 1];
        int y = t[2][(st >> 1) & 1];
        int z = t[3][(st >> 2) & 1];

        if(s[1][0] <= x && x <= s[1][1] && s[2][0] <= y && y <= s[2][1] && s[3][0] <= z && z <= s[3][1]) {
            if(x == s[1][!((st >> 0) & 1)] || y == s[2][!((st >> 1) & 1)] || s[3][!((st >> 2) & 1)] == z){

            }
            else return true;
        }
    }
    return false;
}

void solve()
{

  
    for(int j = 0; j <= 1; j ++)
        for(int i = 1; i <= 3; i ++) {
            cin >> s[i][j];
    }

    for(int j = 0; j <= 1; j ++)
        for(int i = 1; i <= 3; i ++) {
            cin >> t[i][j];
    }

    if(s[1][0] == s[1][1] && s[2][1] == s[2][0] && s[3][1] == s[3][0]) {
        cout << "No";
        return;
    }

    if(t[1][0] == t[1][1] && t[2][1] == t[2][0] && t[3][1] == t[3][0]) {
        cout << "No";
        return;
    }

    if(pd()) {
        cout << "Yes";
        return;
    }
    swap(s,t);
    if(pd()) {
        cout << "Yes";
        return;
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