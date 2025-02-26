#include "DoesMyNumberLookBigInThis.h"
#include <cmath>
#include <iostream>
#include <sstream>

namespace DoesMyNumberLookBigInThis {
	bool narcissistic(int value) {
		std::string strValue = std::to_string(value);
		int valueLength = strValue.length();

		if (valueLength <= 1)
			return true;

		int total = 0;
		for (auto it = strValue.begin(); it != strValue.end(); ++it) {
			int digit = *it - '0';
			total += pow(digit, valueLength);
		}

		return (total == value);
	}

	void run_tests() {
		struct TestCase {
			int testValue;
			bool expectedValue;
		};

		TestCase tests[] = {
			{7, true},
			{371, true},
			{122, false},
			{4887, false},
			{153, true},
			{1938, false}
		};

		bool all_passed = true;

		int testCount = 0;
		for (const auto& test : tests) {
			auto result = DoesMyNumberLookBigInThis::narcissistic(test.testValue);
			if (result == test.expectedValue) {
				std::cout << "PASSED: solution(  " << testCount << "  ) = \r\n";
			}
			else {
				std::cout << "FAILED: solution(  " << testCount << "  ) = \r\n";
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