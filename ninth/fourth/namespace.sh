#!/bin/bash

# Task 4: Arguments and namespaces
if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <new_hostname>"
    exit 1
fi

new_hostname=$1

echo "Original hostname: $(gethostname)"

# Creating child process with clone
echo "Creating child process with new hostname: $new_hostname"
clone ./child_namespace.sh "$new_hostname"
