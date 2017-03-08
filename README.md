# pig-latinizer
For the software development phd-course. An application to turn proper english into pig-latin and the reverse.

``` bash
Usage: translator [options]
  -h, --help          Display this help text and exit. 
  -p, --parallel      Translate the words in parallel using one thread for each 
                      word. 
  -i, --inverse       Translate the words from pig-latin to english. 
  -f, --file-input    Use the file from the provided path as input. 
  -o, --file-output   Write result to specified path. 
```
  
To download:
git clone git@github.com:GustavHager/pig-latinizer.git
cd pig-latinizer
git submodule init
git submodule update

To build:
mkdir build && cd build && cmake .. && make

To run translator: (under build)
./translator and enter the text to be translated

To run inverse translator: (under build)
./inverse_translator and enter the text to be inversely translated

To test: (under build)
./translator_test

Dependencies:
Google test (gtest)

Project members:
* Gustav Häger
* Mattias Tiger
* Martin Danelljan
* Bertil Grelsson 
