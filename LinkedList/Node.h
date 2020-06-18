/*
# 顺序访问的线性群体-链表类

链表和数组一样都可以存储线性群体。不同之处是：对于数组（静态数组/动态数组），频繁的插入和删除元素，会导致其他元素都在移动。
会影响程序的运行效率。

*  链表是一种动态数据结构，可以用来表示顺序访问的线性群体。（数组是用数组名下标去访问元素，而链表是从最开头的元素开始，一个个往下找）
*  链表是由系列结点组成的，结点可以在运行时动态生成。
*  每一个结点包括 数据域 和 指向链表中下一个结点的指针（即下一个结点的地址） 。如果链表中每个结点中只有一个指向后继结点的指针，
   则该链表为单链表。（依靠指针维持结点次序关系）。（数组是按逻辑次序，在物理地址上依次存放。 链表在物理地址上不再相邻）。

## 单链表
   * 每个结点的物理地址不一定相邻。结点的插入和删除不影响其他结点。需要有第一个指针指向首结点，头指针。
   data1|指针 ->  data2|指针 -> data3|指针 -> ... -> datan|NULL
   
 */

//Node.h
#ifndef NODE_H
#define NODE_H

//单链表的结点类模板
template <class T>
class Node{
    private:
        Node<T> *next;//指向后继结点的指针
    public: 
        T data; //数据域; 设为public，方便访问
        //成员函数
        Node(const T& item,Node<T>* next = 0);//构造函数; 第一个参数是结点要容纳的数据元素，第二个元素是后继指针初始化为空指针
        void insertAfter(Node<T> *p);//在当前结点后插入一个结点
        Node<T> *deleteAfter();//删除当前结点的下一个结点
        Node<T> *nextNode() const;//返回下一个结点的地址
};

//构造函数，初始化数据和指针成员
template<class T>
Node<T>::Node(const T& data,Node<T> *next = 0) : data(data),next(next){}

//返回后续结点的指针
template<class T>
Node<T>* Node<T>::nextNode() const
{
    return next;
}

/* 
插入结点：在当前结点后插入结点。变更的次序：要先将 插入的新结点的指针 指向后面的结点，保证后面的结点不会丢。
再将上一结点的指针 指向 插入的新结点。(先连再断)
*/
template<class T>
void Node<T>::insertAfter(Node<T> *p)
{   
    //p结点指针域指向当前结点的后续结点
    p->next = next;
    //p->next = this->next;
    next = p;//当前结点的指针指向p    
}

/*
删除结点：直接删除结点会导致当初通过动态内存分配得到的空间会泄漏。内存空间会泄漏。所以删除结点要释放他对应的空间。
至于是否在删除结点的同时释放？删除结点的目的不确定，或许还有别的用途。所以在删除结点的函数里，不做内存释放。
将要被删除的结点地址存放在临时变量里。
 */
template<class T>
Node<T>* Node<T>::deleteAfter(void)//删除当前结点的下一结点
{
    Node<T> *temptr = next;
    if(next == 0) return 0;//如果当前结点后续没有结点，则return 0;
    next = temptr->next; //有后续结点，则把指针指向后续结点的后续结点
    return temptr;//返回删除的结点地址
                                                  
}

#endif