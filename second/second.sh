#! /bin/bash


sudo find /sys -name 'temp*input' > temp.txt

for word in $(cat temp.txt); do 
    output=$(cat $word)
    let "c = $output / 1000"
    echo $c
done


# ввести темературу