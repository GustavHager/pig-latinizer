# pig-latinizer
For the software development phd-course. An application to turn proper english into pig-latin and the reverse.

To download
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
