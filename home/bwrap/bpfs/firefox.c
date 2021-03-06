#include <stddef.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <seccomp.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <sys/mman.h>
#include <linux/shm.h>
#include <linux/random.h>
#include <linux/vt.h>

int main (void) {
  int rc = -1;
  scmp_filter_ctx ctx;
  int filter_fd;

  ctx = seccomp_init(SCMP_ACT_KILL);
  if (ctx == NULL) { goto out; }

  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(_llseek), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(_newselect), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(accept), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(accept4), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(access), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(alarm), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(arch_prctl), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(bind), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(brk), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(cacheflush), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(capget), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(capset), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(chdir), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(chmod), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(chown), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(chown32), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(chroot), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(clock_getres), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(clock_gettime), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(clock_nanosleep), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(clone), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(close), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(connect), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(copy_file_range), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(creat), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(dup), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(dup2), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(dup3), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(epoll_create), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(epoll_create1), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(epoll_ctl), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(epoll_pwait), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(epoll_wait), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(eventfd), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(eventfd2), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(execve), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(execveat), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(exit), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(exit_group), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(faccessat), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(fadvise64), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(fadvise64_64), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(fallocate), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(fanotify_mark), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(fchdir), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(fchmod), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(fchmodat), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(fchown), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(fchown32), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(fchownat), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(fcntl), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(fcntl64), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(fdatasync), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(fgetxattr), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(flistxattr), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(flock), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(fork), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(fremovexattr), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(fstat), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(fstat64), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(fstatat64), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(fstatfs), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(fstatfs64), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(fsync), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(ftruncate), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(ftruncate64), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(futex), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(futimesat), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(get_robust_list), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(get_thread_area), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(getcpu), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(getcwd), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(getdents), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(getdents64), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(getegid), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(getegid32), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(geteuid), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(geteuid32), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(getgid), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(getgid32), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(getgroups), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(getgroups32), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(getitimer), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(getpeername), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(getpgid), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(getpgrp), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(getpid), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(getppid), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(getpriority), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(getrandom), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(getresgid), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(getresgid32), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(getresuid), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(getresuid32), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(getrlimit), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(getrusage), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(getsid), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(getsockname), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(getsockopt), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(gettid), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(gettimeofday), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(getuid), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(getuid32), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(getxattr), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(inotify_add_watch), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(inotify_init), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(inotify_init1), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(inotify_rm_watch), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(ioctl), 1, SCMP_A1(SCMP_CMP_MASKED_EQ, 0xFFFFFFFFu, (int) FIOCLEX)) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(ioctl), 1, SCMP_A1(SCMP_CMP_MASKED_EQ, 0xFFFFFFFFu, (int) FIONBIO)) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(ioctl), 1, SCMP_A1(SCMP_CMP_MASKED_EQ, 0xFFFFFFFFu, (int) FIONREAD)) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(ioctl), 1, SCMP_A1(SCMP_CMP_MASKED_EQ, 0xFFFFFFFFu, (int) RNDGETENTCNT)) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(ioctl), 1, SCMP_A1(SCMP_CMP_MASKED_EQ, 0xFFFFFFFFu, (int) TCGETS)) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(ioctl), 1, SCMP_A1(SCMP_CMP_MASKED_EQ, 0xFFFFFFFFu, (int) TCSETS)) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(ioctl), 1, SCMP_A1(SCMP_CMP_MASKED_EQ, 0xFFFFFFFFu, (int) TCSETSW)) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(ioctl), 1, SCMP_A1(SCMP_CMP_MASKED_EQ, 0xFFFFFFFFu, (int) TIOCGPGRP)) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(ioctl), 1, SCMP_A1(SCMP_CMP_MASKED_EQ, 0xFFFFFFFFu, (int) TIOCGWINSZ)) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(ioctl), 1, SCMP_A1(SCMP_CMP_MASKED_EQ, 0xFFFFFFFFu, (int) TIOCSPGRP)) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(ioctl), 1, SCMP_A1(SCMP_CMP_MASKED_EQ, 0xFFFFFFFFu, (int) TIOCSWINSZ)) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(ioctl), 1, SCMP_A1(SCMP_CMP_MASKED_EQ, 0xFFFFFFFFu, (int) VT_GETSTATE)) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(ioprio_get), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(ipc), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(kill), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(lchown), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(lchown32), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(lgetxattr), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(link), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(linkat), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(listen), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(listxattr), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(llistxattr), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(lremovexattr), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(lseek), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(lsetxattr), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(lstat), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(lstat64), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(madvise), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(membarrier), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(memfd_create), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(mincore), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(mkdir), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(mkdirat), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(mknod), 1, SCMP_A1(SCMP_CMP_EQ, S_IFREG)) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(mknod), 1, SCMP_A1(SCMP_CMP_EQ, S_IFIFO)) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(mknod), 1, SCMP_A1(SCMP_CMP_EQ, S_IFSOCK)) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(mknodat), 1, SCMP_A1(SCMP_CMP_EQ, S_IFREG)) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(mknodat), 1, SCMP_A1(SCMP_CMP_EQ, S_IFIFO)) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(mknodat), 1, SCMP_A1(SCMP_CMP_EQ, S_IFSOCK)) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(mlock), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(mlock2), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(mlockall), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(mq_getsetattr), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(mq_notify), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(mq_open), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(mq_timedreceive), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(mq_timedsend), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(mq_unlink), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(mremap), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(msgctl), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(msgget), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(msgrcv), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(msgsnd), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(msync), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(munlock), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(munlockall), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(munmap), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(nanosleep), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(newfstatat), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(nice), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(oldfstat), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(oldlstat), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(oldolduname), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(oldstat), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(olduname), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(open), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(openat), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(pause), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(pipe), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(pipe2), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(pkey_alloc), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(pkey_free), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(poll), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(ppoll), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(prctl), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(pread64), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(preadv), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(preadv2), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(prlimit64), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(pselect6), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(pwrite64), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(pwritev), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(pwritev2), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(quotactl), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(read), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(readahead), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(readdir), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(readlink), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(readlinkat), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(readv), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(recv), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(recvfrom), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(recvmsg), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(recvmmsg), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(removexattr), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(rename), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(renameat), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(renameat2), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(restart_syscall), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(rmdir), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(rt_sigaction), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(rt_sigpending), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(rt_sigprocmask), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(rt_sigqueueinfo), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(rt_sigreturn), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(rt_sigsuspend), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(rt_sigtimedwait), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(rt_tgsigqueueinfo), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(s390_pci_mmio_read), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(s390_pci_mmio_write), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(s390_sthyi), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(sched_get_priority_max), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(sched_get_priority_min), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(sched_getaffinity), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(sched_getattr), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(sched_getparam), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(sched_getscheduler), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(sched_rr_get_interval), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(sched_setaffinity), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(sched_setattr), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(sched_setparam), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(sched_setscheduler), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(sched_yield), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(seccomp), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(select), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(semctl), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(semget), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(semop), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(semtimedop), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(send), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(sendfile), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(sendfile64), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(sendmmsg), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(sendmsg), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(sendto), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(set_robust_list), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(set_thread_area), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(set_tid_address), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(setfsgid), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(setfsgid32), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(setfsuid), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(setfsuid32), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(setgid), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(setgid32), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(setgroups), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(setgroups32), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(setitimer), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(setns), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(setpgid), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(setpriority), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(setregid), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(setregid32), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(setresgid), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(setresgid32), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(setresuid), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(setresuid32), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(setrlimit), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(setsid), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(setsockopt), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(setuid), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(setuid32), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(setxattr), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(shmctl), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(shmdt), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(shmget), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(shutdown), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(sigaction), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(sigaltstack), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(signal), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(signalfd), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(signalfd4), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(sigpending), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(sigprocmask), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(sigreturn), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(sigsuspend), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(socket), 1, SCMP_A0(SCMP_CMP_EQ, AF_INET)) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(socket), 1, SCMP_A0(SCMP_CMP_EQ, AF_INET6)) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(socket), 1, SCMP_A0(SCMP_CMP_EQ, AF_LOCAL)) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(socket), 1, SCMP_A0(SCMP_CMP_EQ, AF_NETLINK)) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(socket), 1, SCMP_A0(SCMP_CMP_EQ, AF_UNIX)) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(socket), 1, SCMP_A0(SCMP_CMP_EQ, AF_UNSPEC)) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(socketcall), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(socketpair), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(splice), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(spu_create), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(spu_run), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(stat), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(stat64), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(statfs), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(statfs64), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(statx), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(symlink), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(symlinkat), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(sync), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(sync_file_range), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(sync_file_range2), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(syncfs), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(sysinfo), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(tee), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(tgkill), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(time), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(timer_create), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(timer_delete), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(timer_getoverrun), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(timer_gettime), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(timer_settime), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(timerfd_create), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(timerfd_gettime), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(timerfd_settime), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(times), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(tkill), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(truncate), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(truncate64), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(ugetrlimit), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(umask), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(uname), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(unlink), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(unlinkat), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(unshare), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(utime), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(utimensat), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(utimes), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(vfork), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(wait4), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(waitid), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(waitpid), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(write), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(writev), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(mmap), 1, SCMP_A2(SCMP_CMP_EQ, PROT_NONE)) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(mmap), 1, SCMP_A2(SCMP_CMP_EQ, PROT_READ)) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(mmap), 1, SCMP_A2(SCMP_CMP_EQ, PROT_WRITE)) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(mmap), 1, SCMP_A2(SCMP_CMP_EQ, PROT_EXEC)) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(mmap), 1, SCMP_A2(SCMP_CMP_EQ, PROT_READ|PROT_EXEC)) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(mmap), 1, SCMP_A2(SCMP_CMP_EQ, PROT_READ|PROT_WRITE)) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(mmap2), 1, SCMP_A2(SCMP_CMP_EQ, PROT_NONE)) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(mmap2), 1, SCMP_A2(SCMP_CMP_EQ, PROT_READ)) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(mmap2), 1, SCMP_A2(SCMP_CMP_EQ, PROT_WRITE)) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(mmap2), 1, SCMP_A2(SCMP_CMP_EQ, PROT_EXEC)) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(mmap2), 1, SCMP_A2(SCMP_CMP_EQ, PROT_READ|PROT_EXEC)) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(mmap2), 1, SCMP_A2(SCMP_CMP_EQ, PROT_READ|PROT_WRITE)) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(mprotect), 1, SCMP_A2(SCMP_CMP_EQ, PROT_NONE)) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(mprotect), 1, SCMP_A2(SCMP_CMP_EQ, PROT_READ)) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(mprotect), 1, SCMP_A2(SCMP_CMP_EQ, PROT_WRITE)) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(mprotect), 1, SCMP_A2(SCMP_CMP_EQ, PROT_READ|PROT_WRITE)) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(pkey_mprotect), 1, SCMP_A2(SCMP_CMP_EQ, PROT_NONE)) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(pkey_mprotect), 1, SCMP_A2(SCMP_CMP_EQ, PROT_READ)) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(pkey_mprotect), 1, SCMP_A2(SCMP_CMP_EQ, PROT_WRITE)) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(pkey_mprotect), 1, SCMP_A2(SCMP_CMP_EQ, PROT_READ|PROT_WRITE)) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(shmat), 1, SCMP_A2(SCMP_CMP_EQ, 0)) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(shmat), 1, SCMP_A2(SCMP_CMP_EQ, SHM_RND)) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(shmat), 1, SCMP_A2(SCMP_CMP_EQ, SHM_RDONLY)) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(shmat), 1, SCMP_A2(SCMP_CMP_EQ, SHM_REMAP)) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(mmap), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(mmap2), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(mprotect), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(pkey_mprotect), 0) < 0) { goto out; }
  if (seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(shmat), 0) < 0) { goto out; }

  filter_fd = open("firefox_seccomp_filter.bpf", O_CREAT | O_WRONLY | O_TRUNC, 0644);
  if (filter_fd == -1) {
    rc = -errno;
    goto out;
  }
  rc = seccomp_export_bpf(ctx, filter_fd);
  if (rc < 0) {
    close(filter_fd);
    goto out;
  }
  close(filter_fd);

out:
  seccomp_release(ctx);
  return -rc;
}
