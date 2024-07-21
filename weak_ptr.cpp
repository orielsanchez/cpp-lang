#include <iostream>
#include <memory>

class UDT {
   public:
    UDT() { std::println("UDT Created"); }
    ~UDT() { std::println("UDT Destroyed"); }
};

int main()
{
    // weak_ptr holds a non-owning reference to object of shared_ptr
    // does not increase reference count
    std::shared_ptr<UDT> ptr1 = std::make_shared<UDT>();

    std::println("Use count = {}", ptr1.use_count());
    {
        std::weak_ptr<UDT> ptr2 = ptr1;
        std::println("Use count = {}", ptr1.use_count());
    }

    std::println("Use count = {}", ptr1.use_count());

    // 'safer' way to have dangling pointers
    // a way to break cycles e.g. sp1 -> sp2 -> sp3 -> sp1

    return 0;
}
