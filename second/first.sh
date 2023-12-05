#! /bin/bash

dir="./png"

for file in $dir/*.png; do
    filename=$(basename "$file")
    filenamePNG=${filename//png/jpg}
    echo $filenamePNG
    convert $file $filenamePNG
    mv $filenamePNG ./jpg/$filenamePNG
    # mv $(convert $file $filename ) ./jpg
done