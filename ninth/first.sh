#!/bin/bash

# Task 1: System calls
echo "Executing getpid using getpid wrapper: $(getpid)"
echo "Executing getpid using syscall wrapper: $(syscall 20)"
