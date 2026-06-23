#include<iostream>
#include<algorithm>

using namespace std;

const int N=2e6+10,M=30;
int num[4*N];
int son[4*N][M];
int idx;
string s[N];

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
       
        cin>>s[i];
        int p=0;
        for(int j=0;j<s[i].size();j++)
        {
            int u=s[i][j]-'a';

            if(son[p][u]==0){
                son[p][u] = ++idx;
            }
            p=son[p][u];
            num[p]++;
        }
    }

    for(int i=1;i<=n;i++)
    {
        int cnt=0;
         int p=0;
        for(int j=0;j<s[i].size();j++)
        {
            int u=s[i][j]-'a';
            p=son[p][u];
            if(num[p]<=1)break;
            cnt++;
        }
        cout<<cnt<<endl;
    }

}
