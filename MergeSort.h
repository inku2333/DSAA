#ifndef MERGESORT_H
#define MERGESORT_H

#include "SortInterface.h"
#include <vector>

class MergeSort : public SortInterface<int>
{
public:
    explicit MergeSort(const std::vector<int>& arr);
    ~MergeSort() override = default;
    void sort() override;
    // 获取排序结果
    const std::vector<int>& getArr() const;

private:
    void mergeArr(std::vector<int> &arr, std::vector<int> left, std::vector<int> right);
    void mergeSort(std::vector<int> &arr);
};

#endif // MERGESORT_H