#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);
int n,m;
// int a[N];
string s;
bool f;
int check(int l){
    int s1 = 0;
    if(s[l] == ')' || s[l] == '(')s1 = 1;
    return s1;
}
void dfs(int l, int r){
    
    if(l == r){
        f = false;return;
    }
    if(check(l) != check(r)){
        f = false;return;
    }
    if(r - l == 1)return;
    if(check(l+1) == check(r-1) && check(l+1) != check(l)){
        dfs(l+1, r-1);
    }
    else f = false;
}
void solve()
{
    cin >> s;
    if(s.size() % 2 == 1){
        cout << "No" << endl;return;
    }
    f = true;
    int c1 = 0, c2 = 0;
    vector<int> p;
    int cnt = 0, pos = 0;
    for(int i=0; i<s.size(); ++i){
        int cur = check(i);
        if(p.empty())p.push_back(cur);
        else if(p.back() == cur)p.pop_back();
        else p.push_back(cur);
        if(p.empty()){
            if(!pos)
            pos = i;
            ++cnt;
        }
    }
    
    // cout << cnt << endl;
    if(p.size() || cnt > 2)f = false;
    
    dfs(0, pos);
    // cout << 0 << ' ' << pos << endl;
    if(pos + 1 <= s.size() - 1){
        dfs(pos + 1, s.size() - 1);
        if(check(pos) == check(pos + 1))f = false;
    }
    if(f){
        cout << "Yes\n";
    }
    else cout << "No\n";
    





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