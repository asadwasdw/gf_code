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

struct {
    int son[26];
    int end;
    int fail;
} t[N];
int cnt;


void Insert(string s) {
    int now = 0;
    for(int i = 0; i < s.size(); i ++) {
        int ch = s[i] - 'a';
        if(t[now].son[ch] == 0) {
            t[now].son[ch] = cnt ++;
        }
        now = t[now].son[ch];
    }
    t[now].end ++;
}

void getFail() {
    queue<int> q;
    for(int i = 0; i < 26; i ++) {
        if(t[0].son[i]) {
            q.push(t[0].son[i]);
        }
    }
    while(q.size()) {
        int now = q.front(); q.pop();
        for(int i = 0; i < 26; i ++) {
            if(t[now].son[i]) {
                t[t[now].son[i]].fail = t[t[now].fail].son[i];
                q.push(t[now].son[i]);
            } else {
                t[now].son[i] = t[t[now].fail].son[i];
            }
        }
    }
}


int query(string s) {
    int ans = 0;
    int now = 0;
    for(int i = 0; i < s.size(); i ++) {
        int ch = s[i] - 'a';
        now = t[now].son[ch];
        int tmp = now;
        while(tmp && t[tmp].end != -1) {
            ans += t[tmp].end;
            t[tmp].end = -1;
            tmp = t[tmp].fail;;
        }
    }
    return ans;
}

string s[N];

void solve()
{
    cnt = 1;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> s[i];
        Insert(s[i]);
    }
    string t;
    getFail();
    cin >> t;
    printf("%d\n", query(t));
}


signed main()
{
   
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
    return 0;
}