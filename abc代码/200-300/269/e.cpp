#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int, char>PII;
const int N = 1e6 + 10;
const int mod = 998244353;
const int INF = 0x3f3f3f3f;
const ll INFll = 0x3f3f3f3f3f3f3f3f;




void solve()
{
    int n;
    cin >> n;

    int ansx=0, ansy=0;

    int l = 1, r = n;

    while (l < r)
    {
        int x;
        int mid = l + r >> 1;
        cout << "? 1 " << n << " " << l << " " << mid << endl;;
        cin >> x;
       // cout << x << " " << mid - l + 1 << endl;
        if (x != mid - l + 1)r = mid;
        else l = mid + 1;
    }
    ansy = l;
    l = 1,r=n;

    while (l < r)
    {
        int x;
        int mid = l + r >> 1;
        cout << "? " << l << " " << mid<<" 1 "<<n << endl;;
        cin >> x;
       // cout << x << " " << mid - l + 1 << endl;
        if (x != mid - l + 1)r = mid;
        else l = mid + 1;
    }
    ansx = r;
    cout << "! " << ansx << " " << ansy << endl;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t; t = 1;
    //cin>>t;
    for (int i = 1; i <= t; i++) {
        //printf("Case %d: ",i);
        solve();
    }
}