#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <algorithm>
#include <iostream>

template <typename T>
class Heap {
private:
    std::vector<T> m_data;
    bool isMaxHeap;

    void heapifyUp(int index){
        if (index == 0) return;

        int p = (index - 1) / 2;
        bool shouldSwap = isMaxHeap ? (m_data[index] > m_data[p]) : (m_data[index] < m_data[p]);
        if(shouldSwap){
            std::swap(m_data[p], m_data[index]);
            heapifyUp(p);
        }
    }

    void heapifyDown(int index){
        int left = 2*index + 1;
        int right = 2*index + 2;
        int selected = index;

        if (left < m_data.size()) {
            bool leftBetter = isMaxHeap ? (m_data[left] > m_data[selected]) : (m_data[left] < m_data[selected]);
            if (leftBetter) selected = left;
        }

        if (right < m_data.size()) { //要选择左右节点中更大/小的一个
            bool rightBetter = isMaxHeap ? (m_data[right] > m_data[selected]) : (m_data[right] < m_data[selected]);
            if (rightBetter) selected = right;
        }

        if (selected != index) {
            std::swap(m_data[index], m_data[selected]);
            heapifyDown(selected);
        }
    }

    int findHelper(const T& value, int currentIndex) const{
        if(currentIndex >= m_data.size()) return -1;
        if(m_data[currentIndex] == value) return currentIndex;

        int left = findHelper(value, currentIndex * 2 + 1);
        if(left != -1) return left; // 递归剪枝 省略右子树搜索
        return findHelper(value, currentIndex * 2 + 2);
    }

public:
    explicit Heap(bool maxHeap = true) : isMaxHeap(maxHeap) {}

    Heap(const std::vector<T>& arr, bool maxHeap = true){ //O(n)，优于逐个插入的O(nlogn)建堆方式
        m_data = arr;
        isMaxHeap = maxHeap;
        for(int i = (m_data.size()/2 - 1); i >= 0; --i){
            heapifyDown(i);
        }
    }

    void insert(const T& value){
        m_data.push_back(value);
        heapifyUp(m_data.size() - 1);
    }

    void remove(const T& value){
        int index = findHelper(value, 0);//从0开始查找
        if (index == -1) return;

        std::swap(m_data.back(), m_data[index]);
        m_data.pop_back();

        heapifyUp(m_data.size() - 1);
    }

    bool find(const T& value) const{
        return findHelper(value, 0) != -1;
    }

    void sort(std::vector<T>& result){ //会使原本的heap中的清空
        Heap<T> tempHeap = *this;
        result.clear();
        while(!tempHeap.empty()){
            result.push_back(tempHeap.extractTop());
        }
    }

    T extractTop(){ // 取顶
        if(m_data.empty()) throw std::out_of_range("Heap is empty");

        T top = m_data[0];
        m_data[0] = m_data.back();
        m_data.pop_back();
        heapifyDown(0);//重新堆化

        return top;
    }

    bool empty() const { return m_data.empty(); }

    size_t size() const { return m_data.size(); }

    std::vector<T> getData() const {
        return m_data;
    }

};

#endif // HEAP_H
