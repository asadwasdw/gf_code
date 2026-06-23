#include<bits/stdc++.h>

void solve() {

    std::string s; std::cin >> s;
    int n = s.size();
    
    std::vector<std::array<int, 2>> ans;
    for (int i = n - 1, last = -1; i >= 0; i--) {
        if (s[i] == '>' && last != -1) {
            if (last + 3 >= n) {
                std::cout << "No\n";
                return;
            }
            ans.push_back({i, last + 3});
            last = -1;
        } else if (s[i] == '-' && last == -1) last = i;
    }
    if (s[0] != '>' || ans.empty()) {
        std::cout << "No\n";
        return;
    }
    std::set<int> st;
    for (auto [l, r] : ans) st.insert(l);
    
    for (int i = ans[0][0]; i + 4 < n; i++) {
        if (st.count(i)) continue;
        ans.push_back({i, i + 4});
    }
    for (int i = ans[0][0];  i >= 0; i--) {
        if (st.count(i)) continue;
        ans.push_back({i, i + 4});
    }
    std::reverse(ans.begin(), ans.end());
    std::cout << "Yes " << ans.size() << "\n";
    for (auto [l, r] : ans ) {
        std::cout << l + 1 << ' ' << r - l + 1 << "\n";
    }
}


signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0),std::cout.tie(0);
    int t;t=1;
    std::cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}