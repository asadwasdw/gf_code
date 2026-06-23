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


void solve()
{

    string s;
    cin >> s;
    sort(s.begin(), s.end(),[&](char a, char b){
        return a > b;
    });
    // for(int i = 0; i + 2 < s.size(); i ++) {
    //     string t = s.substr(i, 3);
    //     if(t == "FFT") swap(s[i], s[i + 2]);
    //     if(t == "NTT") swap(s[i], s[i + 1]);
    //     cout << s << endl;
    // }
    cout << s << endl;







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