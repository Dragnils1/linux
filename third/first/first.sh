#!/bin/bash

if [ $# -eq 0 ]; then
    echo "Usage: $0 <file>"
    exit 1
fi

file_path="$1"
mime_type=$(file -b --mime-type "$file_path")

case "$mime_type" in 
    "image/jpeg") 
        program="gimp";;
    "application/pdf")
        program="libreoffice";;
    "application/vnd.oasis.opendocument.*|application/msword")
        program="libreoffice";;
    video/*)
        program="mpv";;
    *)

        echo "Unsupported file type: $mime_type"
        exit 1;;
esac

echo "Opening $file_path with $program"
"$program" "$file_path"
