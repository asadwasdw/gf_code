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
    string s;
    cin >> s;
    s.reserve();
    string x, y;
    bool xy = true;
    bool z = false;
    for(auto t : s) {
        if(t == 'X') {
            if(z) {
                cout << "-1";
                return ;
            }
            
            x +='1';
            y +='0'; 
        }
        else if(t == 'Y') {
            if(z) {
                cout << "-1";
                return ;
            }

            y += '1';
            x += '0';
        }
        else x += '0', y += '0', z = true;
    }
    cout << x << "\n" << y;







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