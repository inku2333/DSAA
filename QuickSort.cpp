#include "QuickSort.h"

QuickSort::QuickSort(const std::vector<int>& arr) : SortInterface(arr) {}

int QuickSort::partition(int left, int right) //快慢指针
{
    int pivot = m_arr[right];
    int slow = left, fast = left;
    while (fast < right) {
        if (m_arr[fast] < pivot) {
            swap(slow, fast);
            slow++;
        }
        fast++;
    }
    swap(slow, right);
    return slow;
}

void QuickSort::quickSort(int left, int right)
{
    if (left >= right) return;
    int newR = partition(left, right);//分割
    quickSort(left, newR - 1);
    quickSort(newR + 1, right);
}

void QuickSort::sort()
{
    if (!m_arr.empty())
        quickSort(0, static_cast<int>(m_arr.size()) - 1);
}

const std::vector<int>& QuickSort::getArr() const {
    return m_arr;
}
