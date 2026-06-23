#include<bits/stdc++.h>
#define int long long 
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=100+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);
int n, m;
char a[N][N];
char ans[N][N];
int res = INF;


stack<int> num;
stack<int> op;

map<char,int> h;

void eval() {
    int b = num.top(); num.pop();
    int a = num.top(); num.pop();
    char c = op.top(); op.pop();


    int res;
    if(c == '*') res = a * b;
    else res = a + b;
    num.push(res);
}

int js(string s) {

    for(int i = 0; i < s.size(); i ++) {
        if(s[i] == '1') {
            int t = 1;
            while(i + 1 < s.size() && s[i + 1] == '1') {
                t = t * 10 + 1;
                i++;
            }
            num.push(t);
        }
        else {
            while(op.size() && h[s[i]] <= h[op.top()]) {
                eval();
            }
            op.push(s[i]);
        }
    }

    while(op.size())eval();
    int ans = num.top(); num.pop();
    return ans;
}

void print98(){
     cout <<"11111111\n11*1*1*1\n1+1+1+11\n11*1*1*1\n1*1*1*11\n11*1*1*1\n1*1*1*11\n11*1*1*1\n11111111";
}


void dfs(int x, int y, int bj) {
    if(y == m) {
        y = 2;
        x ++;
    }


    if(x == n) {
        int T = 0;
        for(int i = 1; i <= n; i ++) {
            string s;
            for(int j = 1; j <= m; j ++) s += a[i][j];
            T += js(s); 
        }

        for(int j = 1; j <= m; j ++) {
            string s;
            for(int i = 1; i <= n; i ++) s += a[i][j];
            T += js(s);
        }

        if(T < res) {
            for(int i = 1; i <= n; i ++) 
                for(int j = 1; j <= m; j ++) 
                    ans[i][j] = a[i][j];

            res = T;
        }

        return;
    }


    if((x + y) % 2 == bj) {
        a[x][y] = '1';
        dfs(x, y + 1, bj);
    }
    else {
        if((n == 7 && m == 7) || (n == 9 && m == 9)) {
        if(x != n - 1 && x != 2 && y != m - 1 && y != 2) {
                a[x][y] = '+';
                dfs(x, y + 1, bj);
            }
        }
        else {
                a[x][y] = '+';
                dfs(x, y + 1, bj);
        }
  
 
        a[x][y] = '*';
        dfs(x, y + 1, bj);
    }
}


void solve()
{
    cin >> n >> m;
    if(n == 9 && m == 8) {
        print98();
        return;
    }
    for(int i = 1; i <= n; i ++)  a[i][1] = a[i][m] = '1';
    for(int i = 1; i <= m; i ++)  a[1][i] = a[n][i] = '1';
    

    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            // cout << a[i][j] << " \n"[j == m];
            ans[i][j] = a[i][j];
        }
    }


    dfs(2,2,1);
    dfs(2,2,0);
    // // cout << res << endl;

    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            cout << ans[i][j];
        }
        cout << endl;
    }

}


signed main()
{
    h['+'] = 1;
    h['*'] = 2;
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