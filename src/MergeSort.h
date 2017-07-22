/************************************************
  FileName    : MergeSort.h           ;
  Description :                                 ;
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
#ifndef _MERGESORT_H_
#define _MERGESORT_H_
#include "SuperSort.h"

namespace Chirl
{
    /************************************************************************
     思      路：https://en.wikipedia.org/wiki/Merge_sort 
     算法复杂度：O(n*lg(n)), 
     ************************************************************************/
    class CMergeSort : public CSuperSort
    {
    public:
        void MergeSort(vector<int> &arr)
        {
            vector<int> ans = Divide(arr, 0, arr.size());
            swap(arr, ans);
            return;
        }
        
        void DoSort(vector<int> &arr)
        {
            MergeSort(arr);
        }
    private:
        vector<int> Divide(vector<int> &arr, int first, int last)
        {
            if (first == last - 1)
            {
                return vector<int>(1, arr[first]);
            }

            int mid = (first + last) / 2;
            vector<int> ans1 = Divide(arr, first, mid);
            vector<int> ans2 = Divide(arr, mid, last);

            vector<int> ans;
            ans.reserve(ans1.size() + ans2.size());
            Merge(ans1, ans2, ans);
            return ans;
        }

        void Merge(vector<int> &leftArr, vector<int> &rightArr, vector<int> &ans)
        {
            int leftIdx = 0;
            int rightIdx = 0;

            while (leftIdx < leftArr.size() && rightIdx < rightArr.size())
            {
                if (leftArr[leftIdx] < rightArr[rightIdx])
                {
                    ans.push_back(leftArr[leftIdx++]);
                }
                else
                {
                    ans.push_back(rightArr[rightIdx++]);
                }
            }

            while (leftIdx < leftArr.size())
            {
                ans.push_back(leftArr[leftIdx++]);
            }

            while (rightIdx < rightArr.size())
            {
                ans.push_back(rightArr[rightIdx++]);
            }
        }
    public:
        static void test()
        {
            CMergeSort obj;
            obj.DoTest(&obj);
        }
    };
  
}


#endif //!_MergeSort_H_
