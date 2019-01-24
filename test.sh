#!/bin/sh


for i in 0 1 2
do
	echo "++++++++++++++++++++++++"
	echo "for map 0$i as player O"
	echo "++++++++++++++++++++++++"
	for b in 0 1 2 3 4 5 6 7 8 9
	do
	echo "\ntry $b as player O\n"
		./filler_vm -p1 ./mnishimo.filler  -p2 ./players/carli.filler -f ./maps/map0$i | grep "== "
	done
done

for i in 0 1 2
do
	echo "++++++++++++++++++++++++"
	echo "for map 0$i as player X"
	echo "++++++++++++++++++++++++"
	for b in 0 1 2 3 4 5 6 7 8 9
	do
	echo "\ntry $b as player X\n"
		./filler_vm -p2 ./mnishimo.filler  -p1 ./players/carli.filler -f ./maps/map0$i | grep "== "
	done
done
