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
    string op;
    string S;
    cin >> n;
    cin >> op;
    while(n -- ) {
        string t = "";
        vector<string>s;
        cin >> S;
        // cout << S << endl;
        for(int i = 0; i < S.size(); i ++) {
            if(S[i] == '_') {
                s.push_back(t);
                t = "";
            }
            else if(S[i]>='A' && S[i] <= 'Z') {
                if(t.size())s.push_back(t);
                t = (char)(S[i] - 'A' + 'a');
            }
            else {
                t += S[i];
            }
        }
        s.push_back(t);

        for(int i = 0; i < s.size();i ++) {
            string t  = s[i];
            if(op == "Snake" && i != 0) {
                cout << "_" ;
            }

            if(op == "Camel") {
                if(i != 0) t[0] = (char)(t[0] - 'a' + 'A');
            }

            if(op == "Pascal") {
                 t[0] = (char)(t[0] - 'a' + 'A');
            }
            cout << t;
        }
        cout <<endl;
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