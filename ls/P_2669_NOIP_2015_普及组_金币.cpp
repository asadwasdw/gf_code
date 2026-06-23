#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

//vector<vector<int>>adj(N);


void solve()
{
    int k;
    cin >> k;
    int sum = 0;
    int a = 1; // 当前天发的金币数量
    int b = 1; // 发当前金币数量的剩余天数

    for(int i = 1; i <= k; i ++) {
        sum += a;
        b --;
        if(b == 0) { //发当前金币数量的天数发完了，该发下一个了
            a ++;
            b = a;
        }
    }
    cout << sum << endl;

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