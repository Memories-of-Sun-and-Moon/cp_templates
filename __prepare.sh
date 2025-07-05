sudo sysctl vm.mmap_rnd_bits=30
ulimit -s unlimited
./__build_gch.sh
