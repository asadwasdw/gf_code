#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

map<string,int>st;

int main()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
        string a;
        cin>>a;
        st[a]++;
    }

    string an;
    int ans=0;

    for(auto t:st)
    {
        if(t.second>ans){
            ans=t.second;
            an=t.first;
        }
    }

    cout<<an;


}