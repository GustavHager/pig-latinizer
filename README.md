# pig-latinizer
For the software development phd-course. An application to turn proper english into pig-latin.


To download
git clone git@github.com:GustavHager/pig-latinizer.git
cd pig-latinizer
git submodule init
git submodule update

To build:
mkdir build && cd build && cmake .. && make

To run: (under build)
./translator

To test: (under build)
./translator_test


Dependencies:
Google test (gtest)


Project members:
* Gustav Häger
* Mattias Tiger
* Martin Danelljan
* Bertil Grelsson
