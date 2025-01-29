#include "FindOutlier.h"
#include <vector>
#include <iostream>

namespace FindOutlier {
	int FindOutlier(std::vector<int> arr)
	{
		int even = 0;
		int odd = 0;

		for (auto digit : arr) {
			if (digit % 2)
				odd++;
			else
				even++;
		}

		for (auto digit : arr) {
			bool isOdd = (digit % 2);
			
			if (odd < even && isOdd)
				return digit;
			if (even < odd && !isOdd)
				return digit;
		}

		return 0;
	}

	void run_tests() {
		struct TestCase {
			const std::vector<int> testValues;
			const int expectedValue;
		};

		TestCase tests[] = {
			{{2,3,4}, 3},
			{{1,2,3}, 2},
			{{4,1,3,5,9}, 4}
		};

		bool all_passed = true;

		int testCount = 0;
		for (const auto& test : tests) {
			auto result = FindOutlier::FindOutlier(test.testValues);
			if (result == test.expectedValue) {
				std::cout << "PASSED: solution(  " << test.expectedValue << "  ) = " << result << "\r\n";
			}
			else {
				std::cout << "FAILED: solution(  " << test.expectedValue << "  ) = " << result << "\r\n";
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