#include <fmt/core.h>

#include <array>
#include <algorithm>
#include <string>
#include <functional>

#include "common/io.h"

// const std::string fname = "c:/Projects/aoc_2022/02/test_input.txt";
const std::string fname = "c:/Projects/aoc_2022/02/input.txt";

int main()
{
    uint64_t total_score = 0;
    for (const auto &line : MyFileLines{fname.c_str(), /*with_trailing_empty_line=*/false})
    {
        assert(!line.empty());

        // A X Rock      1p
        // B Y Paper     2p
        // C Z Scissors  3p
        int op = line[0] - 'A';
        int me = line[2] - 'X';

        //  -1 = loss, 0 = draw, 1 = win
        int result = ((me - op + 1 + 3) % 3) - 1;

        int score_choice = me + 1;
        int score_result = (result + 1) * 3;
        int score = score_choice + score_result;

        total_score += score;

        // fmt::print("op={}  me={}  res={}         score_choice={}  score_result={}  score={}\n",
        //            op, me,
        //            result,
        //            score_choice, score_result, score);
    }
    fmt::print("{}\n", total_score);
}