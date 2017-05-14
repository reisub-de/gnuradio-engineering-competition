correctly compile (With avx2 enabled, requires at least haswell processor, build-server uses -march=skylake)

CXXFLAGS="-march=haswell -mtune=haswell" cmake -DCMAKE_BUILD_TYPE=RelWithDebInfo ../
