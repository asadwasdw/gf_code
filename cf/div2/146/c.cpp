//https://codeforces.com/contest/1814/problem/C

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

typedef pair<int,int> PII;
const int N=2e5+10;
PII a[N];


bool cmp(PII a,PII b)
{
    return a.first>b.first;
}


void solve()
{
    int n;cin >> n;
    int s1,s2;
    cin>>s1>>s2;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].first;
        a[i].second=i;
    }

    sort(a+1,a+n+1,cmp);

   // for(int i=1;i<=n;i++)cout<<a[i].second<<" "; cout<<endl;

    vector<int>ans1;
    vector<int>ans2;
    int t1=s1,t2=s2;

    for(int i=1;i<=n;i++)
    {
        if(t1==t2)
        {
            if(s1<=s2){
                ans1.push_back(a[i].second);
                t1+=s1;
            }
            else {
                ans2.push_back(a[i].second);
                t2+=s2;
            }
        }
        else if(t1<t2){
             ans1.push_back(a[i].second);
            t1+=s1;
        }
        else {
             ans2.push_back(a[i].second);
                t2+=s2;
        }
    }

    cout<<ans1.size()<<" ";
    for(auto t:ans1)cout<<t<<" ";
    cout<<endl;

    cout<<ans2.size()<<" ";
    for(auto t:ans2)cout<<t<<" ";
    cout<<endl;

}

int main()
{
   int t;cin>>t; while(t--)
    solve();
}