/************************************************
  FileName    : QuickSort.h           ;
  Description :                                 ;
  Creator     : Chirl                           ;
  Contact     : ChirlChen@163.com               ;
  CreatedDate : 2017/07/16                      ;
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
#ifndef _QUICKSORT_H_
#define _QUICKSORT_H_
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

namespace Chirl
{
    /************************************************************************
     思      路： 分治(https://en.wikipedia.org/wiki/Quicksort)
     算法复杂度： O(n*lg(n)) ~ O(n^2)
     ************************************************************************/
    class CQuickSort
    {
    public:
        void QuickSort(vector<int> &arr)
        {
            QuickSort(arr, 0, arr.size()-1);
        }
    private:
        void QuickSort(vector<int> &arr, int low, int high)
        {
            if (low < high)
            {
                int p = Partition_H(arr, low, high);
                QuickSort(arr, low, p-1);
                QuickSort(arr, p+1, high);
            }

        }

        //Lomuto partition scheme
        int Partition_L(vector<int> &arr, int low, int high)
        {
            int p = arr[high];
            int i = low - 1;

            for (int j = low; j < high; ++j)
            {
                if (arr[j] < p)
                {
                    swap(arr[++i], arr[j]);
                }
            }

            if (arr[i+1] > arr[high])
            {
                swap(arr[++i], arr[high]);
            }

            return i;
        }

        //Hoare partition scheme,比Lomuto版本平均swap次数少3倍;
        int Partition_H(vector<int> &arr, int low, int high)
        {
            int p = arr[low];
            int lo = low, hi = high;

            while (lo < hi)
            {
                while (arr[lo] < p)
                {
                    ++lo;
                }
                while (arr[hi] > p)
                {
                    --hi;
                }
                swap(arr[lo], arr[hi]);
            }

            return hi;
        }
    public:
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

            CQuickSort su;
            su.QuickSort(arr);              //调用排序算法;

            cout << "Sorted array: " ;       //输出排序结果;
            for (auto itr = arr.begin(); itr != arr.end(); ++itr)
            {
                cout << *itr << " ";
            }
            cout << endl;
        }
    };
  
}


#endif //!_QuickSort_H_
