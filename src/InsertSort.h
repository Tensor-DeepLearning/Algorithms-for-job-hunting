/************************************************
  FileName    : InsertSort.h           ;
  Description :                                 ;
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
#ifndef _INSERTSORT_H_
#define _INSERTSORT_H_
#include <iostream>
#include <vector>
#include "SuperSort.h"
using namespace std;

namespace Chirl
{
    /************************************************************************
     思      路： 
     算法复杂度：O(n^2)
     ************************************************************************/
    class CInsertSort : public CSuperSort
    {
    public:
        void InsertSort(vector<int> &arr)
        {
            if (arr.empty())
            {
                return;
            }

            for (int i = 1; i < arr.size(); ++i)
            {
                int tmp = arr[i];

                int j = i;
                while (j > 0 && arr[j - 1] > tmp)
                {
                    arr[j--] = arr[j];
                }
                arr[j] = tmp;
            }

        }
  
        void DoSort(vector<int> &arr)
        {
            InsertSort(arr);
        }

        static void test()
        {
            CInsertSort obj;
            obj.DoTest(&obj);
        }
    };
  
}


#endif //!_InsertSort_H_
