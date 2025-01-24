#include <iostream>
#include "Triangle.h"

namespace Triangle {
    bool isTriangle(int a, int b, int c) {
        return a > 0 && b > 0 && c > 0 &&
            a + b > c && a + c > b && b + c > a;
    }

    void run_tests() {
        struct TestCase {
            int a, b, c;
            bool expected;
        };

        TestCase tests[] = {
            {0, 0, 0, false},
            {0, 1, 2, false},
            {-17, 15, 20, false},
            {-17, -15, 20, false},
            {15, 17, 20, true},
            {10, 10, 10, true},
            {10, 5, 10, true},
            {3, 2, 1, false},
            {10, 10, 20, false}
        };

        bool all_passed = true;

        for (const auto& test : tests) {
            bool result = Triangle::isTriangle(test.a, test.b, test.c);
            if (result == test.expected) {
                std::cout << "PASSED: isTriangle(" << test.a << ", " << test.b << ", " << test.c << ") = "
                    << std::boolalpha << result << "\n";
            }
            else {
                std::cout << "FAILED: isTriangle(" << test.a << ", " << test.b << ", " << test.c << ") = "
                    << std::boolalpha << result << " (Expected: " << test.expected << ")\n";
                all_passed = false;
            }
        }

        if (all_passed) {
            std::cout << "All tests passed successfully!\n";
        }
        else {
            std::cout << "Some tests failed. Check the output above.\n";
        }
    }
}