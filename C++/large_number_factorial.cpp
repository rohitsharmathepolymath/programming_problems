#include<iostream>
#include<chrono>
using namespace std;
#define MAX 100000
int multiply(int x, int res[],int res_size );

int main(){
    int res[MAX], res_size,n;
    cout<<"Enter the Number:";
    cin>>n;
    res[0]=1;
    res_size=1;
    auto start = chrono::high_resolution_clock::now();
    for(int x=2;x<=n;x++){
        res_size=multiply(x,res,res_size);
    }
    auto stop =chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start).count();
    for(int i=res_size-1;i>=0;i--){
        cout<<res[i];
    }
    cout<<endl;
    cout << "Execution time: " << duration << " milliseconds" << endl;
    cout << "Number of digit:" <<res_size;
}
int multiply(int x, int res[],int res_size ){
    int carry=0;
    for(int i=0;i<res_size;i++){
        int prod=res[i] * x + carry;
        res[i]=prod%10;
        carry=prod/10;
    }
    while(carry!=0){
        res[res_size]=carry%10;
        carry=carry/10;
        res_size++;
    }
    return res_size;
}