#include <iostream>
#include <string>
#include <chrono>
#include "TimeCounter.h"
#include "spdlog/spdlog.h"
#include "nlohmann/json.hpp"
using json = nlohmann::json;


int main()
{
    START_COUNT_TIME;
    std::cout << "hello world" << std::endl;
    spdlog::info("hello {}", "main");
    json ext1 = json::parse(R"({"name":"ketop", "age":31, "gender":"male", "married":true})");
    spdlog::info("personal info: name:{}, age:{}, married:{}, gender:{}", ext1["name"].get<std::string>(), ext1["age"].get<int>(), ext1["married"].get<bool>(), ext1["gender"].get<std::string>());

    return 0;
}
