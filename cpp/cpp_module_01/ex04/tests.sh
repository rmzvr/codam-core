#!/bin/bash
set -e  # exit if any command fails

REPLACE_BIN=./replace
TEST_DIR=tests
RESULT_DIR=results

mkdir -p "$RESULT_DIR"

# Map: filename → target → replacement
declare -A targets
declare -A replacements

targets["empty.txt"]="a"
replacements["empty.txt"]="b"

targets["long_text.txt"]="at"
replacements["long_text.txt"]="____AT_____"

targets["matches_with_newlines.txt"]="s1 and s2.

It"
replacements["matches_with_newlines.txt"]="STRING1 and STRING 2.
"

targets["multiple_matches.txt"]="a"
replacements["multiple_matches.txt"]="B"

targets["no_matches.txt"]="user"
replacements["no_matches.txt"]="USER"

targets["one_match.txt"]="program"
replacements["one_match.txt"]="PROGRAM"

targets["only_newlines.txt"]="a"
replacements["only_newlines.txt"]="b"

targets["replace_with_newlines.txt"]="and
two strings"
replacements["replace_with_newlines.txt"]="only



one string"

for file in "$TEST_DIR"/*.txt; do
    filename=$(basename "$file")
    target=${targets[$filename]}
    replacement=${replacements[$filename]}

    if [ -z "$target" ] || [ -z "$replacement" ]; then
        echo "⚠ No mapping for $filename — skipping"
        continue
    fi

    echo "Processing $filename: replace '$target' → '$replacement'"
    "$REPLACE_BIN" "$file" "$target" "$replacement"

    # Move the .replace output to results folder
    mv "${file}.replace" "$RESULT_DIR/${filename}.replace"
done

echo "✅ All done. Results in $RESULT_DIR"
