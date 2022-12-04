#include "common/io.h"

#include <fmt/core.h>

#include <array>
#include <algorithm>
#include <string>
#include <vector>
#include <functional>
#include <set>
#include <cassert>

// const std::string fname = "c:/Projects/aoc_2022/03/test_input.txt";
const std::string fname = "c:/Projects/aoc_2022/03/input.txt";

int main()
{
    std::vector<char> char_intersection;

    uint64_t sum_prio = 0;

    for (const auto &line : MyFileLines{fname.c_str(), /*with_trailing_empty_line=*/false})
    {
        assert(!line.empty());
        std::string comp1 = line.substr(0, line.length() / 2);
        std::string comp2 = line.substr(line.length() / 2);

        std::sort(comp1.begin(), comp1.end());
        comp1.erase(std::unique(comp1.begin(), comp1.end()), comp1.end());
        std::sort(comp2.begin(), comp2.end());
        comp2.erase(std::unique(comp2.begin(), comp2.end()), comp2.end());

        char_intersection.clear();
        char_intersection.reserve(std::max(comp1.length(), comp2.length()));

        std::set_intersection(comp1.begin(), comp1.end(),
                              comp2.begin(), comp2.end(),
                              std::back_inserter(char_intersection));
        assert(char_intersection.size() == 1);
        int c = char_intersection[0];
        int prio = c > 'Z' ? c-'a' + 1 : c - 'A' + 1 + 26;

        assert(prio > 0);

        sum_prio += prio;

        // fmt::print("comp1={}   comp2={}   inter={}  prio={}\n", comp1, comp2, char_intersection[0], prio);
    }
    fmt::print("{}\n", sum_prio);
}