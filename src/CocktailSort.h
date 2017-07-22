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
#include "SuperSort.h"
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
    class CCocktailSort : public CSuperSort
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
  
        void DoSort(vector<int> &arr)
        {
            CocktailSort(arr);
        }

        static void test()
        {
            CCocktailSort obj;
            obj.DoTest(&obj);
        }
    };
  
}


#endif //!_CocktailSort_H_
