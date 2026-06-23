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

map<int,int> mp;
map<int,PII> small;



int a[N];

int A, B, C, D;

void solve()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        int x;
        cin >> x;
        mp[x] = 1;
        a[i] = x;
    }
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i ++) {
        int x = a[i];
        if(!B && mp[x] && !mp[x + 1] && x + 1 <= n + m) {
            A = x, B = x + 1;
        }
        else if(B && B != x - 1 && mp[x] && !mp[x - 1] && x - 1) {
            C = x - 1;
            D = x;
            cout << B << " " << C << " " << A << " " << D << endl;
            return;
        }
    }

    A = B = C = D = 0;

    for(int i = 1; i <= n; i ++) {
        int x = a[i];
        if(!B && mp[x] && !mp[x - 1] && x - 1) {
            A = x - 1, B = x;
        }
        else if(B && mp[x] && !mp[x + 1] && x + 1 <= n + m) {
            C = x;
            D = x + 1;
            cout << A << " " << D << " " << B << " " << C << endl;
            return;
        }
    }

    cout << "-1" << endl;








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