#!/bin/bash

# qa : enter q
# :%s/<property>\n\s*<name>\(.*\)<\/name>\n\s*<value>\(.*\)<\/value>\n\s*<\/property>/\1=\2/g

# применяется ко всем строчкам 
# ищем совпадения 
# применяется глобально для каждого совпадения в строке 