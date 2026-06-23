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
int a[N];

void solve()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    if(n > 31) {
        cout << "NO";
        return;
    }

    if(n == 31) {
        sort(a+1,a+n+1);
        for(int i = 1; i <= n; i ++) {
            if(a[i] != (1<<(i - 1))) {
                cout << "NO";
                return;
            }
        }
        cout << "YES";
        return;
    }

    int n1 = n/2;

    set<int>s;
    bool ky = false;
    for(int st = 1; st < pow(3,n1); st ++) {
        int ST = st;
        int i = 1;
        int sum = 0;
        while(ST) {
            int t = ST % 3;
            if(t == 1) sum += a[i];
            if(t == 2) sum -= a[i];
            i++;
            ST/=3;
        }
        // cout << "1 " << sum << endl;
        s.insert(sum);
        if(sum == 0) ky = true;

    }

    for(int st = 1; st < pow(3,n - n1); st ++) {
        int ST = st;
        int i = 1 + n1;
        int sum = 0;
        while(ST) {
            int t = ST % 3;
            if(t == 1) sum += a[i];
            if(t == 2) sum -= a[i];
            i++;
            ST/=3;
        }
        if(sum == 0) ky = true;
        if(s.count(sum)) ky = true;
        //  cout << "2 " << sum << endl;
    }
    if(!ky)cout << "YES";
    else cout << "NO";







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