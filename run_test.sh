#!/bin/bash

# Find all executables in the current directory
executables=$(find . -maxdepth 1 -type f -executable)

# Run each executable and check for success
for exe in $executables; do
    echo "Running $exe..."
    ./$exe
    if [ $? -ne 0 ]; then
        echo "Test failed: $exe"
        exit 1
    fi
done

echo "All tests passed!"