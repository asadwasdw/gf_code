#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<char,int>PII;
const int N=1e5+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);

const int B = 600, L = 200;
vector<PII> p[N];
int cnt, root[N],num[10*N];

void add(string& s, int rt, int x) {
    if(root[rt] == 0) root[rt] = ++cnt;
    int u = root[rt];
    for(char C : s) {
        int v = 0;
        for(auto [c, id] : p[u]) {
            if(c == C) {
                v = id;
                break;
            }
        }
        if(v == 0) {
            v = ++cnt;
            p[u].push_back({C, v});
        }
        num[u = v] += x;
    }
}

int get(string& s, int rt) {
    if(root[rt] == 0) root[rt] = ++cnt;
    int u = root[rt];
    for(char C : s) {
        int v = 0;
        for(auto [c, id] : p[u]) {
            if(c == C) {
                v = id;
                break;
            }
        }
        if(v == 0)  return 0;
        u = v;
    }
    return num[u];
}

string s[N];
vector<int>big;


void solve()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        cin >> s[i];
        if(s[i].size() < L) add(s[i],i/B,1);
        else big.push_back(i);
    }
    int ans = 0;
    while(m -- ) {
        int op,l,r;
        string S;
        char C;
        cin >> op;
        if(op == 1) {
            cin >> l >> r >> C;
            if(s[l].size() < L) {
                add(s[l], l/B, -1);
                s[l][r - 1] = C;
                add(s[l], l/B, 1);
            }
            else {
                s[l][r - 1] = C;
            }
        }
        else {
            cin >> S >> l >> r;
            l = ((l ^ ans) % n) + 1;
            r = ((r ^ ans) % n) + 1;
            if(l > r) swap(l, r);
            ans = 0;
            for(int i = l; i <= r; i ++) {
                if(i % B == 0 && i + B <= r) {
                    // cout << i << " " << get(S,i/l) << " " << r << endl;
                    ans += get(S,i/B);
                    i += B - 1;
                }
                else if(s[i].size() < L && s[i].size() >= S.size()) {
                    ans++;
                    for(int j = 0; j < S.size(); j ++) 
                        if(s[i][j] != S[j]) {
                            ans--;
                            break;
                        }
                }
            }


            for(auto i : big) {
                if(i < l || i > r) continue;
                if(s[i].size() >= S.size()) {
                    ans ++;
                    for(int j = 0; j < S.size(); j ++) 
                        if(s[i][j] != S[j]) {
                            ans--;
                            break;
                        }
                }
            }

            cout << ans << endl;

        }

        
    }

// for(int i = 1; i <= n; i ++) cout << i << " " << s[i] << endl; 





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