#!/bin/bash

# Child process script for Task 4
if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <new_hostname>"
    exit 1
fi

new_hostname=$1

# Setting new hostname
sethostname "$new_hostname"

echo "Child process hostname: $(gethostname)"
