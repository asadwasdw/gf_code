#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

//vector<vector<int>>adj(N);

int tr[N];
int n;

int lowbit(int x) {
    return x&-x;
}

void add(int x, int y) {
    for(int i=x;i<N;i+=lowbit(i))tr[i]+=y;
}

int get(int x) {
    int res=0;
    for(int i=x;i;i-=lowbit(i))res+=tr[i];
    return res;
}



void solve()
{
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i ++) {
        int x; cin >> x;
        add(i, x);
    }

    while(q -- ) {
        int op, l, r, x;
        cin >> op;
        if(op == 1) {
            cin >> x;
            int a = get(x) - get(x - 1); 
            int b = get(x + 1) - get(x);
            
            add(x, b - a);
            add(x + 1, a - b);
        }else {
            cin >> l >> r;
            cout << get(r) - get(l - 1) << endl;
        }
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
    return 0;
}