#!/bin/bash
SCRIPT_PATH=$(dirname $(realpath -s $0))
pushd "$SCRIPT_PATH" >/dev/null
echo in path `pwd`
git submodule update --init --recursive
mkdir -p "$SCRIPT_PATH/build"
pushd "$SCRIPT_PATH/build" >/dev/null
echo in path `pwd`
cmake .. && make && ./translator_test
test_exit_code=$?
popd >/dev/null
popd >/dev/null
exit "$test_exit_code"
