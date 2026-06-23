#include<iostream>
#include<algorithm>


using namespace std;

char T[20];

int main()
{

    int n;cin>>n;

    for(int i=0;i<10;i++)
    {
        T[i]=(char)(i+'0');
    }
    T[10]='A';
    T[11]='B';
    T[12]='C';
    T[13]='D';
    T[14]='E';
    T[15]='F';

    int t1=n%16;
    int t2=n/16;

    cout<<T[t2];
    cout<<T[t1];
}