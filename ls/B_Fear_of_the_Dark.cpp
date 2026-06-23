#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-8;
//vector<vector<int>>edg(N);

struct node{
    double x,y;

    double js(node t) {
        return  sqrt((t.x - x) * (t.x - x) + (t.y - y) * (t.y - y));
    }
};
node O,P,A,B;

int f[5];
int find(int x) {
    if(x != f[x]) f[x] = find(f[x]);
    return f[x];
}

bool check(double mid) {
    for(int i = 0;i < 5; i++) f[i] = i;

    if(B.js(A) <= 2*mid) {
        f[find(3)] = 4;
    }
    if(O.js(A) <= mid) {
        f[find(1)] = 4;
    }

    if(P.js(A) <= mid) {
        f[find(2)] = 4;
    }   

    if(O.js(B) <= mid) {
        f[find(1)] = find(3);
    }

    if(P.js(B) <= mid) {
        f[find(2)]= find(3);
    }

    return find(1) == find(2);

}

void solve()
{
    cin >> P.x >> P.y >> A.x >> A.y >> B.x >> B.y;

    double l = 0, r = 1e6;
    while(r - l >= eps) {
        double mid = (r + l) / 2;
        if(check(mid))r = mid;
        else l = mid;
    }
    printf("%.8lf\n",l);

}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}