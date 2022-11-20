#!/bin/bash
#SBATCH --job-name=dockF # nombre para identificar el trabajo. Por defecto es el nombre del script
#SBATCH --ntasks=24 # cantidad de cores pedidos
#SBATCH --tasks-per-node=24 # cantidad de cores por nodo, para que distribuya entre varios nodos
#SBATCH --output=%j.out # la salida y error estandar van a este archivo. Si no es especifca es slurm-%j.out (donde %j es el Job ID)
#SBATCH --error=%j.er # si se especifica, la salida de error va por separado a este archivo
#SBATCH --partition=internos
#SBATCH --mail-type=ALL
#SBATCH --mail-user=mcgpna@gmail.com
# aqui comienzan los comandos 
./vina_script_local.sh >cribadoFinal.log 


