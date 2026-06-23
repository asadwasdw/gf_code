#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>adj(N);
int ans = 100;
int js(int l, int r) {
    if(l >= ans) l++;
    if(r >= ans) r++;
    return l * r;
}

int ask(int l, int r) {
    cout << "? " << l << " " << r << endl;
   return js(l, r);
    int x; cin >> x;
    return x;
}


void solve()
{
	ans = rand()%1000 + 1;
    int l = 1 , r = 1000;
    int cnt = 0;
    while(l + 1 < r) {
    	cnt ++;
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;
        if(l == mid1 && r == mid2) {
        	mid1 = mid2 = l + 1;
		}
        int mj = ask(mid1, mid2);
        if(mj <= mid1 * mid2) {
            l = mid2;
        }
        else if(mj <= mid1 * (mid2 + 1)) {
            l = mid1;
            r = mid2;
        }
        else {
            r = mid1;
        }
//        cout << l << " " << r << end; 
    }
//    assert(cnt <= 7);
//    assert(ans == l + 1);
   cout << cnt << " " <<ans << " ";
    cout << "! " << l + 1 << endl;

}


signed main()
{

    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}
