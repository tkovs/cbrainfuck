What
--------
This is the project I chose to do just as a way to learn how to use git and github.

You can fork and pull request. You welcome!

Contributing
--------

As I do not have much experience with advanced C language, the code is easy to read and understand. So **anyone** can contribute, needs to know just how brainfuck works and the reasoning used to implement the interpreter.

```
1. Fork it.
2. Clone to your workstation.
3. Create a branch (`git checkout -b my_contribution`)
4. Commit your changes (`git commit -am "Added performance tester"`)
5. Push to the branch (`git push origin my_contribution`)
6. Open a Pull Request
7. Enjoy a refreshing Dollynho and wait.
```

How to use
--------

Need only the source and include folders in your project folder.
Add your program in your project folder.
In your code, reference the *include/cbrainfuck.h* file.
Create a text file with the brainfuck code.
Create a text file with content to be read when a comma is found in brainfuck code (or use */dev/stdin* in linux).

In your C code to call the interpreter function. The interpreter function returns a string with the result of the interpretation of brainfuck code. The interpreter function takes two parameters: the first is the address of the text file and the second the address of the input file (or */dev/stdin*).

A example:

```cpp
#include <stdio.h>
#include <stdlib.h>
#include "include/cbrainfuck.h"

// If the program was generated main.a, so
// $./main.a code.txt
int main(int argc, char ** argv) {
    char *s;
    s = interpreter(argv[1], argc>2?argv[2]:"/dev/stdin");

    if (_ERRORS_ > 0) {
        fprintf(stderr, "%s\n", _MESSAGE_);
        return 1;
    } else {
        printf ("%s", s);
        free(s);
    }

    return 0;
}
```