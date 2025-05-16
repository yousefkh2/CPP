#!/bin/bash

# Colors for output
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m' # No Color

# Get directory of this script
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
# Fix the path to point to the executable in the parent directory
PROGRAM="../replace"

# Ensure program is compiled
if [ ! -f $PROGRAM ]; then
    echo -e "${RED}Error: Program not found. Compile it first with 'make'.${NC}"
    exit 1
fi

run_test() {
    test_name=$1
    filename=$2
    s1=$3
    s2=$4
    expected_result=$5

    echo -n "Running test: $test_name... "
    
    # Run the program
    output=$($PROGRAM "$filename" "$s1" "$s2" 2>&1)
    exit_code=$?
    
    # Check if the exit code matches expected result
    if [ $exit_code -eq $expected_result ]; then
        echo -e "${GREEN}PASSED${NC}"
        
        # If test should succeed, verify the replaced file exists
        if [ $expected_result -eq 0 ]; then
            if [ -f "$filename.replace" ]; then
                echo "   Output file created successfully."
                echo "   Original content: $(cat $filename)"
                echo "   Replaced content: $(cat $filename.replace)"
            else
                echo -e "${RED}   Output file not created!${NC}"
            fi
        else
            echo "   Error output: $output"
        fi
    else
        echo -e "${RED}FAILED${NC}"
        echo "   Expected exit code $expected_result, got $exit_code"
        echo "   Output: $output"
    fi
    
    # Clean up the output file
    rm -f "$filename.replace"
    echo ""
}

echo "===== RUNNING TESTS FOR STRING REPLACEMENT PROGRAM ====="

# Standard usage tests
run_test "Normal replacement" "$DIR/normal.txt" "hello" "world" 0
run_test "Empty file" "$DIR/empty.txt" "test" "replace" 0
run_test "Replace with empty string" "$DIR/normal.txt" "hello" "" 0
run_test "Special characters" "$DIR/special.txt" "***" "!!!" 0
run_test "Case sensitivity" "$DIR/normal.txt" "Hello" "Goodbye" 0
run_test "Multi-line file" "$DIR/multiline.txt" "line" "sentence" 0

# Error cases
run_test "Missing arguments" "$DIR/normal.txt" "" "" 1
run_test "Empty s1" "$DIR/normal.txt" "" "something" 1
run_test "Non-existent file" "nonexistent.txt" "hello" "world" 1

echo "===== ALL TESTS COMPLETED ====="
