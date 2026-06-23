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

void solve()
{

    int n;cin >> n;
    vector<vector<int>> a(n, vector<int> (n));
    for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) 
        cin >> a[i][j];
    getchar();
    string s;
    getline(cin, s);
    while (s.size() % n) s += ' ';
    int m = s.size();

    vector<int> b(n);
    map<char, int> mp1;
    map<int, char> mp2;
    for (char i = 'A'; i <= 'Z'; i++) {
        mp1[i] = i - 'A';
        mp2[i - 'A'] = i;
    }
    for (char i = '0'; i <= '9'; i++) {
        mp1[i] = i - '0' + 26;
        mp2[i - '0' + 26] = i;
    }
    mp1[' '] = 36;
    mp2[36] = ' '; 
    auto calc = [&]() -> vector<int> {
        vector<int> c(n);
        for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            (c[i] += a[i][j] * b[j] % 37) %= 37;
        }
        return c;
    };
    
    for (int i = 0; i < m; i++) {
        if (i % n == 0) b.assign(n, 36);
        b[i % n] = mp1[s[i]];
        if ((i + 1) % n == 0) {
            auto c = calc();
            
            for (int j = 0; j <= i % n; j++) {
                cout << mp2[c[j]];
            }
        }
    }    



}


signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0),cout.tie(0);
    cout << setprecision(11) << fixed;
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}