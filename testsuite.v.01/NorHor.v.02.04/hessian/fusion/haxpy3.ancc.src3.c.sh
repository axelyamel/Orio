#!/bin/bash
#PBS -l nodes=1
#PBS -l walltime=300:00:00
#PBS -j oe
#PBS -m abe
#PBS -N haxpy3.ancc.src3.c

cd $PBS_O_WORKDIR

orcc -v haxpy3.ancc.src3.c > haxpy3.ancc.src3.c.rs.data
