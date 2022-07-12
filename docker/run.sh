#!/bin/bash

docker run --privileged --rm -v /home/ecervera/Escritorio/SLAM/Maps:/Maps:rw -v /dev:/dev:ro -it robinlab/orb-slam3
