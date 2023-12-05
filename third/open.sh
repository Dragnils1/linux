#! /bin/bash

mime_type=$(file -b --mime-type "$1")

case "$mime_type" in 
    "png") 
        program="gimp";;
    application/vnd.oasis.opendocument.*|application/msword)
        program="libreoffice";;
    video/*)
        program="mpv";;
    *)

        echo "don't work :)"
        exit 1;;
esac

"$program" "$1"