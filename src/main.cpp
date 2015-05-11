
#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <fstream>

#include "mlib/command_line_parser.hpp"

void compile(int64_t time_in_ms)
{
    time_in_ms = std::abs(time_in_ms);
    std::this_thread::sleep_for(std::chrono::milliseconds(time_in_ms));
}

void create_file(std::string filename)
{
    if (filename.empty() || filename == "") return;

    std::ofstream f(filename.c_str());
    f << " ";
    f.close();
}

const std::string keys
(
    "{ help h   |    | print this help information }"
    "{ :time t  | 25 | build time                  }"
    "{ :o       |    | create file                 }"
);

int main(int argc, char **argv)
{
    mlib::CommandLineParser parser(argc, argv, keys);
    parser.about("Fake Compiler v0.1");

    if (parser.has("help"))
    {
        parser.print_help();
        return 0;
    }

    std::string filename = parser.get<std::string>("o");
    int64_t time = parser.get<int64_t>("time");

    if (parser.is_error())
    {
        parser.print_errors();
        return 0;
    }

    create_file(filename);
    compile(time);

    return 0;
}
