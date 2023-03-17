### Recover
A program which recovers lost JPEG images from raw bytes file by using JPEG signature headers identifies.

Specifically, the first three bytes of JPEGs are:
`0xff 0xd8 0xff`

While the fourth byte, meanwhile, is either: `0xe0, 0xe1, 0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7, 0xe8, 0xe9, 0xea, 0xeb, 0xec, 0xed, 0xee, or 0xef`

#### How does recover work
Assuming file system is using FAT whose block size is 512 bytes. We read the raw file in chunks of 512 bytes, then check if it the start of a JPEG image and write to new file.
However if its not the start of a new JPEG file continue reading to opened file.

#### Usage:
```
Usage: $ ./recover card.raw
```
where `card.raw` is bytes file to recover images from.


#### Program's Memory utilisation:
```
recover/ $ valgrind --leak-check=full --show-leak-kinds=all -s ./recover card.raw 
==6188== Memcheck, a memory error detector
==6188== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==6188== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==6188== Command: ./recover card.raw
==6188== 
==6188== 
==6188== HEAP SUMMARY:
==6188==     in use at exit: 0 bytes in 0 blocks
==6188==   total heap usage: 104 allocs, 104 frees, 233,492 bytes allocated
==6188== 
==6188== All heap blocks were freed -- no leaks are possible
==6188== 
==6188== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```