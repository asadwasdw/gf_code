#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

const int N=2e5+10;
string t, s;
int n, m;
int l[N];

void solve()
{
    cin >> t;
    string T=t;
    reverse(t.begin(),t.end());
    m = t.length();
    
    n = (m << 1) + 1;
    s.resize(n + 1);
    s[0] = '@', s[n] = '%', s[1] = '#';
    l[0]=0;
    for (int i = 1; i <= m; i ++) {
        l[i]=0;
        s[i << 1] = t[i - 1];
        s[i << 1 | 1] = '#';
    }

    int ans = 0, k = 0, r = 0;

    l[1] = 1;
    for (int i = 2; i <= n; i ++) {
        if (i < r) l[i] = min (r - i, l[(k << 1) - i]);
        else l[i] = 1;

        while (s[i - l[i]] == s[i + l[i]]) l[i] ++; // 暴力更新超过r的部分
        if (i + l[i] > r) k = i, r = i + l[i]; // 更新k,r
        if(i==l[i]&&m+1!=l[i])ans = max (ans, l[i] - 1); // 找到最长回文子串

       // cout<<l[i]<<" "<<i<<" "<<s[i]<<endl;
    }


  //  cout<<ans<<endl;
    map<char,int>st;
    st.clear();
    for(int i=0;i<=m-1-ans&&i<=28;i++)
    {
       // cout<<T[i]<<" ";
        if(st[T[i]]>=1||i>=28||ans==0){
             cout<<"NaN"<<endl;
            return ;
        }
        st[T[i]]++;
       
    }

   cout<<"HE"<<endl;

}



int main()
{
 int t;cin>>t;while(t--)
    solve();
}