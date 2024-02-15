#include<stdio.h>
int tower(int n,char src, char des, char aux){
    static int count = 0;
    if(n==1){
        printf("Step %d : Move disk 1 from source %c to %c\n",++count,src,des);
        return count;
    }
    tower(n-1,src,aux,des);
    printf("Step %d : Move disk %d from source %c to %c\n",++count,n,src,des);
    tower(n-1,aux,des,src);
    return count;
}

int main(){
    int n;
    printf("Enter the number of Discs: ");
    scanf("%d",&n);
    printf("\nTotal moves required : %d",tower(n,'A','B','C'));
    return 0;
}