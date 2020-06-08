/* 
 C++的产生和发展
从C语言发展演变而来，最初被成为“带类的C”
1983年正式取名为C++
1998年11月被国际标准化组织(ISO)批准为国际标准
2003年10月发布第二版C++标准ISO/IEC 14882：2003
2011年8月ISO公布了第三版C++标准C++11， 包含核心语言的新机能，扩展C++标准程序库
2014年ISO公布了C++14， 其正式名称为International Standard ISO/IEC 14882:2014(E) Programming Language C++"

## C++ 特点：
兼容C，支持面向过程的程序设计
支持面向对象的方法
支持泛型程序设计方法
*/

// C++ 程序实例
#include <iostream>
using namespace std;

//规定返回类型是int类型
int main()
{
    //cout:预定义好的类的对象，向显示器送数据的功能。类库中有常用的功能，已预定义好。是输出流的对象。
    //<< : 运算符，是流插入运算，将后面的字符串插入到数据输出流中。endl:表示行结束。
    cout << "hello! " << endl;
    //<< 
    cout << "welcome to C++ " << endl;
    //返回计算结果，操作系统是主函数的调用者。
    return 0;
}