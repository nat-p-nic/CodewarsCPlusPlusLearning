#include <string>
#include <set>
#include <iostream>
#include <algorithm>
#include <cctype>
#include "DisemvowelTrolls.h"

namespace DisemvowelTrolls {
	std::string disemvowel(const std::string& str) {
		
		const std::set<char> vowels = { 'A', 'E', 'I', 'O', 'U' };
		
		std::string result;

		for (auto it = str.begin(); it != str.end(); ++it) {
			char c = std::toupper(*it);
			if (vowels.find(c) == vowels.end()) {
				result += *it;
			}
		}

		return result;
	}

	void run_tests() {
		struct TestCase {
			std::string testValue;
			std::string expected;
		};

		TestCase tests[] = {
			{"This website is for losers LOL!", "Ths wbst s fr lsrs LL!"}
		};

		bool all_passed = true;

		for (const auto& test : tests) {
			std::string result = DisemvowelTrolls::disemvowel(test.testValue);
			if (result == test.expected) {
				std::cout << "PASSED: solution(  " << test.expected << "  ) = " << test.testValue << " "
					<< std::boolalpha << result << "\n";
			}
			else {
				std::cout << "FAILED: solution(  " << test.expected << "  ) = " << test.testValue << " "
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