#include<iostream>
using namespace std;
#define MAX 1000
int main(){
    int a[MAX];
    int n, flag=0;
    
    cout<<"Enter the length of the binary number:";
    cin>>n;
    cout<<"Enter the binary number giving space between them:";
    for (int i=0; i<n;i++){
        cin>>a[i];
        if(a[i]>1 || a[i]<0){
            flag=1;
        }
    }
    if(flag==0){
        cout<<"Its a binary number"<<endl;
    }else{
        cout<<"Its not a binary number"<<endl;
    }
    return 0;
}