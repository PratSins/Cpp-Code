//   g++ -o a.exe polyp_08.cpp
//  .\a.exe


Smart Pointers    #include <memory>
    + Issues with raw pointers
    + What are smart pointers?
    + Concept of ownership and RAI!
    + C++ Smart Pointers
        + Unique pointers         (unique_ptr)
        + Shared pointers         (shared_ptr)
        + Weak pointers           (weak_ptr)
    + Custom deleters

Issues with Raw Pointers
    + C++ provides absolute flexibility with memory management
        * Allocation
        * Deallocation
        * Lifetime management

    + Some potentially serious problems
        * Uninitialized (wild) pointers
        * Memory leaks
        * Dangling pointers
        * Not exception safe

    + Ownership?
        * Who owns the pointer?
        * When should a pointer be deleted?

A simple example

{
    std::smart_pointer<Some Class> ptr = ...
    ptr->method();
    
    cout << (*ptr) << endl;
}

// ptr will be destroyed automatically when
// no longer needed


RAII - Resource Acquisition Is Initialization
    + Common idiom or pattern used in software design based on container object lifetime
    
    + RAII objects are allocated on the stack

    + Resource Acquisition
        * Open a file
        * Allocate memory
        * Acquire a lock

    + Is Initialization
        * The resource is acquired in a constructor

    + Resource relinquishing
        * Happens in the destructor
        * Close the file
        * Deallocate the memory
        * Release the lock
