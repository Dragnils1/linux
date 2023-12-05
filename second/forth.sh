#! /bin/bash

prcess_id=$!

# find ./png/*.png & 
echo "PID: $process_id"


dir="./png"


process_file() {
    file="$1"
    
    filename=$(basename "$file")
    filenamePNG=${filename//png/jpg}
    convert $file $filenamePNG
    mv $filenamePNG ./jpg/$filenamePNG
    
    echo "File $filenamePNG converted." 
}

async_process() {
    while IFS= read -r -d $dir file; do
        process_file "$file" &
    done
    wait
    echo "Все файлы обработаны."
}

# //TODO доделать https://courses.igankevich.com/linux-programming/notes/shell/

find ./png/*.png -type f -print0 | async_process

# wait $process_id
# echo "Exit status:: $?"