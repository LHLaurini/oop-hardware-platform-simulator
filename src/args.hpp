#pragma once

#include <filesystem>

struct Args
{
    Args();
    Args(int argc, char **argv);

    bool failed;

    bool debug = false;
    bool help = false;
    std::filesystem::path platform;
    int steps = -1;
    bool verbose = false;
};
