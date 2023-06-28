#!/bin/sh

set -xe

clang -Wall -Wextra -o neuron neuron.c -lm
clang -Wall -Wextra -o gates gates.c -lm
clang -Wall -Wextra -o xor xor.c -lm
