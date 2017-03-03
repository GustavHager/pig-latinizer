# pig-latinizer
For the software development phd-course. An application to turn proper english into pig-latin.


## To download
git clone git@github.com:GustavHager/pig-latinizer.git
cd pig-latinizer
git submodule init
git submodule update

## To build and test

```bash
./build_test.sh
```

or to do it manually:

```bash
git submodule update --init --recursive
mkdir -p build && cd build && cmake .. && make
./translator_test
```

## Dependencies:
Google test (gtest)

## Project memebers:
* Gustav Häger
* Mattias Tiger
* Martin Danelljan
