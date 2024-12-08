#!/bin/bash

# Directory to monitor
MONITOR="/mnt"

# Your compiled C program to trigger
ENCRYPT="/home/joaquin/Documents/final/SimpleLinuxDriver/encrypt"

# Use inotifywait to monitor for 'create' and 'modify' events
inotifywait -m "$MONITOR" -e create,modify |
while read -r directory event filename; do
    echo "File '$filename' was $event in $directory"
    # Trigger your C program and pass the full file path as an argument
    "$ENCRYPT" "$directory$filename"
done
