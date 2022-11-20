#! /bin/bash

for f in $(ls ZINC*/out.pdbqt ); do
	b=$(dirname $f)
	cd $b
	obabel -i pdbqt out.pdbqt -o pdb $b.pdb -m
	cd ..
done
