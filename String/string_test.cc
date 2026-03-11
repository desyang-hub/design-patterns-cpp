#include "my_string.h"

using namespace std;

int main() {

    String name("desyang");

    cout << name.Size() << endl;
    cout << name << endl;

    String s1 = "hhhh";
    cout << s1 << endl;
    String s2{"aaaa"};
    cout << s2 << endl;

    String s3(s1);
    cout << s3 << endl;
    String s4 = s2;
    cout << s4 << endl;
    s4 = s2;
    cout << s4 << endl;

    String s5(std::move(s1));
    cout << s5 << endl;
    String s6 = std::move(s2);
    cout << s6 << endl;
    String s7(String("s7"));
    cout << s7 << endl;
    s7 = s5;
    cout << s7 << endl;

    String t1 = "hello: ";
    String t2 = "desyang";

    cout << t1.Append(t2) << endl;
    cout << t1.Append("...") << endl;
    cout << "Program is ending." << endl;

    t1[0] = ' ';
    cout << t1 << endl;

    t1 << " append string";
    cout << t1 << endl;
    return 0;
}