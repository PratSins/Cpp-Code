unique ptr
    + Simple smart pointer - very efficient!

unique_ptr<T>
    * Points to an object of type T on the heap
    * It is unique - there can only be one unique_ptr<T> pointing to the object on the heap
    * Owns what it points to
    * Cannot be assigned or copied
    * CAN be moved
    * When the pointer is destroyed, what it points to is automatically destroyed


--unique ptr - creating, initializing and using
    {
        unique ptr<int> pl {new int {100} };
        cout << *pl << endl;       // 100

        *pl = 200;
        cout << *pl << endl;       // 200

    }           // automatically deleted

--unique ptr - some other useful methods
    {
        unique ptr<int> pl {new int {100} };

        cout << pl.get() << endl;       // 0x564388
        pl.reset();                     // pl is now nullptr

        if (pl)
            cout << *pl << endl;        // won't execute

    }                                   // automatically deleted

