#include <iostream>
#include <iomanip>
using namespace std;

//hàm nhập mảng
void inarr(int *arr,int n,int *p){
    for(int i=0;i<n;i++){
        cout<<"arr"<<i<<"=";
        cin>>*(arr+i);
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
    cout<<"mang sau khi sap xep thu tu:  ";
    for(int i=0;i<n;i++){
        cout<<*(arr+i)<<setw(4);
    }
    cout<<endl;
}

//hàm tìm kiếm nhị phân
int binsearch(int *arr,int n,int *p){
    int left=0,right=n-1;
    int mid,k;
    while(1){
        mid=(left+right)/2;
        cout<<"x="<<*(arr+mid)<<endl;
        cout<<"k=";//k=-1(<) ; k=0(=) ; k=1(>)
        cin>>k;
        if(k==-1){
            right=mid-1;
        }
        else if(k==1){
            left=mid+1;
        }
        else if(k==0){
            cout<<"position of "<< *(arr+mid)<<" is "<<*(p+mid);
            return 0;
        }
    }
}

int main() {
    int n;
    cout<<"number of elements in array:";
    cin>>n;
    int *arr=new int[n];
    int *p=new int[n];
    inarr(arr,n,p);
    sort(arr,n,p);
    outarr(arr,n,p);
    binsearch(arr,n,p);
    delete[] arr;
    delete[] p;
}