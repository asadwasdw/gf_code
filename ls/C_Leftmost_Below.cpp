#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>adj(N);

int a, b;

int my_atoi(string s) {
    int res = 0;
    for(int i = 0; i < s.size(); i ++) {
        res = res * 10 + s[i] - '0';
    }
    return res;
}


bool pd(string s) {
    int x = my_atoi(s);
    if(x < a || x > b) return false;

    for(int i = 2; i * i <= x; i ++) {
        if(x % i == 0) {
            return false;
        }
    }
    return true;
}


void solve()
{
    cin >> a >> b;
    vector<int> ans;

    for(int i = 1; i <= 9999; i ++) {
        string s = to_string(i);
        string t = s;
        reverse(t.begin(), t.end());
        string s1 = s + t;
        string s2 = s + t.substr(1);

        if(pd(s1)) ans.push_back(my_atoi(s1));
        if(pd(s2)) ans.push_back(my_atoi(s2));
    }

    sort(ans.begin(), ans.end());
    
    for(auto t : ans)  cout << t << endl;


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


