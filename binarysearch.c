#include <stdio.h>
#include <stdlib.h>

//hàm nhập mảng
void inarr(int *arr,int n,int *p){
    for(int i=0;i<n;i++){
        printf("arr%d=",i);
        scanf("%d",arr+i);
    }
    for(int i=0;i<n;i++){
        *(p+i)=i;
    }
}

//sắp xếp thứ tự lại cho mảng
void sort(int *arr,int n,int *p){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(*(arr+i)>*(arr+j)){
                *(arr+i)=*(arr+i)+*(arr+j);
                *(arr+j)=*(arr+i)-*(arr+j);
                *(arr+i)=*(arr+i)-*(arr+j);
                *(p+i)=*(p+i)+*(p+j);
                *(p+j)=*(p+i)-*(p+j);
                *(p+i)=*(p+i)-*(p+j);
            }
        }
    }
}

void outarr(int *arr,int n,int *p){
    printf("mang sau khi sap xep thu tu:  ");
    for(int i=0;i<n;i++){
        printf("%4d",*(arr+i));
    }
    printf("\n");
}

//hàm tìm kiếm nhị phân
int binsearch(int *arr,int n,int *p){
    int left=0,right=n-1;
    int mid,k;
    while(1){
        mid=(left+right)/2;
        printf("x=%d\n",*(arr+mid));
        printf("k=");//k=-1(<) ; k=0(=) ; k=1(>)
        scanf("%d",&k);
        if(k==-1){
            right=mid-1;
        }
        else if(k==1){
            left=mid+1;
        }
        else if(k==0){
            printf("position of %d is %d", *(arr+mid),*(p+mid));
            return 0;
        }
    }
}

int main() {
    int n;
    printf("number of elements in array:");
    scanf("%d",&n);
    int *arr=(int*)malloc(n*sizeof(int));
    int *p=(int*)malloc(n*sizeof(int));
    inarr(arr,n,p);
    sort(arr,n,p);
    outarr(arr,n,p);
    binsearch(arr,n,p);
    free(arr);
    free(p);
}