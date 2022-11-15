#include<iostream>
#include<cstring>
using namespace std;

void replaceAll(char str[],char c1,char c2);

/**
 * @brief 将 str 字符串中出现的每一个字符 c2 替换为字符 c1
 * 
 * @param str 需要替换的字符串
 * @param c1 替换后的字符符变量或是字符常量
 * @param c2 待替换的字符符变量或是字符常量
 */
void replaceAll(char str[],char c1,char c2){
    for(int i=0;i<strlen(str);i++){
        if(str[i]==c2)
            str[i]=c1;  
    }
}

int main(){ 
    char s1[81]="nannies";
    char c1,c2;
    replaceAll(s1,'d','n');
    cout<<s1<<endl;
    cout<<"请输入字符串:";
    cin.getline(s1,80,'\n');
    cout<<"请输入待替换的字符:";
    cin>>c2;
    cout<<"请输入替换后的字符:";
    cin>>c1;
    replaceAll(s1,c1,c2);
    cout<<s1<<endl;
    return 0;
}