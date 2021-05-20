#include <iostream>
#include <fstream>
#include <vector>
#include <limits.h>

using namespace std;

int main() {
    ifstream fin("data");
    int n;
    fin >> n;
    char buf[2000];
    fin.get();
    for (int i = 0; i < 5; i++) {
	fin.getline(buf, 2000);
	cout << buf << endl;
    }

    fin.close();

    return 0;
}
