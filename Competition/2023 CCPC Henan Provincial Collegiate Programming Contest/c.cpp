#include <iostream>
using namespace std;


const int N=1000100;
int idx=0;
int cnt[N];
int son[N][5];

void cr(string s)
{
    int p=0;
    for(int i=0;i<s.size();i++)
    {
        int u=s[i]-'0';
        if(son[p][u]==0)
        {
            son[p][u]=++idx;
        }
        p=son[p][u];
    }
    
    cnt[p]++;
}


int main()
{
    string s;
    bool ky=true;
    while(cin>>s)
    {
        int last=idx;   
        cr(s);
        if(idx==last)ky=false;
    }

    if(ky)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    
}