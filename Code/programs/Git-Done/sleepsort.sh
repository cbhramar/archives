#!/bin/bash
function f() {
    sleep "$1" 
    echo "$1" 
} 
while [ -n "$1" ] 
do 
    f "$1" &     shift 
done 
wait

# This program was not written by me. I just found it a cool way to sort small numbers. 
# This is possibly one of the easiest method for sorting 
