#include <iostream>

using namespace std;

class Animal {
public:
    int val;
    virtual void func() = 0;
};

class Dog : public Animal {
public:
    int val = 1;
    void func() {
	cout << "Dog" << " " << val << endl;
    }
};

class Cat : public Animal {
public:
    int val = 2;
    void func () {
	cout << "Cat" << " " << val << endl;
    }
};

int main() {
    Dog dog;
    Cat cat;

    int *p1 = (int *)(&dog);
    int *p2 = (int *)(&cat);
    p1[0] = p2[0];  // 把dog的虚函数表指针指向了cat

    //dog.func();   // 这么调用不会好象不会调用虚函数表指针
    Animal *a = &dog;
    a->func();

    return 0;
}
