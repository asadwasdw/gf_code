#include<bits/stdc++.h>
#define endl '\n'
using ll = long long;
using i64 = long long;
using namespace std;
constexpr int N = 2e6 + 10;

int a[N];
int ans = 0;


int check(int D, int C, int H, int S, int xx) {
    int res = D/5 + C/5 + H/5 + S/5;
    priority_queue<int> q;
    q.push(D%5);
    q.push(C%5);
    q.push(H%5);
    q.push(S%5);
    while(q.size()) {
        int u = q.top(); q.pop();
        if(xx + u >= 5) {
            res ++;
            xx -= 5 - u;
        }
    }
    res += xx/5;
    return res;
}

typedef unsigned long long ull;

ull js(int D, int C, int H, int S, int xx) {
    vector<int> v;v.push_back(D);v.push_back(C);v.push_back(H);v.push_back(S);v.push_back(xx);
    for(int i = 1; i <= 6; i ++) v.push_back(a[i]);
    ull res = 0;
    for(int i = 0; i < v.size(); i ++) {
        res = res * 131 + v[i]; 
    }
    return res;
}


int cnt = 0;
unordered_map<int,bool> st;
void dfs(int D, int C, int H, int S, int xx) {

    if(st[js(D, C, H, S, xx)]) return;
    st[js(D, C, H, S, xx)] = true;

    ans = max(ans,check(D, C, H, S, xx));
    cnt ++ ;
    for(int d = 0; d <= min(3, D); d ++ )
    for(int c = 0; c <= min(3, C) && d + c <= 3; c ++ )
    for(int h = 0; h <= min(3, H) && d + c + h <= 3; h ++ )
    for(int s = 0; s <= min(3, S) && d + c + h + s<= 3; s ++ ) {
        if(d + c + h + s != 3) continue;

        for(int i = 1; i <= 4; i ++) {
            if(a[i] <= 0) continue;
            D -= d, C -= c, H -= h,  S -= s;
            a[i] --;
            if(i == 1) D += 3;
            if(i == 2) C += 3;
            if(i == 3) H += 3;
            if(i == 4) S += 3;

            dfs(D, C, H, S, xx);

            D += d, C += c, H += h,  S += s;
            a[i] ++;
            if(i == 1) D -= 3;
            if(i == 2) C -= 3;
            if(i == 3) H -= 3;
            if(i == 4) S -= 3;
        }
    }


    if(a[5] > 0) {
        a[5] --;
        if(D) dfs(D - 1, C, H, S, xx + 1);
        if(C) dfs(D, C - 1, H, S, xx + 1);
        if(H) dfs(D, C, H - 1, S, xx + 1);
        if(S) dfs(D, C, H, S - 1, xx + 1);
        a[5] ++;
    }

    if(a[6] > 0) {
        a[6] --;
        vector<int> v;v.push_back(D);v.push_back(C);v.push_back(H);v.push_back(S);v.push_back(xx);
        for(int i = 0; i < 5; i ++) {
            for(int j = 0; j < 5; j ++) {
                if(i == j) continue;
                if(v[i] == 0 || v[j] == 0) continue;
                v[i] --, v[j] ++;
                dfs(v[0], v[1], v[2], v[3], v[4]);
                v[i] ++, v[j] --;
            }
        }
        a[6] ++; 
    }
}



void solve(){
    st.clear();
    map<char,set<char>> p;
    int n; cin >> n;
    for(int i = 1; i <= n; i ++) {
        string s; cin >> s;
        p[s[1]].insert(s[0]);
    }

    for(int i = 1; i <= 6; i ++) {
        cin >> a[i];
    }
    // cout << check(4, 0, 0, 0, 1) << endl;
    // cout << p['D'].size() << endl;
    // cout << p['C'].size() << endl;
    // cout << p['H'].size() << endl;
    // cout << p['S'].size() << endl;
    
    ans = 0;
    dfs(p['D'].size(),p['C'].size(),p['H'].size(),p['S'].size(), 0);
    cout << ans << endl;
    // cerr << cnt << endl;
}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}