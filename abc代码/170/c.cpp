#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;


unordered_map<int,bool>st;


int main()
{
    int a,n;cin>>a>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        st[x]=true;
    }
    int l,r;
    l=r=a;
    while(1)
    {
        if(!st[l]){
            cout<<l<<endl;
            break;
        }

        if(!st[r]){
            cout<<r<<endl;
            break;
        }
        l--;
        r++;
    }
}
