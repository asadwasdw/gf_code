#include<iostream>
#include<algorithm>
#include<set>
#include<unordered_map>
using namespace std;

unordered_map<int,set<int>> edgs;

int main()
{
    int n;cin>>n;
    for(int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        edgs[a].insert(b);
        edgs[b].insert(a);
    }

    bool ky=false;

    for(int i=1;i<=n;i++){
        if(edgs[i].size()==n-1)ky=true;
    }
    if(ky)cout<<"Yes";
    else cout<<"No";
}