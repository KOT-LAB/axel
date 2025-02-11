#!/bin/bash
# Format all C/C++ source and header files in the project

DIRECTORIES=("firmware" "examples" "tests")

for DIR in "${DIRECTORIES[@]}"; do
    if [ -d "$DIR" ]; then
        echo "Formatting files in $DIR..."
        find "$DIR" -type f \( -name "*.cpp" -o -name "*.h" -o -name "*.hpp" -o -name "*.c" \) -exec clang-format -i {} +
    else
        echo "Directory $DIR does not exist. Skipping."
    fi
done

echo "Code formatting completed!"





