#include<iostream>
#include<vector>
using namespace std;

void printInt(int n,int base);

void printInt(int n,int base){
    vector<int> result;
    do{
        result.push_back(n%base);
        n/=base;
    }while(n!=0);   //倒序进制转换，再逆向输出
    for(int j=1;j<=result.size();j++){
        switch(result[result.size()-j]){
            case 10: cout<<"A"; break;
            case 11: cout<<"B"; break;
            case 12: cout<<"C"; break;
            case 13: cout<<"D"; break;
            case 14: cout<<"E"; break;
            case 15: cout<<"F"; break;
            default: cout<<result[result.size()-j];
        }
    }
    cout<<"\n";
}

int main(){
    int x;
    cin>>x;
    printInt(x,2);
    printInt(x,8);
    printInt(x,16);
    return 0;
}