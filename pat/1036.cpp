#include <iostream>
#include <vector>

using namespace std;

struct student {
    string name;
    string id;
    int grade;
    student(int grade) : grade(grade) {}
    student(const string &name, const string &id, int grade) : name(name), id(id), grade(grade) {}
};

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    string name, gender, id;
    int grade;
    student male(101), female(-1);
    for (int i = 0; i < n; i++) {
	cin >> name >> gender >> id >> grade;
	if (gender == "M") {
	    if (grade < male.grade)
		male = {name, id, grade};
	}
	else {
	    if (grade > female.grade)
		female = {name, id, grade};
	}
    }

    bool flag = true;
    if (!female.name.length()) {
	flag = false;
	cout << "Absent" << endl;
    }
    else
	cout << female.name << " " << female.id << endl;

    if (!male.name.length()) {
	flag = false;
	cout << "Absent" << endl;
    }
    else
	cout << male.name << " " << male.id << endl;

    if (flag)
	cout << female.grade - male.grade << endl;
    else
	cout << "NA" << endl;

    return 0;
}
