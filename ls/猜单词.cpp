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

struct OP{
    string s;
    int a,b;
}op[6];


void solve()
{
    for(int i = 1; i <= 5; i ++) {
        cin >> op[i].s >> op[i].a >> op[i].b;
        op[i].s = " " + op[i].s;
    }

    vector<string>ans;

    for(char t1 = 'A'; t1 <= 'Z' ; t1 ++) {
        for(char t2 = 'A'; t2 <= 'Z'; t2 ++) {
            for(char t3 = 'A'; t3 <= 'Z'; t3 ++) {
                string t = "";
                t += t1;
                t += t2;
                t += t3;

                bool ky = true;
                
                for(int i = 1; i <= 5; i ++) {
                    int a  = 0, b = 0;
                    for(int j = 1; j <= 3; j ++) {
                        if(op[i].s[j] == t1 || op[i].s[j] == t2  || op[i].s[j] == t3 ) {
                            a ++;
                        }
                        if(op[i].s[j] == t[j - 1]) b ++;
                    }
                    if(a == op[i].a && b == op[i].b) {

                    }
                    else ky = false;
                    // if(t == " KFC") cout << a << " " << b << " " << op[i].a << " " << op[i].b << endl;
                }
                
                if(ky)ans.push_back(t);
            }
        }
    }

    cout << ans.size() << endl;
    for(auto t : ans) cout << t << endl; 







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