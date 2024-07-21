#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>

class Student {
   public:
    Student();
    ~Student();
    void printName();
    void setName(std::string name);

   private:
    std::string m_name;
};
#endif
