#include <iostream>
#include <cassert>
#include <algorithm>
#include <iterator>
#include <random>
#include <vector>
#include "QuickSort.h"
#include "MergeSort.h"
#include "Heap.h"

using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    constexpr int num = 100;
    std::vector<int> arr(num);

    //创建随机数引擎（使用硬件熵源）
    std::random_device rd;
    std::mt19937 gen(rd());

    //定义分布范围（0-99的整数）
    std::uniform_int_distribution<> dis(0, 99);
    //浮点数：std::uniform_real_distribution<double>(0.0, 1.0)
    //正态分布：std::normal_distribution<double>(mean, stddev)

    for(int i=0; i<num; ++i){
        arr[i] = dis(gen);
    }

    std::vector<int> arr2 = arr;
    std::vector<int> arr3 = arr;

    {//QuickSort begin
        cout << "arr Before sorting :" << endl;
        QuickSort qs(arr);
        qs.printArr();
        qs.sort();
        cout << "arr After sorting :" << endl;
        qs.printArr();
        arr = qs.getArr();
    }//QuickSort end

    {//MergeSort begin
        cout << "arr2 Before sorting :" << endl;
        MergeSort ms(arr2);
        ms.printArr();
        ms.sort();
        cout << "arr2 After sorting :" << endl;
        ms.printArr();
        arr2 = ms.getArr();
    }//MergeSort end

    {
        cout << "arr3 Before sorting :" << endl;
        for (const auto& num : arr3)
            std::cout << num << " ";
        std::cout << "\n ========================== ============================ \n";

        Heap<int> heap(arr3, false);

        std::vector<int> arrHeap = heap.getData();
        cout << "arrHeap After creating :" << endl;
        for (const auto& num : arrHeap)
            std::cout << num << " ";
        std::cout << "\n ========================== ============================ \n";

//        bool isHeap = std::is_heap(arrHeap.begin(), arrHeap.end());//最大堆
        bool isHeap = std::is_heap(arrHeap.begin(), arrHeap.end(),std::greater<int>());//最小堆
        std::cout << "arrHeap is Heap: "<< isHeap << "\n";

        heap.sort(arrHeap);
        cout << "arrHeap After sorting :" << endl;
        for (const auto& num : arrHeap)
            std::cout << num << " ";
        std::cout << "\n ========================== ============================ \n";
    }

    
    return 0;
}
