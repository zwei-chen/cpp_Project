# C++基础与深度解析 Project1
下面主要对本Project的实现做简单介绍  
整个Project由三个文件组成，内含一个类和一个结构体
### 结构体Problem
结构体定义如下：
```c++
struct Problem{
    //! problem
    int first_num;
    int sencond_num;
    int method;         // 0=+;1=-;2=*;3=*/

    //! result
    double true_result;
    double user_result;
    bool true_or_false;
    //! time
    double times;
};
```  
主要包含每一个问题的变量，依次为  
first_num 计算处理第一项  
sencond_num 计算处理第二项  
method  计算方法
true_result  题目正确的答案  
user_result  用户输入的答案  
true_or_false  用户输入的答案是否正确  
times  用户计算该题时所需时间

### 类AddSubExercise
由于本类包含内容较多，故在此只做简单介绍，具体实现见代码及相关注释
1. AddSubExercise();  
类的构造函数，输出相关信息，并让用户设定题目数量和难度  
本Project支持的题目数量为100题以内，支持的难度有三种模式  
a. 难度1星：100以内的加减法
b. 难度2星：1000以内的加减法
c. 难度3星：两项为100以内的加减乘除法
2. Run();  
Project功能的接口，依次进行问题建立、向用户提问、结果显示
3. ProblemCreat();  
根据用户的问题设置和创建问题，问题生成使用rand()函数，并确定边界，
同时计算相应的正确答案。
4. StartAskQuestion();  
向用户提问，记录用户的答案和时间，并判断用户的答案是否正确  
5. ResultShow();  
统计用户的用时，输出平均时间和最短时间；  
同时输出用户的答题情况，并对用户答错的题目解答

### 执行示例
本示例使用10道题，难度3星，前5题答对，后5题答错
```
这是一个加减乘除法练习程序，能够生成加减乘除法题目
首先，请设定题目的数量及难度
现在请您设定题目的数量，目前程序只支持100以内的题目数量，输入数量后，并按回车
10
您设定的题目数量为:10
现在请您设定题目的难度
难度1星：100以内的加减法，如果选择此难度，请输入1，并按回车
难度2星：1000以内的加减法，如果选择此难度，请输入2，并按回车
难度3星：两项为100以内的加减乘除法，如果选择此难度，请输入3，并按回车
3
您设定的题目难度为:难度3星
题目数量和难度设定完毕，请进行答题
32/38= ?
输入答案请保留两位小数
0.84
86*13= ?
1118
89-2= ?
87
54*96= ?
5184
48+22= ?
70
8/42= ?
输入答案请保留两位小数
1
68*63= ?
1
69*46= ?
1
65*60= ?
1
53-11= ?
1
答题已经结束
您答题的平均用时为2.7737s
您答题的最短用时为0.451992s
您答对的题目数量为：5
您答错的题目数量为：5
您答错的题目信息如下
8/42= ?
正确的答案是 0.19
您的答案是 1
按任意键看下一个错误的题目


68*63= ?
正确的答案是 4284
您的答案是 1
按任意键看下一个错误的题目


69*46= ?
正确的答案是 3174
您的答案是 1
按任意键看下一个错误的题目


65*60= ?
正确的答案是 3900
您的答案是 1
按任意键看下一个错误的题目


53-11= ?
正确的答案是 42
您的答案是 1
```
