/*
栈是一种线性数据结构，只能从一端访问的线性群体，
是一种后进先出的数据结构。

从一端插入数据，从同一端删除数据。
从一端把数据放出去，叫入栈，压入栈。
取出数据，叫出栈，弹出栈。

实际上函数的调用和返回的过程，底层处理都是用栈来实现。
调用子函数，控制流程进入子函数，流程如何回到调用位置？
他是把要返回的位置，即返回地址，压入到栈里。

栈的基本状态：
* 栈空
* 栈满
* 一般状态

栈的基本操作
* 初始化
* 入栈
* 出栈
* 清空栈
* 访问栈顶元素
* 检测栈的状态

*/

#ifndef STACK_H
#define STACK_H

#include<cassert>

template < class T, int SIZE = 50>
class Stack {
private:
	T list[SIZE];
	int top;
public:
	Stack();
	void push(const T&item);
	T pop();
	void clear();
	const T& peek() const;
	bool isEmpty() const;
	bool isFull() const;
};

//模板的实现
template<class T,int SIZE>
Stack<T,SIZE>::Stack():top(-1){}
template<class T,int SIZE>
void Stack<T, SIZE>::push(const T&item) {
	assert(!isFull());
	list[++top] = item;
}
template<class T,int SIZE>
T Stack<T, SIZE>::pop() {
	assert(!isEmpty());
	return list[top--];
}

template<class T,int SIZE>
const T& Stack<T, SIZE>::peek() const {
	assert(!isEmpty());
	return
}
template<class T,int SIZE>
void Stack<T, SIZE>::clear() {

}



#endif // !STACK_H
