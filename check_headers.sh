#!/bin/bash

# Function to check if a C++ header is self-contained
check_header() {
    header_file="$1"
    temp_dir=$(mktemp -d)

    # Create a temporary test program
    echo "#include \"$header_file\"" > "$temp_dir/test.cpp"

    # Try to compile the test program with proper include paths
    g++ -std=c++98 -I"$search_folder" -c "$temp_dir/test.cpp" -o "$temp_dir/test.o" > /dev/null 2>&1

    if [ $? -eq 0 ]; then
        echo "$header_file: Self-contained"
    else
        echo "$header_file: Not self-contained"
    fi

    # Clean up temporary files
    rm -r "$temp_dir"
}

# Main script

if [ $# -ne 1 ]; then
    echo "Usage: $0 <folder>"
    exit 1
fi

search_folder=$(realpath "$1")

if [ ! -d "$search_folder" ]; then
    echo "Error: $search_folder is not a valid directory."
    exit 1
fi

# Find all C++ header files and check them
find "$search_folder" -type f \( -name "*.h" -o -name "*.hpp" \) | while read -r header_file; do
    check_header "$header_file"
done
