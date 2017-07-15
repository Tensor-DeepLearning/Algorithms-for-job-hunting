/************************************************
  FileName    : CocktailSort.h           ;
  Description : 鸡尾酒排序                                ;
  Creator     : Chirl                           ;
  Contact     : ChirlChen@163.com               ;
  CreatedDate : 2017/07/15                      ;
              _                                 ;
             /  \         吉                    ;     
            /|oo \         祥                   ;    
           (_|  /_)       物                    ;   
             `@/  \   _    镇                   ;    
             |     \  \\  楼                    ;   
              \||   \  ))  !!                   ;    
              |||\ / \//                        ; 
            _//|| _\  /                         ;
    ______(_/(_|(____/_________                 ;
*************************************************/
#ifndef _COCKTAILSORT_H_
#define _COCKTAILSORT_H_

#include <vector>
#include <iostream>

using namespace std;

namespace Chirl
{
    /************************************************************************
     思      路： 鸡尾酒排序，也叫定向冒泡排序，是冒泡排序的一种改进。此算法;
                  与冒泡排序的不同处在于从低到高然后从高到低，而冒泡排序则仅;
                  从低到高去比较序列里的每个元素。他可以得到比冒泡排序稍微好;
                  一点的效能。;
     算法复杂度：
     ************************************************************************/
    class CCocktailSort
    {
    public:
        void CocktailSort(vector<int> &arr)
        {
            if (arr.empty())
            {
                return;
            }

            int left = 0, right = arr.size()-1;
            while (left < right)
            {
                for (int i = left; i < right; ++i)
                {
                    if (arr[i] > arr[i+1])
                    {
                        swap(arr[i], arr[i+1]);
                    }
                }
                --right;
                for (int i = right; i > left; --i)
                {
                    if (arr[i] < arr[i-1])
                    {
                        swap(arr[i], arr[i-1]);
                    }
                }
                ++left;
            }
        }
  
         static void test()
        {
            /*********测试用例************
                10
                51 49 18 93 6 23 13 55 19 1
            ******************************/
            int len = 0;
            vector<int> arr;
            cout << "Please input the length of arr:" << endl;
            cin >> len;

            cout << "Please input your array to sort:" << endl;
            arr.reserve(len);
            for (int i = 0; i < len; ++i)
            {
                int tmp = 0;
                cin >> tmp;
                arr.push_back(tmp);
            }

            CCocktailSort su;
            su.CocktailSort(arr);

            cout << "Sorted array: " ;
            for (auto itr = arr.begin(); itr != arr.end(); ++itr)
            {
                cout << *itr << " ";
            }
            cout << endl;
        }
    };
  
}


#endif //!_CocktailSort_H_
