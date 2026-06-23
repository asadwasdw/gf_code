#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);

int a[N];
int d[N];

void solve()
{
    int n; cin >> n;
    string s; cin >> s;
    s = " " + s;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        d[a[i]]++;
    }
    queue<int>q;

    for(int i = 1; i <= n; i++) {
        if(d[i] == 0) q.push(i);
    }

    vector<int> ans;
    while(q.size()) {
        int t = q.front(); q.pop();
    
        if(s[t] == '1') {
            s[t] = '0';
            s[a[t]] ^= 1;
            ans.push_back(t);
        }

        d[a[t]] --;
        if(d[a[t]] == 0) {
            q.push(a[t]);
        }
    }

    // for(int i = 1;i<=n;i++)cout << d[i] <<" ";cout << endl;
    // cout << s << endl;


    for(int i = 1; i <= n; i++) {

        if(d[i]) {
            int j = i;
            int len = 0;
            int res = 0;
            int t = 0;
            while(d[j]){
                if(s[j]=='1') {
                    t^=1;
                }
                if(t)res++;
                d[j] = 0;
                len ++;
                j = a[j];
            }

            if(t) {
                cout << "-1\n";
                return ;
            }   
        

            for(int k = 1; k <= len; k++) {
                if(s[j] == '1') {
                    t^=1;
                }

                if(t == (res < len - res)) {
                    ans.push_back(j);
                }
                j=a[j];
            }
        }
    }

    cout << ans.size() << endl;
    for(auto t:ans) cout << t << " \n"[t==ans.back()];

    for (int i= 1;i<=n;i++)d[i] = a[i] = 0;

}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}