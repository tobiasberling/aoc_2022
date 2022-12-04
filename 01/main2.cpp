#include <fmt/core.h>

#include <array>
#include <algorithm>
#include <string>
#include <functional>

#include "common/io.h"

const std::string fname = "c:/Projects/aoc_2022/01/test_input.txt";
// const std::string fname = "c:/Projects/aoc_2022/01/input.txt";

int main()
{
    // sorted top3 calories  [0] = min, [2] = max
    std::array<uint64_t, 3> top3_cals{0, 0, 0};
    uint64_t one_elf_cals = 0;

    for (const auto &line : MyFileLines{fname.c_str(), /*with_trailing_empty_line=*/ true})
    {
        if (line.empty())
        {
            if (one_elf_cals > top3_cals[0])
            {
                top3_cals[0] = one_elf_cals;
            }
            std::sort(top3_cals.begin(), top3_cals.end());
            one_elf_cals = 0;
        }
        else
        {
            one_elf_cals += std::stoull(line);
        }
    }
    fmt::print("{}\n", top3_cals[0] + top3_cals[1] + top3_cals[2]);
}