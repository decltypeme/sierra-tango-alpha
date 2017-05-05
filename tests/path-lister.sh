cd netlist
chmod +x ../../bin/path-lister
for i in *.netlist.v ; do ../../bin/path-lister "$i" "../paths/$i.path";echo "Processsing file $i ..."; done

