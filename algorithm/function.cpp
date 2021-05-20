#include <iostream>

using namespace std;

template<typename T, typename Arg0>
class Function {
private:
    class __call_base {
    public:
	virtual T operator()(Arg0 arg0) = 0;
	virtual ~__call_base();
    };
    __call_base *base;
public:
    R operator(Arg0 arg0) {
	return (*base)(arg0);
    }
}
int main() {


    return 0;
}
