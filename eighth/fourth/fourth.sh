#!/bin/bash

git clone https://github.com/santiquin/unistdx.git
cd unistdx
meson setup build -Dbuildtype=release
cd build
meson compile

meson --buildtype=release --prefix=/usr -Db_ndebug=true -Dc_args='-march=native -O3' -Dcpp_args='-march=native -O3' -Dlink_args='-flto' ..

ninja

# optional
sudo ninja install
