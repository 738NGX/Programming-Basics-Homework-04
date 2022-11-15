#include<iostream>
#include<cstring>
#include<vector>
#include<string>
using namespace std;

void readWords(char row[],char words[][21],int *numberOfWords);
void countAndPrintWords(char words[][21]);

/**
 * @brief 从读入的几行文本中抽取每个单词，将其存储在二维数组words
 * 
 * @param row 输入行
 * @param words 单词库
 * @param numberOfWords 已存储单词数
 */
void readWords(char row[],char words[][21],int *numberOfWords){
    int number_of_words=*numberOfWords; //已存储单词数
    for(int j=0;j<strlen(row);j++){
        if(row[j]>='A'&&row[j]<='Z'){
                row[j]=row[j]-'A'+'a';  //大写转小写
        }
    }
    for(int j=0;j<strlen(row);j++){
        if((row[j]==' '&&words[number_of_words][0]!='\0')||(row[j]==' '&&number_of_words==0)){
            number_of_words++;          //完成单词录入
        }
        else{
            if((row[j]>='a'&&row[j]<='z')||row[j]=='\''){
                for(int k=0;k<21;k++){
                    if(words[number_of_words][k]=='\0'){
                        words[number_of_words][k]=row[j];
                        break;          //字母录入
                    }
                }
            }
        }
    }
    *numberOfWords=number_of_words;
}

/**
 * @brief 依次计算 words 数组中每个单词出现的次数，并按照每行显示五个单词的格式，依次打印出每个单词出现的次数
 * 
 * @param words 单词库
 */
void countAndPrintWords(char words[][21]){
    vector<string> word_name;
    vector<int> word_times;
    //确定库一共存储了多少个单词
    int number_of_words=0;              //库已存储单词数
    for(int i=1;i<1001;i++){
        if(words[i][0]!=0)
            number_of_words++;
        else
            break;
    }
    //依次处理库中每一个单词
    for(int i=1;i<=number_of_words;i++){
        string temp_word;                   //临时存储单词
        for(int j=0;j<strlen(words[i]);j++){
            //将单词存入临时存储
            temp_word.push_back(words[i][j]);
        }
        if(word_name.size()==0){            //首位空占格
            word_name.push_back("0");
            word_times.push_back(0);
        }
        bool new_word=true;                 //判断是否为新单词
        for(int j=0;j<word_name.size();j++){
            if(word_name[j].compare(temp_word)==0){
                word_times[j]++;            //计数增加
                new_word=false;
                break;
            } 
        }
        if(new_word){
            word_name.push_back(temp_word); //录入新单词
            word_times.push_back(1);
        }
    }
    int flag=0;
    for(int i=1;i<word_name.size();i++){
        cout<<word_name[i]<<'\t'<<word_times[i]<<'\t';
        flag++;
        if(flag==5){
            flag=0;
            cout<<'\n';
        }
    }
    cout<<'\n';
}

int main(){
    //变量定义&声明
    char row[81];                       //行存储
    char words[1001][21];               //单词库
    int number_of_rows=0;               //目标输入行数
    int number_of_words=0;              //库已存储单词数
    //字符串初始化
    memset(row,0,sizeof(row));
    memset(words,0,sizeof(words));
    //输入
    cout<<"请输入你想要的行数:"<<endl;
    cin>>number_of_rows;
    cout<<"请输入:"<<endl;
    for(int i=0;i<=number_of_rows;i++){
        memset(row,0,sizeof(row));      //重置行
        cin.getline(row,81,'\n');       //输入行
        readWords(row,words,&number_of_words);        
        number_of_words++;              //完成行录入
    }
    countAndPrintWords(words);
    return 0;
}