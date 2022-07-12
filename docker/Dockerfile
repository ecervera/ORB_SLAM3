FROM suminmin/orb-slam3

RUN apt-get update && \
    apt-get install -y \
    libusb-1.0-0-dev && \
    rm -rf /var/lib/apt/lists/*

RUN wget --no-check-certificate https://github.com/IntelRealSense/librealsense/archive/refs/tags/v2.50.0.tar.gz && \
    tar -xzf v2.50.0.tar.gz && \
    rm v2.50.0.tar.gz && \
    cd librealsense-2.50.0/ && \
    mkdir build && cd build && \
    cmake .. && \
    make && \
    make install

ADD https://api.github.com/repos/ecervera/ORB_SLAM3/git/refs/heads/master version.json

RUN cd /tmp/ORB_SLAM3 && \
    git remote set-url origin https://github.com/ecervera/ORB_SLAM3.git && \
    git pull

RUN cd /tmp/ORB_SLAM3 && \
    ./build.sh
