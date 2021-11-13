#include "args.hpp"

#include <getopt.h>
#include <iostream>
#include <string>

Args::Args() = default;

Args::Args(int argc, char **argv)
{
    while (true)
    {
        static option longOptions[] = {
            {"debug", no_argument, 0, 0}, //
            {"help", no_argument, 0, 0},
            {"platform", required_argument, 0, 0},
            {"steps", required_argument, 0, 0},
            {"verbose", no_argument, 0, 0},
            {0, 0, 0, 0},
        };

        int optionIndex = 0;

        int c = getopt_long_only(argc, argv, "", longOptions, &optionIndex);
        if (c == -1)
            break;

        try
        {
            switch (c)
            {
            case 0:
                switch (optionIndex)
                {
                case 0: // debug
                    debug = true;
                    break;

                case 1: // help
                    help = true;
                    break;

                case 2: // platform
                    platform = optarg;
                    break;

                case 3: // steps
                    steps = std::stoi(optarg);
                    break;

                case 4: // verbose
                    verbose = true;
                    break;
                }
                break;

            case '?':
            default:
                failed = true;
                return;
            }
        }
        catch (const std::invalid_argument &)
        {
            throw std::runtime_error("argument is not a number");
        }
    }

    if (optind < argc)
    {
        throw std::runtime_error("unexpected extra command-line arguments");
    }

    failed = false;

    if (debug)
    {
        std::cout << "failed=" << failed << "\n";
        std::cout << "help=" << help << "\n";
        std::cout << "platform=" << platform << "\n";
        std::cout << "steps=" << steps << "\n";
        std::cout << "verbose=" << verbose << "\n";
    }

    if (help)
    {
        std::cout << argv[0] << "\n\noptions:\n"
                  << "  --help       displays this message\n"
                  << "  --platform   path to a platform description file\n"
                  << "  --steps      number of steps to simulate\n"
                  << "  --verbose    enable verbose output\n";
    }
}
