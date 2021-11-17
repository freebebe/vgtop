#!/usr/bin/env bash

set -euo pipefail
( exec bwrap \
  --ro-bind "/usr/share" "/usr/share" \
  --ro-bind "/usr/lib" "/usr/lib" \
  --ro-bind "/usr/lib64" "/usr/lib64" \
  --tmpfs "/usr/lib/modules" \
  --tmpfs "/usr/lib/systemd" \
  --symlink "/usr/lib" "/lib" \
  --symlink "/usr/lib64" "/lib64" \
  --ro-bind "/usr/bin" "/usr/bin" \
  --symlink "/usr/bin" "/bin" \
  --symlink "/usr/bin" "/sbin" \
  --setenv "PATH" "/usr/bin" \
  --ro-bind "/etc/fonts" "/etc/fonts" \
  --ro-bind "/etc/resolv.conf" "/etc/resolv.conf" \
  --ro-bind "/etc/ssl" "/etc/ssl" \
  --ro-bind "/etc/ca-certificates" "/etc/ca-certificates" \
  --ro-bind "/etc/localtime" "/etc/localtime" \
  --ro-bind "$HOME/.nvim/plugged" "/home/de0013bian/.nvim/plugged" \
  --ro-bind "$HOME/box/.zshrc" "/home/de0013bian/.zshrc" \
  --ro-bind "$HOME/box/.tmux.conf" "/home/de0013bian/.tmux.conf" \
  --ro-bind "$HOME/box/.yarn" "/home/de0013bian/.yarn" \
  --ro-bind "$HOME/box/.local/share/nvim/site/autoload" "/home/de0013bian/.local/share/nvim/site/autoload" \
  --ro-bind "$HOME/box/machine-id" "/etc/machine-id" \
  --ro-bind "$HOME/.config/nvim" "/home/de0013bian/.config/nvim" \
  --ro-bind "$HOME/box/.local/share/nvim/rplugin.vim" "/home/de0013bian/.local/share/nvim/rplugin.vim" \
  --proc "/proc" \
  --dev "/dev" \
  --tmpfs "/tmp" \
  --tmpfs "/run" \
  --unsetenv "DBUS_SESSION_BUS_ADDRESS" \
  --setenv "HOME" "/home/de0013bian" \
  --setenv "USER" "/home/de0013bian" \
  --setenv "LOGNAME" "/home/de0013bian" \
  --bind "$HOME/ROM" "/home/de0013bian/build" \
  --ro-bind "$HOME/.config/yarn/" "/home/de0013bian/.config/yarn/" \
  --hostname "well" \
  --unshare-uts \
/bin/sh)
