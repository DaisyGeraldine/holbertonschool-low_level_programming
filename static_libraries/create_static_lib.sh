#!/bin/bash
ar -rc liball.a *.o
ar -t liball.a
ranlib liball.a
