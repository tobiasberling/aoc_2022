#pragma once

#include <cassert>
#include <fstream>
#include <string>

struct LineIter
{
    explicit LineIter() = default;
    explicit LineIter(std::ifstream &f, bool with_trailing_empty_line) : fstream{&f}, with_trailing_empty_line_{with_trailing_empty_line}
    {
        is_end = false;
        std::getline(*fstream, line);
    }

    bool operator!=(const LineIter &other)
    {
        if (is_end && other.is_end)
        {
            return false;
        }
        return true;
    }

    const std::string &operator*()
    {
        return line;
    }
    LineIter &operator++()
    {
        if (fstream->eof())
        {
            // Always emit an empty line at the end
            if (with_trailing_empty_line_ && !line.empty())
            {
                line.clear();
            }
            else
            {
                is_end = true;
            }
        }
        else
        {
            if (!is_end)
            {
                std::getline(*fstream, line);
            }
        }
        return *this;
    }

    std::string line;
    std::ifstream *fstream = nullptr;
    bool is_end = true;
    bool with_trailing_empty_line_ = false;
};

struct MyFileLines
{
    explicit MyFileLines(const char *path, bool with_trailing_empty_line) : fstream{path}, with_trailing_empty_line_{with_trailing_empty_line}
    {
        assert(fstream.is_open());
    }

    auto begin() { return LineIter{fstream, with_trailing_empty_line_}; }
    auto end() { return LineIter{}; }
    std::ifstream fstream;
    bool with_trailing_empty_line_ = false;
};