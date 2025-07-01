#include "MergeSort.h"

MergeSort::MergeSort(const std::vector<int>& arr) : SortInterface(arr) {}

void MergeSort::mergeArr(std::vector<int> &arr, std::vector<int> left, std::vector<int> right)
{
    int numA = left.size();
    int numB = right.size();
    int numC = numA + numB;
    int ai =0, bi =0;
    for(int i=0;i<numC;++i){
        if(ai < numA && bi >= numB){
            arr[i] = left[ai];
            ai++;
            continue;
        }
        if(ai >= numA && bi < numB){
            arr[i] = right[bi];
            bi++;
            continue;
        }
        if(ai < numA && bi < numB){
            if(left[ai] <= right[bi]){
                arr[i] = left[ai];
                ai++;
            }else{
                arr[i] = right[bi];
                bi++;
            }
        }
    }
}

void MergeSort::mergeSort(std::vector<int> &arr)
{
    //分解
    int as = arr.size();
    if(as > 1){
        int mid = as / 2;
        std::vector<int> left(arr.begin(), arr.begin()+mid);
        std::vector<int> right(arr.begin()+mid, arr.end());

        //迭代
        mergeSort(left);
        mergeSort(right);

        //合并
        mergeArr(arr, left, right);
    }
}

void MergeSort::sort()
{
    mergeSort(m_arr);
}

const std::vector<int>& MergeSort::getArr() const {
    return m_arr;
}

