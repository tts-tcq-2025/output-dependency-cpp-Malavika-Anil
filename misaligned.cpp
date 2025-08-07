#include <iostream>
#include <cassert>
#include <sstream>
#include <string>
#include <vector>

extern int printColorMap(); 

void testPrintColorMap() {
    std::cout << "\nPrint color map test\n";


    std::stringstream buffer;
    std::streambuf *orig = std::cout.rdbuf(buffer.rdbuf());

    int result = printColorMap();

    std::cout.rdbuf(orig);


    const std::vector<std::string> major = {"White","Red","Black","Yellow","Violet"};
    const std::vector<std::string> minor = {"Blue","Orange","Green","Brown","Slate"};

   
    std::string line;
    int lineCount = 0;
    while (std::getline(buffer, line)) {
        if (line.empty()) continue;
      
        int idx;
        char pipe;
        std::string maj, min;
        std::istringstream iss(line);
        iss >> idx >> pipe >> pipe >> maj >> pipe >> min;
       
        int i = idx / 5;
        int j = idx % 5;
        std::string expectedMaj = major[i];
        std::string expectedMin = minor[j];
       
        assert(maj == expectedMaj && "Major color mismatch");
        assert(min == expectedMin && "Minor color mismatch");
        lineCount++;
    }

   
    assert(lineCount == 25 && "Unexpected number of lines");
    assert(result == 25 && "Return value should be 25");

    std::cout << "All is well (maybe!)\n";
}
