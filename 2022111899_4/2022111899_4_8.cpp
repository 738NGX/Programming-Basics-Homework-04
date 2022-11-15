#include<iostream>
#include<cstring>
using namespace std;

bool isPalindrome(char str[]);
void cutHeadAndTail(char str[]);
void disCaps(char str[]);

/**
 * @brief 把一个字符串掐头去尾
 * 
 * @param str 字符串
 */
void cutHeadAndTail(char str[]){
    for(int i=0;i<=strlen(str)-1;i++){
        str[i]=str[i+1];
    }
    str[strlen(str)-1]='\0';
}

/**
 * @brief 把字符串中的大写字母换成小写
 * 
 * @param str 字符串
 */
void disCaps(char str[]){
    for(int i=0;i<strlen(str);i++){
        if(str[i]>='A'&&str[i]<='Z')
            str[i]=str[i]-'A'+'a';
    }
}

/**
 * @brief 判断字符串是否回文
 * 
 * @param str 字符串
 * @return true 
 * @return false 
 */
bool isPalindrome(char str[]){
    if(strlen(str)<=1){
        return true;
    }
    else{
        if(str[0]==str[strlen(str)-1]){
            cutHeadAndTail(str);
            isPalindrome(str);
        }
        else{
            return false;
        }
    }
}

int main()
{ 
    char str[81];
    cout<<"Please input a string:\n";
    cin.getline(str,80,'\n');
    cout<<str;
    disCaps(str);
    if(isPalindrome(str))
        cout<<" is a palinedrome.\n";
    else
        cout<<" is not a palinedrome.\n";
    return 0;
}