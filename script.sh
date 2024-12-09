#!/bin/bash

MONITOR="/media/joaquin/usb"
ENCRYPT="/home/joaquin/Documents/final/SimpleLinuxDriver/encrypt"
DECRYPT="/home/joaquin/Documents/final/SimpleLinuxDriver/decrypt"
INOTIFYWAIT="/usr/bin/inotifywait"

$INOTIFYWAIT -m "$MONITOR" -e create -e moved_from |
while read -r directory event filename; do
    echo "File '$filename' was $event in $directory"
    
    full_file_path="$directory$filename"

    if [[ $event == "CREATE" ]]; then
        bash -c "$ENCRYPT $full_file_path; exec bash"
    fi

    if [[ $event == "MOVED_FROM" ]]; then
        bash -c "$DECRYPT $full_file_path; exec bash"
    fi
done
