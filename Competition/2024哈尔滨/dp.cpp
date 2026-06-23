#include<bits/stdc++.h>
#include<unistd.h>

using namespace std;

int main() {
    system("g++ data.cpp -o data");
    system("g++ std.cpp -o std");
    system("g++ test.cpp -o test");

    for(int i = 1;; i ++) {
        printf("id : %d: \n",i);
        system("data");
        printf("data ok");
        system("std < data.in > std.out");
        system("test < data.in > test.out");
        printf("ok");
        if(system("fc std.out test.out")) {
            printf("wa\n");
            return 0;
        }
        else printf("ac\n");
        sleep(1);
    }

}