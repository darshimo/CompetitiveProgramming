#!/bin/bash

if [ -z "$1" ]; then
    exit 1
fi

filename=$1

if [ ${filename##*.} != 'cpp' ]; then
    filename=${filename}.cpp
fi

if [ ! -e "./$filename" ]; then
    echo -e "#include <cstdio>\n\nint main(){\n    return 0;\n}" > $filename
fi

vim $filename
