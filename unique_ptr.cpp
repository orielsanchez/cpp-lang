#include <algorithm>
#include <iostream>
#include <memory>
#include <print>

class UDT {
   public:
    UDT() { std::cout << "UDT Created" << std::endl; }
    ~UDT() { std::cout << "UDT Destroyed" << std::endl; }
};

int main()
{
    int x = 42;
    int* ptr = &x;

    std::println("*ptr = {}", *ptr);

    // raw pointers allow sharing but
    // allow room for errors:
    // forgetting to deallocate
    // who owns the pointer?
    int* ptr2 = ptr;
    std::println("*ptr2 = {}", *ptr2);

    // scoped smart pointer
    // allocated on heap with new
    // don't need to delete
    // it will delete itself when it leaves scope
    std::unique_ptr<UDT> oriel = std::unique_ptr<UDT>(new UDT);

    // Create an 'array' that is pointed to by one unique ptr (not preferred syntax)
    std::unique_ptr<UDT[]> oriel_array = std::unique_ptr<UDT[]>(new UDT[10]);

    // equivalent with preferred syntax
    // Note: make_unique uses design pattern: factory pattern
    std::unique_ptr<UDT[]> oriel_array2 = std::make_unique<UDT[]>(10);

    // Unique_ptr:
    // we cannot share (no copies allowed)
    // don't have to delete (deletes within block scope)
    //
    // allowed to transfer ownership (oriel is nulled out)
    std::unique_ptr<UDT> ben = std::move(oriel);
    std::cout << "oriel = " << oriel << std::endl;
    return 0;
}
