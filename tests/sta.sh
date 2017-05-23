cd netlist
chmod +x ../../bin/sta
for i in *.netlist.v ; do ../../bin/sta ../../lib/osu035-updated.lib "$i" "../caps/$i.cap" "../constraints/$i.const" "../clk.txt" "../reports/$i.txt";echo "Processsing file $i"; done
