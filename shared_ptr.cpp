#include <iostream>
#include <memory>  // shared_ptr

// Some User defined type
class UDT {
   public:
    UDT() { std::cout << "UDT Created" << std::endl; }

    ~UDT() { std::cout << "UDT Destroyed" << std::endl; }
};

int main()
{
    // Shared pointer helps us avoid calling new/delete
    // multiple pointers can point to a resource

    std::shared_ptr<UDT> ptr1 = std::make_shared<UDT>();

    std::println("Use count: {}", ptr1.use_count());

    {
        std::shared_ptr<UDT> ptr2 = ptr1;
        std::println("Use count: {}", ptr1.use_count());
    }  // ptr2 is freed here

    std::println("Use count: {}", ptr1.use_count());

    // Resource destroyed once all pointers go out of scope
    // Reference count keeping track of number of pointers by control block
    // Reference count is thread safe
    // can be cyclic (avoid)

    return 0;
}
