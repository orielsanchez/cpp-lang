#pragma once

#include <string>
#include <string_view>

class Person {
  private:
    std::string m_name{};

  public:
    void kills(const Person &person) const;
    void setName(std::string_view name);
};
