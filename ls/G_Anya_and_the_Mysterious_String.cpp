#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

int tr[N];
int n;
void modify(int x, int k) {
    for(int i = x; i <= n; i += i&-i) tr[i] += k;
}

void modify(int l, int r, int k){
    modify(l, k);
    if(r + 1 <= n)modify(r + 1, -k);
}

int query(int x) {
    int res = 0;
    for(int i = x; i ; i -= i&-i) res += tr[i];
    return res;
}



void solve()
{
    int m;
    cin >> n >> m;

    for(int i = 0; i <= n; i++) tr[i] = 0;

    string s;
    cin >> s;
    s = " " + s;

    for(int i = 1; i <= n; i++){
        modify(i,i,s[i] - 'a');
    }

    set<int>s2, s3;
    for(int i = 1; i <= n; i++) {
        if(i + 1 <= n && s[i] == s[i + 1]) s2.insert(i);
        if(i - 1 >= 1 && i + 1 <=n && s[i - 1] == s[i + 1]) s3.insert(i);
    }

    while(m--) {
        int op;
        cin >> op;
        if(op == 1){
            int l, r, x;
            cin >> l >> r >> x;
            modify(l, r, x);

            auto check = [&](int pos) {
                if(pos < 1 || pos > n)return ;
                if(pos + 1 <= n) {
                    int x1 = query(pos) % 26;
                    int x2 = query(pos + 1) % 26;
                    if(x1 == x2) s2.insert(pos);
                    else s2.erase(pos);
                }
                if(pos + 1 <= n || pos - 1 >= 1) {
                    int x1 = query(pos - 1) % 26;
                    int x2 = query(pos + 1) % 26;
                    if(x1 == x2) s3.insert(pos);
                    else s3.erase(pos);
                }
            };

            for(int i = -1; i <= 1; i++) {
                check(l + i);
                check(r + i);
            }
        }
        else {
            int l, r;
            cin >> l >> r;
            bool ok = false;
            {
                auto it = s2.lower_bound(l);
                if(it != s2.end() && (*it + 1) <= r)ok=true;
            }
            
            {
                auto it = s3.upper_bound(l);
                if(it != s3.end() && (*it + 1) <= r)ok=true;
            }
            if(ok)cout<<"NO\n";
            else cout<<"YES\n";
        }
    }

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