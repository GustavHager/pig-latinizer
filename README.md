# pig-latinizer
For the software development phd-course. An application to turn proper english into pig-latin and the reverse.
  
## To download:
``` bash
git clone git@github.com:GustavHager/pig-latinizer.git
cd pig-latinizer
git submodule init
git submodule update
```

## Required libraries: SFML, TGUI
* SFML: 2.3 or greater
* TGUI: 0.7.3

The dependencies can be installed on Ubuntu 16.04 by
``` bash
sudo apt-get install libsfml-dev

sudo add-apt-repository ppa:texus/tgui
sudo apt-get update
sudo apt-get install libtgui-dev
```
The graphics components will not be built if one of these (SFML,TGUI) are not found.

## To build:
mkdir build && cd build && cmake .. && make

## To run translator: (under build)
./translator and enter the text to be translated
``` bash
Usage: translator [options] 
  -h, --help          Display this help text and exit. 
  -p, --parallel      Translate the words in parallel using one thread for each 
                      word. 
  -i, --inverse       Translate the words from pig-latin to english. 
  -f, --file-input    Use the file from the provided path as input. 
  -o, --file-output   Write result to specified path. 
  -g, --graphical-user-interface
                      Start the GUI of the translator. 
```

## To run inverse translator: (under build)
./inverse_translator and enter the text to be inversely translated

## To test: (under build)
./translator_test

## Dependencies:
Google test (this is included as a subrepository)
SFML (for graphics)

## Project members:
* Gustav Häger
* Mattias Tiger
* Martin Danelljan
* Bertil Grelsson 
