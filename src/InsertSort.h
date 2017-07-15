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

using namespace std;

namespace Chirl
{
    /************************************************************************
     思      路： 
     算法复杂度：O(n^2)
     ************************************************************************/
    class CInsertSort
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

            CInsertSort su;
            su.InsertSort(arr);

            cout << "Sorted array: " ;
            for (auto itr = arr.begin(); itr != arr.end(); ++itr)
            {
                cout << *itr << " ";
            }
            cout << endl;
        }
    };
  
}


#endif //!_InsertSort_H_
