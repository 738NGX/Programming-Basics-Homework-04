#include<iostream>
using namespace std;

int digitalSum(int n);
int digitalRoot(int n);

/**
 * @brief 求n的各数位之和
 * 
 * @param n 
 * @return int 
 */
int digitalSum(int n){
    if(n/10==0){
        return(n);
    }
    else{
        return(digitalSum(n/10)+digitalSum(n%10));
    }
}

/**
 * @brief 计算n的数字根
 * 
 * @param n 
 * @return int 
 */
int digitalRoot(int n){
    if(n/10==0){
        return(n);
    }
    else{
        return(digitalRoot(digitalSum(n)));
    }
}

int main(){
    int n;
    cin>>n;
    cout<<digitalRoot(n)<<endl;
    return 0;
}