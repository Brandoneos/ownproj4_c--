using namespace std;
#include "helper.h"
#include <map>
#include <set>
#include <vector>

int main() {
    libraryDatabase l1;
    int input = 0;
    while(input != 6) {
        prompt(input);
        l1.action(input);
    }
    ending();

    return 0;
}

