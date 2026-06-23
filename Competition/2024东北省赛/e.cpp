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


void solve()
{
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int a = 0;
    for(auto t : s) if(t == '1') a ++;
    for(int st = 0; st < (1 << k) ; st ++) {
        int b = __builtin_popcount(st);
        if(a + b == st) {
            stack<int> sta;
            while(k --) {
                sta.push(st % 2);
                st/=2;
            }
            while(sta.size()) {
                cout << sta.top();
                sta.pop();
            }
            cout << endl;
            return;
        } 
    }

    cout << "None"<<endl;

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