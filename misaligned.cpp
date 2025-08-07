#include <iostream>
#include <assert.h>

int printColorMap(int &totalPairs) {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int count = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            std::cout << count << " | " << majorColor[i] << " | " << minorColor[j] << "\n";
            count++;
        }
    }
    totalPairs = count;
    return 0;  
}

void testPrintColorMap() {
    std::cout << "\nPrint color map test\n";
    int total = 0;
    int ret = printColorMap(total);
    
    assert(total == 25);
    assert(ret == 0);
    std::cout << "All is well (maybe!)\n";
}

int main() {
    testPrintColorMap();
    return 0;
}
