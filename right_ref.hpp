#include <chrono>
#include <iostream>

class A {
public:
    int* p;
public:
    A() {
        p = new int(10);
        std::cout << "using A(),p= "
            << p
            << std::endl;
    }
    //深拷贝 就是传左值引用进来，按照a的样子复制一份新的给b。
    A(const A& a) {
        p = new int(10);
        memcpy(p, a.p, 10 * sizeof(int));
        std::cout << "using A(const A&),p= "
            << p
            << std::endl;
    }
    //移动 利用右值引用：将a和引用绑定在一起传入
    A(A&& a) {
        this->p = a.p;
        a.p = nullptr;
        std::cout << "using A(A&&),p= "
            << p
            << std::endl;
    }

    ~A() {
        std::cout << "using ~A()" << std::endl;
        if (p != nullptr) {
            delete[]p;
            p = nullptr;
        }
        else {
            std::cout << "error: a.p is nullptr" << std::endl;
        }
    }
};


void test1() {
    
}