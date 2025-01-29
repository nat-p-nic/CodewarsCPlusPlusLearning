#include "WhoLikesIt.h"
#include <vector>
#include <string>
#include <iostream>

namespace WhoLikesIt {
	std::string likes(const std::vector<std::string>& names)
	{
		int peopleCount = names.size();
		switch (peopleCount) {
			case 0:
				return "no one likes this";
				break;
			case 1:
				return names[0] + " likes this";
				break;
			case 2:
				return names[0] + " and " + names[1] + " like this";
				break;
			case 3:
				return names[0] + ", " + names[1] + " and " + names[2] + " like this";
				break;
			default:
				int peopleCountDiff = peopleCount - 2;
				return names[0] + ", " + names[1] + " and " + std::to_string(peopleCountDiff) + " others like this";
		}
	}

	void run_tests() {
		struct TestCase {
			const std::vector<std::string> testValues;
			const std::string expectedValues;
		};

		TestCase tests[] = {
			{{"Alex", "Jacob", "Mark", "Max", "Nathan"}, "Alex, Jacob and 3 others like this"},
			{{}, "no one likes this"},
			{{"Peter"}, "Peter likes this"},
			{{"Jacob", "Alex"}, "Jacob and Alex like this"},
			{{"Max", "John", "Mark"}, "Max, John and Mark like this"},
			{{"Alex", "Jacob", "Mark", "Max"}, "Alex, Jacob and 2 others like this"}
		};

		bool all_passed = true;

		int testCount = 0;
		for (const auto& test : tests) {
			auto result = WhoLikesIt::likes(test.testValues);
			if (result == test.expectedValues) {
				std::cout << "PASSED: solution(  " << test.expectedValues << "  ) = " << result << "\r\n";
			}
			else {
				std::cout << "FAILED: solution(  " << test.expectedValues << "  ) = " << result << "\r\n";
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