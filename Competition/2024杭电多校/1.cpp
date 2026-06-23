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


void solve()
{
    int n, m;
    cin >> n;
    if(n <= 5) {
        for(int i = 2; i <= n + 1; i ++) {
            cout << "1 " << i << endl;
        }
        return;
    }

    m = n % 3;
    n = n / 3 * 3;
    vector<PII> ans1, ans2;

    {
        int M = n / 3 + 3;
        ans1.push_back({1,M-1});
        ans1.push_back({1,M-2});
        ans1.push_back({1, M});
    
        for(int i = 2; i < M - 2; i ++) {
            ans1.push_back({1,i});
            ans1.push_back({i,M - 1});
            ans1.push_back({i,M - 2});
        }
        for(int i = 0; i < m; i ++) {
            ans1.push_back({1,++M});
        }

        for(auto &[u, v] : ans2){
            if(u > v) swap(u,v);
        }

        sort(ans1.begin(), ans1.end(),[&](PII a, PII b){
            if(a.first != b.first) return a.first < b.first;
            return a.second < b.second;
        }); 
    }


    {
        int M = n / 3 + 3;
        vector<PII> ans;
        ans2.push_back({1,2});
        ans2.push_back({1,3});
        ans2.push_back({1,M});
     

        for(int i = 4; i < M; i ++) {
            ans2.push_back({1,i});
            ans2.push_back({2,i});
            if(i != M - 1)ans2.push_back({3,i});
        }
        ans2.push_back({2,3});
        for(int i = 0; i < m; i ++) {
            ans2.push_back({1,++M});
        }

        for(auto &[u, v] : ans1){
            if(u > v) swap(u,v);
        }
        sort(ans2.begin(), ans2.end(),[&](PII a, PII b){
            if(a.first != b.first) return a.first < b.first;
            return a.second < b.second;
        }); 
    }
    int ky = 1;
    for(int i = 0; i < ans1.size() && ky; i ++) {
        if(ans1[i].first != ans2[i].first) {
            if(ans1[i].second > ans2[i].second) ky = 0;
            else break;
        }
        else if(ans1[i].second > ans2[i].second) ky = 0;
        else if(ans1[i].second < ans2[i].second) break;
    }


    if(ky)  for(auto [u, v] : ans1) cout << u << " " << v << endl;
    else for(auto [u, v] : ans2) cout << u << " " << v << endl;
    
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