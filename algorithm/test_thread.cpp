#include <iostream> 
#include <thread>
#include <mutex>

using namespace std;

class Foo {
public:
    mutex m1, m2;
    Foo() {m1.lock(); m2.lock();};
    void first() {cout << "first" << endl;}
    void second() {cout << "second" << endl;}
    void third() {cout << "third" << endl;}
};

void task1(Foo f) {
    f.first();
    f.m1.unlock();
}

void task2(Foo f) {
    f.m1.lock();
    f.second();
    f.m1.unlock();
    f.m2.lock();
}

void task3(Foo f) {
    f.m2.lock();
    f.third();
    f.m2.unlock();
}

int main() {
    Foo foo;
    cout << "begin" << endl;
    thread thread1(task1, foo);
    thread thread2(task2, foo);
    thread thread3(task3, foo);
    cout << "end" << endl;

    thread1.join();
    thread2.join();
    thread3.join();

    return 0;
}
