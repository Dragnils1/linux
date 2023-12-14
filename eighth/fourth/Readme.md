
Я флагом линковщика -flto.  заменил  на
    -Db_lto=true указывает использовать флаг -flto для линковщика.


cpp_args = [ '-march=native -O3']
cpp_linker_args = ['-flto']

я отредактировал