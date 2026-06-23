#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);
int n,cnt;
unordered_map<char,int>id;
char zf[N];
set<int>s;
void add(char x) {
    if(!s.count(x)) {
        s.insert(x);
        id[x] = ++ cnt;
    }
}
string str[N];

bool ky[50][50];

vector<int>st[5];
int ans = 0;
void dfs(int x) {
    if(ans) return;
    if(x == 19) {
        ans = 1;
        for(int i=1;i<=3;i++) {
            for(auto t:st[i])cout<<zf[t];cout<<" ";
        }
        return ;
    }
    for(int i = 1;i <= 3; i++) {
        if(st[i].size() >= 6) continue;
        bool ok = true;
        for(auto t : st[i]) {
            if(ky[t][x]) {
                ok = false;
                break;
            }
        }
        if(ok) {
            st[i].push_back(x);
            dfs(x+1);
            st[i].pop_back();
        }
    }
}


void solve()
{
    cin >> n;
    for(int i=1;i<=n;i++) {
        cin >> str[i];
        str[i] = " " + str[i];
        add(str[i][1]);
        add(str[i][2]);
        add(str[i][3]);
        int x1 = id[str[i][1]];
        int x2 = id[str[i][2]];
        int x3 = id[str[i][3]];
        ky[x1][x2] = ky[x2][x3] = ky[x1][x3] = 1;
        ky[x2][x1] = ky[x3][x2] = ky[x3][x1] = 1;

        if(x1 == x2 || x1 == x3 || x2 == x3) ans = -1;
    }

    for(int i=1;i<=18;i++) {
        int num = 0;
        for(int j=1;j<=18;j++) {
            num += ky[i][j];
        }
        if(num>=13)ans = -1;
    }

 
    while(cnt <= 18) {
        for(int i = 0; i < 26;i++) {
            add('a' + i);
        }
    }

    for(auto [c,i]:id) {
        zf[i] = c; 
    }

    dfs(1);

    if(ans  != 1) {
        cout<<'0';
        return;
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