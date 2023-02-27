#include<stdio.h>
#include<stdlib.h>

void gin(int *a,int *b,int na,int nb){
    printf("\narr a:\n");
    for(int i=0;i<na;i++){
        printf("a%d=",i);
        scanf("%d",a+i);
    }
    printf("\narr b:\n");
    for(int i=0;i<nb;i++){
        printf("b%d=",i);
        scanf("%d",b+i);
    }
}

void gout(int *a,int *b,int na, int nb){
    printf("arr a:\n");
    for(int i=0;i<na;i++){
        printf("a%d=%d\t",i,*(a+i));
    }
    printf("\narr b:\n");
    for(int i=0;i<nb;i++){
        printf("b%d=%d\t",i,*(b+i));
    }
}

void mix(int *a,int *b,int na,int nb){
    na+=nb;
    realloc(a,na);
    int j=0;
    for(int i=na-nb;i<na;i++){
        *(a+i)=*(b+j);
        j++;
    }
    for(int i=0;i<na;i++){
        for(int j=i+1;j<na;j++){
            if(*(a+i)>*(a+j)){
                *(a+i)=*(a+j)+*(a+i);
                *(a+j)=*(a+i)-*(a+j);
                *(a+i)=*(a+i)-*(a+j);
            }
        }
    }
    printf("result:\n");
    for(int i=0;i<na;i++){
        printf("arr%d=%d  \t",i,*(a+i));
    }
}

int main(){
    int na,nb;
    printf("amount of array a:");
    scanf("%d",&na);
    int *a=(int*)malloc(na*sizeof(int));
    printf("amount of array b:");
    scanf("%d",&nb);
    int *b=(int*)malloc(nb*sizeof(int));
    printf("\n----in----\n");
    gin(a,b,na,nb);
    printf("\n----out----\n");
    gout(a,b,na,nb);
    printf("\n----mix----\n");
    mix(a,b,na,nb);
    free(a);
    free(b);
}