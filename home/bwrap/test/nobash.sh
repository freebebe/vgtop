#!/usr/bin/env bash

set -euxo pipefail
(exec bwrap \
      --ro-bind /usr /usr \
      --dir /tmp \
      --dir /var \
      --symlink ../tmp var/tmp \
      --proc /proc \
      --dev /dev \
      --ro-bind /etc/resolv.conf /etc/resolv.conf \
      --symlink /usr/lib /lib \
      --symlink /usr/lib64 /lib64 \
      --symlink /usr/bin /bin \
      --symlink /usr/sbin /sbin \
      --ro-bind /usr/bin /usr/bin \
      --ro-bind /usr/share /usr/share \
      --bind $HOME/.config/nvim /home/eys/.config/nvim \
      --ro-bind $HOME/.nvim/plugged /home/eys/.nvim/plugged \
      --ro-bind $HOME/box/.zshrc /home/eys/.zshrc \
      --ro-bind $HOME/box/.tmux.conf /home/eys/.tmux.conf \
      --ro-bind $HOME/box/.yarn /home/eys/.yarn \
      --ro-bind $HOME/box/.local/share/nvim/site/autoload /home/eys/.local/share/nvim/site/autoload \
      --ro-bind $HOME/box/.local/share/nvim/rplugin.vim /home/eys/.local/share/nvim/rplugin.vim \
      --ro-bind $HOME/box/machine-id /etc/machine-id \
      --bind $HOME/ROM /home/eys/work \
      --chdir / \
      --unshare-all \
      --share-net \
      --die-with-parent \
      --dir /run/user/$(id -u) \
      --hostname nozsh \
      --setenv HOME /home/eys \
      --setenv XDG_RUNTIME_DIR "/run/user/`id -u`" \
      --setenv PS1 "noFish " \
      --setenv "USER" "noFish" \
      --setenv "LOGNAME" "noFish" \
      --file 11 /etc/passwd \
      --file 12 /etc/group \
      /bin/sh) \
    11< <(getent passwd $UID 65534) \
    12< <(getent group $(id -g) 65534) \
