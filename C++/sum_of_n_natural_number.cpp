#include<iostream>
#include<chrono>
using namespace std;
#define ull long

int main(){
    ull i,sum=0, n;
    cout<<"Enter a Number:";
    cin>>n;
    auto start = chrono::high_resolution_clock::now();
    for (i=1; i<=n;i++){
        sum+=i;
    }
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start).count();
    cout<<"Sum of "<<n<<"natural number is:"<<sum<<endl;
    cout<<"Execution time is:"<<duration<<" Milliseconds"<<endl;
    return 0;
}