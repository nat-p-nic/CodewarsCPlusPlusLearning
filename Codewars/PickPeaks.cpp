#include "PickPeaks.h"
#include <algorithm>
#include <vector>
#include <iostream>

namespace PickPeaks {
	struct PeakData {
		std::vector<int> pos;
		std::vector<int> peaks;

		bool operator==(const PeakData& other) const {
			return pos == other.pos && peaks == other.peaks;
		}
	};
	
	PeakData pick_peaks(const std::vector<int>& v) {
		PeakData result;

		if (v.size() < 3) 
			return result;

		int peakCandidate = -1;
		for (size_t i = 1; i < v.size() - 1; i++) {
			if (v[i] > v[i - 1] && v[i] > v[i + 1]) {
				// Peak
				result.pos.push_back(i);
				result.peaks.push_back(v[i]);
			}
			else if (v[i] > v[i - 1] && v[i] == v[i + 1]) {
				// Start of plateau?
				peakCandidate = i;
			}
			else if (peakCandidate != -1 && v[i] > v[i + 1]) {
				// Plateau confirmed
				result.pos.push_back(peakCandidate);
				result.peaks.push_back(v[peakCandidate]);
				peakCandidate = -1;
			}
			else if (v[i] < v[i + 1]) {
				// Not a plateau
				peakCandidate = -1;
			}
		}

		return result;
	}

	void run_tests() {
		struct TestCase {
			std::vector<int> testValues; 
			PeakData expectedValues;
		};

		TestCase tests[] = {
			{{3, 2, 3, 6, 4, 1, 2, 3, 2, 1, 2, 3}, {{3, 7}, {6, 3}}},
			{{1, 2, 2, 2, 1}, {{1}, {2}}},
			{{1, 2, 2, 2, 3}, {{}, {}}}
		};

		bool all_passed = true;

		int testCount = 0;
		for (const auto& test : tests) {
			auto result = PickPeaks::pick_peaks(test.testValues);
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