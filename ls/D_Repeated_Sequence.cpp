#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>adj(N);

int a[N], s1[N], s2[N];
map<int,bool> st;
void solve()
{
    int n, s;
    cin >> n >> s;
    st[0] = true;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        s1[i] = s1[i - 1] + a[i];
    }
    for(int i = n + 1; i <= 2 * n; i ++) {
        s1[i] = s1[i - 1] + a[i - n];
    }
    s %= s1[n];
    // cout << s << endl;

    for(int i = 0; i <= n * 2; i ++) {
        if(st[s1[i] - s] == true) {
            cout << "Yes";
            return;
        }
        st[s1[i]] = true;
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