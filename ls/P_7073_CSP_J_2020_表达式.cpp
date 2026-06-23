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

int f[N],st[N];
int find(int x) {
    if(f[x] != x) return find(f[x]);
    return f[x];
}

void merge(int a,int b) {
    a = find(a), b = find(b);
    f[a] = b;
}

void solve()
{

    string s;
    getline(cin, s);
    int n; cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    for(int i = 1; i <= 3 * n; i ++) f[i] = i;

    stack<PII> num;
    int cnt = n;
    for(int i = 0; i < s.size(); i ++) {
        if(s[i] == ' ') continue;
        if(s[i] == 'x') {
            int id = 0;
            for(int j = 1; i + j < s.size(); j ++) {
                if(s[i + j] >= '0' && s[i + j] <= '9') 
                    id = id * 10 + s[i + j] - '0';
                else {
                    i += j;
                    break;
                }
            }
            num.push({a[id], id});
        } else if(s[i] == '!') {
            num.top().first ^= 1;
        }
        else {
            ++cnt;
            PII b = num.top();num.pop();
            PII a = num.top();num.pop();
            if(s[i] == '&') {
                if(a.x == 0) st[b.y] = 1;
                if(b.x == 0) st[a.y] = 1;
                num.push({a.x&b.x, cnt});
            } 
            if(s[i] == '^') {
                num.push({a.x^b.x, cnt});
            }
            if(s[i] == '|') {
                if(a.x == 1) st[b.y] = 1;
                if(b.x == 1) st[a.y] = 1;
                num.push({a.x|b.x, cnt});
            }
            f[a.second] = cnt, f[b.second] = cnt;
        }
    }

    // cout << num.top().first << endl;


    for(int i = cnt; i >= 1; i --) {
        st[i] |= st[f[i]];
    }

    // for(int i = 1; i <= cnt; i ++) cout << st[i] << " \n"[i == cnt];

    int q; cin >> q;
    while(q --) {
        int x; cin >> x;
        cout << (num.top().first ^ st[x] ^ 1) << endl;
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