# Hashmap

A hashmap implementation using the Robert Jenkins' 32 bit mix function with Knuth's multiplicative method for hashing.

# Installation

* Install the library

`em list`
`em install`
`em build lib`

## Usage

* Include in a file

`touch test.c`
```c
#include "export/Hashmap.h"
int main(void) {
    hashmap *h = hashmap_new();

    hashmap_add(h, "one", (void*)1);
    hashmap_add(h, "value", (void*)"value");

    printf("%s\n", (char*)hashmap_get(h, "value"));
    printf("%ld\n", (long)hashmap_get(h, "one"));
}
```

* Compile

`clang test.c export/*.*o`

## Development

* Write tests

## Contributing

1. Fork it (<https://github.com/EmeraldsFramework/Hashmap/fork>)
2. Create your feature branch (`git checkout -b my-new-feature`)
3. Commit your changes (`git commit -am 'Add some feature'`)
4. Push to the branch (`git push origin my-new-feature`)
5. Create a new Pull Request

## Contributors

- [Oblivious](https://github.com/Oblivious-Oblivious) - creator and maintainer
