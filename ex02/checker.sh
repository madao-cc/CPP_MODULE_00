#!/bin/bash

# Paths
EXEC=./ex02
REF_LOG=19920104_091532.log
MY_LOG=my_output.log
CLEAN_REF=clean_ref.log
CLEAN_MY=clean_my.log

# Colors
RED='\033[0;31m'
NC='\033[0m' # No Color

# Check if executable exists
if [ ! -x "$EXEC" ]; then
	echo -e "${RED}❌ Error: Executable '$EXEC' not found or not executable.${NC}"
	exit 1
fi

# Check if reference log exists
if [ ! -f "$REF_LOG" ]; then
	echo -e "${RED}❌ Error: Reference log '$REF_LOG' not found.${NC}"
	exit 1
fi

# 1. Run your executable and redirect output
$EXEC > $MY_LOG

# 2. Remove timestamps and destructor lines
sed -E 's/^\[[0-9_]+\] //' "$REF_LOG" | grep -v 'closed$' > "$CLEAN_REF"
sed -E 's/^\[[0-9_]+\] //' "$MY_LOG" | grep -v 'closed$' > "$CLEAN_MY"

# 3. Compare
echo "Comparing output ignoring timestamps and destructor lines..."

diff_output=$(diff -u "$CLEAN_REF" "$CLEAN_MY")

if [ $? -eq 0 ]; then
	echo -e "✅ Output matches reference (ignoring timestamps and destructors)"
else
	echo -e "${RED}❌ Output differs:${NC}"
	# Print diff with differences in red
	echo "$diff_output" | while IFS= read -r line; do
		if [[ "$line" =~ ^[\+\-] && ! "$line" =~ ^--- && ! "$line" =~ ^+++ ]]; then
			echo -e "${RED}$line${NC}"
		else
			echo "$line"
		fi
	done
fi

# 4. Clean up temporary files
rm -f "$MY_LOG" "$CLEAN_REF" "$CLEAN_MY"

