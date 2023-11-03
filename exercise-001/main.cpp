#include <fmt/chrono.h>
#include <fmt/format.h>

#include <iostream>
#include <random>

#include "CLI/CLI.hpp"
#include "config.h"

auto main(int argc, char **argv) -> int
{
    //.data segment
    int data =4711;
    fmt::ptr(&data);    

    // .roaddata segment 
    int roaddata = 455;

    fmt::ptr(&roaddata);    

    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    int foo = 0;
    fmt::ptr(&foo);    
    
    fmt::print("Value of variable foo {} address of variable foo{}",foo,fmt::ptr(&foo));
    return 0; /* exit gracefully*/
}
