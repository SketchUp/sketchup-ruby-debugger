#ifdef __GNUC__
# pragma GCC system_header
#endif










#define ALWAYS_INLINE(x) __attribute__ ((__always_inline__)) x











































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































typedef signed char __int8_t;



typedef unsigned char __uint8_t;
typedef short __int16_t;
typedef unsigned short __uint16_t;
typedef int __int32_t;
typedef unsigned int __uint32_t;
typedef long long __int64_t;
typedef unsigned long long __uint64_t;

typedef long __darwin_intptr_t;
typedef unsigned int __darwin_natural_t;
typedef int __darwin_ct_rune_t;





typedef union {
 char __mbstate8[128];
 long long _mbstateL;
} __mbstate_t;

typedef __mbstate_t __darwin_mbstate_t;


typedef long int __darwin_ptrdiff_t;







typedef long unsigned int __darwin_size_t;





typedef __builtin_va_list __darwin_va_list;





typedef int __darwin_wchar_t;




typedef __darwin_wchar_t __darwin_rune_t;


typedef int __darwin_wint_t;




typedef unsigned long __darwin_clock_t;
typedef __uint32_t __darwin_socklen_t;
typedef long __darwin_ssize_t;
typedef long __darwin_time_t;


typedef __int64_t __darwin_blkcnt_t;
typedef __int32_t __darwin_blksize_t;
typedef __int32_t __darwin_dev_t;
typedef unsigned int __darwin_fsblkcnt_t;
typedef unsigned int __darwin_fsfilcnt_t;
typedef __uint32_t __darwin_gid_t;
typedef __uint32_t __darwin_id_t;
typedef __uint64_t __darwin_ino64_t;

typedef __darwin_ino64_t __darwin_ino_t;



typedef __darwin_natural_t __darwin_mach_port_name_t;
typedef __darwin_mach_port_name_t __darwin_mach_port_t;
typedef __uint16_t __darwin_mode_t;
typedef __int64_t __darwin_off_t;
typedef __int32_t __darwin_pid_t;
typedef __uint32_t __darwin_sigset_t;
typedef __int32_t __darwin_suseconds_t;
typedef __uint32_t __darwin_uid_t;
typedef __uint32_t __darwin_useconds_t;
typedef unsigned char __darwin_uuid_t[16];
typedef char __darwin_uuid_string_t[37];







struct __darwin_pthread_handler_rec {
 void (*__routine)(void *);
 void *__arg;
 struct __darwin_pthread_handler_rec *__next;
};

struct _opaque_pthread_attr_t {
 long __sig;
 char __opaque[56];
};

struct _opaque_pthread_cond_t {
 long __sig;
 char __opaque[40];
};

struct _opaque_pthread_condattr_t {
 long __sig;
 char __opaque[8];
};

struct _opaque_pthread_mutex_t {
 long __sig;
 char __opaque[56];
};

struct _opaque_pthread_mutexattr_t {
 long __sig;
 char __opaque[8];
};

struct _opaque_pthread_once_t {
 long __sig;
 char __opaque[8];
};

struct _opaque_pthread_rwlock_t {
 long __sig;
 char __opaque[192];
};

struct _opaque_pthread_rwlockattr_t {
 long __sig;
 char __opaque[16];
};

struct _opaque_pthread_t {
 long __sig;
 struct __darwin_pthread_handler_rec *__cleanup_stack;
 char __opaque[8176];
};

typedef struct _opaque_pthread_attr_t __darwin_pthread_attr_t;
typedef struct _opaque_pthread_cond_t __darwin_pthread_cond_t;
typedef struct _opaque_pthread_condattr_t __darwin_pthread_condattr_t;
typedef unsigned long __darwin_pthread_key_t;
typedef struct _opaque_pthread_mutex_t __darwin_pthread_mutex_t;
typedef struct _opaque_pthread_mutexattr_t __darwin_pthread_mutexattr_t;
typedef struct _opaque_pthread_once_t __darwin_pthread_once_t;
typedef struct _opaque_pthread_rwlock_t __darwin_pthread_rwlock_t;
typedef struct _opaque_pthread_rwlockattr_t __darwin_pthread_rwlockattr_t;
typedef struct _opaque_pthread_t *__darwin_pthread_t;












typedef int __darwin_nl_item;
typedef int __darwin_wctrans_t;

typedef __uint32_t __darwin_wctype_t;






















typedef signed char int8_t;
typedef short int16_t;
typedef int int32_t;
typedef long long int64_t;

typedef unsigned char u_int8_t;
typedef unsigned short u_int16_t;
typedef unsigned int u_int32_t;
typedef unsigned long long u_int64_t;


typedef int64_t register_t;







typedef __darwin_intptr_t intptr_t;
typedef unsigned long uintptr_t;




typedef u_int64_t user_addr_t;
typedef u_int64_t user_size_t;
typedef int64_t user_ssize_t;
typedef int64_t user_long_t;
typedef u_int64_t user_ulong_t;
typedef int64_t user_time_t;
typedef int64_t user_off_t;








typedef u_int64_t syscall_arg_t;
typedef __darwin_va_list va_list;

typedef __darwin_size_t size_t;









int renameat(int, const char *, int, const char *) __attribute__((availability(macosx,introduced=10.10)));



int renamex_np(const char *, const char *, unsigned int) __attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,introduced=10.0))) __attribute__((availability(tvos,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0)));
int renameatx_np(int, const char *, int, const char *, unsigned int) __attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,introduced=10.0))) __attribute__((availability(tvos,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0)));

typedef __darwin_off_t fpos_t;









struct __sbuf {
 unsigned char *_base;
 int _size;
};


struct __sFILEX;
typedef struct __sFILE {
 unsigned char *_p;
 int _r;
 int _w;
 short _flags;
 short _file;
 struct __sbuf _bf;
 int _lbfsize;


 void *_cookie;
 int (* _Nullable _close)(void *);
 int (* _Nullable _read) (void *, char *, int);
 fpos_t (* _Nullable _seek) (void *, fpos_t, int);
 int (* _Nullable _write)(void *, const char *, int);


 struct __sbuf _ub;
 struct __sFILEX *_extra;
 int _ur;


 unsigned char _ubuf[3];
 unsigned char _nbuf[1];


 struct __sbuf _lb;


 int _blksize;
 fpos_t _offset;
} FILE;


extern FILE *__stdinp;
extern FILE *__stdoutp;
extern FILE *__stderrp;


















void clearerr(FILE *);
int fclose(FILE *);
int feof(FILE *);
int ferror(FILE *);
int fflush(FILE *);
int fgetc(FILE *);
int fgetpos(FILE * __restrict, fpos_t *);
char *fgets(char * __restrict, int, FILE *);

FILE *fopen(const char * __restrict __filename, const char * __restrict __mode) __asm("_" "fopen" "$DARWIN_EXTSN");



int fprintf(FILE * __restrict, const char * __restrict, ...) __attribute__((__format__ (__printf__, 2, 3)));
int fputc(int, FILE *);
int fputs(const char * __restrict, FILE * __restrict) __asm("_" "fputs" );
size_t fread(void * __restrict __ptr, size_t __size, size_t __nitems, FILE * __restrict __stream);
FILE *freopen(const char * __restrict, const char * __restrict,
                 FILE * __restrict) __asm("_" "freopen" );
int fscanf(FILE * __restrict, const char * __restrict, ...) __attribute__((__format__ (__scanf__, 2, 3)));
int fseek(FILE *, long, int);
int fsetpos(FILE *, const fpos_t *);
long ftell(FILE *);
size_t fwrite(const void * __restrict __ptr, size_t __size, size_t __nitems, FILE * __restrict __stream) __asm("_" "fwrite" );
int getc(FILE *);
int getchar(void);
char *gets(char *);
void perror(const char *) __attribute__((__cold__));
int printf(const char * __restrict, ...) __attribute__((__format__ (__printf__, 1, 2)));
int putc(int, FILE *);
int putchar(int);
int puts(const char *);
int remove(const char *);
int rename (const char *__old, const char *__new);
void rewind(FILE *);
int scanf(const char * __restrict, ...) __attribute__((__format__ (__scanf__, 1, 2)));
void setbuf(FILE * __restrict, char * __restrict);
int setvbuf(FILE * __restrict, char * __restrict, int, size_t);
int sprintf(char * __restrict, const char * __restrict, ...) __attribute__((__format__ (__printf__, 2, 3))) __attribute__((__availability__(swift, unavailable, message="Use snprintf instead.")));
int sscanf(const char * __restrict, const char * __restrict, ...) __attribute__((__format__ (__scanf__, 2, 3)));
FILE *tmpfile(void);

__attribute__((__availability__(swift, unavailable, message="Use mkstemp(3) instead.")))

__attribute__((__deprecated__("This function is provided for compatibility reasons only.  Due to security concerns inherent in the design of tmpnam(3), it is highly recommended that you use mkstemp(3) instead.")))

char *tmpnam(char *);
int ungetc(int, FILE *);
int vfprintf(FILE * __restrict, const char * __restrict, va_list) __attribute__((__format__ (__printf__, 2, 0)));
int vprintf(const char * __restrict, va_list) __attribute__((__format__ (__printf__, 1, 0)));
int vsprintf(char * __restrict, const char * __restrict, va_list) __attribute__((__format__ (__printf__, 2, 0))) __attribute__((__availability__(swift, unavailable, message="Use vsnprintf instead.")));








char *ctermid(char *);


FILE *fdopen(int, const char *) __asm("_" "fdopen" "$DARWIN_EXTSN");



int fileno(FILE *);




int pclose(FILE *) __attribute__((__availability__(swift, unavailable, message="Use posix_spawn APIs or NSTask instead.")));

FILE *popen(const char *, const char *) __asm("_" "popen" "$DARWIN_EXTSN") __attribute__((__availability__(swift, unavailable, message="Use posix_spawn APIs or NSTask instead.")));






int __srget(FILE *);
int __svfscanf(FILE *, const char *, va_list) __attribute__((__format__ (__scanf__, 2, 0)));
int __swbuf(int, FILE *);







inline __attribute__ ((__always_inline__)) int __sputc(int _c, FILE *_p) {
 if (--_p->_w >= 0 || (_p->_w >= _p->_lbfsize && (char)_c != '\n'))
  return (*_p->_p++ = _c);
 else
  return (__swbuf(_c, _p));
}


void flockfile(FILE *);
int ftrylockfile(FILE *);
void funlockfile(FILE *);
int getc_unlocked(FILE *);
int getchar_unlocked(void);
int putc_unlocked(int, FILE *);
int putchar_unlocked(int);



int getw(FILE *);
int putw(int, FILE *);


__attribute__((__availability__(swift, unavailable, message="Use mkstemp(3) instead.")))

__attribute__((__deprecated__("This function is provided for compatibility reasons only.  Due to security concerns inherent in the design of tempnam(3), it is highly recommended that you use mkstemp(3) instead.")))

char *tempnam(const char *__dir, const char *__prefix) __asm("_" "tempnam" );






typedef __darwin_off_t off_t;


int fseeko(FILE * __stream, off_t __offset, int __whence);
off_t ftello(FILE * __stream);





int snprintf(char * __restrict __str, size_t __size, const char * __restrict __format, ...) __attribute__((__format__ (__printf__, 3, 4)));
int vfscanf(FILE * __restrict __stream, const char * __restrict __format, va_list) __attribute__((__format__ (__scanf__, 2, 0)));
int vscanf(const char * __restrict __format, va_list) __attribute__((__format__ (__scanf__, 1, 0)));
int vsnprintf(char * __restrict __str, size_t __size, const char * __restrict __format, va_list) __attribute__((__format__ (__printf__, 3, 0)));
int vsscanf(const char * __restrict __str, const char * __restrict __format, va_list) __attribute__((__format__ (__scanf__, 2, 0)));

typedef __darwin_ssize_t ssize_t;


int dprintf(int, const char * __restrict, ...) __attribute__((__format__ (__printf__, 2, 3))) __attribute__((availability(macosx,introduced=10.7)));
int vdprintf(int, const char * __restrict, va_list) __attribute__((__format__ (__printf__, 2, 0))) __attribute__((availability(macosx,introduced=10.7)));
ssize_t getdelim(char ** __restrict __linep, size_t * __restrict __linecapp, int __delimiter, FILE * __restrict __stream) __attribute__((availability(macosx,introduced=10.7)));
ssize_t getline(char ** __restrict __linep, size_t * __restrict __linecapp, FILE * __restrict __stream) __attribute__((availability(macosx,introduced=10.7)));
FILE *fmemopen(void * __restrict __buf, size_t __size, const char * __restrict __mode) __attribute__((availability(macos,introduced=10.13))) __attribute__((availability(ios,introduced=11.0))) __attribute__((availability(tvos,introduced=11.0))) __attribute__((availability(watchos,introduced=4.0)));
FILE *open_memstream(char **__bufp, size_t *__sizep) __attribute__((availability(macos,introduced=10.13))) __attribute__((availability(ios,introduced=11.0))) __attribute__((availability(tvos,introduced=11.0))) __attribute__((availability(watchos,introduced=4.0)));
extern const int sys_nerr;
extern const char *const sys_errlist[];

int asprintf(char ** __restrict, const char * __restrict, ...) __attribute__((__format__ (__printf__, 2, 3)));
char *ctermid_r(char *);
char *fgetln(FILE *, size_t *);
const char *fmtcheck(const char *, const char *);
int fpurge(FILE *);
void setbuffer(FILE *, char *, int);
int setlinebuf(FILE *);
int vasprintf(char ** __restrict, const char * __restrict, va_list) __attribute__((__format__ (__printf__, 2, 0)));
FILE *zopen(const char *, const char *, int);





FILE *funopen(const void *,
                 int (* _Nullable)(void *, char *, int),
                 int (* _Nullable)(void *, const char *, int),
                 fpos_t (* _Nullable)(void *, fpos_t, int),
                 int (* _Nullable)(void *));














extern int __sprintf_chk (char * __restrict, int, size_t,
     const char * __restrict, ...);






extern int __snprintf_chk (char * __restrict, size_t, int, size_t,
      const char * __restrict, ...);





extern int __vsprintf_chk (char * __restrict, int, size_t,
      const char * __restrict, va_list);





extern int __vsnprintf_chk (char * __restrict, size_t, int, size_t,
       const char * __restrict, va_list);








































































typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long long uint64_t;


typedef int8_t int_least8_t;
typedef int16_t int_least16_t;
typedef int32_t int_least32_t;
typedef int64_t int_least64_t;
typedef uint8_t uint_least8_t;
typedef uint16_t uint_least16_t;
typedef uint32_t uint_least32_t;
typedef uint64_t uint_least64_t;



typedef int8_t int_fast8_t;
typedef int16_t int_fast16_t;
typedef int32_t int_fast32_t;
typedef int64_t int_fast64_t;
typedef uint8_t uint_fast8_t;
typedef uint16_t uint_fast16_t;
typedef uint32_t uint_fast32_t;
typedef uint64_t uint_fast64_t;

typedef long int intmax_t;

typedef long unsigned int uintmax_t;
























































static inline
uint16_t
_OSSwapInt16(
 uint16_t _data
 )
{

 return (uint16_t)(_data << 8 | _data >> 8);
}

static inline
uint32_t
_OSSwapInt32(
 uint32_t _data
 )
{

 _data = __builtin_bswap32(_data);





 return _data;
}

static inline
uint64_t
_OSSwapInt64(
 uint64_t _data
 )
{

 return __builtin_bswap64(_data);
}



struct _OSUnalignedU16 {
 volatile uint16_t __val;
} __attribute__((__packed__));

struct _OSUnalignedU32 {
 volatile uint32_t __val;
} __attribute__((__packed__));

struct _OSUnalignedU64 {
 volatile uint64_t __val;
} __attribute__((__packed__));


static inline
uint16_t
_OSReadSwapInt16(
 const volatile void * _base,
 uintptr_t _offset
 )
{
 return _OSSwapInt16(((struct _OSUnalignedU16 *)((uintptr_t)_base + _offset))->__val);
}
static inline
uint32_t
_OSReadSwapInt32(
 const volatile void * _base,
 uintptr_t _offset
 )
{
 return _OSSwapInt32(((struct _OSUnalignedU32 *)((uintptr_t)_base + _offset))->__val);
}
static inline
uint64_t
_OSReadSwapInt64(
 const volatile void * _base,
 uintptr_t _offset
 )
{
 return _OSSwapInt64(((struct _OSUnalignedU64 *)((uintptr_t)_base + _offset))->__val);
}
static inline
void
_OSWriteSwapInt16(
 volatile void * _base,
 uintptr_t _offset,
 uint16_t _data
 )
{
 ((struct _OSUnalignedU16 *)((uintptr_t)_base + _offset))->__val = _OSSwapInt16(_data);
}
static inline
void
_OSWriteSwapInt32(
 volatile void * _base,
 uintptr_t _offset,
 uint32_t _data
 )
{
 ((struct _OSUnalignedU32 *)((uintptr_t)_base + _offset))->__val = _OSSwapInt32(_data);
}
static inline
void
_OSWriteSwapInt64(
 volatile void * _base,
 uintptr_t _offset,
 uint64_t _data
 )
{
 ((struct _OSUnalignedU64 *)((uintptr_t)_base + _offset))->__val = _OSSwapInt64(_data);
}















typedef unsigned char u_char;
typedef unsigned short u_short;
typedef unsigned int u_int;

typedef unsigned long u_long;

typedef unsigned short ushort;
typedef unsigned int uint;


typedef u_int64_t u_quad_t;
typedef int64_t quad_t;
typedef quad_t * qaddr_t;


typedef char * caddr_t;

typedef int32_t daddr_t;



typedef __darwin_dev_t dev_t;

typedef u_int32_t fixpt_t;



typedef __darwin_blkcnt_t blkcnt_t;

typedef __darwin_blksize_t blksize_t;

typedef __darwin_gid_t gid_t;

typedef __uint32_t in_addr_t;

typedef __uint16_t in_port_t;

typedef __darwin_ino_t ino_t;



typedef __darwin_ino64_t ino64_t;



typedef __int32_t key_t;

typedef __darwin_mode_t mode_t;

typedef __uint16_t nlink_t;

typedef __darwin_id_t id_t;

typedef __darwin_pid_t pid_t;


typedef int32_t segsz_t;
typedef int32_t swblk_t;



typedef __darwin_uid_t uid_t;






typedef __darwin_clock_t clock_t;



typedef __darwin_time_t time_t;


typedef __darwin_useconds_t useconds_t;

typedef __darwin_suseconds_t suseconds_t;



typedef __darwin_size_t rsize_t;
typedef int errno_t;











typedef struct fd_set {
 __int32_t fds_bits[((((1024) % ((sizeof(__int32_t) * 8))) == 0) ? ((1024) / ((sizeof(__int32_t) * 8))) : (((1024) / ((sizeof(__int32_t) * 8))) + 1))];
} fd_set;

int __darwin_check_fd_set_overflow(int, const void *, int) __attribute__((availability(macosx,introduced=11.0))) __attribute__((availability(ios,introduced=14.0))) __attribute__((availability(tvos,introduced=14.0))) __attribute__((availability(watchos,introduced=7.0)));


inline __attribute__ ((__always_inline__)) int
__darwin_check_fd_set(int _a, const void *_b)
{


 if ((uintptr_t)&__darwin_check_fd_set_overflow != (uintptr_t) 0) {

  return __darwin_check_fd_set_overflow(_a, _b, 1);



 } else {
  return 1;
 }


}


inline __attribute__ ((__always_inline__)) int
__darwin_fd_isset(int _fd, const struct fd_set *_p)
{
 if (__darwin_check_fd_set(_fd, (const void *) _p)) {
  return _p->fds_bits[(unsigned long)_fd / (sizeof(__int32_t) * 8)] & ((__int32_t)(((unsigned long)1) << ((unsigned long)_fd % (sizeof(__int32_t) * 8))));
 }

 return 0;
}

inline __attribute__ ((__always_inline__)) void
__darwin_fd_set(int _fd, struct fd_set *const _p)
{
 if (__darwin_check_fd_set(_fd, (const void *) _p)) {
  (_p->fds_bits[(unsigned long)_fd / (sizeof(__int32_t) * 8)] |= ((__int32_t)(((unsigned long)1) << ((unsigned long)_fd % (sizeof(__int32_t) * 8)))));
 }
}

inline __attribute__ ((__always_inline__)) void
__darwin_fd_clr(int _fd, struct fd_set *const _p)
{
 if (__darwin_check_fd_set(_fd, (const void *) _p)) {
  (_p->fds_bits[(unsigned long)_fd / (sizeof(__int32_t) * 8)] &= ~((__int32_t)(((unsigned long)1) << ((unsigned long)_fd % (sizeof(__int32_t) * 8)))));
 }
}













typedef __int32_t fd_mask;











typedef __darwin_pthread_attr_t pthread_attr_t;

typedef __darwin_pthread_cond_t pthread_cond_t;

typedef __darwin_pthread_condattr_t pthread_condattr_t;

typedef __darwin_pthread_mutex_t pthread_mutex_t;

typedef __darwin_pthread_mutexattr_t pthread_mutexattr_t;

typedef __darwin_pthread_once_t pthread_once_t;

typedef __darwin_pthread_rwlock_t pthread_rwlock_t;

typedef __darwin_pthread_rwlockattr_t pthread_rwlockattr_t;

typedef __darwin_pthread_t pthread_t;




typedef __darwin_pthread_key_t pthread_key_t;





typedef __darwin_fsblkcnt_t fsblkcnt_t;

typedef __darwin_fsfilcnt_t fsfilcnt_t;












struct timespec
{
 __darwin_time_t tv_sec;
 long tv_nsec;
};
struct ostat {
 __uint16_t st_dev;
 ino_t st_ino;
 mode_t st_mode;
 nlink_t st_nlink;
 __uint16_t st_uid;
 __uint16_t st_gid;
 __uint16_t st_rdev;
 __int32_t st_size;
 struct timespec st_atimespec;
 struct timespec st_mtimespec;
 struct timespec st_ctimespec;
 __int32_t st_blksize;
 __int32_t st_blocks;
 __uint32_t st_flags;
 __uint32_t st_gen;
};

struct stat { dev_t st_dev; mode_t st_mode; nlink_t st_nlink; __darwin_ino64_t st_ino; uid_t st_uid; gid_t st_gid; dev_t st_rdev; struct timespec st_atimespec; struct timespec st_mtimespec; struct timespec st_ctimespec; struct timespec st_birthtimespec; off_t st_size; blkcnt_t st_blocks; blksize_t st_blksize; __uint32_t st_flags; __uint32_t st_gen; __int32_t st_lspare; __int64_t st_qspare[2]; };


































































int chmod(const char *, mode_t) __asm("_" "chmod" );
int fchmod(int, mode_t) __asm("_" "fchmod" );
int fstat(int, struct stat *) __asm("_" "fstat" );
int lstat(const char *, struct stat *) __asm("_" "lstat" );
int mkdir(const char *, mode_t);
int mkfifo(const char *, mode_t);
int stat(const char *, struct stat *) __asm("_" "stat" );
int mknod(const char *, mode_t, dev_t);
mode_t umask(mode_t);


int fchmodat(int, const char *, mode_t, int) __attribute__((availability(macosx,introduced=10.10)));
int fstatat(int, const char *, struct stat *, int) __asm("_" "fstatat" ) __attribute__((availability(macosx,introduced=10.10)));
int mkdirat(int, const char *, mode_t) __attribute__((availability(macosx,introduced=10.10)));


int futimens(int __fd, const struct timespec __times[2]) __attribute__((availability(macosx,introduced=10.13))) __attribute__((availability(ios,introduced=11.0))) __attribute__((availability(tvos,introduced=11.0))) __attribute__((availability(watchos,introduced=4.0)));
int utimensat(int __fd, const char *__path, const struct timespec __times[2],
    int __flag) __attribute__((availability(macosx,introduced=10.13))) __attribute__((availability(ios,introduced=11.0))) __attribute__((availability(tvos,introduced=11.0))) __attribute__((availability(watchos,introduced=4.0)));





struct _filesec;
typedef struct _filesec *filesec_t;

int chflags(const char *, __uint32_t);
int chmodx_np(const char *, filesec_t);
int fchflags(int, __uint32_t);
int fchmodx_np(int, filesec_t);
int fstatx_np(int, struct stat *, filesec_t) __asm("_" "fstatx_np" );
int lchflags(const char *, __uint32_t) __attribute__((availability(macosx,introduced=10.5)));
int lchmod(const char *, mode_t) __attribute__((availability(macosx,introduced=10.5)));
int lstatx_np(const char *, struct stat *, filesec_t) __asm("_" "lstatx_np" );
int mkdirx_np(const char *, filesec_t);
int mkfifox_np(const char *, filesec_t);
int statx_np(const char *, struct stat *, filesec_t) __asm("_" "statx_np" );
int umaskx_np(filesec_t) __attribute__((availability(macosx,introduced=10.4,deprecated=10.6)));









typedef enum {
 P_ALL,
 P_PID,
 P_PGID
} idtype_t;



















typedef int sig_atomic_t;






























struct __darwin_arm_exception_state
{
 __uint32_t __exception;
 __uint32_t __fsr;
 __uint32_t __far;
};
struct __darwin_arm_exception_state64
{
 __uint64_t __far;
 __uint32_t __esr;
 __uint32_t __exception;
};
struct __darwin_arm_thread_state
{
 __uint32_t __r[13];
 __uint32_t __sp;
 __uint32_t __lr;
 __uint32_t __pc;
 __uint32_t __cpsr;
};
struct __darwin_arm_thread_state64
{
 __uint64_t __x[29];
 __uint64_t __fp;
 __uint64_t __lr;
 __uint64_t __sp;
 __uint64_t __pc;
 __uint32_t __cpsr;
 __uint32_t __pad;
};




















struct __darwin_arm_vfp_state
{
 __uint32_t __r[64];
 __uint32_t __fpscr;
};


struct __darwin_arm_neon_state64
{
 __uint128_t __v[32];
 __uint32_t __fpsr;
 __uint32_t __fpcr;
};

struct __darwin_arm_neon_state
{
 __uint128_t __v[16];
 __uint32_t __fpsr;
 __uint32_t __fpcr;
};
struct __darwin_arm_amx_state_v1
{
 __uint8_t __x[8][64];
 __uint8_t __y[8][64];
 __uint8_t __z[64][64];
 __uint64_t __amx_state_t_el1;
} __attribute__((aligned(64)));
struct __arm_pagein_state
{
 int __pagein_error;
};
struct __arm_legacy_debug_state
{
 __uint32_t __bvr[16];
 __uint32_t __bcr[16];
 __uint32_t __wvr[16];
 __uint32_t __wcr[16];
};
struct __darwin_arm_debug_state32
{
 __uint32_t __bvr[16];
 __uint32_t __bcr[16];
 __uint32_t __wvr[16];
 __uint32_t __wcr[16];
 __uint64_t __mdscr_el1;
};

struct __darwin_arm_debug_state64
{
 __uint64_t __bvr[16];
 __uint64_t __bcr[16];
 __uint64_t __wvr[16];
 __uint64_t __wcr[16];
 __uint64_t __mdscr_el1;
};
struct __darwin_arm_cpmu_state64
{
 __uint64_t __ctrs[16];
};



struct __darwin_mcontext32
{
 struct __darwin_arm_exception_state __es;
 struct __darwin_arm_thread_state __ss;
 struct __darwin_arm_vfp_state __fs;
};
struct __darwin_mcontext64
{
 struct __darwin_arm_exception_state64 __es;
 struct __darwin_arm_thread_state64 __ss;
 struct __darwin_arm_neon_state64 __ns;
};

typedef struct __darwin_mcontext64 *mcontext_t;









struct __darwin_sigaltstack
{
 void *ss_sp;
 __darwin_size_t ss_size;
 int ss_flags;
};
typedef struct __darwin_sigaltstack stack_t;









struct __darwin_ucontext
{
 int uc_onstack;
 __darwin_sigset_t uc_sigmask;
 struct __darwin_sigaltstack uc_stack;
 struct __darwin_ucontext *uc_link;
 __darwin_size_t uc_mcsize;
 struct __darwin_mcontext64 *uc_mcontext;

 struct __darwin_mcontext64 __mcontext_data;

};


typedef struct __darwin_ucontext ucontext_t;



typedef __darwin_sigset_t sigset_t;



union sigval {

 int sival_int;
 void *sival_ptr;
};


struct sigevent {
 int sigev_notify;
 int sigev_signo;
 union sigval sigev_value;
 void (*sigev_notify_function)(union sigval);
 pthread_attr_t *sigev_notify_attributes;
};


typedef struct __siginfo {
 int si_signo;
 int si_errno;
 int si_code;
 pid_t si_pid;
 uid_t si_uid;
 int si_status;
 void *si_addr;
 union sigval si_value;
 long si_band;
 unsigned long __pad[7];
} siginfo_t;























union __sigaction_u {
 void (*__sa_handler)(int);
 void (*__sa_sigaction)(int, struct __siginfo *,
     void *);
};


struct __sigaction {
 union __sigaction_u __sigaction_u;
 void (*sa_tramp)(void *, int, int, siginfo_t *, void *);
 sigset_t sa_mask;
 int sa_flags;
};




struct sigaction {
 union __sigaction_u __sigaction_u;
 sigset_t sa_mask;
 int sa_flags;
};




















typedef void (*sig_t)(int);












struct sigvec {
 void (*sv_handler)(int);
 int sv_mask;
 int sv_flags;
};







struct sigstack {
 char *ss_sp;
 int ss_onstack;
};








 void(*signal(int, void (*)(int)))(int);




struct timeval
{
 __darwin_time_t tv_sec;
 __darwin_suseconds_t tv_usec;
};








typedef __uint64_t rlim_t;


















struct rusage {
 struct timeval ru_utime;
 struct timeval ru_stime;
 long ru_maxrss;
 long ru_ixrss;
 long ru_idrss;
 long ru_isrss;
 long ru_minflt;
 long ru_majflt;
 long ru_nswap;
 long ru_inblock;
 long ru_oublock;
 long ru_msgsnd;
 long ru_msgrcv;
 long ru_nsignals;
 long ru_nvcsw;
 long ru_nivcsw;

};










typedef void *rusage_info_t;

struct rusage_info_v0 {
 uint8_t ri_uuid[16];
 uint64_t ri_user_time;
 uint64_t ri_system_time;
 uint64_t ri_pkg_idle_wkups;
 uint64_t ri_interrupt_wkups;
 uint64_t ri_pageins;
 uint64_t ri_wired_size;
 uint64_t ri_resident_size;
 uint64_t ri_phys_footprint;
 uint64_t ri_proc_start_abstime;
 uint64_t ri_proc_exit_abstime;
};

struct rusage_info_v1 {
 uint8_t ri_uuid[16];
 uint64_t ri_user_time;
 uint64_t ri_system_time;
 uint64_t ri_pkg_idle_wkups;
 uint64_t ri_interrupt_wkups;
 uint64_t ri_pageins;
 uint64_t ri_wired_size;
 uint64_t ri_resident_size;
 uint64_t ri_phys_footprint;
 uint64_t ri_proc_start_abstime;
 uint64_t ri_proc_exit_abstime;
 uint64_t ri_child_user_time;
 uint64_t ri_child_system_time;
 uint64_t ri_child_pkg_idle_wkups;
 uint64_t ri_child_interrupt_wkups;
 uint64_t ri_child_pageins;
 uint64_t ri_child_elapsed_abstime;
};

struct rusage_info_v2 {
 uint8_t ri_uuid[16];
 uint64_t ri_user_time;
 uint64_t ri_system_time;
 uint64_t ri_pkg_idle_wkups;
 uint64_t ri_interrupt_wkups;
 uint64_t ri_pageins;
 uint64_t ri_wired_size;
 uint64_t ri_resident_size;
 uint64_t ri_phys_footprint;
 uint64_t ri_proc_start_abstime;
 uint64_t ri_proc_exit_abstime;
 uint64_t ri_child_user_time;
 uint64_t ri_child_system_time;
 uint64_t ri_child_pkg_idle_wkups;
 uint64_t ri_child_interrupt_wkups;
 uint64_t ri_child_pageins;
 uint64_t ri_child_elapsed_abstime;
 uint64_t ri_diskio_bytesread;
 uint64_t ri_diskio_byteswritten;
};

struct rusage_info_v3 {
 uint8_t ri_uuid[16];
 uint64_t ri_user_time;
 uint64_t ri_system_time;
 uint64_t ri_pkg_idle_wkups;
 uint64_t ri_interrupt_wkups;
 uint64_t ri_pageins;
 uint64_t ri_wired_size;
 uint64_t ri_resident_size;
 uint64_t ri_phys_footprint;
 uint64_t ri_proc_start_abstime;
 uint64_t ri_proc_exit_abstime;
 uint64_t ri_child_user_time;
 uint64_t ri_child_system_time;
 uint64_t ri_child_pkg_idle_wkups;
 uint64_t ri_child_interrupt_wkups;
 uint64_t ri_child_pageins;
 uint64_t ri_child_elapsed_abstime;
 uint64_t ri_diskio_bytesread;
 uint64_t ri_diskio_byteswritten;
 uint64_t ri_cpu_time_qos_default;
 uint64_t ri_cpu_time_qos_maintenance;
 uint64_t ri_cpu_time_qos_background;
 uint64_t ri_cpu_time_qos_utility;
 uint64_t ri_cpu_time_qos_legacy;
 uint64_t ri_cpu_time_qos_user_initiated;
 uint64_t ri_cpu_time_qos_user_interactive;
 uint64_t ri_billed_system_time;
 uint64_t ri_serviced_system_time;
};

struct rusage_info_v4 {
 uint8_t ri_uuid[16];
 uint64_t ri_user_time;
 uint64_t ri_system_time;
 uint64_t ri_pkg_idle_wkups;
 uint64_t ri_interrupt_wkups;
 uint64_t ri_pageins;
 uint64_t ri_wired_size;
 uint64_t ri_resident_size;
 uint64_t ri_phys_footprint;
 uint64_t ri_proc_start_abstime;
 uint64_t ri_proc_exit_abstime;
 uint64_t ri_child_user_time;
 uint64_t ri_child_system_time;
 uint64_t ri_child_pkg_idle_wkups;
 uint64_t ri_child_interrupt_wkups;
 uint64_t ri_child_pageins;
 uint64_t ri_child_elapsed_abstime;
 uint64_t ri_diskio_bytesread;
 uint64_t ri_diskio_byteswritten;
 uint64_t ri_cpu_time_qos_default;
 uint64_t ri_cpu_time_qos_maintenance;
 uint64_t ri_cpu_time_qos_background;
 uint64_t ri_cpu_time_qos_utility;
 uint64_t ri_cpu_time_qos_legacy;
 uint64_t ri_cpu_time_qos_user_initiated;
 uint64_t ri_cpu_time_qos_user_interactive;
 uint64_t ri_billed_system_time;
 uint64_t ri_serviced_system_time;
 uint64_t ri_logical_writes;
 uint64_t ri_lifetime_max_phys_footprint;
 uint64_t ri_instructions;
 uint64_t ri_cycles;
 uint64_t ri_billed_energy;
 uint64_t ri_serviced_energy;
 uint64_t ri_interval_max_phys_footprint;
 uint64_t ri_runnable_time;
};

struct rusage_info_v5 {
 uint8_t ri_uuid[16];
 uint64_t ri_user_time;
 uint64_t ri_system_time;
 uint64_t ri_pkg_idle_wkups;
 uint64_t ri_interrupt_wkups;
 uint64_t ri_pageins;
 uint64_t ri_wired_size;
 uint64_t ri_resident_size;
 uint64_t ri_phys_footprint;
 uint64_t ri_proc_start_abstime;
 uint64_t ri_proc_exit_abstime;
 uint64_t ri_child_user_time;
 uint64_t ri_child_system_time;
 uint64_t ri_child_pkg_idle_wkups;
 uint64_t ri_child_interrupt_wkups;
 uint64_t ri_child_pageins;
 uint64_t ri_child_elapsed_abstime;
 uint64_t ri_diskio_bytesread;
 uint64_t ri_diskio_byteswritten;
 uint64_t ri_cpu_time_qos_default;
 uint64_t ri_cpu_time_qos_maintenance;
 uint64_t ri_cpu_time_qos_background;
 uint64_t ri_cpu_time_qos_utility;
 uint64_t ri_cpu_time_qos_legacy;
 uint64_t ri_cpu_time_qos_user_initiated;
 uint64_t ri_cpu_time_qos_user_interactive;
 uint64_t ri_billed_system_time;
 uint64_t ri_serviced_system_time;
 uint64_t ri_logical_writes;
 uint64_t ri_lifetime_max_phys_footprint;
 uint64_t ri_instructions;
 uint64_t ri_cycles;
 uint64_t ri_billed_energy;
 uint64_t ri_serviced_energy;
 uint64_t ri_interval_max_phys_footprint;
 uint64_t ri_runnable_time;
 uint64_t ri_flags;
};

typedef struct rusage_info_v5 rusage_info_current;














struct rlimit {
 rlim_t rlim_cur;
 rlim_t rlim_max;
};




















struct proc_rlimit_control_wakeupmon {
 uint32_t wm_flags;
 int32_t wm_rate;
};





















int getpriority(int, id_t);

int getiopolicy_np(int, int) __attribute__((availability(macosx,introduced=10.5)));

int getrlimit(int, struct rlimit *) __asm("_" "getrlimit" );
int getrusage(int, struct rusage *);
int setpriority(int, id_t, int);

int setiopolicy_np(int, int, int) __attribute__((availability(macosx,introduced=10.5)));

int setrlimit(int, const struct rlimit *) __asm("_" "setrlimit" );


















union wait {
 int w_status;



 struct {

  unsigned int w_Termsig:7,
      w_Coredump:1,
      w_Retcode:8,
      w_Filler:16;







 } w_T;





 struct {

  unsigned int w_Stopval:8,
      w_Stopsig:8,
      w_Filler:16;






 } w_S;
};
pid_t wait(int *) __asm("_" "wait" );
pid_t waitpid(pid_t, int *, int) __asm("_" "waitpid" );

int waitid(idtype_t, id_t, siginfo_t *, int) __asm("_" "waitid" );


pid_t wait3(int *, int, struct rusage *);
pid_t wait4(pid_t, int *, int, struct rusage *);







void *alloca(size_t);













typedef __darwin_ct_rune_t ct_rune_t;

typedef __darwin_rune_t rune_t;



typedef __darwin_wchar_t wchar_t;

typedef struct {
 int quot;
 int rem;
} div_t;

typedef struct {
 long quot;
 long rem;
} ldiv_t;


typedef struct {
 long long quot;
 long long rem;
} lldiv_t;





extern int __mb_cur_max;
void *malloc(size_t __size) __attribute__((__warn_unused_result__)) __attribute__((alloc_size(1)));
void *calloc(size_t __count, size_t __size) __attribute__((__warn_unused_result__)) __attribute__((alloc_size(1,2)));
void free(void *);
void *realloc(void *__ptr, size_t __size) __attribute__((__warn_unused_result__)) __attribute__((alloc_size(2)));

void *valloc(size_t) __attribute__((alloc_size(1)));




void *aligned_alloc(size_t __alignment, size_t __size) __attribute__((__warn_unused_result__)) __attribute__((alloc_size(2))) __attribute__((availability(macosx,introduced=10.15))) __attribute__((availability(ios,introduced=13.0))) __attribute__((availability(tvos,introduced=13.0))) __attribute__((availability(watchos,introduced=6.0)));

int posix_memalign(void **__memptr, size_t __alignment, size_t __size) __attribute__((availability(macosx,introduced=10.6)));


void abort(void) __attribute__((__cold__)) __attribute__((__noreturn__));
int abs(int) __attribute__((__const__));
int atexit(void (* _Nonnull)(void));
double atof(const char *);
int atoi(const char *);
long atol(const char *);

long long
  atoll(const char *);

void *bsearch(const void *__key, const void *__base, size_t __nel,
     size_t __width, int (* _Nonnull __compar)(const void *, const void *));

div_t div(int, int) __attribute__((__const__));
void exit(int) __attribute__((__noreturn__));

char *getenv(const char *);
long labs(long) __attribute__((__const__));
ldiv_t ldiv(long, long) __attribute__((__const__));

long long
  llabs(long long);
lldiv_t lldiv(long long, long long);


int mblen(const char *__s, size_t __n);
size_t mbstowcs(wchar_t * __restrict , const char * __restrict, size_t);
int mbtowc(wchar_t * __restrict, const char * __restrict, size_t);

void qsort(void *__base, size_t __nel, size_t __width,
     int (* _Nonnull __compar)(const void *, const void *));
int rand(void) __attribute__((__availability__(swift, unavailable, message="Use arc4random instead.")));

void srand(unsigned) __attribute__((__availability__(swift, unavailable, message="Use arc4random instead.")));
double strtod(const char *, char **) __asm("_" "strtod" );
float strtof(const char *, char **) __asm("_" "strtof" );
long strtol(const char *__str, char **__endptr, int __base);
long double
  strtold(const char *, char **);

long long
  strtoll(const char *__str, char **__endptr, int __base);

unsigned long
  strtoul(const char *__str, char **__endptr, int __base);

unsigned long long
  strtoull(const char *__str, char **__endptr, int __base);







__attribute__((__availability__(swift, unavailable, message="Use posix_spawn APIs or NSTask instead.")))
__attribute__((availability(macos,introduced=10.0))) __attribute__((availability(ios,unavailable)))
__attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)))
int system(const char *) __asm("_" "system" );


size_t wcstombs(char * __restrict, const wchar_t * __restrict, size_t);
int wctomb(char *, wchar_t);


void _Exit(int) __attribute__((__noreturn__));
long a64l(const char *);
double drand48(void);
char *ecvt(double, int, int *__restrict, int *__restrict);
double erand48(unsigned short[3]);
char *fcvt(double, int, int *__restrict, int *__restrict);
char *gcvt(double, int, char *);
int getsubopt(char **, char * const *, char **);
int grantpt(int);

char *initstate(unsigned, char *, size_t);



long jrand48(unsigned short[3]) __attribute__((__availability__(swift, unavailable, message="Use arc4random instead.")));
char *l64a(long);
void lcong48(unsigned short[7]);
long lrand48(void) __attribute__((__availability__(swift, unavailable, message="Use arc4random instead.")));
char *mktemp(char *);
int mkstemp(char *);
long mrand48(void) __attribute__((__availability__(swift, unavailable, message="Use arc4random instead.")));
long nrand48(unsigned short[3]) __attribute__((__availability__(swift, unavailable, message="Use arc4random instead.")));
int posix_openpt(int);
char *ptsname(int);


int ptsname_r(int fildes, char *buffer, size_t buflen) __attribute__((availability(macos,introduced=10.13.4))) __attribute__((availability(ios,introduced=11.3))) __attribute__((availability(tvos,introduced=11.3))) __attribute__((availability(watchos,introduced=4.3)));


int putenv(char *) __asm("_" "putenv" );
long random(void) __attribute__((__availability__(swift, unavailable, message="Use arc4random instead.")));
int rand_r(unsigned *) __attribute__((__availability__(swift, unavailable, message="Use arc4random instead.")));

char *realpath(const char * __restrict, char * __restrict) __asm("_" "realpath" "$DARWIN_EXTSN");



unsigned short
 *seed48(unsigned short[3]);
int setenv(const char * __name, const char * __value, int __overwrite) __asm("_" "setenv" );

void setkey(const char *) __asm("_" "setkey" );



char *setstate(const char *);
void srand48(long);

void srandom(unsigned);



int unlockpt(int);

int unsetenv(const char *) __asm("_" "unsetenv" );
uint32_t arc4random(void);
void arc4random_addrandom(unsigned char * , int )
    __attribute__((availability(macosx,introduced=10.0))) __attribute__((availability(macosx,deprecated=10.12,message="use arc4random_stir")))
    __attribute__((availability(ios,introduced=2.0))) __attribute__((availability(ios,deprecated=10.0,message="use arc4random_stir")))
    __attribute__((availability(tvos,introduced=2.0))) __attribute__((availability(tvos,deprecated=10.0,message="use arc4random_stir")))
    __attribute__((availability(watchos,introduced=1.0))) __attribute__((availability(watchos,deprecated=3.0,message="use arc4random_stir")));
void arc4random_buf(void * __buf, size_t __nbytes) __attribute__((availability(macosx,introduced=10.7)));
void arc4random_stir(void);
uint32_t
  arc4random_uniform(uint32_t __upper_bound) __attribute__((availability(macosx,introduced=10.7)));

int atexit_b(void (^ _Nonnull)(void)) __attribute__((availability(macosx,introduced=10.6)));
void *bsearch_b(const void *__key, const void *__base, size_t __nel,
     size_t __width, int (^ _Nonnull __compar)(const void *, const void *)) __attribute__((availability(macosx,introduced=10.6)));



char *cgetcap(char *, const char *, int);
int cgetclose(void);
int cgetent(char **, char **, const char *);
int cgetfirst(char **, char **);
int cgetmatch(const char *, const char *);
int cgetnext(char **, char **);
int cgetnum(char *, const char *, long *);
int cgetset(const char *);
int cgetstr(char *, const char *, char **);
int cgetustr(char *, const char *, char **);

int daemon(int, int) __asm("_" "daemon" ) __attribute__((availability(macosx,introduced=10.0,deprecated=10.5,message="Use posix_spawn APIs instead."))) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));
char *devname(dev_t, mode_t);
char *devname_r(dev_t, mode_t, char *buf, int len);
char *getbsize(int *, long *);
int getloadavg(double [], int);
const char
 *getprogname(void);
void setprogname(const char *);








int heapsort(void *__base, size_t __nel, size_t __width,
     int (* _Nonnull __compar)(const void *, const void *));

int heapsort_b(void *__base, size_t __nel, size_t __width,
     int (^ _Nonnull __compar)(const void *, const void *) __attribute__((__noescape__)))
     __attribute__((availability(macosx,introduced=10.6)));

int mergesort(void *__base, size_t __nel, size_t __width,
     int (* _Nonnull __compar)(const void *, const void *));

int mergesort_b(void *__base, size_t __nel, size_t __width,
     int (^ _Nonnull __compar)(const void *, const void *) __attribute__((__noescape__)))
     __attribute__((availability(macosx,introduced=10.6)));

void psort(void *__base, size_t __nel, size_t __width,
     int (* _Nonnull __compar)(const void *, const void *))
     __attribute__((availability(macosx,introduced=10.6)));

void psort_b(void *__base, size_t __nel, size_t __width,
     int (^ _Nonnull __compar)(const void *, const void *) __attribute__((__noescape__)))
     __attribute__((availability(macosx,introduced=10.6)));

void psort_r(void *__base, size_t __nel, size_t __width, void *,
     int (* _Nonnull __compar)(void *, const void *, const void *))
     __attribute__((availability(macosx,introduced=10.6)));

void qsort_b(void *__base, size_t __nel, size_t __width,
     int (^ _Nonnull __compar)(const void *, const void *) __attribute__((__noescape__)))
     __attribute__((availability(macosx,introduced=10.6)));

void qsort_r(void *__base, size_t __nel, size_t __width, void *,
     int (* _Nonnull __compar)(void *, const void *, const void *));
int radixsort(const unsigned char **__base, int __nel, const unsigned char *__table,
     unsigned __endbyte);
int rpmatch(const char *)
 __attribute__((availability(macos,introduced=10.15))) __attribute__((availability(ios,introduced=13.0))) __attribute__((availability(tvos,introduced=13.0))) __attribute__((availability(watchos,introduced=6.0)));
int sradixsort(const unsigned char **__base, int __nel, const unsigned char *__table,
     unsigned __endbyte);
void sranddev(void);
void srandomdev(void);
void *reallocf(void *__ptr, size_t __size) __attribute__((alloc_size(2)));
long long
 strtonum(const char *__numstr, long long __minval, long long __maxval, const char **__errstrp)
 __attribute__((availability(macos,introduced=11.0))) __attribute__((availability(ios,introduced=14.0))) __attribute__((availability(tvos,introduced=14.0))) __attribute__((availability(watchos,introduced=7.0)));

long long
  strtoq(const char *__str, char **__endptr, int __base);
unsigned long long
  strtouq(const char *__str, char **__endptr, int __base);

extern char *suboptarg;









typedef long int ptrdiff_t;
























void *memchr(const void *__s, int __c, size_t __n);
int memcmp(const void *__s1, const void *__s2, size_t __n);
void *memcpy(void *__dst, const void *__src, size_t __n);
void *memmove(void *__dst, const void *__src, size_t __len);
void *memset(void *__b, int __c, size_t __len);
char *strcat(char *__s1, const char *__s2);
char *strchr(const char *__s, int __c);
int strcmp(const char *__s1, const char *__s2);
int strcoll(const char *__s1, const char *__s2);
char *strcpy(char *__dst, const char *__src);
size_t strcspn(const char *__s, const char *__charset);
char *strerror(int __errnum) __asm("_" "strerror" );
size_t strlen(const char *__s);
char *strncat(char *__s1, const char *__s2, size_t __n);
int strncmp(const char *__s1, const char *__s2, size_t __n);
char *strncpy(char *__dst, const char *__src, size_t __n);
char *strpbrk(const char *__s, const char *__charset);
char *strrchr(const char *__s, int __c);
size_t strspn(const char *__s, const char *__charset);
char *strstr(const char *__big, const char *__little);
char *strtok(char *__str, const char *__sep);
size_t strxfrm(char *__s1, const char *__s2, size_t __n);
char *strtok_r(char *__str, const char *__sep, char **__lasts);
int strerror_r(int __errnum, char *__strerrbuf, size_t __buflen);
char *strdup(const char *__s1);
void *memccpy(void *__dst, const void *__src, int __c, size_t __n);
char *stpcpy(char *__dst, const char *__src);
char *stpncpy(char *__dst, const char *__src, size_t __n) __attribute__((availability(macosx,introduced=10.7)));
char *strndup(const char *__s1, size_t __n) __attribute__((availability(macosx,introduced=10.7)));
size_t strnlen(const char *__s1, size_t __n) __attribute__((availability(macosx,introduced=10.7)));
char *strsignal(int __sig);
errno_t memset_s(void *__s, rsize_t __smax, int __c, rsize_t __n) __attribute__((availability(macosx,introduced=10.9)));
void *memmem(const void *__big, size_t __big_len, const void *__little, size_t __little_len) __attribute__((availability(macosx,introduced=10.7)));
void memset_pattern4(void *__b, const void *__pattern4, size_t __len) __attribute__((availability(macosx,introduced=10.5)));
void memset_pattern8(void *__b, const void *__pattern8, size_t __len) __attribute__((availability(macosx,introduced=10.5)));
void memset_pattern16(void *__b, const void *__pattern16, size_t __len) __attribute__((availability(macosx,introduced=10.5)));

char *strcasestr(const char *__big, const char *__little);
char *strnstr(const char *__big, const char *__little, size_t __len);
size_t strlcat(char *__dst, const char *__source, size_t __size);
size_t strlcpy(char *__dst, const char *__source, size_t __size);
void strmode(int __mode, char *__bp);
char *strsep(char **__stringp, const char *__delim);


void swab(const void * __restrict, void * __restrict, ssize_t);

__attribute__((availability(macosx,introduced=10.12.1))) __attribute__((availability(ios,introduced=10.1)))
__attribute__((availability(tvos,introduced=10.0.1))) __attribute__((availability(watchos,introduced=3.1)))
int timingsafe_bcmp(const void *__b1, const void *__b2, size_t __len);

__attribute__((availability(macosx,introduced=11.0))) __attribute__((availability(ios,introduced=14.0)))
__attribute__((availability(tvos,introduced=14.0))) __attribute__((availability(watchos,introduced=7.0)))
int strsignal_r(int __sig, char *__strsignalbuf, size_t __buflen);








int bcmp(const void *, const void *, size_t) ;
void bcopy(const void *, void *, size_t) ;
void bzero(void *, size_t) ;
char *index(const char *, int) ;
char *rindex(const char *, int) ;


int ffs(int);
int strcasecmp(const char *, const char *);
int strncasecmp(const char *, const char *, size_t);





int ffsl(long) __attribute__((availability(macosx,introduced=10.5)));
int ffsll(long long) __attribute__((availability(macosx,introduced=10.9)));
int fls(int) __attribute__((availability(macosx,introduced=10.5)));
int flsl(long) __attribute__((availability(macosx,introduced=10.5)));
int flsll(long long) __attribute__((availability(macosx,introduced=10.9)));


































































































































__attribute__((availability(macosx,introduced=10.4)))
extern intmax_t
imaxabs(intmax_t j);


typedef struct {
 intmax_t quot;
 intmax_t rem;
} imaxdiv_t;

__attribute__((availability(macosx,introduced=10.4)))
extern imaxdiv_t
imaxdiv(intmax_t __numer, intmax_t __denom);


__attribute__((availability(macosx,introduced=10.4)))
extern intmax_t
strtoimax(const char * __restrict __nptr,
   char ** __restrict __endptr,
   int __base);

__attribute__((availability(macosx,introduced=10.4)))
extern uintmax_t
strtoumax(const char * __restrict __nptr,
   char ** __restrict __endptr,
   int __base);


__attribute__((availability(macosx,introduced=10.4)))
extern intmax_t
wcstoimax(const wchar_t * __restrict __nptr,
   wchar_t ** __restrict __endptr,
   int __base);

__attribute__((availability(macosx,introduced=10.4)))
extern uintmax_t
wcstoumax(const wchar_t * __restrict __nptr,
   wchar_t ** __restrict __endptr,
   int __base);














































struct accessx_descriptor {
 unsigned int ad_name_offset;
 int ad_flags;
 int ad_pad[2];
};









int getattrlistbulk(int, void *, void *, size_t, uint64_t) __attribute__((availability(macosx,introduced=10.10)));
int getattrlistat(int, const char *, void *, void *, size_t, unsigned long) __attribute__((availability(macosx,introduced=10.10)));
int setattrlistat(int, const char *, void *, void *, size_t, uint32_t) __attribute__((availability(macosx,introduced=10.13))) __attribute__((availability(ios,introduced=11.0))) __attribute__((availability(tvos,introduced=11.0))) __attribute__((availability(watchos,introduced=4.0)));
int faccessat(int, const char *, int, int) __attribute__((availability(macosx,introduced=10.10)));
int fchownat(int, const char *, uid_t, gid_t, int) __attribute__((availability(macosx,introduced=10.10)));
int linkat(int, const char *, int, const char *, int) __attribute__((availability(macosx,introduced=10.10)));
ssize_t readlinkat(int, const char *, char *, size_t) __attribute__((availability(macosx,introduced=10.10)));
int symlinkat(const char *, int, const char *) __attribute__((availability(macosx,introduced=10.10)));
int unlinkat(int, const char *, int) __attribute__((availability(macosx,introduced=10.10)));


































































void _exit(int) __attribute__((__noreturn__));
int access(const char *, int);
unsigned int
  alarm(unsigned int);
int chdir(const char *);
int chown(const char *, uid_t, gid_t);

int close(int) __asm("_" "close" );

int dup(int);
int dup2(int, int);
int execl(const char * __path, const char * __arg0, ...) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));
int execle(const char * __path, const char * __arg0, ...) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));
int execlp(const char * __file, const char * __arg0, ...) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));
int execv(const char * __path, char * const * __argv) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));
int execve(const char * __file, char * const * __argv, char * const * __envp) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));
int execvp(const char * __file, char * const * __argv) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));
pid_t fork(void) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));
long fpathconf(int, int);
char *getcwd(char *, size_t);
gid_t getegid(void);
uid_t geteuid(void);
gid_t getgid(void);

int getgroups(int, gid_t []) __asm("_" "getgroups" "$DARWIN_EXTSN");



char *getlogin(void);
pid_t getpgrp(void);
pid_t getpid(void);
pid_t getppid(void);
uid_t getuid(void);
int isatty(int);
int link(const char *, const char *);
off_t lseek(int, off_t, int);
long pathconf(const char *, int);

int pause(void) __asm("_" "pause" );

int pipe(int [2]);

ssize_t read(int, void *, size_t) __asm("_" "read" );

int rmdir(const char *);
int setgid(gid_t);
int setpgid(pid_t, pid_t);
pid_t setsid(void);
int setuid(uid_t);

unsigned int
  sleep(unsigned int) __asm("_" "sleep" );

long sysconf(int);
pid_t tcgetpgrp(int);
int tcsetpgrp(int, pid_t);
char *ttyname(int);


int ttyname_r(int, char *, size_t) __asm("_" "ttyname_r" );




int unlink(const char *);

ssize_t write(int __fd, const void * __buf, size_t __nbyte) __asm("_" "write" );
size_t confstr(int, char *, size_t) __asm("_" "confstr" );

int getopt(int, char * const [], const char *) __asm("_" "getopt" );

extern char *optarg;
extern int optind, opterr, optopt;







__attribute__((__deprecated__)) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)))

void *brk(const void *);
int chroot(const char *) ;


char *crypt(const char *, const char *);

void encrypt(char *, int) __asm("_" "encrypt" );



int fchdir(int);
long gethostid(void);
pid_t getpgid(pid_t);
pid_t getsid(pid_t);



int getdtablesize(void) ;
int getpagesize(void) __attribute__((__const__)) ;
char *getpass(const char *) ;




char *getwd(char *) ;


int lchown(const char *, uid_t, gid_t) __asm("_" "lchown" );

int lockf(int, int, off_t) __asm("_" "lockf" );

int nice(int) __asm("_" "nice" );

ssize_t pread(int __fd, void * __buf, size_t __nbyte, off_t __offset) __asm("_" "pread" );

ssize_t pwrite(int __fd, const void * __buf, size_t __nbyte, off_t __offset) __asm("_" "pwrite" );






__attribute__((__deprecated__)) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)))

void *sbrk(int);



pid_t setpgrp(void) __asm("_" "setpgrp" );




int setregid(gid_t, gid_t) __asm("_" "setregid" );

int setreuid(uid_t, uid_t) __asm("_" "setreuid" );

void swab(const void * __restrict, void * __restrict, ssize_t);
void sync(void);
int truncate(const char *, off_t);
useconds_t ualarm(useconds_t, useconds_t);
int usleep(useconds_t) __asm("_" "usleep" );
pid_t fork(void) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));


int fsync(int) __asm("_" "fsync" );

int ftruncate(int, off_t);
int getlogin_r(char *, size_t);
int fchown(int, uid_t, gid_t);
int gethostname(char *, size_t);
ssize_t readlink(const char * __restrict, char * __restrict, size_t);
int setegid(gid_t);
int seteuid(uid_t);
int symlink(const char *, const char *);
int pselect(int, fd_set * __restrict, fd_set * __restrict,
    fd_set * __restrict, const struct timespec * __restrict,
    const sigset_t * __restrict)

__asm("_" "pselect" "$DARWIN_EXTSN" )







;








int select(int, fd_set * __restrict, fd_set * __restrict,
    fd_set * __restrict, struct timeval * __restrict)


__asm("_" "select" "$DARWIN_EXTSN" )







;




typedef __darwin_uuid_t uuid_t;


void _Exit(int) __attribute__((__noreturn__));
int accessx_np(const struct accessx_descriptor *, size_t, int *, uid_t);
int acct(const char *);
int add_profil(char *, size_t, unsigned long, unsigned int) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));
void endusershell(void);
int execvP(const char * __file, const char * __searchpath, char * const * __argv) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));
char *fflagstostr(unsigned long);
int getdomainname(char *, int);
int getgrouplist(const char *, int, int *, int *);













int gethostuuid(uuid_t, const struct timespec *) __attribute__((availability(macosx,introduced=10.5)));




mode_t getmode(const void *, mode_t);
int getpeereid(int, uid_t *, gid_t *);
int getsgroups_np(int *, uuid_t);
char *getusershell(void);
int getwgroups_np(int *, uuid_t);
int initgroups(const char *, int);
int issetugid(void);
char *mkdtemp(char *);
int mknod(const char *, mode_t, dev_t);
int mkpath_np(const char *path, mode_t omode) __attribute__((availability(macosx,introduced=10.8)));
int mkpathat_np(int dfd, const char *path, mode_t omode)
  __attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,introduced=10.0)))
  __attribute__((availability(tvos,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0)));
int mkstemp(char *);
int mkstemps(char *, int);
char *mktemp(char *);
int mkostemp(char *path, int oflags)
  __attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,introduced=10.0)))
  __attribute__((availability(tvos,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0)));
int mkostemps(char *path, int slen, int oflags)
  __attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,introduced=10.0)))
  __attribute__((availability(tvos,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0)));

int mkstemp_dprotected_np(char *path, int dpclass, int dpflags)
  __attribute__((availability(macosx,unavailable))) __attribute__((availability(ios,introduced=10.0)))
  __attribute__((availability(tvos,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0)));
char *mkdtempat_np(int dfd, char *path)
  __attribute__((availability(macosx,introduced=10.13))) __attribute__((availability(ios,introduced=11.0)))
  __attribute__((availability(tvos,introduced=11.0))) __attribute__((availability(watchos,introduced=4.0)));
int mkstempsat_np(int dfd, char *path, int slen)
  __attribute__((availability(macosx,introduced=10.13))) __attribute__((availability(ios,introduced=11.0)))
  __attribute__((availability(tvos,introduced=11.0))) __attribute__((availability(watchos,introduced=4.0)));
int mkostempsat_np(int dfd, char *path, int slen, int oflags)
  __attribute__((availability(macosx,introduced=10.13))) __attribute__((availability(ios,introduced=11.0)))
  __attribute__((availability(tvos,introduced=11.0))) __attribute__((availability(watchos,introduced=4.0)));
int nfssvc(int, void *);
int profil(char *, size_t, unsigned long, unsigned int);

__attribute__((__deprecated__("Use of per-thread security contexts is error-prone and discouraged.")))
int pthread_setugid_np(uid_t, gid_t);
int pthread_getugid_np( uid_t *, gid_t *);

int reboot(int);
int revoke(const char *);

__attribute__((__deprecated__)) int rcmd(char **, int, const char *, const char *, const char *, int *);
__attribute__((__deprecated__)) int rcmd_af(char **, int, const char *, const char *, const char *, int *,
  int);
__attribute__((__deprecated__)) int rresvport(int *);
__attribute__((__deprecated__)) int rresvport_af(int *, int);
__attribute__((__deprecated__)) int iruserok(unsigned long, int, const char *, const char *);
__attribute__((__deprecated__)) int iruserok_sa(const void *, int, int, const char *, const char *);
__attribute__((__deprecated__)) int ruserok(const char *, int, const char *, const char *);

int setdomainname(const char *, int);
int setgroups(int, const gid_t *);
void sethostid(long);
int sethostname(const char *, int);

void setkey(const char *) __asm("_" "setkey" );



int setlogin(const char *);
void *setmode(const char *) __asm("_" "setmode" );
int setrgid(gid_t);
int setruid(uid_t);
int setsgroups_np(int, const uuid_t);
void setusershell(void);
int setwgroups_np(int, const uuid_t);
int strtofflags(char **, unsigned long *, unsigned long *);
int swapon(const char *);
int ttyslot(void);
int undelete(const char *);
int unwhiteout(const char *);
void *valloc(size_t);

__attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)))
__attribute__((availability(ios,deprecated=10.0,message="syscall(2) is unsupported; " "please switch to a supported interface. For SYS_kdebug_trace use kdebug_signpost().")))

__attribute__((availability(macosx,deprecated=10.12,message="syscall(2) is unsupported; " "please switch to a supported interface. For SYS_kdebug_trace use kdebug_signpost().")))

int syscall(int, ...);

extern char *suboptarg;
int getsubopt(char **, char * const *, char **);



int fgetattrlist(int,void*,void*,size_t,unsigned int) __attribute__((availability(macosx,introduced=10.6)));
int fsetattrlist(int,void*,void*,size_t,unsigned int) __attribute__((availability(macosx,introduced=10.6)));
int getattrlist(const char*,void*,void*,size_t,unsigned int) __asm("_" "getattrlist" );
int setattrlist(const char*,void*,void*,size_t,unsigned int) __asm("_" "setattrlist" );
int exchangedata(const char*,const char*,unsigned int) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));
int getdirentriesattr(int,void*,void*,size_t,unsigned int*,unsigned int*,unsigned int*,unsigned int) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));
struct fssearchblock;
struct searchstate;

int searchfs(const char *, struct fssearchblock *, unsigned long *, unsigned int, unsigned int, struct searchstate *) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));
int fsctl(const char *,unsigned long,void*,unsigned int);
int ffsctl(int,unsigned long,void*,unsigned int) __attribute__((availability(macosx,introduced=10.6)));


int fsync_volume_np(int, int) __attribute__((availability(macosx,introduced=10.8)));
int sync_volume_np(const char *, int) __attribute__((availability(macosx,introduced=10.8)));

extern int optreset;


 typedef float float_t;
    typedef double double_t;



















extern int __math_errhandling(void);




extern int __fpclassifyf(float);
extern int __fpclassifyd(double);
extern int __fpclassifyl(long double);




















inline __attribute__ ((__always_inline__)) int __inline_isfinitef(float);
inline __attribute__ ((__always_inline__)) int __inline_isfinited(double);
inline __attribute__ ((__always_inline__)) int __inline_isfinitel(long double);
inline __attribute__ ((__always_inline__)) int __inline_isinff(float);
inline __attribute__ ((__always_inline__)) int __inline_isinfd(double);
inline __attribute__ ((__always_inline__)) int __inline_isinfl(long double);
inline __attribute__ ((__always_inline__)) int __inline_isnanf(float);
inline __attribute__ ((__always_inline__)) int __inline_isnand(double);
inline __attribute__ ((__always_inline__)) int __inline_isnanl(long double);
inline __attribute__ ((__always_inline__)) int __inline_isnormalf(float);
inline __attribute__ ((__always_inline__)) int __inline_isnormald(double);
inline __attribute__ ((__always_inline__)) int __inline_isnormall(long double);
inline __attribute__ ((__always_inline__)) int __inline_signbitf(float);
inline __attribute__ ((__always_inline__)) int __inline_signbitd(double);
inline __attribute__ ((__always_inline__)) int __inline_signbitl(long double);

inline __attribute__ ((__always_inline__)) int __inline_isfinitef(float __x) {
    return __x == __x && __builtin_fabsf(__x) != __builtin_inff();
}
inline __attribute__ ((__always_inline__)) int __inline_isfinited(double __x) {
    return __x == __x && __builtin_fabs(__x) != __builtin_inf();
}
inline __attribute__ ((__always_inline__)) int __inline_isfinitel(long double __x) {
    return __x == __x && __builtin_fabsl(__x) != __builtin_infl();
}
inline __attribute__ ((__always_inline__)) int __inline_isinff(float __x) {
    return __builtin_fabsf(__x) == __builtin_inff();
}
inline __attribute__ ((__always_inline__)) int __inline_isinfd(double __x) {
    return __builtin_fabs(__x) == __builtin_inf();
}
inline __attribute__ ((__always_inline__)) int __inline_isinfl(long double __x) {
    return __builtin_fabsl(__x) == __builtin_infl();
}
inline __attribute__ ((__always_inline__)) int __inline_isnanf(float __x) {
    return __x != __x;
}
inline __attribute__ ((__always_inline__)) int __inline_isnand(double __x) {
    return __x != __x;
}
inline __attribute__ ((__always_inline__)) int __inline_isnanl(long double __x) {
    return __x != __x;
}
inline __attribute__ ((__always_inline__)) int __inline_signbitf(float __x) {
    union { float __f; unsigned int __u; } __u;
    __u.__f = __x;
    return (int)(__u.__u >> 31);
}
inline __attribute__ ((__always_inline__)) int __inline_signbitd(double __x) {
    union { double __f; unsigned long long __u; } __u;
    __u.__f = __x;
    return (int)(__u.__u >> 63);
}
inline __attribute__ ((__always_inline__)) int __inline_signbitl(long double __x) {
    union { long double __f; unsigned long long __u;} __u;
    __u.__f = __x;
    return (int)(__u.__u >> 63);
}

inline __attribute__ ((__always_inline__)) int __inline_isnormalf(float __x) {
    return __inline_isfinitef(__x) && __builtin_fabsf(__x) >= 1.17549435e-38F;
}
inline __attribute__ ((__always_inline__)) int __inline_isnormald(double __x) {
    return __inline_isfinited(__x) && __builtin_fabs(__x) >= 2.2250738585072014e-308;
}
inline __attribute__ ((__always_inline__)) int __inline_isnormall(long double __x) {
    return __inline_isfinitel(__x) && __builtin_fabsl(__x) >= 2.2250738585072014e-308L;
}
extern float acosf(float);
extern double acos(double);
extern long double acosl(long double);

extern float asinf(float);
extern double asin(double);
extern long double asinl(long double);

extern float atanf(float);
extern double atan(double);
extern long double atanl(long double);

extern float atan2f(float, float);
extern double atan2(double, double);
extern long double atan2l(long double, long double);

extern float cosf(float);
extern double cos(double);
extern long double cosl(long double);

extern float sinf(float);
extern double sin(double);
extern long double sinl(long double);

extern float tanf(float);
extern double tan(double);
extern long double tanl(long double);

extern float acoshf(float);
extern double acosh(double);
extern long double acoshl(long double);

extern float asinhf(float);
extern double asinh(double);
extern long double asinhl(long double);

extern float atanhf(float);
extern double atanh(double);
extern long double atanhl(long double);

extern float coshf(float);
extern double cosh(double);
extern long double coshl(long double);

extern float sinhf(float);
extern double sinh(double);
extern long double sinhl(long double);

extern float tanhf(float);
extern double tanh(double);
extern long double tanhl(long double);

extern float expf(float);
extern double exp(double);
extern long double expl(long double);

extern float exp2f(float);
extern double exp2(double);
extern long double exp2l(long double);

extern float expm1f(float);
extern double expm1(double);
extern long double expm1l(long double);

extern float logf(float);
extern double log(double);
extern long double logl(long double);

extern float log10f(float);
extern double log10(double);
extern long double log10l(long double);

extern float log2f(float);
extern double log2(double);
extern long double log2l(long double);

extern float log1pf(float);
extern double log1p(double);
extern long double log1pl(long double);

extern float logbf(float);
extern double logb(double);
extern long double logbl(long double);

extern float modff(float, float *);
extern double modf(double, double *);
extern long double modfl(long double, long double *);

extern float ldexpf(float, int);
extern double ldexp(double, int);
extern long double ldexpl(long double, int);

extern float frexpf(float, int *);
extern double frexp(double, int *);
extern long double frexpl(long double, int *);

extern int ilogbf(float);
extern int ilogb(double);
extern int ilogbl(long double);

extern float scalbnf(float, int);
extern double scalbn(double, int);
extern long double scalbnl(long double, int);

extern float scalblnf(float, long int);
extern double scalbln(double, long int);
extern long double scalblnl(long double, long int);

extern float fabsf(float);
extern double fabs(double);
extern long double fabsl(long double);

extern float cbrtf(float);
extern double cbrt(double);
extern long double cbrtl(long double);

extern float hypotf(float, float);
extern double hypot(double, double);
extern long double hypotl(long double, long double);

extern float powf(float, float);
extern double pow(double, double);
extern long double powl(long double, long double);

extern float sqrtf(float);
extern double sqrt(double);
extern long double sqrtl(long double);

extern float erff(float);
extern double erf(double);
extern long double erfl(long double);

extern float erfcf(float);
extern double erfc(double);
extern long double erfcl(long double);




extern float lgammaf(float);
extern double lgamma(double);
extern long double lgammal(long double);

extern float tgammaf(float);
extern double tgamma(double);
extern long double tgammal(long double);

extern float ceilf(float);
extern double ceil(double);
extern long double ceill(long double);

extern float floorf(float);
extern double floor(double);
extern long double floorl(long double);

extern float nearbyintf(float);
extern double nearbyint(double);
extern long double nearbyintl(long double);

extern float rintf(float);
extern double rint(double);
extern long double rintl(long double);

extern long int lrintf(float);
extern long int lrint(double);
extern long int lrintl(long double);

extern float roundf(float);
extern double round(double);
extern long double roundl(long double);

extern long int lroundf(float);
extern long int lround(double);
extern long int lroundl(long double);




extern long long int llrintf(float);
extern long long int llrint(double);
extern long long int llrintl(long double);

extern long long int llroundf(float);
extern long long int llround(double);
extern long long int llroundl(long double);


extern float truncf(float);
extern double trunc(double);
extern long double truncl(long double);

extern float fmodf(float, float);
extern double fmod(double, double);
extern long double fmodl(long double, long double);

extern float remainderf(float, float);
extern double remainder(double, double);
extern long double remainderl(long double, long double);

extern float remquof(float, float, int *);
extern double remquo(double, double, int *);
extern long double remquol(long double, long double, int *);

extern float copysignf(float, float);
extern double copysign(double, double);
extern long double copysignl(long double, long double);

extern float nanf(const char *);
extern double nan(const char *);
extern long double nanl(const char *);

extern float nextafterf(float, float);
extern double nextafter(double, double);
extern long double nextafterl(long double, long double);

extern double nexttoward(double, long double);
extern float nexttowardf(float, long double);
extern long double nexttowardl(long double, long double);

extern float fdimf(float, float);
extern double fdim(double, double);
extern long double fdiml(long double, long double);

extern float fmaxf(float, float);
extern double fmax(double, double);
extern long double fmaxl(long double, long double);

extern float fminf(float, float);
extern double fmin(double, double);
extern long double fminl(long double, long double);

extern float fmaf(float, float, float);
extern double fma(double, double, double);
extern long double fmal(long double, long double, long double);

extern float lgammaf_r(float, int *) __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=3.1)));
extern double lgamma_r(double, int *) __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=3.1)));
extern long double lgammal_r(long double, int *) __attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=3.1)));
extern float __exp10f(float) __attribute__((availability(macos,introduced=10.9))) __attribute__((availability(ios,introduced=7.0)));
extern double __exp10(double) __attribute__((availability(macos,introduced=10.9))) __attribute__((availability(ios,introduced=7.0)));





inline __attribute__ ((__always_inline__)) void __sincosf(float __x, float *__sinp, float *__cosp);
inline __attribute__ ((__always_inline__)) void __sincos(double __x, double *__sinp, double *__cosp);
extern float __cospif(float) __attribute__((availability(macos,introduced=10.9))) __attribute__((availability(ios,introduced=7.0)));
extern double __cospi(double) __attribute__((availability(macos,introduced=10.9))) __attribute__((availability(ios,introduced=7.0)));
extern float __sinpif(float) __attribute__((availability(macos,introduced=10.9))) __attribute__((availability(ios,introduced=7.0)));
extern double __sinpi(double) __attribute__((availability(macos,introduced=10.9))) __attribute__((availability(ios,introduced=7.0)));
extern float __tanpif(float) __attribute__((availability(macos,introduced=10.9))) __attribute__((availability(ios,introduced=7.0)));
extern double __tanpi(double) __attribute__((availability(macos,introduced=10.9))) __attribute__((availability(ios,introduced=7.0)));
inline __attribute__ ((__always_inline__)) void __sincospif(float __x, float *__sinp, float *__cosp);
inline __attribute__ ((__always_inline__)) void __sincospi(double __x, double *__sinp, double *__cosp);






struct __float2 { float __sinval; float __cosval; };
struct __double2 { double __sinval; double __cosval; };

extern struct __float2 __sincosf_stret(float);
extern struct __double2 __sincos_stret(double);
extern struct __float2 __sincospif_stret(float);
extern struct __double2 __sincospi_stret(double);

inline __attribute__ ((__always_inline__)) void __sincosf(float __x, float *__sinp, float *__cosp) {
    const struct __float2 __stret = __sincosf_stret(__x);
    *__sinp = __stret.__sinval; *__cosp = __stret.__cosval;
}

inline __attribute__ ((__always_inline__)) void __sincos(double __x, double *__sinp, double *__cosp) {
    const struct __double2 __stret = __sincos_stret(__x);
    *__sinp = __stret.__sinval; *__cosp = __stret.__cosval;
}

inline __attribute__ ((__always_inline__)) void __sincospif(float __x, float *__sinp, float *__cosp) {
    const struct __float2 __stret = __sincospif_stret(__x);
    *__sinp = __stret.__sinval; *__cosp = __stret.__cosval;
}

inline __attribute__ ((__always_inline__)) void __sincospi(double __x, double *__sinp, double *__cosp) {
    const struct __double2 __stret = __sincospi_stret(__x);
    *__sinp = __stret.__sinval; *__cosp = __stret.__cosval;
}







extern double j0(double) __attribute__((availability(macos,introduced=10.0))) __attribute__((availability(ios,introduced=3.2)));
extern double j1(double) __attribute__((availability(macos,introduced=10.0))) __attribute__((availability(ios,introduced=3.2)));
extern double jn(int, double) __attribute__((availability(macos,introduced=10.0))) __attribute__((availability(ios,introduced=3.2)));
extern double y0(double) __attribute__((availability(macos,introduced=10.0))) __attribute__((availability(ios,introduced=3.2)));
extern double y1(double) __attribute__((availability(macos,introduced=10.0))) __attribute__((availability(ios,introduced=3.2)));
extern double yn(int, double) __attribute__((availability(macos,introduced=10.0))) __attribute__((availability(ios,introduced=3.2)));
extern double scalb(double, double);
extern int signgam;




struct exception {
    int type;
    char *name;
    double arg1;
    double arg2;
    double retval;
};




extern int eaccess(const char*, int);







extern int finite(double);
extern void setproctitle(const char *fmt, ...);



extern void explicit_bzero(void *b, size_t len);






































void *ruby_xmalloc(size_t) __attribute__((__malloc__)) __attribute__((__returns_nonnull__)) __attribute__((__alloc_size__ (1)));
void *ruby_xmalloc2(size_t,size_t) __attribute__((__malloc__)) __attribute__((__returns_nonnull__)) __attribute__((__alloc_size__ (1,2)));
void *ruby_xcalloc(size_t,size_t) __attribute__((__malloc__)) __attribute__((__returns_nonnull__)) __attribute__((__alloc_size__ (1,2)));
void *ruby_xrealloc(void*,size_t) __attribute__((__returns_nonnull__)) __attribute__((__alloc_size__ (2)));
void *ruby_xrealloc2(void*,size_t,size_t) __attribute__((__returns_nonnull__)) __attribute__((__alloc_size__ (2,3)));
void ruby_xfree(void*);



























































__attribute__ ((__noreturn__)) void rb_assert_failure(const char *, int, const char *, const char *);





























typedef __builtin_va_list va_list;










typedef __builtin_va_list __gnuc_va_list;

typedef unsigned long VALUE;
typedef unsigned long ID;
typedef char ruby_check_sizeof_int[4 == sizeof(int) ? 1 : -1];
typedef char ruby_check_sizeof_long[8 == sizeof(long) ? 1 : -1];

typedef char ruby_check_sizeof_long_long[8 == sizeof(long long) ? 1 : -1];

typedef char ruby_check_sizeof_voidp[8 == sizeof(void*) ? 1 : -1];








































































































































VALUE rb_int2inum(intptr_t);

VALUE rb_uint2inum(uintptr_t);



VALUE rb_ll2inum(long long);
VALUE rb_ull2inum(unsigned long long);
__attribute__ ((__noreturn__)) void rb_out_of_int(long num);



static inline int
rb_long2int_inline(long n)
{
    int i = (int)n;
    if ((long)i != n)
 rb_out_of_int(n);

    return i;
}
static inline long
rb_fix2long(VALUE x)
{
    return ((long)(((long)(x))>>(int)(1)));
}
static inline unsigned long
rb_fix2ulong(VALUE x)
{
    return ((unsigned long)((long)(((long)(x))>>(int)(1))));
}


ID rb_sym2id(VALUE);
VALUE rb_id2sym(ID);
















enum ruby_special_consts {

    RUBY_Qfalse = 0x00,
    RUBY_Qtrue = 0x14,
    RUBY_Qnil = 0x08,
    RUBY_Qundef = 0x34,

    RUBY_IMMEDIATE_MASK = 0x07,
    RUBY_FIXNUM_FLAG = 0x01,
    RUBY_FLONUM_MASK = 0x03,
    RUBY_FLONUM_FLAG = 0x02,
    RUBY_SYMBOL_FLAG = 0x0c,
    RUBY_SPECIAL_SHIFT = 8
};






enum ruby_value_type {
    RUBY_T_NONE = 0x00,

    RUBY_T_OBJECT = 0x01,
    RUBY_T_CLASS = 0x02,
    RUBY_T_MODULE = 0x03,
    RUBY_T_FLOAT = 0x04,
    RUBY_T_STRING = 0x05,
    RUBY_T_REGEXP = 0x06,
    RUBY_T_ARRAY = 0x07,
    RUBY_T_HASH = 0x08,
    RUBY_T_STRUCT = 0x09,
    RUBY_T_BIGNUM = 0x0a,
    RUBY_T_FILE = 0x0b,
    RUBY_T_DATA = 0x0c,
    RUBY_T_MATCH = 0x0d,
    RUBY_T_COMPLEX = 0x0e,
    RUBY_T_RATIONAL = 0x0f,

    RUBY_T_NIL = 0x11,
    RUBY_T_TRUE = 0x12,
    RUBY_T_FALSE = 0x13,
    RUBY_T_SYMBOL = 0x14,
    RUBY_T_FIXNUM = 0x15,
    RUBY_T_UNDEF = 0x16,

    RUBY_T_IMEMO = 0x1a,
    RUBY_T_NODE = 0x1b,
    RUBY_T_ICLASS = 0x1c,
    RUBY_T_ZOMBIE = 0x1d,
    RUBY_T_MOVED = 0x1e,

    RUBY_T_MASK = 0x1f
};



static inline int rb_type(VALUE obj);








void rb_check_type(VALUE,int);

VALUE rb_str_to_str(VALUE);
VALUE rb_string_value(volatile VALUE*);
char *rb_string_value_ptr(volatile VALUE*);
char *rb_string_value_cstr(volatile VALUE*);


void rb_check_safe_obj(VALUE);






VALUE rb_str_export(VALUE);



VALUE rb_str_export_locale(VALUE);

VALUE rb_get_path(VALUE);

VALUE rb_get_path_no_checksafe(VALUE);


void rb_secure(int);
int rb_safe_level(void);
void rb_set_safe_level(int);
void rb_set_safe_level_force(int);
void rb_secure_update(VALUE);
__attribute__ ((__noreturn__)) void rb_insecure_operation(void);

VALUE rb_errinfo(void);
void rb_set_errinfo(VALUE);

long rb_num2long(VALUE);
unsigned long rb_num2ulong(VALUE);
static inline long
rb_num2long_inline(VALUE x)
{
    if ((((int)(long)(x))&RUBY_FIXNUM_FLAG))
 return ((long)(((long)(x))>>(int)(1)));
    else
 return rb_num2long(x);
}
static inline unsigned long
rb_num2ulong_inline(VALUE x)
{
    if ((((int)(long)(x))&RUBY_FIXNUM_FLAG))
 return ((unsigned long)((long)(((long)(x))>>(int)(1))));
    else
 return rb_num2ulong(x);
}

long rb_num2int(VALUE);
long rb_fix2int(VALUE);

static inline int
rb_num2int_inline(VALUE x)
{
    if ((((int)(long)(x))&RUBY_FIXNUM_FLAG))
 return (int)rb_fix2int(x);
    else
 return (int)rb_num2int(x);
}

unsigned long rb_num2uint(VALUE);
unsigned long rb_fix2uint(VALUE);







short rb_num2short(VALUE);
unsigned short rb_num2ushort(VALUE);
short rb_fix2short(VALUE);
unsigned short rb_fix2ushort(VALUE);
static inline short
rb_num2short_inline(VALUE x)
{
    if ((((int)(long)(x))&RUBY_FIXNUM_FLAG))
 return rb_fix2short(x);
    else
 return rb_num2short(x);
}



long long rb_num2ll(VALUE);
unsigned long long rb_num2ull(VALUE);
static inline long long
rb_num2ll_inline(VALUE x)
{
    if ((((int)(long)(x))&RUBY_FIXNUM_FLAG))
 return ((long)(((long)(x))>>(int)(1)));
    else
 return rb_num2ll(x);
}


double rb_num2dbl(VALUE);

VALUE rb_uint2big(uintptr_t);
VALUE rb_int2big(intptr_t);

VALUE rb_newobj(void);
VALUE rb_newobj_of(VALUE, VALUE);
VALUE rb_obj_setup(VALUE obj, VALUE klass, VALUE type);




























__extension__

enum ruby_fl_type {
    RUBY_FL_WB_PROTECTED = (1<<5),
    RUBY_FL_PROMOTED0 = (1<<5),
    RUBY_FL_PROMOTED1 = (1<<6),
    RUBY_FL_PROMOTED = RUBY_FL_PROMOTED0|RUBY_FL_PROMOTED1,
    RUBY_FL_FINALIZE = (1<<7),
    RUBY_FL_TAINT = (1<<8),
    RUBY_FL_UNTRUSTED = RUBY_FL_TAINT,
    RUBY_FL_SEEN_OBJ_ID = (1<<9),
    RUBY_FL_EXIVAR = (1<<10),
    RUBY_FL_FREEZE = (1<<11),

    RUBY_FL_USHIFT = 12,

 RUBY_FL_USER0 = (1<<(RUBY_FL_USHIFT+0)),
    RUBY_FL_USER1 = (1<<(RUBY_FL_USHIFT+1)),
    RUBY_FL_USER2 = (1<<(RUBY_FL_USHIFT+2)),
    RUBY_FL_USER3 = (1<<(RUBY_FL_USHIFT+3)),
    RUBY_FL_USER4 = (1<<(RUBY_FL_USHIFT+4)),
    RUBY_FL_USER5 = (1<<(RUBY_FL_USHIFT+5)),
    RUBY_FL_USER6 = (1<<(RUBY_FL_USHIFT+6)),
    RUBY_FL_USER7 = (1<<(RUBY_FL_USHIFT+7)),
    RUBY_FL_USER8 = (1<<(RUBY_FL_USHIFT+8)),
    RUBY_FL_USER9 = (1<<(RUBY_FL_USHIFT+9)),
    RUBY_FL_USER10 = (1<<(RUBY_FL_USHIFT+10)),
    RUBY_FL_USER11 = (1<<(RUBY_FL_USHIFT+11)),
    RUBY_FL_USER12 = (1<<(RUBY_FL_USHIFT+12)),
    RUBY_FL_USER13 = (1<<(RUBY_FL_USHIFT+13)),
    RUBY_FL_USER14 = (1<<(RUBY_FL_USHIFT+14)),
    RUBY_FL_USER15 = (1<<(RUBY_FL_USHIFT+15)),
    RUBY_FL_USER16 = (1<<(RUBY_FL_USHIFT+16)),
    RUBY_FL_USER17 = (1<<(RUBY_FL_USHIFT+17)),
    RUBY_FL_USER18 = (1<<(RUBY_FL_USHIFT+18)),

    RUBY_FL_USER19 = (1<<(RUBY_FL_USHIFT+19)),




    RUBY_ELTS_SHARED = RUBY_FL_USER2,
    RUBY_FL_DUPPED = (RUBY_T_MASK|RUBY_FL_EXIVAR|RUBY_FL_TAINT),
    RUBY_FL_SINGLETON = RUBY_FL_USER0
};

struct __attribute__((__aligned__(8))) RBasic {
    VALUE flags;
    const VALUE klass;
};

VALUE rb_obj_hide(VALUE obj);
VALUE rb_obj_reveal(VALUE obj, VALUE klass);



enum ruby_rvalue_flags {
    RVALUE_EMBED_LEN_MAX = 3,
};

enum ruby_robject_flags {
    ROBJECT_EMBED_LEN_MAX = RVALUE_EMBED_LEN_MAX,
    ROBJECT_EMBED = RUBY_FL_USER1,

    ROBJECT_ENUM_END
};

struct RObject {
    struct RBasic basic;
    union {
 struct {
     uint32_t numiv;
     VALUE *ivptr;
            void *iv_index_tbl;
 } heap;
 VALUE ary[ROBJECT_EMBED_LEN_MAX];
    } as;
};










enum ruby_rmodule_flags {
    RMODULE_IS_OVERLAID = RUBY_FL_USER2,
    RMODULE_IS_REFINEMENT = RUBY_FL_USER3,
    RMODULE_INCLUDED_INTO_REFINEMENT = RUBY_FL_USER4,

    RMODULE_ENUM_END
};

__attribute__ ((__pure__)) double rb_float_value(VALUE);
VALUE rb_float_new(double);
VALUE rb_float_new_in_heap(double);



enum ruby_rstring_flags {
    RSTRING_NOEMBED = RUBY_FL_USER1,
    RSTRING_EMBED_LEN_MASK = (RUBY_FL_USER2|RUBY_FL_USER3|RUBY_FL_USER4|
         RUBY_FL_USER5|RUBY_FL_USER6),
    RSTRING_EMBED_LEN_SHIFT = (RUBY_FL_USHIFT+2),
    RSTRING_EMBED_LEN_MAX = (int)((sizeof(VALUE)*RVALUE_EMBED_LEN_MAX)/sizeof(char)-1),
    RSTRING_FSTR = RUBY_FL_USER17,

    RSTRING_ENUM_END
};

struct RString {
    struct RBasic basic;
    union {
 struct {
     long len;
     char *ptr;
     union {
  long capa;
  VALUE shared;
     } aux;
 } heap;
 char ary[RSTRING_EMBED_LEN_MAX + 1];
    } as;
};


















enum ruby_rarray_flags {
    RARRAY_EMBED_LEN_MAX = RVALUE_EMBED_LEN_MAX,
    RARRAY_EMBED_FLAG = RUBY_FL_USER1,

    RARRAY_EMBED_LEN_MASK = (RUBY_FL_USER4|RUBY_FL_USER3),
    RARRAY_EMBED_LEN_SHIFT = (RUBY_FL_USHIFT+3),


    RARRAY_TRANSIENT_FLAG = RUBY_FL_USER13,




 RARRAY_ENUM_END
};

struct RArray {
    struct RBasic basic;
    union {
 struct {
     long len;
     union {
  long capa;



                const

                VALUE shared_root;
     } aux;
     const VALUE *ptr;
 } heap;
 const VALUE ary[RARRAY_EMBED_LEN_MAX];
    } as;
};






























struct RRegexp {
    struct RBasic basic;
    struct re_pattern_buffer *ptr;
    const VALUE src;
    unsigned long usecnt;
};


size_t rb_hash_size_num(VALUE hash);


struct RFile {
    struct RBasic basic;
    struct rb_io_t *fptr;
};

struct RData {
    struct RBasic basic;
    void (*dmark)(void*);
    void (*dfree)(void*);
    void *data;
};

typedef struct rb_data_type_struct rb_data_type_t;

struct rb_data_type_struct {
    const char *wrap_struct_name;
    struct {
 void (*dmark)(void*);
 void (*dfree)(void*);
 size_t (*dsize)(const void *);
        void (*dcompact)(void*);
        void *reserved[1];

    } function;
    const rb_data_type_t *parent;
    void *data;

    VALUE flags;
};


struct RTypedData {
    struct RBasic basic;
    const rb_data_type_t *type;
    VALUE typed_flag;
    void *data;
};






typedef void (*RUBY_DATA_FUNC)(void*);







VALUE rb_data_object_wrap(VALUE,void*,RUBY_DATA_FUNC,RUBY_DATA_FUNC);
VALUE rb_data_object_zalloc(VALUE,size_t,RUBY_DATA_FUNC,RUBY_DATA_FUNC);
VALUE rb_data_typed_object_wrap(VALUE klass, void *datap, const rb_data_type_t *);
VALUE rb_data_typed_object_zalloc(VALUE klass, size_t size, const rb_data_type_t *type);
int rb_typeddata_inherited_p(const rb_data_type_t *child, const rb_data_type_t *parent);
int rb_typeddata_is_kind_of(VALUE, const rb_data_type_t *);
void *rb_check_typeddata(VALUE, const rb_data_type_t *);






















int rb_big_sign(VALUE);




















void rb_freeze_singleton_class(VALUE klass);

static inline void
rb_obj_freeze_inline(VALUE x)
{
    if ((!(((VALUE)(x) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(x) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(x))->flags & RUBY_T_MASK) != RUBY_T_NODE)) {
 (void)(((struct RBasic*)(x))->flags |= RUBY_FL_FREEZE);
 if ((((struct RBasic*)(x))->klass) && !(((struct RBasic*)(x))->flags & RUBY_FL_SINGLETON)) {
     rb_freeze_singleton_class(x);
 }
    }
}








__attribute__ ((__deprecated__)) static inline VALUE rb_data_object_wrap_warning(VALUE,void*,RUBY_DATA_FUNC,RUBY_DATA_FUNC);

__attribute__ ((__deprecated__)) static inline void *rb_data_object_get_warning(VALUE);

static inline VALUE
rb_data_object_wrap_warning(VALUE klass, void *ptr, RUBY_DATA_FUNC mark, RUBY_DATA_FUNC free)
{
    return rb_data_object_wrap(klass, ptr, mark, free);
}










static inline void *
rb_data_object_get(VALUE obj)
{
    rb_check_type((VALUE)(obj),(RUBY_T_DATA));
    return ((struct RData *)obj)->data;
}


static inline void *
rb_data_object_get_warning(VALUE obj)
{
    return rb_data_object_get(obj);
}


static inline VALUE
rb_data_object_make(VALUE klass, RUBY_DATA_FUNC mark_func, RUBY_DATA_FUNC free_func, void **datap, size_t size)
{
    VALUE result = rb_data_object_zalloc((klass), (size), (RUBY_DATA_FUNC)(mark_func), (RUBY_DATA_FUNC)(free_func)); (void)((*datap) = (void *)(((struct RData*)(result))->data));;
    return result;
}

static inline VALUE
rb_data_typed_object_make(VALUE klass, const rb_data_type_t *type, void **datap, size_t size)
{
    VALUE result = rb_data_typed_object_zalloc(klass, size, type); (void)((*datap) = (void *)(((struct RData*)(result))->data));;
    return result;
}


__attribute__ ((__deprecated__("by ""rb_data_object_wrap"))) static inline VALUE rb_data_object_alloc(VALUE,void*,RUBY_DATA_FUNC,RUBY_DATA_FUNC);
static inline VALUE
rb_data_object_alloc(VALUE klass, void *data, RUBY_DATA_FUNC dmark, RUBY_DATA_FUNC dfree)
{
    return rb_data_object_wrap(klass, data, dmark, dfree);
}



__attribute__ ((__deprecated__("by ""rb_data_typed_object_wrap"))) static inline VALUE rb_data_typed_object_alloc(VALUE,void*,const rb_data_type_t*);
static inline VALUE
rb_data_typed_object_alloc(VALUE klass, void *datap, const rb_data_type_t *type)
{
    return rb_data_typed_object_wrap(klass, datap, type);
}







void rb_gc_writebarrier(VALUE a, VALUE b);
void rb_gc_writebarrier_unprotect(VALUE obj);














static inline VALUE
rb_obj_wb_unprotect(VALUE x, const char *filename __attribute__ ((unused)), int line __attribute__ ((unused)))
{




    rb_gc_writebarrier_unprotect(x);

    return x;
}

static inline VALUE
rb_obj_written(VALUE a, VALUE oldv __attribute__ ((unused)), VALUE b, const char *filename __attribute__ ((unused)), int line __attribute__ ((unused)))
{





    if (!(((VALUE)(b) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(b) & (VALUE)~((VALUE)RUBY_Qnil)) == 0))) {
 rb_gc_writebarrier(a, b);
    }


    return a;
}

static inline VALUE
rb_obj_write(VALUE a, VALUE *slot, VALUE b, const char *filename __attribute__ ((unused)), int line __attribute__ ((unused)))
{




    *slot = b;


    rb_obj_written(a, ((VALUE)RUBY_Qundef) , b, filename, line);

    return a;
}





static inline VALUE
rb_long2num_inline(long v)
{
    if ((((v) < (9223372036854775807L>>1)+1) && ((v) >= (((long)(-9223372036854775807L -1L))>>(int)(1)))))
 return (((VALUE)(v))<<1 | RUBY_FIXNUM_FLAG);
    else
 return rb_int2big(v);
}

static inline VALUE
rb_ulong2num_inline(unsigned long v)
{
    if (((v) < (9223372036854775807L>>1)+1))
 return (((VALUE)(v))<<1 | RUBY_FIXNUM_FLAG);
    else
 return rb_uint2big(v);
}

static inline char
rb_num2char_inline(VALUE x)
{
    if (( ((RUBY_T_STRING) == RUBY_T_FIXNUM) ? (((int)(long)(x))&RUBY_FIXNUM_FLAG) : ((RUBY_T_STRING) == RUBY_T_TRUE) ? ((x) == ((VALUE)RUBY_Qtrue)) : ((RUBY_T_STRING) == RUBY_T_FALSE) ? ((x) == ((VALUE)RUBY_Qfalse)) : ((RUBY_T_STRING) == RUBY_T_NIL) ? ((x) == ((VALUE)RUBY_Qnil)) : ((RUBY_T_STRING) == RUBY_T_UNDEF) ? ((x) == ((VALUE)RUBY_Qundef)) : ((RUBY_T_STRING) == RUBY_T_SYMBOL) ? ((((VALUE)(x)&~((~(VALUE)0)<<RUBY_SPECIAL_SHIFT)) == RUBY_SYMBOL_FLAG)||(!(((VALUE)(x) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(x) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(x))->flags & RUBY_T_MASK) == (RUBY_T_SYMBOL))) : ((RUBY_T_STRING) == RUBY_T_FLOAT) ? ( ((((int)(long)(x))&RUBY_FLONUM_MASK) == RUBY_FLONUM_FLAG) || (!(((VALUE)(x) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(x) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(x))->flags & RUBY_T_MASK) == RUBY_T_FLOAT)) : (!(((VALUE)(x) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(x) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(x))->flags & RUBY_T_MASK) == (RUBY_T_STRING))) && ((!(((struct RBasic*)(x))->flags & RSTRING_NOEMBED) ? (long)((((struct RBasic*)(x))->flags >> RSTRING_EMBED_LEN_SHIFT) & (RSTRING_EMBED_LEN_MASK >> RSTRING_EMBED_LEN_SHIFT)) : ((struct RString*)(x))->as.heap.len)>=1))
 return (!(((struct RBasic*)(x))->flags & RSTRING_NOEMBED) ? ((struct RString*)(x))->as.ary : ((struct RString*)(x))->as.heap.ptr)[0];
    else
 return (char)(rb_num2int_inline(x) & 0xff);
}















void *rb_alloc_tmp_buffer(volatile VALUE *store, long len) __attribute__((__alloc_size__ (2)));
void *rb_alloc_tmp_buffer_with_count(volatile VALUE *store, size_t len,size_t count) __attribute__((__alloc_size__ (2,3)));
void rb_free_tmp_buffer(volatile VALUE *store);
__attribute__ ((__noreturn__)) void ruby_malloc_size_overflow(size_t, size_t);




static inline int
rb_mul_size_overflow(size_t a, size_t b, size_t max, size_t *c)
{


    __extension__

    unsigned __int128 c2 = (unsigned __int128)a * (unsigned __int128)b;
    if (c2 > max) return 1;
    *c = (size_t)c2;




    return 0;
}
static inline void *
rb_alloc_tmp_buffer2(volatile VALUE *store, long count, size_t elsize)
{
    size_t cnt = (size_t)count;
    if (elsize == sizeof(VALUE)) {
 if ((__builtin_expect(!!(cnt > 9223372036854775807L / sizeof(VALUE)), 0))) {
     ruby_malloc_size_overflow(cnt, elsize);
 }
    }
    else {
 size_t size, max = 9223372036854775807L - sizeof(VALUE) + 1;
 if ((__builtin_expect(!!(rb_mul_size_overflow(cnt, elsize, max, &size)), 0))) {
     ruby_malloc_size_overflow(cnt, elsize);
 }
 cnt = (size + sizeof(VALUE) - 1) / sizeof(VALUE);
    }
    return rb_alloc_tmp_buffer_with_count(store, cnt * sizeof(VALUE), cnt);
}















void rb_obj_infect(VALUE victim, VALUE carrier);

typedef int ruby_glob_func(const char*,VALUE, void*);
void rb_glob(const char*,void(*)(const char*,VALUE,void*),VALUE);
int ruby_glob(const char*,int,ruby_glob_func*,VALUE);
int ruby_brace_glob(const char*,int,ruby_glob_func*,VALUE);

VALUE rb_define_class(const char*,VALUE);
VALUE rb_define_module(const char*);
VALUE rb_define_class_under(VALUE, const char*, VALUE);
VALUE rb_define_module_under(VALUE, const char*);

void rb_include_module(VALUE,VALUE);
void rb_extend_object(VALUE,VALUE);
void rb_prepend_module(VALUE,VALUE);

typedef VALUE rb_gvar_getter_t(ID id, VALUE *data);
typedef void rb_gvar_setter_t(VALUE val, ID id, VALUE *data);
typedef void rb_gvar_marker_t(VALUE *var);

rb_gvar_getter_t rb_gvar_undef_getter;
rb_gvar_setter_t rb_gvar_undef_setter;
rb_gvar_marker_t rb_gvar_undef_marker;

rb_gvar_getter_t rb_gvar_val_getter;
rb_gvar_setter_t rb_gvar_val_setter;
rb_gvar_marker_t rb_gvar_val_marker;

rb_gvar_getter_t rb_gvar_var_getter;
rb_gvar_setter_t rb_gvar_var_setter;
rb_gvar_marker_t rb_gvar_var_marker;

__attribute__ ((__noreturn__)) rb_gvar_setter_t rb_gvar_readonly_setter;

void rb_define_variable(const char*,VALUE*);
void rb_define_virtual_variable(const char*,rb_gvar_getter_t*,rb_gvar_setter_t*);
void rb_define_hooked_variable(const char*,VALUE*,rb_gvar_getter_t*,rb_gvar_setter_t*);
void rb_define_readonly_variable(const char*,const VALUE*);
void rb_define_const(VALUE,const char*,VALUE);
void rb_define_global_const(const char*,VALUE);

void rb_define_method(VALUE,const char*,VALUE(*)(),int);
void rb_define_module_function(VALUE,const char*,VALUE(*)(),int);
void rb_define_global_function(const char*,VALUE(*)(),int);

void rb_undef_method(VALUE,const char*);
void rb_define_alias(VALUE,const char*,const char*);
void rb_define_attr(VALUE,const char*,int,int);

void rb_global_variable(VALUE*);
void rb_gc_register_mark_object(VALUE);
void rb_gc_register_address(VALUE*);
void rb_gc_unregister_address(VALUE*);

ID rb_intern(const char*);
ID rb_intern2(const char*, long);
ID rb_intern_str(VALUE str);
const char *rb_id2name(ID);
ID rb_check_id(volatile VALUE *);
ID rb_to_id(VALUE);
VALUE rb_id2str(ID);
VALUE rb_sym2str(VALUE);
VALUE rb_to_symbol(VALUE name);
VALUE rb_check_symbol(volatile VALUE *namep);





























const char *rb_class2name(VALUE);
const char *rb_obj_classname(VALUE);

void rb_p(VALUE);

VALUE rb_eval_string(const char*);
VALUE rb_eval_string_protect(const char*, int*);
VALUE rb_eval_string_wrap(const char*, int*);
VALUE rb_funcall(VALUE, ID, int, ...);
VALUE rb_funcallv(VALUE, ID, int, const VALUE*);
VALUE rb_funcallv_kw(VALUE, ID, int, const VALUE*, int);
VALUE rb_funcallv_public(VALUE, ID, int, const VALUE*);
VALUE rb_funcallv_public_kw(VALUE, ID, int, const VALUE*, int);
VALUE rb_funcall_passing_block(VALUE, ID, int, const VALUE*);
VALUE rb_funcall_passing_block_kw(VALUE, ID, int, const VALUE*, int);
VALUE rb_funcall_with_block(VALUE, ID, int, const VALUE*, VALUE);
VALUE rb_funcall_with_block_kw(VALUE, ID, int, const VALUE*, VALUE, int);
int rb_scan_args(int, const VALUE*, const char*, ...);
int rb_scan_args_kw(int, int, const VALUE*, const char*, ...);
VALUE rb_call_super(int, const VALUE*);
VALUE rb_call_super_kw(int, const VALUE*, int);
VALUE rb_current_receiver(void);
int rb_get_kwargs(VALUE keyword_hash, const ID *table, int required, int optional, VALUE *);
VALUE rb_extract_keywords(VALUE *orighash);



VALUE rb_gv_set(const char*, VALUE);
VALUE rb_gv_get(const char*);
VALUE rb_iv_get(VALUE, const char*);
VALUE rb_iv_set(VALUE, const char*, VALUE);

VALUE rb_equal(VALUE,VALUE);

VALUE *rb_ruby_verbose_ptr(void);
VALUE *rb_ruby_debug_ptr(void);


enum rb_io_wait_readwrite {RB_IO_WAIT_READABLE, RB_IO_WAIT_WRITABLE};

__attribute__ ((__noreturn__)) void rb_raise(VALUE, const char*, ...) __attribute__((format(printf, 2, 3)));
__attribute__ ((__noreturn__)) void rb_fatal(const char*, ...) __attribute__((format(printf, 1, 2)));
__attribute__((cold)) __attribute__ ((__noreturn__)) void rb_bug(const char*, ...) __attribute__((format(printf, 1, 2)));
__attribute__ ((__noreturn__)) void rb_bug_errno(const char*, int);
__attribute__ ((__noreturn__)) void rb_sys_fail(const char*);
__attribute__ ((__noreturn__)) void rb_sys_fail_str(VALUE);
__attribute__ ((__noreturn__)) void rb_mod_sys_fail(VALUE, const char*);
__attribute__ ((__noreturn__)) void rb_mod_sys_fail_str(VALUE, VALUE);
__attribute__ ((__noreturn__)) void rb_readwrite_sys_fail(enum rb_io_wait_readwrite, const char*);
__attribute__ ((__noreturn__)) void rb_iter_break(void);
__attribute__ ((__noreturn__)) void rb_iter_break_value(VALUE);
__attribute__ ((__noreturn__)) void rb_exit(int);
__attribute__ ((__noreturn__)) void rb_notimplement(void);
VALUE rb_syserr_new(int, const char *);
VALUE rb_syserr_new_str(int n, VALUE arg);
__attribute__ ((__noreturn__)) void rb_syserr_fail(int, const char*);
__attribute__ ((__noreturn__)) void rb_syserr_fail_str(int, VALUE);
__attribute__ ((__noreturn__)) void rb_mod_syserr_fail(VALUE, int, const char*);
__attribute__ ((__noreturn__)) void rb_mod_syserr_fail_str(VALUE, int, VALUE);
__attribute__ ((__noreturn__)) void rb_readwrite_syserr_fail(enum rb_io_wait_readwrite, int, const char*);


void rb_warning(const char*, ...) __attribute__((format(printf, 1, 2)));
void rb_compile_warning(const char *, int, const char*, ...) __attribute__((format(printf, 3, 4)));
void rb_sys_warning(const char*, ...) __attribute__((format(printf, 1, 2)));

__attribute__((cold)) void rb_warn(const char*, ...) __attribute__((format(printf, 1, 2)));
void rb_compile_warn(const char *, int, const char*, ...) __attribute__((format(printf, 3, 4)));


typedef VALUE rb_block_call_func(VALUE yielded_arg, VALUE callback_arg, int argc, const VALUE *argv, VALUE blockarg);
typedef rb_block_call_func *rb_block_call_func_t;

VALUE rb_each(VALUE);
VALUE rb_yield(VALUE);
VALUE rb_yield_values(int n, ...);
VALUE rb_yield_values2(int n, const VALUE *argv);
VALUE rb_yield_values_kw(int n, const VALUE *argv, int kw_splat);
VALUE rb_yield_splat(VALUE);
VALUE rb_yield_splat_kw(VALUE, int);
VALUE rb_yield_block(VALUE yielded_arg, VALUE callback_arg, int argc, const VALUE *argv, VALUE blockarg);
int rb_keyword_given_p(void);
int rb_block_given_p(void);
void rb_need_block(void);
VALUE rb_iterate(VALUE(*)(VALUE),VALUE,rb_block_call_func_t,VALUE);
VALUE rb_block_call(VALUE,ID,int,const VALUE*,rb_block_call_func_t,VALUE);
VALUE rb_block_call_kw(VALUE,ID,int,const VALUE*,rb_block_call_func_t,VALUE,int);
VALUE rb_rescue(VALUE(*)(VALUE),VALUE,VALUE(*)(VALUE,VALUE),VALUE);
VALUE rb_rescue2(VALUE(*)(VALUE),VALUE,VALUE(*)(VALUE,VALUE),VALUE,...);
VALUE rb_vrescue2(VALUE(*)(VALUE),VALUE,VALUE(*)(VALUE,VALUE),VALUE,va_list);
VALUE rb_ensure(VALUE(*)(VALUE),VALUE,VALUE(*)(VALUE),VALUE);
VALUE rb_catch(const char*,rb_block_call_func_t,VALUE);
VALUE rb_catch_obj(VALUE,rb_block_call_func_t,VALUE);
__attribute__ ((__noreturn__)) void rb_throw(const char*,VALUE);
__attribute__ ((__noreturn__)) void rb_throw_obj(VALUE,VALUE);

VALUE rb_require(const char*);

extern VALUE rb_mKernel;
extern VALUE rb_mComparable;
extern VALUE rb_mEnumerable;
extern VALUE rb_mErrno;
extern VALUE rb_mFileTest;
extern VALUE rb_mGC;
extern VALUE rb_mMath;
extern VALUE rb_mProcess;
extern VALUE rb_mWaitReadable;
extern VALUE rb_mWaitWritable;

extern VALUE rb_cBasicObject;
extern VALUE rb_cObject;
extern VALUE rb_cArray;



extern VALUE rb_cBinding;
extern VALUE rb_cClass;
extern VALUE rb_cCont;
extern VALUE rb_cData;
extern VALUE rb_cDir;
extern VALUE rb_cEncoding;
extern VALUE rb_cEnumerator;
extern VALUE rb_cFalseClass;
extern VALUE rb_cFile;



extern VALUE rb_cComplex;
extern VALUE rb_cFloat;
extern VALUE rb_cHash;
extern VALUE rb_cIO;
extern VALUE rb_cInteger;
extern VALUE rb_cMatch;
extern VALUE rb_cMethod;
extern VALUE rb_cModule;
extern VALUE rb_cNameErrorMesg;
extern VALUE rb_cNilClass;
extern VALUE rb_cNumeric;
extern VALUE rb_cProc;
extern VALUE rb_cRandom;
extern VALUE rb_cRange;
extern VALUE rb_cRational;
extern VALUE rb_cRegexp;
extern VALUE rb_cStat;
extern VALUE rb_cString;
extern VALUE rb_cStruct;
extern VALUE rb_cSymbol;
extern VALUE rb_cThread;
extern VALUE rb_cTime;
extern VALUE rb_cTrueClass;
extern VALUE rb_cUnboundMethod;

extern VALUE rb_eException;
extern VALUE rb_eStandardError;
extern VALUE rb_eSystemExit;
extern VALUE rb_eInterrupt;
extern VALUE rb_eSignal;
extern VALUE rb_eFatal;
extern VALUE rb_eArgError;
extern VALUE rb_eEOFError;
extern VALUE rb_eIndexError;
extern VALUE rb_eStopIteration;
extern VALUE rb_eKeyError;
extern VALUE rb_eRangeError;
extern VALUE rb_eIOError;
extern VALUE rb_eRuntimeError;
extern VALUE rb_eFrozenError;
extern VALUE rb_eSecurityError;
extern VALUE rb_eSystemCallError;
extern VALUE rb_eThreadError;
extern VALUE rb_eTypeError;
extern VALUE rb_eZeroDivError;
extern VALUE rb_eNotImpError;
extern VALUE rb_eNoMemError;
extern VALUE rb_eNoMethodError;
extern VALUE rb_eFloatDomainError;
extern VALUE rb_eLocalJumpError;
extern VALUE rb_eSysStackError;
extern VALUE rb_eRegexpError;
extern VALUE rb_eEncodingError;
extern VALUE rb_eEncCompatError;
extern VALUE rb_eNoMatchingPatternError;

extern VALUE rb_eScriptError;
extern VALUE rb_eNameError;
extern VALUE rb_eSyntaxError;
extern VALUE rb_eLoadError;

extern VALUE rb_eMathDomainError;

extern VALUE rb_stdin, rb_stdout, rb_stderr;

static inline VALUE
rb_class_of(VALUE obj)
{
    if (((VALUE)(obj) & RUBY_IMMEDIATE_MASK)) {
 if ((((int)(long)(obj))&RUBY_FIXNUM_FLAG)) return rb_cInteger;
 if (((((int)(long)(obj))&RUBY_FLONUM_MASK) == RUBY_FLONUM_FLAG)) return rb_cFloat;
 if (obj == ((VALUE)RUBY_Qtrue)) return rb_cTrueClass;
 if ((((VALUE)(obj)&~((~(VALUE)0)<<RUBY_SPECIAL_SHIFT)) == RUBY_SYMBOL_FLAG)) return rb_cSymbol;
    }
    else if (!!(((VALUE)(obj) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) {
 if (obj == ((VALUE)RUBY_Qnil)) return rb_cNilClass;
 if (obj == ((VALUE)RUBY_Qfalse)) return rb_cFalseClass;
    }
    return ((struct RBasic*)(obj))->klass;
}

static inline int
rb_type(VALUE obj)
{
    if (((VALUE)(obj) & RUBY_IMMEDIATE_MASK)) {
 if ((((int)(long)(obj))&RUBY_FIXNUM_FLAG)) return RUBY_T_FIXNUM;
        if (((((int)(long)(obj))&RUBY_FLONUM_MASK) == RUBY_FLONUM_FLAG)) return RUBY_T_FLOAT;
        if (obj == ((VALUE)RUBY_Qtrue)) return RUBY_T_TRUE;
 if ((((VALUE)(obj)&~((~(VALUE)0)<<RUBY_SPECIAL_SHIFT)) == RUBY_SYMBOL_FLAG)) return RUBY_T_SYMBOL;
 if (obj == ((VALUE)RUBY_Qundef)) return RUBY_T_UNDEF;
    }
    else if (!!(((VALUE)(obj) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) {
 if (obj == ((VALUE)RUBY_Qnil)) return RUBY_T_NIL;
 if (obj == ((VALUE)RUBY_Qfalse)) return RUBY_T_FALSE;
    }
    return (int)(((struct RBasic*)(obj))->flags & RUBY_T_MASK);
}


















typedef unsigned long st_data_t;





typedef struct st_table st_table;

typedef st_data_t st_index_t;



typedef int st_compare_func(st_data_t, st_data_t);
typedef st_index_t st_hash_func(st_data_t);

typedef char st_check_for_sizeof_st_index_t[8 == (int)sizeof(st_index_t) ? 1 : -1];

struct st_hash_type {
    int (*compare)(st_data_t, st_data_t);
    st_index_t (*hash)(st_data_t);
};








typedef struct st_table_entry st_table_entry;

struct st_table_entry;

struct st_table {

    unsigned char entry_power, bin_power, size_ind;

    unsigned int rebuilds_num;
    const struct st_hash_type *type;

    st_index_t num_entries;

    st_index_t *bins;



    st_index_t entries_start, entries_bound;

    st_table_entry *entries;
};


enum st_retval {ST_CONTINUE, ST_STOP, ST_DELETE, ST_CHECK, ST_REPLACE};

st_table *rb_st_init_table(const struct st_hash_type *);
st_table *rb_st_init_table_with_size(const struct st_hash_type *, st_index_t);
st_table *rb_st_init_numtable(void);
st_table *rb_st_init_numtable_with_size(st_index_t);
st_table *rb_st_init_strtable(void);
st_table *rb_st_init_strtable_with_size(st_index_t);
st_table *rb_st_init_strcasetable(void);
st_table *rb_st_init_strcasetable_with_size(st_index_t);
int rb_st_delete(st_table *, st_data_t *, st_data_t *);
int rb_st_delete_safe(st_table *, st_data_t *, st_data_t *, st_data_t);
int rb_st_shift(st_table *, st_data_t *, st_data_t *);
int rb_st_insert(st_table *, st_data_t, st_data_t);
int rb_st_insert2(st_table *, st_data_t, st_data_t, st_data_t (*)(st_data_t));
int rb_st_lookup(st_table *, st_data_t, st_data_t *);
int rb_st_get_key(st_table *, st_data_t, st_data_t *);
typedef int st_update_callback_func(st_data_t *key, st_data_t *value, st_data_t arg, int existing);



int rb_st_update(st_table *table, st_data_t key, st_update_callback_func *func, st_data_t arg);
typedef int st_foreach_callback_func(st_data_t, st_data_t, st_data_t);
typedef int st_foreach_check_callback_func(st_data_t, st_data_t, st_data_t, int);
int rb_st_foreach_with_replace(st_table *tab, st_foreach_check_callback_func *func, st_update_callback_func *replace, st_data_t arg);
int rb_st_foreach(st_table *, st_foreach_callback_func *, st_data_t);
int rb_st_foreach_check(st_table *, st_foreach_check_callback_func *, st_data_t, st_data_t);
st_index_t rb_st_keys(st_table *table, st_data_t *keys, st_index_t size);
st_index_t rb_st_keys_check(st_table *table, st_data_t *keys, st_index_t size, st_data_t never);
st_index_t rb_st_values(st_table *table, st_data_t *values, st_index_t size);
st_index_t rb_st_values_check(st_table *table, st_data_t *values, st_index_t size, st_data_t never);
void rb_st_add_direct(st_table *, st_data_t, st_data_t);
void rb_st_free_table(st_table *);
void rb_st_cleanup_safe(st_table *, st_data_t);
void rb_st_clear(st_table *);
st_table *rb_st_copy(st_table *);
__attribute__ ((__const__)) int rb_st_numcmp(st_data_t, st_data_t);
__attribute__ ((__const__)) st_index_t rb_st_numhash(st_data_t);
__attribute__ ((__pure__)) int rb_st_locale_insensitive_strcasecmp(const char *s1, const char *s2);
__attribute__ ((__pure__)) int rb_st_locale_insensitive_strncasecmp(const char *s1, const char *s2, size_t n);
__attribute__ ((__pure__)) size_t rb_st_memsize(const st_table *);
__attribute__ ((__pure__)) st_index_t rb_st_hash(const void *ptr, size_t len, st_index_t h);
__attribute__ ((__const__)) st_index_t rb_st_hash_uint32(st_index_t h, uint32_t i);
__attribute__ ((__const__)) st_index_t rb_st_hash_uint(st_index_t h, st_index_t i);
__attribute__ ((__const__)) st_index_t rb_st_hash_end(st_index_t h);
__attribute__ ((__const__)) st_index_t rb_st_hash_start(st_index_t h);

void rb_hash_bulk_insert_into_st_table(long, const VALUE *, VALUE);


















void rb_mem_clear(VALUE*, long);
VALUE rb_assoc_new(VALUE, VALUE);
VALUE rb_check_array_type(VALUE);
VALUE rb_ary_new(void);
VALUE rb_ary_new_capa(long capa);
VALUE rb_ary_new_from_args(long n, ...);
VALUE rb_ary_new_from_values(long n, const VALUE *elts);
VALUE rb_ary_tmp_new(long);
void rb_ary_free(VALUE);
void rb_ary_modify(VALUE);
VALUE rb_ary_freeze(VALUE);
VALUE rb_ary_shared_with_p(VALUE, VALUE);
VALUE rb_ary_aref(int, const VALUE*, VALUE);
VALUE rb_ary_subseq(VALUE, long, long);
void rb_ary_store(VALUE, long, VALUE);
VALUE rb_ary_dup(VALUE);
VALUE rb_ary_resurrect(VALUE ary);
VALUE rb_ary_to_ary(VALUE);
VALUE rb_ary_to_s(VALUE);
VALUE rb_ary_cat(VALUE, const VALUE *, long);
VALUE rb_ary_push(VALUE, VALUE);
VALUE rb_ary_pop(VALUE);
VALUE rb_ary_shift(VALUE);
VALUE rb_ary_unshift(VALUE, VALUE);
VALUE rb_ary_entry(VALUE, long);
VALUE rb_ary_each(VALUE);
VALUE rb_ary_join(VALUE, VALUE);
VALUE rb_ary_reverse(VALUE);
VALUE rb_ary_rotate(VALUE, long);
VALUE rb_ary_sort(VALUE);
VALUE rb_ary_sort_bang(VALUE);
VALUE rb_ary_delete(VALUE, VALUE);
VALUE rb_ary_delete_at(VALUE, long);
VALUE rb_ary_clear(VALUE);
VALUE rb_ary_plus(VALUE, VALUE);
VALUE rb_ary_concat(VALUE, VALUE);
VALUE rb_ary_assoc(VALUE, VALUE);
VALUE rb_ary_rassoc(VALUE, VALUE);
VALUE rb_ary_includes(VALUE, VALUE);
VALUE rb_ary_cmp(VALUE, VALUE);
VALUE rb_ary_replace(VALUE copy, VALUE orig);
VALUE rb_get_values_at(VALUE, long, int, const VALUE*, VALUE(*)(VALUE,long));
VALUE rb_ary_resize(VALUE ary, long len);

VALUE rb_big_new(size_t, int);
int rb_bigzero_p(VALUE x);
VALUE rb_big_clone(VALUE);
void rb_big_2comp(VALUE);
VALUE rb_big_norm(VALUE);
void rb_big_resize(VALUE big, size_t len);
VALUE rb_cstr_to_inum(const char*, int, int);
VALUE rb_str_to_inum(VALUE, int, int);
VALUE rb_cstr2inum(const char*, int);
VALUE rb_str2inum(VALUE, int);
VALUE rb_big2str(VALUE, int);
long rb_big2long(VALUE);
unsigned long rb_big2ulong(VALUE);

long long rb_big2ll(VALUE);
unsigned long long rb_big2ull(VALUE);

void rb_big_pack(VALUE val, unsigned long *buf, long num_longs);
VALUE rb_big_unpack(unsigned long *buf, long num_longs);
int rb_uv_to_utf8(char[6],unsigned long);
VALUE rb_dbl2big(double);
double rb_big2dbl(VALUE);
VALUE rb_big_cmp(VALUE, VALUE);
VALUE rb_big_eq(VALUE, VALUE);
VALUE rb_big_eql(VALUE, VALUE);
VALUE rb_big_plus(VALUE, VALUE);
VALUE rb_big_minus(VALUE, VALUE);
VALUE rb_big_mul(VALUE, VALUE);
VALUE rb_big_div(VALUE, VALUE);
VALUE rb_big_idiv(VALUE, VALUE);
VALUE rb_big_modulo(VALUE, VALUE);
VALUE rb_big_divmod(VALUE, VALUE);
VALUE rb_big_pow(VALUE, VALUE);
VALUE rb_big_and(VALUE, VALUE);
VALUE rb_big_or(VALUE, VALUE);
VALUE rb_big_xor(VALUE, VALUE);
VALUE rb_big_lshift(VALUE, VALUE);
VALUE rb_big_rshift(VALUE, VALUE);










int rb_integer_pack(VALUE val, void *words, size_t numwords, size_t wordsize, size_t nails, int flags);
VALUE rb_integer_unpack(const void *words, size_t numwords, size_t wordsize, size_t nails, int flags);
size_t rb_absint_size(VALUE val, int *nlz_bits_ret);
size_t rb_absint_numwords(VALUE val, size_t word_numbits, size_t *nlz_bits_ret);
int rb_absint_singlebit_p(VALUE val);


VALUE rb_rational_raw(VALUE, VALUE);
VALUE rb_rational_new(VALUE, VALUE);
VALUE rb_Rational(VALUE, VALUE);
VALUE rb_rational_num(VALUE rat);
VALUE rb_rational_den(VALUE rat);
VALUE rb_flt_rationalize_with_prec(VALUE, VALUE);
VALUE rb_flt_rationalize(VALUE);

VALUE rb_complex_raw(VALUE, VALUE);
VALUE rb_complex_new(VALUE, VALUE);
VALUE rb_complex_new_polar(VALUE abs, VALUE arg);
__attribute__ ((__deprecated__("by ""rb_complex_new_polar"))) VALUE rb_complex_polar(VALUE abs, VALUE arg);
VALUE rb_complex_real(VALUE z);
VALUE rb_complex_imag(VALUE z);
VALUE rb_complex_plus(VALUE x, VALUE y);
VALUE rb_complex_minus(VALUE x, VALUE y);
VALUE rb_complex_mul(VALUE x, VALUE y);
VALUE rb_complex_div(VALUE x, VALUE y);
VALUE rb_complex_uminus(VALUE z);
VALUE rb_complex_conjugate(VALUE z);
VALUE rb_complex_abs(VALUE z);
VALUE rb_complex_arg(VALUE z);
VALUE rb_complex_pow(VALUE base, VALUE exp);
VALUE rb_dbl_complex_new(double real, double imag);

VALUE rb_Complex(VALUE, VALUE);

VALUE rb_class_new(VALUE);
VALUE rb_mod_init_copy(VALUE, VALUE);
VALUE rb_singleton_class_clone(VALUE);
void rb_singleton_class_attached(VALUE,VALUE);
void rb_check_inheritable(VALUE);
VALUE rb_define_class_id(ID, VALUE);
VALUE rb_define_class_id_under(VALUE, ID, VALUE);
VALUE rb_module_new(void);
VALUE rb_define_module_id(ID);
VALUE rb_define_module_id_under(VALUE, ID);
VALUE rb_mod_included_modules(VALUE);
VALUE rb_mod_include_p(VALUE, VALUE);
VALUE rb_mod_ancestors(VALUE);
VALUE rb_class_instance_methods(int, const VALUE*, VALUE);
VALUE rb_class_public_instance_methods(int, const VALUE*, VALUE);
VALUE rb_class_protected_instance_methods(int, const VALUE*, VALUE);
VALUE rb_class_private_instance_methods(int, const VALUE*, VALUE);
VALUE rb_obj_singleton_methods(int, const VALUE*, VALUE);
void rb_define_method_id(VALUE, ID, VALUE (*)(), int);
void rb_undef(VALUE, ID);
void rb_define_protected_method(VALUE, const char*, VALUE (*)(), int);
void rb_define_private_method(VALUE, const char*, VALUE (*)(), int);
void rb_define_singleton_method(VALUE, const char*, VALUE(*)(), int);
VALUE rb_singleton_class(VALUE);

int rb_cmpint(VALUE, VALUE, VALUE);
__attribute__ ((__noreturn__)) void rb_cmperr(VALUE, VALUE);

VALUE rb_fiber_new(rb_block_call_func_t, VALUE);
VALUE rb_fiber_resume(VALUE fib, int argc, const VALUE *argv);
VALUE rb_fiber_resume_kw(VALUE fib, int argc, const VALUE *argv, int kw_splat);
VALUE rb_fiber_yield(int argc, const VALUE *argv);
VALUE rb_fiber_yield_kw(int argc, const VALUE *argv, int kw_splat);
VALUE rb_fiber_current(void);
VALUE rb_fiber_alive_p(VALUE);

VALUE rb_enum_values_pack(int, const VALUE*);

VALUE rb_enumeratorize(VALUE, VALUE, int, const VALUE *);
typedef VALUE rb_enumerator_size_func(VALUE, VALUE, VALUE);
VALUE rb_enumeratorize_with_size(VALUE, VALUE, int, const VALUE *, rb_enumerator_size_func *);
VALUE rb_enumeratorize_with_size_kw(VALUE, VALUE, int, const VALUE *, rb_enumerator_size_func *, int);
















typedef struct {
    VALUE begin;
    VALUE end;
    VALUE step;
    int exclude_end;
} rb_arithmetic_sequence_components_t;
int rb_arithmetic_sequence_extract(VALUE, rb_arithmetic_sequence_components_t *);

VALUE rb_exc_new(VALUE, const char*, long);
VALUE rb_exc_new_cstr(VALUE, const char*);
VALUE rb_exc_new_str(VALUE, VALUE);
__attribute__ ((__noreturn__)) void rb_loaderror(const char*, ...) __attribute__((format(printf, 1, 2)));
__attribute__ ((__noreturn__)) void rb_loaderror_with_path(VALUE path, const char*, ...) __attribute__((format(printf, 2, 3)));
__attribute__ ((__noreturn__)) void rb_name_error(ID, const char*, ...) __attribute__((format(printf, 2, 3)));
__attribute__ ((__noreturn__)) void rb_name_error_str(VALUE, const char*, ...) __attribute__((format(printf, 2, 3)));
__attribute__ ((__noreturn__)) void rb_frozen_error_raise(VALUE, const char*, ...) __attribute__((format(printf, 2, 3)));
__attribute__ ((__noreturn__)) void rb_invalid_str(const char*, const char*);
__attribute__ ((__noreturn__)) void rb_error_frozen(const char*);
__attribute__ ((__noreturn__)) void rb_error_frozen_object(VALUE);
void rb_error_untrusted(VALUE);
void rb_check_frozen(VALUE);
void rb_check_trusted(VALUE);






void rb_check_copyable(VALUE obj, VALUE orig);




int rb_sourceline(void);
const char *rb_sourcefile(void);
VALUE rb_check_funcall(VALUE, ID, int, const VALUE*);
VALUE rb_check_funcall_kw(VALUE, ID, int, const VALUE*, int);

__attribute__ ((__noreturn__)) static void rb_error_arity(int, int, int);
static inline int
rb_check_arity(int argc, int min, int max)
{
    if ((argc < min) || (max != (-1) && argc > max))
 rb_error_arity(argc, min, max);
    return argc;
}


typedef struct {
    int maxfd;
    fd_set *fdset;
} rb_fdset_t;

void rb_fd_init(rb_fdset_t *);
void rb_fd_term(rb_fdset_t *);
void rb_fd_zero(rb_fdset_t *);
void rb_fd_set(int, rb_fdset_t *);
void rb_fd_clr(int, rb_fdset_t *);
int rb_fd_isset(int, const rb_fdset_t *);
void rb_fd_copy(rb_fdset_t *, const fd_set *, int);
void rb_fd_dup(rb_fdset_t *dst, const rb_fdset_t *src);

struct timeval;
int rb_fd_select(int, rb_fdset_t *, rb_fdset_t *, rb_fdset_t *, struct timeval *);

__attribute__ ((__noreturn__)) void rb_exc_raise(VALUE);
__attribute__ ((__noreturn__)) void rb_exc_fatal(VALUE);
__attribute__ ((__noreturn__)) VALUE rb_f_exit(int, const VALUE*);
__attribute__ ((__noreturn__)) VALUE rb_f_abort(int, const VALUE*);
void rb_remove_method(VALUE, const char*);
void rb_remove_method_id(VALUE, ID);
typedef VALUE (*rb_alloc_func_t)(VALUE);
void rb_define_alloc_func(VALUE, rb_alloc_func_t);
void rb_undef_alloc_func(VALUE);
rb_alloc_func_t rb_get_alloc_func(VALUE);
void rb_clear_constant_cache(void);
void rb_clear_method_cache_by_class(VALUE);
void rb_alias(VALUE, ID, ID);
void rb_attr(VALUE,ID,int,int,int);
int rb_method_boundp(VALUE, ID, int);
int rb_method_basic_definition_p(VALUE, ID);
VALUE rb_eval_cmd(VALUE, VALUE, int);
VALUE rb_eval_cmd_kw(VALUE, VALUE, int);
int rb_obj_respond_to(VALUE, ID, int);
int rb_respond_to(VALUE, ID);
__attribute__ ((__noreturn__)) VALUE rb_f_notimplement(int argc, const VALUE *argv, VALUE obj, VALUE marker);




__attribute__ ((__noreturn__)) void rb_interrupt(void);
VALUE rb_apply(VALUE, ID, VALUE);
void rb_backtrace(void);
ID rb_frame_this_func(void);
VALUE rb_obj_instance_eval(int, const VALUE*, VALUE);
VALUE rb_obj_instance_exec(int, const VALUE*, VALUE);
VALUE rb_mod_module_eval(int, const VALUE*, VALUE);
VALUE rb_mod_module_exec(int, const VALUE*, VALUE);
void rb_load(VALUE, int);
void rb_load_protect(VALUE, int, int*);
__attribute__ ((__noreturn__)) void rb_jump_tag(int);
int rb_provided(const char*);
int rb_feature_provided(const char *, const char **);
void rb_provide(const char*);
VALUE rb_f_require(VALUE, VALUE);
VALUE rb_require_safe(VALUE, int);
VALUE rb_require_string(VALUE);
void rb_obj_call_init(VALUE, int, const VALUE*);
void rb_obj_call_init_kw(VALUE, int, const VALUE*, int);
VALUE rb_class_new_instance(int, const VALUE*, VALUE);
VALUE rb_class_new_instance_kw(int, const VALUE*, VALUE, int);
VALUE rb_block_proc(void);
VALUE rb_block_lambda(void);
VALUE rb_proc_new(rb_block_call_func_t, VALUE);
VALUE rb_obj_is_proc(VALUE);
VALUE rb_proc_call(VALUE, VALUE);
VALUE rb_proc_call_kw(VALUE, VALUE, int);
VALUE rb_proc_call_with_block(VALUE, int argc, const VALUE *argv, VALUE);
VALUE rb_proc_call_with_block_kw(VALUE, int argc, const VALUE *argv, VALUE, int);
int rb_proc_arity(VALUE);
VALUE rb_proc_lambda_p(VALUE);
VALUE rb_binding_new(void);
VALUE rb_obj_method(VALUE, VALUE);
VALUE rb_obj_is_method(VALUE);
VALUE rb_method_call(int, const VALUE*, VALUE);
VALUE rb_method_call_kw(int, const VALUE*, VALUE, int);
VALUE rb_method_call_with_block(int, const VALUE *, VALUE, VALUE);
VALUE rb_method_call_with_block_kw(int, const VALUE *, VALUE, VALUE, int);
int rb_mod_method_arity(VALUE, ID);
int rb_obj_method_arity(VALUE, ID);
VALUE rb_protect(VALUE (*)(VALUE), VALUE, int*);
void rb_set_end_proc(void (*)(VALUE), VALUE);
void rb_thread_schedule(void);
void rb_thread_wait_fd(int);
int rb_thread_fd_writable(int);
void rb_thread_fd_close(int);
int rb_thread_alone(void);
void rb_thread_sleep(int);
void rb_thread_sleep_forever(void);
void rb_thread_sleep_deadly(void);
VALUE rb_thread_stop(void);
VALUE rb_thread_wakeup(VALUE);
VALUE rb_thread_wakeup_alive(VALUE);
VALUE rb_thread_run(VALUE);
VALUE rb_thread_kill(VALUE);
VALUE rb_thread_create(VALUE (*)(void *), void*);
int rb_thread_fd_select(int, rb_fdset_t *, rb_fdset_t *, rb_fdset_t *, struct timeval *);
void rb_thread_wait_for(struct timeval);
VALUE rb_thread_current(void);
VALUE rb_thread_main(void);
VALUE rb_thread_local_aref(VALUE, ID);
VALUE rb_thread_local_aset(VALUE, ID, VALUE);
void rb_thread_atfork(void);
void rb_thread_atfork_before_exec(void);
VALUE rb_exec_recursive(VALUE(*)(VALUE, VALUE, int),VALUE,VALUE);
VALUE rb_exec_recursive_paired(VALUE(*)(VALUE, VALUE, int),VALUE,VALUE,VALUE);
VALUE rb_exec_recursive_outer(VALUE(*)(VALUE, VALUE, int),VALUE,VALUE);
VALUE rb_exec_recursive_paired_outer(VALUE(*)(VALUE, VALUE, int),VALUE,VALUE,VALUE);

VALUE rb_dir_getwd(void);

VALUE rb_file_s_expand_path(int, const VALUE *);
VALUE rb_file_expand_path(VALUE, VALUE);
VALUE rb_file_s_absolute_path(int, const VALUE *);
VALUE rb_file_absolute_path(VALUE, VALUE);
VALUE rb_file_dirname(VALUE fname);
int rb_find_file_ext_safe(VALUE*, const char* const*, int);
VALUE rb_find_file_safe(VALUE, int);
int rb_find_file_ext(VALUE*, const char* const*);
VALUE rb_find_file(VALUE);
VALUE rb_file_directory_p(VALUE,VALUE);
VALUE rb_str_encode_ospath(VALUE);
int rb_is_absolute_path(const char *);

__attribute__((cold)) __attribute__ ((__noreturn__)) void rb_memerror(void);
__attribute__ ((__pure__)) int rb_during_gc(void);
void rb_gc_mark_locations(const VALUE*, const VALUE*);
void rb_mark_tbl(struct st_table*);
void rb_mark_tbl_no_pin(struct st_table*);
void rb_mark_set(struct st_table*);
void rb_mark_hash(struct st_table*);
void rb_gc_update_tbl_refs(st_table *ptr);
void rb_gc_mark_maybe(VALUE);
void rb_gc_mark(VALUE);
void rb_gc_mark_movable(VALUE);
VALUE rb_gc_location(VALUE);
void rb_gc_force_recycle(VALUE);
void rb_gc(void);
void rb_gc_copy_finalizer(VALUE,VALUE);
VALUE rb_gc_enable(void);
VALUE rb_gc_disable(void);
VALUE rb_gc_start(void);
VALUE rb_define_finalizer(VALUE, VALUE);
VALUE rb_undefine_finalizer(VALUE);
size_t rb_gc_count(void);
size_t rb_gc_stat(VALUE);
VALUE rb_gc_latest_gc_info(VALUE);
void rb_gc_adjust_memory_usage(ssize_t);

void rb_st_foreach_safe(struct st_table *, int (*)(st_data_t, st_data_t, st_data_t), st_data_t);
VALUE rb_check_hash_type(VALUE);
void rb_hash_foreach(VALUE, int (*)(VALUE, VALUE, VALUE), VALUE);
VALUE rb_hash(VALUE);
VALUE rb_hash_new(void);
VALUE rb_hash_dup(VALUE);
VALUE rb_hash_freeze(VALUE);
VALUE rb_hash_aref(VALUE, VALUE);
VALUE rb_hash_lookup(VALUE, VALUE);
VALUE rb_hash_lookup2(VALUE, VALUE, VALUE);
VALUE rb_hash_fetch(VALUE, VALUE);
VALUE rb_hash_aset(VALUE, VALUE, VALUE);
VALUE rb_hash_clear(VALUE);
VALUE rb_hash_delete_if(VALUE);
VALUE rb_hash_delete(VALUE,VALUE);
VALUE rb_hash_set_ifnone(VALUE hash, VALUE ifnone);
void rb_hash_bulk_insert(long, const VALUE *, VALUE);
typedef VALUE rb_hash_update_func(VALUE newkey, VALUE oldkey, VALUE value);
VALUE rb_hash_update_by(VALUE hash1, VALUE hash2, rb_hash_update_func *func);
struct st_table *rb_hash_tbl(VALUE, const char *file, int line);
int rb_path_check(const char*);
int rb_env_path_tainted(void);
VALUE rb_env_clear(void);
VALUE rb_hash_size(VALUE);
void rb_hash_free(VALUE);

extern VALUE rb_fs;
extern VALUE rb_output_fs;
extern VALUE rb_rs;
extern VALUE rb_default_rs;
extern VALUE rb_output_rs;
VALUE rb_io_write(VALUE, VALUE);
VALUE rb_io_gets(VALUE);
VALUE rb_io_getbyte(VALUE);
VALUE rb_io_ungetc(VALUE, VALUE);
VALUE rb_io_ungetbyte(VALUE, VALUE);
VALUE rb_io_close(VALUE);
VALUE rb_io_flush(VALUE);
VALUE rb_io_eof(VALUE);
VALUE rb_io_binmode(VALUE);
VALUE rb_io_ascii8bit_binmode(VALUE);
VALUE rb_io_addstr(VALUE, VALUE);
VALUE rb_io_printf(int, const VALUE*, VALUE);
VALUE rb_io_print(int, const VALUE*, VALUE);
VALUE rb_io_puts(int, const VALUE*, VALUE);
VALUE rb_io_fdopen(int, int, const char*);
VALUE rb_io_get_io(VALUE);
VALUE rb_file_open(const char*, const char*);
VALUE rb_file_open_str(VALUE, const char*);
VALUE rb_gets(void);
void rb_write_error(const char*);
void rb_write_error2(const char*, long);
void rb_close_before_exec(int lowfd, int maxhint, VALUE noclose_fds);
int rb_pipe(int *pipes);
int rb_reserved_fd_p(int fd);
int rb_cloexec_open(const char *pathname, int flags, mode_t mode);
int rb_cloexec_dup(int oldfd);
int rb_cloexec_dup2(int oldfd, int newfd);
int rb_cloexec_pipe(int fildes[2]);
int rb_cloexec_fcntl_dupfd(int fd, int minfd);
void rb_update_max_fd(int fd);
void rb_fd_fix_cloexec(int fd);

VALUE rb_marshal_dump(VALUE, VALUE);
VALUE rb_marshal_load(VALUE);
void rb_marshal_define_compat(VALUE newclass, VALUE oldclass, VALUE (*dumper)(VALUE), VALUE (*loader)(VALUE, VALUE));

__attribute__ ((__noreturn__)) void rb_num_zerodiv(void);
VALUE rb_num_coerce_bin(VALUE, VALUE, ID);
VALUE rb_num_coerce_cmp(VALUE, VALUE, ID);
VALUE rb_num_coerce_relop(VALUE, VALUE, ID);
VALUE rb_num_coerce_bit(VALUE, VALUE, ID);
VALUE rb_num2fix(VALUE);
VALUE rb_fix2str(VALUE, int);
__attribute__ ((__const__)) VALUE rb_dbl_cmp(double, double);

int rb_eql(VALUE, VALUE);
VALUE rb_any_to_s(VALUE);
VALUE rb_inspect(VALUE);
VALUE rb_obj_is_instance_of(VALUE, VALUE);
VALUE rb_obj_is_kind_of(VALUE, VALUE);
VALUE rb_obj_alloc(VALUE);
VALUE rb_obj_clone(VALUE);
VALUE rb_obj_dup(VALUE);
VALUE rb_obj_init_copy(VALUE,VALUE);
VALUE rb_obj_taint(VALUE);
__attribute__ ((__pure__)) VALUE rb_obj_tainted(VALUE);
VALUE rb_obj_untaint(VALUE);
VALUE rb_obj_untrust(VALUE);
__attribute__ ((__pure__)) VALUE rb_obj_untrusted(VALUE);
VALUE rb_obj_trust(VALUE);
VALUE rb_obj_freeze(VALUE);
__attribute__ ((__pure__)) VALUE rb_obj_frozen_p(VALUE);
VALUE rb_obj_id(VALUE);
VALUE rb_memory_id(VALUE);
VALUE rb_obj_class(VALUE);
__attribute__ ((__pure__)) VALUE rb_class_real(VALUE);
__attribute__ ((__pure__)) VALUE rb_class_inherited_p(VALUE, VALUE);
VALUE rb_class_superclass(VALUE);
VALUE rb_class_get_superclass(VALUE);
VALUE rb_convert_type(VALUE,int,const char*,const char*);
VALUE rb_check_convert_type(VALUE,int,const char*,const char*);
VALUE rb_check_to_integer(VALUE, const char *);
VALUE rb_check_to_float(VALUE);
VALUE rb_to_int(VALUE);
VALUE rb_check_to_int(VALUE);
VALUE rb_Integer(VALUE);
VALUE rb_to_float(VALUE);
VALUE rb_Float(VALUE);
VALUE rb_String(VALUE);
VALUE rb_Array(VALUE);
VALUE rb_Hash(VALUE);
double rb_cstr_to_dbl(const char*, int);
double rb_str_to_dbl(VALUE, int);

ID rb_id_attrset(ID);
__attribute__ ((__const__)) int rb_is_const_id(ID);
__attribute__ ((__const__)) int rb_is_global_id(ID);
__attribute__ ((__const__)) int rb_is_instance_id(ID);
__attribute__ ((__const__)) int rb_is_attrset_id(ID);
__attribute__ ((__const__)) int rb_is_class_id(ID);
__attribute__ ((__const__)) int rb_is_local_id(ID);
__attribute__ ((__const__)) int rb_is_junk_id(ID);
int rb_symname_p(const char*);
int rb_sym_interned_p(VALUE);
VALUE rb_backref_get(void);
void rb_backref_set(VALUE);
VALUE rb_lastline_get(void);
void rb_lastline_set(VALUE);

void rb_last_status_set(int status, pid_t pid);
VALUE rb_last_status_get(void);
int rb_proc_exec(const char*);
__attribute__ ((__noreturn__)) VALUE rb_f_exec(int, const VALUE*);
pid_t rb_waitpid(pid_t pid, int *status, int flags);
void rb_syswait(pid_t pid);
pid_t rb_spawn(int, const VALUE*);
pid_t rb_spawn_err(int, const VALUE*, char*, size_t);
VALUE rb_proc_times(VALUE);
VALUE rb_detach_process(pid_t pid);

VALUE rb_range_new(VALUE, VALUE, int);
VALUE rb_range_beg_len(VALUE, long*, long*, long, int);
int rb_range_values(VALUE range, VALUE *begp, VALUE *endp, int *exclp);

unsigned int rb_genrand_int32(void);
double rb_genrand_real(void);
void rb_reset_random_seed(void);
VALUE rb_random_bytes(VALUE rnd, long n);
VALUE rb_random_int(VALUE rnd, VALUE max);
unsigned int rb_random_int32(VALUE rnd);
double rb_random_real(VALUE rnd);
unsigned long rb_random_ulong_limited(VALUE rnd, unsigned long limit);
unsigned long rb_genrand_ulong_limited(unsigned long i);

int rb_memcicmp(const void*,const void*,long);
void rb_match_busy(VALUE);
VALUE rb_reg_nth_defined(int, VALUE);
VALUE rb_reg_nth_match(int, VALUE);
int rb_reg_backref_number(VALUE match, VALUE backref);
VALUE rb_reg_last_match(VALUE);
VALUE rb_reg_match_pre(VALUE);
VALUE rb_reg_match_post(VALUE);
VALUE rb_reg_match_last(VALUE);
VALUE rb_reg_new_str(VALUE, int);
VALUE rb_reg_new(const char *, long, int);
VALUE rb_reg_alloc(void);
VALUE rb_reg_init_str(VALUE re, VALUE s, int options);
VALUE rb_reg_match(VALUE, VALUE);
VALUE rb_reg_match2(VALUE);
int rb_reg_options(VALUE);

extern VALUE rb_argv0;
VALUE rb_get_argv(void);
void *rb_load_file(const char*);
void *rb_load_file_str(VALUE);

VALUE rb_f_kill(int, const VALUE*);

void (*ruby_posix_signal(int, void (*)(int)))(int);

const char *ruby_signal_name(int);
void ruby_default_signal(int);

VALUE rb_f_sprintf(int, const VALUE*);
VALUE rb_sprintf(const char*, ...) __attribute__((format(printf, 1, 2)));
VALUE rb_vsprintf(const char*, va_list);
VALUE rb_str_catf(VALUE, const char*, ...) __attribute__((format(printf, 2, 3)));
VALUE rb_str_vcatf(VALUE, const char*, va_list);
VALUE rb_str_format(int, const VALUE *, VALUE);

VALUE rb_str_new(const char*, long);
VALUE rb_str_new_cstr(const char*);
VALUE rb_str_new_shared(VALUE);
VALUE rb_str_new_frozen(VALUE);
VALUE rb_str_new_with_class(VALUE, const char*, long);
VALUE rb_tainted_str_new_cstr(const char*);
VALUE rb_tainted_str_new(const char*, long);
VALUE rb_external_str_new(const char*, long);
VALUE rb_external_str_new_cstr(const char*);
VALUE rb_locale_str_new(const char*, long);
VALUE rb_locale_str_new_cstr(const char*);
VALUE rb_filesystem_str_new(const char*, long);
VALUE rb_filesystem_str_new_cstr(const char*);
VALUE rb_str_buf_new(long);
VALUE rb_str_buf_new_cstr(const char*);
VALUE rb_str_buf_new2(const char*);
VALUE rb_str_tmp_new(long);
VALUE rb_usascii_str_new(const char*, long);
VALUE rb_usascii_str_new_cstr(const char*);
VALUE rb_utf8_str_new(const char*, long);
VALUE rb_utf8_str_new_cstr(const char*);
VALUE rb_str_new_static(const char *, long);
VALUE rb_usascii_str_new_static(const char *, long);
VALUE rb_utf8_str_new_static(const char *, long);
void rb_str_free(VALUE);
void rb_str_shared_replace(VALUE, VALUE);
VALUE rb_str_buf_append(VALUE, VALUE);
VALUE rb_str_buf_cat(VALUE, const char*, long);
VALUE rb_str_buf_cat2(VALUE, const char*);
VALUE rb_str_buf_cat_ascii(VALUE, const char*);
VALUE rb_obj_as_string(VALUE);
VALUE rb_check_string_type(VALUE);
void rb_must_asciicompat(VALUE);
VALUE rb_str_dup(VALUE);
VALUE rb_str_resurrect(VALUE str);
VALUE rb_str_locktmp(VALUE);
VALUE rb_str_unlocktmp(VALUE);
VALUE rb_str_dup_frozen(VALUE);
VALUE rb_str_plus(VALUE, VALUE);
VALUE rb_str_times(VALUE, VALUE);
long rb_str_sublen(VALUE, long);
VALUE rb_str_substr(VALUE, long, long);
VALUE rb_str_subseq(VALUE, long, long);
char *rb_str_subpos(VALUE, long, long*);
void rb_str_modify(VALUE);
void rb_str_modify_expand(VALUE, long);
VALUE rb_str_freeze(VALUE);
void rb_str_set_len(VALUE, long);
VALUE rb_str_resize(VALUE, long);
VALUE rb_str_cat(VALUE, const char*, long);
VALUE rb_str_cat_cstr(VALUE, const char*);
VALUE rb_str_cat2(VALUE, const char*);
VALUE rb_str_append(VALUE, VALUE);
VALUE rb_str_concat(VALUE, VALUE);
st_index_t rb_memhash(const void *ptr, long len);
st_index_t rb_hash_start(st_index_t);
st_index_t rb_hash_uint32(st_index_t, uint32_t);
st_index_t rb_hash_uint(st_index_t, st_index_t);
st_index_t rb_hash_end(st_index_t);
st_index_t rb_str_hash(VALUE);
int rb_str_hash_cmp(VALUE,VALUE);
int rb_str_comparable(VALUE, VALUE);
int rb_str_cmp(VALUE, VALUE);
VALUE rb_str_equal(VALUE str1, VALUE str2);
VALUE rb_str_drop_bytes(VALUE, long);
void rb_str_update(VALUE, long, long, VALUE);
VALUE rb_str_replace(VALUE, VALUE);
VALUE rb_str_inspect(VALUE);
VALUE rb_str_dump(VALUE);
VALUE rb_str_split(VALUE, const char*);
rb_gvar_setter_t rb_str_setter;
VALUE rb_str_intern(VALUE);
VALUE rb_sym_to_s(VALUE);
long rb_str_strlen(VALUE);
VALUE rb_str_length(VALUE);
long rb_str_offset(VALUE, long);
__attribute__ ((__pure__)) size_t rb_str_capacity(VALUE);
VALUE rb_str_ellipsize(VALUE, long);
VALUE rb_str_scrub(VALUE, VALUE);

VALUE rb_sym_all_symbols(void);






















































VALUE rb_struct_new(VALUE, ...);
VALUE rb_struct_define(const char*, ...);
VALUE rb_struct_define_under(VALUE, const char*, ...);
VALUE rb_struct_alloc(VALUE, VALUE);
VALUE rb_struct_initialize(VALUE, VALUE);
VALUE rb_struct_aref(VALUE, VALUE);
VALUE rb_struct_aset(VALUE, VALUE, VALUE);
VALUE rb_struct_getmember(VALUE, ID);
VALUE rb_struct_s_members(VALUE);
VALUE rb_struct_members(VALUE);
VALUE rb_struct_size(VALUE s);
VALUE rb_struct_alloc_noinit(VALUE);
VALUE rb_struct_define_without_accessor(const char *, VALUE, rb_alloc_func_t, ...);
VALUE rb_struct_define_without_accessor_under(VALUE outer, const char *class_name, VALUE super, rb_alloc_func_t alloc, ...);


typedef void rb_unblock_function_t(void *);
typedef VALUE rb_blocking_function_t(void *);
void rb_thread_check_ints(void);
int rb_thread_interrupted(VALUE thval);

VALUE rb_mutex_new(void);
VALUE rb_mutex_locked_p(VALUE mutex);
VALUE rb_mutex_trylock(VALUE mutex);
VALUE rb_mutex_lock(VALUE mutex);
VALUE rb_mutex_unlock(VALUE mutex);
VALUE rb_mutex_sleep(VALUE self, VALUE timeout);
VALUE rb_mutex_synchronize(VALUE mutex, VALUE (*func)(VALUE arg), VALUE arg);

struct timespec;
void rb_timespec_now(struct timespec *);
VALUE rb_time_new(time_t, long);
VALUE rb_time_nano_new(time_t, long);
VALUE rb_time_timespec_new(const struct timespec *, int);
VALUE rb_time_num_new(VALUE, VALUE);
struct timeval rb_time_interval(VALUE num);
struct timeval rb_time_timeval(VALUE time);
struct timespec rb_time_timespec(VALUE time);
struct timespec rb_time_timespec_interval(VALUE num);
VALUE rb_time_utc_offset(VALUE time);

VALUE rb_mod_name(VALUE);
VALUE rb_class_path(VALUE);
VALUE rb_class_path_cached(VALUE);
void rb_set_class_path(VALUE, VALUE, const char*);
void rb_set_class_path_string(VALUE, VALUE, VALUE);
VALUE rb_path_to_class(VALUE);
VALUE rb_path2class(const char*);
VALUE rb_class_name(VALUE);
VALUE rb_autoload_load(VALUE, ID);
VALUE rb_autoload_p(VALUE, ID);
VALUE rb_f_trace_var(int, const VALUE*);
VALUE rb_f_untrace_var(int, const VALUE*);
VALUE rb_f_global_variables(void);
void rb_alias_variable(ID, ID);
void rb_copy_generic_ivar(VALUE,VALUE);
void rb_free_generic_ivar(VALUE);
VALUE rb_ivar_get(VALUE, ID);
VALUE rb_ivar_set(VALUE, ID, VALUE);
VALUE rb_ivar_defined(VALUE, ID);
void rb_ivar_foreach(VALUE, int (*)(ID, VALUE, st_data_t), st_data_t);
st_index_t rb_ivar_count(VALUE);
VALUE rb_attr_get(VALUE, ID);
VALUE rb_obj_instance_variables(VALUE);
VALUE rb_obj_remove_instance_variable(VALUE, VALUE);
void *rb_mod_const_at(VALUE, void*);
void *rb_mod_const_of(VALUE, void*);
VALUE rb_const_list(void*);
VALUE rb_mod_constants(int, const VALUE *, VALUE);
VALUE rb_mod_remove_const(VALUE, VALUE);
int rb_const_defined(VALUE, ID);
int rb_const_defined_at(VALUE, ID);
int rb_const_defined_from(VALUE, ID);
VALUE rb_const_get(VALUE, ID);
VALUE rb_const_get_at(VALUE, ID);
VALUE rb_const_get_from(VALUE, ID);
void rb_const_set(VALUE, ID, VALUE);
VALUE rb_const_remove(VALUE, ID);



VALUE rb_cvar_defined(VALUE, ID);
void rb_cvar_set(VALUE, ID, VALUE);
VALUE rb_cvar_get(VALUE, ID);
void rb_cv_set(VALUE, const char*, VALUE);
VALUE rb_cv_get(VALUE, const char*);
void rb_define_class_variable(VALUE, const char*, VALUE);
VALUE rb_mod_class_variables(int, const VALUE*, VALUE);
VALUE rb_mod_remove_cvar(VALUE, VALUE);

ID rb_frame_callee(void);
int rb_frame_method_id_and_class(ID *idp, VALUE *klassp);
VALUE rb_str_succ(VALUE);
VALUE rb_time_succ(VALUE);
VALUE rb_make_backtrace(void);
VALUE rb_make_exception(int, const VALUE*);



















 __attribute__((__unused__,__weakref__("rb_define_method_id"),__nonnull__ (3)))static void rb_define_method_id0(VALUE klass, ID name,VALUE(*func)(VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_method_id"),__nonnull__ (3)))static void rb_define_method_id1(VALUE klass, ID name,VALUE(*func)(VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_method_id"),__nonnull__ (3)))static void rb_define_method_id2(VALUE klass, ID name,VALUE(*func)(VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_method_id"),__nonnull__ (3)))static void rb_define_method_id3(VALUE klass, ID name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_method_id"),__nonnull__ (3)))static void rb_define_method_id4(VALUE klass, ID name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_method_id"),__nonnull__ (3)))static void rb_define_method_id5(VALUE klass, ID name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_method_id"),__nonnull__ (3)))static void rb_define_method_id6(VALUE klass, ID name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_method_id"),__nonnull__ (3)))static void rb_define_method_id7(VALUE klass, ID name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_method_id"),__nonnull__ (3)))static void rb_define_method_id8(VALUE klass, ID name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_method_id"),__nonnull__ (3)))static void rb_define_method_id9(VALUE klass, ID name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_method_id"),__nonnull__ (3)))static void rb_define_method_id10(VALUE klass, ID name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_method_id"),__nonnull__ (3)))static void rb_define_method_id11(VALUE klass, ID name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_method_id"),__nonnull__ (3)))static void rb_define_method_id12(VALUE klass, ID name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_method_id"),__nonnull__ (3)))static void rb_define_method_id13(VALUE klass, ID name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_method_id"),__nonnull__ (3)))static void rb_define_method_id14(VALUE klass, ID name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_method_id"),__nonnull__ (3)))static void rb_define_method_id15(VALUE klass, ID name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_method_id"),__nonnull__ (3)))static void rb_define_method_idm3(VALUE klass, ID name,VALUE(*func)(),int arity); __attribute__((__unused__,__weakref__("rb_define_method_id"),__nonnull__ (3)))static void rb_define_method_idm2(VALUE klass, ID name,VALUE(*func)(VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_method_id"),__nonnull__ (3)))static void rb_define_method_idm1(VALUE klass, ID name,VALUE(*func)(int,union{VALUE*x;const VALUE*y;}__attribute__((__transparent_union__)),VALUE),int arity);





 __attribute__((__unused__,__weakref__("rb_define_protected_method"),__nonnull__ (2,3)))static void rb_define_protected_method0(VALUE klass, const char *name,VALUE(*func)(VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_protected_method"),__nonnull__ (2,3)))static void rb_define_protected_method1(VALUE klass, const char *name,VALUE(*func)(VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_protected_method"),__nonnull__ (2,3)))static void rb_define_protected_method2(VALUE klass, const char *name,VALUE(*func)(VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_protected_method"),__nonnull__ (2,3)))static void rb_define_protected_method3(VALUE klass, const char *name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_protected_method"),__nonnull__ (2,3)))static void rb_define_protected_method4(VALUE klass, const char *name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_protected_method"),__nonnull__ (2,3)))static void rb_define_protected_method5(VALUE klass, const char *name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_protected_method"),__nonnull__ (2,3)))static void rb_define_protected_method6(VALUE klass, const char *name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_protected_method"),__nonnull__ (2,3)))static void rb_define_protected_method7(VALUE klass, const char *name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_protected_method"),__nonnull__ (2,3)))static void rb_define_protected_method8(VALUE klass, const char *name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_protected_method"),__nonnull__ (2,3)))static void rb_define_protected_method9(VALUE klass, const char *name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_protected_method"),__nonnull__ (2,3)))static void rb_define_protected_method10(VALUE klass, const char *name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_protected_method"),__nonnull__ (2,3)))static void rb_define_protected_method11(VALUE klass, const char *name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_protected_method"),__nonnull__ (2,3)))static void rb_define_protected_method12(VALUE klass, const char *name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_protected_method"),__nonnull__ (2,3)))static void rb_define_protected_method13(VALUE klass, const char *name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_protected_method"),__nonnull__ (2,3)))static void rb_define_protected_method14(VALUE klass, const char *name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_protected_method"),__nonnull__ (2,3)))static void rb_define_protected_method15(VALUE klass, const char *name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_protected_method"),__nonnull__ (2,3)))static void rb_define_protected_methodm3(VALUE klass, const char *name,VALUE(*func)(),int arity); __attribute__((__unused__,__weakref__("rb_define_protected_method"),__nonnull__ (2,3)))static void rb_define_protected_methodm2(VALUE klass, const char *name,VALUE(*func)(VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_protected_method"),__nonnull__ (2,3)))static void rb_define_protected_methodm1(VALUE klass, const char *name,VALUE(*func)(int,union{VALUE*x;const VALUE*y;}__attribute__((__transparent_union__)),VALUE),int arity);





 __attribute__((__unused__,__weakref__("rb_define_private_method"),__nonnull__ (2,3)))static void rb_define_private_method0(VALUE klass, const char *name,VALUE(*func)(VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_private_method"),__nonnull__ (2,3)))static void rb_define_private_method1(VALUE klass, const char *name,VALUE(*func)(VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_private_method"),__nonnull__ (2,3)))static void rb_define_private_method2(VALUE klass, const char *name,VALUE(*func)(VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_private_method"),__nonnull__ (2,3)))static void rb_define_private_method3(VALUE klass, const char *name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_private_method"),__nonnull__ (2,3)))static void rb_define_private_method4(VALUE klass, const char *name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_private_method"),__nonnull__ (2,3)))static void rb_define_private_method5(VALUE klass, const char *name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_private_method"),__nonnull__ (2,3)))static void rb_define_private_method6(VALUE klass, const char *name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_private_method"),__nonnull__ (2,3)))static void rb_define_private_method7(VALUE klass, const char *name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_private_method"),__nonnull__ (2,3)))static void rb_define_private_method8(VALUE klass, const char *name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_private_method"),__nonnull__ (2,3)))static void rb_define_private_method9(VALUE klass, const char *name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_private_method"),__nonnull__ (2,3)))static void rb_define_private_method10(VALUE klass, const char *name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_private_method"),__nonnull__ (2,3)))static void rb_define_private_method11(VALUE klass, const char *name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_private_method"),__nonnull__ (2,3)))static void rb_define_private_method12(VALUE klass, const char *name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_private_method"),__nonnull__ (2,3)))static void rb_define_private_method13(VALUE klass, const char *name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_private_method"),__nonnull__ (2,3)))static void rb_define_private_method14(VALUE klass, const char *name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_private_method"),__nonnull__ (2,3)))static void rb_define_private_method15(VALUE klass, const char *name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_private_method"),__nonnull__ (2,3)))static void rb_define_private_methodm3(VALUE klass, const char *name,VALUE(*func)(),int arity); __attribute__((__unused__,__weakref__("rb_define_private_method"),__nonnull__ (2,3)))static void rb_define_private_methodm2(VALUE klass, const char *name,VALUE(*func)(VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_private_method"),__nonnull__ (2,3)))static void rb_define_private_methodm1(VALUE klass, const char *name,VALUE(*func)(int,union{VALUE*x;const VALUE*y;}__attribute__((__transparent_union__)),VALUE),int arity);





 __attribute__((__unused__,__weakref__("rb_define_singleton_method"),__nonnull__ (2,3)))static void rb_define_singleton_method0(VALUE klass, const char *name,VALUE(*func)(VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_singleton_method"),__nonnull__ (2,3)))static void rb_define_singleton_method1(VALUE klass, const char *name,VALUE(*func)(VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_singleton_method"),__nonnull__ (2,3)))static void rb_define_singleton_method2(VALUE klass, const char *name,VALUE(*func)(VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_singleton_method"),__nonnull__ (2,3)))static void rb_define_singleton_method3(VALUE klass, const char *name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_singleton_method"),__nonnull__ (2,3)))static void rb_define_singleton_method4(VALUE klass, const char *name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_singleton_method"),__nonnull__ (2,3)))static void rb_define_singleton_method5(VALUE klass, const char *name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_singleton_method"),__nonnull__ (2,3)))static void rb_define_singleton_method6(VALUE klass, const char *name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_singleton_method"),__nonnull__ (2,3)))static void rb_define_singleton_method7(VALUE klass, const char *name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_singleton_method"),__nonnull__ (2,3)))static void rb_define_singleton_method8(VALUE klass, const char *name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_singleton_method"),__nonnull__ (2,3)))static void rb_define_singleton_method9(VALUE klass, const char *name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_singleton_method"),__nonnull__ (2,3)))static void rb_define_singleton_method10(VALUE klass, const char *name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_singleton_method"),__nonnull__ (2,3)))static void rb_define_singleton_method11(VALUE klass, const char *name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_singleton_method"),__nonnull__ (2,3)))static void rb_define_singleton_method12(VALUE klass, const char *name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_singleton_method"),__nonnull__ (2,3)))static void rb_define_singleton_method13(VALUE klass, const char *name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_singleton_method"),__nonnull__ (2,3)))static void rb_define_singleton_method14(VALUE klass, const char *name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_singleton_method"),__nonnull__ (2,3)))static void rb_define_singleton_method15(VALUE klass, const char *name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_singleton_method"),__nonnull__ (2,3)))static void rb_define_singleton_methodm3(VALUE klass, const char *name,VALUE(*func)(),int arity); __attribute__((__unused__,__weakref__("rb_define_singleton_method"),__nonnull__ (2,3)))static void rb_define_singleton_methodm2(VALUE klass, const char *name,VALUE(*func)(VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_singleton_method"),__nonnull__ (2,3)))static void rb_define_singleton_methodm1(VALUE klass, const char *name,VALUE(*func)(int,union{VALUE*x;const VALUE*y;}__attribute__((__transparent_union__)),VALUE),int arity);




static inline void
rb_clone_setup(VALUE clone, VALUE obj)
{
    rb_obj_setup(clone, rb_singleton_class_clone(obj),
                 ((struct RBasic*)(obj))->flags & ~(((VALUE)RUBY_FL_PROMOTED0)|((VALUE)RUBY_FL_PROMOTED1)|((VALUE)RUBY_FL_FINALIZE)));
    rb_singleton_class_attached((((struct RBasic*)(clone))->klass), clone);
    if (((!(((VALUE)(obj) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(obj) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(obj))->flags & RUBY_T_MASK) != RUBY_T_NODE)?(((struct RBasic*)((obj)))->flags&((RUBY_FL_EXIVAR))):0)) rb_copy_generic_ivar(clone, obj);
}

static inline void
rb_dup_setup(VALUE dup, VALUE obj)
{
    rb_obj_setup(dup, rb_obj_class(obj), (((struct RBasic*)(obj))->flags&(RUBY_FL_DUPPED)));
    if (((!(((VALUE)(obj) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(obj) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(obj))->flags & RUBY_T_MASK) != RUBY_T_NODE)?(((struct RBasic*)((obj)))->flags&((RUBY_FL_EXIVAR))):0)) rb_copy_generic_ivar(dup, obj);
}

static inline long
rb_array_len(VALUE a)
{
    return (((struct RBasic*)(a))->flags & (VALUE)RARRAY_EMBED_FLAG) ?
 (long)((((struct RBasic*)(a))->flags >> RARRAY_EMBED_LEN_SHIFT) & ((VALUE)RARRAY_EMBED_LEN_MASK >> RARRAY_EMBED_LEN_SHIFT)) : ((struct RArray*)(a))->as.heap.len;
}









static inline const VALUE *
rb_array_const_ptr_transient(VALUE a)
{
    return ((((struct RBasic*)(a))->flags & (VALUE)RARRAY_EMBED_FLAG) ? ((struct RArray*)(a))->as.ary : ((struct RArray*)(a))->as.heap.ptr);

}


static inline const VALUE *
rb_array_const_ptr(VALUE a)
{

    void rb_ary_detransient(VALUE a);

    if ((((struct RBasic*)((a)))->flags&(RARRAY_TRANSIENT_FLAG))) {
        rb_ary_detransient(a);
    }

    return rb_array_const_ptr_transient(a);
}


static inline VALUE *
rb_array_ptr_use_start(VALUE a, int allow_transient)
{
    VALUE *rb_ary_ptr_use_start(VALUE ary);


    if (!allow_transient) {
        if ((((struct RBasic*)((a)))->flags&(RARRAY_TRANSIENT_FLAG))) {
            void rb_ary_detransient(VALUE a);
            rb_ary_detransient(a);
        }
    }

    (void)allow_transient;

    return rb_ary_ptr_use_start(a);
}


static inline void
rb_array_ptr_use_end(VALUE a, int allow_transient)
{
    void rb_ary_ptr_use_end(VALUE a);
    rb_ary_ptr_use_end(a);
    (void)allow_transient;
}






int ruby_native_thread_p(void);










typedef uint32_t rb_event_flag_t;
typedef void (*rb_event_hook_func_t)(rb_event_flag_t evflag, VALUE data, VALUE self, ID mid, VALUE klass);

void rb_add_event_hook(rb_event_hook_func_t func, rb_event_flag_t events, VALUE data);
int rb_remove_event_hook(rb_event_hook_func_t func);



static inline int rb_isascii(int c){ return '\0' <= c && c <= '\x7f'; }
static inline int rb_isupper(int c){ return 'A' <= c && c <= 'Z'; }
static inline int rb_islower(int c){ return 'a' <= c && c <= 'z'; }
static inline int rb_isalpha(int c){ return rb_isupper(c) || rb_islower(c); }
static inline int rb_isdigit(int c){ return '0' <= c && c <= '9'; }
static inline int rb_isalnum(int c){ return rb_isalpha(c) || rb_isdigit(c); }
static inline int rb_isxdigit(int c){ return rb_isdigit(c) || ('A' <= c && c <= 'F') || ('a' <= c && c <= 'f'); }
static inline int rb_isblank(int c){ return c == ' ' || c == '\t'; }
static inline int rb_isspace(int c){ return c == ' ' || ('\t' <= c && c <= '\r'); }
static inline int rb_iscntrl(int c){ return ('\0' <= c && c < ' ') || c == '\x7f'; }
static inline int rb_isprint(int c){ return ' ' <= c && c <= '\x7e'; }
static inline int rb_ispunct(int c){ return !rb_isalnum(c); }
static inline int rb_isgraph(int c){ return '!' <= c && c <= '\x7e'; }
static inline int rb_tolower(int c) { return rb_isupper(c) ? (c|0x20) : c; }
static inline int rb_toupper(int c) { return rb_islower(c) ? (c&0x5f) : c; }




int rb_st_locale_insensitive_strcasecmp(const char *s1, const char *s2);
int rb_st_locale_insensitive_strncasecmp(const char *s1, const char *s2, size_t n);

unsigned long ruby_strtoul(const char *str, char **endptr, int base);


int ruby_snprintf(char *str, size_t n, char const *fmt, ...) __attribute__((format(printf, 3, 4)));
int ruby_vsnprintf(char *str, size_t n, char const *fmt, va_list ap);


int rb_empty_keyword_given_p(void);

































__attribute__ ((__always_inline__)) static int rb_scan_args_lead_p(const char *fmt);
static inline int
rb_scan_args_lead_p(const char *fmt)
{
    return ((unsigned char)((fmt[0])-'0')<10);
}

__attribute__ ((__always_inline__)) static int rb_scan_args_n_lead(const char *fmt);
static inline int
rb_scan_args_n_lead(const char *fmt)
{
    return (rb_scan_args_lead_p(fmt) ? fmt[0]-'0' : 0);
}

__attribute__ ((__always_inline__)) static int rb_scan_args_opt_p(const char *fmt);
static inline int
rb_scan_args_opt_p(const char *fmt)
{
    return (rb_scan_args_lead_p(fmt) && ((unsigned char)((fmt[1])-'0')<10));
}

__attribute__ ((__always_inline__)) static int rb_scan_args_n_opt(const char *fmt);
static inline int
rb_scan_args_n_opt(const char *fmt)
{
    return (rb_scan_args_opt_p(fmt) ? fmt[1]-'0' : 0);
}

__attribute__ ((__always_inline__)) static int rb_scan_args_var_idx(const char *fmt);
static inline int
rb_scan_args_var_idx(const char *fmt)
{
    return (!rb_scan_args_lead_p(fmt) ? 0 : !((unsigned char)((fmt[1])-'0')<10) ? 1 : 2);
}

__attribute__ ((__always_inline__)) static int rb_scan_args_f_var(const char *fmt);
static inline int
rb_scan_args_f_var(const char *fmt)
{
    return (fmt[rb_scan_args_var_idx(fmt)]=='*');
}

__attribute__ ((__always_inline__)) static int rb_scan_args_trail_idx(const char *fmt);
static inline int
rb_scan_args_trail_idx(const char *fmt)
{
    const int idx = rb_scan_args_var_idx(fmt);
    return idx+(fmt[idx]=='*');
}

__attribute__ ((__always_inline__)) static int rb_scan_args_n_trail(const char *fmt);
static inline int
rb_scan_args_n_trail(const char *fmt)
{
    const int idx = rb_scan_args_trail_idx(fmt);
    return (((unsigned char)((fmt[idx])-'0')<10) ? fmt[idx]-'0' : 0);
}

__attribute__ ((__always_inline__)) static int rb_scan_args_hash_idx(const char *fmt);
static inline int
rb_scan_args_hash_idx(const char *fmt)
{
    const int idx = rb_scan_args_trail_idx(fmt);
    return idx+((unsigned char)((fmt[idx])-'0')<10);
}

__attribute__ ((__always_inline__)) static int rb_scan_args_f_hash(const char *fmt);
static inline int
rb_scan_args_f_hash(const char *fmt)
{
    return (fmt[rb_scan_args_hash_idx(fmt)]==':');
}

__attribute__ ((__always_inline__)) static int rb_scan_args_block_idx(const char *fmt);
static inline int
rb_scan_args_block_idx(const char *fmt)
{
    const int idx = rb_scan_args_hash_idx(fmt);
    return idx+(fmt[idx]==':');
}

__attribute__ ((__always_inline__)) static int rb_scan_args_f_block(const char *fmt);
static inline int
rb_scan_args_f_block(const char *fmt)
{
    return (fmt[rb_scan_args_block_idx(fmt)]=='&');
}








__attribute__ ((__always_inline__)) static int rb_scan_args_set(int argc, const VALUE *argv, int n_lead, int n_opt, int n_trail, int f_var, int f_hash, int f_block, VALUE *vars[], char *fmt, int varc);





inline int
rb_scan_args_set(int argc, const VALUE *argv,
   int n_lead, int n_opt, int n_trail,
   int f_var, int f_hash, int f_block,
   VALUE *vars[], char *fmt __attribute__ ((unused)), int varc __attribute__ ((unused)))

    __attribute__((diagnose_if((!((unsigned char)((fmt[0])-'0')<10) ? (fmt[0]!='*' ? (!((unsigned char)((fmt[0])-'0')<10) ? (fmt[0]!=':' ? (fmt[0]!='&' ? (fmt[0] ? -1 : (0)) : (fmt[0 +1] ? -1 : (0 +1))) : (fmt[0 +1]!='&' ? (fmt[0 +1] ? -1 : (0 +1)) : (fmt[0 +1 +1] ? -1 : (0 +1 +1)))) : (fmt[0 +1]!=':' ? (fmt[0 +1]!='&' ? (fmt[0 +1] ? -1 : (0 +(fmt[0]-'0'))) : (fmt[0 +1 +1] ? -1 : (0 +(fmt[0]-'0')+1))) : (fmt[0 +1 +1]!='&' ? (fmt[0 +1 +1] ? -1 : (0 +(fmt[0]-'0')+1)) : (fmt[0 +1 +1 +1] ? -1 : (0 +(fmt[0]-'0')+1 +1))))) : (!((unsigned char)((fmt[0 +1])-'0')<10) ? (fmt[0 +1]!=':' ? (fmt[0 +1]!='&' ? (fmt[0 +1] ? -1 : (0 +1)) : (fmt[0 +1 +1] ? -1 : (0 +1 +1))) : (fmt[0 +1 +1]!='&' ? (fmt[0 +1 +1] ? -1 : (0 +1 +1)) : (fmt[0 +1 +1 +1] ? -1 : (0 +1 +1 +1)))) : (fmt[0 +1 +1]!=':' ? (fmt[0 +1 +1]!='&' ? (fmt[0 +1 +1] ? -1 : (0 +1 +(fmt[0 +1]-'0'))) : (fmt[0 +1 +1 +1] ? -1 : (0 +1 +(fmt[0 +1]-'0')+1))) : (fmt[0 +1 +1 +1]!='&' ? (fmt[0 +1 +1 +1] ? -1 : (0 +1 +(fmt[0 +1]-'0')+1)) : (fmt[0 +1 +1 +1 +1] ? -1 : (0 +1 +(fmt[0 +1]-'0')+1 +1)))))) : (!((unsigned char)((fmt[0 +1])-'0')<10) ? (fmt[0 +1]!='*' ? (!((unsigned char)((fmt[0 +1])-'0')<10) ? (fmt[0 +1]!=':' ? (fmt[0 +1]!='&' ? (fmt[0 +1] ? -1 : (0 +fmt[0]-'0')) : (fmt[0 +1 +1] ? -1 : (0 +fmt[0]-'0'+1))) : (fmt[0 +1 +1]!='&' ? (fmt[0 +1 +1] ? -1 : (0 +fmt[0]-'0'+1)) : (fmt[0 +1 +1 +1] ? -1 : (0 +fmt[0]-'0'+1 +1)))) : (fmt[0 +1 +1]!=':' ? (fmt[0 +1 +1]!='&' ? (fmt[0 +1 +1] ? -1 : (0 +fmt[0]-'0'+(fmt[0 +1]-'0'))) : (fmt[0 +1 +1 +1] ? -1 : (0 +fmt[0]-'0'+(fmt[0 +1]-'0')+1))) : (fmt[0 +1 +1 +1]!='&' ? (fmt[0 +1 +1 +1] ? -1 : (0 +fmt[0]-'0'+(fmt[0 +1]-'0')+1)) : (fmt[0 +1 +1 +1 +1] ? -1 : (0 +fmt[0]-'0'+(fmt[0 +1]-'0')+1 +1))))) : (!((unsigned char)((fmt[0 +1 +1])-'0')<10) ? (fmt[0 +1 +1]!=':' ? (fmt[0 +1 +1]!='&' ? (fmt[0 +1 +1] ? -1 : (0 +fmt[0]-'0'+1)) : (fmt[0 +1 +1 +1] ? -1 : (0 +fmt[0]-'0'+1 +1))) : (fmt[0 +1 +1 +1]!='&' ? (fmt[0 +1 +1 +1] ? -1 : (0 +fmt[0]-'0'+1 +1)) : (fmt[0 +1 +1 +1 +1] ? -1 : (0 +fmt[0]-'0'+1 +1 +1)))) : (fmt[0 +1 +1 +1]!=':' ? (fmt[0 +1 +1 +1]!='&' ? (fmt[0 +1 +1 +1] ? -1 : (0 +fmt[0]-'0'+1 +(fmt[0 +1 +1]-'0'))) : (fmt[0 +1 +1 +1 +1] ? -1 : (0 +fmt[0]-'0'+1 +(fmt[0 +1 +1]-'0')+1))) : (fmt[0 +1 +1 +1 +1]!='&' ? (fmt[0 +1 +1 +1 +1] ? -1 : (0 +fmt[0]-'0'+1 +(fmt[0 +1 +1]-'0')+1)) : (fmt[0 +1 +1 +1 +1 +1] ? -1 : (0 +fmt[0]-'0'+1 +(fmt[0 +1 +1]-'0')+1 +1)))))) : (fmt[0 +1 +1]!='*' ? (!((unsigned char)((fmt[0 +1 +1])-'0')<10) ? (fmt[0 +1 +1]!=':' ? (fmt[0 +1 +1]!='&' ? (fmt[0 +1 +1] ? -1 : (0 +fmt[0]-'0'+fmt[0 +1]-'0')) : (fmt[0 +1 +1 +1] ? -1 : (0 +fmt[0]-'0'+fmt[0 +1]-'0'+1))) : (fmt[0 +1 +1 +1]!='&' ? (fmt[0 +1 +1 +1] ? -1 : (0 +fmt[0]-'0'+fmt[0 +1]-'0'+1)) : (fmt[0 +1 +1 +1 +1] ? -1 : (0 +fmt[0]-'0'+fmt[0 +1]-'0'+1 +1)))) : (fmt[0 +1 +1 +1]!=':' ? (fmt[0 +1 +1 +1]!='&' ? (fmt[0 +1 +1 +1] ? -1 : (0 +fmt[0]-'0'+fmt[0 +1]-'0'+(fmt[0 +1 +1]-'0'))) : (fmt[0 +1 +1 +1 +1] ? -1 : (0 +fmt[0]-'0'+fmt[0 +1]-'0'+(fmt[0 +1 +1]-'0')+1))) : (fmt[0 +1 +1 +1 +1]!='&' ? (fmt[0 +1 +1 +1 +1] ? -1 : (0 +fmt[0]-'0'+fmt[0 +1]-'0'+(fmt[0 +1 +1]-'0')+1)) : (fmt[0 +1 +1 +1 +1 +1] ? -1 : (0 +fmt[0]-'0'+fmt[0 +1]-'0'+(fmt[0 +1 +1]-'0')+1 +1))))) : (!((unsigned char)((fmt[0 +1 +1 +1])-'0')<10) ? (fmt[0 +1 +1 +1]!=':' ? (fmt[0 +1 +1 +1]!='&' ? (fmt[0 +1 +1 +1] ? -1 : (0 +fmt[0]-'0'+fmt[0 +1]-'0'+1)) : (fmt[0 +1 +1 +1 +1] ? -1 : (0 +fmt[0]-'0'+fmt[0 +1]-'0'+1 +1))) : (fmt[0 +1 +1 +1 +1]!='&' ? (fmt[0 +1 +1 +1 +1] ? -1 : (0 +fmt[0]-'0'+fmt[0 +1]-'0'+1 +1)) : (fmt[0 +1 +1 +1 +1 +1] ? -1 : (0 +fmt[0]-'0'+fmt[0 +1]-'0'+1 +1 +1)))) : (fmt[0 +1 +1 +1 +1]!=':' ? (fmt[0 +1 +1 +1 +1]!='&' ? (fmt[0 +1 +1 +1 +1] ? -1 : (0 +fmt[0]-'0'+fmt[0 +1]-'0'+1 +(fmt[0 +1 +1 +1]-'0'))) : (fmt[0 +1 +1 +1 +1 +1] ? -1 : (0 +fmt[0]-'0'+fmt[0 +1]-'0'+1 +(fmt[0 +1 +1 +1]-'0')+1))) : (fmt[0 +1 +1 +1 +1 +1]!='&' ? (fmt[0 +1 +1 +1 +1 +1] ? -1 : (0 +fmt[0]-'0'+fmt[0 +1]-'0'+1 +(fmt[0 +1 +1 +1]-'0')+1)) : (fmt[0 +1 +1 +1 +1 +1 +1] ? -1 : (0 +fmt[0]-'0'+fmt[0 +1]-'0'+1 +(fmt[0 +1 +1 +1]-'0')+1 +1))))))))<0,"bad scan arg format","error")))
    __attribute__((diagnose_if((!((unsigned char)((fmt[0])-'0')<10) ? (fmt[0]!='*' ? (!((unsigned char)((fmt[0])-'0')<10) ? (fmt[0]!=':' ? (fmt[0]!='&' ? (fmt[0] ? -1 : (0)) : (fmt[0 +1] ? -1 : (0 +1))) : (fmt[0 +1]!='&' ? (fmt[0 +1] ? -1 : (0 +1)) : (fmt[0 +1 +1] ? -1 : (0 +1 +1)))) : (fmt[0 +1]!=':' ? (fmt[0 +1]!='&' ? (fmt[0 +1] ? -1 : (0 +(fmt[0]-'0'))) : (fmt[0 +1 +1] ? -1 : (0 +(fmt[0]-'0')+1))) : (fmt[0 +1 +1]!='&' ? (fmt[0 +1 +1] ? -1 : (0 +(fmt[0]-'0')+1)) : (fmt[0 +1 +1 +1] ? -1 : (0 +(fmt[0]-'0')+1 +1))))) : (!((unsigned char)((fmt[0 +1])-'0')<10) ? (fmt[0 +1]!=':' ? (fmt[0 +1]!='&' ? (fmt[0 +1] ? -1 : (0 +1)) : (fmt[0 +1 +1] ? -1 : (0 +1 +1))) : (fmt[0 +1 +1]!='&' ? (fmt[0 +1 +1] ? -1 : (0 +1 +1)) : (fmt[0 +1 +1 +1] ? -1 : (0 +1 +1 +1)))) : (fmt[0 +1 +1]!=':' ? (fmt[0 +1 +1]!='&' ? (fmt[0 +1 +1] ? -1 : (0 +1 +(fmt[0 +1]-'0'))) : (fmt[0 +1 +1 +1] ? -1 : (0 +1 +(fmt[0 +1]-'0')+1))) : (fmt[0 +1 +1 +1]!='&' ? (fmt[0 +1 +1 +1] ? -1 : (0 +1 +(fmt[0 +1]-'0')+1)) : (fmt[0 +1 +1 +1 +1] ? -1 : (0 +1 +(fmt[0 +1]-'0')+1 +1)))))) : (!((unsigned char)((fmt[0 +1])-'0')<10) ? (fmt[0 +1]!='*' ? (!((unsigned char)((fmt[0 +1])-'0')<10) ? (fmt[0 +1]!=':' ? (fmt[0 +1]!='&' ? (fmt[0 +1] ? -1 : (0 +fmt[0]-'0')) : (fmt[0 +1 +1] ? -1 : (0 +fmt[0]-'0'+1))) : (fmt[0 +1 +1]!='&' ? (fmt[0 +1 +1] ? -1 : (0 +fmt[0]-'0'+1)) : (fmt[0 +1 +1 +1] ? -1 : (0 +fmt[0]-'0'+1 +1)))) : (fmt[0 +1 +1]!=':' ? (fmt[0 +1 +1]!='&' ? (fmt[0 +1 +1] ? -1 : (0 +fmt[0]-'0'+(fmt[0 +1]-'0'))) : (fmt[0 +1 +1 +1] ? -1 : (0 +fmt[0]-'0'+(fmt[0 +1]-'0')+1))) : (fmt[0 +1 +1 +1]!='&' ? (fmt[0 +1 +1 +1] ? -1 : (0 +fmt[0]-'0'+(fmt[0 +1]-'0')+1)) : (fmt[0 +1 +1 +1 +1] ? -1 : (0 +fmt[0]-'0'+(fmt[0 +1]-'0')+1 +1))))) : (!((unsigned char)((fmt[0 +1 +1])-'0')<10) ? (fmt[0 +1 +1]!=':' ? (fmt[0 +1 +1]!='&' ? (fmt[0 +1 +1] ? -1 : (0 +fmt[0]-'0'+1)) : (fmt[0 +1 +1 +1] ? -1 : (0 +fmt[0]-'0'+1 +1))) : (fmt[0 +1 +1 +1]!='&' ? (fmt[0 +1 +1 +1] ? -1 : (0 +fmt[0]-'0'+1 +1)) : (fmt[0 +1 +1 +1 +1] ? -1 : (0 +fmt[0]-'0'+1 +1 +1)))) : (fmt[0 +1 +1 +1]!=':' ? (fmt[0 +1 +1 +1]!='&' ? (fmt[0 +1 +1 +1] ? -1 : (0 +fmt[0]-'0'+1 +(fmt[0 +1 +1]-'0'))) : (fmt[0 +1 +1 +1 +1] ? -1 : (0 +fmt[0]-'0'+1 +(fmt[0 +1 +1]-'0')+1))) : (fmt[0 +1 +1 +1 +1]!='&' ? (fmt[0 +1 +1 +1 +1] ? -1 : (0 +fmt[0]-'0'+1 +(fmt[0 +1 +1]-'0')+1)) : (fmt[0 +1 +1 +1 +1 +1] ? -1 : (0 +fmt[0]-'0'+1 +(fmt[0 +1 +1]-'0')+1 +1)))))) : (fmt[0 +1 +1]!='*' ? (!((unsigned char)((fmt[0 +1 +1])-'0')<10) ? (fmt[0 +1 +1]!=':' ? (fmt[0 +1 +1]!='&' ? (fmt[0 +1 +1] ? -1 : (0 +fmt[0]-'0'+fmt[0 +1]-'0')) : (fmt[0 +1 +1 +1] ? -1 : (0 +fmt[0]-'0'+fmt[0 +1]-'0'+1))) : (fmt[0 +1 +1 +1]!='&' ? (fmt[0 +1 +1 +1] ? -1 : (0 +fmt[0]-'0'+fmt[0 +1]-'0'+1)) : (fmt[0 +1 +1 +1 +1] ? -1 : (0 +fmt[0]-'0'+fmt[0 +1]-'0'+1 +1)))) : (fmt[0 +1 +1 +1]!=':' ? (fmt[0 +1 +1 +1]!='&' ? (fmt[0 +1 +1 +1] ? -1 : (0 +fmt[0]-'0'+fmt[0 +1]-'0'+(fmt[0 +1 +1]-'0'))) : (fmt[0 +1 +1 +1 +1] ? -1 : (0 +fmt[0]-'0'+fmt[0 +1]-'0'+(fmt[0 +1 +1]-'0')+1))) : (fmt[0 +1 +1 +1 +1]!='&' ? (fmt[0 +1 +1 +1 +1] ? -1 : (0 +fmt[0]-'0'+fmt[0 +1]-'0'+(fmt[0 +1 +1]-'0')+1)) : (fmt[0 +1 +1 +1 +1 +1] ? -1 : (0 +fmt[0]-'0'+fmt[0 +1]-'0'+(fmt[0 +1 +1]-'0')+1 +1))))) : (!((unsigned char)((fmt[0 +1 +1 +1])-'0')<10) ? (fmt[0 +1 +1 +1]!=':' ? (fmt[0 +1 +1 +1]!='&' ? (fmt[0 +1 +1 +1] ? -1 : (0 +fmt[0]-'0'+fmt[0 +1]-'0'+1)) : (fmt[0 +1 +1 +1 +1] ? -1 : (0 +fmt[0]-'0'+fmt[0 +1]-'0'+1 +1))) : (fmt[0 +1 +1 +1 +1]!='&' ? (fmt[0 +1 +1 +1 +1] ? -1 : (0 +fmt[0]-'0'+fmt[0 +1]-'0'+1 +1)) : (fmt[0 +1 +1 +1 +1 +1] ? -1 : (0 +fmt[0]-'0'+fmt[0 +1]-'0'+1 +1 +1)))) : (fmt[0 +1 +1 +1 +1]!=':' ? (fmt[0 +1 +1 +1 +1]!='&' ? (fmt[0 +1 +1 +1 +1] ? -1 : (0 +fmt[0]-'0'+fmt[0 +1]-'0'+1 +(fmt[0 +1 +1 +1]-'0'))) : (fmt[0 +1 +1 +1 +1 +1] ? -1 : (0 +fmt[0]-'0'+fmt[0 +1]-'0'+1 +(fmt[0 +1 +1 +1]-'0')+1))) : (fmt[0 +1 +1 +1 +1 +1]!='&' ? (fmt[0 +1 +1 +1 +1 +1] ? -1 : (0 +fmt[0]-'0'+fmt[0 +1]-'0'+1 +(fmt[0 +1 +1 +1]-'0')+1)) : (fmt[0 +1 +1 +1 +1 +1 +1] ? -1 : (0 +fmt[0]-'0'+fmt[0 +1]-'0'+1 +(fmt[0 +1 +1 +1]-'0')+1 +1))))))))!=varc,"variable argument length doesn't match","error")))

{
    int i, argi = 0, vari = 0, last_idx = -1;
    VALUE *var, hash = ((VALUE)RUBY_Qnil), last_hash = 0;
    const int n_mand = n_lead + n_trail;
    int keyword_given = rb_keyword_given_p();
    int empty_keyword_given = 0;
    VALUE tmp_buffer = 0;

    if (!keyword_given) {
        empty_keyword_given = rb_empty_keyword_given_p();
    }



    if (argc > 0 && !(f_hash && empty_keyword_given)) {
        VALUE last = argv[argc - 1];

        if (f_hash && n_mand < argc) {
            if (keyword_given) {
                if (!( ((RUBY_T_HASH) == RUBY_T_FIXNUM) ? (((int)(long)(last))&RUBY_FIXNUM_FLAG) : ((RUBY_T_HASH) == RUBY_T_TRUE) ? ((last) == ((VALUE)RUBY_Qtrue)) : ((RUBY_T_HASH) == RUBY_T_FALSE) ? ((last) == ((VALUE)RUBY_Qfalse)) : ((RUBY_T_HASH) == RUBY_T_NIL) ? ((last) == ((VALUE)RUBY_Qnil)) : ((RUBY_T_HASH) == RUBY_T_UNDEF) ? ((last) == ((VALUE)RUBY_Qundef)) : ((RUBY_T_HASH) == RUBY_T_SYMBOL) ? ((((VALUE)(last)&~((~(VALUE)0)<<RUBY_SPECIAL_SHIFT)) == RUBY_SYMBOL_FLAG)||(!(((VALUE)(last) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(last) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(last))->flags & RUBY_T_MASK) == (RUBY_T_SYMBOL))) : ((RUBY_T_HASH) == RUBY_T_FLOAT) ? ( ((((int)(long)(last))&RUBY_FLONUM_MASK) == RUBY_FLONUM_FLAG) || (!(((VALUE)(last) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(last) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(last))->flags & RUBY_T_MASK) == RUBY_T_FLOAT)) : (!(((VALUE)(last) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(last) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(last))->flags & RUBY_T_MASK) == (RUBY_T_HASH)))) {
                    rb_warn("Keyword flag set when calling rb_scan_args, but last entry is not a hash");
                }
                else {
                    hash = last;
                }
            }
            else if (!((VALUE)(last) != ((VALUE)RUBY_Qnil))) {




                if (!f_var && n_mand + n_opt < argc) {
                    rb_warn("The last argument is nil, treating as empty keywords");
                    argc--;
                }
            }
            else {
                hash = rb_check_hash_type(last);
            }


            if (!!((VALUE)(hash) != ((VALUE)RUBY_Qnil))) {
                VALUE opts = rb_extract_keywords(&hash);

                if (!(last_hash = hash)) {
                    if (!keyword_given) {


                        rb_warn("Using the last argument as keyword parameters is deprecated");
                    }
                    argc--;
                }
                else {


                    rb_warn("The last argument is split into positional and keyword parameters");
                    last_idx = argc - 1;
                }
                hash = opts ? opts : ((VALUE)RUBY_Qnil);
            }
        }
        else if (f_hash && keyword_given && n_mand == argc) {

            rb_warn("Passing the keyword argument as the last hash parameter is deprecated");
        }
    }
    if (f_hash && n_mand > 0 && n_mand == argc+1 && empty_keyword_given) {
        VALUE *ptr = (VALUE *)rb_alloc_tmp_buffer2(&tmp_buffer, argc+1, sizeof(VALUE));
        __builtin___memcpy_chk (ptr, argv, sizeof(VALUE)*argc, __builtin_object_size (ptr, 0));
        ptr[argc] = rb_hash_new();
        argc++;
        *(&argv) = ptr;
        rb_warn("Passing the keyword argument as the last hash parameter is deprecated");
    }


    if (argc < n_mand) {
        goto argc_error;
    }


    for (i = n_lead; i-- > 0; ) {
 var = vars[vari++];
 if (var) *var = (argi == last_idx) ? last_hash : argv[argi];
 argi++;
    }

    for (i = n_opt; i-- > 0; ) {
 var = vars[vari++];
 if (argi < argc - n_trail) {
     if (var) *var = (argi == last_idx) ? last_hash : argv[argi];
     argi++;
 }
 else {
     if (var) *var = ((VALUE)RUBY_Qnil);
 }
    }

    if (f_var) {
 int n_var = argc - argi - n_trail;

 var = vars[vari++];
 if (0 < n_var) {
     if (var) {
  int f_last = (last_idx + 1 == argc - n_trail);
  *var = rb_ary_new_from_values(n_var-f_last, &argv[argi]);
  if (f_last) rb_ary_push(*var, last_hash);
     }
     argi += n_var;
 }
 else {
     if (var) *var = rb_ary_new();
 }
    }

    for (i = n_trail; i-- > 0; ) {
 var = vars[vari++];
 if (var) *var = (argi == last_idx) ? last_hash : argv[argi];
 argi++;
    }

    if (f_hash) {
 var = vars[vari++];
 if (var) *var = hash;
    }

    if (f_block) {
 var = vars[vari++];
 if (rb_block_given_p()) {
     *var = rb_block_proc();
 }
 else {
     *var = ((VALUE)RUBY_Qnil);
 }
    }

    if (argi < argc) {
      argc_error:
        if (tmp_buffer) rb_free_tmp_buffer(&tmp_buffer);
        rb_error_arity(argc, n_mand, f_var ? (-1) : n_mand + n_opt);
    }

    if (tmp_buffer) rb_free_tmp_buffer(&tmp_buffer);
    return argc;
}





void ruby_sysinit(int *argc, char ***argv);
void ruby_init(void);
void* ruby_options(int argc, char** argv);
int ruby_executable_node(void *n, int *status);
int ruby_run_node(void *n);


void ruby_show_version(void);
void ruby_show_copyright(void);








void ruby_init_stack(volatile VALUE*);

int ruby_setup(void);
int ruby_cleanup(volatile int);

void ruby_finalize(void);
__attribute__ ((__noreturn__)) void ruby_stop(int);

void ruby_set_stack_size(size_t);
int ruby_stack_check(void);
size_t ruby_stack_length(VALUE**);

int ruby_exec_node(void *n);

void ruby_script(const char* name);
void ruby_set_script_name(VALUE name);

void ruby_prog_init(void);
void ruby_set_argv(int, char**);
void *ruby_process_options(int, char**);
void ruby_init_loadpath(void);
void ruby_incpush(const char*);
void ruby_sig_finalize(void);







 __attribute__((__unused__,__weakref__("rb_define_method"),__nonnull__ (2,3)))static void rb_define_method0(VALUE klass, const char *name,VALUE(*func)(VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_method"),__nonnull__ (2,3)))static void rb_define_method1(VALUE klass, const char *name,VALUE(*func)(VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_method"),__nonnull__ (2,3)))static void rb_define_method2(VALUE klass, const char *name,VALUE(*func)(VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_method"),__nonnull__ (2,3)))static void rb_define_method3(VALUE klass, const char *name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_method"),__nonnull__ (2,3)))static void rb_define_method4(VALUE klass, const char *name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_method"),__nonnull__ (2,3)))static void rb_define_method5(VALUE klass, const char *name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_method"),__nonnull__ (2,3)))static void rb_define_method6(VALUE klass, const char *name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_method"),__nonnull__ (2,3)))static void rb_define_method7(VALUE klass, const char *name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_method"),__nonnull__ (2,3)))static void rb_define_method8(VALUE klass, const char *name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_method"),__nonnull__ (2,3)))static void rb_define_method9(VALUE klass, const char *name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_method"),__nonnull__ (2,3)))static void rb_define_method10(VALUE klass, const char *name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_method"),__nonnull__ (2,3)))static void rb_define_method11(VALUE klass, const char *name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_method"),__nonnull__ (2,3)))static void rb_define_method12(VALUE klass, const char *name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_method"),__nonnull__ (2,3)))static void rb_define_method13(VALUE klass, const char *name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_method"),__nonnull__ (2,3)))static void rb_define_method14(VALUE klass, const char *name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_method"),__nonnull__ (2,3)))static void rb_define_method15(VALUE klass, const char *name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_method"),__nonnull__ (2,3)))static void rb_define_methodm3(VALUE klass, const char *name,VALUE(*func)(),int arity); __attribute__((__unused__,__weakref__("rb_define_method"),__nonnull__ (2,3)))static void rb_define_methodm2(VALUE klass, const char *name,VALUE(*func)(VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_method"),__nonnull__ (2,3)))static void rb_define_methodm1(VALUE klass, const char *name,VALUE(*func)(int,union{VALUE*x;const VALUE*y;}__attribute__((__transparent_union__)),VALUE),int arity);





 __attribute__((__unused__,__weakref__("rb_define_module_function"),__nonnull__ (2,3)))static void rb_define_module_function0(VALUE klass, const char *name,VALUE(*func)(VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_module_function"),__nonnull__ (2,3)))static void rb_define_module_function1(VALUE klass, const char *name,VALUE(*func)(VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_module_function"),__nonnull__ (2,3)))static void rb_define_module_function2(VALUE klass, const char *name,VALUE(*func)(VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_module_function"),__nonnull__ (2,3)))static void rb_define_module_function3(VALUE klass, const char *name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_module_function"),__nonnull__ (2,3)))static void rb_define_module_function4(VALUE klass, const char *name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_module_function"),__nonnull__ (2,3)))static void rb_define_module_function5(VALUE klass, const char *name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_module_function"),__nonnull__ (2,3)))static void rb_define_module_function6(VALUE klass, const char *name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_module_function"),__nonnull__ (2,3)))static void rb_define_module_function7(VALUE klass, const char *name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_module_function"),__nonnull__ (2,3)))static void rb_define_module_function8(VALUE klass, const char *name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_module_function"),__nonnull__ (2,3)))static void rb_define_module_function9(VALUE klass, const char *name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_module_function"),__nonnull__ (2,3)))static void rb_define_module_function10(VALUE klass, const char *name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_module_function"),__nonnull__ (2,3)))static void rb_define_module_function11(VALUE klass, const char *name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_module_function"),__nonnull__ (2,3)))static void rb_define_module_function12(VALUE klass, const char *name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_module_function"),__nonnull__ (2,3)))static void rb_define_module_function13(VALUE klass, const char *name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_module_function"),__nonnull__ (2,3)))static void rb_define_module_function14(VALUE klass, const char *name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_module_function"),__nonnull__ (2,3)))static void rb_define_module_function15(VALUE klass, const char *name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_module_function"),__nonnull__ (2,3)))static void rb_define_module_functionm3(VALUE klass, const char *name,VALUE(*func)(),int arity); __attribute__((__unused__,__weakref__("rb_define_module_function"),__nonnull__ (2,3)))static void rb_define_module_functionm2(VALUE klass, const char *name,VALUE(*func)(VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_module_function"),__nonnull__ (2,3)))static void rb_define_module_functionm1(VALUE klass, const char *name,VALUE(*func)(int,union{VALUE*x;const VALUE*y;}__attribute__((__transparent_union__)),VALUE),int arity);





 __attribute__((__unused__,__weakref__("rb_define_global_function"),__nonnull__ (1,2)))static void rb_define_global_function0(const char *name,VALUE(*func)(VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_global_function"),__nonnull__ (1,2)))static void rb_define_global_function1(const char *name,VALUE(*func)(VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_global_function"),__nonnull__ (1,2)))static void rb_define_global_function2(const char *name,VALUE(*func)(VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_global_function"),__nonnull__ (1,2)))static void rb_define_global_function3(const char *name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_global_function"),__nonnull__ (1,2)))static void rb_define_global_function4(const char *name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_global_function"),__nonnull__ (1,2)))static void rb_define_global_function5(const char *name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_global_function"),__nonnull__ (1,2)))static void rb_define_global_function6(const char *name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_global_function"),__nonnull__ (1,2)))static void rb_define_global_function7(const char *name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_global_function"),__nonnull__ (1,2)))static void rb_define_global_function8(const char *name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_global_function"),__nonnull__ (1,2)))static void rb_define_global_function9(const char *name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_global_function"),__nonnull__ (1,2)))static void rb_define_global_function10(const char *name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_global_function"),__nonnull__ (1,2)))static void rb_define_global_function11(const char *name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_global_function"),__nonnull__ (1,2)))static void rb_define_global_function12(const char *name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_global_function"),__nonnull__ (1,2)))static void rb_define_global_function13(const char *name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_global_function"),__nonnull__ (1,2)))static void rb_define_global_function14(const char *name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_global_function"),__nonnull__ (1,2)))static void rb_define_global_function15(const char *name,VALUE(*func)(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_global_function"),__nonnull__ (1,2)))static void rb_define_global_functionm3(const char *name,VALUE(*func)(),int arity); __attribute__((__unused__,__weakref__("rb_define_global_function"),__nonnull__ (1,2)))static void rb_define_global_functionm2(const char *name,VALUE(*func)(VALUE,VALUE),int arity); __attribute__((__unused__,__weakref__("rb_define_global_function"),__nonnull__ (1,2)))static void rb_define_global_functionm1(const char *name,VALUE(*func)(int,union{VALUE*x;const VALUE*y;}__attribute__((__transparent_union__)),VALUE),int arity);




















































static inline unsigned int
nlz_int(unsigned int x)
{

    if (x == 0) return 4 * 8;
    return (unsigned int)__builtin_clz(x);
}

static inline unsigned int
nlz_long(unsigned long x)
{

    if (x == 0) return 8 * 8;
    return (unsigned int)__builtin_clzl(x);
}


static inline unsigned int
nlz_long_long(unsigned long long x)
{

    if (x == 0) return 8 * 8;
    return (unsigned int)__builtin_clzll(x);
}



static inline unsigned int
nlz_int128(unsigned __int128 x)
{
    unsigned __int128 y;
    unsigned int n = 128;
    y = x >> 64; if (y) {n -= 64; x = y;}
    y = x >> 32; if (y) {n -= 32; x = y;}
    y = x >> 16; if (y) {n -= 16; x = y;}
    y = x >> 8; if (y) {n -= 8; x = y;}
    y = x >> 4; if (y) {n -= 4; x = y;}
    y = x >> 2; if (y) {n -= 2; x = y;}
    y = x >> 1; if (y) {return n - 2;}
    return (unsigned int)(n - x);
}


static inline unsigned int
nlz_intptr(uintptr_t x)
{



    return nlz_long(x);






}

static inline unsigned int
rb_popcount32(uint32_t x)
{

    return (unsigned int)__builtin_popcount(x);







}

static inline int
rb_popcount64(uint64_t x)
{

    return __builtin_popcountll(x);
}

static inline int
rb_popcount_intptr(uintptr_t x)
{

    return rb_popcount64(x);



}

static inline int
ntz_int32(uint32_t x)
{

    return __builtin_ctz(x);



}

static inline int
ntz_int64(uint64_t x)
{

    return __builtin_ctzll(x);



}

static inline int
ntz_intptr(uintptr_t x)
{

    return ntz_int64(x);



}





VALUE rb_int128t2big(__int128 n);


static inline long
rb_overflowed_fix_to_int(long x)
{
    return (long)((unsigned long)(x >> 1) ^ (1LU << (8 * 8 - 1)));
}

static inline VALUE
rb_fix_plus_fix(VALUE x, VALUE y)
{

    long lz;
    if (__builtin_add_overflow((long)x, (long)y-1, &lz)) {
 return rb_int2big(rb_overflowed_fix_to_int(lz));
    }
    else {
 return (VALUE)lz;
    }




}

static inline VALUE
rb_fix_minus_fix(VALUE x, VALUE y)
{

    long lz;
    if (__builtin_sub_overflow((long)x, (long)y-1, &lz)) {
 return rb_int2big(rb_overflowed_fix_to_int(lz));
    }
    else {
 return (VALUE)lz;
    }




}


static inline VALUE
rb_fix_mul_fix(VALUE x, VALUE y)
{
    long lx = ((long)(((long)(x))>>(int)(1)));
    long ly = ((long)(((long)(y))>>(int)(1)));

    return (((((__int128)lx * (__int128)ly) < (9223372036854775807L>>1)+1) && (((__int128)lx * (__int128)ly) >= (((long)(-9223372036854775807L -1L))>>(int)(1)))) ? (((VALUE)((__int128)lx * (__int128)ly))<<1 | RUBY_FIXNUM_FLAG) : rb_int128t2big((__int128)lx * (__int128)ly));
}





static inline void
rb_fix_divmod_fix(VALUE a, VALUE b, VALUE *divp, VALUE *modp)
{




    long x = ((long)(((long)(a))>>(int)(1)));
    long y = ((long)(((long)(b))>>(int)(1)));
    long div, mod;
    if (x == (((long)(-9223372036854775807L -1L))>>(int)(1)) && y == -1) {
 if (divp) *divp = rb_long2num_inline(-(((long)(-9223372036854775807L -1L))>>(int)(1)));
 if (modp) *modp = (((VALUE)(0))<<1 | RUBY_FIXNUM_FLAG);
 return;
    }
    div = x / y;
    mod = x % y;
    if (y > 0 ? mod < 0 : mod > 0) {
 mod += y;
 div -= 1;
    }
    if (divp) *divp = (((VALUE)(div))<<1 | RUBY_FIXNUM_FLAG);
    if (modp) *modp = (((VALUE)(mod))<<1 | RUBY_FIXNUM_FLAG);
}




static inline VALUE
rb_fix_div_fix(VALUE x, VALUE y)
{
    VALUE div;
    rb_fix_divmod_fix(x, y, &div, ((void*)0));
    return div;
}




static inline VALUE
rb_fix_mod_fix(VALUE x, VALUE y)
{
    VALUE mod;
    rb_fix_divmod_fix(x, y, ((void*)0), &mod);
    return mod;
}

















struct RBignum {
    struct RBasic basic;
    union {
        struct {
            size_t len;
            unsigned int *digits;
        } heap;
        unsigned int ary[(8*RVALUE_EMBED_LEN_MAX/4)];
    } as;
};
















struct RRational {
    struct RBasic basic;
    VALUE num;
    VALUE den;
};


struct RFloat {
    struct RBasic basic;
    double float_value;
};


struct RComplex {
    struct RBasic basic;
    VALUE real;
    VALUE imag;
};




enum ruby_rhash_flags {
    RHASH_PASS_AS_KEYWORDS = ((VALUE)RUBY_FL_USER1),
    RHASH_PROC_DEFAULT = ((VALUE)RUBY_FL_USER2),
    RHASH_ST_TABLE_FLAG = ((VALUE)RUBY_FL_USER3),
 RHASH_AR_TABLE_SIZE_MASK = (((VALUE)RUBY_FL_USER4)|((VALUE)RUBY_FL_USER5)|((VALUE)RUBY_FL_USER6)|((VALUE)RUBY_FL_USER7)),
    RHASH_AR_TABLE_SIZE_SHIFT = (((VALUE)RUBY_FL_USHIFT)+4),
    RHASH_AR_TABLE_BOUND_MASK = (((VALUE)RUBY_FL_USER8)|((VALUE)RUBY_FL_USER9)|((VALUE)RUBY_FL_USER10)|((VALUE)RUBY_FL_USER11)),
    RHASH_AR_TABLE_BOUND_SHIFT = (((VALUE)RUBY_FL_USHIFT)+8),





 RHASH_TRANSIENT_FLAG = ((VALUE)RUBY_FL_USER12),


    RHASH_LEV_SHIFT = (((VALUE)RUBY_FL_USHIFT) + 13),
    RHASH_LEV_MAX = 127,

    RHASH_ENUM_END
};



void rb_hash_st_table_set(VALUE hash, st_table *st);





typedef unsigned char ar_hint_t;




struct RHash {
    struct RBasic basic;
    union {
        st_table *st;
        struct ar_table_struct *ar;
    } as;
    const VALUE ifnone;
    union {
        ar_hint_t ary[8];
        VALUE word;
    } ar_hint;
};





struct RMoved {
    VALUE flags;
    VALUE destination;
    VALUE next;
};



extern void ruby_init_setproctitle(int argc, char *argv[]);



enum {
    RSTRUCT_EMBED_LEN_MAX = RVALUE_EMBED_LEN_MAX,
    RSTRUCT_EMBED_LEN_MASK = (RUBY_FL_USER2|RUBY_FL_USER1),
    RSTRUCT_EMBED_LEN_SHIFT = (RUBY_FL_USHIFT+1),
    RSTRUCT_TRANSIENT_FLAG = ((VALUE)RUBY_FL_USER3),

    RSTRUCT_ENUM_END
};








struct RStruct {
    struct RBasic basic;
    union {
 struct {
     long len;
     const VALUE *ptr;
 } heap;
 const VALUE ary[RSTRUCT_EMBED_LEN_MAX];
    } as;
};




static inline long
rb_struct_len(VALUE st)
{
    return (((struct RBasic*)(st))->flags & RSTRUCT_EMBED_LEN_MASK) ?
 (long)((((struct RBasic*)(st))->flags >> RSTRUCT_EMBED_LEN_SHIFT) & (RSTRUCT_EMBED_LEN_MASK >> RSTRUCT_EMBED_LEN_SHIFT)) : ((struct RStruct*)(st))->as.heap.len;
}

static inline const VALUE *
rb_struct_const_ptr(VALUE st)
{
    return ((((struct RBasic*)(st))->flags & RSTRUCT_EMBED_LEN_MASK) ? ((struct RStruct*)(st))->as.ary : ((struct RStruct*)(st))->as.heap.ptr);

}

static inline const VALUE *
rb_struct_const_heap_ptr(VALUE st)
{

    return ((struct RStruct*)(st))->as.heap.ptr;
}



struct rb_deprecated_classext_struct {
    char conflict[sizeof(VALUE) * 3];
};

struct rb_subclass_entry;
typedef struct rb_subclass_entry rb_subclass_entry_t;

struct rb_subclass_entry {
    VALUE klass;
    rb_subclass_entry_t *next;
};


typedef unsigned long long rb_serial_t;
struct rb_classext_struct {
    struct st_table *iv_index_tbl;
    struct st_table *iv_tbl;

    struct rb_id_table *m_tbl;

    struct rb_id_table *const_tbl;
    struct rb_id_table *callable_m_tbl;
    rb_subclass_entry_t *subclasses;
    rb_subclass_entry_t **parent_subclasses;





    rb_subclass_entry_t **module_subclasses;



    const VALUE origin_;
    const VALUE refined_class;
    rb_alloc_func_t allocator;
    const VALUE includer;
};

typedef struct rb_classext_struct rb_classext_t;

struct RClass {
    struct RBasic basic;
    VALUE super;
    rb_classext_t *ptr;


    rb_serial_t class_serial;




};

void rb_class_subclass_add(VALUE super, VALUE klass);
void rb_class_remove_from_super_subclasses(VALUE);
int rb_singleton_class_internal_p(VALUE sklass);











static inline void
RCLASS_SET_ORIGIN(VALUE klass, VALUE origin)
{
    rb_obj_write((VALUE)(klass), (VALUE *)(&((((struct RClass*)(klass))->ptr)->origin_)), (VALUE)(origin), "./internal.h", 1091);
    if (klass != origin) ((!(((VALUE)(origin) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(origin) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(origin))->flags & RUBY_T_MASK) != RUBY_T_NODE) ? (void)(((struct RBasic*)(origin))->flags |= (((VALUE)RUBY_FL_USER5))) : (void)0);
}

static inline void
RCLASS_SET_INCLUDER(VALUE iclass, VALUE klass)
{
    rb_obj_write((VALUE)(iclass), (VALUE *)(&((((struct RClass*)(iclass))->ptr)->includer)), (VALUE)(klass), "./internal.h", 1098);
}

static inline VALUE
RCLASS_SUPER(VALUE klass)
{
    return ((struct RClass*)(klass))->super;
}

static inline VALUE
RCLASS_SET_SUPER(VALUE klass, VALUE super)
{
    if (super) {
 rb_class_remove_from_super_subclasses(klass);
 rb_class_subclass_add(super, klass);
    }
    rb_obj_write((VALUE)(klass), (VALUE *)(&((struct RClass*)(klass))->super), (VALUE)(super), "./internal.h", 1115);
    return super;
}





struct RIMemo {
    VALUE flags;
    VALUE v0;
    VALUE v1;
    VALUE v2;
    VALUE v3;
};

enum imemo_type {
    imemo_env = 0,
    imemo_cref = 1,
    imemo_svar = 2,
    imemo_throw_data = 3,
    imemo_ifunc = 4,
    imemo_memo = 5,
    imemo_ment = 6,
    imemo_iseq = 7,
    imemo_tmpbuf = 8,
    imemo_ast = 9,
    imemo_parser_strterm = 10
};

static inline enum imemo_type
imemo_type(VALUE imemo)
{
    return (((struct RBasic*)(imemo))->flags >> ((VALUE)RUBY_FL_USHIFT)) & 0x0f;
}

static inline int
imemo_type_p(VALUE imemo, enum imemo_type imemo_type)
{
    if ((__builtin_expect(!!(!(((VALUE)(imemo) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(imemo) & (VALUE)~((VALUE)RUBY_Qnil)) == 0))), 1))) {

 const VALUE mask = (0x0f << ((VALUE)RUBY_FL_USHIFT)) | RUBY_T_MASK;
 const VALUE expected_type = (imemo_type << ((VALUE)RUBY_FL_USHIFT)) | RUBY_T_IMEMO;

 return expected_type == (((struct RBasic*)(imemo))->flags & mask);
    }
    else {
 return 0;
    }
}

VALUE rb_imemo_new(enum imemo_type type, VALUE v1, VALUE v2, VALUE v3, VALUE v0);






struct vm_svar {
    VALUE flags;
    const VALUE cref_or_me;
    const VALUE lastline;
    const VALUE backref;
    const VALUE others;
};




struct vm_throw_data {
    VALUE flags;
    VALUE reserved;
    const VALUE throw_obj;
    const struct rb_control_frame_struct *catch_frame;
    int throw_state;
};




struct vm_ifunc_argc {




    int min, max;

};


struct vm_ifunc {
    VALUE flags;
    VALUE reserved;
    rb_block_call_func_t func;
    const void *data;
    struct vm_ifunc_argc argc;
};

struct vm_ifunc *rb_vm_ifunc_new(rb_block_call_func_t func, const void *data, int min_argc, int max_argc);
static inline struct vm_ifunc *
rb_vm_ifunc_proc_new(rb_block_call_func_t func, const void *data)
{
    return rb_vm_ifunc_new(func, data, 0, (-1));
}

typedef struct rb_imemo_tmpbuf_struct {
    VALUE flags;
    VALUE reserved;
    VALUE *ptr;
    struct rb_imemo_tmpbuf_struct *next;
    size_t cnt;
} rb_imemo_tmpbuf_t;

rb_imemo_tmpbuf_t *rb_imemo_tmpbuf_parser_heap(void *buf, rb_imemo_tmpbuf_t *old_heap, size_t cnt);



static inline void *
rb_imemo_tmpbuf_set_ptr(VALUE v, void *ptr)
{
    return ((rb_imemo_tmpbuf_t *)v)->ptr = ptr;
}

static inline VALUE
rb_imemo_tmpbuf_auto_free_pointer_new_from_an_RString(VALUE str)
{
    const void *src;
    VALUE imemo;
    rb_imemo_tmpbuf_t *tmpbuf;
    void *dst;
    size_t len;

    rb_string_value(&(str));

    imemo = rb_imemo_new(imemo_tmpbuf, 0, 0, 0, 0);
    tmpbuf = (rb_imemo_tmpbuf_t *)imemo;
    len = (!(((struct RBasic*)(str))->flags & RSTRING_NOEMBED) ? (long)((((struct RBasic*)(str))->flags >> RSTRING_EMBED_LEN_SHIFT) & (RSTRING_EMBED_LEN_MASK >> RSTRING_EMBED_LEN_SHIFT)) : ((struct RString*)(str))->as.heap.len);
    src = (!(((struct RBasic*)(str))->flags & RSTRING_NOEMBED) ? ((struct RString*)(str))->as.ary : ((struct RString*)(str))->as.heap.ptr);
    dst = ruby_xmalloc(len);
    __builtin___memcpy_chk (dst, src, len, __builtin_object_size (dst, 0));
    tmpbuf->ptr = dst;
    return imemo;
}

void rb_strterm_mark(VALUE obj);





struct MEMO {
    VALUE flags;
    VALUE reserved;
    const VALUE v1;
    const VALUE v2;
    union {
 long cnt;
 long state;
        const VALUE value;
        void (*func)(void);
    } u3;
};













enum {
    cmp_opt_Fixnum,
    cmp_opt_String,
    cmp_opt_Float,
    cmp_optimizable_count
};

struct cmp_opt_data {
    unsigned int opt_methods;
    unsigned int opt_inited;
};








struct rb_global_entry {
    struct rb_global_variable *var;
    ID id;
};

struct rb_global_entry *rb_global_entry(ID);
VALUE rb_gvar_get(struct rb_global_entry *);
VALUE rb_gvar_set(struct rb_global_entry *, VALUE);
VALUE rb_gvar_defined(struct rb_global_entry *);















VALUE rb_ary_last(int, const VALUE *, VALUE);
void rb_ary_set_len(VALUE, long);
void rb_ary_delete_same(VALUE, VALUE);
VALUE rb_ary_tmp_new_fill(long capa);
VALUE rb_ary_at(VALUE, VALUE);
VALUE rb_ary_aref1(VALUE ary, VALUE i);
size_t rb_ary_memsize(VALUE);
VALUE rb_to_array_type(VALUE obj);
VALUE rb_check_to_array(VALUE ary);
VALUE rb_ary_tmp_new_from_values(VALUE, long, const VALUE *);
VALUE rb_ary_behead(VALUE, long);

static inline VALUE
rb_ary_entry_internal(VALUE ary, long offset)
{
    long len = rb_array_len(ary);
    const VALUE *ptr = rb_array_const_ptr_transient(ary);
    if (len == 0) return ((VALUE)RUBY_Qnil);
    if (offset < 0) {
        offset += len;
        if (offset < 0) return ((VALUE)RUBY_Qnil);
    }
    else if (len <= offset) {
        return ((VALUE)RUBY_Qnil);
    }
    return ptr[offset];
}


void rb_obj_info_dump(VALUE obj);
void rb_obj_info_dump_loc(VALUE obj, const char *file, int line, const char *func);
void ruby_debug_breakpoint(void);












extern const char ruby_digitmap[];
double rb_big_fdiv_double(VALUE x, VALUE y);
VALUE rb_big_uminus(VALUE x);
VALUE rb_big_hash(VALUE);
VALUE rb_big_odd_p(VALUE);
VALUE rb_big_even_p(VALUE);
size_t rb_big_size(VALUE);
VALUE rb_integer_float_cmp(VALUE x, VALUE y);
VALUE rb_integer_float_eq(VALUE x, VALUE y);
VALUE rb_str_convert_to_inum(VALUE str, int base, int badcheck, int raise_exception);
VALUE rb_big_comp(VALUE x);
VALUE rb_big_aref(VALUE x, VALUE y);
VALUE rb_big_abs(VALUE x);
VALUE rb_big_size_m(VALUE big);
VALUE rb_big_bit_length(VALUE big);
VALUE rb_big_remainder(VALUE x, VALUE y);
VALUE rb_big_gt(VALUE x, VALUE y);
VALUE rb_big_ge(VALUE x, VALUE y);
VALUE rb_big_lt(VALUE x, VALUE y);
VALUE rb_big_le(VALUE x, VALUE y);
VALUE rb_int_powm(int const argc, VALUE * const argv, VALUE const num);


VALUE rb_class_boot(VALUE);
VALUE rb_class_inherited(VALUE, VALUE);
VALUE rb_make_metaclass(VALUE, VALUE);
VALUE rb_include_class_new(VALUE, VALUE);
void rb_class_foreach_subclass(VALUE klass, void (*f)(VALUE, VALUE), VALUE);
void rb_class_detach_subclasses(VALUE);
void rb_class_detach_module_subclasses(VALUE);
void rb_class_remove_from_module_subclasses(VALUE);
VALUE rb_obj_methods(int argc, const VALUE *argv, VALUE obj);
VALUE rb_obj_protected_methods(int argc, const VALUE *argv, VALUE obj);
VALUE rb_obj_private_methods(int argc, const VALUE *argv, VALUE obj);
VALUE rb_obj_public_methods(int argc, const VALUE *argv, VALUE obj);
VALUE rb_special_singleton_class(VALUE);
VALUE rb_singleton_class_clone_and_attach(VALUE obj, VALUE attach);
VALUE rb_singleton_class_get(VALUE obj);
void Init_class_hierarchy(void);

int rb_class_has_methods(VALUE c);
void rb_undef_methods_from(VALUE klass, VALUE super);


VALUE rb_invcmp(VALUE, VALUE);


struct rb_block;
struct rb_iseq_struct;
int rb_dvar_defined(ID, const struct rb_iseq_struct *);
int rb_local_defined(ID, const struct rb_iseq_struct *);
const char * rb_insns_name(int i);
VALUE rb_insns_name_array(void);
int rb_vm_insn_addr2insn(const void *);


VALUE rb_dbl_complex_new_polar_pi(double abs, double ang);

struct rb_thread_struct;

struct rb_fiber_struct;
VALUE rb_obj_is_fiber(VALUE);
void rb_fiber_reset_root_local_storage(struct rb_thread_struct *);
void ruby_register_rollback_func_for_ensure(VALUE (*ensure_func)(VALUE), VALUE (*rollback_func)(VALUE));
void rb_fiber_init_mjit_cont(struct rb_fiber_struct *fiber);


void ruby_debug_printf(const char*, ...) __attribute__((format(printf, 1, 2)));


VALUE rb_dir_getwd_ospath(void);


void Init_enc(void);
void Init_ext(void);


ID rb_id_encoding(void);




int rb_encdb_replicate(const char *alias, const char *orig);
int rb_encdb_alias(const char *alias, const char *orig);
int rb_encdb_dummy(const char *name);
void rb_encdb_declare(const char *name);
void rb_enc_set_base(const char *name, const char *orig);
int rb_enc_set_dummy(int index);
void rb_encdb_set_unicode(int index);
__attribute__ ((__pure__)) int rb_data_is_encoding(VALUE obj);


extern VALUE rb_cArithSeq;
VALUE rb_f_send(int argc, VALUE *argv, VALUE recv);
VALUE rb_nmin_run(VALUE obj, VALUE num, int by, int rev, int ary);


extern VALUE rb_eEAGAIN;
extern VALUE rb_eEWOULDBLOCK;
extern VALUE rb_eEINPROGRESS;
void rb_report_bug_valist(VALUE file, int line, const char *fmt, va_list args);
__attribute__ ((__noreturn__)) void rb_async_bug_errno(const char *,int);
const char *rb_builtin_type_name(int t);
const char *rb_builtin_class_name(VALUE x);
void rb_warn_deprecated(const char *fmt, const char *suggest, ...) __attribute__((format(printf, 1, 3)));







typedef enum {
    RB_WARN_CATEGORY_NONE,
    RB_WARN_CATEGORY_DEPRECATED,
    RB_WARN_CATEGORY_EXPERIMENTAL,
    RB_WARN_CATEGORY_ALL_BITS = 0x6,
} rb_warning_category_t;
rb_warning_category_t rb_warning_category_from_name(VALUE category);
_Bool rb_warning_category_enabled_p(rb_warning_category_t category);




VALUE rb_name_err_new(VALUE mesg, VALUE recv, VALUE method);


VALUE rb_nomethod_err_new(VALUE mesg, VALUE recv, VALUE method, VALUE args, int priv);
VALUE rb_key_err_new(VALUE mesg, VALUE recv, VALUE name);

VALUE rb_warning_string(const char *fmt, ...) __attribute__((format(printf, 1, 2)));
__attribute__ ((__noreturn__)) void rb_vraise(VALUE, const char *, va_list);


VALUE rb_refinement_module_get_refined_class(VALUE module);
extern ID ruby_static_id_signo, ruby_static_id_status;
void rb_class_modify_check(VALUE);
__attribute__ ((__noreturn__)) VALUE rb_f_raise(int argc, VALUE *argv);


VALUE rb_get_backtrace(VALUE info);


void rb_call_end_proc(VALUE data);
void rb_mark_end_proc(void);


extern const char ruby_null_device[];
VALUE rb_home_dir_of(VALUE user, VALUE result);
VALUE rb_default_home_dir(VALUE result);
VALUE rb_realpath_internal(VALUE basedir, VALUE path, int strict);



void rb_file_const(const char*, VALUE);
int rb_file_load_ok(const char *);
VALUE rb_file_expand_path_fast(VALUE, VALUE);
VALUE rb_file_expand_path_internal(VALUE, VALUE, int, int, VALUE);
VALUE rb_get_path_check_to_string(VALUE);
VALUE rb_get_path_check_convert(VALUE);
void Init_File(void);
int ruby_is_fd_loadable(int fd);




__attribute__ ((__noreturn__)) void rb_sys_fail_path_in(const char *func_name, VALUE path);
__attribute__ ((__noreturn__)) void rb_syserr_fail_path_in(const char *func_name, int err, VALUE path);








extern VALUE *ruby_initial_gc_stress_ptr;
extern int ruby_disable_gc;
struct rb_objspace;
void Init_heap(void);
void *ruby_mimmalloc(size_t size) __attribute__((__malloc__));
void ruby_mimfree(void *ptr);
void rb_objspace_set_event_hook(const rb_event_flag_t event);
VALUE rb_objspace_gc_enable(struct rb_objspace *);
VALUE rb_objspace_gc_disable(struct rb_objspace *);

void rb_gc_writebarrier_remember(VALUE obj);



void ruby_gc_set_params(void);
void rb_copy_wb_protected_attribute(VALUE dest, VALUE obj);








__attribute__((__alloc_align__(1)))


void *rb_aligned_malloc(size_t, size_t) __attribute__((__malloc__)) __attribute__((__alloc_size__ (2)));

size_t rb_size_mul_or_raise(size_t, size_t, VALUE);
size_t rb_size_mul_add_or_raise(size_t, size_t, size_t, VALUE);
void *rb_xmalloc_mul_add(size_t, size_t, size_t) __attribute__((__malloc__));
void *rb_xrealloc_mul_add(const void *, size_t, size_t, size_t);
void *rb_xmalloc_mul_add_mul(size_t, size_t, size_t, size_t) __attribute__((__malloc__));
void *rb_xcalloc_mul_add_mul(size_t, size_t, size_t, size_t) __attribute__((__malloc__));






struct st_table *rb_hash_tbl_raw(VALUE hash);


VALUE rb_hash_new_with_size(st_index_t size);
VALUE rb_hash_has_key(VALUE hash, VALUE key);
VALUE rb_hash_default_value(VALUE hash, VALUE key);
VALUE rb_hash_set_default_proc(VALUE hash, VALUE proc);
long rb_dbl_long_hash(double d);
st_table *rb_init_identtable(void);
VALUE rb_hash_compare_by_id_p(VALUE hash);
VALUE rb_to_hash_type(VALUE obj);
VALUE rb_hash_key_str(VALUE);
VALUE rb_hash_keys(VALUE hash);
VALUE rb_hash_values(VALUE hash);
VALUE rb_hash_rehash(VALUE hash);
VALUE rb_hash_resurrect(VALUE hash);
int rb_hash_add_new_element(VALUE hash, VALUE key, VALUE val);
VALUE rb_hash_set_pair(VALUE hash, VALUE pair);

int rb_hash_stlike_lookup(VALUE hash, st_data_t key, st_data_t *pval);
int rb_hash_stlike_delete(VALUE hash, st_data_t *pkey, st_data_t *pval);
int rb_hash_stlike_foreach(VALUE hash, st_foreach_callback_func *func, st_data_t arg);
int rb_hash_stlike_foreach_with_replace(VALUE hash, st_foreach_check_callback_func *func, st_update_callback_func *replace, st_data_t arg);
int rb_hash_stlike_update(VALUE hash, st_data_t key, st_update_callback_func func, st_data_t arg);


void rb_call_inits(void);


void ruby_set_inplace_mode(const char *);
void rb_stdio_set_default_encoding(void);
VALUE rb_io_flush_raw(VALUE, int);



int rb_stderr_tty_p(void);
void rb_io_fptr_finalize_internal(void *ptr);


VALUE rb_get_expanded_load_path(void);
int rb_require_internal(VALUE fname);
__attribute__ ((__noreturn__)) void rb_load_fail(VALUE, const char*);


extern const char ruby_exec_prefix[];
extern const char ruby_initial_load_paths[];


int Init_enc_set_filesystem_encoding(void);


VALUE rb_math_atan2(VALUE, VALUE);
VALUE rb_math_cos(VALUE);
VALUE rb_math_cosh(VALUE);
VALUE rb_math_exp(VALUE);
VALUE rb_math_hypot(VALUE, VALUE);
VALUE rb_math_log(int argc, const VALUE *argv);
VALUE rb_math_sin(VALUE);
VALUE rb_math_sinh(VALUE);




extern _Bool mjit_enabled;
VALUE mjit_pause(_Bool wait_p);
VALUE mjit_resume(void);
void mjit_finish(_Bool close_handle_p);
void Init_newline(void);








enum ruby_num_rounding_mode {
    RUBY_NUM_ROUND_HALF_UP,
    RUBY_NUM_ROUND_HALF_EVEN,
    RUBY_NUM_ROUND_HALF_DOWN,
    RUBY_NUM_ROUND_DEFAULT = RUBY_NUM_ROUND_HALF_UP
};






int rb_num_to_uint(VALUE val, unsigned int *ret);
VALUE ruby_num_interval_step_size(VALUE from, VALUE to, VALUE step, int excl);
double ruby_float_step_size(double beg, double end, double unit, int excl);
int ruby_float_step(VALUE from, VALUE to, VALUE step, int excl, int allow_endless);
double ruby_float_mod(double x, double y);
int rb_num_negative_p(VALUE);
VALUE rb_int_succ(VALUE num);
VALUE rb_int_uminus(VALUE num);
VALUE rb_float_uminus(VALUE num);
VALUE rb_int_plus(VALUE x, VALUE y);
VALUE rb_float_plus(VALUE x, VALUE y);
VALUE rb_int_minus(VALUE x, VALUE y);
VALUE rb_int_mul(VALUE x, VALUE y);
VALUE rb_float_mul(VALUE x, VALUE y);
VALUE rb_float_div(VALUE x, VALUE y);
VALUE rb_int_idiv(VALUE x, VALUE y);
VALUE rb_int_modulo(VALUE x, VALUE y);
VALUE rb_int2str(VALUE num, int base);
VALUE rb_fix_plus(VALUE x, VALUE y);
VALUE rb_fix_aref(VALUE fix, VALUE idx);
VALUE rb_int_gt(VALUE x, VALUE y);
int rb_float_cmp(VALUE x, VALUE y);
VALUE rb_float_gt(VALUE x, VALUE y);
VALUE rb_int_ge(VALUE x, VALUE y);
enum ruby_num_rounding_mode rb_num_get_rounding_option(VALUE opts);
double rb_int_fdiv_double(VALUE x, VALUE y);
VALUE rb_int_pow(VALUE x, VALUE y);
VALUE rb_float_pow(VALUE x, VALUE y);
VALUE rb_int_cmp(VALUE x, VALUE y);
VALUE rb_int_equal(VALUE x, VALUE y);
VALUE rb_int_divmod(VALUE x, VALUE y);
VALUE rb_int_and(VALUE x, VALUE y);
VALUE rb_int_lshift(VALUE x, VALUE y);
VALUE rb_int_div(VALUE x, VALUE y);
VALUE rb_int_abs(VALUE num);
VALUE rb_int_odd_p(VALUE num);
int rb_int_positive_p(VALUE num);
int rb_int_negative_p(VALUE num);
VALUE rb_num_pow(VALUE x, VALUE y);
VALUE rb_float_ceil(VALUE num, int ndigits);

static inline VALUE
rb_num_compare_with_zero(VALUE num, ID mid)
{
    VALUE zero = (((VALUE)(0))<<1 | RUBY_FIXNUM_FLAG);
    VALUE r = rb_check_funcall(num, mid, 1, &zero);
    if (r == ((VALUE)RUBY_Qundef)) {
 rb_cmperr(num, zero);
    }
    return r;
}

static inline int
rb_num_positive_int_p(VALUE num)
{
    const ID mid = '>';

    if ((((int)(long)(num))&RUBY_FIXNUM_FLAG)) {
 if (rb_method_basic_definition_p(rb_cInteger, mid))
     return ((long)(num) > (long)(((VALUE)(0))<<1 | RUBY_FIXNUM_FLAG));
    }
    else if (( ((RUBY_T_BIGNUM) == RUBY_T_FIXNUM) ? (((int)(long)(num))&RUBY_FIXNUM_FLAG) : ((RUBY_T_BIGNUM) == RUBY_T_TRUE) ? ((num) == ((VALUE)RUBY_Qtrue)) : ((RUBY_T_BIGNUM) == RUBY_T_FALSE) ? ((num) == ((VALUE)RUBY_Qfalse)) : ((RUBY_T_BIGNUM) == RUBY_T_NIL) ? ((num) == ((VALUE)RUBY_Qnil)) : ((RUBY_T_BIGNUM) == RUBY_T_UNDEF) ? ((num) == ((VALUE)RUBY_Qundef)) : ((RUBY_T_BIGNUM) == RUBY_T_SYMBOL) ? ((((VALUE)(num)&~((~(VALUE)0)<<RUBY_SPECIAL_SHIFT)) == RUBY_SYMBOL_FLAG)||(!(((VALUE)(num) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(num) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(num))->flags & RUBY_T_MASK) == (RUBY_T_SYMBOL))) : ((RUBY_T_BIGNUM) == RUBY_T_FLOAT) ? ( ((((int)(long)(num))&RUBY_FLONUM_MASK) == RUBY_FLONUM_FLAG) || (!(((VALUE)(num) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(num) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(num))->flags & RUBY_T_MASK) == RUBY_T_FLOAT)) : (!(((VALUE)(num) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(num) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(num))->flags & RUBY_T_MASK) == (RUBY_T_BIGNUM)))) {
 if (rb_method_basic_definition_p(rb_cInteger, mid))
     return ((((struct RBasic*)(num))->flags & ((VALUE)((VALUE)RUBY_FL_USER1))) != 0);
    }
    return !(((VALUE)(rb_num_compare_with_zero(num, mid)) & (VALUE)~((VALUE)RUBY_Qnil)) == 0);
}


static inline int
rb_num_negative_int_p(VALUE num)
{
    const ID mid = '<';

    if ((((int)(long)(num))&RUBY_FIXNUM_FLAG)) {
 if (rb_method_basic_definition_p(rb_cInteger, mid))
     return ((long)(num) < 0);
    }
    else if (( ((RUBY_T_BIGNUM) == RUBY_T_FIXNUM) ? (((int)(long)(num))&RUBY_FIXNUM_FLAG) : ((RUBY_T_BIGNUM) == RUBY_T_TRUE) ? ((num) == ((VALUE)RUBY_Qtrue)) : ((RUBY_T_BIGNUM) == RUBY_T_FALSE) ? ((num) == ((VALUE)RUBY_Qfalse)) : ((RUBY_T_BIGNUM) == RUBY_T_NIL) ? ((num) == ((VALUE)RUBY_Qnil)) : ((RUBY_T_BIGNUM) == RUBY_T_UNDEF) ? ((num) == ((VALUE)RUBY_Qundef)) : ((RUBY_T_BIGNUM) == RUBY_T_SYMBOL) ? ((((VALUE)(num)&~((~(VALUE)0)<<RUBY_SPECIAL_SHIFT)) == RUBY_SYMBOL_FLAG)||(!(((VALUE)(num) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(num) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(num))->flags & RUBY_T_MASK) == (RUBY_T_SYMBOL))) : ((RUBY_T_BIGNUM) == RUBY_T_FLOAT) ? ( ((((int)(long)(num))&RUBY_FLONUM_MASK) == RUBY_FLONUM_FLAG) || (!(((VALUE)(num) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(num) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(num))->flags & RUBY_T_MASK) == RUBY_T_FLOAT)) : (!(((VALUE)(num) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(num) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(num))->flags & RUBY_T_MASK) == (RUBY_T_BIGNUM)))) {
 if (rb_method_basic_definition_p(rb_cInteger, mid))
     return (!((((struct RBasic*)(num))->flags & ((VALUE)((VALUE)RUBY_FL_USER1))) != 0));
    }
    return !(((VALUE)(rb_num_compare_with_zero(num, mid)) & (VALUE)~((VALUE)RUBY_Qnil)) == 0);
}


VALUE rb_float_abs(VALUE flt);
VALUE rb_float_equal(VALUE x, VALUE y);
VALUE rb_float_eql(VALUE x, VALUE y);
VALUE rb_flo_div_flo(VALUE x, VALUE y);




static inline double
rb_float_flonum_value(VALUE v)
{

    if (v != (VALUE)0x8000000000000002) {
 union {
     double d;
     VALUE v;
 } t;

 VALUE b63 = (v >> 63);



 t.v = ((((2 - b63) | (v & ~(VALUE)0x03)) >> (3)) | (((2 - b63) | (v & ~(VALUE)0x03)) << ((sizeof((2 - b63) | (v & ~(VALUE)0x03)) * 8) - 3)));
 return t.d;
    }

    return 0.0;
}

static inline double
rb_float_noflonum_value(VALUE v)
{
    return ((struct RFloat *)v)->float_value;
}

static inline double
rb_float_value_inline(VALUE v)
{
    if (((((int)(long)(v))&RUBY_FLONUM_MASK) == RUBY_FLONUM_FLAG)) {
 return rb_float_flonum_value(v);
    }
    return rb_float_noflonum_value(v);
}

static inline VALUE
rb_float_new_inline(double d)
{

    union {
 double d;
 VALUE v;
    } t;
    int bits;

    t.d = d;
    bits = (int)((VALUE)(t.v >> 60) & 0x7);





    if (t.v != 0x3000000000000000 &&
 !((bits-3) & ~0x01)) {
 return ((((t.v) << (3)) | ((t.v) >> ((sizeof(t.v) * 8) - 3))) & ~(VALUE)0x01) | 0x02;
    }
    else if (t.v == (VALUE)0) {

 return 0x8000000000000002;
    }


    return rb_float_new_in_heap(d);
}



void rb_obj_copy_ivar(VALUE dest, VALUE obj);
__attribute__ ((__const__)) VALUE rb_obj_equal(VALUE obj1, VALUE obj2);
__attribute__ ((__const__)) VALUE rb_obj_not(VALUE obj);
VALUE rb_class_search_ancestor(VALUE klass, VALUE super);
__attribute__ ((__noreturn__)) void rb_undefined_alloc(VALUE klass);
double rb_num_to_dbl(VALUE val);
VALUE rb_obj_dig(int argc, VALUE *argv, VALUE self, VALUE notfound);
VALUE rb_immutable_obj_clone(int, VALUE *, VALUE);
VALUE rb_obj_not_equal(VALUE obj1, VALUE obj2);
VALUE rb_convert_type_with_id(VALUE,int,const char*,ID);
VALUE rb_check_convert_type_with_id(VALUE,int,const char*,ID);
int rb_bool_expected(VALUE, const char *);

struct RBasicRaw {
    VALUE flags;
    VALUE klass;
};








VALUE rb_parser_set_yydebug(VALUE, VALUE);
VALUE rb_parser_set_context(VALUE, const struct rb_iseq_struct *, int);
void *rb_parser_load_file(VALUE parser, VALUE name);
int rb_is_const_name(VALUE name);
int rb_is_class_name(VALUE name);
int rb_is_instance_name(VALUE name);
int rb_is_local_name(VALUE name);
__attribute__ ((__pure__)) int rb_is_const_sym(VALUE sym);
__attribute__ ((__pure__)) int rb_is_attrset_sym(VALUE sym);
ID rb_make_internal_id(void);
void rb_gc_free_dsymbol(VALUE);


VALUE rb_proc_location(VALUE self);
st_index_t rb_hash_proc(st_index_t hash, VALUE proc);
int rb_block_arity(void);
int rb_block_min_max_arity(int *max);
VALUE rb_func_proc_new(rb_block_call_func_t func, VALUE val);
VALUE rb_func_lambda_new(rb_block_call_func_t func, VALUE val, int min_argc, int max_argc);
VALUE rb_block_to_s(VALUE self, const struct rb_block *block, const char *additional_info);



struct waitpid_state;
struct rb_execarg {
    union {
        struct {
            VALUE shell_script;
        } sh;
        struct {
            VALUE command_name;
            VALUE command_abspath;
            VALUE argv_str;
            VALUE argv_buf;
        } cmd;
    } invoke;
    VALUE redirect_fds;
    VALUE envp_str;
    VALUE envp_buf;
    VALUE dup2_tmpbuf;
    unsigned use_shell : 1;
    unsigned pgroup_given : 1;
    unsigned umask_given : 1;
    unsigned unsetenv_others_given : 1;
    unsigned unsetenv_others_do : 1;
    unsigned close_others_given : 1;
    unsigned close_others_do : 1;
    unsigned chdir_given : 1;
    unsigned new_pgroup_given : 1;
    unsigned new_pgroup_flag : 1;
    unsigned uid_given : 1;
    unsigned gid_given : 1;
    unsigned exception : 1;
    unsigned exception_given : 1;
    struct waitpid_state *waitpid_state;
    pid_t pgroup_pgid;
    VALUE rlimit_limits;
    mode_t umask_mask;
    uid_t uid;
    gid_t gid;
    int close_others_maxhint;
    VALUE fd_dup2;
    VALUE fd_close;
    VALUE fd_open;
    VALUE fd_dup2_child;
    VALUE env_modification;
    VALUE path_env;
    VALUE chdir_dir;
};






static inline size_t
ARGVSTR2ARGC(VALUE argv_str)
{
    size_t i = 0;
    char *const *p = ((char **)((void *)(((const struct rb_imemo_tmpbuf_struct *)(argv_str))->ptr)) + 1);
    while (p[i++])
        ;
    return i - 1;
}

pid_t rb_fork_ruby(int *status);
void rb_last_status_clear(void);




VALUE rb_rational_canonicalize(VALUE x);
VALUE rb_rational_uminus(VALUE self);
VALUE rb_rational_plus(VALUE self, VALUE other);
VALUE rb_rational_mul(VALUE self, VALUE other);
VALUE rb_lcm(VALUE x, VALUE y);
VALUE rb_rational_reciprocal(VALUE x);
VALUE rb_cstr_to_rat(const char *, int);
VALUE rb_rational_abs(VALUE self);
VALUE rb_rational_cmp(VALUE self, VALUE other);
VALUE rb_rational_pow(VALUE self, VALUE other);
VALUE rb_numeric_quo(VALUE x, VALUE y);
VALUE rb_float_numerator(VALUE x);
VALUE rb_float_denominator(VALUE x);


VALUE rb_reg_compile(VALUE str, int options, const char *sourcefile, int sourceline);
VALUE rb_reg_check_preprocess(VALUE);
long rb_reg_search0(VALUE, VALUE, long, int, int);
VALUE rb_reg_match_p(VALUE re, VALUE str, long pos);
_Bool rb_reg_start_with_p(VALUE re, VALUE str);
void rb_backref_set_string(VALUE string, long pos, long len);
void rb_match_unbusy(VALUE);
int rb_match_count(VALUE match);
int rb_match_nth_defined(int nth, VALUE match);
VALUE rb_reg_new_ary(VALUE ary, int options);


extern int ruby_enable_coredump;
int rb_get_next_signal(void);


VALUE rb_fstring(VALUE);
VALUE rb_fstring_new(const char *ptr, long len);
VALUE rb_fstring_cstr(const char *str);

int rb_str_buf_cat_escaped_char(VALUE result, unsigned int c, int unicode_p);
int rb_str_symname_p(VALUE);
VALUE rb_str_quote_unprintable(VALUE);
VALUE rb_id_quote_unprintable(ID);
char *rb_str_fill_terminator(VALUE str, const int termlen);
void rb_str_change_terminator_length(VALUE str, const int oldtermlen, const int termlen);
VALUE rb_str_locktmp_ensure(VALUE str, VALUE (*func)(VALUE), VALUE arg);
VALUE rb_str_chomp_string(VALUE str, VALUE chomp);







size_t rb_str_memsize(VALUE);
VALUE rb_sym_proc_call(ID mid, int argc, const VALUE *argv, int kw_splat, VALUE passed_proc);
VALUE rb_sym_to_proc(VALUE sym);
char *rb_str_to_cstr(VALUE str);
VALUE rb_str_eql(VALUE str1, VALUE str2);
VALUE rb_obj_as_string_result(VALUE str, VALUE obj);
const char *ruby_escaped_char(int c);
VALUE rb_str_opt_plus(VALUE, VALUE);


static inline VALUE
rb_str_eql_internal(const VALUE str1, const VALUE str2)
{
    const long len = (!(((struct RBasic*)(str1))->flags & RSTRING_NOEMBED) ? (long)((((struct RBasic*)(str1))->flags >> RSTRING_EMBED_LEN_SHIFT) & (RSTRING_EMBED_LEN_MASK >> RSTRING_EMBED_LEN_SHIFT)) : ((struct RString*)(str1))->as.heap.len);
    const char *ptr1, *ptr2;

    if (len != (!(((struct RBasic*)(str2))->flags & RSTRING_NOEMBED) ? (long)((((struct RBasic*)(str2))->flags >> RSTRING_EMBED_LEN_SHIFT) & (RSTRING_EMBED_LEN_MASK >> RSTRING_EMBED_LEN_SHIFT)) : ((struct RString*)(str2))->as.heap.len)) return ((VALUE)RUBY_Qfalse);
    if (!rb_str_comparable(str1, str2)) return ((VALUE)RUBY_Qfalse);
    if ((ptr1 = (!(((struct RBasic*)(str1))->flags & RSTRING_NOEMBED) ? ((struct RString*)(str1))->as.ary : ((struct RString*)(str1))->as.heap.ptr)) == (ptr2 = (!(((struct RBasic*)(str2))->flags & RSTRING_NOEMBED) ? ((struct RString*)(str2))->as.ary : ((struct RString*)(str2))->as.heap.ptr)))
        return ((VALUE)RUBY_Qtrue);
    if (memcmp(ptr1, ptr2, len) == 0)
        return ((VALUE)RUBY_Qtrue);
    return ((VALUE)RUBY_Qfalse);
}





VALUE rb_sym_intern_ascii(const char *ptr, long len);
VALUE rb_sym_intern_ascii_cstr(const char *ptr);







VALUE rb_to_symbol_type(VALUE obj);


VALUE rb_struct_init_copy(VALUE copy, VALUE s);
VALUE rb_struct_lookup(VALUE s, VALUE idx);
VALUE rb_struct_s_keyword_init(VALUE klass);


struct timeval rb_time_timeval(VALUE);



VALUE rb_obj_is_mutex(VALUE obj);
VALUE rb_suppress_tracing(VALUE (*func)(VALUE), VALUE arg);
void rb_thread_execute_interrupts(VALUE th);
VALUE rb_get_coverages(void);
int rb_get_coverage_mode(void);
VALUE rb_default_coverage(int);
VALUE rb_thread_shield_new(void);
VALUE rb_thread_shield_wait(VALUE self);
VALUE rb_thread_shield_release(VALUE self);
VALUE rb_thread_shield_destroy(VALUE self);
int rb_thread_to_be_killed(VALUE thread);
void rb_mutex_allow_trap(VALUE self, int val);
VALUE rb_uninterruptible(VALUE (*b_proc)(VALUE), VALUE data);
VALUE rb_mutex_owned_p(VALUE self);


extern VALUE rb_cEncodingConverter;
char *ruby_dtoa(double d_, int mode, int ndigits, int *decpt, int *sign, char **rve);
char *ruby_hdtoa(double d, const char *xdigs, int ndigits, int *decpt, int *sign, char **rve);





void rb_gc_mark_global_tbl(void);
size_t rb_generic_ivar_memsize(VALUE);
VALUE rb_search_class_path(VALUE);
VALUE rb_attr_delete(VALUE, ID);
VALUE rb_ivar_lookup(VALUE obj, ID id, VALUE undef);
void rb_autoload_str(VALUE mod, ID id, VALUE file);
VALUE rb_autoload_at_p(VALUE, ID, int);
void rb_deprecate_constant(VALUE mod, const char *name);
__attribute__ ((__noreturn__)) VALUE rb_mod_const_missing(VALUE,VALUE);
rb_gvar_getter_t *rb_gvar_getter_function_of(const struct rb_global_entry *);
rb_gvar_setter_t *rb_gvar_setter_function_of(const struct rb_global_entry *);
_Bool rb_gvar_is_traced(const struct rb_global_entry *);
void rb_gvar_readonly_setter(VALUE v, ID id, VALUE *_);


rb_serial_t rb_next_class_serial(void);


VALUE rb_obj_is_thread(VALUE obj);
void rb_vm_mark(void *ptr);
void Init_BareVM(void);
void Init_vm_objects(void);
__attribute__ ((__pure__)) VALUE rb_vm_top_self(void);
void rb_vm_inc_const_missing_count(void);
const void **rb_vm_get_insns_address_table(void);
VALUE rb_source_location(int *pline);
const char *rb_source_location_cstr(int *pline);
static void rb_vm_pop_cfunc_frame(void);
int rb_vm_add_root_module(ID id, VALUE module);
void rb_vm_check_redefinition_by_prepend(VALUE klass);
int rb_vm_check_optimizable_mid(VALUE mid);
VALUE rb_yield_refine_block(VALUE refinement, VALUE refinements);
static VALUE ruby_vm_special_exception_copy(VALUE);
__attribute__ ((__pure__)) st_table *rb_vm_fstring_table(void);



void rb_print_backtrace(void);


void Init_vm_eval(void);
VALUE rb_adjust_argv_kw_splat(int *, const VALUE **, int *);
VALUE rb_current_realfilepath(void);
VALUE rb_check_block_call(VALUE, ID, int, const VALUE *, rb_block_call_func_t, VALUE);
typedef void rb_check_funcall_hook(int, VALUE, ID, int, const VALUE *, VALUE);
VALUE rb_check_funcall_with_hook(VALUE recv, ID mid, int argc, const VALUE *argv,
     rb_check_funcall_hook *hook, VALUE arg);
VALUE rb_check_funcall_with_hook_kw(VALUE recv, ID mid, int argc, const VALUE *argv,
                                 rb_check_funcall_hook *hook, VALUE arg, int kw_splat);
const char *rb_type_str(enum ruby_value_type type);
VALUE rb_check_funcall_default(VALUE, ID, int, const VALUE *, VALUE);
VALUE rb_yield_1(VALUE val);
VALUE rb_yield_force_blockarg(VALUE values);
VALUE rb_lambda_call(VALUE obj, ID mid, int argc, const VALUE *argv,
       rb_block_call_func_t bl_proc, int min_argc, int max_argc,
       VALUE data2);


VALUE rb_equal_opt(VALUE obj1, VALUE obj2);static inline 
VALUE rb_eql_opt(VALUE obj1, VALUE obj2);static inline 
void Init_vm_stack_canary(void);


void Init_eval_method(void);

enum method_missing_reason {
    MISSING_NOENTRY = 0x00,
    MISSING_PRIVATE = 0x01,
    MISSING_PROTECTED = 0x02,
    MISSING_FCALL = 0x04,
    MISSING_VCALL = 0x08,
    MISSING_SUPER = 0x10,
    MISSING_MISSING = 0x20,
    MISSING_NONE = 0x40
};
struct rb_callable_method_entry_struct;
struct rb_method_definition_struct;
struct rb_execution_context_struct;
struct rb_control_frame_struct;
struct rb_calling_info;
struct rb_call_data;
struct rb_call_cache {

    rb_serial_t method_state;
    rb_serial_t class_serial[
        (64
         - sizeof(rb_serial_t)
         - sizeof(struct rb_callable_method_entry_struct *)
         - sizeof(uintptr_t)
         - sizeof(enum method_missing_reason)
         - sizeof(VALUE (*)(
               struct rb_execution_context_struct *e,
               struct rb_control_frame_struct *,
               struct rb_calling_info *,
               const struct rb_call_data *)))
        / sizeof(rb_serial_t)
    ];


    const struct rb_callable_method_entry_struct *me;
    uintptr_t method_serial;

    VALUE (*call)(struct rb_execution_context_struct *ec,
                  struct rb_control_frame_struct *cfp,
                  struct rb_calling_info *calling,
                  struct rb_call_data *cd);

    union {
        unsigned int index;
        enum method_missing_reason method_missing_reason;
    } aux;
};
__extension__ _Static_assert(sizeof(struct rb_call_cache) <= 64, "cachelined" ": " "sizeof(struct rb_call_cache) <= CACHELINE");
struct rb_call_info {

    ID mid;
    unsigned int flag;
    int orig_argc;
};
struct rb_call_data {
    struct rb_call_cache cc;
    struct rb_call_info ci;
};
__attribute__ ((__visibility__("default"))) extern
__attribute__ ((__nonnull__(1))) VALUE rb_funcallv_with_cc(struct rb_call_data*, VALUE, ID, int, const VALUE*);
__attribute__ ((__visibility__("default"))) extern
__attribute__ ((__nonnull__(1))) _Bool rb_method_basic_definition_p_with_cc(struct rb_call_data *, VALUE, ID);














void Init_vm_backtrace(void);
VALUE rb_vm_thread_backtrace(int argc, const VALUE *argv, VALUE thval);
VALUE rb_vm_thread_backtrace_locations(int argc, const VALUE *argv, VALUE thval);

VALUE rb_make_backtrace(void);
void rb_backtrace_print_as_bugreport(void);
int rb_backtrace_p(VALUE obj);
VALUE rb_backtrace_to_str_ary(VALUE obj);
VALUE rb_backtrace_to_location_ary(VALUE obj);
void rb_backtrace_each(VALUE (*iter)(VALUE recv, VALUE str), VALUE output);

const char *rb_objspace_data_type_name(VALUE obj);


VALUE rb_thread_io_blocking_region(rb_blocking_function_t *func, void *data1, int fd);


void rb_ary_detransient(VALUE a);
VALUE *rb_ary_ptr_use_start(VALUE ary);
void rb_ary_ptr_use_end(VALUE ary);


VALUE rb_big_mul_normal(VALUE x, VALUE y);
VALUE rb_big_mul_balance(VALUE x, VALUE y);
VALUE rb_big_mul_karatsuba(VALUE x, VALUE y);
VALUE rb_big_mul_toom3(VALUE x, VALUE y);
VALUE rb_big_sq_fast(VALUE x);
VALUE rb_big_divrem_normal(VALUE x, VALUE y);
VALUE rb_big2str_poweroftwo(VALUE x, int base);
VALUE rb_big2str_generic(VALUE x, int base);
VALUE rb_str2big_poweroftwo(VALUE arg, int base, int badcheck);
VALUE rb_str2big_normal(VALUE arg, int base, int badcheck);
VALUE rb_str2big_karatsuba(VALUE arg, int base, int badcheck);






enum rb_int_parse_flags {
    RB_INT_PARSE_SIGN = 0x01,
    RB_INT_PARSE_UNDERSCORE = 0x02,
    RB_INT_PARSE_PREFIX = 0x04,
    RB_INT_PARSE_ALL = 0x07,
    RB_INT_PARSE_DEFAULT = 0x07
};
VALUE rb_int_parse_cstr(const char *str, ssize_t len, char **endp, size_t *ndigits, int base, int flags);


VALUE rb_arith_seq_new(VALUE obj, VALUE meth, int argc, VALUE const *argv,
                       rb_enumerator_size_func *size_fn,
                       VALUE beg, VALUE end, VALUE step, int excl);


int rb_bug_reporter_add(void (*func)(FILE *, void *), void *data);
__attribute__ ((__noreturn__)) void rb_unexpected_type(VALUE,int);




static inline int
rb_typeddata_is_instance_of_inline(VALUE obj, const rb_data_type_t *data_type)
{
    return ( ((RUBY_T_DATA) == RUBY_T_FIXNUM) ? (((int)(long)(obj))&RUBY_FIXNUM_FLAG) : ((RUBY_T_DATA) == RUBY_T_TRUE) ? ((obj) == ((VALUE)RUBY_Qtrue)) : ((RUBY_T_DATA) == RUBY_T_FALSE) ? ((obj) == ((VALUE)RUBY_Qfalse)) : ((RUBY_T_DATA) == RUBY_T_NIL) ? ((obj) == ((VALUE)RUBY_Qnil)) : ((RUBY_T_DATA) == RUBY_T_UNDEF) ? ((obj) == ((VALUE)RUBY_Qundef)) : ((RUBY_T_DATA) == RUBY_T_SYMBOL) ? ((((VALUE)(obj)&~((~(VALUE)0)<<RUBY_SPECIAL_SHIFT)) == RUBY_SYMBOL_FLAG)||(!(((VALUE)(obj) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(obj) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(obj))->flags & RUBY_T_MASK) == (RUBY_T_SYMBOL))) : ((RUBY_T_DATA) == RUBY_T_FLOAT) ? ( ((((int)(long)(obj))&RUBY_FLONUM_MASK) == RUBY_FLONUM_FLAG) || (!(((VALUE)(obj) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(obj) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(obj))->flags & RUBY_T_MASK) == RUBY_T_FLOAT)) : (!(((VALUE)(obj) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(obj) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(obj))->flags & RUBY_T_MASK) == (RUBY_T_DATA))) && (((struct RTypedData*)(obj))->typed_flag == 1) && ((((struct RTypedData*)(obj))->type) == data_type);
}






VALUE rb_str_normalize_ospath(const char *ptr, long len);



VALUE rb_hash_delete_entry(VALUE hash, VALUE key);
VALUE rb_ident_hash_new(void);


void rb_maygvl_fd_fix_cloexec(int fd);
int rb_gc_for_fd(int err);
void rb_write_error_str(VALUE mesg);


VALUE rb_int_positive_pow(long x, unsigned long y);


int rb_opts_exception_p(VALUE opts, int default_value);


int rb_exec_async_signal_safe(const struct rb_execarg *e, char *errmsg, size_t errmsg_buflen);
pid_t rb_fork_async_signal_safe(int *status, int (*chfunc)(void*, char *, size_t), void *charg, VALUE fds, char *errmsg, size_t errmsg_buflen);
VALUE rb_execarg_new(int argc, const VALUE *argv, int accept_shell, int allow_exc_opt);
struct rb_execarg *rb_execarg_get(VALUE execarg_obj);
int rb_execarg_addopt(VALUE execarg_obj, VALUE key, VALUE val);
void rb_execarg_parent_start(VALUE execarg_obj);
void rb_execarg_parent_end(VALUE execarg_obj);
int rb_execarg_run_options(const struct rb_execarg *e, struct rb_execarg *s, char* errmsg, size_t errmsg_buflen);
VALUE rb_execarg_extract_options(VALUE execarg_obj, VALUE opthash);
void rb_execarg_setenv(VALUE execarg_obj, VALUE env);


VALUE rb_gcd(VALUE x, VALUE y);
VALUE rb_gcd_normal(VALUE self, VALUE other);





int rb_grantpt(int fd);


VALUE rb_str_tmp_frozen_acquire(VALUE str);
void rb_str_tmp_frozen_release(VALUE str, VALUE tmp);




VALUE rb_str_upto_each(VALUE, VALUE, int, int (*each)(VALUE, VALUE), VALUE);
VALUE rb_str_upto_endless_each(VALUE, int (*each)(VALUE, VALUE), VALUE);


int ruby_thread_has_gvl_p(void);


void ruby_reset_leap_second_info(void);


extern const signed char ruby_digit36_to_number_table[];
extern const char ruby_hexdigits[];
extern unsigned long ruby_scan_digits(const char *str, ssize_t len, int base, size_t *retlen, int *overflow);


void rb_mark_generic_ivar(VALUE);
void rb_mv_generic_ivar(VALUE src, VALUE dst);
VALUE rb_const_missing(VALUE klass, VALUE name);
int rb_class_ivar_set(VALUE klass, ID vid, VALUE value);
void rb_iv_tbl_copy(VALUE dst, VALUE src);


VALUE rb_wb_protected_newobj_of(VALUE, VALUE);
VALUE rb_wb_unprotected_newobj_of(VALUE, VALUE);

size_t rb_obj_memsize_of(VALUE);
void rb_gc_verify_internal_consistency(void);

size_t rb_obj_gc_flags(VALUE, ID[], size_t);
void rb_gc_mark_values(long n, const VALUE *values);
void rb_gc_mark_vm_stack_values(long n, const VALUE *values);





VALUE rb_imemo_new(enum imemo_type type, VALUE v1, VALUE v2, VALUE v3, VALUE v0);



int ruby_fill_random_bytes(void *, size_t, int);


























typedef struct rb_vm_struct ruby_vm_t;


int ruby_vm_destruct(ruby_vm_t *vm);
void ruby_vm_at_exit(void(*func)(ruby_vm_t *));















__attribute__ ((__noinline__)) void rb_gc_set_stack_end(VALUE **stack_end_p);






















const char *rb_obj_info(VALUE obj);
const char *rb_raw_obj_info(char *buff, const int buff_size, VALUE obj);

VALUE rb_gc_disable_no_rest(void);

struct rb_thread_struct;



size_t rb_objspace_data_type_memsize(VALUE obj);
void rb_objspace_reachable_objects_from(VALUE obj, void (func)(VALUE, void *), void *data);
void rb_objspace_reachable_objects_from_root(void (func)(const char *category, VALUE, void *), void *data);
int rb_objspace_markable_object_p(VALUE obj);
int rb_objspace_internal_object_p(VALUE obj);
int rb_objspace_marked_object_p(VALUE obj);
int rb_objspace_garbage_object_p(VALUE obj);

void rb_objspace_each_objects(
    int (*callback)(void *start, void *end, size_t stride, void *data),
    void *data);

void rb_objspace_each_objects_without_setup(
    int (*callback)(void *, void *, size_t, void *),
    void *data);







































enum node_type {
    NODE_SCOPE,
    NODE_BLOCK,
    NODE_IF,
    NODE_UNLESS,
    NODE_CASE,
    NODE_CASE2,
    NODE_CASE3,
    NODE_WHEN,
    NODE_IN,
    NODE_WHILE,
    NODE_UNTIL,
    NODE_ITER,
    NODE_FOR,
    NODE_FOR_MASGN,
    NODE_BREAK,
    NODE_NEXT,
    NODE_REDO,
    NODE_RETRY,
    NODE_BEGIN,
    NODE_RESCUE,
    NODE_RESBODY,
    NODE_ENSURE,
    NODE_AND,
    NODE_OR,
    NODE_MASGN,
    NODE_LASGN,
    NODE_DASGN,
    NODE_DASGN_CURR,
    NODE_GASGN,
    NODE_IASGN,
    NODE_CDECL,
    NODE_CVASGN,
    NODE_OP_ASGN1,
    NODE_OP_ASGN2,
    NODE_OP_ASGN_AND,
    NODE_OP_ASGN_OR,
    NODE_OP_CDECL,
    NODE_CALL,
    NODE_OPCALL,
    NODE_FCALL,
    NODE_VCALL,
    NODE_QCALL,
    NODE_SUPER,
    NODE_ZSUPER,
    NODE_LIST,
    NODE_ZLIST,
    NODE_VALUES,
    NODE_HASH,
    NODE_RETURN,
    NODE_YIELD,
    NODE_LVAR,
    NODE_DVAR,
    NODE_GVAR,
    NODE_IVAR,
    NODE_CONST,
    NODE_CVAR,
    NODE_NTH_REF,
    NODE_BACK_REF,
    NODE_MATCH,
    NODE_MATCH2,
    NODE_MATCH3,
    NODE_LIT,
    NODE_STR,
    NODE_DSTR,
    NODE_XSTR,
    NODE_DXSTR,
    NODE_EVSTR,
    NODE_DREGX,
    NODE_ONCE,
    NODE_ARGS,
    NODE_ARGS_AUX,
    NODE_OPT_ARG,
    NODE_KW_ARG,
    NODE_POSTARG,
    NODE_ARGSCAT,
    NODE_ARGSPUSH,
    NODE_SPLAT,
    NODE_BLOCK_PASS,
    NODE_DEFN,
    NODE_DEFS,
    NODE_ALIAS,
    NODE_VALIAS,
    NODE_UNDEF,
    NODE_CLASS,
    NODE_MODULE,
    NODE_SCLASS,
    NODE_COLON2,
    NODE_COLON3,
    NODE_DOT2,
    NODE_DOT3,
    NODE_FLIP2,
    NODE_FLIP3,
    NODE_SELF,
    NODE_NIL,
    NODE_TRUE,
    NODE_FALSE,
    NODE_ERRINFO,
    NODE_DEFINED,
    NODE_POSTEXE,
    NODE_DSYM,
    NODE_ATTRASGN,
    NODE_LAMBDA,
    NODE_ARYPTN,
    NODE_HSHPTN,
    NODE_LAST
};

typedef struct rb_code_position_struct {
    int lineno;
    int column;
} rb_code_position_t;

typedef struct rb_code_location_struct {
    rb_code_position_t beg_pos;
    rb_code_position_t end_pos;
} rb_code_location_t;

static inline rb_code_location_t
code_loc_gen(rb_code_location_t *loc1, rb_code_location_t *loc2)
{
    rb_code_location_t loc;
    loc.beg_pos = loc1->beg_pos;
    loc.end_pos = loc2->end_pos;
    return loc;
}

typedef struct RNode {
    VALUE flags;
    union {
 struct RNode *node;
 ID id;
 VALUE value;
 ID *tbl;
    } u1;
    union {
 struct RNode *node;
 ID id;
 long argc;
 VALUE value;
    } u2;
    union {
 struct RNode *node;
 ID id;
 long state;
 struct rb_global_entry *entry;
 struct rb_args_info *args;
        struct rb_ary_pattern_info *apinfo;
 VALUE value;
    } u3;
    rb_code_location_t nd_loc;
    int node_id;
} NODE;







































VALUE rb_node_case_when_optimizable_literal(const NODE *const node);


typedef struct node_buffer_struct node_buffer_t;

typedef struct rb_ast_body_struct {
    const NODE *root;
    VALUE compile_option;
    int line_count;
} rb_ast_body_t;
typedef struct rb_ast_struct {
    VALUE flags;
    node_buffer_t *node_buffer;
    rb_ast_body_t body;
} rb_ast_t;
rb_ast_t *rb_ast_new(void);
void rb_ast_mark(rb_ast_t*);
void rb_ast_update_references(rb_ast_t*);
void rb_ast_add_local_table(rb_ast_t*, ID *buf);
void rb_ast_dispose(rb_ast_t*);
void rb_ast_free(rb_ast_t*);
size_t rb_ast_memsize(const rb_ast_t*);
void rb_ast_add_mark_object(rb_ast_t*, VALUE);
NODE *rb_ast_newnode(rb_ast_t*, enum node_type type);
void rb_ast_delete_node(rb_ast_t*, NODE *n);

VALUE rb_parser_new(void);
VALUE rb_parser_end_seen_p(VALUE);
VALUE rb_parser_encoding(VALUE);
VALUE rb_parser_set_yydebug(VALUE, VALUE);
VALUE rb_parser_dump_tree(const NODE *node, int comment);
void rb_parser_set_options(VALUE, int, int, int, int);

rb_ast_t *rb_parser_compile_string(VALUE, const char*, VALUE, int);
rb_ast_t *rb_parser_compile_string_path(VALUE vparser, VALUE fname, VALUE src, int line);
rb_ast_t *rb_parser_compile_file_path(VALUE vparser, VALUE fname, VALUE input, int line);
rb_ast_t *rb_parser_compile_generic(VALUE vparser, VALUE (*lex_gets)(VALUE, int), VALUE fname, VALUE input, int line);

void rb_node_init(NODE *n, enum node_type type, VALUE a0, VALUE a1, VALUE a2);
const char *ruby_node_name(int node);

const struct kwtable *rb_reserved_word(const char *, unsigned int);

struct rb_args_info {
    NODE *pre_init;
    NODE *post_init;

    int pre_args_num;
    int post_args_num;

    ID first_post_arg;

    ID rest_arg;
    ID block_arg;

    NODE *kw_args;
    NODE *kw_rest_arg;

    NODE *opt_args;
    unsigned int no_kwarg: 1;
    unsigned int ruby2_keywords: 1;

    VALUE imemo;
};

struct rb_ary_pattern_info {
    NODE *pre_args;
    NODE *rest_arg;
    NODE *post_args;
    VALUE imemo;
};

struct parser_params;
void *rb_parser_malloc(struct parser_params *, size_t);
void *rb_parser_realloc(struct parser_params *, void *, size_t);
void *rb_parser_calloc(struct parser_params *, size_t, size_t);
void rb_parser_free(struct parser_params *, void *);
void rb_parser_printf(struct parser_params *parser, const char *fmt, ...) __attribute__((format(printf, 2, 3)));























enum ruby_id_types {
    RUBY_ID_STATIC_SYM = 0x01,
    RUBY_ID_LOCAL = 0x00,
    RUBY_ID_INSTANCE = (0x01<<1),
    RUBY_ID_GLOBAL = (0x03<<1),
    RUBY_ID_ATTRSET = (0x04<<1),
    RUBY_ID_CONST = (0x05<<1),
    RUBY_ID_CLASS = (0x06<<1),
    RUBY_ID_JUNK = (0x07<<1),
    RUBY_ID_INTERNAL = RUBY_ID_JUNK,
    RUBY_ID_SCOPE_SHIFT = 4,
    RUBY_ID_SCOPE_MASK = (~(~0U<<(RUBY_ID_SCOPE_SHIFT-1))<<1)
};





enum ruby_method_ids {
    idDot2 = 128,
    idDot3 = 129,
    idUPlus = 132,
    idUMinus = 133,
    idPow = 134,
    idCmp = 135,
    idPLUS = '+',
    idMINUS = '-',
    idMULT = '*',
    idDIV = '/',
    idMOD = '%',
    idLTLT = 136,
    idGTGT = 137,
    idLT = '<',
    idLE = 138,
    idGT = '>',
    idGE = 139,
    idEq = 140,
    idEqq = 141,
    idNeq = 142,
    idNot = '!',
    idAnd = '&',
    idOr = '|',
    idBackquote = '`',
    idEqTilde = 143,
    idNeqTilde = 144,
    idAREF = 145,
    idASET = 146,
    idCOLON2 = 147,
    idANDOP = 148,
    idOROP = 149,
    idANDDOT = 150,
    tPRESERVED_ID_BEGIN = 150,
    idNilP,
    idNULL,
    idEmptyP,
    idEqlP,
    idRespond_to,
    idRespond_to_missing,
    idIFUNC,
    idCFUNC,
    id_core_set_method_alias,
    id_core_set_variable_alias,
    id_core_undef_method,
    id_core_define_method,
    id_core_define_singleton_method,
    id_core_set_postexe,
    id_core_hash_merge_ptr,
    id_core_hash_merge_kwd,
    id_core_raise,
    id_debug_created_info,
    tPRESERVED_ID_END,
    tTOKEN_LOCAL_BEGIN = tPRESERVED_ID_END-1,
    tMax,
    tMin,
    tFreeze,
    tInspect,
    tIntern,
    tObject_id,
    tConst_missing,
    tMethodMissing,
    tMethod_added,
    tSingleton_method_added,
    tMethod_removed,
    tSingleton_method_removed,
    tMethod_undefined,
    tSingleton_method_undefined,
    tLength,
    tSize,
    tGets,
    tSucc,
    tEach,
    tProc,
    tLambda,
    tSend,
    t__send__,
    t__attached__,
    tInitialize,
    tInitialize_copy,
    tInitialize_clone,
    tInitialize_dup,
    tTo_int,
    tTo_ary,
    tTo_str,
    tTo_sym,
    tTo_hash,
    tTo_proc,
    tTo_io,
    tTo_a,
    tTo_s,
    tTo_i,
    tTo_f,
    tTo_r,
    tBt,
    tBt_locations,
    tCall,
    tMesg,
    tException,
    tLocals,
    tNOT,
    tAND,
    tOR,
    tDiv,
    tDivmod,
    tFdiv,
    tQuo,
    tName,
    tNil,
    tUScore,
    tNUMPARAM_1,
    tNUMPARAM_2,
    tNUMPARAM_3,
    tNUMPARAM_4,
    tNUMPARAM_5,
    tNUMPARAM_6,
    tNUMPARAM_7,
    tNUMPARAM_8,
    tNUMPARAM_9,
    tTOKEN_LOCAL_END,
    tTOKEN_INSTANCE_BEGIN = tTOKEN_LOCAL_END-1,
    tTOKEN_INSTANCE_END,
    tTOKEN_GLOBAL_BEGIN = tTOKEN_INSTANCE_END-1,
    tLASTLINE,
    tBACKREF,
    tERROR_INFO,
    tTOKEN_GLOBAL_END,
    tTOKEN_CONST_BEGIN = tTOKEN_GLOBAL_END-1,
    tTOKEN_CONST_END,
    tTOKEN_CLASS_BEGIN = tTOKEN_CONST_END-1,
    tTOKEN_CLASS_END,
    tTOKEN_ATTRSET_BEGIN = tTOKEN_CLASS_END-1,
    tTOKEN_ATTRSET_END,
    tNEXT_ID = tTOKEN_ATTRSET_END,
 idMax = ((tMax<<RUBY_ID_SCOPE_SHIFT)|RUBY_ID_LOCAL|RUBY_ID_STATIC_SYM),
    idMin = ((tMin<<RUBY_ID_SCOPE_SHIFT)|RUBY_ID_LOCAL|RUBY_ID_STATIC_SYM),
    idFreeze = ((tFreeze<<RUBY_ID_SCOPE_SHIFT)|RUBY_ID_LOCAL|RUBY_ID_STATIC_SYM),
    idInspect = ((tInspect<<RUBY_ID_SCOPE_SHIFT)|RUBY_ID_LOCAL|RUBY_ID_STATIC_SYM),
    idIntern = ((tIntern<<RUBY_ID_SCOPE_SHIFT)|RUBY_ID_LOCAL|RUBY_ID_STATIC_SYM),
    idObject_id = ((tObject_id<<RUBY_ID_SCOPE_SHIFT)|RUBY_ID_LOCAL|RUBY_ID_STATIC_SYM),
    idConst_missing = ((tConst_missing<<RUBY_ID_SCOPE_SHIFT)|RUBY_ID_LOCAL|RUBY_ID_STATIC_SYM),
    idMethodMissing = ((tMethodMissing<<RUBY_ID_SCOPE_SHIFT)|RUBY_ID_LOCAL|RUBY_ID_STATIC_SYM),
    idMethod_added = ((tMethod_added<<RUBY_ID_SCOPE_SHIFT)|RUBY_ID_LOCAL|RUBY_ID_STATIC_SYM),
    idSingleton_method_added = ((tSingleton_method_added<<RUBY_ID_SCOPE_SHIFT)|RUBY_ID_LOCAL|RUBY_ID_STATIC_SYM),
    idMethod_removed = ((tMethod_removed<<RUBY_ID_SCOPE_SHIFT)|RUBY_ID_LOCAL|RUBY_ID_STATIC_SYM),
    idSingleton_method_removed = ((tSingleton_method_removed<<RUBY_ID_SCOPE_SHIFT)|RUBY_ID_LOCAL|RUBY_ID_STATIC_SYM),
    idMethod_undefined = ((tMethod_undefined<<RUBY_ID_SCOPE_SHIFT)|RUBY_ID_LOCAL|RUBY_ID_STATIC_SYM),
    idSingleton_method_undefined = ((tSingleton_method_undefined<<RUBY_ID_SCOPE_SHIFT)|RUBY_ID_LOCAL|RUBY_ID_STATIC_SYM),
    idLength = ((tLength<<RUBY_ID_SCOPE_SHIFT)|RUBY_ID_LOCAL|RUBY_ID_STATIC_SYM),
    idSize = ((tSize<<RUBY_ID_SCOPE_SHIFT)|RUBY_ID_LOCAL|RUBY_ID_STATIC_SYM),
    idGets = ((tGets<<RUBY_ID_SCOPE_SHIFT)|RUBY_ID_LOCAL|RUBY_ID_STATIC_SYM),
    idSucc = ((tSucc<<RUBY_ID_SCOPE_SHIFT)|RUBY_ID_LOCAL|RUBY_ID_STATIC_SYM),
    idEach = ((tEach<<RUBY_ID_SCOPE_SHIFT)|RUBY_ID_LOCAL|RUBY_ID_STATIC_SYM),
    idProc = ((tProc<<RUBY_ID_SCOPE_SHIFT)|RUBY_ID_LOCAL|RUBY_ID_STATIC_SYM),
    idLambda = ((tLambda<<RUBY_ID_SCOPE_SHIFT)|RUBY_ID_LOCAL|RUBY_ID_STATIC_SYM),
    idSend = ((tSend<<RUBY_ID_SCOPE_SHIFT)|RUBY_ID_LOCAL|RUBY_ID_STATIC_SYM),
    id__send__ = ((t__send__<<RUBY_ID_SCOPE_SHIFT)|RUBY_ID_LOCAL|RUBY_ID_STATIC_SYM),
    id__attached__ = ((t__attached__<<RUBY_ID_SCOPE_SHIFT)|RUBY_ID_LOCAL|RUBY_ID_STATIC_SYM),
    idInitialize = ((tInitialize<<RUBY_ID_SCOPE_SHIFT)|RUBY_ID_LOCAL|RUBY_ID_STATIC_SYM),
    idInitialize_copy = ((tInitialize_copy<<RUBY_ID_SCOPE_SHIFT)|RUBY_ID_LOCAL|RUBY_ID_STATIC_SYM),
    idInitialize_clone = ((tInitialize_clone<<RUBY_ID_SCOPE_SHIFT)|RUBY_ID_LOCAL|RUBY_ID_STATIC_SYM),
    idInitialize_dup = ((tInitialize_dup<<RUBY_ID_SCOPE_SHIFT)|RUBY_ID_LOCAL|RUBY_ID_STATIC_SYM),
    idTo_int = ((tTo_int<<RUBY_ID_SCOPE_SHIFT)|RUBY_ID_LOCAL|RUBY_ID_STATIC_SYM),
    idTo_ary = ((tTo_ary<<RUBY_ID_SCOPE_SHIFT)|RUBY_ID_LOCAL|RUBY_ID_STATIC_SYM),
    idTo_str = ((tTo_str<<RUBY_ID_SCOPE_SHIFT)|RUBY_ID_LOCAL|RUBY_ID_STATIC_SYM),
    idTo_sym = ((tTo_sym<<RUBY_ID_SCOPE_SHIFT)|RUBY_ID_LOCAL|RUBY_ID_STATIC_SYM),
    idTo_hash = ((tTo_hash<<RUBY_ID_SCOPE_SHIFT)|RUBY_ID_LOCAL|RUBY_ID_STATIC_SYM),
    idTo_proc = ((tTo_proc<<RUBY_ID_SCOPE_SHIFT)|RUBY_ID_LOCAL|RUBY_ID_STATIC_SYM),
    idTo_io = ((tTo_io<<RUBY_ID_SCOPE_SHIFT)|RUBY_ID_LOCAL|RUBY_ID_STATIC_SYM),
    idTo_a = ((tTo_a<<RUBY_ID_SCOPE_SHIFT)|RUBY_ID_LOCAL|RUBY_ID_STATIC_SYM),
    idTo_s = ((tTo_s<<RUBY_ID_SCOPE_SHIFT)|RUBY_ID_LOCAL|RUBY_ID_STATIC_SYM),
    idTo_i = ((tTo_i<<RUBY_ID_SCOPE_SHIFT)|RUBY_ID_LOCAL|RUBY_ID_STATIC_SYM),
    idTo_f = ((tTo_f<<RUBY_ID_SCOPE_SHIFT)|RUBY_ID_LOCAL|RUBY_ID_STATIC_SYM),
    idTo_r = ((tTo_r<<RUBY_ID_SCOPE_SHIFT)|RUBY_ID_LOCAL|RUBY_ID_STATIC_SYM),
    idBt = ((tBt<<RUBY_ID_SCOPE_SHIFT)|RUBY_ID_LOCAL|RUBY_ID_STATIC_SYM),
    idBt_locations = ((tBt_locations<<RUBY_ID_SCOPE_SHIFT)|RUBY_ID_LOCAL|RUBY_ID_STATIC_SYM),
    idCall = ((tCall<<RUBY_ID_SCOPE_SHIFT)|RUBY_ID_LOCAL|RUBY_ID_STATIC_SYM),
    idMesg = ((tMesg<<RUBY_ID_SCOPE_SHIFT)|RUBY_ID_LOCAL|RUBY_ID_STATIC_SYM),
    idException = ((tException<<RUBY_ID_SCOPE_SHIFT)|RUBY_ID_LOCAL|RUBY_ID_STATIC_SYM),
    idLocals = ((tLocals<<RUBY_ID_SCOPE_SHIFT)|RUBY_ID_LOCAL|RUBY_ID_STATIC_SYM),
    idNOT = ((tNOT<<RUBY_ID_SCOPE_SHIFT)|RUBY_ID_LOCAL|RUBY_ID_STATIC_SYM),
    idAND = ((tAND<<RUBY_ID_SCOPE_SHIFT)|RUBY_ID_LOCAL|RUBY_ID_STATIC_SYM),
    idOR = ((tOR<<RUBY_ID_SCOPE_SHIFT)|RUBY_ID_LOCAL|RUBY_ID_STATIC_SYM),
    idDiv = ((tDiv<<RUBY_ID_SCOPE_SHIFT)|RUBY_ID_LOCAL|RUBY_ID_STATIC_SYM),
    idDivmod = ((tDivmod<<RUBY_ID_SCOPE_SHIFT)|RUBY_ID_LOCAL|RUBY_ID_STATIC_SYM),
    idFdiv = ((tFdiv<<RUBY_ID_SCOPE_SHIFT)|RUBY_ID_LOCAL|RUBY_ID_STATIC_SYM),
    idQuo = ((tQuo<<RUBY_ID_SCOPE_SHIFT)|RUBY_ID_LOCAL|RUBY_ID_STATIC_SYM),
    idName = ((tName<<RUBY_ID_SCOPE_SHIFT)|RUBY_ID_LOCAL|RUBY_ID_STATIC_SYM),
    idNil = ((tNil<<RUBY_ID_SCOPE_SHIFT)|RUBY_ID_LOCAL|RUBY_ID_STATIC_SYM),
    idUScore = ((tUScore<<RUBY_ID_SCOPE_SHIFT)|RUBY_ID_LOCAL|RUBY_ID_STATIC_SYM),
    idNUMPARAM_1 = ((tNUMPARAM_1<<RUBY_ID_SCOPE_SHIFT)|RUBY_ID_LOCAL|RUBY_ID_STATIC_SYM),
    idNUMPARAM_2 = ((tNUMPARAM_2<<RUBY_ID_SCOPE_SHIFT)|RUBY_ID_LOCAL|RUBY_ID_STATIC_SYM),
    idNUMPARAM_3 = ((tNUMPARAM_3<<RUBY_ID_SCOPE_SHIFT)|RUBY_ID_LOCAL|RUBY_ID_STATIC_SYM),
    idNUMPARAM_4 = ((tNUMPARAM_4<<RUBY_ID_SCOPE_SHIFT)|RUBY_ID_LOCAL|RUBY_ID_STATIC_SYM),
    idNUMPARAM_5 = ((tNUMPARAM_5<<RUBY_ID_SCOPE_SHIFT)|RUBY_ID_LOCAL|RUBY_ID_STATIC_SYM),
    idNUMPARAM_6 = ((tNUMPARAM_6<<RUBY_ID_SCOPE_SHIFT)|RUBY_ID_LOCAL|RUBY_ID_STATIC_SYM),
    idNUMPARAM_7 = ((tNUMPARAM_7<<RUBY_ID_SCOPE_SHIFT)|RUBY_ID_LOCAL|RUBY_ID_STATIC_SYM),
    idNUMPARAM_8 = ((tNUMPARAM_8<<RUBY_ID_SCOPE_SHIFT)|RUBY_ID_LOCAL|RUBY_ID_STATIC_SYM),
    idNUMPARAM_9 = ((tNUMPARAM_9<<RUBY_ID_SCOPE_SHIFT)|RUBY_ID_LOCAL|RUBY_ID_STATIC_SYM),
 idLASTLINE = ((tLASTLINE<<RUBY_ID_SCOPE_SHIFT)|RUBY_ID_GLOBAL|RUBY_ID_STATIC_SYM),
    idBACKREF = ((tBACKREF<<RUBY_ID_SCOPE_SHIFT)|RUBY_ID_GLOBAL|RUBY_ID_STATIC_SYM),
    idERROR_INFO = ((tERROR_INFO<<RUBY_ID_SCOPE_SHIFT)|RUBY_ID_GLOBAL|RUBY_ID_STATIC_SYM),
 tLAST_OP_ID = tPRESERVED_ID_END-1,
    idLAST_OP_ID = tLAST_OP_ID >> RUBY_ID_SCOPE_SHIFT
};












typedef enum {
    METHOD_VISI_UNDEF = 0x00,
    METHOD_VISI_PUBLIC = 0x01,
    METHOD_VISI_PRIVATE = 0x02,
    METHOD_VISI_PROTECTED = 0x03,

    METHOD_VISI_MASK = 0x03
} rb_method_visibility_t;

typedef struct rb_scope_visi_struct {
    rb_method_visibility_t method_visi : 3;
    unsigned int module_func : 1;
} rb_scope_visibility_t;


typedef struct rb_cref_struct {
    VALUE flags;
    VALUE refinements;
    VALUE klass;
    struct rb_cref_struct * next;
    const rb_scope_visibility_t scope_visi;
} rb_cref_t;



typedef struct rb_method_entry_struct {
    VALUE flags;
    VALUE defined_class;
    struct rb_method_definition_struct * const def;
    ID called_id;
    VALUE owner;
} rb_method_entry_t;

typedef struct rb_callable_method_entry_struct {
    VALUE flags;
    const VALUE defined_class;
    struct rb_method_definition_struct * const def;
    ID called_id;
    const VALUE owner;
} rb_callable_method_entry_t;


static inline void
METHOD_ENTRY_VISI_SET(rb_method_entry_t *me, rb_method_visibility_t visi)
{
    ((void)0);
    me->flags = (me->flags & ~(((VALUE)RUBY_FL_USER4) | ((VALUE)RUBY_FL_USER5))) | (visi << ((((VALUE)RUBY_FL_USHIFT) + 4)+0));
}
static inline void
METHOD_ENTRY_BASIC_SET(rb_method_entry_t *me, unsigned int basic)
{
    ((void)0);
    me->flags = (me->flags & ~(((VALUE)RUBY_FL_USER6) )) | (basic << ((((VALUE)RUBY_FL_USHIFT) + 4)+2));
}
static inline void
METHOD_ENTRY_FLAGS_SET(rb_method_entry_t *me, rb_method_visibility_t visi, unsigned int basic)
{
    ((void)0);
    ((void)0);
    me->flags =
      (me->flags & ~(((VALUE)RUBY_FL_USER4)|((VALUE)RUBY_FL_USER5)|((VALUE)RUBY_FL_USER6))) |
        ((visi << ((((VALUE)RUBY_FL_USHIFT) + 4)+0)) | (basic << ((((VALUE)RUBY_FL_USHIFT) + 4)+2)));
}
static inline void
METHOD_ENTRY_FLAGS_COPY(rb_method_entry_t *dst, const rb_method_entry_t *src)
{
    dst->flags =
      (dst->flags & ~(((VALUE)RUBY_FL_USER4)|((VALUE)RUBY_FL_USER5)|((VALUE)RUBY_FL_USER6))) |
        (src->flags & (((VALUE)RUBY_FL_USER4)|((VALUE)RUBY_FL_USER5)|((VALUE)RUBY_FL_USER6)));
}

typedef enum {
    VM_METHOD_TYPE_ISEQ,
    VM_METHOD_TYPE_CFUNC,
    VM_METHOD_TYPE_ATTRSET,
    VM_METHOD_TYPE_IVAR,
    VM_METHOD_TYPE_BMETHOD,
    VM_METHOD_TYPE_ZSUPER,
    VM_METHOD_TYPE_ALIAS,
    VM_METHOD_TYPE_UNDEF,
    VM_METHOD_TYPE_NOTIMPLEMENTED,
    VM_METHOD_TYPE_OPTIMIZED,
    VM_METHOD_TYPE_MISSING,
    VM_METHOD_TYPE_REFINED,


} rb_method_type_t;
__extension__ _Static_assert(VM_METHOD_TYPE_REFINED <= (1<<4), "VM_METHOD_TYPE_MINIMUM_BITS" ": " "VM_METHOD_TYPE_REFINED <= (1<<VM_METHOD_TYPE_MINIMUM_BITS)");



typedef struct rb_iseq_struct rb_iseq_t;


typedef struct rb_method_iseq_struct {
    rb_iseq_t * iseqptr;
    rb_cref_t * cref;
} rb_method_iseq_t;

typedef struct rb_method_cfunc_struct {
    VALUE (*func)();
    VALUE (*invoker)(VALUE recv, int argc, const VALUE *argv, VALUE (*func)());
    int argc;
} rb_method_cfunc_t;

typedef struct rb_method_attr_struct {
    ID id;
    VALUE location;
} rb_method_attr_t;

typedef struct rb_method_alias_struct {
    struct rb_method_entry_struct * original_me;
} rb_method_alias_t;

typedef struct rb_method_refined_struct {
    struct rb_method_entry_struct * orig_me;
    VALUE owner;
} rb_method_refined_t;

typedef struct rb_method_bmethod_struct {
    VALUE proc;
    struct rb_hook_list_struct *hooks;
} rb_method_bmethod_t;

enum method_optimized_type {
    OPTIMIZED_METHOD_TYPE_SEND,
    OPTIMIZED_METHOD_TYPE_CALL,
    OPTIMIZED_METHOD_TYPE_BLOCK_CALL,
    OPTIMIZED_METHOD_TYPE__MAX
};

struct rb_method_definition_struct {
    rb_method_type_t type : 4;
    int alias_count : 28;
    int complemented_count : 28;

    union {
        rb_method_iseq_t iseq;
        rb_method_cfunc_t cfunc;
        rb_method_attr_t attr;
        rb_method_alias_t alias;
        rb_method_refined_t refined;
        rb_method_bmethod_t bmethod;

        enum method_optimized_type optimize_type;
    } body;

    ID original_id;
    uintptr_t method_serial;
};

typedef struct rb_method_definition_struct rb_method_definition_t;
__extension__ _Static_assert(__builtin_offsetof(rb_method_definition_t, body)==8, "sizeof_method_def" ": " "offsetof(rb_method_definition_t, body)==8");




void rb_add_method_cfunc(VALUE klass, ID mid, VALUE (*func)(), int argc, rb_method_visibility_t visi);
void rb_add_method_iseq(VALUE klass, ID mid, const rb_iseq_t *iseq, rb_cref_t *cref, rb_method_visibility_t visi);
void rb_add_refined_method_entry(VALUE refined_class, ID mid);
void rb_add_method(VALUE klass, ID mid, rb_method_type_t type, void *option, rb_method_visibility_t visi);

rb_method_entry_t *rb_method_entry_set(VALUE klass, ID mid, const rb_method_entry_t *, rb_method_visibility_t noex);
rb_method_entry_t *rb_method_entry_create(ID called_id, VALUE klass, rb_method_visibility_t visi, const rb_method_definition_t *def);

const rb_method_entry_t *rb_method_entry_at(VALUE obj, ID id);

const rb_method_entry_t *rb_method_entry(VALUE klass, ID id);
const rb_method_entry_t *rb_method_entry_with_refinements(VALUE klass, ID id, VALUE *defined_class);
const rb_method_entry_t *rb_method_entry_without_refinements(VALUE klass, ID id, VALUE *defined_class);
const rb_method_entry_t *rb_resolve_refined_method(VALUE refinements, const rb_method_entry_t *me);
const rb_method_entry_t *rb_resolve_me_location(const rb_method_entry_t *, VALUE[5]);

const rb_callable_method_entry_t *rb_callable_method_entry(VALUE klass, ID id);
const rb_callable_method_entry_t *rb_callable_method_entry_with_refinements(VALUE klass, ID id, VALUE *defined_class);
const rb_callable_method_entry_t *rb_callable_method_entry_without_refinements(VALUE klass, ID id, VALUE *defined_class);

int rb_method_entry_arity(const rb_method_entry_t *me);
int rb_method_entry_eq(const rb_method_entry_t *m1, const rb_method_entry_t *m2);
st_index_t rb_hash_method_entry(st_index_t hash, const rb_method_entry_t *me);

VALUE rb_method_entry_location(const rb_method_entry_t *me);

void rb_free_method_entry(const rb_method_entry_t *me);

const rb_method_entry_t *rb_method_entry_clone(const rb_method_entry_t *me);
const rb_callable_method_entry_t *rb_method_entry_complement_defined_class(const rb_method_entry_t *src_me, ID called_id, VALUE defined_class);
void rb_method_entry_copy(rb_method_entry_t *dst, const rb_method_entry_t *src);

void rb_scope_visibility_set(rb_method_visibility_t);

VALUE rb_unnamed_parameters(int arity);




typedef unsigned int rb_atomic_t;






























void __assert_rtn(const char *, const char *, int, const char *) __attribute__((__noreturn__)) __attribute__((__cold__)) __attribute__((__disable_tail_calls__));














static inline char *container_of_or_null_(void *member_ptr, size_t offset)
{
 return member_ptr ? (char *)member_ptr - offset : ((void*)0);
}
struct list_node
{
 struct list_node *next, *prev;
};
struct list_head
{
 struct list_node n;
};

static inline void list_head_init(struct list_head *h)
{
 h->n.next = h->n.prev = &h->n;
}
static inline void list_node_init(struct list_node *n)
{
 n->next = n->prev = n;
}
static inline void list_add_after_(struct list_head *h,
       struct list_node *p,
       struct list_node *n,
       const char *abortstr)
{
 n->next = p->next;
 n->prev = p;
 p->next->prev = n;
 p->next = n;
 (void)((void)abortstr, h);
}
static inline void list_add_(struct list_head *h,
        struct list_node *n,
        const char *abortstr)
{
 list_add_after_(h, &h->n, n, abortstr);
}
static inline void list_add_before_(struct list_head *h,
        struct list_node *p,
        struct list_node *n,
        const char *abortstr)
{
 n->next = p;
 n->prev = p->prev;
 p->prev->next = n;
 p->prev = n;
 (void)((void)abortstr, h);
}
static inline void list_add_tail_(struct list_head *h,
      struct list_node *n,
      const char *abortstr)
{
 list_add_before_(h, &h->n, n, abortstr);
}
static inline int list_empty_(const struct list_head *h, const char* abortstr)
{
 (void)((void)abortstr, h);
 return h->n.next == &h->n;
}
static inline _Bool list_empty_nocheck(const struct list_head *h)
{
 return h->n.next == &h->n;
}
static inline void list_del_(struct list_node *n, const char* abortstr)
{
 (void)((void)abortstr, n);
 n->next->prev = n->prev;
 n->prev->next = n->next;




}
static inline void list_del_init_(struct list_node *n, const char *abortstr)
{
 list_del_(n, abortstr);
 list_node_init(n);
}
static inline void list_del_from(struct list_head *h, struct list_node *n)
{
 (__builtin_expect(!(!list_empty_(h, "./ccan/list/list.h" ":" "328")), 0) ? __assert_rtn(__func__, "./ccan/list/list.h", 328, "!list_empty(h)") : (void)0);
 list_del_(n, "./ccan/list/list.h" ":" "329");
}
static inline void list_swap_(struct list_node *o,
         struct list_node *n,
         const char* abortstr)
{
 (void)((void)abortstr, o);
 *n = *o;
 n->next->prev = n;
 n->prev->next = n;




}


static inline const void *list_top_(const struct list_head *h, size_t off)
{
 if (list_empty_(h, "./ccan/list/list.h" ":" "399"))
  return ((void*)0);
 return (const char *)h->n.next - off;
}


static inline const void *list_pop_(const struct list_head *h, size_t off)
{
 struct list_node *n;

 if (list_empty_(h, "./ccan/list/list.h" ":" "425"))
  return ((void*)0);
 n = h->n.next;
 list_del_(n, "./ccan/list/list.h" ":" "428");
 return (const char *)n - off;
}


static inline const void *list_tail_(const struct list_head *h, size_t off)
{
 if (list_empty_(h, "./ccan/list/list.h" ":" "451"))
  return ((void*)0);
 return (const char *)h->n.prev - off;
}

static inline void list_append_list_(struct list_head *to,
         struct list_head *from,
         const char *abortstr)
{
 struct list_node *from_tail = ((void)abortstr, from)->n.prev;
 struct list_node *to_tail = ((void)abortstr, to)->n.prev;


 to->n.prev = from_tail;
 from_tail->next = &to->n;
 to_tail->next = &from->n;
 from->n.prev = to_tail;


 list_del_(&from->n, "./ccan/list/list.h" ":" "600");
 list_head_init(from);
}
static inline void list_prepend_list_(struct list_head *to,
          struct list_head *from,
          const char *abortstr)
{
 struct list_node *from_tail = ((void)abortstr, from)->n.prev;
 struct list_node *to_head = ((void)abortstr, to)->n.next;


 to->n.next = &from->n;
 from->n.prev = &to->n;
 to_head->prev = from_tail;
 from_tail->next = to_head;


 list_del_(&from->n, "./ccan/list/list.h" ":" "632");
 list_head_init(from);
}
























static inline void *list_node_to_off_(struct list_node *node, size_t off)
{
 return (void *)((char *)node - off);
}
static inline struct list_node *list_node_from_off_(void *ptr, size_t off)
{
 return (struct list_node *)((char *)ptr + off);
}














static inline void *list_entry_or_null(const struct list_head *h,
           const struct list_node *n,
           size_t off)
{
 if (n == &h->n)
  return ((void*)0);
 return (char *)n - off;
}


































struct sched_param { int sched_priority; char __opaque[4]; };




extern int sched_yield(void);
extern int sched_get_priority_min(int);
extern int sched_get_priority_max(int);
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
 long tm_gmtoff;
 char *tm_zone;
};









extern char *tzname[];


extern int getdate_err;

extern long timezone __asm("_" "timezone" );

extern int daylight;


char *asctime(const struct tm *);
clock_t clock(void) __asm("_" "clock" );
char *ctime(const time_t *);
double difftime(time_t, time_t);
struct tm *getdate(const char *);
struct tm *gmtime(const time_t *);
struct tm *localtime(const time_t *);
time_t mktime(struct tm *) __asm("_" "mktime" );
size_t strftime(char * __restrict, size_t, const char * __restrict, const struct tm * __restrict) __asm("_" "strftime" );
char *strptime(const char * __restrict, const char * __restrict, struct tm * __restrict) __asm("_" "strptime" );
time_t time(time_t *);


void tzset(void);



char *asctime_r(const struct tm * __restrict, char * __restrict);
char *ctime_r(const time_t *, char *);
struct tm *gmtime_r(const time_t * __restrict, struct tm * __restrict);
struct tm *localtime_r(const time_t * __restrict, struct tm * __restrict);


time_t posix2time(time_t);



void tzsetwall(void);
time_t time2posix(time_t);
time_t timelocal(struct tm * const);
time_t timegm(struct tm * const);



int nanosleep(const struct timespec *__rqtp, struct timespec *__rmtp) __asm("_" "nanosleep" );









typedef enum {
_CLOCK_REALTIME __attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,introduced=10.0))) __attribute__((availability(tvos,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0))) = 0,
_CLOCK_MONOTONIC __attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,introduced=10.0))) __attribute__((availability(tvos,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0))) = 6,

_CLOCK_MONOTONIC_RAW __attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,introduced=10.0))) __attribute__((availability(tvos,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0))) = 4,
_CLOCK_MONOTONIC_RAW_APPROX __attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,introduced=10.0))) __attribute__((availability(tvos,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0))) = 5,
_CLOCK_UPTIME_RAW __attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,introduced=10.0))) __attribute__((availability(tvos,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0))) = 8,
_CLOCK_UPTIME_RAW_APPROX __attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,introduced=10.0))) __attribute__((availability(tvos,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0))) = 9,

_CLOCK_PROCESS_CPUTIME_ID __attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,introduced=10.0))) __attribute__((availability(tvos,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0))) = 12,
_CLOCK_THREAD_CPUTIME_ID __attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,introduced=10.0))) __attribute__((availability(tvos,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0))) = 16
} clockid_t;

__attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,introduced=10.0))) __attribute__((availability(tvos,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0)))
int clock_getres(clockid_t __clock_id, struct timespec *__res);

__attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,introduced=10.0))) __attribute__((availability(tvos,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0)))
int clock_gettime(clockid_t __clock_id, struct timespec *__tp);


__attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,introduced=10.0))) __attribute__((availability(tvos,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0)))
__uint64_t clock_gettime_nsec_np(clockid_t __clock_id);


__attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,unavailable)))
__attribute__((availability(tvos,unavailable))) __attribute__((availability(watchos,unavailable)))
int clock_settime(clockid_t __clock_id, const struct timespec *__tp);




enum { QOS_CLASS_USER_INTERACTIVE __attribute__((availability(macos,introduced=10.10))) __attribute__((availability(ios,introduced=8.0))) = 0x21, QOS_CLASS_USER_INITIATED __attribute__((availability(macos,introduced=10.10))) __attribute__((availability(ios,introduced=8.0))) = 0x19, QOS_CLASS_DEFAULT __attribute__((availability(macos,introduced=10.10))) __attribute__((availability(ios,introduced=8.0))) = 0x15, QOS_CLASS_UTILITY __attribute__((availability(macos,introduced=10.10))) __attribute__((availability(ios,introduced=8.0))) = 0x11, QOS_CLASS_BACKGROUND __attribute__((availability(macos,introduced=10.10))) __attribute__((availability(ios,introduced=8.0))) = 0x09, QOS_CLASS_UNSPECIFIED __attribute__((availability(macos,introduced=10.10))) __attribute__((availability(ios,introduced=8.0))) = 0x00, }; typedef unsigned int qos_class_t;







__attribute__((availability(macos,introduced=10.10))) __attribute__((availability(ios,introduced=8.0)))
qos_class_t
qos_class_self(void);
__attribute__((availability(macos,introduced=10.10))) __attribute__((availability(ios,introduced=8.0)))
qos_class_t
qos_class_main(void);




__attribute__((availability(macos,introduced=10.10))) __attribute__((availability(ios,introduced=8.0)))
int
pthread_attr_set_qos_class_np(pthread_attr_t *__attr,
  qos_class_t __qos_class, int __relative_priority);
__attribute__((availability(macos,introduced=10.10))) __attribute__((availability(ios,introduced=8.0)))
int
pthread_attr_get_qos_class_np(pthread_attr_t * __restrict __attr,
  qos_class_t * _Nullable __restrict __qos_class,
  int * _Nullable __restrict __relative_priority);
__attribute__((availability(macos,introduced=10.10))) __attribute__((availability(ios,introduced=8.0)))
int
pthread_set_qos_class_self_np(qos_class_t __qos_class,
  int __relative_priority);
__attribute__((availability(macos,introduced=10.10))) __attribute__((availability(ios,introduced=8.0)))
int
pthread_get_qos_class_np(pthread_t __pthread,
  qos_class_t * _Nullable __restrict __qos_class,
  int * _Nullable __restrict __relative_priority);
typedef struct pthread_override_s* pthread_override_t;
__attribute__((availability(macos,introduced=10.10))) __attribute__((availability(ios,introduced=8.0)))
pthread_override_t
pthread_override_qos_class_start_np(pthread_t __pthread,
  qos_class_t __qos_class, int __relative_priority);
__attribute__((availability(macos,introduced=10.10))) __attribute__((availability(ios,introduced=8.0)))
int
pthread_override_qos_class_end_np(pthread_override_t __override);




typedef __darwin_mach_port_t mach_port_t;












































__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))
int pthread_atfork(void (* _Nullable)(void), void (* _Nullable)(void),
  void (* _Nullable)(void));

__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))
int pthread_attr_destroy(pthread_attr_t *);

__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))
int pthread_attr_getdetachstate(const pthread_attr_t *, int *);

__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))
int pthread_attr_getguardsize(const pthread_attr_t * __restrict, size_t * __restrict);

__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))
int pthread_attr_getinheritsched(const pthread_attr_t * __restrict, int * __restrict);

__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))
int pthread_attr_getschedparam(const pthread_attr_t * __restrict,
  struct sched_param * __restrict);

__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))
int pthread_attr_getschedpolicy(const pthread_attr_t * __restrict, int * __restrict);

__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))
int pthread_attr_getscope(const pthread_attr_t * __restrict, int * __restrict);

__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))
int pthread_attr_getstack(const pthread_attr_t * __restrict,
  void * _Nullable * _Nonnull __restrict, size_t * __restrict);

__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))
int pthread_attr_getstackaddr(const pthread_attr_t * __restrict,
  void * _Nullable * _Nonnull __restrict);

__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))
int pthread_attr_getstacksize(const pthread_attr_t * __restrict, size_t * __restrict);

__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))
int pthread_attr_init(pthread_attr_t *);

__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))
int pthread_attr_setdetachstate(pthread_attr_t *, int);

__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))
int pthread_attr_setguardsize(pthread_attr_t *, size_t);

__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))
int pthread_attr_setinheritsched(pthread_attr_t *, int);

__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))
int pthread_attr_setschedparam(pthread_attr_t * __restrict,
  const struct sched_param * __restrict);

__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))
int pthread_attr_setschedpolicy(pthread_attr_t *, int);

__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))
int pthread_attr_setscope(pthread_attr_t *, int);

__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))
int pthread_attr_setstack(pthread_attr_t *, void *, size_t);

__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))
int pthread_attr_setstackaddr(pthread_attr_t *, void *);

__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))
int pthread_attr_setstacksize(pthread_attr_t *, size_t);

__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))
int pthread_cancel(pthread_t) __asm("_" "pthread_cancel" );

__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))
int pthread_cond_broadcast(pthread_cond_t *);

__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))
int pthread_cond_destroy(pthread_cond_t *);

__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))
int pthread_cond_init(
  pthread_cond_t * __restrict,
  const pthread_condattr_t * _Nullable __restrict)
  __asm("_" "pthread_cond_init" );

__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))
int pthread_cond_signal(pthread_cond_t *);

__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))
int pthread_cond_timedwait(
  pthread_cond_t * __restrict, pthread_mutex_t * __restrict,
  const struct timespec * _Nullable __restrict)
  __asm("_" "pthread_cond_timedwait" );

__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))
int pthread_cond_wait(pthread_cond_t * __restrict,
  pthread_mutex_t * __restrict) __asm("_" "pthread_cond_wait" );

__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))
int pthread_condattr_destroy(pthread_condattr_t *);

__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))
int pthread_condattr_init(pthread_condattr_t *);

__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))
int pthread_condattr_getpshared(const pthread_condattr_t * __restrict,
  int * __restrict);

__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))
int pthread_condattr_setpshared(pthread_condattr_t *, int);

__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))

int pthread_create(pthread_t _Nullable * _Nonnull __restrict,
  const pthread_attr_t * _Nullable __restrict,
  void * _Nullable (* _Nonnull)(void * _Nullable),
  void * _Nullable __restrict);






__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))
int pthread_detach(pthread_t);

__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))
int pthread_equal(pthread_t _Nullable, pthread_t _Nullable);

__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))
void pthread_exit(void * _Nullable) __attribute__((__noreturn__));

__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))
int pthread_getconcurrency(void);

__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))
int pthread_getschedparam(pthread_t , int * _Nullable __restrict,
  struct sched_param * _Nullable __restrict);

__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))
void* _Nullable pthread_getspecific(pthread_key_t);

__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))
int pthread_join(pthread_t , void * _Nullable * _Nullable)
  __asm("_" "pthread_join" );

__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))
int pthread_key_create(pthread_key_t *, void (* _Nullable)(void *));

__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))
int pthread_key_delete(pthread_key_t);

__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))
int pthread_mutex_destroy(pthread_mutex_t *);

__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))
int pthread_mutex_getprioceiling(const pthread_mutex_t * __restrict,
  int * __restrict);

__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))
int pthread_mutex_init(pthread_mutex_t * __restrict,
  const pthread_mutexattr_t * _Nullable __restrict);

__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))
int pthread_mutex_lock(pthread_mutex_t *);

__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))
int pthread_mutex_setprioceiling(pthread_mutex_t * __restrict, int,
  int * __restrict);

__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))
int pthread_mutex_trylock(pthread_mutex_t *);

__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))
int pthread_mutex_unlock(pthread_mutex_t *);

__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))
int pthread_mutexattr_destroy(pthread_mutexattr_t *) __asm("_" "pthread_mutexattr_destroy" );

__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))
int pthread_mutexattr_getprioceiling(const pthread_mutexattr_t * __restrict,
  int * __restrict);

__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))
int pthread_mutexattr_getprotocol(const pthread_mutexattr_t * __restrict,
  int * __restrict);

__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))
int pthread_mutexattr_getpshared(const pthread_mutexattr_t * __restrict,
  int * __restrict);

__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))
int pthread_mutexattr_gettype(const pthread_mutexattr_t * __restrict,
  int * __restrict);

__attribute__((availability(macos,introduced=10.13.4))) __attribute__((availability(ios,introduced=11.3))) __attribute__((availability(watchos,introduced=4.3))) __attribute__((availability(tvos,introduced=11.3)))
int pthread_mutexattr_getpolicy_np(const pthread_mutexattr_t * __restrict,
  int * __restrict);

__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))
int pthread_mutexattr_init(pthread_mutexattr_t *);

__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))
int pthread_mutexattr_setprioceiling(pthread_mutexattr_t *, int);

__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))
int pthread_mutexattr_setprotocol(pthread_mutexattr_t *, int);

__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))
int pthread_mutexattr_setpshared(pthread_mutexattr_t *, int);

__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))
int pthread_mutexattr_settype(pthread_mutexattr_t *, int);

__attribute__((availability(macos,introduced=10.7))) __attribute__((availability(ios,introduced=5.0)))
int pthread_mutexattr_setpolicy_np(pthread_mutexattr_t *, int);

__attribute__((availability(swift,unavailable,message="Use lazily initialized globals instead")))
__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))
int pthread_once(pthread_once_t *, void (* _Nonnull)(void));

__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))
int pthread_rwlock_destroy(pthread_rwlock_t * ) __asm("_" "pthread_rwlock_destroy" );

__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))
int pthread_rwlock_init(pthread_rwlock_t * __restrict,
  const pthread_rwlockattr_t * _Nullable __restrict)
  __asm("_" "pthread_rwlock_init" );

__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))
int pthread_rwlock_rdlock(pthread_rwlock_t *) __asm("_" "pthread_rwlock_rdlock" );

__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))
int pthread_rwlock_tryrdlock(pthread_rwlock_t *) __asm("_" "pthread_rwlock_tryrdlock" );

__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))
int pthread_rwlock_trywrlock(pthread_rwlock_t *) __asm("_" "pthread_rwlock_trywrlock" );

__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))
int pthread_rwlock_wrlock(pthread_rwlock_t *) __asm("_" "pthread_rwlock_wrlock" );

__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))
int pthread_rwlock_unlock(pthread_rwlock_t *) __asm("_" "pthread_rwlock_unlock" );

__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))
int pthread_rwlockattr_destroy(pthread_rwlockattr_t *);

__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))
int pthread_rwlockattr_getpshared(const pthread_rwlockattr_t * __restrict,
  int * __restrict);

__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))
int pthread_rwlockattr_init(pthread_rwlockattr_t *);

__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))
int pthread_rwlockattr_setpshared(pthread_rwlockattr_t *, int);

__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))
pthread_t pthread_self(void);

__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))
int pthread_setcancelstate(int , int * _Nullable)
  __asm("_" "pthread_setcancelstate" );

__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))
int pthread_setcanceltype(int , int * _Nullable)
  __asm("_" "pthread_setcanceltype" );

__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))
int pthread_setconcurrency(int);

__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))
int pthread_setschedparam(pthread_t, int, const struct sched_param *);

__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))
int pthread_setspecific(pthread_key_t , const void * _Nullable);

__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))
void pthread_testcancel(void) __asm("_" "pthread_testcancel" );




__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))
int pthread_is_threaded_np(void);

__attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=3.2)))
int pthread_threadid_np(pthread_t _Nullable,__uint64_t* _Nullable);


__attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=3.2)))
int pthread_getname_np(pthread_t,char*,size_t);

__attribute__((availability(macos,introduced=10.6))) __attribute__((availability(ios,introduced=3.2)))
int pthread_setname_np(const char*);


__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))
int pthread_main_np(void);


__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))
mach_port_t pthread_mach_thread_np(pthread_t);

__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))
size_t pthread_get_stacksize_np(pthread_t);

__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))
void* pthread_get_stackaddr_np(pthread_t);


__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))
int pthread_cond_signal_thread_np(pthread_cond_t *, pthread_t _Nullable);


__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))
int pthread_cond_timedwait_relative_np(pthread_cond_t *, pthread_mutex_t *,
  const struct timespec * _Nullable);


__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))

int pthread_create_suspended_np(
  pthread_t _Nullable * _Nonnull, const pthread_attr_t * _Nullable,
  void * _Nullable (* _Nonnull)(void * _Nullable), void * _Nullable);





__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))
int pthread_kill(pthread_t, int);

__attribute__((availability(macos,introduced=10.5))) __attribute__((availability(ios,introduced=2.0)))
_Nullable pthread_t pthread_from_mach_thread_np(mach_port_t);

__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))
int pthread_sigmask(int, const sigset_t * _Nullable, sigset_t * _Nullable)
  __asm("_" "pthread_sigmask" );

__attribute__((availability(macos,introduced=10.4))) __attribute__((availability(ios,introduced=2.0)))
void pthread_yield_np(void);

__attribute__((availability(macos,introduced=11.0)))
__attribute__((availability(ios,unavailable))) __attribute__((availability(tvos,unavailable))) __attribute__((availability(watchos,unavailable)))
void pthread_jit_write_protect_np(int enabled);

__attribute__((availability(macos,introduced=11.0)))
__attribute__((availability(ios,unavailable))) __attribute__((availability(tvos,unavailable))) __attribute__((availability(watchos,unavailable)))
int pthread_jit_write_protect_supported_np(void);
__attribute__((availability(macos,introduced=11.0))) __attribute__((availability(ios,introduced=14.2))) __attribute__((availability(tvos,introduced=14.2))) __attribute__((availability(watchos,introduced=7.1)))
int
pthread_cpu_number_np(size_t *cpu_number_out);
typedef pthread_t rb_nativethread_id_t;
typedef pthread_mutex_t rb_nativethread_lock_t;







rb_nativethread_id_t rb_nativethread_self();

void rb_nativethread_lock_initialize(rb_nativethread_lock_t *lock);
void rb_nativethread_lock_destroy(rb_nativethread_lock_t *lock);
void rb_nativethread_lock_lock(rb_nativethread_lock_t *lock);
void rb_nativethread_lock_unlock(rb_nativethread_lock_t *lock);










typedef pthread_cond_t rb_nativethread_cond_t;

typedef struct native_thread_data_struct {
    union {
        struct list_node ubf;
        struct list_node gvl;
    } node;







    struct

    {
        rb_nativethread_cond_t intr;
        rb_nativethread_cond_t gvlq;
    } cond;
} native_thread_data_t;


typedef struct rb_global_vm_lock_struct {

    const struct rb_thread_struct *owner;
    rb_nativethread_lock_t lock;
    struct list_head waitq;
    const struct rb_thread_struct *timer;
    int timer_err;


    rb_nativethread_cond_t switch_cond;
    rb_nativethread_cond_t switch_wait_cond;
    int need_yield;
    int wait_yield;
} rb_global_vm_lock_t;



typedef int jmp_buf[((14 + 8 + 2) * 2)];
typedef int sigjmp_buf[((14 + 8 + 2) * 2) + 1];






extern int setjmp(jmp_buf);
extern void longjmp(jmp_buf, int) __attribute__((__noreturn__));


int _setjmp(jmp_buf);
void _longjmp(jmp_buf, int) __attribute__((__noreturn__));
int sigsetjmp(sigjmp_buf, int);
void siglongjmp(sigjmp_buf, int) __attribute__((__noreturn__));



void longjmperror(void);
extern const char *const sys_signame[32];
extern const char *const sys_siglist[32];



int raise(int);




void (* _Nullable bsd_signal(int, void (* _Nullable)(int)))(int);
int kill(pid_t, int) __asm("_" "kill" );
int killpg(pid_t, int) __asm("_" "killpg" );
int pthread_kill(pthread_t, int);
int pthread_sigmask(int, const sigset_t *, sigset_t *) __asm("_" "pthread_sigmask" );
int sigaction(int, const struct sigaction * __restrict,
     struct sigaction * __restrict);
int sigaddset(sigset_t *, int);
int sigaltstack(const stack_t * __restrict, stack_t * __restrict) __asm("_" "sigaltstack" ) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));
int sigdelset(sigset_t *, int);
int sigemptyset(sigset_t *);
int sigfillset(sigset_t *);
int sighold(int);
int sigignore(int);
int siginterrupt(int, int);
int sigismember(const sigset_t *, int);
int sigpause(int) __asm("_" "sigpause" );
int sigpending(sigset_t *);
int sigprocmask(int, const sigset_t * __restrict, sigset_t * __restrict);
int sigrelse(int);
void (* _Nullable sigset(int, void (* _Nullable)(int)))(int);
int sigsuspend(const sigset_t *) __asm("_" "sigsuspend" );
int sigwait(const sigset_t * __restrict, int * __restrict) __asm("_" "sigwait" );

void psignal(unsigned int, const char *);
int sigblock(int);
int sigsetmask(int);
int sigvec(int, struct sigvec *, struct sigvec *);




inline __attribute__ ((__always_inline__)) int
__sigbits(int __signo)
{
    return __signo > 32 ? 0 : (1 << (__signo - 1));
}

























void *rb_register_sigaltstack(void);
void rb_vm_encoded_insn_data_table_init(void);
typedef unsigned long rb_num_t;
typedef signed long rb_snum_t;

enum ruby_tag_type {
    RUBY_TAG_NONE = 0x0,
    RUBY_TAG_RETURN = 0x1,
    RUBY_TAG_BREAK = 0x2,
    RUBY_TAG_NEXT = 0x3,
    RUBY_TAG_RETRY = 0x4,
    RUBY_TAG_REDO = 0x5,
    RUBY_TAG_RAISE = 0x6,
    RUBY_TAG_THROW = 0x7,
    RUBY_TAG_FATAL = 0x8,
    RUBY_TAG_MASK = 0xf
};


enum ruby_vm_throw_flags {
    VM_THROW_NO_ESCAPE_FLAG = 0x8000,
    VM_THROW_STATE_MASK = 0xff
};


struct rb_thread_struct;
struct rb_control_frame_struct;


typedef struct rb_compile_option_struct rb_compile_option_t;

struct iseq_inline_cache_entry {
    rb_serial_t ic_serial;
    const rb_cref_t *ic_cref;
    VALUE value;
};

struct iseq_inline_iv_cache_entry {
    rb_serial_t ic_serial;
    size_t index;
};

union iseq_inline_storage_entry {
    struct {
 struct rb_thread_struct *running_thread;
 VALUE value;
    } once;
    struct iseq_inline_cache_entry cache;
    struct iseq_inline_iv_cache_entry iv_cache;
};

struct rb_call_info_kw_arg {
    int keyword_len;
    VALUE keywords[1];
};

struct rb_call_info_with_kwarg {
    struct rb_call_info ci;
    struct rb_call_info_kw_arg *kw_arg;
};

struct rb_calling_info {
    VALUE block_handler;
    VALUE recv;
    int argc;
    int kw_splat;
};

struct rb_kwarg_call_data {
    struct rb_call_cache cc;
    struct rb_call_info_with_kwarg ci_kw;
};

struct rb_execution_context_struct;
typedef VALUE (*vm_call_handler)(struct rb_execution_context_struct *ec, struct rb_control_frame_struct *cfp, struct rb_calling_info *calling, struct rb_call_data *cd);






typedef struct rb_iseq_location_struct {
    VALUE pathobj;
    VALUE base_label;
    VALUE label;
    VALUE first_lineno;
    int node_id;
    rb_code_location_t code_location;
} rb_iseq_location_t;


static inline VALUE
pathobj_path(VALUE pathobj)
{
    if (( ((RUBY_T_STRING) == RUBY_T_FIXNUM) ? (((int)(long)(pathobj))&RUBY_FIXNUM_FLAG) : ((RUBY_T_STRING) == RUBY_T_TRUE) ? ((pathobj) == ((VALUE)RUBY_Qtrue)) : ((RUBY_T_STRING) == RUBY_T_FALSE) ? ((pathobj) == ((VALUE)RUBY_Qfalse)) : ((RUBY_T_STRING) == RUBY_T_NIL) ? ((pathobj) == ((VALUE)RUBY_Qnil)) : ((RUBY_T_STRING) == RUBY_T_UNDEF) ? ((pathobj) == ((VALUE)RUBY_Qundef)) : ((RUBY_T_STRING) == RUBY_T_SYMBOL) ? ((((VALUE)(pathobj)&~((~(VALUE)0)<<RUBY_SPECIAL_SHIFT)) == RUBY_SYMBOL_FLAG)||(!(((VALUE)(pathobj) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(pathobj) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(pathobj))->flags & RUBY_T_MASK) == (RUBY_T_SYMBOL))) : ((RUBY_T_STRING) == RUBY_T_FLOAT) ? ( ((((int)(long)(pathobj))&RUBY_FLONUM_MASK) == RUBY_FLONUM_FLAG) || (!(((VALUE)(pathobj) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(pathobj) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(pathobj))->flags & RUBY_T_MASK) == RUBY_T_FLOAT)) : (!(((VALUE)(pathobj) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(pathobj) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(pathobj))->flags & RUBY_T_MASK) == (RUBY_T_STRING)))) {
 return pathobj;
    }
    else {
 ((void)0);
 return (rb_array_const_ptr_transient(pathobj)[0]);
    }
}

static inline VALUE
pathobj_realpath(VALUE pathobj)
{
    if (( ((RUBY_T_STRING) == RUBY_T_FIXNUM) ? (((int)(long)(pathobj))&RUBY_FIXNUM_FLAG) : ((RUBY_T_STRING) == RUBY_T_TRUE) ? ((pathobj) == ((VALUE)RUBY_Qtrue)) : ((RUBY_T_STRING) == RUBY_T_FALSE) ? ((pathobj) == ((VALUE)RUBY_Qfalse)) : ((RUBY_T_STRING) == RUBY_T_NIL) ? ((pathobj) == ((VALUE)RUBY_Qnil)) : ((RUBY_T_STRING) == RUBY_T_UNDEF) ? ((pathobj) == ((VALUE)RUBY_Qundef)) : ((RUBY_T_STRING) == RUBY_T_SYMBOL) ? ((((VALUE)(pathobj)&~((~(VALUE)0)<<RUBY_SPECIAL_SHIFT)) == RUBY_SYMBOL_FLAG)||(!(((VALUE)(pathobj) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(pathobj) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(pathobj))->flags & RUBY_T_MASK) == (RUBY_T_SYMBOL))) : ((RUBY_T_STRING) == RUBY_T_FLOAT) ? ( ((((int)(long)(pathobj))&RUBY_FLONUM_MASK) == RUBY_FLONUM_FLAG) || (!(((VALUE)(pathobj) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(pathobj) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(pathobj))->flags & RUBY_T_MASK) == RUBY_T_FLOAT)) : (!(((VALUE)(pathobj) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(pathobj) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(pathobj))->flags & RUBY_T_MASK) == (RUBY_T_STRING)))) {
 return pathobj;
    }
    else {
 ((void)0);
 return (rb_array_const_ptr_transient(pathobj)[1]);
    }
}


struct rb_mjit_unit;

struct rb_iseq_constant_body {
    enum iseq_type {
 ISEQ_TYPE_TOP,
 ISEQ_TYPE_METHOD,
 ISEQ_TYPE_BLOCK,
 ISEQ_TYPE_CLASS,
 ISEQ_TYPE_RESCUE,
 ISEQ_TYPE_ENSURE,
 ISEQ_TYPE_EVAL,
 ISEQ_TYPE_MAIN,
 ISEQ_TYPE_PLAIN
    } type;

    unsigned int iseq_size;
    VALUE *iseq_encoded;
    struct {
 struct {
     unsigned int has_lead : 1;
     unsigned int has_opt : 1;
     unsigned int has_rest : 1;
     unsigned int has_post : 1;
     unsigned int has_kw : 1;
     unsigned int has_kwrest : 1;
     unsigned int has_block : 1;

     unsigned int ambiguous_param0 : 1;
     unsigned int accepts_no_kwarg : 1;
            unsigned int ruby2_keywords: 1;
 } flags;

 unsigned int size;

 int lead_num;
 int opt_num;
 int rest_start;
 int post_start;
 int post_num;
 int block_start;

 const VALUE *opt_table;
 const struct rb_iseq_param_keyword {
     int num;
     int required_num;
     int bits_start;
     int rest_start;
     const ID *table;
            VALUE *default_values;
 } *keyword;
    } param;

    rb_iseq_location_t location;


    struct iseq_insn_info {
 const struct iseq_insn_info_entry *body;
 unsigned int *positions;
 unsigned int size;

 struct succ_index_table *succ_index_table;

    } insns_info;

    const ID *local_table;


    struct iseq_catch_table *catch_table;


    const struct rb_iseq_struct *parent_iseq;
    struct rb_iseq_struct *local_iseq;

    union iseq_inline_storage_entry *is_entries;
    struct rb_call_data *call_data;






    struct {
 rb_snum_t flip_count;
 VALUE coverage;
        VALUE pc2branchindex;
 VALUE *original_iseq;
    } variable;

    unsigned int local_table_size;
    unsigned int is_size;
    unsigned int ci_size;
    unsigned int ci_kw_size;
    unsigned int stack_max;

    char catch_except_p;



    VALUE (*jit_func)(struct rb_execution_context_struct *,
                      struct rb_control_frame_struct *);
    long unsigned total_calls;
    struct rb_mjit_unit *jit_unit;


    uintptr_t iseq_unique_id;
};



struct rb_iseq_struct {
    VALUE flags;
    VALUE wrapper;

    struct rb_iseq_constant_body *body;

    union {
 struct iseq_compile_data *compile_data;

 struct {
     VALUE obj;
     int index;
 } loader;

        struct {
            struct rb_hook_list_struct *local_hooks;
            rb_event_flag_t global_trace_events;
        } exec;
    } aux;
};








static inline const rb_iseq_t *
rb_iseq_check(const rb_iseq_t *iseq)
{





    return iseq;
}

static inline const rb_iseq_t *
def_iseq_ptr(rb_method_definition_t *def)
{




    return rb_iseq_check(def->body.iseq.iseqptr);
}

enum ruby_special_exceptions {
    ruby_error_reenter,
    ruby_error_nomemory,
    ruby_error_sysstack,
    ruby_error_stackfatal,
    ruby_error_stream_closed,
    ruby_special_error_count
};

enum ruby_basic_operators {
    BOP_PLUS,
    BOP_MINUS,
    BOP_MULT,
    BOP_DIV,
    BOP_MOD,
    BOP_EQ,
    BOP_EQQ,
    BOP_LT,
    BOP_LE,
    BOP_LTLT,
    BOP_AREF,
    BOP_ASET,
    BOP_LENGTH,
    BOP_SIZE,
    BOP_EMPTY_P,
    BOP_NIL_P,
    BOP_SUCC,
    BOP_GT,
    BOP_GE,
    BOP_NOT,
    BOP_NEQ,
    BOP_MATCH,
    BOP_FREEZE,
    BOP_UMINUS,
    BOP_MAX,
    BOP_MIN,
    BOP_CALL,
    BOP_AND,
    BOP_OR,

    BOP_LAST_
};



struct rb_vm_struct;
typedef void rb_vm_at_exit_func(struct rb_vm_struct*);

typedef struct rb_at_exit_list {
    rb_vm_at_exit_func *func;
    struct rb_at_exit_list *next;
} rb_at_exit_list;

struct rb_objspace;
struct rb_objspace *rb_objspace_alloc(void);
void rb_objspace_free(struct rb_objspace *);
void rb_objspace_call_finalizer(struct rb_objspace *);

typedef struct rb_hook_list_struct {
    struct rb_event_hook_struct *hooks;
    rb_event_flag_t events;
    unsigned int need_clean;
    unsigned int running;
} rb_hook_list_t;



typedef const struct rb_builtin_function *RB_BUILTIN;

typedef struct rb_vm_struct {
    VALUE self;

    rb_global_vm_lock_t gvl;

    struct rb_thread_struct *main_thread;


    const struct rb_thread_struct *running_thread;


    void *main_altstack;


    rb_serial_t fork_gen;
    rb_nativethread_lock_t waitpid_lock;
    struct list_head waiting_pids;
    struct list_head waiting_grps;
    struct list_head waiting_fds;
    struct list_head living_threads;
    VALUE thgroup_default;
    int living_thread_num;


    volatile int ubf_async_safe;

    unsigned int running: 1;
    unsigned int thread_abort_on_exception: 1;
    unsigned int thread_report_on_exception: 1;

    unsigned int safe_level_: 1;
    int sleeper;


    VALUE mark_object_ary;
    const VALUE special_exceptions[ruby_special_error_count];


    VALUE top_self;
    VALUE load_path;
    VALUE load_path_snapshot;
    VALUE load_path_check_cache;
    VALUE expanded_load_path;
    VALUE loaded_features;
    VALUE loaded_features_snapshot;
    struct st_table *loaded_features_index;
    struct st_table *loading_table;


    struct {
 VALUE cmd[32];
    } trap_list;


    rb_hook_list_t global_hooks;


    struct st_table *ensure_rollback_table;


    struct rb_postponed_job_struct *postponed_job_buffer;
    int postponed_job_index;

    int src_encoding_index;


    struct list_head workqueue;
    rb_nativethread_lock_t workqueue_lock;

    VALUE verbose, debug, orig_progname, progname;
    VALUE coverages;
    int coverage_mode;

    st_table * defined_module_hash;

    struct rb_objspace *objspace;

    rb_at_exit_list *at_exit;

    VALUE *defined_strings;
    st_table *frozen_strings;

    const struct rb_builtin_function *builtin_function_table;
    int builtin_inline_index;


    struct {
 size_t thread_vm_stack_size;
 size_t thread_machine_stack_size;
 size_t fiber_vm_stack_size;
 size_t fiber_machine_stack_size;
    } default_params;

    short redefined_flag[BOP_LAST_];
} rb_vm_t;

















struct rb_captured_block {
    VALUE self;
    const VALUE *ep;
    union {
 const rb_iseq_t *iseq;
 const struct vm_ifunc *ifunc;
 VALUE val;
    } code;
};

enum rb_block_handler_type {
    block_handler_type_iseq,
    block_handler_type_ifunc,
    block_handler_type_symbol,
    block_handler_type_proc
};

enum rb_block_type {
    block_type_iseq,
    block_type_ifunc,
    block_type_symbol,
    block_type_proc
};

struct rb_block {
    union {
 struct rb_captured_block captured;
 VALUE symbol;
 VALUE proc;
    } as;
    enum rb_block_type type;
};

typedef struct rb_control_frame_struct {
    const VALUE *pc;
    VALUE *sp;
    const rb_iseq_t *iseq;
    VALUE self;
    const VALUE *ep;
    const void *block_code;
    VALUE *__bp__;




} rb_control_frame_t;

extern const rb_data_type_t ruby_threadptr_data_type;

static inline struct rb_thread_struct *
rb_thread_ptr(VALUE thval)
{
    return (struct rb_thread_struct *)rb_check_typeddata(thval, &ruby_threadptr_data_type);
}

enum rb_thread_status {
    THREAD_RUNNABLE,
    THREAD_STOPPED,
    THREAD_STOPPED_FOREVER,
    THREAD_KILLED
};


typedef sigjmp_buf rb_jmpbuf_t;
struct rb_vm_tag {
    VALUE tag;
    VALUE retval;
    rb_jmpbuf_t buf;
    struct rb_vm_tag *prev;
    enum ruby_tag_type state;
};

__extension__ _Static_assert(__builtin_offsetof(struct rb_vm_tag, buf) > 0, "rb_vm_tag_buf_offset" ": " "offsetof(struct rb_vm_tag, buf) > 0");
__extension__ _Static_assert(__builtin_offsetof(struct rb_vm_tag, buf) + sizeof(rb_jmpbuf_t) < sizeof(struct rb_vm_tag), "rb_vm_tag_buf_end" ": " "offsetof(struct rb_vm_tag, buf) + sizeof(rb_jmpbuf_t) < sizeof(struct rb_vm_tag)");



struct rb_vm_protect_tag {
    struct rb_vm_protect_tag *prev;
};

struct rb_unblock_callback {
    rb_unblock_function_t *func;
    void *arg;
};

struct rb_mutex_struct;

typedef struct rb_thread_list_struct{
    struct rb_thread_list_struct *next;
    struct rb_thread_struct *th;
} rb_thread_list_t;

typedef struct rb_ensure_entry {
    VALUE marker;
    VALUE (*e_proc)(VALUE);
    VALUE data2;
} rb_ensure_entry_t;

typedef struct rb_ensure_list {
    struct rb_ensure_list *next;
    struct rb_ensure_entry entry;
} rb_ensure_list_t;

typedef char rb_thread_id_string_t[sizeof(rb_nativethread_id_t) * 2 + 3];

typedef struct rb_fiber_struct rb_fiber_t;

typedef struct rb_execution_context_struct {

    VALUE *vm_stack;
    size_t vm_stack_size;
    rb_control_frame_t *cfp;

    struct rb_vm_tag *tag;
    struct rb_vm_protect_tag *protect_tag;


    rb_atomic_t interrupt_flag;
    rb_atomic_t interrupt_mask;

    rb_fiber_t *fiber_ptr;
    struct rb_thread_struct *thread_ptr;


    st_table *local_storage;
    VALUE local_storage_recursive_hash;
    VALUE local_storage_recursive_hash_for_trace;


    const VALUE *root_lep;
    VALUE root_svar;


    rb_ensure_list_t *ensure_list;


    struct rb_trace_arg_struct *trace_arg;


    VALUE errinfo;
    VALUE passed_block_handler;

    uint8_t raised_flag;


    enum method_missing_reason method_missing_reason : 8;

    VALUE private_const_reference;


    struct {
 VALUE *stack_start;
 VALUE *stack_end;
 size_t stack_maxsize;
 __attribute__((__aligned__(8))) jmp_buf regs;
    } machine;
} rb_execution_context_t;




void rb_ec_set_vm_stack(rb_execution_context_t *ec, VALUE *stack, size_t size);





void rb_ec_initialize_vm_stack(rb_execution_context_t *ec, VALUE *stack, size_t size);



void rb_ec_clear_vm_stack(rb_execution_context_t *ec);

typedef struct rb_thread_struct {
    struct list_node vmlt_node;
    VALUE self;
    rb_vm_t *vm;

    rb_execution_context_t *ec;

    VALUE last_status;


    struct rb_calling_info *calling;


    VALUE top_self;
    VALUE top_wrapper;


    rb_nativethread_id_t thread_id;



    enum rb_thread_status status : 2;

    unsigned int to_kill : 1;
    unsigned int abort_on_exception: 1;
    unsigned int report_on_exception: 1;
    unsigned int pending_interrupt_queue_checked: 1;
    int8_t priority;
    uint32_t running_time_us;

    native_thread_data_t native_thread_data;
    void *blocking_region_buffer;

    VALUE thgroup;
    VALUE value;







    VALUE pending_interrupt_queue;
    VALUE pending_interrupt_mask_stack;


    rb_nativethread_lock_t interrupt_lock;
    struct rb_unblock_callback unblock;
    VALUE locking_mutex;
    struct rb_mutex_struct *keeping_mutexes;

    rb_thread_list_t *join_list;

    union {
        struct {
            VALUE proc;
            VALUE args;
            int kw_splat;
        } proc;
        struct {
            VALUE (*func)(void *);
            void *arg;
        } func;
    } invoke_arg;

    enum {
        thread_invoke_type_none = 0,
        thread_invoke_type_proc,
        thread_invoke_type_func
    } invoke_type;


    VALUE stat_insn_usage;


    rb_fiber_t *root_fiber;
    rb_jmpbuf_t root_jmpbuf;


    VALUE name;

} rb_thread_t;

typedef enum {
    VM_DEFINECLASS_TYPE_CLASS = 0x00,
    VM_DEFINECLASS_TYPE_SINGLETON_CLASS = 0x01,
    VM_DEFINECLASS_TYPE_MODULE = 0x02,

    VM_DEFINECLASS_TYPE_MASK = 0x07
} rb_vm_defineclass_type_t;






rb_iseq_t *rb_iseq_new (const rb_ast_body_t *ast, VALUE name, VALUE path, VALUE realpath, const rb_iseq_t *parent, enum iseq_type);
rb_iseq_t *rb_iseq_new_top (const rb_ast_body_t *ast, VALUE name, VALUE path, VALUE realpath, const rb_iseq_t *parent);
rb_iseq_t *rb_iseq_new_main (const rb_ast_body_t *ast, VALUE path, VALUE realpath, const rb_iseq_t *parent);
rb_iseq_t *rb_iseq_new_with_opt(const rb_ast_body_t *ast, VALUE name, VALUE path, VALUE realpath, VALUE first_lineno,
    const rb_iseq_t *parent, enum iseq_type, const rb_compile_option_t*);
struct iseq_link_anchor;
struct rb_iseq_new_with_callback_callback_func {
    VALUE flags;
    VALUE reserved;
    void (*func)(rb_iseq_t *, struct iseq_link_anchor *, const void *);
    const void *data;
};
static inline struct rb_iseq_new_with_callback_callback_func *
rb_iseq_new_with_callback_new_callback(
    void (*func)(rb_iseq_t *, struct iseq_link_anchor *, const void *), const void *ptr)
{
    VALUE memo = rb_imemo_new(imemo_ifunc, (VALUE)func, (VALUE)ptr, ((VALUE)RUBY_Qundef), ((VALUE)RUBY_Qfalse));
    return (struct rb_iseq_new_with_callback_callback_func *)memo;
}
rb_iseq_t *rb_iseq_new_with_callback(const struct rb_iseq_new_with_callback_callback_func * ifunc,
    VALUE name, VALUE path, VALUE realpath, VALUE first_lineno,
    const rb_iseq_t *parent, enum iseq_type, const rb_compile_option_t*);

VALUE rb_iseq_disasm(const rb_iseq_t *iseq);
int rb_iseq_disasm_insn(VALUE str, const VALUE *iseqval, size_t pos, const rb_iseq_t *iseq, VALUE child);

VALUE rb_iseq_coverage(const rb_iseq_t *iseq);

extern VALUE rb_cISeq;
extern VALUE rb_cRubyVM;
extern VALUE rb_mRubyVMFrozenCore;
extern VALUE rb_block_param_proxy;



typedef struct {
    const struct rb_block block;
    unsigned int is_from_method: 1;
    unsigned int is_lambda: 1;
} rb_proc_t;

typedef struct {
    VALUE flags;
    rb_iseq_t *iseq;
    const VALUE *ep;
    const VALUE *env;
    unsigned int env_size;
} rb_env_t;

extern const rb_data_type_t ruby_binding_data_type;



typedef struct {
    const struct rb_block block;
    const VALUE pathobj;
    unsigned short first_lineno;
} rb_binding_t;



enum vm_check_match_type {
    VM_CHECKMATCH_TYPE_WHEN = 1,
    VM_CHECKMATCH_TYPE_CASE = 2,
    VM_CHECKMATCH_TYPE_RESCUE = 3
};


enum vm_call_flag_bits {
    VM_CALL_ARGS_SPLAT_bit,
    VM_CALL_ARGS_BLOCKARG_bit,
    VM_CALL_FCALL_bit,
    VM_CALL_VCALL_bit,
    VM_CALL_ARGS_SIMPLE_bit,
    VM_CALL_BLOCKISEQ_bit,
    VM_CALL_KWARG_bit,
    VM_CALL_KW_SPLAT_bit,
    VM_CALL_TAILCALL_bit,
    VM_CALL_SUPER_bit,
    VM_CALL_ZSUPER_bit,
    VM_CALL_OPT_SEND_bit,
    VM_CALL__END
};


enum vm_special_object_type {
    VM_SPECIAL_OBJECT_VMCORE = 1,
    VM_SPECIAL_OBJECT_CBASE,
    VM_SPECIAL_OBJECT_CONST_BASE
};

enum vm_svar_index {
    VM_SVAR_LASTLINE = 0,
    VM_SVAR_BACKREF = 1,

    VM_SVAR_EXTRA_START = 2,
    VM_SVAR_FLIPFLOP_START = 2
};


typedef struct iseq_inline_cache_entry *IC;
typedef struct iseq_inline_iv_cache_entry *IVC;
typedef union iseq_inline_storage_entry *ISE;
typedef struct rb_call_info *CALL_INFO;
typedef struct rb_call_cache *CALL_CACHE;
typedef struct rb_call_data *CALL_DATA;

typedef VALUE CDHASH;




typedef rb_control_frame_t *
  (*rb_insn_func_t)(rb_execution_context_t *, rb_control_frame_t *);



enum {
    VM_FRAME_MAGIC_METHOD = 0x11110001,
    VM_FRAME_MAGIC_BLOCK = 0x22220001,
    VM_FRAME_MAGIC_CLASS = 0x33330001,
    VM_FRAME_MAGIC_TOP = 0x44440001,
    VM_FRAME_MAGIC_CFUNC = 0x55550001,
    VM_FRAME_MAGIC_IFUNC = 0x66660001,
    VM_FRAME_MAGIC_EVAL = 0x77770001,
    VM_FRAME_MAGIC_RESCUE = 0x78880001,
    VM_FRAME_MAGIC_DUMMY = 0x79990001,

    VM_FRAME_MAGIC_MASK = 0x7fff0001,


    VM_FRAME_FLAG_PASSED = 0x0010,
    VM_FRAME_FLAG_FINISH = 0x0020,
    VM_FRAME_FLAG_BMETHOD = 0x0040,
    VM_FRAME_FLAG_CFRAME = 0x0080,
    VM_FRAME_FLAG_LAMBDA = 0x0100,
    VM_FRAME_FLAG_MODIFIED_BLOCK_PARAM = 0x0200,
    VM_FRAME_FLAG_CFRAME_KW = 0x0400,
    VM_FRAME_FLAG_CFRAME_EMPTY_KW = 0x0800,


    VM_ENV_FLAG_LOCAL = 0x0002,
    VM_ENV_FLAG_ESCAPED = 0x0004,
    VM_ENV_FLAG_WB_REQUIRED = 0x0008
};




static inline void VM_FORCE_WRITE_SPECIAL_CONST(const VALUE *ptr, VALUE special_const_value);

static inline void
VM_ENV_FLAGS_SET(const VALUE *ep, VALUE flag)
{
    VALUE flags = ep[( 0)];
    ((void)0);
    VM_FORCE_WRITE_SPECIAL_CONST(&ep[( 0)], flags | flag);
}

static inline void
VM_ENV_FLAGS_UNSET(const VALUE *ep, VALUE flag)
{
    VALUE flags = ep[( 0)];
    ((void)0);
    VM_FORCE_WRITE_SPECIAL_CONST(&ep[( 0)], flags & ~flag);
}

static inline unsigned long
VM_ENV_FLAGS(const VALUE *ep, long flag)
{
    VALUE flags = ep[( 0)];
    ((void)0);
    return flags & flag;
}

static inline unsigned long
VM_FRAME_TYPE(const rb_control_frame_t *cfp)
{
    return VM_ENV_FLAGS(cfp->ep, VM_FRAME_MAGIC_MASK);
}

static inline int
VM_FRAME_LAMBDA_P(const rb_control_frame_t *cfp)
{
    return VM_ENV_FLAGS(cfp->ep, VM_FRAME_FLAG_LAMBDA) != 0;
}

static inline int
VM_FRAME_CFRAME_KW_P(const rb_control_frame_t *cfp)
{
    return VM_ENV_FLAGS(cfp->ep, VM_FRAME_FLAG_CFRAME_KW) != 0;
}


static inline int
VM_FRAME_CFRAME_EMPTY_KW_P(const rb_control_frame_t *cfp)
{
    return VM_ENV_FLAGS(cfp->ep, VM_FRAME_FLAG_CFRAME_EMPTY_KW) != 0;
}

static inline int
VM_FRAME_FINISHED_P(const rb_control_frame_t *cfp)
{
    return VM_ENV_FLAGS(cfp->ep, VM_FRAME_FLAG_FINISH) != 0;
}

static inline int
VM_FRAME_BMETHOD_P(const rb_control_frame_t *cfp)
{
    return VM_ENV_FLAGS(cfp->ep, VM_FRAME_FLAG_BMETHOD) != 0;
}

static inline int
rb_obj_is_iseq(VALUE iseq)
{
    return imemo_type_p(iseq, imemo_iseq);
}





static inline int
VM_FRAME_CFRAME_P(const rb_control_frame_t *cfp)
{
    int cframe_p = VM_ENV_FLAGS(cfp->ep, VM_FRAME_FLAG_CFRAME) != 0;
    ((void)0);
    return cframe_p;
}

static inline int
VM_FRAME_RUBYFRAME_P(const rb_control_frame_t *cfp)
{
    return !VM_FRAME_CFRAME_P(cfp);
}




static inline int
VM_ENV_LOCAL_P(const VALUE *ep)
{
    return VM_ENV_FLAGS(ep, VM_ENV_FLAG_LOCAL) ? 1 : 0;
}

static inline const VALUE *
VM_ENV_PREV_EP(const VALUE *ep)
{
    ((void)0);
    return ((void *)(((ep[(-1)])) & ~0x03));
}

static inline VALUE
VM_ENV_BLOCK_HANDLER(const VALUE *ep)
{
    ((void)0);
    return ep[(-1)];
}





static inline int
VM_ENV_ESCAPED_P(const VALUE *ep)
{
    ((void)0);
    return VM_ENV_FLAGS(ep, VM_ENV_FLAG_ESCAPED) ? 1 : 0;
}
static inline VALUE
VM_ENV_ENVVAL(const VALUE *ep)
{
    VALUE envval = ep[( 1)];
    ((void)0);
    ((void)0);
    return envval;
}

static inline const rb_env_t *
VM_ENV_ENVVAL_PTR(const VALUE *ep)
{
    return (const rb_env_t *)VM_ENV_ENVVAL(ep);
}

static inline const rb_env_t *
vm_env_new(VALUE *env_ep, VALUE *env_body, unsigned int env_size, const rb_iseq_t *iseq)
{
    rb_env_t *env = (rb_env_t *)rb_imemo_new(imemo_env, (VALUE)env_ep, (VALUE)env_body, 0, (VALUE)iseq);
    env->env_size = env_size;
    env_ep[( 1)] = (VALUE)env;
    return env;
}

static inline void
VM_FORCE_WRITE(const VALUE *ptr, VALUE v)
{
    *((VALUE *)ptr) = v;
}

static inline void
VM_FORCE_WRITE_SPECIAL_CONST(const VALUE *ptr, VALUE special_const_value)
{
    ((void)0);
    VM_FORCE_WRITE(ptr, special_const_value);
}

static inline void
VM_STACK_ENV_WRITE(const VALUE *ep, int index, VALUE v)
{
    ((void)0);
    VM_FORCE_WRITE(&ep[index], v);
}static inline 

const VALUE *rb_vm_ep_local_ep(const VALUE *ep);
const VALUE *rb_vm_proc_local_ep(VALUE proc);static inline 
void rb_vm_block_ep_update(VALUE obj, const struct rb_block *dst, const VALUE *ep);
void rb_vm_block_copy(VALUE obj, const struct rb_block *dst, const struct rb_block *src);static inline 

VALUE rb_vm_frame_block_handler(const rb_control_frame_t *cfp);




static inline const rb_control_frame_t *
RUBY_VM_END_CONTROL_FRAME(const rb_execution_context_t *ec)
{
    return (rb_control_frame_t *)(ec->vm_stack + ec->vm_stack_size);
}

static inline int
RUBY_VM_CONTROL_FRAME_STACK_OVERFLOW_P(const rb_execution_context_t *ec, const rb_control_frame_t *cfp)
{
    return !((void *)(RUBY_VM_END_CONTROL_FRAME(ec)) > (void *)(cfp));
}

static inline int
VM_BH_ISEQ_BLOCK_P(VALUE block_handler)
{
    if ((block_handler & 0x03) == 0x01) {




 return 1;
    }
    else {
 return 0;
    }
}

static inline VALUE
VM_BH_FROM_ISEQ_BLOCK(const struct rb_captured_block *captured)
{
    VALUE block_handler = ((VALUE)(captured) | (0x01));
    ((void)0);
    return block_handler;
}

static inline const struct rb_captured_block *
VM_BH_TO_ISEQ_BLOCK(VALUE block_handler)
{
    struct rb_captured_block *captured = ((void *)((block_handler) & ~0x03));
    ((void)0);
    return captured;
}

static inline int
VM_BH_IFUNC_P(VALUE block_handler)
{
    if ((block_handler & 0x03) == 0x03) {




 return 1;
    }
    else {
 return 0;
    }
}

static inline VALUE
VM_BH_FROM_IFUNC_BLOCK(const struct rb_captured_block *captured)
{
    VALUE block_handler = ((VALUE)(captured) | (0x03));
    ((void)0);
    return block_handler;
}

static inline const struct rb_captured_block *
VM_BH_TO_IFUNC_BLOCK(VALUE block_handler)
{
    struct rb_captured_block *captured = ((void *)((block_handler) & ~0x03));
    ((void)0);
    return captured;
}

static inline const struct rb_captured_block *
VM_BH_TO_CAPT_BLOCK(VALUE block_handler)
{
    struct rb_captured_block *captured = ((void *)((block_handler) & ~0x03));
    ((void)0);
    return captured;
}

static inline enum rb_block_handler_type
vm_block_handler_type(VALUE block_handler)
{
    if (VM_BH_ISEQ_BLOCK_P(block_handler)) {
 return block_handler_type_iseq;
    }
    else if (VM_BH_IFUNC_P(block_handler)) {
 return block_handler_type_ifunc;
    }
    else if (((((VALUE)(block_handler)&~((~(VALUE)0)<<RUBY_SPECIAL_SHIFT)) == RUBY_SYMBOL_FLAG)||(!(((VALUE)(block_handler) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(block_handler) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(block_handler))->flags & RUBY_T_MASK) == (RUBY_T_SYMBOL)))) {
 return block_handler_type_symbol;
    }
    else {
 ((void)0);
 return block_handler_type_proc;
    }
}

static inline void
vm_block_handler_verify(__attribute__ ((__unused__)) VALUE block_handler)
{
    ((void)0);

}

static inline int
vm_cfp_forwarded_bh_p(const rb_control_frame_t *cfp, VALUE block_handler)
{
    return ((VALUE) cfp->block_code) == block_handler;
}

static inline enum rb_block_type
vm_block_type(const struct rb_block *block)
{
    return block->type;
}

static inline void
vm_block_type_set(const struct rb_block *block, enum rb_block_type type)
{
    struct rb_block *mb = (struct rb_block *)block;
    mb->type = type;
}

static inline const struct rb_block *
vm_proc_block(VALUE procval)
{
    ((void)0);
    return &((rb_proc_t *)(((struct RTypedData*)(procval))->data))->block;
}

static inline const rb_iseq_t *vm_block_iseq(const struct rb_block *block);
static inline const VALUE *vm_block_ep(const struct rb_block *block);

static inline const rb_iseq_t *
vm_proc_iseq(VALUE procval)
{
    return vm_block_iseq(vm_proc_block(procval));
}

static inline const VALUE *
vm_proc_ep(VALUE procval)
{
    return vm_block_ep(vm_proc_block(procval));
}

static inline const rb_iseq_t *
vm_block_iseq(const struct rb_block *block)
{
    switch (vm_block_type(block)) {
      case block_type_iseq: return rb_iseq_check(block->as.captured.code.iseq);
      case block_type_proc: return vm_proc_iseq(block->as.proc);
      case block_type_ifunc:
      case block_type_symbol: return ((void*)0);
    }
    __builtin_unreachable();
    return ((void*)0);
}

static inline const VALUE *
vm_block_ep(const struct rb_block *block)
{
    switch (vm_block_type(block)) {
      case block_type_iseq:
      case block_type_ifunc: return block->as.captured.ep;
      case block_type_proc: return vm_proc_ep(block->as.proc);
      case block_type_symbol: return ((void*)0);
    }
    __builtin_unreachable();
    return ((void*)0);
}

static inline VALUE
vm_block_self(const struct rb_block *block)
{
    switch (vm_block_type(block)) {
      case block_type_iseq:
      case block_type_ifunc:
 return block->as.captured.self;
      case block_type_proc:
 return vm_block_self(vm_proc_block(block->as.proc));
      case block_type_symbol:
 return ((VALUE)RUBY_Qundef);
    }
    __builtin_unreachable();
    return ((VALUE)RUBY_Qundef);
}

static inline VALUE
VM_BH_TO_SYMBOL(VALUE block_handler)
{
    ((void)0);
    return block_handler;
}

static inline VALUE
VM_BH_FROM_SYMBOL(VALUE symbol)
{
    ((void)0);
    return symbol;
}

static inline VALUE
VM_BH_TO_PROC(VALUE block_handler)
{
    ((void)0);
    return block_handler;
}

static inline VALUE
VM_BH_FROM_PROC(VALUE procval)
{
    ((void)0);
    return procval;
}


VALUE rb_thread_alloc(VALUE klass);
VALUE rb_binding_alloc(VALUE klass);
VALUE rb_proc_alloc(VALUE klass);
VALUE rb_proc_dup(VALUE self);


extern void rb_vmdebug_stack_dump_raw(const rb_execution_context_t *ec, const rb_control_frame_t *cfp);
extern void rb_vmdebug_debug_print_pre(const rb_execution_context_t *ec, const rb_control_frame_t *cfp, const VALUE *_pc);
extern void rb_vmdebug_debug_print_post(const rb_execution_context_t *ec, const rb_control_frame_t *cfp



);

void rb_vm_bugreport(const void *);
typedef void (*ruby_sighandler_t)(int);
__attribute__ ((__noreturn__)) void rb_bug_for_fatal_signal(ruby_sighandler_t default_sighandler, int sig, const void *, const char *fmt, ...);


VALUE rb_iseq_eval(const rb_iseq_t *iseq);
VALUE rb_iseq_eval_main(const rb_iseq_t *iseq);
VALUE rb_iseq_path(const rb_iseq_t *iseq);
VALUE rb_iseq_realpath(const rb_iseq_t *iseq);

VALUE rb_iseq_pathobj_new(VALUE path, VALUE realpath);
void rb_iseq_pathobj_set(const rb_iseq_t *iseq, VALUE path, VALUE realpath);

int rb_ec_frame_method_id_and_class(const rb_execution_context_t *ec, ID *idp, ID *called_idp, VALUE *klassp);
void rb_ec_setup_exception(const rb_execution_context_t *ec, VALUE mesg, VALUE cause);

VALUE rb_vm_invoke_proc(rb_execution_context_t *ec, rb_proc_t *proc, int argc, const VALUE *argv, int kw_splat, VALUE block_handler);

VALUE rb_vm_make_proc_lambda(const rb_execution_context_t *ec, const struct rb_captured_block *captured, VALUE klass, int8_t is_lambda);
static inline VALUE
rb_vm_make_proc(const rb_execution_context_t *ec, const struct rb_captured_block *captured, VALUE klass)
{
    return rb_vm_make_proc_lambda(ec, captured, klass, 0);
}

static inline VALUE
rb_vm_make_lambda(const rb_execution_context_t *ec, const struct rb_captured_block *captured, VALUE klass)
{
    return rb_vm_make_proc_lambda(ec, captured, klass, 1);
}

VALUE rb_vm_make_binding(const rb_execution_context_t *ec, const rb_control_frame_t *src_cfp);
VALUE rb_vm_env_local_variables(const rb_env_t *env);
const rb_env_t *rb_vm_env_prev_env(const rb_env_t *env);
const VALUE *rb_binding_add_dynavars(VALUE bindval, rb_binding_t *bind, int dyncount, const ID *dynvars);
void rb_vm_inc_const_missing_count(void);
void rb_vm_gvl_destroy(rb_vm_t *vm);
VALUE rb_vm_call_kw(rb_execution_context_t *ec, VALUE recv, VALUE id, int argc,
                 const VALUE *argv, const rb_callable_method_entry_t *me, int kw_splat);
static void rb_vm_pop_frame(rb_execution_context_t *ec);

void rb_thread_start_timer_thread(void);
void rb_thread_stop_timer_thread(void);
void rb_thread_reset_timer_thread(void);
void rb_thread_wakeup_timer_thread(int);

static inline void
rb_vm_living_threads_init(rb_vm_t *vm)
{
    list_head_init(&vm->waiting_fds);
    list_head_init(&vm->waiting_pids);
    list_head_init(&vm->workqueue);
    list_head_init(&vm->waiting_grps);
    list_head_init(&vm->living_threads);
    vm->living_thread_num = 0;
}

static inline void
rb_vm_living_threads_insert(rb_vm_t *vm, rb_thread_t *th)
{
    list_add_tail_(&vm->living_threads, &th->vmlt_node, "./vm_core.h" ":" "1703");
    vm->living_thread_num++;
}

static inline void
rb_vm_living_threads_remove(rb_vm_t *vm, rb_thread_t *th)
{
    list_del_(&th->vmlt_node, "./vm_core.h" ":" "1710");
    vm->living_thread_num--;
}

typedef int rb_backtrace_iter_func(void *, VALUE, int, VALUE);
rb_control_frame_t *rb_vm_get_ruby_level_next_cfp(const rb_execution_context_t *ec, const rb_control_frame_t *cfp);
rb_control_frame_t *rb_vm_get_binding_creatable_next_cfp(const rb_execution_context_t *ec, const rb_control_frame_t *cfp);
int rb_vm_get_sourceline(const rb_control_frame_t *);
void rb_vm_stack_to_heap(rb_execution_context_t *ec);
void ruby_thread_init_stack(rb_thread_t *th);
int rb_vm_control_frame_id_and_class(const rb_control_frame_t *cfp, ID *idp, ID *called_idp, VALUE *klassp);
void rb_vm_rewind_cfp(rb_execution_context_t *ec, rb_control_frame_t *cfp);
static VALUE rb_vm_bh_to_procval(const rb_execution_context_t *ec, VALUE block_handler);

void rb_vm_register_special_exception_str(enum ruby_special_exceptions sp, VALUE exception_class, VALUE mesg);



void rb_gc_mark_machine_stack(const rb_execution_context_t *ec);static inline 

void rb_vm_rewrite_cref(rb_cref_t *node, VALUE old_klass, VALUE new_klass, rb_cref_t **new_cref_ptr);

static const rb_callable_method_entry_t *rb_vm_frame_method_entry(const rb_control_frame_t *cfp);









VALUE rb_catch_protect(VALUE t, rb_block_call_func *func, VALUE data, enum ruby_tag_type *stateptr);





extern rb_vm_t *ruby_current_vm_ptr;
extern rb_execution_context_t *ruby_current_execution_context_ptr;
extern rb_event_flag_t ruby_vm_event_flags;
extern rb_event_flag_t ruby_vm_event_enabled_global_flags;
extern unsigned int ruby_vm_event_local_num;



static inline rb_thread_t *
rb_ec_thread_ptr(const rb_execution_context_t *ec)
{
    return ec->thread_ptr;
}

static inline rb_vm_t *
rb_ec_vm_ptr(const rb_execution_context_t *ec)
{
    const rb_thread_t *th = rb_ec_thread_ptr(ec);
    if (th) {
 return th->vm;
    }
    else {
 return ((void*)0);
    }
}

static inline rb_execution_context_t *
rb_current_execution_context(void)
{
    return ruby_current_execution_context_ptr;
}

static inline rb_thread_t *
rb_current_thread(void)
{
    const rb_execution_context_t *ec = rb_current_execution_context();
    return rb_ec_thread_ptr(ec);
}

static inline rb_vm_t *
rb_current_vm(void)
{
    ((void)0);



    return ruby_current_vm_ptr;
}

static inline void
rb_thread_set_current_raw(const rb_thread_t *th)
{
    ruby_current_execution_context_ptr = th->ec;
}

static inline void
rb_thread_set_current(rb_thread_t *th)
{
    if (th->vm->running_thread != th) {
        th->running_time_us = 0;
    }
    rb_thread_set_current_raw(th);
    th->vm->running_thread = th;
}





enum {
    TIMER_INTERRUPT_MASK = 0x01,
    PENDING_INTERRUPT_MASK = 0x02,
    POSTPONED_JOB_INTERRUPT_MASK = 0x04,
    TRAP_INTERRUPT_MASK = 0x08
};



VALUE rb_exc_set_backtrace(VALUE exc, VALUE bt);
int rb_signal_buff_size(void);
int rb_signal_exec(rb_thread_t *th, int sig);
void rb_threadptr_check_signal(rb_thread_t *mth);
void rb_threadptr_signal_raise(rb_thread_t *th, int sig);
void rb_threadptr_signal_exit(rb_thread_t *th);
int rb_threadptr_execute_interrupts(rb_thread_t *, int);
void rb_threadptr_interrupt(rb_thread_t *th);
void rb_threadptr_unlock_all_locking_mutexes(rb_thread_t *th);
void rb_threadptr_pending_interrupt_clear(rb_thread_t *th);
void rb_threadptr_pending_interrupt_enque(rb_thread_t *th, VALUE v);
VALUE rb_ec_get_errinfo(const rb_execution_context_t *ec);
void rb_ec_error_print(rb_execution_context_t * volatile ec, volatile VALUE errinfo);
void rb_execution_context_update(const rb_execution_context_t *ec);
void rb_execution_context_mark(const rb_execution_context_t *ec);
void rb_fiber_close(rb_fiber_t *fib);
void Init_native_thread(rb_thread_t *th);

static inline void
rb_vm_check_ints(rb_execution_context_t *ec)
{
    ((void)0);
    if ((__builtin_expect(!!(((ec)->interrupt_flag & ~(ec)->interrupt_mask)), 0))) {
 rb_threadptr_execute_interrupts(rb_ec_thread_ptr(ec), 0);
    }
}



struct rb_trace_arg_struct {
    rb_event_flag_t event;
    rb_execution_context_t *ec;
    const rb_control_frame_t *cfp;
    VALUE self;
    ID id;
    ID called_id;
    VALUE klass;
    VALUE data;

    int klass_solved;


    int lineno;
    VALUE path;
};

void rb_hook_list_mark(rb_hook_list_t *hooks);
void rb_hook_list_free(rb_hook_list_t *hooks);
void rb_hook_list_connect_tracepoint(VALUE target, rb_hook_list_t *list, VALUE tpval, unsigned int target_line);
void rb_hook_list_remove_tracepoint(rb_hook_list_t *list, VALUE tpval);

void rb_exec_event_hooks(struct rb_trace_arg_struct *trace_arg, rb_hook_list_t *hooks, int pop_p);









static inline void
rb_exec_event_hook_orig(rb_execution_context_t *ec, rb_hook_list_t *hooks, rb_event_flag_t flag,
                        VALUE self, ID id, ID called_id, VALUE klass, VALUE data, int pop_p)
{
    struct rb_trace_arg_struct trace_arg;

    ((void)0);

    trace_arg.event = flag;
    trace_arg.ec = ec;
    trace_arg.cfp = ec->cfp;
    trace_arg.self = self;
    trace_arg.id = id;
    trace_arg.called_id = called_id;
    trace_arg.klass = klass;
    trace_arg.data = data;
    trace_arg.path = ((VALUE)RUBY_Qundef);
    trace_arg.klass_solved = 0;

    rb_exec_event_hooks(&trace_arg, hooks, pop_p);
}

static inline rb_hook_list_t *
rb_vm_global_hooks(const rb_execution_context_t *ec)
{
    return &rb_ec_vm_ptr(ec)->global_hooks;
}





static inline void
rb_exec_event_hook_script_compiled(rb_execution_context_t *ec, const rb_iseq_t *iseq, VALUE eval_script)
{
    do { const rb_event_flag_t flag_arg_ = (0x2000); rb_hook_list_t *hooks_arg_ = (rb_vm_global_hooks(ec)); if ((__builtin_expect(!!((hooks_arg_)->events & (flag_arg_)), 0))) { rb_exec_event_hook_orig(ec, hooks_arg_, flag_arg_, ec->cfp->self, 0, 0, 0, !((VALUE)(eval_script) != ((VALUE)RUBY_Qnil)) ? (VALUE)iseq : __extension__ ({ const VALUE args_to_new_ary[] = {eval_script, (VALUE)iseq}; if (__builtin_constant_p(2)) { __extension__ _Static_assert(((int)(sizeof(args_to_new_ary) / sizeof((args_to_new_ary)[0]))) == (2), "rb_ary_new_from_args" ": " "numberof(args_to_new_ary) == (2)"); } rb_ary_new_from_values(((int)(sizeof(args_to_new_ary) / sizeof((args_to_new_ary)[0]))), args_to_new_ary); }), 0); } } while (0);


}

void rb_vm_trap_exit(rb_vm_t *vm);


int rb_thread_check_trap_pending(void);



extern VALUE rb_get_coverages(void);
extern void rb_set_coverages(VALUE, int, VALUE);
extern void rb_clear_coverages(void);
extern void rb_reset_coverages(void);

void rb_postponed_job_flush(rb_vm_t *vm);







VALUE ruby_debug_print_value(int level, int debug_level, const char *header, VALUE v);
ID ruby_debug_print_id(int level, int debug_level, const char *header, ID id);
NODE *ruby_debug_print_node(int level, int debug_level, const char *header, const NODE *node);
int ruby_debug_print_indent(int level, int debug_level, int indent_level);
void ruby_debug_gc_check_func(void);
void ruby_set_debug_option(const char *str);


extern const int ruby_api_version[];






extern const ID rb_iseq_shared_exc_local_tbl[];

static inline size_t
rb_call_info_kw_arg_bytes(int keyword_len)
{
    return rb_size_mul_add_or_raise(
        keyword_len - 1, sizeof(VALUE), sizeof(struct rb_call_info_kw_arg),
        rb_eRuntimeError);
}




static inline rb_snum_t
ISEQ_FLIP_CNT_INCREMENT(const rb_iseq_t *iseq)
{
    rb_snum_t cnt = iseq->body->variable.flip_count;
    iseq->body->variable.flip_count += 1;
    return cnt;
}

static inline VALUE *
ISEQ_ORIGINAL_ISEQ(const rb_iseq_t *iseq)
{
    return iseq->body->variable.original_iseq;
}

static inline void
ISEQ_ORIGINAL_ISEQ_CLEAR(const rb_iseq_t *iseq)
{
    void *ptr = iseq->body->variable.original_iseq;
    iseq->body->variable.original_iseq = ((void*)0);
    if (ptr) {
        ruby_xfree(ptr);
    }
}

static inline VALUE *
ISEQ_ORIGINAL_ISEQ_ALLOC(const rb_iseq_t *iseq, long size)
{
    return iseq->body->variable.original_iseq =
        ((VALUE*)ruby_xmalloc2((size_t)(size),sizeof(VALUE)));
}



struct iseq_compile_data {

    const VALUE err_info;
    const VALUE catch_table_ary;


    struct iseq_label_data *start_label;
    struct iseq_label_data *end_label;
    struct iseq_label_data *redo_label;
    const rb_iseq_t *current_block;
    struct iseq_compile_data_ensure_node_stack *ensure_node_stack;
    struct {
      struct iseq_compile_data_storage *storage_head;
      struct iseq_compile_data_storage *storage_current;
    } node;
    struct {
      struct iseq_compile_data_storage *storage_head;
      struct iseq_compile_data_storage *storage_current;
    } insn;
    int loopval_popped;
    int last_line;
    int label_no;
    int node_level;
    unsigned int ci_index;
    unsigned int ci_kw_index;
    const rb_compile_option_t *option;
    struct rb_id_table *ivar_cache_table;
    const struct rb_builtin_function *builtin_function_table;



};

static inline struct iseq_compile_data *
ISEQ_COMPILE_DATA(const rb_iseq_t *iseq)
{
    if (iseq->flags & ((VALUE)RUBY_FL_USER6)) {
 return iseq->aux.compile_data;
    }
    else {
 return ((void*)0);
    }
}

static inline void
ISEQ_COMPILE_DATA_ALLOC(rb_iseq_t *iseq)
{
    iseq->aux.compile_data = (((struct iseq_compile_data*)ruby_xcalloc((size_t)(1),sizeof(struct iseq_compile_data))));
    iseq->flags |= ((VALUE)RUBY_FL_USER6);
}

static inline void
ISEQ_COMPILE_DATA_CLEAR(rb_iseq_t *iseq)
{
    iseq->flags &= ~((VALUE)RUBY_FL_USER6);
    iseq->aux.compile_data = ((void*)0);
}

static inline rb_iseq_t *
iseq_imemo_alloc(void)
{
    return (rb_iseq_t *)rb_imemo_new(imemo_iseq, 0, 0, 0, 0);
}

VALUE rb_iseq_ibf_dump(const rb_iseq_t *iseq, VALUE opt);
void rb_ibf_load_iseq_complete(rb_iseq_t *iseq);
const rb_iseq_t *rb_iseq_ibf_load(VALUE str);
const rb_iseq_t *rb_iseq_ibf_load_bytes(const char *cstr, size_t);
VALUE rb_iseq_ibf_load_extra_data(VALUE str);
void rb_iseq_init_trace(rb_iseq_t *iseq);
int rb_iseq_add_local_tracepoint_recursively(const rb_iseq_t *iseq, rb_event_flag_t turnon_events, VALUE tpval, unsigned int target_line);
int rb_iseq_remove_local_tracepoint_recursively(const rb_iseq_t *iseq, VALUE tpval);
const rb_iseq_t *rb_iseq_load_iseq(VALUE fname);


unsigned int *rb_iseq_insns_info_decode_positions(const struct rb_iseq_constant_body *body);




VALUE rb_iseq_compile_node(rb_iseq_t *iseq, const NODE *node);
VALUE rb_iseq_compile_callback(rb_iseq_t *iseq, const struct rb_iseq_new_with_callback_callback_func * ifunc);
VALUE *rb_iseq_original_iseq(const rb_iseq_t *iseq);
void rb_iseq_build_from_ary(rb_iseq_t *iseq, VALUE misc,
       VALUE locals, VALUE args,
       VALUE exception, VALUE body);
void rb_iseq_mark_insn_storage(struct iseq_compile_data_storage *arena);


VALUE rb_iseq_load(VALUE data, VALUE parent, VALUE opt);
VALUE rb_iseq_parameters(const rb_iseq_t *iseq, int is_proc);
unsigned int rb_iseq_line_no(const rb_iseq_t *iseq, size_t pos);
void rb_iseq_trace_set(const rb_iseq_t *iseq, rb_event_flag_t turnon_events);
void rb_iseq_trace_set_all(rb_event_flag_t turnon_events);
void rb_iseq_insns_info_encode_positions(const rb_iseq_t *iseq);

struct rb_iseq_constant_body *rb_iseq_constant_body_alloc(void);
VALUE rb_iseqw_new(const rb_iseq_t *iseq);
const rb_iseq_t *rb_iseqw_to_iseq(VALUE iseqw);

VALUE rb_iseq_absolute_path(const rb_iseq_t *iseq);
VALUE rb_iseq_label(const rb_iseq_t *iseq);
VALUE rb_iseq_base_label(const rb_iseq_t *iseq);
VALUE rb_iseq_first_lineno(const rb_iseq_t *iseq);
VALUE rb_iseq_method_name(const rb_iseq_t *iseq);
void rb_iseq_code_location(const rb_iseq_t *iseq, int *first_lineno, int *first_column, int *last_lineno, int *last_column);

void rb_iseq_remove_coverage_all(void);


const rb_iseq_t *rb_method_iseq(VALUE body);
const rb_iseq_t *rb_proc_get_iseq(VALUE proc, int *is_proc);

struct rb_compile_option_struct {
    unsigned int inline_const_cache: 1;
    unsigned int peephole_optimization: 1;
    unsigned int tailcall_optimization: 1;
    unsigned int specialized_instruction: 1;
    unsigned int operands_unification: 1;
    unsigned int instructions_unification: 1;
    unsigned int stack_caching: 1;
    unsigned int frozen_string_literal: 1;
    unsigned int debug_frozen_string_literal: 1;
    unsigned int coverage_enabled: 1;
    int debug_level;
};

struct iseq_insn_info_entry {
    int line_no;
    rb_event_flag_t events;
};

struct iseq_catch_table_entry {
    enum catch_type {
 CATCH_TYPE_RESCUE = (((VALUE)(1))<<1 | RUBY_FIXNUM_FLAG),
 CATCH_TYPE_ENSURE = (((VALUE)(2))<<1 | RUBY_FIXNUM_FLAG),
 CATCH_TYPE_RETRY = (((VALUE)(3))<<1 | RUBY_FIXNUM_FLAG),
 CATCH_TYPE_BREAK = (((VALUE)(4))<<1 | RUBY_FIXNUM_FLAG),
 CATCH_TYPE_REDO = (((VALUE)(5))<<1 | RUBY_FIXNUM_FLAG),
 CATCH_TYPE_NEXT = (((VALUE)(6))<<1 | RUBY_FIXNUM_FLAG)
    } type;
    rb_iseq_t *iseq;

    unsigned int start;
    unsigned int end;
    unsigned int cont;
    unsigned int sp;
};

struct iseq_catch_table { unsigned int size; struct iseq_catch_table_entry entries[];};




static inline int
iseq_catch_table_bytes(int n)
{
    enum {
 catch_table_entry_size = sizeof(struct iseq_catch_table_entry),
 catch_table_entries_max = (2147483647 - __builtin_offsetof(struct iseq_catch_table, entries)) / catch_table_entry_size
    };
    if (n > catch_table_entries_max) rb_fatal("too large iseq_catch_table - %d", n);
    return (int)(__builtin_offsetof(struct iseq_catch_table, entries) +
   n * catch_table_entry_size);
}


struct iseq_compile_data_storage {
    struct iseq_compile_data_storage *next;
    unsigned int pos;
    unsigned int size;
    char buff[];
};



enum defined_type {
    DEFINED_NOT_DEFINED,
    DEFINED_NIL = 1,
    DEFINED_IVAR,
    DEFINED_LVAR,
    DEFINED_GVAR,
    DEFINED_CVAR,
    DEFINED_CONST,
    DEFINED_METHOD,
    DEFINED_YIELD,
    DEFINED_ZSUPER,
    DEFINED_SELF,
    DEFINED_TRUE,
    DEFINED_FALSE,
    DEFINED_ASGN,
    DEFINED_EXPR,
    DEFINED_IVAR2,
    DEFINED_REF,
    DEFINED_FUNC,
    DEFINED_CONST_FROM
};

VALUE rb_iseq_defined_string(enum defined_type type);


VALUE rb_iseq_local_variables(const rb_iseq_t *iseq);






static inline void
vm_passed_block_handler_set(rb_execution_context_t *ec, VALUE block_handler)
{
    vm_block_handler_verify(block_handler);
    ec->passed_block_handler = block_handler;
}

static inline void
pass_passed_block_handler(rb_execution_context_t *ec)
{
    VALUE block_handler = rb_vm_frame_block_handler(ec->cfp);
    vm_passed_block_handler_set(ec, block_handler);
    VM_ENV_FLAGS_SET(ec->cfp->ep, VM_FRAME_FLAG_PASSED);
}

extern char ***_NSGetArgv(void);
extern int *_NSGetArgc(void);
extern char ***_NSGetEnviron(void);
extern char **_NSGetProgname(void);

extern struct mach_header_64 *



    _NSGetMachExecuteHeader(void);
extern int * __error(void);














































































































































































static inline int
rb_ec_tag_state(const rb_execution_context_t *ec)
{
    enum ruby_tag_type state = ec->tag->state;
    ec->tag->state = RUBY_TAG_NONE;
    return state;
}

__attribute__ ((__noreturn__)) static inline void rb_ec_tag_jump(const rb_execution_context_t *ec, enum ruby_tag_type st);
static inline void
rb_ec_tag_jump(const rb_execution_context_t *ec, enum ruby_tag_type st)
{
    ec->tag->state = st;
    siglongjmp(((ec->tag->buf)),(1));
}












static inline VALUE
CREF_CLASS(const rb_cref_t *cref)
{
    return cref->klass;
}

static inline rb_cref_t *
CREF_NEXT(const rb_cref_t *cref)
{
    return cref->next;
}

static inline const rb_scope_visibility_t *
CREF_SCOPE_VISI(const rb_cref_t *cref)
{
    return &cref->scope_visi;
}

static inline VALUE
CREF_REFINEMENTS(const rb_cref_t *cref)
{
    return cref->refinements;
}

static inline void
CREF_REFINEMENTS_SET(rb_cref_t *cref, VALUE refs)
{
    __extension__({
;
; typeof(rb_obj_write((VALUE)(cref), (VALUE *)(&cref->refinements), (VALUE)(refs), "./eval_intern.h", 220)) unaligned_member_access_result = (rb_obj_write((VALUE)(cref), (VALUE *)(&cref->refinements), (VALUE)(refs), "./eval_intern.h", 220));
; unaligned_member_access_result; });
}

static inline int
CREF_PUSHED_BY_EVAL(const rb_cref_t *cref)
{
    return cref->flags & ((VALUE)RUBY_FL_USER5);
}

static inline void
CREF_PUSHED_BY_EVAL_SET(rb_cref_t *cref)
{
    cref->flags |= ((VALUE)RUBY_FL_USER5);
}

static inline int
CREF_OMOD_SHARED(const rb_cref_t *cref)
{
    return cref->flags & ((VALUE)RUBY_FL_USER6);
}

static inline void
CREF_OMOD_SHARED_SET(rb_cref_t *cref)
{
    cref->flags |= ((VALUE)RUBY_FL_USER6);
}

static inline void
CREF_OMOD_SHARED_UNSET(rb_cref_t *cref)
{
    cref->flags &= ~((VALUE)RUBY_FL_USER6);
}

enum {
    RAISED_EXCEPTION = 1,
    RAISED_STACKOVERFLOW = 2,
    RAISED_NOMEMORY = 4
};
int rb_ec_set_raised(rb_execution_context_t *ec);
int rb_ec_reset_raised(rb_execution_context_t *ec);
int rb_ec_stack_check(rb_execution_context_t *ec);

VALUE rb_f_eval(int argc, const VALUE *argv, VALUE self);
VALUE rb_make_exception(int argc, const VALUE *argv);

__attribute__ ((__noreturn__)) void rb_method_name_error(VALUE, VALUE);

__attribute__ ((__noreturn__)) void rb_fiber_start(void);

__attribute__ ((__noreturn__)) void rb_print_undef(VALUE, ID, rb_method_visibility_t);
__attribute__ ((__noreturn__)) void rb_print_undef_str(VALUE, VALUE);
__attribute__ ((__noreturn__)) void rb_print_inaccessible(VALUE, ID, rb_method_visibility_t);
__attribute__ ((__noreturn__)) void rb_vm_localjump_error(const char *,VALUE, int);
__attribute__ ((__noreturn__)) void rb_vm_jump_tag_but_local_jump(int);

VALUE rb_vm_make_jump_tag_but_local_jump(int state, VALUE val);
rb_cref_t *rb_vm_cref(void);
rb_cref_t *rb_vm_cref_replace_with_duplicated_cref(void);
VALUE rb_vm_call_cfunc(VALUE recv, VALUE (*func)(VALUE), VALUE arg, VALUE block_handler, VALUE filename);
void rb_vm_set_progname(VALUE filename);
void rb_thread_terminate_all(void);
VALUE rb_vm_cbase(void);


VALUE rb_ec_backtrace_object(const rb_execution_context_t *ec);
VALUE rb_ec_backtrace_str_ary(const rb_execution_context_t *ec, long lev, long n);
VALUE rb_ec_backtrace_location_ary(const rb_execution_context_t *ec, long lev, long n);







struct rb_builtin_function {

    const void * const func_ptr;
    const int argc;


    const int index;
    const char * const name;
};







void rb_load_with_builtin_functions(const char *feature_name, const struct rb_builtin_function *table);
static inline void rb_builtin_function_check_arity0(VALUE (*f)(rb_execution_context_t *ec, VALUE self)){}
static inline void rb_builtin_function_check_arity1(VALUE (*f)(rb_execution_context_t *ec, VALUE self, VALUE)){}
static inline void rb_builtin_function_check_arity2(VALUE (*f)(rb_execution_context_t *ec, VALUE self, VALUE, VALUE)){}
static inline void rb_builtin_function_check_arity3(VALUE (*f)(rb_execution_context_t *ec, VALUE self, VALUE, VALUE, VALUE)){}
static inline void rb_builtin_function_check_arity4(VALUE (*f)(rb_execution_context_t *ec, VALUE self, VALUE, VALUE, VALUE, VALUE)){}
static inline void rb_builtin_function_check_arity5(VALUE (*f)(rb_execution_context_t *ec, VALUE self, VALUE, VALUE, VALUE, VALUE, VALUE)){}
static inline void rb_builtin_function_check_arity6(VALUE (*f)(rb_execution_context_t *ec, VALUE self, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE)){}
static inline void rb_builtin_function_check_arity7(VALUE (*f)(rb_execution_context_t *ec, VALUE self, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE)){}
static inline void rb_builtin_function_check_arity8(VALUE (*f)(rb_execution_context_t *ec, VALUE self, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE)){}
static inline void rb_builtin_function_check_arity9(VALUE (*f)(rb_execution_context_t *ec, VALUE self, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE)){}
static inline void rb_builtin_function_check_arity10(VALUE (*f)(rb_execution_context_t *ec, VALUE self, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE)){}
static inline void rb_builtin_function_check_arity11(VALUE (*f)(rb_execution_context_t *ec, VALUE self, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE)){}
static inline void rb_builtin_function_check_arity12(VALUE (*f)(rb_execution_context_t *ec, VALUE self, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE)){}
static inline void rb_builtin_function_check_arity13(VALUE (*f)(rb_execution_context_t *ec, VALUE self, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE)){}
static inline void rb_builtin_function_check_arity14(VALUE (*f)(rb_execution_context_t *ec, VALUE self, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE)){}
static inline void rb_builtin_function_check_arity15(VALUE (*f)(rb_execution_context_t *ec, VALUE self, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE)){}static inline 

VALUE rb_vm_lvar_exposed(rb_execution_context_t *ec, int index);



__attribute__ ((__pure__)) static inline VALUE rb_vm_lvar(rb_execution_context_t *ec, int index);

static inline VALUE
rb_vm_lvar(rb_execution_context_t *ec, int index)
{

    return ec->cfp->ep[index];



}



struct builtin_binary {
    const char *feature;
    const unsigned char *bin;
    size_t bin_size;
};


































struct ruby_dtrace_method_hook_args {
    const char *classname;
    const char *methodname;
    const char *filename;
    int line_no;
    volatile VALUE klass;
    volatile VALUE name;
};

__attribute__ ((__noinline__)) int rb_dtrace_setup(rb_execution_context_t *, VALUE, ID, struct ruby_dtrace_method_hook_args *);








VALUE rb_str_concat_literals(size_t, const VALUE*);
__attribute__ ((__visibility__("default"))) extern

VALUE rb_vm_exec(rb_execution_context_t *, int);

__attribute__ ((__pure__)) static inline const VALUE *VM_EP_LEP(const VALUE *);
static inline const VALUE *
VM_EP_LEP(const VALUE *ep)
{
    while (!VM_ENV_LOCAL_P(ep)) {
 ep = VM_ENV_PREV_EP(ep);
    }
    return ep;
}

static inline const rb_control_frame_t *
rb_vm_search_cf_from_ep(const rb_execution_context_t *ec, const rb_control_frame_t *cfp, const VALUE * const ep)
{
    if (!ep) {
 return ((void*)0);
    }
    else {
 const rb_control_frame_t * const eocfp = RUBY_VM_END_CONTROL_FRAME(ec);

 while (cfp < eocfp) {
     if (cfp->ep == ep) {
  return cfp;
     }
     cfp = ((cfp)+1);
 }

 return ((void*)0);
    }
}static inline 

const VALUE *
rb_vm_ep_local_ep(const VALUE *ep)
{
    return VM_EP_LEP(ep);
}

__attribute__ ((__pure__)) static inline const VALUE *VM_CF_LEP(const rb_control_frame_t * const cfp);
static inline const VALUE *
VM_CF_LEP(const rb_control_frame_t * const cfp)
{
    return VM_EP_LEP(cfp->ep);
}

static inline const VALUE *
VM_CF_PREV_EP(const rb_control_frame_t * const cfp)
{
    return VM_ENV_PREV_EP(cfp->ep);
}

__attribute__ ((__pure__)) static inline VALUE VM_CF_BLOCK_HANDLER(const rb_control_frame_t * const cfp);
static inline VALUE
VM_CF_BLOCK_HANDLER(const rb_control_frame_t * const cfp)
{
    const VALUE *ep = VM_CF_LEP(cfp);
    return VM_ENV_BLOCK_HANDLER(ep);
}static inline 

int
rb_vm_cframe_keyword_p(const rb_control_frame_t *cfp)
{
    return VM_FRAME_CFRAME_KW_P(cfp);
}static inline 


int
rb_vm_cframe_empty_keyword_p(const rb_control_frame_t *cfp)
{
    return VM_FRAME_CFRAME_EMPTY_KW_P(cfp);
}static inline 

VALUE
rb_vm_frame_block_handler(const rb_control_frame_t *cfp)
{
    return VM_CF_BLOCK_HANDLER(cfp);
}
static struct rb_captured_block *
VM_CFP_TO_CAPTURED_BLOCK(const rb_control_frame_t *cfp)
{
    ((void)0);
    return (struct rb_captured_block *)&cfp->self;
}

static rb_control_frame_t *
VM_CAPTURED_BLOCK_TO_CFP(const struct rb_captured_block *captured)
{
    rb_control_frame_t *cfp = ((rb_control_frame_t *)((VALUE *)(captured) - 3));
    ((void)0);
    ((void)0);
    return cfp;
}

static int
VM_BH_FROM_CFP_P(VALUE block_handler, const rb_control_frame_t *cfp)
{
    const struct rb_captured_block *captured = VM_CFP_TO_CAPTURED_BLOCK(cfp);
    return ((void *)((block_handler) & ~0x03)) == captured;
}

static VALUE
vm_passed_block_handler(rb_execution_context_t *ec)
{
    VALUE block_handler = ec->passed_block_handler;
    ec->passed_block_handler = 0;
    vm_block_handler_verify(block_handler);
    return block_handler;
}

static rb_cref_t *
vm_cref_new0(VALUE klass, rb_method_visibility_t visi, int module_func, rb_cref_t *prev_cref, int pushed_by_eval, int use_prev_prev)
{
    VALUE refinements = ((VALUE)RUBY_Qnil);
    int omod_shared = 0;
    rb_cref_t *cref;


    union {
 rb_scope_visibility_t visi;
 VALUE value;
    } scope_visi;

    scope_visi.visi.method_visi = visi;
    scope_visi.visi.module_func = module_func;


    if (prev_cref != ((void*)0) && prev_cref != (void *)1 ) {
 refinements = CREF_REFINEMENTS(prev_cref);

 if (!!((VALUE)(refinements) != ((VALUE)RUBY_Qnil))) {
     omod_shared = 1;
     CREF_OMOD_SHARED_SET(prev_cref);
 }
    }

    cref = (rb_cref_t *)rb_imemo_new(imemo_cref, klass, (VALUE)(use_prev_prev ? CREF_NEXT(prev_cref) : prev_cref), scope_visi.value, refinements);

    if (pushed_by_eval) CREF_PUSHED_BY_EVAL_SET(cref);
    if (omod_shared) CREF_OMOD_SHARED_SET(cref);

    return cref;
}

static rb_cref_t *
vm_cref_new(VALUE klass, rb_method_visibility_t visi, int module_func, rb_cref_t *prev_cref, int pushed_by_eval)
{
    return vm_cref_new0(klass, visi, module_func, prev_cref, pushed_by_eval, 0);
}

static rb_cref_t *
vm_cref_new_use_prev(VALUE klass, rb_method_visibility_t visi, int module_func, rb_cref_t *prev_cref, int pushed_by_eval)
{
    return vm_cref_new0(klass, visi, module_func, prev_cref, pushed_by_eval, 1);
}

static int
ref_delete_symkey(VALUE key, VALUE value, VALUE unused)
{
    return ((((VALUE)(key)&~((~(VALUE)0)<<RUBY_SPECIAL_SHIFT)) == RUBY_SYMBOL_FLAG)||(!(((VALUE)(key) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(key) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(key))->flags & RUBY_T_MASK) == (RUBY_T_SYMBOL))) ? ST_DELETE : ST_CONTINUE;
}

static rb_cref_t *
vm_cref_dup(const rb_cref_t *cref)
{
    VALUE klass = CREF_CLASS(cref);
    const rb_scope_visibility_t *visi = CREF_SCOPE_VISI(cref);
    rb_cref_t *next_cref = CREF_NEXT(cref), *new_cref;
    int pushed_by_eval = CREF_PUSHED_BY_EVAL(cref);

    new_cref = vm_cref_new(klass, visi->method_visi, visi->module_func, next_cref, pushed_by_eval);

    if (!!((VALUE)(CREF_REFINEMENTS(cref)) != ((VALUE)RUBY_Qnil))) {
        VALUE ref = rb_hash_dup(CREF_REFINEMENTS(cref));
        rb_hash_foreach(ref, ref_delete_symkey, ((VALUE)RUBY_Qnil));
        CREF_REFINEMENTS_SET(new_cref, ref);
 CREF_OMOD_SHARED_UNSET(new_cref);
    }

    return new_cref;
}

static rb_cref_t *
vm_cref_new_toplevel(rb_execution_context_t *ec)
{
    rb_cref_t *cref = vm_cref_new(rb_cObject, METHOD_VISI_PRIVATE , 0, ((void*)0), 0);
    VALUE top_wrapper = rb_ec_thread_ptr(ec)->top_wrapper;

    if (top_wrapper) {
 cref = vm_cref_new(top_wrapper, METHOD_VISI_PRIVATE, 0, cref, 0);
    }

    return cref;
}static inline 

rb_cref_t *
rb_vm_cref_new_toplevel(void)
{
    return vm_cref_new_toplevel(rb_current_execution_context());
}

static void
vm_cref_dump(const char *mesg, const rb_cref_t *cref)
{
    fprintf(__stderrp, "vm_cref_dump: %s (%p)\n", mesg, (void *)cref);

    while (cref) {
 fprintf(__stderrp, "= cref| klass: %s\n", (!(((struct RBasic*)(rb_class_path(CREF_CLASS(cref))))->flags & RSTRING_NOEMBED) ? ((struct RString*)(rb_class_path(CREF_CLASS(cref))))->as.ary : ((struct RString*)(rb_class_path(CREF_CLASS(cref))))->as.heap.ptr));
 cref = CREF_NEXT(cref);
    }
}static inline 

void
rb_vm_block_ep_update(VALUE obj, const struct rb_block *dst, const VALUE *ep)
{
    *((const VALUE **)&dst->as.captured.ep) = ep;
    rb_obj_written((VALUE)(obj), (VALUE)(((VALUE)RUBY_Qundef)), (VALUE)(VM_ENV_ENVVAL(ep)), "./vm.c", 318);
}

static void
vm_bind_update_env(VALUE bindval, rb_binding_t *bind, VALUE envval)
{
    const rb_env_t *env = (rb_env_t *)envval;
    __extension__({
;
; typeof(rb_obj_write((VALUE)(bindval), (VALUE *)(&bind->block.as.captured.code.iseq), (VALUE)(env->iseq), "./vm.c", 325)) unaligned_member_access_result = (rb_obj_write((VALUE)(bindval), (VALUE *)(&bind->block.as.captured.code.iseq), (VALUE)(env->iseq), "./vm.c", 325));
; unaligned_member_access_result; });
    rb_vm_block_ep_update(bindval, &bind->block, env->ep);
}







static VALUE vm_make_env_object(const rb_execution_context_t *ec, rb_control_frame_t *cfp);
extern VALUE rb_vm_invoke_bmethod(rb_execution_context_t *ec, rb_proc_t *proc, VALUE self,
                                  int argc, const VALUE *argv, int kw_splat, VALUE block_handler,
                                  const rb_callable_method_entry_t *me);
static VALUE vm_invoke_proc(rb_execution_context_t *ec, rb_proc_t *proc, VALUE self, int argc, const VALUE *argv, int kw_splat, VALUE block_handler);










enum rb_debug_counter_type {

RB_DEBUG_COUNTER_mc_inline_hit,
RB_DEBUG_COUNTER_mc_inline_miss,
RB_DEBUG_COUNTER_mc_global_hit,
RB_DEBUG_COUNTER_mc_global_miss,
RB_DEBUG_COUNTER_mc_global_state_miss,
RB_DEBUG_COUNTER_mc_class_serial_miss,
RB_DEBUG_COUNTER_mc_cme_complement,
RB_DEBUG_COUNTER_mc_cme_complement_hit,
RB_DEBUG_COUNTER_mc_search_super,
RB_DEBUG_COUNTER_mc_miss_by_nome,
RB_DEBUG_COUNTER_mc_miss_by_distinct,
RB_DEBUG_COUNTER_mc_miss_by_refine,
RB_DEBUG_COUNTER_mc_miss_by_visi,
RB_DEBUG_COUNTER_mc_miss_spurious,
RB_DEBUG_COUNTER_mc_miss_reuse_call,




RB_DEBUG_COUNTER_ccf_general,
RB_DEBUG_COUNTER_ccf_iseq_setup,
RB_DEBUG_COUNTER_ccf_iseq_setup_0start,
RB_DEBUG_COUNTER_ccf_iseq_setup_tailcall_0start,
RB_DEBUG_COUNTER_ccf_iseq_fix,
RB_DEBUG_COUNTER_ccf_iseq_opt,
RB_DEBUG_COUNTER_ccf_iseq_kw1,
RB_DEBUG_COUNTER_ccf_iseq_kw2,
RB_DEBUG_COUNTER_ccf_cfunc,
RB_DEBUG_COUNTER_ccf_ivar,
RB_DEBUG_COUNTER_ccf_attrset,
RB_DEBUG_COUNTER_ccf_method_missing,
RB_DEBUG_COUNTER_ccf_zsuper,
RB_DEBUG_COUNTER_ccf_bmethod,
RB_DEBUG_COUNTER_ccf_opt_send,
RB_DEBUG_COUNTER_ccf_opt_call,
RB_DEBUG_COUNTER_ccf_opt_block_call,
RB_DEBUG_COUNTER_ccf_super_method,
RB_DEBUG_COUNTER_frame_push,
RB_DEBUG_COUNTER_frame_push_method,
RB_DEBUG_COUNTER_frame_push_block,
RB_DEBUG_COUNTER_frame_push_class,
RB_DEBUG_COUNTER_frame_push_top,
RB_DEBUG_COUNTER_frame_push_cfunc,
RB_DEBUG_COUNTER_frame_push_ifunc,
RB_DEBUG_COUNTER_frame_push_eval,
RB_DEBUG_COUNTER_frame_push_rescue,
RB_DEBUG_COUNTER_frame_push_dummy,

RB_DEBUG_COUNTER_frame_R2R,
RB_DEBUG_COUNTER_frame_R2C,
RB_DEBUG_COUNTER_frame_C2C,
RB_DEBUG_COUNTER_frame_C2R,
RB_DEBUG_COUNTER_ivar_get_ic_hit,
RB_DEBUG_COUNTER_ivar_get_ic_miss,
RB_DEBUG_COUNTER_ivar_get_ic_miss_serial,
RB_DEBUG_COUNTER_ivar_get_ic_miss_unset,
RB_DEBUG_COUNTER_ivar_get_ic_miss_noobject,
RB_DEBUG_COUNTER_ivar_set_ic_hit,
RB_DEBUG_COUNTER_ivar_set_ic_miss,
RB_DEBUG_COUNTER_ivar_set_ic_miss_serial,
RB_DEBUG_COUNTER_ivar_set_ic_miss_unset,
RB_DEBUG_COUNTER_ivar_set_ic_miss_oorange,
RB_DEBUG_COUNTER_ivar_set_ic_miss_noobject,
RB_DEBUG_COUNTER_ivar_get_base,
RB_DEBUG_COUNTER_ivar_set_base,
RB_DEBUG_COUNTER_lvar_get,
RB_DEBUG_COUNTER_lvar_get_dynamic,
RB_DEBUG_COUNTER_lvar_set,
RB_DEBUG_COUNTER_lvar_set_dynamic,
RB_DEBUG_COUNTER_lvar_set_slowpath,
RB_DEBUG_COUNTER_gc_count,
RB_DEBUG_COUNTER_gc_minor_newobj,
RB_DEBUG_COUNTER_gc_minor_malloc,
RB_DEBUG_COUNTER_gc_minor_method,
RB_DEBUG_COUNTER_gc_minor_capi,
RB_DEBUG_COUNTER_gc_minor_stress,
RB_DEBUG_COUNTER_gc_major_nofree,
RB_DEBUG_COUNTER_gc_major_oldgen,
RB_DEBUG_COUNTER_gc_major_shady,
RB_DEBUG_COUNTER_gc_major_force,
RB_DEBUG_COUNTER_gc_major_oldmalloc,

RB_DEBUG_COUNTER_gc_isptr_trial,
RB_DEBUG_COUNTER_gc_isptr_range,
RB_DEBUG_COUNTER_gc_isptr_align,
RB_DEBUG_COUNTER_gc_isptr_maybe,
RB_DEBUG_COUNTER_obj_newobj,
RB_DEBUG_COUNTER_obj_newobj_slowpath,
RB_DEBUG_COUNTER_obj_newobj_wb_unprotected,
RB_DEBUG_COUNTER_obj_free,
RB_DEBUG_COUNTER_obj_promote,
RB_DEBUG_COUNTER_obj_wb_unprotect,

RB_DEBUG_COUNTER_obj_obj_embed,
RB_DEBUG_COUNTER_obj_obj_transient,
RB_DEBUG_COUNTER_obj_obj_ptr,

RB_DEBUG_COUNTER_obj_str_ptr,
RB_DEBUG_COUNTER_obj_str_embed,
RB_DEBUG_COUNTER_obj_str_shared,
RB_DEBUG_COUNTER_obj_str_nofree,
RB_DEBUG_COUNTER_obj_str_fstr,

RB_DEBUG_COUNTER_obj_ary_embed,
RB_DEBUG_COUNTER_obj_ary_transient,
RB_DEBUG_COUNTER_obj_ary_ptr,
RB_DEBUG_COUNTER_obj_ary_extracapa,






RB_DEBUG_COUNTER_obj_ary_shared_create,
RB_DEBUG_COUNTER_obj_ary_shared,
RB_DEBUG_COUNTER_obj_ary_shared_root_occupied,

RB_DEBUG_COUNTER_obj_hash_empty,
RB_DEBUG_COUNTER_obj_hash_1,
RB_DEBUG_COUNTER_obj_hash_2,
RB_DEBUG_COUNTER_obj_hash_3,
RB_DEBUG_COUNTER_obj_hash_4,
RB_DEBUG_COUNTER_obj_hash_5_8,
RB_DEBUG_COUNTER_obj_hash_g8,

RB_DEBUG_COUNTER_obj_hash_null,
RB_DEBUG_COUNTER_obj_hash_ar,
RB_DEBUG_COUNTER_obj_hash_st,
RB_DEBUG_COUNTER_obj_hash_transient,
RB_DEBUG_COUNTER_obj_hash_force_convert,

RB_DEBUG_COUNTER_obj_struct_embed,
RB_DEBUG_COUNTER_obj_struct_transient,
RB_DEBUG_COUNTER_obj_struct_ptr,

RB_DEBUG_COUNTER_obj_data_empty,
RB_DEBUG_COUNTER_obj_data_xfree,
RB_DEBUG_COUNTER_obj_data_imm_free,
RB_DEBUG_COUNTER_obj_data_zombie,

RB_DEBUG_COUNTER_obj_match_under4,
RB_DEBUG_COUNTER_obj_match_ge4,
RB_DEBUG_COUNTER_obj_match_ge8,
RB_DEBUG_COUNTER_obj_match_ptr,

RB_DEBUG_COUNTER_obj_iclass_ptr,
RB_DEBUG_COUNTER_obj_class_ptr,
RB_DEBUG_COUNTER_obj_module_ptr,

RB_DEBUG_COUNTER_obj_bignum_ptr,
RB_DEBUG_COUNTER_obj_bignum_embed,
RB_DEBUG_COUNTER_obj_float,
RB_DEBUG_COUNTER_obj_complex,
RB_DEBUG_COUNTER_obj_rational,

RB_DEBUG_COUNTER_obj_regexp_ptr,
RB_DEBUG_COUNTER_obj_file_ptr,
RB_DEBUG_COUNTER_obj_symbol,

RB_DEBUG_COUNTER_obj_imemo_ment,
RB_DEBUG_COUNTER_obj_imemo_iseq,
RB_DEBUG_COUNTER_obj_imemo_env,
RB_DEBUG_COUNTER_obj_imemo_tmpbuf,
RB_DEBUG_COUNTER_obj_imemo_ast,
RB_DEBUG_COUNTER_obj_imemo_cref,
RB_DEBUG_COUNTER_obj_imemo_svar,
RB_DEBUG_COUNTER_obj_imemo_throw_data,
RB_DEBUG_COUNTER_obj_imemo_ifunc,
RB_DEBUG_COUNTER_obj_imemo_memo,
RB_DEBUG_COUNTER_obj_imemo_parser_strterm,


RB_DEBUG_COUNTER_artable_hint_hit,
RB_DEBUG_COUNTER_artable_hint_miss,
RB_DEBUG_COUNTER_artable_hint_notfound,





RB_DEBUG_COUNTER_heap_xmalloc,
RB_DEBUG_COUNTER_heap_xrealloc,
RB_DEBUG_COUNTER_heap_xfree,


RB_DEBUG_COUNTER_theap_alloc,
RB_DEBUG_COUNTER_theap_alloc_fail,
RB_DEBUG_COUNTER_theap_evacuate,


RB_DEBUG_COUNTER_mjit_exec,
RB_DEBUG_COUNTER_mjit_exec_not_added,
RB_DEBUG_COUNTER_mjit_exec_not_added_add_iseq,
RB_DEBUG_COUNTER_mjit_exec_not_ready,
RB_DEBUG_COUNTER_mjit_exec_not_compiled,
RB_DEBUG_COUNTER_mjit_exec_call_func,


RB_DEBUG_COUNTER_mjit_frame_VM2VM,
RB_DEBUG_COUNTER_mjit_frame_VM2JT,
RB_DEBUG_COUNTER_mjit_frame_JT2JT,
RB_DEBUG_COUNTER_mjit_frame_JT2VM,


RB_DEBUG_COUNTER_mjit_cancel,
RB_DEBUG_COUNTER_mjit_cancel_ivar_inline,
RB_DEBUG_COUNTER_mjit_cancel_send_inline,
RB_DEBUG_COUNTER_mjit_cancel_opt_insn,
RB_DEBUG_COUNTER_mjit_cancel_invalidate_all,


RB_DEBUG_COUNTER_mjit_length_unit_queue,
RB_DEBUG_COUNTER_mjit_length_active_units,
RB_DEBUG_COUNTER_mjit_length_compact_units,
RB_DEBUG_COUNTER_mjit_length_stale_units,


RB_DEBUG_COUNTER_mjit_compile_failures,
 RB_DEBUG_COUNTER_MAX
};


void rb_debug_counter_show_results(const char *msg);


size_t ruby_debug_counter_get(const char **names_ptr, size_t *counters_ptr);
void ruby_debug_counter_reset(void);
void ruby_debug_counter_show_at_exit(int enable);






enum rb_mjit_iseq_func {

    NOT_ADDED_JIT_ISEQ_FUNC = 0,


    NOT_READY_JIT_ISEQ_FUNC = 1,


    NOT_COMPILED_JIT_ISEQ_FUNC = 2,

    LAST_JIT_ISEQ_FUNC = 3
};


struct mjit_options {


    char on;



    char save_temps;

    char warnings;


    char debug;

    char* debug_flags;

    unsigned int wait;

    unsigned int min_calls;


    int verbose;


    int max_cache_size;
};


struct rb_mjit_compile_info {

    _Bool disable_ivar_cache;

    _Bool disable_send_cache;

    _Bool disable_inlining;
};

typedef VALUE (*mjit_func_t)(rb_execution_context_t *, rb_control_frame_t *);

extern struct mjit_options mjit_opts;
extern _Bool mjit_call_p;

extern void rb_mjit_add_iseq_to_process(const rb_iseq_t *iseq);
extern VALUE rb_mjit_wait_call(rb_execution_context_t *ec, struct rb_iseq_constant_body *body);
extern struct rb_mjit_compile_info* rb_mjit_iseq_compile_info(const struct rb_iseq_constant_body *body);
extern void rb_mjit_recompile_iseq(const rb_iseq_t *iseq);

extern _Bool mjit_compile(FILE *f, const rb_iseq_t *iseq, const char *funcname);
extern void mjit_init(const struct mjit_options *opts);
extern void mjit_gc_start_hook(void);
extern void mjit_gc_exit_hook(void);
extern void mjit_free_iseq(const rb_iseq_t *iseq);
extern void mjit_update_references(const rb_iseq_t *iseq);
extern void mjit_mark(void);
extern struct mjit_cont *mjit_cont_new(rb_execution_context_t *ec);
extern void mjit_cont_free(struct mjit_cont *cont);
extern void mjit_add_class_serial(rb_serial_t class_serial);
extern void mjit_remove_class_serial(rb_serial_t class_serial);





static inline int
mjit_target_iseq_p(struct rb_iseq_constant_body *body)
{
    return (body->type == ISEQ_TYPE_METHOD || body->type == ISEQ_TYPE_BLOCK)
        && body->iseq_size < 1000;
}



static inline VALUE
mjit_exec(rb_execution_context_t *ec)
{
    const rb_iseq_t *iseq;
    struct rb_iseq_constant_body *body;
    long unsigned total_calls;
    mjit_func_t func;

    if (!mjit_call_p)
        return ((VALUE)RUBY_Qundef);
    ((void)0);

    iseq = ec->cfp->iseq;
    body = iseq->body;
    total_calls = ++body->total_calls;

    func = body->jit_func;
    if ((__builtin_expect(!!((uintptr_t)func <= (uintptr_t)LAST_JIT_ISEQ_FUNC), 0))) {

        ((void)0);



        switch ((enum rb_mjit_iseq_func)func) {
          case NOT_ADDED_JIT_ISEQ_FUNC:
            ((void)0);
            if (total_calls == mjit_opts.min_calls && mjit_target_iseq_p(body)) {
                ((void)0);
                rb_mjit_add_iseq_to_process(iseq);
                if ((__builtin_expect(!!(mjit_opts.wait), 0))) {
                    return rb_mjit_wait_call(ec, body);
                }
            }
            return ((VALUE)RUBY_Qundef);
          case NOT_READY_JIT_ISEQ_FUNC:
            ((void)0);
            return ((VALUE)RUBY_Qundef);
          case NOT_COMPILED_JIT_ISEQ_FUNC:
            ((void)0);
            return ((VALUE)RUBY_Qundef);
          default:
            break;
        }
    }


      ((void)0);



    ((void)0);
    return func(ec, ec->cfp);
}

void mjit_child_after_fork(void);


extern VALUE ruby_vm_const_missing_count;
extern rb_serial_t ruby_vm_global_method_state;
extern rb_serial_t ruby_vm_global_constant_state;
extern rb_serial_t ruby_vm_class_serial;








































static inline void
CC_SET_FASTPATH(CALL_CACHE cc, vm_call_handler func, _Bool enabled)
{
    if ((__builtin_expect(!!(enabled), 1))) {
        cc->call = func;
    }
}

static inline void
CC_SET_ME(CALL_CACHE cc, const rb_callable_method_entry_t *me)
{
    cc->me = me;
    cc->method_serial = me ? me->def->method_serial : 0;
}


static inline struct vm_throw_data *
THROW_DATA_NEW(VALUE val, const rb_control_frame_t *cf, int st)
{
    struct vm_throw_data *obj = (struct vm_throw_data *)rb_imemo_new(imemo_throw_data, val, (VALUE)cf, 0, 0);
    obj->throw_state = st;
    return obj;
}

static inline VALUE
THROW_DATA_VAL(const struct vm_throw_data *obj)
{
    ((void)0);
    return obj->throw_obj;
}

static inline const rb_control_frame_t *
THROW_DATA_CATCH_FRAME(const struct vm_throw_data *obj)
{
    ((void)0);
    return obj->catch_frame;
}

static inline int
THROW_DATA_STATE(const struct vm_throw_data *obj)
{
    ((void)0);
    return obj->throw_state;
}

static inline int
THROW_DATA_CONSUMED_P(const struct vm_throw_data *obj)
{
    ((void)0);
    return obj->flags & ((VALUE)RUBY_FL_USER4);
}

static inline void
THROW_DATA_CATCH_FRAME_SET(struct vm_throw_data *obj, const rb_control_frame_t *cfp)
{
    ((void)0);
    obj->catch_frame = cfp;
}

static inline void
THROW_DATA_STATE_SET(struct vm_throw_data *obj, int st)
{
    ((void)0);
    obj->throw_state = st;
}

static inline void
THROW_DATA_CONSUMED_SET(struct vm_throw_data *obj)
{
    if (( ((RUBY_T_IMEMO) == RUBY_T_FIXNUM) ? (((int)(long)((VALUE)(obj)))&RUBY_FIXNUM_FLAG) : ((RUBY_T_IMEMO) == RUBY_T_TRUE) ? (((VALUE)(obj)) == ((VALUE)RUBY_Qtrue)) : ((RUBY_T_IMEMO) == RUBY_T_FALSE) ? (((VALUE)(obj)) == ((VALUE)RUBY_Qfalse)) : ((RUBY_T_IMEMO) == RUBY_T_NIL) ? (((VALUE)(obj)) == ((VALUE)RUBY_Qnil)) : ((RUBY_T_IMEMO) == RUBY_T_UNDEF) ? (((VALUE)(obj)) == ((VALUE)RUBY_Qundef)) : ((RUBY_T_IMEMO) == RUBY_T_SYMBOL) ? ((((VALUE)((VALUE)(obj))&~((~(VALUE)0)<<RUBY_SPECIAL_SHIFT)) == RUBY_SYMBOL_FLAG)||(!(((VALUE)((VALUE)(obj)) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)((VALUE)(obj)) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)((VALUE)(obj)))->flags & RUBY_T_MASK) == (RUBY_T_SYMBOL))) : ((RUBY_T_IMEMO) == RUBY_T_FLOAT) ? ( ((((int)(long)((VALUE)(obj)))&RUBY_FLONUM_MASK) == RUBY_FLONUM_FLAG) || (!(((VALUE)((VALUE)(obj)) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)((VALUE)(obj)) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)((VALUE)(obj)))->flags & RUBY_T_MASK) == RUBY_T_FLOAT)) : (!(((VALUE)((VALUE)(obj)) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)((VALUE)(obj)) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)((VALUE)(obj)))->flags & RUBY_T_MASK) == (RUBY_T_IMEMO))) &&
 THROW_DATA_STATE(obj) == RUBY_TAG_BREAK) {
 obj->flags |= ((VALUE)RUBY_FL_USER4);
    }
}




static _Bool
vm_call_iseq_optimizable_p(const struct rb_call_info *ci, const struct rb_call_cache *cc)
{
    return !((ci)->flag & (0x01 << VM_CALL_ARGS_SPLAT_bit)) && !((ci)->flag & (0x01 << VM_CALL_KWARG_bit)) &&
        !((rb_method_visibility_t)(((cc->me)->flags & (((VALUE)RUBY_FL_USER4) | ((VALUE)RUBY_FL_USER5))) >> ((((VALUE)RUBY_FL_USHIFT) + 4)+0)) == METHOD_VISI_PROTECTED);
}

typedef long OFFSET;
typedef unsigned long lindex_t;
typedef VALUE GENTRY;
typedef rb_iseq_t *ISEQ;






































enum ruby_vminsn_type {
    YARVINSN_nop,
    YARVINSN_getlocal,
    YARVINSN_setlocal,
    YARVINSN_getblockparam,
    YARVINSN_setblockparam,
    YARVINSN_getblockparamproxy,
    YARVINSN_getspecial,
    YARVINSN_setspecial,
    YARVINSN_getinstancevariable,
    YARVINSN_setinstancevariable,
    YARVINSN_getclassvariable,
    YARVINSN_setclassvariable,
    YARVINSN_getconstant,
    YARVINSN_setconstant,
    YARVINSN_getglobal,
    YARVINSN_setglobal,
    YARVINSN_putnil,
    YARVINSN_putself,
    YARVINSN_putobject,
    YARVINSN_putspecialobject,
    YARVINSN_putstring,
    YARVINSN_concatstrings,
    YARVINSN_tostring,
    YARVINSN_freezestring,
    YARVINSN_toregexp,
    YARVINSN_intern,
    YARVINSN_newarray,
    YARVINSN_newarraykwsplat,
    YARVINSN_duparray,
    YARVINSN_duphash,
    YARVINSN_expandarray,
    YARVINSN_concatarray,
    YARVINSN_splatarray,
    YARVINSN_newhash,
    YARVINSN_newrange,
    YARVINSN_pop,
    YARVINSN_dup,
    YARVINSN_dupn,
    YARVINSN_swap,
    YARVINSN_reverse,
    YARVINSN_topn,
    YARVINSN_setn,
    YARVINSN_adjuststack,
    YARVINSN_defined,
    YARVINSN_checkmatch,
    YARVINSN_checkkeyword,
    YARVINSN_checktype,
    YARVINSN_defineclass,
    YARVINSN_definemethod,
    YARVINSN_definesmethod,
    YARVINSN_send,
    YARVINSN_opt_send_without_block,
    YARVINSN_opt_str_freeze,
    YARVINSN_opt_nil_p,
    YARVINSN_opt_str_uminus,
    YARVINSN_opt_newarray_max,
    YARVINSN_opt_newarray_min,
    YARVINSN_invokesuper,
    YARVINSN_invokeblock,
    YARVINSN_leave,
    YARVINSN_throw,
    YARVINSN_jump,
    YARVINSN_branchif,
    YARVINSN_branchunless,
    YARVINSN_branchnil,
    YARVINSN_opt_getinlinecache,
    YARVINSN_opt_setinlinecache,
    YARVINSN_once,
    YARVINSN_opt_case_dispatch,
    YARVINSN_opt_plus,
    YARVINSN_opt_minus,
    YARVINSN_opt_mult,
    YARVINSN_opt_div,
    YARVINSN_opt_mod,
    YARVINSN_opt_eq,
    YARVINSN_opt_neq,
    YARVINSN_opt_lt,
    YARVINSN_opt_le,
    YARVINSN_opt_gt,
    YARVINSN_opt_ge,
    YARVINSN_opt_ltlt,
    YARVINSN_opt_and,
    YARVINSN_opt_or,
    YARVINSN_opt_aref,
    YARVINSN_opt_aset,
    YARVINSN_opt_aset_with,
    YARVINSN_opt_aref_with,
    YARVINSN_opt_length,
    YARVINSN_opt_size,
    YARVINSN_opt_empty_p,
    YARVINSN_opt_succ,
    YARVINSN_opt_not,
    YARVINSN_opt_regexpmatch2,
    YARVINSN_opt_call_c_function,
    YARVINSN_invokebuiltin,
    YARVINSN_opt_invokebuiltin_delegate,
    YARVINSN_opt_invokebuiltin_delegate_leave,
    YARVINSN_getlocal_WC_0,
    YARVINSN_getlocal_WC_1,
    YARVINSN_setlocal_WC_0,
    YARVINSN_setlocal_WC_1,
    YARVINSN_putobject_INT2FIX_0_,
    YARVINSN_putobject_INT2FIX_1_,
    YARVINSN_trace_nop,
    YARVINSN_trace_getlocal,
    YARVINSN_trace_setlocal,
    YARVINSN_trace_getblockparam,
    YARVINSN_trace_setblockparam,
    YARVINSN_trace_getblockparamproxy,
    YARVINSN_trace_getspecial,
    YARVINSN_trace_setspecial,
    YARVINSN_trace_getinstancevariable,
    YARVINSN_trace_setinstancevariable,
    YARVINSN_trace_getclassvariable,
    YARVINSN_trace_setclassvariable,
    YARVINSN_trace_getconstant,
    YARVINSN_trace_setconstant,
    YARVINSN_trace_getglobal,
    YARVINSN_trace_setglobal,
    YARVINSN_trace_putnil,
    YARVINSN_trace_putself,
    YARVINSN_trace_putobject,
    YARVINSN_trace_putspecialobject,
    YARVINSN_trace_putstring,
    YARVINSN_trace_concatstrings,
    YARVINSN_trace_tostring,
    YARVINSN_trace_freezestring,
    YARVINSN_trace_toregexp,
    YARVINSN_trace_intern,
    YARVINSN_trace_newarray,
    YARVINSN_trace_newarraykwsplat,
    YARVINSN_trace_duparray,
    YARVINSN_trace_duphash,
    YARVINSN_trace_expandarray,
    YARVINSN_trace_concatarray,
    YARVINSN_trace_splatarray,
    YARVINSN_trace_newhash,
    YARVINSN_trace_newrange,
    YARVINSN_trace_pop,
    YARVINSN_trace_dup,
    YARVINSN_trace_dupn,
    YARVINSN_trace_swap,
    YARVINSN_trace_reverse,
    YARVINSN_trace_topn,
    YARVINSN_trace_setn,
    YARVINSN_trace_adjuststack,
    YARVINSN_trace_defined,
    YARVINSN_trace_checkmatch,
    YARVINSN_trace_checkkeyword,
    YARVINSN_trace_checktype,
    YARVINSN_trace_defineclass,
    YARVINSN_trace_definemethod,
    YARVINSN_trace_definesmethod,
    YARVINSN_trace_send,
    YARVINSN_trace_opt_send_without_block,
    YARVINSN_trace_opt_str_freeze,
    YARVINSN_trace_opt_nil_p,
    YARVINSN_trace_opt_str_uminus,
    YARVINSN_trace_opt_newarray_max,
    YARVINSN_trace_opt_newarray_min,
    YARVINSN_trace_invokesuper,
    YARVINSN_trace_invokeblock,
    YARVINSN_trace_leave,
    YARVINSN_trace_throw,
    YARVINSN_trace_jump,
    YARVINSN_trace_branchif,
    YARVINSN_trace_branchunless,
    YARVINSN_trace_branchnil,
    YARVINSN_trace_opt_getinlinecache,
    YARVINSN_trace_opt_setinlinecache,
    YARVINSN_trace_once,
    YARVINSN_trace_opt_case_dispatch,
    YARVINSN_trace_opt_plus,
    YARVINSN_trace_opt_minus,
    YARVINSN_trace_opt_mult,
    YARVINSN_trace_opt_div,
    YARVINSN_trace_opt_mod,
    YARVINSN_trace_opt_eq,
    YARVINSN_trace_opt_neq,
    YARVINSN_trace_opt_lt,
    YARVINSN_trace_opt_le,
    YARVINSN_trace_opt_gt,
    YARVINSN_trace_opt_ge,
    YARVINSN_trace_opt_ltlt,
    YARVINSN_trace_opt_and,
    YARVINSN_trace_opt_or,
    YARVINSN_trace_opt_aref,
    YARVINSN_trace_opt_aset,
    YARVINSN_trace_opt_aset_with,
    YARVINSN_trace_opt_aref_with,
    YARVINSN_trace_opt_length,
    YARVINSN_trace_opt_size,
    YARVINSN_trace_opt_empty_p,
    YARVINSN_trace_opt_succ,
    YARVINSN_trace_opt_not,
    YARVINSN_trace_opt_regexpmatch2,
    YARVINSN_trace_opt_call_c_function,
    YARVINSN_trace_invokebuiltin,
    YARVINSN_trace_opt_invokebuiltin_delegate,
    YARVINSN_trace_opt_invokebuiltin_delegate_leave,
    YARVINSN_trace_getlocal_WC_0,
    YARVINSN_trace_getlocal_WC_1,
    YARVINSN_trace_setlocal_WC_0,
    YARVINSN_trace_setlocal_WC_1,
    YARVINSN_trace_putobject_INT2FIX_0_,
    YARVINSN_trace_putobject_INT2FIX_1_,
    VM_INSTRUCTION_SIZE
};






typedef enum {
    CONST_DEPRECATED = 0x100,

    CONST_VISIBILITY_MASK = 0xff,
    CONST_PUBLIC = 0x00,
    CONST_PRIVATE,
    CONST_VISIBILITY_MAX
} rb_const_flag_t;






typedef struct rb_const_entry_struct {
    rb_const_flag_t flag;
    int line;
    VALUE value;
    VALUE file;
} rb_const_entry_t;

VALUE rb_mod_private_constant(int argc, const VALUE *argv, VALUE obj);
VALUE rb_mod_public_constant(int argc, const VALUE *argv, VALUE obj);
VALUE rb_mod_deprecate_constant(int argc, const VALUE *argv, VALUE obj);
void rb_free_const_table(struct rb_id_table *tbl);
VALUE rb_public_const_get_at(VALUE klass, ID id);
VALUE rb_public_const_get_from(VALUE klass, ID id);
int rb_public_const_defined_from(VALUE klass, ID id);
rb_const_entry_t *rb_const_lookup(VALUE klass, ID id);
int rb_autoloading_value(VALUE mod, ID id, VALUE *value, rb_const_flag_t *flag);
VALUE rb_const_source_location(VALUE, ID);
VALUE rb_const_source_location_at(VALUE, ID);





struct gen_ivtbl {
    uint32_t numiv;
    VALUE ivptr[];
};

struct st_table *rb_ivar_generic_ivtbl(void);

extern rb_method_definition_t *rb_method_definition_create(rb_method_type_t type, ID mid);
extern void rb_method_definition_set(const rb_method_entry_t *me, rb_method_definition_t *def, void *opts);
extern int rb_method_definition_eq(const rb_method_definition_t *d1, const rb_method_definition_t *d2);
extern VALUE rb_make_no_method_exception(VALUE exc, VALUE format, VALUE obj,
                                         int argc, const VALUE *argv, int priv);



static rb_control_frame_t *vm_get_ruby_level_caller_cfp(const rb_execution_context_t *ec, const rb_control_frame_t *cfp);

static VALUE
ruby_vm_special_exception_copy(VALUE exc)
{
    VALUE e = rb_obj_alloc(rb_class_real((((struct RBasic*)(exc))->klass)));
    rb_obj_copy_ivar(e, exc);
    return e;
}

__attribute__ ((__noreturn__)) static void ec_stack_overflow(rb_execution_context_t *ec, int);
static void
ec_stack_overflow(rb_execution_context_t *ec, int setup)
{
    VALUE mesg = rb_ec_vm_ptr(ec)->special_exceptions[ruby_error_sysstack];
    ec->raised_flag = RAISED_STACKOVERFLOW;
    if (setup) {
 VALUE at = rb_ec_backtrace_object(ec);
 mesg = ruby_vm_special_exception_copy(mesg);
 rb_ivar_set(mesg, idBt, at);
 rb_ivar_set(mesg, idBt_locations, at);
    }
    ec->errinfo = mesg;
    rb_ec_tag_jump(ec, RUBY_TAG_RAISE);
}

__attribute__ ((__noreturn__)) static void vm_stackoverflow(void);

static void
vm_stackoverflow(void)
{
    ec_stack_overflow(rb_current_execution_context(), 1);
}

__attribute__ ((__noreturn__)) static void rb_ec_stack_overflow(rb_execution_context_t *ec, int crit);
static void
rb_ec_stack_overflow(rb_execution_context_t *ec, int crit)
{
    if (crit || rb_during_gc()) {
 ec->raised_flag = RAISED_STACKOVERFLOW;
 ec->errinfo = rb_ec_vm_ptr(ec)->special_exceptions[ruby_error_stackfatal];
 rb_ec_tag_jump(ec, RUBY_TAG_RAISE);
    }

    ec_stack_overflow(ec, 1);



}


static inline rb_control_frame_t *
vm_push_frame(rb_execution_context_t *ec,
       const rb_iseq_t *iseq,
       VALUE type,
       VALUE self,
       VALUE specval,
       VALUE cref_or_me,
       const VALUE *pc,
       VALUE *sp,
       int local_size,
       int stack_max)
{
    rb_control_frame_t *const cfp = ((ec->cfp)-1);

                                                   ;
    ((void)0);


    if ((__builtin_expect(!!(!(!(1/!!(sizeof(*(sp)) == sizeof(VALUE))) || !(1/!!(sizeof(*(cfp)) == sizeof(rb_control_frame_t))) || ((rb_control_frame_t *)((sp) + (local_size + stack_max)) + 1) >= (cfp))), 1))) {(void)0;} else vm_stackoverflow();
                           ;

    ec->cfp = cfp;


    cfp->pc = (VALUE *)pc;
    cfp->iseq = (rb_iseq_t *)iseq;
    cfp->self = self;
    cfp->block_code = ((void*)0);




    for (int i=0; i < local_size; i++) {
 *sp++ = ((VALUE)RUBY_Qnil);
    }


    ((void)0);
    ((void)0);
    ((void)0);
    *sp++ = cref_or_me;
    *sp++ = specval ;
    *sp = type;


    cfp->ep = sp;
    cfp->__bp__ = cfp->sp = sp + 1;





    if (0 == 2) {
 rb_vmdebug_stack_dump_raw(rb_current_execution_context(), rb_current_execution_context()->cfp);
    }
    return cfp;
}


static inline int
vm_pop_frame(rb_execution_context_t *ec, rb_control_frame_t *cfp, const VALUE *ep)
{
    VALUE flags = ep[( 0)];

    if ((((0) > 0) ? (0) : 0) >= 4) rb_gc_verify_internal_consistency();
    if (0 == 2) rb_vmdebug_stack_dump_raw(rb_current_execution_context(), rb_current_execution_context()->cfp);

    rb_vm_check_ints(ec);
    ec->cfp = ((cfp)+1);

    return flags & VM_FRAME_FLAG_FINISH;
}

static void
rb_vm_pop_frame(rb_execution_context_t *ec)
{
    vm_pop_frame(ec, ec->cfp, ec->cfp->ep);
}


static inline VALUE
rb_arity_error_new(int argc, int min, int max)
{
    VALUE err_mess = 0;
    if (min == max) {
 err_mess = rb_sprintf("wrong number of arguments (given %d, expected %d)", argc, min);
    }
    else if (max == (-1)) {
 err_mess = rb_sprintf("wrong number of arguments (given %d, expected %d+)", argc, min);
    }
    else {
 err_mess = rb_sprintf("wrong number of arguments (given %d, expected %d..%d)", argc, min, max);
    }
    return rb_exc_new_str(rb_eArgError, err_mess);
}

static void
rb_error_arity(int argc, int min, int max)
{
    rb_exc_raise(rb_arity_error_new(argc, min, max));
}



__attribute__ ((__noinline__)) static void vm_env_write_slowpath(const VALUE *ep, int index, VALUE v);

static void
vm_env_write_slowpath(const VALUE *ep, int index, VALUE v)
{

    rb_gc_writebarrier_remember(VM_ENV_ENVVAL(ep));
    VM_FORCE_WRITE(&ep[index], v);
    VM_ENV_FLAGS_UNSET(ep, VM_ENV_FLAG_WB_REQUIRED);
    ((void)0);
}

static inline void
vm_env_write(const VALUE *ep, int index, VALUE v)
{
    VALUE flags = ep[( 0)];
    if ((__builtin_expect(!!((flags & VM_ENV_FLAG_WB_REQUIRED) == 0), 1))) {
 VM_STACK_ENV_WRITE(ep, index, v);
    }
    else {
 vm_env_write_slowpath(ep, index, v);
    }
}

static VALUE
rb_vm_bh_to_procval(const rb_execution_context_t *ec, VALUE block_handler)
{
    if (block_handler == 0) {
 return ((VALUE)RUBY_Qnil);
    }
    else {
 switch (vm_block_handler_type(block_handler)) {
   case block_handler_type_iseq:
   case block_handler_type_ifunc:
     return rb_vm_make_proc(ec, VM_BH_TO_CAPT_BLOCK(block_handler), rb_cProc);
   case block_handler_type_symbol:
     return rb_sym_to_proc(VM_BH_TO_SYMBOL(block_handler));
   case block_handler_type_proc:
     return VM_BH_TO_PROC(block_handler);
   default:
     __builtin_unreachable();
 }
    }
}
static inline struct vm_svar *
lep_svar(const rb_execution_context_t *ec, const VALUE *lep)
{
    VALUE svar;

    if (lep && (ec == ((void*)0) || ec->root_lep != lep)) {
 svar = lep[(-2)];
    }
    else {
 svar = ec->root_svar;
    }

    ((void)0);

    return (struct vm_svar *)svar;
}

static inline void
lep_svar_write(const rb_execution_context_t *ec, const VALUE *lep, const struct vm_svar *svar)
{
    ((void)0);

    if (lep && (ec == ((void*)0) || ec->root_lep != lep)) {
 vm_env_write(lep, (-2), (VALUE)svar);
    }
    else {
 __extension__({
;
; typeof(rb_obj_write((VALUE)(rb_ec_thread_ptr(ec)->self), (VALUE *)(&ec->root_svar), (VALUE)(svar), "./vm_insnhelper.c", 486)) unaligned_member_access_result = (rb_obj_write((VALUE)(rb_ec_thread_ptr(ec)->self), (VALUE *)(&ec->root_svar), (VALUE)(svar), "./vm_insnhelper.c", 486));
; unaligned_member_access_result; });
    }
}

static VALUE
lep_svar_get(const rb_execution_context_t *ec, const VALUE *lep, rb_num_t key)
{
    const struct vm_svar *svar = lep_svar(ec, lep);

    if ((VALUE)svar == ((VALUE)RUBY_Qfalse) || imemo_type((VALUE)svar) != imemo_svar) return ((VALUE)RUBY_Qnil);

    switch (key) {
      case VM_SVAR_LASTLINE:
 return svar->lastline;
      case VM_SVAR_BACKREF:
 return svar->backref;
      default: {
 const VALUE ary = svar->others;

 if (!((VALUE)(ary) != ((VALUE)RUBY_Qnil))) {
     return ((VALUE)RUBY_Qnil);
 }
 else {
     return rb_ary_entry(ary, key - VM_SVAR_EXTRA_START);
 }
      }
    }
}

static struct vm_svar *
svar_new(VALUE obj)
{
    return (struct vm_svar *)rb_imemo_new(imemo_svar, ((VALUE)RUBY_Qnil), ((VALUE)RUBY_Qnil), ((VALUE)RUBY_Qnil), obj);
}

static void
lep_svar_set(const rb_execution_context_t *ec, const VALUE *lep, rb_num_t key, VALUE val)
{
    struct vm_svar *svar = lep_svar(ec, lep);

    if ((VALUE)svar == ((VALUE)RUBY_Qfalse) || imemo_type((VALUE)svar) != imemo_svar) {
 lep_svar_write(ec, lep, svar = svar_new((VALUE)svar));
    }

    switch (key) {
      case VM_SVAR_LASTLINE:
 __extension__({
;
; typeof(rb_obj_write((VALUE)(svar), (VALUE *)(&svar->lastline), (VALUE)(val), "./vm_insnhelper.c", 532)) unaligned_member_access_result = (rb_obj_write((VALUE)(svar), (VALUE *)(&svar->lastline), (VALUE)(val), "./vm_insnhelper.c", 532));
; unaligned_member_access_result; });
 return;
      case VM_SVAR_BACKREF:
 __extension__({
;
; typeof(rb_obj_write((VALUE)(svar), (VALUE *)(&svar->backref), (VALUE)(val), "./vm_insnhelper.c", 535)) unaligned_member_access_result = (rb_obj_write((VALUE)(svar), (VALUE *)(&svar->backref), (VALUE)(val), "./vm_insnhelper.c", 535));
; unaligned_member_access_result; });
 return;
      default: {
 VALUE ary = svar->others;

 if (!((VALUE)(ary) != ((VALUE)RUBY_Qnil))) {
     __extension__({
;
; typeof(rb_obj_write((VALUE)(svar), (VALUE *)(&svar->others), (VALUE)(ary = rb_ary_new()), "./vm_insnhelper.c", 541)) unaligned_member_access_result = (rb_obj_write((VALUE)(svar), (VALUE *)(&svar->others), (VALUE)(ary = rb_ary_new()), "./vm_insnhelper.c", 541));
; unaligned_member_access_result; });
 }
 rb_ary_store(ary, key - VM_SVAR_EXTRA_START, val);
      }
    }
}

static inline VALUE
vm_getspecial(const rb_execution_context_t *ec, const VALUE *lep, rb_num_t key, rb_num_t type)
{
    VALUE val;

    if (type == 0) {
 val = lep_svar_get(ec, lep, key);
    }
    else {
 VALUE backref = lep_svar_get(ec, lep, VM_SVAR_BACKREF);

 if (type & 0x01) {
     switch (type >> 1) {
       case '&':
  val = rb_reg_last_match(backref);
  break;
       case '`':
  val = rb_reg_match_pre(backref);
  break;
       case '\'':
  val = rb_reg_match_post(backref);
  break;
       case '+':
  val = rb_reg_match_last(backref);
  break;
       default:
  rb_bug("unexpected back-ref");
     }
 }
 else {
     val = rb_reg_nth_match((int)(type >> 1), backref);
 }
    }
    return val;
}

__attribute__ ((__pure__)) static rb_callable_method_entry_t *check_method_entry(VALUE obj, int can_be_svar);
static rb_callable_method_entry_t *
check_method_entry(VALUE obj, int can_be_svar)
{
    if (obj == ((VALUE)RUBY_Qfalse)) return ((void*)0);





    switch (imemo_type(obj)) {
      case imemo_ment:
 return (rb_callable_method_entry_t *)obj;
      case imemo_cref:
 return ((void*)0);
      case imemo_svar:
 if (can_be_svar) {
     return check_method_entry(((struct vm_svar *)obj)->cref_or_me, 0);
 }
      default:



 return ((void*)0);
    }
}

static const rb_callable_method_entry_t *
rb_vm_frame_method_entry(const rb_control_frame_t *cfp)
{
    const VALUE *ep = cfp->ep;
    rb_callable_method_entry_t *me;

    while (!VM_ENV_LOCAL_P(ep)) {
 if ((me = check_method_entry(ep[(-2)], 0)) != ((void*)0)) return me;
 ep = VM_ENV_PREV_EP(ep);
    }

    return check_method_entry(ep[(-2)], 1);
}

static rb_cref_t *
method_entry_cref(rb_callable_method_entry_t *me)
{
    switch (me->def->type) {
      case VM_METHOD_TYPE_ISEQ:
 return me->def->body.iseq.cref;
      default:
 return ((void*)0);
    }
}


__attribute__ ((__pure__)) static rb_cref_t *check_cref(VALUE, int);

static rb_cref_t *
check_cref(VALUE obj, int can_be_svar)
{
    if (obj == ((VALUE)RUBY_Qfalse)) return ((void*)0);





    switch (imemo_type(obj)) {
      case imemo_ment:
 return method_entry_cref((rb_callable_method_entry_t *)obj);
      case imemo_cref:
 return (rb_cref_t *)obj;
      case imemo_svar:
 if (can_be_svar) {
     return check_cref(((struct vm_svar *)obj)->cref_or_me, 0);
 }
      default:



 return ((void*)0);
    }
}

static inline rb_cref_t *
vm_env_cref(const VALUE *ep)
{
    rb_cref_t *cref;

    while (!VM_ENV_LOCAL_P(ep)) {
 if ((cref = check_cref(ep[(-2)], 0)) != ((void*)0)) return cref;
 ep = VM_ENV_PREV_EP(ep);
    }

    return check_cref(ep[(-2)], 1);
}

static int
is_cref(const VALUE v, int can_be_svar)
{
    if (( ((RUBY_T_IMEMO) == RUBY_T_FIXNUM) ? (((int)(long)(v))&RUBY_FIXNUM_FLAG) : ((RUBY_T_IMEMO) == RUBY_T_TRUE) ? ((v) == ((VALUE)RUBY_Qtrue)) : ((RUBY_T_IMEMO) == RUBY_T_FALSE) ? ((v) == ((VALUE)RUBY_Qfalse)) : ((RUBY_T_IMEMO) == RUBY_T_NIL) ? ((v) == ((VALUE)RUBY_Qnil)) : ((RUBY_T_IMEMO) == RUBY_T_UNDEF) ? ((v) == ((VALUE)RUBY_Qundef)) : ((RUBY_T_IMEMO) == RUBY_T_SYMBOL) ? ((((VALUE)(v)&~((~(VALUE)0)<<RUBY_SPECIAL_SHIFT)) == RUBY_SYMBOL_FLAG)||(!(((VALUE)(v) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(v) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(v))->flags & RUBY_T_MASK) == (RUBY_T_SYMBOL))) : ((RUBY_T_IMEMO) == RUBY_T_FLOAT) ? ( ((((int)(long)(v))&RUBY_FLONUM_MASK) == RUBY_FLONUM_FLAG) || (!(((VALUE)(v) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(v) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(v))->flags & RUBY_T_MASK) == RUBY_T_FLOAT)) : (!(((VALUE)(v) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(v) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(v))->flags & RUBY_T_MASK) == (RUBY_T_IMEMO)))) {
 switch (imemo_type(v)) {
   case imemo_cref:
     return 1;
   case imemo_svar:
     if (can_be_svar) return is_cref(((struct vm_svar *)v)->cref_or_me, 0);
   default:
     break;
 }
    }
    return 0;
}

static int
vm_env_cref_by_cref(const VALUE *ep)
{
    while (!VM_ENV_LOCAL_P(ep)) {
 if (is_cref(ep[(-2)], 0)) return 1;
 ep = VM_ENV_PREV_EP(ep);
    }
    return is_cref(ep[(-2)], 1);
}

static rb_cref_t *
cref_replace_with_duplicated_cref_each_frame(const VALUE *vptr, int can_be_svar, VALUE parent)
{
    const VALUE v = *vptr;
    rb_cref_t *cref, *new_cref;

    if (( ((RUBY_T_IMEMO) == RUBY_T_FIXNUM) ? (((int)(long)(v))&RUBY_FIXNUM_FLAG) : ((RUBY_T_IMEMO) == RUBY_T_TRUE) ? ((v) == ((VALUE)RUBY_Qtrue)) : ((RUBY_T_IMEMO) == RUBY_T_FALSE) ? ((v) == ((VALUE)RUBY_Qfalse)) : ((RUBY_T_IMEMO) == RUBY_T_NIL) ? ((v) == ((VALUE)RUBY_Qnil)) : ((RUBY_T_IMEMO) == RUBY_T_UNDEF) ? ((v) == ((VALUE)RUBY_Qundef)) : ((RUBY_T_IMEMO) == RUBY_T_SYMBOL) ? ((((VALUE)(v)&~((~(VALUE)0)<<RUBY_SPECIAL_SHIFT)) == RUBY_SYMBOL_FLAG)||(!(((VALUE)(v) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(v) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(v))->flags & RUBY_T_MASK) == (RUBY_T_SYMBOL))) : ((RUBY_T_IMEMO) == RUBY_T_FLOAT) ? ( ((((int)(long)(v))&RUBY_FLONUM_MASK) == RUBY_FLONUM_FLAG) || (!(((VALUE)(v) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(v) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(v))->flags & RUBY_T_MASK) == RUBY_T_FLOAT)) : (!(((VALUE)(v) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(v) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(v))->flags & RUBY_T_MASK) == (RUBY_T_IMEMO)))) {
 switch (imemo_type(v)) {
   case imemo_cref:
     cref = (rb_cref_t *)v;
     new_cref = vm_cref_dup(cref);
     if (parent) {
  __extension__({
;
; typeof(rb_obj_write((VALUE)(parent), (VALUE *)(vptr), (VALUE)(new_cref), "./vm_insnhelper.c", 716)) unaligned_member_access_result = (rb_obj_write((VALUE)(parent), (VALUE *)(vptr), (VALUE)(new_cref), "./vm_insnhelper.c", 716));
; unaligned_member_access_result; });
     }
     else {
  VM_FORCE_WRITE(vptr, (VALUE)new_cref);
     }
     return (rb_cref_t *)new_cref;
   case imemo_svar:
     if (can_be_svar) {
  return cref_replace_with_duplicated_cref_each_frame((const VALUE *)&((struct vm_svar *)v)->cref_or_me, 0, v);
     }

   case imemo_ment:
     rb_bug("cref_replace_with_duplicated_cref_each_frame: unreachable");
   default:
     break;
 }
    }
    return 0;
}

static rb_cref_t *
vm_cref_replace_with_duplicated_cref(const VALUE *ep)
{
    if (vm_env_cref_by_cref(ep)) {
 rb_cref_t *cref;
 VALUE envval;

 while (!VM_ENV_LOCAL_P(ep)) {
     envval = VM_ENV_ESCAPED_P(ep) ? VM_ENV_ENVVAL(ep) : ((VALUE)RUBY_Qfalse);
     if ((cref = cref_replace_with_duplicated_cref_each_frame(&ep[(-2)], 0, envval)) != ((void*)0)) {
  return cref;
     }
     ep = VM_ENV_PREV_EP(ep);
 }
 envval = VM_ENV_ESCAPED_P(ep) ? VM_ENV_ENVVAL(ep) : ((VALUE)RUBY_Qfalse);
 return cref_replace_with_duplicated_cref_each_frame(&ep[(-2)], 1, envval);
    }
    else {
 rb_bug("vm_cref_dup: unreachable");
    }
}

static rb_cref_t *
vm_get_cref(const VALUE *ep)
{
    rb_cref_t *cref = vm_env_cref(ep);

    if (cref != ((void*)0)) {
 return cref;
    }
    else {
        rb_bug("vm_get_cref: unreachable");
    }
}

static rb_cref_t *
vm_ec_cref(const rb_execution_context_t *ec)
{
    const rb_control_frame_t *cfp = rb_vm_get_ruby_level_next_cfp(ec, ec->cfp);

    if (cfp == ((void*)0)) {
        return ((void*)0);
    }
    return vm_get_cref(cfp->ep);
}

static const rb_cref_t *
vm_get_const_key_cref(const VALUE *ep)
{
    const rb_cref_t *cref = vm_get_cref(ep);
    const rb_cref_t *key_cref = cref;

    while (cref) {
        if (((!(((VALUE)(CREF_CLASS(cref)) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(CREF_CLASS(cref)) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(CREF_CLASS(cref)))->flags & RUBY_T_MASK) != RUBY_T_NODE)?(((struct RBasic*)((CREF_CLASS(cref))))->flags&((((VALUE)RUBY_FL_SINGLETON)))):0) ||
            ((!(((VALUE)(CREF_CLASS(cref)) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(CREF_CLASS(cref)) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(CREF_CLASS(cref)))->flags & RUBY_T_MASK) != RUBY_T_NODE)?(((struct RBasic*)((CREF_CLASS(cref))))->flags&((((VALUE)RUBY_FL_USER6)))):0)) {
            return key_cref;
 }
 cref = CREF_NEXT(cref);
    }


    return ((void*)0);
}static inline 

void
rb_vm_rewrite_cref(rb_cref_t *cref, VALUE old_klass, VALUE new_klass, rb_cref_t **new_cref_ptr)
{
    rb_cref_t *new_cref;

    while (cref) {
 if (CREF_CLASS(cref) == old_klass) {
     new_cref = vm_cref_new_use_prev(new_klass, METHOD_VISI_UNDEF, 0, cref, 0);
     *new_cref_ptr = new_cref;
     return;
 }
 new_cref = vm_cref_new_use_prev(CREF_CLASS(cref), METHOD_VISI_UNDEF, 0, cref, 0);
 cref = CREF_NEXT(cref);
 *new_cref_ptr = new_cref;
 new_cref_ptr = (rb_cref_t **)&new_cref->next;
    }
    *new_cref_ptr = ((void*)0);
}

static rb_cref_t *
vm_cref_push(const rb_execution_context_t *ec, VALUE klass, const VALUE *ep, int pushed_by_eval)
{
    rb_cref_t *prev_cref = ((void*)0);

    if (ep) {
 prev_cref = vm_env_cref(ep);
    }
    else {
 rb_control_frame_t *cfp = vm_get_ruby_level_caller_cfp(ec, ec->cfp);

 if (cfp) {
     prev_cref = vm_env_cref(cfp->ep);
 }
    }

    return vm_cref_new(klass, METHOD_VISI_PUBLIC, 0, prev_cref, pushed_by_eval);
}

static inline VALUE
vm_get_cbase(const VALUE *ep)
{
    const rb_cref_t *cref = vm_get_cref(ep);
    VALUE klass = ((VALUE)RUBY_Qundef);

    while (cref) {
 if ((klass = CREF_CLASS(cref)) != 0) {
     break;
 }
 cref = CREF_NEXT(cref);
    }

    return klass;
}

static inline VALUE
vm_get_const_base(const VALUE *ep)
{
    const rb_cref_t *cref = vm_get_cref(ep);
    VALUE klass = ((VALUE)RUBY_Qundef);

    while (cref) {
 if (!CREF_PUSHED_BY_EVAL(cref) &&
     (klass = CREF_CLASS(cref)) != 0) {
     break;
 }
 cref = CREF_NEXT(cref);
    }

    return klass;
}

static inline void
vm_check_if_namespace(VALUE klass)
{
    if (!( ((RUBY_T_CLASS) == RUBY_T_FIXNUM) ? (((int)(long)(klass))&RUBY_FIXNUM_FLAG) : ((RUBY_T_CLASS) == RUBY_T_TRUE) ? ((klass) == ((VALUE)RUBY_Qtrue)) : ((RUBY_T_CLASS) == RUBY_T_FALSE) ? ((klass) == ((VALUE)RUBY_Qfalse)) : ((RUBY_T_CLASS) == RUBY_T_NIL) ? ((klass) == ((VALUE)RUBY_Qnil)) : ((RUBY_T_CLASS) == RUBY_T_UNDEF) ? ((klass) == ((VALUE)RUBY_Qundef)) : ((RUBY_T_CLASS) == RUBY_T_SYMBOL) ? ((((VALUE)(klass)&~((~(VALUE)0)<<RUBY_SPECIAL_SHIFT)) == RUBY_SYMBOL_FLAG)||(!(((VALUE)(klass) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(klass) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(klass))->flags & RUBY_T_MASK) == (RUBY_T_SYMBOL))) : ((RUBY_T_CLASS) == RUBY_T_FLOAT) ? ( ((((int)(long)(klass))&RUBY_FLONUM_MASK) == RUBY_FLONUM_FLAG) || (!(((VALUE)(klass) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(klass) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(klass))->flags & RUBY_T_MASK) == RUBY_T_FLOAT)) : (!(((VALUE)(klass) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(klass) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(klass))->flags & RUBY_T_MASK) == (RUBY_T_CLASS))) && !( ((RUBY_T_MODULE) == RUBY_T_FIXNUM) ? (((int)(long)(klass))&RUBY_FIXNUM_FLAG) : ((RUBY_T_MODULE) == RUBY_T_TRUE) ? ((klass) == ((VALUE)RUBY_Qtrue)) : ((RUBY_T_MODULE) == RUBY_T_FALSE) ? ((klass) == ((VALUE)RUBY_Qfalse)) : ((RUBY_T_MODULE) == RUBY_T_NIL) ? ((klass) == ((VALUE)RUBY_Qnil)) : ((RUBY_T_MODULE) == RUBY_T_UNDEF) ? ((klass) == ((VALUE)RUBY_Qundef)) : ((RUBY_T_MODULE) == RUBY_T_SYMBOL) ? ((((VALUE)(klass)&~((~(VALUE)0)<<RUBY_SPECIAL_SHIFT)) == RUBY_SYMBOL_FLAG)||(!(((VALUE)(klass) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(klass) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(klass))->flags & RUBY_T_MASK) == (RUBY_T_SYMBOL))) : ((RUBY_T_MODULE) == RUBY_T_FLOAT) ? ( ((((int)(long)(klass))&RUBY_FLONUM_MASK) == RUBY_FLONUM_FLAG) || (!(((VALUE)(klass) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(klass) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(klass))->flags & RUBY_T_MASK) == RUBY_T_FLOAT)) : (!(((VALUE)(klass) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(klass) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(klass))->flags & RUBY_T_MASK) == (RUBY_T_MODULE)))) {
 rb_raise(rb_eTypeError, "%+""l""i" "\v"" is not a class/module", klass);
    }
}

static inline void
vm_ensure_not_refinement_module(VALUE self)
{
    if (( ((RUBY_T_MODULE) == RUBY_T_FIXNUM) ? (((int)(long)(self))&RUBY_FIXNUM_FLAG) : ((RUBY_T_MODULE) == RUBY_T_TRUE) ? ((self) == ((VALUE)RUBY_Qtrue)) : ((RUBY_T_MODULE) == RUBY_T_FALSE) ? ((self) == ((VALUE)RUBY_Qfalse)) : ((RUBY_T_MODULE) == RUBY_T_NIL) ? ((self) == ((VALUE)RUBY_Qnil)) : ((RUBY_T_MODULE) == RUBY_T_UNDEF) ? ((self) == ((VALUE)RUBY_Qundef)) : ((RUBY_T_MODULE) == RUBY_T_SYMBOL) ? ((((VALUE)(self)&~((~(VALUE)0)<<RUBY_SPECIAL_SHIFT)) == RUBY_SYMBOL_FLAG)||(!(((VALUE)(self) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(self) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(self))->flags & RUBY_T_MASK) == (RUBY_T_SYMBOL))) : ((RUBY_T_MODULE) == RUBY_T_FLOAT) ? ( ((((int)(long)(self))&RUBY_FLONUM_MASK) == RUBY_FLONUM_FLAG) || (!(((VALUE)(self) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(self) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(self))->flags & RUBY_T_MASK) == RUBY_T_FLOAT)) : (!(((VALUE)(self) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(self) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(self))->flags & RUBY_T_MASK) == (RUBY_T_MODULE))) && ((!(((VALUE)(self) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(self) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(self))->flags & RUBY_T_MASK) != RUBY_T_NODE)?(((struct RBasic*)((self)))->flags&((RMODULE_IS_REFINEMENT))):0)) {
 rb_warn("not defined at the refinement, but at the outer class/module");
    }
}

static inline VALUE
vm_get_iclass(rb_control_frame_t *cfp, VALUE klass)
{
    return klass;
}

static inline VALUE
vm_get_ev_const(rb_execution_context_t *ec, VALUE orig_klass, ID id, _Bool allow_nil, int is_defined)
{
    void rb_const_warn_if_deprecated(const rb_const_entry_t *ce, VALUE klass, ID id);
    VALUE val;

    if (orig_klass == ((VALUE)RUBY_Qnil) && allow_nil) {

        const rb_cref_t *root_cref = vm_get_cref(ec->cfp->ep);
 const rb_cref_t *cref;
 VALUE klass = ((VALUE)RUBY_Qnil);

 while (root_cref && CREF_PUSHED_BY_EVAL(root_cref)) {
     root_cref = CREF_NEXT(root_cref);
 }
 cref = root_cref;
 while (cref && CREF_NEXT(cref)) {
     if (CREF_PUSHED_BY_EVAL(cref)) {
  klass = ((VALUE)RUBY_Qnil);
     }
     else {
  klass = CREF_CLASS(cref);
     }
     cref = CREF_NEXT(cref);

     if (!!((VALUE)(klass) != ((VALUE)RUBY_Qnil))) {
  VALUE av, am = 0;
  rb_const_entry_t *ce;
       search_continue:
  if ((ce = rb_const_lookup(klass, id))) {
      rb_const_warn_if_deprecated(ce, klass, id);
      val = ce->value;
      if (val == ((VALUE)RUBY_Qundef)) {
   if (am == klass) break;
   am = klass;
   if (is_defined) return 1;
   if (rb_autoloading_value(klass, id, &av, ((void*)0))) return av;
   rb_autoload_load(klass, id);
   goto search_continue;
      }
      else {
   if (is_defined) {
       return 1;
   }
   else {
       return val;
   }
      }
  }
     }
 }


 if (root_cref && !!((VALUE)(CREF_CLASS(root_cref)) != ((VALUE)RUBY_Qnil))) {
     klass = vm_get_iclass(ec->cfp, CREF_CLASS(root_cref));
 }
 else {
     klass = rb_class_of((VALUE)(ec->cfp->self));
 }

 if (is_defined) {
     return rb_const_defined(klass, id);
 }
 else {
     return rb_const_get(klass, id);
 }
    }
    else {
 vm_check_if_namespace(orig_klass);
 if (is_defined) {
     return rb_public_const_defined_from(orig_klass, id);
 }
 else {
     return rb_public_const_get_from(orig_klass, id);
 }
    }
}

static inline VALUE
vm_get_cvar_base(const rb_cref_t *cref, rb_control_frame_t *cfp)
{
    VALUE klass;

    if (!cref) {
 rb_bug("vm_get_cvar_base: no cref");
    }

    while (CREF_NEXT(cref) &&
    (!((VALUE)(CREF_CLASS(cref)) != ((VALUE)RUBY_Qnil)) || ((!(((VALUE)(CREF_CLASS(cref)) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(CREF_CLASS(cref)) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(CREF_CLASS(cref)))->flags & RUBY_T_MASK) != RUBY_T_NODE)?(((struct RBasic*)((CREF_CLASS(cref))))->flags&((((VALUE)RUBY_FL_SINGLETON)))):0) ||
     CREF_PUSHED_BY_EVAL(cref))) {
 cref = CREF_NEXT(cref);
    }
    if (!CREF_NEXT(cref)) {
 rb_warn("class variable access from toplevel");
    }

    klass = vm_get_iclass(cfp, CREF_CLASS(cref));

    if (!((VALUE)(klass) != ((VALUE)RUBY_Qnil))) {
 rb_raise(rb_eTypeError, "no class variables available");
    }
    return klass;
}

static VALUE
vm_search_const_defined_class(const VALUE cbase, ID id)
{
    if (rb_const_defined_at(cbase, id)) return cbase;
    if (cbase == rb_cObject) {
 VALUE tmp = RCLASS_SUPER(cbase);
 while (tmp) {
     if (rb_const_defined_at(tmp, id)) return tmp;
     tmp = RCLASS_SUPER(tmp);
 }
    }
    return 0;
}

__attribute__ ((__always_inline__)) static VALUE vm_getivar(VALUE, ID, IVC, struct rb_call_cache *, int);
static inline VALUE
vm_getivar(VALUE obj, ID id, IVC ic, struct rb_call_cache *cc, int is_attr)
{

    VALUE val = ((VALUE)RUBY_Qundef);

    if ((((VALUE)(obj) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(obj) & (VALUE)~((VALUE)RUBY_Qnil)) == 0))) {

    }
    else if ((__builtin_expect(!!(is_attr ? (cc->aux.index > 0) : (ic->ic_serial == (((struct RClass*)(((struct RBasic*)(obj))->klass))->class_serial))), 1))) {



        st_index_t index = !is_attr ? ic->index : (cc->aux.index - 1);

        ((void)0);

        if ((__builtin_expect(!!((int)(((struct RBasic*)(obj))->flags & RUBY_T_MASK) == RUBY_T_OBJECT), 1)) &&
            (__builtin_expect(!!(index < ((((struct RBasic*)(obj))->flags & ROBJECT_EMBED) ? ROBJECT_EMBED_LEN_MAX : ((struct RObject*)(obj))->as.heap.numiv)), 1))) {
            val = ((((struct RBasic*)(obj))->flags & ROBJECT_EMBED) ? ((struct RObject*)(obj))->as.ary : ((struct RObject*)(obj))->as.heap.ivptr)[index];
        }
        else if ((((struct RBasic*)(obj))->flags&(((VALUE)RUBY_FL_EXIVAR)))) {
            struct gen_ivtbl *ivtbl;

            if ((__builtin_expect(!!(rb_st_lookup(rb_ivar_generic_ivtbl(), (st_data_t)obj, (st_data_t *)&ivtbl)), 1)) &&
                (__builtin_expect(!!(index < ivtbl->numiv), 1))) {
                val = ivtbl->ivptr[index];
            }
        }
        goto ret;
    }
    else {
        struct st_table *iv_index_tbl;
        st_index_t numiv;
        VALUE *ivptr;

        st_data_t index;

        if ((int)(((struct RBasic*)(obj))->flags & RUBY_T_MASK) == RUBY_T_OBJECT) {
            iv_index_tbl = ((((struct RBasic*)(obj))->flags & ROBJECT_EMBED) ? ((((struct RClass*)(rb_obj_class(obj)))->ptr)->iv_index_tbl) : ((struct RObject*)(obj))->as.heap.iv_index_tbl);
            numiv = ((((struct RBasic*)(obj))->flags & ROBJECT_EMBED) ? ROBJECT_EMBED_LEN_MAX : ((struct RObject*)(obj))->as.heap.numiv);
            ivptr = ((((struct RBasic*)(obj))->flags & ROBJECT_EMBED) ? ((struct RObject*)(obj))->as.ary : ((struct RObject*)(obj))->as.heap.ivptr);

          fill:
     if (iv_index_tbl) {
  if (rb_st_lookup(iv_index_tbl, id, &index)) {
                    if (!is_attr) {
                        ic->index = index;
                        ic->ic_serial = (((struct RClass*)(((struct RBasic*)(obj))->klass))->class_serial);
                    }
                    else {
                        cc->aux.index = (int)index + 1;
                    }

                    if (index < numiv) {
                        val = ivptr[index];
      }
  }
     }
 }
        else if ((((struct RBasic*)(obj))->flags&(((VALUE)RUBY_FL_EXIVAR)))) {
            struct gen_ivtbl *ivtbl;

            if ((__builtin_expect(!!(rb_st_lookup(rb_ivar_generic_ivtbl(), (st_data_t)obj, (st_data_t *)&ivtbl)), 1))) {
                numiv = ivtbl->numiv;
                ivptr = ivtbl->ivptr;
                iv_index_tbl = ((((struct RClass*)(rb_obj_class(obj)))->ptr)->iv_index_tbl);
                goto fill;
            }
        }
        else {

            goto general_path;
        }

      ret:
        if ((__builtin_expect(!!(val != ((VALUE)RUBY_Qundef)), 1))) {
            return val;
        }
        else {
            if (!is_attr && !(((VALUE)((*rb_ruby_verbose_ptr())) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) {
                rb_warning("instance variable %""l""i" "\v"" not initialized", rb_id_quote_unprintable(id));
            }
            return ((VALUE)RUBY_Qnil);
        }
    }
  general_path:

    ((void)0);

    if (is_attr) {
        return rb_attr_get(obj, id);
    }
    else {
        return rb_ivar_get(obj, id);
    }
}
ALWAYS_INLINE(static inline VALUE
vm_setivar(VALUE obj, ID id, VALUE val, IVC ic, struct rb_call_cache *cc, int is_attr));
static inline VALUE
vm_setivar(VALUE obj, ID id, VALUE val, IVC ic, struct rb_call_cache *cc, int is_attr) {

    do { VALUE frozen_obj = (obj); if ((__builtin_expect(!!((!(!(((VALUE)(frozen_obj) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(frozen_obj) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(frozen_obj))->flags & RUBY_T_MASK) != RUBY_T_NODE) || (((struct RBasic*)(frozen_obj))->flags&RUBY_FL_FREEZE))), 0))) { rb_error_frozen_object(frozen_obj); } } while (0);

    if ((__builtin_expect(!!(( ((RUBY_T_OBJECT) == RUBY_T_FIXNUM) ? (((int)(long)(obj))&RUBY_FIXNUM_FLAG) : ((RUBY_T_OBJECT) == RUBY_T_TRUE) ? ((obj) == ((VALUE)RUBY_Qtrue)) : ((RUBY_T_OBJECT) == RUBY_T_FALSE) ? ((obj) == ((VALUE)RUBY_Qfalse)) : ((RUBY_T_OBJECT) == RUBY_T_NIL) ? ((obj) == ((VALUE)RUBY_Qnil)) : ((RUBY_T_OBJECT) == RUBY_T_UNDEF) ? ((obj) == ((VALUE)RUBY_Qundef)) : ((RUBY_T_OBJECT) == RUBY_T_SYMBOL) ? ((((VALUE)(obj)&~((~(VALUE)0)<<RUBY_SPECIAL_SHIFT)) == RUBY_SYMBOL_FLAG)||(!(((VALUE)(obj) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(obj) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(obj))->flags & RUBY_T_MASK) == (RUBY_T_SYMBOL))) : ((RUBY_T_OBJECT) == RUBY_T_FLOAT) ? ( ((((int)(long)(obj))&RUBY_FLONUM_MASK) == RUBY_FLONUM_FLAG) || (!(((VALUE)(obj) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(obj) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(obj))->flags & RUBY_T_MASK) == RUBY_T_FLOAT)) : (!(((VALUE)(obj) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(obj) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(obj))->flags & RUBY_T_MASK) == (RUBY_T_OBJECT)))), 1))) {
 VALUE klass = ((struct RBasic*)(obj))->klass;
 st_data_t index;

 if ((__builtin_expect(!!((!is_attr && (ic->ic_serial == (((struct RClass*)(klass))->class_serial))) || ( is_attr && (cc->aux.index > 0))), 1))) {


     VALUE *ptr = ((((struct RBasic*)(obj))->flags & ROBJECT_EMBED) ? ((struct RObject*)(obj))->as.ary : ((struct RObject*)(obj))->as.heap.ivptr);
     index = !is_attr ? ic->index : cc->aux.index-1;

     if ((index < ((((struct RBasic*)(obj))->flags & ROBJECT_EMBED) ? ROBJECT_EMBED_LEN_MAX : ((struct RObject*)(obj))->as.heap.numiv))) {
  __extension__({
;
; typeof(rb_obj_write((VALUE)(obj), (VALUE *)(&ptr[index]), (VALUE)(val), "./vm_insnhelper.c", 1127)) unaligned_member_access_result = (rb_obj_write((VALUE)(obj), (VALUE *)(&ptr[index]), (VALUE)(val), "./vm_insnhelper.c", 1127));
; unaligned_member_access_result; });
  ((void)0);
  return val;
     }
 }
 else {
     struct st_table *iv_index_tbl = ((((struct RBasic*)(obj))->flags & ROBJECT_EMBED) ? ((((struct RClass*)(rb_obj_class(obj)))->ptr)->iv_index_tbl) : ((struct RObject*)(obj))->as.heap.iv_index_tbl);

     if (iv_index_tbl && rb_st_lookup(iv_index_tbl, (st_data_t)id, &index)) {
                if (!is_attr) {
                    ic->index = index;
                    ic->ic_serial = (((struct RClass*)(klass))->class_serial);
                }
  else if (index >= 2147483647) {
      rb_raise(rb_eArgError, "too many instance variables");
  }
  else {
      cc->aux.index = (int)(index + 1);
  }
     }

 }
    }
    else {
 ((void)0);
    }

    ((void)0);
    return rb_ivar_set(obj, id, val);
}
ALWAYS_INLINE(static inline VALUE
vm_getinstancevariable(VALUE obj, ID id, IVC ic));
static inline VALUE
vm_getinstancevariable(VALUE obj, ID id, IVC ic) {
    return vm_getivar(obj, id, ic, ((void*)0), 0);
}
ALWAYS_INLINE(static inline void
vm_setinstancevariable(VALUE obj, ID id, VALUE val, IVC ic));
static inline void
vm_setinstancevariable(VALUE obj, ID id, VALUE val, IVC ic) {
    vm_setivar(obj, id, val, ic, 0, 0);
}

static VALUE
vm_throw_continue(const rb_execution_context_t *ec, VALUE err)
{


    if ((((int)(long)(err))&RUBY_FIXNUM_FLAG)) {
 ec->tag->state = ((int)rb_fix2int((VALUE)(err)));
    }
    else if (((((VALUE)(err)&~((~(VALUE)0)<<RUBY_SPECIAL_SHIFT)) == RUBY_SYMBOL_FLAG)||(!(((VALUE)(err) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(err) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(err))->flags & RUBY_T_MASK) == (RUBY_T_SYMBOL)))) {
 ec->tag->state = RUBY_TAG_THROW;
    }
    else if (( ((RUBY_T_IMEMO) == RUBY_T_FIXNUM) ? (((int)(long)((VALUE)(err)))&RUBY_FIXNUM_FLAG) : ((RUBY_T_IMEMO) == RUBY_T_TRUE) ? (((VALUE)(err)) == ((VALUE)RUBY_Qtrue)) : ((RUBY_T_IMEMO) == RUBY_T_FALSE) ? (((VALUE)(err)) == ((VALUE)RUBY_Qfalse)) : ((RUBY_T_IMEMO) == RUBY_T_NIL) ? (((VALUE)(err)) == ((VALUE)RUBY_Qnil)) : ((RUBY_T_IMEMO) == RUBY_T_UNDEF) ? (((VALUE)(err)) == ((VALUE)RUBY_Qundef)) : ((RUBY_T_IMEMO) == RUBY_T_SYMBOL) ? ((((VALUE)((VALUE)(err))&~((~(VALUE)0)<<RUBY_SPECIAL_SHIFT)) == RUBY_SYMBOL_FLAG)||(!(((VALUE)((VALUE)(err)) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)((VALUE)(err)) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)((VALUE)(err)))->flags & RUBY_T_MASK) == (RUBY_T_SYMBOL))) : ((RUBY_T_IMEMO) == RUBY_T_FLOAT) ? ( ((((int)(long)((VALUE)(err)))&RUBY_FLONUM_MASK) == RUBY_FLONUM_FLAG) || (!(((VALUE)((VALUE)(err)) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)((VALUE)(err)) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)((VALUE)(err)))->flags & RUBY_T_MASK) == RUBY_T_FLOAT)) : (!(((VALUE)((VALUE)(err)) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)((VALUE)(err)) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)((VALUE)(err)))->flags & RUBY_T_MASK) == (RUBY_T_IMEMO)))) {
 ec->tag->state = THROW_DATA_STATE((struct vm_throw_data *)err);
    }
    else {
 ec->tag->state = RUBY_TAG_RAISE;
    }
    return err;
}

static VALUE
vm_throw_start(const rb_execution_context_t *ec, rb_control_frame_t *const reg_cfp, enum ruby_tag_type state,
               const int flag, const VALUE throwobj)
{
    const rb_control_frame_t *escape_cfp = ((void*)0);
    const rb_control_frame_t * const eocfp = RUBY_VM_END_CONTROL_FRAME(ec);

    if (flag != 0) {

    }
    else if (state == RUBY_TAG_BREAK) {
 int is_orphan = 1;
 const VALUE *ep = ((((reg_cfp)->ep)));
 const rb_iseq_t *base_iseq = ((((reg_cfp)))->iseq);
 escape_cfp = reg_cfp;

 while (base_iseq->body->type != ISEQ_TYPE_BLOCK) {
     if (escape_cfp->iseq->body->type == ISEQ_TYPE_CLASS) {
  escape_cfp = ((escape_cfp)+1);
  ep = escape_cfp->ep;
  base_iseq = escape_cfp->iseq;
     }
     else {
  ep = VM_ENV_PREV_EP(ep);
  base_iseq = base_iseq->body->parent_iseq;
  escape_cfp = rb_vm_search_cf_from_ep(ec, escape_cfp, ep);
  ((void)0);
     }
 }

 if (VM_FRAME_LAMBDA_P(escape_cfp)) {

     is_orphan = 0;
     state = RUBY_TAG_RETURN;
 }
 else {
     ep = VM_ENV_PREV_EP(ep);

     while (escape_cfp < eocfp) {
  if (escape_cfp->ep == ep) {
      const rb_iseq_t *const iseq = escape_cfp->iseq;
      const VALUE epc = escape_cfp->pc - iseq->body->iseq_encoded;
      const struct iseq_catch_table *const ct = iseq->body->catch_table;
      unsigned int i;

      if (!ct) break;
      for (i=0; i < ct->size; i++) {
   const struct iseq_catch_table_entry *const entry =
       __extension__({
;
; typeof(&(ct)->entries[i]) unaligned_member_access_result = (&(ct)->entries[i]);
; unaligned_member_access_result; });

   if (entry->type == CATCH_TYPE_BREAK &&
       entry->iseq == base_iseq &&
       entry->start < epc && entry->end >= epc) {
       if (entry->cont == epc) {
    is_orphan = 0;
       }
       break;
   }
      }
      break;
  }

  escape_cfp = ((escape_cfp)+1);
     }
 }

 if (is_orphan) {
     rb_vm_localjump_error("break from proc-closure", throwobj, RUBY_TAG_BREAK);
 }
    }
    else if (state == RUBY_TAG_RETRY) {
 const VALUE *ep = VM_ENV_PREV_EP(((((reg_cfp)->ep))));

 escape_cfp = rb_vm_search_cf_from_ep(ec, reg_cfp, ep);
    }
    else if (state == RUBY_TAG_RETURN) {
 const VALUE *current_ep = ((((reg_cfp)->ep)));
 const VALUE *target_lep = VM_EP_LEP(current_ep);
 int in_class_frame = 0;
 int toplevel = 1;
 escape_cfp = reg_cfp;

 while (escape_cfp < eocfp) {
     const VALUE *lep = VM_CF_LEP(escape_cfp);

     if (!target_lep) {
  target_lep = lep;
     }

     if (lep == target_lep &&
  VM_FRAME_RUBYFRAME_P(escape_cfp) &&
  escape_cfp->iseq->body->type == ISEQ_TYPE_CLASS) {
  in_class_frame = 1;
  target_lep = 0;
     }

     if (lep == target_lep) {
  if (VM_FRAME_LAMBDA_P(escape_cfp)) {
      toplevel = 0;
      if (in_class_frame) {

   goto valid_return;
      }
      else {
   const VALUE *tep = current_ep;

   while (target_lep != tep) {
       if (escape_cfp->ep == tep) {

    goto valid_return;
       }
       tep = VM_ENV_PREV_EP(tep);
   }
      }
  }
  else if (VM_FRAME_RUBYFRAME_P(escape_cfp)) {
      switch (escape_cfp->iseq->body->type) {
        case ISEQ_TYPE_TOP:
        case ISEQ_TYPE_MAIN:
                        if (toplevel) {
                            if (in_class_frame) goto unexpected_return;
                            goto valid_return;
                        }
   break;
        case ISEQ_TYPE_EVAL:
        case ISEQ_TYPE_CLASS:
   toplevel = 0;
   break;
        default:
   break;
      }
  }
     }

     if (escape_cfp->ep == target_lep && escape_cfp->iseq->body->type == ISEQ_TYPE_METHOD) {
  goto valid_return;
     }

     escape_cfp = ((escape_cfp)+1);
 }
      unexpected_return:;
 rb_vm_localjump_error("unexpected return", throwobj, RUBY_TAG_RETURN);

      valid_return:;

    }
    else {
 rb_bug("isns(throw): unsupported throw type");
    }

    ec->tag->state = state;
    return (VALUE)THROW_DATA_NEW(throwobj, escape_cfp, state);
}

static VALUE
vm_throw(const rb_execution_context_t *ec, rb_control_frame_t *reg_cfp,
  rb_num_t throw_state, VALUE throwobj)
{
    const int state = (int)(throw_state & VM_THROW_STATE_MASK);
    const int flag = (int)(throw_state & VM_THROW_NO_ESCAPE_FLAG);

    if (state != 0) {
        return vm_throw_start(ec, reg_cfp, state, flag, throwobj);
    }
    else {
 return vm_throw_continue(ec, throwobj);
    }
}

static inline void
vm_expandarray(VALUE *sp, VALUE ary, rb_num_t num, int flag)
{
    int is_splat = flag & 0x01;
    rb_num_t space_size = num + is_splat;
    VALUE *base = sp - 1;
    const VALUE *ptr;
    rb_num_t len;
    const VALUE obj = ary;

    if (!( ((RUBY_T_ARRAY) == RUBY_T_FIXNUM) ? (((int)(long)(ary))&RUBY_FIXNUM_FLAG) : ((RUBY_T_ARRAY) == RUBY_T_TRUE) ? ((ary) == ((VALUE)RUBY_Qtrue)) : ((RUBY_T_ARRAY) == RUBY_T_FALSE) ? ((ary) == ((VALUE)RUBY_Qfalse)) : ((RUBY_T_ARRAY) == RUBY_T_NIL) ? ((ary) == ((VALUE)RUBY_Qnil)) : ((RUBY_T_ARRAY) == RUBY_T_UNDEF) ? ((ary) == ((VALUE)RUBY_Qundef)) : ((RUBY_T_ARRAY) == RUBY_T_SYMBOL) ? ((((VALUE)(ary)&~((~(VALUE)0)<<RUBY_SPECIAL_SHIFT)) == RUBY_SYMBOL_FLAG)||(!(((VALUE)(ary) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(ary) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(ary))->flags & RUBY_T_MASK) == (RUBY_T_SYMBOL))) : ((RUBY_T_ARRAY) == RUBY_T_FLOAT) ? ( ((((int)(long)(ary))&RUBY_FLONUM_MASK) == RUBY_FLONUM_FLAG) || (!(((VALUE)(ary) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(ary) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(ary))->flags & RUBY_T_MASK) == RUBY_T_FLOAT)) : (!(((VALUE)(ary) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(ary) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(ary))->flags & RUBY_T_MASK) == (RUBY_T_ARRAY))) && !((VALUE)(ary = rb_check_array_type(ary)) != ((VALUE)RUBY_Qnil))) {
 ary = obj;
 ptr = &ary;
 len = 1;
    }
    else {
        ptr = rb_array_const_ptr_transient(ary);
 len = (rb_num_t)rb_array_len(ary);
    }

    if (space_size == 0) {

    }
    else if (flag & 0x02) {

 rb_num_t i = 0, j;

 if (len < num) {
     for (i=0; i<num-len; i++) {
  *base++ = ((VALUE)RUBY_Qnil);
     }
 }
 for (j=0; i<num; i++, j++) {
     VALUE v = ptr[len - j - 1];
     *base++ = v;
 }
 if (is_splat) {
     *base = rb_ary_new_from_values(len - j, ptr);
 }
    }
    else {

 rb_num_t i;
 VALUE *bptr = &base[space_size - 1];

 for (i=0; i<num; i++) {
     if (len <= i) {
  for (; i<num; i++) {
      *bptr-- = ((VALUE)RUBY_Qnil);
  }
  break;
     }
     *bptr-- = ptr[i];
 }
 if (is_splat) {
     if (num > len) {
  *bptr = rb_ary_new();
     }
     else {
  *bptr = rb_ary_new_from_values(len - num, ptr + num);
     }
 }
    }
    (*__extension__ ({ volatile VALUE *rb_gc_guarded_ptr = &(ary); __asm__("" : : "m"(rb_gc_guarded_ptr)); rb_gc_guarded_ptr; }));
}

static VALUE vm_call_general(rb_execution_context_t *ec, rb_control_frame_t *reg_cfp, struct rb_calling_info *calling, struct rb_call_data *cd);



__attribute__((__artificial__))


static inline vm_call_handler
calccall(const struct rb_call_data *cd, const rb_callable_method_entry_t *me)
{
    const struct rb_call_info *ci = &cd->ci;
    const struct rb_call_cache *cc = &cd->cc;

    if ((__builtin_expect(!!(!me), 0))) {
        ((void)0);
        return vm_call_general;
    }
    else if ((__builtin_expect(!!(cc->me != me), 1))) {
        ((void)0);
        return vm_call_general;
    }
    else if ((__builtin_expect(!!(cc->method_serial != me->def->method_serial), 0))) {
        ((void)0);
        return vm_call_general;
    }




    else if (((rb_method_visibility_t)(((cc->me)->flags & (((VALUE)RUBY_FL_USER4) | ((VALUE)RUBY_FL_USER5))) >> ((((VALUE)RUBY_FL_USHIFT) + 4)+0)) != METHOD_VISI_PUBLIC) &&
             !(ci->flag & (0x01 << VM_CALL_FCALL_bit))) {
        ((void)0);
        return vm_call_general;
    }
    else {
        ((void)0);
        (void)(cc->call != vm_call_general);
        return cc->call;
    }
}

__attribute__ ((__visibility__("default"))) extern void
rb_vm_search_method_slowpath(struct rb_call_data *cd, VALUE klass)
;
static inline _Bool
vm_cache_check_for_class_serial(struct rb_call_cache *cc, rb_serial_t class_serial)
{
    int i;
    rb_serial_t j;


    for (i = 0; i < ((int)(sizeof(cc->class_serial) / sizeof((cc->class_serial)[0]))); i++) {
        j = cc->class_serial[i];

        if (! j) {
            break;
        }
        else if (j != class_serial) {
            continue;
        }
        else if (! i) {
            return 1;
        }
        else {
            goto hit;
        }
    }

    ((void)0);
    return 0;

  hit:

    for (; i > 0; i--) {
        cc->class_serial[i] = cc->class_serial[i - 1];
    }

    cc->class_serial[0] = j;
    __builtin___memset_chk ((&cc->aux), 0, sizeof(cc->aux)*(size_t)(1), __builtin_object_size ((&cc->aux), 0));
    return 1;
}

static void
vm_search_method_fastpath(struct rb_call_data *cd, VALUE klass)
{
    struct rb_call_cache *cc = &cd->cc;


    if ((__builtin_expect(!!(((ruby_vm_global_method_state) == cc->method_state) && vm_cache_check_for_class_serial(cc, (((struct RClass*)(klass))->class_serial))), 1))) {



 ((void)0);
 ((void)0);
 return;
    }
    ((void)0);

    rb_vm_search_method_slowpath(cd, klass);
}

static void
vm_search_method(struct rb_call_data *cd, VALUE recv)
{
    VALUE klass = rb_class_of((VALUE)(recv));

    ((void)0);
    ((void)0);
    vm_search_method_fastpath(cd, klass);
}

static inline int
check_cfunc(const rb_callable_method_entry_t *me, VALUE (*func)())
{
    if (me && me->def->type == VM_METHOD_TYPE_CFUNC &&
 me->def->body.cfunc.func == func) {
 return 1;
    }
    else {
 return 0;
    }
}

static inline int
vm_method_cfunc_is(CALL_DATA cd, VALUE recv, VALUE (*func)())
{
    vm_search_method(cd, recv);
    return check_cfunc(cd->cc.me, func);
}

static VALUE
opt_equal_fallback(VALUE recv, VALUE obj, CALL_DATA cd)
{
    if (vm_method_cfunc_is(cd, recv, rb_obj_equal)) {
 return recv == obj ? ((VALUE)RUBY_Qtrue) : ((VALUE)RUBY_Qfalse);
    }

    return ((VALUE)RUBY_Qundef);
}


static inline _Bool
FIXNUM_2_P(VALUE a, VALUE b)
{



    long x = a;
    long y = b;
    long z = x & y & 1;
    return z == 1;
}

static inline _Bool
FLONUM_2_P(VALUE a, VALUE b)
{





    long x = a;
    long y = b;
    long z = ((x ^ 2) | (y ^ 2)) & 3;
    return !z;



}


static inline int
comparable_by_identity(VALUE recv, VALUE obj)
{
    if (FIXNUM_2_P(recv, obj)) {
 return (((__builtin_expect(!!((rb_current_vm()->redefined_flag[(BOP_EQ)]&((1 << 0))) == 0), 1))) != 0) * 2 - 1;
    }
    if (FLONUM_2_P(recv, obj)) {
 return (((__builtin_expect(!!((rb_current_vm()->redefined_flag[(BOP_EQ)]&((1 << 1))) == 0), 1))) != 0) * 2 - 1;
    }
    if (((((VALUE)(recv)&~((~(VALUE)0)<<RUBY_SPECIAL_SHIFT)) == RUBY_SYMBOL_FLAG)||(!(((VALUE)(recv) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(recv) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(recv))->flags & RUBY_T_MASK) == (RUBY_T_SYMBOL))) && ((((VALUE)(obj)&~((~(VALUE)0)<<RUBY_SPECIAL_SHIFT)) == RUBY_SYMBOL_FLAG)||(!(((VALUE)(obj) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(obj) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(obj))->flags & RUBY_T_MASK) == (RUBY_T_SYMBOL)))) {
 return (((__builtin_expect(!!((rb_current_vm()->redefined_flag[(BOP_EQ)]&((1 << 6))) == 0), 1))) != 0) * 2 - 1;
    }
    return 0;
}

static

inline

VALUE
opt_eq_func(VALUE recv, VALUE obj, CALL_DATA cd)
{
    switch (comparable_by_identity(recv, obj)) {
      case 1:
 return (recv == obj) ? ((VALUE)RUBY_Qtrue) : ((VALUE)RUBY_Qfalse);
      case -1:
 goto fallback;
    }
    if (0) {
    }
    else if ((!(((VALUE)(recv) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(recv) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (((struct RBasic*)(recv))->klass) == rb_cFloat)) {
 if (((__builtin_expect(!!((rb_current_vm()->redefined_flag[(BOP_EQ)]&((1 << 1))) == 0), 1)))) {
     return rb_float_equal(recv, obj);
 }
    }
    else if ((!(((VALUE)(recv) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(recv) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (((struct RBasic*)(recv))->klass) == rb_cString) && ((__builtin_expect(!!((rb_current_vm()->redefined_flag[(BOP_EQ)]&((1 << 2))) == 0), 1)))) {
        if (recv == obj) return ((VALUE)RUBY_Qtrue);
        if (( ((RUBY_T_STRING) == RUBY_T_FIXNUM) ? (((int)(long)(obj))&RUBY_FIXNUM_FLAG) : ((RUBY_T_STRING) == RUBY_T_TRUE) ? ((obj) == ((VALUE)RUBY_Qtrue)) : ((RUBY_T_STRING) == RUBY_T_FALSE) ? ((obj) == ((VALUE)RUBY_Qfalse)) : ((RUBY_T_STRING) == RUBY_T_NIL) ? ((obj) == ((VALUE)RUBY_Qnil)) : ((RUBY_T_STRING) == RUBY_T_UNDEF) ? ((obj) == ((VALUE)RUBY_Qundef)) : ((RUBY_T_STRING) == RUBY_T_SYMBOL) ? ((((VALUE)(obj)&~((~(VALUE)0)<<RUBY_SPECIAL_SHIFT)) == RUBY_SYMBOL_FLAG)||(!(((VALUE)(obj) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(obj) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(obj))->flags & RUBY_T_MASK) == (RUBY_T_SYMBOL))) : ((RUBY_T_STRING) == RUBY_T_FLOAT) ? ( ((((int)(long)(obj))&RUBY_FLONUM_MASK) == RUBY_FLONUM_FLAG) || (!(((VALUE)(obj) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(obj) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(obj))->flags & RUBY_T_MASK) == RUBY_T_FLOAT)) : (!(((VALUE)(obj) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(obj) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(obj))->flags & RUBY_T_MASK) == (RUBY_T_STRING)))) {
            return rb_str_eql_internal(recv, obj);
        }
    }

  fallback:
    return opt_equal_fallback(recv, obj, cd);
}

static

inline

VALUE
opt_eql_func(VALUE recv, VALUE obj, CALL_DATA cd)
{
    switch (comparable_by_identity(recv, obj)) {
      case 1:
 return (recv == obj) ? ((VALUE)RUBY_Qtrue) : ((VALUE)RUBY_Qfalse);
      case -1:
 goto fallback;
    }
    if (0) {
    }
    else if ((!(((VALUE)(recv) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(recv) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (((struct RBasic*)(recv))->klass) == rb_cFloat)) {
 if (((__builtin_expect(!!((rb_current_vm()->redefined_flag[(BOP_EQ)]&((1 << 1))) == 0), 1)))) {
     return rb_float_eql(recv, obj);
 }
    }
    else if ((!(((VALUE)(recv) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(recv) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (((struct RBasic*)(recv))->klass) == rb_cString)) {
 if (((__builtin_expect(!!((rb_current_vm()->redefined_flag[(BOP_EQ)]&((1 << 2))) == 0), 1)))) {
     return rb_str_eql(recv, obj);
 }
    }

  fallback:
    return opt_equal_fallback(recv, obj, cd);
}

VALUE
rb_equal_opt(VALUE obj1, VALUE obj2)
;static inline 

VALUE
rb_eql_opt(VALUE obj1, VALUE obj2)
{
    struct rb_call_data cd = { .ci = { .mid = idEqlP, }, };

    return opt_eql_func(obj1, obj2, &cd);
}

extern VALUE rb_vm_call0(rb_execution_context_t *ec, VALUE, ID, int, const VALUE*, const rb_callable_method_entry_t *, int kw_splat);

static VALUE
check_match(rb_execution_context_t *ec, VALUE pattern, VALUE target, enum vm_check_match_type type)
{
    switch (type) {
      case VM_CHECKMATCH_TYPE_WHEN:
 return pattern;
      case VM_CHECKMATCH_TYPE_RESCUE:
 if (!rb_obj_is_kind_of(pattern, rb_cModule)) {
     rb_raise(rb_eTypeError, "class or module required for rescue clause");
 }

      case VM_CHECKMATCH_TYPE_CASE: {
 const rb_callable_method_entry_t *me =
     rb_callable_method_entry_with_refinements(rb_class_of((VALUE)(pattern)), idEqq, ((void*)0));
 if (me) {
            return rb_vm_call0(ec, pattern, idEqq, 1, &target, me, 0);
 }
 else {

     return __extension__({ static struct rb_call_data rb_funcallv_data; rb_funcallv_with_cc(&rb_funcallv_data, pattern, idEqq, 1, &target); });
 }
      }
      default:
 rb_bug("check_match: unreachable");
    }
}







static inline VALUE
double_cmp_lt(double a, double b)
{
                       ;
    return a < b ? ((VALUE)RUBY_Qtrue) : ((VALUE)RUBY_Qfalse);
}

static inline VALUE
double_cmp_le(double a, double b)
{
                       ;
    return a <= b ? ((VALUE)RUBY_Qtrue) : ((VALUE)RUBY_Qfalse);
}

static inline VALUE
double_cmp_gt(double a, double b)
{
                       ;
    return a > b ? ((VALUE)RUBY_Qtrue) : ((VALUE)RUBY_Qfalse);
}

static inline VALUE
double_cmp_ge(double a, double b)
{
                       ;
    return a >= b ? ((VALUE)RUBY_Qtrue) : ((VALUE)RUBY_Qfalse);
}

static inline VALUE *
vm_base_ptr(const rb_control_frame_t *cfp)
{
    return cfp->__bp__;

}




__attribute__ ((__noreturn__)) static void raise_argument_error(rb_execution_context_t *ec, const rb_iseq_t *iseq, const VALUE exc);
__attribute__ ((__noreturn__)) static void argument_arity_error(rb_execution_context_t *ec, const rb_iseq_t *iseq, const int miss_argc, const int min_argc, const int max_argc);
__attribute__ ((__noreturn__)) static void argument_kw_error(rb_execution_context_t *ec, const rb_iseq_t *iseq, const char *error, const VALUE keys);
VALUE rb_keyword_error_new(const char *error, VALUE keys);
static VALUE method_missing(VALUE obj, ID id, int argc, const VALUE *argv,
                            enum method_missing_reason call_status, int kw_splat);

__attribute__ ((__visibility__("default"))) extern

const rb_callable_method_entry_t *rb_resolve_refined_method_callable(VALUE refinements, const rb_callable_method_entry_t *me);

struct args_info {

    VALUE *argv;
    int argc;


    int rest_index;
    int rest_dupped;
    const struct rb_call_info_kw_arg *kw_arg;
    VALUE *kw_argv;
    VALUE rest;
};

enum arg_setup_type {
    arg_setup_method,
    arg_setup_block
};

static inline void
arg_rest_dup(struct args_info *args)
{
    if (!args->rest_dupped) {
        args->rest = rb_ary_dup(args->rest);
        args->rest_dupped = 1;
    }
}

static inline int
args_argc(struct args_info *args)
{
    if (args->rest == ((VALUE)RUBY_Qfalse)) {
 return args->argc;
    }
    else {
 return args->argc + rb_long2int_inline(rb_array_len(args->rest)) - args->rest_index;
    }
}

static inline void
args_extend(struct args_info *args, const int min_argc)
{
    int i;

    if (args->rest) {
        arg_rest_dup(args);
 ((void)0);
 for (i=args->argc + rb_long2int_inline(rb_array_len(args->rest)); i<min_argc; i++) {
     rb_ary_push(args->rest, ((VALUE)RUBY_Qnil));
 }
    }
    else {
 for (i=args->argc; i<min_argc; i++) {
     args->argv[args->argc++] = ((VALUE)RUBY_Qnil);
 }
    }
}

static inline void
args_reduce(struct args_info *args, int over_argc)
{
    if (args->rest) {
 const long len = rb_array_len(args->rest);

 if (len > over_argc) {
     arg_rest_dup(args);
     rb_ary_resize(args->rest, len - over_argc);
     return;
 }
 else {
     args->rest = ((VALUE)RUBY_Qfalse);
     over_argc -= len;
 }
    }

    ((void)0);
    args->argc -= over_argc;
}

static inline int
args_check_block_arg0(struct args_info *args)
{
    VALUE ary = ((VALUE)RUBY_Qnil);

    if (args->rest && rb_array_len(args->rest) == 1) {
 VALUE arg0 = (rb_array_const_ptr_transient(args->rest)[0]);
 ary = rb_check_array_type(arg0);
    }
    else if (args->argc == 1) {
 VALUE arg0 = args->argv[0];
 ary = rb_check_array_type(arg0);
 args->argv[0] = arg0;
    }

    if (!!((VALUE)(ary) != ((VALUE)RUBY_Qnil))) {
 args->rest = ary;
 args->rest_index = 0;
 args->argc = 0;
 return 1;
    }

    return 0;
}

static inline void
args_copy(struct args_info *args)
{
    if (args->rest != ((VALUE)RUBY_Qfalse)) {
 int argc = args->argc;
 args->argc = 0;
        arg_rest_dup(args);
 while (args->rest_index > 0 && argc > 0) {
     do { const VALUE _ary = (args->rest); const VALUE _v = (args->argv[--argc]); VALUE *ptr = (VALUE *)rb_array_ptr_use_start(_ary, 1); __extension__({
;
; typeof(rb_obj_write((VALUE)(_ary), (VALUE *)(&ptr[--args->rest_index]), (VALUE)(_v), "./vm_args.c", 154)) unaligned_member_access_result = (rb_obj_write((VALUE)(_ary), (VALUE *)(&ptr[--args->rest_index]), (VALUE)(_v), "./vm_args.c", 154));
; unaligned_member_access_result; }); rb_array_ptr_use_end(_ary, 1); } while (0);
 }
 while (argc > 0) {
     rb_ary_unshift(args->rest, args->argv[--argc]);
 }
    }
    else if (args->argc > 0) {
 args->rest = rb_ary_new_from_values(args->argc, args->argv);
 args->rest_index = 0;
        args->rest_dupped = 1;
 args->argc = 0;
    }
}

static inline const VALUE *
args_rest_argv(struct args_info *args)
{
    return rb_array_const_ptr_transient(args->rest) + args->rest_index;
}

static inline VALUE
args_rest_array(struct args_info *args)
{
    VALUE ary;

    if (args->rest) {
        ary = rb_ary_behead(args->rest, args->rest_index);
        args->rest_index = 0;
 args->rest = 0;
    }
    else {
 ary = rb_ary_new();
    }
    return ary;
}


static int
keyword_hash_symbol_other_iter(st_data_t key, st_data_t val, st_data_t arg)
{
    *(int*)arg |= ((((VALUE)((VALUE)key)&~((~(VALUE)0)<<RUBY_SPECIAL_SHIFT)) == RUBY_SYMBOL_FLAG)||(!(((VALUE)((VALUE)key) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)((VALUE)key) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)((VALUE)key))->flags & RUBY_T_MASK) == (RUBY_T_SYMBOL))) ? 1 : 2;

    if ((*(int*)arg & 3) == 3) {
 return ST_STOP;
    }

    return ST_CONTINUE;
}

static int
keyword_hash_symbol_other(VALUE hash)
{
    int symbol_other = 0;
    rb_hash_stlike_foreach(hash, keyword_hash_symbol_other_iter, (st_data_t)(&symbol_other));
    return symbol_other;
}

static int
keyword_hash_split_iter(st_data_t key, st_data_t val, st_data_t arg)
{
    if (((((VALUE)((VALUE)key)&~((~(VALUE)0)<<RUBY_SPECIAL_SHIFT)) == RUBY_SYMBOL_FLAG)||(!(((VALUE)((VALUE)key) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)((VALUE)key) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)((VALUE)key))->flags & RUBY_T_MASK) == (RUBY_T_SYMBOL)))) {
 rb_hash_aset((VALUE)arg, (VALUE)key, (VALUE)val);
 return ST_DELETE;
    }

    return ST_CONTINUE;
}

static void
keyword_hash_split(VALUE *kw_hash_ptr, VALUE *rest_hash_ptr)
{
    *kw_hash_ptr = rb_hash_new();
    rb_hash_stlike_foreach(*rest_hash_ptr, keyword_hash_split_iter, (st_data_t)(*kw_hash_ptr));
}

static int
keyword_hash_p(VALUE *kw_hash_ptr, VALUE *rest_hash_ptr, int check_only_symbol)
{
    *rest_hash_ptr = rb_check_hash_type(*kw_hash_ptr);

    if (!!((VALUE)(*rest_hash_ptr) != ((VALUE)RUBY_Qnil))) {
 if (check_only_symbol) {
     switch (keyword_hash_symbol_other(*rest_hash_ptr)) {
              case 0:
              case 1:
  break;
              case 2:
  *kw_hash_ptr = ((VALUE)RUBY_Qnil);
  return 0;
              case 3:
                *rest_hash_ptr = rb_hash_dup(*rest_hash_ptr);
  keyword_hash_split(kw_hash_ptr, rest_hash_ptr);
  return 1;
     }
 }
 *kw_hash_ptr = *rest_hash_ptr;
 *rest_hash_ptr = ((VALUE)RUBY_Qfalse);
 return 1;
    }
    else {
 *kw_hash_ptr = ((VALUE)RUBY_Qnil);
 return 0;
    }
}

static VALUE
args_pop_keyword_hash(struct args_info *args, VALUE *kw_hash_ptr, int check_only_symbol)
{
    VALUE rest_hash;

    if (args->rest == ((VALUE)RUBY_Qfalse)) {
      from_argv:
 ((void)0);
 *kw_hash_ptr = args->argv[args->argc-1];

 if (keyword_hash_p(kw_hash_ptr, &rest_hash, check_only_symbol)) {
     if (rest_hash) {
  args->argv[args->argc-1] = rest_hash;
     }
     else {
  args->argc--;
  return 1;
     }
 }
    }
    else {
 long len = rb_array_len(args->rest);

 if (len > 0) {
     *kw_hash_ptr = (rb_array_const_ptr_transient(args->rest)[len - 1]);

     if (keyword_hash_p(kw_hash_ptr, &rest_hash, check_only_symbol)) {
  if (rest_hash) {
      do { const VALUE _ary = (args->rest); const VALUE _v = (rest_hash); VALUE *ptr = (VALUE *)rb_array_ptr_use_start(_ary, 1); __extension__({
;
; typeof(rb_obj_write((VALUE)(_ary), (VALUE *)(&ptr[len - 1]), (VALUE)(_v), "./vm_args.c", 291)) unaligned_member_access_result = (rb_obj_write((VALUE)(_ary), (VALUE *)(&ptr[len - 1]), (VALUE)(_v), "./vm_args.c", 291));
; unaligned_member_access_result; }); rb_array_ptr_use_end(_ary, 1); } while (0);
  }
  else {
      arg_rest_dup(args);
      rb_ary_pop(args->rest);
      return 1;
  }
     }
 }
 else {
     goto from_argv;
 }
    }

    return 0;
}

static int
args_kw_argv_to_hash(struct args_info *args)
{
    const struct rb_call_info_kw_arg *kw_arg = args->kw_arg;
    const VALUE *const passed_keywords = kw_arg->keywords;
    const int kw_len = kw_arg->keyword_len;
    VALUE h = rb_hash_new_with_size(kw_len);
    const int kw_start = args->argc - kw_len;
    const VALUE * const kw_argv = args->argv + kw_start;
    int i;

    args->argc = kw_start + 1;
    for (i=0; i<kw_len; i++) {
 rb_hash_aset(h, passed_keywords[i], kw_argv[i]);
    }

    args->argv[args->argc - 1] = h;

    return args->argc;
}

static void
args_stored_kw_argv_to_hash(struct args_info *args)
{
    int i;
    const struct rb_call_info_kw_arg *kw_arg = args->kw_arg;
    const VALUE *const passed_keywords = kw_arg->keywords;
    const int passed_keyword_len = kw_arg->keyword_len;
    VALUE h = rb_hash_new_with_size(passed_keyword_len);

    for (i=0; i<passed_keyword_len; i++) {
 rb_hash_aset(h, passed_keywords[i], args->kw_argv[i]);
    }
    args->kw_argv = ((void*)0);

    if (args->rest) {
 arg_rest_dup(args);
 rb_ary_push(args->rest, h);
    }
    else {
 args->argv[args->argc++] = h;
    }
}

static inline void
args_setup_lead_parameters(struct args_info *args, int argc, VALUE *locals)
{
    if (args->argc >= argc) {

 args->argc -= argc;
 args->argv += argc;
    }
    else {
 int i, j;
 const VALUE *argv = args_rest_argv(args);

 for (i=args->argc, j=0; i<argc; i++, j++) {
     locals[i] = argv[j];
 }
 args->rest_index += argc - args->argc;
 args->argc = 0;
    }
}

static inline void
args_setup_post_parameters(struct args_info *args, int argc, VALUE *locals)
{
    long len;
    len = rb_array_len(args->rest);
    __builtin___memcpy_chk ((locals), (rb_array_const_ptr_transient(args->rest) + len - argc), sizeof(VALUE)*(size_t)(argc), __builtin_object_size ((locals), 0));
    rb_ary_resize(args->rest, len - argc);
}

static inline int
args_setup_opt_parameters(struct args_info *args, int opt_max, VALUE *locals)
{
    int i;

    if (args->argc >= opt_max) {
 args->argc -= opt_max;
 args->argv += opt_max;
 i = opt_max;
    }
    else {
 int j;
 i = args->argc;
 args->argc = 0;

 if (args->rest) {
            int len = rb_long2int_inline(rb_array_len(args->rest));
            const VALUE *argv = rb_array_const_ptr_transient(args->rest);

            for (; i<opt_max && args->rest_index < len; i++, args->rest_index++) {
                locals[i] = argv[args->rest_index];
            }
        }


 for (j=i; j<opt_max; j++) {
     locals[j] = ((VALUE)RUBY_Qnil);
 }
    }

    return i;
}

static inline void
args_setup_rest_parameter(struct args_info *args, VALUE *locals)
{
    *locals = args_rest_array(args);
}

static VALUE
make_unknown_kw_hash(const VALUE *passed_keywords, int passed_keyword_len, const VALUE *kw_argv)
{
    int i;
    VALUE obj = rb_ary_tmp_new(1);

    for (i=0; i<passed_keyword_len; i++) {
 if (kw_argv[i] != ((VALUE)RUBY_Qundef)) {
     rb_ary_push(obj, passed_keywords[i]);
 }
    }
    return obj;
}

static VALUE
make_rest_kw_hash(const VALUE *passed_keywords, int passed_keyword_len, const VALUE *kw_argv)
{
    int i;
    VALUE obj = rb_hash_new_with_size(passed_keyword_len);

    for (i=0; i<passed_keyword_len; i++) {
 if (kw_argv[i] != ((VALUE)RUBY_Qundef)) {
     rb_hash_aset(obj, passed_keywords[i], kw_argv[i]);
 }
    }
    return obj;
}

static inline int
args_setup_kw_parameters_lookup(const ID key, VALUE *ptr, const VALUE *const passed_keywords, VALUE *passed_values, const int passed_keyword_len)
{
    int i;
    const VALUE keyname = (rb_id2sym(key));

    for (i=0; i<passed_keyword_len; i++) {
 if (keyname == passed_keywords[i]) {
     *ptr = passed_values[i];
     passed_values[i] = ((VALUE)RUBY_Qundef);
     return 1;
 }
    }

    return 0;
}


static void
args_setup_kw_parameters(rb_execution_context_t *const ec, const rb_iseq_t *const iseq,
    VALUE *const passed_values, const int passed_keyword_len, const VALUE *const passed_keywords,
    VALUE *const locals)
{
    const ID *acceptable_keywords = iseq->body->param.keyword->table;
    const int req_key_num = iseq->body->param.keyword->required_num;
    const int key_num = iseq->body->param.keyword->num;
    const VALUE * const default_values = iseq->body->param.keyword->default_values;
    VALUE missing = 0;
    int i, di, found = 0;
    int unspecified_bits = 0;
    VALUE unspecified_bits_value = ((VALUE)RUBY_Qnil);

    for (i=0; i<req_key_num; i++) {
 ID key = acceptable_keywords[i];
 if (args_setup_kw_parameters_lookup(key, &locals[i], passed_keywords, passed_values, passed_keyword_len)) {
     found++;
 }
 else {
     if (!missing) missing = rb_ary_tmp_new(1);
     rb_ary_push(missing, (rb_id2sym(key)));
 }
    }

    if (missing) argument_kw_error(ec, iseq, "missing", missing);

    for (di=0; i<key_num; i++, di++) {
 if (args_setup_kw_parameters_lookup(acceptable_keywords[i], &locals[i], passed_keywords, passed_values, passed_keyword_len)) {
     found++;
 }
 else {
     if (default_values[di] == ((VALUE)RUBY_Qundef)) {
  locals[i] = ((VALUE)RUBY_Qnil);

  if ((__builtin_expect(!!(i < (32-1)), 1))) {
      unspecified_bits |= 0x01 << di;
  }
  else {
      if (!((VALUE)(unspecified_bits_value) != ((VALUE)RUBY_Qnil))) {

   int j;
   unspecified_bits_value = rb_hash_new();

   for (j=0; j<(32-1); j++) {
       if (unspecified_bits & (0x01 << j)) {
    rb_hash_aset(unspecified_bits_value, (((VALUE)(j))<<1 | RUBY_FIXNUM_FLAG), ((VALUE)RUBY_Qtrue));
       }
   }
      }
      rb_hash_aset(unspecified_bits_value, (((VALUE)(di))<<1 | RUBY_FIXNUM_FLAG), ((VALUE)RUBY_Qtrue));
  }
     }
     else {
  locals[i] = default_values[di];
     }
 }
    }

    if (iseq->body->param.flags.has_kwrest) {
 const int rest_hash_index = key_num + 1;
 locals[rest_hash_index] = make_rest_kw_hash(passed_keywords, passed_keyword_len, passed_values);
    }
    else {
 if (found != passed_keyword_len) {
     VALUE keys = make_unknown_kw_hash(passed_keywords, passed_keyword_len, passed_values);
     argument_kw_error(ec, iseq, "unknown", keys);
 }
    }

    if (!((VALUE)(unspecified_bits_value) != ((VALUE)RUBY_Qnil))) {
 unspecified_bits_value = (((VALUE)(unspecified_bits))<<1 | RUBY_FIXNUM_FLAG);
    }
    locals[key_num] = unspecified_bits_value;
}

static inline void
args_setup_kw_rest_parameter(VALUE keyword_hash, VALUE *locals)
{
    locals[0] = !((VALUE)(keyword_hash) != ((VALUE)RUBY_Qnil)) ? rb_hash_new() : rb_hash_dup(keyword_hash);
}

static inline void
args_setup_block_parameter(const rb_execution_context_t *ec, struct rb_calling_info *calling, VALUE *locals)
{
    VALUE block_handler = calling->block_handler;
    *locals = rb_vm_bh_to_procval(ec, block_handler);
}

struct fill_values_arg {
    VALUE *keys;
    VALUE *vals;
    int argc;
};

static int
fill_keys_values(st_data_t key, st_data_t val, st_data_t ptr)
{
    struct fill_values_arg *arg = (struct fill_values_arg *)ptr;
    int i = arg->argc++;
    arg->keys[i] = (VALUE)key;
    arg->vals[i] = (VALUE)val;
    return ST_CONTINUE;
}

static inline int
ignore_keyword_hash_p(VALUE keyword_hash, const rb_iseq_t * const iseq)
{
    if (!(iseq->body->param.flags.has_kw) &&
       !(iseq->body->param.flags.has_kwrest)) {
 keyword_hash = rb_check_hash_type(keyword_hash);

 if (!!((VALUE)(keyword_hash) != ((VALUE)RUBY_Qnil)) && (((!(((struct RBasic*)((keyword_hash)))->flags&(RHASH_ST_TABLE_FLAG))) ? ((unsigned int)((((struct RBasic*)(keyword_hash))->flags & (VALUE)RHASH_AR_TABLE_SIZE_MASK) >> RHASH_AR_TABLE_SIZE_SHIFT)) : ((((struct RHash*)(keyword_hash))->as.st)->num_entries)) == 0)) {
     return 1;
 }
    }

    return 0;
}

VALUE rb_iseq_location(const rb_iseq_t *iseq);







static st_table *caller_to_callees = 0;

static VALUE
rb_warn_check(const rb_execution_context_t * const ec, const rb_iseq_t *const iseq)
{
    if (!rb_warning_category_enabled_p(RB_WARN_CATEGORY_DEPRECATED)) return 1;

    if (!iseq) return 0;

    const st_data_t callee = (st_data_t)(iseq->body->iseq_unique_id * 2);

    const rb_control_frame_t * const cfp = rb_vm_get_ruby_level_next_cfp(ec, ec->cfp);

    if (!cfp) return 0;

    const st_data_t caller = (st_data_t)cfp->pc;

    if (!caller_to_callees) {
        caller_to_callees = rb_st_init_numtable();
    }

    st_data_t val;
    if (rb_st_lookup(caller_to_callees, caller, &val)) {
        st_table *callees;

        if (val & 1) {
            val &= ~(st_data_t)1;
            if (val == callee) return 1;

            callees = rb_st_init_numtable();
            rb_st_insert(callees, val, 1);
        }
        else {
            callees = (st_table *) val;
            if (rb_st_lookup((callees),(callee),(st_data_t *)0)) return 1;
        }
        rb_st_insert(callees, callee, 1);
        rb_st_insert(caller_to_callees, caller, (st_data_t) callees);
    }
    else {
        rb_st_insert(caller_to_callees, caller, callee | 1);
    }

    return 0;
}

static inline void
rb_warn_keyword_to_last_hash(rb_execution_context_t * const ec, struct rb_calling_info *calling, const struct rb_call_info *ci, const rb_iseq_t * const iseq)
{
    if (rb_warn_check(ec, iseq)) return;

    VALUE name, loc;
    if (calling->recv == ((VALUE)RUBY_Qundef)) {
        rb_warn("Passing the keyword argument as the last hash parameter is deprecated");
        return;
    }
    name = rb_id2str(ci->mid);
    loc = rb_iseq_location(iseq);
    if (!((VALUE)(loc) != ((VALUE)RUBY_Qnil))) {
        rb_warn("Passing the keyword argument for `%""l""i" "\v""' as the last hash parameter is deprecated",
                name);
    }
    else {
        rb_warn("Passing the keyword argument as the last hash parameter is deprecated");
        if (name) {
            rb_compile_warn((!(((struct RBasic*)((rb_array_const_ptr_transient(loc)[0])))->flags & RSTRING_NOEMBED) ? ((struct RString*)((rb_array_const_ptr_transient(loc)[0])))->as.ary : ((struct RString*)((rb_array_const_ptr_transient(loc)[0])))->as.heap.ptr), ((int)rb_fix2int((VALUE)((rb_array_const_ptr_transient(loc)[1])))),
                            "The called method `%""l""i" "\v""' is defined here", name);
        }
        else {
            rb_compile_warn((!(((struct RBasic*)((rb_array_const_ptr_transient(loc)[0])))->flags & RSTRING_NOEMBED) ? ((struct RString*)((rb_array_const_ptr_transient(loc)[0])))->as.ary : ((struct RString*)((rb_array_const_ptr_transient(loc)[0])))->as.heap.ptr), ((int)rb_fix2int((VALUE)((rb_array_const_ptr_transient(loc)[1])))),
                            "The called method is defined here");
        }
    }
}

static inline void
rb_warn_split_last_hash_to_keyword(rb_execution_context_t * const ec, struct rb_calling_info *calling, const struct rb_call_info *ci, const rb_iseq_t * const iseq)
{
    if (rb_warn_check(ec, iseq)) return;

    VALUE name, loc;
    name = rb_id2str(ci->mid);
    loc = rb_iseq_location(iseq);
    if (!((VALUE)(loc) != ((VALUE)RUBY_Qnil))) {
        rb_warn("Splitting the last argument for `%""l""i" "\v""' into positional and keyword parameters is deprecated",
                name);
    }
    else {
        rb_warn("Splitting the last argument into positional and keyword parameters is deprecated");
        if (calling->recv != ((VALUE)RUBY_Qundef)) {
            rb_compile_warn((!(((struct RBasic*)((rb_array_const_ptr_transient(loc)[0])))->flags & RSTRING_NOEMBED) ? ((struct RString*)((rb_array_const_ptr_transient(loc)[0])))->as.ary : ((struct RString*)((rb_array_const_ptr_transient(loc)[0])))->as.heap.ptr), ((int)rb_fix2int((VALUE)((rb_array_const_ptr_transient(loc)[1])))),
                            "The called method `%""l""i" "\v""' is defined here", name);
        }
        else {
            rb_compile_warn((!(((struct RBasic*)((rb_array_const_ptr_transient(loc)[0])))->flags & RSTRING_NOEMBED) ? ((struct RString*)((rb_array_const_ptr_transient(loc)[0])))->as.ary : ((struct RString*)((rb_array_const_ptr_transient(loc)[0])))->as.heap.ptr), ((int)rb_fix2int((VALUE)((rb_array_const_ptr_transient(loc)[1])))),
                            "The called method is defined here");
        }
    }
}

static inline void
rb_warn_last_hash_to_keyword(rb_execution_context_t * const ec, struct rb_calling_info *calling, const struct rb_call_info *ci, const rb_iseq_t * const iseq)
{
    if (rb_warn_check(ec, iseq)) return;

    VALUE name, loc;
    name = rb_id2str(ci->mid);
    loc = rb_iseq_location(iseq);
    if (!((VALUE)(loc) != ((VALUE)RUBY_Qnil))) {
        rb_warn("Using the last argument for `%""l""i" "\v""' as keyword parameters is deprecated; maybe ** should be added to the call",
                name);
    }
    else {
        rb_warn("Using the last argument as keyword parameters is deprecated; maybe ** should be added to the call");
        if (calling->recv != ((VALUE)RUBY_Qundef)) {
            rb_compile_warn((!(((struct RBasic*)((rb_array_const_ptr_transient(loc)[0])))->flags & RSTRING_NOEMBED) ? ((struct RString*)((rb_array_const_ptr_transient(loc)[0])))->as.ary : ((struct RString*)((rb_array_const_ptr_transient(loc)[0])))->as.heap.ptr), ((int)rb_fix2int((VALUE)((rb_array_const_ptr_transient(loc)[1])))),
                            "The called method `%""l""i" "\v""' is defined here", name);
        }
        else {
            rb_compile_warn((!(((struct RBasic*)((rb_array_const_ptr_transient(loc)[0])))->flags & RSTRING_NOEMBED) ? ((struct RString*)((rb_array_const_ptr_transient(loc)[0])))->as.ary : ((struct RString*)((rb_array_const_ptr_transient(loc)[0])))->as.heap.ptr), ((int)rb_fix2int((VALUE)((rb_array_const_ptr_transient(loc)[1])))),
                            "The called method is defined here");
        }
    }
}

static int
setup_parameters_complex(rb_execution_context_t * const ec, const rb_iseq_t * const iseq,
    struct rb_calling_info *const calling,
    const struct rb_call_info *ci,
    VALUE * const locals, const enum arg_setup_type arg_setup_type)
{
    const int min_argc = iseq->body->param.lead_num + iseq->body->param.post_num;
    const int max_argc = (iseq->body->param.flags.has_rest == 0) ? min_argc + iseq->body->param.opt_num : (-1);
    int given_argc;
    int kw_splat = 0;
    unsigned int kw_flag = ci->flag & ((0x01 << VM_CALL_KWARG_bit) | (0x01 << VM_CALL_KW_SPLAT_bit));
    int opt_pc = 0, allow_autosplat = !kw_flag;
    struct args_info args_body, *args;
    VALUE keyword_hash = ((VALUE)RUBY_Qnil);
    VALUE * const orig_sp = ec->cfp->sp;
    unsigned int i;
    int remove_empty_keyword_hash = 1;
    VALUE flag_keyword_hash = 0;

                                ;
    for (i=calling->argc; i<iseq->body->param.size; i++) {
 locals[i] = ((VALUE)RUBY_Qnil);
    }
    ec->cfp->sp = &locals[i];


    args = &args_body;
    given_argc = args->argc = calling->argc;
    args->argv = locals;
    args->rest_dupped = 0;

    if (kw_flag & (0x01 << VM_CALL_KWARG_bit)) {
 args->kw_arg = ((struct rb_call_info_with_kwarg *)ci)->kw_arg;

 if (iseq->body->param.flags.has_kw) {
     int kw_len = args->kw_arg->keyword_len;

     args->kw_argv = (VALUE*)__builtin_alloca_with_align((sizeof(VALUE)*(kw_len)), _Alignof(VALUE) * 8);
     args->argc -= kw_len;
     given_argc -= kw_len;
     __builtin___memcpy_chk ((args->kw_argv), (locals + args->argc), sizeof(VALUE)*(size_t)(kw_len), __builtin_object_size ((args->kw_argv), 0));
 }
 else {
     args->kw_argv = ((void*)0);
     given_argc = args_kw_argv_to_hash(args);
     kw_flag |= (0x01 << VM_CALL_KW_SPLAT_bit);
 }
    }
    else {
 args->kw_arg = ((void*)0);
 args->kw_argv = ((void*)0);
    }

    if (kw_flag && iseq->body->param.flags.ruby2_keywords) {
        remove_empty_keyword_hash = 0;
    }

    if (ci->flag & (0x01 << VM_CALL_ARGS_SPLAT_bit)) {
        VALUE rest_last = 0;
        int len;
 args->rest = locals[--args->argc];
 args->rest_index = 0;
        len = rb_long2int_inline(rb_array_len(args->rest));
        given_argc += len - 1;
        rest_last = (rb_array_const_ptr_transient(args->rest)[len - 1]);

        if (!kw_flag && len > 0) {
            if (( ((RUBY_T_HASH) == RUBY_T_FIXNUM) ? (((int)(long)(rest_last))&RUBY_FIXNUM_FLAG) : ((RUBY_T_HASH) == RUBY_T_TRUE) ? ((rest_last) == ((VALUE)RUBY_Qtrue)) : ((RUBY_T_HASH) == RUBY_T_FALSE) ? ((rest_last) == ((VALUE)RUBY_Qfalse)) : ((RUBY_T_HASH) == RUBY_T_NIL) ? ((rest_last) == ((VALUE)RUBY_Qnil)) : ((RUBY_T_HASH) == RUBY_T_UNDEF) ? ((rest_last) == ((VALUE)RUBY_Qundef)) : ((RUBY_T_HASH) == RUBY_T_SYMBOL) ? ((((VALUE)(rest_last)&~((~(VALUE)0)<<RUBY_SPECIAL_SHIFT)) == RUBY_SYMBOL_FLAG)||(!(((VALUE)(rest_last) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(rest_last) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(rest_last))->flags & RUBY_T_MASK) == (RUBY_T_SYMBOL))) : ((RUBY_T_HASH) == RUBY_T_FLOAT) ? ( ((((int)(long)(rest_last))&RUBY_FLONUM_MASK) == RUBY_FLONUM_FLAG) || (!(((VALUE)(rest_last) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(rest_last) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(rest_last))->flags & RUBY_T_MASK) == RUBY_T_FLOAT)) : (!(((VALUE)(rest_last) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(rest_last) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(rest_last))->flags & RUBY_T_MASK) == (RUBY_T_HASH))) &&
                (((struct RHash *)rest_last)->basic.flags & RHASH_PASS_AS_KEYWORDS)) {
                rest_last = rb_hash_dup(rest_last);
                kw_flag |= (0x01 << VM_CALL_KW_SPLAT_bit);
                if (iseq->body->param.flags.ruby2_keywords) {
                    remove_empty_keyword_hash = 0;
                }
            }
            else {
                rest_last = 0;
            }
        }

        if (kw_flag & (0x01 << VM_CALL_KW_SPLAT_bit)) {
            if (len > 0 && ignore_keyword_hash_p(rest_last, iseq)) {
                if (given_argc != min_argc) {
                    if (remove_empty_keyword_hash) {
                        arg_rest_dup(args);
                        rb_ary_pop(args->rest);
                        given_argc--;
                        kw_flag &= ~(0x01 << VM_CALL_KW_SPLAT_bit);
                    }
                    else {
                        if (( ((RUBY_T_HASH) == RUBY_T_FIXNUM) ? (((int)(long)(rest_last))&RUBY_FIXNUM_FLAG) : ((RUBY_T_HASH) == RUBY_T_TRUE) ? ((rest_last) == ((VALUE)RUBY_Qtrue)) : ((RUBY_T_HASH) == RUBY_T_FALSE) ? ((rest_last) == ((VALUE)RUBY_Qfalse)) : ((RUBY_T_HASH) == RUBY_T_NIL) ? ((rest_last) == ((VALUE)RUBY_Qnil)) : ((RUBY_T_HASH) == RUBY_T_UNDEF) ? ((rest_last) == ((VALUE)RUBY_Qundef)) : ((RUBY_T_HASH) == RUBY_T_SYMBOL) ? ((((VALUE)(rest_last)&~((~(VALUE)0)<<RUBY_SPECIAL_SHIFT)) == RUBY_SYMBOL_FLAG)||(!(((VALUE)(rest_last) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(rest_last) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(rest_last))->flags & RUBY_T_MASK) == (RUBY_T_SYMBOL))) : ((RUBY_T_HASH) == RUBY_T_FLOAT) ? ( ((((int)(long)(rest_last))&RUBY_FLONUM_MASK) == RUBY_FLONUM_FLAG) || (!(((VALUE)(rest_last) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(rest_last) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(rest_last))->flags & RUBY_T_MASK) == RUBY_T_FLOAT)) : (!(((VALUE)(rest_last) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(rest_last) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(rest_last))->flags & RUBY_T_MASK) == (RUBY_T_HASH))) && rb_obj_frozen_p(rest_last)) {
                            rest_last = rb_hash_new();
                            do { const VALUE _ary = (args->rest); const VALUE _v = (rest_last); VALUE *ptr = (VALUE *)rb_array_ptr_use_start(_ary, 1); __extension__({
;
; typeof(rb_obj_write((VALUE)(_ary), (VALUE *)(&ptr[len - 1]), (VALUE)(_v), "./vm_args.c", 826)) unaligned_member_access_result = (rb_obj_write((VALUE)(_ary), (VALUE *)(&ptr[len - 1]), (VALUE)(_v), "./vm_args.c", 826));
; unaligned_member_access_result; }); rb_array_ptr_use_end(_ary, 1); } while (0);
                        }
                        flag_keyword_hash = rest_last;
                    }
                }
                else {
                    rb_warn_keyword_to_last_hash(ec, calling, ci, iseq);
                }
     }
            else if (!remove_empty_keyword_hash && rest_last) {
                flag_keyword_hash = rest_last;
            }
        }
    }
    else {
        if (kw_flag & (0x01 << VM_CALL_KW_SPLAT_bit)) {
            VALUE last_arg = args->argv[args->argc-1];
            if (ignore_keyword_hash_p(last_arg, iseq)) {
                if (given_argc != min_argc) {
                    if (remove_empty_keyword_hash) {
                        args->argc--;
                        given_argc--;
                        kw_flag &= ~(0x01 << VM_CALL_KW_SPLAT_bit);
                    }
                    else {
                        if (( ((RUBY_T_HASH) == RUBY_T_FIXNUM) ? (((int)(long)(last_arg))&RUBY_FIXNUM_FLAG) : ((RUBY_T_HASH) == RUBY_T_TRUE) ? ((last_arg) == ((VALUE)RUBY_Qtrue)) : ((RUBY_T_HASH) == RUBY_T_FALSE) ? ((last_arg) == ((VALUE)RUBY_Qfalse)) : ((RUBY_T_HASH) == RUBY_T_NIL) ? ((last_arg) == ((VALUE)RUBY_Qnil)) : ((RUBY_T_HASH) == RUBY_T_UNDEF) ? ((last_arg) == ((VALUE)RUBY_Qundef)) : ((RUBY_T_HASH) == RUBY_T_SYMBOL) ? ((((VALUE)(last_arg)&~((~(VALUE)0)<<RUBY_SPECIAL_SHIFT)) == RUBY_SYMBOL_FLAG)||(!(((VALUE)(last_arg) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(last_arg) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(last_arg))->flags & RUBY_T_MASK) == (RUBY_T_SYMBOL))) : ((RUBY_T_HASH) == RUBY_T_FLOAT) ? ( ((((int)(long)(last_arg))&RUBY_FLONUM_MASK) == RUBY_FLONUM_FLAG) || (!(((VALUE)(last_arg) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(last_arg) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(last_arg))->flags & RUBY_T_MASK) == RUBY_T_FLOAT)) : (!(((VALUE)(last_arg) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(last_arg) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(last_arg))->flags & RUBY_T_MASK) == (RUBY_T_HASH))) && rb_obj_frozen_p(last_arg)) {
                            last_arg = rb_hash_new();
                            args->argv[args->argc-1] = last_arg;
                        }
                        flag_keyword_hash = last_arg;
                    }
                }
                else {
                    rb_warn_keyword_to_last_hash(ec, calling, ci, iseq);
                }
     }
            else if (!remove_empty_keyword_hash) {
                flag_keyword_hash = args->argv[args->argc-1];
            }
        }
 args->rest = ((VALUE)RUBY_Qfalse);
    }

    if (flag_keyword_hash && ( ((RUBY_T_HASH) == RUBY_T_FIXNUM) ? (((int)(long)(flag_keyword_hash))&RUBY_FIXNUM_FLAG) : ((RUBY_T_HASH) == RUBY_T_TRUE) ? ((flag_keyword_hash) == ((VALUE)RUBY_Qtrue)) : ((RUBY_T_HASH) == RUBY_T_FALSE) ? ((flag_keyword_hash) == ((VALUE)RUBY_Qfalse)) : ((RUBY_T_HASH) == RUBY_T_NIL) ? ((flag_keyword_hash) == ((VALUE)RUBY_Qnil)) : ((RUBY_T_HASH) == RUBY_T_UNDEF) ? ((flag_keyword_hash) == ((VALUE)RUBY_Qundef)) : ((RUBY_T_HASH) == RUBY_T_SYMBOL) ? ((((VALUE)(flag_keyword_hash)&~((~(VALUE)0)<<RUBY_SPECIAL_SHIFT)) == RUBY_SYMBOL_FLAG)||(!(((VALUE)(flag_keyword_hash) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(flag_keyword_hash) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(flag_keyword_hash))->flags & RUBY_T_MASK) == (RUBY_T_SYMBOL))) : ((RUBY_T_HASH) == RUBY_T_FLOAT) ? ( ((((int)(long)(flag_keyword_hash))&RUBY_FLONUM_MASK) == RUBY_FLONUM_FLAG) || (!(((VALUE)(flag_keyword_hash) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(flag_keyword_hash) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(flag_keyword_hash))->flags & RUBY_T_MASK) == RUBY_T_FLOAT)) : (!(((VALUE)(flag_keyword_hash) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(flag_keyword_hash) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(flag_keyword_hash))->flags & RUBY_T_MASK) == (RUBY_T_HASH)))) {
        ((struct RHash *)flag_keyword_hash)->basic.flags |= RHASH_PASS_AS_KEYWORDS;
    }

    if (kw_flag && iseq->body->param.flags.accepts_no_kwarg) {
 rb_raise(rb_eArgError, "no keywords accepted");
    }

    switch (arg_setup_type) {
      case arg_setup_method:
 break;
      case arg_setup_block:
 if (given_argc == 1 &&
            allow_autosplat &&
     (min_argc > 0 || iseq->body->param.opt_num > 1 ||
      iseq->body->param.flags.has_kw || iseq->body->param.flags.has_kwrest) &&
     !iseq->body->param.flags.ambiguous_param0 &&
     args_check_block_arg0(args)) {
     given_argc = rb_long2int_inline(rb_array_len(args->rest));
 }
 break;
    }


    if (given_argc < min_argc) {
 if (given_argc == min_argc - 1 && args->kw_argv) {
     args_stored_kw_argv_to_hash(args);
     given_argc = args_argc(args);
 }
 else {
     if (arg_setup_type == arg_setup_block) {
  if ((__builtin_expect(!!(!(!(1/!!(sizeof(*((ec->cfp)->sp)) == sizeof(VALUE))) || !(1/!!(sizeof(*(ec->cfp)) == sizeof(rb_control_frame_t))) || ((rb_control_frame_t *)(((ec->cfp)->sp) + (min_argc)) + 1) >= (ec->cfp))), 1))) {(void)0;} else vm_stackoverflow();
  given_argc = min_argc;
  args_extend(args, min_argc);
     }
     else {
  argument_arity_error(ec, iseq, given_argc, min_argc, max_argc);
     }
 }
    }

    if (kw_flag & (0x01 << VM_CALL_KW_SPLAT_bit)) {
 kw_splat = !iseq->body->param.flags.has_rest;
    }
    if ((iseq->body->param.flags.has_kw || iseq->body->param.flags.has_kwrest ||
  (kw_splat && given_argc > max_argc)) &&
 args->kw_argv == ((void*)0)) {
        if (given_argc > min_argc) {
            if (kw_flag) {
                int check_only_symbol = (kw_flag & (0x01 << VM_CALL_KW_SPLAT_bit)) &&
                                        iseq->body->param.flags.has_kw &&
                                        !iseq->body->param.flags.has_kwrest;

                if (args_pop_keyword_hash(args, &keyword_hash, check_only_symbol)) {
                    given_argc--;
                }
                else if (check_only_symbol) {
                    if (keyword_hash != ((VALUE)RUBY_Qnil)) {
                        rb_warn_split_last_hash_to_keyword(ec, calling, ci, iseq);
                    }
                    else {
                        rb_warn_keyword_to_last_hash(ec, calling, ci, iseq);
                    }
                }
            }
            else if (args_pop_keyword_hash(args, &keyword_hash, 1)) {




                rb_warn_last_hash_to_keyword(ec, calling, ci, iseq);
                given_argc--;
            }
            else if (keyword_hash != ((VALUE)RUBY_Qnil)) {
                rb_warn_split_last_hash_to_keyword(ec, calling, ci, iseq);
            }
        }
        else if (given_argc == min_argc && kw_flag) {
            rb_warn_keyword_to_last_hash(ec, calling, ci, iseq);
        }
    }

    if (given_argc > max_argc && max_argc != (-1)) {
 if (arg_setup_type == arg_setup_block) {

     args_reduce(args, given_argc - max_argc);
     given_argc = max_argc;
 }
 else {
     argument_arity_error(ec, iseq, given_argc, min_argc, max_argc);
 }
    }

    if (iseq->body->param.flags.has_lead) {
 args_setup_lead_parameters(args, iseq->body->param.lead_num, locals + 0);
    }

    if (iseq->body->param.flags.has_rest || iseq->body->param.flags.has_post){
        args_copy(args);
    }

    if (iseq->body->param.flags.has_post) {
 args_setup_post_parameters(args, iseq->body->param.post_num, locals + iseq->body->param.post_start);
    }

    if (iseq->body->param.flags.has_opt) {
 int opt = args_setup_opt_parameters(args, iseq->body->param.opt_num, locals + iseq->body->param.lead_num);
 opt_pc = (int)iseq->body->param.opt_table[opt];
    }

    if (iseq->body->param.flags.has_rest) {
 args_setup_rest_parameter(args, locals + iseq->body->param.rest_start);
    }

    if (iseq->body->param.flags.has_kw) {
 VALUE * const klocals = locals + iseq->body->param.keyword->bits_start - iseq->body->param.keyword->num;

 if (args->kw_argv != ((void*)0)) {
     const struct rb_call_info_kw_arg *kw_arg = args->kw_arg;
     args_setup_kw_parameters(ec, iseq, args->kw_argv, kw_arg->keyword_len, kw_arg->keywords, klocals);
 }
 else if (!!((VALUE)(keyword_hash) != ((VALUE)RUBY_Qnil))) {
     int kw_len = rb_long2int_inline(((!(((struct RBasic*)((keyword_hash)))->flags&(RHASH_ST_TABLE_FLAG))) ? ((unsigned int)((((struct RBasic*)(keyword_hash))->flags & (VALUE)RHASH_AR_TABLE_SIZE_MASK) >> RHASH_AR_TABLE_SIZE_SHIFT)) : ((((struct RHash*)(keyword_hash))->as.st)->num_entries)));
     struct fill_values_arg arg;

     arg.keys = args->kw_argv = (VALUE*)__builtin_alloca_with_align((sizeof(VALUE)*(kw_len * 2)), _Alignof(VALUE) * 8);
     arg.vals = arg.keys + kw_len;
     arg.argc = 0;
     rb_hash_foreach(keyword_hash, fill_keys_values, (VALUE)&arg);
     ((void)0);
     args_setup_kw_parameters(ec, iseq, arg.vals, kw_len, arg.keys, klocals);
 }
 else {
     ((void)0);
     args_setup_kw_parameters(ec, iseq, ((void*)0), 0, ((void*)0), klocals);
 }
    }
    else if (iseq->body->param.flags.has_kwrest) {
 args_setup_kw_rest_parameter(keyword_hash, locals + iseq->body->param.keyword->rest_start);
    }
    else if (!!((VALUE)(keyword_hash) != ((VALUE)RUBY_Qnil)) && ((!(((struct RBasic*)((keyword_hash)))->flags&(RHASH_ST_TABLE_FLAG))) ? ((unsigned int)((((struct RBasic*)(keyword_hash))->flags & (VALUE)RHASH_AR_TABLE_SIZE_MASK) >> RHASH_AR_TABLE_SIZE_SHIFT)) : ((((struct RHash*)(keyword_hash))->as.st)->num_entries)) > 0 && arg_setup_type == arg_setup_method) {
 argument_kw_error(ec, iseq, "unknown", rb_hash_keys(keyword_hash));
    }

    if (iseq->body->param.flags.has_block) {
 if (iseq->body->local_iseq == iseq) {

 }
 else {
     args_setup_block_parameter(ec, calling, locals + iseq->body->param.block_start);
 }
    }
    ec->cfp->sp = orig_sp;
    return opt_pc;
}

void rb_backtrace_use_iseq_first_lineno_for_last_location(VALUE self);

static void
raise_argument_error(rb_execution_context_t *ec, const rb_iseq_t *iseq, const VALUE exc)
{
    VALUE at;

    if (iseq) {
 vm_push_frame(ec, iseq, VM_FRAME_MAGIC_DUMMY | VM_ENV_FLAG_LOCAL, ((VALUE)RUBY_Qnil) ,
        0 , ((VALUE)RUBY_Qfalse) ,
        iseq->body->iseq_encoded,
        ec->cfp->sp, 0, 0 );
 at = rb_ec_backtrace_object(ec);
 rb_backtrace_use_iseq_first_lineno_for_last_location(at);
 rb_vm_pop_frame(ec);
    }
    else {
 at = rb_ec_backtrace_object(ec);
    }

    rb_ivar_set(exc, idBt_locations, at);
    rb_exc_set_backtrace(exc, at);
    rb_exc_raise(exc);
}

static void
argument_arity_error(rb_execution_context_t *ec, const rb_iseq_t *iseq, const int miss_argc, const int min_argc, const int max_argc)
{
    VALUE exc = rb_arity_error_new(miss_argc, min_argc, max_argc);
    if (iseq->body->param.flags.has_kw) {
 const struct rb_iseq_param_keyword *const kw = iseq->body->param.keyword;
 const ID *keywords = kw->table;
 int req_key_num = kw->required_num;
 if (req_key_num > 0) {
     static const char required[] = "; required keywords";
     VALUE mesg = rb_attr_get(exc, idMesg);
     rb_str_resize(mesg, (!(((struct RBasic*)(mesg))->flags & RSTRING_NOEMBED) ? (long)((((struct RBasic*)(mesg))->flags >> RSTRING_EMBED_LEN_SHIFT) & (RSTRING_EMBED_LEN_MASK >> RSTRING_EMBED_LEN_SHIFT)) : ((struct RString*)(mesg))->as.heap.len)-1);
     rb_str_cat(mesg, required, sizeof(required) - 1 - (req_key_num == 1));
     __extension__ ({ (__builtin_constant_p(":")) ? rb_str_cat((mesg), (":"), (long)strlen(":")) : rb_str_cat_cstr((mesg), (":")); });
     do {
  __extension__ ({ (__builtin_constant_p(" ")) ? rb_str_cat((mesg), (" "), (long)strlen(" ")) : rb_str_cat_cstr((mesg), (" ")); });
  rb_str_append(mesg, rb_id2str(*keywords++));
  __extension__ ({ (__builtin_constant_p(",")) ? rb_str_cat((mesg), (","), (long)strlen(",")) : rb_str_cat_cstr((mesg), (",")); });
     } while (--req_key_num);
     (!(((struct RBasic*)(mesg))->flags & RSTRING_NOEMBED) ? ((struct RString*)(mesg))->as.ary : ((struct RString*)(mesg))->as.heap.ptr)[(!(((struct RBasic*)(mesg))->flags & RSTRING_NOEMBED) ? (long)((((struct RBasic*)(mesg))->flags >> RSTRING_EMBED_LEN_SHIFT) & (RSTRING_EMBED_LEN_MASK >> RSTRING_EMBED_LEN_SHIFT)) : ((struct RString*)(mesg))->as.heap.len)-1] = ')';
 }
    }
    raise_argument_error(ec, iseq, exc);
}

static void
argument_kw_error(rb_execution_context_t *ec, const rb_iseq_t *iseq, const char *error, const VALUE keys)
{
    raise_argument_error(ec, iseq, rb_keyword_error_new(error, keys));
}

static inline void
vm_caller_setup_arg_splat(rb_control_frame_t *cfp, struct rb_calling_info *calling)
{
    int argc = calling->argc;
    VALUE *argv = cfp->sp - argc;
    VALUE ary = argv[argc-1];

                                      ;
    cfp->sp--;

    if (!!((VALUE)(ary) != ((VALUE)RUBY_Qnil))) {
        const VALUE *ptr = rb_array_const_ptr_transient(ary);
        long len = rb_array_len(ary), i;

        if ((__builtin_expect(!!(!(!(1/!!(sizeof(*((cfp)->sp)) == sizeof(VALUE))) || !(1/!!(sizeof(*(cfp)) == sizeof(rb_control_frame_t))) || ((rb_control_frame_t *)(((cfp)->sp) + (len)) + 1) >= (cfp))), 1))) {(void)0;} else vm_stackoverflow();

        for (i = 0; i < len; i++) {
            *cfp->sp++ = ptr[i];
        }
        calling->argc += i - 1;
    }
}

static inline void
vm_caller_setup_arg_kw(rb_control_frame_t *cfp, struct rb_calling_info *calling, const struct rb_call_info *ci)
{
    struct rb_call_info_with_kwarg *ci_kw = (struct rb_call_info_with_kwarg *)ci;
    const VALUE *const passed_keywords = ci_kw->kw_arg->keywords;
    const int kw_len = ci_kw->kw_arg->keyword_len;
    const VALUE h = rb_hash_new_with_size(kw_len);
    VALUE *sp = cfp->sp;
    int i;

    for (i=0; i<kw_len; i++) {
 rb_hash_aset(h, passed_keywords[i], (sp - kw_len)[i]);
    }
    (sp-kw_len)[0] = h;

    cfp->sp -= kw_len - 1;
    calling->argc -= kw_len - 1;
    calling->kw_splat = 1;
}

static VALUE
vm_to_proc(VALUE proc)
{
    if ((__builtin_expect(!!(!rb_obj_is_proc(proc)), 0))) {
 VALUE b;
 const rb_callable_method_entry_t *me =
     rb_callable_method_entry_with_refinements(rb_class_of((VALUE)(proc)), idTo_proc, ((void*)0));

 if (me) {
            b = rb_vm_call0(rb_current_execution_context(), proc, idTo_proc, 0, ((void*)0), me, 0);
 }
 else {

     b = rb_check_convert_type_with_id(proc, RUBY_T_DATA, "Proc", idTo_proc);
 }

 if (!((VALUE)(b) != ((VALUE)RUBY_Qnil)) || !rb_obj_is_proc(b)) {
     rb_raise(rb_eTypeError,
       "wrong argument type %s (expected Proc)",
       rb_obj_classname(proc));
 }
 return b;
    }
    else {
 return proc;
    }
}

static VALUE
refine_sym_proc_call(VALUE yielded_arg, VALUE callback_arg, int argc, const VALUE *argv, VALUE blockarg)
{
    VALUE obj;
    ID mid;
    const rb_callable_method_entry_t *me;
    rb_execution_context_t *ec;
    const VALUE symbol = (rb_array_const_ptr_transient(callback_arg)[0]);
    const VALUE refinements = (rb_array_const_ptr_transient(callback_arg)[1]);
    int kw_splat = 3;
    VALUE v;
    VALUE ret;
    VALUE klass;

    if (argc-- < 1) {
 rb_raise(rb_eArgError, "no receiver given");
    }
    obj = *argv++;

    mid = (rb_sym2id(symbol));
    for (klass = rb_class_of((VALUE)(obj)); klass; klass = RCLASS_SUPER(klass)) {
        me = rb_callable_method_entry(klass, mid);
        if (me) {
            me = rb_resolve_refined_method_callable(refinements, me);
            if (me) break;
        }
    }

    ec = rb_current_execution_context();
    if (!!((VALUE)(blockarg) != ((VALUE)RUBY_Qnil))) {
 vm_passed_block_handler_set(ec, blockarg);
    }
    v = rb_adjust_argv_kw_splat(&argc, &argv, &kw_splat);
    if (!me) {
        ret = method_missing(obj, mid, argc, argv, MISSING_NOENTRY, kw_splat);
    }
    else {
        ret = rb_vm_call0(ec, obj, mid, argc, argv, me, kw_splat);
    }
    rb_free_tmp_buffer(&v);
    return ret;
}

static VALUE
vm_caller_setup_arg_block(const rb_execution_context_t *ec, rb_control_frame_t *reg_cfp,
                          const struct rb_call_info *ci, const rb_iseq_t *blockiseq, const int is_super)
{
    if (ci->flag & (0x01 << VM_CALL_ARGS_BLOCKARG_bit)) {
 VALUE block_code = *(--reg_cfp->sp);

 if (!((VALUE)(block_code) != ((VALUE)RUBY_Qnil))) {
            return 0;
        }
 else if (block_code == rb_block_param_proxy) {
            ((void)0);
            VALUE handler = VM_CF_BLOCK_HANDLER(reg_cfp);
            reg_cfp->block_code = (const void *) handler;
            return handler;
        }
 else if (((((VALUE)(block_code)&~((~(VALUE)0)<<RUBY_SPECIAL_SHIFT)) == RUBY_SYMBOL_FLAG)||(!(((VALUE)(block_code) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(block_code) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(block_code))->flags & RUBY_T_MASK) == (RUBY_T_SYMBOL))) && __extension__({ static struct rb_call_data rb_mbdp; (rb_cSymbol == ((VALUE)RUBY_Qfalse)) ? 1 : rb_method_basic_definition_p_with_cc(&rb_mbdp, rb_cSymbol, idTo_proc); })) {
     const rb_cref_t *cref = vm_env_cref(reg_cfp->ep);
     if (cref && !!((VALUE)(cref->refinements) != ((VALUE)RUBY_Qnil))) {
  VALUE ref = cref->refinements;
  VALUE func = rb_hash_lookup(ref, block_code);
  if (!((VALUE)(func) != ((VALUE)RUBY_Qnil))) {

                    VALUE callback_arg = rb_ary_tmp_new(2);
                    rb_ary_push(callback_arg, block_code);
                    rb_ary_push(callback_arg, ref);
                    (void)(((struct RBasic*)(callback_arg))->flags |= RUBY_FL_FREEZE);
                    func = rb_func_proc_new(refine_sym_proc_call, callback_arg);
      rb_hash_aset(ref, block_code, func);
  }
  block_code = func;
     }
            return block_code;
        }
        else {
            return vm_to_proc(block_code);
        }
    }
    else if (blockiseq != ((void*)0)) {
 struct rb_captured_block *captured = VM_CFP_TO_CAPTURED_BLOCK(reg_cfp);
 captured->code.iseq = blockiseq;
        return VM_BH_FROM_ISEQ_BLOCK(captured);
    }
    else {
 if (is_super) {
            return ((VM_EP_LEP(((((reg_cfp)->ep)))))[(-1)]);
        }
        else {
            return 0;
        }
    }
}

static inline VALUE vm_call_iseq_setup_2(rb_execution_context_t *ec, rb_control_frame_t *cfp, struct rb_calling_info *calling, struct rb_call_data *cd, int opt_pc, int param_size, int local_size);
__attribute__ ((__always_inline__)) static VALUE vm_call_iseq_setup_normal(rb_execution_context_t *ec, rb_control_frame_t *cfp, struct rb_calling_info *calling, const rb_callable_method_entry_t *me, int opt_pc, int param_size, int local_size);
static inline VALUE vm_call_iseq_setup_tailcall(rb_execution_context_t *ec, rb_control_frame_t *cfp, struct rb_calling_info *calling, struct rb_call_data *cd, int opt_pc);
static VALUE vm_call_super_method(rb_execution_context_t *ec, rb_control_frame_t *reg_cfp, struct rb_calling_info *calling, struct rb_call_data *cd);
static VALUE vm_call_method_nome(rb_execution_context_t *ec, rb_control_frame_t *cfp, struct rb_calling_info *calling, struct rb_call_data *cd);
static VALUE vm_call_method_each_type(rb_execution_context_t *ec, rb_control_frame_t *cfp, struct rb_calling_info *calling, struct rb_call_data *cd);
static inline VALUE vm_call_method(rb_execution_context_t *ec, rb_control_frame_t *cfp, struct rb_calling_info *calling, struct rb_call_data *cd);

static vm_call_handler vm_call_iseq_setup_func(const struct rb_call_info *ci, const int param_size, const int local_size);

static VALUE
vm_call_iseq_setup_tailcall_0start(rb_execution_context_t *ec, rb_control_frame_t *cfp, struct rb_calling_info *calling, struct rb_call_data *cd)
{
    ((void)0);

    return vm_call_iseq_setup_tailcall(ec, cfp, calling, cd, 0);
}

static VALUE
vm_call_iseq_setup_normal_0start(rb_execution_context_t *ec, rb_control_frame_t *cfp, struct rb_calling_info *calling, struct rb_call_data *cd)
{
    ((void)0);

    struct rb_call_cache *cc = &cd->cc;
    const rb_iseq_t *iseq = def_iseq_ptr(cc->me->def);
    int param = iseq->body->param.size;
    int local = iseq->body->local_table_size;
    return vm_call_iseq_setup_normal(ec, cfp, calling, cc->me, 0, param, local);
}

static _Bool
rb_simple_iseq_p(const rb_iseq_t *iseq)
{
    return iseq->body->param.flags.has_opt == 0 &&
           iseq->body->param.flags.has_rest == 0 &&
    iseq->body->param.flags.has_post == 0 &&
    iseq->body->param.flags.has_kw == 0 &&
    iseq->body->param.flags.has_kwrest == 0 &&
           iseq->body->param.flags.accepts_no_kwarg == 0 &&
    iseq->body->param.flags.has_block == 0;
}

static _Bool
rb_iseq_only_optparam_p(const rb_iseq_t *iseq)
{
    return iseq->body->param.flags.has_opt == 1 &&
           iseq->body->param.flags.has_rest == 0 &&
           iseq->body->param.flags.has_post == 0 &&
           iseq->body->param.flags.has_kw == 0 &&
           iseq->body->param.flags.has_kwrest == 0 &&
           iseq->body->param.flags.accepts_no_kwarg == 0 &&
           iseq->body->param.flags.has_block == 0;
}

static _Bool
rb_iseq_only_kwparam_p(const rb_iseq_t *iseq)
{
    return iseq->body->param.flags.has_opt == 0 &&
           iseq->body->param.flags.has_rest == 0 &&
           iseq->body->param.flags.has_post == 0 &&
           iseq->body->param.flags.has_kw == 1 &&
           iseq->body->param.flags.has_kwrest == 0 &&
           iseq->body->param.flags.has_block == 0;
}


static inline void
CALLER_SETUP_ARG(struct rb_control_frame_struct *restrict cfp,
                 struct rb_calling_info *restrict calling,
                 const struct rb_call_info *restrict ci)
{
    if ((__builtin_expect(!!(((ci)->flag & (0x01 << VM_CALL_ARGS_SPLAT_bit))), 0))) {
        VALUE final_hash;



        vm_caller_setup_arg_splat(cfp, calling);
        if (!((ci)->flag & ((0x01 << VM_CALL_KWARG_bit) | (0x01 << VM_CALL_KW_SPLAT_bit))) &&
                calling->argc > 0 &&
                ( ((RUBY_T_HASH) == RUBY_T_FIXNUM) ? (((int)(long)((final_hash = *(cfp->sp - 1))))&RUBY_FIXNUM_FLAG) : ((RUBY_T_HASH) == RUBY_T_TRUE) ? (((final_hash = *(cfp->sp - 1))) == ((VALUE)RUBY_Qtrue)) : ((RUBY_T_HASH) == RUBY_T_FALSE) ? (((final_hash = *(cfp->sp - 1))) == ((VALUE)RUBY_Qfalse)) : ((RUBY_T_HASH) == RUBY_T_NIL) ? (((final_hash = *(cfp->sp - 1))) == ((VALUE)RUBY_Qnil)) : ((RUBY_T_HASH) == RUBY_T_UNDEF) ? (((final_hash = *(cfp->sp - 1))) == ((VALUE)RUBY_Qundef)) : ((RUBY_T_HASH) == RUBY_T_SYMBOL) ? ((((VALUE)((final_hash = *(cfp->sp - 1)))&~((~(VALUE)0)<<RUBY_SPECIAL_SHIFT)) == RUBY_SYMBOL_FLAG)||(!(((VALUE)((final_hash = *(cfp->sp - 1))) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)((final_hash = *(cfp->sp - 1))) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)((final_hash = *(cfp->sp - 1))))->flags & RUBY_T_MASK) == (RUBY_T_SYMBOL))) : ((RUBY_T_HASH) == RUBY_T_FLOAT) ? ( ((((int)(long)((final_hash = *(cfp->sp - 1))))&RUBY_FLONUM_MASK) == RUBY_FLONUM_FLAG) || (!(((VALUE)((final_hash = *(cfp->sp - 1))) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)((final_hash = *(cfp->sp - 1))) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)((final_hash = *(cfp->sp - 1))))->flags & RUBY_T_MASK) == RUBY_T_FLOAT)) : (!(((VALUE)((final_hash = *(cfp->sp - 1))) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)((final_hash = *(cfp->sp - 1))) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)((final_hash = *(cfp->sp - 1))))->flags & RUBY_T_MASK) == (RUBY_T_HASH))) &&
                (((struct RHash *)final_hash)->basic.flags & RHASH_PASS_AS_KEYWORDS)) {
            *(cfp->sp - 1) = rb_hash_dup(final_hash);
            calling->kw_splat = 1;
        }
    }
    if ((__builtin_expect(!!(((ci)->flag & (0x01 << VM_CALL_KWARG_bit))), 0))) {




        vm_caller_setup_arg_kw(cfp, calling, ci);
    }
}

static inline void
CALLER_REMOVE_EMPTY_KW_SPLAT(struct rb_control_frame_struct *restrict cfp,
                             struct rb_calling_info *restrict calling,
                             const struct rb_call_info *restrict ci)
{
    if ((__builtin_expect(!!(calling->kw_splat), 0))) {
        if ((((!(((struct RBasic*)((cfp->sp[-1])))->flags&(RHASH_ST_TABLE_FLAG))) ? ((unsigned int)((((struct RBasic*)(cfp->sp[-1]))->flags & (VALUE)RHASH_AR_TABLE_SIZE_MASK) >> RHASH_AR_TABLE_SIZE_SHIFT)) : ((((struct RHash*)(cfp->sp[-1]))->as.st)->num_entries)) == 0)) {
            cfp->sp--;
            calling->argc--;
            calling->kw_splat = 0;
        }
    }
}

static VALUE
vm_call_iseq_setup_normal_opt_start(rb_execution_context_t *ec, rb_control_frame_t *cfp,
                                    struct rb_calling_info *calling,
                                    struct rb_call_data *cd)
{
    const struct rb_call_cache *cc = &cd->cc;
    const rb_iseq_t *iseq = def_iseq_ptr(cc->me->def);
    const int lead_num = iseq->body->param.lead_num;
    const int opt = calling->argc - lead_num;
    const int opt_num = iseq->body->param.opt_num;
    const int opt_pc = (int)iseq->body->param.opt_table[opt];
    const int param = iseq->body->param.size;
    const int local = iseq->body->local_table_size;
    const int delta = opt_num - opt;

    ((void)0);
    return vm_call_iseq_setup_normal(ec, cfp, calling, cc->me, opt_pc, param - delta, local);
}

static VALUE
vm_call_iseq_setup_tailcall_opt_start(rb_execution_context_t *ec, rb_control_frame_t *cfp,
                                      struct rb_calling_info *calling,
                                      struct rb_call_data *cd)
{
    const struct rb_call_cache *cc = &cd->cc;
    const rb_iseq_t *iseq = def_iseq_ptr(cc->me->def);
    const int lead_num = iseq->body->param.lead_num;
    const int opt = calling->argc - lead_num;
    const int opt_pc = (int)iseq->body->param.opt_table[opt];

    ((void)0);
    return vm_call_iseq_setup_tailcall(ec, cfp, calling, cd, opt_pc);
}

static void
args_setup_kw_parameters(rb_execution_context_t *const ec, const rb_iseq_t *const iseq,
                         VALUE *const passed_values, const int passed_keyword_len, const VALUE *const passed_keywords,
                         VALUE *const locals);

static VALUE
vm_call_iseq_setup_kwparm_kwarg(rb_execution_context_t *ec, rb_control_frame_t *cfp,
                                struct rb_calling_info *calling,
                                struct rb_call_data *cd)
{
    const struct rb_kwarg_call_data *kcd = (void *)cd;
    const struct rb_call_info_with_kwarg *ci_kw = &kcd->ci_kw;
    const struct rb_call_cache *cc = &kcd->cc;

    ((void)0);
    ((void)0);

    const rb_iseq_t *iseq = def_iseq_ptr(cc->me->def);
    const struct rb_iseq_param_keyword *kw_param = iseq->body->param.keyword;
    const struct rb_call_info_kw_arg *kw_arg = ci_kw->kw_arg;
    const int ci_kw_len = kw_arg->keyword_len;
    const VALUE * const ci_keywords = kw_arg->keywords;
    VALUE *argv = cfp->sp - calling->argc;
    VALUE *const klocals = argv + kw_param->bits_start - kw_param->num;
    const int lead_num = iseq->body->param.lead_num;
    VALUE * const ci_kws = (VALUE*)__builtin_alloca_with_align((sizeof(VALUE)*(ci_kw_len)), _Alignof(VALUE) * 8);
    __builtin___memcpy_chk ((ci_kws), (argv + lead_num), sizeof(VALUE)*(size_t)(ci_kw_len), __builtin_object_size ((ci_kws), 0));
    args_setup_kw_parameters(ec, iseq, ci_kws, ci_kw_len, ci_keywords, klocals);

    int param = iseq->body->param.size;
    int local = iseq->body->local_table_size;
    return vm_call_iseq_setup_normal(ec, cfp, calling, cc->me, 0, param, local);
}

static VALUE
vm_call_iseq_setup_kwparm_nokwarg(rb_execution_context_t *ec, rb_control_frame_t *cfp,
                                  struct rb_calling_info *calling,
                                  struct rb_call_data *cd)
{
    const struct rb_call_info *__attribute__ ((__unused__)) ci = &cd->ci;
    const struct rb_call_cache *cc = &cd->cc;

    ((void)0);
    ((void)0);

    const rb_iseq_t *iseq = def_iseq_ptr(cc->me->def);
    const struct rb_iseq_param_keyword *kw_param = iseq->body->param.keyword;
    VALUE * const argv = cfp->sp - calling->argc;
    VALUE * const klocals = argv + kw_param->bits_start - kw_param->num;

    int i;
    for (i=0; i<kw_param->num; i++) {
        klocals[i] = kw_param->default_values[i];
    }
    klocals[i] = (((VALUE)(0))<<1 | RUBY_FIXNUM_FLAG);




    int param = iseq->body->param.size;
    int local = iseq->body->local_table_size;
    return vm_call_iseq_setup_normal(ec, cfp, calling, cc->me, 0, param, local);
}

static inline int
vm_callee_setup_arg(rb_execution_context_t *ec, struct rb_calling_info *calling, struct rb_call_data *cd,
      const rb_iseq_t *iseq, VALUE *argv, int param_size, int local_size)
{
    const struct rb_call_info *ci = &cd->ci;
    struct rb_call_cache *cc = &cd->cc;

    if ((__builtin_expect(!!(!(ci->flag & (0x01 << VM_CALL_KW_SPLAT_bit))), 1))) {
        if ((__builtin_expect(!!(rb_simple_iseq_p(iseq)), 1))) {
            rb_control_frame_t *cfp = ec->cfp;
            CALLER_SETUP_ARG(cfp, calling, ci);
            CALLER_REMOVE_EMPTY_KW_SPLAT(cfp, calling, ci);

            if (calling->argc != iseq->body->param.lead_num) {
                argument_arity_error(ec, iseq, calling->argc, iseq->body->param.lead_num, iseq->body->param.lead_num);
            }

            CC_SET_FASTPATH(cc, vm_call_iseq_setup_func(ci, param_size, local_size), vm_call_iseq_optimizable_p(&cd->ci, &cd->cc));
            return 0;
        }
        else if (rb_iseq_only_optparam_p(iseq)) {
            rb_control_frame_t *cfp = ec->cfp;
            CALLER_SETUP_ARG(cfp, calling, ci);
            CALLER_REMOVE_EMPTY_KW_SPLAT(cfp, calling, ci);

            const int lead_num = iseq->body->param.lead_num;
            const int opt_num = iseq->body->param.opt_num;
            const int argc = calling->argc;
            const int opt = argc - lead_num;

            if (opt < 0 || opt > opt_num) {
                argument_arity_error(ec, iseq, argc, lead_num, lead_num + opt_num);
            }

            if ((__builtin_expect(!!(!(ci->flag & (0x01 << VM_CALL_TAILCALL_bit))), 1))) {
                CC_SET_FASTPATH(cc, vm_call_iseq_setup_normal_opt_start,
                                !((ci)->flag & (0x01 << VM_CALL_ARGS_SPLAT_bit)) && !((ci)->flag & (0x01 << VM_CALL_KWARG_bit)) &&
                                !((rb_method_visibility_t)(((cc->me)->flags & (((VALUE)RUBY_FL_USER4) | ((VALUE)RUBY_FL_USER5))) >> ((((VALUE)RUBY_FL_USHIFT) + 4)+0)) == METHOD_VISI_PROTECTED));
            }
            else {
                CC_SET_FASTPATH(cc, vm_call_iseq_setup_tailcall_opt_start,
                                !((ci)->flag & (0x01 << VM_CALL_ARGS_SPLAT_bit)) && !((ci)->flag & (0x01 << VM_CALL_KWARG_bit)) &&
                                !((rb_method_visibility_t)(((cc->me)->flags & (((VALUE)RUBY_FL_USER4) | ((VALUE)RUBY_FL_USER5))) >> ((((VALUE)RUBY_FL_USHIFT) + 4)+0)) == METHOD_VISI_PROTECTED));
            }


            ((void)0);
            for (int i=argc; i<lead_num + opt_num; i++) {
                argv[i] = ((VALUE)RUBY_Qnil);
            }
            return (int)iseq->body->param.opt_table[opt];
        }
        else if (rb_iseq_only_kwparam_p(iseq) && !((ci)->flag & (0x01 << VM_CALL_ARGS_SPLAT_bit))) {
            const int lead_num = iseq->body->param.lead_num;
            const int argc = calling->argc;
            const struct rb_iseq_param_keyword *kw_param = iseq->body->param.keyword;

            if (ci->flag & (0x01 << VM_CALL_KWARG_bit)) {
                const struct rb_call_info_kw_arg *kw_arg = ((struct rb_call_info_with_kwarg *)ci)->kw_arg;

                if (argc - kw_arg->keyword_len == lead_num) {
                    const int ci_kw_len = kw_arg->keyword_len;
                    const VALUE * const ci_keywords = kw_arg->keywords;
                    VALUE * const ci_kws = (VALUE*)__builtin_alloca_with_align((sizeof(VALUE)*(ci_kw_len)), _Alignof(VALUE) * 8);
                    __builtin___memcpy_chk ((ci_kws), (argv + lead_num), sizeof(VALUE)*(size_t)(ci_kw_len), __builtin_object_size ((ci_kws), 0));

                    VALUE *const klocals = argv + kw_param->bits_start - kw_param->num;
                    args_setup_kw_parameters(ec, iseq, ci_kws, ci_kw_len, ci_keywords, klocals);

                    CC_SET_FASTPATH(cc, vm_call_iseq_setup_kwparm_kwarg,
                                    !((rb_method_visibility_t)(((cc->me)->flags & (((VALUE)RUBY_FL_USER4) | ((VALUE)RUBY_FL_USER5))) >> ((((VALUE)RUBY_FL_USHIFT) + 4)+0)) == METHOD_VISI_PROTECTED));

                    return 0;
                }
            }
            else if (argc == lead_num) {

                VALUE *const klocals = argv + kw_param->bits_start - kw_param->num;
                args_setup_kw_parameters(ec, iseq, ((void*)0), 0, ((void*)0), klocals);

                if (klocals[kw_param->num] == (((VALUE)(0))<<1 | RUBY_FIXNUM_FLAG)) {

                    CC_SET_FASTPATH(cc, vm_call_iseq_setup_kwparm_nokwarg,
                                    !((rb_method_visibility_t)(((cc->me)->flags & (((VALUE)RUBY_FL_USER4) | ((VALUE)RUBY_FL_USER5))) >> ((((VALUE)RUBY_FL_USHIFT) + 4)+0)) == METHOD_VISI_PROTECTED));
                }

                return 0;
            }
        }
    }

    return setup_parameters_complex(ec, iseq, calling, ci, argv, arg_setup_method);
}

static VALUE
vm_call_iseq_setup(rb_execution_context_t *ec, rb_control_frame_t *cfp, struct rb_calling_info *calling, struct rb_call_data *cd)
{
    ((void)0);

    const struct rb_call_cache *cc = &cd->cc;
    const rb_iseq_t *iseq = def_iseq_ptr(cc->me->def);
    const int param_size = iseq->body->param.size;
    const int local_size = iseq->body->local_table_size;
    const int opt_pc = vm_callee_setup_arg(ec, calling, cd, def_iseq_ptr(cc->me->def), cfp->sp - calling->argc, param_size, local_size);
    return vm_call_iseq_setup_2(ec, cfp, calling, cd, opt_pc, param_size, local_size);
}

static inline VALUE
vm_call_iseq_setup_2(rb_execution_context_t *ec, rb_control_frame_t *cfp, struct rb_calling_info *calling, struct rb_call_data *cd,
       int opt_pc, int param_size, int local_size)
{
    const struct rb_call_info *ci = &cd->ci;
    const struct rb_call_cache *cc = &cd->cc;

    if ((__builtin_expect(!!(!(ci->flag & (0x01 << VM_CALL_TAILCALL_bit))), 1))) {
        return vm_call_iseq_setup_normal(ec, cfp, calling, cc->me, opt_pc, param_size, local_size);
    }
    else {
        return vm_call_iseq_setup_tailcall(ec, cfp, calling, cd, opt_pc);
    }
}

static inline VALUE
vm_call_iseq_setup_normal(rb_execution_context_t *ec, rb_control_frame_t *cfp, struct rb_calling_info *calling, const rb_callable_method_entry_t *me,
                          int opt_pc, int param_size, int local_size)
{
    const rb_iseq_t *iseq = def_iseq_ptr(me->def);
    VALUE *argv = cfp->sp - calling->argc;
    VALUE *sp = argv + param_size;
    cfp->sp = argv - 1 ;

    vm_push_frame(ec, iseq, VM_FRAME_MAGIC_METHOD | VM_ENV_FLAG_LOCAL, calling->recv,
                  calling->block_handler, (VALUE)me,
                  iseq->body->iseq_encoded + opt_pc, sp,
                  local_size - param_size,
                  iseq->body->stack_max);
    return ((VALUE)RUBY_Qundef);
}

static inline VALUE
vm_call_iseq_setup_tailcall(rb_execution_context_t *ec, rb_control_frame_t *cfp, struct rb_calling_info *calling, struct rb_call_data *cd,
       int opt_pc)
{
    const struct rb_call_cache *cc = &cd->cc;
    unsigned int i;
    VALUE *argv = cfp->sp - calling->argc;
    const rb_callable_method_entry_t *me = cc->me;
    const rb_iseq_t *iseq = def_iseq_ptr(me->def);
    VALUE *src_argv = argv;
    VALUE *sp_orig, *sp;
    VALUE finish_flag = VM_FRAME_FINISHED_P(cfp) ? VM_FRAME_FLAG_FINISH : 0;

    if (VM_BH_FROM_CFP_P(calling->block_handler, cfp)) {
 struct rb_captured_block *dst_captured = VM_CFP_TO_CAPTURED_BLOCK(((cfp)+1));
 const struct rb_captured_block *src_captured = VM_BH_TO_CAPT_BLOCK(calling->block_handler);
 dst_captured->code.val = src_captured->code.val;
 if (VM_BH_ISEQ_BLOCK_P(calling->block_handler)) {
     calling->block_handler = VM_BH_FROM_ISEQ_BLOCK(dst_captured);
 }
 else {
     calling->block_handler = VM_BH_FROM_IFUNC_BLOCK(dst_captured);
 }
    }

    vm_pop_frame(ec, cfp, cfp->ep);
    cfp = ec->cfp;

    sp_orig = sp = cfp->sp;


    sp[0] = calling->recv;
    sp++;


    for (i=0; i < iseq->body->param.size; i++) {
 *sp++ = src_argv[i];
    }

    vm_push_frame(ec, iseq, VM_FRAME_MAGIC_METHOD | VM_ENV_FLAG_LOCAL | finish_flag,
    calling->recv, calling->block_handler, (VALUE)me,
    iseq->body->iseq_encoded + opt_pc, sp,
    iseq->body->local_table_size - iseq->body->param.size,
    iseq->body->stack_max);

    cfp->sp = sp_orig;

    return ((VALUE)RUBY_Qundef);
}

static VALUE
call_cfunc_m2(VALUE recv, int argc, const VALUE *argv, VALUE (*func)())
{
    return (*func)(recv, rb_ary_new_from_values(argc, argv));
}

static VALUE
call_cfunc_m1(VALUE recv, int argc, const VALUE *argv, VALUE (*func)())
{
    return (*func)(argc, argv, recv);
}

static VALUE
call_cfunc_0(VALUE recv, int argc, const VALUE *argv, VALUE (*func)())
{
    VALUE(*f)(VALUE) = (VALUE(*)(VALUE))func;
    return (*f)(recv);
}
static VALUE
call_cfunc_1(VALUE recv, int argc, const VALUE *argv, VALUE (*func)())
{
    VALUE(*f)(VALUE, VALUE) = (VALUE(*)(VALUE, VALUE))func;
    return (*f)(recv, argv[0]);
}
static VALUE
call_cfunc_2(VALUE recv, int argc, const VALUE *argv, VALUE (*func)())
{
    VALUE(*f)(VALUE, VALUE, VALUE) = (VALUE(*)(VALUE, VALUE, VALUE))func;
    return (*f)(recv, argv[0], argv[1]);
}
static VALUE
call_cfunc_3(VALUE recv, int argc, const VALUE *argv, VALUE (*func)())
{
    VALUE(*f)(VALUE, VALUE, VALUE, VALUE) = (VALUE(*)(VALUE, VALUE, VALUE, VALUE))func;
    return (*f)(recv, argv[0], argv[1], argv[2]);
}
static VALUE
call_cfunc_4(VALUE recv, int argc, const VALUE *argv, VALUE (*func)())
{
    VALUE(*f)(VALUE, VALUE, VALUE, VALUE, VALUE) = (VALUE(*)(VALUE, VALUE, VALUE, VALUE, VALUE))func;
    return (*f)(recv, argv[0], argv[1], argv[2], argv[3]);
}
static VALUE
call_cfunc_5(VALUE recv, int argc, const VALUE *argv, VALUE (*func)())
{
    VALUE(*f)(VALUE, VALUE, VALUE, VALUE, VALUE, VALUE) = (VALUE(*)(VALUE, VALUE, VALUE, VALUE, VALUE, VALUE))func;
    return (*f)(recv, argv[0], argv[1], argv[2], argv[3], argv[4]);
}
static VALUE
call_cfunc_6(VALUE recv, int argc, const VALUE *argv, VALUE (*func)())
{
    VALUE(*f)(VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE) = (VALUE(*)(VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE))func;
    return (*f)(recv, argv[0], argv[1], argv[2], argv[3], argv[4], argv[5]);
}
static VALUE
call_cfunc_7(VALUE recv, int argc, const VALUE *argv, VALUE (*func)())
{
    VALUE(*f)(VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE) = (VALUE(*)(VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE))func;
    return (*f)(recv, argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6]);
}
static VALUE
call_cfunc_8(VALUE recv, int argc, const VALUE *argv, VALUE (*func)())
{
    VALUE(*f)(VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE) = (VALUE(*)(VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE))func;
    return (*f)(recv, argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6], argv[7]);
}
static VALUE
call_cfunc_9(VALUE recv, int argc, const VALUE *argv, VALUE (*func)())
{
    VALUE(*f)(VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE) = (VALUE(*)(VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE))func;
    return (*f)(recv, argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6], argv[7], argv[8]);
}
static VALUE
call_cfunc_10(VALUE recv, int argc, const VALUE *argv, VALUE (*func)())
{
    VALUE(*f)(VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE) = (VALUE(*)(VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE))func;
    return (*f)(recv, argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6], argv[7], argv[8], argv[9]);
}
static VALUE
call_cfunc_11(VALUE recv, int argc, const VALUE *argv, VALUE (*func)())
{
    VALUE(*f)(VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE) = (VALUE(*)(VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE))func;
    return (*f)(recv, argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6], argv[7], argv[8], argv[9], argv[10]);
}
static VALUE
call_cfunc_12(VALUE recv, int argc, const VALUE *argv, VALUE (*func)())
{
    VALUE(*f)(VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE) = (VALUE(*)(VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE))func;
    return (*f)(recv, argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6], argv[7], argv[8], argv[9], argv[10], argv[11]);
}
static VALUE
call_cfunc_13(VALUE recv, int argc, const VALUE *argv, VALUE (*func)())
{
    VALUE(*f)(VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE) = (VALUE(*)(VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE))func;
    return (*f)(recv, argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6], argv[7], argv[8], argv[9], argv[10], argv[11], argv[12]);
}
static VALUE
call_cfunc_14(VALUE recv, int argc, const VALUE *argv, VALUE (*func)())
{
    VALUE(*f)(VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE) = (VALUE(*)(VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE))func;
    return (*f)(recv, argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6], argv[7], argv[8], argv[9], argv[10], argv[11], argv[12], argv[13]);
}
static VALUE
call_cfunc_15(VALUE recv, int argc, const VALUE *argv, VALUE (*func)())
{
    VALUE(*f)(VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE) = (VALUE(*)(VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE, VALUE))func;
    return (*f)(recv, argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6], argv[7], argv[8], argv[9], argv[10], argv[11], argv[12], argv[13], argv[14]);
}

static inline int
vm_cfp_consistent_p(rb_execution_context_t *ec, const rb_control_frame_t *reg_cfp)
{
    const int ov_flags = RAISED_STACKOVERFLOW;
    if ((__builtin_expect(!!(reg_cfp == ec->cfp + 1), 1))) return 1;
    if ((((ec)->raised_flag & (ov_flags)) != 0)) {
 ((ec)->raised_flag &= ~(ov_flags));
 return 1;
    }
    return 0;
}




static inline
const rb_method_cfunc_t *
vm_method_cfunc_entry(const rb_callable_method_entry_t *me)
{
    return __extension__({
;
; typeof(&(me->def)->body.cfunc) unaligned_member_access_result = (&(me->def)->body.cfunc);
; unaligned_member_access_result; });
}


static VALUE
vm_call_cfunc_with_frame(rb_execution_context_t *ec, rb_control_frame_t *reg_cfp, struct rb_calling_info *calling, struct rb_call_data *cd, int empty_kw_splat)
{
    const struct rb_call_info *ci = &cd->ci;
    const struct rb_call_cache *cc = &cd->cc;
    VALUE val;
    const rb_callable_method_entry_t *me = cc->me;
    const rb_method_cfunc_t *cfunc = vm_method_cfunc_entry(me);
    int len = cfunc->argc;

    VALUE recv = calling->recv;
    VALUE block_handler = calling->block_handler;
    VALUE frame_type = VM_FRAME_MAGIC_CFUNC | VM_FRAME_FLAG_CFRAME | VM_ENV_FLAG_LOCAL;
    int argc = calling->argc;
    int orig_argc = argc;

    if ((__builtin_expect(!!(calling->kw_splat), 0))) {
        frame_type |= VM_FRAME_FLAG_CFRAME_KW;
    }
    else if ((__builtin_expect(!!(empty_kw_splat), 0))) {
        frame_type |= VM_FRAME_FLAG_CFRAME_EMPTY_KW;
    }

    do { if ((__builtin_expect(!!(0), 0))) { struct ruby_dtrace_method_hook_args args; if (rb_dtrace_setup(ec, me->owner, me->def->original_id, &args)) { do {} while (0); } } } while (0);
    do { const rb_event_flag_t flag_arg_ = (0x0020); rb_hook_list_t *hooks_arg_ = (rb_vm_global_hooks(ec)); if ((__builtin_expect(!!((hooks_arg_)->events & (flag_arg_)), 0))) { rb_exec_event_hook_orig(ec, hooks_arg_, flag_arg_, recv, me->def->original_id, ci->mid, me->owner, ((VALUE)RUBY_Qundef), 0); } } while (0);

    vm_push_frame(ec, ((void*)0), frame_type, recv,
    block_handler, (VALUE)me,
    0, ec->cfp->sp, 0, 0);

    if (len >= 0) rb_check_arity(argc, len, len);

    reg_cfp->sp -= orig_argc + 1;
    val = (*cfunc->invoker)(recv, argc, reg_cfp->sp + 1, cfunc->func);

    ((__builtin_expect(!!(vm_cfp_consistent_p(ec, reg_cfp)), 1)) ? (void)0 : rb_bug("vm_call_cfunc" ": cfp consistency error (%p, %p)", (void *)reg_cfp, (void *)(ec->cfp+1)));

    rb_vm_pop_frame(ec);

    do { const rb_event_flag_t flag_arg_ = (0x0040); rb_hook_list_t *hooks_arg_ = (rb_vm_global_hooks(ec)); if ((__builtin_expect(!!((hooks_arg_)->events & (flag_arg_)), 0))) { rb_exec_event_hook_orig(ec, hooks_arg_, flag_arg_, recv, me->def->original_id, ci->mid, me->owner, val, 0); } } while (0);
    do { if ((__builtin_expect(!!(0), 0))) { struct ruby_dtrace_method_hook_args args; if (rb_dtrace_setup(ec, me->owner, me->def->original_id, &args)) { do {} while (0); } } } while (0);

    return val;
}

static VALUE
vm_call_cfunc(rb_execution_context_t *ec, rb_control_frame_t *reg_cfp, struct rb_calling_info *calling, struct rb_call_data *cd)
{
    const struct rb_call_info *ci = &cd->ci;
    int empty_kw_splat;
    ((void)0);

    CALLER_SETUP_ARG(reg_cfp, calling, ci);
    empty_kw_splat = calling->kw_splat;
    CALLER_REMOVE_EMPTY_KW_SPLAT(reg_cfp, calling, ci);
    if (empty_kw_splat && calling->kw_splat) {
        empty_kw_splat = 0;
    }
    return vm_call_cfunc_with_frame(ec, reg_cfp, calling, cd, empty_kw_splat);
}

static VALUE
vm_call_ivar(rb_execution_context_t *ec, rb_control_frame_t *cfp, struct rb_calling_info *calling, struct rb_call_data *cd)
{
    struct rb_call_cache *cc = &cd->cc;
    ((void)0);
    cfp->sp -= 1;
    return vm_getivar(calling->recv, cc->me->def->body.attr.id, ((void*)0), cc, 1);
}

static VALUE
vm_call_attrset(rb_execution_context_t *ec, rb_control_frame_t *cfp, struct rb_calling_info *calling, struct rb_call_data *cd)
{
    struct rb_call_cache *cc = &cd->cc;
    ((void)0);
    VALUE val = *(cfp->sp - 1);
    cfp->sp -= 2;
    return vm_setivar(calling->recv, cc->me->def->body.attr.id, val, ((void*)0), cc, 1);
}

static inline VALUE
vm_call_bmethod_body(rb_execution_context_t *ec, struct rb_calling_info *calling, struct rb_call_data *cd, const VALUE *argv)
{
    rb_proc_t *proc;
    VALUE val;
    const struct rb_call_cache *cc = &cd->cc;


    (((proc)) = (rb_proc_t*)(((struct RData*)(((cc->me->def->body.bmethod.proc))))->data));
    val = rb_vm_invoke_bmethod(ec, proc, calling->recv, calling->argc, argv, calling->kw_splat, calling->block_handler, cc->me);

    return val;
}

static VALUE
vm_call_bmethod(rb_execution_context_t *ec, rb_control_frame_t *cfp, struct rb_calling_info *calling, struct rb_call_data *cd)
{
    ((void)0);

    VALUE *argv;
    int argc;
    const struct rb_call_info *ci = &cd->ci;

    CALLER_SETUP_ARG(cfp, calling, ci);
    argc = calling->argc;
    argv = (VALUE*)__builtin_alloca_with_align((sizeof(VALUE)*(argc)), _Alignof(VALUE) * 8);
    __builtin___memcpy_chk ((argv), (cfp->sp - argc), sizeof(VALUE)*(size_t)(argc), __builtin_object_size ((argv), 0));
    cfp->sp += - argc - 1;

    return vm_call_bmethod_body(ec, calling, cd, argv);
}

static enum method_missing_reason
ci_missing_reason(const struct rb_call_info *ci)
{
    enum method_missing_reason stat = MISSING_NOENTRY;
    if (ci->flag & (0x01 << VM_CALL_VCALL_bit)) stat |= MISSING_VCALL;
    if (ci->flag & (0x01 << VM_CALL_FCALL_bit)) stat |= MISSING_FCALL;
    if (ci->flag & (0x01 << VM_CALL_SUPER_bit)) stat |= MISSING_SUPER;
    return stat;
}

static VALUE
vm_call_opt_send(rb_execution_context_t *ec, rb_control_frame_t *reg_cfp, struct rb_calling_info *calling, struct rb_call_data *orig_cd)
{
    ((void)0);

    int i;
    VALUE sym;
    const struct rb_call_info *orig_ci = &orig_cd->ci;
    const struct rb_call_cache *orig_cc = &orig_cd->cc;
    struct rb_call_info *ci;
    struct rb_call_cache *cc;
    struct rb_kwarg_call_data cd;

    CALLER_SETUP_ARG(reg_cfp, calling, orig_ci);

    i = calling->argc - 1;

    if (calling->argc == 0) {
 rb_raise(rb_eArgError, "no method name given");
    }


    if (orig_ci->flag & (0x01 << VM_CALL_KWARG_bit)) {
        const struct rb_kwarg_call_data *orig_kcd = (void *)orig_cd;
        cd = *orig_kcd;
    }
    else {
        cd.ci_kw.ci = *orig_ci;
        cd.cc = *orig_cc;
    }
    ci = &cd.ci_kw.ci;
    cc = &cd.cc;

    sym = (*(((((reg_cfp)->sp)))-(i)-1));

    if (!(ci->mid = rb_check_id(&sym))) {
 if (__extension__({ static struct rb_call_data rb_mbdp; (rb_class_of((VALUE)(calling->recv)) == ((VALUE)RUBY_Qfalse)) ? 1 : rb_method_basic_definition_p_with_cc(&rb_mbdp, rb_class_of((VALUE)(calling->recv)), idMethodMissing); })) {
     VALUE exc =
  rb_make_no_method_exception(rb_eNoMethodError, 0, calling->recv,
         rb_long2int_inline(calling->argc), &(*(((((reg_cfp)->sp)))-(i)-1)),
         ci->flag & ((0x01 << VM_CALL_FCALL_bit)|(0x01 << VM_CALL_VCALL_bit)));
     rb_exc_raise(exc);
 }
 (*(((((reg_cfp)->sp)))-(i)-1)) = rb_str_intern(sym);
 ci->mid = idMethodMissing;
 ec->method_missing_reason = cc->aux.method_missing_reason = ci_missing_reason(ci);
    }
    else {

 if (i > 0) {
     __builtin___memmove_chk ((&(*(((((reg_cfp)->sp)))-(i)-1))), (&(*(((((reg_cfp)->sp)))-(i-1)-1))), sizeof(VALUE)*(size_t)(i), __builtin_object_size ((&(*(((((reg_cfp)->sp)))-(i)-1))), 0));
 }
 calling->argc -= 1;
 (((reg_cfp)->sp) -= (((1))));
    }

    CC_SET_ME(cc, rb_callable_method_entry_with_refinements(rb_class_of((VALUE)(calling->recv)), ci->mid, ((void*)0)));
    ci->flag = (0x01 << VM_CALL_FCALL_bit) | (0x01 << VM_CALL_OPT_SEND_bit) | (calling->kw_splat ? (0x01 << VM_CALL_KW_SPLAT_bit) : 0);
    return vm_call_method(ec, reg_cfp, calling, (CALL_DATA)&cd);
}

static inline VALUE vm_invoke_block(rb_execution_context_t *ec, rb_control_frame_t *reg_cfp, struct rb_calling_info *calling, const struct rb_call_info *ci, VALUE block_handler);

__attribute__ ((__noinline__)) static VALUE vm_invoke_block_opt_call(rb_execution_context_t *ec, rb_control_frame_t *reg_cfp, struct rb_calling_info *calling, const struct rb_call_info *ci, VALUE block_handler);



static VALUE
vm_invoke_block_opt_call(rb_execution_context_t *ec, rb_control_frame_t *reg_cfp,
    struct rb_calling_info *calling, const struct rb_call_info *ci, VALUE block_handler)
{
    int argc = calling->argc;


    if (argc > 0) __builtin___memmove_chk ((&(*(((((reg_cfp)->sp)))-(argc)-1))), (&(*(((((reg_cfp)->sp)))-(argc-1)-1))), sizeof(VALUE)*(size_t)(argc), __builtin_object_size ((&(*(((((reg_cfp)->sp)))-(argc)-1))), 0));
    (((reg_cfp)->sp) -= (((1))));

    return vm_invoke_block(ec, reg_cfp, calling, ci, block_handler);
}

static VALUE
vm_call_opt_call(rb_execution_context_t *ec, rb_control_frame_t *reg_cfp, struct rb_calling_info *calling, struct rb_call_data *cd)
{
    ((void)0);

    const struct rb_call_info *ci = &cd->ci;
    VALUE procval = calling->recv;
    return vm_invoke_block_opt_call(ec, reg_cfp, calling, ci, VM_BH_FROM_PROC(procval));
}

static VALUE
vm_call_opt_block_call(rb_execution_context_t *ec, rb_control_frame_t *reg_cfp, struct rb_calling_info *calling, struct rb_call_data *cd)
{
    ((void)0);
    VALUE block_handler = VM_ENV_BLOCK_HANDLER(VM_CF_LEP(reg_cfp));
    const struct rb_call_info *ci = &cd->ci;

    if (((__builtin_expect(!!((rb_current_vm()->redefined_flag[(BOP_CALL)]&((1 << 12))) == 0), 1)))) {
 return vm_invoke_block_opt_call(ec, reg_cfp, calling, ci, block_handler);
    }
    else {
 calling->recv = rb_vm_bh_to_procval(ec, block_handler);
        vm_search_method(cd, calling->recv);
        return vm_call_general(ec, reg_cfp, calling, cd);
    }
}

static VALUE
vm_call_method_missing(rb_execution_context_t *ec, rb_control_frame_t *reg_cfp, struct rb_calling_info *calling, struct rb_call_data *orig_cd)
{
    ((void)0);

    const struct rb_call_info *orig_ci = &orig_cd->ci;
    const struct rb_call_cache *orig_cc = &orig_cd->cc;
    VALUE *argv = (((((reg_cfp)->sp)))-(calling->argc));
    struct rb_call_data cd = *orig_cd;
    unsigned int argc;

    CALLER_SETUP_ARG(reg_cfp, calling, orig_ci);
    argc = calling->argc+1;

    cd.ci.flag = (0x01 << VM_CALL_FCALL_bit) | (0x01 << VM_CALL_OPT_SEND_bit) | (calling->kw_splat ? (0x01 << VM_CALL_KW_SPLAT_bit) : 0);
    cd.ci.mid = idMethodMissing;
    cd.ci.orig_argc = argc;

    cd.cc.me =
 rb_callable_method_entry_without_refinements(rb_class_of((VALUE)(calling->recv)),
           idMethodMissing, ((void*)0));

    calling->argc = argc;


    if ((__builtin_expect(!!(!(!(1/!!(sizeof(*((reg_cfp)->sp)) == sizeof(VALUE))) || !(1/!!(sizeof(*(reg_cfp)) == sizeof(rb_control_frame_t))) || ((rb_control_frame_t *)(((reg_cfp)->sp) + (1)) + 1) >= (reg_cfp))), 1))) {(void)0;} else vm_stackoverflow();
                                    ;
    if (argc > 1) {
 __builtin___memmove_chk ((argv+1), (argv), sizeof(VALUE)*(size_t)(argc-1), __builtin_object_size ((argv+1), 0));
    }
    argv[0] = (rb_id2sym(orig_ci->mid));
    (((reg_cfp)->sp) += (((1))));

    ec->method_missing_reason = orig_cc->aux.method_missing_reason;
    return vm_call_method(ec, reg_cfp, calling, &cd);
}

static const rb_callable_method_entry_t *refined_method_callable_without_refinement(const rb_callable_method_entry_t *me);
static VALUE
vm_call_zsuper(rb_execution_context_t *ec, rb_control_frame_t *cfp, struct rb_calling_info *calling, struct rb_call_data *cd, VALUE klass)
{
    ((void)0);

    const struct rb_call_info *ci = &cd->ci;
    struct rb_call_cache *cc = &cd->cc;
    klass = RCLASS_SUPER(klass);
    CC_SET_ME(cc, klass ? rb_callable_method_entry(klass, ci->mid) : ((void*)0));

    if (!cc->me) {
        return vm_call_method_nome(ec, cfp, calling, cd);
    }
    if (cc->me->def->type == VM_METHOD_TYPE_REFINED &&
 cc->me->def->body.refined.orig_me) {
        CC_SET_ME(cc, refined_method_callable_without_refinement(cc->me));
    }
    return vm_call_method_each_type(ec, cfp, calling, cd);
}

static inline VALUE
find_refinement(VALUE refinements, VALUE klass)
{
    if (!((VALUE)(refinements) != ((VALUE)RUBY_Qnil))) {
 return ((VALUE)RUBY_Qnil);
    }
    return rb_hash_lookup(refinements, klass);
}

__attribute__ ((__pure__)) static rb_control_frame_t * current_method_entry(const rb_execution_context_t *ec, rb_control_frame_t *cfp);
static rb_control_frame_t *
current_method_entry(const rb_execution_context_t *ec, rb_control_frame_t *cfp)
{
    rb_control_frame_t *top_cfp = cfp;

    if (cfp->iseq && cfp->iseq->body->type == ISEQ_TYPE_BLOCK) {
 const rb_iseq_t *local_iseq = cfp->iseq->body->local_iseq;

 do {
     cfp = ((cfp)+1);
     if (RUBY_VM_CONTROL_FRAME_STACK_OVERFLOW_P(ec, cfp)) {

  return top_cfp;
     }
 } while (cfp->iseq != local_iseq);
    }
    return cfp;
}

static VALUE
find_defined_class_by_owner(VALUE current_class, VALUE target_owner)
{
    VALUE klass = current_class;


    if (( ((RUBY_T_ICLASS) == RUBY_T_FIXNUM) ? (((int)(long)(klass))&RUBY_FIXNUM_FLAG) : ((RUBY_T_ICLASS) == RUBY_T_TRUE) ? ((klass) == ((VALUE)RUBY_Qtrue)) : ((RUBY_T_ICLASS) == RUBY_T_FALSE) ? ((klass) == ((VALUE)RUBY_Qfalse)) : ((RUBY_T_ICLASS) == RUBY_T_NIL) ? ((klass) == ((VALUE)RUBY_Qnil)) : ((RUBY_T_ICLASS) == RUBY_T_UNDEF) ? ((klass) == ((VALUE)RUBY_Qundef)) : ((RUBY_T_ICLASS) == RUBY_T_SYMBOL) ? ((((VALUE)(klass)&~((~(VALUE)0)<<RUBY_SPECIAL_SHIFT)) == RUBY_SYMBOL_FLAG)||(!(((VALUE)(klass) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(klass) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(klass))->flags & RUBY_T_MASK) == (RUBY_T_SYMBOL))) : ((RUBY_T_ICLASS) == RUBY_T_FLOAT) ? ( ((((int)(long)(klass))&RUBY_FLONUM_MASK) == RUBY_FLONUM_FLAG) || (!(((VALUE)(klass) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(klass) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(klass))->flags & RUBY_T_MASK) == RUBY_T_FLOAT)) : (!(((VALUE)(klass) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(klass) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(klass))->flags & RUBY_T_MASK) == (RUBY_T_ICLASS))) && ((!(((VALUE)(klass) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(klass) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(klass))->flags & RUBY_T_MASK) != RUBY_T_NODE)?(((struct RBasic*)((klass)))->flags&((((VALUE)RUBY_FL_USER5)))):0)) klass = (((struct RBasic*)(klass))->klass);

    while (!(((VALUE)(klass) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) {
 VALUE owner = ( ((RUBY_T_ICLASS) == RUBY_T_FIXNUM) ? (((int)(long)(klass))&RUBY_FIXNUM_FLAG) : ((RUBY_T_ICLASS) == RUBY_T_TRUE) ? ((klass) == ((VALUE)RUBY_Qtrue)) : ((RUBY_T_ICLASS) == RUBY_T_FALSE) ? ((klass) == ((VALUE)RUBY_Qfalse)) : ((RUBY_T_ICLASS) == RUBY_T_NIL) ? ((klass) == ((VALUE)RUBY_Qnil)) : ((RUBY_T_ICLASS) == RUBY_T_UNDEF) ? ((klass) == ((VALUE)RUBY_Qundef)) : ((RUBY_T_ICLASS) == RUBY_T_SYMBOL) ? ((((VALUE)(klass)&~((~(VALUE)0)<<RUBY_SPECIAL_SHIFT)) == RUBY_SYMBOL_FLAG)||(!(((VALUE)(klass) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(klass) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(klass))->flags & RUBY_T_MASK) == (RUBY_T_SYMBOL))) : ((RUBY_T_ICLASS) == RUBY_T_FLOAT) ? ( ((((int)(long)(klass))&RUBY_FLONUM_MASK) == RUBY_FLONUM_FLAG) || (!(((VALUE)(klass) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(klass) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(klass))->flags & RUBY_T_MASK) == RUBY_T_FLOAT)) : (!(((VALUE)(klass) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(klass) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(klass))->flags & RUBY_T_MASK) == (RUBY_T_ICLASS))) ? (((struct RBasic*)(klass))->klass) : klass;
 if (owner == target_owner) {
     return klass;
 }
 klass = RCLASS_SUPER(klass);
    }

    return current_class;
}

static const rb_callable_method_entry_t *
aliased_callable_method_entry(const rb_callable_method_entry_t *me)
{
    const rb_method_entry_t *orig_me = me->def->body.alias.original_me;
    const rb_callable_method_entry_t *cme;

    if (orig_me->defined_class == 0) {
 VALUE defined_class = find_defined_class_by_owner(me->defined_class, orig_me->owner);
 ((void)0);
 cme = rb_method_entry_complement_defined_class(orig_me, me->called_id, defined_class);

 if (me->def->alias_count + me->def->complemented_count == 0) {
     __extension__({
;
; typeof(rb_obj_write((VALUE)(me), (VALUE *)(&me->def->body.alias.original_me), (VALUE)(cme), "./vm_insnhelper.c", 2828)) unaligned_member_access_result = (rb_obj_write((VALUE)(me), (VALUE *)(&me->def->body.alias.original_me), (VALUE)(cme), "./vm_insnhelper.c", 2828));
; unaligned_member_access_result; });
 }
 else {
     rb_method_definition_t *def =
  rb_method_definition_create(VM_METHOD_TYPE_ALIAS, me->def->original_id);
     rb_method_definition_set((rb_method_entry_t *)me, def, (void *)cme);
 }
    }
    else {
 cme = (const rb_callable_method_entry_t *)orig_me;
    }

    ((void)0);
    return cme;
}

static const rb_callable_method_entry_t *
refined_method_callable_without_refinement(const rb_callable_method_entry_t *me)
{
    const rb_method_entry_t *orig_me = me->def->body.refined.orig_me;
    const rb_callable_method_entry_t *cme;

    if (orig_me->defined_class == 0) {
 cme = ((void*)0);
 rb_notimplement();
    }
    else {
 cme = (const rb_callable_method_entry_t *)orig_me;
    }

    ((void)0);

    if ((!(cme) || !(cme)->def || (cme)->def->type == VM_METHOD_TYPE_UNDEF)) {
 cme = ((void*)0);
    }

    return cme;
}

static int
search_refined_method(rb_execution_context_t *ec, rb_control_frame_t *cfp, ID mid, struct rb_call_cache *cc)
{
    const rb_cref_t *cref = vm_get_cref(cfp->ep);

    for (; cref; cref = CREF_NEXT(cref)) {
        const VALUE refinement = find_refinement(CREF_REFINEMENTS(cref), cc->me->owner);
        if (!((VALUE)(refinement) != ((VALUE)RUBY_Qnil))) continue;

        const rb_callable_method_entry_t *const ref_me =
            rb_callable_method_entry(refinement, mid);

        if (ref_me) {
            if (cc->call == vm_call_super_method) {
                const rb_control_frame_t *top_cfp = current_method_entry(ec, cfp);
                const rb_callable_method_entry_t *top_me = rb_vm_frame_method_entry(top_cfp);
                if (top_me && rb_method_definition_eq(ref_me->def, top_me->def)) {
                    continue;
                }
            }
            if (cc->me->def->type != VM_METHOD_TYPE_REFINED ||
                cc->me->def != ref_me->def) {
                CC_SET_ME(cc, ref_me);
            }
            if (ref_me->def->type != VM_METHOD_TYPE_REFINED) {
                return 1;
            }
        }
        else {
            CC_SET_ME(cc, ((void*)0));
            return 0;
        }
    }

    if (cc->me->def->body.refined.orig_me) {
        CC_SET_ME(cc, refined_method_callable_without_refinement(cc->me));
    }
    else {
        VALUE klass = RCLASS_SUPER(cc->me->defined_class);
        CC_SET_ME(cc, klass ? rb_callable_method_entry(klass, mid) : ((void*)0));
    }
    return 1;
}

static VALUE
vm_call_method_each_type(rb_execution_context_t *ec, rb_control_frame_t *cfp, struct rb_calling_info *calling, struct rb_call_data *cd)
{
    const struct rb_call_info *ci = &cd->ci;
    struct rb_call_cache *cc = &cd->cc;

    switch (cc->me->def->type) {
      case VM_METHOD_TYPE_ISEQ:
        CC_SET_FASTPATH(cc, vm_call_iseq_setup, 1);
        return vm_call_iseq_setup(ec, cfp, calling, cd);

      case VM_METHOD_TYPE_NOTIMPLEMENTED:
      case VM_METHOD_TYPE_CFUNC:
        CC_SET_FASTPATH(cc, vm_call_cfunc, 1);
        return vm_call_cfunc(ec, cfp, calling, cd);

      case VM_METHOD_TYPE_ATTRSET:
        CALLER_SETUP_ARG(cfp, calling, ci);
        if (calling->argc == 1 && calling->kw_splat && (((!(((struct RBasic*)((cfp->sp[-1])))->flags&(RHASH_ST_TABLE_FLAG))) ? ((unsigned int)((((struct RBasic*)(cfp->sp[-1]))->flags & (VALUE)RHASH_AR_TABLE_SIZE_MASK) >> RHASH_AR_TABLE_SIZE_SHIFT)) : ((((struct RHash*)(cfp->sp[-1]))->as.st)->num_entries)) == 0)) {
            rb_warn_keyword_to_last_hash(ec, calling, ci, ((void*)0));
        }
        else {
            CALLER_REMOVE_EMPTY_KW_SPLAT(cfp, calling, ci);
        }

 rb_check_arity(calling->argc, 1, 1);
 cc->aux.index = 0;
        CC_SET_FASTPATH(cc, vm_call_attrset, !((ci->flag & (0x01 << VM_CALL_ARGS_SPLAT_bit)) || (ci->flag & (0x01 << VM_CALL_KWARG_bit))));
        return vm_call_attrset(ec, cfp, calling, cd);

      case VM_METHOD_TYPE_IVAR:
        CALLER_SETUP_ARG(cfp, calling, ci);
        CALLER_REMOVE_EMPTY_KW_SPLAT(cfp, calling, ci);
 rb_check_arity(calling->argc, 0, 0);
 cc->aux.index = 0;
        CC_SET_FASTPATH(cc, vm_call_ivar, !(ci->flag & (0x01 << VM_CALL_ARGS_SPLAT_bit)));
        return vm_call_ivar(ec, cfp, calling, cd);

      case VM_METHOD_TYPE_MISSING:
 cc->aux.method_missing_reason = 0;
        CC_SET_FASTPATH(cc, vm_call_method_missing, 1);
        return vm_call_method_missing(ec, cfp, calling, cd);

      case VM_METHOD_TYPE_BMETHOD:
        CC_SET_FASTPATH(cc, vm_call_bmethod, 1);
        return vm_call_bmethod(ec, cfp, calling, cd);

      case VM_METHOD_TYPE_ALIAS:
        CC_SET_ME(cc, aliased_callable_method_entry(cc->me));
 ((void)0);
        return vm_call_method_each_type(ec, cfp, calling, cd);

      case VM_METHOD_TYPE_OPTIMIZED:
 switch (cc->me->def->body.optimize_type) {
   case OPTIMIZED_METHOD_TYPE_SEND:
            CC_SET_FASTPATH(cc, vm_call_opt_send, 1);
            return vm_call_opt_send(ec, cfp, calling, cd);
   case OPTIMIZED_METHOD_TYPE_CALL:
            CC_SET_FASTPATH(cc, vm_call_opt_call, 1);
            return vm_call_opt_call(ec, cfp, calling, cd);
   case OPTIMIZED_METHOD_TYPE_BLOCK_CALL:
            CC_SET_FASTPATH(cc, vm_call_opt_block_call, 1);
            return vm_call_opt_block_call(ec, cfp, calling, cd);
   default:
     rb_bug("vm_call_method: unsupported optimized method type (%d)",
     cc->me->def->body.optimize_type);
 }

      case VM_METHOD_TYPE_UNDEF:
 break;

      case VM_METHOD_TYPE_ZSUPER:
        return vm_call_zsuper(ec, cfp, calling, cd, ((((struct RClass*)(cc->me->defined_class))->ptr)->origin_));

      case VM_METHOD_TYPE_REFINED:
        if (search_refined_method(ec, cfp, ci->mid, cc))
            return vm_call_method(ec, cfp, calling, cd);
        else
            return vm_call_method_nome(ec, cfp, calling, cd);
    }

    rb_bug("vm_call_method: unsupported method type (%d)", cc->me->def->type);
}

__attribute__ ((__noreturn__)) static void vm_raise_method_missing(rb_execution_context_t *ec, int argc, const VALUE *argv, VALUE obj, int call_status);

static VALUE
vm_call_method_nome(rb_execution_context_t *ec, rb_control_frame_t *cfp, struct rb_calling_info *calling, struct rb_call_data *cd)
{

    const struct rb_call_info *ci = &cd->ci;
    struct rb_call_cache *cc = &cd->cc;
    const int stat = ci_missing_reason(ci);

    if (ci->mid == idMethodMissing) {
 rb_control_frame_t *reg_cfp = cfp;
 VALUE *argv = (((((reg_cfp)->sp)))-(calling->argc));
 vm_raise_method_missing(ec, calling->argc, argv, calling->recv, stat);
    }
    else {
 cc->aux.method_missing_reason = stat;
        CC_SET_FASTPATH(cc, vm_call_method_missing, 1);
        return vm_call_method_missing(ec, cfp, calling, cd);
    }
}

static inline VALUE
vm_call_method(rb_execution_context_t *ec, rb_control_frame_t *cfp, struct rb_calling_info *calling, struct rb_call_data *cd)
{
    const struct rb_call_info *ci = &cd->ci;
    struct rb_call_cache *cc = &cd->cc;

    ((void)0);

    if (cc->me != ((void*)0)) {
 switch ((rb_method_visibility_t)(((cc->me)->flags & (((VALUE)RUBY_FL_USER4) | ((VALUE)RUBY_FL_USER5))) >> ((((VALUE)RUBY_FL_USHIFT) + 4)+0))) {
   case METHOD_VISI_PUBLIC:
            return vm_call_method_each_type(ec, cfp, calling, cd);

   case METHOD_VISI_PRIVATE:
     if (!(ci->flag & (0x01 << VM_CALL_FCALL_bit))) {
  enum method_missing_reason stat = MISSING_PRIVATE;
  if (ci->flag & (0x01 << VM_CALL_VCALL_bit)) stat |= MISSING_VCALL;

  cc->aux.method_missing_reason = stat;
                CC_SET_FASTPATH(cc, vm_call_method_missing, 1);
                return vm_call_method_missing(ec, cfp, calling, cd);
     }
            return vm_call_method_each_type(ec, cfp, calling, cd);

   case METHOD_VISI_PROTECTED:
     if (!(ci->flag & (0x01 << VM_CALL_OPT_SEND_bit))) {
  if (!rb_obj_is_kind_of(cfp->self, cc->me->defined_class)) {
      cc->aux.method_missing_reason = MISSING_PROTECTED;
                    return vm_call_method_missing(ec, cfp, calling, cd);
  }
  else {

      ((void)0);
                    if (ci->flag & (0x01 << VM_CALL_KWARG_bit)) {
                        struct rb_kwarg_call_data *kcd = (void *)cd;
                        struct rb_kwarg_call_data cd_entry = *kcd;
                        return vm_call_method_each_type(ec, cfp, calling, (void *)&cd_entry);
                    }
                    else {
                        struct rb_call_data cd_entry = *cd;
                        return vm_call_method_each_type(ec, cfp, calling, &cd_entry);
                    }
  }
     }
            return vm_call_method_each_type(ec, cfp, calling, cd);

   default:
     rb_bug("unreachable");
 }
    }
    else {
        return vm_call_method_nome(ec, cfp, calling, cd);
    }
}

static VALUE
vm_call_general(rb_execution_context_t *ec, rb_control_frame_t *reg_cfp, struct rb_calling_info *calling, struct rb_call_data *cd)
{
    ((void)0);
    return vm_call_method(ec, reg_cfp, calling, cd);
}

static VALUE
vm_call_super_method(rb_execution_context_t *ec, rb_control_frame_t *reg_cfp, struct rb_calling_info *calling, struct rb_call_data *cd)
{
    ((void)0);


    const struct rb_call_cache *cc = &cd->cc;
    if (cc->call != vm_call_super_method) rb_bug("bug");
    return vm_call_method(ec, reg_cfp, calling, cd);
}



static inline VALUE
vm_search_normal_superclass(VALUE klass)
{
    if ((int)(((struct RBasic*)(klass))->flags & RUBY_T_MASK) == RUBY_T_ICLASS &&
 ((!(((VALUE)(((struct RBasic*)(klass))->klass) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(((struct RBasic*)(klass))->klass) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(((struct RBasic*)(klass))->klass))->flags & RUBY_T_MASK) != RUBY_T_NODE)?(((struct RBasic*)((((struct RBasic*)(klass))->klass)))->flags&((RMODULE_IS_REFINEMENT))):0)) {
 klass = ((struct RBasic*)(klass))->klass;
    }
    klass = ((((struct RClass*)(klass))->ptr)->origin_);
    return RCLASS_SUPER(klass);
}

__attribute__ ((__noreturn__)) static void vm_super_outside(void);

static void
vm_super_outside(void)
{
    rb_raise(rb_eNoMethodError, "super called outside of method");
}

static void
vm_search_super_method(const rb_control_frame_t *reg_cfp, struct rb_call_data *cd, VALUE recv)
{
    VALUE current_defined_class, klass;
    const rb_callable_method_entry_t *me = rb_vm_frame_method_entry(reg_cfp);
    struct rb_call_info *ci = &cd->ci;
    struct rb_call_cache *cc = &cd->cc;

    if (!me) {
 vm_super_outside();
    }

    current_defined_class = me->defined_class;

    if (!!((VALUE)(((((struct RClass*)(current_defined_class))->ptr)->refined_class)) != ((VALUE)RUBY_Qnil))) {
 current_defined_class = ((((struct RClass*)(current_defined_class))->ptr)->refined_class);
    }

    if ((int)(((struct RBasic*)(current_defined_class))->flags & RUBY_T_MASK) != RUBY_T_MODULE &&
 !((!(((VALUE)(current_defined_class) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(current_defined_class) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(current_defined_class))->flags & RUBY_T_MASK) != RUBY_T_NODE)?(((struct RBasic*)((current_defined_class)))->flags&((RMODULE_INCLUDED_INTO_REFINEMENT))):0) &&
        !rb_obj_is_kind_of(recv, current_defined_class)) {
 VALUE m = ( ((RUBY_T_ICLASS) == RUBY_T_FIXNUM) ? (((int)(long)(current_defined_class))&RUBY_FIXNUM_FLAG) : ((RUBY_T_ICLASS) == RUBY_T_TRUE) ? ((current_defined_class) == ((VALUE)RUBY_Qtrue)) : ((RUBY_T_ICLASS) == RUBY_T_FALSE) ? ((current_defined_class) == ((VALUE)RUBY_Qfalse)) : ((RUBY_T_ICLASS) == RUBY_T_NIL) ? ((current_defined_class) == ((VALUE)RUBY_Qnil)) : ((RUBY_T_ICLASS) == RUBY_T_UNDEF) ? ((current_defined_class) == ((VALUE)RUBY_Qundef)) : ((RUBY_T_ICLASS) == RUBY_T_SYMBOL) ? ((((VALUE)(current_defined_class)&~((~(VALUE)0)<<RUBY_SPECIAL_SHIFT)) == RUBY_SYMBOL_FLAG)||(!(((VALUE)(current_defined_class) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(current_defined_class) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(current_defined_class))->flags & RUBY_T_MASK) == (RUBY_T_SYMBOL))) : ((RUBY_T_ICLASS) == RUBY_T_FLOAT) ? ( ((((int)(long)(current_defined_class))&RUBY_FLONUM_MASK) == RUBY_FLONUM_FLAG) || (!(((VALUE)(current_defined_class) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(current_defined_class) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(current_defined_class))->flags & RUBY_T_MASK) == RUBY_T_FLOAT)) : (!(((VALUE)(current_defined_class) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(current_defined_class) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(current_defined_class))->flags & RUBY_T_MASK) == (RUBY_T_ICLASS))) ?
            ((((struct RClass*)(current_defined_class))->ptr)->includer) : current_defined_class;

        if (m) {
            rb_raise(rb_eTypeError,
                     "self has wrong type to call super in this context: "
                     "%""l""i" "\v"" (expected %""l""i" "\v"")",
                     rb_obj_class(recv), m);
        }
    }

    if (me->def->type == VM_METHOD_TYPE_BMETHOD && (ci->flag & (0x01 << VM_CALL_ZSUPER_bit))) {
 rb_raise(rb_eRuntimeError,
   "implicit argument passing of super from method defined"
   " by define_method() is not supported."
   " Specify all arguments explicitly.");
    }

    ci->mid = me->def->original_id;
    klass = vm_search_normal_superclass(me->defined_class);

    if (!klass) {

 cc->aux.method_missing_reason = MISSING_SUPER;
        CC_SET_FASTPATH(cc, vm_call_method_missing, 1);
    }
    else {

        CC_SET_ME(cc, rb_callable_method_entry(klass, ci->mid));
        CC_SET_FASTPATH(cc, vm_call_super_method, 1);
    }
}



static inline int
block_proc_is_lambda(const VALUE procval)
{
    rb_proc_t *proc;

    if (procval) {
 (((proc)) = (rb_proc_t*)(((struct RData*)(((procval))))->data));
 return proc->is_lambda;
    }
    else {
 return 0;
    }
}

static VALUE
vm_yield_with_cfunc(rb_execution_context_t *ec,
      const struct rb_captured_block *captured,
                    VALUE self, int argc, const VALUE *argv, int kw_splat, VALUE block_handler,
                    const rb_callable_method_entry_t *me)
{
    int is_lambda = 0;
    VALUE val, arg, blockarg;
    int frame_flag;
    const struct vm_ifunc *ifunc = captured->code.ifunc;

    if (is_lambda) {
 arg = rb_ary_new_from_values(argc, argv);
    }
    else if (argc == 0) {
 arg = ((VALUE)RUBY_Qnil);
    }
    else {
 arg = argv[0];
    }

    blockarg = rb_vm_bh_to_procval(ec, block_handler);

    frame_flag = VM_FRAME_MAGIC_IFUNC | VM_FRAME_FLAG_CFRAME | (me ? VM_FRAME_FLAG_BMETHOD : 0);
    switch (kw_splat) {
      case 1:
        frame_flag |= VM_FRAME_FLAG_CFRAME_KW;
        break;
      case 2:
        frame_flag |= VM_FRAME_FLAG_CFRAME_EMPTY_KW;
        break;
    }

    vm_push_frame(ec, (const rb_iseq_t *)captured->code.ifunc,
                  frame_flag,
    self,
    ((VALUE)((captured->ep)) | (0x01)),
                  (VALUE)me,
    0, ec->cfp->sp, 0, 0);
    val = (*ifunc->func)(arg, (VALUE)ifunc->data, argc, argv, blockarg);
    rb_vm_pop_frame(ec);

    return val;
}

static VALUE
vm_yield_with_symbol(rb_execution_context_t *ec, VALUE symbol, int argc, const VALUE *argv, int kw_splat, VALUE block_handler)
{
    return rb_sym_proc_call((rb_sym2id(symbol)), argc, argv, kw_splat, rb_vm_bh_to_procval(ec, block_handler));
}

static inline int
vm_callee_setup_block_arg_arg0_splat(rb_control_frame_t *cfp, const rb_iseq_t *iseq, VALUE *argv, VALUE ary)
{
    int i;
    long len = rb_array_len(ary);

    if ((__builtin_expect(!!(!(!(1/!!(sizeof(*((cfp)->sp)) == sizeof(VALUE))) || !(1/!!(sizeof(*(cfp)) == sizeof(rb_control_frame_t))) || ((rb_control_frame_t *)(((cfp)->sp) + (iseq->body->param.lead_num)) + 1) >= (cfp))), 1))) {(void)0;} else vm_stackoverflow();

    for (i=0; i<len && i<iseq->body->param.lead_num; i++) {
 argv[i] = (rb_array_const_ptr_transient(ary)[i]);
    }

    return i;
}

static inline VALUE
vm_callee_setup_block_arg_arg0_check(VALUE *argv)
{
    VALUE ary, arg0 = argv[0];
    ary = rb_check_array_type(arg0);



    ((void)0);

    return ary;
}

static int
vm_callee_setup_block_arg(rb_execution_context_t *ec, struct rb_calling_info *calling, const struct rb_call_info *ci, const rb_iseq_t *iseq, VALUE *argv, const enum arg_setup_type arg_setup_type)
{
    if (rb_simple_iseq_p(iseq)) {
 rb_control_frame_t *cfp = ec->cfp;
 VALUE arg0;

        CALLER_SETUP_ARG(cfp, calling, ci);
        if (calling->kw_splat && calling->argc == iseq->body->param.lead_num + iseq->body->param.post_num && (((!(((struct RBasic*)((cfp->sp[-1])))->flags&(RHASH_ST_TABLE_FLAG))) ? ((unsigned int)((((struct RBasic*)(cfp->sp[-1]))->flags & (VALUE)RHASH_AR_TABLE_SIZE_MASK) >> RHASH_AR_TABLE_SIZE_SHIFT)) : ((((struct RHash*)(cfp->sp[-1]))->as.st)->num_entries)) == 0)) {
            rb_warn_keyword_to_last_hash(ec, calling, ci, iseq);
        }
        else {
            CALLER_REMOVE_EMPTY_KW_SPLAT(cfp, calling, ci);
        }

 if (arg_setup_type == arg_setup_block &&
     calling->argc == 1 &&
     iseq->body->param.flags.has_lead &&
     !iseq->body->param.flags.ambiguous_param0 &&
     !!((VALUE)(arg0 = vm_callee_setup_block_arg_arg0_check(argv)) != ((VALUE)RUBY_Qnil))) {
     calling->argc = vm_callee_setup_block_arg_arg0_splat(cfp, iseq, argv, arg0);
 }

 if (calling->argc != iseq->body->param.lead_num) {
     if (arg_setup_type == arg_setup_block) {
  if (calling->argc < iseq->body->param.lead_num) {
      int i;
      if ((__builtin_expect(!!(!(!(1/!!(sizeof(*((cfp)->sp)) == sizeof(VALUE))) || !(1/!!(sizeof(*(cfp)) == sizeof(rb_control_frame_t))) || ((rb_control_frame_t *)(((cfp)->sp) + (iseq->body->param.lead_num)) + 1) >= (cfp))), 1))) {(void)0;} else vm_stackoverflow();
      for (i=calling->argc; i<iseq->body->param.lead_num; i++) argv[i] = ((VALUE)RUBY_Qnil);
      calling->argc = iseq->body->param.lead_num;
  }
  else if (calling->argc > iseq->body->param.lead_num) {
      calling->argc = iseq->body->param.lead_num;
  }
     }
     else {
  argument_arity_error(ec, iseq, calling->argc, iseq->body->param.lead_num, iseq->body->param.lead_num);
     }
 }

 return 0;
    }
    else {
 return setup_parameters_complex(ec, iseq, calling, ci, argv, arg_setup_type);
    }
}

static int
vm_yield_setup_args(rb_execution_context_t *ec, const rb_iseq_t *iseq, const int argc, VALUE *argv, int kw_splat, VALUE block_handler, enum arg_setup_type arg_setup_type)
{
    struct rb_calling_info calling_entry, *calling;
    struct rb_call_info ci_entry, *ci;

    calling = &calling_entry;
    calling->argc = argc;
    calling->block_handler = block_handler;
    calling->kw_splat = kw_splat;
    calling->recv = ((VALUE)RUBY_Qundef);

    ci_entry.flag = kw_splat ? (0x01 << VM_CALL_KW_SPLAT_bit) : 0;
    ci = &ci_entry;

    return vm_callee_setup_block_arg(ec, calling, ci, iseq, argv, arg_setup_type);
}



static VALUE
vm_invoke_iseq_block(rb_execution_context_t *ec, rb_control_frame_t *reg_cfp,
       struct rb_calling_info *calling, const struct rb_call_info *ci,
       int is_lambda, const struct rb_captured_block *captured)
{
    const rb_iseq_t *iseq = rb_iseq_check(captured->code.iseq);
    const int arg_size = iseq->body->param.size;
    VALUE * const rsp = ((((reg_cfp)->sp))) - calling->argc;
    int opt_pc = vm_callee_setup_block_arg(ec, calling, ci, iseq, rsp, is_lambda ? arg_setup_method : arg_setup_block);

    (((reg_cfp)->sp) = (((rsp))));

    vm_push_frame(ec, iseq,
    VM_FRAME_MAGIC_BLOCK | (is_lambda ? VM_FRAME_FLAG_LAMBDA : 0),
    captured->self,
    ((VALUE)((captured->ep)) | (0x01)), 0,
    iseq->body->iseq_encoded + opt_pc,
    rsp + arg_size,
    iseq->body->local_table_size - arg_size, iseq->body->stack_max);

    return ((VALUE)RUBY_Qundef);
}

static VALUE
vm_invoke_symbol_block(rb_execution_context_t *ec, rb_control_frame_t *reg_cfp,
         struct rb_calling_info *calling, const struct rb_call_info *ci,
         VALUE symbol)
{
    VALUE val;
    int argc;
    CALLER_SETUP_ARG(ec->cfp, calling, ci);
    argc = calling->argc;
    val = vm_yield_with_symbol(ec, symbol, argc, (((((reg_cfp)->sp)))-(argc)), calling->kw_splat, calling->block_handler);
    ((((reg_cfp)->sp) -= (((argc)))));
    return val;
}

static VALUE
vm_invoke_ifunc_block(rb_execution_context_t *ec, rb_control_frame_t *reg_cfp,
        struct rb_calling_info *calling, const struct rb_call_info *ci,
        const struct rb_captured_block *captured)
{
    VALUE val;
    int argc;
    int kw_splat = calling->kw_splat;
    CALLER_SETUP_ARG(ec->cfp, calling, ci);
    CALLER_REMOVE_EMPTY_KW_SPLAT(ec->cfp, calling, ci);
    if (kw_splat && !calling->kw_splat) {
        kw_splat = 2;
    }
    else {
        kw_splat = calling->kw_splat;
    }
    argc = calling->argc;
    val = vm_yield_with_cfunc(ec, captured, captured->self, argc, (((((reg_cfp)->sp)))-(argc)), kw_splat, calling->block_handler, ((void*)0));
    ((((reg_cfp)->sp) -= (((argc)))));
    return val;
}

static VALUE
vm_proc_to_block_handler(VALUE procval)
{
    const struct rb_block *block = vm_proc_block(procval);

    switch (vm_block_type(block)) {
      case block_type_iseq:
 return VM_BH_FROM_ISEQ_BLOCK(&block->as.captured);
      case block_type_ifunc:
 return VM_BH_FROM_IFUNC_BLOCK(&block->as.captured);
      case block_type_symbol:
 return VM_BH_FROM_SYMBOL(block->as.symbol);
      case block_type_proc:
 return VM_BH_FROM_PROC(block->as.proc);
    }
    __builtin_unreachable();
    return ((VALUE)RUBY_Qundef);
}

static inline VALUE
vm_invoke_block(rb_execution_context_t *ec, rb_control_frame_t *reg_cfp,
  struct rb_calling_info *calling, const struct rb_call_info *ci, VALUE block_handler)
{
    int is_lambda = 0;

  again:
    switch (vm_block_handler_type(block_handler)) {
      case block_handler_type_iseq:
 {
     const struct rb_captured_block *captured = VM_BH_TO_ISEQ_BLOCK(block_handler);
     return vm_invoke_iseq_block(ec, reg_cfp, calling, ci, is_lambda, captured);
 }
      case block_handler_type_ifunc:
 {
     const struct rb_captured_block *captured = VM_BH_TO_IFUNC_BLOCK(block_handler);
     return vm_invoke_ifunc_block(ec, reg_cfp, calling, ci, captured);
 }
      case block_handler_type_proc:
 is_lambda = block_proc_is_lambda(VM_BH_TO_PROC(block_handler));
 block_handler = vm_proc_to_block_handler(VM_BH_TO_PROC(block_handler));
 goto again;
      case block_handler_type_symbol:
 return vm_invoke_symbol_block(ec, reg_cfp, calling, ci, VM_BH_TO_SYMBOL(block_handler));
    }
    __builtin_unreachable();
    return ((VALUE)RUBY_Qnil);
}

static VALUE
vm_make_proc_with_iseq(const rb_iseq_t *blockiseq)
{
    const rb_execution_context_t *ec = rb_current_execution_context();
    const rb_control_frame_t *cfp = rb_vm_get_ruby_level_next_cfp(ec, ec->cfp);
    struct rb_captured_block *captured;

    if (cfp == 0) {
 rb_bug("vm_make_proc_with_iseq: unreachable");
    }

    captured = VM_CFP_TO_CAPTURED_BLOCK(cfp);
    captured->code.iseq = blockiseq;

    return rb_vm_make_proc(ec, captured, rb_cProc);
}

static VALUE
vm_once_exec(VALUE iseq)
{
    VALUE proc = vm_make_proc_with_iseq((rb_iseq_t *)iseq);
    return rb_proc_call_with_block(proc, 0, 0, ((VALUE)RUBY_Qnil));
}

static VALUE
vm_once_clear(VALUE data)
{
    union iseq_inline_storage_entry *is = (union iseq_inline_storage_entry *)data;
    is->once.running_thread = ((void*)0);
    return ((VALUE)RUBY_Qnil);
}static inline 

rb_control_frame_t *
rb_vm_opt_struct_aref(rb_execution_context_t *ec, rb_control_frame_t *reg_cfp)
{
    (*(((((reg_cfp)->sp)))-(0)-1)) = rb_struct_aref((((((reg_cfp)))->self)), (*(((((reg_cfp)->sp)))-(0)-1)));
    return reg_cfp;
}static inline 

rb_control_frame_t *
rb_vm_opt_struct_aset(rb_execution_context_t *ec, rb_control_frame_t *reg_cfp)
{
    rb_struct_aset((((((reg_cfp)))->self)), (*(((((reg_cfp)->sp)))-(0)-1)), (*(((((reg_cfp)->sp)))-(1)-1)));
    return reg_cfp;
}



static enum defined_type
check_respond_to_missing(VALUE obj, VALUE v)
{
    VALUE args[2];
    VALUE r;

    args[0] = obj; args[1] = ((VALUE)RUBY_Qfalse);
    r = rb_check_funcall(v, idRespond_to_missing, 2, args);
    if (r != ((VALUE)RUBY_Qundef) && !(((VALUE)(r) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) {
 return DEFINED_METHOD;
    }
    else {
 return DEFINED_NOT_DEFINED;
    }
}

static VALUE
vm_defined(rb_execution_context_t *ec, rb_control_frame_t *reg_cfp, rb_num_t op_type, VALUE obj, VALUE needstr, VALUE v)
{
    VALUE klass;
    enum defined_type expr_type = DEFINED_NOT_DEFINED;
    enum defined_type type = (enum defined_type)op_type;

    switch (type) {
      case DEFINED_IVAR:
 if (rb_ivar_defined((((((reg_cfp)))->self)), (rb_sym2id(obj)))) {
     expr_type = DEFINED_IVAR;
 }
 break;
      case DEFINED_IVAR2:
 klass = vm_get_cbase(((((reg_cfp)->ep))));
 break;
      case DEFINED_GVAR:
 if (rb_gvar_defined(rb_global_entry((rb_sym2id(obj))))) {
     expr_type = DEFINED_GVAR;
 }
 break;
      case DEFINED_CVAR: {
        const rb_cref_t *cref = vm_get_cref(((((reg_cfp)->ep))));
 klass = vm_get_cvar_base(cref, (((reg_cfp))));
 if (rb_cvar_defined(klass, (rb_sym2id(obj)))) {
     expr_type = DEFINED_CVAR;
 }
 break;
      }
      case DEFINED_CONST:
      case DEFINED_CONST_FROM: {
 _Bool allow_nil = type == DEFINED_CONST;
 klass = v;
        if (vm_get_ev_const(ec, klass, (rb_sym2id(obj)), allow_nil, 1)) {
     expr_type = DEFINED_CONST;
 }
 break;
      }
      case DEFINED_FUNC:
 klass = rb_class_of((VALUE)(v));
 if (rb_method_boundp(klass, (rb_sym2id(obj)), 0)) {
     expr_type = DEFINED_METHOD;
 }
 else {
     expr_type = check_respond_to_missing(obj, v);
 }
 break;
      case DEFINED_METHOD:{
 VALUE klass = rb_class_of((VALUE)(v));
 const rb_method_entry_t *me = rb_method_entry(klass, (rb_sym2id(obj)));

 if (me) {
     switch ((rb_method_visibility_t)(((me)->flags & (((VALUE)RUBY_FL_USER4) | ((VALUE)RUBY_FL_USER5))) >> ((((VALUE)RUBY_FL_USHIFT) + 4)+0))) {
       case METHOD_VISI_PRIVATE:
  break;
       case METHOD_VISI_PROTECTED:
  if (!rb_obj_is_kind_of((((((reg_cfp)))->self)), rb_class_real(me->defined_class))) {
      break;
  }
       case METHOD_VISI_PUBLIC:
  expr_type = DEFINED_METHOD;
  break;
       default:
  rb_bug("vm_defined: unreachable: %u", (unsigned int)(rb_method_visibility_t)(((me)->flags & (((VALUE)RUBY_FL_USER4) | ((VALUE)RUBY_FL_USER5))) >> ((((VALUE)RUBY_FL_USHIFT) + 4)+0)));
     }
 }
 else {
     expr_type = check_respond_to_missing(obj, v);
 }
 break;
      }
      case DEFINED_YIELD:
 if (((VM_EP_LEP(((((reg_cfp)->ep)))))[(-1)]) != 0) {
     expr_type = DEFINED_YIELD;
 }
 break;
      case DEFINED_ZSUPER:
 {
     const rb_callable_method_entry_t *me = rb_vm_frame_method_entry((((reg_cfp))));

     if (me) {
  VALUE klass = vm_search_normal_superclass(me->defined_class);
  ID id = me->def->original_id;

  if (rb_method_boundp(klass, id, 0)) {
      expr_type = DEFINED_ZSUPER;
  }
     }
 }
 break;
      case DEFINED_REF:{
 if (vm_getspecial(ec, (VM_EP_LEP(((((reg_cfp)->ep))))), ((VALUE)RUBY_Qfalse), ((int)rb_fix2int((VALUE)(obj)))) != ((VALUE)RUBY_Qnil)) {
     expr_type = DEFINED_GVAR;
 }
 break;
      }
      default:
 rb_bug("unimplemented defined? type (VM)");
 break;
    }

    if (expr_type != 0) {
 if (needstr != ((VALUE)RUBY_Qfalse)) {
     return rb_iseq_defined_string(expr_type);
 }
 else {
     return ((VALUE)RUBY_Qtrue);
 }
    }
    else {
 return ((VALUE)RUBY_Qnil);
    }
}

static const VALUE *
vm_get_ep(const VALUE *const reg_ep, rb_num_t lv)
{
    rb_num_t i;
    const VALUE *ep = reg_ep;
    for (i = 0; i < lv; i++) {
 ep = ((VALUE *)((ep)[(-1)] & ~0x03));
    }
    return ep;
}

static VALUE
vm_get_special_object(const VALUE *const reg_ep,
        enum vm_special_object_type type)
{
    switch (type) {
      case VM_SPECIAL_OBJECT_VMCORE:
 return rb_mRubyVMFrozenCore;
      case VM_SPECIAL_OBJECT_CBASE:
 return vm_get_cbase(reg_ep);
      case VM_SPECIAL_OBJECT_CONST_BASE:
 return vm_get_const_base(reg_ep);
      default:
 rb_bug("putspecialobject insn: unknown value_type %d", type);
    }
}

static void
vm_freezestring(VALUE str, VALUE debug)
{
    if (!!((VALUE)(debug) != ((VALUE)RUBY_Qnil))) {
 rb_ivar_set(str, id_debug_created_info, debug);
    }
    rb_str_freeze(str);
}

static VALUE
vm_concat_array(VALUE ary1, VALUE ary2st)
{
    const VALUE ary2 = ary2st;
    VALUE tmp1 = rb_check_to_array(ary1);
    VALUE tmp2 = rb_check_to_array(ary2);

    if (!((VALUE)(tmp1) != ((VALUE)RUBY_Qnil))) {
 tmp1 = __extension__ ({ const VALUE args_to_new_ary[] = {ary1}; if (__builtin_constant_p(1)) { __extension__ _Static_assert(((int)(sizeof(args_to_new_ary) / sizeof((args_to_new_ary)[0]))) == (1), "rb_ary_new_from_args" ": " "numberof(args_to_new_ary) == (1)"); } rb_ary_new_from_values(((int)(sizeof(args_to_new_ary) / sizeof((args_to_new_ary)[0]))), args_to_new_ary); });
    }

    if (!((VALUE)(tmp2) != ((VALUE)RUBY_Qnil))) {
 tmp2 = __extension__ ({ const VALUE args_to_new_ary[] = {ary2}; if (__builtin_constant_p(1)) { __extension__ _Static_assert(((int)(sizeof(args_to_new_ary) / sizeof((args_to_new_ary)[0]))) == (1), "rb_ary_new_from_args" ": " "numberof(args_to_new_ary) == (1)"); } rb_ary_new_from_values(((int)(sizeof(args_to_new_ary) / sizeof((args_to_new_ary)[0]))), args_to_new_ary); });
    }

    if (tmp1 == ary1) {
 tmp1 = rb_ary_dup(ary1);
    }
    return rb_ary_concat(tmp1, tmp2);
}

static VALUE
vm_splat_array(VALUE flag, VALUE ary)
{
    VALUE tmp = rb_check_to_array(ary);
    if (!((VALUE)(tmp) != ((VALUE)RUBY_Qnil))) {
 return __extension__ ({ const VALUE args_to_new_ary[] = {ary}; if (__builtin_constant_p(1)) { __extension__ _Static_assert(((int)(sizeof(args_to_new_ary) / sizeof((args_to_new_ary)[0]))) == (1), "rb_ary_new_from_args" ": " "numberof(args_to_new_ary) == (1)"); } rb_ary_new_from_values(((int)(sizeof(args_to_new_ary) / sizeof((args_to_new_ary)[0]))), args_to_new_ary); });
    }
    else if (!(((VALUE)(flag) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) {
 return rb_ary_dup(tmp);
    }
    else {
 return tmp;
    }
}

static VALUE
vm_check_match(rb_execution_context_t *ec, VALUE target, VALUE pattern, rb_num_t flag)
{
    enum vm_check_match_type type = ((int)flag) & 0x03;

    if (flag & 0x04) {
 long i;
 const long n = rb_array_len(pattern);

 for (i = 0; i < n; i++) {
     VALUE v = (rb_array_const_ptr_transient(pattern)[i]);
     VALUE c = check_match(ec, v, target, type);

     if (!(((VALUE)(c) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) {
  return c;
     }
 }
 return ((VALUE)RUBY_Qfalse);
    }
    else {
 return check_match(ec, pattern, target, type);
    }
}

static VALUE
vm_check_keyword(lindex_t bits, lindex_t idx, const VALUE *ep)
{
    const VALUE kw_bits = *(ep - bits);

    if ((((int)(long)(kw_bits))&RUBY_FIXNUM_FLAG)) {
 unsigned int b = (unsigned int)((unsigned long)((long)(((long)(kw_bits))>>(int)(1))));
 if ((idx < (32-1)) && (b & (0x01 << idx)))
     return ((VALUE)RUBY_Qfalse);
    }
    else {
 ((void)0);
 if (rb_hash_has_key(kw_bits, (((VALUE)(idx))<<1 | RUBY_FIXNUM_FLAG))) return ((VALUE)RUBY_Qfalse);
    }
    return ((VALUE)RUBY_Qtrue);
}

static void
vm_dtrace(rb_event_flag_t flag, rb_execution_context_t *ec)
{
    if (0 ||
 0 ||
 0 ||
 0) {

 switch (flag) {
   case 0x0008:
     do { if ((__builtin_expect(!!(0), 0))) { struct ruby_dtrace_method_hook_args args; if (rb_dtrace_setup(ec, 0, 0, &args)) { do {} while (0); } } } while (0);
     return;
   case 0x0020:
     do { if ((__builtin_expect(!!(0), 0))) { struct ruby_dtrace_method_hook_args args; if (rb_dtrace_setup(ec, 0, 0, &args)) { do {} while (0); } } } while (0);
     return;
   case 0x0010:
     do { if ((__builtin_expect(!!(0), 0))) { struct ruby_dtrace_method_hook_args args; if (rb_dtrace_setup(ec, 0, 0, &args)) { do {} while (0); } } } while (0);
     return;
   case 0x0040:
     do { if ((__builtin_expect(!!(0), 0))) { struct ruby_dtrace_method_hook_args args; if (rb_dtrace_setup(ec, 0, 0, &args)) { do {} while (0); } } } while (0);
     return;
 }
    }
}

static VALUE
vm_const_get_under(ID id, rb_num_t flags, VALUE cbase)
{
    VALUE ns;

    if ((ns = vm_search_const_defined_class(cbase, id)) == 0) {
 return ns;
    }
    else if (((flags) & 0x08)) {
 return rb_public_const_get_at(ns, id);
    }
    else {
 return rb_const_get_at(ns, id);
    }
}

static VALUE
vm_check_if_class(ID id, rb_num_t flags, VALUE super, VALUE klass)
{
    if (!( ((RUBY_T_CLASS) == RUBY_T_FIXNUM) ? (((int)(long)(klass))&RUBY_FIXNUM_FLAG) : ((RUBY_T_CLASS) == RUBY_T_TRUE) ? ((klass) == ((VALUE)RUBY_Qtrue)) : ((RUBY_T_CLASS) == RUBY_T_FALSE) ? ((klass) == ((VALUE)RUBY_Qfalse)) : ((RUBY_T_CLASS) == RUBY_T_NIL) ? ((klass) == ((VALUE)RUBY_Qnil)) : ((RUBY_T_CLASS) == RUBY_T_UNDEF) ? ((klass) == ((VALUE)RUBY_Qundef)) : ((RUBY_T_CLASS) == RUBY_T_SYMBOL) ? ((((VALUE)(klass)&~((~(VALUE)0)<<RUBY_SPECIAL_SHIFT)) == RUBY_SYMBOL_FLAG)||(!(((VALUE)(klass) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(klass) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(klass))->flags & RUBY_T_MASK) == (RUBY_T_SYMBOL))) : ((RUBY_T_CLASS) == RUBY_T_FLOAT) ? ( ((((int)(long)(klass))&RUBY_FLONUM_MASK) == RUBY_FLONUM_FLAG) || (!(((VALUE)(klass) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(klass) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(klass))->flags & RUBY_T_MASK) == RUBY_T_FLOAT)) : (!(((VALUE)(klass) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(klass) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(klass))->flags & RUBY_T_MASK) == (RUBY_T_CLASS)))) {
        return 0;
    }
    else if (((flags) & 0x10)) {
 VALUE tmp = rb_class_real(RCLASS_SUPER(klass));

 if (tmp != super) {
     rb_raise(rb_eTypeError,
       "superclass mismatch for class %""l""i" "\v""",
       rb_id2str(id));
 }
 else {
     return klass;
 }
    }
    else {
 return klass;
    }
}

static VALUE
vm_check_if_module(ID id, VALUE mod)
{
    if (!( ((RUBY_T_MODULE) == RUBY_T_FIXNUM) ? (((int)(long)(mod))&RUBY_FIXNUM_FLAG) : ((RUBY_T_MODULE) == RUBY_T_TRUE) ? ((mod) == ((VALUE)RUBY_Qtrue)) : ((RUBY_T_MODULE) == RUBY_T_FALSE) ? ((mod) == ((VALUE)RUBY_Qfalse)) : ((RUBY_T_MODULE) == RUBY_T_NIL) ? ((mod) == ((VALUE)RUBY_Qnil)) : ((RUBY_T_MODULE) == RUBY_T_UNDEF) ? ((mod) == ((VALUE)RUBY_Qundef)) : ((RUBY_T_MODULE) == RUBY_T_SYMBOL) ? ((((VALUE)(mod)&~((~(VALUE)0)<<RUBY_SPECIAL_SHIFT)) == RUBY_SYMBOL_FLAG)||(!(((VALUE)(mod) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(mod) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(mod))->flags & RUBY_T_MASK) == (RUBY_T_SYMBOL))) : ((RUBY_T_MODULE) == RUBY_T_FLOAT) ? ( ((((int)(long)(mod))&RUBY_FLONUM_MASK) == RUBY_FLONUM_FLAG) || (!(((VALUE)(mod) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(mod) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(mod))->flags & RUBY_T_MASK) == RUBY_T_FLOAT)) : (!(((VALUE)(mod) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(mod) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(mod))->flags & RUBY_T_MASK) == (RUBY_T_MODULE)))) {
        return 0;
    }
    else {
 return mod;
    }
}

static VALUE
declare_under(ID id, VALUE cbase, VALUE c)
{
    rb_set_class_path_string(c, cbase, rb_id2str(id));
    rb_const_set(cbase, id, c);
    return c;
}

static VALUE
vm_declare_class(ID id, rb_num_t flags, VALUE cbase, VALUE super)
{

    VALUE s = ((flags) & 0x10) ? super : rb_cObject;
    VALUE c = declare_under(id, cbase, rb_define_class_id(id, s));
    rb_class_inherited(s, c);
    return c;
}

static VALUE
vm_declare_module(ID id, VALUE cbase)
{

    return declare_under(id, cbase, rb_define_module_id(id));
}

__attribute__ ((__noreturn__)) static void unmatched_redefinition(const char *type, VALUE cbase, ID id, VALUE old);
static void
unmatched_redefinition(const char *type, VALUE cbase, ID id, VALUE old)
{
    VALUE name = rb_id2str(id);
    VALUE message = rb_sprintf("%""l""i" "\v"" is not a %s",
                               name, type);
    VALUE location = rb_const_source_location_at(cbase, id);
    if (!!((VALUE)(location) != ((VALUE)RUBY_Qnil))) {
        rb_str_catf(message, "\n%""l""i" "\v"":%""l""i" "\v"":"
                    " previous definition of %""l""i" "\v"" was here",
                    rb_ary_entry(location, 0), rb_ary_entry(location, 1), name);
    }
    rb_exc_raise(rb_exc_new_str(rb_eTypeError, message));
}

static VALUE
vm_define_class(ID id, rb_num_t flags, VALUE cbase, VALUE super)
{
    VALUE klass;

    if (((flags) & 0x10) && !( ((RUBY_T_CLASS) == RUBY_T_FIXNUM) ? (((int)(long)(super))&RUBY_FIXNUM_FLAG) : ((RUBY_T_CLASS) == RUBY_T_TRUE) ? ((super) == ((VALUE)RUBY_Qtrue)) : ((RUBY_T_CLASS) == RUBY_T_FALSE) ? ((super) == ((VALUE)RUBY_Qfalse)) : ((RUBY_T_CLASS) == RUBY_T_NIL) ? ((super) == ((VALUE)RUBY_Qnil)) : ((RUBY_T_CLASS) == RUBY_T_UNDEF) ? ((super) == ((VALUE)RUBY_Qundef)) : ((RUBY_T_CLASS) == RUBY_T_SYMBOL) ? ((((VALUE)(super)&~((~(VALUE)0)<<RUBY_SPECIAL_SHIFT)) == RUBY_SYMBOL_FLAG)||(!(((VALUE)(super) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(super) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(super))->flags & RUBY_T_MASK) == (RUBY_T_SYMBOL))) : ((RUBY_T_CLASS) == RUBY_T_FLOAT) ? ( ((((int)(long)(super))&RUBY_FLONUM_MASK) == RUBY_FLONUM_FLAG) || (!(((VALUE)(super) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(super) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(super))->flags & RUBY_T_MASK) == RUBY_T_FLOAT)) : (!(((VALUE)(super) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(super) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(super))->flags & RUBY_T_MASK) == (RUBY_T_CLASS)))) {
 rb_raise(rb_eTypeError,
   "superclass must be a Class (%""l""i" "\v"" given)",
   rb_obj_class(super));
    }

    vm_check_if_namespace(cbase);


    rb_autoload_load(cbase, id);
    if ((klass = vm_const_get_under(id, flags, cbase)) != 0) {
        if (!vm_check_if_class(id, flags, super, klass))
            unmatched_redefinition("class", cbase, id, klass);
        return klass;
    }
    else {
 return vm_declare_class(id, flags, cbase, super);
    }
}

static VALUE
vm_define_module(ID id, rb_num_t flags, VALUE cbase)
{
    VALUE mod;

    vm_check_if_namespace(cbase);
    if ((mod = vm_const_get_under(id, flags, cbase)) != 0) {
        if (!vm_check_if_module(id, mod))
            unmatched_redefinition("module", cbase, id, mod);
        return mod;
    }
    else {
 return vm_declare_module(id, cbase);
    }
}

static VALUE
vm_find_or_create_class_by_id(ID id,
         rb_num_t flags,
         VALUE cbase,
         VALUE super)
{
    rb_vm_defineclass_type_t type = ((rb_vm_defineclass_type_t)(flags) & VM_DEFINECLASS_TYPE_MASK);

    switch (type) {
      case VM_DEFINECLASS_TYPE_CLASS:

 return vm_define_class(id, flags, cbase, super);

      case VM_DEFINECLASS_TYPE_SINGLETON_CLASS:

 return rb_singleton_class(cbase);

      case VM_DEFINECLASS_TYPE_MODULE:

 return vm_define_module(id, flags, cbase);

      default:
 rb_bug("unknown defineclass type: %d", (int)type);
    }
}

static rb_method_visibility_t
vm_scope_visibility_get(const rb_execution_context_t *ec)
{
    const rb_control_frame_t *cfp = rb_vm_get_ruby_level_next_cfp(ec, ec->cfp);

    if (!vm_env_cref_by_cref(cfp->ep)) {
        return METHOD_VISI_PUBLIC;
    }
    else {
        return CREF_SCOPE_VISI(vm_ec_cref(ec))->method_visi;
    }
}

static int
vm_scope_module_func_check(const rb_execution_context_t *ec)
{
    const rb_control_frame_t *cfp = rb_vm_get_ruby_level_next_cfp(ec, ec->cfp);

    if (!vm_env_cref_by_cref(cfp->ep)) {
        return 0;
    }
    else {
        return CREF_SCOPE_VISI(vm_ec_cref(ec))->module_func;
    }
}

static void
vm_define_method(const rb_execution_context_t *ec, VALUE obj, ID id, VALUE iseqval, int is_singleton)
{
    VALUE klass;
    rb_method_visibility_t visi;
    rb_cref_t *cref = vm_ec_cref(ec);

    if (!is_singleton) {
        klass = CREF_CLASS(cref);
        visi = vm_scope_visibility_get(ec);
    }
    else {
        klass = rb_singleton_class(obj);
        visi = METHOD_VISI_PUBLIC;
    }

    if (!((VALUE)(klass) != ((VALUE)RUBY_Qnil))) {
        rb_raise(rb_eTypeError, "no class/module to add method");
    }

    rb_add_method_iseq(klass, id, (const rb_iseq_t *)iseqval, cref, visi);

    if (!is_singleton && vm_scope_module_func_check(ec)) {
        klass = rb_singleton_class(klass);
        rb_add_method_iseq(klass, id, (const rb_iseq_t *)iseqval, cref, METHOD_VISI_PUBLIC);
    }
}

static void
vm_search_method_wrap(
    const struct rb_control_frame_struct *reg_cfp,
    struct rb_call_data *cd,
    VALUE recv)
{
    vm_search_method(cd, recv);
}

static void
vm_search_invokeblock(
    const struct rb_control_frame_struct *reg_cfp,
    struct rb_call_data *cd,
    VALUE recv)
{

}

static VALUE
vm_invokeblock_i(
    struct rb_execution_context_struct *ec,
    struct rb_control_frame_struct *reg_cfp,
    struct rb_calling_info *calling,
    struct rb_call_data *cd)
{
    const struct rb_call_info *ci = &cd->ci;
    VALUE block_handler = VM_CF_BLOCK_HANDLER((((reg_cfp))));

    if (block_handler == 0) {
        rb_vm_localjump_error("no block given (yield)", ((VALUE)RUBY_Qnil), 0);
    }
    else {
        return vm_invoke_block(ec, (((reg_cfp))), calling, ci, block_handler);
    }
}

static VALUE
vm_sendish(
    struct rb_execution_context_struct *ec,
    struct rb_control_frame_struct *reg_cfp,
    struct rb_call_data *cd,
    VALUE block_handler,
    void (*method_explorer)(
        const struct rb_control_frame_struct *reg_cfp,
        struct rb_call_data *cd,
        VALUE recv))
{
    CALL_INFO ci = &cd->ci;
    CALL_CACHE cc = &cd->cc;
    VALUE val;
    int argc = ci->orig_argc;
    VALUE recv = (*(((((reg_cfp)->sp)))-(argc)-1));
    struct rb_calling_info calling;

    calling.block_handler = block_handler;
    calling.kw_splat = ((ci)->flag & (0x01 << VM_CALL_KW_SPLAT_bit)) > 0;
    calling.recv = recv;
    calling.argc = argc;

    method_explorer((((reg_cfp))), cd, recv);

    val = cc->call(ec, (((reg_cfp))), &calling, cd);

    if (val != ((VALUE)RUBY_Qundef)) {
        return val;
    }
    else {
        do { (reg_cfp) = ec->cfp; } while (0);
    }
    if (((((reg_cfp)))->iseq)->body->catch_except_p) {
        VM_ENV_FLAGS_SET(((((reg_cfp)->ep))), VM_FRAME_FLAG_FINISH);
        return rb_vm_exec(ec, 1);
    }
    else if ((val = mjit_exec(ec)) == ((VALUE)RUBY_Qundef)) {
        VM_ENV_FLAGS_SET(((((reg_cfp)->ep))), VM_FRAME_FLAG_FINISH);
        return rb_vm_exec(ec, 0);
    }
    else {
        return val;
    }






}

static VALUE
vm_opt_str_freeze(VALUE str, int bop, ID id)
{
    if (((__builtin_expect(!!((rb_current_vm()->redefined_flag[(bop)]&((1 << 2))) == 0), 1)))) {
 return str;
    }
    else {
 return ((VALUE)RUBY_Qundef);
    }
}



static VALUE
vm_opt_newarray_max(rb_num_t num, const VALUE *ptr)
{
    if (((__builtin_expect(!!((rb_current_vm()->redefined_flag[(BOP_MAX)]&((1 << 3))) == 0), 1)))) {
 if (num == 0) {
     return ((VALUE)RUBY_Qnil);
 }
 else {
     struct cmp_opt_data cmp_opt = { 0, 0 };
     VALUE result = *ptr;
            rb_snum_t i = num - 1;
     while (i-- > 0) {
  const VALUE v = *++ptr;
  if ((((((int)(long)(v))&RUBY_FIXNUM_FLAG) && (((int)(long)(result))&RUBY_FIXNUM_FLAG) && (((cmp_opt).opt_inited & (1U << cmp_opt_Fixnum)) ? ((cmp_opt).opt_methods & (1U << cmp_opt_Fixnum)) : (((cmp_opt).opt_inited |= (1U << cmp_opt_Fixnum)), __extension__({ static struct rb_call_data rb_mbdp; (rb_cInteger == ((VALUE)RUBY_Qfalse)) ? 1 : rb_method_basic_definition_p_with_cc(&rb_mbdp, rb_cInteger, idCmp); }) && ((cmp_opt).opt_methods |= (1U << cmp_opt_Fixnum))))) ? (((long)v > (long)result) ? 1 : ((long)v < (long)result) ? -1 : 0) : ((( ((RUBY_T_STRING) == RUBY_T_FIXNUM) ? (((int)(long)((v)))&RUBY_FIXNUM_FLAG) : ((RUBY_T_STRING) == RUBY_T_TRUE) ? (((v)) == ((VALUE)RUBY_Qtrue)) : ((RUBY_T_STRING) == RUBY_T_FALSE) ? (((v)) == ((VALUE)RUBY_Qfalse)) : ((RUBY_T_STRING) == RUBY_T_NIL) ? (((v)) == ((VALUE)RUBY_Qnil)) : ((RUBY_T_STRING) == RUBY_T_UNDEF) ? (((v)) == ((VALUE)RUBY_Qundef)) : ((RUBY_T_STRING) == RUBY_T_SYMBOL) ? ((((VALUE)((v))&~((~(VALUE)0)<<RUBY_SPECIAL_SHIFT)) == RUBY_SYMBOL_FLAG)||(!(((VALUE)((v)) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)((v)) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)((v)))->flags & RUBY_T_MASK) == (RUBY_T_SYMBOL))) : ((RUBY_T_STRING) == RUBY_T_FLOAT) ? ( ((((int)(long)((v)))&RUBY_FLONUM_MASK) == RUBY_FLONUM_FLAG) || (!(((VALUE)((v)) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)((v)) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)((v)))->flags & RUBY_T_MASK) == RUBY_T_FLOAT)) : (!(((VALUE)((v)) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)((v)) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)((v)))->flags & RUBY_T_MASK) == (RUBY_T_STRING))) && rb_class_of((VALUE)(v)) == rb_cString) && (( ((RUBY_T_STRING) == RUBY_T_FIXNUM) ? (((int)(long)((result)))&RUBY_FIXNUM_FLAG) : ((RUBY_T_STRING) == RUBY_T_TRUE) ? (((result)) == ((VALUE)RUBY_Qtrue)) : ((RUBY_T_STRING) == RUBY_T_FALSE) ? (((result)) == ((VALUE)RUBY_Qfalse)) : ((RUBY_T_STRING) == RUBY_T_NIL) ? (((result)) == ((VALUE)RUBY_Qnil)) : ((RUBY_T_STRING) == RUBY_T_UNDEF) ? (((result)) == ((VALUE)RUBY_Qundef)) : ((RUBY_T_STRING) == RUBY_T_SYMBOL) ? ((((VALUE)((result))&~((~(VALUE)0)<<RUBY_SPECIAL_SHIFT)) == RUBY_SYMBOL_FLAG)||(!(((VALUE)((result)) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)((result)) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)((result)))->flags & RUBY_T_MASK) == (RUBY_T_SYMBOL))) : ((RUBY_T_STRING) == RUBY_T_FLOAT) ? ( ((((int)(long)((result)))&RUBY_FLONUM_MASK) == RUBY_FLONUM_FLAG) || (!(((VALUE)((result)) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)((result)) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)((result)))->flags & RUBY_T_MASK) == RUBY_T_FLOAT)) : (!(((VALUE)((result)) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)((result)) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)((result)))->flags & RUBY_T_MASK) == (RUBY_T_STRING))) && rb_class_of((VALUE)(result)) == rb_cString) && (((cmp_opt).opt_inited & (1U << cmp_opt_String)) ? ((cmp_opt).opt_methods & (1U << cmp_opt_String)) : (((cmp_opt).opt_inited |= (1U << cmp_opt_String)), __extension__({ static struct rb_call_data rb_mbdp; (rb_cString == ((VALUE)RUBY_Qfalse)) ? 1 : rb_method_basic_definition_p_with_cc(&rb_mbdp, rb_cString, idCmp); }) && ((cmp_opt).opt_methods |= (1U << cmp_opt_String))))) ? rb_str_cmp(v, result) : (( ((((int)(long)(v))&RUBY_FLONUM_MASK) == RUBY_FLONUM_FLAG) || (!(((VALUE)(v) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(v) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(v))->flags & RUBY_T_MASK) == RUBY_T_FLOAT)) && ( ((((int)(long)(result))&RUBY_FLONUM_MASK) == RUBY_FLONUM_FLAG) || (!(((VALUE)(result) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(result) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(result))->flags & RUBY_T_MASK) == RUBY_T_FLOAT)) && (((cmp_opt).opt_inited & (1U << cmp_opt_Float)) ? ((cmp_opt).opt_methods & (1U << cmp_opt_Float)) : (((cmp_opt).opt_inited |= (1U << cmp_opt_Float)), __extension__({ static struct rb_call_data rb_mbdp; (rb_cFloat == ((VALUE)RUBY_Qfalse)) ? 1 : rb_method_basic_definition_p_with_cc(&rb_mbdp, rb_cFloat, idCmp); }) && ((cmp_opt).opt_methods |= (1U << cmp_opt_Float))))) ? rb_float_cmp(v, result) : rb_cmpint(__extension__({ static struct rb_call_data rb_funcallv_data; rb_funcallv_with_cc(&rb_funcallv_data, v, idCmp, 1, &result); }), v, result)) > 0) {
      result = v;
  }
     }
     return result;
 }
    }
    else {
 VALUE ary = rb_ary_new_from_values(num, ptr);
 return __extension__({ const int rb_funcall_argc = (0); const VALUE rb_funcall_args[] = {}; const int rb_funcall_nargs = (int)(sizeof(rb_funcall_args) / sizeof(VALUE)); __extension__({ static struct rb_call_data rb_funcallv_data; rb_funcallv_with_cc(&rb_funcallv_data, ary, idMax, __builtin_choose_expr(__builtin_constant_p(rb_funcall_argc), (((rb_funcall_argc) == 0 ? (rb_funcall_nargs) <= 1 : (rb_funcall_argc) == (rb_funcall_nargs)) ? (rb_funcall_argc) : ((rb_funcall_argc)/((rb_funcall_argc) == 0 ? (rb_funcall_nargs) <= 1 : (rb_funcall_argc) == (rb_funcall_nargs)))), (((rb_funcall_argc) <= (rb_funcall_nargs)) ? (rb_funcall_argc) : (rb_fatal("argc(%d) exceeds actual arguments(%d)", rb_funcall_argc, rb_funcall_nargs), 0))), rb_funcall_nargs ? rb_funcall_args : ((void*)0)); }); });
    }
}

static VALUE
vm_opt_newarray_min(rb_num_t num, const VALUE *ptr)
{
    if (((__builtin_expect(!!((rb_current_vm()->redefined_flag[(BOP_MIN)]&((1 << 3))) == 0), 1)))) {
 if (num == 0) {
     return ((VALUE)RUBY_Qnil);
 }
 else {
     struct cmp_opt_data cmp_opt = { 0, 0 };
     VALUE result = *ptr;
            rb_snum_t i = num - 1;
     while (i-- > 0) {
  const VALUE v = *++ptr;
  if ((((((int)(long)(v))&RUBY_FIXNUM_FLAG) && (((int)(long)(result))&RUBY_FIXNUM_FLAG) && (((cmp_opt).opt_inited & (1U << cmp_opt_Fixnum)) ? ((cmp_opt).opt_methods & (1U << cmp_opt_Fixnum)) : (((cmp_opt).opt_inited |= (1U << cmp_opt_Fixnum)), __extension__({ static struct rb_call_data rb_mbdp; (rb_cInteger == ((VALUE)RUBY_Qfalse)) ? 1 : rb_method_basic_definition_p_with_cc(&rb_mbdp, rb_cInteger, idCmp); }) && ((cmp_opt).opt_methods |= (1U << cmp_opt_Fixnum))))) ? (((long)v > (long)result) ? 1 : ((long)v < (long)result) ? -1 : 0) : ((( ((RUBY_T_STRING) == RUBY_T_FIXNUM) ? (((int)(long)((v)))&RUBY_FIXNUM_FLAG) : ((RUBY_T_STRING) == RUBY_T_TRUE) ? (((v)) == ((VALUE)RUBY_Qtrue)) : ((RUBY_T_STRING) == RUBY_T_FALSE) ? (((v)) == ((VALUE)RUBY_Qfalse)) : ((RUBY_T_STRING) == RUBY_T_NIL) ? (((v)) == ((VALUE)RUBY_Qnil)) : ((RUBY_T_STRING) == RUBY_T_UNDEF) ? (((v)) == ((VALUE)RUBY_Qundef)) : ((RUBY_T_STRING) == RUBY_T_SYMBOL) ? ((((VALUE)((v))&~((~(VALUE)0)<<RUBY_SPECIAL_SHIFT)) == RUBY_SYMBOL_FLAG)||(!(((VALUE)((v)) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)((v)) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)((v)))->flags & RUBY_T_MASK) == (RUBY_T_SYMBOL))) : ((RUBY_T_STRING) == RUBY_T_FLOAT) ? ( ((((int)(long)((v)))&RUBY_FLONUM_MASK) == RUBY_FLONUM_FLAG) || (!(((VALUE)((v)) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)((v)) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)((v)))->flags & RUBY_T_MASK) == RUBY_T_FLOAT)) : (!(((VALUE)((v)) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)((v)) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)((v)))->flags & RUBY_T_MASK) == (RUBY_T_STRING))) && rb_class_of((VALUE)(v)) == rb_cString) && (( ((RUBY_T_STRING) == RUBY_T_FIXNUM) ? (((int)(long)((result)))&RUBY_FIXNUM_FLAG) : ((RUBY_T_STRING) == RUBY_T_TRUE) ? (((result)) == ((VALUE)RUBY_Qtrue)) : ((RUBY_T_STRING) == RUBY_T_FALSE) ? (((result)) == ((VALUE)RUBY_Qfalse)) : ((RUBY_T_STRING) == RUBY_T_NIL) ? (((result)) == ((VALUE)RUBY_Qnil)) : ((RUBY_T_STRING) == RUBY_T_UNDEF) ? (((result)) == ((VALUE)RUBY_Qundef)) : ((RUBY_T_STRING) == RUBY_T_SYMBOL) ? ((((VALUE)((result))&~((~(VALUE)0)<<RUBY_SPECIAL_SHIFT)) == RUBY_SYMBOL_FLAG)||(!(((VALUE)((result)) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)((result)) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)((result)))->flags & RUBY_T_MASK) == (RUBY_T_SYMBOL))) : ((RUBY_T_STRING) == RUBY_T_FLOAT) ? ( ((((int)(long)((result)))&RUBY_FLONUM_MASK) == RUBY_FLONUM_FLAG) || (!(((VALUE)((result)) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)((result)) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)((result)))->flags & RUBY_T_MASK) == RUBY_T_FLOAT)) : (!(((VALUE)((result)) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)((result)) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)((result)))->flags & RUBY_T_MASK) == (RUBY_T_STRING))) && rb_class_of((VALUE)(result)) == rb_cString) && (((cmp_opt).opt_inited & (1U << cmp_opt_String)) ? ((cmp_opt).opt_methods & (1U << cmp_opt_String)) : (((cmp_opt).opt_inited |= (1U << cmp_opt_String)), __extension__({ static struct rb_call_data rb_mbdp; (rb_cString == ((VALUE)RUBY_Qfalse)) ? 1 : rb_method_basic_definition_p_with_cc(&rb_mbdp, rb_cString, idCmp); }) && ((cmp_opt).opt_methods |= (1U << cmp_opt_String))))) ? rb_str_cmp(v, result) : (( ((((int)(long)(v))&RUBY_FLONUM_MASK) == RUBY_FLONUM_FLAG) || (!(((VALUE)(v) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(v) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(v))->flags & RUBY_T_MASK) == RUBY_T_FLOAT)) && ( ((((int)(long)(result))&RUBY_FLONUM_MASK) == RUBY_FLONUM_FLAG) || (!(((VALUE)(result) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(result) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(result))->flags & RUBY_T_MASK) == RUBY_T_FLOAT)) && (((cmp_opt).opt_inited & (1U << cmp_opt_Float)) ? ((cmp_opt).opt_methods & (1U << cmp_opt_Float)) : (((cmp_opt).opt_inited |= (1U << cmp_opt_Float)), __extension__({ static struct rb_call_data rb_mbdp; (rb_cFloat == ((VALUE)RUBY_Qfalse)) ? 1 : rb_method_basic_definition_p_with_cc(&rb_mbdp, rb_cFloat, idCmp); }) && ((cmp_opt).opt_methods |= (1U << cmp_opt_Float))))) ? rb_float_cmp(v, result) : rb_cmpint(__extension__({ static struct rb_call_data rb_funcallv_data; rb_funcallv_with_cc(&rb_funcallv_data, v, idCmp, 1, &result); }), v, result)) < 0) {
      result = v;
  }
     }
     return result;
 }
    }
    else {
 VALUE ary = rb_ary_new_from_values(num, ptr);
 return __extension__({ const int rb_funcall_argc = (0); const VALUE rb_funcall_args[] = {}; const int rb_funcall_nargs = (int)(sizeof(rb_funcall_args) / sizeof(VALUE)); __extension__({ static struct rb_call_data rb_funcallv_data; rb_funcallv_with_cc(&rb_funcallv_data, ary, idMin, __builtin_choose_expr(__builtin_constant_p(rb_funcall_argc), (((rb_funcall_argc) == 0 ? (rb_funcall_nargs) <= 1 : (rb_funcall_argc) == (rb_funcall_nargs)) ? (rb_funcall_argc) : ((rb_funcall_argc)/((rb_funcall_argc) == 0 ? (rb_funcall_nargs) <= 1 : (rb_funcall_argc) == (rb_funcall_nargs)))), (((rb_funcall_argc) <= (rb_funcall_nargs)) ? (rb_funcall_argc) : (rb_fatal("argc(%d) exceeds actual arguments(%d)", rb_funcall_argc, rb_funcall_nargs), 0))), rb_funcall_nargs ? rb_funcall_args : ((void*)0)); }); });
    }
}


static int
vm_ic_hit_p(IC ic, const VALUE *reg_ep)
{
    if (ic->ic_serial == (ruby_vm_global_constant_state)) {
        return (ic->ic_cref == ((void*)0) ||
                ic->ic_cref == vm_get_cref(reg_ep));
    }
    return 0;
}

static void
vm_ic_update(IC ic, VALUE val, const VALUE *reg_ep)
{
    ((void)0);
    ic->value = val;
    ic->ic_serial = (ruby_vm_global_constant_state) - ruby_vm_const_missing_count;
    ic->ic_cref = vm_get_const_key_cref(reg_ep);
    ruby_vm_const_missing_count = 0;
}

static VALUE
vm_once_dispatch(rb_execution_context_t *ec, ISEQ iseq, ISE is)
{
    rb_thread_t *th = rb_ec_thread_ptr(ec);
    rb_thread_t *const RUNNING_THREAD_ONCE_DONE = (rb_thread_t *)(0x1);

  again:
    if (is->once.running_thread == RUNNING_THREAD_ONCE_DONE) {
 return is->once.value;
    }
    else if (is->once.running_thread == ((void*)0)) {
 VALUE val;
 is->once.running_thread = th;
 val = rb_ensure(vm_once_exec, (VALUE)iseq, vm_once_clear, (VALUE)is);
 __extension__({
;
; typeof(rb_obj_write((VALUE)(ec->cfp->iseq), (VALUE *)(&is->once.value), (VALUE)(val), "./vm_insnhelper.c", 4160)) unaligned_member_access_result = (rb_obj_write((VALUE)(ec->cfp->iseq), (VALUE *)(&is->once.value), (VALUE)(val), "./vm_insnhelper.c", 4160));
; unaligned_member_access_result; });

 is->once.running_thread = RUNNING_THREAD_ONCE_DONE;
 return val;
    }
    else if (is->once.running_thread == th) {

 return vm_once_exec((VALUE)iseq);
    }
    else {

 rb_vm_check_ints(ec);
 rb_thread_schedule();
 goto again;
    }
}

static OFFSET
vm_case_dispatch(CDHASH hash, OFFSET else_offset, VALUE key)
{
    switch (__extension__({ VALUE arg_obj = (key); (((VALUE)(arg_obj) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(arg_obj) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) ? -1 : (int)(((struct RBasic*)(arg_obj))->flags & RUBY_T_MASK); })) {
      case -1:
      case RUBY_T_FLOAT:
      case RUBY_T_SYMBOL:
      case RUBY_T_BIGNUM:
      case RUBY_T_STRING:
 if (((__builtin_expect(!!((rb_current_vm()->redefined_flag[(BOP_EQQ)]&((1 << 6) | (1 << 0) | (1 << 1) | (1 << 9) | (1 << 10) | (1 << 11) | (1 << 2))) == 0), 1)))) {







     st_data_t val;
     if (( ((((int)(long)(key))&RUBY_FLONUM_MASK) == RUBY_FLONUM_FLAG) || (!(((VALUE)(key) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(key) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(key))->flags & RUBY_T_MASK) == RUBY_T_FLOAT))) {
  double kval = rb_float_value_inline(key);
  if (!( sizeof(kval) == sizeof(float) ? __inline_isinff((float)(kval)) : sizeof(kval) == sizeof(double) ? __inline_isinfd((double)(kval)) : __inline_isinfl((long double)(kval))) && modf(kval, &kval) == 0.0) {
      key = (((kval) < (9223372036854775807L>>1)+1) && ((kval) >= (((long)(-9223372036854775807L -1L))>>(int)(1)))) ? (((VALUE)((long)kval))<<1 | RUBY_FIXNUM_FLAG) : rb_dbl2big(kval);
  }
     }
            if (rb_hash_stlike_lookup(hash, key, &val)) {
  return ((long)(((long)((VALUE)val))>>(int)(1)));
     }
     else {
  return else_offset;
     }
 }
    }
    return 0;
}

__attribute__ ((__noreturn__)) static void vm_stack_consistency_error(const rb_execution_context_t *ec, const rb_control_frame_t *, const VALUE *);



static void
vm_stack_consistency_error(const rb_execution_context_t *ec,
      const rb_control_frame_t *cfp,
      const VALUE *bp)
{
    const ptrdiff_t nsp = ((cfp->sp) - (ec)->vm_stack);
    const ptrdiff_t nbp = ((bp) - (ec)->vm_stack);
    static const char stack_consistency_error[] =
 "Stack consistency error (sp: %""t""d"", bp: %""t""d"")";






    rb_bug(stack_consistency_error, nsp, nbp);

}
ALWAYS_INLINE(static inline VALUE
vm_opt_plus(VALUE recv, VALUE obj));
static inline VALUE
vm_opt_plus(VALUE recv, VALUE obj) {
    if (FIXNUM_2_P(recv, obj) &&
 ((__builtin_expect(!!((rb_current_vm()->redefined_flag[(BOP_PLUS)]&((1 << 0))) == 0), 1)))) {
 return rb_fix_plus_fix(recv, obj);
    }
    else if (FLONUM_2_P(recv, obj) &&
      ((__builtin_expect(!!((rb_current_vm()->redefined_flag[(BOP_PLUS)]&((1 << 1))) == 0), 1)))) {
 return rb_float_new_inline(rb_float_value_inline(recv) + rb_float_value_inline(obj));
    }
    else if ((((VALUE)(recv) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(recv) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) || (((VALUE)(obj) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(obj) & (VALUE)~((VALUE)RUBY_Qnil)) == 0))) {
 return ((VALUE)RUBY_Qundef);
    }
    else if ((((struct RBasic*)(recv))->klass) == rb_cFloat &&
      (((struct RBasic*)(obj))->klass) == rb_cFloat &&
      ((__builtin_expect(!!((rb_current_vm()->redefined_flag[(BOP_PLUS)]&((1 << 1))) == 0), 1)))) {
 return rb_float_new_inline(rb_float_value_inline(recv) + rb_float_value_inline(obj));
    }
    else if ((((struct RBasic*)(recv))->klass) == rb_cString &&
      (((struct RBasic*)(obj))->klass) == rb_cString &&
      ((__builtin_expect(!!((rb_current_vm()->redefined_flag[(BOP_PLUS)]&((1 << 2))) == 0), 1)))) {
        return rb_str_opt_plus(recv, obj);
    }
    else if ((((struct RBasic*)(recv))->klass) == rb_cArray &&
             (((struct RBasic*)(obj))->klass) == rb_cArray &&
      ((__builtin_expect(!!((rb_current_vm()->redefined_flag[(BOP_PLUS)]&((1 << 3))) == 0), 1)))) {
 return rb_ary_plus(recv, obj);
    }
    else {
 return ((VALUE)RUBY_Qundef);
    }
}
ALWAYS_INLINE(static inline VALUE
vm_opt_minus(VALUE recv, VALUE obj));
static inline VALUE
vm_opt_minus(VALUE recv, VALUE obj) {
    if (FIXNUM_2_P(recv, obj) &&
 ((__builtin_expect(!!((rb_current_vm()->redefined_flag[(BOP_MINUS)]&((1 << 0))) == 0), 1)))) {
 return rb_fix_minus_fix(recv, obj);
    }
    else if (FLONUM_2_P(recv, obj) &&
      ((__builtin_expect(!!((rb_current_vm()->redefined_flag[(BOP_MINUS)]&((1 << 1))) == 0), 1)))) {
 return rb_float_new_inline(rb_float_value_inline(recv) - rb_float_value_inline(obj));
    }
    else if ((((VALUE)(recv) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(recv) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) || (((VALUE)(obj) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(obj) & (VALUE)~((VALUE)RUBY_Qnil)) == 0))) {
 return ((VALUE)RUBY_Qundef);
    }
    else if ((((struct RBasic*)(recv))->klass) == rb_cFloat &&
      (((struct RBasic*)(obj))->klass) == rb_cFloat &&
      ((__builtin_expect(!!((rb_current_vm()->redefined_flag[(BOP_MINUS)]&((1 << 1))) == 0), 1)))) {
 return rb_float_new_inline(rb_float_value_inline(recv) - rb_float_value_inline(obj));
    }
    else {
 return ((VALUE)RUBY_Qundef);
    }
}
ALWAYS_INLINE(static inline VALUE
vm_opt_mult(VALUE recv, VALUE obj));
static inline VALUE
vm_opt_mult(VALUE recv, VALUE obj) {
    if (FIXNUM_2_P(recv, obj) &&
 ((__builtin_expect(!!((rb_current_vm()->redefined_flag[(BOP_MULT)]&((1 << 0))) == 0), 1)))) {
 return rb_fix_mul_fix(recv, obj);
    }
    else if (FLONUM_2_P(recv, obj) &&
      ((__builtin_expect(!!((rb_current_vm()->redefined_flag[(BOP_MULT)]&((1 << 1))) == 0), 1)))) {
 return rb_float_new_inline(rb_float_value_inline(recv) * rb_float_value_inline(obj));
    }
    else if ((((VALUE)(recv) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(recv) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) || (((VALUE)(obj) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(obj) & (VALUE)~((VALUE)RUBY_Qnil)) == 0))) {
 return ((VALUE)RUBY_Qundef);
    }
    else if ((((struct RBasic*)(recv))->klass) == rb_cFloat &&
      (((struct RBasic*)(obj))->klass) == rb_cFloat &&
      ((__builtin_expect(!!((rb_current_vm()->redefined_flag[(BOP_MULT)]&((1 << 1))) == 0), 1)))) {
 return rb_float_new_inline(rb_float_value_inline(recv) * rb_float_value_inline(obj));
    }
    else {
 return ((VALUE)RUBY_Qundef);
    }
}
ALWAYS_INLINE(static inline VALUE
vm_opt_div(VALUE recv, VALUE obj));
static inline VALUE
vm_opt_div(VALUE recv, VALUE obj) {
    if (FIXNUM_2_P(recv, obj) &&
 ((__builtin_expect(!!((rb_current_vm()->redefined_flag[(BOP_DIV)]&((1 << 0))) == 0), 1)))) {
 return (((long)(((long)(obj))>>(int)(1))) == 0) ? ((VALUE)RUBY_Qundef) : rb_fix_div_fix(recv, obj);
    }
    else if (FLONUM_2_P(recv, obj) &&
      ((__builtin_expect(!!((rb_current_vm()->redefined_flag[(BOP_DIV)]&((1 << 1))) == 0), 1)))) {
        return rb_flo_div_flo(recv, obj);
    }
    else if ((((VALUE)(recv) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(recv) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) || (((VALUE)(obj) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(obj) & (VALUE)~((VALUE)RUBY_Qnil)) == 0))) {
 return ((VALUE)RUBY_Qundef);
    }
    else if ((((struct RBasic*)(recv))->klass) == rb_cFloat &&
      (((struct RBasic*)(obj))->klass) == rb_cFloat &&
      ((__builtin_expect(!!((rb_current_vm()->redefined_flag[(BOP_DIV)]&((1 << 1))) == 0), 1)))) {
        return rb_flo_div_flo(recv, obj);
    }
    else {
 return ((VALUE)RUBY_Qundef);
    }
}
ALWAYS_INLINE(static inline VALUE
vm_opt_mod(VALUE recv, VALUE obj));
static inline VALUE
vm_opt_mod(VALUE recv, VALUE obj) {
    if (FIXNUM_2_P(recv, obj) &&
 ((__builtin_expect(!!((rb_current_vm()->redefined_flag[(BOP_MOD)]&((1 << 0))) == 0), 1)))) {
 return (((long)(((long)(obj))>>(int)(1))) == 0) ? ((VALUE)RUBY_Qundef) : rb_fix_mod_fix(recv, obj);
    }
    else if (FLONUM_2_P(recv, obj) &&
      ((__builtin_expect(!!((rb_current_vm()->redefined_flag[(BOP_MOD)]&((1 << 1))) == 0), 1)))) {
 return rb_float_new_inline(ruby_float_mod(rb_float_value_inline(recv), rb_float_value_inline(obj)));
    }
    else if ((((VALUE)(recv) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(recv) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) || (((VALUE)(obj) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(obj) & (VALUE)~((VALUE)RUBY_Qnil)) == 0))) {
 return ((VALUE)RUBY_Qundef);
    }
    else if ((((struct RBasic*)(recv))->klass) == rb_cFloat &&
      (((struct RBasic*)(obj))->klass) == rb_cFloat &&
      ((__builtin_expect(!!((rb_current_vm()->redefined_flag[(BOP_MOD)]&((1 << 1))) == 0), 1)))) {
 return rb_float_new_inline(ruby_float_mod(rb_float_value_inline(recv), rb_float_value_inline(obj)));
    }
    else {
 return ((VALUE)RUBY_Qundef);
    }
}
ALWAYS_INLINE(static inline VALUE
vm_opt_neq(CALL_DATA cd, CALL_DATA cd_eq, VALUE recv, VALUE obj));
static inline VALUE
vm_opt_neq(CALL_DATA cd, CALL_DATA cd_eq, VALUE recv, VALUE obj) {
    if (vm_method_cfunc_is(cd, recv, rb_obj_not_equal)) {
        VALUE val = opt_eq_func(recv, obj, cd_eq);

 if (val != ((VALUE)RUBY_Qundef)) {
     return !(((VALUE)(val) & (VALUE)~((VALUE)RUBY_Qnil)) == 0) ? ((VALUE)RUBY_Qfalse) : ((VALUE)RUBY_Qtrue);
 }
    }

    return ((VALUE)RUBY_Qundef);
}
ALWAYS_INLINE(static inline VALUE
vm_opt_lt(VALUE recv, VALUE obj));
static inline VALUE
vm_opt_lt(VALUE recv, VALUE obj) {
    if (FIXNUM_2_P(recv, obj) &&
 ((__builtin_expect(!!((rb_current_vm()->redefined_flag[(BOP_LT)]&((1 << 0))) == 0), 1)))) {
 return (long)recv < (long)obj ? ((VALUE)RUBY_Qtrue) : ((VALUE)RUBY_Qfalse);
    }
    else if (FLONUM_2_P(recv, obj) &&
      ((__builtin_expect(!!((rb_current_vm()->redefined_flag[(BOP_LT)]&((1 << 1))) == 0), 1)))) {
 return rb_float_value_inline(recv) < rb_float_value_inline(obj) ? ((VALUE)RUBY_Qtrue) : ((VALUE)RUBY_Qfalse);
    }
    else if ((((VALUE)(recv) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(recv) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) || (((VALUE)(obj) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(obj) & (VALUE)~((VALUE)RUBY_Qnil)) == 0))) {
 return ((VALUE)RUBY_Qundef);
    }
    else if ((((struct RBasic*)(recv))->klass) == rb_cFloat &&
      (((struct RBasic*)(obj))->klass) == rb_cFloat &&
      ((__builtin_expect(!!((rb_current_vm()->redefined_flag[(BOP_LT)]&((1 << 1))) == 0), 1)))) {
                                                     ;
 return rb_float_value_inline(recv) < rb_float_value_inline(obj) ? ((VALUE)RUBY_Qtrue) : ((VALUE)RUBY_Qfalse);
    }
    else {
 return ((VALUE)RUBY_Qundef);
    }
}
ALWAYS_INLINE(static inline VALUE
vm_opt_le(VALUE recv, VALUE obj));
static inline VALUE
vm_opt_le(VALUE recv, VALUE obj) {
    if (FIXNUM_2_P(recv, obj) &&
 ((__builtin_expect(!!((rb_current_vm()->redefined_flag[(BOP_LE)]&((1 << 0))) == 0), 1)))) {
 return (long)recv <= (long)obj ? ((VALUE)RUBY_Qtrue) : ((VALUE)RUBY_Qfalse);
    }
    else if (FLONUM_2_P(recv, obj) &&
      ((__builtin_expect(!!((rb_current_vm()->redefined_flag[(BOP_LE)]&((1 << 1))) == 0), 1)))) {
 return rb_float_value_inline(recv) <= rb_float_value_inline(obj) ? ((VALUE)RUBY_Qtrue) : ((VALUE)RUBY_Qfalse);
    }
    else if ((((VALUE)(recv) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(recv) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) || (((VALUE)(obj) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(obj) & (VALUE)~((VALUE)RUBY_Qnil)) == 0))) {
 return ((VALUE)RUBY_Qundef);
    }
    else if ((((struct RBasic*)(recv))->klass) == rb_cFloat &&
      (((struct RBasic*)(obj))->klass) == rb_cFloat &&
      ((__builtin_expect(!!((rb_current_vm()->redefined_flag[(BOP_LE)]&((1 << 1))) == 0), 1)))) {
                                                     ;
 return rb_float_value_inline(recv) <= rb_float_value_inline(obj) ? ((VALUE)RUBY_Qtrue) : ((VALUE)RUBY_Qfalse);
    }
    else {
 return ((VALUE)RUBY_Qundef);
    }
}
ALWAYS_INLINE(static inline VALUE
vm_opt_gt(VALUE recv, VALUE obj));
static inline VALUE
vm_opt_gt(VALUE recv, VALUE obj) {
    if (FIXNUM_2_P(recv, obj) &&
 ((__builtin_expect(!!((rb_current_vm()->redefined_flag[(BOP_GT)]&((1 << 0))) == 0), 1)))) {
 return (long)recv > (long)obj ? ((VALUE)RUBY_Qtrue) : ((VALUE)RUBY_Qfalse);
    }
    else if (FLONUM_2_P(recv, obj) &&
      ((__builtin_expect(!!((rb_current_vm()->redefined_flag[(BOP_GT)]&((1 << 1))) == 0), 1)))) {
 return rb_float_value_inline(recv) > rb_float_value_inline(obj) ? ((VALUE)RUBY_Qtrue) : ((VALUE)RUBY_Qfalse);
    }
    else if ((((VALUE)(recv) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(recv) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) || (((VALUE)(obj) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(obj) & (VALUE)~((VALUE)RUBY_Qnil)) == 0))) {
 return ((VALUE)RUBY_Qundef);
    }
    else if ((((struct RBasic*)(recv))->klass) == rb_cFloat &&
      (((struct RBasic*)(obj))->klass) == rb_cFloat &&
      ((__builtin_expect(!!((rb_current_vm()->redefined_flag[(BOP_GT)]&((1 << 1))) == 0), 1)))) {
                                                     ;
 return rb_float_value_inline(recv) > rb_float_value_inline(obj) ? ((VALUE)RUBY_Qtrue) : ((VALUE)RUBY_Qfalse);
    }
    else {
 return ((VALUE)RUBY_Qundef);
    }
}
ALWAYS_INLINE(static inline VALUE
vm_opt_ge(VALUE recv, VALUE obj));
static inline VALUE
vm_opt_ge(VALUE recv, VALUE obj) {
    if (FIXNUM_2_P(recv, obj) &&
 ((__builtin_expect(!!((rb_current_vm()->redefined_flag[(BOP_GE)]&((1 << 0))) == 0), 1)))) {
 return (long)recv >= (long)obj ? ((VALUE)RUBY_Qtrue) : ((VALUE)RUBY_Qfalse);
    }
    else if (FLONUM_2_P(recv, obj) &&
      ((__builtin_expect(!!((rb_current_vm()->redefined_flag[(BOP_GE)]&((1 << 1))) == 0), 1)))) {
 return rb_float_value_inline(recv) >= rb_float_value_inline(obj) ? ((VALUE)RUBY_Qtrue) : ((VALUE)RUBY_Qfalse);
    }
    else if ((((VALUE)(recv) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(recv) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) || (((VALUE)(obj) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(obj) & (VALUE)~((VALUE)RUBY_Qnil)) == 0))) {
 return ((VALUE)RUBY_Qundef);
    }
    else if ((((struct RBasic*)(recv))->klass) == rb_cFloat &&
      (((struct RBasic*)(obj))->klass) == rb_cFloat &&
      ((__builtin_expect(!!((rb_current_vm()->redefined_flag[(BOP_GE)]&((1 << 1))) == 0), 1)))) {
                                                     ;
 return rb_float_value_inline(recv) >= rb_float_value_inline(obj) ? ((VALUE)RUBY_Qtrue) : ((VALUE)RUBY_Qfalse);
    }
    else {
 return ((VALUE)RUBY_Qundef);
    }
}
ALWAYS_INLINE(static inline VALUE
vm_opt_ltlt(VALUE recv, VALUE obj));
static inline VALUE
vm_opt_ltlt(VALUE recv, VALUE obj) {
    if ((((VALUE)(recv) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(recv) & (VALUE)~((VALUE)RUBY_Qnil)) == 0))) {
 return ((VALUE)RUBY_Qundef);
    }
    else if ((((struct RBasic*)(recv))->klass) == rb_cString &&
      ((__builtin_expect(!!((rb_current_vm()->redefined_flag[(BOP_LTLT)]&((1 << 2))) == 0), 1)))) {
 return rb_str_concat(recv, obj);
    }
    else if ((((struct RBasic*)(recv))->klass) == rb_cArray &&
      ((__builtin_expect(!!((rb_current_vm()->redefined_flag[(BOP_LTLT)]&((1 << 3))) == 0), 1)))) {
 return rb_ary_push(recv, obj);
    }
    else {
 return ((VALUE)RUBY_Qundef);
    }
}
ALWAYS_INLINE(static inline VALUE
vm_opt_and(VALUE recv, VALUE obj));
static inline VALUE
vm_opt_and(VALUE recv, VALUE obj) {
    if (FIXNUM_2_P(recv, obj) &&
        ((__builtin_expect(!!((rb_current_vm()->redefined_flag[(BOP_AND)]&((1 << 0))) == 0), 1)))) {
        return (recv & obj) | 1;
    }
    else {
        return ((VALUE)RUBY_Qundef);
    }
}
ALWAYS_INLINE(static inline VALUE
vm_opt_or(VALUE recv, VALUE obj));
static inline VALUE
vm_opt_or(VALUE recv, VALUE obj) {
    if (FIXNUM_2_P(recv, obj) &&
        ((__builtin_expect(!!((rb_current_vm()->redefined_flag[(BOP_OR)]&((1 << 0))) == 0), 1)))) {
        return recv | obj;
    }
    else {
        return ((VALUE)RUBY_Qundef);
    }
}
ALWAYS_INLINE(static inline VALUE
vm_opt_aref(VALUE recv, VALUE obj));
static inline VALUE
vm_opt_aref(VALUE recv, VALUE obj) {
    if ((((VALUE)(recv) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(recv) & (VALUE)~((VALUE)RUBY_Qnil)) == 0))) {
        if (FIXNUM_2_P(recv, obj) &&
                ((__builtin_expect(!!((rb_current_vm()->redefined_flag[(BOP_AREF)]&((1 << 0))) == 0), 1)))) {
            return rb_fix_aref(recv, obj);
        }
 return ((VALUE)RUBY_Qundef);
    }
    else if ((((struct RBasic*)(recv))->klass) == rb_cArray &&
      ((__builtin_expect(!!((rb_current_vm()->redefined_flag[(BOP_AREF)]&((1 << 3))) == 0), 1)))) {
        if ((((int)(long)(obj))&RUBY_FIXNUM_FLAG)) {
            return rb_ary_entry_internal(recv, ((long)(((long)(obj))>>(int)(1))));
        }
        else {
            return rb_ary_aref1(recv, obj);
        }
    }
    else if ((((struct RBasic*)(recv))->klass) == rb_cHash &&
      ((__builtin_expect(!!((rb_current_vm()->redefined_flag[(BOP_AREF)]&((1 << 4))) == 0), 1)))) {
 return rb_hash_aref(recv, obj);
    }
    else {
 return ((VALUE)RUBY_Qundef);
    }
}
ALWAYS_INLINE(static inline VALUE
vm_opt_aset(VALUE recv, VALUE obj, VALUE set));
static inline VALUE
vm_opt_aset(VALUE recv, VALUE obj, VALUE set) {
    if ((((VALUE)(recv) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(recv) & (VALUE)~((VALUE)RUBY_Qnil)) == 0))) {
 return ((VALUE)RUBY_Qundef);
    }
    else if ((((struct RBasic*)(recv))->klass) == rb_cArray &&
      ((__builtin_expect(!!((rb_current_vm()->redefined_flag[(BOP_ASET)]&((1 << 3))) == 0), 1))) &&
      (((int)(long)(obj))&RUBY_FIXNUM_FLAG)) {
 rb_ary_store(recv, ((long)(((long)(obj))>>(int)(1))), set);
 return set;
    }
    else if ((((struct RBasic*)(recv))->klass) == rb_cHash &&
      ((__builtin_expect(!!((rb_current_vm()->redefined_flag[(BOP_ASET)]&((1 << 4))) == 0), 1)))) {
 rb_hash_aset(recv, obj, set);
 return set;
    }
    else {
 return ((VALUE)RUBY_Qundef);
    }
}
ALWAYS_INLINE(static inline VALUE
vm_opt_aref_with(VALUE recv, VALUE key));
static inline VALUE
vm_opt_aref_with(VALUE recv, VALUE key) {
    if (!(((VALUE)(recv) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(recv) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (((struct RBasic*)(recv))->klass) == rb_cHash &&
 ((__builtin_expect(!!((rb_current_vm()->redefined_flag[(BOP_AREF)]&((1 << 4))) == 0), 1))) &&
 rb_hash_compare_by_id_p(recv) == ((VALUE)RUBY_Qfalse)) {
 return rb_hash_aref(recv, key);
    }
    else {
 return ((VALUE)RUBY_Qundef);
    }
}
ALWAYS_INLINE(static inline VALUE
vm_opt_aset_with(VALUE recv, VALUE key, VALUE val));
static inline VALUE
vm_opt_aset_with(VALUE recv, VALUE key, VALUE val) {
    if (!(((VALUE)(recv) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(recv) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (((struct RBasic*)(recv))->klass) == rb_cHash &&
 ((__builtin_expect(!!((rb_current_vm()->redefined_flag[(BOP_ASET)]&((1 << 4))) == 0), 1))) &&
 rb_hash_compare_by_id_p(recv) == ((VALUE)RUBY_Qfalse)) {
 return rb_hash_aset(recv, key, val);
    }
    else {
 return ((VALUE)RUBY_Qundef);
    }
}

static VALUE
vm_opt_length(VALUE recv, int bop)
{
    if ((((VALUE)(recv) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(recv) & (VALUE)~((VALUE)RUBY_Qnil)) == 0))) {
 return ((VALUE)RUBY_Qundef);
    }
    else if ((((struct RBasic*)(recv))->klass) == rb_cString &&
      ((__builtin_expect(!!((rb_current_vm()->redefined_flag[(bop)]&((1 << 2))) == 0), 1)))) {
 if (bop == BOP_EMPTY_P) {
     return rb_long2num_inline((!(((struct RBasic*)(recv))->flags & RSTRING_NOEMBED) ? (long)((((struct RBasic*)(recv))->flags >> RSTRING_EMBED_LEN_SHIFT) & (RSTRING_EMBED_LEN_MASK >> RSTRING_EMBED_LEN_SHIFT)) : ((struct RString*)(recv))->as.heap.len));
 }
 else {
     return rb_str_length(recv);
 }
    }
    else if ((((struct RBasic*)(recv))->klass) == rb_cArray &&
      ((__builtin_expect(!!((rb_current_vm()->redefined_flag[(bop)]&((1 << 3))) == 0), 1)))) {
 return rb_long2num_inline(rb_array_len(recv));
    }
    else if ((((struct RBasic*)(recv))->klass) == rb_cHash &&
      ((__builtin_expect(!!((rb_current_vm()->redefined_flag[(bop)]&((1 << 4))) == 0), 1)))) {
 return (((VALUE)(((!(((struct RBasic*)((recv)))->flags&(RHASH_ST_TABLE_FLAG))) ? ((unsigned int)((((struct RBasic*)(recv))->flags & (VALUE)RHASH_AR_TABLE_SIZE_MASK) >> RHASH_AR_TABLE_SIZE_SHIFT)) : ((((struct RHash*)(recv))->as.st)->num_entries))))<<1 | RUBY_FIXNUM_FLAG);
    }
    else {
 return ((VALUE)RUBY_Qundef);
    }
}

static VALUE
vm_opt_empty_p(VALUE recv)
{
    switch (vm_opt_length(recv, BOP_EMPTY_P)) {
      case ((VALUE)RUBY_Qundef): return ((VALUE)RUBY_Qundef);
      case (((VALUE)(0))<<1 | RUBY_FIXNUM_FLAG): return ((VALUE)RUBY_Qtrue);
      default: return ((VALUE)RUBY_Qfalse);
    }
}

VALUE rb_false(VALUE obj);

static VALUE
vm_opt_nil_p(CALL_DATA cd, VALUE recv)
{
    if (recv == ((VALUE)RUBY_Qnil) &&
        ((__builtin_expect(!!((rb_current_vm()->redefined_flag[(BOP_NIL_P)]&((1 << 9))) == 0), 1)))) {
        return ((VALUE)RUBY_Qtrue);
    }
    else if (vm_method_cfunc_is(cd, recv, rb_false)) {
        return ((VALUE)RUBY_Qfalse);
    }
    else {
        return ((VALUE)RUBY_Qundef);
    }
}

static VALUE
fix_succ(VALUE x)
{
    switch (x) {
      case ~0UL:


        return (((VALUE)(0))<<1 | RUBY_FIXNUM_FLAG);
      case ((~0UL)>>(int)(1)):


        return rb_uint2big(1UL << (8 * 8 - 2));
      default:
        return x + 2;
    }
}

static VALUE
vm_opt_succ(VALUE recv)
{
    if ((((int)(long)(recv))&RUBY_FIXNUM_FLAG) &&
 ((__builtin_expect(!!((rb_current_vm()->redefined_flag[(BOP_SUCC)]&((1 << 0))) == 0), 1)))) {
        return fix_succ(recv);
    }
    else if ((((VALUE)(recv) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(recv) & (VALUE)~((VALUE)RUBY_Qnil)) == 0))) {
 return ((VALUE)RUBY_Qundef);
    }
    else if ((((struct RBasic*)(recv))->klass) == rb_cString &&
      ((__builtin_expect(!!((rb_current_vm()->redefined_flag[(BOP_SUCC)]&((1 << 2))) == 0), 1)))) {
 return rb_str_succ(recv);
    }
    else {
 return ((VALUE)RUBY_Qundef);
    }
}
ALWAYS_INLINE(static inline VALUE
vm_opt_not(CALL_DATA cd, VALUE recv));
static inline VALUE
vm_opt_not(CALL_DATA cd, VALUE recv) {
    if (vm_method_cfunc_is(cd, recv, rb_obj_not)) {
 return !(((VALUE)(recv) & (VALUE)~((VALUE)RUBY_Qnil)) == 0) ? ((VALUE)RUBY_Qfalse) : ((VALUE)RUBY_Qtrue);
    }
    else {
 return ((VALUE)RUBY_Qundef);
    }
}

static VALUE
vm_opt_regexpmatch2(VALUE recv, VALUE obj)
{
    if ((((VALUE)(recv) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(recv) & (VALUE)~((VALUE)RUBY_Qnil)) == 0))) {
        return ((VALUE)RUBY_Qundef);
    }
    else if ((((struct RBasic*)(recv))->klass) == rb_cString &&
        rb_class_of((VALUE)(obj)) == rb_cRegexp &&
 ((__builtin_expect(!!((rb_current_vm()->redefined_flag[(BOP_MATCH)]&((1 << 2))) == 0), 1)))) {
 return rb_reg_match(obj, recv);
    }
    else if ((((struct RBasic*)(recv))->klass) == rb_cRegexp &&
        ((__builtin_expect(!!((rb_current_vm()->redefined_flag[(BOP_MATCH)]&((1 << 8))) == 0), 1)))) {
 return rb_reg_match(recv, obj);
    }
    else {
 return ((VALUE)RUBY_Qundef);
    }
}

rb_event_flag_t rb_iseq_event_flags(const rb_iseq_t *iseq, size_t pos);

__attribute__ ((__noinline__)) static void vm_trace(rb_execution_context_t *ec, rb_control_frame_t *reg_cfp, const VALUE *pc);

static inline void
vm_trace_hook(rb_execution_context_t *ec, rb_control_frame_t *reg_cfp, const VALUE *pc,
              rb_event_flag_t pc_events, rb_event_flag_t target_event,
              rb_hook_list_t *global_hooks, rb_hook_list_t *local_hooks, VALUE val)
{
    rb_event_flag_t event = pc_events & target_event;
    VALUE self = (((((reg_cfp)))->self));

    ((void)0);

    if (event & global_hooks->events) {

        reg_cfp->pc++;
        vm_dtrace(event, ec);
        rb_exec_event_hook_orig(ec, global_hooks, event, self, 0, 0, 0 , val, 0);
        reg_cfp->pc--;
    }

    if (local_hooks != ((void*)0)) {
        if (event & local_hooks->events) {

            reg_cfp->pc++;
            rb_exec_event_hook_orig(ec, local_hooks, event, self, 0, 0, 0 , val, 0);
            reg_cfp->pc--;
        }
    }
}






static void
vm_trace(rb_execution_context_t *ec, rb_control_frame_t *reg_cfp, const VALUE *pc)
{
    rb_event_flag_t enabled_flags = ruby_vm_event_flags & (0x0001 | 0x0002 | 0x0004 | 0x0008 | 0x0010| 0x0100| 0x0200| 0x010000| 0x020000);

    if (enabled_flags == 0 && ruby_vm_event_local_num == 0) {
        return;
    }
    else {
 const rb_iseq_t *iseq = reg_cfp->iseq;
 size_t pos = pc - iseq->body->iseq_encoded;
        rb_event_flag_t pc_events = rb_iseq_event_flags(iseq, pos);
        rb_hook_list_t *local_hooks = iseq->aux.exec.local_hooks;
        rb_event_flag_t local_hook_events = local_hooks != ((void*)0) ? local_hooks->events : 0;
        enabled_flags |= local_hook_events;

        ((void)0);

        if ((pc_events & enabled_flags) == 0) {
     return;
        }
        else if (ec->trace_arg != ((void*)0)) {

            return;
        }
        else {
            rb_hook_list_t *global_hooks = rb_vm_global_hooks(ec);

            if (0) {
                fprintf(__stderrp, "vm_trace>>%4d (%4x) - %s:%d %s\n",
                        (int)pos,
                        (int)pc_events,
                        (!(((struct RBasic*)(rb_iseq_path(iseq)))->flags & RSTRING_NOEMBED) ? ((struct RString*)(rb_iseq_path(iseq)))->as.ary : ((struct RString*)(rb_iseq_path(iseq)))->as.heap.ptr),
                        (int)rb_iseq_line_no(iseq, pos),
                        (!(((struct RBasic*)(rb_iseq_label(iseq)))->flags & RSTRING_NOEMBED) ? ((struct RString*)(rb_iseq_label(iseq)))->as.ary : ((struct RString*)(rb_iseq_label(iseq)))->as.heap.ptr));
            }
            ((void)0);
            ((void)0);
            ((void)0);


            do { if ((pc_events & (0x0002 | 0x0008 | 0x0100)) & enabled_flags) { vm_trace_hook(ec, reg_cfp, pc, pc_events, (0x0002 | 0x0008 | 0x0100), global_hooks, local_hooks, (((VALUE)RUBY_Qundef))); } } while (0);
            do { if ((pc_events & (0x0001)) & enabled_flags) { vm_trace_hook(ec, reg_cfp, pc, pc_events, (0x0001), global_hooks, local_hooks, (((VALUE)RUBY_Qundef))); } } while (0);
            do { if ((pc_events & (0x010000)) & enabled_flags) { vm_trace_hook(ec, reg_cfp, pc, pc_events, (0x010000), global_hooks, local_hooks, (((VALUE)RUBY_Qundef))); } } while (0);
            do { if ((pc_events & (0x020000)) & enabled_flags) { vm_trace_hook(ec, reg_cfp, pc, pc_events, (0x020000), global_hooks, local_hooks, (((VALUE)RUBY_Qundef))); } } while (0);
            do { if ((pc_events & (0x0004 | 0x0010 | 0x0200)) & enabled_flags) { vm_trace_hook(ec, reg_cfp, pc, pc_events, (0x0004 | 0x0010 | 0x0200), global_hooks, local_hooks, ((*(((((reg_cfp)->sp)))-(0)-1)))); } } while (0);
        }
    }
}static inline 
void Init_vm_stack_canary(void) { }
static VALUE
builtin_invoker0(rb_execution_context_t *ec, VALUE self, const VALUE *argv, rb_insn_func_t funcptr)
{
    typedef VALUE (*rb_invoke_funcptr0_t)(rb_execution_context_t *ec, VALUE self);
    return (*(rb_invoke_funcptr0_t)funcptr)(ec, self);
}

static VALUE
builtin_invoker1(rb_execution_context_t *ec, VALUE self, const VALUE *argv, rb_insn_func_t funcptr)
{
    typedef VALUE (*rb_invoke_funcptr1_t)(rb_execution_context_t *ec, VALUE self, VALUE v1);
    return (*(rb_invoke_funcptr1_t)funcptr)(ec, self, argv[0]);
}

static VALUE
builtin_invoker2(rb_execution_context_t *ec, VALUE self, const VALUE *argv, rb_insn_func_t funcptr)
{
    typedef VALUE (*rb_invoke_funcptr2_t)(rb_execution_context_t *ec, VALUE self, VALUE v1, VALUE v2);
    return (*(rb_invoke_funcptr2_t)funcptr)(ec, self, argv[0], argv[1]);
}

static VALUE
builtin_invoker3(rb_execution_context_t *ec, VALUE self, const VALUE *argv, rb_insn_func_t funcptr)
{
    typedef VALUE (*rb_invoke_funcptr3_t)(rb_execution_context_t *ec, VALUE self, VALUE v1, VALUE v2, VALUE v3);
    return (*(rb_invoke_funcptr3_t)funcptr)(ec, self, argv[0], argv[1], argv[2]);
}

static VALUE
builtin_invoker4(rb_execution_context_t *ec, VALUE self, const VALUE *argv, rb_insn_func_t funcptr)
{
    typedef VALUE (*rb_invoke_funcptr4_t)(rb_execution_context_t *ec, VALUE self, VALUE v1, VALUE v2, VALUE v3, VALUE v4);
    return (*(rb_invoke_funcptr4_t)funcptr)(ec, self, argv[0], argv[1], argv[2], argv[3]);
}

static VALUE
builtin_invoker5(rb_execution_context_t *ec, VALUE self, const VALUE *argv, rb_insn_func_t funcptr)
{
    typedef VALUE (*rb_invoke_funcptr5_t)(rb_execution_context_t *ec, VALUE self, VALUE v1, VALUE v2, VALUE v3, VALUE v4, VALUE v5);
    return (*(rb_invoke_funcptr5_t)funcptr)(ec, self, argv[0], argv[1], argv[2], argv[3], argv[4]);
}

static VALUE
builtin_invoker6(rb_execution_context_t *ec, VALUE self, const VALUE *argv, rb_insn_func_t funcptr)
{
    typedef VALUE (*rb_invoke_funcptr6_t)(rb_execution_context_t *ec, VALUE self, VALUE v1, VALUE v2, VALUE v3, VALUE v4, VALUE v5, VALUE v6);
    return (*(rb_invoke_funcptr6_t)funcptr)(ec, self, argv[0], argv[1], argv[2], argv[3], argv[4], argv[5]);
}

static VALUE
builtin_invoker7(rb_execution_context_t *ec, VALUE self, const VALUE *argv, rb_insn_func_t funcptr)
{
    typedef VALUE (*rb_invoke_funcptr7_t)(rb_execution_context_t *ec, VALUE self, VALUE v1, VALUE v2, VALUE v3, VALUE v4, VALUE v5, VALUE v6, VALUE v7);
    return (*(rb_invoke_funcptr7_t)funcptr)(ec, self, argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6]);
}

static VALUE
builtin_invoker8(rb_execution_context_t *ec, VALUE self, const VALUE *argv, rb_insn_func_t funcptr)
{
    typedef VALUE (*rb_invoke_funcptr8_t)(rb_execution_context_t *ec, VALUE self, VALUE v1, VALUE v2, VALUE v3, VALUE v4, VALUE v5, VALUE v6, VALUE v7, VALUE v8);
    return (*(rb_invoke_funcptr8_t)funcptr)(ec, self, argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6], argv[7]);
}

static VALUE
builtin_invoker9(rb_execution_context_t *ec, VALUE self, const VALUE *argv, rb_insn_func_t funcptr)
{
    typedef VALUE (*rb_invoke_funcptr9_t)(rb_execution_context_t *ec, VALUE self, VALUE v1, VALUE v2, VALUE v3, VALUE v4, VALUE v5, VALUE v6, VALUE v7, VALUE v8, VALUE v9);
    return (*(rb_invoke_funcptr9_t)funcptr)(ec, self, argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6], argv[7], argv[8]);
}

static VALUE
builtin_invoker10(rb_execution_context_t *ec, VALUE self, const VALUE *argv, rb_insn_func_t funcptr)
{
    typedef VALUE (*rb_invoke_funcptr10_t)(rb_execution_context_t *ec, VALUE self, VALUE v1, VALUE v2, VALUE v3, VALUE v4, VALUE v5, VALUE v6, VALUE v7, VALUE v8, VALUE v9, VALUE v10);
    return (*(rb_invoke_funcptr10_t)funcptr)(ec, self, argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6], argv[7], argv[8], argv[9]);
}

static VALUE
builtin_invoker11(rb_execution_context_t *ec, VALUE self, const VALUE *argv, rb_insn_func_t funcptr)
{
    typedef VALUE (*rb_invoke_funcptr11_t)(rb_execution_context_t *ec, VALUE self, VALUE v1, VALUE v2, VALUE v3, VALUE v4, VALUE v5, VALUE v6, VALUE v7, VALUE v8, VALUE v9, VALUE v10, VALUE v11);
    return (*(rb_invoke_funcptr11_t)funcptr)(ec, self, argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6], argv[7], argv[8], argv[9], argv[10]);
}

static VALUE
builtin_invoker12(rb_execution_context_t *ec, VALUE self, const VALUE *argv, rb_insn_func_t funcptr)
{
    typedef VALUE (*rb_invoke_funcptr12_t)(rb_execution_context_t *ec, VALUE self, VALUE v1, VALUE v2, VALUE v3, VALUE v4, VALUE v5, VALUE v6, VALUE v7, VALUE v8, VALUE v9, VALUE v10, VALUE v11, VALUE v12);
    return (*(rb_invoke_funcptr12_t)funcptr)(ec, self, argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6], argv[7], argv[8], argv[9], argv[10], argv[11]);
}

static VALUE
builtin_invoker13(rb_execution_context_t *ec, VALUE self, const VALUE *argv, rb_insn_func_t funcptr)
{
    typedef VALUE (*rb_invoke_funcptr13_t)(rb_execution_context_t *ec, VALUE self, VALUE v1, VALUE v2, VALUE v3, VALUE v4, VALUE v5, VALUE v6, VALUE v7, VALUE v8, VALUE v9, VALUE v10, VALUE v11, VALUE v12, VALUE v13);
    return (*(rb_invoke_funcptr13_t)funcptr)(ec, self, argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6], argv[7], argv[8], argv[9], argv[10], argv[11], argv[12]);
}

static VALUE
builtin_invoker14(rb_execution_context_t *ec, VALUE self, const VALUE *argv, rb_insn_func_t funcptr)
{
    typedef VALUE (*rb_invoke_funcptr14_t)(rb_execution_context_t *ec, VALUE self, VALUE v1, VALUE v2, VALUE v3, VALUE v4, VALUE v5, VALUE v6, VALUE v7, VALUE v8, VALUE v9, VALUE v10, VALUE v11, VALUE v12, VALUE v13, VALUE v14);
    return (*(rb_invoke_funcptr14_t)funcptr)(ec, self, argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6], argv[7], argv[8], argv[9], argv[10], argv[11], argv[12], argv[13]);
}

static VALUE
builtin_invoker15(rb_execution_context_t *ec, VALUE self, const VALUE *argv, rb_insn_func_t funcptr)
{
    typedef VALUE (*rb_invoke_funcptr15_t)(rb_execution_context_t *ec, VALUE self, VALUE v1, VALUE v2, VALUE v3, VALUE v4, VALUE v5, VALUE v6, VALUE v7, VALUE v8, VALUE v9, VALUE v10, VALUE v11, VALUE v12, VALUE v13, VALUE v14, VALUE v15);
    return (*(rb_invoke_funcptr15_t)funcptr)(ec, self, argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6], argv[7], argv[8], argv[9], argv[10], argv[11], argv[12], argv[13], argv[14]);
}

typedef VALUE (*builtin_invoker)(rb_execution_context_t *ec, VALUE self, const VALUE *argv, rb_insn_func_t funcptr);

static builtin_invoker
lookup_builtin_invoker(int argc)
{
    static const builtin_invoker invokers[] = {
        builtin_invoker0,
        builtin_invoker1,
        builtin_invoker2,
        builtin_invoker3,
        builtin_invoker4,
        builtin_invoker5,
        builtin_invoker6,
        builtin_invoker7,
        builtin_invoker8,
        builtin_invoker9,
        builtin_invoker10,
        builtin_invoker11,
        builtin_invoker12,
        builtin_invoker13,
        builtin_invoker14,
        builtin_invoker15,
    };

    return invokers[argc];
}

static inline VALUE
invoke_bf(rb_execution_context_t *ec, rb_control_frame_t *cfp, const struct rb_builtin_function* bf, const VALUE *argv)
{
    VALUE self = cfp->self;
    return (*lookup_builtin_invoker(bf->argc))(ec, self, argv, (rb_insn_func_t)bf->func_ptr);
}

static VALUE
vm_invoke_builtin(rb_execution_context_t *ec, rb_control_frame_t *cfp, const struct rb_builtin_function* bf, const VALUE *argv)
{
    return invoke_bf(ec, cfp, bf, argv);
}

static VALUE
vm_invoke_builtin_delegate(rb_execution_context_t *ec, rb_control_frame_t *cfp, const struct rb_builtin_function *bf, unsigned int start_index)
{
    if (0) {
        fprintf(__stderrp, "vm_invoke_builtin_delegate: passing -> ");
        for (int i=0; i<bf->argc; i++) {
            fprintf(__stderrp, ":%s ", rb_id2name(cfp->iseq->body->local_table[i+start_index]));
        }
        fprintf(__stderrp, "\n");
        fprintf(__stderrp, "%s %s(%d):%p\n", __func__, bf->name, bf->argc, bf->func_ptr);
    }

    if (bf->argc == 0) {
        return invoke_bf(ec, cfp, bf, ((void*)0));
    }
    else {
        const VALUE *argv = cfp->ep - cfp->iseq->body->local_table_size - ( 3) + 1 + start_index;
        return invoke_bf(ec, cfp, bf, argv);
    }
}static inline 



VALUE
rb_vm_lvar_exposed(rb_execution_context_t *ec, int index)
{
    const rb_control_frame_t *cfp = ec->cfp;
    return cfp->ep[index];
}







struct local_var_list {
    VALUE tbl;
};

static inline VALUE method_missing(VALUE obj, ID id, int argc, const VALUE *argv, enum method_missing_reason call_status, int kw_splat);
static inline VALUE vm_yield_with_cref(rb_execution_context_t *ec, int argc, const VALUE *argv, int kw_splat, const rb_cref_t *cref, int is_lambda);
static inline VALUE vm_yield(rb_execution_context_t *ec, int argc, const VALUE *argv, int kw_splat);
static inline VALUE vm_yield_with_block(rb_execution_context_t *ec, int argc, const VALUE *argv, VALUE block_handler, int kw_splat);
static inline VALUE vm_yield_force_blockarg(rb_execution_context_t *ec, VALUE args);
VALUE rb_vm_exec(rb_execution_context_t *ec, int mjit_enable_p);
static void vm_set_eval_stack(rb_execution_context_t * th, const rb_iseq_t *iseq, const rb_cref_t *cref, const struct rb_block *base_block);
static int vm_collect_local_variables_in_heap(const VALUE *dfp, const struct local_var_list *vars);

static VALUE rb_eUncaughtThrow;
static ID id_result, id_tag, id_value;

typedef enum call_type {
    CALL_PUBLIC,
    CALL_FCALL,
    CALL_VCALL,
    CALL_PUBLIC_KW,
    CALL_FCALL_KW,
    CALL_TYPE_MAX
} call_type;

static VALUE send_internal(int argc, const VALUE *argv, VALUE recv, call_type scope);
static VALUE vm_call0_body(rb_execution_context_t* ec, struct rb_calling_info *calling, struct rb_call_data *cd, const VALUE *argv);
static inline void
stack_check(rb_execution_context_t *ec)
{
    if (!(((ec)->raised_flag & (RAISED_STACKOVERFLOW)) != 0) &&
 rb_ec_stack_check(ec)) {
 ((ec)->raised_flag |= (RAISED_STACKOVERFLOW));
 rb_ec_stack_overflow(ec, 0);
    }
}
static void
raise_method_missing(rb_execution_context_t *ec, int argc, const VALUE *argv, VALUE obj,
       enum method_missing_reason last_call_status)
{
    VALUE exc = rb_eNoMethodError;
    VALUE format = 0;

    if ((__builtin_expect(!!(argc == 0), 0))) {
 rb_raise(rb_eArgError, "no method name given");
    }
    else if ((__builtin_expect(!!(!((((VALUE)(argv[0])&~((~(VALUE)0)<<RUBY_SPECIAL_SHIFT)) == RUBY_SYMBOL_FLAG)||(!(((VALUE)(argv[0]) & RUBY_IMMEDIATE_MASK) || !!(((VALUE)(argv[0]) & (VALUE)~((VALUE)RUBY_Qnil)) == 0)) && (int)(((struct RBasic*)(argv[0]))->flags & RUBY_T_MASK) == (RUBY_T_SYMBOL)))), 0))) {
 const VALUE e = rb_eArgError;
 rb_raise(e, "method name must be a Symbol but %""l""i" "\v"" is given",
   rb_obj_class(argv[0]));
    }

    stack_check(ec);

    if (last_call_status & MISSING_PRIVATE) {
 format = rb_fstring_new(("private method `%s' called for %s%s%s"), (sizeof("private method `%s' called for %s%s%s" "") - 1));
    }
    else if (last_call_status & MISSING_PROTECTED) {
 format = rb_fstring_new(("protected method `%s' called for %s%s%s"), (sizeof("protected method `%s' called for %s%s%s" "") - 1));
    }
    else if (last_call_status & MISSING_VCALL) {
 format = rb_fstring_new(("undefined local variable or method `%s' for %s%s%s"), (sizeof("undefined local variable or method `%s' for %s%s%s" "") - 1));
 exc = rb_eNameError;
    }
    else if (last_call_status & MISSING_SUPER) {
 format = rb_fstring_new(("super: no superclass method `%s' for %s%s%s"), (sizeof("super: no superclass method `%s' for %s%s%s" "") - 1));
    }

    {
 exc = rb_make_no_method_exception(exc, format, obj, argc, argv,
       last_call_status & (MISSING_FCALL|MISSING_VCALL));
 if (!(last_call_status & MISSING_MISSING)) {
     rb_vm_pop_cfunc_frame();
 }
 rb_exc_raise(exc);
    }
}

static void
vm_raise_method_missing(rb_execution_context_t *ec, int argc, const VALUE *argv,
   VALUE obj, int call_status)
{
    vm_passed_block_handler_set(ec, 0);
    raise_method_missing(ec, argc, argv, obj, call_status | MISSING_MISSING);
}

static inline VALUE
method_missing(VALUE obj, ID id, int argc, const VALUE *argv, enum method_missing_reason call_status, int kw_splat)
{
    VALUE *nargv, result, work, klass;
    rb_execution_context_t *ec = rb_current_execution_context();
    VALUE block_handler = vm_passed_block_handler(ec);
    const rb_callable_method_entry_t *me;

    ec->method_missing_reason = call_status;

    if (id == idMethodMissing) {
      missing:
 raise_method_missing(ec, argc, argv, obj, call_status | MISSING_MISSING);
    }

    nargv = ((VALUE*)(((size_t)(argc + 1) < 1024 / sizeof(VALUE)) ? ((work) = 0, __builtin_alloca((size_t)(argc + 1) * sizeof(VALUE))) : rb_alloc_tmp_buffer2(&(work), (long)(argc + 1), sizeof(VALUE))));
    nargv[0] = (rb_id2sym(id));







    __builtin___memcpy_chk ((nargv + 1), (argv), sizeof(VALUE)*(size_t)(argc), __builtin_object_size ((nargv + 1), 0));
    ++argc;
    argv = nargv;

    klass = rb_class_of((VALUE)(obj));
    if (!klass) goto missing;
    me = rb_callable_method_entry(klass, idMethodMissing);
    if (!me || (int) (((me)->flags & (((VALUE)RUBY_FL_USER6) )) >> ((((VALUE)RUBY_FL_USHIFT) + 4)+2))) goto missing;
    vm_passed_block_handler_set(ec, block_handler);
    result = rb_vm_call_kw(ec, obj, idMethodMissing, argc, argv, me, kw_splat);
    if (work) rb_free_tmp_buffer(&(work));
    return result;
}
static rb_control_frame_t *
vm_get_ruby_level_caller_cfp(const rb_execution_context_t *ec, const rb_control_frame_t *cfp)
{
    if (VM_FRAME_RUBYFRAME_P(cfp)) {
 return (rb_control_frame_t *)cfp;
    }

    cfp = ((cfp)+1);

    while (!RUBY_VM_CONTROL_FRAME_STACK_OVERFLOW_P(ec, cfp)) {
 if (VM_FRAME_RUBYFRAME_P(cfp)) {
     return (rb_control_frame_t *)cfp;
 }

 if (VM_ENV_FLAGS(cfp->ep, VM_FRAME_FLAG_PASSED) == 0) {
     break;
 }
 cfp = ((cfp)+1);
    }
    return 0;
}

static void
rb_vm_pop_cfunc_frame(void)
{
    rb_execution_context_t *ec = rb_current_execution_context();
    rb_control_frame_t *cfp = ec->cfp;
    const rb_callable_method_entry_t *me = rb_vm_frame_method_entry(cfp);

    do { const rb_event_flag_t flag_arg_ = (0x0040); rb_hook_list_t *hooks_arg_ = (rb_vm_global_hooks(ec)); if ((__builtin_expect(!!((hooks_arg_)->events & (flag_arg_)), 0))) { rb_exec_event_hook_orig(ec, hooks_arg_, flag_arg_, cfp->self, me->def->original_id, me->called_id, me->owner, ((VALUE)RUBY_Qnil), 0); } } while (0);
    do { if ((__builtin_expect(!!(0), 0))) { struct ruby_dtrace_method_hook_args args; if (rb_dtrace_setup(ec, me->owner, me->def->original_id, &args)) { do {} while (0); } } } while (0);
    vm_pop_frame(ec, cfp, cfp->ep);
}








static VALUE
vm_call_iseq_setup_normal_0start_0params_0locals(rb_execution_context_t *ec, rb_control_frame_t *cfp, struct rb_calling_info *calling, struct rb_call_data *cd)
{
    ((void)0);
    return vm_call_iseq_setup_normal(ec, cfp, calling, cd->cc.me, 0, 0, 0);
}

static VALUE
vm_call_iseq_setup_normal_0start_0params_1locals(rb_execution_context_t *ec, rb_control_frame_t *cfp, struct rb_calling_info *calling, struct rb_call_data *cd)
{
    ((void)0);
    return vm_call_iseq_setup_normal(ec, cfp, calling, cd->cc.me, 0, 0, 1);
}

static VALUE
vm_call_iseq_setup_normal_0start_0params_2locals(rb_execution_context_t *ec, rb_control_frame_t *cfp, struct rb_calling_info *calling, struct rb_call_data *cd)
{
    ((void)0);
    return vm_call_iseq_setup_normal(ec, cfp, calling, cd->cc.me, 0, 0, 2);
}

static VALUE
vm_call_iseq_setup_normal_0start_0params_3locals(rb_execution_context_t *ec, rb_control_frame_t *cfp, struct rb_calling_info *calling, struct rb_call_data *cd)
{
    ((void)0);
    return vm_call_iseq_setup_normal(ec, cfp, calling, cd->cc.me, 0, 0, 3);
}

static VALUE
vm_call_iseq_setup_normal_0start_0params_4locals(rb_execution_context_t *ec, rb_control_frame_t *cfp, struct rb_calling_info *calling, struct rb_call_data *cd)
{
    ((void)0);
    return vm_call_iseq_setup_normal(ec, cfp, calling, cd->cc.me, 0, 0, 4);
}

static VALUE
vm_call_iseq_setup_normal_0start_0params_5locals(rb_execution_context_t *ec, rb_control_frame_t *cfp, struct rb_calling_info *calling, struct rb_call_data *cd)
{
    ((void)0);
    return vm_call_iseq_setup_normal(ec, cfp, calling, cd->cc.me, 0, 0, 5);
}

static VALUE
vm_call_iseq_setup_normal_0start_1params_0locals(rb_execution_context_t *ec, rb_control_frame_t *cfp, struct rb_calling_info *calling, struct rb_call_data *cd)
{
    ((void)0);
    return vm_call_iseq_setup_normal(ec, cfp, calling, cd->cc.me, 0, 1, 0);
}

static VALUE
vm_call_iseq_setup_normal_0start_1params_1locals(rb_execution_context_t *ec, rb_control_frame_t *cfp, struct rb_calling_info *calling, struct rb_call_data *cd)
{
    ((void)0);
    return vm_call_iseq_setup_normal(ec, cfp, calling, cd->cc.me, 0, 1, 1);
}

static VALUE
vm_call_iseq_setup_normal_0start_1params_2locals(rb_execution_context_t *ec, rb_control_frame_t *cfp, struct rb_calling_info *calling, struct rb_call_data *cd)
{
    ((void)0);
    return vm_call_iseq_setup_normal(ec, cfp, calling, cd->cc.me, 0, 1, 2);
}

static VALUE
vm_call_iseq_setup_normal_0start_1params_3locals(rb_execution_context_t *ec, rb_control_frame_t *cfp, struct rb_calling_info *calling, struct rb_call_data *cd)
{
    ((void)0);
    return vm_call_iseq_setup_normal(ec, cfp, calling, cd->cc.me, 0, 1, 3);
}

static VALUE
vm_call_iseq_setup_normal_0start_1params_4locals(rb_execution_context_t *ec, rb_control_frame_t *cfp, struct rb_calling_info *calling, struct rb_call_data *cd)
{
    ((void)0);
    return vm_call_iseq_setup_normal(ec, cfp, calling, cd->cc.me, 0, 1, 4);
}

static VALUE
vm_call_iseq_setup_normal_0start_1params_5locals(rb_execution_context_t *ec, rb_control_frame_t *cfp, struct rb_calling_info *calling, struct rb_call_data *cd)
{
    ((void)0);
    return vm_call_iseq_setup_normal(ec, cfp, calling, cd->cc.me, 0, 1, 5);
}

static VALUE
vm_call_iseq_setup_normal_0start_2params_0locals(rb_execution_context_t *ec, rb_control_frame_t *cfp, struct rb_calling_info *calling, struct rb_call_data *cd)
{
    ((void)0);
    return vm_call_iseq_setup_normal(ec, cfp, calling, cd->cc.me, 0, 2, 0);
}

static VALUE
vm_call_iseq_setup_normal_0start_2params_1locals(rb_execution_context_t *ec, rb_control_frame_t *cfp, struct rb_calling_info *calling, struct rb_call_data *cd)
{
    ((void)0);
    return vm_call_iseq_setup_normal(ec, cfp, calling, cd->cc.me, 0, 2, 1);
}

static VALUE
vm_call_iseq_setup_normal_0start_2params_2locals(rb_execution_context_t *ec, rb_control_frame_t *cfp, struct rb_calling_info *calling, struct rb_call_data *cd)
{
    ((void)0);
    return vm_call_iseq_setup_normal(ec, cfp, calling, cd->cc.me, 0, 2, 2);
}

static VALUE
vm_call_iseq_setup_normal_0start_2params_3locals(rb_execution_context_t *ec, rb_control_frame_t *cfp, struct rb_calling_info *calling, struct rb_call_data *cd)
{
    ((void)0);
    return vm_call_iseq_setup_normal(ec, cfp, calling, cd->cc.me, 0, 2, 3);
}

static VALUE
vm_call_iseq_setup_normal_0start_2params_4locals(rb_execution_context_t *ec, rb_control_frame_t *cfp, struct rb_calling_info *calling, struct rb_call_data *cd)
{
    ((void)0);
    return vm_call_iseq_setup_normal(ec, cfp, calling, cd->cc.me, 0, 2, 4);
}

static VALUE
vm_call_iseq_setup_normal_0start_2params_5locals(rb_execution_context_t *ec, rb_control_frame_t *cfp, struct rb_calling_info *calling, struct rb_call_data *cd)
{
    ((void)0);
    return vm_call_iseq_setup_normal(ec, cfp, calling, cd->cc.me, 0, 2, 5);
}

static VALUE
vm_call_iseq_setup_normal_0start_3params_0locals(rb_execution_context_t *ec, rb_control_frame_t *cfp, struct rb_calling_info *calling, struct rb_call_data *cd)
{
    ((void)0);
    return vm_call_iseq_setup_normal(ec, cfp, calling, cd->cc.me, 0, 3, 0);
}

static VALUE
vm_call_iseq_setup_normal_0start_3params_1locals(rb_execution_context_t *ec, rb_control_frame_t *cfp, struct rb_calling_info *calling, struct rb_call_data *cd)
{
    ((void)0);
    return vm_call_iseq_setup_normal(ec, cfp, calling, cd->cc.me, 0, 3, 1);
}

static VALUE
vm_call_iseq_setup_normal_0start_3params_2locals(rb_execution_context_t *ec, rb_control_frame_t *cfp, struct rb_calling_info *calling, struct rb_call_data *cd)
{
    ((void)0);
    return vm_call_iseq_setup_normal(ec, cfp, calling, cd->cc.me, 0, 3, 2);
}

static VALUE
vm_call_iseq_setup_normal_0start_3params_3locals(rb_execution_context_t *ec, rb_control_frame_t *cfp, struct rb_calling_info *calling, struct rb_call_data *cd)
{
    ((void)0);
    return vm_call_iseq_setup_normal(ec, cfp, calling, cd->cc.me, 0, 3, 3);
}

static VALUE
vm_call_iseq_setup_normal_0start_3params_4locals(rb_execution_context_t *ec, rb_control_frame_t *cfp, struct rb_calling_info *calling, struct rb_call_data *cd)
{
    ((void)0);
    return vm_call_iseq_setup_normal(ec, cfp, calling, cd->cc.me, 0, 3, 4);
}

static VALUE
vm_call_iseq_setup_normal_0start_3params_5locals(rb_execution_context_t *ec, rb_control_frame_t *cfp, struct rb_calling_info *calling, struct rb_call_data *cd)
{
    ((void)0);
    return vm_call_iseq_setup_normal(ec, cfp, calling, cd->cc.me, 0, 3, 5);
}


static const vm_call_handler vm_call_iseq_handlers[][6] = {
{vm_call_iseq_setup_normal_0start_0params_0locals,
 vm_call_iseq_setup_normal_0start_0params_1locals,
 vm_call_iseq_setup_normal_0start_0params_2locals,
 vm_call_iseq_setup_normal_0start_0params_3locals,
 vm_call_iseq_setup_normal_0start_0params_4locals,
 vm_call_iseq_setup_normal_0start_0params_5locals},
{vm_call_iseq_setup_normal_0start_1params_0locals,
 vm_call_iseq_setup_normal_0start_1params_1locals,
 vm_call_iseq_setup_normal_0start_1params_2locals,
 vm_call_iseq_setup_normal_0start_1params_3locals,
 vm_call_iseq_setup_normal_0start_1params_4locals,
 vm_call_iseq_setup_normal_0start_1params_5locals},
{vm_call_iseq_setup_normal_0start_2params_0locals,
 vm_call_iseq_setup_normal_0start_2params_1locals,
 vm_call_iseq_setup_normal_0start_2params_2locals,
 vm_call_iseq_setup_normal_0start_2params_3locals,
 vm_call_iseq_setup_normal_0start_2params_4locals,
 vm_call_iseq_setup_normal_0start_2params_5locals},
{vm_call_iseq_setup_normal_0start_3params_0locals,
 vm_call_iseq_setup_normal_0start_3params_1locals,
 vm_call_iseq_setup_normal_0start_3params_2locals,
 vm_call_iseq_setup_normal_0start_3params_3locals,
 vm_call_iseq_setup_normal_0start_3params_4locals,
 vm_call_iseq_setup_normal_0start_3params_5locals}
};

static inline vm_call_handler
vm_call_iseq_setup_func(const struct rb_call_info *ci, const int param_size, const int local_size)
{
    if ((__builtin_expect(!!(ci->flag & (0x01 << VM_CALL_TAILCALL_bit)), 0))) {
 return &vm_call_iseq_setup_tailcall_0start;
    }
    else if (0) {
        return &vm_call_iseq_setup_normal_0start;
    }
    else {
 if (param_size <= 3 &&
     local_size <= 5) {
     ((void)0);
     return vm_call_iseq_handlers[param_size][local_size];
 }
 return &vm_call_iseq_setup_normal_0start;
    }
}

#define MJIT_HEADER 1
#define _FORTIFY_SOURCE 2
#define RUBY_EXPORT 1
#define CANONICALIZATION_FOR_MATHN 1
#define _XOPEN_SOURCE 1
#define _DARWIN_C_SOURCE 1
#define _DARWIN_UNLIMITED_SELECT 1
#define _REENTRANT 1
#define RUBY_INTERNAL_H 1
#define RUBY_H 1
#define HAVE_RUBY_DEFINES_H 1
#define HAVE_RUBY_ENCODING_H 1
#define HAVE_RUBY_INTERN_H 1
#define HAVE_RUBY_IO_H 1
#define HAVE_RUBY_MISSING_H 1
#define HAVE_RUBY_ONIGURUMA_H 1
#define HAVE_RUBY_RE_H 1
#define HAVE_RUBY_REGEX_H 1
#define HAVE_RUBY_RUBY_H 1
#define HAVE_RUBY_ST_H 1
#define HAVE_RUBY_THREAD_H 1
#define HAVE_RUBY_UTIL_H 1
#define HAVE_RUBY_VERSION_H 1
#define HAVE_RUBY_VM_H 1
#define RUBY_RUBY_H 1
#define INCLUDE_RUBY_CONFIG_H 1
#define STDC_HEADERS 1
#define HAVE_SYS_TYPES_H 1
#define HAVE_SYS_STAT_H 1
#define HAVE_STDLIB_H 1
#define HAVE_STRING_H 1
#define HAVE_MEMORY_H 1
#define HAVE_STRINGS_H 1
#define HAVE_INTTYPES_H 1
#define HAVE_STDINT_H 1
#define HAVE_UNISTD_H 1
#define __EXTENSIONS__ 1
#define _ALL_SOURCE 1
#define _GNU_SOURCE 1
#define _POSIX_PTHREAD_SEMANTICS 1
#define _TANDEM_SOURCE 1
#define RUBY_SYMBOL_EXPORT_BEGIN _Pragma("GCC visibility push(default)")
#define RUBY_SYMBOL_EXPORT_END _Pragma("GCC visibility pop")
#define HAVE_STMT_AND_DECL_IN_EXPR 1
#define BROKEN_CRYPT 1
#define HAVE_CRT_EXTERNS_H 1
#define HAVE_LIBDL 1
#define HAVE_DIRENT_H 1
#define HAVE__BOOL 1
#define HAVE_STDBOOL_H 1
#define HAVE_SYS_WAIT_H 1
#define HAVE_COPYFILE_H 1
#define HAVE_GRP_H 1
#define HAVE_FCNTL_H 1
#define HAVE_FLOAT_H 1
#define HAVE_LANGINFO_H 1
#define HAVE_LIMITS_H 1
#define HAVE_LOCALE_H 1
#define HAVE_MALLOC_MALLOC_H 1
#define HAVE_PWD_H 1
#define HAVE_SANITIZER_ASAN_INTERFACE_H 1
#define HAVE_SANITIZER_MSAN_INTERFACE_H 1
#define HAVE_STDALIGN_H 1
#define HAVE_SYS_ATTR_H 1
#define HAVE_SYS_FCNTL_H 1
#define HAVE_SYS_FILE_H 1
#define HAVE_SYS_IOCTL_H 1
#define HAVE_SYS_PARAM_H 1
#define HAVE_SYS_RESOURCE_H 1
#define HAVE_SYS_SELECT_H 1
#define HAVE_SYS_SOCKET_H 1
#define HAVE_SYS_TIME_H 1
#define HAVE_SYS_TIMES_H 1
#define HAVE_SYS_UIO_H 1
#define HAVE_TIME_H 1
#define HAVE_UCONTEXT_H 1
#define HAVE_UTIME_H 1
#define HAVE_TYPEOF 1
#define restrict __restrict
#define HAVE_LONG_LONG 1
#define HAVE_OFF_T 1
#define SIZEOF_INT 4
#define SIZEOF_SHORT 2
#define SIZEOF_LONG 8
#define SIZEOF_LONG_LONG 8
#define SIZEOF___INT64 0
#define SIZEOF___INT128 16
#define SIZEOF_OFF_T 8
#define SIZEOF_VOIDP 8
#define SIZEOF_FLOAT 4
#define SIZEOF_DOUBLE 8
#define SIZEOF_TIME_T 8
#define SIZEOF_CLOCK_T 8
#define PACKED_STRUCT(x) x __attribute__((packed))
#define USE_UNALIGNED_MEMBER_ACCESS 1
#define PRI_LL_PREFIX "ll"
#define HAVE_PID_T 1
#define rb_pid_t pid_t
#define SIGNEDNESS_OF_PID_T -1
#define PIDT2NUM(v) INT2NUM(v)
#define NUM2PIDT(v) NUM2INT(v)
#define PRI_PIDT_PREFIX PRI_INT_PREFIX
#define HAVE_UID_T 1
#define rb_uid_t uid_t
#define SIGNEDNESS_OF_UID_T +1
#define UIDT2NUM(v) UINT2NUM(v)
#define NUM2UIDT(v) NUM2UINT(v)
#define PRI_UIDT_PREFIX PRI_INT_PREFIX
#define HAVE_GID_T 1
#define rb_gid_t gid_t
#define SIGNEDNESS_OF_GID_T +1
#define GIDT2NUM(v) UINT2NUM(v)
#define NUM2GIDT(v) NUM2UINT(v)
#define PRI_GIDT_PREFIX PRI_INT_PREFIX
#define HAVE_TIME_T 1
#define rb_time_t time_t
#define SIGNEDNESS_OF_TIME_T -1
#define TIMET2NUM(v) LONG2NUM(v)
#define NUM2TIMET(v) NUM2LONG(v)
#define PRI_TIMET_PREFIX PRI_LONG_PREFIX
#define HAVE_DEV_T 1
#define rb_dev_t dev_t
#define SIGNEDNESS_OF_DEV_T -1
#define DEVT2NUM(v) INT2NUM(v)
#define NUM2DEVT(v) NUM2INT(v)
#define PRI_DEVT_PREFIX PRI_INT_PREFIX
#define HAVE_MODE_T 1
#define rb_mode_t mode_t
#define SIGNEDNESS_OF_MODE_T +1
#define MODET2NUM(v) USHORT2NUM(v)
#define NUM2MODET(v) NUM2USHORT(v)
#define PRI_MODET_PREFIX PRI_SHORT_PREFIX
#define HAVE_RLIM_T 1
#define rb_rlim_t rlim_t
#define SIGNEDNESS_OF_RLIM_T +1
#define RLIM2NUM(v) ULL2NUM(v)
#define NUM2RLIM(v) NUM2ULL(v)
#define PRI_RLIM_PREFIX PRI_LL_PREFIX
#define HAVE_OFF_T 1
#define rb_off_t off_t
#define SIGNEDNESS_OF_OFF_T -1
#define OFFT2NUM(v) LL2NUM(v)
#define NUM2OFFT(v) NUM2LL(v)
#define PRI_OFFT_PREFIX PRI_LL_PREFIX
#define HAVE_CLOCKID_T 1
#define rb_clockid_t clockid_t
#define SIGNEDNESS_OF_CLOCKID_T +1
#define CLOCKID2NUM(v) UINT2NUM(v)
#define NUM2CLOCKID(v) NUM2UINT(v)
#define PRI_CLOCKID_PREFIX PRI_INT_PREFIX
#define HAVE_PROTOTYPES 1
#define TOKEN_PASTE(x,y) x##y
#define STRINGIZE(expr) STRINGIZE0(expr)
#define HAVE_STDARG_PROTOTYPES 1
#define HAVE_VA_ARGS_MACRO 1
#define RUBY_ALIGNAS(x) __attribute__((__aligned__(x)))
#define RUBY_ALIGNOF alignof
#define CONSTFUNC(x) __attribute__ ((__const__)) x
#define PUREFUNC(x) __attribute__ ((__pure__)) x
#define NORETURN(x) __attribute__ ((__noreturn__)) x
#define DEPRECATED(x) __attribute__ ((__deprecated__)) x
#define DEPRECATED_BY(n,x) __attribute__ ((__deprecated__("by "#n))) x
#define DEPRECATED_TYPE(mesg,x) x __attribute__ ((__deprecated__ mesg))
#define NOINLINE(x) __attribute__ ((__noinline__)) x
#define NO_SANITIZE(san,x) __attribute__ ((__no_sanitize__(san))) x
#define NO_SANITIZE_ADDRESS(x) __attribute__ ((__no_sanitize_address__)) x
#define NO_ADDRESS_SAFETY_ANALYSIS(x) __attribute__ ((__no_address_safety_analysis__)) x
#define WARN_UNUSED_RESULT(x) __attribute__ ((__warn_unused_result__)) x
#define MAYBE_UNUSED(x) __attribute__ ((__unused__)) x
#define WEAK(x) __attribute__ ((__weak__)) x
#define HAVE_FUNC_WEAK 1
#define RUBY_CXX_DEPRECATED(msg) __attribute__((__deprecated__(msg)))
#define FUNC_CDECL(x) __attribute__ ((__cdecl__)) x
#define HAVE_GCC_ATOMIC_BUILTINS 1
#define HAVE_GCC_SYNC_BUILTINS 1
#define UNREACHABLE __builtin_unreachable()
#define RUBY_FUNC_EXPORTED __attribute__ ((__visibility__("default"))) extern
#define RUBY_FUNC_NONNULL(n,x) __attribute__ ((__nonnull__(n))) x
#define RUBY_FUNCTION_NAME_STRING __func__
#define ENUM_OVER_INT 1
#define HAVE_DECL_SYS_NERR 1
#define HAVE_DECL_GETENV 1
#define SIZEOF_SIZE_T 8
#define SIZEOF_PTRDIFF_T 8
#define PRI_SIZE_PREFIX "z"
#define PRI_PTRDIFF_PREFIX "t"
#define HAVE_STRUCT_STAT_ST_BLKSIZE 1
#define HAVE_ST_BLKSIZE 1
#define HAVE_STRUCT_STAT_ST_BLOCKS 1
#define HAVE_ST_BLOCKS 1
#define HAVE_STRUCT_STAT_ST_RDEV 1
#define HAVE_ST_RDEV 1
#define SIZEOF_STRUCT_STAT_ST_SIZE SIZEOF_OFF_T
#define SIZEOF_STRUCT_STAT_ST_BLOCKS SIZEOF_OFF_T
#define SIZEOF_STRUCT_STAT_ST_INO SIZEOF_LONG
#define HAVE_STRUCT_STAT_ST_ATIMESPEC 1
#define HAVE_STRUCT_STAT_ST_MTIMESPEC 1
#define HAVE_STRUCT_STAT_ST_CTIMESPEC 1
#define HAVE_STRUCT_STAT_ST_BIRTHTIMESPEC 1
#define HAVE_STRUCT_TIMEVAL 1
#define SIZEOF_STRUCT_TIMEVAL_TV_SEC SIZEOF_TIME_T
#define HAVE_STRUCT_TIMESPEC 1
#define HAVE_STRUCT_TIMEZONE 1
#define HAVE_RB_FD_INIT 1
#define HAVE_INT8_T 1
#define SIZEOF_INT8_T 1
#define HAVE_UINT8_T 1
#define SIZEOF_UINT8_T 1
#define HAVE_INT16_T 1
#define SIZEOF_INT16_T 2
#define HAVE_UINT16_T 1
#define SIZEOF_UINT16_T 2
#define HAVE_INT32_T 1
#define SIZEOF_INT32_T 4
#define HAVE_UINT32_T 1
#define SIZEOF_UINT32_T 4
#define HAVE_INT64_T 1
#define SIZEOF_INT64_T 8
#define HAVE_UINT64_T 1
#define SIZEOF_UINT64_T 8
#define HAVE_INT128_T 1
#define int128_t __int128
#define SIZEOF_INT128_T SIZEOF___INT128
#define HAVE_UINT128_T 1
#define uint128_t unsigned __int128
#define SIZEOF_UINT128_T SIZEOF___INT128
#define HAVE_INTPTR_T 1
#define SIZEOF_INTPTR_T 8
#define HAVE_UINTPTR_T 1
#define SIZEOF_UINTPTR_T 8
#define PRI_PTR_PREFIX "l"
#define HAVE_SSIZE_T 1
#define SIZEOF_SSIZE_T 8
#define PRI_64_PREFIX "ll"
#define GETGROUPS_T gid_t
#define RETSIGTYPE void
#define HAVE_ALLOCA_H 1
#define HAVE_ALLOCA 1
#define HAVE_ACOSH 1
#define HAVE_CBRT 1
#define HAVE_CRYPT 1
#define HAVE_DUP2 1
#define HAVE_ERF 1
#define HAVE_FFS 1
#define HAVE_FLOCK 1
#define HAVE_HYPOT 1
#define HAVE_LGAMMA_R 1
#define HAVE_MEMMOVE 1
#define HAVE_NAN 1
#define HAVE_NEXTAFTER 1
#define HAVE_STRCHR 1
#define HAVE_STRERROR 1
#define HAVE_STRLCAT 1
#define HAVE_STRLCPY 1
#define HAVE_STRSTR 1
#define HAVE_TGAMMA 1
#define HAVE_ISINF 1
#define HAVE_ISNAN 1
#define SPT_TYPE SPT_REUSEARGV
#define HAVE_SIGNBIT 1
#define HAVE_FORK 1
#define vfork fork
#define HAVE_WORKING_FORK 1
#define HAVE__LONGJMP 1
#define HAVE_ARC4RANDOM_BUF 1
#define HAVE_ATAN2L 1
#define HAVE_ATAN2F 1
#define HAVE_CHROOT 1
#define HAVE_CLOCK_GETTIME 1
#define HAVE_COSH 1
#define HAVE_DIRFD 1
#define HAVE_DLOPEN 1
#define HAVE_DLADDR 1
#define HAVE_DUP 1
#define HAVE_ENDGRENT 1
#define HAVE_FCOPYFILE 1
#define HAVE_FCHMOD 1
#define HAVE_FCHOWN 1
#define HAVE_FCNTL 1
#define HAVE_FDOPENDIR 1
#define HAVE_FGETATTRLIST 1
#define HAVE_FMOD 1
#define HAVE_FSTATAT 1
#define HAVE_FSYNC 1
#define HAVE_FTRUNCATE 1
#define HAVE_GETATTRLIST 1
#define HAVE_GETCWD 1
#define HAVE_GETGRNAM 1
#define HAVE_GETGRNAM_R 1
#define HAVE_GETGROUPS 1
#define HAVE_GETPGID 1
#define HAVE_GETPGRP 1
#define HAVE_GETPRIORITY 1
#define HAVE_GETPWNAM_R 1
#define HAVE_GETRLIMIT 1
#define HAVE_GETSID 1
#define HAVE_GETTIMEOFDAY 1
#define HAVE_GMTIME_R 1
#define HAVE_GRANTPT 1
#define HAVE_INITGROUPS 1
#define HAVE_IOCTL 1
#define HAVE_ISSETUGID 1
#define HAVE_KILLPG 1
#define HAVE_LCHMOD 1
#define HAVE_LCHOWN 1
#define HAVE_LINK 1
#define HAVE_LLABS 1
#define HAVE_LOCKF 1
#define HAVE_LOG2 1
#define HAVE_LSTAT 1
#define HAVE_LUTIMES 1
#define HAVE_MALLOC_SIZE 1
#define HAVE_MBLEN 1
#define HAVE_MEMSET_S 1
#define HAVE_WRITEV 1
#define HAVE_MEMMEM 1
#define HAVE_MKFIFO 1
#define HAVE_MKNOD 1
#define HAVE_MKTIME 1
#define HAVE_OPENAT 1
#define HAVE_POLL 1
#define HAVE_POSIX_MEMALIGN 1
#define HAVE_PREAD 1
#define HAVE_PWRITE 1
#define HAVE_QSORT_R 1
#define HAVE_READLINK 1
#define HAVE_REALPATH 1
#define HAVE_ROUND 1
#define HAVE_SEEKDIR 1
#define HAVE_SENDFILE 1
#define HAVE_SETEGID 1
#define HAVE_SETENV 1
#define HAVE_SETEUID 1
#define HAVE_SETGID 1
#define HAVE_SETGROUPS 1
#define HAVE_SETPGID 1
#define HAVE_SETPGRP 1
#define HAVE_SETREGID 1
#define HAVE_SETREUID 1
#define HAVE_SETRGID 1
#define HAVE_SETRLIMIT 1
#define HAVE_SETRUID 1
#define HAVE_SETSID 1
#define HAVE_SETUID 1
#define HAVE_SHUTDOWN 1
#define HAVE_SIGACTION 1
#define HAVE_SIGALTSTACK 1
#define HAVE_SIGPROCMASK 1
#define HAVE_SINH 1
#define HAVE_SYMLINK 1
#define HAVE_SYSCONF 1
#define HAVE_TANH 1
#define HAVE_TELLDIR 1
#define HAVE_TIMEGM 1
#define HAVE_TIMES 1
#define HAVE_TRUNCATE 1
#define HAVE_UNSETENV 1
#define HAVE_UTIMENSAT 1
#define HAVE_UTIMES 1
#define HAVE_WAIT4 1
#define HAVE_WAITPID 1
#define __STDC_WANT_LIB_EXT1__ 1
#define HAVE_BUILTIN___BUILTIN_ALLOCA_WITH_ALIGN 1
#define HAVE_BUILTIN___BUILTIN_ASSUME_ALIGNED 1
#define HAVE_BUILTIN___BUILTIN_BSWAP16 1
#define HAVE_BUILTIN___BUILTIN_BSWAP32 1
#define HAVE_BUILTIN___BUILTIN_BSWAP64 1
#define HAVE_BUILTIN___BUILTIN_POPCOUNT 1
#define HAVE_BUILTIN___BUILTIN_POPCOUNTLL 1
#define HAVE_BUILTIN___BUILTIN_CLZ 1
#define HAVE_BUILTIN___BUILTIN_CLZL 1
#define HAVE_BUILTIN___BUILTIN_CLZLL 1
#define HAVE_BUILTIN___BUILTIN_CTZ 1
#define HAVE_BUILTIN___BUILTIN_CTZLL 1
#define HAVE_BUILTIN___BUILTIN_ADD_OVERFLOW 1
#define HAVE_BUILTIN___BUILTIN_SUB_OVERFLOW 1
#define HAVE_BUILTIN___BUILTIN_MUL_OVERFLOW 1
#define HAVE_BUILTIN___BUILTIN_CONSTANT_P 1
#define HAVE_BUILTIN___BUILTIN_CHOOSE_EXPR 1
#define HAVE_BUILTIN___BUILTIN_CHOOSE_EXPR_CONSTANT_P 1
#define HAVE_BUILTIN___BUILTIN_TYPES_COMPATIBLE_P 1
#define HAVE_BUILTIN___BUILTIN_TRAP 1
#define HAVE_BSD_QSORT_R 1
#define ATAN2_INF_C99 1
#define HAVE_CLOCK_GETRES 1
#define HAVE_STRUCT_TM_TM_ZONE 1
#define HAVE_TM_ZONE 1
#define HAVE_STRUCT_TM_TM_GMTOFF 1
#define HAVE_DAYLIGHT 1
#define NEGATIVE_TIME_T 1
#define POSIX_SIGNAL 1
#define HAVE_SIG_T 1
#define RSHIFT(x,y) ((x)>>(int)(y))
#define HAVE__SC_CLK_TCK 1
#define STACK_GROW_DIRECTION -1
#define COROUTINE_H "coroutine/arm64/Context.h"
#define _REENTRANT 1
#define _THREAD_SAFE 1
#define HAVE_LIBPTHREAD 1
#define HAVE_SCHED_YIELD 1
#define HAVE_PTHREAD_ATTR_SETINHERITSCHED 1
#define HAVE_PTHREAD_ATTR_GETSTACK 1
#define HAVE_PTHREAD_ATTR_GETGUARDSIZE 1
#define HAVE_PTHREAD_GET_STACKADDR_NP 1
#define HAVE_PTHREAD_GET_STACKSIZE_NP 1
#define HAVE_PTHREAD_SIGMASK 1
#define HAVE_PTHREAD_SETNAME_NP 1
#define SET_CURRENT_THREAD_NAME(name) pthread_setname_np(name)
#define DEFINE_MCONTEXT_PTR(mc,uc) mcontext_t mc = (uc)->uc_mcontext
#define HAVE_MACH_O_LOADER_H 1
#define HAVE_LIBPROC_H 1
#define HAVE_EXECINFO_H 1
#define HAVE_LIBUNWIND_H 1
#define HAVE_BACKTRACE 1
#define BROKEN_BACKTRACE 1
#define DLEXT_MAXLEN 7
#define DLEXT ".bundle"
#define EXTSTATIC 1
#define LIBDIR_BASENAME "lib"
#define HAVE__SETJMP 1
#define HAVE_SIGSETJMP 1
#define RUBY_SETJMP(env) sigsetjmp((env),0)
#define RUBY_LONGJMP(env,val) siglongjmp((env),val)
#define RUBY_JMP_BUF sigjmp_buf
#define USE_MJIT 1
#define HAVE_PTHREAD_H 1
#define LOAD_RELATIVE 1
#define RUBY_PLATFORM "arm64-darwin20"
#define RUBY_DEFINES_H 1
#define HAVE_ATTRIBUTE_ERRORFUNC 0
#define ERRORFUNC(mesg,x) x
#define HAVE_ATTRIBUTE_WARNINGFUNC 0
#define WARNINGFUNC(mesg,x) x
#define GCC_VERSION_SINCE(major,minor,patchlevel) 0
#define GCC_VERSION_BEFORE(major,minor,patchlevel) 0
#define RB_LIKELY(x) (__builtin_expect(!!(x), 1))
#define RB_UNLIKELY(x) (__builtin_expect(!!(x), 0))
#define COLDFUNC __attribute__((cold))
#define PRINTF_ARGS(decl,string_index,first_to_check) decl __attribute__((format(printf, string_index, first_to_check)))
#define RB_GNUC_EXTENSION __extension__
#define RB_GNUC_EXTENSION_BLOCK(x) __extension__ ({ x; })
#define _STDIO_H_ 
#define __STDIO_H_ 
#define _CDEFS_H_ 
#define __BEGIN_DECLS 
#define __END_DECLS 
#define __P(protos) protos
#define __CONCAT(x,y) x ## y
#define __STRING(x) #x
#define __const const
#define __signed signed
#define __volatile volatile
#define __dead2 __attribute__((__noreturn__))
#define __pure2 __attribute__((__const__))
#define __unused __attribute__((__unused__))
#define __used __attribute__((__used__))
#define __cold __attribute__((__cold__))
#define __exported __attribute__((__visibility__("default")))
#define __exported_push _Pragma("GCC visibility push(default)")
#define __exported_pop _Pragma("GCC visibility pop")
#define __deprecated __attribute__((__deprecated__))
#define __deprecated_msg(_msg) __attribute__((__deprecated__(_msg)))
#define __deprecated_enum_msg(_msg) __deprecated_msg(_msg)
#define __kpi_deprecated(_msg) 
#define __unavailable __attribute__((__unavailable__))
#define __kpi_unavailable 
#define __kpi_deprecated_arm64_macos_unavailable 
#define __dead 
#define __pure 
#define __restrict restrict
#define __disable_tail_calls __attribute__((__disable_tail_calls__))
#define __not_tail_called __attribute__((__not_tail_called__))
#define __result_use_check __attribute__((__warn_unused_result__))
#define __swift_unavailable(_msg) __attribute__((__availability__(swift, unavailable, message=_msg)))
#define __abortlike __dead2 __cold __not_tail_called
#define __header_inline inline
#define __header_always_inline __header_inline __attribute__ ((__always_inline__))
#define __unreachable_ok_push _Pragma("clang diagnostic push") _Pragma("clang diagnostic ignored \"-Wunreachable-code\"")
#define __unreachable_ok_pop _Pragma("clang diagnostic pop")
#define __printflike(fmtarg,firstvararg) __attribute__((__format__ (__printf__, fmtarg, firstvararg)))
#define __printf0like(fmtarg,firstvararg) __attribute__((__format__ (__printf0__, fmtarg, firstvararg)))
#define __scanflike(fmtarg,firstvararg) __attribute__((__format__ (__scanf__, fmtarg, firstvararg)))
#define __IDSTRING(name,string) static const char name[] __used = string
#define __COPYRIGHT(s) __IDSTRING(copyright,s)
#define __RCSID(s) __IDSTRING(rcsid,s)
#define __SCCSID(s) __IDSTRING(sccsid,s)
#define __PROJECT_VERSION(s) __IDSTRING(project_version,s)
#define __FBSDID(s) 
#define __DECONST(type,var) __CAST_AWAY_QUALIFIER(var, const, type)
#define __DEVOLATILE(type,var) __CAST_AWAY_QUALIFIER(var, volatile, type)
#define __DEQUALIFY(type,var) __CAST_AWAY_QUALIFIER(var, const volatile, type)
#define __alloc_size(...) __attribute__((alloc_size(__VA_ARGS__)))
#define __DARWIN_ONLY_64_BIT_INO_T 1
#define __DARWIN_ONLY_UNIX_CONFORMANCE 1
#define __DARWIN_ONLY_VERS_1050 1
#define __DARWIN_UNIX03 1
#define __DARWIN_64_BIT_INO_T 1
#define __DARWIN_VERS_1050 1
#define __DARWIN_NON_CANCELABLE 0
#define __DARWIN_SUF_UNIX03 
#define __DARWIN_SUF_64_BIT_INO_T 
#define __DARWIN_SUF_1050 
#define __DARWIN_SUF_NON_CANCELABLE 
#define __DARWIN_SUF_EXTSN "$DARWIN_EXTSN"
#define __DARWIN_ALIAS(sym) __asm("_" __STRING(sym) __DARWIN_SUF_UNIX03)
#define __DARWIN_ALIAS_C(sym) __asm("_" __STRING(sym) __DARWIN_SUF_NON_CANCELABLE __DARWIN_SUF_UNIX03)
#define __DARWIN_ALIAS_I(sym) __asm("_" __STRING(sym) __DARWIN_SUF_64_BIT_INO_T __DARWIN_SUF_UNIX03)
#define __DARWIN_NOCANCEL(sym) __asm("_" __STRING(sym) __DARWIN_SUF_NON_CANCELABLE)
#define __DARWIN_INODE64(sym) __asm("_" __STRING(sym) __DARWIN_SUF_64_BIT_INO_T)
#define __DARWIN_1050(sym) __asm("_" __STRING(sym) __DARWIN_SUF_1050)
#define __DARWIN_1050ALIAS(sym) __asm("_" __STRING(sym) __DARWIN_SUF_1050 __DARWIN_SUF_UNIX03)
#define __DARWIN_1050ALIAS_C(sym) __asm("_" __STRING(sym) __DARWIN_SUF_1050 __DARWIN_SUF_NON_CANCELABLE __DARWIN_SUF_UNIX03)
#define __DARWIN_1050ALIAS_I(sym) __asm("_" __STRING(sym) __DARWIN_SUF_1050 __DARWIN_SUF_64_BIT_INO_T __DARWIN_SUF_UNIX03)
#define __DARWIN_1050INODE64(sym) __asm("_" __STRING(sym) __DARWIN_SUF_1050 __DARWIN_SUF_64_BIT_INO_T)
#define __DARWIN_EXTSN(sym) __asm("_" __STRING(sym) __DARWIN_SUF_EXTSN)
#define __DARWIN_EXTSN_C(sym) __asm("_" __STRING(sym) __DARWIN_SUF_EXTSN __DARWIN_SUF_NON_CANCELABLE)
#define __DARWIN_ALIAS_STARTING_IPHONE___IPHONE_2_0(x) 
#define __DARWIN_ALIAS_STARTING_IPHONE___IPHONE_2_1(x) 
#define __DARWIN_ALIAS_STARTING_IPHONE___IPHONE_2_2(x) 
#define __DARWIN_ALIAS_STARTING_IPHONE___IPHONE_3_0(x) 
#define __DARWIN_ALIAS_STARTING_IPHONE___IPHONE_3_1(x) 
#define __DARWIN_ALIAS_STARTING_IPHONE___IPHONE_3_2(x) 
#define __DARWIN_ALIAS_STARTING_IPHONE___IPHONE_4_0(x) 
#define __DARWIN_ALIAS_STARTING_IPHONE___IPHONE_4_1(x) 
#define __DARWIN_ALIAS_STARTING_IPHONE___IPHONE_4_2(x) 
#define __DARWIN_ALIAS_STARTING_IPHONE___IPHONE_4_3(x) 
#define __DARWIN_ALIAS_STARTING_IPHONE___IPHONE_5_0(x) 
#define __DARWIN_ALIAS_STARTING_IPHONE___IPHONE_5_1(x) 
#define __DARWIN_ALIAS_STARTING_IPHONE___IPHONE_6_0(x) 
#define __DARWIN_ALIAS_STARTING_IPHONE___IPHONE_6_1(x) 
#define __DARWIN_ALIAS_STARTING_IPHONE___IPHONE_7_0(x) 
#define __DARWIN_ALIAS_STARTING_IPHONE___IPHONE_7_1(x) 
#define __DARWIN_ALIAS_STARTING_IPHONE___IPHONE_8_0(x) 
#define __DARWIN_ALIAS_STARTING_IPHONE___IPHONE_8_1(x) 
#define __DARWIN_ALIAS_STARTING_IPHONE___IPHONE_8_2(x) 
#define __DARWIN_ALIAS_STARTING_IPHONE___IPHONE_8_3(x) 
#define __DARWIN_ALIAS_STARTING_IPHONE___IPHONE_8_4(x) 
#define __DARWIN_ALIAS_STARTING_IPHONE___IPHONE_9_0(x) 
#define __DARWIN_ALIAS_STARTING_IPHONE___IPHONE_9_1(x) 
#define __DARWIN_ALIAS_STARTING_IPHONE___IPHONE_9_2(x) 
#define __DARWIN_ALIAS_STARTING_IPHONE___IPHONE_9_3(x) 
#define __DARWIN_ALIAS_STARTING_IPHONE___IPHONE_10_0(x) 
#define __DARWIN_ALIAS_STARTING_IPHONE___IPHONE_10_1(x) 
#define __DARWIN_ALIAS_STARTING_IPHONE___IPHONE_10_2(x) 
#define __DARWIN_ALIAS_STARTING_IPHONE___IPHONE_10_3(x) 
#define __DARWIN_ALIAS_STARTING_IPHONE___IPHONE_11_0(x) 
#define __DARWIN_ALIAS_STARTING_IPHONE___IPHONE_11_1(x) 
#define __DARWIN_ALIAS_STARTING_IPHONE___IPHONE_11_2(x) 
#define __DARWIN_ALIAS_STARTING_IPHONE___IPHONE_11_3(x) 
#define __DARWIN_ALIAS_STARTING_IPHONE___IPHONE_11_4(x) 
#define __DARWIN_ALIAS_STARTING_IPHONE___IPHONE_12_0(x) 
#define __DARWIN_ALIAS_STARTING_IPHONE___IPHONE_12_1(x) 
#define __DARWIN_ALIAS_STARTING_IPHONE___IPHONE_12_2(x) 
#define __DARWIN_ALIAS_STARTING_IPHONE___IPHONE_12_3(x) 
#define __DARWIN_ALIAS_STARTING_IPHONE___IPHONE_12_4(x) 
#define __DARWIN_ALIAS_STARTING_IPHONE___IPHONE_13_0(x) 
#define __DARWIN_ALIAS_STARTING_IPHONE___IPHONE_13_1(x) 
#define __DARWIN_ALIAS_STARTING_IPHONE___IPHONE_13_2(x) 
#define __DARWIN_ALIAS_STARTING_IPHONE___IPHONE_13_3(x) 
#define __DARWIN_ALIAS_STARTING_IPHONE___IPHONE_13_4(x) 
#define __DARWIN_ALIAS_STARTING_IPHONE___IPHONE_13_5(x) 
#define __DARWIN_ALIAS_STARTING_IPHONE___IPHONE_13_6(x) 
#define __DARWIN_ALIAS_STARTING_IPHONE___IPHONE_13_7(x) 
#define __DARWIN_ALIAS_STARTING_IPHONE___IPHONE_14_0(x) 
#define __DARWIN_ALIAS_STARTING_IPHONE___IPHONE_14_1(x) 
#define __DARWIN_ALIAS_STARTING_IPHONE___IPHONE_14_2(x) 
#define __DARWIN_ALIAS_STARTING_IPHONE___IPHONE_14_3(x) 
#define __DARWIN_ALIAS_STARTING_MAC___MAC_10_0(x) x
#define __DARWIN_ALIAS_STARTING_MAC___MAC_10_1(x) x
#define __DARWIN_ALIAS_STARTING_MAC___MAC_10_2(x) x
#define __DARWIN_ALIAS_STARTING_MAC___MAC_10_3(x) x
#define __DARWIN_ALIAS_STARTING_MAC___MAC_10_4(x) x
#define __DARWIN_ALIAS_STARTING_MAC___MAC_10_5(x) x
#define __DARWIN_ALIAS_STARTING_MAC___MAC_10_6(x) x
#define __DARWIN_ALIAS_STARTING_MAC___MAC_10_7(x) x
#define __DARWIN_ALIAS_STARTING_MAC___MAC_10_8(x) x
#define __DARWIN_ALIAS_STARTING_MAC___MAC_10_9(x) x
#define __DARWIN_ALIAS_STARTING_MAC___MAC_10_10(x) x
#define __DARWIN_ALIAS_STARTING_MAC___MAC_10_10_2(x) x
#define __DARWIN_ALIAS_STARTING_MAC___MAC_10_10_3(x) x
#define __DARWIN_ALIAS_STARTING_MAC___MAC_10_11(x) x
#define __DARWIN_ALIAS_STARTING_MAC___MAC_10_11_2(x) x
#define __DARWIN_ALIAS_STARTING_MAC___MAC_10_11_3(x) x
#define __DARWIN_ALIAS_STARTING_MAC___MAC_10_11_4(x) x
#define __DARWIN_ALIAS_STARTING_MAC___MAC_10_12(x) x
#define __DARWIN_ALIAS_STARTING_MAC___MAC_10_12_1(x) x
#define __DARWIN_ALIAS_STARTING_MAC___MAC_10_12_2(x) x
#define __DARWIN_ALIAS_STARTING_MAC___MAC_10_12_4(x) x
#define __DARWIN_ALIAS_STARTING_MAC___MAC_10_13(x) x
#define __DARWIN_ALIAS_STARTING_MAC___MAC_10_13_1(x) 
#define __DARWIN_ALIAS_STARTING_MAC___MAC_10_13_2(x) 
#define __DARWIN_ALIAS_STARTING_MAC___MAC_10_13_4(x) 
#define __DARWIN_ALIAS_STARTING_MAC___MAC_10_14(x) 
#define __DARWIN_ALIAS_STARTING_MAC___MAC_10_14_1(x) 
#define __DARWIN_ALIAS_STARTING_MAC___MAC_10_14_4(x) 
#define __DARWIN_ALIAS_STARTING_MAC___MAC_10_14_5(x) 
#define __DARWIN_ALIAS_STARTING_MAC___MAC_10_14_6(x) 
#define __DARWIN_ALIAS_STARTING_MAC___MAC_10_15(x) 
#define __DARWIN_ALIAS_STARTING_MAC___MAC_10_15_1(x) 
#define __DARWIN_ALIAS_STARTING_MAC___MAC_10_16(x) 
#define __DARWIN_ALIAS_STARTING_MAC___MAC_11_0(x) 
#define __DARWIN_ALIAS_STARTING_MAC___MAC_11_1(x) 
#define __DARWIN_ALIAS_STARTING(_mac,_iphone,x) __DARWIN_ALIAS_STARTING_MAC_##_mac(x)
#define ___POSIX_C_DEPRECATED_STARTING_198808L 
#define ___POSIX_C_DEPRECATED_STARTING_199009L 
#define ___POSIX_C_DEPRECATED_STARTING_199209L 
#define ___POSIX_C_DEPRECATED_STARTING_199309L 
#define ___POSIX_C_DEPRECATED_STARTING_199506L 
#define ___POSIX_C_DEPRECATED_STARTING_200112L 
#define ___POSIX_C_DEPRECATED_STARTING_200809L 
#define __POSIX_C_DEPRECATED(ver) ___POSIX_C_DEPRECATED_STARTING_##ver
#define __DARWIN_C_ANSI 010000L
#define __DARWIN_C_FULL 900000L
#define __DARWIN_C_LEVEL __DARWIN_C_FULL
#define __DARWIN_NO_LONG_LONG 0
#define _DARWIN_FEATURE_64_BIT_INODE 1
#define _DARWIN_FEATURE_ONLY_64_BIT_INODE 1
#define _DARWIN_FEATURE_ONLY_VERS_1050 1
#define _DARWIN_FEATURE_ONLY_UNIX_CONFORMANCE 1
#define _DARWIN_FEATURE_UNIX_CONFORMANCE 3
#define __CAST_AWAY_QUALIFIER(variable,qualifier,type) (type) (long)(variable)
#define __XNU_PRIVATE_EXTERN __attribute__((visibility("hidden")))
#define __compiler_barrier() __asm__ __volatile__("" ::: "memory")
#define __enum_open __attribute__((__enum_extensibility__(open)))
#define __enum_closed __attribute__((__enum_extensibility__(closed)))
#define __enum_options __attribute__((__flag_enum__))
#define __enum_decl(_name,_type,...) typedef enum : _type __VA_ARGS__ __enum_open _name
#define __enum_closed_decl(_name,_type,...) typedef enum : _type __VA_ARGS__ __enum_closed _name
#define __options_decl(_name,_type,...) typedef enum : _type __VA_ARGS__ __enum_open __enum_options _name
#define __options_closed_decl(_name,_type,...) typedef enum : _type __VA_ARGS__ __enum_closed __enum_options _name
#define __AVAILABILITY__ 
#define __API_TO_BE_DEPRECATED 100000
#define __AVAILABILITY_VERSIONS__ 
#define __MAC_10_0 1000
#define __MAC_10_1 1010
#define __MAC_10_2 1020
#define __MAC_10_3 1030
#define __MAC_10_4 1040
#define __MAC_10_5 1050
#define __MAC_10_6 1060
#define __MAC_10_7 1070
#define __MAC_10_8 1080
#define __MAC_10_9 1090
#define __MAC_10_10 101000
#define __MAC_10_10_2 101002
#define __MAC_10_10_3 101003
#define __MAC_10_11 101100
#define __MAC_10_11_2 101102
#define __MAC_10_11_3 101103
#define __MAC_10_11_4 101104
#define __MAC_10_12 101200
#define __MAC_10_12_1 101201
#define __MAC_10_12_2 101202
#define __MAC_10_12_4 101204
#define __MAC_10_13 101300
#define __MAC_10_13_1 101301
#define __MAC_10_13_2 101302
#define __MAC_10_13_4 101304
#define __MAC_10_14 101400
#define __MAC_10_14_1 101401
#define __MAC_10_14_4 101404
#define __MAC_10_14_6 101406
#define __MAC_10_15 101500
#define __MAC_10_15_1 101501
#define __MAC_10_15_4 101504
#define __MAC_10_16 101600
#define __MAC_11_0 110000
#define __MAC_11_1 110100
#define __IPHONE_2_0 20000
#define __IPHONE_2_1 20100
#define __IPHONE_2_2 20200
#define __IPHONE_3_0 30000
#define __IPHONE_3_1 30100
#define __IPHONE_3_2 30200
#define __IPHONE_4_0 40000
#define __IPHONE_4_1 40100
#define __IPHONE_4_2 40200
#define __IPHONE_4_3 40300
#define __IPHONE_5_0 50000
#define __IPHONE_5_1 50100
#define __IPHONE_6_0 60000
#define __IPHONE_6_1 60100
#define __IPHONE_7_0 70000
#define __IPHONE_7_1 70100
#define __IPHONE_8_0 80000
#define __IPHONE_8_1 80100
#define __IPHONE_8_2 80200
#define __IPHONE_8_3 80300
#define __IPHONE_8_4 80400
#define __IPHONE_9_0 90000
#define __IPHONE_9_1 90100
#define __IPHONE_9_2 90200
#define __IPHONE_9_3 90300
#define __IPHONE_10_0 100000
#define __IPHONE_10_1 100100
#define __IPHONE_10_2 100200
#define __IPHONE_10_3 100300
#define __IPHONE_11_0 110000
#define __IPHONE_11_1 110100
#define __IPHONE_11_2 110200
#define __IPHONE_11_3 110300
#define __IPHONE_11_4 110400
#define __IPHONE_12_0 120000
#define __IPHONE_12_1 120100
#define __IPHONE_12_2 120200
#define __IPHONE_12_3 120300
#define __IPHONE_12_4 120400
#define __IPHONE_13_0 130000
#define __IPHONE_13_1 130100
#define __IPHONE_13_2 130200
#define __IPHONE_13_3 130300
#define __IPHONE_13_4 130400
#define __IPHONE_13_5 130500
#define __IPHONE_13_6 130600
#define __IPHONE_13_7 130700
#define __IPHONE_14_0 140000
#define __IPHONE_14_1 140100
#define __IPHONE_14_2 140200
#define __IPHONE_14_3 140300
#define __TVOS_9_0 90000
#define __TVOS_9_1 90100
#define __TVOS_9_2 90200
#define __TVOS_10_0 100000
#define __TVOS_10_0_1 100001
#define __TVOS_10_1 100100
#define __TVOS_10_2 100200
#define __TVOS_11_0 110000
#define __TVOS_11_1 110100
#define __TVOS_11_2 110200
#define __TVOS_11_3 110300
#define __TVOS_11_4 110400
#define __TVOS_12_0 120000
#define __TVOS_12_1 120100
#define __TVOS_12_2 120200
#define __TVOS_12_3 120300
#define __TVOS_12_4 120400
#define __TVOS_13_0 130000
#define __TVOS_13_2 130200
#define __TVOS_13_3 130300
#define __TVOS_13_4 130400
#define __TVOS_14_0 140000
#define __TVOS_14_1 140100
#define __TVOS_14_2 140200
#define __TVOS_14_3 140300
#define __WATCHOS_1_0 10000
#define __WATCHOS_2_0 20000
#define __WATCHOS_2_1 20100
#define __WATCHOS_2_2 20200
#define __WATCHOS_3_0 30000
#define __WATCHOS_3_1 30100
#define __WATCHOS_3_1_1 30101
#define __WATCHOS_3_2 30200
#define __WATCHOS_4_0 40000
#define __WATCHOS_4_1 40100
#define __WATCHOS_4_2 40200
#define __WATCHOS_4_3 40300
#define __WATCHOS_5_0 50000
#define __WATCHOS_5_1 50100
#define __WATCHOS_5_2 50200
#define __WATCHOS_5_3 50300
#define __WATCHOS_6_0 60000
#define __WATCHOS_6_1 60100
#define __WATCHOS_6_2 60200
#define __WATCHOS_7_0 70000
#define __WATCHOS_7_1 70100
#define __WATCHOS_7_2 70200
#define MAC_OS_X_VERSION_10_0 1000
#define MAC_OS_X_VERSION_10_1 1010
#define MAC_OS_X_VERSION_10_2 1020
#define MAC_OS_X_VERSION_10_3 1030
#define MAC_OS_X_VERSION_10_4 1040
#define MAC_OS_X_VERSION_10_5 1050
#define MAC_OS_X_VERSION_10_6 1060
#define MAC_OS_X_VERSION_10_7 1070
#define MAC_OS_X_VERSION_10_8 1080
#define MAC_OS_X_VERSION_10_9 1090
#define MAC_OS_X_VERSION_10_10 101000
#define MAC_OS_X_VERSION_10_10_2 101002
#define MAC_OS_X_VERSION_10_10_3 101003
#define MAC_OS_X_VERSION_10_11 101100
#define MAC_OS_X_VERSION_10_11_2 101102
#define MAC_OS_X_VERSION_10_11_3 101103
#define MAC_OS_X_VERSION_10_11_4 101104
#define MAC_OS_X_VERSION_10_12 101200
#define MAC_OS_X_VERSION_10_12_1 101201
#define MAC_OS_X_VERSION_10_12_2 101202
#define MAC_OS_X_VERSION_10_12_4 101204
#define MAC_OS_X_VERSION_10_13 101300
#define MAC_OS_X_VERSION_10_13_1 101301
#define MAC_OS_X_VERSION_10_13_2 101302
#define MAC_OS_X_VERSION_10_13_4 101304
#define MAC_OS_X_VERSION_10_14 101400
#define MAC_OS_X_VERSION_10_14_1 101401
#define MAC_OS_X_VERSION_10_14_4 101404
#define MAC_OS_X_VERSION_10_14_6 101406
#define MAC_OS_X_VERSION_10_15 101500
#define MAC_OS_X_VERSION_10_15_1 101501
#define MAC_OS_X_VERSION_10_16 101600
#define MAC_OS_VERSION_11_0 110000
#define __DRIVERKIT_19_0 190000
#define __DRIVERKIT_20_0 200000
#define __AVAILABILITY_INTERNAL__ 
#define __MAC_OS_X_VERSION_MIN_REQUIRED __ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__
#define __MAC_OS_X_VERSION_MAX_ALLOWED __MAC_11_1
#define __AVAILABILITY_INTERNAL_DEPRECATED __attribute__((deprecated))
#define __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg) __attribute__((deprecated(_msg)))
#define __AVAILABILITY_INTERNAL_UNAVAILABLE __attribute__((unavailable))
#define __AVAILABILITY_INTERNAL_WEAK_IMPORT __attribute__((weak_import))
#define __AVAILABILITY_INTERNAL_REGULAR 
#define __ENABLE_LEGACY_MAC_AVAILABILITY 1
#define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_1 __attribute__((availability(macosx,introduced=10.1,deprecated=10.1)))
#define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_10 __attribute__((availability(macosx,introduced=10.1,deprecated=10.10)))
#define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_10_2 __attribute__((availability(macosx,introduced=10.1,deprecated=10.10.2)))
#define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_10_2_MSG(_msg) __attribute__((availability(macosx,introduced=10.1,deprecated=10.10.2,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_10_3 __attribute__((availability(macosx,introduced=10.1,deprecated=10.10.3)))
#define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_10_3_MSG(_msg) __attribute__((availability(macosx,introduced=10.1,deprecated=10.10.3,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_10_MSG(_msg) __attribute__((availability(macosx,introduced=10.1,deprecated=10.10,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_11 __attribute__((availability(macosx,introduced=10.1,deprecated=10.11)))
#define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_11_2 __attribute__((availability(macosx,introduced=10.1,deprecated=10.11.2)))
#define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_11_2_MSG(_msg) __attribute__((availability(macosx,introduced=10.1,deprecated=10.11.2,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_11_3 __attribute__((availability(macosx,introduced=10.1,deprecated=10.11.3)))
#define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_11_3_MSG(_msg) __attribute__((availability(macosx,introduced=10.1,deprecated=10.11.3,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_11_4 __attribute__((availability(macosx,introduced=10.1,deprecated=10.11.4)))
#define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_11_4_MSG(_msg) __attribute__((availability(macosx,introduced=10.1,deprecated=10.11.4,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_11_MSG(_msg) __attribute__((availability(macosx,introduced=10.1,deprecated=10.11,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_12 __attribute__((availability(macosx,introduced=10.1,deprecated=10.12)))
#define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_12_1 __attribute__((availability(macosx,introduced=10.1,deprecated=10.12.1)))
#define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_12_1_MSG(_msg) __attribute__((availability(macosx,introduced=10.1,deprecated=10.12.1,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_12_2 __attribute__((availability(macosx,introduced=10.1,deprecated=10.12.2)))
#define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_12_2_MSG(_msg) __attribute__((availability(macosx,introduced=10.1,deprecated=10.12.2,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_12_4 __attribute__((availability(macosx,introduced=10.1,deprecated=10.12.4)))
#define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_12_4_MSG(_msg) __attribute__((availability(macosx,introduced=10.1,deprecated=10.12.4,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_12_MSG(_msg) __attribute__((availability(macosx,introduced=10.1,deprecated=10.12,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_1_MSG(_msg) __attribute__((availability(macosx,introduced=10.1,deprecated=10.1,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_2 __attribute__((availability(macosx,introduced=10.1,deprecated=10.2)))
#define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_2_MSG(_msg) __attribute__((availability(macosx,introduced=10.1,deprecated=10.2,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_3 __attribute__((availability(macosx,introduced=10.1,deprecated=10.3)))
#define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_3_MSG(_msg) __attribute__((availability(macosx,introduced=10.1,deprecated=10.3,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_4 __attribute__((availability(macosx,introduced=10.1,deprecated=10.4)))
#define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_4_MSG(_msg) __attribute__((availability(macosx,introduced=10.1,deprecated=10.4,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_5 __attribute__((availability(macosx,introduced=10.1,deprecated=10.5)))
#define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_5_MSG(_msg) __attribute__((availability(macosx,introduced=10.1,deprecated=10.5,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_6 __attribute__((availability(macosx,introduced=10.1,deprecated=10.6)))
#define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_6_MSG(_msg) __attribute__((availability(macosx,introduced=10.1,deprecated=10.6,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_7 __attribute__((availability(macosx,introduced=10.1,deprecated=10.7)))
#define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_7_MSG(_msg) __attribute__((availability(macosx,introduced=10.1,deprecated=10.7,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_8 __attribute__((availability(macosx,introduced=10.1,deprecated=10.8)))
#define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_8_MSG(_msg) __attribute__((availability(macosx,introduced=10.1,deprecated=10.8,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_9 __attribute__((availability(macosx,introduced=10.1,deprecated=10.9)))
#define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_9_MSG(_msg) __attribute__((availability(macosx,introduced=10.1,deprecated=10.9,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_NA __attribute__((availability(macosx,introduced=10.1)))
#define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_NA_MSG(_msg) __attribute__((availability(macosx,introduced=10.1)))
#define __AVAILABILITY_INTERNAL__MAC_10_2 __attribute__((availability(macosx,introduced=10.2)))
#define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_1 __attribute__((availability(macosx,introduced=10.2,deprecated=10.1)))
#define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_10 __attribute__((availability(macosx,introduced=10.2,deprecated=10.10)))
#define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_10_2 __attribute__((availability(macosx,introduced=10.2,deprecated=10.10.2)))
#define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_10_2_MSG(_msg) __attribute__((availability(macosx,introduced=10.2,deprecated=10.10.2,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_10_3 __attribute__((availability(macosx,introduced=10.2,deprecated=10.10.3)))
#define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_10_3_MSG(_msg) __attribute__((availability(macosx,introduced=10.2,deprecated=10.10.3,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_10_MSG(_msg) __attribute__((availability(macosx,introduced=10.2,deprecated=10.10,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_11 __attribute__((availability(macosx,introduced=10.2,deprecated=10.11)))
#define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_11_2 __attribute__((availability(macosx,introduced=10.2,deprecated=10.11.2)))
#define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_11_2_MSG(_msg) __attribute__((availability(macosx,introduced=10.2,deprecated=10.11.2,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_11_3 __attribute__((availability(macosx,introduced=10.2,deprecated=10.11.3)))
#define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_11_3_MSG(_msg) __attribute__((availability(macosx,introduced=10.2,deprecated=10.11.3,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_11_4 __attribute__((availability(macosx,introduced=10.2,deprecated=10.11.4)))
#define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_11_4_MSG(_msg) __attribute__((availability(macosx,introduced=10.2,deprecated=10.11.4,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_11_MSG(_msg) __attribute__((availability(macosx,introduced=10.2,deprecated=10.11,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_12 __attribute__((availability(macosx,introduced=10.2,deprecated=10.12)))
#define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_12_1 __attribute__((availability(macosx,introduced=10.2,deprecated=10.12.1)))
#define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_12_1_MSG(_msg) __attribute__((availability(macosx,introduced=10.2,deprecated=10.12.1,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_12_2 __attribute__((availability(macosx,introduced=10.2,deprecated=10.12.2)))
#define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_12_2_MSG(_msg) __attribute__((availability(macosx,introduced=10.2,deprecated=10.12.2,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_12_4 __attribute__((availability(macosx,introduced=10.2,deprecated=10.12.4)))
#define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_12_4_MSG(_msg) __attribute__((availability(macosx,introduced=10.2,deprecated=10.12.4,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_12_MSG(_msg) __attribute__((availability(macosx,introduced=10.2,deprecated=10.12,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_13 __attribute__((availability(macosx,introduced=10.2,deprecated=10.13)))
#define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_2 __attribute__((availability(macosx,introduced=10.2,deprecated=10.2)))
#define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_2_MSG(_msg) __attribute__((availability(macosx,introduced=10.2,deprecated=10.2,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_3 __attribute__((availability(macosx,introduced=10.2,deprecated=10.3)))
#define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_3_MSG(_msg) __attribute__((availability(macosx,introduced=10.2,deprecated=10.3,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_4 __attribute__((availability(macosx,introduced=10.2,deprecated=10.4)))
#define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_4_MSG(_msg) __attribute__((availability(macosx,introduced=10.2,deprecated=10.4,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_5 __attribute__((availability(macosx,introduced=10.2,deprecated=10.5)))
#define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_5_MSG(_msg) __attribute__((availability(macosx,introduced=10.2,deprecated=10.5,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_6 __attribute__((availability(macosx,introduced=10.2,deprecated=10.6)))
#define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_6_MSG(_msg) __attribute__((availability(macosx,introduced=10.2,deprecated=10.6,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_7 __attribute__((availability(macosx,introduced=10.2,deprecated=10.7)))
#define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_7_MSG(_msg) __attribute__((availability(macosx,introduced=10.2,deprecated=10.7,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_8 __attribute__((availability(macosx,introduced=10.2,deprecated=10.8)))
#define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_8_MSG(_msg) __attribute__((availability(macosx,introduced=10.2,deprecated=10.8,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_9 __attribute__((availability(macosx,introduced=10.2,deprecated=10.9)))
#define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_9_MSG(_msg) __attribute__((availability(macosx,introduced=10.2,deprecated=10.9,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_NA __attribute__((availability(macosx,introduced=10.2)))
#define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_NA_MSG(_msg) __attribute__((availability(macosx,introduced=10.2)))
#define __AVAILABILITY_INTERNAL__MAC_10_3 __attribute__((availability(macosx,introduced=10.3)))
#define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_1 __attribute__((availability(macosx,introduced=10.3,deprecated=10.1)))
#define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_10 __attribute__((availability(macosx,introduced=10.3,deprecated=10.10)))
#define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_10_2 __attribute__((availability(macosx,introduced=10.3,deprecated=10.10.2)))
#define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_10_2_MSG(_msg) __attribute__((availability(macosx,introduced=10.3,deprecated=10.10.2,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_10_3 __attribute__((availability(macosx,introduced=10.3,deprecated=10.10.3)))
#define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_10_3_MSG(_msg) __attribute__((availability(macosx,introduced=10.3,deprecated=10.10.3,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_10_MSG(_msg) __attribute__((availability(macosx,introduced=10.3,deprecated=10.10,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_11 __attribute__((availability(macosx,introduced=10.3,deprecated=10.11)))
#define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_11_2 __attribute__((availability(macosx,introduced=10.3,deprecated=10.11.2)))
#define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_11_2_MSG(_msg) __attribute__((availability(macosx,introduced=10.3,deprecated=10.11.2,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_11_3 __attribute__((availability(macosx,introduced=10.3,deprecated=10.11.3)))
#define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_11_3_MSG(_msg) __attribute__((availability(macosx,introduced=10.3,deprecated=10.11.3,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_11_4 __attribute__((availability(macosx,introduced=10.3,deprecated=10.11.4)))
#define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_11_4_MSG(_msg) __attribute__((availability(macosx,introduced=10.3,deprecated=10.11.4,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_11_MSG(_msg) __attribute__((availability(macosx,introduced=10.3,deprecated=10.11,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_12 __attribute__((availability(macosx,introduced=10.3,deprecated=10.12)))
#define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_12_1 __attribute__((availability(macosx,introduced=10.3,deprecated=10.12.1)))
#define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_12_1_MSG(_msg) __attribute__((availability(macosx,introduced=10.3,deprecated=10.12.1,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_12_2 __attribute__((availability(macosx,introduced=10.3,deprecated=10.12.2)))
#define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_12_2_MSG(_msg) __attribute__((availability(macosx,introduced=10.3,deprecated=10.12.2,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_12_4 __attribute__((availability(macosx,introduced=10.3,deprecated=10.12.4)))
#define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_12_4_MSG(_msg) __attribute__((availability(macosx,introduced=10.3,deprecated=10.12.4,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_12_MSG(_msg) __attribute__((availability(macosx,introduced=10.3,deprecated=10.12,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_13 __attribute__((availability(macosx,introduced=10.3,deprecated=10.13)))
#define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_3 __attribute__((availability(macosx,introduced=10.3,deprecated=10.3)))
#define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_3_MSG(_msg) __attribute__((availability(macosx,introduced=10.3,deprecated=10.3,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_4 __attribute__((availability(macosx,introduced=10.3,deprecated=10.4)))
#define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_4_MSG(_msg) __attribute__((availability(macosx,introduced=10.3,deprecated=10.4,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_5 __attribute__((availability(macosx,introduced=10.3,deprecated=10.5)))
#define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_5_MSG(_msg) __attribute__((availability(macosx,introduced=10.3,deprecated=10.5,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_6 __attribute__((availability(macosx,introduced=10.3,deprecated=10.6)))
#define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_6_MSG(_msg) __attribute__((availability(macosx,introduced=10.3,deprecated=10.6,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_7 __attribute__((availability(macosx,introduced=10.3,deprecated=10.7)))
#define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_7_MSG(_msg) __attribute__((availability(macosx,introduced=10.3,deprecated=10.7,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_8 __attribute__((availability(macosx,introduced=10.3,deprecated=10.8)))
#define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_8_MSG(_msg) __attribute__((availability(macosx,introduced=10.3,deprecated=10.8,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_9 __attribute__((availability(macosx,introduced=10.3,deprecated=10.9)))
#define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_9_MSG(_msg) __attribute__((availability(macosx,introduced=10.3,deprecated=10.9,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_NA __attribute__((availability(macosx,introduced=10.3)))
#define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_NA_MSG(_msg) __attribute__((availability(macosx,introduced=10.3)))
#define __AVAILABILITY_INTERNAL__MAC_10_4 __attribute__((availability(macosx,introduced=10.4)))
#define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_1 __attribute__((availability(macosx,introduced=10.4,deprecated=10.1)))
#define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_10 __attribute__((availability(macosx,introduced=10.4,deprecated=10.10)))
#define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_10_2 __attribute__((availability(macosx,introduced=10.4,deprecated=10.10.2)))
#define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_10_2_MSG(_msg) __attribute__((availability(macosx,introduced=10.4,deprecated=10.10.2,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_10_3 __attribute__((availability(macosx,introduced=10.4,deprecated=10.10.3)))
#define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_10_3_MSG(_msg) __attribute__((availability(macosx,introduced=10.4,deprecated=10.10.3,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_10_MSG(_msg) __attribute__((availability(macosx,introduced=10.4,deprecated=10.10,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_11 __attribute__((availability(macosx,introduced=10.4,deprecated=10.11)))
#define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_11_2 __attribute__((availability(macosx,introduced=10.4,deprecated=10.11.2)))
#define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_11_2_MSG(_msg) __attribute__((availability(macosx,introduced=10.4,deprecated=10.11.2,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_11_3 __attribute__((availability(macosx,introduced=10.4,deprecated=10.11.3)))
#define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_11_3_MSG(_msg) __attribute__((availability(macosx,introduced=10.4,deprecated=10.11.3,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_11_4 __attribute__((availability(macosx,introduced=10.4,deprecated=10.11.4)))
#define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_11_4_MSG(_msg) __attribute__((availability(macosx,introduced=10.4,deprecated=10.11.4,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_11_MSG(_msg) __attribute__((availability(macosx,introduced=10.4,deprecated=10.11,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_12 __attribute__((availability(macosx,introduced=10.4,deprecated=10.12)))
#define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_12_1 __attribute__((availability(macosx,introduced=10.4,deprecated=10.12.1)))
#define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_12_1_MSG(_msg) __attribute__((availability(macosx,introduced=10.4,deprecated=10.12.1,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_12_2 __attribute__((availability(macosx,introduced=10.4,deprecated=10.12.2)))
#define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_12_2_MSG(_msg) __attribute__((availability(macosx,introduced=10.4,deprecated=10.12.2,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_12_4 __attribute__((availability(macosx,introduced=10.4,deprecated=10.12.4)))
#define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_12_4_MSG(_msg) __attribute__((availability(macosx,introduced=10.4,deprecated=10.12.4,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_12_MSG(_msg) __attribute__((availability(macosx,introduced=10.4,deprecated=10.12,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_13 __attribute__((availability(macosx,introduced=10.4,deprecated=10.13)))
#define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_4 __attribute__((availability(macosx,introduced=10.4,deprecated=10.4)))
#define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_4_MSG(_msg) __attribute__((availability(macosx,introduced=10.4,deprecated=10.4,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_5 __attribute__((availability(macosx,introduced=10.4,deprecated=10.5)))
#define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_5_MSG(_msg) __attribute__((availability(macosx,introduced=10.4,deprecated=10.5,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_6 __attribute__((availability(macosx,introduced=10.4,deprecated=10.6)))
#define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_6_MSG(_msg) __attribute__((availability(macosx,introduced=10.4,deprecated=10.6,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_7 __attribute__((availability(macosx,introduced=10.4,deprecated=10.7)))
#define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_7_MSG(_msg) __attribute__((availability(macosx,introduced=10.4,deprecated=10.7,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_8 __attribute__((availability(macosx,introduced=10.4,deprecated=10.8)))
#define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_8_MSG(_msg) __attribute__((availability(macosx,introduced=10.4,deprecated=10.8,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_9 __attribute__((availability(macosx,introduced=10.4,deprecated=10.9)))
#define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_9_MSG(_msg) __attribute__((availability(macosx,introduced=10.4,deprecated=10.9,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_NA __attribute__((availability(macosx,introduced=10.4)))
#define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_NA_MSG(_msg) __attribute__((availability(macosx,introduced=10.4)))
#define __AVAILABILITY_INTERNAL__MAC_10_5 __attribute__((availability(macosx,introduced=10.5)))
#define __AVAILABILITY_INTERNAL__MAC_10_5_DEPRECATED__MAC_10_7 __attribute__((availability(macosx,introduced=10.5.DEPRECATED..MAC.10.7)))
#define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_10_1 __attribute__((availability(macosx,introduced=10.5,deprecated=10.1)))
#define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_10_10 __attribute__((availability(macosx,introduced=10.5,deprecated=10.10)))
#define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_10_10_2 __attribute__((availability(macosx,introduced=10.5,deprecated=10.10.2)))
#define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_10_10_2_MSG(_msg) __attribute__((availability(macosx,introduced=10.5,deprecated=10.10.2,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_10_10_3 __attribute__((availability(macosx,introduced=10.5,deprecated=10.10.3)))
#define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_10_10_3_MSG(_msg) __attribute__((availability(macosx,introduced=10.5,deprecated=10.10.3,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_10_10_MSG(_msg) __attribute__((availability(macosx,introduced=10.5,deprecated=10.10,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_10_11 __attribute__((availability(macosx,introduced=10.5,deprecated=10.11)))
#define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_10_11_2 __attribute__((availability(macosx,introduced=10.5,deprecated=10.11.2)))
#define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_10_11_2_MSG(_msg) __attribute__((availability(macosx,introduced=10.5,deprecated=10.11.2,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_10_11_3 __attribute__((availability(macosx,introduced=10.5,deprecated=10.11.3)))
#define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_10_11_3_MSG(_msg) __attribute__((availability(macosx,introduced=10.5,deprecated=10.11.3,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_10_11_4 __attribute__((availability(macosx,introduced=10.5,deprecated=10.11.4)))
#define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_10_11_4_MSG(_msg) __attribute__((availability(macosx,introduced=10.5,deprecated=10.11.4,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_10_11_MSG(_msg) __attribute__((availability(macosx,introduced=10.5,deprecated=10.11,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_10_12 __attribute__((availability(macosx,introduced=10.5,deprecated=10.12)))
#define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_10_12_1 __attribute__((availability(macosx,introduced=10.5,deprecated=10.12.1)))
#define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_10_12_1_MSG(_msg) __attribute__((availability(macosx,introduced=10.5,deprecated=10.12.1,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_10_12_2 __attribute__((availability(macosx,introduced=10.5,deprecated=10.12.2)))
#define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_10_12_2_MSG(_msg) __attribute__((availability(macosx,introduced=10.5,deprecated=10.12.2,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_10_12_4 __attribute__((availability(macosx,introduced=10.5,deprecated=10.12.4)))
#define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_10_12_4_MSG(_msg) __attribute__((availability(macosx,introduced=10.5,deprecated=10.12.4,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_10_12_MSG(_msg) __attribute__((availability(macosx,introduced=10.5,deprecated=10.12,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_10_5 __attribute__((availability(macosx,introduced=10.5,deprecated=10.5)))
#define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_10_5_MSG(_msg) __attribute__((availability(macosx,introduced=10.5,deprecated=10.5,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_10_6 __attribute__((availability(macosx,introduced=10.5,deprecated=10.6)))
#define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_10_6_MSG(_msg) __attribute__((availability(macosx,introduced=10.5,deprecated=10.6,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_10_7 __attribute__((availability(macosx,introduced=10.5,deprecated=10.7)))
#define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_10_7_MSG(_msg) __attribute__((availability(macosx,introduced=10.5,deprecated=10.7,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_10_8 __attribute__((availability(macosx,introduced=10.5,deprecated=10.8)))
#define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_10_8_MSG(_msg) __attribute__((availability(macosx,introduced=10.5,deprecated=10.8,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_10_9 __attribute__((availability(macosx,introduced=10.5,deprecated=10.9)))
#define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_10_9_MSG(_msg) __attribute__((availability(macosx,introduced=10.5,deprecated=10.9,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_NA __attribute__((availability(macosx,introduced=10.5)))
#define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_NA_MSG(_msg) __attribute__((availability(macosx,introduced=10.5)))
#define __AVAILABILITY_INTERNAL__MAC_10_6 __attribute__((availability(macosx,introduced=10.6)))
#define __AVAILABILITY_INTERNAL__MAC_10_6_DEP__MAC_10_1 __attribute__((availability(macosx,introduced=10.6,deprecated=10.1)))
#define __AVAILABILITY_INTERNAL__MAC_10_6_DEP__MAC_10_10 __attribute__((availability(macosx,introduced=10.6,deprecated=10.10)))
#define __AVAILABILITY_INTERNAL__MAC_10_6_DEP__MAC_10_10_2 __attribute__((availability(macosx,introduced=10.6,deprecated=10.10.2)))
#define __AVAILABILITY_INTERNAL__MAC_10_6_DEP__MAC_10_10_2_MSG(_msg) __attribute__((availability(macosx,introduced=10.6,deprecated=10.10.2,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_6_DEP__MAC_10_10_3 __attribute__((availability(macosx,introduced=10.6,deprecated=10.10.3)))
#define __AVAILABILITY_INTERNAL__MAC_10_6_DEP__MAC_10_10_3_MSG(_msg) __attribute__((availability(macosx,introduced=10.6,deprecated=10.10.3,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_6_DEP__MAC_10_10_MSG(_msg) __attribute__((availability(macosx,introduced=10.6,deprecated=10.10,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_6_DEP__MAC_10_11 __attribute__((availability(macosx,introduced=10.6,deprecated=10.11)))
#define __AVAILABILITY_INTERNAL__MAC_10_6_DEP__MAC_10_11_2 __attribute__((availability(macosx,introduced=10.6,deprecated=10.11.2)))
#define __AVAILABILITY_INTERNAL__MAC_10_6_DEP__MAC_10_11_2_MSG(_msg) __attribute__((availability(macosx,introduced=10.6,deprecated=10.11.2,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_6_DEP__MAC_10_11_3 __attribute__((availability(macosx,introduced=10.6,deprecated=10.11.3)))
#define __AVAILABILITY_INTERNAL__MAC_10_6_DEP__MAC_10_11_3_MSG(_msg) __attribute__((availability(macosx,introduced=10.6,deprecated=10.11.3,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_6_DEP__MAC_10_11_4 __attribute__((availability(macosx,introduced=10.6,deprecated=10.11.4)))
#define __AVAILABILITY_INTERNAL__MAC_10_6_DEP__MAC_10_11_4_MSG(_msg) __attribute__((availability(macosx,introduced=10.6,deprecated=10.11.4,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_6_DEP__MAC_10_11_MSG(_msg) __attribute__((availability(macosx,introduced=10.6,deprecated=10.11,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_6_DEP__MAC_10_12 __attribute__((availability(macosx,introduced=10.6,deprecated=10.12)))
#define __AVAILABILITY_INTERNAL__MAC_10_6_DEP__MAC_10_12_1 __attribute__((availability(macosx,introduced=10.6,deprecated=10.12.1)))
#define __AVAILABILITY_INTERNAL__MAC_10_6_DEP__MAC_10_12_1_MSG(_msg) __attribute__((availability(macosx,introduced=10.6,deprecated=10.12.1,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_6_DEP__MAC_10_12_2 __attribute__((availability(macosx,introduced=10.6,deprecated=10.12.2)))
#define __AVAILABILITY_INTERNAL__MAC_10_6_DEP__MAC_10_12_2_MSG(_msg) __attribute__((availability(macosx,introduced=10.6,deprecated=10.12.2,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_6_DEP__MAC_10_12_4 __attribute__((availability(macosx,introduced=10.6,deprecated=10.12.4)))
#define __AVAILABILITY_INTERNAL__MAC_10_6_DEP__MAC_10_12_4_MSG(_msg) __attribute__((availability(macosx,introduced=10.6,deprecated=10.12.4,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_6_DEP__MAC_10_12_MSG(_msg) __attribute__((availability(macosx,introduced=10.6,deprecated=10.12,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_6_DEP__MAC_10_13 __attribute__((availability(macosx,introduced=10.6,deprecated=10.13)))
#define __AVAILABILITY_INTERNAL__MAC_10_6_DEP__MAC_10_6 __attribute__((availability(macosx,introduced=10.6,deprecated=10.6)))
#define __AVAILABILITY_INTERNAL__MAC_10_6_DEP__MAC_10_6_MSG(_msg) __attribute__((availability(macosx,introduced=10.6,deprecated=10.6,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_6_DEP__MAC_10_7 __attribute__((availability(macosx,introduced=10.6,deprecated=10.7)))
#define __AVAILABILITY_INTERNAL__MAC_10_6_DEP__MAC_10_7_MSG(_msg) __attribute__((availability(macosx,introduced=10.6,deprecated=10.7,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_6_DEP__MAC_10_8 __attribute__((availability(macosx,introduced=10.6,deprecated=10.8)))
#define __AVAILABILITY_INTERNAL__MAC_10_6_DEP__MAC_10_8_MSG(_msg) __attribute__((availability(macosx,introduced=10.6,deprecated=10.8,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_6_DEP__MAC_10_9 __attribute__((availability(macosx,introduced=10.6,deprecated=10.9)))
#define __AVAILABILITY_INTERNAL__MAC_10_6_DEP__MAC_10_9_MSG(_msg) __attribute__((availability(macosx,introduced=10.6,deprecated=10.9,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_6_DEP__MAC_NA __attribute__((availability(macosx,introduced=10.6)))
#define __AVAILABILITY_INTERNAL__MAC_10_6_DEP__MAC_NA_MSG(_msg) __attribute__((availability(macosx,introduced=10.6)))
#define __AVAILABILITY_INTERNAL__MAC_10_7 __attribute__((availability(macosx,introduced=10.7)))
#define __AVAILABILITY_INTERNAL__MAC_10_7_DEP__MAC_10_1 __attribute__((availability(macosx,introduced=10.7,deprecated=10.1)))
#define __AVAILABILITY_INTERNAL__MAC_10_7_DEP__MAC_10_10 __attribute__((availability(macosx,introduced=10.7,deprecated=10.10)))
#define __AVAILABILITY_INTERNAL__MAC_10_7_DEP__MAC_10_10_2 __attribute__((availability(macosx,introduced=10.7,deprecated=10.10.2)))
#define __AVAILABILITY_INTERNAL__MAC_10_7_DEP__MAC_10_10_2_MSG(_msg) __attribute__((availability(macosx,introduced=10.7,deprecated=10.10.2,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_7_DEP__MAC_10_10_3 __attribute__((availability(macosx,introduced=10.7,deprecated=10.10.3)))
#define __AVAILABILITY_INTERNAL__MAC_10_7_DEP__MAC_10_10_3_MSG(_msg) __attribute__((availability(macosx,introduced=10.7,deprecated=10.10.3,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_7_DEP__MAC_10_10_MSG(_msg) __attribute__((availability(macosx,introduced=10.7,deprecated=10.10,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_7_DEP__MAC_10_11 __attribute__((availability(macosx,introduced=10.7,deprecated=10.11)))
#define __AVAILABILITY_INTERNAL__MAC_10_7_DEP__MAC_10_11_2 __attribute__((availability(macosx,introduced=10.7,deprecated=10.11.2)))
#define __AVAILABILITY_INTERNAL__MAC_10_7_DEP__MAC_10_11_2_MSG(_msg) __attribute__((availability(macosx,introduced=10.7,deprecated=10.11.2,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_7_DEP__MAC_10_11_3 __attribute__((availability(macosx,introduced=10.7,deprecated=10.11.3)))
#define __AVAILABILITY_INTERNAL__MAC_10_7_DEP__MAC_10_11_3_MSG(_msg) __attribute__((availability(macosx,introduced=10.7,deprecated=10.11.3,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_7_DEP__MAC_10_11_4 __attribute__((availability(macosx,introduced=10.7,deprecated=10.11.4)))
#define __AVAILABILITY_INTERNAL__MAC_10_7_DEP__MAC_10_11_4_MSG(_msg) __attribute__((availability(macosx,introduced=10.7,deprecated=10.11.4,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_7_DEP__MAC_10_11_MSG(_msg) __attribute__((availability(macosx,introduced=10.7,deprecated=10.11,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_7_DEP__MAC_10_12 __attribute__((availability(macosx,introduced=10.7,deprecated=10.12)))
#define __AVAILABILITY_INTERNAL__MAC_10_7_DEP__MAC_10_12_1 __attribute__((availability(macosx,introduced=10.7,deprecated=10.12.1)))
#define __AVAILABILITY_INTERNAL__MAC_10_7_DEP__MAC_10_12_1_MSG(_msg) __attribute__((availability(macosx,introduced=10.7,deprecated=10.12.1,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_7_DEP__MAC_10_12_2 __attribute__((availability(macosx,introduced=10.7,deprecated=10.12.2)))
#define __AVAILABILITY_INTERNAL__MAC_10_7_DEP__MAC_10_12_2_MSG(_msg) __attribute__((availability(macosx,introduced=10.7,deprecated=10.12.2,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_7_DEP__MAC_10_12_4 __attribute__((availability(macosx,introduced=10.7,deprecated=10.12.4)))
#define __AVAILABILITY_INTERNAL__MAC_10_7_DEP__MAC_10_12_4_MSG(_msg) __attribute__((availability(macosx,introduced=10.7,deprecated=10.12.4,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_7_DEP__MAC_10_12_MSG(_msg) __attribute__((availability(macosx,introduced=10.7,deprecated=10.12,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_7_DEP__MAC_10_13_2 __attribute__((availability(macosx,introduced=10.7,deprecated=10.13.2)))
#define __AVAILABILITY_INTERNAL__MAC_10_7_DEP__MAC_10_7 __attribute__((availability(macosx,introduced=10.7,deprecated=10.7)))
#define __AVAILABILITY_INTERNAL__MAC_10_7_DEP__MAC_10_7_MSG(_msg) __attribute__((availability(macosx,introduced=10.7,deprecated=10.7,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_7_DEP__MAC_10_8 __attribute__((availability(macosx,introduced=10.7,deprecated=10.8)))
#define __AVAILABILITY_INTERNAL__MAC_10_7_DEP__MAC_10_8_MSG(_msg) __attribute__((availability(macosx,introduced=10.7,deprecated=10.8,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_7_DEP__MAC_10_9 __attribute__((availability(macosx,introduced=10.7,deprecated=10.9)))
#define __AVAILABILITY_INTERNAL__MAC_10_7_DEP__MAC_10_9_MSG(_msg) __attribute__((availability(macosx,introduced=10.7,deprecated=10.9,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_7_DEP__MAC_NA __attribute__((availability(macosx,introduced=10.7)))
#define __AVAILABILITY_INTERNAL__MAC_10_7_DEP__MAC_NA_MSG(_msg) __attribute__((availability(macosx,introduced=10.7)))
#define __AVAILABILITY_INTERNAL__MAC_10_8 __attribute__((availability(macosx,introduced=10.8)))
#define __AVAILABILITY_INTERNAL__MAC_10_8_DEP__MAC_10_1 __attribute__((availability(macosx,introduced=10.8,deprecated=10.1)))
#define __AVAILABILITY_INTERNAL__MAC_10_8_DEP__MAC_10_10 __attribute__((availability(macosx,introduced=10.8,deprecated=10.10)))
#define __AVAILABILITY_INTERNAL__MAC_10_8_DEP__MAC_10_10_2 __attribute__((availability(macosx,introduced=10.8,deprecated=10.10.2)))
#define __AVAILABILITY_INTERNAL__MAC_10_8_DEP__MAC_10_10_2_MSG(_msg) __attribute__((availability(macosx,introduced=10.8,deprecated=10.10.2,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_8_DEP__MAC_10_10_3 __attribute__((availability(macosx,introduced=10.8,deprecated=10.10.3)))
#define __AVAILABILITY_INTERNAL__MAC_10_8_DEP__MAC_10_10_3_MSG(_msg) __attribute__((availability(macosx,introduced=10.8,deprecated=10.10.3,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_8_DEP__MAC_10_10_MSG(_msg) __attribute__((availability(macosx,introduced=10.8,deprecated=10.10,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_8_DEP__MAC_10_11 __attribute__((availability(macosx,introduced=10.8,deprecated=10.11)))
#define __AVAILABILITY_INTERNAL__MAC_10_8_DEP__MAC_10_11_2 __attribute__((availability(macosx,introduced=10.8,deprecated=10.11.2)))
#define __AVAILABILITY_INTERNAL__MAC_10_8_DEP__MAC_10_11_2_MSG(_msg) __attribute__((availability(macosx,introduced=10.8,deprecated=10.11.2,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_8_DEP__MAC_10_11_3 __attribute__((availability(macosx,introduced=10.8,deprecated=10.11.3)))
#define __AVAILABILITY_INTERNAL__MAC_10_8_DEP__MAC_10_11_3_MSG(_msg) __attribute__((availability(macosx,introduced=10.8,deprecated=10.11.3,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_8_DEP__MAC_10_11_4 __attribute__((availability(macosx,introduced=10.8,deprecated=10.11.4)))
#define __AVAILABILITY_INTERNAL__MAC_10_8_DEP__MAC_10_11_4_MSG(_msg) __attribute__((availability(macosx,introduced=10.8,deprecated=10.11.4,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_8_DEP__MAC_10_11_MSG(_msg) __attribute__((availability(macosx,introduced=10.8,deprecated=10.11,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_8_DEP__MAC_10_12 __attribute__((availability(macosx,introduced=10.8,deprecated=10.12)))
#define __AVAILABILITY_INTERNAL__MAC_10_8_DEP__MAC_10_12_1 __attribute__((availability(macosx,introduced=10.8,deprecated=10.12.1)))
#define __AVAILABILITY_INTERNAL__MAC_10_8_DEP__MAC_10_12_1_MSG(_msg) __attribute__((availability(macosx,introduced=10.8,deprecated=10.12.1,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_8_DEP__MAC_10_12_2 __attribute__((availability(macosx,introduced=10.8,deprecated=10.12.2)))
#define __AVAILABILITY_INTERNAL__MAC_10_8_DEP__MAC_10_12_2_MSG(_msg) __attribute__((availability(macosx,introduced=10.8,deprecated=10.12.2,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_8_DEP__MAC_10_12_4 __attribute__((availability(macosx,introduced=10.8,deprecated=10.12.4)))
#define __AVAILABILITY_INTERNAL__MAC_10_8_DEP__MAC_10_12_4_MSG(_msg) __attribute__((availability(macosx,introduced=10.8,deprecated=10.12.4,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_8_DEP__MAC_10_12_MSG(_msg) __attribute__((availability(macosx,introduced=10.8,deprecated=10.12,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_8_DEP__MAC_10_13 __attribute__((availability(macosx,introduced=10.8,deprecated=10.13)))
#define __AVAILABILITY_INTERNAL__MAC_10_8_DEP__MAC_10_8 __attribute__((availability(macosx,introduced=10.8,deprecated=10.8)))
#define __AVAILABILITY_INTERNAL__MAC_10_8_DEP__MAC_10_8_MSG(_msg) __attribute__((availability(macosx,introduced=10.8,deprecated=10.8,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_8_DEP__MAC_10_9 __attribute__((availability(macosx,introduced=10.8,deprecated=10.9)))
#define __AVAILABILITY_INTERNAL__MAC_10_8_DEP__MAC_10_9_MSG(_msg) __attribute__((availability(macosx,introduced=10.8,deprecated=10.9,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_8_DEP__MAC_NA __attribute__((availability(macosx,introduced=10.8)))
#define __AVAILABILITY_INTERNAL__MAC_10_8_DEP__MAC_NA_MSG(_msg) __attribute__((availability(macosx,introduced=10.8)))
#define __AVAILABILITY_INTERNAL__MAC_10_9 __attribute__((availability(macosx,introduced=10.9)))
#define __AVAILABILITY_INTERNAL__MAC_10_9_DEP__MAC_10_1 __attribute__((availability(macosx,introduced=10.9,deprecated=10.1)))
#define __AVAILABILITY_INTERNAL__MAC_10_9_DEP__MAC_10_10 __attribute__((availability(macosx,introduced=10.9,deprecated=10.10)))
#define __AVAILABILITY_INTERNAL__MAC_10_9_DEP__MAC_10_10_2 __attribute__((availability(macosx,introduced=10.9,deprecated=10.10.2)))
#define __AVAILABILITY_INTERNAL__MAC_10_9_DEP__MAC_10_10_2_MSG(_msg) __attribute__((availability(macosx,introduced=10.9,deprecated=10.10.2,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_9_DEP__MAC_10_10_3 __attribute__((availability(macosx,introduced=10.9,deprecated=10.10.3)))
#define __AVAILABILITY_INTERNAL__MAC_10_9_DEP__MAC_10_10_3_MSG(_msg) __attribute__((availability(macosx,introduced=10.9,deprecated=10.10.3,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_9_DEP__MAC_10_10_MSG(_msg) __attribute__((availability(macosx,introduced=10.9,deprecated=10.10,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_9_DEP__MAC_10_11 __attribute__((availability(macosx,introduced=10.9,deprecated=10.11)))
#define __AVAILABILITY_INTERNAL__MAC_10_9_DEP__MAC_10_11_2 __attribute__((availability(macosx,introduced=10.9,deprecated=10.11.2)))
#define __AVAILABILITY_INTERNAL__MAC_10_9_DEP__MAC_10_11_2_MSG(_msg) __attribute__((availability(macosx,introduced=10.9,deprecated=10.11.2,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_9_DEP__MAC_10_11_3 __attribute__((availability(macosx,introduced=10.9,deprecated=10.11.3)))
#define __AVAILABILITY_INTERNAL__MAC_10_9_DEP__MAC_10_11_3_MSG(_msg) __attribute__((availability(macosx,introduced=10.9,deprecated=10.11.3,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_9_DEP__MAC_10_11_4 __attribute__((availability(macosx,introduced=10.9,deprecated=10.11.4)))
#define __AVAILABILITY_INTERNAL__MAC_10_9_DEP__MAC_10_11_4_MSG(_msg) __attribute__((availability(macosx,introduced=10.9,deprecated=10.11.4,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_9_DEP__MAC_10_11_MSG(_msg) __attribute__((availability(macosx,introduced=10.9,deprecated=10.11,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_9_DEP__MAC_10_12 __attribute__((availability(macosx,introduced=10.9,deprecated=10.12)))
#define __AVAILABILITY_INTERNAL__MAC_10_9_DEP__MAC_10_12_1 __attribute__((availability(macosx,introduced=10.9,deprecated=10.12.1)))
#define __AVAILABILITY_INTERNAL__MAC_10_9_DEP__MAC_10_12_1_MSG(_msg) __attribute__((availability(macosx,introduced=10.9,deprecated=10.12.1,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_9_DEP__MAC_10_12_2 __attribute__((availability(macosx,introduced=10.9,deprecated=10.12.2)))
#define __AVAILABILITY_INTERNAL__MAC_10_9_DEP__MAC_10_12_2_MSG(_msg) __attribute__((availability(macosx,introduced=10.9,deprecated=10.12.2,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_9_DEP__MAC_10_12_4 __attribute__((availability(macosx,introduced=10.9,deprecated=10.12.4)))
#define __AVAILABILITY_INTERNAL__MAC_10_9_DEP__MAC_10_12_4_MSG(_msg) __attribute__((availability(macosx,introduced=10.9,deprecated=10.12.4,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_9_DEP__MAC_10_12_MSG(_msg) __attribute__((availability(macosx,introduced=10.9,deprecated=10.12,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_9_DEP__MAC_10_13 __attribute__((availability(macosx,introduced=10.9,deprecated=10.13)))
#define __AVAILABILITY_INTERNAL__MAC_10_9_DEP__MAC_10_14 __attribute__((availability(macosx,introduced=10.9,deprecated=10.14)))
#define __AVAILABILITY_INTERNAL__MAC_10_9_DEP__MAC_10_9 __attribute__((availability(macosx,introduced=10.9,deprecated=10.9)))
#define __AVAILABILITY_INTERNAL__MAC_10_9_DEP__MAC_10_9_MSG(_msg) __attribute__((availability(macosx,introduced=10.9,deprecated=10.9,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_9_DEP__MAC_NA __attribute__((availability(macosx,introduced=10.9)))
#define __AVAILABILITY_INTERNAL__MAC_10_9_DEP__MAC_NA_MSG(_msg) __attribute__((availability(macosx,introduced=10.9)))
#define __AVAILABILITY_INTERNAL__MAC_10_0 __attribute__((availability(macosx,introduced=10.0)))
#define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_0 __attribute__((availability(macosx,introduced=10.0,deprecated=10.0)))
#define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_0_MSG(_msg) __attribute__((availability(macosx,introduced=10.0,deprecated=10.0,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_1 __attribute__((availability(macosx,introduced=10.0,deprecated=10.1)))
#define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_10 __attribute__((availability(macosx,introduced=10.0,deprecated=10.10)))
#define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_10_2 __attribute__((availability(macosx,introduced=10.0,deprecated=10.10.2)))
#define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_10_2_MSG(_msg) __attribute__((availability(macosx,introduced=10.0,deprecated=10.10.2,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_10_3 __attribute__((availability(macosx,introduced=10.0,deprecated=10.10.3)))
#define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_10_3_MSG(_msg) __attribute__((availability(macosx,introduced=10.0,deprecated=10.10.3,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_10_MSG(_msg) __attribute__((availability(macosx,introduced=10.0,deprecated=10.10,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_11 __attribute__((availability(macosx,introduced=10.0,deprecated=10.11)))
#define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_11_2 __attribute__((availability(macosx,introduced=10.0,deprecated=10.11.2)))
#define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_11_2_MSG(_msg) __attribute__((availability(macosx,introduced=10.0,deprecated=10.11.2,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_11_3 __attribute__((availability(macosx,introduced=10.0,deprecated=10.11.3)))
#define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_11_3_MSG(_msg) __attribute__((availability(macosx,introduced=10.0,deprecated=10.11.3,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_11_4 __attribute__((availability(macosx,introduced=10.0,deprecated=10.11.4)))
#define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_11_4_MSG(_msg) __attribute__((availability(macosx,introduced=10.0,deprecated=10.11.4,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_11_MSG(_msg) __attribute__((availability(macosx,introduced=10.0,deprecated=10.11,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_12 __attribute__((availability(macosx,introduced=10.0,deprecated=10.12)))
#define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_12_1 __attribute__((availability(macosx,introduced=10.0,deprecated=10.12.1)))
#define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_12_1_MSG(_msg) __attribute__((availability(macosx,introduced=10.0,deprecated=10.12.1,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_12_2 __attribute__((availability(macosx,introduced=10.0,deprecated=10.12.2)))
#define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_12_2_MSG(_msg) __attribute__((availability(macosx,introduced=10.0,deprecated=10.12.2,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_12_4 __attribute__((availability(macosx,introduced=10.0,deprecated=10.12.4)))
#define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_12_4_MSG(_msg) __attribute__((availability(macosx,introduced=10.0,deprecated=10.12.4,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_12_MSG(_msg) __attribute__((availability(macosx,introduced=10.0,deprecated=10.12,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_13 __attribute__((availability(macosx,introduced=10.0,deprecated=10.13)))
#define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_1_MSG(_msg) __attribute__((availability(macosx,introduced=10.0,deprecated=10.1,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_2 __attribute__((availability(macosx,introduced=10.0,deprecated=10.2)))
#define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_2_MSG(_msg) __attribute__((availability(macosx,introduced=10.0,deprecated=10.2,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_3 __attribute__((availability(macosx,introduced=10.0,deprecated=10.3)))
#define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_3_MSG(_msg) __attribute__((availability(macosx,introduced=10.0,deprecated=10.3,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_4 __attribute__((availability(macosx,introduced=10.0,deprecated=10.4)))
#define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_4_MSG(_msg) __attribute__((availability(macosx,introduced=10.0,deprecated=10.4,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_5 __attribute__((availability(macosx,introduced=10.0,deprecated=10.5)))
#define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_5_MSG(_msg) __attribute__((availability(macosx,introduced=10.0,deprecated=10.5,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_6 __attribute__((availability(macosx,introduced=10.0,deprecated=10.6)))
#define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_6_MSG(_msg) __attribute__((availability(macosx,introduced=10.0,deprecated=10.6,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_7 __attribute__((availability(macosx,introduced=10.0,deprecated=10.7)))
#define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_7_MSG(_msg) __attribute__((availability(macosx,introduced=10.0,deprecated=10.7,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_8 __attribute__((availability(macosx,introduced=10.0,deprecated=10.8)))
#define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_8_MSG(_msg) __attribute__((availability(macosx,introduced=10.0,deprecated=10.8,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_9 __attribute__((availability(macosx,introduced=10.0,deprecated=10.9)))
#define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_9_MSG(_msg) __attribute__((availability(macosx,introduced=10.0,deprecated=10.9,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_13_MSG(_msg) __attribute__((availability(macosx,introduced=10.0,deprecated=10.13,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_NA __attribute__((availability(macosx,introduced=10.0)))
#define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_NA_MSG(_msg) __attribute__((availability(macosx,introduced=10.0)))
#define __AVAILABILITY_INTERNAL__MAC_10_1 __attribute__((availability(macosx,introduced=10.1)))
#define __AVAILABILITY_INTERNAL__MAC_10_10 __attribute__((availability(macosx,introduced=10.10)))
#define __AVAILABILITY_INTERNAL__MAC_10_10_2 __attribute__((availability(macosx,introduced=10.10.2)))
#define __AVAILABILITY_INTERNAL__MAC_10_10_2_DEP__MAC_10_10_2 __attribute__((availability(macosx,introduced=10.10.2,deprecated=10.10.2)))
#define __AVAILABILITY_INTERNAL__MAC_10_10_2_DEP__MAC_10_10_2_MSG(_msg) __attribute__((availability(macosx,introduced=10.10.2,deprecated=10.10.2,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_10_2_DEP__MAC_10_10_3 __attribute__((availability(macosx,introduced=10.10.2,deprecated=10.10.3)))
#define __AVAILABILITY_INTERNAL__MAC_10_10_2_DEP__MAC_10_10_3_MSG(_msg) __attribute__((availability(macosx,introduced=10.10.2,deprecated=10.10.3,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_10_2_DEP__MAC_10_11 __attribute__((availability(macosx,introduced=10.10.2,deprecated=10.11)))
#define __AVAILABILITY_INTERNAL__MAC_10_10_2_DEP__MAC_10_11_2 __attribute__((availability(macosx,introduced=10.10.2,deprecated=10.11.2)))
#define __AVAILABILITY_INTERNAL__MAC_10_10_2_DEP__MAC_10_11_2_MSG(_msg) __attribute__((availability(macosx,introduced=10.10.2,deprecated=10.11.2,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_10_2_DEP__MAC_10_11_3 __attribute__((availability(macosx,introduced=10.10.2,deprecated=10.11.3)))
#define __AVAILABILITY_INTERNAL__MAC_10_10_2_DEP__MAC_10_11_3_MSG(_msg) __attribute__((availability(macosx,introduced=10.10.2,deprecated=10.11.3,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_10_2_DEP__MAC_10_11_4 __attribute__((availability(macosx,introduced=10.10.2,deprecated=10.11.4)))
#define __AVAILABILITY_INTERNAL__MAC_10_10_2_DEP__MAC_10_11_4_MSG(_msg) __attribute__((availability(macosx,introduced=10.10.2,deprecated=10.11.4,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_10_2_DEP__MAC_10_11_MSG(_msg) __attribute__((availability(macosx,introduced=10.10.2,deprecated=10.11,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_10_2_DEP__MAC_10_12 __attribute__((availability(macosx,introduced=10.10.2,deprecated=10.12)))
#define __AVAILABILITY_INTERNAL__MAC_10_10_2_DEP__MAC_10_12_1 __attribute__((availability(macosx,introduced=10.10.2,deprecated=10.12.1)))
#define __AVAILABILITY_INTERNAL__MAC_10_10_2_DEP__MAC_10_12_1_MSG(_msg) __attribute__((availability(macosx,introduced=10.10.2,deprecated=10.12.1,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_10_2_DEP__MAC_10_12_2 __attribute__((availability(macosx,introduced=10.10.2,deprecated=10.12.2)))
#define __AVAILABILITY_INTERNAL__MAC_10_10_2_DEP__MAC_10_12_2_MSG(_msg) __attribute__((availability(macosx,introduced=10.10.2,deprecated=10.12.2,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_10_2_DEP__MAC_10_12_4 __attribute__((availability(macosx,introduced=10.10.2,deprecated=10.12.4)))
#define __AVAILABILITY_INTERNAL__MAC_10_10_2_DEP__MAC_10_12_4_MSG(_msg) __attribute__((availability(macosx,introduced=10.10.2,deprecated=10.12.4,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_10_2_DEP__MAC_10_12_MSG(_msg) __attribute__((availability(macosx,introduced=10.10.2,deprecated=10.12,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_10_2_DEP__MAC_NA __attribute__((availability(macosx,introduced=10.10.2)))
#define __AVAILABILITY_INTERNAL__MAC_10_10_2_DEP__MAC_NA_MSG(_msg) __attribute__((availability(macosx,introduced=10.10.2)))
#define __AVAILABILITY_INTERNAL__MAC_10_10_3 __attribute__((availability(macosx,introduced=10.10.3)))
#define __AVAILABILITY_INTERNAL__MAC_10_10_3_DEP__MAC_10_10_3 __attribute__((availability(macosx,introduced=10.10.3,deprecated=10.10.3)))
#define __AVAILABILITY_INTERNAL__MAC_10_10_3_DEP__MAC_10_10_3_MSG(_msg) __attribute__((availability(macosx,introduced=10.10.3,deprecated=10.10.3,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_10_3_DEP__MAC_10_11 __attribute__((availability(macosx,introduced=10.10.3,deprecated=10.11)))
#define __AVAILABILITY_INTERNAL__MAC_10_10_3_DEP__MAC_10_11_2 __attribute__((availability(macosx,introduced=10.10.3,deprecated=10.11.2)))
#define __AVAILABILITY_INTERNAL__MAC_10_10_3_DEP__MAC_10_11_2_MSG(_msg) __attribute__((availability(macosx,introduced=10.10.3,deprecated=10.11.2,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_10_3_DEP__MAC_10_11_3 __attribute__((availability(macosx,introduced=10.10.3,deprecated=10.11.3)))
#define __AVAILABILITY_INTERNAL__MAC_10_10_3_DEP__MAC_10_11_3_MSG(_msg) __attribute__((availability(macosx,introduced=10.10.3,deprecated=10.11.3,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_10_3_DEP__MAC_10_11_4 __attribute__((availability(macosx,introduced=10.10.3,deprecated=10.11.4)))
#define __AVAILABILITY_INTERNAL__MAC_10_10_3_DEP__MAC_10_11_4_MSG(_msg) __attribute__((availability(macosx,introduced=10.10.3,deprecated=10.11.4,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_10_3_DEP__MAC_10_11_MSG(_msg) __attribute__((availability(macosx,introduced=10.10.3,deprecated=10.11,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_10_3_DEP__MAC_10_12 __attribute__((availability(macosx,introduced=10.10.3,deprecated=10.12)))
#define __AVAILABILITY_INTERNAL__MAC_10_10_3_DEP__MAC_10_12_1 __attribute__((availability(macosx,introduced=10.10.3,deprecated=10.12.1)))
#define __AVAILABILITY_INTERNAL__MAC_10_10_3_DEP__MAC_10_12_1_MSG(_msg) __attribute__((availability(macosx,introduced=10.10.3,deprecated=10.12.1,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_10_3_DEP__MAC_10_12_2 __attribute__((availability(macosx,introduced=10.10.3,deprecated=10.12.2)))
#define __AVAILABILITY_INTERNAL__MAC_10_10_3_DEP__MAC_10_12_2_MSG(_msg) __attribute__((availability(macosx,introduced=10.10.3,deprecated=10.12.2,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_10_3_DEP__MAC_10_12_4 __attribute__((availability(macosx,introduced=10.10.3,deprecated=10.12.4)))
#define __AVAILABILITY_INTERNAL__MAC_10_10_3_DEP__MAC_10_12_4_MSG(_msg) __attribute__((availability(macosx,introduced=10.10.3,deprecated=10.12.4,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_10_3_DEP__MAC_10_12_MSG(_msg) __attribute__((availability(macosx,introduced=10.10.3,deprecated=10.12,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_10_3_DEP__MAC_NA __attribute__((availability(macosx,introduced=10.10.3)))
#define __AVAILABILITY_INTERNAL__MAC_10_10_3_DEP__MAC_NA_MSG(_msg) __attribute__((availability(macosx,introduced=10.10.3)))
#define __AVAILABILITY_INTERNAL__MAC_10_10_DEP__MAC_10_1 __attribute__((availability(macosx,introduced=10.10,deprecated=10.1)))
#define __AVAILABILITY_INTERNAL__MAC_10_10_DEP__MAC_10_10 __attribute__((availability(macosx,introduced=10.10,deprecated=10.10)))
#define __AVAILABILITY_INTERNAL__MAC_10_10_DEP__MAC_10_10_2 __attribute__((availability(macosx,introduced=10.10,deprecated=10.10.2)))
#define __AVAILABILITY_INTERNAL__MAC_10_10_DEP__MAC_10_10_2_MSG(_msg) __attribute__((availability(macosx,introduced=10.10,deprecated=10.10.2,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_10_DEP__MAC_10_10_3 __attribute__((availability(macosx,introduced=10.10,deprecated=10.10.3)))
#define __AVAILABILITY_INTERNAL__MAC_10_10_DEP__MAC_10_10_3_MSG(_msg) __attribute__((availability(macosx,introduced=10.10,deprecated=10.10.3,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_10_DEP__MAC_10_10_MSG(_msg) __attribute__((availability(macosx,introduced=10.10,deprecated=10.10,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_10_DEP__MAC_10_11 __attribute__((availability(macosx,introduced=10.10,deprecated=10.11)))
#define __AVAILABILITY_INTERNAL__MAC_10_10_DEP__MAC_10_11_2 __attribute__((availability(macosx,introduced=10.10,deprecated=10.11.2)))
#define __AVAILABILITY_INTERNAL__MAC_10_10_DEP__MAC_10_11_2_MSG(_msg) __attribute__((availability(macosx,introduced=10.10,deprecated=10.11.2,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_10_DEP__MAC_10_11_3 __attribute__((availability(macosx,introduced=10.10,deprecated=10.11.3)))
#define __AVAILABILITY_INTERNAL__MAC_10_10_DEP__MAC_10_11_3_MSG(_msg) __attribute__((availability(macosx,introduced=10.10,deprecated=10.11.3,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_10_DEP__MAC_10_11_4 __attribute__((availability(macosx,introduced=10.10,deprecated=10.11.4)))
#define __AVAILABILITY_INTERNAL__MAC_10_10_DEP__MAC_10_11_4_MSG(_msg) __attribute__((availability(macosx,introduced=10.10,deprecated=10.11.4,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_10_DEP__MAC_10_11_MSG(_msg) __attribute__((availability(macosx,introduced=10.10,deprecated=10.11,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_10_DEP__MAC_10_12 __attribute__((availability(macosx,introduced=10.10,deprecated=10.12)))
#define __AVAILABILITY_INTERNAL__MAC_10_10_DEP__MAC_10_12_1 __attribute__((availability(macosx,introduced=10.10,deprecated=10.12.1)))
#define __AVAILABILITY_INTERNAL__MAC_10_10_DEP__MAC_10_12_1_MSG(_msg) __attribute__((availability(macosx,introduced=10.10,deprecated=10.12.1,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_10_DEP__MAC_10_12_2 __attribute__((availability(macosx,introduced=10.10,deprecated=10.12.2)))
#define __AVAILABILITY_INTERNAL__MAC_10_10_DEP__MAC_10_12_2_MSG(_msg) __attribute__((availability(macosx,introduced=10.10,deprecated=10.12.2,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_10_DEP__MAC_10_12_4 __attribute__((availability(macosx,introduced=10.10,deprecated=10.12.4)))
#define __AVAILABILITY_INTERNAL__MAC_10_10_DEP__MAC_10_12_4_MSG(_msg) __attribute__((availability(macosx,introduced=10.10,deprecated=10.12.4,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_10_DEP__MAC_10_12_MSG(_msg) __attribute__((availability(macosx,introduced=10.10,deprecated=10.12,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_10_DEP__MAC_10_13 __attribute__((availability(macosx,introduced=10.10,deprecated=10.13)))
#define __AVAILABILITY_INTERNAL__MAC_10_10_DEP__MAC_10_13_MSG(_msg) __attribute__((availability(macosx,introduced=10.10,deprecated=10.13,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_10_DEP__MAC_10_13_4 __attribute__((availability(macosx,introduced=10.10,deprecated=10.13.4)))
#define __AVAILABILITY_INTERNAL__MAC_10_10_DEP__MAC_NA __attribute__((availability(macosx,introduced=10.10)))
#define __AVAILABILITY_INTERNAL__MAC_10_10_DEP__MAC_NA_MSG(_msg) __attribute__((availability(macosx,introduced=10.10)))
#define __AVAILABILITY_INTERNAL__MAC_10_11 __attribute__((availability(macosx,introduced=10.11)))
#define __AVAILABILITY_INTERNAL__MAC_10_11_2 __attribute__((availability(macosx,introduced=10.11.2)))
#define __AVAILABILITY_INTERNAL__MAC_10_11_2_DEP__MAC_10_11_2 __attribute__((availability(macosx,introduced=10.11.2,deprecated=10.11.2)))
#define __AVAILABILITY_INTERNAL__MAC_10_11_2_DEP__MAC_10_11_2_MSG(_msg) __attribute__((availability(macosx,introduced=10.11.2,deprecated=10.11.2,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_11_2_DEP__MAC_10_11_3 __attribute__((availability(macosx,introduced=10.11.2,deprecated=10.11.3)))
#define __AVAILABILITY_INTERNAL__MAC_10_11_2_DEP__MAC_10_11_3_MSG(_msg) __attribute__((availability(macosx,introduced=10.11.2,deprecated=10.11.3,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_11_2_DEP__MAC_10_11_4 __attribute__((availability(macosx,introduced=10.11.2,deprecated=10.11.4)))
#define __AVAILABILITY_INTERNAL__MAC_10_11_2_DEP__MAC_10_11_4_MSG(_msg) __attribute__((availability(macosx,introduced=10.11.2,deprecated=10.11.4,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_11_2_DEP__MAC_10_12 __attribute__((availability(macosx,introduced=10.11.2,deprecated=10.12)))
#define __AVAILABILITY_INTERNAL__MAC_10_11_2_DEP__MAC_10_12_1 __attribute__((availability(macosx,introduced=10.11.2,deprecated=10.12.1)))
#define __AVAILABILITY_INTERNAL__MAC_10_11_2_DEP__MAC_10_12_1_MSG(_msg) __attribute__((availability(macosx,introduced=10.11.2,deprecated=10.12.1,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_11_2_DEP__MAC_10_12_2 __attribute__((availability(macosx,introduced=10.11.2,deprecated=10.12.2)))
#define __AVAILABILITY_INTERNAL__MAC_10_11_2_DEP__MAC_10_12_2_MSG(_msg) __attribute__((availability(macosx,introduced=10.11.2,deprecated=10.12.2,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_11_2_DEP__MAC_10_12_4 __attribute__((availability(macosx,introduced=10.11.2,deprecated=10.12.4)))
#define __AVAILABILITY_INTERNAL__MAC_10_11_2_DEP__MAC_10_12_4_MSG(_msg) __attribute__((availability(macosx,introduced=10.11.2,deprecated=10.12.4,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_11_2_DEP__MAC_10_12_MSG(_msg) __attribute__((availability(macosx,introduced=10.11.2,deprecated=10.12,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_11_2_DEP__MAC_NA __attribute__((availability(macosx,introduced=10.11.2)))
#define __AVAILABILITY_INTERNAL__MAC_10_11_2_DEP__MAC_NA_MSG(_msg) __attribute__((availability(macosx,introduced=10.11.2)))
#define __AVAILABILITY_INTERNAL__MAC_10_11_3 __attribute__((availability(macosx,introduced=10.11.3)))
#define __AVAILABILITY_INTERNAL__MAC_10_11_3_DEP__MAC_10_11_3 __attribute__((availability(macosx,introduced=10.11.3,deprecated=10.11.3)))
#define __AVAILABILITY_INTERNAL__MAC_10_11_3_DEP__MAC_10_11_3_MSG(_msg) __attribute__((availability(macosx,introduced=10.11.3,deprecated=10.11.3,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_11_3_DEP__MAC_10_11_4 __attribute__((availability(macosx,introduced=10.11.3,deprecated=10.11.4)))
#define __AVAILABILITY_INTERNAL__MAC_10_11_3_DEP__MAC_10_11_4_MSG(_msg) __attribute__((availability(macosx,introduced=10.11.3,deprecated=10.11.4,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_11_3_DEP__MAC_10_12 __attribute__((availability(macosx,introduced=10.11.3,deprecated=10.12)))
#define __AVAILABILITY_INTERNAL__MAC_10_11_3_DEP__MAC_10_12_1 __attribute__((availability(macosx,introduced=10.11.3,deprecated=10.12.1)))
#define __AVAILABILITY_INTERNAL__MAC_10_11_3_DEP__MAC_10_12_1_MSG(_msg) __attribute__((availability(macosx,introduced=10.11.3,deprecated=10.12.1,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_11_3_DEP__MAC_10_12_2 __attribute__((availability(macosx,introduced=10.11.3,deprecated=10.12.2)))
#define __AVAILABILITY_INTERNAL__MAC_10_11_3_DEP__MAC_10_12_2_MSG(_msg) __attribute__((availability(macosx,introduced=10.11.3,deprecated=10.12.2,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_11_3_DEP__MAC_10_12_4 __attribute__((availability(macosx,introduced=10.11.3,deprecated=10.12.4)))
#define __AVAILABILITY_INTERNAL__MAC_10_11_3_DEP__MAC_10_12_4_MSG(_msg) __attribute__((availability(macosx,introduced=10.11.3,deprecated=10.12.4,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_11_3_DEP__MAC_10_12_MSG(_msg) __attribute__((availability(macosx,introduced=10.11.3,deprecated=10.12,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_11_3_DEP__MAC_NA __attribute__((availability(macosx,introduced=10.11.3)))
#define __AVAILABILITY_INTERNAL__MAC_10_11_3_DEP__MAC_NA_MSG(_msg) __attribute__((availability(macosx,introduced=10.11.3)))
#define __AVAILABILITY_INTERNAL__MAC_10_11_4 __attribute__((availability(macosx,introduced=10.11.4)))
#define __AVAILABILITY_INTERNAL__MAC_10_11_4_DEP__MAC_10_11_4 __attribute__((availability(macosx,introduced=10.11.4,deprecated=10.11.4)))
#define __AVAILABILITY_INTERNAL__MAC_10_11_4_DEP__MAC_10_11_4_MSG(_msg) __attribute__((availability(macosx,introduced=10.11.4,deprecated=10.11.4,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_11_4_DEP__MAC_10_12 __attribute__((availability(macosx,introduced=10.11.4,deprecated=10.12)))
#define __AVAILABILITY_INTERNAL__MAC_10_11_4_DEP__MAC_10_12_1 __attribute__((availability(macosx,introduced=10.11.4,deprecated=10.12.1)))
#define __AVAILABILITY_INTERNAL__MAC_10_11_4_DEP__MAC_10_12_1_MSG(_msg) __attribute__((availability(macosx,introduced=10.11.4,deprecated=10.12.1,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_11_4_DEP__MAC_10_12_2 __attribute__((availability(macosx,introduced=10.11.4,deprecated=10.12.2)))
#define __AVAILABILITY_INTERNAL__MAC_10_11_4_DEP__MAC_10_12_2_MSG(_msg) __attribute__((availability(macosx,introduced=10.11.4,deprecated=10.12.2,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_11_4_DEP__MAC_10_12_4 __attribute__((availability(macosx,introduced=10.11.4,deprecated=10.12.4)))
#define __AVAILABILITY_INTERNAL__MAC_10_11_4_DEP__MAC_10_12_4_MSG(_msg) __attribute__((availability(macosx,introduced=10.11.4,deprecated=10.12.4,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_11_4_DEP__MAC_10_12_MSG(_msg) __attribute__((availability(macosx,introduced=10.11.4,deprecated=10.12,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_11_4_DEP__MAC_NA __attribute__((availability(macosx,introduced=10.11.4)))
#define __AVAILABILITY_INTERNAL__MAC_10_11_4_DEP__MAC_NA_MSG(_msg) __attribute__((availability(macosx,introduced=10.11.4)))
#define __AVAILABILITY_INTERNAL__MAC_10_11_DEP__MAC_10_1 __attribute__((availability(macosx,introduced=10.11,deprecated=10.1)))
#define __AVAILABILITY_INTERNAL__MAC_10_11_DEP__MAC_10_11 __attribute__((availability(macosx,introduced=10.11,deprecated=10.11)))
#define __AVAILABILITY_INTERNAL__MAC_10_11_DEP__MAC_10_11_2 __attribute__((availability(macosx,introduced=10.11,deprecated=10.11.2)))
#define __AVAILABILITY_INTERNAL__MAC_10_11_DEP__MAC_10_11_2_MSG(_msg) __attribute__((availability(macosx,introduced=10.11,deprecated=10.11.2,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_11_DEP__MAC_10_11_3 __attribute__((availability(macosx,introduced=10.11,deprecated=10.11.3)))
#define __AVAILABILITY_INTERNAL__MAC_10_11_DEP__MAC_10_11_3_MSG(_msg) __attribute__((availability(macosx,introduced=10.11,deprecated=10.11.3,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_11_DEP__MAC_10_11_4 __attribute__((availability(macosx,introduced=10.11,deprecated=10.11.4)))
#define __AVAILABILITY_INTERNAL__MAC_10_11_DEP__MAC_10_11_4_MSG(_msg) __attribute__((availability(macosx,introduced=10.11,deprecated=10.11.4,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_11_DEP__MAC_10_11_MSG(_msg) __attribute__((availability(macosx,introduced=10.11,deprecated=10.11,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_11_DEP__MAC_10_12 __attribute__((availability(macosx,introduced=10.11,deprecated=10.12)))
#define __AVAILABILITY_INTERNAL__MAC_10_11_DEP__MAC_10_12_1 __attribute__((availability(macosx,introduced=10.11,deprecated=10.12.1)))
#define __AVAILABILITY_INTERNAL__MAC_10_11_DEP__MAC_10_12_1_MSG(_msg) __attribute__((availability(macosx,introduced=10.11,deprecated=10.12.1,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_11_DEP__MAC_10_12_2 __attribute__((availability(macosx,introduced=10.11,deprecated=10.12.2)))
#define __AVAILABILITY_INTERNAL__MAC_10_11_DEP__MAC_10_12_2_MSG(_msg) __attribute__((availability(macosx,introduced=10.11,deprecated=10.12.2,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_11_DEP__MAC_10_12_4 __attribute__((availability(macosx,introduced=10.11,deprecated=10.12.4)))
#define __AVAILABILITY_INTERNAL__MAC_10_11_DEP__MAC_10_12_4_MSG(_msg) __attribute__((availability(macosx,introduced=10.11,deprecated=10.12.4,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_11_DEP__MAC_10_12_MSG(_msg) __attribute__((availability(macosx,introduced=10.11,deprecated=10.12,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_11_DEP__MAC_NA __attribute__((availability(macosx,introduced=10.11)))
#define __AVAILABILITY_INTERNAL__MAC_10_11_DEP__MAC_NA_MSG(_msg) __attribute__((availability(macosx,introduced=10.11)))
#define __AVAILABILITY_INTERNAL__MAC_10_12 __attribute__((availability(macosx,introduced=10.12)))
#define __AVAILABILITY_INTERNAL__MAC_10_12_1 __attribute__((availability(macosx,introduced=10.12.1)))
#define __AVAILABILITY_INTERNAL__MAC_10_12_1_DEP__MAC_10_12_1 __attribute__((availability(macosx,introduced=10.12.1,deprecated=10.12.1)))
#define __AVAILABILITY_INTERNAL__MAC_10_12_1_DEP__MAC_10_12_1_MSG(_msg) __attribute__((availability(macosx,introduced=10.12.1,deprecated=10.12.1,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_12_1_DEP__MAC_10_12_2 __attribute__((availability(macosx,introduced=10.12.1,deprecated=10.12.2)))
#define __AVAILABILITY_INTERNAL__MAC_10_12_1_DEP__MAC_10_12_2_MSG(_msg) __attribute__((availability(macosx,introduced=10.12.1,deprecated=10.12.2,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_12_1_DEP__MAC_10_12_4 __attribute__((availability(macosx,introduced=10.12.1,deprecated=10.12.4)))
#define __AVAILABILITY_INTERNAL__MAC_10_12_1_DEP__MAC_10_12_4_MSG(_msg) __attribute__((availability(macosx,introduced=10.12.1,deprecated=10.12.4,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_12_1_DEP__MAC_NA __attribute__((availability(macosx,introduced=10.12.1)))
#define __AVAILABILITY_INTERNAL__MAC_10_12_1_DEP__MAC_NA_MSG(_msg) __attribute__((availability(macosx,introduced=10.12.1)))
#define __AVAILABILITY_INTERNAL__MAC_10_12_2 __attribute__((availability(macosx,introduced=10.12.2)))
#define __AVAILABILITY_INTERNAL__MAC_10_12_2_DEP__MAC_10_12_2 __attribute__((availability(macosx,introduced=10.12.2,deprecated=10.12.2)))
#define __AVAILABILITY_INTERNAL__MAC_10_12_2_DEP__MAC_10_12_2_MSG(_msg) __attribute__((availability(macosx,introduced=10.12.2,deprecated=10.12.2,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_12_2_DEP__MAC_10_12_4 __attribute__((availability(macosx,introduced=10.12.2,deprecated=10.12.4)))
#define __AVAILABILITY_INTERNAL__MAC_10_12_2_DEP__MAC_10_12_4_MSG(_msg) __attribute__((availability(macosx,introduced=10.12.2,deprecated=10.12.4,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_12_2_DEP__MAC_NA __attribute__((availability(macosx,introduced=10.12.2)))
#define __AVAILABILITY_INTERNAL__MAC_10_12_2_DEP__MAC_NA_MSG(_msg) __attribute__((availability(macosx,introduced=10.12.2)))
#define __AVAILABILITY_INTERNAL__MAC_10_12_4 __attribute__((availability(macosx,introduced=10.12.4)))
#define __AVAILABILITY_INTERNAL__MAC_10_12_4_DEP__MAC_10_12_4 __attribute__((availability(macosx,introduced=10.12.4,deprecated=10.12.4)))
#define __AVAILABILITY_INTERNAL__MAC_10_12_4_DEP__MAC_10_12_4_MSG(_msg) __attribute__((availability(macosx,introduced=10.12.4,deprecated=10.12.4,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_12_4_DEP__MAC_NA __attribute__((availability(macosx,introduced=10.12.4)))
#define __AVAILABILITY_INTERNAL__MAC_10_12_4_DEP__MAC_NA_MSG(_msg) __attribute__((availability(macosx,introduced=10.12.4)))
#define __AVAILABILITY_INTERNAL__MAC_10_12_DEP__MAC_10_12 __attribute__((availability(macosx,introduced=10.12,deprecated=10.12)))
#define __AVAILABILITY_INTERNAL__MAC_10_12_DEP__MAC_10_12_1 __attribute__((availability(macosx,introduced=10.12,deprecated=10.12.1)))
#define __AVAILABILITY_INTERNAL__MAC_10_12_DEP__MAC_10_12_1_MSG(_msg) __attribute__((availability(macosx,introduced=10.12,deprecated=10.12.1,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_12_DEP__MAC_10_12_2 __attribute__((availability(macosx,introduced=10.12,deprecated=10.12.2)))
#define __AVAILABILITY_INTERNAL__MAC_10_12_DEP__MAC_10_12_2_MSG(_msg) __attribute__((availability(macosx,introduced=10.12,deprecated=10.12.2,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_12_DEP__MAC_10_12_4 __attribute__((availability(macosx,introduced=10.12,deprecated=10.12.4)))
#define __AVAILABILITY_INTERNAL__MAC_10_12_DEP__MAC_10_12_4_MSG(_msg) __attribute__((availability(macosx,introduced=10.12,deprecated=10.12.4,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_12_DEP__MAC_10_12_MSG(_msg) __attribute__((availability(macosx,introduced=10.12,deprecated=10.12,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_12_DEP__MAC_10_13 __attribute__((availability(macosx,introduced=10.12,deprecated=10.13)))
#define __AVAILABILITY_INTERNAL__MAC_10_12_DEP__MAC_10_13_MSG(_msg) __attribute__((availability(macosx,introduced=10.12,deprecated=10.13,message=_msg)))
#define __AVAILABILITY_INTERNAL__MAC_10_12_DEP__MAC_10_13_4 __attribute__((availability(macosx,introduced=10.12,deprecated=10.13.4)))
#define __AVAILABILITY_INTERNAL__MAC_10_12_DEP__MAC_10_14 __attribute__((availability(macosx,introduced=10.12,deprecated=10.14)))
#define __AVAILABILITY_INTERNAL__MAC_10_12_DEP__MAC_NA __attribute__((availability(macosx,introduced=10.12)))
#define __AVAILABILITY_INTERNAL__MAC_10_12_DEP__MAC_NA_MSG(_msg) __attribute__((availability(macosx,introduced=10.12)))
#define __AVAILABILITY_INTERNAL__MAC_10_13 __attribute__((availability(macosx,introduced=10.13)))
#define __AVAILABILITY_INTERNAL__MAC_10_13_4 __attribute__((availability(macosx,introduced=10.13.4)))
#define __AVAILABILITY_INTERNAL__MAC_10_14 __attribute__((availability(macosx,introduced=10.14)))
#define __AVAILABILITY_INTERNAL__MAC_10_14_DEP__MAC_10_14 __attribute__((availability(macosx,introduced=10.14,deprecated=10.14)))
#define __AVAILABILITY_INTERNAL__MAC_10_15 __attribute__((availability(macosx,introduced=10.15)))
#define __AVAILABILITY_INTERNAL__MAC_NA __attribute__((availability(macosx,unavailable)))
#define __AVAILABILITY_INTERNAL__MAC_NA_DEP__MAC_NA __attribute__((availability(macosx,unavailable)))
#define __AVAILABILITY_INTERNAL__MAC_NA_DEP__MAC_NA_MSG(_msg) __attribute__((availability(macosx,unavailable)))
#define __AVAILABILITY_INTERNAL__IPHONE_NA __attribute__((availability(ios,unavailable)))
#define __AVAILABILITY_INTERNAL__IPHONE_NA__IPHONE_NA __attribute__((availability(ios,unavailable)))
#define __AVAILABILITY_INTERNAL__IPHONE_NA_DEP__IPHONE_NA __attribute__((availability(ios,unavailable)))
#define __AVAILABILITY_INTERNAL__IPHONE_NA_DEP__IPHONE_NA_MSG(_msg) __attribute__((availability(ios,unavailable)))
#define __AVAILABILITY_INTERNAL__IPHONE_COMPAT_VERSION __attribute__((availability(ios,unavailable)))
#define __AVAILABILITY_INTERNAL__IPHONE_COMPAT_VERSION_DEP__IPHONE_COMPAT_VERSION __attribute__((availability(ios,unavailable)))
#define __AVAILABILITY_INTERNAL__IPHONE_COMPAT_VERSION_DEP__IPHONE_COMPAT_VERSION_MSG(_msg) __attribute__((availability(ios,unavailable)))
#define __API_AVAILABLE_PLATFORM_macos(x) macos,introduced=x
#define __API_AVAILABLE_PLATFORM_macosx(x) macosx,introduced=x
#define __API_AVAILABLE_PLATFORM_ios(x) ios,introduced=x
#define __API_AVAILABLE_PLATFORM_watchos(x) watchos,introduced=x
#define __API_AVAILABLE_PLATFORM_tvos(x) tvos,introduced=x
#define __API_AVAILABLE_PLATFORM_macCatalyst(x) macCatalyst,introduced=x
#define __API_AVAILABLE_PLATFORM_macCatalyst(x) macCatalyst,introduced=x
#define __API_AVAILABLE_PLATFORM_uikitformac(x) uikitformac,introduced=x
#define __API_AVAILABLE_PLATFORM_driverkit(x) driverkit,introduced=x
#define __API_A(x) __attribute__((availability(__API_AVAILABLE_PLATFORM_##x)))
#define __API_AVAILABLE1(x) __API_A(x)
#define __API_AVAILABLE2(x,y) __API_A(x) __API_A(y)
#define __API_AVAILABLE3(x,y,z) __API_A(x) __API_A(y) __API_A(z)
#define __API_AVAILABLE4(x,y,z,t) __API_A(x) __API_A(y) __API_A(z) __API_A(t)
#define __API_AVAILABLE5(x,y,z,t,b) __API_A(x) __API_A(y) __API_A(z) __API_A(t) __API_A(b)
#define __API_AVAILABLE6(x,y,z,t,b,m) __API_A(x) __API_A(y) __API_A(z) __API_A(t) __API_A(b) __API_A(m)
#define __API_AVAILABLE7(x,y,z,t,b,m,d) __API_A(x) __API_A(y) __API_A(z) __API_A(t) __API_A(b) __API_A(m) __API_A(d)
#define __API_AVAILABLE_GET_MACRO(_1,_2,_3,_4,_5,_6,_7,NAME,...) NAME
#define __API_APPLY_TO any(record, enum, enum_constant, function, objc_method, objc_category, objc_protocol, objc_interface, objc_property, type_alias, variable, field)
#define __API_RANGE_STRINGIFY(x) __API_RANGE_STRINGIFY2(x)
#define __API_RANGE_STRINGIFY2(x) #x
#define __API_A_BEGIN(x) _Pragma(__API_RANGE_STRINGIFY (clang attribute (__attribute__((availability(__API_AVAILABLE_PLATFORM_##x))), apply_to = __API_APPLY_TO)))
#define __API_AVAILABLE_BEGIN1(a) __API_A_BEGIN(a)
#define __API_AVAILABLE_BEGIN2(a,b) __API_A_BEGIN(a) __API_A_BEGIN(b)
#define __API_AVAILABLE_BEGIN3(a,b,c) __API_A_BEGIN(a) __API_A_BEGIN(b) __API_A_BEGIN(c)
#define __API_AVAILABLE_BEGIN4(a,b,c,d) __API_A_BEGIN(a) __API_A_BEGIN(b) __API_A_BEGIN(c) __API_A_BEGIN(d)
#define __API_AVAILABLE_BEGIN5(a,b,c,d,e) __API_A_BEGIN(a) __API_A_BEGIN(b) __API_A_BEGIN(c) __API_A_BEGIN(d) __API_A_BEGIN(e)
#define __API_AVAILABLE_BEGIN6(a,b,c,d,e,f) __API_A_BEGIN(a) __API_A_BEGIN(b) __API_A_BEGIN(c) __API_A_BEGIN(d) __API_A_BEGIN(e) __API_A_BEGIN(f)
#define __API_AVAILABLE_BEGIN7(a,b,c,d,e,f,g) __API_A_BEGIN(a) __API_A_BEGIN(b) __API_A_BEGIN(c) __API_A_BEGIN(d) __API_A_BEGIN(e) __API_A_BEGIN(f) __API_A_BEGIN(g)
#define __API_AVAILABLE_BEGIN_GET_MACRO(_1,_2,_3,_4,_5,_6,_7,NAME,...) NAME
#define __API_DEPRECATED_PLATFORM_macos(x,y) macos,introduced=x,deprecated=y
#define __API_DEPRECATED_PLATFORM_macosx(x,y) macosx,introduced=x,deprecated=y
#define __API_DEPRECATED_PLATFORM_ios(x,y) ios,introduced=x,deprecated=y
#define __API_DEPRECATED_PLATFORM_watchos(x,y) watchos,introduced=x,deprecated=y
#define __API_DEPRECATED_PLATFORM_tvos(x,y) tvos,introduced=x,deprecated=y
#define __API_DEPRECATED_PLATFORM_macCatalyst(x,y) macCatalyst,introduced=x,deprecated=y
#define __API_DEPRECATED_PLATFORM_macCatalyst(x,y) macCatalyst,introduced=x,deprecated=y
#define __API_DEPRECATED_PLATFORM_uikitformac(x) uikitformac,introduced=x,deprecated=y
#define __API_DEPRECATED_PLATFORM_driverkit(x,y) driverkit,introduced=x,deprecated=y
#define __API_D(msg,x) __attribute__((availability(__API_DEPRECATED_PLATFORM_##x,message=msg)))
#define __API_DEPRECATED_MSG2(msg,x) __API_D(msg,x)
#define __API_DEPRECATED_MSG3(msg,x,y) __API_D(msg,x) __API_D(msg,y)
#define __API_DEPRECATED_MSG4(msg,x,y,z) __API_DEPRECATED_MSG3(msg,x,y) __API_D(msg,z)
#define __API_DEPRECATED_MSG5(msg,x,y,z,t) __API_DEPRECATED_MSG4(msg,x,y,z) __API_D(msg,t)
#define __API_DEPRECATED_MSG6(msg,x,y,z,t,b) __API_DEPRECATED_MSG5(msg,x,y,z,t) __API_D(msg,b)
#define __API_DEPRECATED_MSG7(msg,x,y,z,t,b,m) __API_DEPRECATED_MSG6(msg,x,y,z,t,b) __API_D(msg,m)
#define __API_DEPRECATED_MSG8(msg,x,y,z,t,b,m,d) __API_DEPRECATED_MSG7(msg,x,y,z,t,b,m) __API_D(msg,d)
#define __API_DEPRECATED_MSG_GET_MACRO(_1,_2,_3,_4,_5,_6,_7,_8,NAME,...) NAME
#define __API_D_BEGIN(msg,x) _Pragma(__API_RANGE_STRINGIFY (clang attribute (__attribute__((availability(__API_DEPRECATED_PLATFORM_##x,message=msg))), apply_to = __API_APPLY_TO)))
#define __API_DEPRECATED_BEGIN_MSG2(msg,a) __API_D_BEGIN(msg,a)
#define __API_DEPRECATED_BEGIN_MSG3(msg,a,b) __API_D_BEGIN(msg,a) __API_D_BEGIN(msg,b)
#define __API_DEPRECATED_BEGIN_MSG4(msg,a,b,c) __API_D_BEGIN(msg,a) __API_D_BEGIN(msg,b) __API_D_BEGIN(msg,c)
#define __API_DEPRECATED_BEGIN_MSG5(msg,a,b,c,d) __API_D_BEGIN(msg,a) __API_D_BEGIN(msg,b) __API_D_BEGIN(msg,c) __API_D_BEGIN(msg,d)
#define __API_DEPRECATED_BEGIN_MSG6(msg,a,b,c,d,e) __API_D_BEGIN(msg,a) __API_D_BEGIN(msg,b) __API_D_BEGIN(msg,c) __API_D_BEGIN(msg,d) __API_D_BEGIN(msg,e)
#define __API_DEPRECATED_BEGIN_MSG7(msg,a,b,c,d,e,f) __API_D_BEGIN(msg,a) __API_D_BEGIN(msg,b) __API_D_BEGIN(msg,c) __API_D_BEGIN(msg,d) __API_D_BEGIN(msg,e) __API_D_BEGIN(msg,f)
#define __API_DEPRECATED_BEGIN_MSG8(msg,a,b,c,d,e,f,g) __API_D_BEGIN(msg,a) __API_D_BEGIN(msg,b) __API_D_BEGIN(msg,c) __API_D_BEGIN(msg,d) __API_D_BEGIN(msg,e) __API_D_BEGIN(msg,f) __API_D_BEGIN(msg,g)
#define __API_DEPRECATED_BEGIN_MSG_GET_MACRO(_1,_2,_3,_4,_5,_6,_7,_8,NAME,...) NAME
#define __API_R(rep,x) __attribute__((availability(__API_DEPRECATED_PLATFORM_##x,replacement=rep)))
#define __API_DEPRECATED_REP2(rep,x) __API_R(rep,x)
#define __API_DEPRECATED_REP3(rep,x,y) __API_R(rep,x) __API_R(rep,y)
#define __API_DEPRECATED_REP4(rep,x,y,z) __API_DEPRECATED_REP3(rep,x,y) __API_R(rep,z)
#define __API_DEPRECATED_REP5(rep,x,y,z,t) __API_DEPRECATED_REP4(rep,x,y,z) __API_R(rep,t)
#define __API_DEPRECATED_REP6(rep,x,y,z,t,b) __API_DEPRECATED_REP5(rep,x,y,z,t) __API_R(rep,b)
#define __API_DEPRECATED_REP7(rep,x,y,z,t,b,m) __API_DEPRECATED_REP6(rep,x,y,z,t,b) __API_R(rep,m)
#define __API_DEPRECATED_REP8(rep,x,y,z,t,b,m,d) __API_DEPRECATED_REP7(rep,x,y,z,t,b,m) __API_R(rep,d)
#define __API_DEPRECATED_REP_GET_MACRO(_1,_2,_3,_4,_5,_6,_7,_8,NAME,...) NAME
#define __API_R_BEGIN(rep,x) _Pragma(__API_RANGE_STRINGIFY (clang attribute (__attribute__((availability(__API_DEPRECATED_PLATFORM_##x,replacement=rep))), apply_to = __API_APPLY_TO)))
#define __API_DEPRECATED_BEGIN_REP2(rep,a) __API_R_BEGIN(rep,a)
#define __API_DEPRECATED_BEGIN_REP3(rep,a,b) __API_R_BEGIN(rep,a) __API_R_BEGIN(rep,b)
#define __API_DEPRECATED_BEGIN_REP4(rep,a,b,c) __API_R_BEGIN(rep,a) __API_R_BEGIN(rep,b) __API_R_BEGIN(rep,c)
#define __API_DEPRECATED_BEGIN_REP5(rep,a,b,c,d) __API_R_BEGIN(rep,a) __API_R_BEGIN(rep,b) __API_R_BEGIN(rep,c) __API_R_BEGIN(rep,d)
#define __API_DEPRECATED_BEGIN_REP6(rep,a,b,c,d,e) __API_R_BEGIN(rep,a) __API_R_BEGIN(rep,b) __API_R_BEGIN(rep,c) __API_R_BEGIN(rep,d) __API_R_BEGIN(rep,e)
#define __API_DEPRECATED_BEGIN_REP7(rep,a,b,c,d,e,f) __API_R_BEGIN(rep,a) __API_R_BEGIN(rep,b) __API_R_BEGIN(rep,c) __API_R_BEGIN(rep,d) __API_R_BEGIN(rep,e) __API_R_BEGIN(rep,f)
#define __API_DEPRECATED_BEGIN_REP8(rep,a,b,c,d,e,f,g) __API_R_BEGIN(rep,a) __API_R_BEGIN(rep,b) __API_R_BEGIN(rep,c) __API_R_BEGIN(rep,d) __API_R_BEGIN(rep,e) __API_R_BEGIN(rep,f) __API_R_BEGIN(rep,g)
#define __API_DEPRECATED_BEGIN_REP_GET_MACRO(_1,_2,_3,_4,_5,_6,_7,_8,NAME,...) NAME
#define __API_UNAVAILABLE_PLATFORM_macos macos,unavailable
#define __API_UNAVAILABLE_PLATFORM_macosx macosx,unavailable
#define __API_UNAVAILABLE_PLATFORM_ios ios,unavailable
#define __API_UNAVAILABLE_PLATFORM_watchos watchos,unavailable
#define __API_UNAVAILABLE_PLATFORM_tvos tvos,unavailable
#define __API_UNAVAILABLE_PLATFORM_macCatalyst macCatalyst,unavailable
#define __API_UNAVAILABLE_PLATFORM_macCatalyst macCatalyst,unavailable
#define __API_UNAVAILABLE_PLATFORM_uikitformac(x) uikitformac,unavailable
#define __API_UNAVAILABLE_PLATFORM_driverkit driverkit,unavailable
#define __API_U(x) __attribute__((availability(__API_UNAVAILABLE_PLATFORM_##x)))
#define __API_UNAVAILABLE1(x) __API_U(x)
#define __API_UNAVAILABLE2(x,y) __API_U(x) __API_U(y)
#define __API_UNAVAILABLE3(x,y,z) __API_UNAVAILABLE2(x,y) __API_U(z)
#define __API_UNAVAILABLE4(x,y,z,t) __API_UNAVAILABLE3(x,y,z) __API_U(t)
#define __API_UNAVAILABLE5(x,y,z,t,b) __API_UNAVAILABLE4(x,y,z,t) __API_U(b)
#define __API_UNAVAILABLE6(x,y,z,t,b,m) __API_UNAVAILABLE5(x,y,z,t,b) __API_U(m)
#define __API_UNAVAILABLE7(x,y,z,t,b,m,d) __API_UNAVAILABLE6(x,y,z,t,b,m) __API_U(d)
#define __API_UNAVAILABLE_GET_MACRO(_1,_2,_3,_4,_5,_6,_7,NAME,...) NAME
#define __API_U_BEGIN(x) _Pragma(__API_RANGE_STRINGIFY (clang attribute (__attribute__((availability(__API_UNAVAILABLE_PLATFORM_##x))), apply_to = __API_APPLY_TO)))
#define __API_UNAVAILABLE_BEGIN1(a) __API_U_BEGIN(a)
#define __API_UNAVAILABLE_BEGIN2(a,b) __API_U_BEGIN(a) __API_U_BEGIN(b)
#define __API_UNAVAILABLE_BEGIN3(a,b,c) __API_U_BEGIN(a) __API_U_BEGIN(b) __API_U_BEGIN(c)
#define __API_UNAVAILABLE_BEGIN4(a,b,c,d) __API_U_BEGIN(a) __API_U_BEGIN(b) __API_U_BEGIN(c) __API_U_BEGIN(d)
#define __API_UNAVAILABLE_BEGIN5(a,b,c,d,e) __API_U_BEGIN(a) __API_U_BEGIN(b) __API_U_BEGIN(c) __API_U_BEGIN(d) __API_U_BEGIN(e)
#define __API_UNAVAILABLE_BEGIN6(a,b,c,d,e,f) __API_U_BEGIN(a) __API_U_BEGIN(b) __API_U_BEGIN(c) __API_U_BEGIN(d) __API_U_BEGIN(e) __API_U_BEGIN(f)
#define __API_UNAVAILABLE_BEGIN7(a,b,c,d,e,f) __API_U_BEGIN(a) __API_U_BEGIN(b) __API_U_BEGIN(c) __API_U_BEGIN(d) __API_U_BEGIN(e) __API_U_BEGIN(f) __API_U_BEGIN(g)
#define __API_UNAVAILABLE_BEGIN_GET_MACRO(_1,_2,_3,_4,_5,_6,_7,NAME,...) NAME
#define __swift_compiler_version_at_least(...) 1
#define __SPI_AVAILABLE(...) 
#define __OSX_AVAILABLE_STARTING(_osx,_ios) __AVAILABILITY_INTERNAL##_osx
#define __OSX_AVAILABLE_BUT_DEPRECATED(_osxIntro,_osxDep,_iosIntro,_iosDep) __AVAILABILITY_INTERNAL##_osxIntro##_DEP##_osxDep
#define __OSX_AVAILABLE_BUT_DEPRECATED_MSG(_osxIntro,_osxDep,_iosIntro,_iosDep,_msg) __AVAILABILITY_INTERNAL##_osxIntro##_DEP##_osxDep##_MSG(_msg)
#define __OS_AVAILABILITY(_target,_availability) __attribute__((availability(_target,_availability)))
#define __OS_AVAILABILITY_MSG(_target,_availability,_msg) __attribute__((availability(_target,_availability,message=_msg)))
#define __OSX_EXTENSION_UNAVAILABLE(_msg) __OS_AVAILABILITY_MSG(macosx_app_extension,unavailable,_msg)
#define __IOS_EXTENSION_UNAVAILABLE(_msg) __OS_AVAILABILITY_MSG(ios_app_extension,unavailable,_msg)
#define __OS_EXTENSION_UNAVAILABLE(_msg) __OSX_EXTENSION_UNAVAILABLE(_msg) __IOS_EXTENSION_UNAVAILABLE(_msg)
#define __OSX_UNAVAILABLE __OS_AVAILABILITY(macosx,unavailable)
#define __OSX_AVAILABLE(_vers) __OS_AVAILABILITY(macosx,introduced=_vers)
#define __OSX_DEPRECATED(_start,_dep,_msg) __OSX_AVAILABLE(_start) __OS_AVAILABILITY_MSG(macosx,deprecated=_dep,_msg)
#define __IOS_UNAVAILABLE __OS_AVAILABILITY(ios,unavailable)
#define __IOS_PROHIBITED __OS_AVAILABILITY(ios,unavailable)
#define __IOS_AVAILABLE(_vers) __OS_AVAILABILITY(ios,introduced=_vers)
#define __IOS_DEPRECATED(_start,_dep,_msg) __IOS_AVAILABLE(_start) __OS_AVAILABILITY_MSG(ios,deprecated=_dep,_msg)
#define __TVOS_UNAVAILABLE __OS_AVAILABILITY(tvos,unavailable)
#define __TVOS_PROHIBITED __OS_AVAILABILITY(tvos,unavailable)
#define __TVOS_AVAILABLE(_vers) __OS_AVAILABILITY(tvos,introduced=_vers)
#define __TVOS_DEPRECATED(_start,_dep,_msg) __TVOS_AVAILABLE(_start) __OS_AVAILABILITY_MSG(tvos,deprecated=_dep,_msg)
#define __WATCHOS_UNAVAILABLE __OS_AVAILABILITY(watchos,unavailable)
#define __WATCHOS_PROHIBITED __OS_AVAILABILITY(watchos,unavailable)
#define __WATCHOS_AVAILABLE(_vers) __OS_AVAILABILITY(watchos,introduced=_vers)
#define __WATCHOS_DEPRECATED(_start,_dep,_msg) __WATCHOS_AVAILABLE(_start) __OS_AVAILABILITY_MSG(watchos,deprecated=_dep,_msg)
#define __SWIFT_UNAVAILABLE __OS_AVAILABILITY(swift,unavailable)
#define __SWIFT_UNAVAILABLE_MSG(_msg) __OS_AVAILABILITY_MSG(swift,unavailable,_msg)
#define __API_AVAILABLE(...) __API_AVAILABLE_GET_MACRO(__VA_ARGS__,__API_AVAILABLE7, __API_AVAILABLE6, __API_AVAILABLE5, __API_AVAILABLE4, __API_AVAILABLE3, __API_AVAILABLE2, __API_AVAILABLE1, 0)(__VA_ARGS__)
#define __API_AVAILABLE_BEGIN(...) _Pragma("clang attribute push") __API_AVAILABLE_BEGIN_GET_MACRO(__VA_ARGS__,__API_AVAILABLE_BEGIN7, __API_AVAILABLE_BEGIN6, __API_AVAILABLE_BEGIN5, __API_AVAILABLE_BEGIN4, __API_AVAILABLE_BEGIN3, __API_AVAILABLE_BEGIN2, __API_AVAILABLE_BEGIN1, 0)(__VA_ARGS__)
#define __API_AVAILABLE_END _Pragma("clang attribute pop")
#define __API_DEPRECATED(...) __API_DEPRECATED_MSG_GET_MACRO(__VA_ARGS__,__API_DEPRECATED_MSG8,__API_DEPRECATED_MSG7,__API_DEPRECATED_MSG6,__API_DEPRECATED_MSG5,__API_DEPRECATED_MSG4,__API_DEPRECATED_MSG3,__API_DEPRECATED_MSG2,__API_DEPRECATED_MSG1, 0)(__VA_ARGS__)
#define __API_DEPRECATED_WITH_REPLACEMENT(...) __API_DEPRECATED_REP_GET_MACRO(__VA_ARGS__,__API_DEPRECATED_REP8,__API_DEPRECATED_REP7,__API_DEPRECATED_REP6,__API_DEPRECATED_REP5,__API_DEPRECATED_REP4,__API_DEPRECATED_REP3,__API_DEPRECATED_REP2,__API_DEPRECATED_REP1, 0)(__VA_ARGS__)
#define __API_DEPRECATED_BEGIN(...) _Pragma("clang attribute push") __API_DEPRECATED_BEGIN_MSG_GET_MACRO(__VA_ARGS__,__API_DEPRECATED_BEGIN_MSG8,__API_DEPRECATED_BEGIN_MSG7, __API_DEPRECATED_BEGIN_MSG6, __API_DEPRECATED_BEGIN_MSG5, __API_DEPRECATED_BEGIN_MSG4, __API_DEPRECATED_BEGIN_MSG3, __API_DEPRECATED_BEGIN_MSG2, __API_DEPRECATED_BEGIN_MSG1, 0)(__VA_ARGS__)
#define __API_DEPRECATED_END _Pragma("clang attribute pop")
#define __API_DEPRECATED_WITH_REPLACEMENT_BEGIN(...) _Pragma("clang attribute push") __API_DEPRECATED_BEGIN_REP_GET_MACRO(__VA_ARGS__,__API_DEPRECATED_BEGIN_REP8,__API_DEPRECATED_BEGIN_REP7, __API_DEPRECATED_BEGIN_REP6, __API_DEPRECATED_BEGIN_REP5, __API_DEPRECATED_BEGIN_REP4, __API_DEPRECATED_BEGIN_REP3, __API_DEPRECATED_BEGIN_REP2, __API_DEPRECATED_BEGIN_REP1, 0)(__VA_ARGS__)
#define __API_DEPRECATED_WITH_REPLACEMENT_END _Pragma("clang attribute pop")
#define __API_UNAVAILABLE(...) __API_UNAVAILABLE_GET_MACRO(__VA_ARGS__,__API_UNAVAILABLE7,__API_UNAVAILABLE6,__API_UNAVAILABLE5,__API_UNAVAILABLE4,__API_UNAVAILABLE3,__API_UNAVAILABLE2,__API_UNAVAILABLE1, 0)(__VA_ARGS__)
#define __API_UNAVAILABLE_BEGIN(...) _Pragma("clang attribute push") __API_UNAVAILABLE_BEGIN_GET_MACRO(__VA_ARGS__,__API_UNAVAILABLE_BEGIN7,__API_UNAVAILABLE_BEGIN6, __API_UNAVAILABLE_BEGIN5, __API_UNAVAILABLE_BEGIN4, __API_UNAVAILABLE_BEGIN3, __API_UNAVAILABLE_BEGIN2, __API_UNAVAILABLE_BEGIN1, 0)(__VA_ARGS__)
#define __API_UNAVAILABLE_END _Pragma("clang attribute pop")
#define __SPI_DEPRECATED(...) 
#define __SPI_DEPRECATED_WITH_REPLACEMENT(...) 
#define __TYPES_H_ 
#define _SYS__TYPES_H_ 
#define _BSD_MACHINE__TYPES_H_ 
#define _BSD_ARM__TYPES_H_ 
#define __DARWIN_NULL ((void *)0)
#define _SYS__PTHREAD_TYPES_H_ 
#define __PTHREAD_SIZE__ 8176
#define __PTHREAD_ATTR_SIZE__ 56
#define __PTHREAD_MUTEXATTR_SIZE__ 8
#define __PTHREAD_MUTEX_SIZE__ 56
#define __PTHREAD_CONDATTR_SIZE__ 8
#define __PTHREAD_COND_SIZE__ 40
#define __PTHREAD_ONCE_SIZE__ 8
#define __PTHREAD_RWLOCK_SIZE__ 192
#define __PTHREAD_RWLOCKATTR_SIZE__ 16
#define __offsetof(type,field) __builtin_offsetof(type, field)
#define __strfmonlike(fmtarg,firstvararg) __attribute__((__format__ (__strfmon__, fmtarg, firstvararg)))
#define __strftimelike(fmtarg) __attribute__((__format__ (__strftime__, fmtarg, 0)))
#define __DARWIN_WCHAR_MAX __WCHAR_MAX__
#define __DARWIN_WCHAR_MIN (-0x7fffffff - 1)
#define __DARWIN_WEOF ((__darwin_wint_t)-1)
#define _VA_LIST_T 
#define _BSD_MACHINE_TYPES_H_ 
#define _MACHTYPES_H_ 
#define _INT8_T 
#define _INT16_T 
#define _INT32_T 
#define _INT64_T 
#define _U_INT8_T 
#define _U_INT16_T 
#define _U_INT32_T 
#define _U_INT64_T 
#define _INTPTR_T 
#define _UINTPTR_T 
#define USER_ADDR_NULL ((user_addr_t) 0)
#define CAST_USER_ADDR_T(a_ptr) ((user_addr_t)((uintptr_t)(a_ptr)))
#define _SIZE_T 
#define NULL __DARWIN_NULL
#define _SYS_STDIO_H_ 
#define RENAME_SECLUDE 0x00000001
#define RENAME_SWAP 0x00000002
#define RENAME_EXCL 0x00000004
#define _FSTDIO 
#define __SLBF 0x0001
#define __SNBF 0x0002
#define __SRD 0x0004
#define __SWR 0x0008
#define __SRW 0x0010
#define __SEOF 0x0020
#define __SERR 0x0040
#define __SMBF 0x0080
#define __SAPP 0x0100
#define __SSTR 0x0200
#define __SOPT 0x0400
#define __SNPT 0x0800
#define __SOFF 0x1000
#define __SMOD 0x2000
#define __SALC 0x4000
#define __SIGN 0x8000
#define _IOFBF 0
#define _IOLBF 1
#define _IONBF 2
#define BUFSIZ 1024
#define EOF (-1)
#define FOPEN_MAX 20
#define FILENAME_MAX 1024
#define P_tmpdir "/var/tmp/"
#define L_tmpnam 1024
#define TMP_MAX 308915776
#define SEEK_SET 0
#define SEEK_CUR 1
#define SEEK_END 2
#define stdin __stdinp
#define stdout __stdoutp
#define stderr __stderrp
#define L_ctermid 1024
#define _CTERMID_H_ 
#define __swift_unavailable_on(osx_msg,ios_msg) __swift_unavailable(osx_msg)
#undef __swift_unavailable_on
#define __sgetc(p) (--(p)->_r < 0 ? __srget(p) : (int)(*(p)->_p++))
#define __sfeof(p) (((p)->_flags & __SEOF) != 0)
#define __sferror(p) (((p)->_flags & __SERR) != 0)
#define __sclearerr(p) ((void)((p)->_flags &= ~(__SERR|__SEOF)))
#define __sfileno(p) ((p)->_file)
#define getc_unlocked(fp) __sgetc(fp)
#define putc_unlocked(x,fp) __sputc(x, fp)
#define getchar_unlocked() getc_unlocked(stdin)
#define putchar_unlocked(x) putc_unlocked(x, stdout)
#define _OFF_T 
#define _SSIZE_T 
#define fropen(cookie,fn) funopen(cookie, fn, 0, 0, 0)
#define fwopen(cookie,fn) funopen(cookie, 0, fn, 0, 0)
#define feof_unlocked(p) __sfeof(p)
#define ferror_unlocked(p) __sferror(p)
#define clearerr_unlocked(p) __sclearerr(p)
#define fileno_unlocked(p) __sfileno(p)
#define _SECURE__STDIO_H_ 
#define _SECURE__COMMON_H_ 
#undef _USE_FORTIFY_LEVEL
#define _USE_FORTIFY_LEVEL 2
#define __darwin_obsz0(object) __builtin_object_size (object, 0)
#define __darwin_obsz(object) __builtin_object_size (object, _USE_FORTIFY_LEVEL > 1 ? 1 : 0)
#undef sprintf
#define sprintf(str,...) __builtin___sprintf_chk (str, 0, __darwin_obsz(str), __VA_ARGS__)
#undef snprintf
#define snprintf(str,len,...) __builtin___snprintf_chk (str, len, 0, __darwin_obsz(str), __VA_ARGS__)
#undef vsprintf
#define vsprintf(str,format,ap) __builtin___vsprintf_chk (str, 0, __darwin_obsz(str), format, ap)
#undef vsnprintf
#define vsnprintf(str,len,format,ap) __builtin___vsnprintf_chk (str, len, 0, __darwin_obsz(str), format, ap)
#define _SYS_TYPES_H_ 
#define __SYS_APPLEAPIOPTS_H__ 
#define __APPLE_API_STANDARD 
#define __APPLE_API_STABLE 
#define __APPLE_API_EVOLVING 
#define __APPLE_API_UNSTABLE 
#define __APPLE_API_PRIVATE 
#define __APPLE_API_OBSOLETE 
#define _BSD_MACHINE_ENDIAN_H_ 
#define _ARM__ENDIAN_H_ 
#define _QUAD_HIGHWORD 1
#define _QUAD_LOWWORD 0
#define __DARWIN_LITTLE_ENDIAN 1234
#define __DARWIN_BIG_ENDIAN 4321
#define __DARWIN_PDP_ENDIAN 3412
#define __DARWIN_BYTE_ORDER __DARWIN_LITTLE_ENDIAN
#define LITTLE_ENDIAN __DARWIN_LITTLE_ENDIAN
#define BIG_ENDIAN __DARWIN_BIG_ENDIAN
#define PDP_ENDIAN __DARWIN_PDP_ENDIAN
#define BYTE_ORDER __DARWIN_BYTE_ORDER
#define _SYS__ENDIAN_H_ 
#define _OS__OSBYTEORDER_H 
#define __DARWIN_OSSwapConstInt16(x) ((__uint16_t)((((__uint16_t)(x) & 0xff00U) >> 8) | (((__uint16_t)(x) & 0x00ffU) << 8)))
#define __DARWIN_OSSwapConstInt32(x) ((__uint32_t)((((__uint32_t)(x) & 0xff000000U) >> 24) | (((__uint32_t)(x) & 0x00ff0000U) >> 8) | (((__uint32_t)(x) & 0x0000ff00U) << 8) | (((__uint32_t)(x) & 0x000000ffU) << 24)))
#define __DARWIN_OSSwapConstInt64(x) ((__uint64_t)((((__uint64_t)(x) & 0xff00000000000000ULL) >> 56) | (((__uint64_t)(x) & 0x00ff000000000000ULL) >> 40) | (((__uint64_t)(x) & 0x0000ff0000000000ULL) >> 24) | (((__uint64_t)(x) & 0x000000ff00000000ULL) >> 8) | (((__uint64_t)(x) & 0x00000000ff000000ULL) << 8) | (((__uint64_t)(x) & 0x0000000000ff0000ULL) << 24) | (((__uint64_t)(x) & 0x000000000000ff00ULL) << 40) | (((__uint64_t)(x) & 0x00000000000000ffULL) << 56)))
#define __DARWIN_OS_INLINE static inline
#define _OS_OSBYTEORDERARM_H 
#define __CLANG_STDINT_H 
#define _STDINT_H_ 
#define __WORDSIZE 64
#define _UINT8_T 
#define _UINT16_T 
#define _UINT32_T 
#define _UINT64_T 
#define _INTMAX_T 
#define _UINTMAX_T 
#define INT8_C(v) (v)
#define INT16_C(v) (v)
#define INT32_C(v) (v)
#define INT64_C(v) (v ## LL)
#define UINT8_C(v) (v)
#define UINT16_C(v) (v)
#define UINT32_C(v) (v ## U)
#define UINT64_C(v) (v ## ULL)
#define INTMAX_C(v) (v ## L)
#define UINTMAX_C(v) (v ## UL)
#define INT8_MAX 127
#define INT16_MAX 32767
#define INT32_MAX 2147483647
#define INT64_MAX 9223372036854775807LL
#define INT8_MIN -128
#define INT16_MIN -32768
#define INT32_MIN (-INT32_MAX-1)
#define INT64_MIN (-INT64_MAX-1)
#define UINT8_MAX 255
#define UINT16_MAX 65535
#define UINT32_MAX 4294967295U
#define UINT64_MAX 18446744073709551615ULL
#define INT_LEAST8_MIN INT8_MIN
#define INT_LEAST16_MIN INT16_MIN
#define INT_LEAST32_MIN INT32_MIN
#define INT_LEAST64_MIN INT64_MIN
#define INT_LEAST8_MAX INT8_MAX
#define INT_LEAST16_MAX INT16_MAX
#define INT_LEAST32_MAX INT32_MAX
#define INT_LEAST64_MAX INT64_MAX
#define UINT_LEAST8_MAX UINT8_MAX
#define UINT_LEAST16_MAX UINT16_MAX
#define UINT_LEAST32_MAX UINT32_MAX
#define UINT_LEAST64_MAX UINT64_MAX
#define INT_FAST8_MIN INT8_MIN
#define INT_FAST16_MIN INT16_MIN
#define INT_FAST32_MIN INT32_MIN
#define INT_FAST64_MIN INT64_MIN
#define INT_FAST8_MAX INT8_MAX
#define INT_FAST16_MAX INT16_MAX
#define INT_FAST32_MAX INT32_MAX
#define INT_FAST64_MAX INT64_MAX
#define UINT_FAST8_MAX UINT8_MAX
#define UINT_FAST16_MAX UINT16_MAX
#define UINT_FAST32_MAX UINT32_MAX
#define UINT_FAST64_MAX UINT64_MAX
#define INTPTR_MAX 9223372036854775807L
#define INTPTR_MIN (-INTPTR_MAX-1)
#define UINTPTR_MAX 18446744073709551615UL
#define INTMAX_MAX INTMAX_C(9223372036854775807)
#define UINTMAX_MAX UINTMAX_C(18446744073709551615)
#define INTMAX_MIN (-INTMAX_MAX-1)
#define PTRDIFF_MIN INTMAX_MIN
#define PTRDIFF_MAX INTMAX_MAX
#define SIZE_MAX UINTPTR_MAX
#define RSIZE_MAX (SIZE_MAX >> 1)
#define WCHAR_MAX __WCHAR_MAX__
#define WCHAR_MIN (-WCHAR_MAX-1)
#define WINT_MIN INT32_MIN
#define WINT_MAX INT32_MAX
#define SIG_ATOMIC_MIN INT32_MIN
#define SIG_ATOMIC_MAX INT32_MAX
#define _ARM_ARCH_H 
#define __DARWIN_OSSwapInt16(x) ((__uint16_t)(__builtin_constant_p(x) ? __DARWIN_OSSwapConstInt16(x) : _OSSwapInt16(x)))
#define __DARWIN_OSSwapInt32(x) (__builtin_constant_p(x) ? __DARWIN_OSSwapConstInt32(x) : _OSSwapInt32(x))
#define __DARWIN_OSSwapInt64(x) (__builtin_constant_p(x) ? __DARWIN_OSSwapConstInt64(x) : _OSSwapInt64(x))
#define ntohs(x) __DARWIN_OSSwapInt16(x)
#define htons(x) __DARWIN_OSSwapInt16(x)
#define ntohl(x) __DARWIN_OSSwapInt32(x)
#define htonl(x) __DARWIN_OSSwapInt32(x)
#define ntohll(x) __DARWIN_OSSwapInt64(x)
#define htonll(x) __DARWIN_OSSwapInt64(x)
#define NTOHL(x) (x) = ntohl((__uint32_t)x)
#define NTOHS(x) (x) = ntohs((__uint16_t)x)
#define NTOHLL(x) (x) = ntohll((__uint64_t)x)
#define HTONL(x) (x) = htonl((__uint32_t)x)
#define HTONS(x) (x) = htons((__uint16_t)x)
#define HTONLL(x) (x) = htonll((__uint64_t)x)
#define _U_CHAR 
#define _U_SHORT 
#define _U_INT 
#define _U_LONG 
#define _CADDR_T 
#define _DEV_T 
#define _BLKCNT_T 
#define _BLKSIZE_T 
#define _GID_T 
#define _IN_ADDR_T 
#define _IN_PORT_T 
#define _INO_T 
#define _INO64_T 
#define _KEY_T 
#define _MODE_T 
#define _NLINK_T 
#define _ID_T 
#define _PID_T 
#define _UID_T 
#define major(x) ((int32_t)(((u_int32_t)(x) >> 24) & 0xff))
#define minor(x) ((int32_t)((x) & 0xffffff))
#define makedev(x,y) ((dev_t)(((x) << 24) | (y)))
#define _CLOCK_T 
#define _TIME_T 
#define _USECONDS_T 
#define _SUSECONDS_T 
#define _RSIZE_T 
#define _ERRNO_T 
#define _FD_SET 
#define __DARWIN_FD_SETSIZE 1024
#define __DARWIN_NBBY 8
#define __DARWIN_NFDBITS (sizeof(__int32_t) * __DARWIN_NBBY)
#define __DARWIN_howmany(x,y) ((((x) % (y)) == 0) ? ((x) / (y)) : (((x) / (y)) + 1))
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunguarded-availability-new"
#pragma clang diagnostic pop
#define __DARWIN_FD_SET(n,p) __darwin_fd_set((n), (p))
#define __DARWIN_FD_CLR(n,p) __darwin_fd_clr((n), (p))
#define __DARWIN_FD_ISSET(n,p) __darwin_fd_isset((n), (p))
#define __DARWIN_FD_ZERO(p) __builtin_bzero(p, sizeof(*(p)))
#define __DARWIN_FD_COPY(f,t) bcopy(f, t, sizeof(*(f)))
#define NBBY __DARWIN_NBBY
#define NFDBITS __DARWIN_NFDBITS
#define howmany(x,y) __DARWIN_howmany(x, y)
#define FD_SETSIZE __DARWIN_FD_SETSIZE
#define FD_SET(n,p) __DARWIN_FD_SET(n, p)
#define FD_CLR(n,p) __DARWIN_FD_CLR(n, p)
#define FD_ZERO(p) __DARWIN_FD_ZERO(p)
#define FD_ISSET(n,p) __DARWIN_FD_ISSET(n, p)
#define FD_COPY(f,t) __DARWIN_FD_COPY(f, t)
#define _PTHREAD_ATTR_T 
#define _PTHREAD_COND_T 
#define _PTHREAD_CONDATTR_T 
#define _PTHREAD_MUTEX_T 
#define _PTHREAD_MUTEXATTR_T 
#define _PTHREAD_ONCE_T 
#define _PTHREAD_RWLOCK_T 
#define _PTHREAD_RWLOCKATTR_T 
#define _PTHREAD_T 
#define _PTHREAD_KEY_T 
#define _FSBLKCNT_T 
#define _FSFILCNT_T 
#define _SYS_STAT_H_ 
#define _STRUCT_TIMESPEC struct timespec
#define __DARWIN_STRUCT_STAT64_TIMES struct timespec st_atimespec; struct timespec st_mtimespec; struct timespec st_ctimespec; struct timespec st_birthtimespec;
#define __DARWIN_STRUCT_STAT64 { dev_t st_dev; mode_t st_mode; nlink_t st_nlink; __darwin_ino64_t st_ino; uid_t st_uid; gid_t st_gid; dev_t st_rdev; __DARWIN_STRUCT_STAT64_TIMES off_t st_size; blkcnt_t st_blocks; blksize_t st_blksize; __uint32_t st_flags; __uint32_t st_gen; __int32_t st_lspare; __int64_t st_qspare[2]; }
#define st_atime st_atimespec.tv_sec
#define st_mtime st_mtimespec.tv_sec
#define st_ctime st_ctimespec.tv_sec
#define st_birthtime st_birthtimespec.tv_sec
#define S_IFMT 0170000
#define S_IFIFO 0010000
#define S_IFCHR 0020000
#define S_IFDIR 0040000
#define S_IFBLK 0060000
#define S_IFREG 0100000
#define S_IFLNK 0120000
#define S_IFSOCK 0140000
#define S_IFWHT 0160000
#define S_IRWXU 0000700
#define S_IRUSR 0000400
#define S_IWUSR 0000200
#define S_IXUSR 0000100
#define S_IRWXG 0000070
#define S_IRGRP 0000040
#define S_IWGRP 0000020
#define S_IXGRP 0000010
#define S_IRWXO 0000007
#define S_IROTH 0000004
#define S_IWOTH 0000002
#define S_IXOTH 0000001
#define S_ISUID 0004000
#define S_ISGID 0002000
#define S_ISVTX 0001000
#define S_ISTXT S_ISVTX
#define S_IREAD S_IRUSR
#define S_IWRITE S_IWUSR
#define S_IEXEC S_IXUSR
#define S_ISBLK(m) (((m) & S_IFMT) == S_IFBLK)
#define S_ISCHR(m) (((m) & S_IFMT) == S_IFCHR)
#define S_ISDIR(m) (((m) & S_IFMT) == S_IFDIR)
#define S_ISFIFO(m) (((m) & S_IFMT) == S_IFIFO)
#define S_ISREG(m) (((m) & S_IFMT) == S_IFREG)
#define S_ISLNK(m) (((m) & S_IFMT) == S_IFLNK)
#define S_ISSOCK(m) (((m) & S_IFMT) == S_IFSOCK)
#define S_ISWHT(m) (((m) & S_IFMT) == S_IFWHT)
#define S_TYPEISMQ(buf) (0)
#define S_TYPEISSEM(buf) (0)
#define S_TYPEISSHM(buf) (0)
#define S_TYPEISTMO(buf) (0)
#define ACCESSPERMS (S_IRWXU|S_IRWXG|S_IRWXO)
#define ALLPERMS (S_ISUID|S_ISGID|S_ISTXT|S_IRWXU|S_IRWXG|S_IRWXO)
#define DEFFILEMODE (S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)
#define S_BLKSIZE 512
#define UF_SETTABLE 0x0000ffff
#define UF_NODUMP 0x00000001
#define UF_IMMUTABLE 0x00000002
#define UF_APPEND 0x00000004
#define UF_OPAQUE 0x00000008
#define UF_COMPRESSED 0x00000020
#define UF_TRACKED 0x00000040
#define UF_DATAVAULT 0x00000080
#define UF_HIDDEN 0x00008000
#define SF_SUPPORTED 0x009f0000
#define SF_SETTABLE 0x3fff0000
#define SF_SYNTHETIC 0xc0000000
#define SF_ARCHIVED 0x00010000
#define SF_IMMUTABLE 0x00020000
#define SF_APPEND 0x00040000
#define SF_RESTRICTED 0x00080000
#define SF_NOUNLINK 0x00100000
#define SF_FIRMLINK 0x00800000
#define SF_DATALESS 0x40000000
#define EF_MAY_SHARE_BLOCKS 0x00000001
#define EF_NO_XATTRS 0x00000002
#define EF_IS_SYNC_ROOT 0x00000004
#define EF_IS_PURGEABLE 0x00000008
#define EF_IS_SPARSE 0x00000010
#define EF_IS_SYNTHETIC 0x00000020
#define UTIME_NOW -1
#define UTIME_OMIT -2
#define _FILESEC_T 
#define _STDLIB_H_ 
#define _SYS_WAIT_H_ 
#define _SYS_SIGNAL_H_ 
#define __DARWIN_NSIG 32
#define NSIG __DARWIN_NSIG
#define _BSD_MACHINE_SIGNAL_H_ 
#define _ARM_SIGNAL_ 1
#define SIGHUP 1
#define SIGINT 2
#define SIGQUIT 3
#define SIGILL 4
#define SIGTRAP 5
#define SIGABRT 6
#define SIGIOT SIGABRT
#define SIGEMT 7
#define SIGFPE 8
#define SIGKILL 9
#define SIGBUS 10
#define SIGSEGV 11
#define SIGSYS 12
#define SIGPIPE 13
#define SIGALRM 14
#define SIGTERM 15
#define SIGURG 16
#define SIGSTOP 17
#define SIGTSTP 18
#define SIGCONT 19
#define SIGCHLD 20
#define SIGTTIN 21
#define SIGTTOU 22
#define SIGIO 23
#define SIGXCPU 24
#define SIGXFSZ 25
#define SIGVTALRM 26
#define SIGPROF 27
#define SIGWINCH 28
#define SIGINFO 29
#define SIGUSR1 30
#define SIGUSR2 31
#define SIG_DFL (void (*)(int))0
#define SIG_IGN (void (*)(int))1
#define SIG_HOLD (void (*)(int))5
#define SIG_ERR ((void (*)(int))-1)
#define __ARM_MCONTEXT_H_ 
#define _MACH_MACHINE__STRUCTS_H_ 
#define _MACH_ARM__STRUCTS_H_ 
#define _STRUCT_ARM_EXCEPTION_STATE struct __darwin_arm_exception_state
#define _STRUCT_ARM_EXCEPTION_STATE64 struct __darwin_arm_exception_state64
#define _STRUCT_ARM_THREAD_STATE struct __darwin_arm_thread_state
#define __DARWIN_OPAQUE_ARM_THREAD_STATE64 0
#define _STRUCT_ARM_THREAD_STATE64 struct __darwin_arm_thread_state64
#define __darwin_arm_thread_state64_get_pc(ts) ((ts).__pc)
#define __darwin_arm_thread_state64_get_pc_fptr(ts) ((void*)(uintptr_t)((ts).__pc))
#define __darwin_arm_thread_state64_set_pc_fptr(ts,fptr) ((ts).__pc = (uintptr_t)(fptr))
#define __darwin_arm_thread_state64_get_lr(ts) ((ts).__lr)
#define __darwin_arm_thread_state64_get_lr_fptr(ts) ((void*)(uintptr_t)((ts).__lr))
#define __darwin_arm_thread_state64_set_lr_fptr(ts,fptr) ((ts).__lr = (uintptr_t)(fptr))
#define __darwin_arm_thread_state64_get_sp(ts) ((ts).__sp)
#define __darwin_arm_thread_state64_set_sp(ts,ptr) ((ts).__sp = (uintptr_t)(ptr))
#define __darwin_arm_thread_state64_get_fp(ts) ((ts).__fp)
#define __darwin_arm_thread_state64_set_fp(ts,ptr) ((ts).__fp = (uintptr_t)(ptr))
#define __darwin_arm_thread_state64_ptrauth_strip(ts) (void)(ts)
#define _STRUCT_ARM_VFP_STATE struct __darwin_arm_vfp_state
#define _STRUCT_ARM_NEON_STATE64 struct __darwin_arm_neon_state64
#define _STRUCT_ARM_NEON_STATE struct __darwin_arm_neon_state
#define _STRUCT_ARM_AMX_STATE_V1 struct __darwin_arm_amx_state_v1
#define _STRUCT_ARM_PAGEIN_STATE struct __arm_pagein_state
#define _STRUCT_ARM_LEGACY_DEBUG_STATE struct __arm_legacy_debug_state
#define _STRUCT_ARM_DEBUG_STATE32 struct __darwin_arm_debug_state32
#define _STRUCT_ARM_DEBUG_STATE64 struct __darwin_arm_debug_state64
#define _STRUCT_ARM_CPMU_STATE64 struct __darwin_arm_cpmu_state64
#define _STRUCT_MCONTEXT32 struct __darwin_mcontext32
#define _STRUCT_MCONTEXT64 struct __darwin_mcontext64
#define _MCONTEXT_T 
#define _STRUCT_MCONTEXT _STRUCT_MCONTEXT64
#define _STRUCT_SIGALTSTACK struct __darwin_sigaltstack
#define _STRUCT_UCONTEXT struct __darwin_ucontext
#define _SIGSET_T 
#define SIGEV_NONE 0
#define SIGEV_SIGNAL 1
#define SIGEV_THREAD 3
#define ILL_NOOP 0
#define ILL_ILLOPC 1
#define ILL_ILLTRP 2
#define ILL_PRVOPC 3
#define ILL_ILLOPN 4
#define ILL_ILLADR 5
#define ILL_PRVREG 6
#define ILL_COPROC 7
#define ILL_BADSTK 8
#define FPE_NOOP 0
#define FPE_FLTDIV 1
#define FPE_FLTOVF 2
#define FPE_FLTUND 3
#define FPE_FLTRES 4
#define FPE_FLTINV 5
#define FPE_FLTSUB 6
#define FPE_INTDIV 7
#define FPE_INTOVF 8
#define SEGV_NOOP 0
#define SEGV_MAPERR 1
#define SEGV_ACCERR 2
#define BUS_NOOP 0
#define BUS_ADRALN 1
#define BUS_ADRERR 2
#define BUS_OBJERR 3
#define TRAP_BRKPT 1
#define TRAP_TRACE 2
#define CLD_NOOP 0
#define CLD_EXITED 1
#define CLD_KILLED 2
#define CLD_DUMPED 3
#define CLD_TRAPPED 4
#define CLD_STOPPED 5
#define CLD_CONTINUED 6
#define POLL_IN 1
#define POLL_OUT 2
#define POLL_MSG 3
#define POLL_ERR 4
#define POLL_PRI 5
#define POLL_HUP 6
#define sa_handler __sigaction_u.__sa_handler
#define sa_sigaction __sigaction_u.__sa_sigaction
#define SA_ONSTACK 0x0001
#define SA_RESTART 0x0002
#define SA_RESETHAND 0x0004
#define SA_NOCLDSTOP 0x0008
#define SA_NODEFER 0x0010
#define SA_NOCLDWAIT 0x0020
#define SA_SIGINFO 0x0040
#define SA_USERTRAMP 0x0100
#define SA_64REGSET 0x0200
#define SA_USERSPACE_MASK (SA_ONSTACK | SA_RESTART | SA_RESETHAND | SA_NOCLDSTOP | SA_NODEFER | SA_NOCLDWAIT | SA_SIGINFO)
#define SIG_BLOCK 1
#define SIG_UNBLOCK 2
#define SIG_SETMASK 3
#define SI_USER 0x10001
#define SI_QUEUE 0x10002
#define SI_TIMER 0x10003
#define SI_ASYNCIO 0x10004
#define SI_MESGQ 0x10005
#define SS_ONSTACK 0x0001
#define SS_DISABLE 0x0004
#define MINSIGSTKSZ 32768
#define SIGSTKSZ 131072
#define SV_ONSTACK SA_ONSTACK
#define SV_INTERRUPT SA_RESTART
#define SV_RESETHAND SA_RESETHAND
#define SV_NODEFER SA_NODEFER
#define SV_NOCLDSTOP SA_NOCLDSTOP
#define SV_SIGINFO SA_SIGINFO
#define sv_onstack sv_flags
#define sigmask(m) (1 << ((m)-1))
#define BADSIG SIG_ERR
#define _SYS_RESOURCE_H_ 
#define _STRUCT_TIMEVAL struct timeval
#define PRIO_PROCESS 0
#define PRIO_PGRP 1
#define PRIO_USER 2
#define PRIO_DARWIN_THREAD 3
#define PRIO_DARWIN_PROCESS 4
#define PRIO_MIN -20
#define PRIO_MAX 20
#define PRIO_DARWIN_BG 0x1000
#define PRIO_DARWIN_NONUI 0x1001
#define RUSAGE_SELF 0
#define RUSAGE_CHILDREN -1
#define ru_first ru_ixrss
#define ru_last ru_nivcsw
#define RUSAGE_INFO_V0 0
#define RUSAGE_INFO_V1 1
#define RUSAGE_INFO_V2 2
#define RUSAGE_INFO_V3 3
#define RUSAGE_INFO_V4 4
#define RUSAGE_INFO_V5 5
#define RUSAGE_INFO_CURRENT RUSAGE_INFO_V5
#define RU_PROC_RUNS_RESLIDE 0x00000001
#define RLIM_INFINITY (((__uint64_t)1 << 63) - 1)
#define RLIM_SAVED_MAX RLIM_INFINITY
#define RLIM_SAVED_CUR RLIM_INFINITY
#define RLIMIT_CPU 0
#define RLIMIT_FSIZE 1
#define RLIMIT_DATA 2
#define RLIMIT_STACK 3
#define RLIMIT_CORE 4
#define RLIMIT_AS 5
#define RLIMIT_RSS RLIMIT_AS
#define RLIMIT_MEMLOCK 6
#define RLIMIT_NPROC 7
#define RLIMIT_NOFILE 8
#define RLIM_NLIMITS 9
#define _RLIMIT_POSIX_FLAG 0x1000
#define RLIMIT_WAKEUPS_MONITOR 0x1
#define RLIMIT_CPU_USAGE_MONITOR 0x2
#define RLIMIT_THREAD_CPULIMITS 0x3
#define RLIMIT_FOOTPRINT_INTERVAL 0x4
#define WAKEMON_ENABLE 0x01
#define WAKEMON_DISABLE 0x02
#define WAKEMON_GET_PARAMS 0x04
#define WAKEMON_SET_DEFAULTS 0x08
#define WAKEMON_MAKE_FATAL 0x10
#define CPUMON_MAKE_FATAL 0x1000
#define FOOTPRINT_INTERVAL_RESET 0x1
#define IOPOL_TYPE_DISK 0
#define IOPOL_TYPE_VFS_ATIME_UPDATES 2
#define IOPOL_TYPE_VFS_MATERIALIZE_DATALESS_FILES 3
#define IOPOL_TYPE_VFS_STATFS_NO_DATA_VOLUME 4
#define IOPOL_TYPE_VFS_TRIGGER_RESOLVE 5
#define IOPOL_TYPE_VFS_IGNORE_CONTENT_PROTECTION 6
#define IOPOL_SCOPE_PROCESS 0
#define IOPOL_SCOPE_THREAD 1
#define IOPOL_SCOPE_DARWIN_BG 2
#define IOPOL_DEFAULT 0
#define IOPOL_IMPORTANT 1
#define IOPOL_PASSIVE 2
#define IOPOL_THROTTLE 3
#define IOPOL_UTILITY 4
#define IOPOL_STANDARD 5
#define IOPOL_APPLICATION IOPOL_STANDARD
#define IOPOL_NORMAL IOPOL_IMPORTANT
#define IOPOL_ATIME_UPDATES_DEFAULT 0
#define IOPOL_ATIME_UPDATES_OFF 1
#define IOPOL_MATERIALIZE_DATALESS_FILES_DEFAULT 0
#define IOPOL_MATERIALIZE_DATALESS_FILES_OFF 1
#define IOPOL_MATERIALIZE_DATALESS_FILES_ON 2
#define IOPOL_VFS_STATFS_NO_DATA_VOLUME_DEFAULT 0
#define IOPOL_VFS_STATFS_FORCE_NO_DATA_VOLUME 1
#define IOPOL_VFS_TRIGGER_RESOLVE_DEFAULT 0
#define IOPOL_VFS_TRIGGER_RESOLVE_OFF 1
#define IOPOL_VFS_CONTENT_PROTECTION_DEFAULT 0
#define IOPOL_VFS_CONTENT_PROTECTION_IGNORE 1
#define WNOHANG 0x00000001
#define WUNTRACED 0x00000002
#define _W_INT(w) (*(int *)&(w))
#define WCOREFLAG 0200
#define _WSTATUS(x) (_W_INT(x) & 0177)
#define _WSTOPPED 0177
#define WEXITSTATUS(x) ((_W_INT(x) >> 8) & 0x000000ff)
#define WSTOPSIG(x) (_W_INT(x) >> 8)
#define WIFCONTINUED(x) (_WSTATUS(x) == _WSTOPPED && WSTOPSIG(x) == 0x13)
#define WIFSTOPPED(x) (_WSTATUS(x) == _WSTOPPED && WSTOPSIG(x) != 0x13)
#define WIFEXITED(x) (_WSTATUS(x) == 0)
#define WIFSIGNALED(x) (_WSTATUS(x) != _WSTOPPED && _WSTATUS(x) != 0)
#define WTERMSIG(x) (_WSTATUS(x))
#define WCOREDUMP(x) (_W_INT(x) & WCOREFLAG)
#define W_EXITCODE(ret,sig) ((ret) << 8 | (sig))
#define W_STOPCODE(sig) ((sig) << 8 | _WSTOPPED)
#define WEXITED 0x00000004
#define WSTOPPED 0x00000008
#define WCONTINUED 0x00000010
#define WNOWAIT 0x00000020
#define WAIT_ANY (-1)
#define WAIT_MYPGRP 0
#define w_termsig w_T.w_Termsig
#define w_coredump w_T.w_Coredump
#define w_retcode w_T.w_Retcode
#define w_stopval w_S.w_Stopval
#define w_stopsig w_S.w_Stopsig
#define _ALLOCA_H_ 
#undef alloca
#undef __alloca
#define alloca(size) __alloca(size)
#define __alloca(size) __builtin_alloca(size)
#define _CT_RUNE_T 
#define _RUNE_T 
#define _WCHAR_T 
#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0
#define RAND_MAX 0x7fffffff
#define MB_CUR_MAX __mb_cur_max
#define _MALLOC_UNDERSCORE_MALLOC_H_ 
#define __swift_unavailable_on(osx_msg,ios_msg) __swift_unavailable(osx_msg)
#undef __swift_unavailable_on
#define __sort_noescape __attribute__((__noescape__))
#define __STDDEF_H 
#define __need_ptrdiff_t 
#define __need_size_t 
#define __need_wchar_t 
#define __need_NULL 
#define __need_STDDEF_H_misc 
#define _PTRDIFF_T 
#undef __need_ptrdiff_t
#undef __need_size_t
#undef __need_wchar_t
#undef NULL
#define NULL ((void*)0)
#undef __need_NULL
#define offsetof(t,d) __builtin_offsetof(t, d)
#undef __need_STDDEF_H_misc
#define _STRING_H_ 
#define _STRINGS_H_ 
#define _SECURE__STRINGS_H_ 
#undef bcopy
#define bcopy(src,dest,...) __builtin___memmove_chk (dest, src, __VA_ARGS__, __darwin_obsz0 (dest))
#undef bzero
#define bzero(dest,...) __builtin___memset_chk (dest, 0, __VA_ARGS__, __darwin_obsz0 (dest))
#define _SECURE__STRING_H_ 
#define __HAS_FIXED_CHK_PROTOTYPES 1
#undef memccpy
#define memccpy(dest,...) __builtin___memccpy_chk (dest, __VA_ARGS__, __darwin_obsz0 (dest))
#undef memcpy
#define memcpy(dest,...) __builtin___memcpy_chk (dest, __VA_ARGS__, __darwin_obsz0 (dest))
#undef memmove
#define memmove(dest,...) __builtin___memmove_chk (dest, __VA_ARGS__, __darwin_obsz0 (dest))
#undef memset
#define memset(dest,...) __builtin___memset_chk (dest, __VA_ARGS__, __darwin_obsz0 (dest))
#undef strcpy
#define strcpy(dest,...) __builtin___strcpy_chk (dest, __VA_ARGS__, __darwin_obsz (dest))
#undef stpcpy
#define stpcpy(dest,...) __builtin___stpcpy_chk (dest, __VA_ARGS__, __darwin_obsz (dest))
#undef stpncpy
#define stpncpy(dest,...) __builtin___stpncpy_chk (dest, __VA_ARGS__, __darwin_obsz (dest))
#undef strlcpy
#define strlcpy(dest,...) __builtin___strlcpy_chk (dest, __VA_ARGS__, __darwin_obsz (dest))
#undef strlcat
#define strlcat(dest,...) __builtin___strlcat_chk (dest, __VA_ARGS__, __darwin_obsz (dest))
#undef strncpy
#define strncpy(dest,...) __builtin___strncpy_chk (dest, __VA_ARGS__, __darwin_obsz (dest))
#undef strcat
#define strcat(dest,...) __builtin___strcat_chk (dest, __VA_ARGS__, __darwin_obsz (dest))
#undef strncat
#define strncat(dest,...) __builtin___strncat_chk (dest, __VA_ARGS__, __darwin_obsz (dest))
#undef __HAS_FIXED_CHK_PROTOTYPES
#define __CLANG_INTTYPES_H 
#define _INTTYPES_H_ 
#define __PRI_8_LENGTH_MODIFIER__ "hh"
#define __PRI_64_LENGTH_MODIFIER__ "ll"
#define __SCN_64_LENGTH_MODIFIER__ "ll"
#define __PRI_MAX_LENGTH_MODIFIER__ "j"
#define __SCN_MAX_LENGTH_MODIFIER__ "j"
#define PRId8 __PRI_8_LENGTH_MODIFIER__ "d"
#define PRIi8 __PRI_8_LENGTH_MODIFIER__ "i"
#define PRIo8 __PRI_8_LENGTH_MODIFIER__ "o"
#define PRIu8 __PRI_8_LENGTH_MODIFIER__ "u"
#define PRIx8 __PRI_8_LENGTH_MODIFIER__ "x"
#define PRIX8 __PRI_8_LENGTH_MODIFIER__ "X"
#define PRId16 "hd"
#define PRIi16 "hi"
#define PRIo16 "ho"
#define PRIu16 "hu"
#define PRIx16 "hx"
#define PRIX16 "hX"
#define PRId32 "d"
#define PRIi32 "i"
#define PRIo32 "o"
#define PRIu32 "u"
#define PRIx32 "x"
#define PRIX32 "X"
#define PRId64 __PRI_64_LENGTH_MODIFIER__ "d"
#define PRIi64 __PRI_64_LENGTH_MODIFIER__ "i"
#define PRIo64 __PRI_64_LENGTH_MODIFIER__ "o"
#define PRIu64 __PRI_64_LENGTH_MODIFIER__ "u"
#define PRIx64 __PRI_64_LENGTH_MODIFIER__ "x"
#define PRIX64 __PRI_64_LENGTH_MODIFIER__ "X"
#define PRIdLEAST8 PRId8
#define PRIiLEAST8 PRIi8
#define PRIoLEAST8 PRIo8
#define PRIuLEAST8 PRIu8
#define PRIxLEAST8 PRIx8
#define PRIXLEAST8 PRIX8
#define PRIdLEAST16 PRId16
#define PRIiLEAST16 PRIi16
#define PRIoLEAST16 PRIo16
#define PRIuLEAST16 PRIu16
#define PRIxLEAST16 PRIx16
#define PRIXLEAST16 PRIX16
#define PRIdLEAST32 PRId32
#define PRIiLEAST32 PRIi32
#define PRIoLEAST32 PRIo32
#define PRIuLEAST32 PRIu32
#define PRIxLEAST32 PRIx32
#define PRIXLEAST32 PRIX32
#define PRIdLEAST64 PRId64
#define PRIiLEAST64 PRIi64
#define PRIoLEAST64 PRIo64
#define PRIuLEAST64 PRIu64
#define PRIxLEAST64 PRIx64
#define PRIXLEAST64 PRIX64
#define PRIdFAST8 PRId8
#define PRIiFAST8 PRIi8
#define PRIoFAST8 PRIo8
#define PRIuFAST8 PRIu8
#define PRIxFAST8 PRIx8
#define PRIXFAST8 PRIX8
#define PRIdFAST16 PRId16
#define PRIiFAST16 PRIi16
#define PRIoFAST16 PRIo16
#define PRIuFAST16 PRIu16
#define PRIxFAST16 PRIx16
#define PRIXFAST16 PRIX16
#define PRIdFAST32 PRId32
#define PRIiFAST32 PRIi32
#define PRIoFAST32 PRIo32
#define PRIuFAST32 PRIu32
#define PRIxFAST32 PRIx32
#define PRIXFAST32 PRIX32
#define PRIdFAST64 PRId64
#define PRIiFAST64 PRIi64
#define PRIoFAST64 PRIo64
#define PRIuFAST64 PRIu64
#define PRIxFAST64 PRIx64
#define PRIXFAST64 PRIX64
#define PRIdPTR "ld"
#define PRIiPTR "li"
#define PRIoPTR "lo"
#define PRIuPTR "lu"
#define PRIxPTR "lx"
#define PRIXPTR "lX"
#define PRIdMAX __PRI_MAX_LENGTH_MODIFIER__ "d"
#define PRIiMAX __PRI_MAX_LENGTH_MODIFIER__ "i"
#define PRIoMAX __PRI_MAX_LENGTH_MODIFIER__ "o"
#define PRIuMAX __PRI_MAX_LENGTH_MODIFIER__ "u"
#define PRIxMAX __PRI_MAX_LENGTH_MODIFIER__ "x"
#define PRIXMAX __PRI_MAX_LENGTH_MODIFIER__ "X"
#define SCNd8 __PRI_8_LENGTH_MODIFIER__ "d"
#define SCNi8 __PRI_8_LENGTH_MODIFIER__ "i"
#define SCNo8 __PRI_8_LENGTH_MODIFIER__ "o"
#define SCNu8 __PRI_8_LENGTH_MODIFIER__ "u"
#define SCNx8 __PRI_8_LENGTH_MODIFIER__ "x"
#define SCNd16 "hd"
#define SCNi16 "hi"
#define SCNo16 "ho"
#define SCNu16 "hu"
#define SCNx16 "hx"
#define SCNd32 "d"
#define SCNi32 "i"
#define SCNo32 "o"
#define SCNu32 "u"
#define SCNx32 "x"
#define SCNd64 __SCN_64_LENGTH_MODIFIER__ "d"
#define SCNi64 __SCN_64_LENGTH_MODIFIER__ "i"
#define SCNo64 __SCN_64_LENGTH_MODIFIER__ "o"
#define SCNu64 __SCN_64_LENGTH_MODIFIER__ "u"
#define SCNx64 __SCN_64_LENGTH_MODIFIER__ "x"
#define SCNdLEAST8 SCNd8
#define SCNiLEAST8 SCNi8
#define SCNoLEAST8 SCNo8
#define SCNuLEAST8 SCNu8
#define SCNxLEAST8 SCNx8
#define SCNdLEAST16 SCNd16
#define SCNiLEAST16 SCNi16
#define SCNoLEAST16 SCNo16
#define SCNuLEAST16 SCNu16
#define SCNxLEAST16 SCNx16
#define SCNdLEAST32 SCNd32
#define SCNiLEAST32 SCNi32
#define SCNoLEAST32 SCNo32
#define SCNuLEAST32 SCNu32
#define SCNxLEAST32 SCNx32
#define SCNdLEAST64 SCNd64
#define SCNiLEAST64 SCNi64
#define SCNoLEAST64 SCNo64
#define SCNuLEAST64 SCNu64
#define SCNxLEAST64 SCNx64
#define SCNdFAST8 SCNd8
#define SCNiFAST8 SCNi8
#define SCNoFAST8 SCNo8
#define SCNuFAST8 SCNu8
#define SCNxFAST8 SCNx8
#define SCNdFAST16 SCNd16
#define SCNiFAST16 SCNi16
#define SCNoFAST16 SCNo16
#define SCNuFAST16 SCNu16
#define SCNxFAST16 SCNx16
#define SCNdFAST32 SCNd32
#define SCNiFAST32 SCNi32
#define SCNoFAST32 SCNo32
#define SCNuFAST32 SCNu32
#define SCNxFAST32 SCNx32
#define SCNdFAST64 SCNd64
#define SCNiFAST64 SCNi64
#define SCNoFAST64 SCNo64
#define SCNuFAST64 SCNu64
#define SCNxFAST64 SCNx64
#define SCNdPTR "ld"
#define SCNiPTR "li"
#define SCNoPTR "lo"
#define SCNuPTR "lu"
#define SCNxPTR "lx"
#define SCNdMAX __SCN_MAX_LENGTH_MODIFIER__ "d"
#define SCNiMAX __SCN_MAX_LENGTH_MODIFIER__ "i"
#define SCNoMAX __SCN_MAX_LENGTH_MODIFIER__ "o"
#define SCNuMAX __SCN_MAX_LENGTH_MODIFIER__ "u"
#define SCNxMAX __SCN_MAX_LENGTH_MODIFIER__ "x"
#define __STDALIGN_H 
#define alignas _Alignas
#define alignof _Alignof
#define __alignas_is_defined 1
#define __alignof_is_defined 1
#define _UNISTD_H_ 
#define _SYS_UNISTD_H_ 
#define _POSIX_VERSION 200112L
#define _POSIX2_VERSION 200112L
#define _POSIX_VDISABLE ((unsigned char)'\377')
#define _POSIX_THREAD_KEYS_MAX 128
#define F_OK 0
#define X_OK (1<<0)
#define W_OK (1<<1)
#define R_OK (1<<2)
#define _READ_OK (1<<9)
#define _WRITE_OK (1<<10)
#define _EXECUTE_OK (1<<11)
#define _DELETE_OK (1<<12)
#define _APPEND_OK (1<<13)
#define _RMFILE_OK (1<<14)
#define _RATTR_OK (1<<15)
#define _WATTR_OK (1<<16)
#define _REXT_OK (1<<17)
#define _WEXT_OK (1<<18)
#define _RPERM_OK (1<<19)
#define _WPERM_OK (1<<20)
#define _CHOWN_OK (1<<21)
#define _ACCESS_EXTENDED_MASK (_READ_OK | _WRITE_OK | _EXECUTE_OK | _DELETE_OK | _APPEND_OK | _RMFILE_OK | _REXT_OK | _WEXT_OK | _RATTR_OK | _WATTR_OK | _RPERM_OK | _WPERM_OK | _CHOWN_OK)
#define SEEK_HOLE 3
#define SEEK_DATA 4
#define L_SET SEEK_SET
#define L_INCR SEEK_CUR
#define L_XTND SEEK_END
#define ACCESSX_MAX_DESCRIPTORS 100
#define ACCESSX_MAX_TABLESIZE (16 * 1024)
#define _PC_LINK_MAX 1
#define _PC_MAX_CANON 2
#define _PC_MAX_INPUT 3
#define _PC_NAME_MAX 4
#define _PC_PATH_MAX 5
#define _PC_PIPE_BUF 6
#define _PC_CHOWN_RESTRICTED 7
#define _PC_NO_TRUNC 8
#define _PC_VDISABLE 9
#define _PC_NAME_CHARS_MAX 10
#define _PC_CASE_SENSITIVE 11
#define _PC_CASE_PRESERVING 12
#define _PC_EXTENDED_SECURITY_NP 13
#define _PC_AUTH_OPAQUE_NP 14
#define _PC_2_SYMLINKS 15
#define _PC_ALLOC_SIZE_MIN 16
#define _PC_ASYNC_IO 17
#define _PC_FILESIZEBITS 18
#define _PC_PRIO_IO 19
#define _PC_REC_INCR_XFER_SIZE 20
#define _PC_REC_MAX_XFER_SIZE 21
#define _PC_REC_MIN_XFER_SIZE 22
#define _PC_REC_XFER_ALIGN 23
#define _PC_SYMLINK_MAX 24
#define _PC_SYNC_IO 25
#define _PC_XATTR_SIZE_BITS 26
#define _PC_MIN_HOLE_SIZE 27
#define _CS_PATH 1
#define STDIN_FILENO 0
#define STDOUT_FILENO 1
#define STDERR_FILENO 2
#define _XOPEN_VERSION 600
#define _XOPEN_XCU_VERSION 4
#define _POSIX_ADVISORY_INFO (-1)
#define _POSIX_ASYNCHRONOUS_IO (-1)
#define _POSIX_BARRIERS (-1)
#define _POSIX_CHOWN_RESTRICTED 200112L
#define _POSIX_CLOCK_SELECTION (-1)
#define _POSIX_CPUTIME (-1)
#define _POSIX_FSYNC 200112L
#define _POSIX_IPV6 200112L
#define _POSIX_JOB_CONTROL 200112L
#define _POSIX_MAPPED_FILES 200112L
#define _POSIX_MEMLOCK (-1)
#define _POSIX_MEMLOCK_RANGE (-1)
#define _POSIX_MEMORY_PROTECTION 200112L
#define _POSIX_MESSAGE_PASSING (-1)
#define _POSIX_MONOTONIC_CLOCK (-1)
#define _POSIX_NO_TRUNC 200112L
#define _POSIX_PRIORITIZED_IO (-1)
#define _POSIX_PRIORITY_SCHEDULING (-1)
#define _POSIX_RAW_SOCKETS (-1)
#define _POSIX_READER_WRITER_LOCKS 200112L
#define _POSIX_REALTIME_SIGNALS (-1)
#define _POSIX_REGEXP 200112L
#define _POSIX_SAVED_IDS 200112L
#define _POSIX_SEMAPHORES (-1)
#define _POSIX_SHARED_MEMORY_OBJECTS (-1)
#define _POSIX_SHELL 200112L
#define _POSIX_SPAWN (-1)
#define _POSIX_SPIN_LOCKS (-1)
#define _POSIX_SPORADIC_SERVER (-1)
#define _POSIX_SYNCHRONIZED_IO (-1)
#define _POSIX_THREAD_ATTR_STACKADDR 200112L
#define _POSIX_THREAD_ATTR_STACKSIZE 200112L
#define _POSIX_THREAD_CPUTIME (-1)
#define _POSIX_THREAD_PRIO_INHERIT (-1)
#define _POSIX_THREAD_PRIO_PROTECT (-1)
#define _POSIX_THREAD_PRIORITY_SCHEDULING (-1)
#define _POSIX_THREAD_PROCESS_SHARED 200112L
#define _POSIX_THREAD_SAFE_FUNCTIONS 200112L
#define _POSIX_THREAD_SPORADIC_SERVER (-1)
#define _POSIX_THREADS 200112L
#define _POSIX_TIMEOUTS (-1)
#define _POSIX_TIMERS (-1)
#define _POSIX_TRACE (-1)
#define _POSIX_TRACE_EVENT_FILTER (-1)
#define _POSIX_TRACE_INHERIT (-1)
#define _POSIX_TRACE_LOG (-1)
#define _POSIX_TYPED_MEMORY_OBJECTS (-1)
#define _POSIX2_C_BIND 200112L
#define _POSIX2_C_DEV 200112L
#define _POSIX2_CHAR_TERM 200112L
#define _POSIX2_FORT_DEV (-1)
#define _POSIX2_FORT_RUN 200112L
#define _POSIX2_LOCALEDEF 200112L
#define _POSIX2_PBS (-1)
#define _POSIX2_PBS_ACCOUNTING (-1)
#define _POSIX2_PBS_CHECKPOINT (-1)
#define _POSIX2_PBS_LOCATE (-1)
#define _POSIX2_PBS_MESSAGE (-1)
#define _POSIX2_PBS_TRACK (-1)
#define _POSIX2_SW_DEV 200112L
#define _POSIX2_UPE 200112L
#define __ILP32_OFF32 (-1)
#define __ILP32_OFFBIG (-1)
#define __LP64_OFF64 (1)
#define __LPBIG_OFFBIG (1)
#define _POSIX_V6_ILP32_OFF32 __ILP32_OFF32
#define _POSIX_V6_ILP32_OFFBIG __ILP32_OFFBIG
#define _POSIX_V6_LP64_OFF64 __LP64_OFF64
#define _POSIX_V6_LPBIG_OFFBIG __LPBIG_OFFBIG
#define _POSIX_V7_ILP32_OFF32 __ILP32_OFF32
#define _POSIX_V7_ILP32_OFFBIG __ILP32_OFFBIG
#define _POSIX_V7_LP64_OFF64 __LP64_OFF64
#define _POSIX_V7_LPBIG_OFFBIG __LPBIG_OFFBIG
#define _V6_ILP32_OFF32 __ILP32_OFF32
#define _V6_ILP32_OFFBIG __ILP32_OFFBIG
#define _V6_LP64_OFF64 __LP64_OFF64
#define _V6_LPBIG_OFFBIG __LPBIG_OFFBIG
#define _XBS5_ILP32_OFF32 __ILP32_OFF32
#define _XBS5_ILP32_OFFBIG __ILP32_OFFBIG
#define _XBS5_LP64_OFF64 __LP64_OFF64
#define _XBS5_LPBIG_OFFBIG __LPBIG_OFFBIG
#define _XOPEN_CRYPT (1)
#define _XOPEN_ENH_I18N (1)
#define _XOPEN_LEGACY (-1)
#define _XOPEN_REALTIME (-1)
#define _XOPEN_REALTIME_THREADS (-1)
#define _XOPEN_SHM (1)
#define _XOPEN_STREAMS (-1)
#define _XOPEN_UNIX (1)
#define _SC_ARG_MAX 1
#define _SC_CHILD_MAX 2
#define _SC_CLK_TCK 3
#define _SC_NGROUPS_MAX 4
#define _SC_OPEN_MAX 5
#define _SC_JOB_CONTROL 6
#define _SC_SAVED_IDS 7
#define _SC_VERSION 8
#define _SC_BC_BASE_MAX 9
#define _SC_BC_DIM_MAX 10
#define _SC_BC_SCALE_MAX 11
#define _SC_BC_STRING_MAX 12
#define _SC_COLL_WEIGHTS_MAX 13
#define _SC_EXPR_NEST_MAX 14
#define _SC_LINE_MAX 15
#define _SC_RE_DUP_MAX 16
#define _SC_2_VERSION 17
#define _SC_2_C_BIND 18
#define _SC_2_C_DEV 19
#define _SC_2_CHAR_TERM 20
#define _SC_2_FORT_DEV 21
#define _SC_2_FORT_RUN 22
#define _SC_2_LOCALEDEF 23
#define _SC_2_SW_DEV 24
#define _SC_2_UPE 25
#define _SC_STREAM_MAX 26
#define _SC_TZNAME_MAX 27
#define _SC_ASYNCHRONOUS_IO 28
#define _SC_PAGESIZE 29
#define _SC_MEMLOCK 30
#define _SC_MEMLOCK_RANGE 31
#define _SC_MEMORY_PROTECTION 32
#define _SC_MESSAGE_PASSING 33
#define _SC_PRIORITIZED_IO 34
#define _SC_PRIORITY_SCHEDULING 35
#define _SC_REALTIME_SIGNALS 36
#define _SC_SEMAPHORES 37
#define _SC_FSYNC 38
#define _SC_SHARED_MEMORY_OBJECTS 39
#define _SC_SYNCHRONIZED_IO 40
#define _SC_TIMERS 41
#define _SC_AIO_LISTIO_MAX 42
#define _SC_AIO_MAX 43
#define _SC_AIO_PRIO_DELTA_MAX 44
#define _SC_DELAYTIMER_MAX 45
#define _SC_MQ_OPEN_MAX 46
#define _SC_MAPPED_FILES 47
#define _SC_RTSIG_MAX 48
#define _SC_SEM_NSEMS_MAX 49
#define _SC_SEM_VALUE_MAX 50
#define _SC_SIGQUEUE_MAX 51
#define _SC_TIMER_MAX 52
#define _SC_NPROCESSORS_CONF 57
#define _SC_NPROCESSORS_ONLN 58
#define _SC_2_PBS 59
#define _SC_2_PBS_ACCOUNTING 60
#define _SC_2_PBS_CHECKPOINT 61
#define _SC_2_PBS_LOCATE 62
#define _SC_2_PBS_MESSAGE 63
#define _SC_2_PBS_TRACK 64
#define _SC_ADVISORY_INFO 65
#define _SC_BARRIERS 66
#define _SC_CLOCK_SELECTION 67
#define _SC_CPUTIME 68
#define _SC_FILE_LOCKING 69
#define _SC_GETGR_R_SIZE_MAX 70
#define _SC_GETPW_R_SIZE_MAX 71
#define _SC_HOST_NAME_MAX 72
#define _SC_LOGIN_NAME_MAX 73
#define _SC_MONOTONIC_CLOCK 74
#define _SC_MQ_PRIO_MAX 75
#define _SC_READER_WRITER_LOCKS 76
#define _SC_REGEXP 77
#define _SC_SHELL 78
#define _SC_SPAWN 79
#define _SC_SPIN_LOCKS 80
#define _SC_SPORADIC_SERVER 81
#define _SC_THREAD_ATTR_STACKADDR 82
#define _SC_THREAD_ATTR_STACKSIZE 83
#define _SC_THREAD_CPUTIME 84
#define _SC_THREAD_DESTRUCTOR_ITERATIONS 85
#define _SC_THREAD_KEYS_MAX 86
#define _SC_THREAD_PRIO_INHERIT 87
#define _SC_THREAD_PRIO_PROTECT 88
#define _SC_THREAD_PRIORITY_SCHEDULING 89
#define _SC_THREAD_PROCESS_SHARED 90
#define _SC_THREAD_SAFE_FUNCTIONS 91
#define _SC_THREAD_SPORADIC_SERVER 92
#define _SC_THREAD_STACK_MIN 93
#define _SC_THREAD_THREADS_MAX 94
#define _SC_TIMEOUTS 95
#define _SC_THREADS 96
#define _SC_TRACE 97
#define _SC_TRACE_EVENT_FILTER 98
#define _SC_TRACE_INHERIT 99
#define _SC_TRACE_LOG 100
#define _SC_TTY_NAME_MAX 101
#define _SC_TYPED_MEMORY_OBJECTS 102
#define _SC_V6_ILP32_OFF32 103
#define _SC_V6_ILP32_OFFBIG 104
#define _SC_V6_LP64_OFF64 105
#define _SC_V6_LPBIG_OFFBIG 106
#define _SC_IPV6 118
#define _SC_RAW_SOCKETS 119
#define _SC_SYMLOOP_MAX 120
#define _SC_ATEXIT_MAX 107
#define _SC_IOV_MAX 56
#define _SC_PAGE_SIZE _SC_PAGESIZE
#define _SC_XOPEN_CRYPT 108
#define _SC_XOPEN_ENH_I18N 109
#define _SC_XOPEN_LEGACY 110
#define _SC_XOPEN_REALTIME 111
#define _SC_XOPEN_REALTIME_THREADS 112
#define _SC_XOPEN_SHM 113
#define _SC_XOPEN_STREAMS 114
#define _SC_XOPEN_UNIX 115
#define _SC_XOPEN_VERSION 116
#define _SC_XOPEN_XCU_VERSION 121
#define _SC_XBS5_ILP32_OFF32 122
#define _SC_XBS5_ILP32_OFFBIG 123
#define _SC_XBS5_LP64_OFF64 124
#define _SC_XBS5_LPBIG_OFFBIG 125
#define _SC_SS_REPL_MAX 126
#define _SC_TRACE_EVENT_NAME_MAX 127
#define _SC_TRACE_NAME_MAX 128
#define _SC_TRACE_SYS_MAX 129
#define _SC_TRACE_USER_EVENT_MAX 130
#define _SC_PASS_MAX 131
#define _SC_PHYS_PAGES 200
#define _CS_POSIX_V6_ILP32_OFF32_CFLAGS 2
#define _CS_POSIX_V6_ILP32_OFF32_LDFLAGS 3
#define _CS_POSIX_V6_ILP32_OFF32_LIBS 4
#define _CS_POSIX_V6_ILP32_OFFBIG_CFLAGS 5
#define _CS_POSIX_V6_ILP32_OFFBIG_LDFLAGS 6
#define _CS_POSIX_V6_ILP32_OFFBIG_LIBS 7
#define _CS_POSIX_V6_LP64_OFF64_CFLAGS 8
#define _CS_POSIX_V6_LP64_OFF64_LDFLAGS 9
#define _CS_POSIX_V6_LP64_OFF64_LIBS 10
#define _CS_POSIX_V6_LPBIG_OFFBIG_CFLAGS 11
#define _CS_POSIX_V6_LPBIG_OFFBIG_LDFLAGS 12
#define _CS_POSIX_V6_LPBIG_OFFBIG_LIBS 13
#define _CS_POSIX_V6_WIDTH_RESTRICTED_ENVS 14
#define _CS_XBS5_ILP32_OFF32_CFLAGS 20
#define _CS_XBS5_ILP32_OFF32_LDFLAGS 21
#define _CS_XBS5_ILP32_OFF32_LIBS 22
#define _CS_XBS5_ILP32_OFF32_LINTFLAGS 23
#define _CS_XBS5_ILP32_OFFBIG_CFLAGS 24
#define _CS_XBS5_ILP32_OFFBIG_LDFLAGS 25
#define _CS_XBS5_ILP32_OFFBIG_LIBS 26
#define _CS_XBS5_ILP32_OFFBIG_LINTFLAGS 27
#define _CS_XBS5_LP64_OFF64_CFLAGS 28
#define _CS_XBS5_LP64_OFF64_LDFLAGS 29
#define _CS_XBS5_LP64_OFF64_LIBS 30
#define _CS_XBS5_LP64_OFF64_LINTFLAGS 31
#define _CS_XBS5_LPBIG_OFFBIG_CFLAGS 32
#define _CS_XBS5_LPBIG_OFFBIG_LDFLAGS 33
#define _CS_XBS5_LPBIG_OFFBIG_LIBS 34
#define _CS_XBS5_LPBIG_OFFBIG_LINTFLAGS 35
#define _CS_DARWIN_USER_DIR 65536
#define _CS_DARWIN_USER_TEMP_DIR 65537
#define _CS_DARWIN_USER_CACHE_DIR 65538
#define F_ULOCK 0
#define F_LOCK 1
#define F_TLOCK 2
#define F_TEST 3
#define _SYS_SELECT_H_ 
#define _SYS__SELECT_H_ 
#define _UUID_T 
#define __GETHOSTUUID_H 
#define SYNC_VOLUME_FULLSYNC 0x01
#define SYNC_VOLUME_WAIT 0x02
#define RUBY_MISSING_H 1
#define __MATH_H__ 
#define __MATH__ 
#define HUGE_VAL __builtin_huge_val()
#define HUGE_VALF __builtin_huge_valf()
#define HUGE_VALL __builtin_huge_vall()
#define NAN __builtin_nanf("0x7fc00000")
#define INFINITY HUGE_VALF
#define FP_NAN 1
#define FP_INFINITE 2
#define FP_ZERO 3
#define FP_NORMAL 4
#define FP_SUBNORMAL 5
#define FP_SUPERNORMAL 6
#define FP_FAST_FMA 1
#define FP_FAST_FMAF 1
#define FP_FAST_FMAL 1
#define FP_ILOGB0 (-2147483647 - 1)
#define FP_ILOGBNAN (-2147483647 - 1)
#define MATH_ERRNO 1
#define MATH_ERREXCEPT 2
#define math_errhandling (__math_errhandling())
#define fpclassify(x) ( sizeof(x) == sizeof(float) ? __fpclassifyf((float)(x)) : sizeof(x) == sizeof(double) ? __fpclassifyd((double)(x)) : __fpclassifyl((long double)(x)))
#define isnormal(x) ( sizeof(x) == sizeof(float) ? __inline_isnormalf((float)(x)) : sizeof(x) == sizeof(double) ? __inline_isnormald((double)(x)) : __inline_isnormall((long double)(x)))
#define isfinite(x) ( sizeof(x) == sizeof(float) ? __inline_isfinitef((float)(x)) : sizeof(x) == sizeof(double) ? __inline_isfinited((double)(x)) : __inline_isfinitel((long double)(x)))
#define isinf(x) ( sizeof(x) == sizeof(float) ? __inline_isinff((float)(x)) : sizeof(x) == sizeof(double) ? __inline_isinfd((double)(x)) : __inline_isinfl((long double)(x)))
#define isnan(x) ( sizeof(x) == sizeof(float) ? __inline_isnanf((float)(x)) : sizeof(x) == sizeof(double) ? __inline_isnand((double)(x)) : __inline_isnanl((long double)(x)))
#define signbit(x) ( sizeof(x) == sizeof(float) ? __inline_signbitf((float)(x)) : sizeof(x) == sizeof(double) ? __inline_signbitd((double)(x)) : __inline_signbitl((long double)(x)))
#define isgreater(x,y) __builtin_isgreater((x),(y))
#define isgreaterequal(x,y) __builtin_isgreaterequal((x),(y))
#define isless(x,y) __builtin_isless((x),(y))
#define islessequal(x,y) __builtin_islessequal((x),(y))
#define islessgreater(x,y) __builtin_islessgreater((x),(y))
#define isunordered(x,y) __builtin_isunordered((x),(y))
#define M_E 2.71828182845904523536028747135266250
#define M_LOG2E 1.44269504088896340735992468100189214
#define M_LOG10E 0.434294481903251827651128918916605082
#define M_LN2 0.693147180559945309417232121458176568
#define M_LN10 2.30258509299404568401799145468436421
#define M_PI 3.14159265358979323846264338327950288
#define M_PI_2 1.57079632679489661923132169163975144
#define M_PI_4 0.785398163397448309615660845819875721
#define M_1_PI 0.318309886183790671537767526745028724
#define M_2_PI 0.636619772367581343075535053490057448
#define M_2_SQRTPI 1.12837916709551257389615890312154517
#define M_SQRT2 1.41421356237309504880168872420969808
#define M_SQRT1_2 0.707106781186547524400844362104849039
#define MAXFLOAT 0x1.fffffep+127f
#define FP_SNAN FP_NAN
#define FP_QNAN FP_NAN
#define HUGE MAXFLOAT
#define X_TLOSS 1.41484755040568800000e+16
#define DOMAIN 1
#define SING 2
#define OVERFLOW 3
#define UNDERFLOW 4
#define TLOSS 5
#define PLOSS 6
#undef RUBY_EXTERN
#define RUBY_EXTERN extern
#pragma GCC visibility push(default)
#pragma GCC visibility pop
#define RUBY 
#undef _
#define _(args) args
#undef __
#define __(args) args
#define ANYARGS 
#pragma GCC visibility push(default)
#define xmalloc ruby_xmalloc
#define xmalloc2 ruby_xmalloc2
#define xcalloc ruby_xcalloc
#define xrealloc ruby_xrealloc
#define xrealloc2 ruby_xrealloc2
#define xfree ruby_xfree
#define RUBY_ATTR_ALLOC_SIZE(params) __attribute__((__alloc_size__ params))
#define RUBY_ATTR_MALLOC __attribute__((__malloc__))
#define RUBY_ATTR_RETURNS_NONNULL __attribute__((__returns_nonnull__))
#define USE_GC_MALLOC_OBJ_INFO_DETAILS 0
#define STRINGIZE(expr) STRINGIZE0(expr)
#define STRINGIZE0(expr) #expr
#define HAVE_TRUE_LONG_LONG 1
#define LONG_LONG long long
#undef RUBY_EXTERN
#define FALSE 0
#define TRUE 1
#define MJIT_FUNC_EXPORTED RUBY_FUNC_EXPORTED
#define MJIT_SYMBOL_EXPORT_BEGIN RUBY_SYMBOL_EXPORT_BEGIN
#define MJIT_SYMBOL_EXPORT_END RUBY_SYMBOL_EXPORT_END
#define RUBY_EXTERN extern
#define EXTERN _Pragma("message \"EXTERN is deprecated, use RUBY_EXTERN instead\""); RUBY_EXTERN
#define RUBY_MBCHAR_MAXSIZE INT_MAX
#define FLUSH_REGISTER_WINDOWS ((void)0)
#define PATH_SEP ":"
#define PATH_SEP_CHAR PATH_SEP[0]
#define PATH_ENV "PATH"
#define CASEFOLD_FILESYSTEM 0
#define FUNC_MINIMIZED(x) x
#define FUNC_UNOPTIMIZED(x) x
#define RUBY_ALIAS_FUNCTION_TYPE(type,prot,name,args) FUNC_MINIMIZED(type prot) {return (type)name args;}
#define RUBY_ALIAS_FUNCTION_VOID(prot,name,args) FUNC_MINIMIZED(void prot) {name args;}
#define RUBY_ALIAS_FUNCTION(prot,name,args) RUBY_ALIAS_FUNCTION_TYPE(VALUE, prot, name, args)
#define UNALIGNED_WORD_ACCESS 0
#define PACKED_STRUCT_UNALIGNED(x) x
#define NORETURN_STYLE_NEW 1
#pragma GCC visibility pop
#define RUBY_ASSERT_H 
#define RUBY_ASSERT_FAIL(expr) rb_assert_failure(__FILE__, __LINE__, RUBY_FUNCTION_NAME_STRING, expr)
#define RUBY_ASSERT_MESG(expr,mesg) ((expr) ? (void)0 : RUBY_ASSERT_FAIL(mesg))
#define RUBY_ASSERT_MESG_WHEN(cond,expr,mesg) ((RUBY_DEBUG+0) ? RUBY_ASSERT_MESG((expr), mesg) : __builtin_choose_expr( __builtin_constant_p(cond), __builtin_choose_expr(cond, RUBY_ASSERT_MESG(expr, mesg), (void)0), RUBY_ASSERT_MESG(!(cond) || (expr), mesg)))
#define RUBY_ASSERT(expr) RUBY_ASSERT_MESG_WHEN((!RUBY_NDEBUG+0), expr, #expr)
#define RUBY_ASSERT_WHEN(cond,expr) RUBY_ASSERT_MESG_WHEN(cond, expr, #expr)
#define RUBY_ASSERT_ALWAYS(expr) RUBY_ASSERT_MESG_WHEN(TRUE, expr, #expr)
#define RUBY_DEBUG 0
#define RUBY_NDEBUG 0
#define ASSUME(x) (RB_LIKELY(!!(x)) ? (void)0 : UNREACHABLE)
#define UNREACHABLE_RETURN(val) UNREACHABLE
#define RUBY_MACRO_SELECT(base,n) TOKEN_PASTE(base, n)
#define __STDARG_H 
#define _VA_LIST 
#define va_start(ap,param) __builtin_va_start(ap, param)
#define va_end(ap) __builtin_va_end(ap)
#define va_arg(ap,type) __builtin_va_arg(ap, type)
#define __va_copy(d,s) __builtin_va_copy(d,s)
#define va_copy(dest,src) __builtin_va_copy(dest, src)
#define __GNUC_VA_LIST 1
#pragma GCC visibility push(default)
#define SIGNED_VALUE long
#define SIZEOF_VALUE SIZEOF_LONG
#define PRI_VALUE_PREFIX "l"
#define PRI_INT_PREFIX ""
#define PRI_LONG_PREFIX "l"
#define PRI_SHORT_PREFIX "h"
#define RUBY_PRI_VALUE_MARK "\v"
#define PRIdVALUE PRI_VALUE_PREFIX"d"
#define PRIoVALUE PRI_VALUE_PREFIX"o"
#define PRIuVALUE PRI_VALUE_PREFIX"u"
#define PRIxVALUE PRI_VALUE_PREFIX"x"
#define PRIXVALUE PRI_VALUE_PREFIX"X"
#define PRIsVALUE PRI_VALUE_PREFIX"i" RUBY_PRI_VALUE_MARK
#define PRIdPTRDIFF PRI_PTRDIFF_PREFIX"d"
#define PRIiPTRDIFF PRI_PTRDIFF_PREFIX"i"
#define PRIoPTRDIFF PRI_PTRDIFF_PREFIX"o"
#define PRIuPTRDIFF PRI_PTRDIFF_PREFIX"u"
#define PRIxPTRDIFF PRI_PTRDIFF_PREFIX"x"
#define PRIXPTRDIFF PRI_PTRDIFF_PREFIX"X"
#define PRIdSIZE PRI_SIZE_PREFIX"d"
#define PRIiSIZE PRI_SIZE_PREFIX"i"
#define PRIoSIZE PRI_SIZE_PREFIX"o"
#define PRIuSIZE PRI_SIZE_PREFIX"u"
#define PRIxSIZE PRI_SIZE_PREFIX"x"
#define PRIXSIZE PRI_SIZE_PREFIX"X"
#define __CLANG_LIMITS_H 
#define _GCC_LIMITS_H_ 
#define _LIMITS_H_ 
#define _ARM_LIMITS_H_ 
#define _ARM__LIMITS_H_ 
#define __DARWIN_CLK_TCK 100
#define CHAR_BIT 8
#define MB_LEN_MAX 6
#define CLK_TCK __DARWIN_CLK_TCK
#define SCHAR_MAX 127
#define SCHAR_MIN (-128)
#define UCHAR_MAX 255
#define CHAR_MAX 127
#define CHAR_MIN (-128)
#define USHRT_MAX 65535
#define SHRT_MAX 32767
#define SHRT_MIN (-32768)
#define UINT_MAX 0xffffffff
#define INT_MAX 2147483647
#define INT_MIN (-2147483647-1)
#define ULONG_MAX 0xffffffffffffffffUL
#define LONG_MAX 0x7fffffffffffffffL
#define LONG_MIN (-0x7fffffffffffffffL-1)
#define ULLONG_MAX 0xffffffffffffffffULL
#define LLONG_MAX 0x7fffffffffffffffLL
#define LLONG_MIN (-0x7fffffffffffffffLL-1)
#define LONG_BIT 64
#define SSIZE_MAX LONG_MAX
#define WORD_BIT 32
#define SIZE_T_MAX ULONG_MAX
#define UQUAD_MAX ULLONG_MAX
#define QUAD_MAX LLONG_MAX
#define QUAD_MIN LLONG_MIN
#define _SYS_SYSLIMITS_H_ 
#define ARG_MAX (1024 * 1024)
#define CHILD_MAX 266
#define GID_MAX 2147483647U
#define LINK_MAX 32767
#define MAX_CANON 1024
#define MAX_INPUT 1024
#define NAME_MAX 255
#define NGROUPS_MAX 16
#define UID_MAX 2147483647U
#define OPEN_MAX 10240
#define PATH_MAX 1024
#define PIPE_BUF 512
#define BC_BASE_MAX 99
#define BC_DIM_MAX 2048
#define BC_SCALE_MAX 99
#define BC_STRING_MAX 1000
#define CHARCLASS_NAME_MAX 14
#define COLL_WEIGHTS_MAX 2
#define EQUIV_CLASS_MAX 2
#define EXPR_NEST_MAX 32
#define LINE_MAX 2048
#define RE_DUP_MAX 255
#define NZERO 20
#define _POSIX_ARG_MAX 4096
#define _POSIX_CHILD_MAX 25
#define _POSIX_LINK_MAX 8
#define _POSIX_MAX_CANON 255
#define _POSIX_MAX_INPUT 255
#define _POSIX_NAME_MAX 14
#define _POSIX_NGROUPS_MAX 8
#define _POSIX_OPEN_MAX 20
#define _POSIX_PATH_MAX 256
#define _POSIX_PIPE_BUF 512
#define _POSIX_SSIZE_MAX 32767
#define _POSIX_STREAM_MAX 8
#define _POSIX_TZNAME_MAX 6
#define _POSIX2_BC_BASE_MAX 99
#define _POSIX2_BC_DIM_MAX 2048
#define _POSIX2_BC_SCALE_MAX 99
#define _POSIX2_BC_STRING_MAX 1000
#define _POSIX2_EQUIV_CLASS_MAX 2
#define _POSIX2_EXPR_NEST_MAX 32
#define _POSIX2_LINE_MAX 2048
#define _POSIX2_RE_DUP_MAX 255
#define _POSIX_AIO_LISTIO_MAX 2
#define _POSIX_AIO_MAX 1
#define _POSIX_DELAYTIMER_MAX 32
#define _POSIX_MQ_OPEN_MAX 8
#define _POSIX_MQ_PRIO_MAX 32
#define _POSIX_RTSIG_MAX 8
#define _POSIX_SEM_NSEMS_MAX 256
#define _POSIX_SEM_VALUE_MAX 32767
#define _POSIX_SIGQUEUE_MAX 32
#define _POSIX_TIMER_MAX 32
#define _POSIX_CLOCKRES_MIN 20000000
#define _POSIX_THREAD_DESTRUCTOR_ITERATIONS 4
#define _POSIX_THREAD_KEYS_MAX 128
#define _POSIX_THREAD_THREADS_MAX 64
#define PTHREAD_DESTRUCTOR_ITERATIONS 4
#define PTHREAD_KEYS_MAX 512
#define PTHREAD_STACK_MIN 16384
#define _POSIX_HOST_NAME_MAX 255
#define _POSIX_LOGIN_NAME_MAX 9
#define _POSIX_SS_REPL_MAX 4
#define _POSIX_SYMLINK_MAX 255
#define _POSIX_SYMLOOP_MAX 8
#define _POSIX_TRACE_EVENT_NAME_MAX 30
#define _POSIX_TRACE_NAME_MAX 8
#define _POSIX_TRACE_SYS_MAX 8
#define _POSIX_TRACE_USER_EVENT_MAX 32
#define _POSIX_TTY_NAME_MAX 9
#define _POSIX2_CHARCLASS_NAME_MAX 14
#define _POSIX2_COLL_WEIGHTS_MAX 2
#define _POSIX_RE_DUP_MAX _POSIX2_RE_DUP_MAX
#define OFF_MIN LLONG_MIN
#define OFF_MAX LLONG_MAX
#define PASS_MAX 128
#define NL_ARGMAX 9
#define NL_LANGMAX 14
#define NL_MSGMAX 32767
#define NL_NMAX 1
#define NL_SETMAX 255
#define NL_TEXTMAX 2048
#define _XOPEN_IOV_MAX 16
#define IOV_MAX 1024
#define _XOPEN_NAME_MAX 255
#define _XOPEN_PATH_MAX 1024
#undef SCHAR_MIN
#undef SCHAR_MAX
#undef UCHAR_MAX
#undef SHRT_MIN
#undef SHRT_MAX
#undef USHRT_MAX
#undef INT_MIN
#undef INT_MAX
#undef UINT_MAX
#undef LONG_MIN
#undef LONG_MAX
#undef ULONG_MAX
#undef CHAR_BIT
#undef CHAR_MIN
#undef CHAR_MAX
#define SCHAR_MAX __SCHAR_MAX__
#define SHRT_MAX __SHRT_MAX__
#define INT_MAX __INT_MAX__
#define LONG_MAX __LONG_MAX__
#define SCHAR_MIN (-__SCHAR_MAX__-1)
#define SHRT_MIN (-__SHRT_MAX__ -1)
#define INT_MIN (-__INT_MAX__ -1)
#define LONG_MIN (-__LONG_MAX__ -1L)
#define UCHAR_MAX (__SCHAR_MAX__*2 +1)
#define USHRT_MAX (__SHRT_MAX__ *2 +1)
#define UINT_MAX (__INT_MAX__ *2U +1U)
#define ULONG_MAX (__LONG_MAX__ *2UL+1UL)
#define CHAR_BIT __CHAR_BIT__
#define CHAR_MIN SCHAR_MIN
#define CHAR_MAX __SCHAR_MAX__
#undef LLONG_MIN
#undef LLONG_MAX
#undef ULLONG_MAX
#define LLONG_MAX __LONG_LONG_MAX__
#define LLONG_MIN (-__LONG_LONG_MAX__-1LL)
#define ULLONG_MAX (__LONG_LONG_MAX__*2ULL+1ULL)
#undef LONG_LONG_MIN
#undef LONG_LONG_MAX
#undef ULONG_LONG_MAX
#define LONG_LONG_MAX __LONG_LONG_MAX__
#define LONG_LONG_MIN (-__LONG_LONG_MAX__-1LL)
#define ULONG_LONG_MAX (__LONG_LONG_MAX__*2ULL+1ULL)
#define RUBY_FIXNUM_MAX (LONG_MAX>>1)
#define RUBY_FIXNUM_MIN RSHIFT((long)LONG_MIN,1)
#define FIXNUM_MAX RUBY_FIXNUM_MAX
#define FIXNUM_MIN RUBY_FIXNUM_MIN
#define RB_INT2FIX(i) (((VALUE)(i))<<1 | RUBY_FIXNUM_FLAG)
#define INT2FIX(i) RB_INT2FIX(i)
#define RB_LONG2FIX(i) RB_INT2FIX(i)
#define LONG2FIX(i) RB_INT2FIX(i)
#define rb_fix_new(v) RB_INT2FIX(v)
#define rb_int_new(v) rb_int2inum(v)
#define rb_uint_new(v) rb_uint2inum(v)
#define LL2NUM(v) rb_ll2inum(v)
#define ULL2NUM(v) rb_ull2inum(v)
#define SIZET2NUM(v) ULONG2NUM(v)
#define SSIZET2NUM(v) LONG2NUM(v)
#define rb_long2int(n) rb_long2int_inline(n)
#define RB_FIX2LONG(x) ((long)RSHIFT((SIGNED_VALUE)(x),1))
#define RB_FIX2ULONG(x) ((unsigned long)RB_FIX2LONG(x))
#define RB_FIXNUM_P(f) (((int)(SIGNED_VALUE)(f))&RUBY_FIXNUM_FLAG)
#define RB_POSFIXABLE(f) ((f) < RUBY_FIXNUM_MAX+1)
#define RB_NEGFIXABLE(f) ((f) >= RUBY_FIXNUM_MIN)
#define RB_FIXABLE(f) (RB_POSFIXABLE(f) && RB_NEGFIXABLE(f))
#define FIX2LONG(x) RB_FIX2LONG(x)
#define FIX2ULONG(x) RB_FIX2ULONG(x)
#define FIXNUM_P(f) RB_FIXNUM_P(f)
#define POSFIXABLE(f) RB_POSFIXABLE(f)
#define NEGFIXABLE(f) RB_NEGFIXABLE(f)
#define FIXABLE(f) RB_FIXABLE(f)
#define RB_IMMEDIATE_P(x) ((VALUE)(x) & RUBY_IMMEDIATE_MASK)
#define IMMEDIATE_P(x) RB_IMMEDIATE_P(x)
#define RB_STATIC_SYM_P(x) (((VALUE)(x)&~((~(VALUE)0)<<RUBY_SPECIAL_SHIFT)) == RUBY_SYMBOL_FLAG)
#define RB_DYNAMIC_SYM_P(x) (!RB_SPECIAL_CONST_P(x) && RB_BUILTIN_TYPE(x) == (RUBY_T_SYMBOL))
#define RB_SYMBOL_P(x) (RB_STATIC_SYM_P(x)||RB_DYNAMIC_SYM_P(x))
#define RB_ID2SYM(x) (rb_id2sym(x))
#define RB_SYM2ID(x) (rb_sym2id(x))
#define STATIC_SYM_P(x) RB_STATIC_SYM_P(x)
#define DYNAMIC_SYM_P(x) RB_DYNAMIC_SYM_P(x)
#define SYMBOL_P(x) RB_SYMBOL_P(x)
#define ID2SYM(x) RB_ID2SYM(x)
#define SYM2ID(x) RB_SYM2ID(x)
#define USE_FLONUM 1
#define RB_FLONUM_P(x) ((((int)(SIGNED_VALUE)(x))&RUBY_FLONUM_MASK) == RUBY_FLONUM_FLAG)
#define FLONUM_P(x) RB_FLONUM_P(x)
#define USE_SYMBOL_AS_METHOD_NAME 1
#define RUBY_Qfalse ((VALUE)RUBY_Qfalse)
#define RUBY_Qtrue ((VALUE)RUBY_Qtrue)
#define RUBY_Qnil ((VALUE)RUBY_Qnil)
#define RUBY_Qundef ((VALUE)RUBY_Qundef)
#define Qfalse RUBY_Qfalse
#define Qtrue RUBY_Qtrue
#define Qnil RUBY_Qnil
#define Qundef RUBY_Qundef
#define IMMEDIATE_MASK RUBY_IMMEDIATE_MASK
#define FIXNUM_FLAG RUBY_FIXNUM_FLAG
#define FLONUM_MASK RUBY_FLONUM_MASK
#define FLONUM_FLAG RUBY_FLONUM_FLAG
#define SYMBOL_FLAG RUBY_SYMBOL_FLAG
#define RB_TEST(v) !(((VALUE)(v) & (VALUE)~RUBY_Qnil) == 0)
#define RB_NIL_P(v) !((VALUE)(v) != RUBY_Qnil)
#define RTEST(v) RB_TEST(v)
#define NIL_P(v) RB_NIL_P(v)
#define CLASS_OF(v) rb_class_of((VALUE)(v))
#define T_NONE RUBY_T_NONE
#define T_NIL RUBY_T_NIL
#define T_OBJECT RUBY_T_OBJECT
#define T_CLASS RUBY_T_CLASS
#define T_ICLASS RUBY_T_ICLASS
#define T_MODULE RUBY_T_MODULE
#define T_FLOAT RUBY_T_FLOAT
#define T_STRING RUBY_T_STRING
#define T_REGEXP RUBY_T_REGEXP
#define T_ARRAY RUBY_T_ARRAY
#define T_HASH RUBY_T_HASH
#define T_STRUCT RUBY_T_STRUCT
#define T_BIGNUM RUBY_T_BIGNUM
#define T_FILE RUBY_T_FILE
#define T_FIXNUM RUBY_T_FIXNUM
#define T_TRUE RUBY_T_TRUE
#define T_FALSE RUBY_T_FALSE
#define T_DATA RUBY_T_DATA
#define T_MATCH RUBY_T_MATCH
#define T_SYMBOL RUBY_T_SYMBOL
#define T_RATIONAL RUBY_T_RATIONAL
#define T_COMPLEX RUBY_T_COMPLEX
#define T_IMEMO RUBY_T_IMEMO
#define T_UNDEF RUBY_T_UNDEF
#define T_NODE RUBY_T_NODE
#define T_ZOMBIE RUBY_T_ZOMBIE
#define T_MOVED RUBY_T_MOVED
#define T_MASK RUBY_T_MASK
#define RB_BUILTIN_TYPE(x) (int)(((struct RBasic*)(x))->flags & RUBY_T_MASK)
#define BUILTIN_TYPE(x) RB_BUILTIN_TYPE(x)
#define TYPE(x) rb_type((VALUE)(x))
#define RB_FLOAT_TYPE_P(obj) ( RB_FLONUM_P(obj) || (!RB_SPECIAL_CONST_P(obj) && RB_BUILTIN_TYPE(obj) == RUBY_T_FLOAT))
#define RB_TYPE_P(obj,type) ( ((type) == RUBY_T_FIXNUM) ? RB_FIXNUM_P(obj) : ((type) == RUBY_T_TRUE) ? ((obj) == RUBY_Qtrue) : ((type) == RUBY_T_FALSE) ? ((obj) == RUBY_Qfalse) : ((type) == RUBY_T_NIL) ? ((obj) == RUBY_Qnil) : ((type) == RUBY_T_UNDEF) ? ((obj) == RUBY_Qundef) : ((type) == RUBY_T_SYMBOL) ? RB_SYMBOL_P(obj) : ((type) == RUBY_T_FLOAT) ? RB_FLOAT_TYPE_P(obj) : (!RB_SPECIAL_CONST_P(obj) && RB_BUILTIN_TYPE(obj) == (type)))
#define RB_GC_GUARD(v) (*__extension__ ({ volatile VALUE *rb_gc_guarded_ptr = &(v); __asm__("" : : "m"(rb_gc_guarded_ptr)); rb_gc_guarded_ptr; }))
#define RB_UNUSED_VAR(x) x __attribute__ ((unused))
#define Check_Type(v,t) rb_check_type((VALUE)(v),(t))
#define StringValue(v) rb_string_value(&(v))
#define StringValuePtr(v) rb_string_value_ptr(&(v))
#define StringValueCStr(v) rb_string_value_cstr(&(v))
#define SafeStringValue(v) StringValue(v)
#define rb_check_safe_str(x) [<"rb_check_safe_str() is obsolete; use StringValue() instead">]
#define Check_SafeStr(v) [<"Check_SafeStr() is obsolete; use StringValue() instead">]
#define ExportStringValue(v) do { StringValue(v); (v) = rb_str_export(v);} while (0)
#define FilePathValue(v) (RB_GC_GUARD(v) = rb_get_path(v))
#define FilePathStringValue(v) ((v) = rb_get_path(v))
#define RUBY_SAFE_LEVEL_MAX 1
#define RB_NUM2LONG(x) rb_num2long_inline(x)
#define NUM2LONG(x) RB_NUM2LONG(x)
#define RB_NUM2ULONG(x) rb_num2ulong_inline(x)
#define NUM2ULONG(x) RB_NUM2ULONG(x)
#define RB_FIX2INT(x) ((int)rb_fix2int((VALUE)(x)))
#define RB_NUM2INT(x) rb_num2int_inline(x)
#define RB_NUM2UINT(x) ((unsigned int)rb_num2uint(x))
#define RB_FIX2UINT(x) ((unsigned int)rb_fix2uint(x))
#define NUM2INT(x) RB_NUM2INT(x)
#define NUM2UINT(x) RB_NUM2UINT(x)
#define FIX2INT(x) RB_FIX2INT(x)
#define FIX2UINT(x) RB_FIX2UINT(x)
#define RB_FIX2SHORT(x) (rb_fix2short((VALUE)(x)))
#define FIX2SHORT(x) RB_FIX2SHORT(x)
#define RB_NUM2SHORT(x) rb_num2short_inline(x)
#define RB_NUM2USHORT(x) rb_num2ushort(x)
#define NUM2SHORT(x) RB_NUM2SHORT(x)
#define NUM2USHORT(x) RB_NUM2USHORT(x)
#define RB_NUM2LL(x) rb_num2ll_inline(x)
#define RB_NUM2ULL(x) rb_num2ull(x)
#define NUM2LL(x) RB_NUM2LL(x)
#define NUM2ULL(x) RB_NUM2ULL(x)
#define NUM2SIZET(x) NUM2ULONG(x)
#define NUM2SSIZET(x) NUM2LONG(x)
#define NUM2DBL(x) rb_num2dbl((VALUE)(x))
#define RB_NEWOBJ(obj,type) type *(obj) = (type*)rb_newobj()
#define RB_NEWOBJ_OF(obj,type,klass,flags) type *(obj) = (type*)rb_newobj_of(klass, flags)
#define NEWOBJ(obj,type) RB_NEWOBJ(obj,type)
#define NEWOBJ_OF(obj,type,klass,flags) RB_NEWOBJ_OF(obj,type,klass,flags)
#define OBJSETUP(obj,c,t) rb_obj_setup(obj, c, t)
#define CLONESETUP(clone,obj) rb_clone_setup(clone,obj)
#define DUPSETUP(dup,obj) rb_dup_setup(dup,obj)
#define USE_RGENGC 1
#define USE_RINCGC 1
#define RGENGC_WB_PROTECTED_ARRAY 1
#define RGENGC_WB_PROTECTED_HASH 1
#define RGENGC_WB_PROTECTED_STRUCT 1
#define RGENGC_WB_PROTECTED_STRING 1
#define RGENGC_WB_PROTECTED_OBJECT 1
#define RGENGC_WB_PROTECTED_REGEXP 1
#define RGENGC_WB_PROTECTED_CLASS 1
#define RGENGC_WB_PROTECTED_FLOAT 1
#define RGENGC_WB_PROTECTED_COMPLEX 1
#define RGENGC_WB_PROTECTED_RATIONAL 1
#define RGENGC_WB_PROTECTED_BIGNUM 1
#define RGENGC_WB_PROTECTED_NODE_CREF 1
#define RUBY_FL_USER_N(n) RUBY_FL_USER##n = (1<<(RUBY_FL_USHIFT+n))
#define RB_OBJ_WB_UNPROTECT_FOR(type,obj) __extension__( __builtin_choose_expr( RGENGC_WB_PROTECTED_##type, OBJ_WB_UNPROTECT((VALUE)(obj)), ((VALUE)(obj))))
#define RBASIC_CLASS(obj) (RBASIC(obj)->klass)
#define RVALUE_EMBED_LEN_MAX RVALUE_EMBED_LEN_MAX
#define ROBJECT_EMBED_LEN_MAX ROBJECT_EMBED_LEN_MAX
#define ROBJECT_EMBED ROBJECT_EMBED
#define ROBJECT_NUMIV(o) ((RBASIC(o)->flags & ROBJECT_EMBED) ? ROBJECT_EMBED_LEN_MAX : ROBJECT(o)->as.heap.numiv)
#define ROBJECT_IVPTR(o) ((RBASIC(o)->flags & ROBJECT_EMBED) ? ROBJECT(o)->as.ary : ROBJECT(o)->as.heap.ivptr)
#define ROBJECT_IV_INDEX_TBL(o) ((RBASIC(o)->flags & ROBJECT_EMBED) ? RCLASS_IV_INDEX_TBL(rb_obj_class(o)) : ROBJECT(o)->as.heap.iv_index_tbl)
#define RCLASS_SUPER(c) rb_class_get_superclass(c)
#define RMODULE_IV_TBL(m) RCLASS_IV_TBL(m)
#define RMODULE_CONST_TBL(m) RCLASS_CONST_TBL(m)
#define RMODULE_M_TBL(m) RCLASS_M_TBL(m)
#define RMODULE_SUPER(m) RCLASS_SUPER(m)
#define RMODULE_IS_OVERLAID RMODULE_IS_OVERLAID
#define RMODULE_IS_REFINEMENT RMODULE_IS_REFINEMENT
#define RMODULE_INCLUDED_INTO_REFINEMENT RMODULE_INCLUDED_INTO_REFINEMENT
#define RFLOAT_VALUE(v) rb_float_value(v)
#define DBL2NUM(dbl) rb_float_new(dbl)
#define RUBY_ELTS_SHARED RUBY_ELTS_SHARED
#define ELTS_SHARED RUBY_ELTS_SHARED
#define RSTRING_NOEMBED RSTRING_NOEMBED
#define RSTRING_EMBED_LEN_MASK RSTRING_EMBED_LEN_MASK
#define RSTRING_EMBED_LEN_SHIFT RSTRING_EMBED_LEN_SHIFT
#define RSTRING_EMBED_LEN_MAX RSTRING_EMBED_LEN_MAX
#define RSTRING_FSTR RSTRING_FSTR
#define RSTRING_EMBED_LEN(str) (long)((RBASIC(str)->flags >> RSTRING_EMBED_LEN_SHIFT) & (RSTRING_EMBED_LEN_MASK >> RSTRING_EMBED_LEN_SHIFT))
#define RSTRING_LEN(str) (!(RBASIC(str)->flags & RSTRING_NOEMBED) ? RSTRING_EMBED_LEN(str) : RSTRING(str)->as.heap.len)
#define RSTRING_PTR(str) (!(RBASIC(str)->flags & RSTRING_NOEMBED) ? RSTRING(str)->as.ary : RSTRING(str)->as.heap.ptr)
#define RSTRING_END(str) (!(RBASIC(str)->flags & RSTRING_NOEMBED) ? (RSTRING(str)->as.ary + RSTRING_EMBED_LEN(str)) : (RSTRING(str)->as.heap.ptr + RSTRING(str)->as.heap.len))
#define RSTRING_LENINT(str) rb_long2int(RSTRING_LEN(str))
#define RSTRING_GETMEM(str,ptrvar,lenvar) (!(RBASIC(str)->flags & RSTRING_NOEMBED) ? ((ptrvar) = RSTRING(str)->as.ary, (lenvar) = RSTRING_EMBED_LEN(str)) : ((ptrvar) = RSTRING(str)->as.heap.ptr, (lenvar) = RSTRING(str)->as.heap.len))
#define USE_TRANSIENT_HEAP 1
#define RARRAY_TRANSIENT_FLAG RARRAY_TRANSIENT_FLAG
#define RARRAY_EMBED_FLAG (VALUE)RARRAY_EMBED_FLAG
#define RARRAY_EMBED_LEN_MASK (VALUE)RARRAY_EMBED_LEN_MASK
#define RARRAY_EMBED_LEN_MAX RARRAY_EMBED_LEN_MAX
#define RARRAY_EMBED_LEN_SHIFT RARRAY_EMBED_LEN_SHIFT
#define RARRAY_EMBED_LEN(a) (long)((RBASIC(a)->flags >> RARRAY_EMBED_LEN_SHIFT) & (RARRAY_EMBED_LEN_MASK >> RARRAY_EMBED_LEN_SHIFT))
#define RARRAY_LEN(a) rb_array_len(a)
#define RARRAY_LENINT(ary) rb_long2int(RARRAY_LEN(ary))
#define RARRAY_CONST_PTR(a) rb_array_const_ptr(a)
#define RARRAY_CONST_PTR_TRANSIENT(a) rb_array_const_ptr_transient(a)
#define RARRAY_TRANSIENT_P(ary) FL_TEST_RAW((ary), RARRAY_TRANSIENT_FLAG)
#define RARRAY_PTR_USE_START_TRANSIENT(a) rb_array_ptr_use_start(a, 1)
#define RARRAY_PTR_USE_END_TRANSIENT(a) rb_array_ptr_use_end(a, 1)
#define RARRAY_PTR_USE_TRANSIENT(ary,ptr_name,expr) do { const VALUE _ary = (ary); VALUE *ptr_name = (VALUE *)RARRAY_PTR_USE_START_TRANSIENT(_ary); expr; RARRAY_PTR_USE_END_TRANSIENT(_ary); } while (0)
#define RARRAY_PTR_USE_START(a) rb_array_ptr_use_start(a, 0)
#define RARRAY_PTR_USE_END(a) rb_array_ptr_use_end(a, 0)
#define RARRAY_PTR_USE(ary,ptr_name,expr) do { const VALUE _ary = (ary); VALUE *ptr_name = (VALUE *)RARRAY_PTR_USE_START(_ary); expr; RARRAY_PTR_USE_END(_ary); } while (0)
#define RARRAY_AREF(a,i) (RARRAY_CONST_PTR_TRANSIENT(a)[i])
#define RARRAY_ASET(a,i,v) do { const VALUE _ary = (a); const VALUE _v = (v); VALUE *ptr = (VALUE *)RARRAY_PTR_USE_START_TRANSIENT(_ary); RB_OBJ_WRITE(_ary, &ptr[i], _v); RARRAY_PTR_USE_END_TRANSIENT(_ary); } while (0)
#define RARRAY_PTR(a) ((VALUE *)RARRAY_CONST_PTR(RB_OBJ_WB_UNPROTECT_FOR(ARRAY, a)))
#define RREGEXP_PTR(r) (RREGEXP(r)->ptr)
#define RREGEXP_SRC(r) (RREGEXP(r)->src)
#define RREGEXP_SRC_PTR(r) RSTRING_PTR(RREGEXP(r)->src)
#define RREGEXP_SRC_LEN(r) RSTRING_LEN(RREGEXP(r)->src)
#define RREGEXP_SRC_END(r) RSTRING_END(RREGEXP(r)->src)
#define RHASH_TBL(h) rb_hash_tbl(h, __FILE__, __LINE__)
#define RHASH_ITER_LEV(h) rb_hash_iter_lev(h)
#define RHASH_IFNONE(h) rb_hash_ifnone(h)
#define RHASH_SIZE(h) rb_hash_size_num(h)
#define RHASH_EMPTY_P(h) (RHASH_SIZE(h) == 0)
#define RHASH_SET_IFNONE(h,ifnone) rb_hash_set_ifnone((VALUE)h, ifnone)
#define HAVE_TYPE_RB_DATA_TYPE_T 1
#define HAVE_RB_DATA_TYPE_T_FUNCTION 1
#define HAVE_RB_DATA_TYPE_T_PARENT 1
#define DATA_PTR(dta) (RDATA(dta)->data)
#define RTYPEDDATA_P(v) (RTYPEDDATA(v)->typed_flag == 1)
#define RTYPEDDATA_TYPE(v) (RTYPEDDATA(v)->type)
#define RTYPEDDATA_DATA(v) (RTYPEDDATA(v)->data)
#define RUBY_UNTYPED_DATA_WARNING 1
#define Check_TypedStruct(v,t) rb_check_typeddata((VALUE)(v),(t))
#define RUBY_DEFAULT_FREE ((RUBY_DATA_FUNC)-1)
#define RUBY_NEVER_FREE ((RUBY_DATA_FUNC)0)
#define RUBY_TYPED_DEFAULT_FREE RUBY_DEFAULT_FREE
#define RUBY_TYPED_NEVER_FREE RUBY_NEVER_FREE
#define RUBY_TYPED_FREE_IMMEDIATELY 1
#define RUBY_TYPED_WB_PROTECTED RUBY_FL_WB_PROTECTED
#define RUBY_TYPED_PROMOTED1 RUBY_FL_PROMOTED1
#define Data_Wrap_Struct(klass,mark,free,sval) rb_data_object_wrap((klass),(sval),(RUBY_DATA_FUNC)(mark),(RUBY_DATA_FUNC)(free))
#define Data_Make_Struct0(result,klass,type,size,mark,free,sval) VALUE result = rb_data_object_zalloc((klass), (size), (RUBY_DATA_FUNC)(mark), (RUBY_DATA_FUNC)(free)); (void)((sval) = (type *)DATA_PTR(result));
#define Data_Make_Struct(klass,type,mark,free,sval) ({ Data_Make_Struct0(data_struct_obj, klass, type, sizeof(type), mark, free, sval); data_struct_obj; })
#define TypedData_Wrap_Struct(klass,data_type,sval) rb_data_typed_object_wrap((klass),(sval),(data_type))
#define TypedData_Make_Struct0(result,klass,type,size,data_type,sval) VALUE result = rb_data_typed_object_zalloc(klass, size, data_type); (void)((sval) = (type *)DATA_PTR(result));
#define TypedData_Make_Struct(klass,type,data_type,sval) ({ TypedData_Make_Struct0(data_struct_obj, klass, type, sizeof(type), data_type, sval); data_struct_obj; })
#define Data_Get_Struct(obj,type,sval) ((sval) = (type*)rb_data_object_get(obj))
#define TypedData_Get_Struct(obj,type,data_type,sval) ((sval) = (type*)rb_check_typeddata((obj), (data_type)))
#define RSTRUCT_LEN(st) NUM2LONG(rb_struct_size(st))
#define RSTRUCT_PTR(st) rb_struct_ptr(st)
#define RSTRUCT_SET(st,idx,v) rb_struct_aset(st, INT2NUM(idx), (v))
#define RSTRUCT_GET(st,idx) rb_struct_aref(st, INT2NUM(idx))
#define RBIGNUM_SIGN(b) (rb_big_sign(b))
#define RBIGNUM_POSITIVE_P(b) (RBIGNUM_SIGN(b)!=0)
#define RBIGNUM_NEGATIVE_P(b) (RBIGNUM_SIGN(b)==0)
#define R_CAST(st) (struct st*)
#define RMOVED(obj) (R_CAST(RMoved)(obj))
#define RBASIC(obj) (R_CAST(RBasic)(obj))
#define ROBJECT(obj) (R_CAST(RObject)(obj))
#define RCLASS(obj) (R_CAST(RClass)(obj))
#define RMODULE(obj) RCLASS(obj)
#define RSTRING(obj) (R_CAST(RString)(obj))
#define RREGEXP(obj) (R_CAST(RRegexp)(obj))
#define RARRAY(obj) (R_CAST(RArray)(obj))
#define RDATA(obj) (R_CAST(RData)(obj))
#define RTYPEDDATA(obj) (R_CAST(RTypedData)(obj))
#define RFILE(obj) (R_CAST(RFile)(obj))
#define FL_SINGLETON ((VALUE)RUBY_FL_SINGLETON)
#define FL_WB_PROTECTED ((VALUE)RUBY_FL_WB_PROTECTED)
#define FL_PROMOTED0 ((VALUE)RUBY_FL_PROMOTED0)
#define FL_PROMOTED1 ((VALUE)RUBY_FL_PROMOTED1)
#define FL_FINALIZE ((VALUE)RUBY_FL_FINALIZE)
#define FL_TAINT ((VALUE)RUBY_FL_TAINT)
#define FL_UNTRUSTED ((VALUE)RUBY_FL_UNTRUSTED)
#define FL_SEEN_OBJ_ID ((VALUE)RUBY_FL_SEEN_OBJ_ID)
#define FL_EXIVAR ((VALUE)RUBY_FL_EXIVAR)
#define FL_FREEZE ((VALUE)RUBY_FL_FREEZE)
#define FL_USHIFT ((VALUE)RUBY_FL_USHIFT)
#define FL_USER0 ((VALUE)RUBY_FL_USER0)
#define FL_USER1 ((VALUE)RUBY_FL_USER1)
#define FL_USER2 ((VALUE)RUBY_FL_USER2)
#define FL_USER3 ((VALUE)RUBY_FL_USER3)
#define FL_USER4 ((VALUE)RUBY_FL_USER4)
#define FL_USER5 ((VALUE)RUBY_FL_USER5)
#define FL_USER6 ((VALUE)RUBY_FL_USER6)
#define FL_USER7 ((VALUE)RUBY_FL_USER7)
#define FL_USER8 ((VALUE)RUBY_FL_USER8)
#define FL_USER9 ((VALUE)RUBY_FL_USER9)
#define FL_USER10 ((VALUE)RUBY_FL_USER10)
#define FL_USER11 ((VALUE)RUBY_FL_USER11)
#define FL_USER12 ((VALUE)RUBY_FL_USER12)
#define FL_USER13 ((VALUE)RUBY_FL_USER13)
#define FL_USER14 ((VALUE)RUBY_FL_USER14)
#define FL_USER15 ((VALUE)RUBY_FL_USER15)
#define FL_USER16 ((VALUE)RUBY_FL_USER16)
#define FL_USER17 ((VALUE)RUBY_FL_USER17)
#define FL_USER18 ((VALUE)RUBY_FL_USER18)
#define FL_USER19 ((VALUE)(unsigned int)RUBY_FL_USER19)
#define RB_SPECIAL_CONST_P(x) (RB_IMMEDIATE_P(x) || !RB_TEST(x))
#define SPECIAL_CONST_P(x) RB_SPECIAL_CONST_P(x)
#define RB_FL_ABLE(x) (!RB_SPECIAL_CONST_P(x) && RB_BUILTIN_TYPE(x) != RUBY_T_NODE)
#define RB_FL_TEST_RAW(x,f) (RBASIC(x)->flags&(f))
#define RB_FL_TEST(x,f) (RB_FL_ABLE(x)?RB_FL_TEST_RAW((x),(f)):0)
#define RB_FL_ANY_RAW(x,f) RB_FL_TEST_RAW((x),(f))
#define RB_FL_ANY(x,f) RB_FL_TEST((x),(f))
#define RB_FL_ALL_RAW(x,f) (RB_FL_TEST_RAW((x),(f)) == (f))
#define RB_FL_ALL(x,f) (RB_FL_TEST((x),(f)) == (f))
#define RB_FL_SET_RAW(x,f) (void)(RBASIC(x)->flags |= (f))
#define RB_FL_SET(x,f) (RB_FL_ABLE(x) ? RB_FL_SET_RAW(x, f) : (void)0)
#define RB_FL_UNSET_RAW(x,f) (void)(RBASIC(x)->flags &= ~(VALUE)(f))
#define RB_FL_UNSET(x,f) (RB_FL_ABLE(x) ? RB_FL_UNSET_RAW(x, f) : (void)0)
#define RB_FL_REVERSE_RAW(x,f) (void)(RBASIC(x)->flags ^= (f))
#define RB_FL_REVERSE(x,f) (RB_FL_ABLE(x) ? RB_FL_REVERSE_RAW(x, f) : (void)0)
#define RB_OBJ_TAINTABLE(x) (RB_FL_ABLE(x) && RB_BUILTIN_TYPE(x) != RUBY_T_BIGNUM && RB_BUILTIN_TYPE(x) != RUBY_T_FLOAT)
#define RB_OBJ_TAINTED_RAW(x) RB_FL_TEST_RAW(x, RUBY_FL_TAINT)
#define RB_OBJ_TAINTED(x) (!!RB_FL_TEST((x), RUBY_FL_TAINT))
#define RB_OBJ_TAINT_RAW(x) RB_FL_SET_RAW(x, RUBY_FL_TAINT)
#define RB_OBJ_TAINT(x) (RB_OBJ_TAINTABLE(x) ? RB_OBJ_TAINT_RAW(x) : (void)0)
#define RB_OBJ_UNTRUSTED(x) RB_OBJ_TAINTED(x)
#define RB_OBJ_UNTRUST(x) RB_OBJ_TAINT(x)
#define RB_OBJ_INFECT_RAW(x,s) RB_FL_SET_RAW(x, RB_OBJ_TAINTED_RAW(s))
#define RB_OBJ_INFECT(x,s) ( (RB_OBJ_TAINTABLE(x) && RB_FL_ABLE(s)) ? RB_OBJ_INFECT_RAW(x, s) : (void)0)
#define RB_OBJ_FROZEN_RAW(x) (RBASIC(x)->flags&RUBY_FL_FREEZE)
#define RB_OBJ_FROZEN(x) (!RB_FL_ABLE(x) || RB_OBJ_FROZEN_RAW(x))
#define RB_OBJ_FREEZE_RAW(x) (void)(RBASIC(x)->flags |= RUBY_FL_FREEZE)
#define RB_OBJ_FREEZE(x) rb_obj_freeze_inline((VALUE)x)
#define FL_ABLE(x) RB_FL_ABLE(x)
#define FL_TEST_RAW(x,f) RB_FL_TEST_RAW(x,f)
#define FL_TEST(x,f) RB_FL_TEST(x,f)
#define FL_ANY_RAW(x,f) RB_FL_ANY_RAW(x,f)
#define FL_ANY(x,f) RB_FL_ANY(x,f)
#define FL_ALL_RAW(x,f) RB_FL_ALL_RAW(x,f)
#define FL_ALL(x,f) RB_FL_ALL(x,f)
#define FL_SET_RAW(x,f) RB_FL_SET_RAW(x,f)
#define FL_SET(x,f) RB_FL_SET(x,f)
#define FL_UNSET_RAW(x,f) RB_FL_UNSET_RAW(x,f)
#define FL_UNSET(x,f) RB_FL_UNSET(x,f)
#define FL_REVERSE_RAW(x,f) RB_FL_REVERSE_RAW(x,f)
#define FL_REVERSE(x,f) RB_FL_REVERSE(x,f)
#define OBJ_TAINTABLE(x) RB_OBJ_TAINTABLE(x)
#define OBJ_TAINTED_RAW(x) RB_OBJ_TAINTED_RAW(x)
#define OBJ_TAINTED(x) RB_OBJ_TAINTED(x)
#define OBJ_TAINT_RAW(x) RB_OBJ_TAINT_RAW(x)
#define OBJ_TAINT(x) RB_OBJ_TAINT(x)
#define OBJ_UNTRUSTED(x) RB_OBJ_UNTRUSTED(x)
#define OBJ_UNTRUST(x) RB_OBJ_UNTRUST(x)
#define OBJ_INFECT_RAW(x,s) RB_OBJ_INFECT_RAW(x,s)
#define OBJ_INFECT(x,s) RB_OBJ_INFECT(x,s)
#define OBJ_FROZEN_RAW(x) RB_OBJ_FROZEN_RAW(x)
#define OBJ_FROZEN(x) RB_OBJ_FROZEN(x)
#define OBJ_FREEZE_RAW(x) RB_OBJ_FREEZE_RAW(x)
#define OBJ_FREEZE(x) RB_OBJ_FREEZE(x)
#define RUBY_UNTYPED_DATA_FUNC(func) DEPRECATED(func)
#define rb_data_object_wrap_warning(klass,ptr,mark,free) __extension__( __builtin_choose_expr( __builtin_constant_p(klass) && !(klass), rb_data_object_wrap(klass, ptr, mark, free), rb_data_object_wrap_warning(klass, ptr, mark, free)))
#define rb_data_object_wrap_0 rb_data_object_wrap
#define rb_data_object_wrap_1 rb_data_object_wrap_warning
#define rb_data_object_wrap RUBY_MACRO_SELECT(rb_data_object_wrap_, RUBY_UNTYPED_DATA_WARNING)
#define rb_data_object_get_0 rb_data_object_get
#define rb_data_object_get_1 rb_data_object_get_warning
#define rb_data_object_get RUBY_MACRO_SELECT(rb_data_object_get_, RUBY_UNTYPED_DATA_WARNING)
#define rb_data_object_make_0 rb_data_object_make
#define rb_data_object_make_1 rb_data_object_make_warning
#define rb_data_object_make RUBY_MACRO_SELECT(rb_data_object_make_, RUBY_UNTYPED_DATA_WARNING)
#define RB_OBJ_PROMOTED_RAW(x) RB_FL_ALL_RAW(x, RUBY_FL_PROMOTED)
#define RB_OBJ_PROMOTED(x) (RB_SPECIAL_CONST_P(x) ? 0 : RB_OBJ_PROMOTED_RAW(x))
#define RB_OBJ_WB_UNPROTECT(x) rb_obj_wb_unprotect(x, __FILE__, __LINE__)
#define OBJ_PROMOTED_RAW(x) RB_OBJ_PROMOTED_RAW(x)
#define OBJ_PROMOTED(x) RB_OBJ_PROMOTED(x)
#define OBJ_WB_UNPROTECT(x) RB_OBJ_WB_UNPROTECT(x)
#define RB_OBJ_WRITE(a,slot,b) rb_obj_write((VALUE)(a), (VALUE *)(slot), (VALUE)(b), __FILE__, __LINE__)
#define RB_OBJ_WRITTEN(a,oldv,b) rb_obj_written((VALUE)(a), (VALUE)(oldv), (VALUE)(b), __FILE__, __LINE__)
#define USE_RGENGC_LOGGING_WB_UNPROTECT 0
#define RUBY_INTEGER_UNIFICATION 1
#define RB_INTEGER_TYPE_P(obj) rb_integer_type_p(obj)
#define rb_integer_type_p(obj) __extension__ ({ const VALUE integer_type_obj = (obj); (RB_FIXNUM_P(integer_type_obj) || (!RB_SPECIAL_CONST_P(integer_type_obj) && RB_BUILTIN_TYPE(integer_type_obj) == RUBY_T_BIGNUM)); })
#define RB_INT2NUM(v) RB_INT2FIX((int)(v))
#define RB_UINT2NUM(v) RB_LONG2FIX((unsigned int)(v))
#define INT2NUM(x) RB_INT2NUM(x)
#define UINT2NUM(x) RB_UINT2NUM(x)
#define RB_LONG2NUM(x) rb_long2num_inline(x)
#define RB_ULONG2NUM(x) rb_ulong2num_inline(x)
#define RB_NUM2CHR(x) rb_num2char_inline(x)
#define RB_CHR2FIX(x) RB_INT2FIX((long)((x)&0xff))
#define LONG2NUM(x) RB_LONG2NUM(x)
#define ULONG2NUM(x) RB_ULONG2NUM(x)
#define USHORT2NUM(x) RB_INT2FIX(x)
#define NUM2CHR(x) RB_NUM2CHR(x)
#define CHR2FIX(x) RB_CHR2FIX(x)
#define RB_ST2FIX(h) RB_LONG2FIX((long)(h))
#define ST2FIX(h) RB_ST2FIX(h)
#define RB_ALLOC_N(type,n) ((type*)ruby_xmalloc2((size_t)(n),sizeof(type)))
#define RB_ALLOC(type) ((type*)ruby_xmalloc(sizeof(type)))
#define RB_ZALLOC_N(type,n) ((type*)ruby_xcalloc((size_t)(n),sizeof(type)))
#define RB_ZALLOC(type) (RB_ZALLOC_N(type,1))
#define RB_REALLOC_N(var,type,n) ((var)=(type*)ruby_xrealloc2((char*)(var),(size_t)(n),sizeof(type)))
#define ALLOC_N(type,n) RB_ALLOC_N(type,n)
#define ALLOC(type) RB_ALLOC(type)
#define ZALLOC_N(type,n) RB_ZALLOC_N(type,n)
#define ZALLOC(type) RB_ZALLOC(type)
#define REALLOC_N(var,type,n) RB_REALLOC_N(var,type,n)
#define ALLOCA_N(type,n) (type*)__builtin_alloca_with_align((sizeof(type)*(n)), RUBY_ALIGNOF(type) * CHAR_BIT)
#define DSIZE_T uint128_t
#define RUBY_ALLOCV_LIMIT 1024
#define RB_ALLOCV(v,n) ((n) < RUBY_ALLOCV_LIMIT ? ((v) = 0, alloca(n)) : rb_alloc_tmp_buffer(&(v), (n)))
#define RB_ALLOCV_N(type,v,n) ((type*)(((size_t)(n) < RUBY_ALLOCV_LIMIT / sizeof(type)) ? ((v) = 0, alloca((size_t)(n) * sizeof(type))) : rb_alloc_tmp_buffer2(&(v), (long)(n), sizeof(type))))
#define RB_ALLOCV_END(v) rb_free_tmp_buffer(&(v))
#define ALLOCV(v,n) RB_ALLOCV(v, n)
#define ALLOCV_N(type,v,n) RB_ALLOCV_N(type, v, n)
#define ALLOCV_END(v) RB_ALLOCV_END(v)
#define MEMZERO(p,type,n) memset((p), 0, sizeof(type)*(size_t)(n))
#define MEMCPY(p1,p2,type,n) memcpy((p1), (p2), sizeof(type)*(size_t)(n))
#define MEMMOVE(p1,p2,type,n) memmove((p1), (p2), sizeof(type)*(size_t)(n))
#define MEMCMP(p1,p2,type,n) memcmp((p1), (p2), sizeof(type)*(size_t)(n))
#define RUBY_CONST_ID_CACHE(result,str) { static ID rb_intern_id_cache; if (!rb_intern_id_cache) rb_intern_id_cache = rb_intern2((str), (long)strlen(str)); result rb_intern_id_cache; }
#define RUBY_CONST_ID(var,str) do RUBY_CONST_ID_CACHE((var) =, (str)) while (0)
#define CONST_ID_CACHE(result,str) RUBY_CONST_ID_CACHE(result, str)
#define CONST_ID(var,str) RUBY_CONST_ID(var, str)
#define rb_intern(str) (__builtin_constant_p(str) ? __extension__ (RUBY_CONST_ID_CACHE((ID), (str))) : rb_intern(str))
#define rb_intern_const(str) (__builtin_constant_p(str) ? __extension__ (rb_intern2((str), (long)strlen(str))) : (rb_intern)(str))
#define rb_varargs_argc_check_runtime(argc,vargc) (((argc) <= (vargc)) ? (argc) : (rb_fatal("argc(%d) exceeds actual arguments(%d)", argc, vargc), 0))
#define rb_varargs_argc_valid_p(argc,vargc) ((argc) == 0 ? (vargc) <= 1 : (argc) == (vargc))
#define rb_varargs_bad_length(argc,vargc) ((argc)/rb_varargs_argc_valid_p(argc, vargc))
#define rb_varargs_argc_check(argc,vargc) __builtin_choose_expr(__builtin_constant_p(argc), (rb_varargs_argc_valid_p(argc, vargc) ? (argc) : rb_varargs_bad_length(argc, vargc)), rb_varargs_argc_check_runtime(argc, vargc))
#define rb_funcall2 rb_funcallv
#define rb_funcall3 rb_funcallv_public
#define RB_SCAN_ARGS_PASS_CALLED_KEYWORDS 0
#define RB_SCAN_ARGS_KEYWORDS 1
#define RB_SCAN_ARGS_EMPTY_KEYWORDS 2
#define RB_SCAN_ARGS_LAST_HASH_KEYWORDS 3
#define HAVE_RB_SCAN_ARGS_OPTIONAL_HASH 1
#define ruby_verbose (*rb_ruby_verbose_ptr())
#define ruby_debug (*rb_ruby_debug_ptr())
#define RB_IO_WAIT_READABLE RB_IO_WAIT_READABLE
#define RB_IO_WAIT_WRITABLE RB_IO_WAIT_WRITABLE
#define RB_BLOCK_CALL_FUNC_STRICT 1
#define RUBY_BLOCK_CALL_FUNC_TAKES_BLOCKARG 1
#define RB_BLOCK_CALL_FUNC_ARGLIST(yielded_arg,callback_arg) VALUE yielded_arg, VALUE callback_arg, int argc, const VALUE *argv, VALUE blockarg
#define RB_NO_KEYWORDS 0
#define RB_PASS_KEYWORDS 1
#define RB_PASS_EMPTY_KEYWORDS 2
#define RB_PASS_CALLED_KEYWORDS 3
#define rb_type_p(obj,type) __extension__ (__builtin_constant_p(type) ? RB_TYPE_P((obj), (type)) : rb_type(obj) == (type))
#define rb_special_const_p(obj) __extension__ ({ VALUE special_const_obj = (obj); (int)(RB_SPECIAL_CONST_P(special_const_obj) ? RUBY_Qtrue : RUBY_Qfalse); })
#define RUBY_INTERN_H 1
#define RUBY_ST_H 1
#pragma GCC visibility push(default)
#define ST_DATA_T_DEFINED 
#define MAX_ST_INDEX_VAL (~(st_index_t) 0)
#define SIZEOF_ST_INDEX_T SIZEOF_VOIDP
#define ST_INDEX_BITS (SIZEOF_ST_INDEX_T * CHAR_BIT)
#define ST_DATA_COMPATIBLE_P(type) __builtin_choose_expr(__builtin_types_compatible_p(type, st_data_t), 1, 0)
#define st_is_member(table,key) st_lookup((table),(key),(st_data_t *)0)
#define st_init_table rb_st_init_table
#define st_init_table_with_size rb_st_init_table_with_size
#define st_init_numtable rb_st_init_numtable
#define st_init_numtable_with_size rb_st_init_numtable_with_size
#define st_init_strtable rb_st_init_strtable
#define st_init_strtable_with_size rb_st_init_strtable_with_size
#define st_init_strcasetable rb_st_init_strcasetable
#define st_init_strcasetable_with_size rb_st_init_strcasetable_with_size
#define st_delete rb_st_delete
#define st_delete_safe rb_st_delete_safe
#define st_shift rb_st_shift
#define st_insert rb_st_insert
#define st_insert2 rb_st_insert2
#define st_lookup rb_st_lookup
#define st_get_key rb_st_get_key
#define st_update rb_st_update
#define st_foreach_with_replace rb_st_foreach_with_replace
#define st_foreach rb_st_foreach
#define st_foreach_check rb_st_foreach_check
#define st_keys rb_st_keys
#define st_keys_check rb_st_keys_check
#define st_values rb_st_values
#define st_values_check rb_st_values_check
#define st_add_direct rb_st_add_direct
#define st_free_table rb_st_free_table
#define st_cleanup_safe rb_st_cleanup_safe
#define st_clear rb_st_clear
#define st_copy rb_st_copy
#define st_numcmp rb_st_numcmp
#define st_numhash rb_st_numhash
#define st_locale_insensitive_strcasecmp rb_st_locale_insensitive_strcasecmp
#define st_locale_insensitive_strncasecmp rb_st_locale_insensitive_strncasecmp
#define st_strcasecmp rb_st_locale_insensitive_strcasecmp
#define st_strncasecmp rb_st_locale_insensitive_strncasecmp
#define st_memsize rb_st_memsize
#define st_hash rb_st_hash
#define st_hash_uint32 rb_st_hash_uint32
#define st_hash_uint rb_st_hash_uint
#define st_hash_end rb_st_hash_end
#define st_hash_start(h) ((st_index_t)(h))
#pragma GCC visibility pop
#define MJIT_STATIC static
#pragma GCC visibility push(default)
#define UNLIMITED_ARGUMENTS (-1)
#define rb_ary_new2 rb_ary_new_capa
#define rb_ary_new3 rb_ary_new_from_args
#define rb_ary_new4 rb_ary_new_from_values
#define rb_big2int(x) rb_big2long(x)
#define rb_big2uint(x) rb_big2ulong(x)
#define INTEGER_PACK_MSWORD_FIRST 0x01
#define INTEGER_PACK_LSWORD_FIRST 0x02
#define INTEGER_PACK_MSBYTE_FIRST 0x10
#define INTEGER_PACK_LSBYTE_FIRST 0x20
#define INTEGER_PACK_NATIVE_BYTE_ORDER 0x40
#define INTEGER_PACK_2COMP 0x80
#define INTEGER_PACK_FORCE_GENERIC_IMPLEMENTATION 0x400
#define INTEGER_PACK_FORCE_BIGNUM 0x100
#define INTEGER_PACK_NEGATIVE 0x200
#define INTEGER_PACK_LITTLE_ENDIAN (INTEGER_PACK_LSWORD_FIRST | INTEGER_PACK_LSBYTE_FIRST)
#define INTEGER_PACK_BIG_ENDIAN (INTEGER_PACK_MSWORD_FIRST | INTEGER_PACK_MSBYTE_FIRST)
#define rb_rational_raw1(x) rb_rational_raw((x), INT2FIX(1))
#define rb_rational_raw2(x,y) rb_rational_raw((x), (y))
#define rb_rational_new1(x) rb_rational_new((x), INT2FIX(1))
#define rb_rational_new2(x,y) rb_rational_new((x), (y))
#define rb_Rational1(x) rb_Rational((x), INT2FIX(1))
#define rb_Rational2(x,y) rb_Rational((x), (y))
#define rb_complex_raw1(x) rb_complex_raw((x), INT2FIX(0))
#define rb_complex_raw2(x,y) rb_complex_raw((x), (y))
#define rb_complex_new1(x) rb_complex_new((x), INT2FIX(0))
#define rb_complex_new2(x,y) rb_complex_new((x), (y))
#define rb_complex_add rb_complex_plus
#define rb_complex_sub rb_complex_minus
#define rb_complex_nagate rb_complex_uminus
#define rb_Complex1(x) rb_Complex((x), INT2FIX(0))
#define rb_Complex2(x,y) rb_Complex((x), (y))
#define SIZED_ENUMERATOR(obj,argc,argv,size_fn) rb_enumeratorize_with_size((obj), ID2SYM(rb_frame_this_func()), (argc), (argv), (size_fn))
#define SIZED_ENUMERATOR_KW(obj,argc,argv,size_fn,kw_splat) rb_enumeratorize_with_size_kw((obj), ID2SYM(rb_frame_this_func()), (argc), (argv), (size_fn), (kw_splat))
#define RETURN_SIZED_ENUMERATOR(obj,argc,argv,size_fn) do { if (!rb_block_given_p()) return SIZED_ENUMERATOR(obj, argc, argv, size_fn); } while (0)
#define RETURN_SIZED_ENUMERATOR_KW(obj,argc,argv,size_fn,kw_splat) do { if (!rb_block_given_p()) return SIZED_ENUMERATOR_KW(obj, argc, argv, size_fn, kw_splat); } while (0)
#define RETURN_ENUMERATOR(obj,argc,argv) RETURN_SIZED_ENUMERATOR(obj, argc, argv, 0)
#define RETURN_ENUMERATOR_KW(obj,argc,argv,kw_splat) RETURN_SIZED_ENUMERATOR_KW(obj, argc, argv, 0, kw_splat)
#define rb_exc_new2 rb_exc_new_cstr
#define rb_exc_new3 rb_exc_new_str
#define rb_check_frozen_internal(obj) do { VALUE frozen_obj = (obj); if (RB_UNLIKELY(RB_OBJ_FROZEN(frozen_obj))) { rb_error_frozen_object(frozen_obj); } } while (0)
#define rb_check_frozen(obj) __extension__({rb_check_frozen_internal(obj);})
#define RB_OBJ_INIT_COPY(obj,orig) ((obj) != (orig) && (rb_obj_init_copy((obj), (orig)), 1))
#define OBJ_INIT_COPY(obj,orig) RB_OBJ_INIT_COPY(obj, orig)
#define rb_check_arity rb_check_arity
#define rb_fd_ptr(f) ((f)->fdset)
#define rb_fd_max(f) ((f)->maxfd)
#define HAVE_RB_DEFINE_ALLOC_FUNC 1
#define st_foreach_safe rb_st_foreach_safe
#define rb_defout rb_stdout
#define RB_RESERVED_FD_P(fd) rb_reserved_fd_p(fd)
#define RB_NUM_COERCE_FUNCS_NEED_OPID 1
#define rb_memcmp memcmp
#define HAVE_RB_REG_NEW_STR 1
#define rb_argv rb_get_argv()
#define posix_signal ruby_posix_signal
#define rb_str_dup_frozen rb_str_new_frozen
#define rb_hash_uint32(h,i) st_hash_uint32((h), (i))
#define rb_hash_uint(h,i) st_hash_uint((h), (i))
#define rb_hash_end(h) st_hash_end(h)
#define rb_str_new(str,len) RB_GNUC_EXTENSION_BLOCK( (__builtin_constant_p(str) && __builtin_constant_p(len)) ? rb_str_new_static((str), (len)) : rb_str_new((str), (len)) )
#define rb_str_new_cstr(str) RB_GNUC_EXTENSION_BLOCK( (__builtin_constant_p(str)) ? rb_str_new_static((str), (long)strlen(str)) : rb_str_new_cstr(str) )
#define rb_usascii_str_new(str,len) RB_GNUC_EXTENSION_BLOCK( (__builtin_constant_p(str) && __builtin_constant_p(len)) ? rb_usascii_str_new_static((str), (len)) : rb_usascii_str_new((str), (len)) )
#define rb_utf8_str_new(str,len) RB_GNUC_EXTENSION_BLOCK( (__builtin_constant_p(str) && __builtin_constant_p(len)) ? rb_utf8_str_new_static((str), (len)) : rb_utf8_str_new((str), (len)) )
#define rb_tainted_str_new_cstr(str) RB_GNUC_EXTENSION_BLOCK( (__builtin_constant_p(str)) ? rb_tainted_str_new((str), (long)strlen(str)) : rb_tainted_str_new_cstr(str) )
#define rb_usascii_str_new_cstr(str) RB_GNUC_EXTENSION_BLOCK( (__builtin_constant_p(str)) ? rb_usascii_str_new_static((str), (long)strlen(str)) : rb_usascii_str_new_cstr(str) )
#define rb_utf8_str_new_cstr(str) RB_GNUC_EXTENSION_BLOCK( (__builtin_constant_p(str)) ? rb_utf8_str_new_static((str), (long)strlen(str)) : rb_utf8_str_new_cstr(str) )
#define rb_external_str_new_cstr(str) RB_GNUC_EXTENSION_BLOCK( (__builtin_constant_p(str)) ? rb_external_str_new((str), (long)strlen(str)) : rb_external_str_new_cstr(str) )
#define rb_locale_str_new_cstr(str) RB_GNUC_EXTENSION_BLOCK( (__builtin_constant_p(str)) ? rb_locale_str_new((str), (long)strlen(str)) : rb_locale_str_new_cstr(str) )
#define rb_str_buf_new_cstr(str) RB_GNUC_EXTENSION_BLOCK( (__builtin_constant_p(str)) ? rb_str_buf_cat(rb_str_buf_new((long)strlen(str)), (str), (long)strlen(str)) : rb_str_buf_new_cstr(str) )
#define rb_str_cat_cstr(str,ptr) RB_GNUC_EXTENSION_BLOCK( (__builtin_constant_p(ptr)) ? rb_str_cat((str), (ptr), (long)strlen(ptr)) : rb_str_cat_cstr((str), (ptr)) )
#define rb_exc_new_cstr(klass,ptr) RB_GNUC_EXTENSION_BLOCK( (__builtin_constant_p(ptr)) ? rb_exc_new((klass), (ptr), (long)strlen(ptr)) : rb_exc_new_cstr((klass), (ptr)) )
#define rb_str_new2 rb_str_new_cstr
#define rb_str_new3 rb_str_new_shared
#define rb_str_new4 rb_str_new_frozen
#define rb_str_new5 rb_str_new_with_class
#define rb_tainted_str_new2 rb_tainted_str_new_cstr
#define rb_str_buf_new2 rb_str_buf_new_cstr
#define rb_usascii_str_new2 rb_usascii_str_new_cstr
#define rb_str_buf_cat rb_str_cat
#define rb_str_buf_cat2 rb_str_cat_cstr
#define rb_str_cat2 rb_str_cat_cstr
#define rb_strlen_lit(str) (sizeof(str "") - 1)
#define rb_str_new_lit(str) rb_str_new_static((str), rb_strlen_lit(str))
#define rb_usascii_str_new_lit(str) rb_usascii_str_new_static((str), rb_strlen_lit(str))
#define rb_utf8_str_new_lit(str) rb_utf8_str_new_static((str), rb_strlen_lit(str))
#define rb_enc_str_new_lit(str,enc) rb_enc_str_new_static((str), rb_strlen_lit(str), (enc))
#define rb_str_new_literal(str) rb_str_new_lit(str)
#define rb_usascii_str_new_literal(str) rb_usascii_str_new_lit(str)
#define rb_utf8_str_new_literal(str) rb_utf8_str_new_lit(str)
#define rb_enc_str_new_literal(str,enc) rb_enc_str_new_lit(str, enc)
#define RUBY_UBF_IO ((rb_unblock_function_t *)-1)
#define RUBY_UBF_PROCESS ((rb_unblock_function_t *)-1)
#pragma GCC visibility pop
#define rb_f_notimplement_p(f) __builtin_types_compatible_p(__typeof__(f),__typeof__(rb_f_notimplement))
#define RB_METHOD_DEFINITION_DECL_C(def,nonnull,defname,decl,vars,funcargs) __attribute__((__unused__,__weakref__(#def),__nonnull__ nonnull))static void defname(RB_UNWRAP_MACRO decl,VALUE(*func)funcargs,int arity);
#define RB_UNWRAP_MACRO(...) __VA_ARGS__
#define RB_METHOD_DEFINITION_DECL_CXX_BEGIN(def) 
#define RB_METHOD_DEFINITION_DECL_CXX(def,defname,decl,vars,funcargs,arity) 
#define RB_METHOD_DEFINITION_DECL_1(def,nonnull,defname,arity,decl,vars,funcargs) RB_METHOD_DEFINITION_DECL_C(def,nonnull,defname,decl,vars,funcargs) RB_METHOD_DEFINITION_DECL_CXX(def,defname,decl,vars,funcargs,arity)
#define RB_METHOD_DEFINITION_DECL(def,nonnull,decl,vars) RB_METHOD_DEFINITION_DECL_CXX_BEGIN(def) RB_METHOD_DEFINITION_DECL_1(def,nonnull,def##0 ,0 ,decl,vars,(VALUE)) RB_METHOD_DEFINITION_DECL_1(def,nonnull,def##1 ,1 ,decl,vars,(VALUE,VALUE)) RB_METHOD_DEFINITION_DECL_1(def,nonnull,def##2 ,2 ,decl,vars,(VALUE,VALUE,VALUE)) RB_METHOD_DEFINITION_DECL_1(def,nonnull,def##3 ,3 ,decl,vars,(VALUE,VALUE,VALUE,VALUE)) RB_METHOD_DEFINITION_DECL_1(def,nonnull,def##4 ,4 ,decl,vars,(VALUE,VALUE,VALUE,VALUE,VALUE)) RB_METHOD_DEFINITION_DECL_1(def,nonnull,def##5 ,5 ,decl,vars,(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE)) RB_METHOD_DEFINITION_DECL_1(def,nonnull,def##6 ,6 ,decl,vars,(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE)) RB_METHOD_DEFINITION_DECL_1(def,nonnull,def##7 ,7 ,decl,vars,(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE)) RB_METHOD_DEFINITION_DECL_1(def,nonnull,def##8 ,8 ,decl,vars,(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE)) RB_METHOD_DEFINITION_DECL_1(def,nonnull,def##9 ,9 ,decl,vars,(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE)) RB_METHOD_DEFINITION_DECL_1(def,nonnull,def##10,10,decl,vars,(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE)) RB_METHOD_DEFINITION_DECL_1(def,nonnull,def##11,11,decl,vars,(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE)) RB_METHOD_DEFINITION_DECL_1(def,nonnull,def##12,12,decl,vars,(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE)) RB_METHOD_DEFINITION_DECL_1(def,nonnull,def##13,13,decl,vars,(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE)) RB_METHOD_DEFINITION_DECL_1(def,nonnull,def##14,14,decl,vars,(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE)) RB_METHOD_DEFINITION_DECL_1(def,nonnull,def##15,15,decl,vars,(VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE,VALUE)) RB_METHOD_DEFINITION_DECL_M3(def,nonnull,def##m3,decl,vars) RB_METHOD_DEFINITION_DECL_1(def,nonnull,def##m2,-2,decl,vars,(VALUE,VALUE)) RB_METHOD_DEFINITION_DECL_M1(def,nonnull,def##m1,decl,vars)
#define RB_METHOD_DEFINITION_DECL_M1(def,nonnull,defname,decl,vars) RB_METHOD_DEFINITION_DECL_C(def,nonnull,defname,decl,vars,(int,union{VALUE*x;const VALUE*y;}__attribute__((__transparent_union__)),VALUE))
#define RB_METHOD_DEFINITION_DECL_M3(def,nonnull,defname,decl,vars) RB_METHOD_DEFINITION_DECL_C(def,nonnull,defname,decl,vars,())
#define rb_define_method_id_choose_prototype15(n) rb_define_method_if_constexpr((n)==15,rb_define_method_id15,rb_define_method_idm3)
#define rb_define_method_id_choose_prototype14(n) rb_define_method_if_constexpr((n)==14,rb_define_method_id14,rb_define_method_id_choose_prototype15(n))
#define rb_define_method_id_choose_prototype13(n) rb_define_method_if_constexpr((n)==13,rb_define_method_id13,rb_define_method_id_choose_prototype14(n))
#define rb_define_method_id_choose_prototype12(n) rb_define_method_if_constexpr((n)==12,rb_define_method_id12,rb_define_method_id_choose_prototype13(n))
#define rb_define_method_id_choose_prototype11(n) rb_define_method_if_constexpr((n)==11,rb_define_method_id11,rb_define_method_id_choose_prototype12(n))
#define rb_define_method_id_choose_prototype10(n) rb_define_method_if_constexpr((n)==10,rb_define_method_id10,rb_define_method_id_choose_prototype11(n))
#define rb_define_method_id_choose_prototype9(n) rb_define_method_if_constexpr((n)== 9,rb_define_method_id9, rb_define_method_id_choose_prototype10(n))
#define rb_define_method_id_choose_prototype8(n) rb_define_method_if_constexpr((n)== 8,rb_define_method_id8, rb_define_method_id_choose_prototype9(n))
#define rb_define_method_id_choose_prototype7(n) rb_define_method_if_constexpr((n)== 7,rb_define_method_id7, rb_define_method_id_choose_prototype8(n))
#define rb_define_method_id_choose_prototype6(n) rb_define_method_if_constexpr((n)== 6,rb_define_method_id6, rb_define_method_id_choose_prototype7(n))
#define rb_define_method_id_choose_prototype5(n) rb_define_method_if_constexpr((n)== 5,rb_define_method_id5, rb_define_method_id_choose_prototype6(n))
#define rb_define_method_id_choose_prototype4(n) rb_define_method_if_constexpr((n)== 4,rb_define_method_id4, rb_define_method_id_choose_prototype5(n))
#define rb_define_method_id_choose_prototype3(n) rb_define_method_if_constexpr((n)== 3,rb_define_method_id3, rb_define_method_id_choose_prototype4(n))
#define rb_define_method_id_choose_prototype2(n) rb_define_method_if_constexpr((n)== 2,rb_define_method_id2, rb_define_method_id_choose_prototype3(n))
#define rb_define_method_id_choose_prototype1(n) rb_define_method_if_constexpr((n)== 1,rb_define_method_id1, rb_define_method_id_choose_prototype2(n))
#define rb_define_method_id_choose_prototype0(n) rb_define_method_if_constexpr((n)== 0,rb_define_method_id0, rb_define_method_id_choose_prototype1(n))
#define rb_define_method_id_choose_prototypem1(n) rb_define_method_if_constexpr((n)==-1,rb_define_method_idm1,rb_define_method_id_choose_prototype0(n))
#define rb_define_method_id_choose_prototypem2(n) rb_define_method_if_constexpr((n)==-2,rb_define_method_idm2,rb_define_method_id_choose_prototypem1(n))
#define rb_define_method_id_choose_prototypem3(n,f) rb_define_method_if_constexpr(rb_f_notimplement_p(f),rb_define_method_idm3,rb_define_method_id_choose_prototypem2(n))
#define rb_define_method_id(klass,mid,func,arity) rb_define_method_id_choose_prototypem3((arity),(func))((klass),(mid),(func),(arity));
#define rb_define_protected_method_choose_prototype15(n) rb_define_method_if_constexpr((n)==15,rb_define_protected_method15,rb_define_protected_methodm3)
#define rb_define_protected_method_choose_prototype14(n) rb_define_method_if_constexpr((n)==14,rb_define_protected_method14,rb_define_protected_method_choose_prototype15(n))
#define rb_define_protected_method_choose_prototype13(n) rb_define_method_if_constexpr((n)==13,rb_define_protected_method13,rb_define_protected_method_choose_prototype14(n))
#define rb_define_protected_method_choose_prototype12(n) rb_define_method_if_constexpr((n)==12,rb_define_protected_method12,rb_define_protected_method_choose_prototype13(n))
#define rb_define_protected_method_choose_prototype11(n) rb_define_method_if_constexpr((n)==11,rb_define_protected_method11,rb_define_protected_method_choose_prototype12(n))
#define rb_define_protected_method_choose_prototype10(n) rb_define_method_if_constexpr((n)==10,rb_define_protected_method10,rb_define_protected_method_choose_prototype11(n))
#define rb_define_protected_method_choose_prototype9(n) rb_define_method_if_constexpr((n)== 9,rb_define_protected_method9, rb_define_protected_method_choose_prototype10(n))
#define rb_define_protected_method_choose_prototype8(n) rb_define_method_if_constexpr((n)== 8,rb_define_protected_method8, rb_define_protected_method_choose_prototype9(n))
#define rb_define_protected_method_choose_prototype7(n) rb_define_method_if_constexpr((n)== 7,rb_define_protected_method7, rb_define_protected_method_choose_prototype8(n))
#define rb_define_protected_method_choose_prototype6(n) rb_define_method_if_constexpr((n)== 6,rb_define_protected_method6, rb_define_protected_method_choose_prototype7(n))
#define rb_define_protected_method_choose_prototype5(n) rb_define_method_if_constexpr((n)== 5,rb_define_protected_method5, rb_define_protected_method_choose_prototype6(n))
#define rb_define_protected_method_choose_prototype4(n) rb_define_method_if_constexpr((n)== 4,rb_define_protected_method4, rb_define_protected_method_choose_prototype5(n))
#define rb_define_protected_method_choose_prototype3(n) rb_define_method_if_constexpr((n)== 3,rb_define_protected_method3, rb_define_protected_method_choose_prototype4(n))
#define rb_define_protected_method_choose_prototype2(n) rb_define_method_if_constexpr((n)== 2,rb_define_protected_method2, rb_define_protected_method_choose_prototype3(n))
#define rb_define_protected_method_choose_prototype1(n) rb_define_method_if_constexpr((n)== 1,rb_define_protected_method1, rb_define_protected_method_choose_prototype2(n))
#define rb_define_protected_method_choose_prototype0(n) rb_define_method_if_constexpr((n)== 0,rb_define_protected_method0, rb_define_protected_method_choose_prototype1(n))
#define rb_define_protected_method_choose_prototypem1(n) rb_define_method_if_constexpr((n)==-1,rb_define_protected_methodm1,rb_define_protected_method_choose_prototype0(n))
#define rb_define_protected_method_choose_prototypem2(n) rb_define_method_if_constexpr((n)==-2,rb_define_protected_methodm2,rb_define_protected_method_choose_prototypem1(n))
#define rb_define_protected_method_choose_prototypem3(n,f) rb_define_method_if_constexpr(rb_f_notimplement_p(f),rb_define_protected_methodm3,rb_define_protected_method_choose_prototypem2(n))
#define rb_define_protected_method(klass,mid,func,arity) rb_define_protected_method_choose_prototypem3((arity),(func))((klass),(mid),(func),(arity));
#define rb_define_private_method_choose_prototype15(n) rb_define_method_if_constexpr((n)==15,rb_define_private_method15,rb_define_private_methodm3)
#define rb_define_private_method_choose_prototype14(n) rb_define_method_if_constexpr((n)==14,rb_define_private_method14,rb_define_private_method_choose_prototype15(n))
#define rb_define_private_method_choose_prototype13(n) rb_define_method_if_constexpr((n)==13,rb_define_private_method13,rb_define_private_method_choose_prototype14(n))
#define rb_define_private_method_choose_prototype12(n) rb_define_method_if_constexpr((n)==12,rb_define_private_method12,rb_define_private_method_choose_prototype13(n))
#define rb_define_private_method_choose_prototype11(n) rb_define_method_if_constexpr((n)==11,rb_define_private_method11,rb_define_private_method_choose_prototype12(n))
#define rb_define_private_method_choose_prototype10(n) rb_define_method_if_constexpr((n)==10,rb_define_private_method10,rb_define_private_method_choose_prototype11(n))
#define rb_define_private_method_choose_prototype9(n) rb_define_method_if_constexpr((n)== 9,rb_define_private_method9, rb_define_private_method_choose_prototype10(n))
#define rb_define_private_method_choose_prototype8(n) rb_define_method_if_constexpr((n)== 8,rb_define_private_method8, rb_define_private_method_choose_prototype9(n))
#define rb_define_private_method_choose_prototype7(n) rb_define_method_if_constexpr((n)== 7,rb_define_private_method7, rb_define_private_method_choose_prototype8(n))
#define rb_define_private_method_choose_prototype6(n) rb_define_method_if_constexpr((n)== 6,rb_define_private_method6, rb_define_private_method_choose_prototype7(n))
#define rb_define_private_method_choose_prototype5(n) rb_define_method_if_constexpr((n)== 5,rb_define_private_method5, rb_define_private_method_choose_prototype6(n))
#define rb_define_private_method_choose_prototype4(n) rb_define_method_if_constexpr((n)== 4,rb_define_private_method4, rb_define_private_method_choose_prototype5(n))
#define rb_define_private_method_choose_prototype3(n) rb_define_method_if_constexpr((n)== 3,rb_define_private_method3, rb_define_private_method_choose_prototype4(n))
#define rb_define_private_method_choose_prototype2(n) rb_define_method_if_constexpr((n)== 2,rb_define_private_method2, rb_define_private_method_choose_prototype3(n))
#define rb_define_private_method_choose_prototype1(n) rb_define_method_if_constexpr((n)== 1,rb_define_private_method1, rb_define_private_method_choose_prototype2(n))
#define rb_define_private_method_choose_prototype0(n) rb_define_method_if_constexpr((n)== 0,rb_define_private_method0, rb_define_private_method_choose_prototype1(n))
#define rb_define_private_method_choose_prototypem1(n) rb_define_method_if_constexpr((n)==-1,rb_define_private_methodm1,rb_define_private_method_choose_prototype0(n))
#define rb_define_private_method_choose_prototypem2(n) rb_define_method_if_constexpr((n)==-2,rb_define_private_methodm2,rb_define_private_method_choose_prototypem1(n))
#define rb_define_private_method_choose_prototypem3(n,f) rb_define_method_if_constexpr(rb_f_notimplement_p(f),rb_define_private_methodm3,rb_define_private_method_choose_prototypem2(n))
#define rb_define_private_method(klass,mid,func,arity) rb_define_private_method_choose_prototypem3((arity),(func))((klass),(mid),(func),(arity));
#define rb_define_singleton_method_choose_prototype15(n) rb_define_method_if_constexpr((n)==15,rb_define_singleton_method15,rb_define_singleton_methodm3)
#define rb_define_singleton_method_choose_prototype14(n) rb_define_method_if_constexpr((n)==14,rb_define_singleton_method14,rb_define_singleton_method_choose_prototype15(n))
#define rb_define_singleton_method_choose_prototype13(n) rb_define_method_if_constexpr((n)==13,rb_define_singleton_method13,rb_define_singleton_method_choose_prototype14(n))
#define rb_define_singleton_method_choose_prototype12(n) rb_define_method_if_constexpr((n)==12,rb_define_singleton_method12,rb_define_singleton_method_choose_prototype13(n))
#define rb_define_singleton_method_choose_prototype11(n) rb_define_method_if_constexpr((n)==11,rb_define_singleton_method11,rb_define_singleton_method_choose_prototype12(n))
#define rb_define_singleton_method_choose_prototype10(n) rb_define_method_if_constexpr((n)==10,rb_define_singleton_method10,rb_define_singleton_method_choose_prototype11(n))
#define rb_define_singleton_method_choose_prototype9(n) rb_define_method_if_constexpr((n)== 9,rb_define_singleton_method9, rb_define_singleton_method_choose_prototype10(n))
#define rb_define_singleton_method_choose_prototype8(n) rb_define_method_if_constexpr((n)== 8,rb_define_singleton_method8, rb_define_singleton_method_choose_prototype9(n))
#define rb_define_singleton_method_choose_prototype7(n) rb_define_method_if_constexpr((n)== 7,rb_define_singleton_method7, rb_define_singleton_method_choose_prototype8(n))
#define rb_define_singleton_method_choose_prototype6(n) rb_define_method_if_constexpr((n)== 6,rb_define_singleton_method6, rb_define_singleton_method_choose_prototype7(n))
#define rb_define_singleton_method_choose_prototype5(n) rb_define_method_if_constexpr((n)== 5,rb_define_singleton_method5, rb_define_singleton_method_choose_prototype6(n))
#define rb_define_singleton_method_choose_prototype4(n) rb_define_method_if_constexpr((n)== 4,rb_define_singleton_method4, rb_define_singleton_method_choose_prototype5(n))
#define rb_define_singleton_method_choose_prototype3(n) rb_define_method_if_constexpr((n)== 3,rb_define_singleton_method3, rb_define_singleton_method_choose_prototype4(n))
#define rb_define_singleton_method_choose_prototype2(n) rb_define_method_if_constexpr((n)== 2,rb_define_singleton_method2, rb_define_singleton_method_choose_prototype3(n))
#define rb_define_singleton_method_choose_prototype1(n) rb_define_method_if_constexpr((n)== 1,rb_define_singleton_method1, rb_define_singleton_method_choose_prototype2(n))
#define rb_define_singleton_method_choose_prototype0(n) rb_define_method_if_constexpr((n)== 0,rb_define_singleton_method0, rb_define_singleton_method_choose_prototype1(n))
#define rb_define_singleton_method_choose_prototypem1(n) rb_define_method_if_constexpr((n)==-1,rb_define_singleton_methodm1,rb_define_singleton_method_choose_prototype0(n))
#define rb_define_singleton_method_choose_prototypem2(n) rb_define_method_if_constexpr((n)==-2,rb_define_singleton_methodm2,rb_define_singleton_method_choose_prototypem1(n))
#define rb_define_singleton_method_choose_prototypem3(n,f) rb_define_method_if_constexpr(rb_f_notimplement_p(f),rb_define_singleton_methodm3,rb_define_singleton_method_choose_prototypem2(n))
#define rb_define_singleton_method(klass,mid,func,arity) rb_define_singleton_method_choose_prototypem3((arity),(func))((klass),(mid),(func),(arity));
#define FIX_CONST_VALUE_PTR(x) (x)
#define RUBY_VM 1
#define HAVE_NATIVETHREAD 
#define RUBY_EVENT_NONE 0x0000
#define RUBY_EVENT_LINE 0x0001
#define RUBY_EVENT_CLASS 0x0002
#define RUBY_EVENT_END 0x0004
#define RUBY_EVENT_CALL 0x0008
#define RUBY_EVENT_RETURN 0x0010
#define RUBY_EVENT_C_CALL 0x0020
#define RUBY_EVENT_C_RETURN 0x0040
#define RUBY_EVENT_RAISE 0x0080
#define RUBY_EVENT_ALL 0x00ff
#define RUBY_EVENT_B_CALL 0x0100
#define RUBY_EVENT_B_RETURN 0x0200
#define RUBY_EVENT_THREAD_BEGIN 0x0400
#define RUBY_EVENT_THREAD_END 0x0800
#define RUBY_EVENT_FIBER_SWITCH 0x1000
#define RUBY_EVENT_SCRIPT_COMPILED 0x2000
#define RUBY_EVENT_TRACEPOINT_ALL 0xffff
#define RUBY_EVENT_RESERVED_FOR_INTERNAL_USE 0x030000
#define RUBY_INTERNAL_EVENT_SWITCH 0x040000
#define RUBY_EVENT_SWITCH 0x040000
#define RUBY_INTERNAL_EVENT_NEWOBJ 0x100000
#define RUBY_INTERNAL_EVENT_FREEOBJ 0x200000
#define RUBY_INTERNAL_EVENT_GC_START 0x400000
#define RUBY_INTERNAL_EVENT_GC_END_MARK 0x800000
#define RUBY_INTERNAL_EVENT_GC_END_SWEEP 0x1000000
#define RUBY_INTERNAL_EVENT_GC_ENTER 0x2000000
#define RUBY_INTERNAL_EVENT_GC_EXIT 0x4000000
#define RUBY_INTERNAL_EVENT_OBJSPACE_MASK 0x7f00000
#define RUBY_INTERNAL_EVENT_MASK 0xffff0000
#define RB_EVENT_HOOKS_HAVE_CALLBACK_DATA 1
#define ISASCII(c) rb_isascii(c)
#define ISPRINT(c) rb_isprint(c)
#define ISGRAPH(c) rb_isgraph(c)
#define ISSPACE(c) rb_isspace(c)
#define ISUPPER(c) rb_isupper(c)
#define ISLOWER(c) rb_islower(c)
#define ISALNUM(c) rb_isalnum(c)
#define ISALPHA(c) rb_isalpha(c)
#define ISDIGIT(c) rb_isdigit(c)
#define ISXDIGIT(c) rb_isxdigit(c)
#define ISBLANK(c) rb_isblank(c)
#define ISCNTRL(c) rb_iscntrl(c)
#define ISPUNCT(c) rb_ispunct(c)
#define TOUPPER(c) rb_toupper(c)
#define TOLOWER(c) rb_tolower(c)
#define STRCASECMP(s1,s2) (st_locale_insensitive_strcasecmp((s1), (s2)))
#define STRNCASECMP(s1,s2,n) (st_locale_insensitive_strncasecmp((s1), (s2), (n)))
#define STRTOUL(str,endptr,base) (ruby_strtoul((str), (endptr), (base)))
#define InitVM(ext) {void InitVM_##ext(void);InitVM_##ext();}
#define rb_scan_args(argc,argvp,fmt,...) __builtin_choose_expr(__builtin_constant_p(fmt), rb_scan_args0(argc,argvp,fmt, (sizeof((VALUE*[]){__VA_ARGS__})/sizeof(VALUE*)), ((VALUE*[]){__VA_ARGS__})), rb_scan_args(argc,argvp,fmt,##__VA_ARGS__))
#define rb_scan_args_bad_format(fmt) ((void)0)
#define rb_scan_args_length_mismatch(fmt,varc) ((void)0)
#define rb_scan_args_isdigit(c) ((unsigned char)((c)-'0')<10)
#define rb_scan_args_count_end(fmt,ofs,vari) (fmt[ofs] ? -1 : (vari))
#define rb_scan_args_count_block(fmt,ofs,vari) (fmt[ofs]!='&' ? rb_scan_args_count_end(fmt, ofs, vari) : rb_scan_args_count_end(fmt, ofs+1, vari+1))
#define rb_scan_args_count_hash(fmt,ofs,vari) (fmt[ofs]!=':' ? rb_scan_args_count_block(fmt, ofs, vari) : rb_scan_args_count_block(fmt, ofs+1, vari+1))
#define rb_scan_args_count_trail(fmt,ofs,vari) (!rb_scan_args_isdigit(fmt[ofs]) ? rb_scan_args_count_hash(fmt, ofs, vari) : rb_scan_args_count_hash(fmt, ofs+1, vari+(fmt[ofs]-'0')))
#define rb_scan_args_count_var(fmt,ofs,vari) (fmt[ofs]!='*' ? rb_scan_args_count_trail(fmt, ofs, vari) : rb_scan_args_count_trail(fmt, ofs+1, vari+1))
#define rb_scan_args_count_opt(fmt,ofs,vari) (!rb_scan_args_isdigit(fmt[ofs]) ? rb_scan_args_count_var(fmt, ofs, vari) : rb_scan_args_count_var(fmt, ofs+1, vari+fmt[ofs]-'0'))
#define rb_scan_args_count_lead(fmt,ofs,vari) (!rb_scan_args_isdigit(fmt[ofs]) ? rb_scan_args_count_var(fmt, ofs, vari) : rb_scan_args_count_opt(fmt, ofs+1, vari+fmt[ofs]-'0'))
#define rb_scan_args_count(fmt) rb_scan_args_count_lead(fmt, 0, 0)
#define rb_scan_args_verify(fmt,varc) (void)0
#define rb_scan_args0(argc,argv,fmt,varc,vars) rb_scan_args_set(argc, argv, rb_scan_args_n_lead(fmt), rb_scan_args_n_opt(fmt), rb_scan_args_n_trail(fmt), rb_scan_args_f_var(fmt), rb_scan_args_f_hash(fmt), rb_scan_args_f_block(fmt), (rb_scan_args_verify(fmt, varc), vars), (char *)fmt, varc)
#define rb_yield_values(argc,...) __extension__({ const int rb_yield_values_argc = (argc); const VALUE rb_yield_values_args[] = {__VA_ARGS__}; const int rb_yield_values_nargs = (int)(sizeof(rb_yield_values_args) / sizeof(VALUE)); rb_yield_values2( rb_varargs_argc_check(rb_yield_values_argc, rb_yield_values_nargs), rb_yield_values_nargs ? rb_yield_values_args : NULL); })
#define rb_funcall(recv,mid,argc,...) __extension__({ const int rb_funcall_argc = (argc); const VALUE rb_funcall_args[] = {__VA_ARGS__}; const int rb_funcall_nargs = (int)(sizeof(rb_funcall_args) / sizeof(VALUE)); rb_funcallv(recv, mid, rb_varargs_argc_check(rb_funcall_argc, rb_funcall_nargs), rb_funcall_nargs ? rb_funcall_args : NULL); })
#define RUBY_SUBST_H 1
#undef snprintf
#undef vsnprintf
#define snprintf ruby_snprintf
#define vsnprintf ruby_vsnprintf
#define RUBY_INIT_STACK VALUE variable_in_this_stack_frame; ruby_init_stack(&variable_in_this_stack_frame);
#pragma GCC visibility pop
#define rb_define_method_if_constexpr(x,t,f) __builtin_choose_expr(__builtin_choose_expr(__builtin_constant_p(x),(x),0),(t),(f))
#define rb_define_method_choose_prototype15(n) rb_define_method_if_constexpr((n)==15,rb_define_method15,rb_define_methodm3)
#define rb_define_method_choose_prototype14(n) rb_define_method_if_constexpr((n)==14,rb_define_method14,rb_define_method_choose_prototype15(n))
#define rb_define_method_choose_prototype13(n) rb_define_method_if_constexpr((n)==13,rb_define_method13,rb_define_method_choose_prototype14(n))
#define rb_define_method_choose_prototype12(n) rb_define_method_if_constexpr((n)==12,rb_define_method12,rb_define_method_choose_prototype13(n))
#define rb_define_method_choose_prototype11(n) rb_define_method_if_constexpr((n)==11,rb_define_method11,rb_define_method_choose_prototype12(n))
#define rb_define_method_choose_prototype10(n) rb_define_method_if_constexpr((n)==10,rb_define_method10,rb_define_method_choose_prototype11(n))
#define rb_define_method_choose_prototype9(n) rb_define_method_if_constexpr((n)== 9,rb_define_method9, rb_define_method_choose_prototype10(n))
#define rb_define_method_choose_prototype8(n) rb_define_method_if_constexpr((n)== 8,rb_define_method8, rb_define_method_choose_prototype9(n))
#define rb_define_method_choose_prototype7(n) rb_define_method_if_constexpr((n)== 7,rb_define_method7, rb_define_method_choose_prototype8(n))
#define rb_define_method_choose_prototype6(n) rb_define_method_if_constexpr((n)== 6,rb_define_method6, rb_define_method_choose_prototype7(n))
#define rb_define_method_choose_prototype5(n) rb_define_method_if_constexpr((n)== 5,rb_define_method5, rb_define_method_choose_prototype6(n))
#define rb_define_method_choose_prototype4(n) rb_define_method_if_constexpr((n)== 4,rb_define_method4, rb_define_method_choose_prototype5(n))
#define rb_define_method_choose_prototype3(n) rb_define_method_if_constexpr((n)== 3,rb_define_method3, rb_define_method_choose_prototype4(n))
#define rb_define_method_choose_prototype2(n) rb_define_method_if_constexpr((n)== 2,rb_define_method2, rb_define_method_choose_prototype3(n))
#define rb_define_method_choose_prototype1(n) rb_define_method_if_constexpr((n)== 1,rb_define_method1, rb_define_method_choose_prototype2(n))
#define rb_define_method_choose_prototype0(n) rb_define_method_if_constexpr((n)== 0,rb_define_method0, rb_define_method_choose_prototype1(n))
#define rb_define_method_choose_prototypem1(n) rb_define_method_if_constexpr((n)==-1,rb_define_methodm1,rb_define_method_choose_prototype0(n))
#define rb_define_method_choose_prototypem2(n) rb_define_method_if_constexpr((n)==-2,rb_define_methodm2,rb_define_method_choose_prototypem1(n))
#define rb_define_method_choose_prototypem3(n,f) rb_define_method_if_constexpr(rb_f_notimplement_p(f),rb_define_methodm3,rb_define_method_choose_prototypem2(n))
#define rb_define_method(klass,mid,func,arity) rb_define_method_choose_prototypem3((arity),(func))((klass),(mid),(func),(arity));
#define rb_define_module_function_choose_prototype15(n) rb_define_method_if_constexpr((n)==15,rb_define_module_function15,rb_define_module_functionm3)
#define rb_define_module_function_choose_prototype14(n) rb_define_method_if_constexpr((n)==14,rb_define_module_function14,rb_define_module_function_choose_prototype15(n))
#define rb_define_module_function_choose_prototype13(n) rb_define_method_if_constexpr((n)==13,rb_define_module_function13,rb_define_module_function_choose_prototype14(n))
#define rb_define_module_function_choose_prototype12(n) rb_define_method_if_constexpr((n)==12,rb_define_module_function12,rb_define_module_function_choose_prototype13(n))
#define rb_define_module_function_choose_prototype11(n) rb_define_method_if_constexpr((n)==11,rb_define_module_function11,rb_define_module_function_choose_prototype12(n))
#define rb_define_module_function_choose_prototype10(n) rb_define_method_if_constexpr((n)==10,rb_define_module_function10,rb_define_module_function_choose_prototype11(n))
#define rb_define_module_function_choose_prototype9(n) rb_define_method_if_constexpr((n)== 9,rb_define_module_function9, rb_define_module_function_choose_prototype10(n))
#define rb_define_module_function_choose_prototype8(n) rb_define_method_if_constexpr((n)== 8,rb_define_module_function8, rb_define_module_function_choose_prototype9(n))
#define rb_define_module_function_choose_prototype7(n) rb_define_method_if_constexpr((n)== 7,rb_define_module_function7, rb_define_module_function_choose_prototype8(n))
#define rb_define_module_function_choose_prototype6(n) rb_define_method_if_constexpr((n)== 6,rb_define_module_function6, rb_define_module_function_choose_prototype7(n))
#define rb_define_module_function_choose_prototype5(n) rb_define_method_if_constexpr((n)== 5,rb_define_module_function5, rb_define_module_function_choose_prototype6(n))
#define rb_define_module_function_choose_prototype4(n) rb_define_method_if_constexpr((n)== 4,rb_define_module_function4, rb_define_module_function_choose_prototype5(n))
#define rb_define_module_function_choose_prototype3(n) rb_define_method_if_constexpr((n)== 3,rb_define_module_function3, rb_define_module_function_choose_prototype4(n))
#define rb_define_module_function_choose_prototype2(n) rb_define_method_if_constexpr((n)== 2,rb_define_module_function2, rb_define_module_function_choose_prototype3(n))
#define rb_define_module_function_choose_prototype1(n) rb_define_method_if_constexpr((n)== 1,rb_define_module_function1, rb_define_module_function_choose_prototype2(n))
#define rb_define_module_function_choose_prototype0(n) rb_define_method_if_constexpr((n)== 0,rb_define_module_function0, rb_define_module_function_choose_prototype1(n))
#define rb_define_module_function_choose_prototypem1(n) rb_define_method_if_constexpr((n)==-1,rb_define_module_functionm1,rb_define_module_function_choose_prototype0(n))
#define rb_define_module_function_choose_prototypem2(n) rb_define_method_if_constexpr((n)==-2,rb_define_module_functionm2,rb_define_module_function_choose_prototypem1(n))
#define rb_define_module_function_choose_prototypem3(n,f) rb_define_method_if_constexpr(rb_f_notimplement_p(f),rb_define_module_functionm3,rb_define_module_function_choose_prototypem2(n))
#define rb_define_module_function(klass,mid,func,arity) rb_define_module_function_choose_prototypem3((arity),(func))((klass),(mid),(func),(arity));
#define rb_define_global_function_choose_prototype15(n) rb_define_method_if_constexpr((n)==15,rb_define_global_function15,rb_define_global_functionm3)
#define rb_define_global_function_choose_prototype14(n) rb_define_method_if_constexpr((n)==14,rb_define_global_function14,rb_define_global_function_choose_prototype15(n))
#define rb_define_global_function_choose_prototype13(n) rb_define_method_if_constexpr((n)==13,rb_define_global_function13,rb_define_global_function_choose_prototype14(n))
#define rb_define_global_function_choose_prototype12(n) rb_define_method_if_constexpr((n)==12,rb_define_global_function12,rb_define_global_function_choose_prototype13(n))
#define rb_define_global_function_choose_prototype11(n) rb_define_method_if_constexpr((n)==11,rb_define_global_function11,rb_define_global_function_choose_prototype12(n))
#define rb_define_global_function_choose_prototype10(n) rb_define_method_if_constexpr((n)==10,rb_define_global_function10,rb_define_global_function_choose_prototype11(n))
#define rb_define_global_function_choose_prototype9(n) rb_define_method_if_constexpr((n)== 9,rb_define_global_function9, rb_define_global_function_choose_prototype10(n))
#define rb_define_global_function_choose_prototype8(n) rb_define_method_if_constexpr((n)== 8,rb_define_global_function8, rb_define_global_function_choose_prototype9(n))
#define rb_define_global_function_choose_prototype7(n) rb_define_method_if_constexpr((n)== 7,rb_define_global_function7, rb_define_global_function_choose_prototype8(n))
#define rb_define_global_function_choose_prototype6(n) rb_define_method_if_constexpr((n)== 6,rb_define_global_function6, rb_define_global_function_choose_prototype7(n))
#define rb_define_global_function_choose_prototype5(n) rb_define_method_if_constexpr((n)== 5,rb_define_global_function5, rb_define_global_function_choose_prototype6(n))
#define rb_define_global_function_choose_prototype4(n) rb_define_method_if_constexpr((n)== 4,rb_define_global_function4, rb_define_global_function_choose_prototype5(n))
#define rb_define_global_function_choose_prototype3(n) rb_define_method_if_constexpr((n)== 3,rb_define_global_function3, rb_define_global_function_choose_prototype4(n))
#define rb_define_global_function_choose_prototype2(n) rb_define_method_if_constexpr((n)== 2,rb_define_global_function2, rb_define_global_function_choose_prototype3(n))
#define rb_define_global_function_choose_prototype1(n) rb_define_method_if_constexpr((n)== 1,rb_define_global_function1, rb_define_global_function_choose_prototype2(n))
#define rb_define_global_function_choose_prototype0(n) rb_define_method_if_constexpr((n)== 0,rb_define_global_function0, rb_define_global_function_choose_prototype1(n))
#define rb_define_global_function_choose_prototypem1(n) rb_define_method_if_constexpr((n)==-1,rb_define_global_functionm1,rb_define_global_function_choose_prototype0(n))
#define rb_define_global_function_choose_prototypem2(n) rb_define_method_if_constexpr((n)==-2,rb_define_global_functionm2,rb_define_global_function_choose_prototypem1(n))
#define rb_define_global_function_choose_prototypem3(n,f) rb_define_method_if_constexpr(rb_f_notimplement_p(f),rb_define_global_functionm3,rb_define_global_function_choose_prototypem2(n))
#define rb_define_global_function(mid,func,arity) rb_define_global_function_choose_prototypem3((arity),(func))((mid),(func),(arity));
#define RUBY_METHOD_FUNC(func) ((VALUE (*)(ANYARGS))(func))
#define __STDBOOL_H 
#define bool _Bool
#define true 1
#define false 0
#define __bool_true_false_are_defined 1
#define HALF_LONG_MSB ((SIGNED_VALUE)1<<((SIZEOF_LONG*CHAR_BIT-1)/2))
#define LIKELY(x) RB_LIKELY(x)
#define UNLIKELY(x) RB_UNLIKELY(x)
#define ATTRIBUTE_NO_ADDRESS_SAFETY_ANALYSIS(x) NO_SANITIZE("address", NOINLINE(x))
#define VALGRIND_MAKE_MEM_DEFINED(p,n) 0
#define VALGRIND_MAKE_MEM_UNDEFINED(p,n) 0
#define numberof(array) ((int)(sizeof(array) / sizeof((array)[0])))
#define ACCESS_ONCE(type,x) (*((volatile type *)&(x)))
#define STATIC_ASSERT(name,expr) RB_GNUC_EXTENSION _Static_assert(expr, #name ": " #expr)
#define SIGNED_INTEGER_TYPE_P(int_type) (0 > ((int_type)0)-1)
#define SIGNED_INTEGER_MAX(sint_type) (sint_type) ((((sint_type)1) << (sizeof(sint_type) * CHAR_BIT - 2)) | ((((sint_type)1) << (sizeof(sint_type) * CHAR_BIT - 2)) - 1))
#define SIGNED_INTEGER_MIN(sint_type) (-SIGNED_INTEGER_MAX(sint_type)-1)
#define UNSIGNED_INTEGER_MAX(uint_type) (~(uint_type)0)
#define TIMET_MAX SIGNED_INTEGER_MAX(time_t)
#define TIMET_MIN SIGNED_INTEGER_MIN(time_t)
#define TIMET_MAX_PLUS_ONE (2*(double)(TIMET_MAX/2+1))
#define MUL_OVERFLOW_P(a,b) ({__typeof__(a) c; __builtin_mul_overflow((a), (b), &c);})
#define MUL_OVERFLOW_SIGNED_INTEGER_P(a,b,min,max) ( (a) == 0 ? 0 : (a) == -1 ? (b) < -(max) : (a) > 0 ? ((b) > 0 ? (max) / (a) < (b) : (min) / (a) > (b)) : ((b) > 0 ? (min) / (a) < (b) : (max) / (a) > (b)))
#define MUL_OVERFLOW_FIXNUM_P(a,b) MUL_OVERFLOW_SIGNED_INTEGER_P(a, b, FIXNUM_MIN, FIXNUM_MAX)
#define MUL_OVERFLOW_LONG_LONG_P(a,b) MUL_OVERFLOW_P(a, b)
#define MUL_OVERFLOW_LONG_P(a,b) MUL_OVERFLOW_P(a, b)
#define MUL_OVERFLOW_INT_P(a,b) MUL_OVERFLOW_P(a, b)
#define swap16(x) __builtin_bswap16(x)
#define swap32(x) __builtin_bswap32(x)
#define swap64(x) __builtin_bswap64(x)
#define DLONG int128_t
#define DL2NUM(x) (RB_FIXABLE(x) ? LONG2FIX(x) : rb_int128t2big(x))
#define bit_length(x) (unsigned int) (sizeof(x) <= SIZEOF_INT ? SIZEOF_INT * CHAR_BIT - nlz_int((unsigned int)(x)) : sizeof(x) <= SIZEOF_LONG ? SIZEOF_LONG * CHAR_BIT - nlz_long((unsigned long)(x)) : sizeof(x) <= SIZEOF_LONG_LONG ? SIZEOF_LONG_LONG * CHAR_BIT - nlz_long_long((unsigned LONG_LONG)(x)) : SIZEOF_INT128_T * CHAR_BIT - nlz_int128((uint128_t)(x)))
#define BDIGIT unsigned int
#define SIZEOF_BDIGIT SIZEOF_INT
#define BDIGIT_DBL unsigned LONG_LONG
#define BDIGIT_DBL_SIGNED LONG_LONG
#define PRI_BDIGIT_PREFIX ""
#define PRI_BDIGIT_DBL_PREFIX PRI_LL_PREFIX
#define SIZEOF_ACTUAL_BDIGIT SIZEOF_BDIGIT
#define PRIdBDIGIT PRI_BDIGIT_PREFIX"d"
#define PRIiBDIGIT PRI_BDIGIT_PREFIX"i"
#define PRIoBDIGIT PRI_BDIGIT_PREFIX"o"
#define PRIuBDIGIT PRI_BDIGIT_PREFIX"u"
#define PRIxBDIGIT PRI_BDIGIT_PREFIX"x"
#define PRIXBDIGIT PRI_BDIGIT_PREFIX"X"
#define PRIdBDIGIT_DBL PRI_BDIGIT_DBL_PREFIX"d"
#define PRIiBDIGIT_DBL PRI_BDIGIT_DBL_PREFIX"i"
#define PRIoBDIGIT_DBL PRI_BDIGIT_DBL_PREFIX"o"
#define PRIuBDIGIT_DBL PRI_BDIGIT_DBL_PREFIX"u"
#define PRIxBDIGIT_DBL PRI_BDIGIT_DBL_PREFIX"x"
#define PRIXBDIGIT_DBL PRI_BDIGIT_DBL_PREFIX"X"
#define BIGNUM_EMBED_LEN_NUMBITS 3
#define BIGNUM_EMBED_LEN_MAX (SIZEOF_VALUE*RVALUE_EMBED_LEN_MAX/SIZEOF_ACTUAL_BDIGIT)
#define BIGNUM_SIGN_BIT ((VALUE)FL_USER1)
#define BIGNUM_SIGN(b) ((RBASIC(b)->flags & BIGNUM_SIGN_BIT) != 0)
#define BIGNUM_SET_SIGN(b,sign) ((sign) ? (RBASIC(b)->flags |= BIGNUM_SIGN_BIT) : (RBASIC(b)->flags &= ~BIGNUM_SIGN_BIT))
#define BIGNUM_POSITIVE_P(b) BIGNUM_SIGN(b)
#define BIGNUM_NEGATIVE_P(b) (!BIGNUM_SIGN(b))
#define BIGNUM_NEGATE(b) (RBASIC(b)->flags ^= BIGNUM_SIGN_BIT)
#define BIGNUM_EMBED_FLAG ((VALUE)FL_USER2)
#define BIGNUM_EMBED_LEN_MASK (~(~(VALUE)0U << BIGNUM_EMBED_LEN_NUMBITS) << BIGNUM_EMBED_LEN_SHIFT)
#define BIGNUM_EMBED_LEN_SHIFT (FL_USHIFT+3)
#define BIGNUM_LEN(b) ((RBASIC(b)->flags & BIGNUM_EMBED_FLAG) ? (size_t)((RBASIC(b)->flags >> BIGNUM_EMBED_LEN_SHIFT) & (BIGNUM_EMBED_LEN_MASK >> BIGNUM_EMBED_LEN_SHIFT)) : RBIGNUM(b)->as.heap.len)
#define BIGNUM_DIGITS(b) ((RBASIC(b)->flags & BIGNUM_EMBED_FLAG) ? RBIGNUM(b)->as.ary : RBIGNUM(b)->as.heap.digits)
#define BIGNUM_LENINT(b) rb_long2int(BIGNUM_LEN(b))
#define RBIGNUM(obj) (R_CAST(RBignum)(obj))
#define RRATIONAL(obj) (R_CAST(RRational)(obj))
#define RRATIONAL_SET_NUM(rat,n) RB_OBJ_WRITE((rat), &((struct RRational *)(rat))->num,(n))
#define RRATIONAL_SET_DEN(rat,d) RB_OBJ_WRITE((rat), &((struct RRational *)(rat))->den,(d))
#define RFLOAT(obj) (R_CAST(RFloat)(obj))
#define RCOMPLEX(obj) (R_CAST(RComplex)(obj))
#define RCOMPLEX_SET_REAL(cmp,r) RB_OBJ_WRITE((cmp), &((struct RComplex *)(cmp))->real,(r))
#define RCOMPLEX_SET_IMAG(cmp,i) RB_OBJ_WRITE((cmp), &((struct RComplex *)(cmp))->imag,(i))
#define RHASH_AR_TABLE_MAX_SIZE SIZEOF_VALUE
#define RHASH_LEV_MASK (FL_USER13 | FL_USER14 | FL_USER15 | FL_USER16 | FL_USER17 | FL_USER18 | FL_USER19)
#define RHASH_AR_TABLE_SIZE_RAW(h) ((unsigned int)((RBASIC(h)->flags & RHASH_AR_TABLE_SIZE_MASK) >> RHASH_AR_TABLE_SIZE_SHIFT))
#define RHASH_AR_TABLE_P(hash) (!FL_TEST_RAW((hash), RHASH_ST_TABLE_FLAG))
#define RHASH_AR_TABLE(hash) (RHASH(hash)->as.ar)
#define RHASH_ST_TABLE(hash) (RHASH(hash)->as.st)
#define RHASH(obj) (R_CAST(RHash)(obj))
#define RHASH_ST_SIZE(h) (RHASH_ST_TABLE(h)->num_entries)
#define RHASH_ST_TABLE_P(h) (!RHASH_AR_TABLE_P(h))
#define RHASH_ST_CLEAR(h) (FL_UNSET_RAW(h, RHASH_ST_TABLE_FLAG), RHASH(h)->as.ar = NULL)
#define RHASH_AR_TABLE_SIZE_MASK (VALUE)RHASH_AR_TABLE_SIZE_MASK
#define RHASH_AR_TABLE_SIZE_SHIFT RHASH_AR_TABLE_SIZE_SHIFT
#define RHASH_AR_TABLE_BOUND_MASK (VALUE)RHASH_AR_TABLE_BOUND_MASK
#define RHASH_AR_TABLE_BOUND_SHIFT RHASH_AR_TABLE_BOUND_SHIFT
#define RHASH_TRANSIENT_P(hash) FL_TEST_RAW((hash), RHASH_TRANSIENT_FLAG)
#define RHASH_SET_TRANSIENT_FLAG(h) FL_SET_RAW(h, RHASH_TRANSIENT_FLAG)
#define RHASH_UNSET_TRANSIENT_FLAG(h) FL_UNSET_RAW(h, RHASH_TRANSIENT_FLAG)
#undef RHASH_IFNONE
#undef RHASH_SIZE
#define RHASH_IFNONE(h) (RHASH(h)->ifnone)
#define RHASH_SIZE(h) (RHASH_AR_TABLE_P(h) ? RHASH_AR_TABLE_SIZE_RAW(h) : RHASH_ST_SIZE(h))
#define RSTRUCT_EMBED_LEN_MAX RSTRUCT_EMBED_LEN_MAX
#define RSTRUCT_EMBED_LEN_MASK RSTRUCT_EMBED_LEN_MASK
#define RSTRUCT_EMBED_LEN_SHIFT RSTRUCT_EMBED_LEN_SHIFT
#define RSTRUCT_TRANSIENT_P(st) FL_TEST_RAW((obj), RSTRUCT_TRANSIENT_FLAG)
#define RSTRUCT_TRANSIENT_SET(st) FL_SET_RAW((st), RSTRUCT_TRANSIENT_FLAG)
#define RSTRUCT_TRANSIENT_UNSET(st) FL_UNSET_RAW((st), RSTRUCT_TRANSIENT_FLAG)
#undef RSTRUCT_LEN
#undef RSTRUCT_PTR
#undef RSTRUCT_SET
#undef RSTRUCT_GET
#define RSTRUCT_EMBED_LEN(st) (long)((RBASIC(st)->flags >> RSTRUCT_EMBED_LEN_SHIFT) & (RSTRUCT_EMBED_LEN_MASK >> RSTRUCT_EMBED_LEN_SHIFT))
#define RSTRUCT_LEN(st) rb_struct_len(st)
#define RSTRUCT_LENINT(st) rb_long2int(RSTRUCT_LEN(st))
#define RSTRUCT_CONST_PTR(st) rb_struct_const_ptr(st)
#define RSTRUCT_PTR(st) ((VALUE *)RSTRUCT_CONST_PTR(RB_OBJ_WB_UNPROTECT_FOR(STRUCT, st)))
#define RSTRUCT_SET(st,idx,v) RB_OBJ_WRITE(st, &RSTRUCT_CONST_PTR(st)[idx], (v))
#define RSTRUCT_GET(st,idx) (RSTRUCT_CONST_PTR(st)[idx])
#define RSTRUCT(obj) (R_CAST(RStruct)(obj))
#define SERIALT2NUM ULL2NUM
#define PRI_SERIALT_PREFIX PRI_LL_PREFIX
#define SIZEOF_SERIAL_T SIZEOF_LONG_LONG
#undef RClass
#define RCLASS_EXT(c) (RCLASS(c)->ptr)
#define RCLASS_IV_TBL(c) (RCLASS_EXT(c)->iv_tbl)
#define RCLASS_CONST_TBL(c) (RCLASS_EXT(c)->const_tbl)
#define RCLASS_M_TBL(c) (RCLASS_EXT(c)->m_tbl)
#define RCLASS_CALLABLE_M_TBL(c) (RCLASS_EXT(c)->callable_m_tbl)
#define RCLASS_IV_INDEX_TBL(c) (RCLASS_EXT(c)->iv_index_tbl)
#define RCLASS_ORIGIN(c) (RCLASS_EXT(c)->origin_)
#define RCLASS_REFINED_CLASS(c) (RCLASS_EXT(c)->refined_class)
#define RCLASS_SERIAL(c) (RCLASS(c)->class_serial)
#define RCLASS_INCLUDER(c) (RCLASS_EXT(c)->includer)
#define RCLASS_CLONED FL_USER6
#define RICLASS_IS_ORIGIN FL_USER5
#define RCLASS_REFINED_BY_ANY FL_USER7
#undef RCLASS_SUPER
#define IMEMO_DEBUG 0
#define IMEMO_MASK 0x0f
#define IMEMO_FL_USHIFT (FL_USHIFT + 4)
#define IMEMO_FL_USER0 FL_USER4
#define IMEMO_FL_USER1 FL_USER5
#define IMEMO_FL_USER2 FL_USER6
#define IMEMO_FL_USER3 FL_USER7
#define IMEMO_FL_USER4 FL_USER8
#define THROW_DATA_CONSUMED IMEMO_FL_USER0
#define THROW_DATA_P(err) RB_TYPE_P((VALUE)(err), T_IMEMO)
#define IFUNC_NEW(a,b,c) ((struct vm_ifunc *)rb_imemo_new(imemo_ifunc, (VALUE)(a), (VALUE)(b), (VALUE)(c), 0))
#define rb_imemo_tmpbuf_auto_free_pointer() rb_imemo_new(imemo_tmpbuf, 0, 0, 0, 0)
#define RB_IMEMO_TMPBUF_PTR(v) ((void *)(((const struct rb_imemo_tmpbuf_struct *)(v))->ptr))
#define MEMO_V1_SET(m,v) RB_OBJ_WRITE((m), &(m)->v1, (v))
#define MEMO_V2_SET(m,v) RB_OBJ_WRITE((m), &(m)->v2, (v))
#define MEMO_CAST(m) ((struct MEMO *)m)
#define MEMO_NEW(a,b,c) ((struct MEMO *)rb_imemo_new(imemo_memo, (VALUE)(a), (VALUE)(b), (VALUE)(c), 0))
#define roomof(x,y) (((x) + (y) - 1) / (y))
#define type_roomof(x,y) roomof(sizeof(x), sizeof(y))
#define MEMO_FOR(type,value) ((type *)RARRAY_PTR(value))
#define NEW_MEMO_FOR(type,value) ((value) = rb_ary_tmp_new_fill(type_roomof(type, VALUE)), MEMO_FOR(type, value))
#define NEW_PARTIAL_MEMO_FOR(type,value,member) ((value) = rb_ary_tmp_new_fill(type_roomof(type, VALUE)), rb_ary_set_len((value), offsetof(type, member) / sizeof(VALUE)), MEMO_FOR(type, value))
#define STRING_P(s) (RB_TYPE_P((s), T_STRING) && CLASS_OF(s) == rb_cString)
#define rb_cFixnum rb_cInteger
#define rb_cBignum rb_cInteger
#define NEW_CMP_OPT_MEMO(type,value) NEW_PARTIAL_MEMO_FOR(type, value, cmp_opt)
#define CMP_OPTIMIZABLE_BIT(type) (1U << TOKEN_PASTE(cmp_opt_,type))
#define CMP_OPTIMIZABLE(data,type) (((data).opt_inited & CMP_OPTIMIZABLE_BIT(type)) ? ((data).opt_methods & CMP_OPTIMIZABLE_BIT(type)) : (((data).opt_inited |= CMP_OPTIMIZABLE_BIT(type)), rb_method_basic_definition_p(TOKEN_PASTE(rb_c,type), id_cmp) && ((data).opt_methods |= CMP_OPTIMIZABLE_BIT(type))))
#define OPTIMIZED_CMP(a,b,data) ((FIXNUM_P(a) && FIXNUM_P(b) && CMP_OPTIMIZABLE(data, Fixnum)) ? (((long)a > (long)b) ? 1 : ((long)a < (long)b) ? -1 : 0) : (STRING_P(a) && STRING_P(b) && CMP_OPTIMIZABLE(data, String)) ? rb_str_cmp(a, b) : (RB_FLOAT_TYPE_P(a) && RB_FLOAT_TYPE_P(b) && CMP_OPTIMIZABLE(data, Float)) ? rb_float_cmp(a, b) : rb_cmpint(rb_funcallv(a, id_cmp, 1, &b), a, b))
#define ARRAY_DEBUG (0+RUBY_DEBUG)
#define RARRAY_PTR_IN_USE_FLAG FL_USER14
#define ARY_PTR_USING_P(ary) FL_TEST_RAW((ary), RARRAY_PTR_IN_USE_FLAG)
#define RARY_TRANSIENT_SET(ary) FL_SET_RAW((ary), RARRAY_TRANSIENT_FLAG);
#define RARY_TRANSIENT_UNSET(ary) FL_UNSET_RAW((ary), RARRAY_TRANSIENT_FLAG);
#define rb_ary_new_from_args(n,...) __extension__ ({ const VALUE args_to_new_ary[] = {__VA_ARGS__}; if (__builtin_constant_p(n)) { STATIC_ASSERT(rb_ary_new_from_args, numberof(args_to_new_ary) == (n)); } rb_ary_new_from_values(numberof(args_to_new_ary), args_to_new_ary); })
#define rp(obj) rb_obj_info_dump_loc((VALUE)(obj), __FILE__, __LINE__, __func__)
#define rp_m(msg,obj) do { fprintf(stderr, "%s", (msg)); rb_obj_info_dump((VALUE)obj); } while (0)
#define bp() ruby_debug_breakpoint()
#define rb_raise_cstr(etype,mesg) rb_exc_raise(rb_exc_new_str(etype, rb_str_new_cstr(mesg)))
#define rb_raise_static(etype,mesg) rb_exc_raise(rb_exc_new_str(etype, rb_str_new_static(mesg, rb_strlen_lit(mesg))))
#define rb_name_err_raise_str(mesg,recv,name) rb_exc_raise(rb_name_err_new(mesg, recv, name))
#define rb_name_err_raise(mesg,recv,name) rb_name_err_raise_str(rb_fstring_cstr(mesg), (recv), (name))
#define rb_key_err_raise(mesg,recv,name) rb_exc_raise(rb_key_err_new(mesg, recv, name))
#define id_signo ruby_static_id_signo
#define id_status ruby_static_id_status
#pragma GCC visibility push(default)
#pragma GCC visibility pop
#define rb_sys_fail_path(path) rb_sys_fail_path_in(RUBY_FUNCTION_NAME_STRING, path)
#define rb_syserr_fail_path(err,path) rb_syserr_fail_path_in(RUBY_FUNCTION_NAME_STRING, (err), (path))
#define ruby_sized_xrealloc(ptr,new_size,old_size) ruby_xrealloc(ptr, new_size)
#define ruby_sized_xrealloc2(ptr,new_count,element_size,old_count) ruby_xrealloc2(ptr, new_count, element_size)
#define ruby_sized_xfree(ptr,size) ruby_xfree(ptr)
#define SIZED_REALLOC_N(var,type,n,old_n) REALLOC_N(var, type, n)
#undef NEWOBJF_OF
#undef RB_NEWOBJ_OF
#define RB_NEWOBJ_OF(obj,type,klass,flags) type *(obj) = (type*)(((flags) & FL_WB_PROTECTED) ? rb_wb_protected_newobj_of(klass, (flags) & ~FL_WB_PROTECTED) : rb_wb_unprotected_newobj_of(klass, flags))
#define NEWOBJ_OF(obj,type,klass,flags) RB_NEWOBJ_OF(obj,type,klass,flags)
#define RHASH_TBL_RAW(h) rb_hash_tbl_raw(h)
#pragma GCC visibility push(default)
#pragma GCC visibility pop
#define rb_io_fptr_finalize rb_io_fptr_finalize_internal
#define FIXNUM_POSITIVE_P(num) ((SIGNED_VALUE)(num) > (SIGNED_VALUE)INT2FIX(0))
#define FIXNUM_NEGATIVE_P(num) ((SIGNED_VALUE)(num) < 0)
#define FIXNUM_ZERO_P(num) ((num) == INT2FIX(0))
#define INT_NEGATIVE_P(x) (FIXNUM_P(x) ? FIXNUM_NEGATIVE_P(x) : BIGNUM_NEGATIVE_P(x))
#define FLOAT_ZERO_P(x) (RFLOAT_VALUE(x) == 0.0)
#define ROUND_DEFAULT RUBY_NUM_ROUND_HALF_UP
#define ROUND_TO(mode,even,up,down) ((mode) == RUBY_NUM_ROUND_HALF_EVEN ? even : (mode) == RUBY_NUM_ROUND_HALF_UP ? up : down)
#define ROUND_FUNC(mode,name) ROUND_TO(mode, name##_half_even, name##_half_up, name##_half_down)
#define ROUND_CALL(mode,name,args) ROUND_TO(mode, name##_half_even args, name##_half_up args, name##_half_down args)
#define RUBY_BIT_ROTL(v,n) (((v) << (n)) | ((v) >> ((sizeof(v) * 8) - n)))
#define RUBY_BIT_ROTR(v,n) (((v) >> (n)) | ((v) << ((sizeof(v) * 8) - n)))
#define rb_float_value(v) rb_float_value_inline(v)
#define rb_float_new(d) rb_float_new_inline(d)
#define RBASIC_CLEAR_CLASS(obj) memset(&(((struct RBasicRaw *)((VALUE)(obj)))->klass), 0, sizeof(VALUE))
#define RBASIC_SET_CLASS_RAW(obj,cls) memcpy(&((struct RBasicRaw *)((VALUE)(obj)))->klass, &(cls), sizeof(VALUE))
#define RBASIC_SET_CLASS(obj,cls) do { VALUE _obj_ = (obj); RB_OBJ_WRITE(_obj_, &((struct RBasicRaw *)(_obj_))->klass, cls); } while (0)
#define USE_SYMBOL_GC 1
#pragma GCC visibility push(default)
#pragma GCC visibility pop
#define RB_MAX_GROUPS (65536)
#define ARGVSTR2ARGV(argv_str) ((char **)RB_IMEMO_TMPBUF_PTR(argv_str) + 1)
#define RANGE_BEG(r) (RSTRUCT(r)->as.ary[0])
#define RANGE_END(r) (RSTRUCT(r)->as.ary[1])
#define RANGE_EXCL(r) (RSTRUCT(r)->as.ary[2])
#define rb_fstring_lit(str) rb_fstring_new((str), rb_strlen_lit(str))
#define rb_fstring_literal(str) rb_fstring_lit(str)
#define rb_fstring_cstr(str) RB_GNUC_EXTENSION_BLOCK( (__builtin_constant_p(str)) ? rb_fstring_new((str), (long)strlen(str)) : rb_fstring_cstr(str) )
#define QUOTE(str) rb_str_quote_unprintable(str)
#define QUOTE_ID(id) rb_id_quote_unprintable(id)
#define STR_NOEMBED FL_USER1
#define STR_SHARED FL_USER2
#define STR_EMBED_P(str) (!FL_TEST_RAW((str), STR_NOEMBED))
#define STR_SHARED_P(s) FL_ALL_RAW((s), STR_NOEMBED|ELTS_SHARED)
#define is_ascii_string(str) (rb_enc_str_coderange(str) == ENC_CODERANGE_7BIT)
#define is_broken_string(str) (rb_enc_str_coderange(str) == ENC_CODERANGE_BROKEN)
#define rb_sym_intern_ascii_cstr(ptr) __extension__ ( { (__builtin_constant_p(ptr)) ? rb_sym_intern_ascii((ptr), (long)strlen(ptr)) : rb_sym_intern_ascii_cstr(ptr); })
#define COVERAGE_INDEX_LINES 0
#define COVERAGE_INDEX_BRANCHES 1
#define COVERAGE_TARGET_LINES 1
#define COVERAGE_TARGET_BRANCHES 2
#define COVERAGE_TARGET_METHODS 4
#define COVERAGE_TARGET_ONESHOT_LINES 8
#define ROBJECT_TRANSIENT_FLAG FL_USER13
#define ROBJ_TRANSIENT_P(obj) FL_TEST_RAW((obj), ROBJECT_TRANSIENT_FLAG)
#define ROBJ_TRANSIENT_SET(obj) FL_SET_RAW((obj), ROBJECT_TRANSIENT_FLAG)
#define ROBJ_TRANSIENT_UNSET(obj) FL_UNSET_RAW((obj), ROBJECT_TRANSIENT_FLAG)
#define CACHELINE 64
#define rb_funcallv(recv,mid,argc,argv) __extension__({ static struct rb_call_data rb_funcallv_data; rb_funcallv_with_cc(&rb_funcallv_data, recv, mid, argc, argv); })
#define rb_method_basic_definition_p(klass,mid) __extension__({ static struct rb_call_data rb_mbdp; (klass == Qfalse) ? true : rb_method_basic_definition_p_with_cc(&rb_mbdp, klass, mid); })
#pragma GCC visibility push(default)
#undef Check_Type
#define Check_Type(v,t) (!RB_TYPE_P((VALUE)(v), (t)) || ((t) == RUBY_T_DATA && RTYPEDDATA_P(v)) ? rb_unexpected_type((VALUE)(v), (t)) : (void)0)
#define rb_typeddata_is_instance_of rb_typeddata_is_instance_of_inline
#define RB_OBJ_GC_FLAGS_MAX 6
#pragma GCC visibility pop
#define RUBY_DTRACE_CREATE_HOOK(name,arg) RUBY_DTRACE_HOOK(name##_CREATE, arg)
#define RUBY_DTRACE_HOOK(name,arg) do { if (UNLIKELY(RUBY_DTRACE_##name##_ENABLED())) { int dtrace_line; const char *dtrace_file = rb_source_location_cstr(&dtrace_line); if (!dtrace_file) dtrace_file = ""; RUBY_DTRACE_##name(arg, dtrace_file, dtrace_line); } } while (0)
#define RB_OBJ_BUILTIN_TYPE(obj) rb_obj_builtin_type(obj)
#define OBJ_BUILTIN_TYPE(obj) RB_OBJ_BUILTIN_TYPE(obj)
#define rb_obj_builtin_type(obj) __extension__({ VALUE arg_obj = (obj); RB_SPECIAL_CONST_P(arg_obj) ? -1 : RB_BUILTIN_TYPE(arg_obj); })
#define FLEX_ARY_LEN 
#define BITFIELD(type,name,size) type name : size
#define COMPILER_WARNING_PUSH _Pragma("clang diagnostic push")
#define COMPILER_WARNING_POP _Pragma("clang diagnostic pop")
#define COMPILER_WARNING_SPECIFIER(kind,msg) clang diagnostic kind # msg
#define COMPILER_WARNING_ERROR(flag) COMPILER_WARNING_PRAGMA(COMPILER_WARNING_SPECIFIER(error, flag))
#define COMPILER_WARNING_IGNORED(flag) COMPILER_WARNING_PRAGMA(COMPILER_WARNING_SPECIFIER(ignored, flag))
#define COMPILER_WARNING_PRAGMA(str) COMPILER_WARNING_PRAGMA_(str)
#define COMPILER_WARNING_PRAGMA_(str) _Pragma(#str)
#define UNALIGNED_MEMBER_ACCESS(expr) __extension__({ COMPILER_WARNING_PUSH; COMPILER_WARNING_IGNORED(-Waddress-of-packed-member); typeof(expr) unaligned_member_access_result = (expr); COMPILER_WARNING_POP; unaligned_member_access_result; })
#define UNALIGNED_MEMBER_PTR(ptr,mem) UNALIGNED_MEMBER_ACCESS(&(ptr)->mem)
#undef RB_OBJ_WRITE
#define RB_OBJ_WRITE(a,slot,b) UNALIGNED_MEMBER_ACCESS(rb_obj_write((VALUE)(a), (VALUE *)(slot), (VALUE)(b), __FILE__, __LINE__))
#define RUBY_VM_H 1
#pragma GCC visibility push(default)
#pragma GCC visibility pop
#define vm_exec rb_vm_exec
#define RUBY_GC_H 1
#define SET_MACHINE_STACK_END(p) rb_gc_set_stack_end(p)
#define USE_CONSERVATIVE_STACK_END 
#define RUBY_MARK_FREE_DEBUG 0
#define RUBY_MARK_ENTER(msg) 
#define RUBY_MARK_LEAVE(msg) 
#define RUBY_FREE_ENTER(msg) 
#define RUBY_FREE_LEAVE(msg) 
#define RUBY_GC_INFO if(0)printf
#define RUBY_MARK_NO_PIN_UNLESS_NULL(ptr) do { VALUE markobj = (ptr); if (RTEST(markobj)) {rb_gc_mark_movable(markobj);} } while (0)
#define RUBY_MARK_UNLESS_NULL(ptr) do { VALUE markobj = (ptr); if (RTEST(markobj)) {rb_gc_mark(markobj);} } while (0)
#define RUBY_FREE_UNLESS_NULL(ptr) if(ptr){ruby_xfree(ptr);(ptr)=NULL;}
#define STACK_UPPER(x,a,b) (b)
#define STACK_GROW_DIR_DETECTION 
#define STACK_DIR_UPPER(a,b) STACK_UPPER(0, (a), (b))
#define IS_STACK_DIR_UPPER() STACK_DIR_UPPER(1,0)
#pragma GCC visibility push(default)
#pragma GCC visibility pop
#define RUBY_VM_CORE_H 
#define N_OR_RUBY_DEBUG(n) (((n) > 0) ? (n) : RUBY_DEBUG)
#define VM_CHECK_MODE N_OR_RUBY_DEBUG(0)
#define VMDEBUG 0
#undef assert
#define assert RUBY_ASSERT
#define VM_ASSERT(expr) ((void)0)
#define VM_UNREACHABLE(func) UNREACHABLE
#define RUBY_VM_THREAD_MODEL 2
#define VM_INSN_INFO_TABLE_IMPL 2
#define RUBY_NODE_H 1
#define RNODE(obj) (R_CAST(RNode)(obj))
#define NODE_FL_NEWLINE (((VALUE)1)<<7)
#define NODE_TYPESHIFT 8
#define NODE_TYPEMASK (((VALUE)0x7f)<<NODE_TYPESHIFT)
#define nd_type(n) ((int) (((n)->flags & NODE_TYPEMASK)>>NODE_TYPESHIFT))
#define nd_set_type(n,t) (n)->flags=(((n)->flags&~NODE_TYPEMASK)|((((unsigned long)(t))<<NODE_TYPESHIFT)&NODE_TYPEMASK))
#define NODE_LSHIFT (NODE_TYPESHIFT+7)
#define NODE_LMASK (((SIGNED_VALUE)1<<(sizeof(VALUE)*CHAR_BIT-NODE_LSHIFT))-1)
#define nd_line(n) (int)(((SIGNED_VALUE)(n)->flags)>>NODE_LSHIFT)
#define nd_set_line(n,l) (n)->flags=(((n)->flags&~((VALUE)(-1)<<NODE_LSHIFT))|((VALUE)((l)&NODE_LMASK)<<NODE_LSHIFT))
#define nd_first_column(n) ((int)((n)->nd_loc.beg_pos.column))
#define nd_set_first_column(n,v) ((n)->nd_loc.beg_pos.column = (v))
#define nd_first_lineno(n) ((int)((n)->nd_loc.beg_pos.lineno))
#define nd_set_first_lineno(n,v) ((n)->nd_loc.beg_pos.lineno = (v))
#define nd_first_loc(n) ((n)->nd_loc.beg_pos)
#define nd_set_first_loc(n,v) (nd_first_loc(n) = (v))
#define nd_last_column(n) ((int)((n)->nd_loc.end_pos.column))
#define nd_set_last_column(n,v) ((n)->nd_loc.end_pos.column = (v))
#define nd_last_lineno(n) ((int)((n)->nd_loc.end_pos.lineno))
#define nd_set_last_lineno(n,v) ((n)->nd_loc.end_pos.lineno = (v))
#define nd_last_loc(n) ((n)->nd_loc.end_pos)
#define nd_set_last_loc(n,v) (nd_last_loc(n) = (v))
#define nd_node_id(n) ((n)->node_id)
#define nd_set_node_id(n,id) ((n)->node_id = (id))
#define nd_head u1.node
#define nd_alen u2.argc
#define nd_next u3.node
#define nd_cond u1.node
#define nd_body u2.node
#define nd_else u3.node
#define nd_resq u2.node
#define nd_ensr u3.node
#define nd_1st u1.node
#define nd_2nd u2.node
#define nd_stts u1.node
#define nd_entry u3.entry
#define nd_vid u1.id
#define nd_cflag u2.id
#define nd_cval u3.value
#define nd_oid u1.id
#define nd_tbl u1.tbl
#define nd_var u1.node
#define nd_iter u3.node
#define nd_value u2.node
#define nd_aid u3.id
#define nd_lit u1.value
#define nd_rest u1.id
#define nd_opt u1.node
#define nd_pid u1.id
#define nd_plen u2.argc
#define nd_recv u1.node
#define nd_mid u2.id
#define nd_args u3.node
#define nd_ainfo u3.args
#define nd_defn u3.node
#define nd_cpath u1.node
#define nd_super u3.node
#define nd_beg u1.node
#define nd_end u2.node
#define nd_state u3.state
#define nd_rval u2.value
#define nd_nth u2.argc
#define nd_tag u1.id
#define nd_alias u1.id
#define nd_orig u2.id
#define nd_undef u2.node
#define nd_brace u2.argc
#define nd_pconst u1.node
#define nd_pkwargs u2.node
#define nd_pkwrestarg u3.node
#define nd_apinfo u3.apinfo
#define NEW_NODE(t,a0,a1,a2,loc) rb_node_newnode((t),(VALUE)(a0),(VALUE)(a1),(VALUE)(a2),loc)
#define NEW_NODE_WITH_LOCALS(t,a1,a2,loc) node_newnode_with_locals(p, (t),(VALUE)(a1),(VALUE)(a2),loc)
#define NEW_DEFN(i,a,d,loc) NEW_NODE(NODE_DEFN,0,i,NEW_SCOPE(a,d,loc),loc)
#define NEW_DEFS(r,i,a,d,loc) NEW_NODE(NODE_DEFS,r,i,NEW_SCOPE(a,d,loc),loc)
#define NEW_SCOPE(a,b,loc) NEW_NODE_WITH_LOCALS(NODE_SCOPE,b,a,loc)
#define NEW_BLOCK(a,loc) NEW_NODE(NODE_BLOCK,a,0,0,loc)
#define NEW_IF(c,t,e,loc) NEW_NODE(NODE_IF,c,t,e,loc)
#define NEW_UNLESS(c,t,e,loc) NEW_NODE(NODE_UNLESS,c,t,e,loc)
#define NEW_CASE(h,b,loc) NEW_NODE(NODE_CASE,h,b,0,loc)
#define NEW_CASE2(b,loc) NEW_NODE(NODE_CASE2,0,b,0,loc)
#define NEW_CASE3(h,b,loc) NEW_NODE(NODE_CASE3,h,b,0,loc)
#define NEW_WHEN(c,t,e,loc) NEW_NODE(NODE_WHEN,c,t,e,loc)
#define NEW_IN(c,t,e,loc) NEW_NODE(NODE_IN,c,t,e,loc)
#define NEW_WHILE(c,b,n,loc) NEW_NODE(NODE_WHILE,c,b,n,loc)
#define NEW_UNTIL(c,b,n,loc) NEW_NODE(NODE_UNTIL,c,b,n,loc)
#define NEW_FOR(i,b,loc) NEW_NODE(NODE_FOR,0,b,i,loc)
#define NEW_FOR_MASGN(v,loc) NEW_NODE(NODE_FOR_MASGN,v,0,0,loc)
#define NEW_ITER(a,b,loc) NEW_NODE(NODE_ITER,0,NEW_SCOPE(a,b,loc),0,loc)
#define NEW_LAMBDA(a,b,loc) NEW_NODE(NODE_LAMBDA,0,NEW_SCOPE(a,b,loc),0,loc)
#define NEW_BREAK(s,loc) NEW_NODE(NODE_BREAK,s,0,0,loc)
#define NEW_NEXT(s,loc) NEW_NODE(NODE_NEXT,s,0,0,loc)
#define NEW_REDO(loc) NEW_NODE(NODE_REDO,0,0,0,loc)
#define NEW_RETRY(loc) NEW_NODE(NODE_RETRY,0,0,0,loc)
#define NEW_BEGIN(b,loc) NEW_NODE(NODE_BEGIN,0,b,0,loc)
#define NEW_RESCUE(b,res,e,loc) NEW_NODE(NODE_RESCUE,b,res,e,loc)
#define NEW_RESBODY(a,ex,n,loc) NEW_NODE(NODE_RESBODY,n,ex,a,loc)
#define NEW_ENSURE(b,en,loc) NEW_NODE(NODE_ENSURE,b,0,en,loc)
#define NEW_RETURN(s,loc) NEW_NODE(NODE_RETURN,s,0,0,loc)
#define NEW_YIELD(a,loc) NEW_NODE(NODE_YIELD,a,0,0,loc)
#define NEW_LIST(a,loc) NEW_NODE(NODE_LIST,a,1,0,loc)
#define NEW_ZLIST(loc) NEW_NODE(NODE_ZLIST,0,0,0,loc)
#define NEW_HASH(a,loc) NEW_NODE(NODE_HASH,a,0,0,loc)
#define NEW_MASGN(l,r,loc) NEW_NODE(NODE_MASGN,l,0,r,loc)
#define NEW_GASGN(v,val,loc) NEW_NODE(NODE_GASGN,v,val,rb_global_entry(v),loc)
#define NEW_LASGN(v,val,loc) NEW_NODE(NODE_LASGN,v,val,0,loc)
#define NEW_DASGN(v,val,loc) NEW_NODE(NODE_DASGN,v,val,0,loc)
#define NEW_DASGN_CURR(v,val,loc) NEW_NODE(NODE_DASGN_CURR,v,val,0,loc)
#define NEW_IASGN(v,val,loc) NEW_NODE(NODE_IASGN,v,val,0,loc)
#define NEW_CDECL(v,val,path,loc) NEW_NODE(NODE_CDECL,v,val,path,loc)
#define NEW_CVASGN(v,val,loc) NEW_NODE(NODE_CVASGN,v,val,0,loc)
#define NEW_OP_ASGN1(p,id,a,loc) NEW_NODE(NODE_OP_ASGN1,p,id,a,loc)
#define NEW_OP_ASGN2(r,t,i,o,val,loc) NEW_NODE(NODE_OP_ASGN2,r,val,NEW_OP_ASGN22(i,o,t,loc),loc)
#define NEW_OP_ASGN22(i,o,t,loc) NEW_NODE(NODE_OP_ASGN2,i,o,t,loc)
#define NEW_OP_ASGN_OR(i,val,loc) NEW_NODE(NODE_OP_ASGN_OR,i,val,0,loc)
#define NEW_OP_ASGN_AND(i,val,loc) NEW_NODE(NODE_OP_ASGN_AND,i,val,0,loc)
#define NEW_OP_CDECL(v,op,val,loc) NEW_NODE(NODE_OP_CDECL,v,val,op,loc)
#define NEW_GVAR(v,loc) NEW_NODE(NODE_GVAR,v,0,rb_global_entry(v),loc)
#define NEW_LVAR(v,loc) NEW_NODE(NODE_LVAR,v,0,0,loc)
#define NEW_DVAR(v,loc) NEW_NODE(NODE_DVAR,v,0,0,loc)
#define NEW_IVAR(v,loc) NEW_NODE(NODE_IVAR,v,0,0,loc)
#define NEW_CONST(v,loc) NEW_NODE(NODE_CONST,v,0,0,loc)
#define NEW_CVAR(v,loc) NEW_NODE(NODE_CVAR,v,0,0,loc)
#define NEW_NTH_REF(n,loc) NEW_NODE(NODE_NTH_REF,0,n,0,loc)
#define NEW_BACK_REF(n,loc) NEW_NODE(NODE_BACK_REF,0,n,0,loc)
#define NEW_MATCH(c,loc) NEW_NODE(NODE_MATCH,c,0,0,loc)
#define NEW_MATCH2(n1,n2,loc) NEW_NODE(NODE_MATCH2,n1,n2,0,loc)
#define NEW_MATCH3(r,n2,loc) NEW_NODE(NODE_MATCH3,r,n2,0,loc)
#define NEW_LIT(l,loc) NEW_NODE(NODE_LIT,l,0,0,loc)
#define NEW_STR(s,loc) NEW_NODE(NODE_STR,s,0,0,loc)
#define NEW_DSTR(s,loc) NEW_NODE(NODE_DSTR,s,1,0,loc)
#define NEW_XSTR(s,loc) NEW_NODE(NODE_XSTR,s,0,0,loc)
#define NEW_DXSTR(s,loc) NEW_NODE(NODE_DXSTR,s,0,0,loc)
#define NEW_DSYM(s,loc) NEW_NODE(NODE_DSYM,s,0,0,loc)
#define NEW_EVSTR(n,loc) NEW_NODE(NODE_EVSTR,0,(n),0,loc)
#define NEW_CALL(r,m,a,loc) NEW_NODE(NODE_CALL,r,m,a,loc)
#define NEW_OPCALL(r,m,a,loc) NEW_NODE(NODE_OPCALL,r,m,a,loc)
#define NEW_FCALL(m,a,loc) NEW_NODE(NODE_FCALL,0,m,a,loc)
#define NEW_VCALL(m,loc) NEW_NODE(NODE_VCALL,0,m,0,loc)
#define NEW_SUPER(a,loc) NEW_NODE(NODE_SUPER,0,0,a,loc)
#define NEW_ZSUPER(loc) NEW_NODE(NODE_ZSUPER,0,0,0,loc)
#define NEW_ARGS_AUX(r,b,loc) NEW_NODE(NODE_ARGS_AUX,r,b,0,loc)
#define NEW_OPT_ARG(i,v,loc) NEW_NODE(NODE_OPT_ARG,i,v,0,loc)
#define NEW_KW_ARG(i,v,loc) NEW_NODE(NODE_KW_ARG,i,v,0,loc)
#define NEW_POSTARG(i,v,loc) NEW_NODE(NODE_POSTARG,i,v,0,loc)
#define NEW_ARGSCAT(a,b,loc) NEW_NODE(NODE_ARGSCAT,a,b,0,loc)
#define NEW_ARGSPUSH(a,b,loc) NEW_NODE(NODE_ARGSPUSH,a,b,0,loc)
#define NEW_SPLAT(a,loc) NEW_NODE(NODE_SPLAT,a,0,0,loc)
#define NEW_BLOCK_PASS(b,loc) NEW_NODE(NODE_BLOCK_PASS,0,b,0,loc)
#define NEW_ALIAS(n,o,loc) NEW_NODE(NODE_ALIAS,n,o,0,loc)
#define NEW_VALIAS(n,o,loc) NEW_NODE(NODE_VALIAS,n,o,0,loc)
#define NEW_UNDEF(i,loc) NEW_NODE(NODE_UNDEF,0,i,0,loc)
#define NEW_CLASS(n,b,s,loc) NEW_NODE(NODE_CLASS,n,NEW_SCOPE(0,b,loc),(s),loc)
#define NEW_SCLASS(r,b,loc) NEW_NODE(NODE_SCLASS,r,NEW_SCOPE(0,b,loc),0,loc)
#define NEW_MODULE(n,b,loc) NEW_NODE(NODE_MODULE,n,NEW_SCOPE(0,b,loc),0,loc)
#define NEW_COLON2(c,i,loc) NEW_NODE(NODE_COLON2,c,i,0,loc)
#define NEW_COLON3(i,loc) NEW_NODE(NODE_COLON3,0,i,0,loc)
#define NEW_DOT2(b,e,loc) NEW_NODE(NODE_DOT2,b,e,0,loc)
#define NEW_DOT3(b,e,loc) NEW_NODE(NODE_DOT3,b,e,0,loc)
#define NEW_SELF(loc) NEW_NODE(NODE_SELF,0,0,1,loc)
#define NEW_NIL(loc) NEW_NODE(NODE_NIL,0,0,0,loc)
#define NEW_TRUE(loc) NEW_NODE(NODE_TRUE,0,0,0,loc)
#define NEW_FALSE(loc) NEW_NODE(NODE_FALSE,0,0,0,loc)
#define NEW_ERRINFO(loc) NEW_NODE(NODE_ERRINFO,0,0,0,loc)
#define NEW_DEFINED(e,loc) NEW_NODE(NODE_DEFINED,e,0,0,loc)
#define NEW_PREEXE(b,loc) NEW_SCOPE(b,loc)
#define NEW_POSTEXE(b,loc) NEW_NODE(NODE_POSTEXE,0,b,0,loc)
#define NEW_ATTRASGN(r,m,a,loc) NEW_NODE(NODE_ATTRASGN,r,m,a,loc)
#define NODE_SPECIAL_REQUIRED_KEYWORD ((NODE *)-1)
#define NODE_REQUIRED_KEYWORD_P(node) ((node)->nd_value == NODE_SPECIAL_REQUIRED_KEYWORD)
#define NODE_SPECIAL_NO_NAME_REST ((NODE *)-1)
#define NODE_NAMED_REST_P(node) ((node) != NODE_SPECIAL_NO_NAME_REST)
#define NODE_SPECIAL_EXCESSIVE_COMMA ((ID)1)
#define NODE_SPECIAL_NO_REST_KEYWORD ((NODE *)-1)
#pragma GCC visibility push(default)
#pragma GCC visibility pop
#define RUBY_VM_OPTS_H 
#define OPT_TAILCALL_OPTIMIZATION 0
#define OPT_PEEPHOLE_OPTIMIZATION 1
#define OPT_SPECIALISED_INSTRUCTION 1
#define OPT_INLINE_CONST_CACHE 1
#define OPT_FROZEN_STRING_LITERAL 0
#define OPT_DEBUG_FROZEN_STRING_LITERAL 0
#define OPT_THREADED_CODE 0
#define OPT_DIRECT_THREADED_CODE (OPT_THREADED_CODE == 0)
#define OPT_TOKEN_THREADED_CODE (OPT_THREADED_CODE == 1)
#define OPT_CALL_THREADED_CODE (OPT_THREADED_CODE == 2)
#define OPT_CHECKED_RUN 1
#define OPT_INLINE_METHOD_CACHE 1
#define OPT_GLOBAL_METHOD_CACHE 1
#define OPT_BLOCKINLINING 0
#define OPT_IC_FOR_IVAR 1
#define OPT_OPERANDS_UNIFICATION 1
#define OPT_INSTRUCTIONS_UNIFICATION 0
#define OPT_UNIFY_ALL_COMBINATION 0
#define OPT_STACK_CACHING 0
#define OPT_SUPPORT_JOKE 0
#define VM_COLLECT_USAGE_DETAILS 0
#define RUBY_ID_H 
#define ID_STATIC_SYM RUBY_ID_STATIC_SYM
#define ID_SCOPE_SHIFT RUBY_ID_SCOPE_SHIFT
#define ID_SCOPE_MASK RUBY_ID_SCOPE_MASK
#define ID_LOCAL RUBY_ID_LOCAL
#define ID_INSTANCE RUBY_ID_INSTANCE
#define ID_GLOBAL RUBY_ID_GLOBAL
#define ID_ATTRSET RUBY_ID_ATTRSET
#define ID_CONST RUBY_ID_CONST
#define ID_CLASS RUBY_ID_CLASS
#define ID_JUNK RUBY_ID_JUNK
#define ID_INTERNAL RUBY_ID_INTERNAL
#define symIFUNC ID2SYM(idIFUNC)
#define symCFUNC ID2SYM(idCFUNC)
#define RUBY_TOKEN_DOT2 128
#define RUBY_TOKEN_DOT3 129
#define RUBY_TOKEN_BDOT2 130
#define RUBY_TOKEN_BDOT3 131
#define RUBY_TOKEN_UPLUS 132
#define RUBY_TOKEN_UMINUS 133
#define RUBY_TOKEN_POW 134
#define RUBY_TOKEN_CMP 135
#define RUBY_TOKEN_LSHFT 136
#define RUBY_TOKEN_RSHFT 137
#define RUBY_TOKEN_LEQ 138
#define RUBY_TOKEN_GEQ 139
#define RUBY_TOKEN_EQ 140
#define RUBY_TOKEN_EQQ 141
#define RUBY_TOKEN_NEQ 142
#define RUBY_TOKEN_MATCH 143
#define RUBY_TOKEN_NMATCH 144
#define RUBY_TOKEN_AREF 145
#define RUBY_TOKEN_ASET 146
#define RUBY_TOKEN_COLON2 147
#define RUBY_TOKEN_ANDOP 148
#define RUBY_TOKEN_OROP 149
#define RUBY_TOKEN_ANDDOT 150
#define RUBY_TOKEN(t) RUBY_TOKEN_##t
#define RUBY_TOKEN2ID_TYPE(tok,type) ((tok<<RUBY_ID_SCOPE_SHIFT)|type|RUBY_ID_STATIC_SYM)
#define TOKEN2LOCALID(tok) RUBY_TOKEN2ID_TYPE(tok, RUBY_ID_LOCAL)
#define TOKEN2INSTANCEID(tok) RUBY_TOKEN2ID_TYPE(tok, RUBY_ID_INSTANCE)
#define TOKEN2GLOBALID(tok) RUBY_TOKEN2ID_TYPE(tok, RUBY_ID_GLOBAL)
#define TOKEN2CONSTID(tok) RUBY_TOKEN2ID_TYPE(tok, RUBY_ID_CONST)
#define TOKEN2CLASSID(tok) RUBY_TOKEN2ID_TYPE(tok, RUBY_ID_CLASS)
#define TOKEN2ATTRSETID(tok) RUBY_TOKEN2ID_TYPE(tok, RUBY_ID_ATTRSET)
#define DEFINE_LOCALID_FROM_TOKEN(n) id##n = TOKEN2LOCALID(t##n)
#define DEFINE_INSTANCEID_FROM_TOKEN(n) id##n = TOKEN2INSTANCEID(t##n)
#define DEFINE_GLOBALID_FROM_TOKEN(n) id##n = TOKEN2GLOBALID(t##n)
#define DEFINE_CONSTID_FROM_TOKEN(n) id##n = TOKEN2CONSTID(t##n)
#define DEFINE_CLASSID_FROM_TOKEN(n) id##n = TOKEN2CLASSID(t##n)
#define DEFINE_ATTRSETID_FROM_TOKEN(n) id##n = TOKEN2ATTRSETID(t##n)
#define RUBY_METHOD_H 1
#define END_OF_ENUMERATION(key) 
#define METHOD_ENTRY_VISI(me) (rb_method_visibility_t)(((me)->flags & (IMEMO_FL_USER0 | IMEMO_FL_USER1)) >> (IMEMO_FL_USHIFT+0))
#define METHOD_ENTRY_BASIC(me) (int) (((me)->flags & (IMEMO_FL_USER2 )) >> (IMEMO_FL_USHIFT+2))
#define METHOD_ENTRY_COMPLEMENTED(me) ((me)->flags & IMEMO_FL_USER3)
#define METHOD_ENTRY_COMPLEMENTED_SET(me) ((me)->flags = (me)->flags | IMEMO_FL_USER3)
#define VM_METHOD_TYPE_MINIMUM_BITS 4
#define rb_iseq_t rb_iseq_t
#define UNDEFINED_METHOD_ENTRY_P(me) (!(me) || !(me)->def || (me)->def->type == VM_METHOD_TYPE_UNDEF)
#define UNDEFINED_REFINED_METHOD_P(def) ((def)->type == VM_METHOD_TYPE_REFINED && UNDEFINED_METHOD_ENTRY_P((def)->body.refined.orig_me))
#pragma GCC visibility push(default)
#pragma GCC visibility pop
#define RUBY_ATOMIC_H 
#define ATOMIC_SET(var,val) (void)__atomic_exchange_n(&(var), (val), __ATOMIC_SEQ_CST)
#define ATOMIC_INC(var) __atomic_fetch_add(&(var), 1, __ATOMIC_SEQ_CST)
#define ATOMIC_DEC(var) __atomic_fetch_sub(&(var), 1, __ATOMIC_SEQ_CST)
#define ATOMIC_OR(var,val) __atomic_fetch_or(&(var), (val), __ATOMIC_SEQ_CST)
#define ATOMIC_EXCHANGE(var,val) __atomic_exchange_n(&(var), (val), __ATOMIC_SEQ_CST)
#define ATOMIC_CAS(var,oldval,newval) ({ __typeof__(var) oldvaldup = (oldval); __atomic_compare_exchange_n(&(var), &oldvaldup, (newval), 0, __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST); oldvaldup; })
#define ATOMIC_SIZE_ADD(var,val) __atomic_fetch_add(&(var), (val), __ATOMIC_SEQ_CST)
#define ATOMIC_SIZE_SUB(var,val) __atomic_fetch_sub(&(var), (val), __ATOMIC_SEQ_CST)
#define RUBY_ATOMIC_GENERIC_MACRO 1
#define ATOMIC_SIZE_INC(var) ATOMIC_INC(var)
#define ATOMIC_SIZE_DEC(var) ATOMIC_DEC(var)
#define ATOMIC_SIZE_EXCHANGE(var,val) ATOMIC_EXCHANGE(var, val)
#define ATOMIC_SIZE_CAS(var,oldval,val) ATOMIC_CAS(var, oldval, val)
#define ATOMIC_PTR_EXCHANGE(var,val) ATOMIC_EXCHANGE(var, val)
#define ATOMIC_PTR_CAS(var,oldval,newval) ATOMIC_CAS(var, oldval, newval)
#define ATOMIC_VALUE_EXCHANGE(var,val) ATOMIC_EXCHANGE(var, val)
#define ATOMIC_VALUE_CAS(var,oldval,val) ATOMIC_CAS(var, oldval, val)
#define CCAN_LIST_H 
#undef assert
#undef __assert
#define __assert(e,file,line) __assert_rtn ((const char *)-1L, file, line, e)
#define assert(e) (__builtin_expect(!(e), 0) ? __assert_rtn(__func__, __FILE__, __LINE__, #e) : (void)0)
#define _ASSERT_H_ 
#define CCAN_STR_H 
#define stringify(expr) stringify_1(expr)
#define stringify_1(expr) #expr
#define CCAN_CONTAINER_OF_H 
#define CCAN_CHECK_TYPE_H 
#define check_type(expr,type) ((typeof(expr) *)0 != (type *)0)
#define check_types_match(expr1,expr2) ((typeof(expr1) *)0 != (typeof(expr2) *)0)
#define container_of(member_ptr,containing_type,member) ((containing_type *) ((char *)(member_ptr) - container_off(containing_type, member)) + check_types_match(*(member_ptr), ((containing_type *)0)->member))
#define container_of_or_null(member_ptr,containing_type,member) ((containing_type *) container_of_or_null_(member_ptr, container_off(containing_type, member)) + check_types_match(*(member_ptr), ((containing_type *)0)->member))
#define container_off(containing_type,member) offsetof(containing_type, member)
#define container_of_var(member_ptr,container_var,member) container_of(member_ptr, typeof(*container_var), member)
#define container_off_var(var,member) container_off(typeof(*var), member)
#define LIST_LOC __FILE__ ":" stringify(__LINE__)
#define list_debug(h,loc) ((void)loc, h)
#define list_debug_node(n,loc) ((void)loc, n)
#define LIST_HEAD_INIT(name) { { &(name).n, &(name).n } }
#define LIST_HEAD(name) struct list_head name = LIST_HEAD_INIT(name)
#define list_add_after(h,p,n) list_add_after_(h, p, n, LIST_LOC)
#define list_add(h,n) list_add_(h, n, LIST_LOC)
#define list_add_before(h,p,n) list_add_before_(h, p, n, LIST_LOC)
#define list_add_tail(h,n) list_add_tail_(h, n, LIST_LOC)
#define list_empty(h) list_empty_(h, LIST_LOC)
#define list_empty_nodebug(h) list_empty(h)
#define list_del(n) list_del_(n, LIST_LOC)
#define list_del_init(n) list_del_init_(n, LIST_LOC)
#define list_swap(o,n) list_swap_(o, n, LIST_LOC)
#define list_entry(n,type,member) container_of(n, type, member)
#define list_top(h,type,member) ((type *)list_top_((h), list_off_(type, member)))
#define list_pop(h,type,member) ((type *)list_pop_((h), list_off_(type, member)))
#define list_tail(h,type,member) ((type *)list_tail_((h), list_off_(type, member)))
#define list_for_each(h,i,member) list_for_each_off(h, i, list_off_var_(i, member))
#define list_for_each_rev(h,i,member) list_for_each_rev_off(h, i, list_off_var_(i, member))
#define list_for_each_rev_safe(h,i,nxt,member) list_for_each_rev_safe_off(h, i, nxt, list_off_var_(i, member))
#define list_for_each_safe(h,i,nxt,member) list_for_each_safe_off(h, i, nxt, list_off_var_(i, member))
#define list_next(h,i,member) ((list_typeof(i))list_entry_or_null(list_debug(h, __FILE__ ":" stringify(__LINE__)), (i)->member.next, list_off_var_((i), member)))
#define list_prev(h,i,member) ((list_typeof(i))list_entry_or_null(list_debug(h, __FILE__ ":" stringify(__LINE__)), (i)->member.prev, list_off_var_((i), member)))
#define list_append_list(t,f) list_append_list_(t, f, __FILE__ ":" stringify(__LINE__))
#define list_prepend_list(t,f) list_prepend_list_(t, f, LIST_LOC)
#define list_for_each_off_dir_(h,i,off,dir) for (i = list_node_to_off_(list_debug(h, LIST_LOC)->n.dir, (off)); list_node_from_off_((void *)i, (off)) != &(h)->n; i = list_node_to_off_(list_node_from_off_((void *)i, (off))->dir, (off)))
#define list_for_each_safe_off_dir_(h,i,nxt,off,dir) for (i = list_node_to_off_(list_debug(h, LIST_LOC)->n.dir, (off)), nxt = list_node_to_off_(list_node_from_off_(i, (off))->dir, (off)); list_node_from_off_(i, (off)) != &(h)->n; i = nxt, nxt = list_node_to_off_(list_node_from_off_(i, (off))->dir, (off)))
#define list_for_each_off(h,i,off) list_for_each_off_dir_((h),(i),(off),next)
#define list_for_each_rev_off(h,i,off) list_for_each_off_dir_((h),(i),(off),prev)
#define list_for_each_safe_off(h,i,nxt,off) list_for_each_safe_off_dir_((h),(i),(nxt),(off),next)
#define list_for_each_rev_safe_off(h,i,nxt,off) list_for_each_safe_off_dir_((h),(i),(nxt),(off),prev)
#define list_entry_off(n,type,off) ((type *)list_node_from_off_((n), (off)))
#define list_head_off(h,type,off) ((type *)list_head_off((h), (off)))
#define list_tail_off(h,type,off) ((type *)list_tail_((h), (off)))
#define list_add_off(h,n,off) list_add((h), list_node_from_off_((n), (off)))
#define list_del_off(n,off) list_del(list_node_from_off_((n), (off)))
#define list_del_from_off(h,n,off) list_del_from(h, list_node_from_off_((n), (off)))
#define list_off_(type,member) (container_off(type, member) + check_type(((type *)0)->member, struct list_node))
#define list_off_var_(var,member) (container_off_var(var, member) + check_type(var->member, struct list_node))
#define list_typeof(var) typeof(var)
#define RUBY_THREAD_NATIVE_H 1
#define _PTHREAD_H 
#define _SCHED_H_ 
#define _PTHREAD_IMPL_H_ 
#pragma clang assume_nonnull begin
#define _PTHREAD_MUTEX_SIG_init 0x32AAABA7
#define _PTHREAD_ERRORCHECK_MUTEX_SIG_init 0x32AAABA1
#define _PTHREAD_RECURSIVE_MUTEX_SIG_init 0x32AAABA2
#define _PTHREAD_FIRSTFIT_MUTEX_SIG_init 0x32AAABA3
#define _PTHREAD_COND_SIG_init 0x3CB0B1BB
#define _PTHREAD_ONCE_SIG_init 0x30B1BCBA
#define _PTHREAD_RWLOCK_SIG_init 0x2DA8B3B4
#define SCHED_OTHER 1
#define SCHED_FIFO 4
#define SCHED_RR 2
#define __SCHED_PARAM_SIZE__ 4
#pragma clang assume_nonnull end
#define _TIME_H_ 
#define CLOCKS_PER_SEC 1000000
#define __CLOCK_AVAILABILITY __OSX_AVAILABLE(10.12) __IOS_AVAILABLE(10.0) __TVOS_AVAILABLE(10.0) __WATCHOS_AVAILABLE(3.0)
#define CLOCK_REALTIME _CLOCK_REALTIME
#define CLOCK_MONOTONIC _CLOCK_MONOTONIC
#define CLOCK_MONOTONIC_RAW _CLOCK_MONOTONIC_RAW
#define CLOCK_MONOTONIC_RAW_APPROX _CLOCK_MONOTONIC_RAW_APPROX
#define CLOCK_UPTIME_RAW _CLOCK_UPTIME_RAW
#define CLOCK_UPTIME_RAW_APPROX _CLOCK_UPTIME_RAW_APPROX
#define CLOCK_PROCESS_CPUTIME_ID _CLOCK_PROCESS_CPUTIME_ID
#define CLOCK_THREAD_CPUTIME_ID _CLOCK_THREAD_CPUTIME_ID
#undef __CLOCK_AVAILABILITY
#define _PTHREAD_QOS_H 
#define _SYS_QOS_H 
#define __QOS_ENUM(name,type,...) enum { __VA_ARGS__ }; typedef type name##_t
#define __QOS_CLASS_AVAILABLE(...) 
#undef __QOS_CLASS_AVAILABLE
#define __QOS_CLASS_AVAILABLE __API_AVAILABLE
#undef __QOS_ENUM
#define QOS_MIN_RELATIVE_PRIORITY (-15)
#pragma clang assume_nonnull begin
#pragma clang assume_nonnull end
#define _MACH_PORT_T 
#pragma clang assume_nonnull begin
#define pthread_cleanup_push(func,val) { struct __darwin_pthread_handler_rec __handler; pthread_t __self = pthread_self(); __handler.__routine = func; __handler.__arg = val; __handler.__next = __self->__cleanup_stack; __self->__cleanup_stack = &__handler;
#define pthread_cleanup_pop(execute) __self->__cleanup_stack = __handler.__next; if (execute) (__handler.__routine)(__handler.__arg); }
#define PTHREAD_CREATE_JOINABLE 1
#define PTHREAD_CREATE_DETACHED 2
#define PTHREAD_INHERIT_SCHED 1
#define PTHREAD_EXPLICIT_SCHED 2
#define PTHREAD_CANCEL_ENABLE 0x01
#define PTHREAD_CANCEL_DISABLE 0x00
#define PTHREAD_CANCEL_DEFERRED 0x02
#define PTHREAD_CANCEL_ASYNCHRONOUS 0x00
#define PTHREAD_CANCELED ((void *) 1)
#define PTHREAD_SCOPE_SYSTEM 1
#define PTHREAD_SCOPE_PROCESS 2
#define PTHREAD_PROCESS_SHARED 1
#define PTHREAD_PROCESS_PRIVATE 2
#define PTHREAD_PRIO_NONE 0
#define PTHREAD_PRIO_INHERIT 1
#define PTHREAD_PRIO_PROTECT 2
#define PTHREAD_MUTEX_NORMAL 0
#define PTHREAD_MUTEX_ERRORCHECK 1
#define PTHREAD_MUTEX_RECURSIVE 2
#define PTHREAD_MUTEX_DEFAULT PTHREAD_MUTEX_NORMAL
#define PTHREAD_MUTEX_POLICY_FAIRSHARE_NP 1
#define PTHREAD_MUTEX_POLICY_FIRSTFIT_NP 3
#define PTHREAD_RWLOCK_INITIALIZER {_PTHREAD_RWLOCK_SIG_init, {0}}
#define PTHREAD_MUTEX_INITIALIZER {_PTHREAD_MUTEX_SIG_init, {0}}
#define PTHREAD_ERRORCHECK_MUTEX_INITIALIZER {_PTHREAD_ERRORCHECK_MUTEX_SIG_init, {0}}
#define PTHREAD_RECURSIVE_MUTEX_INITIALIZER {_PTHREAD_RECURSIVE_MUTEX_SIG_init, {0}}
#define _PTHREAD_SWIFT_IMPORTER_NULLABILITY_COMPAT defined(SWIFT_CLASS_EXTRA) && (!defined(SWIFT_SDK_OVERLAY_PTHREAD_EPOCH) || (SWIFT_SDK_OVERLAY_PTHREAD_EPOCH < 1))
#define PTHREAD_COND_INITIALIZER {_PTHREAD_COND_SIG_init, {0}}
#define PTHREAD_ONCE_INIT {_PTHREAD_ONCE_SIG_init, {0}}
#pragma clang assume_nonnull end
#pragma GCC visibility push(default)
#pragma GCC visibility pop
#define RUBY_THREAD_PTHREAD_H 
#define RB_NATIVETHREAD_LOCK_INIT PTHREAD_MUTEX_INITIALIZER
#define RB_NATIVETHREAD_COND_INIT PTHREAD_COND_INITIALIZER
#undef except
#undef try
#undef leave
#undef finally
#define _BSD_SETJMP_H 
#define _JBLEN ((14 + 8 + 2) * 2)
#define _USER_SIGNAL_H 
#define sigaddset(set,signo) (*(set) |= __sigbits(signo), 0)
#define sigdelset(set,signo) (*(set) &= ~__sigbits(signo), 0)
#define sigismember(set,signo) ((*(set) & __sigbits(signo)) != 0)
#define sigemptyset(set) (*(set) = 0, 0)
#define sigfillset(set) (*(set) = ~(sigset_t)0, 0)
#define RUBY_NSIG NSIG
#define RUBY_SIGCHLD (SIGCHLD)
#define SIGCHLD_LOSSY (1)
#define WAITPID_USE_SIGCHLD (RUBY_SIGCHLD || SIGCHLD_LOSSY)
#define va_init_list(a,b) va_start((a),(b))
#define USE_SIGALTSTACK 
#define RB_ALTSTACK_INIT(var) var = rb_register_sigaltstack()
#define RB_ALTSTACK_FREE(var) xfree(var)
#define RB_ALTSTACK(var) var
#define TAG_NONE RUBY_TAG_NONE
#define TAG_RETURN RUBY_TAG_RETURN
#define TAG_BREAK RUBY_TAG_BREAK
#define TAG_NEXT RUBY_TAG_NEXT
#define TAG_RETRY RUBY_TAG_RETRY
#define TAG_REDO RUBY_TAG_REDO
#define TAG_RAISE RUBY_TAG_RAISE
#define TAG_THROW RUBY_TAG_THROW
#define TAG_FATAL RUBY_TAG_FATAL
#define TAG_MASK RUBY_TAG_MASK
#define CoreDataFromValue(obj,type) (type*)DATA_PTR(obj)
#define GetCoreDataFromValue(obj,type,ptr) ((ptr) = CoreDataFromValue((obj), type))
#define PATHOBJ_PATH 0
#define PATHOBJ_REALPATH 1
#define USE_LAZY_LOAD 0
#define GetVMPtr(obj,ptr) GetCoreDataFromValue((obj), rb_vm_t, (ptr))
#define RUBY_VM_SIZE_ALIGN 4096
#define RUBY_VM_THREAD_VM_STACK_SIZE ( 128 * 1024 * sizeof(VALUE))
#define RUBY_VM_THREAD_VM_STACK_SIZE_MIN ( 2 * 1024 * sizeof(VALUE))
#define RUBY_VM_THREAD_MACHINE_STACK_SIZE ( 128 * 1024 * sizeof(VALUE))
#define RUBY_VM_THREAD_MACHINE_STACK_SIZE_MIN ( 16 * 1024 * sizeof(VALUE))
#define RUBY_VM_FIBER_VM_STACK_SIZE ( 16 * 1024 * sizeof(VALUE))
#define RUBY_VM_FIBER_VM_STACK_SIZE_MIN ( 2 * 1024 * sizeof(VALUE))
#define RUBY_VM_FIBER_MACHINE_STACK_SIZE ( 64 * 1024 * sizeof(VALUE))
#define RUBY_VM_FIBER_MACHINE_STACK_SIZE_MIN ( 16 * 1024 * sizeof(VALUE))
#define INTEGER_REDEFINED_OP_FLAG (1 << 0)
#define FLOAT_REDEFINED_OP_FLAG (1 << 1)
#define STRING_REDEFINED_OP_FLAG (1 << 2)
#define ARRAY_REDEFINED_OP_FLAG (1 << 3)
#define HASH_REDEFINED_OP_FLAG (1 << 4)
#define SYMBOL_REDEFINED_OP_FLAG (1 << 6)
#define TIME_REDEFINED_OP_FLAG (1 << 7)
#define REGEXP_REDEFINED_OP_FLAG (1 << 8)
#define NIL_REDEFINED_OP_FLAG (1 << 9)
#define TRUE_REDEFINED_OP_FLAG (1 << 10)
#define FALSE_REDEFINED_OP_FLAG (1 << 11)
#define PROC_REDEFINED_OP_FLAG (1 << 12)
#define BASIC_OP_UNREDEFINED_P(op,klass) (LIKELY((GET_VM()->redefined_flag[(op)]&(klass)) == 0))
#define VM_DEBUG_BP_CHECK 0
#define VM_DEBUG_VERIFY_METHOD_CACHE (VMDEBUG != 0)
#define VM_CORE_H_EC_DEFINED 1
#define VM_DEFINECLASS_TYPE(x) ((rb_vm_defineclass_type_t)(x) & VM_DEFINECLASS_TYPE_MASK)
#define VM_DEFINECLASS_FLAG_SCOPED 0x08
#define VM_DEFINECLASS_FLAG_HAS_SUPERCLASS 0x10
#define VM_DEFINECLASS_SCOPED_P(x) ((x) & VM_DEFINECLASS_FLAG_SCOPED)
#define VM_DEFINECLASS_HAS_SUPERCLASS_P(x) ((x) & VM_DEFINECLASS_FLAG_HAS_SUPERCLASS)
#pragma GCC visibility push(default)
#pragma GCC visibility pop
#define GetProcPtr(obj,ptr) GetCoreDataFromValue((obj), rb_proc_t, (ptr))
#define GetBindingPtr(obj,ptr) GetCoreDataFromValue((obj), rb_binding_t, (ptr))
#define VM_CHECKMATCH_TYPE_MASK 0x03
#define VM_CHECKMATCH_ARRAY 0x04
#define VM_CALL_ARGS_SPLAT (0x01 << VM_CALL_ARGS_SPLAT_bit)
#define VM_CALL_ARGS_BLOCKARG (0x01 << VM_CALL_ARGS_BLOCKARG_bit)
#define VM_CALL_FCALL (0x01 << VM_CALL_FCALL_bit)
#define VM_CALL_VCALL (0x01 << VM_CALL_VCALL_bit)
#define VM_CALL_ARGS_SIMPLE (0x01 << VM_CALL_ARGS_SIMPLE_bit)
#define VM_CALL_BLOCKISEQ (0x01 << VM_CALL_BLOCKISEQ_bit)
#define VM_CALL_KWARG (0x01 << VM_CALL_KWARG_bit)
#define VM_CALL_KW_SPLAT (0x01 << VM_CALL_KW_SPLAT_bit)
#define VM_CALL_TAILCALL (0x01 << VM_CALL_TAILCALL_bit)
#define VM_CALL_SUPER (0x01 << VM_CALL_SUPER_bit)
#define VM_CALL_ZSUPER (0x01 << VM_CALL_ZSUPER_bit)
#define VM_CALL_OPT_SEND (0x01 << VM_CALL_OPT_SEND_bit)
#define FUNC_FASTCALL(x) x
#define VM_TAGGED_PTR_SET(p,tag) ((VALUE)(p) | (tag))
#define VM_TAGGED_PTR_REF(v,mask) ((void *)((v) & ~mask))
#define GC_GUARDED_PTR(p) VM_TAGGED_PTR_SET((p), 0x01)
#define GC_GUARDED_PTR_REF(p) VM_TAGGED_PTR_REF((p), 0x03)
#define GC_GUARDED_PTR_P(p) (((VALUE)(p)) & 0x01)
#define VM_ENV_DATA_SIZE ( 3)
#define VM_ENV_DATA_INDEX_ME_CREF (-2)
#define VM_ENV_DATA_INDEX_SPECVAL (-1)
#define VM_ENV_DATA_INDEX_FLAGS ( 0)
#define VM_ENV_DATA_INDEX_ENV ( 1)
#define VM_ENV_INDEX_LAST_LVAR (-VM_ENV_DATA_SIZE)
#define RUBYVM_CFUNC_FRAME_P(cfp) (VM_FRAME_TYPE(cfp) == VM_FRAME_MAGIC_CFUNC)
#define VM_GUARDED_PREV_EP(ep) GC_GUARDED_PTR(ep)
#define VM_BLOCK_HANDLER_NONE 0
#define RUBY_VM_PREVIOUS_CONTROL_FRAME(cfp) ((cfp)+1)
#define RUBY_VM_NEXT_CONTROL_FRAME(cfp) ((cfp)-1)
#define RUBY_VM_VALID_CONTROL_FRAME_P(cfp,ecfp) ((void *)(ecfp) > (void *)(cfp))
#define SDR() rb_vmdebug_stack_dump_raw(GET_EC(), GET_EC()->cfp)
#define SDR2(cfp) rb_vmdebug_stack_dump_raw(GET_EC(), (cfp))
#pragma GCC visibility push(default)
#pragma GCC visibility pop
#define rb_vm_register_special_exception(sp,e,m) rb_vm_register_special_exception_str(sp, e, rb_usascii_str_new_static((m), (long)rb_strlen_lit(m)))
#define sysstack_error GET_VM()->special_exceptions[ruby_error_sysstack]
#define RUBY_CONST_ASSERT(expr) (1/!!(expr))
#define VM_STACK_OVERFLOWED_P(cfp,sp,margin) (!RUBY_CONST_ASSERT(sizeof(*(sp)) == sizeof(VALUE)) || !RUBY_CONST_ASSERT(sizeof(*(cfp)) == sizeof(rb_control_frame_t)) || ((rb_control_frame_t *)((sp) + (margin)) + 1) >= (cfp))
#define WHEN_VM_STACK_OVERFLOWED(cfp,sp,margin) if (LIKELY(!VM_STACK_OVERFLOWED_P(cfp, sp, margin))) {(void)0;} else
#define CHECK_VM_STACK_OVERFLOW0(cfp,sp,margin) WHEN_VM_STACK_OVERFLOWED(cfp, sp, margin) vm_stackoverflow()
#define CHECK_VM_STACK_OVERFLOW(cfp,margin) WHEN_VM_STACK_OVERFLOWED(cfp, (cfp)->sp, margin) vm_stackoverflow()
#pragma GCC visibility push(default)
#pragma GCC visibility pop
#define GET_VM() rb_current_vm()
#define GET_THREAD() rb_current_thread()
#define GET_EC() rb_current_execution_context()
#define RUBY_VM_SET_TIMER_INTERRUPT(ec) ATOMIC_OR((ec)->interrupt_flag, TIMER_INTERRUPT_MASK)
#define RUBY_VM_SET_INTERRUPT(ec) ATOMIC_OR((ec)->interrupt_flag, PENDING_INTERRUPT_MASK)
#define RUBY_VM_SET_POSTPONED_JOB_INTERRUPT(ec) ATOMIC_OR((ec)->interrupt_flag, POSTPONED_JOB_INTERRUPT_MASK)
#define RUBY_VM_SET_TRAP_INTERRUPT(ec) ATOMIC_OR((ec)->interrupt_flag, TRAP_INTERRUPT_MASK)
#define RUBY_VM_INTERRUPTED(ec) ((ec)->interrupt_flag & ~(ec)->interrupt_mask & (PENDING_INTERRUPT_MASK|TRAP_INTERRUPT_MASK))
#define RUBY_VM_INTERRUPTED_ANY(ec) ((ec)->interrupt_flag & ~(ec)->interrupt_mask)
#define RUBY_VM_CHECK_INTS(ec) rb_vm_check_ints(ec)
#define EXEC_EVENT_HOOK_ORIG(ec_,hooks_,flag_,self_,id_,called_id_,klass_,data_,pop_p_) do { const rb_event_flag_t flag_arg_ = (flag_); rb_hook_list_t *hooks_arg_ = (hooks_); if (UNLIKELY((hooks_arg_)->events & (flag_arg_))) { rb_exec_event_hook_orig(ec_, hooks_arg_, flag_arg_, self_, id_, called_id_, klass_, data_, pop_p_); } } while (0)
#define EXEC_EVENT_HOOK(ec_,flag_,self_,id_,called_id_,klass_,data_) EXEC_EVENT_HOOK_ORIG(ec_, rb_vm_global_hooks(ec_), flag_, self_, id_, called_id_, klass_, data_, 0)
#define EXEC_EVENT_HOOK_AND_POP_FRAME(ec_,flag_,self_,id_,called_id_,klass_,data_) EXEC_EVENT_HOOK_ORIG(ec_, rb_vm_global_hooks(ec_), flag_, self_, id_, called_id_, klass_, data_, 1)
#pragma GCC visibility push(default)
#define RUBY_EVENT_COVERAGE_LINE 0x010000
#define RUBY_EVENT_COVERAGE_BRANCH 0x020000
#pragma GCC visibility pop
#define RUBY_DEBUG_H 
#pragma GCC visibility push(default)
#define dpv(h,v) ruby_debug_print_value(-1, 0, (h), (v))
#define dp(v) ruby_debug_print_value(-1, 0, "", (v))
#define dpi(i) ruby_debug_print_id(-1, 0, "", (i))
#define dpn(n) ruby_debug_print_node(-1, 0, "", (n))
#pragma GCC visibility pop
#define RUBY_ISEQ_H 1
#define ISEQ_MAJOR_VERSION ((unsigned int)ruby_api_version[0])
#define ISEQ_MINOR_VERSION ((unsigned int)ruby_api_version[1])
#define ISEQ_COVERAGE(iseq) iseq->body->variable.coverage
#define ISEQ_COVERAGE_SET(iseq,cov) RB_OBJ_WRITE(iseq, &iseq->body->variable.coverage, cov)
#define ISEQ_LINE_COVERAGE(iseq) RARRAY_AREF(ISEQ_COVERAGE(iseq), COVERAGE_INDEX_LINES)
#define ISEQ_BRANCH_COVERAGE(iseq) RARRAY_AREF(ISEQ_COVERAGE(iseq), COVERAGE_INDEX_BRANCHES)
#define ISEQ_PC2BRANCHINDEX(iseq) iseq->body->variable.pc2branchindex
#define ISEQ_PC2BRANCHINDEX_SET(iseq,h) RB_OBJ_WRITE(iseq, &iseq->body->variable.pc2branchindex, h)
#define ISEQ_FLIP_CNT(iseq) (iseq)->body->variable.flip_count
#define ISEQ_TRACE_EVENTS (RUBY_EVENT_LINE | RUBY_EVENT_CLASS | RUBY_EVENT_END | RUBY_EVENT_CALL | RUBY_EVENT_RETURN| RUBY_EVENT_B_CALL| RUBY_EVENT_B_RETURN| RUBY_EVENT_COVERAGE_LINE| RUBY_EVENT_COVERAGE_BRANCH)
#define ISEQ_NOT_LOADED_YET IMEMO_FL_USER1
#define ISEQ_USE_COMPILE_DATA IMEMO_FL_USER2
#define ISEQ_TRANSLATED IMEMO_FL_USER3
#define ISEQ_MARKABLE_ISEQ IMEMO_FL_USER4
#define ISEQ_EXECUTABLE_P(iseq) (FL_TEST_RAW((iseq), ISEQ_NOT_LOADED_YET | ISEQ_USE_COMPILE_DATA) == 0)
#pragma GCC visibility push(default)
#define INITIAL_ISEQ_COMPILE_DATA_STORAGE_BUFF_SIZE (512)
#pragma GCC visibility pop
#define RUBY_EVAL_INTERN_H 
#define PASS_PASSED_BLOCK_HANDLER_EC(ec) pass_passed_block_handler(ec)
#define PASS_PASSED_BLOCK_HANDLER() pass_passed_block_handler(GET_EC())
#define ruby_setjmp(env) RUBY_SETJMP(env)
#define ruby_longjmp(env,val) RUBY_LONGJMP((env),(val))
#define _SYS_ERRNO_H_ 
#define errno (*__error())
#define EPERM 1
#define ENOENT 2
#define ESRCH 3
#define EINTR 4
#define EIO 5
#define ENXIO 6
#define E2BIG 7
#define ENOEXEC 8
#define EBADF 9
#define ECHILD 10
#define EDEADLK 11
#define ENOMEM 12
#define EACCES 13
#define EFAULT 14
#define ENOTBLK 15
#define EBUSY 16
#define EEXIST 17
#define EXDEV 18
#define ENODEV 19
#define ENOTDIR 20
#define EISDIR 21
#define EINVAL 22
#define ENFILE 23
#define EMFILE 24
#define ENOTTY 25
#define ETXTBSY 26
#define EFBIG 27
#define ENOSPC 28
#define ESPIPE 29
#define EROFS 30
#define EMLINK 31
#define EPIPE 32
#define EDOM 33
#define ERANGE 34
#define EAGAIN 35
#define EWOULDBLOCK EAGAIN
#define EINPROGRESS 36
#define EALREADY 37
#define ENOTSOCK 38
#define EDESTADDRREQ 39
#define EMSGSIZE 40
#define EPROTOTYPE 41
#define ENOPROTOOPT 42
#define EPROTONOSUPPORT 43
#define ESOCKTNOSUPPORT 44
#define ENOTSUP 45
#define EPFNOSUPPORT 46
#define EAFNOSUPPORT 47
#define EADDRINUSE 48
#define EADDRNOTAVAIL 49
#define ENETDOWN 50
#define ENETUNREACH 51
#define ENETRESET 52
#define ECONNABORTED 53
#define ECONNRESET 54
#define ENOBUFS 55
#define EISCONN 56
#define ENOTCONN 57
#define ESHUTDOWN 58
#define ETOOMANYREFS 59
#define ETIMEDOUT 60
#define ECONNREFUSED 61
#define ELOOP 62
#define ENAMETOOLONG 63
#define EHOSTDOWN 64
#define EHOSTUNREACH 65
#define ENOTEMPTY 66
#define EPROCLIM 67
#define EUSERS 68
#define EDQUOT 69
#define ESTALE 70
#define EREMOTE 71
#define EBADRPC 72
#define ERPCMISMATCH 73
#define EPROGUNAVAIL 74
#define EPROGMISMATCH 75
#define EPROCUNAVAIL 76
#define ENOLCK 77
#define ENOSYS 78
#define EFTYPE 79
#define EAUTH 80
#define ENEEDAUTH 81
#define EPWROFF 82
#define EDEVERR 83
#define EOVERFLOW 84
#define EBADEXEC 85
#define EBADARCH 86
#define ESHLIBVERS 87
#define EBADMACHO 88
#define ECANCELED 89
#define EIDRM 90
#define ENOMSG 91
#define EILSEQ 92
#define ENOATTR 93
#define EBADMSG 94
#define EMULTIHOP 95
#define ENODATA 96
#define ENOLINK 97
#define ENOSR 98
#define ENOSTR 99
#define EPROTO 100
#define ETIME 101
#define EOPNOTSUPP 102
#define ENOPOLICY 103
#define ENOTRECOVERABLE 104
#define EOWNERDEAD 105
#define EQFULL 106
#define ELAST 106
#define _SYS_PARAM_H_ 
#define BSD 199506
#define BSD4_3 1
#define BSD4_4 1
#define NeXTBSD 1995064
#define NeXTBSD4_0 0
#define MAXCOMLEN 16
#define MAXINTERP 64
#define MAXLOGNAME 255
#define MAXUPRC CHILD_MAX
#define NCARGS ARG_MAX
#define NGROUPS NGROUPS_MAX
#define NOFILE 256
#define NOGROUP 65535
#define MAXHOSTNAMELEN 256
#define MAXDOMNAMELEN 256
#define _BSD_MACHINE_PARAM_H_ 
#define _ARM_PARAM_H_ 
#define _ARM__PARAM_H_ 
#define __DARWIN_ALIGNBYTES (sizeof(__darwin_size_t) - 1)
#define __DARWIN_ALIGN(p) ((__darwin_size_t)((__darwin_size_t)(p) + __DARWIN_ALIGNBYTES) &~ __DARWIN_ALIGNBYTES)
#define __DARWIN_ALIGNBYTES32 (sizeof(__uint32_t) - 1)
#define __DARWIN_ALIGN32(p) ((__darwin_size_t)((__darwin_size_t)(p) + __DARWIN_ALIGNBYTES32) &~ __DARWIN_ALIGNBYTES32)
#define ALIGNBYTES __DARWIN_ALIGNBYTES
#define ALIGN(p) __DARWIN_ALIGN(p)
#define NBPG 4096
#define PGOFSET (NBPG-1)
#define PGSHIFT 12
#define DEV_BSIZE 512
#define DEV_BSHIFT 9
#define BLKDEV_IOSIZE 2048
#define MAXPHYS (64 * 1024)
#define CLSIZE 1
#define CLSIZELOG2 0
#define MSIZESHIFT 8
#define MSIZE (1 << MSIZESHIFT)
#define MCLSHIFT 11
#define MCLBYTES (1 << MCLSHIFT)
#define MBIGCLSHIFT 12
#define MBIGCLBYTES (1 << MBIGCLSHIFT)
#define M16KCLSHIFT 14
#define M16KCLBYTES (1 << M16KCLSHIFT)
#define MCLOFSET (MCLBYTES - 1)
#define NMBCLUSTERS CONFIG_NMBCLUSTERS
#define ctos(x) (x)
#define stoc(x) (x)
#define ctod(x) ((x)<<(PGSHIFT-DEV_BSHIFT))
#define dtoc(x) ((x)>>(PGSHIFT-DEV_BSHIFT))
#define dtob(x) ((x)<<DEV_BSHIFT)
#define ctob(x) ((x)<<PGSHIFT)
#define btoc(x) (((unsigned)(x)+(NBPG-1))>>PGSHIFT)
#define btodb(bytes,devBlockSize) ((unsigned)(bytes) / devBlockSize)
#define dbtob(db,devBlockSize) ((unsigned)(db) * devBlockSize)
#define bdbtofsb(bn) ((bn) / (BLKDEV_IOSIZE/DEV_BSIZE))
#define STATUS_WORD(rpl,ipl) (((ipl) << 8) | (rpl))
#define USERMODE(x) (((x) & 3) == 3)
#define BASEPRI(x) (((x) & (255 << 8)) == 0)
#define DELAY(n) { int N = (n); while (--N > 0); }
#define PSWP 0
#define PVM 4
#define PINOD 8
#define PRIBIO 16
#define PVFS 20
#define PZERO 22
#define PSOCK 24
#define PWAIT 32
#define PLOCK 36
#define PPAUSE 40
#define PUSER 50
#define MAXPRI 127
#define PRIMASK 0x0ff
#define PCATCH 0x100
#define PTTYBLOCK 0x200
#define PDROP 0x400
#define PSPIN 0x800
#define NBPW sizeof(int)
#define CMASK 022
#define NODEV (dev_t)(-1)
#define CLBYTES (CLSIZE*NBPG)
#define CLOFSET (CLSIZE*NBPG-1)
#define claligned(x) ((((int)(x))&CLOFSET)==0)
#define CLOFF CLOFSET
#define CLSHIFT (PGSHIFT+CLSIZELOG2)
#define clbase(i) (i)
#define clrnd(i) (i)
#define CBLOCK 64
#define CBQSIZE (CBLOCK/NBBY)
#define CBSIZE (CBLOCK - sizeof(struct cblock *) - CBQSIZE)
#define CROUND (CBLOCK - 1)
#define MAXBSIZE (256 * 4096)
#define MAXPHYSIO MAXPHYS
#define MAXFRAG 8
#define MAXPHYSIO_WIRED (16 * 1024 * 1024)
#define MAXPATHLEN PATH_MAX
#define MAXSYMLINKS 32
#define setbit(a,i) (((unsigned char *)(a))[(i)/NBBY] |= 1u<<((i)%NBBY))
#define clrbit(a,i) (((unsigned char *)(a))[(i)/NBBY] &= ~(1u<<((i)%NBBY)))
#define isset(a,i) (((unsigned char *)(a))[(i)/NBBY] & (1u<<((i)%NBBY)))
#define isclr(a,i) ((((unsigned char *)(a))[(i)/NBBY] & (1u<<((i)%NBBY))) == 0)
#define roundup(x,y) ((((x) % (y)) == 0) ? (x) : ((x) + ((y) - ((x) % (y)))))
#define powerof2(x) ((((x)-1)&(x))==0)
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define FSHIFT 11
#define FSCALE (1<<FSHIFT)
#define SAVE_ROOT_JMPBUF_BEFORE_STMT 
#define SAVE_ROOT_JMPBUF_AFTER_STMT 
#define SAVE_ROOT_JMPBUF(th,stmt) do if (ruby_setjmp((th)->root_jmpbuf) == 0) { SAVE_ROOT_JMPBUF_BEFORE_STMT stmt; SAVE_ROOT_JMPBUF_AFTER_STMT } else { rb_fiber_start(); } while (0)
#define EC_PUSH_TAG(ec) do { rb_execution_context_t * const _ec = (ec); struct rb_vm_tag _tag; _tag.state = TAG_NONE; _tag.tag = Qundef; _tag.prev = _ec->tag;
#define EC_POP_TAG() _ec->tag = _tag.prev; } while (0)
#define EC_TMPPOP_TAG() _ec->tag = _tag.prev
#define EC_REPUSH_TAG() (void)(_ec->tag = &_tag)
#define VAR_FROM_MEMORY(var) __extension__(*(__typeof__(var) volatile *)&(var))
#define VAR_INITIALIZED(var) ((var) = VAR_FROM_MEMORY(var))
#define VAR_NOCLOBBERED(var) volatile var
#define EC_EXEC_TAG() (ruby_setjmp(_tag.buf) ? rb_ec_tag_state(VAR_FROM_MEMORY(_ec)) : (EC_REPUSH_TAG(), 0))
#define EC_JUMP_TAG(ec,st) rb_ec_tag_jump(ec, st)
#define INTERNAL_EXCEPTION_P(exc) FIXNUM_P(exc)
#define CREF_FL_PUSHED_BY_EVAL IMEMO_FL_USER1
#define CREF_FL_OMOD_SHARED IMEMO_FL_USER2
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Waddress-of-packed-member"
#pragma clang diagnostic pop
#define rb_ec_raised_set(ec,f) ((ec)->raised_flag |= (f))
#define rb_ec_raised_reset(ec,f) ((ec)->raised_flag &= ~(f))
#define rb_ec_raised_p(ec,f) (((ec)->raised_flag & (f)) != 0)
#define rb_ec_raised_clear(ec) ((ec)->raised_flag = 0)
#define CharNext(p) ((p) + mblen((p), RUBY_MBCHAR_MAXSIZE))
#define BUILTIN_H_INCLUDED 
#define RB_BUILTIN_FUNCTION(_i,_name,_fname,_arity) { .name = #_name, .func_ptr = (void *)_fname, .argc = _arity, .index = _i }
#define _PROBES_H 
#define DTRACE_PROBES_DISABLED 1
#define RUBY_DTRACE_METHOD_ENTRY_ENABLED() 0
#define RUBY_DTRACE_METHOD_ENTRY(classname,methodname,filename,lineno) do {} while (0)
#define RUBY_DTRACE_METHOD_RETURN_ENABLED() 0
#define RUBY_DTRACE_METHOD_RETURN(classname,methodname,filename,lineno) do {} while (0)
#define RUBY_DTRACE_CMETHOD_ENTRY_ENABLED() 0
#define RUBY_DTRACE_CMETHOD_ENTRY(classname,methodname,filename,lineno) do {} while (0)
#define RUBY_DTRACE_CMETHOD_RETURN_ENABLED() 0
#define RUBY_DTRACE_CMETHOD_RETURN(classname,methodname,filename,lineno) do {} while (0)
#define RUBY_DTRACE_REQUIRE_ENTRY_ENABLED() 0
#define RUBY_DTRACE_REQUIRE_ENTRY(rquiredfile,filename,lineno) do {} while (0)
#define RUBY_DTRACE_REQUIRE_RETURN_ENABLED() 0
#define RUBY_DTRACE_REQUIRE_RETURN(requiredfile,filename,lineno) do {} while (0)
#define RUBY_DTRACE_FIND_REQUIRE_ENTRY_ENABLED() 0
#define RUBY_DTRACE_FIND_REQUIRE_ENTRY(requiredfile,filename,lineno) do {} while (0)
#define RUBY_DTRACE_FIND_REQUIRE_RETURN_ENABLED() 0
#define RUBY_DTRACE_FIND_REQUIRE_RETURN(requiredfile,filename,lineno) do {} while (0)
#define RUBY_DTRACE_LOAD_ENTRY_ENABLED() 0
#define RUBY_DTRACE_LOAD_ENTRY(loadedfile,filename,lineno) do {} while (0)
#define RUBY_DTRACE_LOAD_RETURN_ENABLED() 0
#define RUBY_DTRACE_LOAD_RETURN(loadedfile,filename,lineno) do {} while (0)
#define RUBY_DTRACE_RAISE_ENABLED() 0
#define RUBY_DTRACE_RAISE(classname,filename,lineno) do {} while (0)
#define RUBY_DTRACE_OBJECT_CREATE_ENABLED() 0
#define RUBY_DTRACE_OBJECT_CREATE(classname,filename,lineno) do {} while (0)
#define RUBY_DTRACE_ARRAY_CREATE_ENABLED() 0
#define RUBY_DTRACE_ARRAY_CREATE(length,filename,lineno) do {} while (0)
#define RUBY_DTRACE_HASH_CREATE_ENABLED() 0
#define RUBY_DTRACE_HASH_CREATE(length,filename,lineno) do {} while (0)
#define RUBY_DTRACE_STRING_CREATE_ENABLED() 0
#define RUBY_DTRACE_STRING_CREATE(length,filename,lineno) do {} while (0)
#define RUBY_DTRACE_SYMBOL_CREATE_ENABLED() 0
#define RUBY_DTRACE_SYMBOL_CREATE(str,filename,lineno) do {} while (0)
#define RUBY_DTRACE_PARSE_BEGIN_ENABLED() 0
#define RUBY_DTRACE_PARSE_BEGIN(sourcefile,lineno) do {} while (0)
#define RUBY_DTRACE_PARSE_END_ENABLED() 0
#define RUBY_DTRACE_PARSE_END(sourcefile,lineno) do {} while (0)
#define RUBY_DTRACE_INSN_ENABLED() 0
#define RUBY_DTRACE_INSN(insns_name) do {} while (0)
#define RUBY_DTRACE_INSN_OPERAND_ENABLED() 0
#define RUBY_DTRACE_INSN_OPERAND(val,insns_name) do {} while (0)
#define RUBY_DTRACE_GC_MARK_BEGIN_ENABLED() 0
#define RUBY_DTRACE_GC_MARK_BEGIN() do {} while (0)
#define RUBY_DTRACE_GC_MARK_END_ENABLED() 0
#define RUBY_DTRACE_GC_MARK_END() do {} while (0)
#define RUBY_DTRACE_GC_SWEEP_BEGIN_ENABLED() 0
#define RUBY_DTRACE_GC_SWEEP_BEGIN() do {} while (0)
#define RUBY_DTRACE_GC_SWEEP_END_ENABLED() 0
#define RUBY_DTRACE_GC_SWEEP_END() do {} while (0)
#define RUBY_DTRACE_METHOD_CACHE_CLEAR_ENABLED() 0
#define RUBY_DTRACE_METHOD_CACHE_CLEAR(class,filename,lineno) do {} while (0)
#define RUBY_PROBES_HELPER_H 
#define RUBY_DTRACE_METHOD_HOOK(name,ec,klazz,id) do { if (UNLIKELY(RUBY_DTRACE_##name##_ENABLED())) { struct ruby_dtrace_method_hook_args args; if (rb_dtrace_setup(ec, klazz, id, &args)) { RUBY_DTRACE_##name(args.classname, args.methodname, args.filename, args.line_no); } } } while (0)
#define RUBY_DTRACE_METHOD_ENTRY_HOOK(ec,klass,id) RUBY_DTRACE_METHOD_HOOK(METHOD_ENTRY, ec, klass, id)
#define RUBY_DTRACE_METHOD_RETURN_HOOK(ec,klass,id) RUBY_DTRACE_METHOD_HOOK(METHOD_RETURN, ec, klass, id)
#define RUBY_DTRACE_CMETHOD_ENTRY_HOOK(ec,klass,id) RUBY_DTRACE_METHOD_HOOK(CMETHOD_ENTRY, ec, klass, id)
#define RUBY_DTRACE_CMETHOD_RETURN_HOOK(ec,klass,id) RUBY_DTRACE_METHOD_HOOK(CMETHOD_RETURN, ec, klass, id)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Waddress-of-packed-member"
#pragma clang diagnostic pop
#define RUBY_MJIT_H 1
#define USE_DEBUG_COUNTER 0
#define RUBY_DEBUG_COUNTER_H 1
#define RB_DEBUG_COUNTER(name) RB_DEBUG_COUNTER_##name,
#undef RB_DEBUG_COUNTER
#define RB_DEBUG_COUNTER_INC(type) ((void)0)
#define RB_DEBUG_COUNTER_INC_UNLESS(type,cond) (cond)
#define RB_DEBUG_COUNTER_INC_IF(type,cond) (cond)
#pragma GCC visibility push(default)
#pragma GCC visibility pop
#pragma GCC visibility push(default)
#pragma GCC visibility pop
#define JIT_ISEQ_SIZE_THRESHOLD 1000
#define RUBY_INSNHELPER_H 
#pragma GCC visibility push(default)
#pragma GCC visibility pop
#define COLLECT_USAGE_INSN(insn) 
#define COLLECT_USAGE_OPERAND(insn,n,op) 
#define COLLECT_USAGE_REGISTER(reg,s) 
#define PUSH(x) (SET_SV(x), INC_SP(1))
#define TOPN(n) (*(GET_SP()-(n)-1))
#define POPN(n) (DEC_SP(n))
#define POP() (DEC_SP(1))
#define STACK_ADDR_FROM_TOP(n) (GET_SP()-(n))
#define VM_REG_CFP (reg_cfp)
#define VM_REG_PC (VM_REG_CFP->pc)
#define VM_REG_SP (VM_REG_CFP->sp)
#define VM_REG_EP (VM_REG_CFP->ep)
#define RESTORE_REGS() do { VM_REG_CFP = ec->cfp; } while (0)
#define COLLECT_USAGE_REGISTER_HELPER(a,b,v) (v)
#define GET_PC() (COLLECT_USAGE_REGISTER_HELPER(PC, GET, VM_REG_PC))
#define SET_PC(x) (VM_REG_PC = (COLLECT_USAGE_REGISTER_HELPER(PC, SET, (x))))
#define GET_CURRENT_INSN() (*GET_PC())
#define GET_OPERAND(n) (GET_PC()[(n)])
#define ADD_PC(n) (SET_PC(VM_REG_PC + (n)))
#define JUMP(dst) (SET_PC(VM_REG_PC + (dst)))
#define GET_CFP() (COLLECT_USAGE_REGISTER_HELPER(CFP, GET, VM_REG_CFP))
#define GET_EP() (COLLECT_USAGE_REGISTER_HELPER(EP, GET, VM_REG_EP))
#define SET_EP(x) (VM_REG_EP = (COLLECT_USAGE_REGISTER_HELPER(EP, SET, (x))))
#define GET_LEP() (VM_EP_LEP(GET_EP()))
#define GET_SP() (COLLECT_USAGE_REGISTER_HELPER(SP, GET, VM_REG_SP))
#define SET_SP(x) (VM_REG_SP = (COLLECT_USAGE_REGISTER_HELPER(SP, SET, (x))))
#define INC_SP(x) (VM_REG_SP += (COLLECT_USAGE_REGISTER_HELPER(SP, SET, (x))))
#define DEC_SP(x) (VM_REG_SP -= (COLLECT_USAGE_REGISTER_HELPER(SP, SET, (x))))
#define SET_SV(x) (*GET_SP() = (x))
#define GET_ISEQ() (GET_CFP()->iseq)
#define GET_PREV_EP(ep) ((VALUE *)((ep)[VM_ENV_DATA_INDEX_SPECVAL] & ~0x03))
#define GET_SELF() (COLLECT_USAGE_REGISTER_HELPER(SELF, GET, GET_CFP()->self))
#define GET_BLOCK_HANDLER() (GET_LEP()[VM_ENV_DATA_INDEX_SPECVAL])
#define SETUP_CANARY() 
#define CHECK_CANARY() 
#define PREV_CLASS_SERIAL() (ruby_vm_class_serial)
#define NEXT_CLASS_SERIAL() (++ruby_vm_class_serial)
#define GET_GLOBAL_METHOD_STATE() (ruby_vm_global_method_state)
#define INC_GLOBAL_METHOD_STATE() (++ruby_vm_global_method_state)
#define GET_GLOBAL_CONSTANT_STATE() (ruby_vm_global_constant_state)
#define INC_GLOBAL_CONSTANT_STATE() (++ruby_vm_global_constant_state)
#define IS_ARGS_SPLAT(ci) ((ci)->flag & VM_CALL_ARGS_SPLAT)
#define IS_ARGS_KEYWORD(ci) ((ci)->flag & VM_CALL_KWARG)
#define IS_ARGS_KW_SPLAT(ci) ((ci)->flag & VM_CALL_KW_SPLAT)
#define IS_ARGS_KW_OR_KW_SPLAT(ci) ((ci)->flag & (VM_CALL_KWARG | VM_CALL_KW_SPLAT))
#define RUBY_VM_EXEC_H 
#define debugs 
#define DEBUG_ENTER_INSN(insn) 
#define DEBUG_END_INSN() 
#define throwdebug if(0)printf
#define LABEL(x) INSN_LABEL_##x
#define ELABEL(x) INSN_ELABEL_##x
#define LABEL_PTR(x) RB_GNUC_EXTENSION(&&LABEL(x))
#define INSN_ENTRY_SIG(insn) if (0) fprintf(stderr, "exec: %s@(%"PRIdPTRDIFF", %"PRIdPTRDIFF")@%s:%u\n", #insn, (reg_pc - reg_cfp->iseq->body->iseq_encoded), (reg_cfp->pc - reg_cfp->iseq->body->iseq_encoded), RSTRING_PTR(rb_iseq_path(reg_cfp->iseq)), rb_iseq_line_no(reg_cfp->iseq, reg_pc - reg_cfp->iseq->body->iseq_encoded));
#define INSN_DISPATCH_SIG(insn) 
#define INSN_ENTRY(insn) LABEL(insn): INSN_ENTRY_SIG(insn);
#define TC_DISPATCH(insn) INSN_DISPATCH_SIG(insn); RB_GNUC_EXTENSION_BLOCK(goto *(void const *)GET_CURRENT_INSN()); ;
#define END_INSN(insn) DEBUG_END_INSN(); TC_DISPATCH(insn);
#define INSN_DISPATCH() TC_DISPATCH(__START__) {
#define END_INSNS_DISPATCH() rb_bug("unknown insn: %"PRIdVALUE, GET_CURRENT_INSN()); }
#define NEXT_INSN() TC_DISPATCH(__NEXT_INSN__)
#define START_OF_ORIGINAL_INSN(x) start_of_##x:
#define DISPATCH_ORIGINAL_INSN(x) goto start_of_##x;
#define VM_SP_CNT(ec,sp) ((sp) - (ec)->vm_stack)
#define THROW_EXCEPTION(exc) do { ec->errinfo = (VALUE)(exc); EC_JUMP_TAG(ec, ec->tag->state); } while (0)
#define SCREG(r) (reg_##r)
#define VM_DEBUG_STACKOVERFLOW 0
#define CHECK_VM_STACK_OVERFLOW_FOR_INSN(cfp,margin) 
#define INSN_LABEL2(insn,name) INSN_LABEL_ ## insn ## _ ## name
#define INSN_LABEL(x) INSN_LABEL2(NAME_OF_CURRENT_INSN, x)
#define BIN(n) YARVINSN_##n
#define ASSERT_VM_INSTRUCTION_SIZE(array) STATIC_ASSERT(numberof_##array, numberof(array) == VM_INSTRUCTION_SIZE)
#define CONSTANT_H 
#define RB_CONST_PRIVATE_P(ce) (((ce)->flag & CONST_VISIBILITY_MASK) == CONST_PRIVATE)
#define RB_CONST_PUBLIC_P(ce) (((ce)->flag & CONST_VISIBILITY_MASK) == CONST_PUBLIC)
#define RB_CONST_DEPRECATED_P(ce) ((ce)->flag & CONST_DEPRECATED)
#define vm_check_canary(ec,sp) 
#define vm_check_frame(a,b,c,d) 
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Waddress-of-packed-member"
#pragma clang diagnostic pop
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Waddress-of-packed-member"
#pragma clang diagnostic pop
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Waddress-of-packed-member"
#pragma clang diagnostic pop
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Waddress-of-packed-member"
#pragma clang diagnostic pop
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Waddress-of-packed-member"
#pragma clang diagnostic pop
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Waddress-of-packed-member"
#pragma clang diagnostic pop
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Waddress-of-packed-member"
#pragma clang diagnostic pop
#define BUILTIN_CLASS_P(x,k) (!SPECIAL_CONST_P(x) && RBASIC_CLASS(x) == k)
#define EQ_UNREDEFINED_P(t) BASIC_OP_UNREDEFINED_P(BOP_EQ, t##_REDEFINED_OP_FLAG)
#undef BUILTIN_CLASS_P
#undef EQ_UNREDEFINED_P
#define CHECK_CMP_NAN(a,b) 
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Waddress-of-packed-member"
#pragma clang diagnostic pop
#define KW_HASH_HAS_NO_KEYS 0
#define KW_HASH_HAS_SYMBOL_KEY 1
#define KW_HASH_HAS_OTHER_KEY 2
#define KW_HASH_HAS_BOTH_KEYS 3
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Waddress-of-packed-member"
#pragma clang diagnostic pop
#define KW_SPECIFIED_BITS_MAX (32-1)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Waddress-of-packed-member"
#pragma clang diagnostic pop
#define USE_OPT_HIST 0
#define CHECK_CFP_CONSISTENCY(func) (LIKELY(vm_cfp_consistent_p(ec, reg_cfp)) ? (void)0 : rb_bug(func ": cfp consistency error (%p, %p)", (void *)reg_cfp, (void *)(ec->cfp+1)))
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Waddress-of-packed-member"
#pragma clang diagnostic pop
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Waddress-of-packed-member"
#pragma clang diagnostic pop
#define id_cmp idCmp
#undef id_cmp
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Waddress-of-packed-member"
#pragma clang diagnostic pop
#define VM_TRACE_HOOK(target_event,val) do { if ((pc_events & (target_event)) & enabled_flags) { vm_trace_hook(ec, reg_cfp, pc, pc_events, (target_event), global_hooks, local_hooks, (val)); } } while (0)
#define id_mesg idMesg
