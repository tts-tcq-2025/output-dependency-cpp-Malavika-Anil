#include <iostream>
#include <vector>
#include <string>
#include <cassert>

std::vector<std::string> getColorMap() {
    static const std::vector<std::string> major = {"White","Red","Black","Yellow","Violet"};
    static const std::vector<std::string> minor = {"Blue","Orange","Green","Brown","Slate"};
    std::vector<std::string> map;
    map.reserve(25);

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            map.push_back(
                std::to_string(i * 5 + j) + " | " +
                major[i] + " | " + minor[j]
            );
        }
    }
    return map;
}

void testPrintColorMap() {
    std::cout << "\nPrint color map test\n";
    auto colorMap = getColorMap();
    assert(colorMap.size() == 25);

    // Spot-check a few entries to validate correctness
    assert(colorMap[0] == "0 | White | Blue");
    assert(colorMap[4] == "4 | White | Slate");
    assert(colorMap[5] == "5 | Red | Blue");
    assert(colorMap[24] == "24 | Violet | Slate");

    std::cout << "All is well (maybe!)\n";
}

int main() {
    testPrintColorMap();
    return 0;
}
