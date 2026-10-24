FROM ubuntu:24.04

ENV DEBIAN_FRONTEND=noninteractive

RUN dpkg --add-architecture i386

RUN apt-get update && apt-get install -y \
    build-essential \
    ninja-build \
    python3 \
    python3-pip \
    python3-venv \
    git \
    rsync \
    binutils-mips-linux-gnu \
    libc6:i386 \
    libstdc++6:i386 \
    cmake \
    && rm -rf /var/lib/apt/lists/*


WORKDIR /workspace

COPY docker-entrypoint.sh /usr/local/bin/docker-entrypoint.sh
RUN chmod +x /usr/local/bin/docker-entrypoint.sh

ENTRYPOINT ["/usr/local/bin/docker-entrypoint.sh"]