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

//vector<vector<int>>edg(N);
int n,m;

vector<int> add(vector<int> a, vector<int> b) {
    vector<int> res;
    int t = 0;
    for(int i = 0; i < a.size() || i < b.size();i ++) {
        if(i < a.size()) t += a[i];
        if(i < b.size()) t += b[i];
        res.push_back(t % 10);
        t /= 10;
    }
    while(t) {
        res.push_back(t % 10);
        t /= 10;
    }

    return res;
}

void print(vector<int> res) {
    for(int i = res.size() - 1; ~i; i --) {
        cout << res[i];
    }
    cout << endl;
}

void solve()
{
    int n;
    cin >> n;
    // vector<int> f,a;
    // f.push_back(2);
    // a.push_back(2);
    // for(int i = 2; i <= n; i ++) {
    //     f = add(add(f,f),a);
       
    // }
    // print(f);
    int a = 2;
    for(int i = 2; i <= n; i ++) {
        a = a * a + 2;
    }
    cout << a;

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