#! /bin/bash

for f in $(ls ZINC*.pdbqt); do
	nombre_lig=$(basename $f .pdbqt)
	echo Procesando el ligando $nombre_lig
	mkdir ${nombre_lig}
	vina --config conf.txt --ligand $f --out ${nombre_lig}/out.pdbqt --log ${nombre_lig}/log.txt
done

