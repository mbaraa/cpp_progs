//this program takes your coordinates and a noted map then shows the coordinates 
#include <iostream>
#include <string.h>
using namespace std;
int main() {
    int x,y;
    int u=0,d=0,l=0,r=0;
    string dist;
    cin>>x>>y;
    cin>>dist;
    int strsize = dist.size();
    for(int i=0;i<strsize;i++){
        if(dist.at(i)=='U'){u++;}
        if(dist.at(i)=='D'){d++;}
        if(dist.at(i)=='L'){l++;}
        if(dist.at(i)=='R'){r++;}

    }
    x += r - l;
    y += u - d;
    cout << x << " " << y;
};//insteade of "return 0;" it returns zero to the system though

