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

    uint64_t sum_prio = 0;

    MyFileLines lines{fname.c_str(), /*with_trailing_empty_line=*/false};
    auto &&it = lines.begin();
    auto &&end = lines.end();

    while (it != end)
    {
        std::string elf1 = *it;
        ++it;
        assert(!elf1.empty());

        std::string elf2 = *it;
        ++it;
        assert(!elf2.empty());

        std::string elf3 = *it;
        ++it;
        assert(!elf3.empty());

        auto uniquify = [](auto &value)
        {
            std::sort(value.begin(), value.end());
            value.erase(std::unique(value.begin(), value.end()), value.end());
        };

        uniquify(elf1);
        uniquify(elf2);
        uniquify(elf3);

        std::vector<char> char_intersection;
        char_intersection.reserve(std::max({elf1.size(), elf2.size(), elf3.size()}));

        std::set_intersection(elf1.begin(), elf1.end(),
                              elf2.begin(), elf2.end(),
                              std::back_inserter(char_intersection));
        
        std::vector<char> char_intersection2;
        char_intersection2.reserve(2);

        std::set_intersection(char_intersection.begin(), char_intersection.end(),
                              elf3.begin(), elf3.end(),
                              std::back_inserter(char_intersection2));
        assert(char_intersection2.size() == 1);
        int c = char_intersection2[0];
        int prio = c > 'Z' ? c - 'a' + 1 : c - 'A' + 1 + 26;

        assert(prio > 0);

        sum_prio += prio;

        fmt::print("inter={}  prio={}\n", char_intersection2[0], prio);
    }
    fmt::print("{}\n", sum_prio);
}