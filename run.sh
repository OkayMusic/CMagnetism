#! /usr/bin/env bash

mate-terminal -x bash -c \
"echo 'magnetic simulation running'; build/a.out; read -n1"

mate-terminal -x bash -c \
"echo 'simulation plotter running'; src/plot.py; read -n1"