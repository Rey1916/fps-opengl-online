FROM gitpod/workspace-full

RUN sudo apt update && sudo apt install -y \
    build-essential \
    freeglut3-dev \
    libglm-dev
