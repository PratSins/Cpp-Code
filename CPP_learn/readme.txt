Lambda Expression
    The Structure of a Lambda Expression
        [] ( ) -> return type specifiers { };

    Simple stateless lambda expressions
        [] () { cout << "Hi"; } ();     // Displays Hi

        int × {10};
        [] (int x) { cout << x; } (100) ;       // Displays 100


    [=]         // Default capture by value      --- deprecated in c++20 FOR CLASSes only
    [&]         // Default capture by reference
    [this]      // Default capture this object by reference

---------------------------------------------------------------------------------------------------------------------
What is an enumeration?  - no type safety
    • A user-defined type that models a set of constant integral values

The Structure of an Enumeration
    enum enum-name: enumerator-type { };

