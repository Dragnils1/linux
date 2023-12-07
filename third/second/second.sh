#!/bin/bash


while getopts ":x:y:" option; do
    case "$option" in
        x) longitude="$OPTARG" ;;
        y) latitude="$OPTARG" ;;
        *) echo "Usage: $0 -x <longitude> -y <latitude>"
           exit 1 ;;
    esac
done

if [ -z "$longitude" ] || [ -z "$latitude" ]; then
    echo "Both -x and -y options are required."
    exit 1
fi

weather=$(curl -s "https://wttr.in/$latitude,$longitude?format=%C+%t")

echo "Weather at longitude $longitude and latitude $latitude: $weather"
