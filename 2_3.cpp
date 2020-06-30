#include<iostream>

using namespace std;

int main()
{
    int radius;
    cout << "please enter radius: " << endl;
    cin >> radius;
    cout << "radius is : " << radius << endl;
    cout << "pi is " << 3.14 << '\n';
    cout << "enter radius: " << endl;
    cin >> radius;
    cout << "Now radius: " << endl;
    
    return 0;

}

//vs studio: 使用调试中逐过程，F10， 一步步执行F10，局部变量窗口会看到变量的信息。
//浮点数在机器中 是近似存储的。！！！和期望的值会有点差别。eg.const double pi(3.14159) 但实际上局部变量里pi的值是3.14158999999
//且注意不能给常量赋值。
//