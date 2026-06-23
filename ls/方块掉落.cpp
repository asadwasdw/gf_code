#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=2e5+10;
const int mod=1e9+7;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

using namespace std;


//vector<vector<int>>edg(N);

ll pow2[N];

void init(){
    pow2[0]=1;
    for(int i = 1; i < N; i++) pow2[i] = 2*pow2[i-1] % mod;
}


struct Data {
    ll a=0,b=0;
    void init() {
        a=0,b=0;
    }
    void print() {
        cout << "a:" << a <<" b:" << b <<endl;
    }
};

Data operator + (const Data &left,const Data &right) {
    Data res;
    res.a = (left.a * pow2[right.b] + right.a)%mod;
    res.b = left.b + right.b;
    return res;
}

struct Node
{
    int l,r;
    Data lData,rData,data;
    ll mid=0;
    bool bule=0;

    void init() {
        lData.init();
        rData.init();
        data.init();
        bule=false;
        mid = 0;
    }

    void print() {
        cout  << l << " " <<r<<endl;
        cout << "lData: ";lData.print();
        cout << "rData: ";rData.print();
        cout << "data: "; data.print();
        cout << "mid: " << mid<<endl;
        cout << "bule: " << bule <<endl;

    }
}tr[N<<2];

Node operator + (const Node &left,const Node &right) {
    Node res;
    res.l = left.l;
    res.r = right.r; 
    if(left.bule && right.bule) {
        res.lData = left.lData;
        res.rData = right.rData;
        res.mid = ((left.rData + right.lData).a) + left.mid + right.mid; 
        res.bule = true;
    }
    else if(left.bule) {
        res.lData = left.lData;
        res.rData = left.rData + right.data;
        res.mid = left.mid;
        res.bule = true;
    }
    else if(right.bule) {
        res.rData = right.rData;
        res.lData = left.data + right.lData;
        res.mid = right.mid;
        res.bule = true;
    }
    else {
        res.data = left.data + right.data;
    }
    return res;
}

int n,m;
string s;

void build(int u,int l,int r) {
    tr[u] = {l,r};
    if(l == r) {
        if(s[l] == 'B') {
            tr[u].bule = true;
            tr[u].rData.a = 1;
        }
        else if(s[l] == 'R') {
            tr[u].data.a = 1;
            tr[u].data.b = 1;
        }
        else {
            tr[u].data.a = 1;
        }
        // tr[u].print();
        return;
    }
    int mid = (l + r) >> 1;
    build(u<<1, l, mid);
    build(u<<1|1, mid + 1, r);
    tr[u] = tr[u<<1] + tr[u<<1|1];
    // tr[u].print();
}

void modify(int u,int x,char y) {
    if(tr[u].l == tr[u].r && tr[u].l == x) {
        s[x] = y;
        tr[u].init();
        int l = x;
        if(s[l] == 'B') {
            tr[u].bule = true;
            tr[u].rData.a = 1;
        }
        else if(s[l] =='R') {
            tr[u].data.a = 1;
            tr[u].data.b = 1;
        }
        else {
            tr[u].data.a = 1;
        }
        return;
    }
    
    int mid = (tr[u].l + tr[u].r) >> 1;
    if(x <= mid)modify(u<<1, x, y);
    if(x >= mid + 1) modify(u<<1|1, x, y);
    tr[u] = tr[u<<1] + tr[u<<1|1];
}

Node query(int u,int l,int r) {
    if(l <= tr[u].l && tr[u].r <= r) {
        return tr[u];
    }
    int mid = (tr[u].l + tr[u].r) >> 1;
    if(r <= mid) return query(u<<1,l,r);
    else if(l >= mid + 1) return query(u<<1|1,l,r);
    return query(u<<1,l,r) + query(u<<1|1,l,r);
}

void solve()
{
    cin >> n >> m;
    cin >> s;
    s = " " + s;
    build(1,1,n);
    while(m --) {
        int op; cin >> op;
        if(op == 1) {
            int x;char y;
            cin>>x>>y;
            modify(1,x,y);
        }
        else {
            int l, r;
            cin >> l >> r;
            auto res = query(1,l,r);
            // res.print();
            cout << (res.lData.a + res.rData.a + res.mid + res.data.a)%mod<<endl;
        }
    }

    // cout << s <<endl;


}


signed main()
{
    init();
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