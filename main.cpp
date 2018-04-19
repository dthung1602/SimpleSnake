#include "src/Game.h"

#include <zconf.h>
#include <iostream>
using  namespace std;
std::string getpath() {
    char buf[100 + 1];
    if (readlink("/proc/self/exe", buf, sizeof(buf) - 1) == -1)
        throw std::string("readlink() failed");
    std::string str(buf);
    return str.substr(0, str.rfind('/'));
}

struct S {
public:
    float f = 12312.0000023f;
};

int main() {
    cout << getpath() << endl;

    unsigned int u = 12312U;
    float f = -1;
    S s;
    int i = static_cast<int>(s.f);
    cout<< (int) s.f / u  << endl;
}