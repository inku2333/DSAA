#ifndef SORTINTERFACE_H
#define SORTINTERFACE_H

#include <iostream>
#include <algorithm>
#include <vector>

template<typename T>
class SortInterface
{
public:
    explicit SortInterface(const std::vector<T>& arr) : m_arr(arr) {}
    virtual ~SortInterface() = default;

    void setArr(const std::vector<T>& arr) { m_arr = arr; }
    void printArr() const {
        std::cout << __FUNCTION__ << "\n";
        for (const auto& num : m_arr)
            std::cout << num << " ";
        std::cout << "\n ========================== ============================ \n";
    }
    virtual void sort() = 0;
    const std::vector<T>& getArr() const { return m_arr; }

protected:
    void swap(int i, int j) { std::swap(m_arr[i], m_arr[j]); }
    std::vector<T> m_arr;
};

#endif // SORTINTERFACE_H
