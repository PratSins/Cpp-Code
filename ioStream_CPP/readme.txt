if ($?) { g++ x.cpp -o a } ; if ($?) { .\a }

Stream manipulators
    * Streams have useful member functions to control formatting
    * Can be used on input and output streams
    * The time of the effect on the stream varies

    * Can be used as member functions or as a manipulator
        cout.width (10);          // member function
        cout << std::setw(10);     // manipulator

Common stream manipulators
    + Boolean
        boolalpha, noboolalpha

    + Integer
        dec, hex, oct, showbase, noshowbase, showpos, noshowpos, uppercase, nouppercase

    + Floating point
        fixed, scientific, setprecision, showpoint, noshowpoint, showpos, noshowpos

    + Field width, justification and fill
        setw, left, right, internal, setfill

    + Others
        endl, flush, skipws, noskipws, ws

Default when displaying integer values is:
    * dec (base 10)
    * noshowbase - prefix used to show hexadecimal or octal
    * nouppercase - when displaying a prefix and hex values it will be lower case
    * noshowpos - no ‘+’ is displayed for positive numbers

Default when displaying floating point values is:
    * setprecision - number of digits displayed (6)
    * fixed - not fixed to a specific number of digits after the decimal point
    * noshowpoint - trailing zeroes are not displayed
    * nouppercase - when displaying in scientific notation
    * noshowpos - no ‘+’ is displayed for positive numbers

Default when displaying floating point values is:
    + setw - not set by default
    + left - when no field width, right - when using field width
    + fill - not set by default - blank space is used



Opening a file for reading with (fstream)
        std::fstream in_ file {"../myfile.txt", std::ios::in };

Open for reading in binary mode
        std::fstream in_file {"../myfile.txt", std::ios::in | std::ios::binary};


Opening a file for reading with (ifstream)
    std::ifstream in file {"../myfile.txt", Std: rios::in };

    std::ifstream in_file {"../myfile.txt"};

Open for reading in binary mode
    std::ifstream in_file {"../myfile.txt", std::ios::binary };
