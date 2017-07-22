/************************************************
  FileName    : BubbleSort.h           ;
  Description : 冒泡排序法                                ;
  Creator     : Chirl                           ;
  Contact     : ChirlChen@163.com               ;
  CreatedDate : 2017/07/14                      ;
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
#ifndef _BUBBLESORT_H_
#define _BUBBLESORT_H_

#include <algorithm>
#include "SuperSort.h"
using namespace std;

namespace Chirl
{
    /************************************************************************
     思      路： 
     算法复杂度：O(n^2)
     ************************************************************************/
    class CBubbleSort : public CSuperSort
    {
    public:
        void BubbleSort(vector<int> &arr)
        {
            if (arr.empty())
            {
                return;
            }

            for (int loop = 1; loop < arr.size(); ++loop)
            {
                for (int idx = 0; idx < arr.size()-loop; ++idx)
                {
                    if (arr[idx] > arr[idx+1])
                    {
                        swap(arr[idx], arr[idx+1]);
                    }
                }
                
            }
        }
  
        void DoSort(vector<int> &arr)
        {
            BubbleSort(arr);
        }

        static void test()
        {
            CBubbleSort obj;
            obj.DoTest(&obj);
        }
    };
  
}


#endif //!_BubbleSort_H_
