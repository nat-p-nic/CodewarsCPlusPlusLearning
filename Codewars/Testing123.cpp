#include "Testing123.h"
#include <vector>
#include <string>
#include <iostream>
#include <sstream>

namespace Testing123 {
	std::vector<std::string> number(const std::vector<std::string> &lines)
	{
		std::vector<std::string> output;
		
		int lineNumber = 1;
		for (auto line : lines) {
			std::stringstream ss;
			ss << lineNumber << ": " << line;
			output.push_back(ss.str());
			lineNumber++;
		}

		return output;
	}

	void run_tests() {
		struct TestCase {
			const std::vector<std::string> testValues;
			const std::vector<std::string> expectedValues;
		};

		TestCase tests[] = {
			{{}, {}},
			{{"a", "b", "c"}, {"1: a", "2: b", "3: c"}}
		};

		bool all_passed = true;

		int testCount = 0;
		for (const auto& test : tests) {
			auto result = Testing123::number(test.testValues);
			if (result == test.expectedValues) {
				std::cout << "PASSED: solution(  " << testCount << "  ) = ";
			}
			else {
				std::cout << "FAILED: solution(  " << testCount << "  ) = ";
				all_passed = false;
			}

			testCount++;
		}

		if (all_passed) {
			std::cout << "All tests passed successfully!\n";
		}
		else {
			std::cout << "Some tests failed. Check the output above.\n";
		}
	}
}