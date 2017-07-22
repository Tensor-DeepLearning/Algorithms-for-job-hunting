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
    class CBubbleSort
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
  
     

        static void test()
        {
            /*********测试用例************
                10
                51 49 18 93 6 23 13 55 19 1
            ******************************/
            
            int len = 0;
            vector<int> arr;
            cout << "Please input the length of arr:" << endl;   
            cin >> len;                     //读取数组长度;

            cout << "Please input your array to sort:" << endl;
            arr.reserve(len); 
            for (int i = 0; i < len; ++i)   //读取输入的随机数组;
            {
                int tmp = 0;
                cin >> tmp;
                arr.push_back(tmp);
            }
            CBubbleSort su;
            su.BubbleSort(arr);
            
            cout << "Sorted array: " ;       //输出排序结果;
            for (auto itr = arr.begin(); itr != arr.end(); ++itr)
            {
                cout << *itr << " ";
            }
            cout << endl;
        }
    };
  
}


#endif //!_BubbleSort_H_
