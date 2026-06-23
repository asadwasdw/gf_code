#include<iostream>
#include<algorithm>

using namespace std;
const int N=150;
bool st[N];

int main()
{
    int n,m;cin>>n>>m;
    string s;
    cin>>s;
    int gs=0;
    for(int i=0;i<s.size();i++)
    {
        char a=s[i];
        if(a=='o')
        {
            st[i]=true;
            gs++;
            if(gs==m)break;
        }
    }

    for(int i=0;i<s.size();i++)
    {
        if(st[i])cout<<"o";
        else cout<<"x";
    }
}