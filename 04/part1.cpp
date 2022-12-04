#include "common/io.h"

#include <fmt/core.h>

#include <algorithm>
#include <array>
#include <cassert>
#include <functional>
#include <numeric>
#include <set>
#include <string>
#include <vector>

// const std::string fname = "c:/Projects/aoc_2022/04/test_input.txt";
const std::string fname = "c:/Projects/aoc_2022/04/input.txt";

int main()
{
    uint64_t result = 0;

    for (const auto &line : MyFileLines{fname.c_str(), /*with_trailing_empty_line=*/false})
    {
        assert(!line.empty());
        int64_t start1=0, end1=0;
        int64_t start2=0, end2=0;
        sscanf(line.c_str(), "%lld-%lld,%lld-%lld", &start1, &end1, &start2, &end2);
        // fmt::print("{}\n", line);
        // fmt::print("{} {} {} {}\n", start1, end1, start2, end2);

        if (start1 <= start2 && end2 <= end1) {
            ++result;
        } else
        if (start2 <= start1 && end1 <= end2) {
            ++result;
        }
    }
    fmt::print("{}\n", result);
}