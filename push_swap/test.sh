#!/bin/bash

# Function to run a test case
run_test() {
  echo "Running: $1"
  output=$($1 2>&1) # Capture the output
  if [ "$output" == "$2" ]; then
    echo "PASS"
  elif [ -z "$output" ] && [ "$2" == "No output" ]; then
    echo "PASS"
  else
    echo "FAIL"
    echo "Expected: $2"
    echo "Got: $output"
  fi
  echo
}

# Valid input cases (expect no output)
run_test "./push_swap 1 3 5 +9 20 -4 50 60 04 08" "No output"
run_test "./push_swap \"3 4 6 8 9 74 -56 +495\"" "No output"
run_test "./push_swap 2147483647 2 4 7" "No output"
run_test "./push_swap \"1 2 4 3\" 76 90 \"348 05\"" "No output"

# Invalid input cases (expect "Error")
run_test "./push_swap 1 3 dog 35 80 -3" "Error"
run_test "./push_swap a" "Error"
run_test "./push_swap 54867543867438 3" "Error"
run_test "./push_swap 1 3 58 9 3" "Error"
run_test "./push_swap 3 03" "Error"
run_test "./push_swap -2147483647765 4 5" "Error"
