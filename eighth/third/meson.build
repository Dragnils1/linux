# meson.build

project('unistdx', 'cpp', default_options : ['warning_level=3'])

cpp = meson.get_compiler('cpp')

executable(
  'unistdx',
  files('main.cc'),
  dependencies : [
    dependency('zlib')
  ],
  c_args : cpp.get_supported_arguments('-march=native -O3'),
  link_args : cpp.get_supported_link_arguments('-flto')
)
