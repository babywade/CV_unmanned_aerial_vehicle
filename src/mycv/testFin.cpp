#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("test.txt");
    int a, b, c, d;
    fin >> a >> b >> c >> d;

    cout << "a = " << a << endl
    << "b = " << b << endl
    << "c = " << c << endl
    << "d = " << d << endl;
}
