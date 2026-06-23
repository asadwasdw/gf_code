#include<iostream>
#include<algorithm>


using namespace std;


int main()
{
    int t;cin>>t;
    string s;
    cin>>s;
    int a=0,b=0;
    int win=-1;

    for(auto t:s)
    {
       // cout<<t<<endl;
        if(t=='A')
        {
            a++;
        }
        else {
            b++;
        }

        if(a!=b)
        {
            if(a>b){
                win=1;
            }
            else win=2;
            
        }

    }

    if(win==1)cout<<"A";
    else cout<<"T";


}