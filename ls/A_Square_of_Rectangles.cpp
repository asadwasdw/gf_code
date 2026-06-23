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
    int l1, b1, l2, b2, l3, b3;
    cin >> l1 >> b1 >> l2 >> b2 >> l3 >> b3;

    int area = l1 * b1 + l2 * b2 + l3 * b3;
    int len = sqrt(area);
    if(area != len * len) {
        cout << "No\n";
        return;
    }

    bool ky = false;

    if(l1 == len) {
        if(l1 == l2 && l2 == l3 && b1 + b2 + b3 == len) ky = true;
        if(l2 + l3 == len && b2 == b3 && b1 + b2 == len) ky = true;
    }  

    if(b1 == len) {
        if(b1 == b2 && b2 == b3 && l1 + l2 + l3 == len) ky = true;
        if(b2 + b3 == len && l2 == l3 && l1 + l2 == len) ky = true;
    }

    if(ky) cout << "Yes\n";
    else cout << "No\n";

    


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