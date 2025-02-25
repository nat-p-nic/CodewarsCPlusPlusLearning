#include "MovingZeroesToTheEnd.h"
#include <algorithm>
#include <vector>
#include <iostream>

namespace MovingZeroesToTheEnd {
	static std::vector<int> move_zeroes(const std::vector<int>& input) {
		int zeroCount = 0;
		std::vector<int> result;

		for (const auto& num : input) {
			if (num != 0)
				result.push_back(num);
			else
				zeroCount++;
		}

		for (int i = 0; i < zeroCount; ++i)
			result.push_back(0);

		return result;
	}

	// A better, production-like versions - thanks ChatGPT
	static std::vector<int> move_zeroes_better(const std::vector<int>& input) {
		std::vector<int> result;
		result.reserve(input.size()); // Avoid reallocations

		// Separate non-zero elements into result
		std::copy_if(input.begin(), input.end(), std::back_inserter(result), [](int num) { return num != 0; });

		// Fill remaining slots with zeros
		result.insert(result.end(), input.size() - result.size(), 0);

		return result;
	}

	void run_tests() {
		struct TestCase {
			const std::vector<int> testValues;
			const std::vector<int> expectedValues;
		};

		TestCase tests[] = {
			{{1, 2, 0, 1, 0, 1, 0, 3, 0, 1}, {1, 2, 1, 1, 3, 1, 0, 0, 0, 0}},
			{{0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}},
			{{1, 2, 5, 1, 5, 1, 5, 3, 2, 1 }, {1, 2, 5, 1, 5, 1, 5, 3, 2, 1}}
		};

		bool all_passed = true;

		int testCount = 0;
		for (const auto& test : tests) {
			auto result = MovingZeroesToTheEnd::move_zeroes(test.testValues);
			if (result == test.expectedValues) {
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