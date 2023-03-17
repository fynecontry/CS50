### Filter
A program which applies filters to BMP bitmap images by manuplating each RGB values of each pixel

#### Available filters
- Greyscale - converts an image to black and white by taking th average of the each RGB value.
- Reflection - converts an image to a mirrored version by moving pixels from left side of image to right and vice-versa.
- Blur - Softens the an image quality by taking each pixel and, for each color value, giving it a new value by averaging the color values of neighboring pixels.
- Edges - Detect edges in an image: lines in the image that create a boundary between one object and another using [The Sobel operator alogrithm](https://en.wikipedia.org/wiki/Sobel_operator).

#### Usage:
```
Usage: ./filter [flag] infile outfile

$ ./filter -g INFILE.bmp OUTFILE.bmp
$ ./filter -r INFILE.bmp OUTFILE.bmp
$ ./filter -b INFILE.bmp OUTFILE.bmp
$ ./filter -e INFILE.bmp OUTFILE.bmp
```
where `IMAGE.bmp` is the name of an image file and `OUTFILE.bmp` is the name given to an output image file.


#### Example output:
##### original image
![image](https://user-images.githubusercontent.com/27024731/225846358-9923a15c-2d07-48d7-8deb-ca7860b4b44f.png)

##### altered image
![image](https://user-images.githubusercontent.com/27024731/225846747-fc811513-32c5-400b-99c8-a893cff7bf1c.png)


#### Memory utilisation:
```
filter-more/ $ valgrind --leak-check=full --show-leak-kinds=all ./filter -e images/yard.bmp out.bmp
==2999== Memcheck, a memory error detector
==2999== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==2999== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==2999== Command: ./filter -e images/yard.bmp out.bmp
==2999==
==2999==
==2999== HEAP SUMMARY:
==2999==     in use at exit: 0 bytes in 0 blocks
==2999==   total heap usage: 6 allocs, 6 frees, 1,449,136 bytes allocated
==2999==
==2999== All heap blocks were freed -- no leaks are possible
==2999==
==2999== For lists of detected and suppressed errors, rerun with: -s
==2999== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
