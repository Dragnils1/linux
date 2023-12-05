#!/bin/bash

# Task 3: Environment variables
echo "Environment variables with 'L':"
for var in $(printenv | grep 'L'); do
    echo "$var"
done
