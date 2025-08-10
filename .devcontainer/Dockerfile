FROM archlinux:base-devel

RUN pacman -Syu --noconfirm \
    cmake make git nano gdb valgrind \
    && pacman -Scc --noconfirm

RUN useradd -m -s /bin/bash devuser \
    && echo "devuser ALL=(ALL) NOPASSWD:ALL" >> /etc/sudoers

USER devuser
WORKDIR /home/devuser

SHELL ["/bin/bash", "-c"]

ENTRYPOINT ["/bin/bash"]
