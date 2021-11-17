#!/usr/bin/env bash
set -euo pipefail
(
    exec bwrap \
     --ro-bind /usr/bin/apulse /usr/bin/apulse \
     --ro-bind /usr/bin/sh /usr/bin/sh \
     --ro-bind /usr/share /usr/share/ \
     --ro-bind /usr/lib /usr/lib \
     --ro-bind /usr/lib64 /usr/lib64 \
     --symlink /usr/lib64 /lib64 \
     --symlink /usr/lib /lib \
     --symlink /usr/bin /bin \
     --symlink /usr/bin /sbin \
     --proc /proc \
     --dev /dev \
     --dev-bind /dev/snd /dev/snd \
     --ro-bind /etc/passwd /etc/passwd \
     --ro-bind /etc/group /etc/group \
     --ro-bind /etc/hostname /etc/hostname \
     --ro-bind /etc/hosts /etc/hosts \
     --ro-bind /etc/localtime /etc/localtime \
     --ro-bind /etc/nsswitch.conf /etc/nsswitch.conf \
     --ro-bind /etc/resolv.conf /etc/resolv.conf \
     --ro-bind /etc/xdg /etc/xdg \
     --ro-bind /etc/gtk-2.0 /etc/gtk-2.0 \
     --ro-bind /etc/gtk-3.0 /etc/gtk-3.0 \
     --ro-bind /etc/fonts /etc/fonts \
     --ro-bind /etc/mime.types /etc/mime.types \
     --ro-bind /etc/pulse /etc/pulse \
     --ro-bind /etc/asound.conf /etc/asound.conf \
     --tmpfs /run \
     --bind ~/.mozilla ~/.mozilla \
     --bind ~/.cache/mozilla ~/.cache/mozilla \
     --bind ~/Downloads ~/Downloads \
     --chdir ~/ \
     --unsetenv DBUS_SESSION_BUS_ADDRESS \
     --setenv MOZ_ENABLE_WAYLAND 1 \
     --unshare-user-try \
     --unshare-pid \
     --unshare-uts \
     --unshare-cgroup-try \
     --new-session \
     --seccomp 10 \
     apulse /usr/lib/firefox/firefox
)

# note: running firefox on wayland like this should make a complete sandbox


# -ro-bind /etc/alsa /etc/alsa \

# todo:

#      --ro-bind /usr/share/locale /usr/share/locale \
#      --ro-bind /usr/share/X11 /usr/share/X11 \
#      --ro-bind /usr/share/gtk-3.0 /usr/share/gtk-3.0 \
#      --ro-bind /usr/share/fonts /usr/share/fonts \
#      --ro-bind /usr/share/ca-certificates /usr/share/ca-certificates \
#      --ro-bind /usr/share/icons /usr/share/icons \
#      --ro-bind /usr/share/pixmaps /usr/share/pixmaps \
#      --ro-bind /usr/share/mime /usr/share/mime \
#      --ro-bind /usr/share/applications /usr/share/applications \
#      --ro-bind /usr/share/glib-2.0 /usr/share/glib-2.0 \
#      --bind /var/cache/fontconfig 
