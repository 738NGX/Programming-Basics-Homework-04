# 上海财经大学 信息管理与工程学院 程序设计基础课 第四次大作业
## 1. 改写字符串（知识点：字符串，数组作为函数参数）
试编写一个函数 void replaceAll(char str[],char c1,char c2) 将 str 字符串中出现的每一个字符 c2 替换为字符 c1。其中第一个参数 str 是需要替换的字符串，c1, c2 是有具体值的字符变量或是字符常量。如果 str 中不存在 c2 中的字符，则不作替换。   
譬如，执行以下代码：   
char str[20]={ "nannies"}；   
replaceAll(str, 'd','n');   
的结果是 str 中存储的是字符串"daddies"。   
## 2. 改写单词。
试编写如下函数void RegularPluralForm(char word[]);其中参数 word（在调用该函数时，在主调函数中对应的实参是字符串数组），该函数将遵循标准英语规则将 word 修改为复数形式。规则如下：（1）如果单词以 s, x, z, ch 或 sh 结尾，单词后加 es; (2)如果单词后以 y 结尾，并且前面是一个辅音，将 y 改为 ies; (3)如果单词以 f 或 fe 结尾，则把 f 或 fe 变成 v, 再加 es; (4)对于其他单词，后面加 s。    
## 3. 多个名词改写。
编写一个函数void MultiplePluralForm(target[], source[]);将 source[]字符串(长度不超过 200 个字符)中的单词依次转换为复数，放入字符串数组target[]中，要求调用第 7 题中的 void RegularPluralForm(char word[]);  
【样例输入】   
bus box peach car dish book class quiz dictionary family monkey boy knife leaf apple tool    
【样例输出】   
buses boxes peaches cars dishes books classes quizzes dictionaries families monkeys boys knives leaves apples tools     
## 4. 计算单词次数（知识点：字符串处理，数组，函数）
编写一个程序，读入几行文本，并打印一个表格。此表格按照单词在文本中出现的顺序，显示每个不同单词（不区分大小写）在文本中的出现次数。约定每个单词的
长度不超过 20 个字符，每行文本字符数不超过 80，输入文本中的单词个数不超过 1000 个。
提示及要求：
（1）可定义一个二维字符数组 char words[1001][21]，用于按照输入文本中单词出现的顺序依次存储每个单词。     
（2）编写一个函数 readWords()从读入的几行文本中抽取每个单词，将其存储在二维数组words中。    
（3）编写一个函数 countAndPrintWords()，依次计算 words 数组中每个单词出现的次数，并按照每行显示五个单词的格式，依次打印出每个单词出现的次数。    
（4）在 main 函数中，调用上述定义的函数。     
程序运行实例：   
【样例输入】   
To be or not to be : that is the question,   
Whether it’s nobler in the mind to suffer   
【样例输出】   
to 3 be 2 or 1 not 1 that 1  
is 1 the 2 question 1 whether 1 it’s 1  
nobler 1 in 1 mind 1 suffer 1   
## 5. 计算数字根（知识点：采用递归求解问题）
小明想吃糖果。小明的爸爸要求小明必须在规定时间内计算出任意整数的数字根，才能吃到糖果。一个整数的数字根（digital root）是指不断重复地将各位数字相加，直到结果只有一位数字为止。例如，1729 的数字根的计算步骤如下：    
步骤 1： 1+7+2+9 -> 19      
步骤 2： 1+9 -> 10      
步骤 3： 10 -> 1      
因此 1729 的数字根是 1。   
请你编写一个程序帮助小明计算任意正整数的数字根。    
要求：首先编写递归函数 int digitalRoot(int n) 该函数返回参数 n 的数字根，要求这个递归函数中不要使用任何循环。然后在主程序中调用这个递归函数。     
【输入】   
任意小于 2X109 的正整数   
【输出】   
 该正整数的数字根  
【样例输入】  
1729  
【样例输出】  
1   
## 6. 任意进制转换问题（知识点：函数，进制转换）
编程输入任意十进制数 N(N:-32767~32767)，请输出它对应的二进制、八进制、十六进制；（注意，当数值超过十之后，就用字母 A、B、C……来代替）比如十六进制数：A1F,代表它最低位是 F,也就是 15，第二位是 1，最高位是 A，也就是10，转换成 10 进制就是 10*16*16+1*16+15=2581。
【输入】  
一个数 N  
【输出】  
对应的二进制、八进制、十六进制；每个一行  
【样例输入】  
4  
【样例输出】  
100  
4  
4  
【提示】：首先编写一个函数 void printInt(int n, int base), 功能是输出 n 的 base 进制表示。然后在以下主程序中调用。
## 7. 函数模板
分别设计一个支持整型、实型、字符型的选择排序的函数模板 selectSort，以及一个打印整型、实型、字符型数组的函数模板 printArray，在主程序调用。   
## 8. 递归
请用递归编写一个函数 bool isPalindrome(char str[])，判断一个字符串是否是回文（palindrome）, 所谓回文，就是从左边读与从右边读完全一样的字符串，本题忽略大小写的不同，例如：Level 是一个回文，abGhgbA 也是一个回文。主程序首先要求用户输入任意字符串，然后调用你编写的函数，判断用户的输入是否是回文。  
