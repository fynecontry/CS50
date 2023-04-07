### Trie

A program which load a dataset file provided by the user of [150 most popular dog names](https://www.dailypaws.com/dogs-puppies/dog-names/common-dog-names) into memory using a trie data structure.

Program then prompts user for a dog name to check to see if it exists in the data structure.

#### Usage:
```
trie/ $ ./trie dog_names.txt
Check word: Roxy
Found!

trie/ $ ./trie dog_names.txt
Check word: Scott
Not Found.
```

#### Memory utilisation:
```
trie/ $ valgrind -s ./trie dog_names.txt
==19282== Memcheck, a memory error detector
==19282== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==19282== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==19282== Command: ./trie dog_names.txt
==19282==
Check word: Scott
Not Found.
==19282==
==19282== HEAP SUMMARY:
==19282==     in use at exit: 0 bytes in 0 blocks
==19282==   total heap usage: 561 allocs, 561 frees, 124,637 bytes allocated
==19282==
==19282== All heap blocks were freed -- no leaks are possible
==19282==
==19282== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```