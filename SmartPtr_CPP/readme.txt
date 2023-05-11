weak_ptr
    + Provides a non-owning “weak” reference

weak_ptr<T>
    + Points to an object of type T on the heap
    + Does not participate in owning relationship
    + Always created from a shared ptr
    + Does NOT increment or decrement reference use count
    + Used to prevent strong reference cycles which could prevent objects from being deleted


Custom deleters - Sometimes when we destroy a smart pointer we need more than to just destroy the object on the heap
    + These are special use-cases
    + C++ smart pointers allow you to provide custom deleters
        * Lots of way to achieve this
        * Functions
        * Lambdas
        * Others...

Custom deleters - EXAMPLES

    void my_deleter(Some_ Class *raw_pointer)
    {
        // your custom deleter code
        delete raw_pointer;
    }
    shared_ptr<Some_Class> ptr { new Some_class{}, my_deleter };
----------------------------------------------------------------------------
    void my_deleter(Test *ptr) 
    {
        cout << "In my custom deleter" << end;
        delete ptr;
    }
    shared_ptr<Test> ptr { new Test{}, my_deleter };
-----------------------------------------------------------------------------
    shared ptr<Test> ptr (new Test{100}, [] (Test *ptr) 
                {
                    cout << "\t Using my custom deleter" << endl;
                    delete ptr;

                });
-----------------------------------------------------------------------------

