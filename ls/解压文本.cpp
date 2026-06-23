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
int a[N];

string S[N];

bool st[N];

string dfs(int x){
    if(x < 1)return "";
    if(x > n)return "";
    if(st[x]) {
        cout << '#';
        exit(0);
    }
    
    st[x] = true;
    string res;

    for(int i = 0 ;i < S[x].size() - 1; i ++) {
        if(S[x][i]=='*') {
            res += dfs(S[x][i + 1] - '1' + 1);
            i ++;
        }
        else res += S[x][i] ;
    }
    st[x] = false;
    return res;
}

void solve()
{
    scanf("%d\n",&n);

    for(int i = 1; i <= n; i ++) {
        char t;
        string s;

        while(1) {
            string t;
            getline(cin,t);
            bool js = false;
            for(auto T : t) {
                if(T == '#')js = true;
            }
            s += t ;
            s += '\n';
            if(js)break;
            
        }
        S[i] = s;
        // cout << S[i] ;
    }

    string ans = dfs(1);
    string aaa;
    for(auto t : ans) {
        if(t != '#') aaa += t;
    }
    if(aaa.size() > 1e6) {
        cout << "#";
    }
    else {
        cout << aaa;
    }








}


signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0),cout.tie(0);
    // cout << setprecision(11) << fixed;
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}