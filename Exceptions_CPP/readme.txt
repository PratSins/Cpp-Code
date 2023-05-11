Exception Handling
    + What is an Exception?
    + What is Exception Handling?
    + What do we throw and catch exceptions?
    + How does it affect flow of control?
    + Defining our own exception classes

    +The Standard Library Exception Hierarchy
        std::exception and what()

Best practice:
    + throw an object not a primitive type
    + throw an object by value
    + catch an object by reference (or const reference)


Basic concepts
    * Exception handling
        + dealing with extraordinary situations
        + indicates that an extraordinary situation has been detected or has occurred
        + program can deal with the extraordinary situations in a suitable manner

    * What causes exceptions?
        + insufficient resources
        + missing resources
        + invalid operations
        + range violations
        + underflows and overflows
        + Illegal data and many others

    * Exception safe
        + when your code handles exceptions


Terminology
    * Exception
        + an object or primitive type that signals that an error has occurred

    * Throwing an exception (raising an exception)
        + your code detects that an error has occurred or will occur
        + the place where the error occurred may not know how to handle the error
        + code can throw an exception describing the error to another part of the program that knows how to handle the error

    * Catching an exception (handle the exception)
        + code that handles the exception
        + may or may not cause the program to terminate

Keywords:
    try
    catch
    throw


Stack unwinding

    If an exception is thrown but not caught in the current scope
    C++ tries to find a handler for the exception by unwinding the stack

    + Function in which the exception was not caught terminates and is removed from the call stack
    + If a try block was used to then catch blocks are checked for a match
    + If no try block was used or the catch handler doesn’t match stack unwinding occurs again
    + If the stack is unwound back to main and no catch handler handles the exception the program terminates

Class-level exceptions - Exceptions can also be thrown from within a class:
    + Method
        * These work the same way as they do for functions as we've seen

    + Constructor
        * Constructors may fail
        * Constructors do not return any value
        * Throw an exception in the constructor if you cannot initialize an object

    + Destructor
        * Do NOT throw exceptions from your destructor


The C++ standard library exception class hierarchy

    C++ provides a class hierarchy of exception classes
        * std::exception is the base class
    all subclasses implement the what () virtual function
        * we can create our own user-defined exception subclasses

    virtual const char *what() const noexcept;


