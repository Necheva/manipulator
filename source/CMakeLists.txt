set(project_name manipul_lib)
file(GLOB_RECURSE source_list "*.cpp")#ищем файлы глобально и рекурсивно,
#имя переменной к которой будут привязаны все cpp
file(GLOB_RECURSE include_list "../include/*.h")#ищем файлы глобально и рекурсивно,
#имя переменной к которой будут привязаны все h
add_library(${project_name} STATIC ${source_list} ${include_list})
#создали статическую библиотеку, указали файлы, которые будут линковаться к проекту
