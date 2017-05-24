cd netlist
chmod +x ../../bin/*
for i in *.netlist.v ; 
		do ../../bin/path-lister "$i" "../lists/$i.list";
		../../bin/sta "../../lib/osu035-updated.lib" "$i" "../caps/$i.cap" "../constraints/$i.const" "../clk.txt" "../paths/$i.paths" "../violations/$i.violations";
		../../bin/violations "../../lib/osu035-updated.lib" "$i" "../caps/$i.cap" "../constraints/$i.const" "../clk.txt" "../paths/$i.paths" "../violations/$i.violations";
		echo "Processsing file $i ...";
		done

