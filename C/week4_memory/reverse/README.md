### Reverse
A program which reverses a WAV file given by the user and create a new WAV file that contains the resulting reversed audio.

A WAV file is broken into three chunks. Each chunk has a few blocks of data inside of it as depicted by the diagram obtained from [WAVE PCM soundfile format](http://soundfile.sapp.org/doc/WaveFormat/)

![image](https://user-images.githubusercontent.com/27024731/226097295-a89250fe-feef-4225-8808-621d3e6b077e.png)

The first and second chunk contain metadata about the WAV file and format, whilst the third chunk contains the Audio data itself.

Recover works by seeking to the end of the third chunk of the input WAV file and writing backwards to an output WAVE.

#### Usage:
```
./reverse input.wav output.wav
```