#!/bin/bash

# :%s/<property>\n\s*<name>\(.*\)<\/name>\n\s*<value>\(.*\)<\/value>\n\s*<\/property>/\1=\2/g