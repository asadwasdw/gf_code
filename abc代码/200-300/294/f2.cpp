#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int N = 4e5+10;

typedef long double ldb;
typedef long long ll;
ll n,m,k;
int x1[N],y[N];
int x2[N],y2[N];

int a[N][5],b[N][5];

long double eps=1e-13;

bool check(ldb C) {
    vector<ldb> aa(n), bb(m);
    for (ll i = 0; i < n; i++)aa[i] = (1.0 - C) * a[i][0] - C * a[i][1];
    for (ll j = 0; j < m; j++)bb[j] = (C - 1.0) * b[j][0] + C * b[j][1];
    sort(aa.begin(), aa.end()), sort(bb.begin(), bb.end());
    ll cur = 0, cnt = 0;
    for (ll i = 0; i < n; ++i) {
        while (cur < m && bb[cur] < aa[i])
            ++cur;
        cnt += cur;
    }
    return cnt <= k;
}

bool check2(long double C)
{
    vector<ldb> aa(n), bb(m);
    for (ll i = 0; i < n; i++)aa[i] = (1.0 - C) * a[i][0] - C * a[i][1];
    for (ll j = 0; j < m; j++)bb[j] = (C - 1.0) * b[j][0] + C * b[j][1];
    sort(aa.begin(), aa.end()), sort(bb.begin(), bb.end());

   ll cur = 0, cnt = 0;

    for(int l=0;l<n;l++)
    {
      while (cur < m && bb[cur] < aa[l])
            ++cur;
        cnt+=cur;
    }

    return cnt<=k;
}

signed main() {
//    freopen("code.in", "r", stdin);
//    freopen("code.out", "w", stdout);
    cin >> n >> m >> k;
    for (ll i = 0; i < n; i++)cin >> a[i][0] >> a[i][1];
    for (ll i = 0; i < m; i++)cin >> b[i][0] >> b[i][1];
    ldb l = 0, r = 1;
    k--;
    while (r - l >eps) {
        ldb mid = (l + r) / 2.0;
        if (check2(mid))
            r = mid;
        else l = mid;
    }
    printf("%.10Lf\n", r * 100);
    return 0;
}