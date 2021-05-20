#include <iostream>
#include <vector>

using namespace std;

const int mod = 1e9 + 7;

class Matrix {
private:
    int n;
    vector<vector<long long>> a;
public:
    Matrix(int n) : n(n) {
	a = vector<vector<long long>>(n, vector<long long>(n, 0));
	for (int i = 0; i < n; i++) {
	    a[i][i] = 1;
	}	
    }

    Matrix(const vector<vector<long long>> &a) : a(a) {n = a.size();}

    vector<long long> operator[](const int i) const {
	return a[i];
    }

    Matrix operator*(const Matrix &b) {
	vector<vector<long long>> tmp(n, vector<long long>(n, 0));
	for (int i = 0; i < n; i++) {
	    for (int j = 0; j < n; j++) {
		for (int k = 0; k < n; k++) {
		    tmp[i][j] += a[i][k] * b[k][j];
		}
	    }
	}
	return Matrix{tmp};
    }

    friend ostream &operator<<(ostream &out, const Matrix &m) {
	int n = m.n;
	for (int i = 0; i < n; i++) {
	    for (int j = 0; j < n; j++) {
		out << m[i][j] << " ";
	    }
	    out << endl;
	}
	return out;
    }

    void qpow(int n) {
	Matrix rst(this->n);
	Matrix m(*this);
	while (n) {
	    if (n & 1) rst = rst * m;
	    n >>= 1;
	    m = m * m;
	}
	*this = rst;
    }
};

int main() {
    Matrix a {{{0, 1}, {1, 2}}};
    a.qpow(3);
    cout << a << endl;

    return 0;
}
