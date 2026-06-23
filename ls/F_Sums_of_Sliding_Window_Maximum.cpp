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

#define int long long
int a[N];
int l[N], r[N];
int s[N];

void solve()
{
    int n; cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    // int lasti = 0, lastmx = 0;
    stack<int> mx, lasti; 
    for(int i = 1; i <= n; i ++) {
        while(mx.size() && a[i] > mx.top()) mx.pop(), lasti.pop(); 

        if(mx.size() == 0) {
            l[i] = 0;
        } else {
            l[i] = lasti.top();
        }

        mx.push(a[i]);
        lasti.push(i);
    }

    while(mx.size()) {
        mx.pop(); lasti.pop();
    }


    for(int i = n; i >= 1; i --) {
        while(mx.size() && a[i] >= mx.top()) mx.pop(), lasti.pop(); 

        if(mx.size() == 0) {
            r[i] = n + 1;
        } else {
            r[i] = lasti.top();
        }

        mx.push(a[i]);
        lasti.push(i);
    }

    for(int i = 1; i <= n; i ++) {
        // cout << i << " " << l[i] << " " << r[i] << endl;
        int L = l[i] + 1, R = r[i] - 1;
        // cout << i << " " << L << " " << R << endl;

        if(i - L < R - i) {
            for(int j = L; j <= i; j ++) {
                int sl = i - j + 1;
                int sr = R - j + 1;
                s[sl] += a[i];
                s[sr + 1] -= a[i];
            }
        } else {
            for(int j = R; j >= i; j --) {
                int sl = j - i + 1;
                int sr = j - L + 1;
                s[sl] += a[i];
                s[sr + 1] -= a[i];
            }
        }
    }


    for(int i = 1; i <= n; i ++) {
        s[i] += s[i - 1];
        cout << s[i] << endl;
    }







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