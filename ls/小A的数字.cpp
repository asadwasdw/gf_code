#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);


void solve()
{
    int n;
    cin >> n;

    string s = to_string(n);
    reverse(s.begin(),s.end());
    string ans;
    for(auto t : s) {
        if(t != '0') {
            ans += '0';
        }else ans += '1';
    }
    reverse(ans.begin(),ans.end());
   
    int Ans = stoi(ans);
    // cout << Ans << endl;
    if(Ans == 0) {
        if(s[0] == '1')  cout <<"2\n";
        else cout<<"1\n";
    }
    else cout << Ans << "\n";






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