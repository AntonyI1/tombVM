#!/bin/bash

VM_BIN=./build/tombVM
PROG_DIR=./tests/programs
EXPECT_DIR=./tests/expected

total=0
passed=0

for prog in $PROG_DIR/*.vmbin; do
    name=$(basename "$prog" .vmbin)
    expected="$EXPECT_DIR/$name.txt"

    echo -n "Test $name: "

    if ! [[ -f "$expected" ]]; then
        echo "✘ FAIL (missing expected output file)"
        ((total++))
        continue
    fi

    if ! output=$($VM_BIN "$prog" 2>/dev/null); then
        echo "✘ FAIL (runtime error)"
        ((total++))
        continue
    fi

    clean_output=$(echo "$output" | sed 's/[[:space:]]//g' | grep -v '^$')
    clean_expected=$(cat "$expected" | sed 's/[[:space:]]//g' | grep -v '^$')

    if [[ "$clean_output" == "$clean_expected" ]]; then
        echo "✔ PASS"
        ((passed++))
    else
        echo "✘ FAIL"
        echo "  Expected:"
        cat "$expected"
        echo "  Got:"
        echo "$output"
    fi

        ((total++))
done

echo "----------------------------"
echo "Tests passed: $passed/$total"
