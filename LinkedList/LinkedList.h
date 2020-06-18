/*
链表的基本操作
# 生成链表
# 插入结点
# 查找结点
# 删除结点
# 遍历链表
# 清空链表 

*/

//LinkedList.h
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
template<class T>
class LinkedList{
    private:
        Node<T> *front, *rear;//表头 和 表尾 指针 ; 表头指针要始终指向链表的表头
        Node<T> *prevPtr, *currPtr;//currptr: 工作指针,指向当前正在操作的结点; 要遍历链表,依次访问链表中的各个元素的话，
                                   //表头指针始终指向表头，表头指针不可以移动，否则会造成内存泄漏; 
                                   //用工作指针向后移动。即记录表当前遍历位置的指针，currptr ; 
                                   //对当前结点的操作依赖于前驱指针，所以需要有前驱指针
        int size;// 表中的元素个数
        int position;// 当前元素在链表中的位置序号，由函数reset使用
        //生成新结点，数据域为item,指针域为ptrNext
        Node<T>* newNode(const T &item, Node<T> *ptrNext = NULL);//生成新结点
        void freeNode(Node<T>* p);//释放结点
        void copy(LinkedList<T> & L);//将链表L复制到当前表（假设当前链表为空），被复制构造函数，operator= 调用

        //对外接口函数
    public:
        LinkedList();//构造函数
        LinkedList(const LinkedList<T> &L);//拷贝构造函数
        ~LinkedList();//析构函数
        LinkedList<T> &operator = (const LinkedList<T> &L);//重载赋值运算符

        int  getSize() const;//返回链表中元素个数
        bool isEmpty() const;//链表是否为空

        void reset(int pos = 0);//初始化游标的位置;游标是一个标记，始终指向当前要处理的结点;
        void next();//使游标移动到下一个结点
        bool endOfList() const;//游标是否到了链尾
        int  currentPosition()  const;//返回游标当前位置

        void insertFront(const T &item); //在表头插入结点
        void insertRear(const T &item);//在表尾添加结点
        void insertAt(const T& item);//在当前结点前插入结点
        void insertAfter(const T&item);//在当前结点之后插入结点
        T deleteFront();//删除头结点
        void deleteCurrent();//删除当前结点

        T& data(); //返回对当前结点成员数据的引用
        const T& data() const; //返回对当前结点成员数据的常引用

        //清空链表: 释放所有结点的内存空间，被析构函数，operator= 调用
        void clear();

};
#endif 