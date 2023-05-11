shared_ptr
    + Provides shared ownership of heap objects

shared_ptr<T>
    + Points to an object of type T on the heap
    + It is not unique - there can many shared_ptrs pointing to the same object on the heap
    + Establishes shared ownership relationship
    + CAN be assigned and copied
    + CAN be moved
    + Doesn't support managing arrays by default
    + When the use count is zero, the managed object on the heap is destroyed


shared_ptr - creating, initializing and using
    {
        shared_ptr<int> pl {new int {100} };
        cout << *pl << endl;       // 100

        *pl = 200;
        cout << *pl << endl;     // 200
    }                           // automatically deleted


shared_ptr - some other useful methods
    {
                // use_count - the number of shared_ptr objects managing the heap object
        std::shared_ptr<int> pl {new int {100} };

        std::cout << pl.use_count () << std::endl;      // 1
        std::shared_ptr<int> p2 { pl };             // shared ownwership

        std::cout << pl.use_count () << std::endl;      // 2

        pl.reset();         // decrement the use_count; pl is nulled out
        std::cout << pl.use_count() << std::endl;       // 0

        std::cout << p2.use_count() << std::endl;       // 2

    }           // automatically deleted


