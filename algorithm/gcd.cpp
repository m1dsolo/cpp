#include <iostream>
#include <utility>
using namespace std;

//pair<int, int> get_gcd_lcm(int a, int b) {
    //int src_a = a, src_b = b;
    //while (int mod = a % b) {
	//a = b;
	//b = mod;	
    //}

    //int gcd = a / b;
    //return make_pair(gcd, src_a * src_b / gcd); 
//} 

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

int main() {
    cout << gcd(15, 20) << " " << lcm(15, 20) << endl;

    return 0;
}
