#!/bin/bash

get_term_size() {
    read -r LINES COLUMNS < <(stty size)
    echo $LINES $COLUMNS
}

clear  # clear terminal
get_term_size

## Create window borders
# top
counter="1"
COLUMNS=$(($COLUMNS - 2))
echo -n "╔"
while [ $counter -le $COLUMNS ]; do
    echo -n "═"
    counter=$(($counter + 1))
done
echo -n "╗"

# left
counter="1"
LINES=$(($LINES - 4))  # -4 because 2 corners and 2 lines for other output (top, bottom)
while [ $counter -le $LINES ]; do
    echo "║"
    #  && printf '%*s' VAR "║"
    counter=$(($counter + 1))
done

# bottom
counter="1"
echo -n "╚"
while [ $counter -le $COLUMNS ]; do
    echo -n "═"
    counter=$(($counter + 1))
done
echo -n "╝"
