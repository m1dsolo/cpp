#include <iostream>

using namespace std;

class Base {
public:
    int val = 1;
    void f1() {
	val *= 10;
    }
    virtual void f2() {
	val++;
    }
};

class Child : public Base {
public:
    void f1() {
	val *= 100;
    }
    void f2() {
	val += 2;
    }

};

int main() {
    //Chlid c;	    // rst = 102
    //c.f1();
    //c.f2();

    Base *c = new Child;    // rst = 12
    c->f1();
    c->f2();

    printf("%d\n", c->val);

    return 0;
}
