#include <string>
#include <iostream>
#include "CreatePhoneNumber.h"

namespace CreatePhoneNumber {
	std::string createPhoneNumber(const int arr[10]) {
		std::string result = "(";

		for (int i = 0; i < 10; ++i) { 			
			result.append(std::to_string(arr[i]));

			if (i == 2)
				result.append(") ");
			else if (i == 5)
				result.append("-");
		}

		return result;
	}

	void run_tests() {
		struct TestCase {
			int testValue[10];
			std::string expected;
		};

		TestCase tests[] = {
			{{1, 2, 3, 4, 5, 6, 7, 8, 9, 0}, "(123) 456-7890"},
			{{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, "(111) 111-1111"},
			{{1, 2, 3, 4, 5, 6, 8, 8, 0, 0}, "(123) 456-8800"},
			{{0, 2, 3, 0, 5, 6, 0, 8, 9, 0}, "(023) 056-0890"},
			{{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, "(000) 000-0000"}
		};

		bool all_passed = true;

		for (const auto& test : tests) {
			std::string result = CreatePhoneNumber::createPhoneNumber(test.testValue);
			if (result == test.expected) {
				std::cout << "PASSED: createPhoneNumber(  " << test.expected << "  ) = "
					<< std::boolalpha << result << "\n";
			}
			else {
				std::cout << "FAILED: createPhoneNumber(  " << test.expected << "  ) = "
					<< std::boolalpha << result << "\n";
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