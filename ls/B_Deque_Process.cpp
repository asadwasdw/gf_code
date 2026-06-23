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


int a[N];
void solve()
{
    string s;
    int n; cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    int l = 1, r = n;
    while(l <= r) {
        if((r - l) % 2 == 0) {
            if(a[l] < a[r]) s += 'L',l ++;
            else s += 'R', r --;
        } else {
            if(a[l] > a[r]) s += 'L', l ++;
            else s += 'R', r -- ;
        }
    }
    cout << s << endl;
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