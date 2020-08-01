#include<stdio.h>
#include<math.h>

int main(){
    //just learned scanf & printf 
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
