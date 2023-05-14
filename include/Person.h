#pragma once
#include <string>
#include "nlohmann/json.hpp"
using std::string;
using json = nlohmann::json;
enum class Gender {
  MALE,
  FEMALE
};

NLOHMANN_JSON_SERIALIZE_ENUM(Gender, {
    {Gender::MALE, "male"},
    {Gender::FEMALE, "female"}
    })

class Person
{
  public:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Person, name, email, gender, age);
    
    Person(const string& name_, const string& email_, Gender gender_, uint8_t age_ )
      :name(name_),email(email_),gender(gender_),age(age_)
    {}
    ~Person()=default;
    string name;
    string email;
    Gender gender; 
    uint8_t age;
};
