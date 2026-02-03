#include<iostream>
using namespace std;

class Fruits{
    public:
    string name;
    string taste;
    string color;
    Fruits(string name, string taste, string color){
        this->color= color;
        this->name= name;
        this->taste= taste;
    }
    void printDetails(){
        cout<<"Name: "<<name<<endl;
        cout<<"Taste: "<<taste<<endl;
        cout<<"Color: "<<color<<endl;
    }
};

int main(){
    Fruits f1("Mango","Sweet","Yellow");
    Fruits f2("Apple","Sweet","Red");
    f1.printDetails();
    f2.printDetails();
    cout<<f1.name<<endl;
    return 0;
}