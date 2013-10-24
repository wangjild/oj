#include "bign.h"

int main() {
    bign a("99");
    bign b("99");

    bign c = a * b;
    cout << c << endl;

    a = "101000000000000000000000000000000000000000";
    b = "100";
    cout << a * b << endl;

    a = "1";
    b = "10";
    cout << a * b << endl;

    a = "0";
    b = "10";
    cout << a * b << endl;
}
