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

const std::string fname = "c:/Projects/aoc_2022/04/test_input.txt";
// const std::string fname = "c:/Projects/aoc_2022/04/input.txt";

int main()
{
    uint64_t result = 0;

    for (const auto &line : MyFileLines{fname.c_str(), /*with_trailing_empty_line=*/false})
    {
        assert(!line.empty());
    }
    fmt::print("{}\n", result);
}