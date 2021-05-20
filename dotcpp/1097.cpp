#include<iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int begin = 1, row_spacing = 1, col_spacing = 2, row = 0;
    int val = begin;
    for (int i =  0; i < n; i++) {
        for (int j = 0; j < n - row - 1; j++) {
            cout << val << " ";
            val += col_spacing;
            col_spacing++;
        }
        cout << val << endl;
        begin += row_spacing;
        val = begin;
        row_spacing++;
        row++;
        col_spacing = row + 2;
    }
    
    return 0;
}
