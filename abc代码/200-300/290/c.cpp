#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;
const int N=3e5+10;
unordered_map<int,bool> st;
int main()
{
    int n,m;
    cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        st[x]=true;
    }

    for(int i=0;i<m;i++)
    {
        if(!st[i]){
            cout<<i<<endl;
            return 0;
        }
    }

    cout<<m<<endl;


}