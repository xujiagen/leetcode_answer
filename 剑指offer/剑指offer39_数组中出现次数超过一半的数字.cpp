/*
数组中出现次数超过一般的数字

判断一个数组的数组里面输入的有没有一个数字出现的次数超过数组大小的一半，如果有，输出出来
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
class Solution
{
  public:
    int MoreThanHalfNum_Solution(vector<int> numbers)
    {
        qsort(numbers.begin(),numbers.end());
        print(numbers);
        int time=0;
        for(int i=0;i<numbers.size();i++)
        {
            //std::cout<<"number:"<<numbers.size()>1;
            if(numbers[i]==numbers[numbers.size()>>1])
                time++;
        }
        if(time>numbers.size()>>1)
            return numbers[numbers.size()>>1];
        else
            return false;
    }

    void qsort(std::vector<int>::iterator left,std::vector<int>::iterator right)
    {
        if(left>=right)
            return;
        std::vector<int>::iterator mid=left;
        mid=partition(left+1,right,bind2nd(less<int>(),*mid));
        iter_swap(mid-1,left);
        qsort(left,mid-1);
        qsort(mid,right);
    }

    void print(std::vector<int> vec_int)
    {
        for(std::vector<int>::iterator iter=vec_int.begin();iter!=vec_int.end();iter++)
        {
            std::cout<<*iter<<" ";
        }
        std::cout<<std::endl;
    }

    void print_iter(std::vector<int>::iterator left,std::vector<int>::iterator right)
    {
        for(auto iter=left;iter!=right;iter++)
            std::cout<<*iter<<" ";
        std::cout<<std::endl;
    }
};



//less<int>()需要输入的参数是两个，第二个参数被绑定了，第一个参数是在循环中的数，输入的数是不是小于第二个数

int main(int argc, char const *argv[])
{
    int a[] = {1,2,3,2,2,2,5,4,2};
    std::vector<int> int_vec(a,a+sizeof(a)/sizeof(int));
    Solution a1;
    std::cout<<a1.MoreThanHalfNum_Solution(int_vec)<<std::endl;


    return 0;
}


/*
class Solution
{
  public:
    int MoreThanHalfNum_Solution(vector<int> numbers)
    {
        
    }
    void qsort(std::vector<int>::iterator front,std::vector<int>::iterator end)
    {
        //数组里面指向指针的前部分和后部分两个指针
        if(front>end)
            return;
        std::vector<int>::iterator mid=left;
        mid=partition(left+1,right,bind2nd(less<int>(),*mid));
        iter_swap(left,mid-1);
        qsort(left,mid-1);
        qsort(mid,right);
    }
};
*/