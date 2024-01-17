
typedef long unsigned int size_t;
typedef __builtin_va_list __gnuc_va_list;
typedef unsigned char __u_char;
typedef unsigned short int __u_short;
typedef unsigned int __u_int;
typedef unsigned long int __u_long;
typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef signed short int __int16_t;
typedef unsigned short int __uint16_t;
typedef signed int __int32_t;
typedef unsigned int __uint32_t;
typedef signed long int __int64_t;
typedef unsigned long int __uint64_t;
typedef __int8_t __int_least8_t;
typedef __uint8_t __uint_least8_t;
typedef __int16_t __int_least16_t;
typedef __uint16_t __uint_least16_t;
typedef __int32_t __int_least32_t;
typedef __uint32_t __uint_least32_t;
typedef __int64_t __int_least64_t;
typedef __uint64_t __uint_least64_t;
typedef long int __quad_t;
typedef unsigned long int __u_quad_t;
typedef long int __intmax_t;
typedef unsigned long int __uintmax_t;
typedef unsigned long int __dev_t;
typedef unsigned int __uid_t;
typedef unsigned int __gid_t;
typedef unsigned long int __ino_t;
typedef unsigned long int __ino64_t;
typedef unsigned int __mode_t;
typedef unsigned long int __nlink_t;
typedef long int __off_t;
typedef long int __off64_t;
typedef int __pid_t;
typedef struct {
  int __val[2];
} __fsid_t;
typedef long int __clock_t;
typedef unsigned long int __rlim_t;
typedef unsigned long int __rlim64_t;
typedef unsigned int __id_t;
typedef long int __time_t;
typedef unsigned int __useconds_t;
typedef long int __suseconds_t;
typedef long int __suseconds64_t;
typedef int __daddr_t;
typedef int __key_t;
typedef int __clockid_t;
typedef void *__timer_t;
typedef long int __blksize_t;
typedef long int __blkcnt_t;
typedef long int __blkcnt64_t;
typedef unsigned long int __fsblkcnt_t;
typedef unsigned long int __fsblkcnt64_t;
typedef unsigned long int __fsfilcnt_t;
typedef unsigned long int __fsfilcnt64_t;
typedef long int __fsword_t;
typedef long int __ssize_t;
typedef long int __syscall_slong_t;
typedef unsigned long int __syscall_ulong_t;
typedef __off64_t __loff_t;
typedef char *__caddr_t;
typedef long int __intptr_t;
typedef unsigned int __socklen_t;
typedef int __sig_atomic_t;
typedef struct {
  int __count;
  union {
    unsigned int __wch;
    char __wchb[4];
  } __value;
} __mbstate_t;
typedef struct _G_fpos_t {
  __off_t __pos;
  __mbstate_t __state;
} __fpos_t;
typedef struct _G_fpos64_t {
  __off64_t __pos;
  __mbstate_t __state;
} __fpos64_t;
struct _IO_FILE;
typedef struct _IO_FILE __FILE;
struct _IO_FILE;
typedef struct _IO_FILE FILE;
struct _IO_FILE;
struct _IO_marker;
struct _IO_codecvt;
struct _IO_wide_data;
typedef void _IO_lock_t;
struct _IO_FILE {
  int _flags;
  char *_IO_read_ptr;
  char *_IO_read_end;
  char *_IO_read_base;
  char *_IO_write_base;
  char *_IO_write_ptr;
  char *_IO_write_end;
  char *_IO_buf_base;
  char *_IO_buf_end;
  char *_IO_save_base;
  char *_IO_backup_base;
  char *_IO_save_end;
  struct _IO_marker *_markers;
  struct _IO_FILE *_chain;
  int _fileno;
  int _flags2;
  __off_t _old_offset;
  unsigned short _cur_column;
  signed char _vtable_offset;
  char _shortbuf[1];
  _IO_lock_t *_lock;
  __off64_t _offset;
  struct _IO_codecvt *_codecvt;
  struct _IO_wide_data *_wide_data;
  struct _IO_FILE *_freeres_list;
  void *_freeres_buf;
  size_t __pad5;
  int _mode;
  char _unused2[15 * sizeof(int) - 4 * sizeof(void *) - sizeof(size_t)];
};
typedef __gnuc_va_list va_list;
typedef __off_t off_t;
typedef __ssize_t ssize_t;
typedef __fpos_t fpos_t;
extern FILE *stdin;
extern FILE *stdout;
extern FILE *stderr;
extern int remove(const char *__filename)
    __attribute__((__nothrow__, __leaf__));
extern int rename(const char *__old, const char *__new)
    __attribute__((__nothrow__, __leaf__));
extern int renameat(int __oldfd, const char *__old, int __newfd,
                    const char *__new) __attribute__((__nothrow__, __leaf__));
extern int fclose(FILE *__stream);
extern FILE *tmpfile(void) __attribute__((__malloc__))
__attribute__((__malloc__(fclose, 1)));
extern char *tmpnam(char[20]) __attribute__((__nothrow__, __leaf__));
extern char *tmpnam_r(char __s[20]) __attribute__((__nothrow__, __leaf__));
extern char *tempnam(const char *__dir, const char *__pfx)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__malloc__))
    __attribute__((__malloc__(__builtin_free, 1)));
extern int fflush(FILE *__stream);
extern int fflush_unlocked(FILE *__stream);
extern FILE *fopen(const char *__restrict __filename,
                   const char *__restrict __modes) __attribute__((__malloc__))
__attribute__((__malloc__(fclose, 1)));
extern FILE *freopen(const char *__restrict __filename,
                     const char *__restrict __modes, FILE *__restrict __stream);
extern FILE *fdopen(int __fd, const char *__modes)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__malloc__))
    __attribute__((__malloc__(fclose, 1)));
extern FILE *fmemopen(void *__s, size_t __len, const char *__modes)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__malloc__))
    __attribute__((__malloc__(fclose, 1)));
extern FILE *open_memstream(char **__bufloc, size_t *__sizeloc)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__malloc__))
    __attribute__((__malloc__(fclose, 1)));
extern void setbuf(FILE *__restrict __stream, char *__restrict __buf)
    __attribute__((__nothrow__, __leaf__));
extern int setvbuf(FILE *__restrict __stream, char *__restrict __buf,
                   int __modes, size_t __n)
    __attribute__((__nothrow__, __leaf__));
extern void setbuffer(FILE *__restrict __stream, char *__restrict __buf,
                      size_t __size) __attribute__((__nothrow__, __leaf__));
extern void setlinebuf(FILE *__stream) __attribute__((__nothrow__, __leaf__));
extern int fprintf(FILE *__restrict __stream, const char *__restrict __format,
                   ...);
extern int printf(const char *__restrict __format, ...);
extern int sprintf(char *__restrict __s, const char *__restrict __format, ...)
    __attribute__((__nothrow__));
extern int vfprintf(FILE *__restrict __s, const char *__restrict __format,
                    __gnuc_va_list __arg);
extern int vprintf(const char *__restrict __format, __gnuc_va_list __arg);
extern int vsprintf(char *__restrict __s, const char *__restrict __format,
                    __gnuc_va_list __arg) __attribute__((__nothrow__));
extern int snprintf(char *__restrict __s, size_t __maxlen,
                    const char *__restrict __format, ...)
    __attribute__((__nothrow__)) __attribute__((__format__(__printf__, 3, 4)));
extern int vsnprintf(char *__restrict __s, size_t __maxlen,
                     const char *__restrict __format, __gnuc_va_list __arg)
    __attribute__((__nothrow__)) __attribute__((__format__(__printf__, 3, 0)));
extern int vdprintf(int __fd, const char *__restrict __fmt,
                    __gnuc_va_list __arg)
    __attribute__((__format__(__printf__, 2, 0)));
extern int dprintf(int __fd, const char *__restrict __fmt, ...)
    __attribute__((__format__(__printf__, 2, 3)));
extern int fscanf(FILE *__restrict __stream, const char *__restrict __format,
                  ...);
extern int scanf(const char *__restrict __format, ...);
extern int sscanf(const char *__restrict __s, const char *__restrict __format,
                  ...) __attribute__((__nothrow__, __leaf__));
extern int fscanf(FILE *__restrict __stream, const char *__restrict __format,
                  ...) __asm__(""
                               "__isoc99_fscanf");
extern int scanf(const char *__restrict __format,
                 ...) __asm__(""
                              "__isoc99_scanf");
extern int sscanf(const char *__restrict __s, const char *__restrict __format,
                  ...) __asm__(""
                               "__isoc99_sscanf")
    __attribute__((__nothrow__, __leaf__));
extern int vfscanf(FILE *__restrict __s, const char *__restrict __format,
                   __gnuc_va_list __arg)
    __attribute__((__format__(__scanf__, 2, 0)));
extern int vscanf(const char *__restrict __format, __gnuc_va_list __arg)
    __attribute__((__format__(__scanf__, 1, 0)));
extern int vsscanf(const char *__restrict __s, const char *__restrict __format,
                   __gnuc_va_list __arg) __attribute__((__nothrow__, __leaf__))
__attribute__((__format__(__scanf__, 2, 0)));
extern int vfscanf(FILE *__restrict __s, const char *__restrict __format,
                   __gnuc_va_list __arg) __asm__(""
                                                 "__isoc99_vfscanf")
    __attribute__((__format__(__scanf__, 2, 0)));
extern int vscanf(const char *__restrict __format,
                  __gnuc_va_list __arg) __asm__(""
                                                "__isoc99_vscanf")
    __attribute__((__format__(__scanf__, 1, 0)));
extern int vsscanf(const char *__restrict __s, const char *__restrict __format,
                   __gnuc_va_list __arg) __asm__(""
                                                 "__isoc99_vsscanf")
    __attribute__((__nothrow__, __leaf__))
    __attribute__((__format__(__scanf__, 2, 0)));
extern int fgetc(FILE *__stream);
extern int getc(FILE *__stream);
extern int getchar(void);
extern int getc_unlocked(FILE *__stream);
extern int getchar_unlocked(void);
extern int fgetc_unlocked(FILE *__stream);
extern int fputc(int __c, FILE *__stream);
extern int putc(int __c, FILE *__stream);
extern int putchar(int __c);
extern int fputc_unlocked(int __c, FILE *__stream);
extern int putc_unlocked(int __c, FILE *__stream);
extern int putchar_unlocked(int __c);
extern int getw(FILE *__stream);
extern int putw(int __w, FILE *__stream);
extern char *fgets(char *__restrict __s, int __n, FILE *__restrict __stream)
    __attribute__((__access__(__write_only__, 1, 2)));
extern __ssize_t __getdelim(char **__restrict __lineptr, size_t *__restrict __n,
                            int __delimiter, FILE *__restrict __stream);
extern __ssize_t getdelim(char **__restrict __lineptr, size_t *__restrict __n,
                          int __delimiter, FILE *__restrict __stream);
extern __ssize_t getline(char **__restrict __lineptr, size_t *__restrict __n,
                         FILE *__restrict __stream);
extern int fputs(const char *__restrict __s, FILE *__restrict __stream);
extern int puts(const char *__s);
extern int ungetc(int __c, FILE *__stream);
extern size_t fread(void *__restrict __ptr, size_t __size, size_t __n,
                    FILE *__restrict __stream);
extern size_t fwrite(const void *__restrict __ptr, size_t __size, size_t __n,
                     FILE *__restrict __s);
extern size_t fread_unlocked(void *__restrict __ptr, size_t __size, size_t __n,
                             FILE *__restrict __stream);
extern size_t fwrite_unlocked(const void *__restrict __ptr, size_t __size,
                              size_t __n, FILE *__restrict __stream);
extern int fseek(FILE *__stream, long int __off, int __whence);
extern long int ftell(FILE *__stream);
extern void rewind(FILE *__stream);
extern int fseeko(FILE *__stream, __off_t __off, int __whence);
extern __off_t ftello(FILE *__stream);
extern int fgetpos(FILE *__restrict __stream, fpos_t *__restrict __pos);
extern int fsetpos(FILE *__stream, const fpos_t *__pos);
extern void clearerr(FILE *__stream) __attribute__((__nothrow__, __leaf__));
extern int feof(FILE *__stream) __attribute__((__nothrow__, __leaf__));
extern int ferror(FILE *__stream) __attribute__((__nothrow__, __leaf__));
extern void clearerr_unlocked(FILE *__stream)
    __attribute__((__nothrow__, __leaf__));
extern int feof_unlocked(FILE *__stream) __attribute__((__nothrow__, __leaf__));
extern int ferror_unlocked(FILE *__stream)
    __attribute__((__nothrow__, __leaf__));
extern void perror(const char *__s);
extern int fileno(FILE *__stream) __attribute__((__nothrow__, __leaf__));
extern int fileno_unlocked(FILE *__stream)
    __attribute__((__nothrow__, __leaf__));
extern int pclose(FILE *__stream);
extern FILE *popen(const char *__command, const char *__modes)
    __attribute__((__malloc__)) __attribute__((__malloc__(pclose, 1)));
extern char *ctermid(char *__s) __attribute__((__nothrow__, __leaf__))
__attribute__((__access__(__write_only__, 1)));
extern void flockfile(FILE *__stream) __attribute__((__nothrow__, __leaf__));
extern int ftrylockfile(FILE *__stream) __attribute__((__nothrow__, __leaf__));
extern void funlockfile(FILE *__stream) __attribute__((__nothrow__, __leaf__));
extern int __uflow(FILE *);
extern int __overflow(FILE *, int);

typedef __u_char u_char;
typedef __u_short u_short;
typedef __u_int u_int;
typedef __u_long u_long;
typedef __quad_t quad_t;
typedef __u_quad_t u_quad_t;
typedef __fsid_t fsid_t;
typedef __loff_t loff_t;
typedef __ino_t ino_t;
typedef __dev_t dev_t;
typedef __gid_t gid_t;
typedef __mode_t mode_t;
typedef __nlink_t nlink_t;
typedef __uid_t uid_t;
typedef __pid_t pid_t;
typedef __id_t id_t;
typedef __daddr_t daddr_t;
typedef __caddr_t caddr_t;
typedef __key_t key_t;
typedef __clock_t clock_t;
typedef __clockid_t clockid_t;
typedef __time_t time_t;
typedef __timer_t timer_t;
typedef unsigned long int ulong;
typedef unsigned short int ushort;
typedef unsigned int uint;
typedef __int8_t int8_t;
typedef __int16_t int16_t;
typedef __int32_t int32_t;
typedef __int64_t int64_t;
typedef __uint8_t u_int8_t;
typedef __uint16_t u_int16_t;
typedef __uint32_t u_int32_t;
typedef __uint64_t u_int64_t;
typedef int register_t __attribute__((__mode__(__word__)));
static __inline __uint16_t __bswap_16(__uint16_t __bsx) {
  return __builtin_bswap16(__bsx);
}
static __inline __uint32_t __bswap_32(__uint32_t __bsx) {
  return __builtin_bswap32(__bsx);
}
__extension__ static __inline __uint64_t __bswap_64(__uint64_t __bsx) {
  return __builtin_bswap64(__bsx);
}
static __inline __uint16_t __uint16_identity(__uint16_t __x) { return __x; }
static __inline __uint32_t __uint32_identity(__uint32_t __x) { return __x; }
static __inline __uint64_t __uint64_identity(__uint64_t __x) { return __x; }
typedef struct {
  unsigned long int __val[(1024 / (8 * sizeof(unsigned long int)))];
} __sigset_t;
typedef __sigset_t sigset_t;
struct timeval {
  __time_t tv_sec;
  __suseconds_t tv_usec;
};
struct timespec {
  __time_t tv_sec;
  __syscall_slong_t tv_nsec;
};
typedef __suseconds_t suseconds_t;
typedef long int __fd_mask;
typedef struct {
  __fd_mask __fds_bits[1024 / (8 * (int)sizeof(__fd_mask))];
} fd_set;
typedef __fd_mask fd_mask;

extern int select(int __nfds, fd_set *__restrict __readfds,
                  fd_set *__restrict __writefds, fd_set *__restrict __exceptfds,
                  struct timeval *__restrict __timeout);
extern int pselect(int __nfds, fd_set *__restrict __readfds,
                   fd_set *__restrict __writefds,
                   fd_set *__restrict __exceptfds,
                   const struct timespec *__restrict __timeout,
                   const __sigset_t *__restrict __sigmask);

typedef __blksize_t blksize_t;
typedef __blkcnt_t blkcnt_t;
typedef __fsblkcnt_t fsblkcnt_t;
typedef __fsfilcnt_t fsfilcnt_t;
typedef union {
  __extension__ unsigned long long int __value64;
  struct {
    unsigned int __low;
    unsigned int __high;
  } __value32;
} __atomic_wide_counter;
typedef struct __pthread_internal_list {
  struct __pthread_internal_list *__prev;
  struct __pthread_internal_list *__next;
} __pthread_list_t;
typedef struct __pthread_internal_slist {
  struct __pthread_internal_slist *__next;
} __pthread_slist_t;
struct __pthread_mutex_s {
  int __lock;
  unsigned int __count;
  int __owner;
  unsigned int __nusers;
  int __kind;
  short __spins;
  short __elision;
  __pthread_list_t __list;
};
struct __pthread_rwlock_arch_t {
  unsigned int __readers;
  unsigned int __writers;
  unsigned int __wrphase_futex;
  unsigned int __writers_futex;
  unsigned int __pad3;
  unsigned int __pad4;
  int __cur_writer;
  int __shared;
  signed char __rwelision;
  unsigned char __pad1[7];
  unsigned long int __pad2;
  unsigned int __flags;
};
struct __pthread_cond_s {
  __atomic_wide_counter __wseq;
  __atomic_wide_counter __g1_start;
  unsigned int __g_refs[2];
  unsigned int __g_size[2];
  unsigned int __g1_orig_size;
  unsigned int __wrefs;
  unsigned int __g_signals[2];
};
typedef unsigned int __tss_t;
typedef unsigned long int __thrd_t;
typedef struct {
  int __data;
} __once_flag;
typedef unsigned long int pthread_t;
typedef union {
  char __size[4];
  int __align;
} pthread_mutexattr_t;
typedef union {
  char __size[4];
  int __align;
} pthread_condattr_t;
typedef unsigned int pthread_key_t;
typedef int pthread_once_t;
union pthread_attr_t {
  char __size[56];
  long int __align;
};
typedef union pthread_attr_t pthread_attr_t;
typedef union {
  struct __pthread_mutex_s __data;
  char __size[40];
  long int __align;
} pthread_mutex_t;
typedef union {
  struct __pthread_cond_s __data;
  char __size[48];
  __extension__ long long int __align;
} pthread_cond_t;
typedef union {
  struct __pthread_rwlock_arch_t __data;
  char __size[56];
  long int __align;
} pthread_rwlock_t;
typedef union {
  char __size[8];
  long int __align;
} pthread_rwlockattr_t;
typedef volatile int pthread_spinlock_t;
typedef union {
  char __size[32];
  long int __align;
} pthread_barrier_t;
typedef union {
  char __size[4];
  int __align;
} pthread_barrierattr_t;

struct iovec {
  void *iov_base;
  size_t iov_len;
};
typedef __socklen_t socklen_t;
enum __socket_type {
  SOCK_STREAM = 1,
  SOCK_DGRAM = 2,
  SOCK_RAW = 3,
  SOCK_RDM = 4,
  SOCK_SEQPACKET = 5,
  SOCK_DCCP = 6,
  SOCK_PACKET = 10,
  SOCK_CLOEXEC = 02000000,
  SOCK_NONBLOCK = 00004000
};
typedef unsigned short int sa_family_t;
struct sockaddr {
  sa_family_t sa_family;
  char sa_data[14];
};
struct sockaddr_storage {
  sa_family_t ss_family;
  char __ss_padding[(128 - (sizeof(unsigned short int)) -
                     sizeof(unsigned long int))];
  unsigned long int __ss_align;
};
enum {
  MSG_OOB = 0x01,
  MSG_PEEK = 0x02,
  MSG_DONTROUTE = 0x04,
  MSG_CTRUNC = 0x08,
  MSG_PROXY = 0x10,
  MSG_TRUNC = 0x20,
  MSG_DONTWAIT = 0x40,
  MSG_EOR = 0x80,
  MSG_WAITALL = 0x100,
  MSG_FIN = 0x200,
  MSG_SYN = 0x400,
  MSG_CONFIRM = 0x800,
  MSG_RST = 0x1000,
  MSG_ERRQUEUE = 0x2000,
  MSG_NOSIGNAL = 0x4000,
  MSG_MORE = 0x8000,
  MSG_WAITFORONE = 0x10000,
  MSG_BATCH = 0x40000,
  MSG_ZEROCOPY = 0x4000000,
  MSG_FASTOPEN = 0x20000000,
  MSG_CMSG_CLOEXEC = 0x40000000
};
struct msghdr {
  void *msg_name;
  socklen_t msg_namelen;
  struct iovec *msg_iov;
  size_t msg_iovlen;
  void *msg_control;
  size_t msg_controllen;
  int msg_flags;
};
struct cmsghdr {
  size_t cmsg_len;
  int cmsg_level;
  int cmsg_type;
  __extension__ unsigned char __cmsg_data[];
};
extern struct cmsghdr *__cmsg_nxthdr(struct msghdr *__mhdr,
                                     struct cmsghdr *__cmsg)
    __attribute__((__nothrow__, __leaf__));
enum { SCM_RIGHTS = 0x01 };
typedef struct {
  unsigned long fds_bits[1024 / (8 * sizeof(long))];
} __kernel_fd_set;
typedef void (*__kernel_sighandler_t)(int);
typedef int __kernel_key_t;
typedef int __kernel_mqd_t;
typedef unsigned short __kernel_old_uid_t;
typedef unsigned short __kernel_old_gid_t;
typedef unsigned long __kernel_old_dev_t;
typedef long __kernel_long_t;
typedef unsigned long __kernel_ulong_t;
typedef __kernel_ulong_t __kernel_ino_t;
typedef unsigned int __kernel_mode_t;
typedef int __kernel_pid_t;
typedef int __kernel_ipc_pid_t;
typedef unsigned int __kernel_uid_t;
typedef unsigned int __kernel_gid_t;
typedef __kernel_long_t __kernel_suseconds_t;
typedef int __kernel_daddr_t;
typedef unsigned int __kernel_uid32_t;
typedef unsigned int __kernel_gid32_t;
typedef __kernel_ulong_t __kernel_size_t;
typedef __kernel_long_t __kernel_ssize_t;
typedef __kernel_long_t __kernel_ptrdiff_t;
typedef struct {
  int val[2];
} __kernel_fsid_t;
typedef __kernel_long_t __kernel_off_t;
typedef long long __kernel_loff_t;
typedef __kernel_long_t __kernel_old_time_t;
typedef __kernel_long_t __kernel_time_t;
typedef long long __kernel_time64_t;
typedef __kernel_long_t __kernel_clock_t;
typedef int __kernel_timer_t;
typedef int __kernel_clockid_t;
typedef char *__kernel_caddr_t;
typedef unsigned short __kernel_uid16_t;
typedef unsigned short __kernel_gid16_t;
struct linger {
  int l_onoff;
  int l_linger;
};
struct osockaddr {
  unsigned short int sa_family;
  unsigned char sa_data[14];
};
enum { SHUT_RD = 0, SHUT_WR, SHUT_RDWR };
extern int socket(int __domain, int __type, int __protocol)
    __attribute__((__nothrow__, __leaf__));
extern int socketpair(int __domain, int __type, int __protocol, int __fds[2])
    __attribute__((__nothrow__, __leaf__));
extern int bind(int __fd, const struct sockaddr *__addr, socklen_t __len)
    __attribute__((__nothrow__, __leaf__));
extern int getsockname(int __fd, struct sockaddr *__restrict __addr,
                       socklen_t *__restrict __len)
    __attribute__((__nothrow__, __leaf__));
extern int connect(int __fd, const struct sockaddr *__addr, socklen_t __len);
extern int getpeername(int __fd, struct sockaddr *__restrict __addr,
                       socklen_t *__restrict __len)
    __attribute__((__nothrow__, __leaf__));
extern ssize_t send(int __fd, const void *__buf, size_t __n, int __flags);
extern ssize_t recv(int __fd, void *__buf, size_t __n, int __flags);
extern ssize_t sendto(int __fd, const void *__buf, size_t __n, int __flags,
                      const struct sockaddr *__addr, socklen_t __addr_len);
extern ssize_t recvfrom(int __fd, void *__restrict __buf, size_t __n,
                        int __flags, struct sockaddr *__restrict __addr,
                        socklen_t *__restrict __addr_len);
extern ssize_t sendmsg(int __fd, const struct msghdr *__message, int __flags);
extern ssize_t recvmsg(int __fd, struct msghdr *__message, int __flags);
extern int getsockopt(int __fd, int __level, int __optname,
                      void *__restrict __optval, socklen_t *__restrict __optlen)
    __attribute__((__nothrow__, __leaf__));
extern int setsockopt(int __fd, int __level, int __optname,
                      const void *__optval, socklen_t __optlen)
    __attribute__((__nothrow__, __leaf__));
extern int listen(int __fd, int __n) __attribute__((__nothrow__, __leaf__));
extern int accept(int __fd, struct sockaddr *__restrict __addr,
                  socklen_t *__restrict __addr_len);
extern int shutdown(int __fd, int __how) __attribute__((__nothrow__, __leaf__));
extern int sockatmark(int __fd) __attribute__((__nothrow__, __leaf__));
extern int isfdtype(int __fd, int __fdtype)
    __attribute__((__nothrow__, __leaf__));

typedef socklen_t curl_socklen_t;
typedef long curl_off_t;
struct tm {
  int tm_sec;
  int tm_min;
  int tm_hour;
  int tm_mday;
  int tm_mon;
  int tm_year;
  int tm_wday;
  int tm_yday;
  int tm_isdst;
  long int tm_gmtoff;
  const char *tm_zone;
};
struct itimerspec {
  struct timespec it_interval;
  struct timespec it_value;
};
struct sigevent;
struct __locale_struct {
  struct __locale_data *__locales[13];
  const unsigned short int *__ctype_b;
  const int *__ctype_tolower;
  const int *__ctype_toupper;
  const char *__names[13];
};
typedef struct __locale_struct *__locale_t;
typedef __locale_t locale_t;

extern clock_t clock(void) __attribute__((__nothrow__, __leaf__));
extern time_t time(time_t *__timer) __attribute__((__nothrow__, __leaf__));
extern double difftime(time_t __time1, time_t __time0)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__const__));
extern time_t mktime(struct tm *__tp) __attribute__((__nothrow__, __leaf__));
extern size_t strftime(char *__restrict __s, size_t __maxsize,
                       const char *__restrict __format,
                       const struct tm *__restrict __tp)
    __attribute__((__nothrow__, __leaf__));
extern size_t strftime_l(char *__restrict __s, size_t __maxsize,
                         const char *__restrict __format,
                         const struct tm *__restrict __tp, locale_t __loc)
    __attribute__((__nothrow__, __leaf__));
extern struct tm *gmtime(const time_t *__timer)
    __attribute__((__nothrow__, __leaf__));
extern struct tm *localtime(const time_t *__timer)
    __attribute__((__nothrow__, __leaf__));
extern struct tm *gmtime_r(const time_t *__restrict __timer,
                           struct tm *__restrict __tp)
    __attribute__((__nothrow__, __leaf__));
extern struct tm *localtime_r(const time_t *__restrict __timer,
                              struct tm *__restrict __tp)
    __attribute__((__nothrow__, __leaf__));
extern char *asctime(const struct tm *__tp)
    __attribute__((__nothrow__, __leaf__));
extern char *ctime(const time_t *__timer)
    __attribute__((__nothrow__, __leaf__));
extern char *asctime_r(const struct tm *__restrict __tp, char *__restrict __buf)
    __attribute__((__nothrow__, __leaf__));
extern char *ctime_r(const time_t *__restrict __timer, char *__restrict __buf)
    __attribute__((__nothrow__, __leaf__));
extern char *__tzname[2];
extern int __daylight;
extern long int __timezone;
extern char *tzname[2];
extern void tzset(void) __attribute__((__nothrow__, __leaf__));
extern int daylight;
extern long int timezone;
extern time_t timegm(struct tm *__tp) __attribute__((__nothrow__, __leaf__));
extern time_t timelocal(struct tm *__tp) __attribute__((__nothrow__, __leaf__));
extern int dysize(int __year) __attribute__((__nothrow__, __leaf__))
__attribute__((__const__));
extern int nanosleep(const struct timespec *__requested_time,
                     struct timespec *__remaining);
extern int clock_getres(clockid_t __clock_id, struct timespec *__res)
    __attribute__((__nothrow__, __leaf__));
extern int clock_gettime(clockid_t __clock_id, struct timespec *__tp)
    __attribute__((__nothrow__, __leaf__));
extern int clock_settime(clockid_t __clock_id, const struct timespec *__tp)
    __attribute__((__nothrow__, __leaf__));
extern int clock_nanosleep(clockid_t __clock_id, int __flags,
                           const struct timespec *__req,
                           struct timespec *__rem);
extern int clock_getcpuclockid(pid_t __pid, clockid_t *__clock_id)
    __attribute__((__nothrow__, __leaf__));
extern int timer_create(clockid_t __clock_id, struct sigevent *__restrict __evp,
                        timer_t *__restrict __timerid)
    __attribute__((__nothrow__, __leaf__));
extern int timer_delete(timer_t __timerid)
    __attribute__((__nothrow__, __leaf__));
extern int timer_settime(timer_t __timerid, int __flags,
                         const struct itimerspec *__restrict __value,
                         struct itimerspec *__restrict __ovalue)
    __attribute__((__nothrow__, __leaf__));
extern int timer_gettime(timer_t __timerid, struct itimerspec *__value)
    __attribute__((__nothrow__, __leaf__));
extern int timer_getoverrun(timer_t __timerid)
    __attribute__((__nothrow__, __leaf__));
extern int timespec_get(struct timespec *__ts, int __base)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));

struct timezone {
  int tz_minuteswest;
  int tz_dsttime;
};
extern int gettimeofday(struct timeval *__restrict __tv, void *__restrict __tz)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int settimeofday(const struct timeval *__tv, const struct timezone *__tz)
    __attribute__((__nothrow__, __leaf__));
extern int adjtime(const struct timeval *__delta, struct timeval *__olddelta)
    __attribute__((__nothrow__, __leaf__));
enum __itimer_which { ITIMER_REAL = 0, ITIMER_VIRTUAL = 1, ITIMER_PROF = 2 };
struct itimerval {
  struct timeval it_interval;
  struct timeval it_value;
};
typedef int __itimer_which_t;
extern int getitimer(__itimer_which_t __which, struct itimerval *__value)
    __attribute__((__nothrow__, __leaf__));
extern int setitimer(__itimer_which_t __which,
                     const struct itimerval *__restrict __new,
                     struct itimerval *__restrict __old)
    __attribute__((__nothrow__, __leaf__));
extern int utimes(const char *__file, const struct timeval __tvp[2])
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int lutimes(const char *__file, const struct timeval __tvp[2])
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int futimes(int __fd, const struct timeval __tvp[2])
    __attribute__((__nothrow__, __leaf__));

typedef void CURL;
typedef void CURLSH;
typedef int curl_socket_t;
typedef enum {
  CURLSSLBACKEND_NONE = 0,
  CURLSSLBACKEND_OPENSSL = 1,
  CURLSSLBACKEND_GNUTLS = 2,
  CURLSSLBACKEND_NSS = 3,
  CURLSSLBACKEND_OBSOLETE4 = 4,
  CURLSSLBACKEND_GSKIT = 5,
  CURLSSLBACKEND_POLARSSL = 6,
  CURLSSLBACKEND_WOLFSSL = 7,
  CURLSSLBACKEND_SCHANNEL = 8,
  CURLSSLBACKEND_SECURETRANSPORT = 9,
  CURLSSLBACKEND_AXTLS = 10,
  CURLSSLBACKEND_MBEDTLS = 11,
  CURLSSLBACKEND_MESALINK = 12,
  CURLSSLBACKEND_BEARSSL = 13,
  CURLSSLBACKEND_RUSTLS = 14
} curl_sslbackend;
struct curl_httppost {
  struct curl_httppost *next;
  char *name;
  long namelength;
  char *contents;
  long contentslength;
  char *buffer;
  long bufferlength;
  char *contenttype;
  struct curl_slist *contentheader;
  struct curl_httppost *more;
  long flags;
  char *showfilename;
  void *userp;
  curl_off_t contentlen;
};
typedef int (*curl_progress_callback)(void *clientp, double dltotal,
                                      double dlnow, double ultotal,
                                      double ulnow);
typedef int (*curl_xferinfo_callback)(void *clientp, curl_off_t dltotal,
                                      curl_off_t dlnow, curl_off_t ultotal,
                                      curl_off_t ulnow);
typedef size_t (*curl_write_callback)(char *buffer, size_t size, size_t nitems,
                                      void *outstream);
typedef int (*curl_resolver_start_callback)(void *resolver_state,
                                            void *reserved, void *userdata);
typedef enum {
  CURLFILETYPE_FILE = 0,
  CURLFILETYPE_DIRECTORY,
  CURLFILETYPE_SYMLINK,
  CURLFILETYPE_DEVICE_BLOCK,
  CURLFILETYPE_DEVICE_CHAR,
  CURLFILETYPE_NAMEDPIPE,
  CURLFILETYPE_SOCKET,
  CURLFILETYPE_DOOR,
  CURLFILETYPE_UNKNOWN
} curlfiletype;
struct curl_fileinfo {
  char *filename;
  curlfiletype filetype;
  time_t time;
  unsigned int perm;
  int uid;
  int gid;
  curl_off_t size;
  long int hardlinks;
  struct {
    char *time;
    char *perm;
    char *user;
    char *group;
    char *target;
  } strings;
  unsigned int flags;
  char *b_data;
  size_t b_size;
  size_t b_used;
};
typedef long (*curl_chunk_bgn_callback)(const void *transfer_info, void *ptr,
                                        int remains);
typedef long (*curl_chunk_end_callback)(void *ptr);
typedef int (*curl_fnmatch_callback)(void *ptr, const char *pattern,
                                     const char *string);
typedef int (*curl_seek_callback)(void *instream, curl_off_t offset,
                                  int origin);
typedef size_t (*curl_read_callback)(char *buffer, size_t size, size_t nitems,
                                     void *instream);
typedef int (*curl_trailer_callback)(struct curl_slist **list, void *userdata);
typedef enum {
  CURLSOCKTYPE_IPCXN,
  CURLSOCKTYPE_ACCEPT,
  CURLSOCKTYPE_LAST
} curlsocktype;
typedef int (*curl_sockopt_callback)(void *clientp, curl_socket_t curlfd,
                                     curlsocktype purpose);
struct curl_sockaddr {
  int family;
  int socktype;
  int protocol;
  unsigned int addrlen;
  struct sockaddr addr;
};
typedef curl_socket_t (*curl_opensocket_callback)(
    void *clientp, curlsocktype purpose, struct curl_sockaddr *address);
typedef int (*curl_closesocket_callback)(void *clientp, curl_socket_t item);
typedef enum {
  CURLIOE_OK,
  CURLIOE_UNKNOWNCMD,
  CURLIOE_FAILRESTART,
  CURLIOE_LAST
} curlioerr;
typedef enum { CURLIOCMD_NOP, CURLIOCMD_RESTARTREAD, CURLIOCMD_LAST } curliocmd;
typedef curlioerr (*curl_ioctl_callback)(CURL *handle, int cmd, void *clientp);
typedef void *(*curl_malloc_callback)(size_t size);
typedef void (*curl_free_callback)(void *ptr);
typedef void *(*curl_realloc_callback)(void *ptr, size_t size);
typedef char *(*curl_strdup_callback)(const char *str);
typedef void *(*curl_calloc_callback)(size_t nmemb, size_t size);
typedef enum {
  CURLINFO_TEXT = 0,
  CURLINFO_HEADER_IN,
  CURLINFO_HEADER_OUT,
  CURLINFO_DATA_IN,
  CURLINFO_DATA_OUT,
  CURLINFO_SSL_DATA_IN,
  CURLINFO_SSL_DATA_OUT,
  CURLINFO_END
} curl_infotype;
typedef int (*curl_debug_callback)(CURL *handle, curl_infotype type, char *data,
                                   size_t size, void *userptr);
typedef int (*curl_prereq_callback)(void *clientp, char *conn_primary_ip,
                                    char *conn_local_ip, int conn_primary_port,
                                    int conn_local_port);
typedef enum {
  CURLE_OK = 0,
  CURLE_UNSUPPORTED_PROTOCOL,
  CURLE_FAILED_INIT,
  CURLE_URL_MALFORMAT,
  CURLE_NOT_BUILT_IN,
  CURLE_COULDNT_RESOLVE_PROXY,
  CURLE_COULDNT_RESOLVE_HOST,
  CURLE_COULDNT_CONNECT,
  CURLE_WEIRD_SERVER_REPLY,
  CURLE_REMOTE_ACCESS_DENIED,
  CURLE_FTP_ACCEPT_FAILED,
  CURLE_FTP_WEIRD_PASS_REPLY,
  CURLE_FTP_ACCEPT_TIMEOUT,
  CURLE_FTP_WEIRD_PASV_REPLY,
  CURLE_FTP_WEIRD_227_FORMAT,
  CURLE_FTP_CANT_GET_HOST,
  CURLE_HTTP2,
  CURLE_FTP_COULDNT_SET_TYPE,
  CURLE_PARTIAL_FILE,
  CURLE_FTP_COULDNT_RETR_FILE,
  CURLE_OBSOLETE20,
  CURLE_QUOTE_ERROR,
  CURLE_HTTP_RETURNED_ERROR,
  CURLE_WRITE_ERROR,
  CURLE_OBSOLETE24,
  CURLE_UPLOAD_FAILED,
  CURLE_READ_ERROR,
  CURLE_OUT_OF_MEMORY,
  CURLE_OPERATION_TIMEDOUT,
  CURLE_OBSOLETE29,
  CURLE_FTP_PORT_FAILED,
  CURLE_FTP_COULDNT_USE_REST,
  CURLE_OBSOLETE32,
  CURLE_RANGE_ERROR,
  CURLE_HTTP_POST_ERROR,
  CURLE_SSL_CONNECT_ERROR,
  CURLE_BAD_DOWNLOAD_RESUME,
  CURLE_FILE_COULDNT_READ_FILE,
  CURLE_LDAP_CANNOT_BIND,
  CURLE_LDAP_SEARCH_FAILED,
  CURLE_OBSOLETE40,
  CURLE_FUNCTION_NOT_FOUND,
  CURLE_ABORTED_BY_CALLBACK,
  CURLE_BAD_FUNCTION_ARGUMENT,
  CURLE_OBSOLETE44,
  CURLE_INTERFACE_FAILED,
  CURLE_OBSOLETE46,
  CURLE_TOO_MANY_REDIRECTS,
  CURLE_UNKNOWN_OPTION,
  CURLE_SETOPT_OPTION_SYNTAX,
  CURLE_OBSOLETE50,
  CURLE_OBSOLETE51,
  CURLE_GOT_NOTHING,
  CURLE_SSL_ENGINE_NOTFOUND,
  CURLE_SSL_ENGINE_SETFAILED,
  CURLE_SEND_ERROR,
  CURLE_RECV_ERROR,
  CURLE_OBSOLETE57,
  CURLE_SSL_CERTPROBLEM,
  CURLE_SSL_CIPHER,
  CURLE_PEER_FAILED_VERIFICATION,
  CURLE_BAD_CONTENT_ENCODING,
  CURLE_LDAP_INVALID_URL,
  CURLE_FILESIZE_EXCEEDED,
  CURLE_USE_SSL_FAILED,
  CURLE_SEND_FAIL_REWIND,
  CURLE_SSL_ENGINE_INITFAILED,
  CURLE_LOGIN_DENIED,
  CURLE_TFTP_NOTFOUND,
  CURLE_TFTP_PERM,
  CURLE_REMOTE_DISK_FULL,
  CURLE_TFTP_ILLEGAL,
  CURLE_TFTP_UNKNOWNID,
  CURLE_REMOTE_FILE_EXISTS,
  CURLE_TFTP_NOSUCHUSER,
  CURLE_CONV_FAILED,
  CURLE_CONV_REQD,
  CURLE_SSL_CACERT_BADFILE,
  CURLE_REMOTE_FILE_NOT_FOUND,
  CURLE_SSH,
  CURLE_SSL_SHUTDOWN_FAILED,
  CURLE_AGAIN,
  CURLE_SSL_CRL_BADFILE,
  CURLE_SSL_ISSUER_ERROR,
  CURLE_FTP_PRET_FAILED,
  CURLE_RTSP_CSEQ_ERROR,
  CURLE_RTSP_SESSION_ERROR,
  CURLE_FTP_BAD_FILE_LIST,
  CURLE_CHUNK_FAILED,
  CURLE_NO_CONNECTION_AVAILABLE,
  CURLE_SSL_PINNEDPUBKEYNOTMATCH,
  CURLE_SSL_INVALIDCERTSTATUS,
  CURLE_HTTP2_STREAM,
  CURLE_RECURSIVE_API_CALL,
  CURLE_AUTH_ERROR,
  CURLE_HTTP3,
  CURLE_QUIC_CONNECT_ERROR,
  CURLE_PROXY,
  CURLE_SSL_CLIENTCERT,
  CURL_LAST
} CURLcode;
typedef enum {
  CURLPX_OK,
  CURLPX_BAD_ADDRESS_TYPE,
  CURLPX_BAD_VERSION,
  CURLPX_CLOSED,
  CURLPX_GSSAPI,
  CURLPX_GSSAPI_PERMSG,
  CURLPX_GSSAPI_PROTECTION,
  CURLPX_IDENTD,
  CURLPX_IDENTD_DIFFER,
  CURLPX_LONG_HOSTNAME,
  CURLPX_LONG_PASSWD,
  CURLPX_LONG_USER,
  CURLPX_NO_AUTH,
  CURLPX_RECV_ADDRESS,
  CURLPX_RECV_AUTH,
  CURLPX_RECV_CONNECT,
  CURLPX_RECV_REQACK,
  CURLPX_REPLY_ADDRESS_TYPE_NOT_SUPPORTED,
  CURLPX_REPLY_COMMAND_NOT_SUPPORTED,
  CURLPX_REPLY_CONNECTION_REFUSED,
  CURLPX_REPLY_GENERAL_SERVER_FAILURE,
  CURLPX_REPLY_HOST_UNREACHABLE,
  CURLPX_REPLY_NETWORK_UNREACHABLE,
  CURLPX_REPLY_NOT_ALLOWED,
  CURLPX_REPLY_TTL_EXPIRED,
  CURLPX_REPLY_UNASSIGNED,
  CURLPX_REQUEST_FAILED,
  CURLPX_RESOLVE_HOST,
  CURLPX_SEND_AUTH,
  CURLPX_SEND_CONNECT,
  CURLPX_SEND_REQUEST,
  CURLPX_UNKNOWN_FAIL,
  CURLPX_UNKNOWN_MODE,
  CURLPX_USER_REJECTED,
  CURLPX_LAST
} CURLproxycode;
typedef CURLcode (*curl_conv_callback)(char *buffer, size_t length);
typedef CURLcode (*curl_ssl_ctx_callback)(CURL *curl, void *ssl_ctx,
                                          void *userptr);
typedef enum {
  CURLPROXY_HTTP = 0,
  CURLPROXY_HTTP_1_0 = 1,
  CURLPROXY_HTTPS = 2,
  CURLPROXY_SOCKS4 = 4,
  CURLPROXY_SOCKS5 = 5,
  CURLPROXY_SOCKS4A = 6,
  CURLPROXY_SOCKS5_HOSTNAME = 7
} curl_proxytype;
enum curl_khtype {
  CURLKHTYPE_UNKNOWN,
  CURLKHTYPE_RSA1,
  CURLKHTYPE_RSA,
  CURLKHTYPE_DSS,
  CURLKHTYPE_ECDSA,
  CURLKHTYPE_ED25519
};
struct curl_khkey {
  const char *key;
  size_t len;
  enum curl_khtype keytype;
};
enum curl_khstat {
  CURLKHSTAT_FINE_ADD_TO_FILE,
  CURLKHSTAT_FINE,
  CURLKHSTAT_REJECT,
  CURLKHSTAT_DEFER,
  CURLKHSTAT_FINE_REPLACE,
  CURLKHSTAT_LAST
};
enum curl_khmatch {
  CURLKHMATCH_OK,
  CURLKHMATCH_MISMATCH,
  CURLKHMATCH_MISSING,
  CURLKHMATCH_LAST
};
typedef int (*curl_sshkeycallback)(CURL *easy,
                                   const struct curl_khkey *knownkey,
                                   const struct curl_khkey *foundkey,
                                   enum curl_khmatch, void *clientp);
typedef enum {
  CURLUSESSL_NONE,
  CURLUSESSL_TRY,
  CURLUSESSL_CONTROL,
  CURLUSESSL_ALL,
  CURLUSESSL_LAST
} curl_usessl;
typedef enum {
  CURLFTPSSL_CCC_NONE,
  CURLFTPSSL_CCC_PASSIVE,
  CURLFTPSSL_CCC_ACTIVE,
  CURLFTPSSL_CCC_LAST
} curl_ftpccc;
typedef enum {
  CURLFTPAUTH_DEFAULT,
  CURLFTPAUTH_SSL,
  CURLFTPAUTH_TLS,
  CURLFTPAUTH_LAST
} curl_ftpauth;
typedef enum {
  CURLFTP_CREATE_DIR_NONE,
  CURLFTP_CREATE_DIR,
  CURLFTP_CREATE_DIR_RETRY,
  CURLFTP_CREATE_DIR_LAST
} curl_ftpcreatedir;
typedef enum {
  CURLFTPMETHOD_DEFAULT,
  CURLFTPMETHOD_MULTICWD,
  CURLFTPMETHOD_NOCWD,
  CURLFTPMETHOD_SINGLECWD,
  CURLFTPMETHOD_LAST
} curl_ftpmethod;
struct curl_hstsentry {
  char *name;
  size_t namelen;
  unsigned int includeSubDomains : 1;
  char expire[18];
};
struct curl_index {
  size_t index;
  size_t total;
};
typedef enum { CURLSTS_OK, CURLSTS_DONE, CURLSTS_FAIL } CURLSTScode;
typedef CURLSTScode (*curl_hstsread_callback)(CURL *easy,
                                              struct curl_hstsentry *e,
                                              void *userp);
typedef CURLSTScode (*curl_hstswrite_callback)(CURL *easy,
                                               struct curl_hstsentry *e,
                                               struct curl_index *i,
                                               void *userp);
typedef enum {
  CURLOPT_WRITEDATA = 10000 + 1,
  CURLOPT_URL = 10000 + 2,
  CURLOPT_PORT = 0 + 3,
  CURLOPT_PROXY = 10000 + 4,
  CURLOPT_USERPWD = 10000 + 5,
  CURLOPT_PROXYUSERPWD = 10000 + 6,
  CURLOPT_RANGE = 10000 + 7,
  CURLOPT_READDATA = 10000 + 9,
  CURLOPT_ERRORBUFFER = 10000 + 10,
  CURLOPT_WRITEFUNCTION = 20000 + 11,
  CURLOPT_READFUNCTION = 20000 + 12,
  CURLOPT_TIMEOUT = 0 + 13,
  CURLOPT_INFILESIZE = 0 + 14,
  CURLOPT_POSTFIELDS = 10000 + 15,
  CURLOPT_REFERER = 10000 + 16,
  CURLOPT_FTPPORT = 10000 + 17,
  CURLOPT_USERAGENT = 10000 + 18,
  CURLOPT_LOW_SPEED_LIMIT = 0 + 19,
  CURLOPT_LOW_SPEED_TIME = 0 + 20,
  CURLOPT_RESUME_FROM = 0 + 21,
  CURLOPT_COOKIE = 10000 + 22,
  CURLOPT_HTTPHEADER = 10000 + 23,
  CURLOPT_HTTPPOST = 10000 + 24,
  CURLOPT_SSLCERT = 10000 + 25,
  CURLOPT_KEYPASSWD = 10000 + 26,
  CURLOPT_CRLF = 0 + 27,
  CURLOPT_QUOTE = 10000 + 28,
  CURLOPT_HEADERDATA = 10000 + 29,
  CURLOPT_COOKIEFILE = 10000 + 31,
  CURLOPT_SSLVERSION = 0 + 32,
  CURLOPT_TIMECONDITION = 0 + 33,
  CURLOPT_TIMEVALUE = 0 + 34,
  CURLOPT_CUSTOMREQUEST = 10000 + 36,
  CURLOPT_STDERR = 10000 + 37,
  CURLOPT_POSTQUOTE = 10000 + 39,
  CURLOPT_OBSOLETE40 = 10000 + 40,
  CURLOPT_VERBOSE = 0 + 41,
  CURLOPT_HEADER = 0 + 42,
  CURLOPT_NOPROGRESS = 0 + 43,
  CURLOPT_NOBODY = 0 + 44,
  CURLOPT_FAILONERROR = 0 + 45,
  CURLOPT_UPLOAD = 0 + 46,
  CURLOPT_POST = 0 + 47,
  CURLOPT_DIRLISTONLY = 0 + 48,
  CURLOPT_APPEND = 0 + 50,
  CURLOPT_NETRC = 0 + 51,
  CURLOPT_FOLLOWLOCATION = 0 + 52,
  CURLOPT_TRANSFERTEXT = 0 + 53,
  CURLOPT_PUT = 0 + 54,
  CURLOPT_PROGRESSFUNCTION = 20000 + 56,
  CURLOPT_XFERINFODATA = 10000 + 57,
  CURLOPT_AUTOREFERER = 0 + 58,
  CURLOPT_PROXYPORT = 0 + 59,
  CURLOPT_POSTFIELDSIZE = 0 + 60,
  CURLOPT_HTTPPROXYTUNNEL = 0 + 61,
  CURLOPT_INTERFACE = 10000 + 62,
  CURLOPT_KRBLEVEL = 10000 + 63,
  CURLOPT_SSL_VERIFYPEER = 0 + 64,
  CURLOPT_CAINFO = 10000 + 65,
  CURLOPT_MAXREDIRS = 0 + 68,
  CURLOPT_FILETIME = 0 + 69,
  CURLOPT_TELNETOPTIONS = 10000 + 70,
  CURLOPT_MAXCONNECTS = 0 + 71,
  CURLOPT_OBSOLETE72 = 0 + 72,
  CURLOPT_FRESH_CONNECT = 0 + 74,
  CURLOPT_FORBID_REUSE = 0 + 75,
  CURLOPT_RANDOM_FILE = 10000 + 76,
  CURLOPT_EGDSOCKET = 10000 + 77,
  CURLOPT_CONNECTTIMEOUT = 0 + 78,
  CURLOPT_HEADERFUNCTION = 20000 + 79,
  CURLOPT_HTTPGET = 0 + 80,
  CURLOPT_SSL_VERIFYHOST = 0 + 81,
  CURLOPT_COOKIEJAR = 10000 + 82,
  CURLOPT_SSL_CIPHER_LIST = 10000 + 83,
  CURLOPT_HTTP_VERSION = 0 + 84,
  CURLOPT_FTP_USE_EPSV = 0 + 85,
  CURLOPT_SSLCERTTYPE = 10000 + 86,
  CURLOPT_SSLKEY = 10000 + 87,
  CURLOPT_SSLKEYTYPE = 10000 + 88,
  CURLOPT_SSLENGINE = 10000 + 89,
  CURLOPT_SSLENGINE_DEFAULT = 0 + 90,
  CURLOPT_DNS_USE_GLOBAL_CACHE = 0 + 91,
  CURLOPT_DNS_CACHE_TIMEOUT = 0 + 92,
  CURLOPT_PREQUOTE = 10000 + 93,
  CURLOPT_DEBUGFUNCTION = 20000 + 94,
  CURLOPT_DEBUGDATA = 10000 + 95,
  CURLOPT_COOKIESESSION = 0 + 96,
  CURLOPT_CAPATH = 10000 + 97,
  CURLOPT_BUFFERSIZE = 0 + 98,
  CURLOPT_NOSIGNAL = 0 + 99,
  CURLOPT_SHARE = 10000 + 100,
  CURLOPT_PROXYTYPE = 0 + 101,
  CURLOPT_ACCEPT_ENCODING = 10000 + 102,
  CURLOPT_PRIVATE = 10000 + 103,
  CURLOPT_HTTP200ALIASES = 10000 + 104,
  CURLOPT_UNRESTRICTED_AUTH = 0 + 105,
  CURLOPT_FTP_USE_EPRT = 0 + 106,
  CURLOPT_HTTPAUTH = 0 + 107,
  CURLOPT_SSL_CTX_FUNCTION = 20000 + 108,
  CURLOPT_SSL_CTX_DATA = 10000 + 109,
  CURLOPT_FTP_CREATE_MISSING_DIRS = 0 + 110,
  CURLOPT_PROXYAUTH = 0 + 111,
  CURLOPT_FTP_RESPONSE_TIMEOUT = 0 + 112,
  CURLOPT_IPRESOLVE = 0 + 113,
  CURLOPT_MAXFILESIZE = 0 + 114,
  CURLOPT_INFILESIZE_LARGE = 30000 + 115,
  CURLOPT_RESUME_FROM_LARGE = 30000 + 116,
  CURLOPT_MAXFILESIZE_LARGE = 30000 + 117,
  CURLOPT_NETRC_FILE = 10000 + 118,
  CURLOPT_USE_SSL = 0 + 119,
  CURLOPT_POSTFIELDSIZE_LARGE = 30000 + 120,
  CURLOPT_TCP_NODELAY = 0 + 121,
  CURLOPT_FTPSSLAUTH = 0 + 129,
  CURLOPT_IOCTLFUNCTION = 20000 + 130,
  CURLOPT_IOCTLDATA = 10000 + 131,
  CURLOPT_FTP_ACCOUNT = 10000 + 134,
  CURLOPT_COOKIELIST = 10000 + 135,
  CURLOPT_IGNORE_CONTENT_LENGTH = 0 + 136,
  CURLOPT_FTP_SKIP_PASV_IP = 0 + 137,
  CURLOPT_FTP_FILEMETHOD = 0 + 138,
  CURLOPT_LOCALPORT = 0 + 139,
  CURLOPT_LOCALPORTRANGE = 0 + 140,
  CURLOPT_CONNECT_ONLY = 0 + 141,
  CURLOPT_CONV_FROM_NETWORK_FUNCTION = 20000 + 142,
  CURLOPT_CONV_TO_NETWORK_FUNCTION = 20000 + 143,
  CURLOPT_CONV_FROM_UTF8_FUNCTION = 20000 + 144,
  CURLOPT_MAX_SEND_SPEED_LARGE = 30000 + 145,
  CURLOPT_MAX_RECV_SPEED_LARGE = 30000 + 146,
  CURLOPT_FTP_ALTERNATIVE_TO_USER = 10000 + 147,
  CURLOPT_SOCKOPTFUNCTION = 20000 + 148,
  CURLOPT_SOCKOPTDATA = 10000 + 149,
  CURLOPT_SSL_SESSIONID_CACHE = 0 + 150,
  CURLOPT_SSH_AUTH_TYPES = 0 + 151,
  CURLOPT_SSH_PUBLIC_KEYFILE = 10000 + 152,
  CURLOPT_SSH_PRIVATE_KEYFILE = 10000 + 153,
  CURLOPT_FTP_SSL_CCC = 0 + 154,
  CURLOPT_TIMEOUT_MS = 0 + 155,
  CURLOPT_CONNECTTIMEOUT_MS = 0 + 156,
  CURLOPT_HTTP_TRANSFER_DECODING = 0 + 157,
  CURLOPT_HTTP_CONTENT_DECODING = 0 + 158,
  CURLOPT_NEW_FILE_PERMS = 0 + 159,
  CURLOPT_NEW_DIRECTORY_PERMS = 0 + 160,
  CURLOPT_POSTREDIR = 0 + 161,
  CURLOPT_SSH_HOST_PUBLIC_KEY_MD5 = 10000 + 162,
  CURLOPT_OPENSOCKETFUNCTION = 20000 + 163,
  CURLOPT_OPENSOCKETDATA = 10000 + 164,
  CURLOPT_COPYPOSTFIELDS = 10000 + 165,
  CURLOPT_PROXY_TRANSFER_MODE = 0 + 166,
  CURLOPT_SEEKFUNCTION = 20000 + 167,
  CURLOPT_SEEKDATA = 10000 + 168,
  CURLOPT_CRLFILE = 10000 + 169,
  CURLOPT_ISSUERCERT = 10000 + 170,
  CURLOPT_ADDRESS_SCOPE = 0 + 171,
  CURLOPT_CERTINFO = 0 + 172,
  CURLOPT_USERNAME = 10000 + 173,
  CURLOPT_PASSWORD = 10000 + 174,
  CURLOPT_PROXYUSERNAME = 10000 + 175,
  CURLOPT_PROXYPASSWORD = 10000 + 176,
  CURLOPT_NOPROXY = 10000 + 177,
  CURLOPT_TFTP_BLKSIZE = 0 + 178,
  CURLOPT_SOCKS5_GSSAPI_SERVICE = 10000 + 179,
  CURLOPT_SOCKS5_GSSAPI_NEC = 0 + 180,
  CURLOPT_PROTOCOLS = 0 + 181,
  CURLOPT_REDIR_PROTOCOLS = 0 + 182,
  CURLOPT_SSH_KNOWNHOSTS = 10000 + 183,
  CURLOPT_SSH_KEYFUNCTION = 20000 + 184,
  CURLOPT_SSH_KEYDATA = 10000 + 185,
  CURLOPT_MAIL_FROM = 10000 + 186,
  CURLOPT_MAIL_RCPT = 10000 + 187,
  CURLOPT_FTP_USE_PRET = 0 + 188,
  CURLOPT_RTSP_REQUEST = 0 + 189,
  CURLOPT_RTSP_SESSION_ID = 10000 + 190,
  CURLOPT_RTSP_STREAM_URI = 10000 + 191,
  CURLOPT_RTSP_TRANSPORT = 10000 + 192,
  CURLOPT_RTSP_CLIENT_CSEQ = 0 + 193,
  CURLOPT_RTSP_SERVER_CSEQ = 0 + 194,
  CURLOPT_INTERLEAVEDATA = 10000 + 195,
  CURLOPT_INTERLEAVEFUNCTION = 20000 + 196,
  CURLOPT_WILDCARDMATCH = 0 + 197,
  CURLOPT_CHUNK_BGN_FUNCTION = 20000 + 198,
  CURLOPT_CHUNK_END_FUNCTION = 20000 + 199,
  CURLOPT_FNMATCH_FUNCTION = 20000 + 200,
  CURLOPT_CHUNK_DATA = 10000 + 201,
  CURLOPT_FNMATCH_DATA = 10000 + 202,
  CURLOPT_RESOLVE = 10000 + 203,
  CURLOPT_TLSAUTH_USERNAME = 10000 + 204,
  CURLOPT_TLSAUTH_PASSWORD = 10000 + 205,
  CURLOPT_TLSAUTH_TYPE = 10000 + 206,
  CURLOPT_TRANSFER_ENCODING = 0 + 207,
  CURLOPT_CLOSESOCKETFUNCTION = 20000 + 208,
  CURLOPT_CLOSESOCKETDATA = 10000 + 209,
  CURLOPT_GSSAPI_DELEGATION = 0 + 210,
  CURLOPT_DNS_SERVERS = 10000 + 211,
  CURLOPT_ACCEPTTIMEOUT_MS = 0 + 212,
  CURLOPT_TCP_KEEPALIVE = 0 + 213,
  CURLOPT_TCP_KEEPIDLE = 0 + 214,
  CURLOPT_TCP_KEEPINTVL = 0 + 215,
  CURLOPT_SSL_OPTIONS = 0 + 216,
  CURLOPT_MAIL_AUTH = 10000 + 217,
  CURLOPT_SASL_IR = 0 + 218,
  CURLOPT_XFERINFOFUNCTION = 20000 + 219,
  CURLOPT_XOAUTH2_BEARER = 10000 + 220,
  CURLOPT_DNS_INTERFACE = 10000 + 221,
  CURLOPT_DNS_LOCAL_IP4 = 10000 + 222,
  CURLOPT_DNS_LOCAL_IP6 = 10000 + 223,
  CURLOPT_LOGIN_OPTIONS = 10000 + 224,
  CURLOPT_SSL_ENABLE_NPN = 0 + 225,
  CURLOPT_SSL_ENABLE_ALPN = 0 + 226,
  CURLOPT_EXPECT_100_TIMEOUT_MS = 0 + 227,
  CURLOPT_PROXYHEADER = 10000 + 228,
  CURLOPT_HEADEROPT = 0 + 229,
  CURLOPT_PINNEDPUBLICKEY = 10000 + 230,
  CURLOPT_UNIX_SOCKET_PATH = 10000 + 231,
  CURLOPT_SSL_VERIFYSTATUS = 0 + 232,
  CURLOPT_SSL_FALSESTART = 0 + 233,
  CURLOPT_PATH_AS_IS = 0 + 234,
  CURLOPT_PROXY_SERVICE_NAME = 10000 + 235,
  CURLOPT_SERVICE_NAME = 10000 + 236,
  CURLOPT_PIPEWAIT = 0 + 237,
  CURLOPT_DEFAULT_PROTOCOL = 10000 + 238,
  CURLOPT_STREAM_WEIGHT = 0 + 239,
  CURLOPT_STREAM_DEPENDS = 10000 + 240,
  CURLOPT_STREAM_DEPENDS_E = 10000 + 241,
  CURLOPT_TFTP_NO_OPTIONS = 0 + 242,
  CURLOPT_CONNECT_TO = 10000 + 243,
  CURLOPT_TCP_FASTOPEN = 0 + 244,
  CURLOPT_KEEP_SENDING_ON_ERROR = 0 + 245,
  CURLOPT_PROXY_CAINFO = 10000 + 246,
  CURLOPT_PROXY_CAPATH = 10000 + 247,
  CURLOPT_PROXY_SSL_VERIFYPEER = 0 + 248,
  CURLOPT_PROXY_SSL_VERIFYHOST = 0 + 249,
  CURLOPT_PROXY_SSLVERSION = 0 + 250,
  CURLOPT_PROXY_TLSAUTH_USERNAME = 10000 + 251,
  CURLOPT_PROXY_TLSAUTH_PASSWORD = 10000 + 252,
  CURLOPT_PROXY_TLSAUTH_TYPE = 10000 + 253,
  CURLOPT_PROXY_SSLCERT = 10000 + 254,
  CURLOPT_PROXY_SSLCERTTYPE = 10000 + 255,
  CURLOPT_PROXY_SSLKEY = 10000 + 256,
  CURLOPT_PROXY_SSLKEYTYPE = 10000 + 257,
  CURLOPT_PROXY_KEYPASSWD = 10000 + 258,
  CURLOPT_PROXY_SSL_CIPHER_LIST = 10000 + 259,
  CURLOPT_PROXY_CRLFILE = 10000 + 260,
  CURLOPT_PROXY_SSL_OPTIONS = 0 + 261,
  CURLOPT_PRE_PROXY = 10000 + 262,
  CURLOPT_PROXY_PINNEDPUBLICKEY = 10000 + 263,
  CURLOPT_ABSTRACT_UNIX_SOCKET = 10000 + 264,
  CURLOPT_SUPPRESS_CONNECT_HEADERS = 0 + 265,
  CURLOPT_REQUEST_TARGET = 10000 + 266,
  CURLOPT_SOCKS5_AUTH = 0 + 267,
  CURLOPT_SSH_COMPRESSION = 0 + 268,
  CURLOPT_MIMEPOST = 10000 + 269,
  CURLOPT_TIMEVALUE_LARGE = 30000 + 270,
  CURLOPT_HAPPY_EYEBALLS_TIMEOUT_MS = 0 + 271,
  CURLOPT_RESOLVER_START_FUNCTION = 20000 + 272,
  CURLOPT_RESOLVER_START_DATA = 10000 + 273,
  CURLOPT_HAPROXYPROTOCOL = 0 + 274,
  CURLOPT_DNS_SHUFFLE_ADDRESSES = 0 + 275,
  CURLOPT_TLS13_CIPHERS = 10000 + 276,
  CURLOPT_PROXY_TLS13_CIPHERS = 10000 + 277,
  CURLOPT_DISALLOW_USERNAME_IN_URL = 0 + 278,
  CURLOPT_DOH_URL = 10000 + 279,
  CURLOPT_UPLOAD_BUFFERSIZE = 0 + 280,
  CURLOPT_UPKEEP_INTERVAL_MS = 0 + 281,
  CURLOPT_CURLU = 10000 + 282,
  CURLOPT_TRAILERFUNCTION = 20000 + 283,
  CURLOPT_TRAILERDATA = 10000 + 284,
  CURLOPT_HTTP09_ALLOWED = 0 + 285,
  CURLOPT_ALTSVC_CTRL = 0 + 286,
  CURLOPT_ALTSVC = 10000 + 287,
  CURLOPT_MAXAGE_CONN = 0 + 288,
  CURLOPT_SASL_AUTHZID = 10000 + 289,
  CURLOPT_MAIL_RCPT_ALLLOWFAILS = 0 + 290,
  CURLOPT_SSLCERT_BLOB = 40000 + 291,
  CURLOPT_SSLKEY_BLOB = 40000 + 292,
  CURLOPT_PROXY_SSLCERT_BLOB = 40000 + 293,
  CURLOPT_PROXY_SSLKEY_BLOB = 40000 + 294,
  CURLOPT_ISSUERCERT_BLOB = 40000 + 295,
  CURLOPT_PROXY_ISSUERCERT = 10000 + 296,
  CURLOPT_PROXY_ISSUERCERT_BLOB = 40000 + 297,
  CURLOPT_SSL_EC_CURVES = 10000 + 298,
  CURLOPT_HSTS_CTRL = 0 + 299,
  CURLOPT_HSTS = 10000 + 300,
  CURLOPT_HSTSREADFUNCTION = 20000 + 301,
  CURLOPT_HSTSREADDATA = 10000 + 302,
  CURLOPT_HSTSWRITEFUNCTION = 20000 + 303,
  CURLOPT_HSTSWRITEDATA = 10000 + 304,
  CURLOPT_AWS_SIGV4 = 10000 + 305,
  CURLOPT_DOH_SSL_VERIFYPEER = 0 + 306,
  CURLOPT_DOH_SSL_VERIFYHOST = 0 + 307,
  CURLOPT_DOH_SSL_VERIFYSTATUS = 0 + 308,
  CURLOPT_CAINFO_BLOB = 40000 + 309,
  CURLOPT_PROXY_CAINFO_BLOB = 40000 + 310,
  CURLOPT_SSH_HOST_PUBLIC_KEY_SHA256 = 10000 + 311,
  CURLOPT_PREREQFUNCTION = 20000 + 312,
  CURLOPT_PREREQDATA = 10000 + 313,
  CURLOPT_MAXLIFETIME_CONN = 0 + 314,
  CURLOPT_MIME_OPTIONS = 0 + 315,
  CURLOPT_LASTENTRY
} CURLoption;
enum {
  CURL_HTTP_VERSION_NONE,
  CURL_HTTP_VERSION_1_0,
  CURL_HTTP_VERSION_1_1,
  CURL_HTTP_VERSION_2_0,
  CURL_HTTP_VERSION_2TLS,
  CURL_HTTP_VERSION_2_PRIOR_KNOWLEDGE,
  CURL_HTTP_VERSION_3 = 30,
  CURL_HTTP_VERSION_LAST
};
enum {
  CURL_RTSPREQ_NONE,
  CURL_RTSPREQ_OPTIONS,
  CURL_RTSPREQ_DESCRIBE,
  CURL_RTSPREQ_ANNOUNCE,
  CURL_RTSPREQ_SETUP,
  CURL_RTSPREQ_PLAY,
  CURL_RTSPREQ_PAUSE,
  CURL_RTSPREQ_TEARDOWN,
  CURL_RTSPREQ_GET_PARAMETER,
  CURL_RTSPREQ_SET_PARAMETER,
  CURL_RTSPREQ_RECORD,
  CURL_RTSPREQ_RECEIVE,
  CURL_RTSPREQ_LAST
};
enum CURL_NETRC_OPTION {
  CURL_NETRC_IGNORED,
  CURL_NETRC_OPTIONAL,
  CURL_NETRC_REQUIRED,
  CURL_NETRC_LAST
};
enum {
  CURL_SSLVERSION_DEFAULT,
  CURL_SSLVERSION_TLSv1,
  CURL_SSLVERSION_SSLv2,
  CURL_SSLVERSION_SSLv3,
  CURL_SSLVERSION_TLSv1_0,
  CURL_SSLVERSION_TLSv1_1,
  CURL_SSLVERSION_TLSv1_2,
  CURL_SSLVERSION_TLSv1_3,
  CURL_SSLVERSION_LAST
};
enum {
  CURL_SSLVERSION_MAX_NONE = 0,
  CURL_SSLVERSION_MAX_DEFAULT = (CURL_SSLVERSION_TLSv1 << 16),
  CURL_SSLVERSION_MAX_TLSv1_0 = (CURL_SSLVERSION_TLSv1_0 << 16),
  CURL_SSLVERSION_MAX_TLSv1_1 = (CURL_SSLVERSION_TLSv1_1 << 16),
  CURL_SSLVERSION_MAX_TLSv1_2 = (CURL_SSLVERSION_TLSv1_2 << 16),
  CURL_SSLVERSION_MAX_TLSv1_3 = (CURL_SSLVERSION_TLSv1_3 << 16),
  CURL_SSLVERSION_MAX_LAST = (CURL_SSLVERSION_LAST << 16)
};
enum CURL_TLSAUTH { CURL_TLSAUTH_NONE, CURL_TLSAUTH_SRP, CURL_TLSAUTH_LAST };
typedef enum {
  CURL_TIMECOND_NONE,
  CURL_TIMECOND_IFMODSINCE,
  CURL_TIMECOND_IFUNMODSINCE,
  CURL_TIMECOND_LASTMOD,
  CURL_TIMECOND_LAST
} curl_TimeCond;
int curl_strequal(const char *s1, const char *s2);
int curl_strnequal(const char *s1, const char *s2, size_t n);
typedef struct curl_mime curl_mime;
typedef struct curl_mimepart curl_mimepart;
curl_mime *curl_mime_init(CURL *easy);
void curl_mime_free(curl_mime *mime);
curl_mimepart *curl_mime_addpart(curl_mime *mime);
CURLcode curl_mime_name(curl_mimepart *part, const char *name);
CURLcode curl_mime_filename(curl_mimepart *part, const char *filename);
CURLcode curl_mime_type(curl_mimepart *part, const char *mimetype);
CURLcode curl_mime_encoder(curl_mimepart *part, const char *encoding);
CURLcode curl_mime_data(curl_mimepart *part, const char *data, size_t datasize);
CURLcode curl_mime_filedata(curl_mimepart *part, const char *filename);
CURLcode curl_mime_data_cb(curl_mimepart *part, curl_off_t datasize,
                           curl_read_callback readfunc,
                           curl_seek_callback seekfunc,
                           curl_free_callback freefunc, void *arg);
CURLcode curl_mime_subparts(curl_mimepart *part, curl_mime *subparts);
CURLcode curl_mime_headers(curl_mimepart *part, struct curl_slist *headers,
                           int take_ownership);
typedef enum {
  CURLFORM_NOTHING,
  CURLFORM_COPYNAME,
  CURLFORM_PTRNAME,
  CURLFORM_NAMELENGTH,
  CURLFORM_COPYCONTENTS,
  CURLFORM_PTRCONTENTS,
  CURLFORM_CONTENTSLENGTH,
  CURLFORM_FILECONTENT,
  CURLFORM_ARRAY,
  CURLFORM_OBSOLETE,
  CURLFORM_FILE,
  CURLFORM_BUFFER,
  CURLFORM_BUFFERPTR,
  CURLFORM_BUFFERLENGTH,
  CURLFORM_CONTENTTYPE,
  CURLFORM_CONTENTHEADER,
  CURLFORM_FILENAME,
  CURLFORM_END,
  CURLFORM_OBSOLETE2,
  CURLFORM_STREAM,
  CURLFORM_CONTENTLEN,
  CURLFORM_LASTENTRY
} CURLformoption;
struct curl_forms {
  CURLformoption option;
  const char *value;
};
typedef enum {
  CURL_FORMADD_OK,
  CURL_FORMADD_MEMORY,
  CURL_FORMADD_OPTION_TWICE,
  CURL_FORMADD_NULL,
  CURL_FORMADD_UNKNOWN_OPTION,
  CURL_FORMADD_INCOMPLETE,
  CURL_FORMADD_ILLEGAL_ARRAY,
  CURL_FORMADD_DISABLED,
  CURL_FORMADD_LAST
} CURLFORMcode;
CURLFORMcode curl_formadd(struct curl_httppost **httppost,
                          struct curl_httppost **last_post, ...);
typedef size_t (*curl_formget_callback)(void *arg, const char *buf, size_t len);
int curl_formget(struct curl_httppost *form, void *arg,
                 curl_formget_callback append);
void curl_formfree(struct curl_httppost *form);
char *curl_getenv(const char *variable);
char *curl_version(void);
char *curl_easy_escape(CURL *handle, const char *string, int length);
char *curl_escape(const char *string, int length);
char *curl_easy_unescape(CURL *handle, const char *string, int length,
                         int *outlength);
char *curl_unescape(const char *string, int length);
void curl_free(void *p);
CURLcode curl_global_init(long flags);
CURLcode curl_global_init_mem(long flags, curl_malloc_callback m,
                              curl_free_callback f, curl_realloc_callback r,
                              curl_strdup_callback s, curl_calloc_callback c);
void curl_global_cleanup(void);
struct curl_slist {
  char *data;
  struct curl_slist *next;
};
struct curl_ssl_backend {
  curl_sslbackend id;
  const char *name;
};
typedef struct curl_ssl_backend curl_ssl_backend;
typedef enum {
  CURLSSLSET_OK = 0,
  CURLSSLSET_UNKNOWN_BACKEND,
  CURLSSLSET_TOO_LATE,
  CURLSSLSET_NO_BACKENDS
} CURLsslset;
CURLsslset curl_global_sslset(curl_sslbackend id, const char *name,
                              const curl_ssl_backend ***avail);
struct curl_slist *curl_slist_append(struct curl_slist *, const char *);
void curl_slist_free_all(struct curl_slist *);
time_t curl_getdate(const char *p, const time_t *unused);
struct curl_certinfo {
  int num_of_certs;
  struct curl_slist **certinfo;
};
struct curl_tlssessioninfo {
  curl_sslbackend backend;
  void *internals;
};
typedef enum {
  CURLINFO_NONE,
  CURLINFO_EFFECTIVE_URL = 0x100000 + 1,
  CURLINFO_RESPONSE_CODE = 0x200000 + 2,
  CURLINFO_TOTAL_TIME = 0x300000 + 3,
  CURLINFO_NAMELOOKUP_TIME = 0x300000 + 4,
  CURLINFO_CONNECT_TIME = 0x300000 + 5,
  CURLINFO_PRETRANSFER_TIME = 0x300000 + 6,
  CURLINFO_SIZE_UPLOAD = 0x300000 + 7,
  CURLINFO_SIZE_UPLOAD_T = 0x600000 + 7,
  CURLINFO_SIZE_DOWNLOAD = 0x300000 + 8,
  CURLINFO_SIZE_DOWNLOAD_T = 0x600000 + 8,
  CURLINFO_SPEED_DOWNLOAD = 0x300000 + 9,
  CURLINFO_SPEED_DOWNLOAD_T = 0x600000 + 9,
  CURLINFO_SPEED_UPLOAD = 0x300000 + 10,
  CURLINFO_SPEED_UPLOAD_T = 0x600000 + 10,
  CURLINFO_HEADER_SIZE = 0x200000 + 11,
  CURLINFO_REQUEST_SIZE = 0x200000 + 12,
  CURLINFO_SSL_VERIFYRESULT = 0x200000 + 13,
  CURLINFO_FILETIME = 0x200000 + 14,
  CURLINFO_FILETIME_T = 0x600000 + 14,
  CURLINFO_CONTENT_LENGTH_DOWNLOAD = 0x300000 + 15,
  CURLINFO_CONTENT_LENGTH_DOWNLOAD_T = 0x600000 + 15,
  CURLINFO_CONTENT_LENGTH_UPLOAD = 0x300000 + 16,
  CURLINFO_CONTENT_LENGTH_UPLOAD_T = 0x600000 + 16,
  CURLINFO_STARTTRANSFER_TIME = 0x300000 + 17,
  CURLINFO_CONTENT_TYPE = 0x100000 + 18,
  CURLINFO_REDIRECT_TIME = 0x300000 + 19,
  CURLINFO_REDIRECT_COUNT = 0x200000 + 20,
  CURLINFO_PRIVATE = 0x100000 + 21,
  CURLINFO_HTTP_CONNECTCODE = 0x200000 + 22,
  CURLINFO_HTTPAUTH_AVAIL = 0x200000 + 23,
  CURLINFO_PROXYAUTH_AVAIL = 0x200000 + 24,
  CURLINFO_OS_ERRNO = 0x200000 + 25,
  CURLINFO_NUM_CONNECTS = 0x200000 + 26,
  CURLINFO_SSL_ENGINES = 0x400000 + 27,
  CURLINFO_COOKIELIST = 0x400000 + 28,
  CURLINFO_LASTSOCKET = 0x200000 + 29,
  CURLINFO_FTP_ENTRY_PATH = 0x100000 + 30,
  CURLINFO_REDIRECT_URL = 0x100000 + 31,
  CURLINFO_PRIMARY_IP = 0x100000 + 32,
  CURLINFO_APPCONNECT_TIME = 0x300000 + 33,
  CURLINFO_CERTINFO = 0x400000 + 34,
  CURLINFO_CONDITION_UNMET = 0x200000 + 35,
  CURLINFO_RTSP_SESSION_ID = 0x100000 + 36,
  CURLINFO_RTSP_CLIENT_CSEQ = 0x200000 + 37,
  CURLINFO_RTSP_SERVER_CSEQ = 0x200000 + 38,
  CURLINFO_RTSP_CSEQ_RECV = 0x200000 + 39,
  CURLINFO_PRIMARY_PORT = 0x200000 + 40,
  CURLINFO_LOCAL_IP = 0x100000 + 41,
  CURLINFO_LOCAL_PORT = 0x200000 + 42,
  CURLINFO_TLS_SESSION = 0x400000 + 43,
  CURLINFO_ACTIVESOCKET = 0x500000 + 44,
  CURLINFO_TLS_SSL_PTR = 0x400000 + 45,
  CURLINFO_HTTP_VERSION = 0x200000 + 46,
  CURLINFO_PROXY_SSL_VERIFYRESULT = 0x200000 + 47,
  CURLINFO_PROTOCOL = 0x200000 + 48,
  CURLINFO_SCHEME = 0x100000 + 49,
  CURLINFO_TOTAL_TIME_T = 0x600000 + 50,
  CURLINFO_NAMELOOKUP_TIME_T = 0x600000 + 51,
  CURLINFO_CONNECT_TIME_T = 0x600000 + 52,
  CURLINFO_PRETRANSFER_TIME_T = 0x600000 + 53,
  CURLINFO_STARTTRANSFER_TIME_T = 0x600000 + 54,
  CURLINFO_REDIRECT_TIME_T = 0x600000 + 55,
  CURLINFO_APPCONNECT_TIME_T = 0x600000 + 56,
  CURLINFO_RETRY_AFTER = 0x600000 + 57,
  CURLINFO_EFFECTIVE_METHOD = 0x100000 + 58,
  CURLINFO_PROXY_ERROR = 0x200000 + 59,
  CURLINFO_REFERER = 0x100000 + 60,
  CURLINFO_LASTONE = 60
} CURLINFO;
typedef enum {
  CURLCLOSEPOLICY_NONE,
  CURLCLOSEPOLICY_OLDEST,
  CURLCLOSEPOLICY_LEAST_RECENTLY_USED,
  CURLCLOSEPOLICY_LEAST_TRAFFIC,
  CURLCLOSEPOLICY_SLOWEST,
  CURLCLOSEPOLICY_CALLBACK,
  CURLCLOSEPOLICY_LAST
} curl_closepolicy;
typedef enum {
  CURL_LOCK_DATA_NONE = 0,
  CURL_LOCK_DATA_SHARE,
  CURL_LOCK_DATA_COOKIE,
  CURL_LOCK_DATA_DNS,
  CURL_LOCK_DATA_SSL_SESSION,
  CURL_LOCK_DATA_CONNECT,
  CURL_LOCK_DATA_PSL,
  CURL_LOCK_DATA_HSTS,
  CURL_LOCK_DATA_LAST
} curl_lock_data;
typedef enum {
  CURL_LOCK_ACCESS_NONE = 0,
  CURL_LOCK_ACCESS_SHARED = 1,
  CURL_LOCK_ACCESS_SINGLE = 2,
  CURL_LOCK_ACCESS_LAST
} curl_lock_access;
typedef void (*curl_lock_function)(CURL *handle, curl_lock_data data,
                                   curl_lock_access locktype, void *userptr);
typedef void (*curl_unlock_function)(CURL *handle, curl_lock_data data,
                                     void *userptr);
typedef enum {
  CURLSHE_OK,
  CURLSHE_BAD_OPTION,
  CURLSHE_IN_USE,
  CURLSHE_INVALID,
  CURLSHE_NOMEM,
  CURLSHE_NOT_BUILT_IN,
  CURLSHE_LAST
} CURLSHcode;
typedef enum {
  CURLSHOPT_NONE,
  CURLSHOPT_SHARE,
  CURLSHOPT_UNSHARE,
  CURLSHOPT_LOCKFUNC,
  CURLSHOPT_UNLOCKFUNC,
  CURLSHOPT_USERDATA,
  CURLSHOPT_LAST
} CURLSHoption;
CURLSH *curl_share_init(void);
CURLSHcode curl_share_setopt(CURLSH *, CURLSHoption option, ...);
CURLSHcode curl_share_cleanup(CURLSH *);
typedef enum {
  CURLVERSION_FIRST,
  CURLVERSION_SECOND,
  CURLVERSION_THIRD,
  CURLVERSION_FOURTH,
  CURLVERSION_FIFTH,
  CURLVERSION_SIXTH,
  CURLVERSION_SEVENTH,
  CURLVERSION_EIGHTH,
  CURLVERSION_NINTH,
  CURLVERSION_TENTH,
  CURLVERSION_LAST
} CURLversion;
struct curl_version_info_data {
  CURLversion age;
  const char *version;
  unsigned int version_num;
  const char *host;
  int features;
  const char *ssl_version;
  long ssl_version_num;
  const char *libz_version;
  const char *const *protocols;
  const char *ares;
  int ares_num;
  const char *libidn;
  int iconv_ver_num;
  const char *libssh_version;
  unsigned int brotli_ver_num;
  const char *brotli_version;
  unsigned int nghttp2_ver_num;
  const char *nghttp2_version;
  const char *quic_version;
  const char *cainfo;
  const char *capath;
  unsigned int zstd_ver_num;
  const char *zstd_version;
  const char *hyper_version;
  const char *gsasl_version;
};
typedef struct curl_version_info_data curl_version_info_data;
curl_version_info_data *curl_version_info(CURLversion);
const char *curl_easy_strerror(CURLcode);
const char *curl_share_strerror(CURLSHcode);
CURLcode curl_easy_pause(CURL *handle, int bitmask);
struct curl_blob {
  void *data;
  size_t len;
  unsigned int flags;
};
CURL *curl_easy_init(void);
CURLcode curl_easy_setopt(CURL *curl, CURLoption option, ...);
CURLcode curl_easy_perform(CURL *curl);
void curl_easy_cleanup(CURL *curl);
CURLcode curl_easy_getinfo(CURL *curl, CURLINFO info, ...);
CURL *curl_easy_duphandle(CURL *curl);
void curl_easy_reset(CURL *curl);
CURLcode curl_easy_recv(CURL *curl, void *buffer, size_t buflen, size_t *n);
CURLcode curl_easy_send(CURL *curl, const void *buffer, size_t buflen,
                        size_t *n);
CURLcode curl_easy_upkeep(CURL *curl);
typedef void CURLM;
typedef enum {
  CURLM_CALL_MULTI_PERFORM = -1,
  CURLM_OK,
  CURLM_BAD_HANDLE,
  CURLM_BAD_EASY_HANDLE,
  CURLM_OUT_OF_MEMORY,
  CURLM_INTERNAL_ERROR,
  CURLM_BAD_SOCKET,
  CURLM_UNKNOWN_OPTION,
  CURLM_ADDED_ALREADY,
  CURLM_RECURSIVE_API_CALL,
  CURLM_WAKEUP_FAILURE,
  CURLM_BAD_FUNCTION_ARGUMENT,
  CURLM_ABORTED_BY_CALLBACK,
  CURLM_LAST
} CURLMcode;
typedef enum { CURLMSG_NONE, CURLMSG_DONE, CURLMSG_LAST } CURLMSG;
struct CURLMsg {
  CURLMSG msg;
  CURL *easy_handle;
  union {
    void *whatever;
    CURLcode result;
  } data;
};
typedef struct CURLMsg CURLMsg;
struct curl_waitfd {
  curl_socket_t fd;
  short events;
  short revents;
};
CURLM *curl_multi_init(void);
CURLMcode curl_multi_add_handle(CURLM *multi_handle, CURL *curl_handle);
CURLMcode curl_multi_remove_handle(CURLM *multi_handle, CURL *curl_handle);
CURLMcode curl_multi_fdset(CURLM *multi_handle, fd_set *read_fd_set,
                           fd_set *write_fd_set, fd_set *exc_fd_set,
                           int *max_fd);
CURLMcode curl_multi_wait(CURLM *multi_handle, struct curl_waitfd extra_fds[],
                          unsigned int extra_nfds, int timeout_ms, int *ret);
CURLMcode curl_multi_poll(CURLM *multi_handle, struct curl_waitfd extra_fds[],
                          unsigned int extra_nfds, int timeout_ms, int *ret);
CURLMcode curl_multi_wakeup(CURLM *multi_handle);
CURLMcode curl_multi_perform(CURLM *multi_handle, int *running_handles);
CURLMcode curl_multi_cleanup(CURLM *multi_handle);
CURLMsg *curl_multi_info_read(CURLM *multi_handle, int *msgs_in_queue);
const char *curl_multi_strerror(CURLMcode);
typedef int (*curl_socket_callback)(CURL *easy, curl_socket_t s, int what,
                                    void *userp, void *socketp);
typedef int (*curl_multi_timer_callback)(CURLM *multi, long timeout_ms,
                                         void *userp);
CURLMcode curl_multi_socket(CURLM *multi_handle, curl_socket_t s,
                            int *running_handles);
CURLMcode curl_multi_socket_action(CURLM *multi_handle, curl_socket_t s,
                                   int ev_bitmask, int *running_handles);
CURLMcode curl_multi_socket_all(CURLM *multi_handle, int *running_handles);
CURLMcode curl_multi_timeout(CURLM *multi_handle, long *milliseconds);
typedef enum {
  CURLMOPT_SOCKETFUNCTION = 20000 + 1,
  CURLMOPT_SOCKETDATA = 10000 + 2,
  CURLMOPT_PIPELINING = 0 + 3,
  CURLMOPT_TIMERFUNCTION = 20000 + 4,
  CURLMOPT_TIMERDATA = 10000 + 5,
  CURLMOPT_MAXCONNECTS = 0 + 6,
  CURLMOPT_MAX_HOST_CONNECTIONS = 0 + 7,
  CURLMOPT_MAX_PIPELINE_LENGTH = 0 + 8,
  CURLMOPT_CONTENT_LENGTH_PENALTY_SIZE = 30000 + 9,
  CURLMOPT_CHUNK_LENGTH_PENALTY_SIZE = 30000 + 10,
  CURLMOPT_PIPELINING_SITE_BL = 10000 + 11,
  CURLMOPT_PIPELINING_SERVER_BL = 10000 + 12,
  CURLMOPT_MAX_TOTAL_CONNECTIONS = 0 + 13,
  CURLMOPT_PUSHFUNCTION = 20000 + 14,
  CURLMOPT_PUSHDATA = 10000 + 15,
  CURLMOPT_MAX_CONCURRENT_STREAMS = 0 + 16,
  CURLMOPT_LASTENTRY
} CURLMoption;
CURLMcode curl_multi_setopt(CURLM *multi_handle, CURLMoption option, ...);
CURLMcode curl_multi_assign(CURLM *multi_handle, curl_socket_t sockfd,
                            void *sockp);
struct curl_pushheaders;
char *curl_pushheader_bynum(struct curl_pushheaders *h, size_t num);
char *curl_pushheader_byname(struct curl_pushheaders *h, const char *name);
typedef int (*curl_push_callback)(CURL *parent, CURL *easy, size_t num_headers,
                                  struct curl_pushheaders *headers,
                                  void *userp);
typedef enum {
  CURLUE_OK,
  CURLUE_BAD_HANDLE,
  CURLUE_BAD_PARTPOINTER,
  CURLUE_MALFORMED_INPUT,
  CURLUE_BAD_PORT_NUMBER,
  CURLUE_UNSUPPORTED_SCHEME,
  CURLUE_URLDECODE,
  CURLUE_OUT_OF_MEMORY,
  CURLUE_USER_NOT_ALLOWED,
  CURLUE_UNKNOWN_PART,
  CURLUE_NO_SCHEME,
  CURLUE_NO_USER,
  CURLUE_NO_PASSWORD,
  CURLUE_NO_OPTIONS,
  CURLUE_NO_HOST,
  CURLUE_NO_PORT,
  CURLUE_NO_QUERY,
  CURLUE_NO_FRAGMENT,
  CURLUE_NO_ZONEID,
  CURLUE_BAD_FILE_URL,
  CURLUE_BAD_FRAGMENT,
  CURLUE_BAD_HOSTNAME,
  CURLUE_BAD_IPV6,
  CURLUE_BAD_LOGIN,
  CURLUE_BAD_PASSWORD,
  CURLUE_BAD_PATH,
  CURLUE_BAD_QUERY,
  CURLUE_BAD_SCHEME,
  CURLUE_BAD_SLASHES,
  CURLUE_BAD_USER,
  CURLUE_LAST
} CURLUcode;
typedef enum {
  CURLUPART_URL,
  CURLUPART_SCHEME,
  CURLUPART_USER,
  CURLUPART_PASSWORD,
  CURLUPART_OPTIONS,
  CURLUPART_HOST,
  CURLUPART_PORT,
  CURLUPART_PATH,
  CURLUPART_QUERY,
  CURLUPART_FRAGMENT,
  CURLUPART_ZONEID
} CURLUPart;
typedef struct Curl_URL CURLU;
CURLU *curl_url(void);
void curl_url_cleanup(CURLU *handle);
CURLU *curl_url_dup(CURLU *in);
CURLUcode curl_url_get(CURLU *handle, CURLUPart what, char **part,
                       unsigned int flags);
CURLUcode curl_url_set(CURLU *handle, CURLUPart what, const char *part,
                       unsigned int flags);
const char *curl_url_strerror(CURLUcode);
typedef enum {
  CURLOT_LONG,
  CURLOT_VALUES,
  CURLOT_OFF_T,
  CURLOT_OBJECT,
  CURLOT_STRING,
  CURLOT_SLIST,
  CURLOT_CBPTR,
  CURLOT_BLOB,
  CURLOT_FUNCTION
} curl_easytype;
struct curl_easyoption {
  const char *name;
  CURLoption id;
  curl_easytype type;
  unsigned int flags;
};
const struct curl_easyoption *curl_easy_option_by_name(const char *name);
const struct curl_easyoption *curl_easy_option_by_id(CURLoption id);
const struct curl_easyoption *
curl_easy_option_next(const struct curl_easyoption *prev);
static void __attribute__((
    __warning__("curl_easy_setopt expects a long argument for this option")))
__attribute__((__unused__)) __attribute__((__noinline__))
_curl_easy_setopt_err_long(void) {
  __asm__("");
}
static void __attribute__((__warning__(
    "curl_easy_setopt expects a curl_off_t argument for this option")))
__attribute__((__unused__)) __attribute__((__noinline__))
_curl_easy_setopt_err_curl_off_t(void) {
  __asm__("");
}
static void __attribute__((
    __warning__("curl_easy_setopt expects a "
                "string ('char *' or char[]) argument for this option")))
__attribute__((__unused__)) __attribute__((__noinline__))
_curl_easy_setopt_err_string(void) {
  __asm__("");
}
static void __attribute__((__warning__(
    "curl_easy_setopt expects a curl_write_callback argument for this option")))
__attribute__((__unused__)) __attribute__((__noinline__))
_curl_easy_setopt_err_write_callback(void) {
  __asm__("");
}
static void __attribute__((
    __warning__("curl_easy_setopt expects a "
                "curl_resolver_start_callback argument for this option")))
__attribute__((__unused__)) __attribute__((__noinline__))
_curl_easy_setopt_err_resolver_start_callback(void) {
  __asm__("");
}
static void __attribute__((__warning__(
    "curl_easy_setopt expects a curl_read_callback argument for this option")))
__attribute__((__unused__)) __attribute__((__noinline__))
_curl_easy_setopt_err_read_cb(void) {
  __asm__("");
}
static void __attribute__((__warning__(
    "curl_easy_setopt expects a curl_ioctl_callback argument for this option")))
__attribute__((__unused__)) __attribute__((__noinline__))
_curl_easy_setopt_err_ioctl_cb(void) {
  __asm__("");
}
static void __attribute__((
    __warning__("curl_easy_setopt expects a curl_sockopt_callback argument for "
                "this option"))) __attribute__((__unused__))
__attribute__((__noinline__)) _curl_easy_setopt_err_sockopt_cb(void) {
  __asm__("");
}
static void __attribute__((
    __warning__("curl_easy_setopt expects a "
                "curl_opensocket_callback argument for this option")))
__attribute__((__unused__)) __attribute__((__noinline__))
_curl_easy_setopt_err_opensocket_cb(void) {
  __asm__("");
}
static void __attribute__((
    __warning__("curl_easy_setopt expects a curl_progress_callback argument "
                "for this option"))) __attribute__((__unused__))
__attribute__((__noinline__)) _curl_easy_setopt_err_progress_cb(void) {
  __asm__("");
}
static void __attribute__((__warning__(
    "curl_easy_setopt expects a curl_debug_callback argument for this option")))
__attribute__((__unused__)) __attribute__((__noinline__))
_curl_easy_setopt_err_debug_cb(void) {
  __asm__("");
}
static void __attribute__((
    __warning__("curl_easy_setopt expects a curl_ssl_ctx_callback argument for "
                "this option"))) __attribute__((__unused__))
__attribute__((__noinline__)) _curl_easy_setopt_err_ssl_ctx_cb(void) {
  __asm__("");
}
static void __attribute__((__warning__(
    "curl_easy_setopt expects a curl_conv_callback argument for this option")))
__attribute__((__unused__)) __attribute__((__noinline__))
_curl_easy_setopt_err_conv_cb(void) {
  __asm__("");
}
static void __attribute__((__warning__(
    "curl_easy_setopt expects a curl_seek_callback argument for this option")))
__attribute__((__unused__)) __attribute__((__noinline__))
_curl_easy_setopt_err_seek_cb(void) {
  __asm__("");
}
static void __attribute__((
    __warning__("curl_easy_setopt expects a "
                "private data pointer as argument for this option")))
__attribute__((__unused__)) __attribute__((__noinline__))
_curl_easy_setopt_err_cb_data(void) {
  __asm__("");
}
static void __attribute__((
    __warning__("curl_easy_setopt expects a "
                "char buffer of CURL_ERROR_SIZE as argument for this option")))
__attribute__((__unused__)) __attribute__((__noinline__))
_curl_easy_setopt_err_error_buffer(void) {
  __asm__("");
}
static void __attribute__((__warning__(
    "curl_easy_setopt expects a 'FILE *' argument for this option")))
__attribute__((__unused__)) __attribute__((__noinline__))
_curl_easy_setopt_err_FILE(void) {
  __asm__("");
}
static void __attribute__((__warning__("curl_easy_setopt expects a 'void *' or "
                                       "'char *' argument for this option")))
__attribute__((__unused__)) __attribute__((__noinline__))
_curl_easy_setopt_err_postfields(void) {
  __asm__("");
}
static void __attribute__((
    __warning__("curl_easy_setopt expects a 'struct curl_httppost *' "
                "argument for this option"))) __attribute__((__unused__))
__attribute__((__noinline__)) _curl_easy_setopt_err_curl_httpost(void) {
  __asm__("");
}
static void
    __attribute__((__warning__("curl_easy_setopt expects a 'curl_mime *' "
                               "argument for this option")))
    __attribute__((__unused__)) __attribute__((__noinline__))
    _curl_easy_setopt_err_curl_mimepost(void) {
  __asm__("");
}
static void
    __attribute__((__warning__("curl_easy_setopt expects a 'struct curl_slist "
                               "*' argument for this option")))
    __attribute__((__unused__)) __attribute__((__noinline__))
    _curl_easy_setopt_err_curl_slist(void) {
  __asm__("");
}
static void __attribute__((
    __warning__("curl_easy_setopt expects a CURLSH* argument for this option")))
__attribute__((__unused__)) __attribute__((__noinline__))
_curl_easy_setopt_err_CURLSH(void) {
  __asm__("");
}
static void __attribute__((__warning__(
    "curl_easy_getinfo expects a pointer to 'char *' for this info")))
__attribute__((__unused__)) __attribute__((__noinline__))
_curl_easy_getinfo_err_string(void) {
  __asm__("");
}
static void __attribute__((
    __warning__("curl_easy_getinfo expects a pointer to long for this info")))
__attribute__((__unused__)) __attribute__((__noinline__))
_curl_easy_getinfo_err_long(void) {
  __asm__("");
}
static void __attribute__((
    __warning__("curl_easy_getinfo expects a pointer to double for this info")))
__attribute__((__unused__)) __attribute__((__noinline__))
_curl_easy_getinfo_err_double(void) {
  __asm__("");
}
static void __attribute__((__warning__("curl_easy_getinfo expects a pointer to "
                                       "'struct curl_slist *' for this info")))
__attribute__((__unused__)) __attribute__((__noinline__))
_curl_easy_getinfo_err_curl_slist(void) {
  __asm__("");
}
static void
    __attribute__((__warning__("curl_easy_getinfo expects a pointer to "
                               "'struct curl_tlssessioninfo *' for this info")))
    __attribute__((__unused__)) __attribute__((__noinline__))
    _curl_easy_getinfo_err_curl_tlssesssioninfo(void) {
  __asm__("");
}
static void
    __attribute__((__warning__("curl_easy_getinfo expects a pointer to "
                               "'struct curl_certinfo *' for this info")))
    __attribute__((__unused__)) __attribute__((__noinline__))
    _curl_easy_getinfo_err_curl_certinfo(void) {
  __asm__("");
}
static void __attribute__((__warning__(
    "curl_easy_getinfo expects a pointer to curl_socket_t for this info")))
__attribute__((__unused__)) __attribute__((__noinline__))
_curl_easy_getinfo_err_curl_socket(void) {
  __asm__("");
}
static void __attribute__((__warning__(
    "curl_easy_getinfo expects a pointer to curl_off_t for this info")))
__attribute__((__unused__)) __attribute__((__noinline__))
_curl_easy_getinfo_err_curl_off_t(void) {
  __asm__("");
}
typedef size_t (*_curl_read_callback1)(char *, size_t, size_t, void *);
typedef size_t (*_curl_read_callback2)(char *, size_t, size_t, const void *);
typedef size_t (*_curl_read_callback3)(char *, size_t, size_t, FILE *);
typedef size_t (*_curl_read_callback4)(void *, size_t, size_t, void *);
typedef size_t (*_curl_read_callback5)(void *, size_t, size_t, const void *);
typedef size_t (*_curl_read_callback6)(void *, size_t, size_t, FILE *);
typedef size_t (*_curl_write_callback1)(const char *, size_t, size_t, void *);
typedef size_t (*_curl_write_callback2)(const char *, size_t, size_t,
                                        const void *);
typedef size_t (*_curl_write_callback3)(const char *, size_t, size_t, FILE *);
typedef size_t (*_curl_write_callback4)(const void *, size_t, size_t, void *);
typedef size_t (*_curl_write_callback5)(const void *, size_t, size_t,
                                        const void *);
typedef size_t (*_curl_write_callback6)(const void *, size_t, size_t, FILE *);
typedef curlioerr (*_curl_ioctl_callback1)(CURL *, int, void *);
typedef curlioerr (*_curl_ioctl_callback2)(CURL *, int, const void *);
typedef curlioerr (*_curl_ioctl_callback3)(CURL *, curliocmd, void *);
typedef curlioerr (*_curl_ioctl_callback4)(CURL *, curliocmd, const void *);
typedef int (*_curl_sockopt_callback1)(void *, curl_socket_t, curlsocktype);
typedef int (*_curl_sockopt_callback2)(const void *, curl_socket_t,
                                       curlsocktype);
typedef curl_socket_t (*_curl_opensocket_callback1)(void *, curlsocktype,
                                                    struct curl_sockaddr *);
typedef curl_socket_t (*_curl_opensocket_callback2)(
    void *, curlsocktype, const struct curl_sockaddr *);
typedef curl_socket_t (*_curl_opensocket_callback3)(const void *, curlsocktype,
                                                    struct curl_sockaddr *);
typedef curl_socket_t (*_curl_opensocket_callback4)(
    const void *, curlsocktype, const struct curl_sockaddr *);
typedef int (*_curl_progress_callback1)(void *, double, double, double, double);
typedef int (*_curl_progress_callback2)(const void *, double, double, double,
                                        double);
typedef int (*_curl_debug_callback1)(CURL *, curl_infotype, char *, size_t,
                                     void *);
typedef int (*_curl_debug_callback2)(CURL *, curl_infotype, char *, size_t,
                                     const void *);
typedef int (*_curl_debug_callback3)(CURL *, curl_infotype, const char *,
                                     size_t, void *);
typedef int (*_curl_debug_callback4)(CURL *, curl_infotype, const char *,
                                     size_t, const void *);
typedef int (*_curl_debug_callback5)(CURL *, curl_infotype, unsigned char *,
                                     size_t, void *);
typedef int (*_curl_debug_callback6)(CURL *, curl_infotype, unsigned char *,
                                     size_t, const void *);
typedef int (*_curl_debug_callback7)(CURL *, curl_infotype,
                                     const unsigned char *, size_t, void *);
typedef int (*_curl_debug_callback8)(CURL *, curl_infotype,
                                     const unsigned char *, size_t,
                                     const void *);
typedef CURLcode (*_curl_ssl_ctx_callback1)(CURL *, void *, void *);
typedef CURLcode (*_curl_ssl_ctx_callback2)(CURL *, void *, const void *);
typedef CURLcode (*_curl_ssl_ctx_callback3)(CURL *, const void *, void *);
typedef CURLcode (*_curl_ssl_ctx_callback4)(CURL *, const void *, const void *);
typedef _curl_ssl_ctx_callback1 _curl_ssl_ctx_callback5;
typedef _curl_ssl_ctx_callback1 _curl_ssl_ctx_callback6;
typedef _curl_ssl_ctx_callback1 _curl_ssl_ctx_callback7;
typedef _curl_ssl_ctx_callback1 _curl_ssl_ctx_callback8;
typedef CURLcode (*_curl_conv_callback1)(char *, size_t length);
typedef CURLcode (*_curl_conv_callback2)(const char *, size_t length);
typedef CURLcode (*_curl_conv_callback3)(void *, size_t length);
typedef CURLcode (*_curl_conv_callback4)(const void *, size_t length);
typedef CURLcode (*_curl_seek_callback1)(void *, curl_off_t, int);
typedef CURLcode (*_curl_seek_callback2)(const void *, curl_off_t, int);
int main(void) {
  CURL *curl;
  CURLcode res;
  curl_global_init(((1 << 0) | (1 << 1)));
  curl = curl_easy_init();
  if (curl) {
    __extension__({
      __typeof__(CURLOPT_URL) _curl_opt = CURLOPT_URL;
      if (__builtin_constant_p(_curl_opt)) {
        if ((0 < (_curl_opt) && (_curl_opt) < 10000))
          if (!(__builtin_types_compatible_p(__typeof__("https://example.com"),
                                             long) ||
                __builtin_types_compatible_p(__typeof__("https://example.com"),
                                             signed long) ||
                __builtin_types_compatible_p(__typeof__("https://example.com"),
                                             unsigned long) ||
                __builtin_types_compatible_p(__typeof__("https://example.com"),
                                             int) ||
                __builtin_types_compatible_p(__typeof__("https://example.com"),
                                             signed int) ||
                __builtin_types_compatible_p(__typeof__("https://example.com"),
                                             unsigned int) ||
                __builtin_types_compatible_p(__typeof__("https://example.com"),
                                             short) ||
                __builtin_types_compatible_p(__typeof__("https://example.com"),
                                             signed short) ||
                __builtin_types_compatible_p(__typeof__("https://example.com"),
                                             unsigned short) ||
                __builtin_types_compatible_p(__typeof__("https://example.com"),
                                             char) ||
                __builtin_types_compatible_p(__typeof__("https://example.com"),
                                             signed char) ||
                __builtin_types_compatible_p(__typeof__("https://example.com"),
                                             unsigned char)))
            _curl_easy_setopt_err_long();
        if ((((_curl_opt) > 30000) && ((_curl_opt) < 40000)))
          if (!(__builtin_types_compatible_p(__typeof__("https://example.com"),
                                             curl_off_t)))
            _curl_easy_setopt_err_curl_off_t();
        if (((_curl_opt) == CURLOPT_ABSTRACT_UNIX_SOCKET ||
             (_curl_opt) == CURLOPT_ACCEPT_ENCODING ||
             (_curl_opt) == CURLOPT_ALTSVC || (_curl_opt) == CURLOPT_CAINFO ||
             (_curl_opt) == CURLOPT_CAPATH || (_curl_opt) == CURLOPT_COOKIE ||
             (_curl_opt) == CURLOPT_COOKIEFILE ||
             (_curl_opt) == CURLOPT_COOKIEJAR ||
             (_curl_opt) == CURLOPT_COOKIELIST ||
             (_curl_opt) == CURLOPT_CRLFILE ||
             (_curl_opt) == CURLOPT_CUSTOMREQUEST ||
             (_curl_opt) == CURLOPT_DEFAULT_PROTOCOL ||
             (_curl_opt) == CURLOPT_DNS_INTERFACE ||
             (_curl_opt) == CURLOPT_DNS_LOCAL_IP4 ||
             (_curl_opt) == CURLOPT_DNS_LOCAL_IP6 ||
             (_curl_opt) == CURLOPT_DNS_SERVERS ||
             (_curl_opt) == CURLOPT_DOH_URL ||
             (_curl_opt) == CURLOPT_EGDSOCKET ||
             (_curl_opt) == CURLOPT_FTPPORT ||
             (_curl_opt) == CURLOPT_FTP_ACCOUNT ||
             (_curl_opt) == CURLOPT_FTP_ALTERNATIVE_TO_USER ||
             (_curl_opt) == CURLOPT_HSTS || (_curl_opt) == CURLOPT_INTERFACE ||
             (_curl_opt) == CURLOPT_ISSUERCERT ||
             (_curl_opt) == CURLOPT_KEYPASSWD ||
             (_curl_opt) == CURLOPT_KRBLEVEL ||
             (_curl_opt) == CURLOPT_LOGIN_OPTIONS ||
             (_curl_opt) == CURLOPT_MAIL_AUTH ||
             (_curl_opt) == CURLOPT_MAIL_FROM ||
             (_curl_opt) == CURLOPT_NETRC_FILE ||
             (_curl_opt) == CURLOPT_NOPROXY ||
             (_curl_opt) == CURLOPT_PASSWORD ||
             (_curl_opt) == CURLOPT_PINNEDPUBLICKEY ||
             (_curl_opt) == CURLOPT_PRE_PROXY || (_curl_opt) == CURLOPT_PROXY ||
             (_curl_opt) == CURLOPT_PROXYPASSWORD ||
             (_curl_opt) == CURLOPT_PROXYUSERNAME ||
             (_curl_opt) == CURLOPT_PROXYUSERPWD ||
             (_curl_opt) == CURLOPT_PROXY_CAINFO ||
             (_curl_opt) == CURLOPT_PROXY_CAPATH ||
             (_curl_opt) == CURLOPT_PROXY_CRLFILE ||
             (_curl_opt) == CURLOPT_PROXY_ISSUERCERT ||
             (_curl_opt) == CURLOPT_PROXY_KEYPASSWD ||
             (_curl_opt) == CURLOPT_PROXY_PINNEDPUBLICKEY ||
             (_curl_opt) == CURLOPT_PROXY_SERVICE_NAME ||
             (_curl_opt) == CURLOPT_PROXY_SSLCERT ||
             (_curl_opt) == CURLOPT_PROXY_SSLCERTTYPE ||
             (_curl_opt) == CURLOPT_PROXY_SSLKEY ||
             (_curl_opt) == CURLOPT_PROXY_SSLKEYTYPE ||
             (_curl_opt) == CURLOPT_PROXY_SSL_CIPHER_LIST ||
             (_curl_opt) == CURLOPT_PROXY_TLS13_CIPHERS ||
             (_curl_opt) == CURLOPT_PROXY_TLSAUTH_PASSWORD ||
             (_curl_opt) == CURLOPT_PROXY_TLSAUTH_TYPE ||
             (_curl_opt) == CURLOPT_PROXY_TLSAUTH_USERNAME ||
             (_curl_opt) == CURLOPT_RANDOM_FILE ||
             (_curl_opt) == CURLOPT_RANGE || (_curl_opt) == CURLOPT_REFERER ||
             (_curl_opt) == CURLOPT_REQUEST_TARGET ||
             (_curl_opt) == CURLOPT_RTSP_SESSION_ID ||
             (_curl_opt) == CURLOPT_RTSP_STREAM_URI ||
             (_curl_opt) == CURLOPT_RTSP_TRANSPORT ||
             (_curl_opt) == CURLOPT_SASL_AUTHZID ||
             (_curl_opt) == CURLOPT_SERVICE_NAME ||
             (_curl_opt) == CURLOPT_SOCKS5_GSSAPI_SERVICE ||
             (_curl_opt) == CURLOPT_SSH_HOST_PUBLIC_KEY_MD5 ||
             (_curl_opt) == CURLOPT_SSH_HOST_PUBLIC_KEY_SHA256 ||
             (_curl_opt) == CURLOPT_SSH_KNOWNHOSTS ||
             (_curl_opt) == CURLOPT_SSH_PRIVATE_KEYFILE ||
             (_curl_opt) == CURLOPT_SSH_PUBLIC_KEYFILE ||
             (_curl_opt) == CURLOPT_SSLCERT ||
             (_curl_opt) == CURLOPT_SSLCERTTYPE ||
             (_curl_opt) == CURLOPT_SSLENGINE ||
             (_curl_opt) == CURLOPT_SSLKEY ||
             (_curl_opt) == CURLOPT_SSLKEYTYPE ||
             (_curl_opt) == CURLOPT_SSL_CIPHER_LIST ||
             (_curl_opt) == CURLOPT_TLS13_CIPHERS ||
             (_curl_opt) == CURLOPT_TLSAUTH_PASSWORD ||
             (_curl_opt) == CURLOPT_TLSAUTH_TYPE ||
             (_curl_opt) == CURLOPT_TLSAUTH_USERNAME ||
             (_curl_opt) == CURLOPT_UNIX_SOCKET_PATH ||
             (_curl_opt) == CURLOPT_URL || (_curl_opt) == CURLOPT_USERAGENT ||
             (_curl_opt) == CURLOPT_USERNAME ||
             (_curl_opt) == CURLOPT_AWS_SIGV4 ||
             (_curl_opt) == CURLOPT_USERPWD ||
             (_curl_opt) == CURLOPT_XOAUTH2_BEARER ||
             (_curl_opt) == CURLOPT_SSL_EC_CURVES || 0))
          if (!((((__builtin_types_compatible_p(
                      __typeof__((("https://example.com"))),
                      __typeof__(((void *)0)))) ||
                  __builtin_types_compatible_p(
                      __typeof__((("https://example.com"))), char *) ||
                  __builtin_types_compatible_p(
                      __typeof__((("https://example.com"))), const char *)) ||
                 __builtin_types_compatible_p(
                     __typeof__(("https://example.com")), char[])) ||
                (((__builtin_types_compatible_p(
                      __typeof__((("https://example.com"))),
                      __typeof__(((void *)0)))) ||
                  __builtin_types_compatible_p(
                      __typeof__((("https://example.com"))), signed char *) ||
                  __builtin_types_compatible_p(
                      __typeof__((("https://example.com"))),
                      const signed char *)) ||
                 __builtin_types_compatible_p(
                     __typeof__(("https://example.com")), signed char[])) ||
                (((__builtin_types_compatible_p(
                      __typeof__((("https://example.com"))),
                      __typeof__(((void *)0)))) ||
                  __builtin_types_compatible_p(
                      __typeof__((("https://example.com"))), unsigned char *) ||
                  __builtin_types_compatible_p(
                      __typeof__((("https://example.com"))),
                      const unsigned char *)) ||
                 __builtin_types_compatible_p(
                     __typeof__(("https://example.com")), unsigned char[]))))
            _curl_easy_setopt_err_string();
        if (((_curl_opt) == CURLOPT_HEADERFUNCTION ||
             (_curl_opt) == CURLOPT_WRITEFUNCTION))
          if (!(((__builtin_types_compatible_p(
                     __typeof__("https://example.com"),
                     __typeof__(((void *)0)))) ||
                 (__builtin_types_compatible_p(
                      __typeof__(("https://example.com")),
                      __typeof__(fread) *) ||
                  __builtin_types_compatible_p(
                      __typeof__(("https://example.com")) *,
                      __typeof__(fread) *)) ||
                 (__builtin_types_compatible_p(
                      __typeof__(("https://example.com")),
                      curl_read_callback) ||
                  __builtin_types_compatible_p(
                      __typeof__(("https://example.com")) *,
                      curl_read_callback)) ||
                 (__builtin_types_compatible_p(
                      __typeof__(("https://example.com")),
                      _curl_read_callback1) ||
                  __builtin_types_compatible_p(
                      __typeof__(("https://example.com")) *,
                      _curl_read_callback1)) ||
                 (__builtin_types_compatible_p(
                      __typeof__(("https://example.com")),
                      _curl_read_callback2) ||
                  __builtin_types_compatible_p(
                      __typeof__(("https://example.com")) *,
                      _curl_read_callback2)) ||
                 (__builtin_types_compatible_p(
                      __typeof__(("https://example.com")),
                      _curl_read_callback3) ||
                  __builtin_types_compatible_p(
                      __typeof__(("https://example.com")) *,
                      _curl_read_callback3)) ||
                 (__builtin_types_compatible_p(
                      __typeof__(("https://example.com")),
                      _curl_read_callback4) ||
                  __builtin_types_compatible_p(
                      __typeof__(("https://example.com")) *,
                      _curl_read_callback4)) ||
                 (__builtin_types_compatible_p(
                      __typeof__(("https://example.com")),
                      _curl_read_callback5) ||
                  __builtin_types_compatible_p(
                      __typeof__(("https://example.com")) *,
                      _curl_read_callback5)) ||
                 (__builtin_types_compatible_p(
                      __typeof__(("https://example.com")),
                      _curl_read_callback6) ||
                  __builtin_types_compatible_p(
                      __typeof__(("https://example.com")) *,
                      _curl_read_callback6))) ||
                (__builtin_types_compatible_p(
                     __typeof__(("https://example.com")),
                     __typeof__(fwrite) *) ||
                 __builtin_types_compatible_p(
                     __typeof__(("https://example.com")) *,
                     __typeof__(fwrite) *)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("https://example.com")),
                     curl_write_callback) ||
                 __builtin_types_compatible_p(
                     __typeof__(("https://example.com")) *,
                     curl_write_callback)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("https://example.com")),
                     _curl_write_callback1) ||
                 __builtin_types_compatible_p(
                     __typeof__(("https://example.com")) *,
                     _curl_write_callback1)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("https://example.com")),
                     _curl_write_callback2) ||
                 __builtin_types_compatible_p(
                     __typeof__(("https://example.com")) *,
                     _curl_write_callback2)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("https://example.com")),
                     _curl_write_callback3) ||
                 __builtin_types_compatible_p(
                     __typeof__(("https://example.com")) *,
                     _curl_write_callback3)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("https://example.com")),
                     _curl_write_callback4) ||
                 __builtin_types_compatible_p(
                     __typeof__(("https://example.com")) *,
                     _curl_write_callback4)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("https://example.com")),
                     _curl_write_callback5) ||
                 __builtin_types_compatible_p(
                     __typeof__(("https://example.com")) *,
                     _curl_write_callback5)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("https://example.com")),
                     _curl_write_callback6) ||
                 __builtin_types_compatible_p(
                     __typeof__(("https://example.com")) *,
                     _curl_write_callback6))))
            _curl_easy_setopt_err_write_callback();
        if ((_curl_opt) == CURLOPT_RESOLVER_START_FUNCTION)
          if (!((__builtin_types_compatible_p(__typeof__("https://example.com"),
                                              __typeof__(((void *)0)))) ||
                (__builtin_types_compatible_p(
                     __typeof__(("https://example.com")),
                     curl_resolver_start_callback) ||
                 __builtin_types_compatible_p(
                     __typeof__(("https://example.com")) *,
                     curl_resolver_start_callback))))
            _curl_easy_setopt_err_resolver_start_callback();
        if ((_curl_opt) == CURLOPT_READFUNCTION)
          if (!((__builtin_types_compatible_p(__typeof__("https://example.com"),
                                              __typeof__(((void *)0)))) ||
                (__builtin_types_compatible_p(
                     __typeof__(("https://example.com")),
                     __typeof__(fread) *) ||
                 __builtin_types_compatible_p(
                     __typeof__(("https://example.com")) *,
                     __typeof__(fread) *)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("https://example.com")), curl_read_callback) ||
                 __builtin_types_compatible_p(
                     __typeof__(("https://example.com")) *,
                     curl_read_callback)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("https://example.com")),
                     _curl_read_callback1) ||
                 __builtin_types_compatible_p(
                     __typeof__(("https://example.com")) *,
                     _curl_read_callback1)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("https://example.com")),
                     _curl_read_callback2) ||
                 __builtin_types_compatible_p(
                     __typeof__(("https://example.com")) *,
                     _curl_read_callback2)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("https://example.com")),
                     _curl_read_callback3) ||
                 __builtin_types_compatible_p(
                     __typeof__(("https://example.com")) *,
                     _curl_read_callback3)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("https://example.com")),
                     _curl_read_callback4) ||
                 __builtin_types_compatible_p(
                     __typeof__(("https://example.com")) *,
                     _curl_read_callback4)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("https://example.com")),
                     _curl_read_callback5) ||
                 __builtin_types_compatible_p(
                     __typeof__(("https://example.com")) *,
                     _curl_read_callback5)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("https://example.com")),
                     _curl_read_callback6) ||
                 __builtin_types_compatible_p(
                     __typeof__(("https://example.com")) *,
                     _curl_read_callback6))))
            _curl_easy_setopt_err_read_cb();
        if ((_curl_opt) == CURLOPT_IOCTLFUNCTION)
          if (!((__builtin_types_compatible_p(__typeof__("https://example.com"),
                                              __typeof__(((void *)0)))) ||
                (__builtin_types_compatible_p(
                     __typeof__(("https://example.com")),
                     curl_ioctl_callback) ||
                 __builtin_types_compatible_p(
                     __typeof__(("https://example.com")) *,
                     curl_ioctl_callback)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("https://example.com")),
                     _curl_ioctl_callback1) ||
                 __builtin_types_compatible_p(
                     __typeof__(("https://example.com")) *,
                     _curl_ioctl_callback1)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("https://example.com")),
                     _curl_ioctl_callback2) ||
                 __builtin_types_compatible_p(
                     __typeof__(("https://example.com")) *,
                     _curl_ioctl_callback2)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("https://example.com")),
                     _curl_ioctl_callback3) ||
                 __builtin_types_compatible_p(
                     __typeof__(("https://example.com")) *,
                     _curl_ioctl_callback3)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("https://example.com")),
                     _curl_ioctl_callback4) ||
                 __builtin_types_compatible_p(
                     __typeof__(("https://example.com")) *,
                     _curl_ioctl_callback4))))
            _curl_easy_setopt_err_ioctl_cb();
        if ((_curl_opt) == CURLOPT_SOCKOPTFUNCTION)
          if (!((__builtin_types_compatible_p(__typeof__("https://example.com"),
                                              __typeof__(((void *)0)))) ||
                (__builtin_types_compatible_p(
                     __typeof__(("https://example.com")),
                     curl_sockopt_callback) ||
                 __builtin_types_compatible_p(
                     __typeof__(("https://example.com")) *,
                     curl_sockopt_callback)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("https://example.com")),
                     _curl_sockopt_callback1) ||
                 __builtin_types_compatible_p(
                     __typeof__(("https://example.com")) *,
                     _curl_sockopt_callback1)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("https://example.com")),
                     _curl_sockopt_callback2) ||
                 __builtin_types_compatible_p(
                     __typeof__(("https://example.com")) *,
                     _curl_sockopt_callback2))))
            _curl_easy_setopt_err_sockopt_cb();
        if ((_curl_opt) == CURLOPT_OPENSOCKETFUNCTION)
          if (!((__builtin_types_compatible_p(__typeof__("https://example.com"),
                                              __typeof__(((void *)0)))) ||
                (__builtin_types_compatible_p(
                     __typeof__(("https://example.com")),
                     curl_opensocket_callback) ||
                 __builtin_types_compatible_p(
                     __typeof__(("https://example.com")) *,
                     curl_opensocket_callback)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("https://example.com")),
                     _curl_opensocket_callback1) ||
                 __builtin_types_compatible_p(
                     __typeof__(("https://example.com")) *,
                     _curl_opensocket_callback1)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("https://example.com")),
                     _curl_opensocket_callback2) ||
                 __builtin_types_compatible_p(
                     __typeof__(("https://example.com")) *,
                     _curl_opensocket_callback2)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("https://example.com")),
                     _curl_opensocket_callback3) ||
                 __builtin_types_compatible_p(
                     __typeof__(("https://example.com")) *,
                     _curl_opensocket_callback3)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("https://example.com")),
                     _curl_opensocket_callback4) ||
                 __builtin_types_compatible_p(
                     __typeof__(("https://example.com")) *,
                     _curl_opensocket_callback4))))
            _curl_easy_setopt_err_opensocket_cb();
        if ((_curl_opt) == CURLOPT_PROGRESSFUNCTION)
          if (!((__builtin_types_compatible_p(__typeof__("https://example.com"),
                                              __typeof__(((void *)0)))) ||
                (__builtin_types_compatible_p(
                     __typeof__(("https://example.com")),
                     curl_progress_callback) ||
                 __builtin_types_compatible_p(
                     __typeof__(("https://example.com")) *,
                     curl_progress_callback)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("https://example.com")),
                     _curl_progress_callback1) ||
                 __builtin_types_compatible_p(
                     __typeof__(("https://example.com")) *,
                     _curl_progress_callback1)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("https://example.com")),
                     _curl_progress_callback2) ||
                 __builtin_types_compatible_p(
                     __typeof__(("https://example.com")) *,
                     _curl_progress_callback2))))
            _curl_easy_setopt_err_progress_cb();
        if ((_curl_opt) == CURLOPT_DEBUGFUNCTION)
          if (!((__builtin_types_compatible_p(__typeof__("https://example.com"),
                                              __typeof__(((void *)0)))) ||
                (__builtin_types_compatible_p(
                     __typeof__(("https://example.com")),
                     curl_debug_callback) ||
                 __builtin_types_compatible_p(
                     __typeof__(("https://example.com")) *,
                     curl_debug_callback)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("https://example.com")),
                     _curl_debug_callback1) ||
                 __builtin_types_compatible_p(
                     __typeof__(("https://example.com")) *,
                     _curl_debug_callback1)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("https://example.com")),
                     _curl_debug_callback2) ||
                 __builtin_types_compatible_p(
                     __typeof__(("https://example.com")) *,
                     _curl_debug_callback2)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("https://example.com")),
                     _curl_debug_callback3) ||
                 __builtin_types_compatible_p(
                     __typeof__(("https://example.com")) *,
                     _curl_debug_callback3)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("https://example.com")),
                     _curl_debug_callback4) ||
                 __builtin_types_compatible_p(
                     __typeof__(("https://example.com")) *,
                     _curl_debug_callback4)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("https://example.com")),
                     _curl_debug_callback5) ||
                 __builtin_types_compatible_p(
                     __typeof__(("https://example.com")) *,
                     _curl_debug_callback5)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("https://example.com")),
                     _curl_debug_callback6) ||
                 __builtin_types_compatible_p(
                     __typeof__(("https://example.com")) *,
                     _curl_debug_callback6)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("https://example.com")),
                     _curl_debug_callback7) ||
                 __builtin_types_compatible_p(
                     __typeof__(("https://example.com")) *,
                     _curl_debug_callback7)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("https://example.com")),
                     _curl_debug_callback8) ||
                 __builtin_types_compatible_p(
                     __typeof__(("https://example.com")) *,
                     _curl_debug_callback8))))
            _curl_easy_setopt_err_debug_cb();
        if ((_curl_opt) == CURLOPT_SSL_CTX_FUNCTION)
          if (!((__builtin_types_compatible_p(__typeof__("https://example.com"),
                                              __typeof__(((void *)0)))) ||
                (__builtin_types_compatible_p(
                     __typeof__(("https://example.com")),
                     curl_ssl_ctx_callback) ||
                 __builtin_types_compatible_p(
                     __typeof__(("https://example.com")) *,
                     curl_ssl_ctx_callback)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("https://example.com")),
                     _curl_ssl_ctx_callback1) ||
                 __builtin_types_compatible_p(
                     __typeof__(("https://example.com")) *,
                     _curl_ssl_ctx_callback1)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("https://example.com")),
                     _curl_ssl_ctx_callback2) ||
                 __builtin_types_compatible_p(
                     __typeof__(("https://example.com")) *,
                     _curl_ssl_ctx_callback2)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("https://example.com")),
                     _curl_ssl_ctx_callback3) ||
                 __builtin_types_compatible_p(
                     __typeof__(("https://example.com")) *,
                     _curl_ssl_ctx_callback3)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("https://example.com")),
                     _curl_ssl_ctx_callback4) ||
                 __builtin_types_compatible_p(
                     __typeof__(("https://example.com")) *,
                     _curl_ssl_ctx_callback4)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("https://example.com")),
                     _curl_ssl_ctx_callback5) ||
                 __builtin_types_compatible_p(
                     __typeof__(("https://example.com")) *,
                     _curl_ssl_ctx_callback5)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("https://example.com")),
                     _curl_ssl_ctx_callback6) ||
                 __builtin_types_compatible_p(
                     __typeof__(("https://example.com")) *,
                     _curl_ssl_ctx_callback6)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("https://example.com")),
                     _curl_ssl_ctx_callback7) ||
                 __builtin_types_compatible_p(
                     __typeof__(("https://example.com")) *,
                     _curl_ssl_ctx_callback7)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("https://example.com")),
                     _curl_ssl_ctx_callback8) ||
                 __builtin_types_compatible_p(
                     __typeof__(("https://example.com")) *,
                     _curl_ssl_ctx_callback8))))
            _curl_easy_setopt_err_ssl_ctx_cb();
        if (((_curl_opt) == CURLOPT_CONV_TO_NETWORK_FUNCTION ||
             (_curl_opt) == CURLOPT_CONV_FROM_NETWORK_FUNCTION ||
             (_curl_opt) == CURLOPT_CONV_FROM_UTF8_FUNCTION))
          if (!((__builtin_types_compatible_p(__typeof__("https://example.com"),
                                              __typeof__(((void *)0)))) ||
                (__builtin_types_compatible_p(
                     __typeof__(("https://example.com")), curl_conv_callback) ||
                 __builtin_types_compatible_p(
                     __typeof__(("https://example.com")) *,
                     curl_conv_callback)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("https://example.com")),
                     _curl_conv_callback1) ||
                 __builtin_types_compatible_p(
                     __typeof__(("https://example.com")) *,
                     _curl_conv_callback1)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("https://example.com")),
                     _curl_conv_callback2) ||
                 __builtin_types_compatible_p(
                     __typeof__(("https://example.com")) *,
                     _curl_conv_callback2)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("https://example.com")),
                     _curl_conv_callback3) ||
                 __builtin_types_compatible_p(
                     __typeof__(("https://example.com")) *,
                     _curl_conv_callback3)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("https://example.com")),
                     _curl_conv_callback4) ||
                 __builtin_types_compatible_p(
                     __typeof__(("https://example.com")) *,
                     _curl_conv_callback4))))
            _curl_easy_setopt_err_conv_cb();
        if ((_curl_opt) == CURLOPT_SEEKFUNCTION)
          if (!((__builtin_types_compatible_p(__typeof__("https://example.com"),
                                              __typeof__(((void *)0)))) ||
                (__builtin_types_compatible_p(
                     __typeof__(("https://example.com")), curl_seek_callback) ||
                 __builtin_types_compatible_p(
                     __typeof__(("https://example.com")) *,
                     curl_seek_callback)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("https://example.com")),
                     _curl_seek_callback1) ||
                 __builtin_types_compatible_p(
                     __typeof__(("https://example.com")) *,
                     _curl_seek_callback1)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("https://example.com")),
                     _curl_seek_callback2) ||
                 __builtin_types_compatible_p(
                     __typeof__(("https://example.com")) *,
                     _curl_seek_callback2))))
            _curl_easy_setopt_err_seek_cb();
        if (((_curl_opt) == CURLOPT_CHUNK_DATA ||
             (_curl_opt) == CURLOPT_CLOSESOCKETDATA ||
             (_curl_opt) == CURLOPT_DEBUGDATA ||
             (_curl_opt) == CURLOPT_FNMATCH_DATA ||
             (_curl_opt) == CURLOPT_HEADERDATA ||
             (_curl_opt) == CURLOPT_HSTSREADDATA ||
             (_curl_opt) == CURLOPT_HSTSWRITEDATA ||
             (_curl_opt) == CURLOPT_INTERLEAVEDATA ||
             (_curl_opt) == CURLOPT_IOCTLDATA ||
             (_curl_opt) == CURLOPT_OPENSOCKETDATA ||
             (_curl_opt) == CURLOPT_PREREQDATA ||
             (_curl_opt) == CURLOPT_XFERINFODATA ||
             (_curl_opt) == CURLOPT_READDATA ||
             (_curl_opt) == CURLOPT_SEEKDATA ||
             (_curl_opt) == CURLOPT_SOCKOPTDATA ||
             (_curl_opt) == CURLOPT_SSH_KEYDATA ||
             (_curl_opt) == CURLOPT_SSL_CTX_DATA ||
             (_curl_opt) == CURLOPT_WRITEDATA ||
             (_curl_opt) == CURLOPT_RESOLVER_START_DATA ||
             (_curl_opt) == CURLOPT_TRAILERDATA || 0))
          if (!(sizeof("https://example.com") == sizeof(void *)))
            _curl_easy_setopt_err_cb_data();
        if ((_curl_opt) == CURLOPT_ERRORBUFFER)
          if (!((__builtin_types_compatible_p(__typeof__("https://example.com"),
                                              __typeof__(((void *)0)))) ||
                __builtin_types_compatible_p(__typeof__("https://example.com"),
                                             char *) ||
                __builtin_types_compatible_p(__typeof__("https://example.com"),
                                             char[])))
            _curl_easy_setopt_err_error_buffer();
        if ((_curl_opt) == CURLOPT_STDERR)
          if (!((__builtin_types_compatible_p(__typeof__("https://example.com"),
                                              __typeof__(((void *)0)))) ||
                (__builtin_types_compatible_p(__typeof__("https://example.com"),
                                              FILE *))))
            _curl_easy_setopt_err_FILE();
        if (((_curl_opt) == CURLOPT_POSTFIELDS ||
             (_curl_opt) == CURLOPT_COPYPOSTFIELDS || 0))
          if (!(((__builtin_types_compatible_p(
                     __typeof__(("https://example.com")),
                     __typeof__(((void *)0)))) ||
                 __builtin_types_compatible_p(
                     __typeof__(("https://example.com")), void *) ||
                 __builtin_types_compatible_p(
                     __typeof__(("https://example.com")), const void *)) ||
                (((__builtin_types_compatible_p(
                      __typeof__((("https://example.com"))),
                      __typeof__(((void *)0)))) ||
                  __builtin_types_compatible_p(
                      __typeof__((("https://example.com"))), char *) ||
                  __builtin_types_compatible_p(
                      __typeof__((("https://example.com"))), const char *)) ||
                 __builtin_types_compatible_p(
                     __typeof__(("https://example.com")), char[])) ||
                (((__builtin_types_compatible_p(
                      __typeof__((("https://example.com"))),
                      __typeof__(((void *)0)))) ||
                  __builtin_types_compatible_p(
                      __typeof__((("https://example.com"))), unsigned char *) ||
                  __builtin_types_compatible_p(
                      __typeof__((("https://example.com"))),
                      const unsigned char *)) ||
                 __builtin_types_compatible_p(
                     __typeof__(("https://example.com")), unsigned char[]))))
            _curl_easy_setopt_err_postfields();
        if ((_curl_opt) == CURLOPT_HTTPPOST)
          if (!(((__builtin_types_compatible_p(
                     __typeof__((("https://example.com"))),
                     __typeof__(((void *)0)))) ||
                 __builtin_types_compatible_p(
                     __typeof__((("https://example.com"))),
                     struct curl_httppost *) ||
                 __builtin_types_compatible_p(
                     __typeof__((("https://example.com"))),
                     const struct curl_httppost *)) ||
                __builtin_types_compatible_p(
                    __typeof__(("https://example.com")),
                    struct curl_httppost[])))
            _curl_easy_setopt_err_curl_httpost();
        if ((_curl_opt) == CURLOPT_MIMEPOST)
          if (!((__builtin_types_compatible_p(
                    __typeof__(("https://example.com")),
                    __typeof__(((void *)0)))) ||
                __builtin_types_compatible_p(
                    __typeof__(("https://example.com")), curl_mime *) ||
                __builtin_types_compatible_p(
                    __typeof__(("https://example.com")), const curl_mime *)))
            _curl_easy_setopt_err_curl_mimepost();
        if (((_curl_opt) == CURLOPT_HTTP200ALIASES ||
             (_curl_opt) == CURLOPT_HTTPHEADER ||
             (_curl_opt) == CURLOPT_MAIL_RCPT ||
             (_curl_opt) == CURLOPT_POSTQUOTE ||
             (_curl_opt) == CURLOPT_PREQUOTE ||
             (_curl_opt) == CURLOPT_PROXYHEADER ||
             (_curl_opt) == CURLOPT_QUOTE || (_curl_opt) == CURLOPT_RESOLVE ||
             (_curl_opt) == CURLOPT_TELNETOPTIONS ||
             (_curl_opt) == CURLOPT_CONNECT_TO || 0))
          if (!(((__builtin_types_compatible_p(
                     __typeof__((("https://example.com"))),
                     __typeof__(((void *)0)))) ||
                 __builtin_types_compatible_p(
                     __typeof__((("https://example.com"))),
                     struct curl_slist *) ||
                 __builtin_types_compatible_p(
                     __typeof__((("https://example.com"))),
                     const struct curl_slist *)) ||
                __builtin_types_compatible_p(
                    __typeof__(("https://example.com")), struct curl_slist[])))
            _curl_easy_setopt_err_curl_slist();
        if ((_curl_opt) == CURLOPT_SHARE)
          if (!((__builtin_types_compatible_p(
                    __typeof__(("https://example.com")),
                    __typeof__(((void *)0)))) ||
                __builtin_types_compatible_p(
                    __typeof__(("https://example.com")), CURLSH *) ||
                __builtin_types_compatible_p(
                    __typeof__(("https://example.com")), const CURLSH *)))
            _curl_easy_setopt_err_CURLSH();
      }
      curl_easy_setopt(curl, _curl_opt, "https://example.com");
    });
    __extension__({
      __typeof__(CURLOPT_POSTFIELDS) _curl_opt = CURLOPT_POSTFIELDS;
      if (__builtin_constant_p(_curl_opt)) {
        if ((0 < (_curl_opt) && (_curl_opt) < 10000))
          if (!(__builtin_types_compatible_p(
                    __typeof__("name=daniel&project=curl"), long) ||
                __builtin_types_compatible_p(
                    __typeof__("name=daniel&project=curl"), signed long) ||
                __builtin_types_compatible_p(
                    __typeof__("name=daniel&project=curl"), unsigned long) ||
                __builtin_types_compatible_p(
                    __typeof__("name=daniel&project=curl"), int) ||
                __builtin_types_compatible_p(
                    __typeof__("name=daniel&project=curl"), signed int) ||
                __builtin_types_compatible_p(
                    __typeof__("name=daniel&project=curl"), unsigned int) ||
                __builtin_types_compatible_p(
                    __typeof__("name=daniel&project=curl"), short) ||
                __builtin_types_compatible_p(
                    __typeof__("name=daniel&project=curl"), signed short) ||
                __builtin_types_compatible_p(
                    __typeof__("name=daniel&project=curl"), unsigned short) ||
                __builtin_types_compatible_p(
                    __typeof__("name=daniel&project=curl"), char) ||
                __builtin_types_compatible_p(
                    __typeof__("name=daniel&project=curl"), signed char) ||
                __builtin_types_compatible_p(
                    __typeof__("name=daniel&project=curl"), unsigned char)))
            _curl_easy_setopt_err_long();
        if ((((_curl_opt) > 30000) && ((_curl_opt) < 40000)))
          if (!(__builtin_types_compatible_p(
                  __typeof__("name=daniel&project=curl"), curl_off_t)))
            _curl_easy_setopt_err_curl_off_t();
        if (((_curl_opt) == CURLOPT_ABSTRACT_UNIX_SOCKET ||
             (_curl_opt) == CURLOPT_ACCEPT_ENCODING ||
             (_curl_opt) == CURLOPT_ALTSVC || (_curl_opt) == CURLOPT_CAINFO ||
             (_curl_opt) == CURLOPT_CAPATH || (_curl_opt) == CURLOPT_COOKIE ||
             (_curl_opt) == CURLOPT_COOKIEFILE ||
             (_curl_opt) == CURLOPT_COOKIEJAR ||
             (_curl_opt) == CURLOPT_COOKIELIST ||
             (_curl_opt) == CURLOPT_CRLFILE ||
             (_curl_opt) == CURLOPT_CUSTOMREQUEST ||
             (_curl_opt) == CURLOPT_DEFAULT_PROTOCOL ||
             (_curl_opt) == CURLOPT_DNS_INTERFACE ||
             (_curl_opt) == CURLOPT_DNS_LOCAL_IP4 ||
             (_curl_opt) == CURLOPT_DNS_LOCAL_IP6 ||
             (_curl_opt) == CURLOPT_DNS_SERVERS ||
             (_curl_opt) == CURLOPT_DOH_URL ||
             (_curl_opt) == CURLOPT_EGDSOCKET ||
             (_curl_opt) == CURLOPT_FTPPORT ||
             (_curl_opt) == CURLOPT_FTP_ACCOUNT ||
             (_curl_opt) == CURLOPT_FTP_ALTERNATIVE_TO_USER ||
             (_curl_opt) == CURLOPT_HSTS || (_curl_opt) == CURLOPT_INTERFACE ||
             (_curl_opt) == CURLOPT_ISSUERCERT ||
             (_curl_opt) == CURLOPT_KEYPASSWD ||
             (_curl_opt) == CURLOPT_KRBLEVEL ||
             (_curl_opt) == CURLOPT_LOGIN_OPTIONS ||
             (_curl_opt) == CURLOPT_MAIL_AUTH ||
             (_curl_opt) == CURLOPT_MAIL_FROM ||
             (_curl_opt) == CURLOPT_NETRC_FILE ||
             (_curl_opt) == CURLOPT_NOPROXY ||
             (_curl_opt) == CURLOPT_PASSWORD ||
             (_curl_opt) == CURLOPT_PINNEDPUBLICKEY ||
             (_curl_opt) == CURLOPT_PRE_PROXY || (_curl_opt) == CURLOPT_PROXY ||
             (_curl_opt) == CURLOPT_PROXYPASSWORD ||
             (_curl_opt) == CURLOPT_PROXYUSERNAME ||
             (_curl_opt) == CURLOPT_PROXYUSERPWD ||
             (_curl_opt) == CURLOPT_PROXY_CAINFO ||
             (_curl_opt) == CURLOPT_PROXY_CAPATH ||
             (_curl_opt) == CURLOPT_PROXY_CRLFILE ||
             (_curl_opt) == CURLOPT_PROXY_ISSUERCERT ||
             (_curl_opt) == CURLOPT_PROXY_KEYPASSWD ||
             (_curl_opt) == CURLOPT_PROXY_PINNEDPUBLICKEY ||
             (_curl_opt) == CURLOPT_PROXY_SERVICE_NAME ||
             (_curl_opt) == CURLOPT_PROXY_SSLCERT ||
             (_curl_opt) == CURLOPT_PROXY_SSLCERTTYPE ||
             (_curl_opt) == CURLOPT_PROXY_SSLKEY ||
             (_curl_opt) == CURLOPT_PROXY_SSLKEYTYPE ||
             (_curl_opt) == CURLOPT_PROXY_SSL_CIPHER_LIST ||
             (_curl_opt) == CURLOPT_PROXY_TLS13_CIPHERS ||
             (_curl_opt) == CURLOPT_PROXY_TLSAUTH_PASSWORD ||
             (_curl_opt) == CURLOPT_PROXY_TLSAUTH_TYPE ||
             (_curl_opt) == CURLOPT_PROXY_TLSAUTH_USERNAME ||
             (_curl_opt) == CURLOPT_RANDOM_FILE ||
             (_curl_opt) == CURLOPT_RANGE || (_curl_opt) == CURLOPT_REFERER ||
             (_curl_opt) == CURLOPT_REQUEST_TARGET ||
             (_curl_opt) == CURLOPT_RTSP_SESSION_ID ||
             (_curl_opt) == CURLOPT_RTSP_STREAM_URI ||
             (_curl_opt) == CURLOPT_RTSP_TRANSPORT ||
             (_curl_opt) == CURLOPT_SASL_AUTHZID ||
             (_curl_opt) == CURLOPT_SERVICE_NAME ||
             (_curl_opt) == CURLOPT_SOCKS5_GSSAPI_SERVICE ||
             (_curl_opt) == CURLOPT_SSH_HOST_PUBLIC_KEY_MD5 ||
             (_curl_opt) == CURLOPT_SSH_HOST_PUBLIC_KEY_SHA256 ||
             (_curl_opt) == CURLOPT_SSH_KNOWNHOSTS ||
             (_curl_opt) == CURLOPT_SSH_PRIVATE_KEYFILE ||
             (_curl_opt) == CURLOPT_SSH_PUBLIC_KEYFILE ||
             (_curl_opt) == CURLOPT_SSLCERT ||
             (_curl_opt) == CURLOPT_SSLCERTTYPE ||
             (_curl_opt) == CURLOPT_SSLENGINE ||
             (_curl_opt) == CURLOPT_SSLKEY ||
             (_curl_opt) == CURLOPT_SSLKEYTYPE ||
             (_curl_opt) == CURLOPT_SSL_CIPHER_LIST ||
             (_curl_opt) == CURLOPT_TLS13_CIPHERS ||
             (_curl_opt) == CURLOPT_TLSAUTH_PASSWORD ||
             (_curl_opt) == CURLOPT_TLSAUTH_TYPE ||
             (_curl_opt) == CURLOPT_TLSAUTH_USERNAME ||
             (_curl_opt) == CURLOPT_UNIX_SOCKET_PATH ||
             (_curl_opt) == CURLOPT_URL || (_curl_opt) == CURLOPT_USERAGENT ||
             (_curl_opt) == CURLOPT_USERNAME ||
             (_curl_opt) == CURLOPT_AWS_SIGV4 ||
             (_curl_opt) == CURLOPT_USERPWD ||
             (_curl_opt) == CURLOPT_XOAUTH2_BEARER ||
             (_curl_opt) == CURLOPT_SSL_EC_CURVES || 0))
          if (!((((__builtin_types_compatible_p(
                      __typeof__((("name=daniel&project=curl"))),
                      __typeof__(((void *)0)))) ||
                  __builtin_types_compatible_p(
                      __typeof__((("name=daniel&project=curl"))), char *) ||
                  __builtin_types_compatible_p(
                      __typeof__((("name=daniel&project=curl"))),
                      const char *)) ||
                 __builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")), char[])) ||
                (((__builtin_types_compatible_p(
                      __typeof__((("name=daniel&project=curl"))),
                      __typeof__(((void *)0)))) ||
                  __builtin_types_compatible_p(
                      __typeof__((("name=daniel&project=curl"))),
                      signed char *) ||
                  __builtin_types_compatible_p(
                      __typeof__((("name=daniel&project=curl"))),
                      const signed char *)) ||
                 __builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")),
                     signed char[])) ||
                (((__builtin_types_compatible_p(
                      __typeof__((("name=daniel&project=curl"))),
                      __typeof__(((void *)0)))) ||
                  __builtin_types_compatible_p(
                      __typeof__((("name=daniel&project=curl"))),
                      unsigned char *) ||
                  __builtin_types_compatible_p(
                      __typeof__((("name=daniel&project=curl"))),
                      const unsigned char *)) ||
                 __builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")),
                     unsigned char[]))))
            _curl_easy_setopt_err_string();
        if (((_curl_opt) == CURLOPT_HEADERFUNCTION ||
             (_curl_opt) == CURLOPT_WRITEFUNCTION))
          if (!(((__builtin_types_compatible_p(
                     __typeof__("name=daniel&project=curl"),
                     __typeof__(((void *)0)))) ||
                 (__builtin_types_compatible_p(
                      __typeof__(("name=daniel&project=curl")),
                      __typeof__(fread) *) ||
                  __builtin_types_compatible_p(
                      __typeof__(("name=daniel&project=curl")) *,
                      __typeof__(fread) *)) ||
                 (__builtin_types_compatible_p(
                      __typeof__(("name=daniel&project=curl")),
                      curl_read_callback) ||
                  __builtin_types_compatible_p(
                      __typeof__(("name=daniel&project=curl")) *,
                      curl_read_callback)) ||
                 (__builtin_types_compatible_p(
                      __typeof__(("name=daniel&project=curl")),
                      _curl_read_callback1) ||
                  __builtin_types_compatible_p(
                      __typeof__(("name=daniel&project=curl")) *,
                      _curl_read_callback1)) ||
                 (__builtin_types_compatible_p(
                      __typeof__(("name=daniel&project=curl")),
                      _curl_read_callback2) ||
                  __builtin_types_compatible_p(
                      __typeof__(("name=daniel&project=curl")) *,
                      _curl_read_callback2)) ||
                 (__builtin_types_compatible_p(
                      __typeof__(("name=daniel&project=curl")),
                      _curl_read_callback3) ||
                  __builtin_types_compatible_p(
                      __typeof__(("name=daniel&project=curl")) *,
                      _curl_read_callback3)) ||
                 (__builtin_types_compatible_p(
                      __typeof__(("name=daniel&project=curl")),
                      _curl_read_callback4) ||
                  __builtin_types_compatible_p(
                      __typeof__(("name=daniel&project=curl")) *,
                      _curl_read_callback4)) ||
                 (__builtin_types_compatible_p(
                      __typeof__(("name=daniel&project=curl")),
                      _curl_read_callback5) ||
                  __builtin_types_compatible_p(
                      __typeof__(("name=daniel&project=curl")) *,
                      _curl_read_callback5)) ||
                 (__builtin_types_compatible_p(
                      __typeof__(("name=daniel&project=curl")),
                      _curl_read_callback6) ||
                  __builtin_types_compatible_p(
                      __typeof__(("name=daniel&project=curl")) *,
                      _curl_read_callback6))) ||
                (__builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")),
                     __typeof__(fwrite) *) ||
                 __builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")) *,
                     __typeof__(fwrite) *)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")),
                     curl_write_callback) ||
                 __builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")) *,
                     curl_write_callback)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")),
                     _curl_write_callback1) ||
                 __builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")) *,
                     _curl_write_callback1)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")),
                     _curl_write_callback2) ||
                 __builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")) *,
                     _curl_write_callback2)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")),
                     _curl_write_callback3) ||
                 __builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")) *,
                     _curl_write_callback3)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")),
                     _curl_write_callback4) ||
                 __builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")) *,
                     _curl_write_callback4)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")),
                     _curl_write_callback5) ||
                 __builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")) *,
                     _curl_write_callback5)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")),
                     _curl_write_callback6) ||
                 __builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")) *,
                     _curl_write_callback6))))
            _curl_easy_setopt_err_write_callback();
        if ((_curl_opt) == CURLOPT_RESOLVER_START_FUNCTION)
          if (!((__builtin_types_compatible_p(
                    __typeof__("name=daniel&project=curl"),
                    __typeof__(((void *)0)))) ||
                (__builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")),
                     curl_resolver_start_callback) ||
                 __builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")) *,
                     curl_resolver_start_callback))))
            _curl_easy_setopt_err_resolver_start_callback();
        if ((_curl_opt) == CURLOPT_READFUNCTION)
          if (!((__builtin_types_compatible_p(
                    __typeof__("name=daniel&project=curl"),
                    __typeof__(((void *)0)))) ||
                (__builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")),
                     __typeof__(fread) *) ||
                 __builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")) *,
                     __typeof__(fread) *)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")),
                     curl_read_callback) ||
                 __builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")) *,
                     curl_read_callback)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")),
                     _curl_read_callback1) ||
                 __builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")) *,
                     _curl_read_callback1)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")),
                     _curl_read_callback2) ||
                 __builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")) *,
                     _curl_read_callback2)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")),
                     _curl_read_callback3) ||
                 __builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")) *,
                     _curl_read_callback3)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")),
                     _curl_read_callback4) ||
                 __builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")) *,
                     _curl_read_callback4)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")),
                     _curl_read_callback5) ||
                 __builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")) *,
                     _curl_read_callback5)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")),
                     _curl_read_callback6) ||
                 __builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")) *,
                     _curl_read_callback6))))
            _curl_easy_setopt_err_read_cb();
        if ((_curl_opt) == CURLOPT_IOCTLFUNCTION)
          if (!((__builtin_types_compatible_p(
                    __typeof__("name=daniel&project=curl"),
                    __typeof__(((void *)0)))) ||
                (__builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")),
                     curl_ioctl_callback) ||
                 __builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")) *,
                     curl_ioctl_callback)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")),
                     _curl_ioctl_callback1) ||
                 __builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")) *,
                     _curl_ioctl_callback1)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")),
                     _curl_ioctl_callback2) ||
                 __builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")) *,
                     _curl_ioctl_callback2)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")),
                     _curl_ioctl_callback3) ||
                 __builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")) *,
                     _curl_ioctl_callback3)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")),
                     _curl_ioctl_callback4) ||
                 __builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")) *,
                     _curl_ioctl_callback4))))
            _curl_easy_setopt_err_ioctl_cb();
        if ((_curl_opt) == CURLOPT_SOCKOPTFUNCTION)
          if (!((__builtin_types_compatible_p(
                    __typeof__("name=daniel&project=curl"),
                    __typeof__(((void *)0)))) ||
                (__builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")),
                     curl_sockopt_callback) ||
                 __builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")) *,
                     curl_sockopt_callback)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")),
                     _curl_sockopt_callback1) ||
                 __builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")) *,
                     _curl_sockopt_callback1)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")),
                     _curl_sockopt_callback2) ||
                 __builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")) *,
                     _curl_sockopt_callback2))))
            _curl_easy_setopt_err_sockopt_cb();
        if ((_curl_opt) == CURLOPT_OPENSOCKETFUNCTION)
          if (!((__builtin_types_compatible_p(
                    __typeof__("name=daniel&project=curl"),
                    __typeof__(((void *)0)))) ||
                (__builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")),
                     curl_opensocket_callback) ||
                 __builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")) *,
                     curl_opensocket_callback)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")),
                     _curl_opensocket_callback1) ||
                 __builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")) *,
                     _curl_opensocket_callback1)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")),
                     _curl_opensocket_callback2) ||
                 __builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")) *,
                     _curl_opensocket_callback2)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")),
                     _curl_opensocket_callback3) ||
                 __builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")) *,
                     _curl_opensocket_callback3)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")),
                     _curl_opensocket_callback4) ||
                 __builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")) *,
                     _curl_opensocket_callback4))))
            _curl_easy_setopt_err_opensocket_cb();
        if ((_curl_opt) == CURLOPT_PROGRESSFUNCTION)
          if (!((__builtin_types_compatible_p(
                    __typeof__("name=daniel&project=curl"),
                    __typeof__(((void *)0)))) ||
                (__builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")),
                     curl_progress_callback) ||
                 __builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")) *,
                     curl_progress_callback)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")),
                     _curl_progress_callback1) ||
                 __builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")) *,
                     _curl_progress_callback1)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")),
                     _curl_progress_callback2) ||
                 __builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")) *,
                     _curl_progress_callback2))))
            _curl_easy_setopt_err_progress_cb();
        if ((_curl_opt) == CURLOPT_DEBUGFUNCTION)
          if (!((__builtin_types_compatible_p(
                    __typeof__("name=daniel&project=curl"),
                    __typeof__(((void *)0)))) ||
                (__builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")),
                     curl_debug_callback) ||
                 __builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")) *,
                     curl_debug_callback)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")),
                     _curl_debug_callback1) ||
                 __builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")) *,
                     _curl_debug_callback1)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")),
                     _curl_debug_callback2) ||
                 __builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")) *,
                     _curl_debug_callback2)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")),
                     _curl_debug_callback3) ||
                 __builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")) *,
                     _curl_debug_callback3)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")),
                     _curl_debug_callback4) ||
                 __builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")) *,
                     _curl_debug_callback4)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")),
                     _curl_debug_callback5) ||
                 __builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")) *,
                     _curl_debug_callback5)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")),
                     _curl_debug_callback6) ||
                 __builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")) *,
                     _curl_debug_callback6)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")),
                     _curl_debug_callback7) ||
                 __builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")) *,
                     _curl_debug_callback7)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")),
                     _curl_debug_callback8) ||
                 __builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")) *,
                     _curl_debug_callback8))))
            _curl_easy_setopt_err_debug_cb();
        if ((_curl_opt) == CURLOPT_SSL_CTX_FUNCTION)
          if (!((__builtin_types_compatible_p(
                    __typeof__("name=daniel&project=curl"),
                    __typeof__(((void *)0)))) ||
                (__builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")),
                     curl_ssl_ctx_callback) ||
                 __builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")) *,
                     curl_ssl_ctx_callback)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")),
                     _curl_ssl_ctx_callback1) ||
                 __builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")) *,
                     _curl_ssl_ctx_callback1)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")),
                     _curl_ssl_ctx_callback2) ||
                 __builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")) *,
                     _curl_ssl_ctx_callback2)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")),
                     _curl_ssl_ctx_callback3) ||
                 __builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")) *,
                     _curl_ssl_ctx_callback3)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")),
                     _curl_ssl_ctx_callback4) ||
                 __builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")) *,
                     _curl_ssl_ctx_callback4)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")),
                     _curl_ssl_ctx_callback5) ||
                 __builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")) *,
                     _curl_ssl_ctx_callback5)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")),
                     _curl_ssl_ctx_callback6) ||
                 __builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")) *,
                     _curl_ssl_ctx_callback6)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")),
                     _curl_ssl_ctx_callback7) ||
                 __builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")) *,
                     _curl_ssl_ctx_callback7)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")),
                     _curl_ssl_ctx_callback8) ||
                 __builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")) *,
                     _curl_ssl_ctx_callback8))))
            _curl_easy_setopt_err_ssl_ctx_cb();
        if (((_curl_opt) == CURLOPT_CONV_TO_NETWORK_FUNCTION ||
             (_curl_opt) == CURLOPT_CONV_FROM_NETWORK_FUNCTION ||
             (_curl_opt) == CURLOPT_CONV_FROM_UTF8_FUNCTION))
          if (!((__builtin_types_compatible_p(
                    __typeof__("name=daniel&project=curl"),
                    __typeof__(((void *)0)))) ||
                (__builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")),
                     curl_conv_callback) ||
                 __builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")) *,
                     curl_conv_callback)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")),
                     _curl_conv_callback1) ||
                 __builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")) *,
                     _curl_conv_callback1)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")),
                     _curl_conv_callback2) ||
                 __builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")) *,
                     _curl_conv_callback2)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")),
                     _curl_conv_callback3) ||
                 __builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")) *,
                     _curl_conv_callback3)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")),
                     _curl_conv_callback4) ||
                 __builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")) *,
                     _curl_conv_callback4))))
            _curl_easy_setopt_err_conv_cb();
        if ((_curl_opt) == CURLOPT_SEEKFUNCTION)
          if (!((__builtin_types_compatible_p(
                    __typeof__("name=daniel&project=curl"),
                    __typeof__(((void *)0)))) ||
                (__builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")),
                     curl_seek_callback) ||
                 __builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")) *,
                     curl_seek_callback)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")),
                     _curl_seek_callback1) ||
                 __builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")) *,
                     _curl_seek_callback1)) ||
                (__builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")),
                     _curl_seek_callback2) ||
                 __builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")) *,
                     _curl_seek_callback2))))
            _curl_easy_setopt_err_seek_cb();
        if (((_curl_opt) == CURLOPT_CHUNK_DATA ||
             (_curl_opt) == CURLOPT_CLOSESOCKETDATA ||
             (_curl_opt) == CURLOPT_DEBUGDATA ||
             (_curl_opt) == CURLOPT_FNMATCH_DATA ||
             (_curl_opt) == CURLOPT_HEADERDATA ||
             (_curl_opt) == CURLOPT_HSTSREADDATA ||
             (_curl_opt) == CURLOPT_HSTSWRITEDATA ||
             (_curl_opt) == CURLOPT_INTERLEAVEDATA ||
             (_curl_opt) == CURLOPT_IOCTLDATA ||
             (_curl_opt) == CURLOPT_OPENSOCKETDATA ||
             (_curl_opt) == CURLOPT_PREREQDATA ||
             (_curl_opt) == CURLOPT_XFERINFODATA ||
             (_curl_opt) == CURLOPT_READDATA ||
             (_curl_opt) == CURLOPT_SEEKDATA ||
             (_curl_opt) == CURLOPT_SOCKOPTDATA ||
             (_curl_opt) == CURLOPT_SSH_KEYDATA ||
             (_curl_opt) == CURLOPT_SSL_CTX_DATA ||
             (_curl_opt) == CURLOPT_WRITEDATA ||
             (_curl_opt) == CURLOPT_RESOLVER_START_DATA ||
             (_curl_opt) == CURLOPT_TRAILERDATA || 0))
          if (!(sizeof("name=daniel&project=curl") == sizeof(void *)))
            _curl_easy_setopt_err_cb_data();
        if ((_curl_opt) == CURLOPT_ERRORBUFFER)
          if (!((__builtin_types_compatible_p(
                    __typeof__("name=daniel&project=curl"),
                    __typeof__(((void *)0)))) ||
                __builtin_types_compatible_p(
                    __typeof__("name=daniel&project=curl"), char *) ||
                __builtin_types_compatible_p(
                    __typeof__("name=daniel&project=curl"), char[])))
            _curl_easy_setopt_err_error_buffer();
        if ((_curl_opt) == CURLOPT_STDERR)
          if (!((__builtin_types_compatible_p(
                    __typeof__("name=daniel&project=curl"),
                    __typeof__(((void *)0)))) ||
                (__builtin_types_compatible_p(
                    __typeof__("name=daniel&project=curl"), FILE *))))
            _curl_easy_setopt_err_FILE();
        if (((_curl_opt) == CURLOPT_POSTFIELDS ||
             (_curl_opt) == CURLOPT_COPYPOSTFIELDS || 0))
          if (!(((__builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")),
                     __typeof__(((void *)0)))) ||
                 __builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")), void *) ||
                 __builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")), const void *)) ||
                (((__builtin_types_compatible_p(
                      __typeof__((("name=daniel&project=curl"))),
                      __typeof__(((void *)0)))) ||
                  __builtin_types_compatible_p(
                      __typeof__((("name=daniel&project=curl"))), char *) ||
                  __builtin_types_compatible_p(
                      __typeof__((("name=daniel&project=curl"))),
                      const char *)) ||
                 __builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")), char[])) ||
                (((__builtin_types_compatible_p(
                      __typeof__((("name=daniel&project=curl"))),
                      __typeof__(((void *)0)))) ||
                  __builtin_types_compatible_p(
                      __typeof__((("name=daniel&project=curl"))),
                      unsigned char *) ||
                  __builtin_types_compatible_p(
                      __typeof__((("name=daniel&project=curl"))),
                      const unsigned char *)) ||
                 __builtin_types_compatible_p(
                     __typeof__(("name=daniel&project=curl")),
                     unsigned char[]))))
            _curl_easy_setopt_err_postfields();
        if ((_curl_opt) == CURLOPT_HTTPPOST)
          if (!(((__builtin_types_compatible_p(
                     __typeof__((("name=daniel&project=curl"))),
                     __typeof__(((void *)0)))) ||
                 __builtin_types_compatible_p(
                     __typeof__((("name=daniel&project=curl"))),
                     struct curl_httppost *) ||
                 __builtin_types_compatible_p(
                     __typeof__((("name=daniel&project=curl"))),
                     const struct curl_httppost *)) ||
                __builtin_types_compatible_p(
                    __typeof__(("name=daniel&project=curl")),
                    struct curl_httppost[])))
            _curl_easy_setopt_err_curl_httpost();
        if ((_curl_opt) == CURLOPT_MIMEPOST)
          if (!((__builtin_types_compatible_p(
                    __typeof__(("name=daniel&project=curl")),
                    __typeof__(((void *)0)))) ||
                __builtin_types_compatible_p(
                    __typeof__(("name=daniel&project=curl")), curl_mime *) ||
                __builtin_types_compatible_p(
                    __typeof__(("name=daniel&project=curl")),
                    const curl_mime *)))
            _curl_easy_setopt_err_curl_mimepost();
        if (((_curl_opt) == CURLOPT_HTTP200ALIASES ||
             (_curl_opt) == CURLOPT_HTTPHEADER ||
             (_curl_opt) == CURLOPT_MAIL_RCPT ||
             (_curl_opt) == CURLOPT_POSTQUOTE ||
             (_curl_opt) == CURLOPT_PREQUOTE ||
             (_curl_opt) == CURLOPT_PROXYHEADER ||
             (_curl_opt) == CURLOPT_QUOTE || (_curl_opt) == CURLOPT_RESOLVE ||
             (_curl_opt) == CURLOPT_TELNETOPTIONS ||
             (_curl_opt) == CURLOPT_CONNECT_TO || 0))
          if (!(((__builtin_types_compatible_p(
                     __typeof__((("name=daniel&project=curl"))),
                     __typeof__(((void *)0)))) ||
                 __builtin_types_compatible_p(
                     __typeof__((("name=daniel&project=curl"))),
                     struct curl_slist *) ||
                 __builtin_types_compatible_p(
                     __typeof__((("name=daniel&project=curl"))),
                     const struct curl_slist *)) ||
                __builtin_types_compatible_p(
                    __typeof__(("name=daniel&project=curl")),
                    struct curl_slist[])))
            _curl_easy_setopt_err_curl_slist();
        if ((_curl_opt) == CURLOPT_SHARE)
          if (!((__builtin_types_compatible_p(
                    __typeof__(("name=daniel&project=curl")),
                    __typeof__(((void *)0)))) ||
                __builtin_types_compatible_p(
                    __typeof__(("name=daniel&project=curl")), CURLSH *) ||
                __builtin_types_compatible_p(
                    __typeof__(("name=daniel&project=curl")), const CURLSH *)))
            _curl_easy_setopt_err_CURLSH();
      }
      curl_easy_setopt(curl, _curl_opt, "name=daniel&project=curl");
    });
    res = curl_easy_perform(curl);
    if (res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));
    curl_easy_cleanup(curl);
  }
  curl_global_cleanup();
  return 0;
}
