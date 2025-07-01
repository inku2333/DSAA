#ifndef LINKED_LIST_H  // 防止头文件重复包含的宏定义
#define LINKED_LIST_H

#include <iostream>    // 标准输入输出流
#include <stdexcept>   // 异常处理类库

template <typename T>  // 模板声明，支持泛型数据类型T
class LinkedList {
private:
    struct Node {      // 私有嵌套节点结构体
        T data;        // 节点存储的数据
        Node* next;    // 指向下一个节点的指针
        Node(const T& val) : data(val), next(nullptr) {} // 节点构造函数
    };

    Node* head;        // 链表头指针
    Node* tail;        // 链表尾指针
    size_t size;       // 链表长度计数器

public:
    class Iterator {   // 嵌套迭代器类
        Node* current; // 当前节点指针
    public:
        Iterator(Node* node) : current(node) {} // 迭代器构造函数
        T& operator*() { return current->data; } // 解引用操作符重载
        Iterator& operator++() {  // 前置++操作符重载
            current = current->next;
            return *this; // 当前Iterator对象
        }
        bool operator!=(const Iterator& other) const { // 不等判断操作符重载
            return current != other.current; // 实际比较Node*地址
        }
    };

    LinkedList() : head(nullptr), tail(nullptr), size(0) {} // 默认构造函数
    ~LinkedList() { clear(); } // 析构函数，自动调用clear()

    // 基础操作接口
    void push_front(const T& val) { // 头部插入
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode; // 空链表处理
        }else {
            newNode->next = head;
            head = newNode;
        }
        size++;
    }

    void push_back(const T& val) {  // 尾部插入
        Node* newNode = new Node(val);
        if (!tail) {
            head = tail = newNode; // 空链表处理
        }else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    void pop_front() {  // 头部删除
        if (!head) throw std::out_of_range("List is empty");
        Node* temp = head;
        head = head->next;
        delete temp;
        if (!head) tail = nullptr; // 删除后为空链表的处理
        size--;
    }

    void reverse() {  // 链表反转
        Node *prev = nullptr, *current = head, *next = nullptr;
        tail = head;  // 反转后尾节点变为原头节点
        while (current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;  // 最终prev成为新头节点
    }

    // 工具方法
    Iterator begin() { return Iterator(head); } // 获取起始迭代器
    Iterator end() { return Iterator(nullptr); } // 获取结束迭代器:相比维护一个特殊的哨兵节点，直接返回nullptr更高效且无需额外内存分配
    size_t getSize() const { return size; }     // 获取链表长度
    bool empty() const { return size == 0; }    // 判断空链表

    void clear() {  // 清空链表
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        size = 0;
    }

    // 禁用拷贝构造和赋值操作（防止浅拷贝问题）
    LinkedList(const LinkedList&) = delete;
    LinkedList& operator=(const LinkedList&) = delete;
    // 深拷贝构造函数示例
//    LinkedList(const LinkedList& oldList) {
//        Node* src = oldList.head;
//        while(src) {
//            append(src->data);  // 创建新节点并复制数据
//            src = src->next;
//        }
//    }
};
#endif // LINKED_LIST_H
