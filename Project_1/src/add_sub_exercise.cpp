//
// Created by Zhiwei Chen on 2021/10/8.
//

#include "add_sub_exercise.h"
#include "iostream"

AddSubExercise::AddSubExercise()
{
    //! 1. Message info
    std::cout<<"这是一个加减乘除法练习程序，能够生成加减乘除法题目"<<std::endl;
    std::cout<<"首先，请设定题目的数量及难度"<<std::endl;

    //! 设定题目数量
    std::cout<<"现在请您设定题目的数量，目前程序只支持100以内的题目数量，输入数量后，并按回车"<<std::endl;
    problem_num=CheckInt();
    while(problem_num>100||problem_num<=0){
        std::cout<<"您设定题目的数量有误，目前程序只支持100以内的题目数量，请重新输入数量后，并按回车"<<std::endl;
        problem_num=CheckInt();
    }
    std::cout<<"您设定的题目数量为:"<<problem_num<<std::endl;

    //! 设定题目难度
    std::cout<<"现在请您设定题目的难度"<<std::endl;
    std::cout<<"难度1星：100以内的加减法，如果选择此难度，请输入1，并按回车"<<std::endl;
    std::cout<<"难度2星：1000以内的加减法，如果选择此难度，请输入2，并按回车"<<std::endl;
    std::cout<<"难度3星：两项为100以内的加减乘除法，如果选择此难度，请输入3，并按回车"<<std::endl;
    int t_problem_star=0;
    t_problem_star=CheckInt();
    while(t_problem_star>3||t_problem_star<=0){
        std::cout<<"您设定题目的难度有误，目前程序只支持1~3星难度 ，请重新输入难度后，并按回车"<<std::endl;
        t_problem_star=CheckInt();
    }
    switch(t_problem_star){
        case 1:
            problem_difficulty=star_1;
            problem_method_num=2;
            problem_edge=100;
            break;
        case 2:
            problem_difficulty=star_2;
            problem_method_num=2;
            problem_edge=1000;
            break;
        case 3:
            problem_difficulty=star_3;
            problem_method_num=4;
            problem_edge=100;
            break;

    }
    std::cout<<"您设定的题目难度为:难度"<<problem_difficulty<<"星"<<std::endl;
    show_true=0;
    show_false=0;
}

bool AddSubExercise::Run()
{
    //! Creat Problem
    if(!ProblemCreat())
        return false;

    //! Start ask Question
    if(!StartAskQuestion())
        return false;

    if(!ResultShow())
        return false;

    return true;

}

bool AddSubExercise::ProblemCreat()
{
    //! reset Promblem
    //problem_.resize(problem_num);

    if(problem_num==0)
        return false;

    //! Creat Problem
    Problem t_problem;
    srand((unsigned)time(NULL));
    for(int i=0;i<problem_num;i++){

        do{
            t_problem.first_num=rand()%(problem_edge-1)+1;
            t_problem.sencond_num=rand()%(problem_edge-1)+1;
            t_problem.method=rand()%problem_method_num;
        }
        while(!EdgeDetection(t_problem));
        problem_.push_back(t_problem);
    }

    return true;
}

bool AddSubExercise::StartAskQuestion()
{
    if(problem_.size()!=problem_num){
        std::cout<<"题目数量生成错误"<<std::endl;
        return false;
    }
    std::chrono::steady_clock::time_point start_time, finish_time;
    std::cout<<"题目数量和难度设定完毕，请进行答题"<<std::endl;
    for(int i=0;i<problem_num;i++){
        start_time=std::chrono::steady_clock::now();
        switch (problem_[i].method)
        {
            case 0:
                std::cout<<problem_[i].first_num<<"+"<<problem_[i].sencond_num<<"= ?"<<std::endl;
                problem_[i].user_result=CheckDouble();
                break;
            case 1:
                std::cout<<problem_[i].first_num<<"-"<<problem_[i].sencond_num<<"= ?"<<std::endl;
                problem_[i].user_result=CheckDouble();
                break;
            case 2:
                std::cout<<problem_[i].first_num<<"*"<<problem_[i].sencond_num<<"= ?"<<std::endl;
                problem_[i].user_result=CheckDouble();
                break;
            case 3:
                std::cout<<problem_[i].first_num<<"/"<<problem_[i].sencond_num<<"= ?"<<std::endl;
                std::cout<<"输入答案请保留两位小数"<<std::endl;
                problem_[i].user_result=CheckDouble();
                break;
        }
        finish_time=std::chrono::steady_clock::now();
        problem_[i].true_or_false=JudgeAnswer(problem_[i]);
        problem_[i].times = std::chrono::duration_cast<std::chrono::duration<double> >(finish_time - start_time).count();
    }

    return true;
}

bool AddSubExercise::EdgeDetection(Problem &_problem)
{
    _problem.true_result= UseMethod(_problem.first_num,_problem.sencond_num,_problem.method);
    //std::cout<<_problem.true_result<<std::endl;
    switch(problem_difficulty)
    {
        case star_1:
            if(_problem.true_result<0)
                return false;
            else if(_problem.true_result>100)
                return false;
            else
                return true;
        case star_2:
            if(_problem.true_result<0)
                return false;
            if(_problem.true_result>1000)
                return false;
            else
                return true;
        case star_3:
            return true;
    }
}

double AddSubExercise::UseMethod(int a, int b, int method)
{
    switch (method)
    {
        case 0:
            return a+b;
        case 1:
            return a-b;
        case 2:
            return a*b;
        case 3:
            int tmp=((double)a/(double)b+0.005)*100;
            return (double)tmp/100.0;
    }
    return 0;
}

bool AddSubExercise::JudgeAnswer(Problem &_problem)
{
    if(_problem.user_result==_problem.true_result)
    {
        show_true++;
        return true;
    }

    else{
        show_false++;
        all_true= false;
        return false;
    }


}

bool AddSubExercise::ResultShow()
{
    std::cin.get();
    int false_hit=0;

    //! 统计用时
    double sum_times=0,min_times=(std::numeric_limits<double>::max)();
    for(int i=0;i<problem_num;i++){
        sum_times+=problem_[i].times;
        if(problem_[i].times<min_times)
            min_times=problem_[i].times;
    }

    std::cout<<"答题已经结束"<<std::endl;
    std::cout<<"您答题的平均用时为"<<sum_times/problem_num<<"s"<<std::endl;
    std::cout<<"您答题的最短用时为"<<min_times<<"s"<<std::endl;
    std::cout<<"您答对的题目数量为："<<show_true<<std::endl;
    if(!all_true){
        std::cout<<"您答错的题目数量为："<<show_false<<std::endl;
        std::cout<<"您答错的题目信息如下"<<std::endl;
        for(int i=0;i<problem_num;i++){
            if(problem_[i].true_or_false== true)
                continue;
            switch (problem_[i].method)
            {
                case 0:
                    std::cout<<problem_[i].first_num<<"+"<<problem_[i].sencond_num<<"= ?"<<std::endl;
                    std::cout<<"正确的答案是 "<<problem_[i].true_result<<std::endl;
                    std::cout<<"您的答案是 "<<problem_[i].user_result<<std::endl;
                    false_hit++;
                    if(false_hit!=show_false)
                    {
                        std::cout<<"按任意键看下一个错误的题目"<<std::endl<<std::endl;
                        std::cin.get();
                    }
                    break;
                case 1:
                    std::cout<<problem_[i].first_num<<"-"<<problem_[i].sencond_num<<"= ?"<<std::endl;
                    std::cout<<"正确的答案是 "<<problem_[i].true_result<<std::endl;
                    std::cout<<"您的答案是 "<<problem_[i].user_result<<std::endl;
                    false_hit++;
                    if(false_hit!=show_false)
                    {
                        std::cout<<"按任意键看下一个错误的题目"<<std::endl<<std::endl;
                        std::cin.get();
                    }
                    break;
                case 2:
                    std::cout<<problem_[i].first_num<<"*"<<problem_[i].sencond_num<<"= ?"<<std::endl;
                    std::cout<<"正确的答案是 "<<problem_[i].true_result<<std::endl;
                    std::cout<<"您的答案是 "<<problem_[i].user_result<<std::endl;
                    false_hit++;
                    if(false_hit!=show_false)
                    {
                        std::cout<<"按任意键看下一个错误的题目"<<std::endl<<std::endl;
                        std::cin.get();
                    }
                    break;
                case 3:
                    std::cout<<problem_[i].first_num<<"/"<<problem_[i].sencond_num<<"= ?"<<std::endl;
                    std::cout<<"正确的答案是 "<<problem_[i].true_result<<std::endl;
                    std::cout<<"您的答案是 "<<problem_[i].user_result<<std::endl;
                    false_hit++;
                    if(false_hit!=show_false)
                    {
                        std::cout<<"按任意键看下一个错误的题目"<<std::endl<<std::endl;
                        std::cin.get();
                    }
                    break;
            }
    }

    }
    return true;
}

int AddSubExercise::CheckInt()
{
    char tmp_ch;
    int tmp_int;
    while(1){
        if(scanf("%d",&tmp_int)==0)
        {
            printf("输入非数字，请重新输入\n");
            while ((tmp_ch = getchar()) != EOF && tmp_ch != '\n') ;
            continue;
        }
        break;
    }
    return tmp_int;
}

double AddSubExercise::CheckDouble()
{
    char tmp_ch;
    double tmp_double;
    while(1){
        if(scanf("%lf",&tmp_double)==0)
        {
            printf("输入非数字，请重新输入\n");
            while ((tmp_ch = getchar()) != EOF && tmp_ch != '\n') ;
            continue;
        }
        break;
    }
    return tmp_double;
}
