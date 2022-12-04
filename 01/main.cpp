#include <fmt/core.h>

#include <string>
#include <fstream>
#include <cassert>

// const std::string fname = "c:/Projects/aoc_2022/01/test_input.txt";
const std::string fname = "c:/Projects/aoc_2022/01/input.txt";

int main()
{
    std::ifstream f{fname.c_str()};
    assert(f.is_open());

    uint64_t max_cals = 0;
    uint64_t max_idx = 0;

    uint64_t counter = 0;
    uint64_t cals_sum = 0;
    std::string line;

    auto finishElf = [&]
    {
        fmt::print("cals_sum={:05} counter={}\n", cals_sum, counter);
        if (cals_sum > max_cals)
        {
            max_cals = cals_sum;
            max_idx = counter;
        }

        counter++;
        cals_sum = 0;
    };

    while (std::getline(f, line))
    {
        if (line.empty())
        {
            finishElf();
        }
        else
        {
            cals_sum += std::stoull(line);
        }
    }
    finishElf();

    fmt::print("max_cals={} max_idx={}\n", max_cals, max_idx);
}