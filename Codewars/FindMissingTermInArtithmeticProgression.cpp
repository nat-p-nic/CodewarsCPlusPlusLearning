#include "FindMissingTermInArithmeticProgression.h"
#include <vector>
#include <iostream>

namespace FindMissingTermInArithmeticProgression {
	static long findMissing(std::vector<long> list) {
		long targetDiff = (list.back() - list.front()) / (long)(list.size());
		
		for (std::size_t i = 0; i < list.size() - 1; ++i) {
			long diff = list[i + 1] - list[i];
			if (diff != targetDiff) {
				if (targetDiff < 0) {
					return list[i] + targetDiff;
				}
				else {
					return list[i + 1] - targetDiff;
				}
			}
		}

		return 0;
	}

	void run_tests() {
		struct TestCase {
			const std::vector<long> testValues;
			const long expectedValue;
		};

		TestCase tests[] = {
			{{1, 5, 7}, 3},
			{{1, 3, 5, 9, 11}, 7},
			{{-20, -15, -10, -5, 5}, 0},
			{{-20, -10, -6, -2}, -14}
		};

		bool all_passed = true;

		int testCount = 0;
		for (const auto& test : tests) {
			auto result = FindMissingTermInArithmeticProgression::findMissing(test.testValues);
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