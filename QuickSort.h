#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "SortInterface.h"
#include <vector>

class QuickSort: public SortInterface<int>
{
public:
    explicit QuickSort(const std::vector<int>& arr);
    ~QuickSort() override = default;
    void sort() override;
    // 获取排序结果
    const std::vector<int>& getArr() const;

private:
    int partition(int left, int right);
    void quickSort(int left, int right);
};

#endif // QUICKSORT_H