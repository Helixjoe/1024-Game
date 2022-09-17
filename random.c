#include<stdio.h>
void display(int a[4][4],int n);
int main(){
    int arr[4][4],n=4,i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
        arr[i][j] = 0;
        }
    }
    display(arr,n);
    return 0;
}
void display(int arr[4][4],int n){
int i,j;
for(i=0;i<n;i++){
    for(j=0;j<n;j++){
        printf(" %d",arr[i][j]);
    }
    printf("\n");
}
}