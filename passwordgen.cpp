//#include "passwordgen.h"
#include <iostream>
#include <random>

using namespace std;

int main() {
    random_device rd;
    mt19937 gen(rd());

    for (int i = 0; i < 5; i++) {
        cout << gen() << " ";
    }
    cout << endl;
    return 0;
}

