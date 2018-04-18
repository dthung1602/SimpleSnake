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

int main() {
    cout << getpath() << endl;
}