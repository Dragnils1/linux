#! /bin/bash

# echo "name of file $0"

# echo "-----first part-----"

# echo "list dir with find:"
# find /proc/

# echo "ls /proc dir"
# ls -l /proc

# echo "Read file reversy"
# if [[ $1 ]]; then
#     rev $1
# else
#     echo No file entered
# fi

# echo "-----second part-----"

echo "CPU temperature:"
let "a = $(cat /sys/class/thermal/thermal_zone0/temp)"
let "temp = $a / 1000"
echo $temp 



