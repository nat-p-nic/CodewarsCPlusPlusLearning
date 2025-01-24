#include <algorithm>
#include <iostream>
#include <vector>
#include "Same.h"

namespace Same {
    static bool comp(std::vector<int> a, std::vector<int> b) {
        // Mine - failed
        /*if (a.size() != b.size() || a.empty() || b.empty())
            return false;

        for (auto& num : a) 
            num *= num;

        std::sort(a.begin(), a.end());
        std::sort(b.begin(), b.end());

        return a == b;*/

        // Best
        for (auto& v : a) {
            v = v * v;
        }
        std::sort(a.begin(), a.end());
        std::sort(b.begin(), b.end());
        return a == b;
    }

    void run_tests()
    {
        std::vector<int> a;
        std::vector<int> b;

        a = { 121, 144, 19, 161, 19, 144, 19, 11 };
        b = { 14641, 20736, 361, 25921, 361, 20736, 361, 121 };
        Same::do_test(a, b, true);

        a = { 121, 144, 19, 161, 19, 144, 19, 11 };
        b = { 132, 14641, 20736, 361, 25921, 361, 20736, 361 };
        Same::do_test(a, b, false);
    }
    
    void do_test(std::vector<int> a, std::vector<int> b, bool sol)
    {
        bool ans = Same::comp(a, b);
        if (ans == sol)
            printf("    OK : Same::comp - ans: %d, sol: %d\r\n", ans, sol);
        else
            printf("FAILED : Same::comp - ans: %d, sol: %d\r\n", ans, sol);
    }
}