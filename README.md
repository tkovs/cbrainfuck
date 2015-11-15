cbrainfuck
=====
[![Build Status](https://travis-ci.org/tkovs/cbrainfuck.svg?branch=master)](https://travis-ci.org/tkovs/cbrainfuck)
[![Issues](https://img.shields.io/github/issues/tkovs/cbrainfuck.svg)](https://github.com/tkovs/cbrainfuck/issues)
[![Licence](https://img.shields.io/badge/licence-MIT-red.svg?style=flat)](LICENSE)

`cbrainfuck` is a brainfuck interpreter written in C

> Detail: This is the project I chose to do just as a way to learn how to use git and github, so all I want to test about project management tools and git/github I will do here

## Example

```cpp
#include <stdio.h>
#include <stdlib.h>

#include "include/cbrainfuck.h"

// argv[1] should be the cbrainfuck code file
// argv[2] should be the input file
int main(int argc, char **argv) {
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

[Some sources](http://esoteric.sange.fi/brainfuck/)

## Licence

Copyright (c) 2015 Vitor Rodrigues (tkovs)

Released under the [MIT licence](https://github.com/tkovs/cbrainfuck/blob/master/LICENCE)