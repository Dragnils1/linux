#!/bin/bash

# Task 2: Child processes
echo "Creating child process..."
pid=$(fork)

if [ $pid -eq 0 ]; then
    # Child process
    echo "Child process ID: $$"
    echo "Executing expr 2 + 2 * 2..."
    execlp "expr" "expr" "2" "+" "2" "*" "2"
else
    # Parent process
    echo "Parent process ID: $$"
    echo "Waiting for the child process to finish..."
    wait
    echo "Child process finished."
fi
