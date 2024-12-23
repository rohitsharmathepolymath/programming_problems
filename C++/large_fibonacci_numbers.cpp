#include<iostream>
#include <chrono>
#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long

int main(){
    ull a=1,b=1,c;
    int n;
    cout<<"Enter n for nth fibonacci number:"<<endl;
    cin>>n;
    cout<<a<<endl;
    cout<<b<<endl;
    auto startTime = chrono::high_resolution_clock::now();
    for(int i=0;i<n-2;i++){
        c=a+b;
        a=b;
        b=c;
        cout<<c<<endl;
    }
    auto endTime = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();
    cout << "Execution time: " << duration << " milliseconds" << endl;
    cout << to_string(c).length() << endl;
    return 0;
}