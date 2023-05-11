if ($?) { g++ stl_try.cpp -o a } ; if ($?) { .\a }    

The Standard Template Library
    * Generic programming/Meta-programming
        + Preprocessor macros
        + Function templates
        + Class templates
    * STL Containers
    * STL Iterators
    * STL Algorithms
    * Array
    * Vector
    * Deque
    * List and Forward List
    * Set and Multi Set
    * Map and Multi Map
    * Stack and Queue
    * Priority Queue
    * Algorithms


*Containers
    Collections of objects or primitive types
     (array, vector, deque, stack, set, map, etc.)

*Algorithms
    Functions for processing sequences of elements from containers
     (find, max, count, accumulate, sort, etc.)

*Iterators
    Generate sequences of element from containers
     (forward, reverse, by value, by reference, constant, etc.)


Sequence containers
    * array, vector, list, forward_list, deque

Associative containers
    * set, multi set, map, multi map

Container adapters
    * stack, queue, priority queue

Types of Iterators
    • Input iterators - from the container to the program
    • Output iterators - from the program to the container
    • Forward iterators - navigate one item at a time in one direction
    • Bi-directional iterators - navigate one item at a time both directions
    • Random access iterators - directly access a container item

Types of Algorithms
    • About 60 algorithms in the STL
    • Non-modifying
    • Modifying

Generic Programming with macros
    • Generic programming
        "Writing code that works with a variety of types as arguments,
        as long as those argument types meet specific syntactic and
        semantic requirements", Bjarne Stroustrup

    • Macros
    • Function templates
    • Class templates

What is a C++ Template?
    • Blueprint
    • Function and class templates
    • Allow plugging-in any data type
    • Compiler generates the appropriate function/class from the blueprint
    • Generic programming / meta-programming

Containers
    • Data structures that can store obiect of almost any type
        • Template-based classes

    • Each container has member functions
        • Some are specific to the container
        • Others are available to all containers

    • Each container has an associated header file
        • #include <container type>

Container elements
What types of elements can we store in containers?
    • A copy of the element will be stored in the container
        • All primitives OK
    • Element should be
        • Copyable and assignable (copy constructor / copy assignment)
        • Moveable for efficiency (move Constructor / move Assignment)
    • Ordered associative containers must be able to compare elem
        • operator‹, operator==


Iterators
    • Allows abstracting an arbitrary container as a sequence of elements
    • They are objects that work like pointers by design
    • Most container classes can be traversed with iterators

Declaring iterators
    •Iterators must be declared based on the container type they will iterate over
        container_type::iterator_type iterator_name;
    

    using namespace std;

    vector<int>::iterator itl;
    list<std::string>::iterator it2;
    map<std::string, std::string>::iterator it3;
    set<char>::iterator it4;


Algorithms --- #include <algorithm>
    • STL algorithms work on sequences of container elements provided to them by an iterator
    • STL has many common and useful algorithms

    • Too many to describe in this section
        • http://en.cppreference.com/w/cpp/algorithm
    
    • Many algorithms require extra information in order to do their
        • Functors (function objects)
        • Function pointers
        • Lambda expressions (C++11)

Iterator invalidation
    • Iterators point to container elements
    • It's possible iterators become invalid during processing

    • Suppose we are iterating over a vector of 10 elements
        • And we clear() the vector while iterating? What happens?
        • Undefined behavior - our iterators are pointing to invalid locations

std::list and std::forward_list
    • Sequence containers
    • Non-contiguous in memory
    • No direct access to elements
    • Very efficient for inserting and deleting elements once an element is found

The STL Set containers
    • Associative containers
        • Collection of stored objects that allow fast retrieval using a key
        • STL provides Sets and Maps
        • Usually implemented as a balanced binary tree or hashsets
        • Most operations are very efficient
    • Sets
        • std::set
        • std::unordered set
        • std::multiset
        • std::unordered multiset

std::set - common methods
    Person pl {"Larry", 18};
    Person p2 {"Moe", 25};

    std::set<Person> stooges;

    stooges.insert(p1); // adds p1 to the set
    auto result = stooges.insert(p2);   // adds p2 to the set


            • uses operator< for ordering!
            • returns a std: :pair<iterator, bool>
                • first is an iterator to the inserted element or to the duplicate
                • second is a boolean indicating success or failure


