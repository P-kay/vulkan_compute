project('vulkan_compute', 'c')

cc = meson.get_compiler('c')
dep_m = cc.find_library('m', required : false)
dep_vulkan = cc.find_library('vulkan', required : false)

includes = include_directories('include')

main = executable('main',
    ['src/main.c'],
    link_with: [],
    include_directories: includes,
    dependencies: [dep_vulkan]
)
