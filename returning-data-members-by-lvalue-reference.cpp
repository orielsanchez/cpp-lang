#include <print>
#include <string>

class Employee {
  private:
    std::string m_name{};

  public:
    void setName(std::string_view name) { m_name = name; }
    const std::string &getName() const {
        return m_name; // getter returns by const reference
    }
};

int main() {
    Employee joe{};
    joe.setName("Joe");

    std::println("Employee name: {}", joe.getName());

    return 0;
}

// It's okay to return a  (const) lvalue to a data member.
// The implicit object (containing the data member)
// still exists in the scope of the called after the function returns,
// so any returned references will be valid.
