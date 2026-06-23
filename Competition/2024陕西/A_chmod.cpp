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
    for(int i = 1; i <= 3; i ++) {
        char T;
        cin >> T;
        int t = (T - '0');


        for(int j = 2; ~j ; j --) {
            if((t >> j) & 1){
                if(j == 0) cout << 'x';
                if(j == 1) cout << 'w';
                if(j == 2) cout << 'r';
            }
            else cout << "-";
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