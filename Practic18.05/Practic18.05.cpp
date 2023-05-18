#include <iostream>
#include <string>
#include "List.h"
#include "Matrix.h"
#include "Pair.h"
using namespace std;

//template <class T>
//T Max(T t1, T t2) {
//    return t1 > t2 ? t1 : t2;
//}
//template <>
//const char* Max<const char*>(const char* t1, const char* t2) {
//    return strcmp(t1, t2) > 0 ? t1 : t2;
//}
//
//
//template<class T>
//void getValue(string promt, T& value) {
//    cout << promt;
//    cin >> value;
//    while (cin.fail()) {
//        cin.clear();
//        cin.ignore();
//        cout << "Error... try again\n";
//        cout << promt;
//        cin >> value;
//    }
//    string endline;
//    getline(cin, endline);
//}
//template <>
//inline void getValue<string>(string promt, string& value) {
//    cout << promt;
//    getline(cin, value);
//}

struct Point {
    int x; int y;
    Point(int x = 0, int y = 0):x{x}, y{y}{}
    friend bool operator> (const Point& p1, const Point& p2) {
        double d1 = sqrt(p1.x * p1.x + p1.y * p1.y);
        double d2 = sqrt(p2.x * p2.x + p2.y * p2.y);
        return d1 - d2;
    }
    friend ostream& operator<<(ostream& out, const Point& p1) {
        out << "(" << p1.x << ", " << p1.y << ")";
        return out;
    }
};

int main()
{
    /*int i1 = 10;
    int i2 = 20;
    double d1 = 10.1;
    double d2 = 20.1;
    string s1 = "hi";
    string s2 = "bye";
    const char* c1 = "hi";
    const char* c2 = "bye";

    cout << Max(i1, i2) << endl;
    cout << Max(d1, d2) << endl;
    cout << Max(s1, s2) << endl;
    cout << Max(c1, c2) << endl;*/

    /*int a;
    char c;
    string s;
    getValue("integer", a);
    getValue("character", c);
    getValue("string", s);*/

    /*List<int> intList;
    intList.add(5);
    intList.add(7);
    intList.add(3);
    intList.add(9);
    intList.add(0);
    cout << "intList min: " << intList.getMin() << endl;
    cout << "intList max: " << intList.getMax() << endl;

    List<string> strList;
    strList.add("one");
    strList.add("two");
    strList.add("three");
    strList.add("four");
    strList.add("five");
    cout << "strList min: " << strList.getMin() << endl;
    cout << "strList max: " << strList.getMax() << endl;

    List<const char*> charList;
    charList.add("one");
    charList.add("two");
    charList.add("three");
    charList.add("four");
    charList.add("five");
    cout << "charList min: " << charList.getMin() << endl;
    cout << "charList max: " << charList.getMax() << endl;*/

    /*const int height = 2;
    const int width = 3;

    Matrix<int, height, width> intMatrix;
    intMatrix(0, 0) = 7;
    intMatrix(0, 1) = 5;
    intMatrix(0, 2) = 4;
    intMatrix(1, 0) = 2;
    intMatrix(1, 1) = 9;
    intMatrix(1, 2) = 3;
    cout << "intMatrix min: " << intMatrix.getMin() << endl;
    cout << "intMatrix max: " << intMatrix.getMax() << endl << endl;

    Matrix<string, height, width> strMatrix;
    strMatrix(0, 0) = "five";
    strMatrix(0, 1) = "seven";
    strMatrix(0, 2) = "two";
    strMatrix(1, 0) = "nine";
    strMatrix(1, 1) = "zero";
    strMatrix(1, 2) = "three";
    cout << "strMatrix min: " << strMatrix.getMin() << endl;
    cout << "strMatrix max: " << strMatrix.getMax() << endl << endl;

    Matrix<const char*, height, width> charMatrix;
    charMatrix(0, 0) = "five";
    charMatrix(0, 1) = "seven";
    charMatrix(0, 2) = "two";
    charMatrix(1, 0) = "nine";
    charMatrix(1, 1) = "zero";
    charMatrix(1, 2) = "three";
    cout << "charMatrix min: " << charMatrix.getMin() << endl;
    cout << "charMatrix max: " << charMatrix.getMax() << endl << endl;*/

    /*Pair<int, int> point1(0, 0);
    Pair<int, int> point2(1, 1);
    point1.display(); cout << " ";
    point2.display(); cout << " ";
    cout << (point1 == point2 ? "equals" : "not equals") << endl;

    Pair<int, int>point3;
    point1.display(); cout << " ";
    point3.display(); cout << " ";
    cout << (point1 == point3 ? "equals" : "not equals") << endl;

    Pair<string, string> name("Ivan", "Ivanov");
    Pair<Pair<string, string>, int> mark(name, 8);
    mark.first.display();
    cout << " : " << mark.second << endl;*/

    Matrix<int> intMatrix(3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            intMatrix(i, j) = i * 10 + j;
        }
    }
    cout << intMatrix << endl;

    Matrix<int> intMatrixA = intMatrix;
    cout << endl << intMatrixA << endl;

    Matrix<string> strMatrix(2, 3);
    strMatrix(0, 0) = "string00";
    strMatrix(0, 1) = "string01";
    strMatrix(0, 2) = "string02";
    strMatrix(1, 0) = "string10";
    strMatrix(1, 1) = "string11";
    strMatrix(1, 2) = "string12";
    cout << endl << strMatrix << endl;

    Matrix<Point> pointMatrix(2, 3);
    pointMatrix(0, 0) = Point(0, 0);
    pointMatrix(0, 1) = Point(0, 1);
    pointMatrix(0, 2) = Point(0, 2);
    pointMatrix(1, 0) = Point(1, 0);
    pointMatrix(1, 1) = Point(1, 1);
    pointMatrix(1, 2) = Point(1, 2);
    cout << endl << pointMatrix << endl << endl << endl;

    NumberMatrix<double> numberMatrixA(2, 3);
    numberMatrixA.setRand();
    cout << numberMatrixA << endl;
    NumberMatrix<double> numberMatrixB(2, 3);
    numberMatrixB.setRand();
    cout << endl << numberMatrixB << endl;

    NumberMatrix<double> numberMatrixC = numberMatrixA + numberMatrixB;
    cout << endl << numberMatrixC;
}
