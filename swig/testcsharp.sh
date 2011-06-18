#!/bin/bash
set -e

test -f test.exe && rm test.exe && echo rm test.exe

echo \
gmcs test.cs -r:csharp/csexodus
gmcs test.cs -r:csharp/csexodus

echo \
env LD_LIBRARY_PATH=csharp env MONO_PATH=csharp ./test.exe
env LD_LIBRARY_PATH=csharp env MONO_PATH=csharp ./test.exe
