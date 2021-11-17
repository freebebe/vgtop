#!/usr/bin/env bash
set -euo pipefail
(
    exec bwrap \
     --ro-bind /usr/bin/ssh /usr/bin/ssh \
     --ro-bind /usr/share /usr/share \
     --ro-bind /usr/lib /usr/lib \
     --ro-bind /usr/lib64 /usr/lib64 \
     --symlink /usr/lib64 /lib64 \
     --tmpfs /usr/lib/modules \
     --tmpfs /usr/lib/systemd \
     --tmpfs /usr/lib/gcc \
     --proc /proc \
     --dev-bind /dev /dev \
     --ro-bind ~/.ssh/ ~/.ssh/ \
     --ro-bind /etc /etc \
     --chdir ~/ \
     --unsetenv MOZ_PLUGIN_PATH \
     --unsetenv DBUS_SESSION_BUS_ADDRESS \
     --unsetenv MAIL \
     --unsetenv DISPLAY \
     --setenv PATH /usr/bin \
     --unshare-pid \
     --unshare-uts \
     --unshare-cgroup \
     --seccomp 10 \
     /usr/bin/ssh "$@"
)
