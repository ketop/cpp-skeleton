#include <gtest/gtest.h>
#include "Person.h"
#include "nlohmann/json.hpp"
#include "spdlog/spdlog.h"
#include <iostream>
#include <iomanip>
using json = nlohmann::json;
using namespace nlohmann::json_literals;
TEST(example, echo)
{
  char* leak = new char[64];
  Person ketop("ketop", "hahpkai@outlook.com", Gender::MALE, 31);
  json serKetop = ketop;
  for(auto it = serKetop.begin(); it != serKetop.end(); it++)
  {
    std::cout << it.key() << ":" << it.value() << std::endl;
  }
  for(auto it = serKetop.rbegin(); it != serKetop.rend(); ++it)
  {
    std::cout << it.key() << ":" << it.value() << std::endl;
  }
  for(auto it: serKetop.items())
  {
    std::cout << it.key() << "=" << it.value() << std::endl;
  }
  char* leak2 = new char[64];
  spdlog::info("{}", serKetop.dump(4));
  spdlog::info("{}", serKetop.flatten().dump(4));
  auto p = serKetop["/email"_json_pointer];
  std::cout << "use json_pointer:" <<   p << std::endl;
  ASSERT_STREQ("ketop", serKetop["name"].get<std::string>().c_str());
  ASSERT_EQ(Gender::MALE, serKetop["gender"].get<Gender>());
  ASSERT_STREQ("hello", "hello");
  ASSERT_STREQ(serKetop.value("job", "it").c_str(), "it");
}

TEST(nlohmanntest, test)
{
  json source = R"({"name":"ketop", "job":"software development", "company":"ZTE"})"_json;
  std::cout << source.dump(4) << std::endl;
  json patch = R"([{"op":"replace", "path":"/company", "value":"huawei"},{"op":"add", "path":"/years", "value":"5"}])"_json;
  json patched = source.patch(patch);
  char* leak3 = new char[64];
  std::cout << patched.dump(4) << std::endl;
  json adiff = json::diff(source, patched);
  std::cout << adiff.dump(4) << std::endl;
  std::cout << json::diff(patched, source).dump(4) << std::endl;
  std::cout << source.dump(4) << std::endl;
  source.merge_patch(patched);
  std::cout << source.dump(4) << std::endl;
  std::cout << std::setw(2) << source << std::endl;
}

