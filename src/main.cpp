
#include "args.hpp"
#include "platform.hpp"

#include <iostream>
#include <ranges>

int pmain(int argc, char **argv)
{
    Args args(argc, argv);

    if (args.failed)
    {
        return 1;
    }

    if (args.help)
    {
        return 0;
    }

    if (args.platform.empty())
    {
        throw std::runtime_error("no platform specified");
    }

    if (args.steps == -1)
    {
        throw std::runtime_error("number of steps unspecified");
    }

    Platform platform(args.platform);

    using std::views::iota;

    for ([[maybe_unused]] auto _ : iota(0, args.steps))
    {
        platform.simulate();
    }

    return 0;
}

int main(int argc, char **argv)
{
    try
    {
        return pmain(argc, argv);
    }
    catch (const std::exception &e)
    {
        std::cerr << argv[0] << ": " << e.what() << std::endl;
        return 1;
    }
}
