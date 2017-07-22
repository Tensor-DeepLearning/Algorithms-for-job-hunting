/************************************************
  FileName    : SuperSort.h           ;
  Description : 排序算法基类，减少重复代码      ;
  Creator     : Chirl                           ;
  Contact     : ChirlChen@163.com               ;
  CreatedDate : 2017/07/22                      ;
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
#ifndef _CSUPERSORT_H_
#define _CSUPERSORT_H_
#include <iostream>
#include <vector>

using namespace std;

namespace Chirl
{
    class CSuperSort
    {
    public:
        virtual void DoSort(vector<int> &arr)
        {
            cout << "Do nothing!\n" ;
        }
  
        void DoTest(CSuperSort *obj)
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
            obj->DoSort(arr);
            
            cout << "Sorted array: " ;       //输出排序结果;
            for (auto itr = arr.begin(); itr != arr.end(); ++itr)
            {
                cout << *itr << " ";
            }
            cout << endl;
        }
    };
  
}


#endif //!_CSuperSort_H_
