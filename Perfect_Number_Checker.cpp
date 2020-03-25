#include<cstdio>
#include<cmath>
using namespace std;
int main(){
    //just learned scanf & printf in c++
    printf("Note that this program is terminated by EOF only\n");
    while(true){
        printf("Enter a number: ");
        int num;
        scanf("%d",&num);
        if(sqrt(num)==(int)sqrt(num)){
            printf("%d is perfect!\n",num);
        }
        else{
            printf("%d isn't perfect!\n",num);
        }
    }
    return 0;
}
