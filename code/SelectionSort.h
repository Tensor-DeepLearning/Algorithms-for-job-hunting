/************************************************
  FileName    : SelectionSort.h           ;
  Description : 选择排序                                ;
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
#ifndef _SELECTIONSORT_H_
#define _SELECTIONSORT_H_

#include <vector>
#include <iostream>

using namespace std;

namespace Chirl
{
    /************************************************************************
     思      路：首先在未排序序列中找到最小（大）元素，存放到排序序列的起始位;
                 置，然后，再从剩余未排序元素中继续寻找最小（大）元素，然后放;
                 到已排序序列的末尾。以此类推，直到所有元素均排序完毕。      ;
     算法复杂度：O(n^2)
     ************************************************************************/
    class CSelectionSort
    {
    public:
        void SelectionSort(vector<int> &arr)
        {
            int minIdx = 0;

            for (int i = 0; i < arr.size()-1; ++i)
            {
                minIdx = i;
                for (int j = i+1; j < arr.size(); ++j)
                {
                    minIdx = arr[minIdx] < arr[j] ? minIdx : j;
                }
                swap(arr[minIdx], arr[i]);
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

            CSelectionSort su;
            su.SelectionSort(arr);

            cout << "Sorted array: " ;
            for (auto itr = arr.begin(); itr != arr.end(); ++itr)
            {
                cout << *itr << " ";
            }
            cout << endl;
        }
    };
  
}


#endif //!_SelectionSort_H_
