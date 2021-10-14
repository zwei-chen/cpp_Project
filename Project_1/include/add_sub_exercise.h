//
// Created by Zhiwei Chen on 2021/10/8.
//

#ifndef PROJECT1_ADD_SUB_EXERCISE_H
#define PROJECT1_ADD_SUB_EXERCISE_H

#include "vector"
#include "cstdlib"
#include "time.h"
#include "limits"

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

class AddSubExercise{
public:
    enum Difficulty{
        star_1=1,
        star_2=2,
        star_3=3
    };

public:
    /**
     * @brief 构造函数，由用户输入题目数量和题目难度
     */
    AddSubExercise();

    /**
     * @brief 根据用户输入题目难度和题目数量，
     *        随机生成相应数量的题目
     * @param void
     * @return true if success false otherwise
     */
     bool Run();

private:
     /**
      * @brief 初始化题目数量、题目相关数据和加减乘除种类
      * @param void
      * @return true if success false otherwise
      */
     bool ProblemCreat();

     /**
      * @brief 开始进行提问的练习
      * @return true if success false otherwise
      */
     bool StartAskQuestion();

     /**
      * @brief 边界检测，看生成的题目是否满足在指定范围之内，同时确定正确答案
      * @param a 第一项
      * @param b 第二项
      * @param method 计算方法
      * @return 是否在边界之内
      */
     bool EdgeDetection(Problem &_problem);

     /**
      * @brief 根据不同的计算方式来进行计算
      * @param a 第一项
      * @param b 第二项
      * @param method 计算方法
      * @return 计算后的数值
      */
     double UseMethod(int a,int b,int method);

     /**
      * @brief 判断题目答案是否正确
      * @param _problem 题目
      * @return 正确为true，错误为false
      */
     bool JudgeAnswer(Problem &_problem);

     /**
      * @brief 用户答题情况显示
      * @return true if success false otherwise
      */
     bool ResultShow();

private:
    //! 相关参数
    int problem_num=0;
    Difficulty problem_difficulty;
    int problem_method_num=0;
    int problem_edge=0;
    int show_true=0;
    int show_false=0;
    bool all_true= true;

    //! 题目
    std::vector<Problem> problem_;

};

#endif //PROJECT1_ADD_SUB_EXERCISE_H
