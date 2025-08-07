#include <iostream>
#include <cassert>
#include <sstream>
#include <string>
#include <vector>

extern int printColorMap();

void testPrintColorMap() {
    std::cout << "\nPrint color map test\n";
    std::stringstream buffer;
    auto* orig = std::cout.rdbuf(buffer.rdbuf());

    int result = printColorMap();

    std::cout.rdbuf(orig);

    const std::vector<std::string> major = {"White", "Red", "Black", "Yellow", "Violet"};
    const std::vector<std::string> minor = {"Blue", "Orange", "Green", "Brown", "Slate"};

    std::string line;
    int count = 0;
    while (std::getline(buffer, line)) {
        if (line.empty()) continue;
        std::istringstream iss(line);
        int idx;
        std::string maj, min;
        char sep1, sep2;
        
        bool ok = (iss >> idx >> sep1 >> sep2 >> maj >> sep1 >> min);
        assert(ok && "Line parsing failed");

        int i = idx / 5;
        int j = idx % 5;
        assert(maj == major[i] && "Major color mismatch");
        assert(min == minor[j] && "Minor color mismatch");

        ++count;
    }

    assert(count == 25 && "Unexpected total line count");
    assert(result == 25 && "Return value should be 25");

    std::cout << "All is well (maybe!)\n";
}
