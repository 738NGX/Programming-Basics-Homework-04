#include<iostream>
#include<cstring>
using namespace std;

void MultiplePluralForm(char target[],char source[]);
void RegularPluralForm(char word[]);
bool isVowel(char ch);
char lastLetter(char word[]);
char lastLetter(char word[],int n);

void MultiplePluralForm(char target[],char source[]){
    char temp[81];                          //临时单词
    memset(temp,0,sizeof(temp));            //初始化
    for(int i=0;i<strlen(source);i++){
        if(source[i]==' '){                 //空格断词
            RegularPluralForm(temp);        
            strcat(temp," ");
            strcat(target,temp);
            memset(temp,0,sizeof(temp));    //重置临时单词
        }
        else{
            for(int j=0;j<81;j++){
                if(temp[j]=='\0'){
                    temp[j]=source[i];      //字母存入临时单词
                    break;
                }
            }
        }        
    }
    RegularPluralForm(temp);        
    strcat(temp," ");
    strcat(target,temp);
    memset(temp,0,sizeof(temp));
}

/**
 * @brief 把一个单词转换为复数形式
 * 
 * @param word 待转换单词
 */
void RegularPluralForm(char word[]){
    int action_type;                                //需要对字符串执行的操作
    //Step1 判断情况
    switch(lastLetter(word)){
        case 's': action_type=1; break;             //-s
        case 'x': action_type=1; break;             //-x
        case 'z':                                   //-z
            if(lastLetter(word,2)=='i'){
                switch(lastLetter(word,3)){
                    case 'u': if(lastLetter(word,4)=='q') action_type=5; break; //quiz
                    case 'w': if(lastLetter(word,4)=='s') action_type=5; break; //swiz
                    case 'h': if(lastLetter(word,4)=='w') action_type=5; break; //whiz
                    default : action_type=1;
                }
            }
            else{
                action_type=1;
            }
            break;
        case 'h': 
            switch(lastLetter(word,2)){
                case 'c': action_type=1; break;     //-ch
                case 's': action_type=1; break;     //-sh
                default : action_type=0;
            }
            break;
        case 'y':
            if(!isVowel(lastLetter(word,2))){
                action_type=2;                      //-y
            }
            else{
                action_type=0;
            }
            break;
        case 'f': action_type=3; break;             //-f
        case 'e':
            if(lastLetter(word,2)=='f'){
                action_type=4;                      //-fe
            }
            else{
                action_type=0;
            }
            break;
        default : action_type=0;
    }
    //Step2 执行操作
    switch(action_type){
        case 0: strcat(word,"s"); break;            //+s
        case 1: strcat(word,"es"); break;           //+es
        case 2:
            word[strlen(word)-1]='i';               //-y+ies
            strcat(word,"es");
            break;
        case 3:
            word[strlen(word)-1]='v';               //-f+ves
            strcat(word,"es");
            break;
        case 4:
            word[strlen(word)-1]='e';               //-fe+ves
            word[strlen(word)-2]='v';
            strcat(word,"s");
            break;
        case 5: strcat(word,"zes");                 //+zes
    }
}

/**
 * @brief 判断一个字母是否为元音字母
 * 
 * @param ch 一个字母
 * @return true 
 * @return false 
 */
bool isVowel(char ch){
    if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'){
        return 1;
    }
    else{
        return 0;
    }
}

/**
 * @brief 返回单词的最后一个字母
 * 
 * @param word 一个单词
 * @return 最后一个字母 
 */
char lastLetter(char word[]){
    return word[strlen(word)-1];
}

/**
 * @brief 返回单词的倒数第n个字母
 * 
 * @param word 一个单词
 * @param n 
 * @return char 
 */
char lastLetter(char word[],int n){
    return word[strlen(word)-n];
}

int main(){
    char str1[201];
    char str2[400];
    cin.getline(str1, 201,'\n');
    memset(str2,0,sizeof(str2));
    MultiplePluralForm(str2, str1);
    cout << str2 <<endl;
    return 0;
}