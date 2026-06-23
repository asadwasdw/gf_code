#include<iostream>
#include<algorithm>

using namespace std;


char s[100100];

int main()
{
    s[0]='0';
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        char c;
        cin>>c;
        s[i]=c;
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='1'){
            ans++;
        }
        else if(s[i-1]=='1'){
            ans++;
        }
        else if(i>1&&s[i-2]=='1'){
            ans++;
        }
    }

    cout<<ans<<endl;

}