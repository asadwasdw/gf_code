#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>adj(N);

int num[] = {2, 3, 3, 3, 3};
int cnt[N];

int a[N];

vector<int> t[10];

int ans = -1;

bool check(vector<int> t) {
    sort(t.begin(), t.end());
    if(t[0] == t[1] && t[1] == t[2]) return true;
    if(t[0] + 1 == t[1] && t[1] + 1 == t[2]) return true;
    return false;
}

void dfs(int x) {


    if(ans != -1) return;
    if(x == 14) {
        for(int i = 0; i < 5 && ans == -1; i ++) {
            if(t[i].size() != num[i]) {
                if(i == 0 || (i != 0 && t[i][0] == t[i][1])) {
                    if(cnt[t[i][0]] < 4) {
                        ans = t[i][0];
                    }
                } else {
                    vector<int> tt = t[i];
                    tt.push_back(0);
                    for(int i = 1; i <= 9; i ++) {
                        if(cnt[i] == 4) continue;
                        tt[2] = i;
                        if(check(tt)) {
                            ans = i;
                        }
                    }
                }
            }
        }

        return;
    }


    for(int i = 0; i < 5; i ++ ) {
        // cout << i << endl;
        if(t[i].size() < num[i]) {
            
            t[i].push_back(a[x]);
            cnt[a[x]] ++;

            bool ky = true;
            if(t[i].size() == num[i]) {
                if(i == 0) {
                    if(t[i][0] != t[i][1]) ky = false;
                } else {
                    if(!check(t[i])) ky = false;
                }
            }

            if(ky) dfs(x + 1);
            t[i].pop_back();
            cnt[a[x]] --;
        }
    }
}




void solve()
{

    for(int i = 0; i < 5; i ++) t[i].clear();
    memset(cnt, 0, sizeof cnt);
    ans = -1;

    for(int i = 1; i <= 13; i ++) {
        char t; cin >> t;
        a[i] = t - '0';
    }

    dfs(1);
    if(ans == -1) cout << "no\n";
    else cout << ans << endl;









}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(11) << fixed;
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}