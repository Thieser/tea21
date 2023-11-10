#include <fmt/chrono.h>
#include <fmt/format.h>

#include "CLI/CLI.hpp"
#include "config.h"

auto main(int argc, char **argv) -> int
{
    std::srand(std::time(nullptr));
    /**
     * CLI11 is a command line parser to add command line options
     * More info at https://github.com/CLIUtils/CLI11#usage
     */
    int count =20;
    CLI::App app{PROJECT_NAME};
    try
    {
        app.set_version_flag("-V,--version", fmt::format("{} {}", PROJECT_VER, PROJECT_BUILD_DATE));
        app.add_option("-c,--count", count, "Variable count");
        app.parse(argc, argv);
    }
    catch (const CLI::ParseError &e)
    {
        return app.exit(e);
    }
    fmt::print("Count: {}",count);
    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    fmt::print("Hello, {}!\n", app.get_name());
    std::vector<int> data(count);
    fmt::print("Created vector of size {} \n", data.size());
    /* INSERT YOUR CODE HERE */
    for (int i = 0; i < data.size(); i++)
    {
        data[i]=rand() %101;
        fmt::print("{}. \t{} \n",i+1 ,data[i]);
    }
    auto start = std::chrono::system_clock::now();
    /*for (int n = 0; n < data.size(); n++)
    {
        if (data[n]<=data[n-1])
        {
            int temp=data[n-1];
            data[n-1]=data[n];
            data[n]=temp;
            n=0;
        }
    }*/
    std::sort(data.begin(),data.end());
    auto end = std::chrono::system_clock::now();
    auto elapsed = end - start;
    fmt::print("_________________________\n");
    for (int i = 0; i < data.size(); i++)
    {
        fmt::print("{}. \t{} \n",i+1 ,data[i]);
    }
    fmt::print("Sorting took {}", elapsed);
    return 0; /* exit gracefully*/
}
