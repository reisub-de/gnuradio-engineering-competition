file(REMOVE_RECURSE
  "libvolk.pdb"
  "libvolk.so"
  "libvolk.so.1.3"
)

# Per-language clean rules from dependency scanning.
foreach(lang C)
  include(CMakeFiles/volk.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
