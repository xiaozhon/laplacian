#define nx_struct struct
#define nx_union union
#define dbg(mode, format, ...) ((void)0)
#define dbg_clear(mode, format, ...) ((void)0)
#define dbg_active(mode) 0
# 150 "/usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h" 3
typedef int ptrdiff_t;
#line 212
typedef unsigned int size_t;
#line 324
typedef int wchar_t;
# 8 "/usr/local/lib/ncc/deputy_nodeputy.h"
struct __nesc_attr_nonnull {
#line 8
  int dummy;
}  ;
#line 9
struct __nesc_attr_bnd {
#line 9
  void *lo, *hi;
}  ;
#line 10
struct __nesc_attr_bnd_nok {
#line 10
  void *lo, *hi;
}  ;
#line 11
struct __nesc_attr_count {
#line 11
  int n;
}  ;
#line 12
struct __nesc_attr_count_nok {
#line 12
  int n;
}  ;
#line 13
struct __nesc_attr_one {
#line 13
  int dummy;
}  ;
#line 14
struct __nesc_attr_one_nok {
#line 14
  int dummy;
}  ;
#line 15
struct __nesc_attr_dmemset {
#line 15
  int a1, a2, a3;
}  ;
#line 16
struct __nesc_attr_dmemcpy {
#line 16
  int a1, a2, a3;
}  ;
#line 17
struct __nesc_attr_nts {
#line 17
  int dummy;
}  ;
# 37 "/usr/include/stdint.h" 3
typedef signed char int8_t;
typedef short int int16_t;
typedef int int32_t;



__extension__ 
typedef long long int int64_t;




typedef unsigned char uint8_t;
typedef unsigned short int uint16_t;

typedef unsigned int uint32_t;





__extension__ 
typedef unsigned long long int uint64_t;






typedef signed char int_least8_t;
typedef short int int_least16_t;
typedef int int_least32_t;



__extension__ 
typedef long long int int_least64_t;



typedef unsigned char uint_least8_t;
typedef unsigned short int uint_least16_t;
typedef unsigned int uint_least32_t;



__extension__ 
typedef unsigned long long int uint_least64_t;






typedef signed char int_fast8_t;





typedef int int_fast16_t;
typedef int int_fast32_t;
__extension__ 
typedef long long int int_fast64_t;



typedef unsigned char uint_fast8_t;





typedef unsigned int uint_fast16_t;
typedef unsigned int uint_fast32_t;
__extension__ 
typedef unsigned long long int uint_fast64_t;
#line 126
typedef int intptr_t;


typedef unsigned int uintptr_t;








__extension__ 
typedef long long int intmax_t;
__extension__ 
typedef unsigned long long int uintmax_t;
# 35 "/usr/include/inttypes.h" 3
typedef int __gwchar_t;
#line 292
#line 288
typedef struct __nesc_unnamed4242 {

  long long int quot;
  long long int rem;
} imaxdiv_t;
# 281 "/usr/local/lib/ncc/nesc_nx.h"
static __inline uint8_t __nesc_ntoh_uint8(const void * source)  ;




static __inline uint8_t __nesc_hton_uint8(void * target, uint8_t value)  ;
#line 303
static __inline int8_t __nesc_hton_int8(void * target, int8_t value)  ;






static __inline uint16_t __nesc_ntoh_uint16(const void * source)  ;




static __inline uint16_t __nesc_hton_uint16(void * target, uint16_t value)  ;
#line 347
static __inline uint32_t __nesc_hton_uint32(void * target, uint32_t value)  ;
#line 431
typedef struct { unsigned char nxdata[1]; } __attribute__((packed)) nx_int8_t;typedef int8_t __nesc_nxbase_nx_int8_t  ;
typedef struct { unsigned char nxdata[2]; } __attribute__((packed)) nx_int16_t;typedef int16_t __nesc_nxbase_nx_int16_t  ;
typedef struct { unsigned char nxdata[4]; } __attribute__((packed)) nx_int32_t;typedef int32_t __nesc_nxbase_nx_int32_t  ;
typedef struct { unsigned char nxdata[8]; } __attribute__((packed)) nx_int64_t;typedef int64_t __nesc_nxbase_nx_int64_t  ;
typedef struct { unsigned char nxdata[1]; } __attribute__((packed)) nx_uint8_t;typedef uint8_t __nesc_nxbase_nx_uint8_t  ;
typedef struct { unsigned char nxdata[2]; } __attribute__((packed)) nx_uint16_t;typedef uint16_t __nesc_nxbase_nx_uint16_t  ;
typedef struct { unsigned char nxdata[4]; } __attribute__((packed)) nx_uint32_t;typedef uint32_t __nesc_nxbase_nx_uint32_t  ;
typedef struct { unsigned char nxdata[8]; } __attribute__((packed)) nx_uint64_t;typedef uint64_t __nesc_nxbase_nx_uint64_t  ;


typedef struct { unsigned char nxdata[1]; } __attribute__((packed)) nxle_int8_t;typedef int8_t __nesc_nxbase_nxle_int8_t  ;
typedef struct { unsigned char nxdata[2]; } __attribute__((packed)) nxle_int16_t;typedef int16_t __nesc_nxbase_nxle_int16_t  ;
typedef struct { unsigned char nxdata[4]; } __attribute__((packed)) nxle_int32_t;typedef int32_t __nesc_nxbase_nxle_int32_t  ;
typedef struct { unsigned char nxdata[8]; } __attribute__((packed)) nxle_int64_t;typedef int64_t __nesc_nxbase_nxle_int64_t  ;
typedef struct { unsigned char nxdata[1]; } __attribute__((packed)) nxle_uint8_t;typedef uint8_t __nesc_nxbase_nxle_uint8_t  ;
typedef struct { unsigned char nxdata[2]; } __attribute__((packed)) nxle_uint16_t;typedef uint16_t __nesc_nxbase_nxle_uint16_t  ;
typedef struct { unsigned char nxdata[4]; } __attribute__((packed)) nxle_uint32_t;typedef uint32_t __nesc_nxbase_nxle_uint32_t  ;
typedef struct { unsigned char nxdata[8]; } __attribute__((packed)) nxle_uint64_t;typedef uint64_t __nesc_nxbase_nxle_uint64_t  ;
# 44 "/usr/include/string.h" 3
extern void *memcpy(void *__restrict __dest, 
const void *__restrict __src, size_t __n) 
__attribute((__leaf__)) __attribute((__nothrow__)) __attribute((__nonnull__(1, 2))) ;
#line 65
extern void *memset(void *__s, int __c, size_t __n) __attribute((__leaf__)) __attribute((__nothrow__)) __attribute((__nonnull__(1))) ;


extern int memcmp(const void *__s1, const void *__s2, size_t __n) 
__attribute((__leaf__)) __attribute((__nothrow__)) __attribute((__pure__)) __attribute((__nonnull__(1, 2))) ;
#line 128
extern char *strcpy(char *__restrict __dest, const char *__restrict __src) 
__attribute((__leaf__)) __attribute((__nothrow__)) __attribute((__nonnull__(1, 2))) ;
#line 143
extern int strcmp(const char *__s1, const char *__s2) 
__attribute((__leaf__)) __attribute((__nothrow__)) __attribute((__pure__)) __attribute((__nonnull__(1, 2))) ;
# 40 "/usr/include/xlocale.h" 3
#line 28
typedef struct __locale_struct {


  struct __locale_data *__locales[13];


  const unsigned short int *__ctype_b;
  const int *__ctype_tolower;
  const int *__ctype_toupper;


  const char *__names[13];
} *__locale_t;


typedef __locale_t locale_t;
# 262 "/usr/include/string.h"
extern char *strrchr(const char *__s, int __c) 
__attribute((__leaf__)) __attribute((__nothrow__)) __attribute((__pure__)) __attribute((__nonnull__(1))) ;
#line 399
extern size_t strlen(const char *__s) 
__attribute((__leaf__)) __attribute((__nothrow__)) __attribute((__pure__)) __attribute((__nonnull__(1))) ;
# 67 "/usr/include/i386-linux-gnu/bits/waitstatus.h" 3
union wait {

  int w_status;
  struct __nesc_unnamed4243 {


    unsigned int __w_termsig : 7;
    unsigned int __w_coredump : 1;
    unsigned int __w_retcode : 8;
    unsigned int  : 16;
  } 






  __wait_terminated;
  struct __nesc_unnamed4244 {


    unsigned int __w_stopval : 8;
    unsigned int __w_stopsig : 8;
    unsigned int  : 16;
  } 





  __wait_stopped;
};
# 72 "/usr/include/stdlib.h" 3
#line 68
typedef union __nesc_unnamed4245 {

  union wait *__uptr;
  int *__iptr;
} __WAIT_STATUS __attribute((__transparent_union__)) ;
#line 102
#line 98
typedef struct __nesc_unnamed4246 {

  int quot;
  int rem;
} div_t;







#line 106
typedef struct __nesc_unnamed4247 {

  long int quot;
  long int rem;
} ldiv_t;







__extension__ 



#line 118
typedef struct __nesc_unnamed4248 {

  long long int quot;
  long long int rem;
} lldiv_t;
#line 158
__extension__ 
#line 195
__extension__ 




__extension__ 








__extension__ 




__extension__ 
# 31 "/usr/include/i386-linux-gnu/bits/types.h" 3
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




__extension__ 
#line 47
typedef signed long long int __int64_t;
__extension__ 
#line 48
typedef unsigned long long int __uint64_t;







__extension__ 
#line 56
typedef long long int __quad_t;
__extension__ 
#line 57
typedef unsigned long long int __u_quad_t;
#line 134
__extension__ 
#line 134
typedef __u_quad_t __dev_t;
__extension__ 
#line 135
typedef unsigned int __uid_t;
__extension__ 
#line 136
typedef unsigned int __gid_t;
__extension__ 
#line 137
typedef unsigned long int __ino_t;
__extension__ 
#line 138
typedef __u_quad_t __ino64_t;
__extension__ 
#line 139
typedef unsigned int __mode_t;
__extension__ 
#line 140
typedef unsigned int __nlink_t;
__extension__ 
#line 141
typedef long int __off_t;
__extension__ 
#line 142
typedef __quad_t __off64_t;
__extension__ 
#line 143
typedef int __pid_t;
__extension__ 
#line 144
typedef struct __nesc_unnamed4249 {
#line 144
  int __val[2];
} 
#line 144
__fsid_t;
__extension__ 
#line 145
typedef long int __clock_t;
__extension__ 
#line 146
typedef unsigned long int __rlim_t;
__extension__ 
#line 147
typedef __u_quad_t __rlim64_t;
__extension__ 
#line 148
typedef unsigned int __id_t;
__extension__ 
#line 149
typedef long int __time_t;
__extension__ 
#line 150
typedef unsigned int __useconds_t;
__extension__ 
#line 151
typedef long int __suseconds_t;

__extension__ 
#line 153
typedef int __daddr_t;
__extension__ 
#line 154
typedef long int __swblk_t;
__extension__ 
#line 155
typedef int __key_t;


__extension__ 
#line 158
typedef int __clockid_t;


__extension__ 
#line 161
typedef void *__timer_t;


__extension__ 
#line 164
typedef long int __blksize_t;




__extension__ 
#line 169
typedef long int __blkcnt_t;
__extension__ 
#line 170
typedef __quad_t __blkcnt64_t;


__extension__ 
#line 173
typedef unsigned long int __fsblkcnt_t;
__extension__ 
#line 174
typedef __u_quad_t __fsblkcnt64_t;


__extension__ 
#line 177
typedef unsigned long int __fsfilcnt_t;
__extension__ 
#line 178
typedef __u_quad_t __fsfilcnt64_t;

__extension__ 
#line 180
typedef int __ssize_t;



typedef __off64_t __loff_t;
typedef __quad_t *__qaddr_t;
typedef char *__caddr_t;


__extension__ 
#line 189
typedef int __intptr_t;


__extension__ 
#line 192
typedef unsigned int __socklen_t;
# 34 "/usr/include/i386-linux-gnu/sys/types.h" 3
typedef __u_char u_char;
typedef __u_short u_short;
typedef __u_int u_int;
typedef __u_long u_long;
typedef __quad_t quad_t;
typedef __u_quad_t u_quad_t;
typedef __fsid_t fsid_t;




typedef __loff_t loff_t;



typedef __ino_t ino_t;
#line 61
typedef __dev_t dev_t;




typedef __gid_t gid_t;




typedef __mode_t mode_t;




typedef __nlink_t nlink_t;




typedef __uid_t uid_t;





typedef __off_t off_t;
#line 99
typedef __pid_t pid_t;





typedef __id_t id_t;




typedef __ssize_t ssize_t;





typedef __daddr_t daddr_t;
typedef __caddr_t caddr_t;





typedef __key_t key_t;
# 60 "/usr/include/time.h" 3
typedef __clock_t clock_t;
#line 76
typedef __time_t time_t;
#line 92
typedef __clockid_t clockid_t;
#line 104
typedef __timer_t timer_t;
# 151 "/usr/include/i386-linux-gnu/sys/types.h" 3
typedef unsigned long int ulong;
typedef unsigned short int ushort;
typedef unsigned int uint;
#line 201
typedef unsigned int u_int8_t __attribute((__mode__(__QI__))) ;
typedef unsigned int u_int16_t __attribute((__mode__(__HI__))) ;
typedef unsigned int u_int32_t __attribute((__mode__(__SI__))) ;
typedef unsigned int u_int64_t __attribute((__mode__(__DI__))) ;

typedef int register_t __attribute((__mode__(__word__))) ;
# 24 "/usr/include/i386-linux-gnu/bits/sigset.h" 3
typedef int __sig_atomic_t;







#line 29
typedef struct __nesc_unnamed4250 {

  unsigned long int __val[1024 / (8 * sizeof(unsigned long int ))];
} __sigset_t;
# 38 "/usr/include/i386-linux-gnu/sys/select.h" 3
typedef __sigset_t sigset_t;
# 120 "/usr/include/time.h" 3
struct timespec {

  __time_t tv_sec;
  long int tv_nsec;
};
# 31 "/usr/include/i386-linux-gnu/bits/time.h" 3
struct timeval {

  __time_t tv_sec;
  __suseconds_t tv_usec;
};
# 49 "/usr/include/i386-linux-gnu/sys/select.h" 3
typedef __suseconds_t suseconds_t;





typedef long int __fd_mask;
#line 76
#line 65
typedef struct __nesc_unnamed4251 {







  __fd_mask __fds_bits[1024 / (8 * (int )sizeof(__fd_mask ))];
} 

fd_set;






typedef __fd_mask fd_mask;
# 32 "/usr/include/i386-linux-gnu/sys/sysmacros.h" 3
__extension__ 


__extension__ 


__extension__ 
# 229 "/usr/include/i386-linux-gnu/sys/types.h" 3
typedef __blksize_t blksize_t;






typedef __blkcnt_t blkcnt_t;



typedef __fsblkcnt_t fsblkcnt_t;



typedef __fsfilcnt_t fsfilcnt_t;
# 36 "/usr/include/i386-linux-gnu/bits/pthreadtypes.h" 3
typedef unsigned long int pthread_t;






#line 39
typedef union __nesc_unnamed4252 {

  char __size[36];
  long int __align;
} pthread_attr_t;





#line 46
typedef struct __pthread_internal_slist {

  struct __pthread_internal_slist *__next;
} __pthread_slist_t;
#line 73
#line 54
typedef union __nesc_unnamed4253 {

  struct __pthread_mutex_s {

    int __lock;
    unsigned int __count;
    int __owner;


    int __kind;
    unsigned int __nusers;
    __extension__ union  {

      int __spins;
      __pthread_slist_t __list;
    } ;
  } __data;
  char __size[24];
  long int __align;
} pthread_mutex_t;





#line 75
typedef union __nesc_unnamed4254 {

  char __size[4];
  long int __align;
} pthread_mutexattr_t;
#line 99
#line 84
typedef union __nesc_unnamed4255 {

  struct __nesc_unnamed4256 {

    int __lock;
    unsigned int __futex;
    __extension__ unsigned long long int __total_seq;
    __extension__ unsigned long long int __wakeup_seq;
    __extension__ unsigned long long int __woken_seq;
    void *__mutex;
    unsigned int __nwaiters;
    unsigned int __broadcast_seq;
  } __data;
  char __size[48];
  __extension__ long long int __align;
} pthread_cond_t;





#line 101
typedef union __nesc_unnamed4257 {

  char __size[4];
  long int __align;
} pthread_condattr_t;



typedef unsigned int pthread_key_t;



typedef int pthread_once_t;
#line 139
#line 119
typedef union __nesc_unnamed4258 {

  struct __nesc_unnamed4259 {

    int __lock;
    unsigned int __nr_readers;
    unsigned int __readers_wakeup;
    unsigned int __writer_wakeup;
    unsigned int __nr_readers_queued;
    unsigned int __nr_writers_queued;


    unsigned char __flags;
    unsigned char __shared;
    unsigned char __pad1;
    unsigned char __pad2;
    int __writer;
  } __data;
  char __size[32];
  long int __align;
} pthread_rwlock_t;





#line 141
typedef union __nesc_unnamed4260 {

  char __size[8];
  long int __align;
} pthread_rwlockattr_t;





typedef volatile int pthread_spinlock_t;








#line 156
typedef union __nesc_unnamed4261 {

  char __size[20];
  long int __align;
} pthread_barrier_t;





#line 162
typedef union __nesc_unnamed4262 {

  char __size[4];
  int __align;
} pthread_barrierattr_t;
# 349 "/usr/include/stdlib.h" 3
struct random_data {

  int32_t *fptr;
  int32_t *rptr;
  int32_t *state;
  int rand_type;
  int rand_deg;
  int rand_sep;
  int32_t *end_ptr;
};
#line 418
struct drand48_data {

  unsigned short int __x[3];
  unsigned short int __old_x[3];
  unsigned short int __c;
  unsigned short int __init;
  unsigned long long int __a;
};
#line 471
extern void *malloc(size_t __size) __attribute((__leaf__)) __attribute((__nothrow__)) __attribute((__malloc__)) ;
#line 488
extern void free(void *__ptr) __attribute((__leaf__)) __attribute((__nothrow__)) ;
#line 742
typedef int (*__compar_fn_t)(const void *arg_0x403642a8, const void *arg_0x40364440);
#line 776
__extension__ 
#line 793
__extension__ 
# 36 "/usr/include/i386-linux-gnu/bits/mathdef.h" 3
typedef long double float_t;

typedef long double double_t;
# 110 "/usr/include/i386-linux-gnu/bits/mathcalls.h" 3
extern double log(double __x) __attribute((__leaf__)) __attribute((__nothrow__)) ;
#line 155
extern double pow(double __x, double __y) __attribute((__leaf__)) __attribute((__nothrow__)) ;


extern double sqrt(double __x) __attribute((__leaf__)) __attribute((__nothrow__)) ;
#line 186
extern double floor(double __x) __attribute((__leaf__)) __attribute((__nothrow__)) __attribute((const)) ;
#line 252
extern double erfc(double arg_0x403b35c0) __attribute((__leaf__)) __attribute((__nothrow__)) ;
# 203 "/usr/include/math.h" 3
enum __nesc_unnamed4263 {

  FP_NAN, 

  FP_INFINITE, 

  FP_ZERO, 

  FP_SUBNORMAL, 

  FP_NORMAL
};
#line 303
#line 296
typedef enum __nesc_unnamed4264 {

  _IEEE_ = -1, 
  _SVID_, 
  _XOPEN_, 
  _POSIX_, 
  _ISOC_
} _LIB_VERSION_TYPE;
#line 321
struct exception {


  int type;
  char *name;
  double arg1;
  double arg2;
  double retval;
};
# 48 "/usr/include/ctype.h" 3
enum __nesc_unnamed4265 {

  _ISupper = 0 < 8 ? (1 << 0) << 8 : (1 << 0) >> 8, 
  _ISlower = 1 < 8 ? (1 << 1) << 8 : (1 << 1) >> 8, 
  _ISalpha = 2 < 8 ? (1 << 2) << 8 : (1 << 2) >> 8, 
  _ISdigit = 3 < 8 ? (1 << 3) << 8 : (1 << 3) >> 8, 
  _ISxdigit = 4 < 8 ? (1 << 4) << 8 : (1 << 4) >> 8, 
  _ISspace = 5 < 8 ? (1 << 5) << 8 : (1 << 5) >> 8, 
  _ISprint = 6 < 8 ? (1 << 6) << 8 : (1 << 6) >> 8, 
  _ISgraph = 7 < 8 ? (1 << 7) << 8 : (1 << 7) >> 8, 
  _ISblank = 8 < 8 ? (1 << 8) << 8 : (1 << 8) >> 8, 
  _IScntrl = 9 < 8 ? (1 << 9) << 8 : (1 << 9) >> 8, 
  _ISpunct = 10 < 8 ? (1 << 10) << 8 : (1 << 10) >> 8, 
  _ISalnum = 11 < 8 ? (1 << 11) << 8 : (1 << 11) >> 8
};
# 45 "/usr/include/stdio.h" 3
struct _IO_FILE;



typedef struct _IO_FILE FILE;
#line 65
typedef struct _IO_FILE __FILE;
# 95 "/usr/include/wchar.h" 3
#line 83
typedef struct __nesc_unnamed4266 {

  int __count;
  union __nesc_unnamed4267 {


    unsigned int __wch;



    char __wchb[4];
  } __value;
} __mbstate_t;
# 26 "/usr/include/_G_config.h" 3
#line 22
typedef struct __nesc_unnamed4268 {

  __off_t __pos;
  __mbstate_t __state;
} _G_fpos_t;




#line 27
typedef struct __nesc_unnamed4269 {

  __off64_t __pos;
  __mbstate_t __state;
} _G_fpos64_t;
#line 53
typedef int _G_int16_t __attribute((__mode__(__HI__))) ;
typedef int _G_int32_t __attribute((__mode__(__SI__))) ;
typedef unsigned int _G_uint16_t __attribute((__mode__(__HI__))) ;
typedef unsigned int _G_uint32_t __attribute((__mode__(__SI__))) ;
# 40 "/usr/lib/gcc/i686-linux-gnu/4.6/include/stdarg.h" 3
typedef __builtin_va_list __gnuc_va_list;
# 172 "/usr/include/libio.h" 3
struct _IO_jump_t;
#line 172
struct _IO_FILE;









typedef void _IO_lock_t;





struct _IO_marker {
  struct _IO_marker *_next;
  struct _IO_FILE *_sbuf;



  int _pos;
};
#line 208
enum __codecvt_result {

  __codecvt_ok, 
  __codecvt_partial, 
  __codecvt_error, 
  __codecvt_noconv
};
#line 273
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








  void *__pad1;
  void *__pad2;
  void *__pad3;
  void *__pad4;
  size_t __pad5;

  int _mode;

  char _unused2[15 * sizeof(int ) - 4 * sizeof(void *) - sizeof(size_t )];
};



typedef struct _IO_FILE _IO_FILE;


struct _IO_FILE_plus;

struct _IO_FILE_plus;
struct _IO_FILE_plus;
struct _IO_FILE_plus;
#line 366
typedef __ssize_t __io_read_fn(void *__cookie, char *__buf, size_t __nbytes);







typedef __ssize_t __io_write_fn(void *__cookie, const char *__buf, 
size_t __n);







typedef int __io_seek_fn(void *__cookie, __off64_t *__pos, int __w);


typedef int __io_close_fn(void *__cookie);
# 80 "/usr/include/stdio.h" 3
typedef __gnuc_va_list va_list;
#line 111
typedef _G_fpos_t fpos_t;
#line 169
struct _IO_FILE;
struct _IO_FILE;
struct _IO_FILE;
#line 243
extern int fflush(FILE *__stream);
#line 307
extern FILE *fdopen(int __fd, const char *__modes) __attribute((__leaf__)) __attribute((__nothrow__)) ;
#line 357
extern int fprintf(FILE *__restrict __stream, 
const char *__restrict __format, ...);




extern int printf(const char *__restrict __format, ...);








extern int vfprintf(FILE *__restrict __s, const char *__restrict __format, 
__gnuc_va_list __arg);
#line 387
extern int snprintf(char *__restrict __s, size_t __maxlen, 
const char *__restrict __format, ...) 
__attribute((__nothrow__)) __attribute((__format__(__printf__, 3, 4))) ;
#line 855
extern int fileno(FILE *__stream) __attribute((__leaf__)) __attribute((__nothrow__)) ;
# 65 "/opt/tinyos-2.1.2/tos/lib/tossim/tos.h"
typedef uint8_t bool;










enum __nesc_unnamed4270 {
#line 76
  FALSE = 0, TRUE = 1
};
extern uint16_t TOS_NODE_ID;
# 51 "/opt/tinyos-2.1.2/tos/lib/tossim/sim_tossim.h"
typedef long long int sim_time_t;

void sim_init();

void sim_end();

void sim_random_seed(int seed);
int sim_random();

sim_time_t sim_time();
void sim_set_time(sim_time_t time);
sim_time_t sim_ticks_per_sec();

unsigned long sim_node();
void sim_set_node(unsigned long node);

int sim_print_time(char *buf, int bufLen, sim_time_t time);
int sim_print_now(char *buf, int bufLen);
char *sim_time_string();

void sim_add_channel(char *channel, FILE *file);
bool sim_remove_channel(char *channel, FILE *file);

bool sim_run_next_event();
# 50 "/opt/tinyos-2.1.2/tos/lib/tossim/sim_event_queue.h"
struct sim_event;
typedef struct sim_event sim_event_t;

struct sim_event {
  sim_time_t time;
  unsigned long mote;
  bool force;

  bool cancelled;
  void *data;

  void (*handle)(sim_event_t *e);
  void (*cleanup)(sim_event_t *e);
};

static sim_event_t *sim_queue_allocate_event();

void sim_queue_init();
void sim_queue_insert(sim_event_t *event);
bool sim_queue_is_empty();
long long int sim_queue_peek_time();
sim_event_t *sim_queue_pop();

void sim_queue_cleanup_none(sim_event_t *e);
void sim_queue_cleanup_event(sim_event_t *e);
void sim_queue_cleanup_data(sim_event_t *e);
void sim_queue_cleanup_total(sim_event_t *e);
# 53 "/opt/tinyos-2.1.2/tos/lib/tossim/sim_mote.h"
long long int sim_mote_euid(int mote);
void sim_mote_set_euid(int mote, long long int euid);

long long int sim_mote_start_time(int mote);
void sim_mote_set_start_time(int mote, long long int t);

bool sim_mote_is_on(int mote);
void sim_mote_turn_on(int mote);
void sim_mote_turn_off(int mote);
int sim_mote_get_variable_info(int mote, char *name, void **addr, size_t *len);
void sim_mote_enqueue_boot_event(int mote);
# 65 "/opt/tinyos-2.1.2/tos/lib/tossim/sim_log.h"
static inline void sim_log_init();
static inline void sim_log_add_channel(char *output, FILE *file);
static inline bool sim_log_remove_channel(char *output, FILE *file);
static void sim_log_commit_change();

static void sim_log_debug(uint16_t id, char *string, const char *format, ...);
static void sim_log_error(uint16_t id, char *string, const char *format, ...);
static void sim_log_debug_clear(uint16_t id, char *string, const char *format, ...);
# 97 "/opt/tinyos-2.1.2/tos/lib/tossim/tos.h"
struct __nesc_attr_atmostonce {
};
#line 98
struct __nesc_attr_atleastonce {
};
#line 99
struct __nesc_attr_exactlyonce {
};
# 9 "/opt/tinyos-2.1.2/tos/lib/tossim/hashtable.h"
struct hashtable;
typedef struct hashtable hashtable_t;
#line 78
struct hashtable *
create_hashtable(unsigned int minsize, 
unsigned int (*hashfunction)(void *arg_0x4050f320), 
int (*key_eq_fn)(void *arg_0x4050f768, void *arg_0x4050f8e0));
#line 103
#line 102
int 
hashtable_insert(struct hashtable *h, void *k, void *v);
#line 120
void *
hashtable_search(struct hashtable *h, void *k);
# 47 "/opt/tinyos-2.1.2/tos/lib/tossim/sim_log.c"
enum __nesc_unnamed4271 {
  DEFAULT_CHANNEL_SIZE = 8
};




#line 51
typedef struct sim_log_output {
  int num;
  FILE **files;
} sim_log_output_t;






#line 56
typedef struct sim_log_channel {
  const char *name;
  int numOutputs;
  int size;
  FILE **outputs;
} sim_log_channel_t;

enum __nesc_unnamed4272 {
  SIM_LOG_OUTPUT_COUNT = 306U
};

sim_log_output_t outputs[SIM_LOG_OUTPUT_COUNT];
struct hashtable *channelTable = (void *)0;


inline static unsigned int sim_log_hash(void *key);
inline static int sim_log_eq(void *key1, void *key2);
#line 84
static void fillInOutput(int id, char *name);
#line 159
static inline void sim_log_init();
#line 172
static inline void sim_log_add_channel(char *name, FILE *file);
#line 212
static inline bool sim_log_remove_channel(char *output, FILE *file);
#line 234
static void sim_log_commit_change();
#line 246
static void sim_log_debug(uint16_t id, char *string, const char *format, ...);
#line 261
static void sim_log_error(uint16_t id, char *string, const char *format, ...);
#line 276
static void sim_log_debug_clear(uint16_t id, char *string, const char *format, ...);
#line 306
inline static unsigned int sim_log_hash(void *key);










inline static int sim_log_eq(void *key1, void *key2);
# 65 "/opt/tinyos-2.1.2/tos/lib/tossim/heap.h"
#line 61
typedef struct heap {
  int size;
  void *data;
  int private_size;
} heap_t;

static inline void init_heap(heap_t *heap);

static inline int heap_is_empty(heap_t *heap);

static inline long long int heap_get_min_key(heap_t *heap);

static void *heap_pop_min_data(heap_t *heap, long long int *key);
static inline void heap_insert(heap_t *heap, void *data, long long int key);
# 58 "/opt/tinyos-2.1.2/tos/lib/tossim/heap.c"
const int STARTING_SIZE = 511;






#line 62
typedef struct node {
  void *data;
  long long int key;
} node_t;

static void down_heap(heap_t *heap, int findex);
static void up_heap(heap_t *heap, int findex);
static void swap(node_t *first, node_t *second);








static inline void init_heap(heap_t *heap);









static inline int is_empty(heap_t *heap);



static inline int heap_is_empty(heap_t *heap);



static inline long long int heap_get_min_key(heap_t *heap);
#line 114
static void *heap_pop_min_data(heap_t *heap, long long int *key);
#line 130
static inline void expand_heap(heap_t *heap);
#line 144
static inline void heap_insert(heap_t *heap, void *data, long long int key);
#line 158
static void swap(node_t *first, node_t *second);
#line 171
static void down_heap(heap_t *heap, int findex);
#line 197
static void up_heap(heap_t *heap, int findex);
# 44 "/opt/tinyos-2.1.2/tos/lib/tossim/sim_event_queue.c"
static heap_t eventHeap;

void sim_queue_init()   ;



void sim_queue_insert(sim_event_t *event)   ;




sim_event_t *sim_queue_pop()   ;




bool sim_queue_is_empty()   ;



long long int sim_queue_peek_time()   ;









void sim_queue_cleanup_none(sim_event_t *event)   ;




void sim_queue_cleanup_event(sim_event_t *event)   ;




void sim_queue_cleanup_data(sim_event_t *event)   ;





void sim_queue_cleanup_total(sim_event_t *event)   ;






static sim_event_t *sim_queue_allocate_event();
# 57 "/usr/include/i386-linux-gnu/sys/time.h" 3
struct timezone {

  int tz_minuteswest;
  int tz_dsttime;
};

typedef struct timezone *__restrict __timezone_ptr_t;









extern int gettimeofday(struct timeval *__restrict __tv, 
__timezone_ptr_t __tz) __attribute((__leaf__)) __attribute((__nothrow__)) __attribute((__nonnull__(1))) ;
#line 93
enum __itimer_which {


  ITIMER_REAL = 0, 


  ITIMER_VIRTUAL = 1, 



  ITIMER_PROF = 2
};




struct itimerval {


  struct timeval it_interval;

  struct timeval it_value;
};






typedef int __itimer_which_t;
# 51 "/opt/tinyos-2.1.2/tos/lib/tossim/sim_noise.h"
enum __nesc_unnamed4273 {
  NOISE_MIN = -115, 
  NOISE_MAX = -5, 
  NOISE_MIN_QUANTIZE = -115, 
  NOISE_QUANTIZE_INTERVAL = 5, 
  NOISE_BIN_SIZE = (NOISE_MAX - NOISE_MIN) / NOISE_QUANTIZE_INTERVAL + 1, 
  NOISE_HISTORY = 20, 
  NOISE_DEFAULT_ELEMENT_SIZE = 8, 
  NOISE_HASHTABLE_SIZE = 128, 
  NOISE_MIN_TRACE = 128, 
  NOISE_NUM_VALUES = NOISE_MAX - NOISE_MIN + 1
};








#line 64
typedef struct sim_noise_hash_t {
  char key[NOISE_HISTORY];
  int numElements;
  int size;
  char *elements;
  char flag;
  float dist[NOISE_NUM_VALUES];
} sim_noise_hash_t;
#line 83
#line 73
typedef struct sim_noise_node_t {
  char key[NOISE_HISTORY];
  char freqKey[NOISE_HISTORY];
  char lastNoiseVal;
  uint32_t noiseGenTime;
  struct hashtable *noiseTable;
  char *noiseTrace;
  uint32_t noiseTraceLen;
  uint32_t noiseTraceIndex;
  bool generated;
} sim_noise_node_t;

void sim_noise_init();

char sim_noise_generate(uint16_t node_id, uint32_t cur_t);
void sim_noise_trace_add(uint16_t node_id, char val);
void sim_noise_create_model(uint16_t node_id);
# 51 "/opt/tinyos-2.1.2/tos/lib/tossim/sim_tossim.c"
static sim_time_t sim_ticks;
static unsigned long current_node;
static int sim_seed;

static int __nesc_nido_resolve(int mote, char *varname, uintptr_t *addr, size_t *size);

void sim_init()   ;
#line 80
void sim_end()   ;





int sim_random()   ;
#line 102
void sim_random_seed(int seed)   ;







sim_time_t sim_time()   ;


void sim_set_time(sim_time_t t)   ;



sim_time_t sim_ticks_per_sec()   ;



unsigned long sim_node()   ;


void sim_set_node(unsigned long node)   ;




bool sim_run_next_event()   ;
#line 156
int sim_print_time(char *buf, int len, sim_time_t ftime)   ;
#line 179
int sim_print_now(char *buf, int len)   ;



char simTimeBuf[128];
char *sim_time_string()   ;




void sim_add_channel(char *channel, FILE *file)   ;



bool sim_remove_channel(char *channel, FILE *file)   ;
# 99 "/opt/tinyos-2.1.2/tos/lib/tossim/sim_csma.h"
int sim_csma_init_high();
int sim_csma_init_low();
int sim_csma_high();
int sim_csma_low();
int sim_csma_symbols_per_sec();
int sim_csma_bits_per_symbol();
int sim_csma_preamble_length();
int sim_csma_exponent_base();
int sim_csma_max_iterations();
int sim_csma_min_free_samples();
int sim_csma_rxtx_delay();
int sim_csma_ack_time();

void sim_csma_set_init_high(int val);
void sim_csma_set_init_low(int val);
void sim_csma_set_high(int val);
void sim_csma_set_low(int val);
void sim_csma_set_symbols_per_sec(int val);
void sim_csma_set_bits_per_symbol(int val);
void sim_csma_set_preamble_length(int val);
void sim_csma_set_exponent_base(int val);
void sim_csma_set_max_iterations(int val);
void sim_csma_set_min_free_samples(int val);
void sim_csma_set_rxtx_delay(int val);
void sim_csma_set_ack_time(int val);
# 44 "/opt/tinyos-2.1.2/tos/lib/tossim/sim_csma.c"
int csmaInitHigh = 640;
int csmaInitLow = 20;
int csmaHigh = 160;
int csmaLow = 20;
int csmaSymbolsPerSec = 65536;
int csmaBitsPerSymbol = 4;
int csmaPreambleLength = 12;
int csmaExponentBase = 1;
int csmaMaxIterations = 0;
int csmaMinFreeSamples = 1;
int csmaRxTxDelay = 11;
int csmaAckTime = 34;

int sim_csma_init_high()   ;


int sim_csma_init_low()   ;


int sim_csma_high()   ;


int sim_csma_low()   ;


int sim_csma_symbols_per_sec()   ;


int sim_csma_bits_per_symbol()   ;


int sim_csma_preamble_length()   ;


int sim_csma_exponent_base()   ;


int sim_csma_max_iterations()   ;


int sim_csma_min_free_samples()   ;


int sim_csma_rxtx_delay()   ;


int sim_csma_ack_time()   ;





void sim_csma_set_init_high(int val)   ;


void sim_csma_set_init_low(int val)   ;


void sim_csma_set_high(int val)   ;


void sim_csma_set_low(int val)   ;


void sim_csma_set_symbols_per_sec(int val)   ;


void sim_csma_set_bits_per_symbol(int val)   ;


void sim_csma_set_preamble_length(int val)   ;


void sim_csma_set_exponent_base(int val)   ;


void sim_csma_set_max_iterations(int val)   ;


void sim_csma_set_min_free_samples(int val)   ;


void sim_csma_set_rxtx_delay(int val)   ;


void sim_csma_set_ack_time(int val)   ;
# 57 "/opt/tinyos-2.1.2/tos/lib/tossim/sim_gain.h"
#line 53
typedef struct gain_entry {
  int mote;
  double gain;
  struct gain_entry *next;
} gain_entry_t;

void sim_gain_add(int src, int dest, double gain);
double sim_gain_value(int src, int dest);
bool sim_gain_connected(int src, int dest);
void sim_gain_remove(int src, int dest);
void sim_gain_set_noise_floor(int node, double mean, double range);
double sim_gain_sample_noise(int node);



void sim_gain_set_sensitivity(double value);
double sim_gain_sensitivity();

gain_entry_t *sim_gain_first(int src);
gain_entry_t *sim_gain_next(gain_entry_t *e);
# 6 "/opt/tinyos-2.1.2/tos/lib/tossim/sim_gain.c"
#line 3
typedef struct sim_gain_noise {
  double mean;
  double range;
} sim_gain_noise_t;


gain_entry_t *connectivity[1000 + 1];
sim_gain_noise_t localNoise[1000 + 1];
double sensitivity = 4.0;

static inline gain_entry_t *sim_gain_allocate_link(int mote);
void sim_gain_deallocate_link(gain_entry_t *linkToDelete);

gain_entry_t *sim_gain_first(int src)   ;






gain_entry_t *sim_gain_next(gain_entry_t *currentLink)   ;



void sim_gain_add(int src, int dest, double gain)   ;
#line 55
double sim_gain_value(int src, int dest)   ;
#line 73
bool sim_gain_connected(int src, int dest)   ;
#line 89
void sim_gain_remove(int src, int dest)   ;
#line 124
void sim_gain_set_noise_floor(int node, double mean, double range)   ;
#line 148
double sim_gain_sample_noise(int node)   ;
#line 161
static inline gain_entry_t *sim_gain_allocate_link(int mote);







void sim_gain_deallocate_link(gain_entry_t *linkToDelete)   ;



void sim_gain_set_sensitivity(double s)   ;



double sim_gain_sensitivity()   ;
# 39 "/opt/tinyos-2.1.2/tos/lib/tossim/randomlib.c"
static double randU[97];
#line 39
static double randC;
#line 39
static double randCD;
#line 39
static double randCM;
static int i97;
#line 40
static int j97;
static int test = FALSE;
#line 55
static inline void RandomInitialise(int ij, int kl);
#line 103
static double RandomUniform(void );
# 133 "/usr/include/time.h" 3
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
#line 161
struct itimerspec {

  struct timespec it_interval;
  struct timespec it_value;
};


struct sigevent;
# 233 "/usr/include/time.h"
struct tm;



struct tm;





struct tm;




struct tm;
# 46 "/opt/tinyos-2.1.2/tos/lib/tossim/randomlib.h"
static inline void RandomInitialise(int arg_0x40644558, int arg_0x406446b0);
static double RandomUniform(void );
# 51 "/opt/tinyos-2.1.2/tos/lib/tossim/sim_noise.c"
int numCase1 = 0;
int numCase2 = 0;
int numTotal = 0;


uint32_t FreqKeyNum = 0;

sim_noise_node_t noiseData[1000];

inline static unsigned int sim_noise_hash(void *key);
inline static int sim_noise_eq(void *key1, void *key2);

void makeNoiseModel(uint16_t node_id);
void makePmfDistr(uint16_t node_id);
uint8_t search_bin_num(char noise);

void sim_noise_init()   ;
#line 84
void sim_noise_create_model(uint16_t node_id)   ;
#line 97
void sim_noise_trace_add(uint16_t node_id, char noiseVal)   ;
#line 113
uint8_t search_bin_num(char noise)   ;









char search_noise_from_bin_num(int i)   ;






inline static unsigned int sim_noise_hash(void *key);









inline static int sim_noise_eq(void *key1, void *key2);



void sim_noise_add(uint16_t node_id, char noise)   ;
#line 192
void sim_noise_dist(uint16_t node_id)   ;
#line 245
void arrangeKey(uint16_t node_id)   ;









void makePmfDistr(uint16_t node_id)   ;
#line 283
int dummy;
static inline void sim_noise_alarm();



char sim_noise_gen(uint16_t node_id)   ;
#line 364
char sim_noise_generate(uint16_t node_id, uint32_t cur_t)   ;
#line 419
void makeNoiseModel(uint16_t node_id)   ;
# 59 "/opt/tinyos-2.1.2/tos/lib/tossim/sim_packet.h"
typedef struct sim_packet {
} 
#line 59
sim_packet_t;

void sim_packet_set_source(sim_packet_t *msg, uint16_t src);
uint16_t sim_packet_source(sim_packet_t *msg);

void sim_packet_set_destination(sim_packet_t *msg, uint16_t dest);
uint16_t sim_packet_destination(sim_packet_t *msg);

void sim_packet_set_length(sim_packet_t *msg, uint8_t len);
uint16_t sim_packet_length(sim_packet_t *msg);

void sim_packet_set_type(sim_packet_t *msg, uint8_t type);
uint8_t sim_packet_type(sim_packet_t *msg);

uint8_t *sim_packet_data(sim_packet_t *msg);
void sim_packet_set_strength(sim_packet_t *msg, uint16_t str);

void sim_packet_deliver(int node, sim_packet_t *msg, sim_time_t t);
uint8_t sim_packet_max_length(sim_packet_t *msg);

sim_packet_t *sim_packet_allocate();
void sim_packet_free(sim_packet_t *m);
# 6 "/opt/tinyos-2.1.2/tos/types/AM.h"
typedef nx_uint8_t nx_am_id_t;
typedef nx_uint8_t nx_am_group_t;
typedef nx_uint16_t nx_am_addr_t;

typedef uint8_t am_id_t;
typedef uint8_t am_group_t;
typedef uint16_t am_addr_t;

enum __nesc_unnamed4274 {
  AM_BROADCAST_ADDR = 0xffff
};









enum __nesc_unnamed4275 {
  TOS_AM_GROUP = 0x22, 
  TOS_AM_ADDRESS = 1
};
# 12 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimRadioMsg.h"
#line 6
typedef nx_struct tossim_header {
  nx_am_addr_t dest;
  nx_am_addr_t src;
  nx_uint8_t length;
  nx_am_group_t group;
  nx_am_id_t type;
} __attribute__((packed)) tossim_header_t;



#line 14
typedef nx_struct tossim_footer {
  nxle_uint16_t crc;
} __attribute__((packed)) tossim_footer_t;





#line 18
typedef nx_struct tossim_metadata {
  nx_int8_t strength;
  nx_uint8_t ack;
  nx_uint16_t time;
} __attribute__((packed)) tossim_metadata_t;
# 83 "/opt/tinyos-2.1.2/tos/lib/serial/Serial.h"
typedef uint8_t uart_id_t;



enum __nesc_unnamed4276 {
  HDLC_FLAG_BYTE = 0x7e, 
  HDLC_CTLESC_BYTE = 0x7d
};



enum __nesc_unnamed4277 {
  TOS_SERIAL_ACTIVE_MESSAGE_ID = 0, 
  TOS_SERIAL_CC1000_ID = 1, 
  TOS_SERIAL_802_15_4_ID = 2, 
  TOS_SERIAL_UNKNOWN_ID = 255
};


enum __nesc_unnamed4278 {
  SERIAL_PROTO_ACK = 67, 
  SERIAL_PROTO_PACKET_ACK = 68, 
  SERIAL_PROTO_PACKET_NOACK = 69, 
  SERIAL_PROTO_PACKET_UNKNOWN = 255
};
#line 121
#line 109
typedef struct radio_stats {
  uint8_t version;
  uint8_t flags;
  uint8_t reserved;
  uint8_t platform;
  uint16_t MTU;
  uint16_t radio_crc_fail;
  uint16_t radio_queue_drops;
  uint16_t serial_crc_fail;
  uint16_t serial_tx_fail;
  uint16_t serial_short_packets;
  uint16_t serial_proto_drops;
} radio_stats_t;







#line 123
typedef nx_struct serial_header {
  nx_am_addr_t dest;
  nx_am_addr_t src;
  nx_uint8_t length;
  nx_am_group_t group;
  nx_am_id_t type;
} __attribute__((packed)) serial_header_t;




#line 131
typedef nx_struct serial_packet {
  serial_header_t header;
  nx_uint8_t data[];
} __attribute__((packed)) serial_packet_t;



#line 136
typedef nx_struct serial_metadata {
  nx_uint8_t ack;
} __attribute__((packed)) serial_metadata_t;
# 53 "/opt/tinyos-2.1.2/tos/lib/tossim/platform_message.h"
#line 50
typedef union message_header {
  tossim_header_t tossim;
  serial_header_t serial;
} message_header_t;



#line 55
typedef union message_footer {
  tossim_footer_t tossim;
} message_footer_t;



#line 59
typedef union message_metadata {
  tossim_metadata_t tossim;
} message_metadata_t;
# 19 "/opt/tinyos-2.1.2/tos/types/message.h"
#line 14
typedef nx_struct message_t {
  nx_uint8_t header[sizeof(message_header_t )];
  nx_uint8_t data[100];
  nx_uint8_t footer[sizeof(message_footer_t )];
  nx_uint8_t metadata[sizeof(message_metadata_t )];
} __attribute__((packed)) message_t;
# 48 "/opt/tinyos-2.1.2/tos/lib/tossim/sim_packet.c"
void active_message_deliver(int node, message_t *m, sim_time_t t);

inline static tossim_header_t *getHeader(message_t *msg);



void sim_packet_set_source(sim_packet_t *msg, uint16_t src)   ;




uint16_t sim_packet_source(sim_packet_t *msg)   ;




void sim_packet_set_destination(sim_packet_t *msg, uint16_t dest)   ;




uint16_t sim_packet_destination(sim_packet_t *msg)   ;




void sim_packet_set_length(sim_packet_t *msg, uint8_t length)   ;



uint16_t sim_packet_length(sim_packet_t *msg)   ;




void sim_packet_set_type(sim_packet_t *msg, uint8_t type)   ;




uint8_t sim_packet_type(sim_packet_t *msg)   ;




uint8_t *sim_packet_data(sim_packet_t *p)   ;



void sim_packet_set_strength(sim_packet_t *p, uint16_t str)   ;




void sim_packet_deliver(int node, sim_packet_t *msg, sim_time_t t)   ;







uint8_t sim_packet_max_length(sim_packet_t *msg)   ;



sim_packet_t *sim_packet_allocate()   ;



void sim_packet_free(sim_packet_t *p)   ;
# 51 "/opt/tinyos-2.1.2/tos/types/TinyError.h"
enum __nesc_unnamed4279 {
  SUCCESS = 0, 
  FAIL = 1, 
  ESIZE = 2, 
  ECANCEL = 3, 
  EOFF = 4, 
  EBUSY = 5, 
  EINVAL = 6, 
  ERETRY = 7, 
  ERESERVE = 8, 
  EALREADY = 9, 
  ENOMEM = 10, 
  ENOACK = 11, 
  ELAST = 11
};

typedef uint8_t error_t  ;

static inline error_t ecombine(error_t r1, error_t r2)  ;
# 5 "LapTest.h"
enum __nesc_unnamed4280 {
  CTP_DATA_MSG = 0xDD
};


enum __nesc_unnamed4281 {
  MAX_PATH_LEN = 30, 

  SINK_ADDR = 0, 
  DEF_INTERVAL = 1024 * 60
};






#line 18
typedef nx_struct DataMsg {
  nx_uint16_t parent;
  nx_uint16_t data;
  nx_uint16_t path[MAX_PATH_LEN];
} __attribute__((packed)) data_msg_t;
# 41 "/opt/tinyos-2.1.2/tos/lib/timer/Timer.h"
typedef struct __nesc_unnamed4282 {
#line 41
  int notUsed;
} 
#line 41
TSecond;
typedef struct __nesc_unnamed4283 {
#line 42
  int notUsed;
} 
#line 42
TMilli;
typedef struct __nesc_unnamed4284 {
#line 43
  int notUsed;
} 
#line 43
T32khz;
typedef struct __nesc_unnamed4285 {
#line 44
  int notUsed;
} 
#line 44
TMicro;
# 43 "/opt/tinyos-2.1.2/tos/types/Leds.h"
enum __nesc_unnamed4286 {
  LEDS_LED0 = 1 << 0, 
  LEDS_LED1 = 1 << 1, 
  LEDS_LED2 = 1 << 2, 
  LEDS_LED3 = 1 << 3, 
  LEDS_LED4 = 1 << 4, 
  LEDS_LED5 = 1 << 5, 
  LEDS_LED6 = 1 << 6, 
  LEDS_LED7 = 1 << 7
};
# 31 "../net/net_EER_sim/eer/Collection.h"
enum __nesc_unnamed4287 {
  AM_COLLECTION_DATA = 20, 
  AM_COLLECTION_CONTROL = 21, 
  AM_COLLECTION_DEBUG = 22
};

typedef uint8_t collection_id_t;
typedef nx_uint8_t nx_collection_id_t;
# 52 "../net/net_EER_sim/eer/Ctp.h"
enum __nesc_unnamed4288 {

  AM_CTP_ROUTING = 0x70, 
  AM_CTP_DATA = 0x71, 
  AM_CTP_DEBUG = 0x72, 


  CTP_OPT_PULL = 0x80, 
  CTP_OPT_ECN = 0x40, 
  CTP_OPT_ALL = 0xff
};

typedef nx_uint8_t nx_ctp_options_t;
typedef uint8_t ctp_options_t;
#line 95
#line 67
typedef nx_struct __nesc_unnamed4289 {
  nx_ctp_options_t options;
  nx_uint8_t thl;
  nx_uint16_t etx;
  nx_am_addr_t origin;
  nx_uint8_t originSeqNo;
  nx_collection_id_t type;


  nx_uint16_t stats_nexthop;
  nx_uint16_t stats_petx;
  nx_uint16_t stats_letx;
  nx_uint8_t stats_frssi;
  nx_uint8_t stats_brssi;


  nx_uint16_t generated;
  nx_uint16_t forwarded;
  nx_uint16_t retx;
  nx_uint16_t dropped;


  nx_uint8_t psetSize;
  nx_uint16_t eer_parent;
  nx_uint8_t reTxs;


  nx_uint8_t ( data)[0];
} __attribute__((packed)) ctp_data_header_t;






#line 97
typedef nx_struct __nesc_unnamed4290 {
  nx_ctp_options_t options;
  nx_am_addr_t parent;
  nx_uint16_t etx;
  nx_uint8_t ( data)[0];
} __attribute__((packed)) ctp_routing_header_t;
# 25 "/opt/tinyos-2.1.2/tos/chips/atm128/sim/atm128_sim.h"
enum __nesc_unnamed4291 {

  ATM128_PINF = 0x00, 


  ATM128_PINE = 0x01, 


  ATM128_DDRE = 0x02, 


  ATM128_PORTE = 0x03, 


  ATM128_ADCW = 0x04, 

  ATM128_ADC = 0x04, 

  ATM128_ADCL = 0x04, 
  ATM128_ADCH = 0x05, 


  ATM128_ADCSR = 0x06, 
  ATM128_ADCSRA = 0x06, 


  ATM128_ADMUX = 0x07, 


  ATM128_ACSR = 0x08, 


  ATM128_UBRR0L = 0x09, 


  ATM128_UCSR0B = 0x0A, 


  ATM128_UCSR0A = 0x0B, 


  ATM128_UDR0 = 0x0C, 


  ATM128_SPCR = 0x0D, 


  ATM128_SPSR = 0x0E, 


  ATM128_SPDR = 0x0F, 


  ATM128_PIND = 0x10, 


  ATM128_DDRD = 0x11, 


  ATM128_PORTD = 0x12, 


  ATM128_PINC = 0x13, 


  ATM128_DDRC = 0x14, 


  ATM128_PORTC = 0x15, 


  ATM128_PINB = 0x16, 


  ATM128_DDRB = 0x17, 


  ATM128_PORTB = 0x18, 


  ATM128_PINA = 0x19, 


  ATM128_DDRA = 0x1A, 


  ATM128_PORTA = 0x1B, 




  ATM128_SFIOR = 0x20, 


  ATM128_WDTCR = 0x21, 


  ATM128_OCDR = 0x22, 


  ATM128_OCR2 = 0x23, 


  ATM128_TCNT2 = 0x24, 


  ATM128_TCCR2 = 0x25, 


  ATM128_ICR1 = 0x26, 
  ATM128_ICR1L = 0x26, 
  ATM128_ICR1H = 0x27, 


  ATM128_OCR1B = 0x28, 
  ATM128_OCR1BL = 0x28, 
  ATM128_OCR1BH = 0x29, 


  ATM128_OCR1A = 0x2A, 
  ATM128_OCR1AL = 0x2A, 
  ATM128_OCR1AH = 0x2B, 


  ATM128_TCNT1 = 0x2C, 
  ATM128_TCNT1L = 0x2C, 
  ATM128_TCNT1H = 0x2D, 


  ATM128_TCCR1B = 0x2E, 


  ATM128_TCCR1A = 0x2F, 


  ATM128_ASSR = 0x30, 


  ATM128_OCR0 = 0x31, 


  ATM128_TCNT0 = 0x32, 


  ATM128_TCCR0 = 0x33, 


  ATM128_MCUSR = 0x34, 
  ATM128_MCUCSR = 0x34, 


  ATM128_MCUCR = 0x35, 


  ATM128_TIFR = 0x36, 


  ATM128_TIMSK = 0x37, 


  ATM128_EIFR = 0x38, 


  ATM128_EIMSK = 0x39, 


  ATM128_EICRB = 0x3A, 


  ATM128_RAMPZ = 0x3B, 


  ATM128_XDIV = 0x3C, 




  ATM128_SREG = 0x3F, 




  ATM128_DDRF = 0x61, 


  ATM128_PORTF = 0x62, 


  ATM128_PING = 0x63, 


  ATM128_DDRG = 0x64, 


  ATM128_PORTG = 0x65, 


  ATM128_SPMCR = 0x68, 
  ATM128_SPMCSR = 0x68, 


  ATM128_EICRA = 0x6A, 


  ATM128_XMCRB = 0x6C, 


  ATM128_XMCRA = 0x6D, 


  ATM128_OSCCAL = 0x6F, 


  ATM128_TWBR = 0x70, 


  ATM128_TWSR = 0x71, 


  ATM128_TWAR = 0x72, 


  ATM128_TWDR = 0x73, 


  ATM128_TWCR = 0x74, 


  ATM128_OCR1C = 0x78, 
  ATM128_OCR1CL = 0x78, 
  ATM128_OCR1CH = 0x79, 


  ATM128_TCCR1C = 0x7A, 


  ATM128_ETIFR = 0x7C, 


  ATM128_ETIMSK = 0x7D, 


  ATM128_ICR3 = 0x80, 
  ATM128_ICR3L = 0x80, 
  ATM128_ICR3H = 0x81, 


  ATM128_OCR3C = 0x82, 
  ATM128_OCR3CL = 0x82, 
  ATM128_OCR3CH = 0x83, 


  ATM128_OCR3B = 0x84, 
  ATM128_OCR3BL = 0x84, 
  ATM128_OCR3BH = 0x85, 


  ATM128_OCR3A = 0x86, 
  ATM128_OCR3AL = 0x86, 
  ATM128_OCR3AH = 0x87, 


  ATM128_TCNT3 = 0x88, 
  ATM128_TCNT3L = 0x88, 
  ATM128_TCNT3H = 0x89, 


  ATM128_TCCR3B = 0x8A, 


  ATM128_TCCR3A = 0x8B, 


  ATM128_TCCR3C = 0x8C, 


  ATM128_UBRR0H = 0x90, 


  ATM128_UCSR0C = 0x95, 


  ATM128_UBRR1H = 0x98, 


  ATM128_UBRR1L = 0x99, 


  ATM128_UCSR1B = 0x9A, 


  ATM128_UCSR1A = 0x9B, 


  ATM128_UDR1 = 0x9C, 


  ATM128_UCSR1C = 0x9D
};
#line 673
enum __nesc_unnamed4292 {

  TWINT = 7, 
  TWEA = 6, 
  TWSTA = 5, 
  TWSTO = 4, 
  TWWC = 3, 
  TWEN = 2, 
  TWIE = 0, 


  TWA6 = 7, 
  TWA5 = 6, 
  TWA4 = 5, 
  TWA3 = 4, 
  TWA2 = 3, 
  TWA1 = 2, 
  TWA0 = 1, 
  TWGCE = 0, 


  TWS7 = 7, 
  TWS6 = 6, 
  TWS5 = 5, 
  TWS4 = 4, 
  TWS3 = 3, 
  TWPS1 = 1, 
  TWPS0 = 0, 


  SRL2 = 6, 
  SRL1 = 5, 
  SRL0 = 4, 
  SRW01 = 3, 
  SRW00 = 2, 
  SRW11 = 1, 


  XMBK = 7, 
  XMM2 = 2, 
  XMM1 = 1, 
  XMM0 = 0, 


  XDIVEN = 7, 
  XDIV6 = 6, 
  XDIV5 = 5, 
  XDIV4 = 4, 
  XDIV3 = 3, 
  XDIV2 = 2, 
  XDIV1 = 1, 
  XDIV0 = 0, 


  RAMPZ0 = 0, 


  ISC31 = 7, 
  ISC30 = 6, 
  ISC21 = 5, 
  ISC20 = 4, 
  ISC11 = 3, 
  ISC10 = 2, 
  ISC01 = 1, 
  ISC00 = 0, 


  ISC71 = 7, 
  ISC70 = 6, 
  ISC61 = 5, 
  ISC60 = 4, 
  ISC51 = 3, 
  ISC50 = 2, 
  ISC41 = 1, 
  ISC40 = 0, 


  SPMIE = 7, 
  RWWSB = 6, 
  RWWSRE = 4, 
  BLBSET = 3, 
  PGWRT = 2, 
  PGERS = 1, 
  SPMEN = 0, 


  INT7 = 7, 
  INT6 = 6, 
  INT5 = 5, 
  INT4 = 4, 
  INT3 = 3, 
  INT2 = 2, 
  INT1 = 1, 
  INT0 = 0, 


  INTF7 = 7, 
  INTF6 = 6, 
  INTF5 = 5, 
  INTF4 = 4, 
  INTF3 = 3, 
  INTF2 = 2, 
  INTF1 = 1, 
  INTF0 = 0, 


  OCIE2 = 7, 
  TOIE2 = 6, 
  TICIE1 = 5, 
  OCIE1A = 4, 
  OCIE1B = 3, 
  TOIE1 = 2, 
  OCIE0 = 1, 
  TOIE0 = 0, 


  OCF2 = 7, 
  TOV2 = 6, 
  ICF1 = 5, 
  OCF1A = 4, 
  OCF1B = 3, 
  TOV1 = 2, 
  OCF0 = 1, 
  TOV0 = 0, 


  TICIE3 = 5, 
  OCIE3A = 4, 
  OCIE3B = 3, 
  TOIE3 = 2, 
  OCIE3C = 1, 
  OCIE1C = 0, 


  ICF3 = 5, 
  OCF3A = 4, 
  OCF3B = 3, 
  TOV3 = 2, 
  OCF3C = 1, 
  OCF1C = 0, 


  SRE = 7, 
  SRW = 6, 
  SRW10 = 6, 
  SE = 5, 
  SM1 = 4, 
  SM0 = 3, 
  SM2 = 2, 
  IVSEL = 1, 
  IVCE = 0, 


  JTD = 7, 
  JTRF = 4, 
  WDRF = 3, 
  BORF = 2, 
  EXTRF = 1, 
  PORF = 0, 


  FOC = 7, 
  WGM0 = 6, 
  COM1 = 5, 
  COM0 = 4, 
  WGM1 = 3, 
  CS2 = 2, 
  CS1 = 1, 
  CS0 = 0, 


  FOC0 = 7, 
  WGM00 = 6, 
  COM01 = 5, 
  COM00 = 4, 
  WGM01 = 3, 
  CS02 = 2, 
  CS01 = 1, 
  CS00 = 0, 


  FOC2 = 7, 
  WGM20 = 6, 
  COM21 = 5, 
  COM20 = 4, 
  WGM21 = 3, 
  CS22 = 2, 
  CS21 = 1, 
  CS20 = 0, 


  AS0 = 3, 
  TCN0UB = 2, 
  OCR0UB = 1, 
  TCR0UB = 0, 


  COMA1 = 7, 
  COMA0 = 6, 
  COMB1 = 5, 
  COMB0 = 4, 
  COMC1 = 3, 
  COMC0 = 2, 
  WGMA1 = 1, 
  WGMA0 = 0, 


  COM1A1 = 7, 
  COM1A0 = 6, 
  COM1B1 = 5, 
  COM1B0 = 4, 
  COM1C1 = 3, 
  COM1C0 = 2, 
  WGM11 = 1, 
  WGM10 = 0, 


  COM3A1 = 7, 
  COM3A0 = 6, 
  COM3B1 = 5, 
  COM3B0 = 4, 
  COM3C1 = 3, 
  COM3C0 = 2, 
  WGM31 = 1, 
  WGM30 = 0, 


  ICNC = 7, 
  ICES = 6, 
  WGMB3 = 4, 
  WGMB2 = 3, 
  CSB2 = 2, 
  CSB1 = 1, 
  CSB0 = 0, 


  ICNC1 = 7, 
  ICES1 = 6, 
  WGM13 = 4, 
  WGM12 = 3, 
  CS12 = 2, 
  CS11 = 1, 
  CS10 = 0, 


  ICNC3 = 7, 
  ICES3 = 6, 
  WGM33 = 4, 
  WGM32 = 3, 
  CS32 = 2, 
  CS31 = 1, 
  CS30 = 0, 


  FOCA = 7, 
  FOCB = 6, 
  FOCC = 5, 


  FOC3A = 7, 
  FOC3B = 6, 
  FOC3C = 5, 


  FOC1A = 7, 
  FOC1B = 6, 
  FOC1C = 5, 


  IDRD = 7, 
  OCDR7 = 7, 
  OCDR6 = 6, 
  OCDR5 = 5, 
  OCDR4 = 4, 
  OCDR3 = 3, 
  OCDR2 = 2, 
  OCDR1 = 1, 
  OCDR0 = 0, 


  WDCE = 4, 
  WDE = 3, 
  WDP2 = 2, 
  WDP1 = 1, 
  WDP0 = 0, 


  TSM = 7, 
  ADHSM = 4, 
  ACME = 3, 
  PUD = 2, 
  PSR0 = 1, 
  PSR321 = 0, 


  SPIF = 7, 
  WCOL = 6, 
  SPI2X = 0, 


  SPIE = 7, 
  SPE = 6, 
  DORD = 5, 
  MSTR = 4, 
  CPOL = 3, 
  CPHA = 2, 
  SPR1 = 1, 
  SPR0 = 0, 


  UMSEL = 6, 
  UPM1 = 5, 
  UPM0 = 4, 
  USBS = 3, 
  UCSZ1 = 2, 
  UCSZ0 = 1, 
  UCPOL = 0, 


  UMSEL1 = 6, 
  UPM11 = 5, 
  UPM10 = 4, 
  USBS1 = 3, 
  UCSZ11 = 2, 
  UCSZ10 = 1, 
  UCPOL1 = 0, 


  UMSEL0 = 6, 
  UPM01 = 5, 
  UPM00 = 4, 
  USBS0 = 3, 
  UCSZ01 = 2, 
  UCSZ00 = 1, 
  UCPOL0 = 0, 


  RXC = 7, 
  TXC = 6, 
  UDRE = 5, 
  FE = 4, 
  DOR = 3, 
  UPE = 2, 
  U2X = 1, 
  MPCM = 0, 


  RXC1 = 7, 
  TXC1 = 6, 
  UDRE1 = 5, 
  FE1 = 4, 
  DOR1 = 3, 
  UPE1 = 2, 
  U2X1 = 1, 
  MPCM1 = 0, 


  RXC0 = 7, 
  TXC0 = 6, 
  UDRE0 = 5, 
  FE0 = 4, 
  DOR0 = 3, 
  UPE0 = 2, 
  U2X0 = 1, 
  MPCM0 = 0, 


  RXCIE = 7, 
  TXCIE = 6, 
  UDRIE = 5, 
  RXEN = 4, 
  TXEN = 3, 
  UCSZ = 2, 
  UCSZ2 = 2, 
  RXB8 = 1, 
  TXB8 = 0, 


  RXCIE1 = 7, 
  TXCIE1 = 6, 
  UDRIE1 = 5, 
  RXEN1 = 4, 
  TXEN1 = 3, 
  UCSZ12 = 2, 
  RXB81 = 1, 
  TXB81 = 0, 


  RXCIE0 = 7, 
  TXCIE0 = 6, 
  UDRIE0 = 5, 
  RXEN0 = 4, 
  TXEN0 = 3, 
  UCSZ02 = 2, 
  RXB80 = 1, 
  TXB80 = 0, 


  ACD = 7, 
  ACBG = 6, 
  ACO = 5, 
  ACI = 4, 
  ACIE = 3, 
  ACIC = 2, 
  ACIS1 = 1, 
  ACIS0 = 0, 


  ADEN = 7, 
  ADSC = 6, 
  ADFR = 5, 
  ADIF = 4, 
  ADIE = 3, 
  ADPS2 = 2, 
  ADPS1 = 1, 
  ADPS0 = 0, 


  REFS1 = 7, 
  REFS0 = 6, 
  ADLAR = 5, 
  MUX4 = 4, 
  MUX3 = 3, 
  MUX2 = 2, 
  MUX1 = 1, 
  MUX0 = 0, 


  PA7 = 7, 
  PA6 = 6, 
  PA5 = 5, 
  PA4 = 4, 
  PA3 = 3, 
  PA2 = 2, 
  PA1 = 1, 
  PA0 = 0, 


  DDA7 = 7, 
  DDA6 = 6, 
  DDA5 = 5, 
  DDA4 = 4, 
  DDA3 = 3, 
  DDA2 = 2, 
  DDA1 = 1, 
  DDA0 = 0, 


  PINA7 = 7, 
  PINA6 = 6, 
  PINA5 = 5, 
  PINA4 = 4, 
  PINA3 = 3, 
  PINA2 = 2, 
  PINA1 = 1, 
  PINA0 = 0, 


  PB7 = 7, 
  PB6 = 6, 
  PB5 = 5, 
  PB4 = 4, 
  PB3 = 3, 
  PB2 = 2, 
  PB1 = 1, 
  PB0 = 0, 


  DDB7 = 7, 
  DDB6 = 6, 
  DDB5 = 5, 
  DDB4 = 4, 
  DDB3 = 3, 
  DDB2 = 2, 
  DDB1 = 1, 
  DDB0 = 0, 


  PINB7 = 7, 
  PINB6 = 6, 
  PINB5 = 5, 
  PINB4 = 4, 
  PINB3 = 3, 
  PINB2 = 2, 
  PINB1 = 1, 
  PINB0 = 0, 


  PC7 = 7, 
  PC6 = 6, 
  PC5 = 5, 
  PC4 = 4, 
  PC3 = 3, 
  PC2 = 2, 
  PC1 = 1, 
  PC0 = 0, 


  DDC7 = 7, 
  DDC6 = 6, 
  DDC5 = 5, 
  DDC4 = 4, 
  DDC3 = 3, 
  DDC2 = 2, 
  DDC1 = 1, 
  DDC0 = 0, 


  PINC7 = 7, 
  PINC6 = 6, 
  PINC5 = 5, 
  PINC4 = 4, 
  PINC3 = 3, 
  PINC2 = 2, 
  PINC1 = 1, 
  PINC0 = 0, 


  PD7 = 7, 
  PD6 = 6, 
  PD5 = 5, 
  PD4 = 4, 
  PD3 = 3, 
  PD2 = 2, 
  PD1 = 1, 
  PD0 = 0, 


  DDD7 = 7, 
  DDD6 = 6, 
  DDD5 = 5, 
  DDD4 = 4, 
  DDD3 = 3, 
  DDD2 = 2, 
  DDD1 = 1, 
  DDD0 = 0, 


  PIND7 = 7, 
  PIND6 = 6, 
  PIND5 = 5, 
  PIND4 = 4, 
  PIND3 = 3, 
  PIND2 = 2, 
  PIND1 = 1, 
  PIND0 = 0, 


  PE7 = 7, 
  PE6 = 6, 
  PE5 = 5, 
  PE4 = 4, 
  PE3 = 3, 
  PE2 = 2, 
  PE1 = 1, 
  PE0 = 0, 


  DDE7 = 7, 
  DDE6 = 6, 
  DDE5 = 5, 
  DDE4 = 4, 
  DDE3 = 3, 
  DDE2 = 2, 
  DDE1 = 1, 
  DDE0 = 0, 


  PINE7 = 7, 
  PINE6 = 6, 
  PINE5 = 5, 
  PINE4 = 4, 
  PINE3 = 3, 
  PINE2 = 2, 
  PINE1 = 1, 
  PINE0 = 0, 


  PF7 = 7, 
  PF6 = 6, 
  PF5 = 5, 
  PF4 = 4, 
  PF3 = 3, 
  PF2 = 2, 
  PF1 = 1, 
  PF0 = 0, 


  DDF7 = 7, 
  DDF6 = 6, 
  DDF5 = 5, 
  DDF4 = 4, 
  DDF3 = 3, 
  DDF2 = 2, 
  DDF1 = 1, 
  DDF0 = 0, 


  PINF7 = 7, 
  PINF6 = 6, 
  PINF5 = 5, 
  PINF4 = 4, 
  PINF3 = 3, 
  PINF2 = 2, 
  PINF1 = 1, 
  PINF0 = 0, 


  PG4 = 4, 
  PG3 = 3, 
  PG2 = 2, 
  PG1 = 1, 
  PG0 = 0, 


  DDG4 = 4, 
  DDG3 = 3, 
  DDG2 = 2, 
  DDG1 = 1, 
  DDG0 = 0, 


  PING4 = 4, 
  PING3 = 3, 
  PING2 = 2, 
  PING1 = 1, 
  PING0 = 0
};
# 51 "/opt/tinyos-2.1.2/tos/chips/atm128/sim/atm128hardware.h"
uint8_t atm128RegFile[1000][0xa0];
#line 85
static __inline void __nesc_enable_interrupt();



static __inline void __nesc_disable_interrupt();




typedef uint8_t __nesc_atomic_t;



#line 97
__inline __nesc_atomic_t 
__nesc_atomic_start(void )  ;








#line 106
__inline void 
__nesc_atomic_end(__nesc_atomic_t original_SREG)  ;
#line 120
typedef uint8_t mcu_power_t  ;





enum __nesc_unnamed4293 {
  ATM128_POWER_IDLE = 0, 
  ATM128_POWER_ADC_NR = 1, 
  ATM128_POWER_EXT_STANDBY = 2, 
  ATM128_POWER_SAVE = 3, 
  ATM128_POWER_STANDBY = 4, 
  ATM128_POWER_DOWN = 5
};
# 43 "/opt/tinyos-2.1.2/tos/chips/atm128/adc/Atm128Adc.h"
enum __nesc_unnamed4294 {
  ATM128_ADC_VREF_OFF = 0, 
  ATM128_ADC_VREF_AVCC = 1, 
  ATM128_ADC_VREF_RSVD, 
  ATM128_ADC_VREF_2_56 = 3
};


enum __nesc_unnamed4295 {
  ATM128_ADC_RIGHT_ADJUST = 0, 
  ATM128_ADC_LEFT_ADJUST = 1
};



enum __nesc_unnamed4296 {
  ATM128_ADC_SNGL_ADC0 = 0, 
  ATM128_ADC_SNGL_ADC1, 
  ATM128_ADC_SNGL_ADC2, 
  ATM128_ADC_SNGL_ADC3, 
  ATM128_ADC_SNGL_ADC4, 
  ATM128_ADC_SNGL_ADC5, 
  ATM128_ADC_SNGL_ADC6, 
  ATM128_ADC_SNGL_ADC7, 
  ATM128_ADC_DIFF_ADC00_10x, 
  ATM128_ADC_DIFF_ADC10_10x, 
  ATM128_ADC_DIFF_ADC00_200x, 
  ATM128_ADC_DIFF_ADC10_200x, 
  ATM128_ADC_DIFF_ADC22_10x, 
  ATM128_ADC_DIFF_ADC32_10x, 
  ATM128_ADC_DIFF_ADC22_200x, 
  ATM128_ADC_DIFF_ADC32_200x, 
  ATM128_ADC_DIFF_ADC01_1x, 
  ATM128_ADC_DIFF_ADC11_1x, 
  ATM128_ADC_DIFF_ADC21_1x, 
  ATM128_ADC_DIFF_ADC31_1x, 
  ATM128_ADC_DIFF_ADC41_1x, 
  ATM128_ADC_DIFF_ADC51_1x, 
  ATM128_ADC_DIFF_ADC61_1x, 
  ATM128_ADC_DIFF_ADC71_1x, 
  ATM128_ADC_DIFF_ADC02_1x, 
  ATM128_ADC_DIFF_ADC12_1x, 
  ATM128_ADC_DIFF_ADC22_1x, 
  ATM128_ADC_DIFF_ADC32_1x, 
  ATM128_ADC_DIFF_ADC42_1x, 
  ATM128_ADC_DIFF_ADC52_1x, 
  ATM128_ADC_SNGL_1_23, 
  ATM128_ADC_SNGL_GND
};







#line 94
typedef struct __nesc_unnamed4297 {

  uint8_t mux : 5;
  uint8_t adlar : 1;
  uint8_t refs : 2;
} Atm128Admux_t;




enum __nesc_unnamed4298 {
  ATM128_ADC_PRESCALE_2 = 0, 
  ATM128_ADC_PRESCALE_2b, 
  ATM128_ADC_PRESCALE_4, 
  ATM128_ADC_PRESCALE_8, 
  ATM128_ADC_PRESCALE_16, 
  ATM128_ADC_PRESCALE_32, 
  ATM128_ADC_PRESCALE_64, 
  ATM128_ADC_PRESCALE_128, 



  ATM128_ADC_PRESCALE
};


enum __nesc_unnamed4299 {
  ATM128_ADC_ENABLE_OFF = 0, 
  ATM128_ADC_ENABLE_ON
};


enum __nesc_unnamed4300 {
  ATM128_ADC_START_CONVERSION_OFF = 0, 
  ATM128_ADC_START_CONVERSION_ON
};


enum __nesc_unnamed4301 {
  ATM128_ADC_FREE_RUNNING_OFF = 0, 
  ATM128_ADC_FREE_RUNNING_ON
};


enum __nesc_unnamed4302 {
  ATM128_ADC_INT_FLAG_OFF = 0, 
  ATM128_ADC_INT_FLAG_ON
};


enum __nesc_unnamed4303 {
  ATM128_ADC_INT_ENABLE_OFF = 0, 
  ATM128_ADC_INT_ENABLE_ON
};










#line 150
typedef struct __nesc_unnamed4304 {

  uint8_t adps : 3;
  uint8_t adie : 1;
  uint8_t adif : 1;
  uint8_t adfr : 1;
  uint8_t adsc : 1;
  uint8_t aden : 1;
} Atm128Adcsra_t;

typedef uint8_t Atm128_ADCH_t;
typedef uint8_t Atm128_ADCL_t;
# 54 "/opt/tinyos-2.1.2/tos/platforms/micaz/sim/platform_hardware.h"
enum __nesc_unnamed4305 {
  CHANNEL_RSSI = ATM128_ADC_SNGL_ADC0, 
  CHANNEL_THERMISTOR = ATM128_ADC_SNGL_ADC1, 
  CHANNEL_BATTERY = ATM128_ADC_SNGL_ADC7, 
  CHANNEL_BANDGAP = 30, 
  CHANNEL_GND = 31, 

  ATM128_TIMER0_TICKSPPS = 32768
};
# 41 "/opt/tinyos-2.1.2/tos/lib/tossim/SimMainP.nc"
static void __nesc_nido_initialise(int node);
# 52 "/opt/tinyos-2.1.2/tos/chips/atm128/timer/Atm128Timer.h"
enum __nesc_unnamed4306 {
  ATM128_CLK8_OFF = 0x0, 
  ATM128_CLK8_NORMAL = 0x1, 
  ATM128_CLK8_DIVIDE_8 = 0x2, 
  ATM128_CLK8_DIVIDE_32 = 0x3, 
  ATM128_CLK8_DIVIDE_64 = 0x4, 
  ATM128_CLK8_DIVIDE_128 = 0x5, 
  ATM128_CLK8_DIVIDE_256 = 0x6, 
  ATM128_CLK8_DIVIDE_1024 = 0x7
};

enum __nesc_unnamed4307 {
  ATM128_CLK16_OFF = 0x0, 
  ATM128_CLK16_NORMAL = 0x1, 
  ATM128_CLK16_DIVIDE_8 = 0x2, 
  ATM128_CLK16_DIVIDE_64 = 0x3, 
  ATM128_CLK16_DIVIDE_256 = 0x4, 
  ATM128_CLK16_DIVIDE_1024 = 0x5, 
  ATM128_CLK16_EXTERNAL_FALL = 0x6, 
  ATM128_CLK16_EXTERNAL_RISE = 0x7
};


enum __nesc_unnamed4308 {
  AVR_CLOCK_OFF = 0, 
  AVR_CLOCK_ON = 1, 
  AVR_CLOCK_DIVIDE_8 = 2
};


enum __nesc_unnamed4309 {
  ATM128_WAVE8_NORMAL = 0, 
  ATM128_WAVE8_PWM, 
  ATM128_WAVE8_CTC, 
  ATM128_WAVE8_PWM_FAST
};


enum __nesc_unnamed4310 {
  ATM128_COMPARE_OFF = 0, 
  ATM128_COMPARE_TOGGLE, 
  ATM128_COMPARE_CLEAR, 
  ATM128_COMPARE_SET
};
#line 108
#line 98
typedef union __nesc_unnamed4311 {

  uint8_t flat;
  struct __nesc_unnamed4312 {
    uint8_t cs : 3;
    uint8_t wgm1 : 1;
    uint8_t com : 2;
    uint8_t wgm0 : 1;
    uint8_t foc : 1;
  } bits;
} Atm128TimerControl_t;

typedef Atm128TimerControl_t Atm128_TCCR0_t;
typedef uint8_t Atm128_TCNT0_t;
typedef uint8_t Atm128_OCR0_t;

typedef Atm128TimerControl_t Atm128_TCCR2_t;
typedef uint8_t Atm128_TCNT2_t;
typedef uint8_t Atm128_OCR2_t;
#line 130
#line 120
typedef union __nesc_unnamed4313 {

  uint8_t flat;
  struct __nesc_unnamed4314 {
    uint8_t tcr0ub : 1;
    uint8_t ocr0ub : 1;
    uint8_t tcn0ub : 1;
    uint8_t as0 : 1;
    uint8_t rsvd : 4;
  } bits;
} Atm128Assr_t;
#line 146
#line 133
typedef union __nesc_unnamed4315 {

  uint8_t flat;
  struct __nesc_unnamed4316 {
    uint8_t toie0 : 1;
    uint8_t ocie0 : 1;
    uint8_t toie1 : 1;
    uint8_t ocie1b : 1;
    uint8_t ocie1a : 1;
    uint8_t ticie1 : 1;
    uint8_t toie2 : 1;
    uint8_t ocie2 : 1;
  } bits;
} Atm128_TIMSK_t;
#line 163
#line 150
typedef union __nesc_unnamed4317 {

  uint8_t flat;
  struct __nesc_unnamed4318 {
    uint8_t tov0 : 1;
    uint8_t ocf0 : 1;
    uint8_t tov1 : 1;
    uint8_t ocf1b : 1;
    uint8_t ocf1a : 1;
    uint8_t icf1 : 1;
    uint8_t tov2 : 1;
    uint8_t ocf2 : 1;
  } bits;
} Atm128_TIFR_t;
#line 178
#line 167
typedef union __nesc_unnamed4319 {

  uint8_t flat;
  struct __nesc_unnamed4320 {
    uint8_t psr321 : 1;
    uint8_t psr0 : 1;
    uint8_t pud : 1;
    uint8_t acme : 1;
    uint8_t rsvd : 3;
    uint8_t tsm : 1;
  } bits;
} Atm128_SFIOR_t;






enum __nesc_unnamed4321 {
  ATM128_TIMER_COMPARE_NORMAL = 0, 
  ATM128_TIMER_COMPARE_TOGGLE, 
  ATM128_TIMER_COMPARE_CLEAR, 
  ATM128_TIMER_COMPARE_SET
};
#line 202
#line 193
typedef union __nesc_unnamed4322 {

  uint8_t flat;
  struct __nesc_unnamed4323 {
    uint8_t wgm10 : 2;
    uint8_t comC : 2;
    uint8_t comB : 2;
    uint8_t comA : 2;
  } bits;
} Atm128TimerCtrlCompare_t;


typedef Atm128TimerCtrlCompare_t Atm128_TCCR1A_t;


typedef Atm128TimerCtrlCompare_t Atm128_TCCR3A_t;


enum __nesc_unnamed4324 {
  ATM128_WAVE16_NORMAL = 0, 
  ATM128_WAVE16_PWM_8BIT, 
  ATM128_WAVE16_PWM_9BIT, 
  ATM128_WAVE16_PWM_10BIT, 
  ATM128_WAVE16_CTC_COMPARE, 
  ATM128_WAVE16_PWM_FAST_8BIT, 
  ATM128_WAVE16_PWM_FAST_9BIT, 
  ATM128_WAVE16_PWM_FAST_10BIT, 
  ATM128_WAVE16_PWM_CAPTURE_LOW, 
  ATM128_WAVE16_PWM_COMPARE_LOW, 
  ATM128_WAVE16_PWM_CAPTURE_HIGH, 
  ATM128_WAVE16_PWM_COMPARE_HIGH, 
  ATM128_WAVE16_CTC_CAPTURE, 
  ATM128_WAVE16_RESERVED, 
  ATM128_WAVE16_PWM_FAST_CAPTURE, 
  ATM128_WAVE16_PWM_FAST_COMPARE
};
#line 241
#line 231
typedef union __nesc_unnamed4325 {

  uint8_t flat;
  struct __nesc_unnamed4326 {
    uint8_t cs : 3;
    uint8_t wgm32 : 2;
    uint8_t rsvd : 1;
    uint8_t ices1 : 1;
    uint8_t icnc1 : 1;
  } bits;
} Atm128TimerCtrlCapture_t;


typedef Atm128TimerCtrlCapture_t Atm128_TCCR1B_t;


typedef Atm128TimerCtrlCapture_t Atm128_TCCR3B_t;
#line 259
#line 250
typedef union __nesc_unnamed4327 {

  uint8_t flat;
  struct __nesc_unnamed4328 {
    uint8_t rsvd : 5;
    uint8_t focC : 1;
    uint8_t focB : 1;
    uint8_t focA : 1;
  } bits;
} Atm128TimerCtrlClock_t;


typedef Atm128TimerCtrlClock_t Atm128_TCCR1C_t;


typedef Atm128TimerCtrlClock_t Atm128_TCCR3C_t;



typedef uint8_t Atm128_TCNT1H_t;
typedef uint8_t Atm128_TCNT1L_t;
typedef uint8_t Atm128_TCNT3H_t;
typedef uint8_t Atm128_TCNT3L_t;


typedef uint8_t Atm128_OCR1AH_t;
typedef uint8_t Atm128_OCR1AL_t;
typedef uint8_t Atm128_OCR1BH_t;
typedef uint8_t Atm128_OCR1BL_t;
typedef uint8_t Atm128_OCR1CH_t;
typedef uint8_t Atm128_OCR1CL_t;


typedef uint8_t Atm128_OCR3AH_t;
typedef uint8_t Atm128_OCR3AL_t;
typedef uint8_t Atm128_OCR3BH_t;
typedef uint8_t Atm128_OCR3BL_t;
typedef uint8_t Atm128_OCR3CH_t;
typedef uint8_t Atm128_OCR3CL_t;


typedef uint8_t Atm128_ICR1H_t;
typedef uint8_t Atm128_ICR1L_t;
typedef uint8_t Atm128_ICR3H_t;
typedef uint8_t Atm128_ICR3L_t;
#line 309
#line 297
typedef union __nesc_unnamed4329 {

  uint8_t flat;
  struct __nesc_unnamed4330 {
    uint8_t ocie1c : 1;
    uint8_t ocie3c : 1;
    uint8_t toie3 : 1;
    uint8_t ocie3b : 1;
    uint8_t ocie3a : 1;
    uint8_t ticie3 : 1;
    uint8_t rsvd : 2;
  } bits;
} Atm128_ETIMSK_t;
#line 324
#line 312
typedef union __nesc_unnamed4331 {

  uint8_t flat;
  struct __nesc_unnamed4332 {
    uint8_t ocf1c : 1;
    uint8_t ocf3c : 1;
    uint8_t tov3 : 1;
    uint8_t ocf3b : 1;
    uint8_t ocf3a : 1;
    uint8_t icf3 : 1;
    uint8_t rsvd : 2;
  } bits;
} Atm128_ETIFR_t;
# 60 "../net/net_EER_sim/eer/CtpForwardingEngine.h"
enum __nesc_unnamed4333 {

  FORWARD_PACKET_TIME = 7
};




enum __nesc_unnamed4334 {
  SENDDONE_OK_OFFSET = FORWARD_PACKET_TIME, 
  SENDDONE_OK_WINDOW = FORWARD_PACKET_TIME, 
  SENDDONE_NOACK_OFFSET = FORWARD_PACKET_TIME, 
  SENDDONE_NOACK_WINDOW = FORWARD_PACKET_TIME, 
  SENDDONE_FAIL_OFFSET = FORWARD_PACKET_TIME << 2, 
  SENDDONE_FAIL_WINDOW = SENDDONE_FAIL_OFFSET, 
  LOOPY_OFFSET = FORWARD_PACKET_TIME << 2, 
  LOOPY_WINDOW = LOOPY_OFFSET, 
  CONGESTED_WAIT_OFFSET = FORWARD_PACKET_TIME << 2, 
  CONGESTED_WAIT_WINDOW = CONGESTED_WAIT_OFFSET, 
  NO_ROUTE_RETRY = 10000
};



enum __nesc_unnamed4335 {
  EER_SEND_WINDOW = 512, 
  EER_SEND_OFFSET = 1024
};








enum __nesc_unnamed4336 {
  MAX_RETRIES = 11
};
#line 114
#line 107
typedef struct __nesc_unnamed4337 {
  message_t * msg;
  uint8_t client;
  uint8_t retries;
  am_addr_t eer_fwder;
  uint8_t eer_retxs;
  bool forcedParentDraw;
} fe_queue_entry_t;
# 7 "../net/net_EER_sim/eer/CtpDebugMsg.h"
enum __nesc_unnamed4338 {
  NET_C_DEBUG_STARTED = 0xDE, 

  NET_C_FE_MSG_POOL_EMPTY = 0x10, 
  NET_C_FE_SEND_QUEUE_FULL = 0x11, 
  NET_C_FE_NO_ROUTE = 0x12, 
  NET_C_FE_SUBSEND_OFF = 0x13, 
  NET_C_FE_SUBSEND_BUSY = 0x14, 
  NET_C_FE_BAD_SENDDONE = 0x15, 
  NET_C_FE_QENTRY_POOL_EMPTY = 0x16, 
  NET_C_FE_SUBSEND_SIZE = 0x17, 
  NET_C_FE_LOOP_DETECTED = 0x18, 
  NET_C_FE_SEND_BUSY = 0x19, 

  NET_C_FE_SENDQUEUE_EMPTY = 0x50, 
  NET_C_FE_PUT_MSGPOOL_ERR = 0x51, 
  NET_C_FE_PUT_QEPOOL_ERR = 0x52, 
  NET_C_FE_GET_MSGPOOL_ERR = 0x53, 
  NET_C_FE_GET_QEPOOL_ERR = 0x54, 
  NET_C_FE_QUEUE_SIZE = 0x55, 

  NET_C_FE_SENT_MSG = 0x20, 
  NET_C_FE_RCV_MSG = 0x21, 
  NET_C_FE_FWD_MSG = 0x22, 
  NET_C_FE_DST_MSG = 0x23, 
  NET_C_FE_SENDDONE_FAIL = 0x24, 
  NET_C_FE_SENDDONE_WAITACK = 0x25, 
  NET_C_FE_SENDDONE_FAIL_ACK_SEND = 0x26, 
  NET_C_FE_SENDDONE_FAIL_ACK_FWD = 0x27, 
  NET_C_FE_DUPLICATE_CACHE = 0x28, 
  NET_C_FE_DUPLICATE_QUEUE = 0x29, 
  NET_C_FE_DUPLICATE_CACHE_AT_SEND = 0x2A, 
  NET_C_FE_CONGESTION_SENDWAIT = 0x2B, 
  NET_C_FE_CONGESTION_BEGIN = 0x2C, 
  NET_C_FE_CONGESTION_END = 0x2D, 



  NET_C_FE_CONGESTED = 0x2E, 

  NET_C_TREE_NO_ROUTE = 0x30, 
  NET_C_TREE_NEW_PARENT = 0x31, 
  NET_C_TREE_ROUTE_INFO = 0x32, 
  NET_C_TREE_SENT_BEACON = 0x33, 
  NET_C_TREE_RCV_BEACON = 0x34, 

  NET_C_DBG_1 = 0x40, 
  NET_C_DBG_2 = 0x41, 
  NET_C_DBG_3 = 0x42
};
#line 79
#line 58
typedef nx_struct CollectionDebugMsg {
  nx_uint8_t type;
  nx_union __nesc_unnamed4339 {
    nx_uint16_t arg;
    nx_struct __nesc_unnamed4340 {
      nx_uint16_t msg_uid;
      nx_am_addr_t origin;
      nx_am_addr_t other_node;
    } __attribute__((packed)) msg;
    nx_struct __nesc_unnamed4341 {
      nx_am_addr_t parent;
      nx_uint8_t hopcount;
      nx_uint16_t metric;
    } __attribute__((packed)) route_info;
    nx_struct __nesc_unnamed4342 {
      nx_uint16_t a;
      nx_uint16_t b;
      nx_uint16_t c;
    } __attribute__((packed)) dbg;
  } __attribute__((packed)) data;
  nx_uint16_t seqno;
} __attribute__((packed)) CollectionDebugMsg;
# 52 "../net/net_EER_sim/4bitle/./LinkEstimator.h"
enum __nesc_unnamed4343 {


  NUM_ENTRIES_FLAG = 15
};
#line 68
#line 65
typedef nx_struct linkest_header {
  nx_uint8_t flags;
  nx_uint8_t seq;
} __attribute__((packed)) linkest_header_t;







#line 73
typedef nx_struct neighbor_stat_entry {
  nx_am_addr_t ll_addr;
  nx_uint8_t inquality;
} __attribute__((packed)) neighbor_stat_entry_t;




#line 79
typedef nx_struct linkest_footer {
  neighbor_stat_entry_t neighborList[1];
} __attribute__((packed)) linkest_footer_t;



enum __nesc_unnamed4344 {
  VALID_ENTRY = 0x1, 


  MATURE_ENTRY = 0x2, 


  INIT_ENTRY = 0x4, 


  PINNED_ENTRY = 0x8
};
#line 128
#line 100
typedef struct neighbor_table_entry {

  am_addr_t ll_addr;

  uint8_t lastseq;


  uint8_t rcvcnt;

  uint8_t failcnt;

  uint8_t flags;


  uint8_t inquality;


  uint16_t etx;



  uint8_t data_success;


  uint8_t data_total;
} 


neighbor_table_entry_t;
# 4 "../net/net_EER_sim/eer/TreeRouting.h"
enum __nesc_unnamed4345 {
  AM_TREE_ROUTING_CONTROL = 0xCE, 
  BEACON_INTERVAL = 8192, 
  INVALID_ADDR = 0xFFFF, 
  ETX_THRESHOLD = 50, 
  PARENT_SWITCH_THRESHOLD = 15, 
  MAX_METRIC = 0xFFFF
};







#line 14
typedef struct __nesc_unnamed4346 {
  am_addr_t parent;
  uint16_t etx;
  bool haveHeard;
  bool congested;
} route_info_t;




#line 21
typedef struct __nesc_unnamed4347 {
  am_addr_t neighbor;
  route_info_t info;
} routing_table_entry;

static __inline void routeInfoInit(route_info_t *ri);
# 45 "../net/net_EER_sim/eer_parentselection/EerParentSelection.h"
#line 43
typedef struct __nesc_unnamed4348 {
  routing_table_entry *candidate;
} ParentTableEntry;









#line 47
typedef nx_struct parentSet {
  nx_uint8_t setSize;
  nx_uint16_t maxPathETX;
  nx_uint16_t bestNeighbor;
  nx_uint8_t maxPathETXPos;
  nx_uint16_t setETX;

  nx_uint16_t previousFwder;
} __attribute__((packed)) parentSet;
typedef TMilli LapTestC$DataTimer$precision_tag;
typedef TMilli /*AlarmCounterMilliP.Atm128AlarmAsyncC*/Atm128AlarmAsyncC$0$precision;
typedef /*AlarmCounterMilliP.Atm128AlarmAsyncC*/Atm128AlarmAsyncC$0$precision /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$precision;
typedef /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$precision /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Alarm$precision_tag;
typedef uint32_t /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Alarm$size_type;
typedef /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$precision /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Counter$precision_tag;
typedef uint32_t /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Counter$size_type;
typedef uint8_t /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Compare$size_type;
typedef uint8_t /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Timer$timer_size;
typedef uint8_t HplAtm128Timer0AsyncP$Timer0$timer_size;
typedef uint8_t HplAtm128Timer0AsyncP$Compare$size_type;
typedef TMilli /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$precision_tag;
typedef /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$precision_tag /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Alarm$precision_tag;
typedef uint32_t /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Alarm$size_type;
typedef /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$precision_tag /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Timer$precision_tag;
typedef TMilli /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$precision_tag;
typedef /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$precision_tag /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$TimerFrom$precision_tag;
typedef /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$precision_tag /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$precision_tag;
typedef TMilli /*HilTimerMilliC.CounterToLocalTimeC*/CounterToLocalTimeC$0$precision_tag;
typedef /*HilTimerMilliC.CounterToLocalTimeC*/CounterToLocalTimeC$0$precision_tag /*HilTimerMilliC.CounterToLocalTimeC*/CounterToLocalTimeC$0$LocalTime$precision_tag;
typedef /*HilTimerMilliC.CounterToLocalTimeC*/CounterToLocalTimeC$0$precision_tag /*HilTimerMilliC.CounterToLocalTimeC*/CounterToLocalTimeC$0$Counter$precision_tag;
typedef uint32_t /*HilTimerMilliC.CounterToLocalTimeC*/CounterToLocalTimeC$0$Counter$size_type;
enum CtpP$__nesc_unnamed4349 {
  CtpP$CLIENT_COUNT = 1U, CtpP$FORWARD_COUNT = 7, CtpP$TREE_ROUTING_TABLE_SIZE = 14, CtpP$QUEUE_SIZE = CtpP$CLIENT_COUNT + CtpP$FORWARD_COUNT, CtpP$CACHE_SIZE = 4
};
typedef message_t */*CtpP.Forwarder*/CtpForwardingEngineP$0$SentCache$t;
typedef TMilli /*CtpP.Forwarder*/CtpForwardingEngineP$0$RetxmitTimer$precision_tag;
typedef fe_queue_entry_t */*CtpP.Forwarder*/CtpForwardingEngineP$0$SendQueue$t;
typedef fe_queue_entry_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$QEntryPool$t;
typedef message_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$MessagePool$t;
typedef message_t /*CtpP.MessagePoolP*/PoolC$0$pool_t;
typedef /*CtpP.MessagePoolP*/PoolC$0$pool_t /*CtpP.MessagePoolP.PoolP*/PoolP$0$pool_t;
typedef /*CtpP.MessagePoolP.PoolP*/PoolP$0$pool_t /*CtpP.MessagePoolP.PoolP*/PoolP$0$Pool$t;
typedef fe_queue_entry_t /*CtpP.QEntryPoolP*/PoolC$1$pool_t;
typedef /*CtpP.QEntryPoolP*/PoolC$1$pool_t /*CtpP.QEntryPoolP.PoolP*/PoolP$1$pool_t;
typedef /*CtpP.QEntryPoolP.PoolP*/PoolP$1$pool_t /*CtpP.QEntryPoolP.PoolP*/PoolP$1$Pool$t;
typedef fe_queue_entry_t */*CtpP.SendQueueP*/QueueC$0$queue_t;
typedef /*CtpP.SendQueueP*/QueueC$0$queue_t /*CtpP.SendQueueP*/QueueC$0$Queue$t;
typedef message_t */*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$Cache$t;
enum AMQueueP$__nesc_unnamed4350 {
  AMQueueP$NUM_CLIENTS = 2U
};
typedef TMilli /*CtpP.Router*/EerParentSetEngineP$0$BeaconTimer$precision_tag;
typedef TMilli /*CtpP.Router*/EerParentSetEngineP$0$RouteTimer$precision_tag;
typedef uint16_t RandomMlcgC$SeedInit$parameter;
# 100 "/opt/tinyos-2.1.2/tos/interfaces/Send.nc"
static void LapTestC$DataSend$sendDone(
#line 96
message_t * msg, 



error_t error);
# 60 "/opt/tinyos-2.1.2/tos/interfaces/Boot.nc"
static void LapTestC$Boot$booted(void );
# 113 "/opt/tinyos-2.1.2/tos/interfaces/SplitControl.nc"
static void LapTestC$RadioControl$startDone(error_t error);
#line 138
static void LapTestC$RadioControl$stopDone(error_t error);
# 83 "/opt/tinyos-2.1.2/tos/lib/timer/Timer.nc"
static void LapTestC$DataTimer$fired(void );
# 31 "/opt/tinyos-2.1.2/tos/interfaces/Intercept.nc"
static bool LapTestC$DataIntercept$forward(
#line 20
message_t * msg, 

void * payload, 








uint8_t len);
# 78 "/opt/tinyos-2.1.2/tos/interfaces/Receive.nc"
static 
#line 74
message_t * 



LapTestC$DataReceive$receive(
#line 71
message_t * msg, 
void * payload, 





uint8_t len);
# 75 "/opt/tinyos-2.1.2/tos/interfaces/TaskBasic.nc"
static void LapTestC$sendDataMessage$runTask(void );
# 62 "/opt/tinyos-2.1.2/tos/interfaces/Init.nc"
static error_t PlatformP$Init$init(void );
#line 62
static error_t MotePlatformP$SubInit$default$init(void );
#line 62
static error_t MotePlatformP$PlatformInit$init(void );
# 46 "/opt/tinyos-2.1.2/tos/interfaces/GeneralIO.nc"
static void /*HplAtm128GeneralIOC.PortA.Bit0*/HplAtm128GeneralIOPinP$0$IO$makeOutput(void );
#line 40
static void /*HplAtm128GeneralIOC.PortA.Bit0*/HplAtm128GeneralIOPinP$0$IO$set(void );





static void /*HplAtm128GeneralIOC.PortA.Bit1*/HplAtm128GeneralIOPinP$1$IO$makeOutput(void );
#line 40
static void /*HplAtm128GeneralIOC.PortA.Bit1*/HplAtm128GeneralIOPinP$1$IO$set(void );





static void /*HplAtm128GeneralIOC.PortA.Bit2*/HplAtm128GeneralIOPinP$2$IO$makeOutput(void );
#line 40
static void /*HplAtm128GeneralIOC.PortA.Bit2*/HplAtm128GeneralIOPinP$2$IO$set(void );



static void /*HplAtm128GeneralIOC.PortA.Bit4*/HplAtm128GeneralIOPinP$4$IO$makeInput(void );
#line 41
static void /*HplAtm128GeneralIOC.PortA.Bit4*/HplAtm128GeneralIOPinP$4$IO$clr(void );
# 62 "/opt/tinyos-2.1.2/tos/interfaces/Init.nc"
static error_t MeasureClockC$Init$init(void );
# 67 "/opt/tinyos-2.1.2/tos/interfaces/TaskBasic.nc"
static error_t SimSchedulerBasicP$TaskBasic$postTask(
# 49 "/opt/tinyos-2.1.2/tos/lib/tossim/SimSchedulerBasicP.nc"
uint8_t arg_0x406e11b8);
# 75 "/opt/tinyos-2.1.2/tos/interfaces/TaskBasic.nc"
static void SimSchedulerBasicP$TaskBasic$default$runTask(
# 49 "/opt/tinyos-2.1.2/tos/lib/tossim/SimSchedulerBasicP.nc"
uint8_t arg_0x406e11b8);
# 57 "/opt/tinyos-2.1.2/tos/interfaces/Scheduler.nc"
static void SimSchedulerBasicP$Scheduler$init(void );







static bool SimSchedulerBasicP$Scheduler$runNextTask(void );
# 44 "/opt/tinyos-2.1.2/tos/lib/tossim/SimMote.nc"
static void SimMoteP$SimMote$setEuid(long long int euid);


static int SimMoteP$SimMote$getVariableInfo(char *name, void **ptr, size_t *len);

static void SimMoteP$SimMote$turnOff(void );
#line 48
static void SimMoteP$SimMote$turnOn(void );
#line 43
static long long int SimMoteP$SimMote$getEuid(void );


static bool SimMoteP$SimMote$isOn(void );
#line 45
static long long int SimMoteP$SimMote$getStartTime(void );
# 80 "/opt/tinyos-2.1.2/tos/interfaces/AMSend.nc"
static error_t TossimActiveMessageC$AMSend$send(
# 47 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimActiveMessageC.nc"
am_id_t arg_0x408eb4b0, 
# 80 "/opt/tinyos-2.1.2/tos/interfaces/AMSend.nc"
am_addr_t addr, 
#line 71
message_t * msg, 








uint8_t len);
#line 123
static uint8_t TossimActiveMessageC$AMSend$maxPayloadLength(
# 47 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimActiveMessageC.nc"
am_id_t arg_0x408eb4b0);
# 78 "/opt/tinyos-2.1.2/tos/interfaces/Receive.nc"
static 
#line 74
message_t * 



TossimActiveMessageC$Snoop$default$receive(
# 49 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimActiveMessageC.nc"
am_id_t arg_0x408ea5b8, 
# 71 "/opt/tinyos-2.1.2/tos/interfaces/Receive.nc"
message_t * msg, 
void * payload, 





uint8_t len);
# 78 "/opt/tinyos-2.1.2/tos/interfaces/Packet.nc"
static uint8_t TossimActiveMessageC$Packet$payloadLength(
#line 74
message_t * msg);
#line 126
static 
#line 123
void * 


TossimActiveMessageC$Packet$getPayload(
#line 121
message_t * msg, 




uint8_t len);
#line 106
static uint8_t TossimActiveMessageC$Packet$maxPayloadLength(void );
#line 94
static void TossimActiveMessageC$Packet$setPayloadLength(
#line 90
message_t * msg, 



uint8_t len);
# 78 "/opt/tinyos-2.1.2/tos/interfaces/Receive.nc"
static 
#line 74
message_t * 



TossimActiveMessageC$Receive$default$receive(
# 48 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimActiveMessageC.nc"
am_id_t arg_0x408ebe70, 
# 71 "/opt/tinyos-2.1.2/tos/interfaces/Receive.nc"
message_t * msg, 
void * payload, 





uint8_t len);
# 85 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimPacketModel.nc"
static void TossimActiveMessageC$Model$receive(message_t *msg);
#line 76
static void TossimActiveMessageC$Model$sendDone(message_t *msg, error_t error);










static bool TossimActiveMessageC$Model$shouldAck(message_t *msg);
# 88 "/opt/tinyos-2.1.2/tos/interfaces/AMPacket.nc"
static am_addr_t TossimActiveMessageC$AMPacket$source(
#line 84
message_t * amsg);
#line 68
static am_addr_t TossimActiveMessageC$AMPacket$address(void );









static am_addr_t TossimActiveMessageC$AMPacket$destination(
#line 74
message_t * amsg);
#line 103
static void TossimActiveMessageC$AMPacket$setDestination(
#line 99
message_t * amsg, 



am_addr_t addr);
#line 147
static am_id_t TossimActiveMessageC$AMPacket$type(
#line 143
message_t * amsg);
#line 162
static void TossimActiveMessageC$AMPacket$setType(
#line 158
message_t * amsg, 



am_id_t t);
#line 136
static bool TossimActiveMessageC$AMPacket$isForMe(
#line 133
message_t * amsg);
# 75 "/opt/tinyos-2.1.2/tos/interfaces/TaskBasic.nc"
static void TossimPacketModelC$stopDoneTask$runTask(void );
# 57 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimPacketModel.nc"
static error_t TossimPacketModelC$Packet$send(int node, message_t *msg, uint8_t len);
# 75 "/opt/tinyos-2.1.2/tos/interfaces/TaskBasic.nc"
static void TossimPacketModelC$sendDoneTask$runTask(void );
# 62 "/opt/tinyos-2.1.2/tos/interfaces/Init.nc"
static error_t TossimPacketModelC$Init$init(void );
# 75 "/opt/tinyos-2.1.2/tos/interfaces/TaskBasic.nc"
static void TossimPacketModelC$startDoneTask$runTask(void );
# 104 "/opt/tinyos-2.1.2/tos/interfaces/SplitControl.nc"
static error_t TossimPacketModelC$Control$start(void );
# 59 "/opt/tinyos-2.1.2/tos/interfaces/PacketAcknowledgements.nc"
static error_t TossimPacketModelC$PacketAcknowledgements$requestAck(
#line 53
message_t * msg);
#line 85
static bool TossimPacketModelC$PacketAcknowledgements$wasAcked(
#line 80
message_t * msg);
# 60 "/opt/tinyos-2.1.2/tos/lib/tossim/GainRadioModel.nc"
static void TossimPacketModelC$GainRadioModel$receive(message_t *msg);
#line 59
static void TossimPacketModelC$GainRadioModel$acked(message_t *msg);

static bool TossimPacketModelC$GainRadioModel$shouldAck(message_t *msg);
#line 48
static void CpmModelC$Model$putOnAirTo(int dest, 
message_t *msg, 
bool ack, 
sim_time_t endTime, 
double gain, 
double reverseGain);


static bool CpmModelC$Model$clearChannel(void );
static void CpmModelC$Model$setPendingTransmission(void );
# 60 "/opt/tinyos-2.1.2/tos/lib/tossim/ActiveMessageAddressC.nc"
static am_addr_t ActiveMessageAddressC$amAddress(void );
# 50 "/opt/tinyos-2.1.2/tos/interfaces/ActiveMessageAddress.nc"
static am_addr_t ActiveMessageAddressC$ActiveMessageAddress$amAddress(void );
# 62 "/opt/tinyos-2.1.2/tos/interfaces/Init.nc"
static error_t LedsP$Init$init(void );
# 109 "/opt/tinyos-2.1.2/tos/lib/timer/Alarm.nc"
static /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Alarm$size_type /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Alarm$getNow(void );
#line 103
static void /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Alarm$startAt(/*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Alarm$size_type t0, /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Alarm$size_type dt);
#line 116
static /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Alarm$size_type /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Alarm$getAlarm(void );
#line 73
static void /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Alarm$stop(void );
# 62 "/opt/tinyos-2.1.2/tos/interfaces/Init.nc"
static error_t /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Init$init(void );
# 64 "/opt/tinyos-2.1.2/tos/lib/timer/Counter.nc"
static /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Counter$size_type /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Counter$get(void );
# 58 "/opt/tinyos-2.1.2/tos/chips/atm128/timer/HplAtm128Compare.nc"
static void /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Compare$fired(void );
# 70 "/opt/tinyos-2.1.2/tos/chips/atm128/timer/HplAtm128Timer.nc"
static void /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Timer$overflow(void );
#line 61
static HplAtm128Timer0AsyncP$Timer0$timer_size HplAtm128Timer0AsyncP$Timer0$get(void );
#line 110
static uint8_t HplAtm128Timer0AsyncP$Timer0$getScale(void );
#line 67
static void HplAtm128Timer0AsyncP$Timer0$set(HplAtm128Timer0AsyncP$Timer0$timer_size t);
# 44 "/opt/tinyos-2.1.2/tos/chips/atm128/timer/HplAtm128TimerAsync.nc"
static int HplAtm128Timer0AsyncP$TimerAsync$compareBusy(void );
#line 32
static void HplAtm128Timer0AsyncP$TimerAsync$setTimer0Asynchronous(void );
# 53 "/opt/tinyos-2.1.2/tos/chips/atm128/timer/HplAtm128TimerCtrl8.nc"
static Atm128_TIFR_t HplAtm128Timer0AsyncP$Timer0Ctrl$getInterruptFlag(void );
#line 46
static void HplAtm128Timer0AsyncP$Timer0Ctrl$setControl(Atm128TimerControl_t control);
# 48 "/opt/tinyos-2.1.2/tos/chips/atm128/timer/HplAtm128Compare.nc"
static HplAtm128Timer0AsyncP$Compare$size_type HplAtm128Timer0AsyncP$Compare$get(void );





static void HplAtm128Timer0AsyncP$Compare$set(HplAtm128Timer0AsyncP$Compare$size_type t);










static void HplAtm128Timer0AsyncP$Compare$start(void );
# 75 "/opt/tinyos-2.1.2/tos/interfaces/TaskBasic.nc"
static void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$fired$runTask(void );
# 78 "/opt/tinyos-2.1.2/tos/lib/timer/Alarm.nc"
static void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Alarm$fired(void );
# 136 "/opt/tinyos-2.1.2/tos/lib/timer/Timer.nc"
static uint32_t /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Timer$getNow(void );
#line 129
static void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Timer$startOneShotAt(uint32_t t0, uint32_t dt);
#line 78
static void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Timer$stop(void );
# 75 "/opt/tinyos-2.1.2/tos/interfaces/TaskBasic.nc"
static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$updateFromTimer$runTask(void );
# 83 "/opt/tinyos-2.1.2/tos/lib/timer/Timer.nc"
static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$TimerFrom$fired(void );
#line 83
static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$default$fired(
# 48 "/opt/tinyos-2.1.2/tos/lib/timer/VirtualizeTimerC.nc"
uint8_t arg_0x40b67c70);
# 92 "/opt/tinyos-2.1.2/tos/lib/timer/Timer.nc"
static bool /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$isRunning(
# 48 "/opt/tinyos-2.1.2/tos/lib/timer/VirtualizeTimerC.nc"
uint8_t arg_0x40b67c70);
# 64 "/opt/tinyos-2.1.2/tos/lib/timer/Timer.nc"
static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$startPeriodic(
# 48 "/opt/tinyos-2.1.2/tos/lib/timer/VirtualizeTimerC.nc"
uint8_t arg_0x40b67c70, 
# 64 "/opt/tinyos-2.1.2/tos/lib/timer/Timer.nc"
uint32_t dt);








static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$startOneShot(
# 48 "/opt/tinyos-2.1.2/tos/lib/timer/VirtualizeTimerC.nc"
uint8_t arg_0x40b67c70, 
# 73 "/opt/tinyos-2.1.2/tos/lib/timer/Timer.nc"
uint32_t dt);




static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$stop(
# 48 "/opt/tinyos-2.1.2/tos/lib/timer/VirtualizeTimerC.nc"
uint8_t arg_0x40b67c70);
# 82 "/opt/tinyos-2.1.2/tos/lib/timer/Counter.nc"
static void /*HilTimerMilliC.CounterToLocalTimeC*/CounterToLocalTimeC$0$Counter$overflow(void );
# 78 "/opt/tinyos-2.1.2/tos/interfaces/Receive.nc"
static 
#line 74
message_t * 



/*CtpP.Forwarder*/CtpForwardingEngineP$0$SubReceive$receive(
#line 71
message_t * msg, 
void * payload, 





uint8_t len);
# 110 "/opt/tinyos-2.1.2/tos/interfaces/AMSend.nc"
static void /*CtpP.Forwarder*/CtpForwardingEngineP$0$SubSend$sendDone(
#line 103
message_t * msg, 






error_t error);
# 61 "../net/net_EER_sim/CollectionDebug.nc"
static error_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$CollectionDebug$default$logEvent(uint8_t type);
#line 73
static error_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$CollectionDebug$default$logEventMsg(uint8_t type, uint16_t msg, am_addr_t origin, am_addr_t node);
# 43 "../net/net_EER_sim/CollectionPacket.nc"
static am_addr_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$CollectionPacket$getOrigin(message_t *msg);





static uint8_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$CollectionPacket$getSequenceNumber(message_t *msg);
# 72 "../net/net_EER_sim/4bitle/LinkEstimator.nc"
static void /*CtpP.Forwarder*/CtpForwardingEngineP$0$LinkEstimator$evicted(am_addr_t neighbor);
# 31 "/opt/tinyos-2.1.2/tos/interfaces/Intercept.nc"
static bool /*CtpP.Forwarder*/CtpForwardingEngineP$0$Intercept$default$forward(
# 122 "../net/net_EER_sim/eer/CtpForwardingEngineP.nc"
collection_id_t arg_0x40bec430, 
# 20 "/opt/tinyos-2.1.2/tos/interfaces/Intercept.nc"
message_t * msg, 

void * payload, 








uint8_t len);
# 78 "/opt/tinyos-2.1.2/tos/interfaces/Packet.nc"
static uint8_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$Packet$payloadLength(
#line 74
message_t * msg);
#line 126
static 
#line 123
void * 


/*CtpP.Forwarder*/CtpForwardingEngineP$0$Packet$getPayload(
#line 121
message_t * msg, 




uint8_t len);
#line 106
static uint8_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$Packet$maxPayloadLength(void );
#line 94
static void /*CtpP.Forwarder*/CtpForwardingEngineP$0$Packet$setPayloadLength(
#line 90
message_t * msg, 



uint8_t len);
# 78 "/opt/tinyos-2.1.2/tos/interfaces/Receive.nc"
static 
#line 74
message_t * 



/*CtpP.Forwarder*/CtpForwardingEngineP$0$Snoop$default$receive(
# 121 "../net/net_EER_sim/eer/CtpForwardingEngineP.nc"
collection_id_t arg_0x40bc5d68, 
# 71 "/opt/tinyos-2.1.2/tos/interfaces/Receive.nc"
message_t * msg, 
void * payload, 





uint8_t len);
# 75 "/opt/tinyos-2.1.2/tos/interfaces/Send.nc"
static error_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$Send$send(
# 119 "../net/net_EER_sim/eer/CtpForwardingEngineP.nc"
uint8_t arg_0x40bc6c58, 
# 67 "/opt/tinyos-2.1.2/tos/interfaces/Send.nc"
message_t * msg, 







uint8_t len);
#line 125
static 
#line 123
void * 

/*CtpP.Forwarder*/CtpForwardingEngineP$0$Send$getPayload(
# 119 "../net/net_EER_sim/eer/CtpForwardingEngineP.nc"
uint8_t arg_0x40bc6c58, 
# 122 "/opt/tinyos-2.1.2/tos/interfaces/Send.nc"
message_t * msg, 


uint8_t len);
#line 112
static uint8_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$Send$maxPayloadLength(
# 119 "../net/net_EER_sim/eer/CtpForwardingEngineP.nc"
uint8_t arg_0x40bc6c58);
# 100 "/opt/tinyos-2.1.2/tos/interfaces/Send.nc"
static void /*CtpP.Forwarder*/CtpForwardingEngineP$0$Send$default$sendDone(
# 119 "../net/net_EER_sim/eer/CtpForwardingEngineP.nc"
uint8_t arg_0x40bc6c58, 
# 96 "/opt/tinyos-2.1.2/tos/interfaces/Send.nc"
message_t * msg, 



error_t error);
# 83 "/opt/tinyos-2.1.2/tos/lib/timer/Timer.nc"
static void /*CtpP.Forwarder*/CtpForwardingEngineP$0$RetxmitTimer$fired(void );
# 113 "/opt/tinyos-2.1.2/tos/interfaces/SplitControl.nc"
static void /*CtpP.Forwarder*/CtpForwardingEngineP$0$RadioControl$startDone(error_t error);
#line 138
static void /*CtpP.Forwarder*/CtpForwardingEngineP$0$RadioControl$stopDone(error_t error);
# 75 "/opt/tinyos-2.1.2/tos/interfaces/TaskBasic.nc"
static void /*CtpP.Forwarder*/CtpForwardingEngineP$0$sendTask$runTask(void );
# 62 "/opt/tinyos-2.1.2/tos/interfaces/Init.nc"
static error_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$Init$init(void );
# 78 "/opt/tinyos-2.1.2/tos/interfaces/Receive.nc"
static 
#line 74
message_t * 



/*CtpP.Forwarder*/CtpForwardingEngineP$0$Receive$default$receive(
# 120 "../net/net_EER_sim/eer/CtpForwardingEngineP.nc"
collection_id_t arg_0x40bc5680, 
# 71 "/opt/tinyos-2.1.2/tos/interfaces/Receive.nc"
message_t * msg, 
void * payload, 





uint8_t len);
# 7 "../net/net_EER_sim/eer/CtpCongestion.nc"
static bool /*CtpP.Forwarder*/CtpForwardingEngineP$0$CtpCongestion$isCongested(void );
# 51 "../net/net_EER_sim/UnicastNameFreeRouting.nc"
static void /*CtpP.Forwarder*/CtpForwardingEngineP$0$UnicastNameFreeRouting$routeFound(void );
static void /*CtpP.Forwarder*/CtpForwardingEngineP$0$UnicastNameFreeRouting$noRoute(void );
# 52 "../net/net_EER_sim/eer/CtpPacket.nc"
static bool /*CtpP.Forwarder*/CtpForwardingEngineP$0$CtpPacket$option(message_t *msg, ctp_options_t opt);





static void /*CtpP.Forwarder*/CtpForwardingEngineP$0$CtpPacket$setEtx(message_t *msg, uint16_t etx);
#line 49
static void /*CtpP.Forwarder*/CtpForwardingEngineP$0$CtpPacket$clearOption(message_t *msg, ctp_options_t option);







static uint16_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$CtpPacket$getEtx(message_t *msg);


static am_addr_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$CtpPacket$getOrigin(message_t *msg);
#line 46
static void /*CtpP.Forwarder*/CtpForwardingEngineP$0$CtpPacket$setOption(message_t *msg, ctp_options_t option);







static uint8_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$CtpPacket$getThl(message_t *msg);








static uint8_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$CtpPacket$getSequenceNumber(message_t *msg);





static bool /*CtpP.Forwarder*/CtpForwardingEngineP$0$CtpPacket$matchInstance(message_t *m1, message_t *m2);
#line 66
static uint8_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$CtpPacket$getType(message_t *msg);
#line 55
static void /*CtpP.Forwarder*/CtpForwardingEngineP$0$CtpPacket$setThl(message_t *msg, uint8_t thl);
# 95 "/opt/tinyos-2.1.2/tos/interfaces/StdControl.nc"
static error_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$StdControl$start(void );
# 78 "/opt/tinyos-2.1.2/tos/interfaces/Receive.nc"
static 
#line 74
message_t * 



/*CtpP.Forwarder*/CtpForwardingEngineP$0$SubSnoop$receive(
#line 71
message_t * msg, 
void * payload, 





uint8_t len);
# 46 "../net/net_EER_sim/CollectionId.nc"
static collection_id_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$CollectionId$default$fetch(
# 157 "../net/net_EER_sim/eer/CtpForwardingEngineP.nc"
uint8_t arg_0x40bfa010);
# 97 "/opt/tinyos-2.1.2/tos/interfaces/Pool.nc"
static 
#line 94
/*CtpP.MessagePoolP.PoolP*/PoolP$0$Pool$t * 


/*CtpP.MessagePoolP.PoolP*/PoolP$0$Pool$get(void );
#line 61
static bool /*CtpP.MessagePoolP.PoolP*/PoolP$0$Pool$empty(void );
#line 89
static error_t /*CtpP.MessagePoolP.PoolP*/PoolP$0$Pool$put(
#line 85
/*CtpP.MessagePoolP.PoolP*/PoolP$0$Pool$t * newVal);
# 62 "/opt/tinyos-2.1.2/tos/interfaces/Init.nc"
static error_t /*CtpP.MessagePoolP.PoolP*/PoolP$0$Init$init(void );
# 97 "/opt/tinyos-2.1.2/tos/interfaces/Pool.nc"
static 
#line 94
/*CtpP.QEntryPoolP.PoolP*/PoolP$1$Pool$t * 


/*CtpP.QEntryPoolP.PoolP*/PoolP$1$Pool$get(void );
#line 61
static bool /*CtpP.QEntryPoolP.PoolP*/PoolP$1$Pool$empty(void );
#line 89
static error_t /*CtpP.QEntryPoolP.PoolP*/PoolP$1$Pool$put(
#line 85
/*CtpP.QEntryPoolP.PoolP*/PoolP$1$Pool$t * newVal);
# 62 "/opt/tinyos-2.1.2/tos/interfaces/Init.nc"
static error_t /*CtpP.QEntryPoolP.PoolP*/PoolP$1$Init$init(void );
# 73 "/opt/tinyos-2.1.2/tos/interfaces/Queue.nc"
static 
#line 71
/*CtpP.SendQueueP*/QueueC$0$Queue$t  

/*CtpP.SendQueueP*/QueueC$0$Queue$head(void );
#line 90
static error_t /*CtpP.SendQueueP*/QueueC$0$Queue$enqueue(
#line 86
/*CtpP.SendQueueP*/QueueC$0$Queue$t  newVal);
#line 101
static 
#line 99
/*CtpP.SendQueueP*/QueueC$0$Queue$t  

/*CtpP.SendQueueP*/QueueC$0$Queue$element(uint8_t idx);
#line 65
static uint8_t /*CtpP.SendQueueP*/QueueC$0$Queue$maxSize(void );
#line 81
static 
#line 79
/*CtpP.SendQueueP*/QueueC$0$Queue$t  

/*CtpP.SendQueueP*/QueueC$0$Queue$dequeue(void );
#line 50
static bool /*CtpP.SendQueueP*/QueueC$0$Queue$empty(void );







static uint8_t /*CtpP.SendQueueP*/QueueC$0$Queue$size(void );
# 51 "/opt/tinyos-2.1.2/tos/interfaces/Cache.nc"
static void /*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$Cache$insert(/*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$Cache$t item);







static bool /*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$Cache$lookup(/*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$Cache$t item);
# 62 "/opt/tinyos-2.1.2/tos/interfaces/Init.nc"
static error_t /*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$Init$init(void );
# 78 "/opt/tinyos-2.1.2/tos/interfaces/Receive.nc"
static 
#line 74
message_t * 



LinkEstimatorP$SubReceive$receive(
#line 71
message_t * msg, 
void * payload, 





uint8_t len);
# 62 "../net/net_EER_sim/4bitle/LinkEstimator.nc"
static error_t LinkEstimatorP$LinkEstimator$txAck(am_addr_t neighbor);
#line 55
static error_t LinkEstimatorP$LinkEstimator$pinNeighbor(am_addr_t neighbor);










static error_t LinkEstimatorP$LinkEstimator$txNoAck(am_addr_t neighbor);
#line 52
static error_t LinkEstimatorP$LinkEstimator$insertNeighbor(am_addr_t neighbor);
#line 69
static error_t LinkEstimatorP$LinkEstimator$clearDLQ(am_addr_t neighbor);
#line 58
static error_t LinkEstimatorP$LinkEstimator$unpinNeighbor(am_addr_t neighbor);
#line 49
static uint16_t LinkEstimatorP$LinkEstimator$getLinkQuality(uint16_t neighbor);
# 78 "/opt/tinyos-2.1.2/tos/interfaces/Packet.nc"
static uint8_t LinkEstimatorP$Packet$payloadLength(
#line 74
message_t * msg);
#line 126
static 
#line 123
void * 


LinkEstimatorP$Packet$getPayload(
#line 121
message_t * msg, 




uint8_t len);
#line 106
static uint8_t LinkEstimatorP$Packet$maxPayloadLength(void );
# 110 "/opt/tinyos-2.1.2/tos/interfaces/AMSend.nc"
static void LinkEstimatorP$AMSend$sendDone(
#line 103
message_t * msg, 






error_t error);
#line 80
static error_t LinkEstimatorP$Send$send(am_addr_t addr, 
#line 71
message_t * msg, 








uint8_t len);
#line 135
static 
#line 133
void * 

LinkEstimatorP$Send$getPayload(
#line 132
message_t * msg, 


uint8_t len);
#line 123
static uint8_t LinkEstimatorP$Send$maxPayloadLength(void );
# 62 "/opt/tinyos-2.1.2/tos/interfaces/Init.nc"
static error_t LinkEstimatorP$Init$init(void );
# 95 "/opt/tinyos-2.1.2/tos/interfaces/StdControl.nc"
static error_t LinkEstimatorP$StdControl$start(void );
# 80 "/opt/tinyos-2.1.2/tos/interfaces/AMSend.nc"
static error_t /*CtpP.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$0$AMSend$send(am_addr_t addr, 
#line 71
message_t * msg, 








uint8_t len);
#line 123
static uint8_t /*CtpP.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$0$AMSend$maxPayloadLength(void );
# 100 "/opt/tinyos-2.1.2/tos/interfaces/Send.nc"
static void /*CtpP.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$0$Send$sendDone(
#line 96
message_t * msg, 



error_t error);
# 110 "/opt/tinyos-2.1.2/tos/interfaces/AMSend.nc"
static void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$AMSend$sendDone(
# 48 "/opt/tinyos-2.1.2/tos/system/AMQueueImplP.nc"
am_id_t arg_0x40de7908, 
# 103 "/opt/tinyos-2.1.2/tos/interfaces/AMSend.nc"
message_t * msg, 






error_t error);
# 75 "/opt/tinyos-2.1.2/tos/interfaces/Send.nc"
static error_t /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Send$send(
# 46 "/opt/tinyos-2.1.2/tos/system/AMQueueImplP.nc"
uint8_t arg_0x40deae70, 
# 67 "/opt/tinyos-2.1.2/tos/interfaces/Send.nc"
message_t * msg, 







uint8_t len);
#line 112
static uint8_t /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Send$maxPayloadLength(
# 46 "/opt/tinyos-2.1.2/tos/system/AMQueueImplP.nc"
uint8_t arg_0x40deae70);
# 100 "/opt/tinyos-2.1.2/tos/interfaces/Send.nc"
static void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Send$default$sendDone(
# 46 "/opt/tinyos-2.1.2/tos/system/AMQueueImplP.nc"
uint8_t arg_0x40deae70, 
# 96 "/opt/tinyos-2.1.2/tos/interfaces/Send.nc"
message_t * msg, 



error_t error);
# 75 "/opt/tinyos-2.1.2/tos/interfaces/TaskBasic.nc"
static void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$errorTask$runTask(void );
#line 75
static void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$CancelTask$runTask(void );
# 43 "../net/net_EER_sim/RootControl.nc"
static bool /*CtpP.Router*/EerParentSetEngineP$0$RootControl$isRoot(void );
#line 41
static error_t /*CtpP.Router*/EerParentSetEngineP$0$RootControl$setRoot(void );
# 75 "/opt/tinyos-2.1.2/tos/interfaces/TaskBasic.nc"
static void /*CtpP.Router*/EerParentSetEngineP$0$updateRouteTask$runTask(void );
# 79 "../net/net_EER_sim/CollectionDebug.nc"
static error_t /*CtpP.Router*/EerParentSetEngineP$0$CollectionDebug$default$logEventRoute(uint8_t type, am_addr_t parent, uint8_t hopcount, uint16_t metric);
#line 67
static error_t /*CtpP.Router*/EerParentSetEngineP$0$CollectionDebug$default$logEventDbg(uint8_t type, uint16_t arg1, uint16_t arg2, uint16_t arg3);
# 72 "../net/net_EER_sim/4bitle/LinkEstimator.nc"
static void /*CtpP.Router*/EerParentSetEngineP$0$LinkEstimator$evicted(am_addr_t neighbor);
# 46 "../net/net_EER_sim/eer/CtpRoutingPacket.nc"
static bool /*CtpP.Router*/EerParentSetEngineP$0$CtpRoutingPacket$getOption(message_t * msg, ctp_options_t opt);
# 113 "/opt/tinyos-2.1.2/tos/interfaces/SplitControl.nc"
static void /*CtpP.Router*/EerParentSetEngineP$0$RadioControl$startDone(error_t error);
#line 138
static void /*CtpP.Router*/EerParentSetEngineP$0$RadioControl$stopDone(error_t error);
# 71 "../net/net_EER_sim/eer/CtpInfo.nc"
static void /*CtpP.Router*/EerParentSetEngineP$0$CtpInfo$recomputeRoutes(void );
#line 59
static void /*CtpP.Router*/EerParentSetEngineP$0$CtpInfo$triggerRouteUpdate(void );
#line 52
static error_t /*CtpP.Router*/EerParentSetEngineP$0$CtpInfo$getEtx(uint16_t *etx);
#line 66
static void /*CtpP.Router*/EerParentSetEngineP$0$CtpInfo$triggerImmediateRouteUpdate(void );









static void /*CtpP.Router*/EerParentSetEngineP$0$CtpInfo$setNeighborCongested(am_addr_t n, bool congested);
#line 42
static error_t /*CtpP.Router*/EerParentSetEngineP$0$CtpInfo$getParent(am_addr_t *parent);
#line 91
static uint16_t /*CtpP.Router*/EerParentSetEngineP$0$CtpInfo$getNeighborEtx(am_addr_t n);
# 62 "/opt/tinyos-2.1.2/tos/interfaces/Init.nc"
static error_t /*CtpP.Router*/EerParentSetEngineP$0$Init$init(void );
# 110 "/opt/tinyos-2.1.2/tos/interfaces/AMSend.nc"
static void /*CtpP.Router*/EerParentSetEngineP$0$BeaconSend$sendDone(
#line 103
message_t * msg, 






error_t error);
# 75 "/opt/tinyos-2.1.2/tos/interfaces/TaskBasic.nc"
static void /*CtpP.Router*/EerParentSetEngineP$0$sendBeaconTask$runTask(void );
# 83 "/opt/tinyos-2.1.2/tos/lib/timer/Timer.nc"
static void /*CtpP.Router*/EerParentSetEngineP$0$BeaconTimer$fired(void );
#line 83
static void /*CtpP.Router*/EerParentSetEngineP$0$RouteTimer$fired(void );
# 43 "../net/net_EER_sim/eer/CompareBit.nc"
static bool /*CtpP.Router*/EerParentSetEngineP$0$CompareBit$shouldInsert(message_t * msg, void * payload, uint8_t len);
# 78 "/opt/tinyos-2.1.2/tos/interfaces/Receive.nc"
static 
#line 74
message_t * 



/*CtpP.Router*/EerParentSetEngineP$0$BeaconReceive$receive(
#line 71
message_t * msg, 
void * payload, 





uint8_t len);
# 95 "/opt/tinyos-2.1.2/tos/interfaces/StdControl.nc"
static error_t /*CtpP.Router*/EerParentSetEngineP$0$StdControl$start(void );
# 49 "../net/net_EER_sim/UnicastNameFreeRouting.nc"
static bool /*CtpP.Router*/EerParentSetEngineP$0$Routing$hasRoute(void );
#line 48
static am_addr_t /*CtpP.Router*/EerParentSetEngineP$0$Routing$nextHop(void );
# 43 "../net/net_EER_sim/eer_parentselection/EerParentSelectionConfig.nc"
static error_t /*CtpP.ParentSelector*/EerParentSelectionP$0$EerParentSelectionConfig$addParentCandidate(routing_table_entry *entry, __nesc_nxbase_nx_uint16_t candETX);

static am_addr_t /*CtpP.ParentSelector*/EerParentSelectionP$0$EerParentSelectionConfig$drawRandomParent(void );
#line 41
static void /*CtpP.ParentSelector*/EerParentSelectionP$0$EerParentSelectionConfig$initializeParentSet(void );





static error_t /*CtpP.ParentSelector*/EerParentSelectionP$0$EerParentSelectionConfig$getParentSetETX(nx_uint16_t *parentSetETX, nx_uint8_t *parentSetSize);

static __nesc_nxbase_nx_uint8_t /*CtpP.ParentSelector*/EerParentSelectionP$0$EerParentSelectionConfig$getParentSetSize(void );
# 41 "../net/net_EER_sim/eer_parentselection/EerParentSelectionHealth.nc"
static __nesc_nxbase_nx_uint8_t /*CtpP.ParentSelector*/EerParentSelectionP$0$EerParentSelectionHealth$getCandiateSetSize(void );
# 52 "/opt/tinyos-2.1.2/tos/interfaces/Random.nc"
static uint16_t RandomMlcgC$Random$rand16(void );
#line 46
static uint32_t RandomMlcgC$Random$rand32(void );
# 62 "/opt/tinyos-2.1.2/tos/interfaces/Init.nc"
static error_t RandomMlcgC$Init$init(void );
# 80 "/opt/tinyos-2.1.2/tos/interfaces/AMSend.nc"
static error_t /*CtpP.SendControl.SenderC.AMQueueEntryP*/AMQueueEntryP$1$AMSend$send(am_addr_t addr, 
#line 71
message_t * msg, 








uint8_t len);
# 100 "/opt/tinyos-2.1.2/tos/interfaces/Send.nc"
static void /*CtpP.SendControl.SenderC.AMQueueEntryP*/AMQueueEntryP$1$Send$sendDone(
#line 96
message_t * msg, 



error_t error);
# 47 "/opt/tinyos-2.1.2/tos/interfaces/LinkPacketMetadata.nc"
static bool DummyActiveMessageP$LinkPacketMetadata$highChannelQuality(
#line 44
message_t * msg);
# 45 "../net/net_EER_sim/eer/EerInstrumentation.nc"
static error_t EerInstrumentationP$EerInstrumentation$ctrl_tricklereset(void );




static error_t EerInstrumentationP$EerInstrumentation$data_pktdup(void );
#line 42
static error_t EerInstrumentationP$EerInstrumentation$ctrl_txpkt(void );










static error_t EerInstrumentationP$EerInstrumentation$init(void );
#line 49
static error_t EerInstrumentationP$EerInstrumentation$data_queuedrop(void );
#line 46
static error_t EerInstrumentationP$EerInstrumentation$data_txpkt(void );
static error_t EerInstrumentationP$EerInstrumentation$data_rxpkt(void );
#line 43
static error_t EerInstrumentationP$EerInstrumentation$ctrl_rxpkt(void );




static error_t EerInstrumentationP$EerInstrumentation$data_rxack(void );


static error_t EerInstrumentationP$EerInstrumentation$data_inconsistent(void );
#line 44
static error_t EerInstrumentationP$EerInstrumentation$ctrl_parentchange(void );
# 48 "../net/net_EER_sim/eer/EerHealth.nc"
static error_t EerHealthP$EerHealth$get_hlth_forwarded(nx_uint16_t *fwd);
#line 47
static error_t EerHealthP$EerHealth$hlth_forwarded(void );
#line 42
static error_t EerHealthP$EerHealth$init(void );

static error_t EerHealthP$EerHealth$hlth_generated(void );
static error_t EerHealthP$EerHealth$get_hlth_generated(nx_uint16_t *gen);





static error_t EerHealthP$EerHealth$get_hlth_retx(nx_uint16_t *retx);




static error_t EerHealthP$EerHealth$get_hlth_psetSize(nx_uint8_t *psetSize);
#line 50
static error_t EerHealthP$EerHealth$hlth_retx(void );



static error_t EerHealthP$EerHealth$get_hlth_dropped(nx_uint16_t *drp);
#line 53
static error_t EerHealthP$EerHealth$hlth_dropped(void );
# 46 "../net/net_EER_sim/CollectionId.nc"
static collection_id_t /*LapTestAppC.CtpDataSenderC.CollectionSenderP.CollectionIdP*/CollectionIdP$0$CollectionId$fetch(void );
# 41 "../net/net_EER_sim/RootControl.nc"
static error_t LapTestC$RootControl$setRoot(void );
# 75 "/opt/tinyos-2.1.2/tos/interfaces/Send.nc"
static error_t LapTestC$DataSend$send(
#line 67
message_t * msg, 







uint8_t len);
#line 125
static 
#line 123
void * 

LapTestC$DataSend$getPayload(
#line 122
message_t * msg, 


uint8_t len);
# 95 "/opt/tinyos-2.1.2/tos/interfaces/StdControl.nc"
static error_t LapTestC$CtpControl$start(void );
# 104 "/opt/tinyos-2.1.2/tos/interfaces/SplitControl.nc"
static error_t LapTestC$RadioControl$start(void );
# 64 "/opt/tinyos-2.1.2/tos/lib/timer/Timer.nc"
static void LapTestC$DataTimer$startPeriodic(uint32_t dt);
# 42 "../net/net_EER_sim/eer/CtpInfo.nc"
static error_t LapTestC$CtpInfo$getParent(am_addr_t *parent);
# 60 "../net/net_EER_sim/eer/CtpPacket.nc"
static am_addr_t LapTestC$CtpPacket$getOrigin(message_t *msg);
#line 54
static uint8_t LapTestC$CtpPacket$getThl(message_t *msg);








static uint8_t LapTestC$CtpPacket$getSequenceNumber(message_t *msg);
# 88 "/opt/tinyos-2.1.2/tos/interfaces/AMPacket.nc"
static am_addr_t LapTestC$AMPacket$source(
#line 84
message_t * amsg);
# 67 "/opt/tinyos-2.1.2/tos/interfaces/TaskBasic.nc"
static error_t LapTestC$sendDataMessage$postTask(void );
# 67 "LapTestC.nc"
enum LapTestC$__nesc_unnamed4351 {
#line 67
  LapTestC$sendDataMessage = 0U
};
#line 67
typedef int LapTestC$__nesc_sillytask_sendDataMessage[LapTestC$sendDataMessage];
#line 27
message_t LapTestC$data_pkt[1000];

bool LapTestC$radioBusy[1000];
uint16_t LapTestC$rounds[1000];
uint8_t LapTestC$i[1000];


uint16_t LapTestC$counter[1000];
am_addr_t LapTestC$parent[1000];


static inline void LapTestC$Boot$booted(void );





static inline void LapTestC$RadioControl$startDone(error_t err);
#line 67
static inline void LapTestC$sendDataMessage$runTask(void );
#line 91
static inline void LapTestC$DataTimer$fired(void );










static inline bool LapTestC$DataIntercept$forward(message_t *msg, void *payload, uint8_t len);
#line 121
static message_t *LapTestC$DataReceive$receive(message_t *msg, void *payload, uint8_t len);
#line 158
static inline void LapTestC$DataSend$sendDone(message_t *msg, error_t err);










static inline void LapTestC$RadioControl$stopDone(error_t err);
# 62 "/opt/tinyos-2.1.2/tos/interfaces/Init.nc"
static error_t PlatformP$MoteInit$init(void );
#line 62
static error_t PlatformP$MeasureClock$init(void );
# 51 "/opt/tinyos-2.1.2/tos/platforms/mica/PlatformP.nc"
static inline error_t PlatformP$Init$init(void );
# 62 "/opt/tinyos-2.1.2/tos/interfaces/Init.nc"
static error_t MotePlatformP$SubInit$init(void );
# 44 "/opt/tinyos-2.1.2/tos/interfaces/GeneralIO.nc"
static void MotePlatformP$SerialIdPin$makeInput(void );
#line 41
static void MotePlatformP$SerialIdPin$clr(void );
# 49 "/opt/tinyos-2.1.2/tos/platforms/micaz/MotePlatformP.nc"
static inline error_t MotePlatformP$PlatformInit$init(void );
#line 61
static inline error_t MotePlatformP$SubInit$default$init(void );
# 55 "/opt/tinyos-2.1.2/tos/chips/atm128/pins/sim/HplAtm128GeneralIOPinP.nc"
static __inline void /*HplAtm128GeneralIOC.PortA.Bit0*/HplAtm128GeneralIOPinP$0$IO$set(void );







static __inline void /*HplAtm128GeneralIOC.PortA.Bit0*/HplAtm128GeneralIOPinP$0$IO$makeOutput(void );
#line 55
static __inline void /*HplAtm128GeneralIOC.PortA.Bit1*/HplAtm128GeneralIOPinP$1$IO$set(void );







static __inline void /*HplAtm128GeneralIOC.PortA.Bit1*/HplAtm128GeneralIOPinP$1$IO$makeOutput(void );
#line 55
static __inline void /*HplAtm128GeneralIOC.PortA.Bit2*/HplAtm128GeneralIOPinP$2$IO$set(void );







static __inline void /*HplAtm128GeneralIOC.PortA.Bit2*/HplAtm128GeneralIOPinP$2$IO$makeOutput(void );
#line 59
static __inline void /*HplAtm128GeneralIOC.PortA.Bit4*/HplAtm128GeneralIOPinP$4$IO$clr(void );


static __inline void /*HplAtm128GeneralIOC.PortA.Bit4*/HplAtm128GeneralIOPinP$4$IO$makeInput(void );
# 21 "/opt/tinyos-2.1.2/tos/platforms/mica/sim/MeasureClockC.nc"
static inline error_t MeasureClockC$Init$init(void );
# 62 "/opt/tinyos-2.1.2/tos/interfaces/Init.nc"
static error_t SimMainP$SoftwareInit$init(void );
# 60 "/opt/tinyos-2.1.2/tos/interfaces/Boot.nc"
static void SimMainP$Boot$booted(void );
# 62 "/opt/tinyos-2.1.2/tos/interfaces/Init.nc"
static error_t SimMainP$PlatformInit$init(void );
# 57 "/opt/tinyos-2.1.2/tos/interfaces/Scheduler.nc"
static void SimMainP$Scheduler$init(void );







static bool SimMainP$Scheduler$runNextTask(void );
# 51 "/opt/tinyos-2.1.2/tos/lib/tossim/SimMainP.nc"
int sim_main_start_mote(void )   ;
# 75 "/opt/tinyos-2.1.2/tos/interfaces/TaskBasic.nc"
static void SimSchedulerBasicP$TaskBasic$runTask(
# 49 "/opt/tinyos-2.1.2/tos/lib/tossim/SimSchedulerBasicP.nc"
uint8_t arg_0x406e11b8);



enum SimSchedulerBasicP$__nesc_unnamed4352 {

  SimSchedulerBasicP$NUM_TASKS = 11U, 
  SimSchedulerBasicP$NO_TASK = 255
};

uint8_t SimSchedulerBasicP$m_head[1000];
uint8_t SimSchedulerBasicP$m_tail[1000];
uint8_t SimSchedulerBasicP$m_next[1000][SimSchedulerBasicP$NUM_TASKS];




bool SimSchedulerBasicP$sim_scheduler_event_pending[1000];
sim_event_t SimSchedulerBasicP$sim_scheduler_event[1000];

static inline int SimSchedulerBasicP$sim_config_task_latency(void );







static void SimSchedulerBasicP$sim_scheduler_submit_event(void );







static inline void SimSchedulerBasicP$sim_scheduler_event_handle(sim_event_t *e);
#line 103
static inline void SimSchedulerBasicP$sim_scheduler_event_init(sim_event_t *e);
#line 120
static inline uint8_t SimSchedulerBasicP$popTask(void );
#line 139
static inline bool SimSchedulerBasicP$isWaiting(uint8_t id);




static inline bool SimSchedulerBasicP$pushTask(uint8_t id);
#line 166
static inline void SimSchedulerBasicP$Scheduler$init(void );
#line 180
static bool SimSchedulerBasicP$Scheduler$runNextTask(void );
#line 205
static error_t SimSchedulerBasicP$TaskBasic$postTask(uint8_t id);
#line 221
static inline void SimSchedulerBasicP$TaskBasic$default$runTask(uint8_t id);
# 50 "/opt/tinyos-2.1.2/tos/lib/tossim/SimMoteP.nc"
long long int SimMoteP$euid[1000];
long long int SimMoteP$startTime[1000];
bool SimMoteP$isOn[1000];
sim_event_t *SimMoteP$bootEvent[1000];

static inline long long int SimMoteP$SimMote$getEuid(void );


static inline void SimMoteP$SimMote$setEuid(long long int e);


static inline long long int SimMoteP$SimMote$getStartTime(void );


static inline bool SimMoteP$SimMote$isOn(void );



static inline int SimMoteP$SimMote$getVariableInfo(char *name, void **addr, size_t *size);



static void SimMoteP$SimMote$turnOn(void );
#line 85
static inline void SimMoteP$SimMote$turnOff(void );




long long int sim_mote_euid(int mote)   ;








void sim_mote_set_euid(int mote, long long int id)   ;






long long int sim_mote_start_time(int mote)   ;








int sim_mote_get_variable_info(int mote, char *name, void **ptr, size_t *len)   ;









void sim_mote_set_start_time(int mote, long long int t)   ;








bool sim_mote_is_on(int mote)   ;








void sim_mote_turn_on(int mote)   ;






void sim_mote_turn_off(int mote)   ;






static inline void SimMoteP$sim_mote_boot_handle(sim_event_t *e);








void sim_mote_enqueue_boot_event(int mote)   ;
# 57 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimActiveMessageC.nc"
static am_addr_t TossimActiveMessageC$amAddress(void );
# 110 "/opt/tinyos-2.1.2/tos/interfaces/AMSend.nc"
static void TossimActiveMessageC$AMSend$sendDone(
# 47 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimActiveMessageC.nc"
am_id_t arg_0x408eb4b0, 
# 103 "/opt/tinyos-2.1.2/tos/interfaces/AMSend.nc"
message_t * msg, 






error_t error);
# 78 "/opt/tinyos-2.1.2/tos/interfaces/Receive.nc"
static 
#line 74
message_t * 



TossimActiveMessageC$Snoop$receive(
# 49 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimActiveMessageC.nc"
am_id_t arg_0x408ea5b8, 
# 71 "/opt/tinyos-2.1.2/tos/interfaces/Receive.nc"
message_t * msg, 
void * payload, 





uint8_t len);
#line 78
static 
#line 74
message_t * 



TossimActiveMessageC$Receive$receive(
# 48 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimActiveMessageC.nc"
am_id_t arg_0x408ebe70, 
# 71 "/opt/tinyos-2.1.2/tos/interfaces/Receive.nc"
message_t * msg, 
void * payload, 





uint8_t len);
# 57 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimPacketModel.nc"
static error_t TossimActiveMessageC$Model$send(int node, message_t *msg, uint8_t len);
# 62 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimActiveMessageC.nc"
message_t TossimActiveMessageC$buffer[1000];
message_t *TossimActiveMessageC$bufferPointer[1000];

static inline tossim_header_t *TossimActiveMessageC$getHeader(message_t *amsg);







static error_t TossimActiveMessageC$AMSend$send(am_id_t id, am_addr_t addr, 
message_t *amsg, 
uint8_t len);
#line 91
static inline uint8_t TossimActiveMessageC$AMSend$maxPayloadLength(am_id_t id);
#line 103
static inline void TossimActiveMessageC$Model$sendDone(message_t *msg, error_t result);





static void TossimActiveMessageC$Model$receive(message_t *msg);
#line 127
static inline bool TossimActiveMessageC$Model$shouldAck(message_t *msg);








static inline am_addr_t TossimActiveMessageC$AMPacket$address(void );



static am_addr_t TossimActiveMessageC$AMPacket$destination(message_t *amsg);




static void TossimActiveMessageC$AMPacket$setDestination(message_t *amsg, am_addr_t addr);




static am_addr_t TossimActiveMessageC$AMPacket$source(message_t *amsg);









static inline bool TossimActiveMessageC$AMPacket$isForMe(message_t *amsg);




static am_id_t TossimActiveMessageC$AMPacket$type(message_t *amsg);




static void TossimActiveMessageC$AMPacket$setType(message_t *amsg, am_id_t t);






static inline uint8_t TossimActiveMessageC$Packet$payloadLength(message_t *msg);



static inline void TossimActiveMessageC$Packet$setPayloadLength(message_t *msg, uint8_t len);



static inline uint8_t TossimActiveMessageC$Packet$maxPayloadLength(void );



static inline void *TossimActiveMessageC$Packet$getPayload(message_t *msg, uint8_t len);
#line 212
static inline message_t *TossimActiveMessageC$Receive$default$receive(am_id_t id, message_t *msg, void *payload, uint8_t len);



static inline message_t *TossimActiveMessageC$Snoop$default$receive(am_id_t id, message_t *msg, void *payload, uint8_t len);
#line 236
static inline void TossimActiveMessageC$active_message_deliver_handle(sim_event_t *evt);





static inline sim_event_t *TossimActiveMessageC$allocate_deliver_event(int node, message_t *msg, sim_time_t t);
#line 254
void active_message_deliver(int node, message_t *msg, sim_time_t t)   ;
# 85 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimPacketModel.nc"
static void TossimPacketModelC$Packet$receive(message_t *msg);
#line 76
static void TossimPacketModelC$Packet$sendDone(message_t *msg, error_t error);










static bool TossimPacketModelC$Packet$shouldAck(message_t *msg);
# 67 "/opt/tinyos-2.1.2/tos/interfaces/TaskBasic.nc"
static error_t TossimPacketModelC$startDoneTask$postTask(void );
# 113 "/opt/tinyos-2.1.2/tos/interfaces/SplitControl.nc"
static void TossimPacketModelC$Control$startDone(error_t error);
#line 138
static void TossimPacketModelC$Control$stopDone(error_t error);
# 48 "/opt/tinyos-2.1.2/tos/lib/tossim/GainRadioModel.nc"
static void TossimPacketModelC$GainRadioModel$putOnAirTo(int dest, 
message_t *msg, 
bool ack, 
sim_time_t endTime, 
double gain, 
double reverseGain);


static bool TossimPacketModelC$GainRadioModel$clearChannel(void );
static void TossimPacketModelC$GainRadioModel$setPendingTransmission(void );
# 96 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimPacketModelC.nc"
enum TossimPacketModelC$__nesc_unnamed4353 {
#line 96
  TossimPacketModelC$startDoneTask = 1U
};
#line 96
typedef int TossimPacketModelC$__nesc_sillytask_startDoneTask[TossimPacketModelC$startDoneTask];




enum TossimPacketModelC$__nesc_unnamed4354 {
#line 101
  TossimPacketModelC$stopDoneTask = 2U
};
#line 101
typedef int TossimPacketModelC$__nesc_sillytask_stopDoneTask[TossimPacketModelC$stopDoneTask];
#line 145
enum TossimPacketModelC$__nesc_unnamed4355 {
#line 145
  TossimPacketModelC$sendDoneTask = 3U
};
#line 145
typedef int TossimPacketModelC$__nesc_sillytask_sendDoneTask[TossimPacketModelC$sendDoneTask];
#line 70
bool TossimPacketModelC$initialized[1000];
bool TossimPacketModelC$running[1000];
uint8_t TossimPacketModelC$backoffCount[1000];
uint8_t TossimPacketModelC$neededFreeSamples[1000];
message_t *TossimPacketModelC$sending[1000];
bool TossimPacketModelC$transmitting[1000];
uint8_t TossimPacketModelC$sendingLength[1000];
int TossimPacketModelC$destNode[1000];
sim_event_t TossimPacketModelC$sendEvent[1000];



static inline tossim_metadata_t *TossimPacketModelC$getMetadata(message_t *msg);



static inline error_t TossimPacketModelC$Init$init(void );









static inline void TossimPacketModelC$startDoneTask$runTask(void );




static inline void TossimPacketModelC$stopDoneTask$runTask(void );




static error_t TossimPacketModelC$Control$start(void );
#line 128
static inline error_t TossimPacketModelC$PacketAcknowledgements$requestAck(message_t *msg);
#line 140
static inline error_t TossimPacketModelC$PacketAcknowledgements$wasAcked(message_t *ack);




static inline void TossimPacketModelC$sendDoneTask$runTask(void );
#line 159
static inline void TossimPacketModelC$start_csma(void );

static inline error_t TossimPacketModelC$Packet$send(int dest, message_t *msg, uint8_t len);
#line 183
static inline void TossimPacketModelC$send_backoff(sim_event_t *evt);
static inline void TossimPacketModelC$send_transmit(sim_event_t *evt);
static inline void TossimPacketModelC$send_transmit_done(sim_event_t *evt);

static inline void TossimPacketModelC$start_csma(void );
#line 211
static inline void TossimPacketModelC$send_backoff(sim_event_t *evt);
#line 253
static inline void TossimPacketModelC$send_transmit(sim_event_t *evt);
#line 280
static inline void TossimPacketModelC$send_transmit_done(sim_event_t *evt);







static inline void TossimPacketModelC$GainRadioModel$receive(message_t *msg);





uint8_t TossimPacketModelC$error[1000];

static inline void TossimPacketModelC$GainRadioModel$acked(message_t *msg);










static bool TossimPacketModelC$GainRadioModel$shouldAck(message_t *msg);
# 60 "/opt/tinyos-2.1.2/tos/lib/tossim/GainRadioModel.nc"
static void CpmModelC$Model$receive(message_t *msg);
#line 59
static void CpmModelC$Model$acked(message_t *msg);

static bool CpmModelC$Model$shouldAck(message_t *msg);
# 58 "/opt/tinyos-2.1.2/tos/lib/tossim/CpmModelC.nc"
message_t *CpmModelC$outgoing[1000];
bool CpmModelC$requestAck[1000];
bool CpmModelC$receiving[1000];
bool CpmModelC$transmitting[1000];
sim_time_t CpmModelC$transmissionEndTime[1000];
struct CpmModelC$receive_message;
typedef struct CpmModelC$receive_message CpmModelC$receive_message_t;

struct CpmModelC$receive_message {
  int source;
  sim_time_t start;
  sim_time_t end;
  double power;
  double reversePower;
  int8_t strength;
  bool lost;
  bool ack;
  message_t *msg;
  CpmModelC$receive_message_t *next;
};

CpmModelC$receive_message_t *CpmModelC$outstandingReceptionHead[1000];

static inline CpmModelC$receive_message_t *CpmModelC$allocate_receive_message(void );
static inline void CpmModelC$free_receive_message(CpmModelC$receive_message_t *msg);
static inline sim_event_t *CpmModelC$allocate_receive_event(sim_time_t t, CpmModelC$receive_message_t *m);

static bool CpmModelC$shouldReceive(double SNR);
static inline bool CpmModelC$checkReceive(CpmModelC$receive_message_t *msg);
static double CpmModelC$packetNoise(CpmModelC$receive_message_t *msg);


static inline double CpmModelC$timeInMs(void );
#line 126
static double CpmModelC$noise_hash_generation(void );
#line 151
static inline double CpmModelC$arr_estimate_from_snr(double SNR);
#line 166
static inline int CpmModelC$shouldAckReceive(double snr);
#line 178
static inline void CpmModelC$sim_gain_ack_handle(sim_event_t *evt);
#line 200
double CpmModelC$clearThreshold[1000];










static inline bool CpmModelC$Model$clearChannel(void );




static void CpmModelC$sim_gain_schedule_ack(int source, sim_time_t t, CpmModelC$receive_message_t *r);
#line 230
static inline double CpmModelC$prr_estimate_from_snr(double SNR);
#line 248
static bool CpmModelC$shouldReceive(double SNR);
#line 260
static inline bool CpmModelC$checkReceive(CpmModelC$receive_message_t *msg);
#line 274
static double CpmModelC$packetNoise(CpmModelC$receive_message_t *msg);
#line 296
static inline void CpmModelC$sim_gain_receive_handle(sim_event_t *evt);
#line 369
static inline void CpmModelC$enqueue_receive_event(int source, sim_time_t endTime, message_t *msg, bool receive, double power, double reversePower);
#line 428
static inline void CpmModelC$sim_gain_put(int dest, message_t *msg, sim_time_t endTime, bool receive, double power, double reversePower);







static inline void CpmModelC$Model$putOnAirTo(int dest, message_t *msg, bool ack, sim_time_t endTime, double power, double reversePower);
#line 459
static inline void CpmModelC$Model$setPendingTransmission(void );







static inline sim_event_t *CpmModelC$allocate_receive_event(sim_time_t endTime, CpmModelC$receive_message_t *msg);
#line 479
static inline CpmModelC$receive_message_t *CpmModelC$allocate_receive_message(void );



static inline void CpmModelC$free_receive_message(CpmModelC$receive_message_t *msg);
# 65 "/opt/tinyos-2.1.2/tos/lib/tossim/ActiveMessageAddressC.nc"
bool ActiveMessageAddressC$set[1000];
am_addr_t ActiveMessageAddressC$addr[1000];









static am_addr_t ActiveMessageAddressC$ActiveMessageAddress$amAddress(void );
#line 88
static inline am_addr_t ActiveMessageAddressC$amAddress(void );
# 46 "/opt/tinyos-2.1.2/tos/interfaces/GeneralIO.nc"
static void LedsP$Led0$makeOutput(void );
#line 40
static void LedsP$Led0$set(void );





static void LedsP$Led1$makeOutput(void );
#line 40
static void LedsP$Led1$set(void );





static void LedsP$Led2$makeOutput(void );
#line 40
static void LedsP$Led2$set(void );
# 56 "/opt/tinyos-2.1.2/tos/system/LedsP.nc"
static inline error_t LedsP$Init$init(void );
# 53 "/opt/tinyos-2.1.2/tos/chips/atm128/timer/HplAtm128TimerCtrl8.nc"
static Atm128_TIFR_t /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$TimerCtrl$getInterruptFlag(void );
#line 46
static void /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$TimerCtrl$setControl(Atm128TimerControl_t control);
# 78 "/opt/tinyos-2.1.2/tos/lib/timer/Alarm.nc"
static void /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Alarm$fired(void );
# 82 "/opt/tinyos-2.1.2/tos/lib/timer/Counter.nc"
static void /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Counter$overflow(void );
# 44 "/opt/tinyos-2.1.2/tos/chips/atm128/timer/HplAtm128TimerAsync.nc"
static int /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$TimerAsync$compareBusy(void );
#line 32
static void /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$TimerAsync$setTimer0Asynchronous(void );
# 48 "/opt/tinyos-2.1.2/tos/chips/atm128/timer/HplAtm128Compare.nc"
static /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Compare$size_type /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Compare$get(void );





static void /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Compare$set(/*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Compare$size_type t);










static void /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Compare$start(void );
# 61 "/opt/tinyos-2.1.2/tos/chips/atm128/timer/HplAtm128Timer.nc"
static /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Timer$timer_size /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Timer$get(void );
# 38 "/opt/tinyos-2.1.2/tos/chips/atm128/timer/Atm128AlarmAsyncP.nc"
uint8_t /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$set[1000];
uint32_t /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$t0[1000];
#line 39
uint32_t /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$dt[1000];
uint32_t /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$base[1000];



enum /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$__nesc_unnamed4356 {
  Atm128AlarmAsyncP$0$MINDT = 2, 
  Atm128AlarmAsyncP$0$MAXT = 230
};



static void /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$setInterrupt(void );


static inline error_t /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Init$init(void );
#line 74
static inline void /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$setOcr0(uint8_t n);
#line 90
static void /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$setInterrupt(void );
#line 149
static inline void /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Compare$fired(void );
#line 161
static uint32_t /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Counter$get(void );
#line 204
static inline void /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Alarm$stop(void );







static void /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Alarm$startAt(uint32_t nt0, uint32_t ndt);









static inline uint32_t /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Alarm$getNow(void );



static inline uint32_t /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Alarm$getAlarm(void );



static inline void /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Timer$overflow(void );
# 70 "/opt/tinyos-2.1.2/tos/chips/atm128/timer/HplAtm128Timer.nc"
static void HplAtm128Timer0AsyncP$Timer0$overflow(void );
# 58 "/opt/tinyos-2.1.2/tos/chips/atm128/timer/HplAtm128Compare.nc"
static void HplAtm128Timer0AsyncP$Compare$fired(void );
# 57 "/opt/tinyos-2.1.2/tos/chips/atm128/timer/sim/HplAtm128Timer0AsyncP.nc"
bool HplAtm128Timer0AsyncP$inOverflow[1000];




static inline void HplAtm128Timer0AsyncP$cancel_overflow(void );
static inline sim_event_t *HplAtm128Timer0AsyncP$allocate_overflow(void );
static void HplAtm128Timer0AsyncP$configure_overflow(sim_event_t *e);
static inline void HplAtm128Timer0AsyncP$schedule_new_overflow(void );

static inline sim_time_t HplAtm128Timer0AsyncP$clock_to_sim(sim_time_t t);
static inline sim_time_t HplAtm128Timer0AsyncP$sim_to_clock(sim_time_t t);
static uint16_t HplAtm128Timer0AsyncP$shiftFromScale(void );




sim_time_t HplAtm128Timer0AsyncP$lastZero[1000];





uint8_t HplAtm128Timer0AsyncP$oldScale[1000];



static inline void HplAtm128Timer0AsyncP$cancel_compare(void );
static inline sim_event_t *HplAtm128Timer0AsyncP$allocate_compare(void );
static void HplAtm128Timer0AsyncP$configure_compare(sim_event_t *e);
static void HplAtm128Timer0AsyncP$schedule_new_compare(void );

static inline sim_time_t HplAtm128Timer0AsyncP$clock_to_sim(sim_time_t t);
static inline sim_time_t HplAtm128Timer0AsyncP$sim_to_clock(sim_time_t t);
static uint16_t HplAtm128Timer0AsyncP$shiftFromScale(void );


void INTERRUPT_15(void )   ;





void INTERRUPT_16(void )   ;







static sim_time_t HplAtm128Timer0AsyncP$last_zero(void );







static inline void HplAtm128Timer0AsyncP$notify_changed(void );










static inline sim_time_t HplAtm128Timer0AsyncP$notify_clockTicksPerSec(void );
#line 148
static inline sim_time_t HplAtm128Timer0AsyncP$clock_to_sim(sim_time_t t);





static inline sim_time_t HplAtm128Timer0AsyncP$sim_to_clock(sim_time_t t);





static uint16_t HplAtm128Timer0AsyncP$shiftFromScale(void );
#line 185
sim_event_t *HplAtm128Timer0AsyncP$compare[1000];

static inline void HplAtm128Timer0AsyncP$timer0_compare_handle(sim_event_t *evt);
#line 223
static inline sim_event_t *HplAtm128Timer0AsyncP$allocate_compare(void );







static void HplAtm128Timer0AsyncP$configure_compare(sim_event_t *evt);
#line 267
static void HplAtm128Timer0AsyncP$schedule_new_compare(void );
#line 282
static uint8_t HplAtm128Timer0AsyncP$Timer0$get(void );
#line 297
static inline void HplAtm128Timer0AsyncP$Timer0$set(uint8_t newVal);
#line 321
static uint8_t HplAtm128Timer0AsyncP$Timer0$getScale(void );
#line 364
static inline void HplAtm128Timer0AsyncP$Timer0Ctrl$setControl(Atm128TimerControl_t x);
#line 383
static Atm128_TIFR_t HplAtm128Timer0AsyncP$Timer0Ctrl$getInterruptFlag(void );
#line 447
static inline void HplAtm128Timer0AsyncP$Compare$start(void );









static uint8_t HplAtm128Timer0AsyncP$Compare$get(void );





static void HplAtm128Timer0AsyncP$Compare$set(uint8_t t);
#line 480
sim_event_t *HplAtm128Timer0AsyncP$overflow[1000];
static inline void HplAtm128Timer0AsyncP$timer0_overflow_handle(sim_event_t *evt);
#line 500
static inline sim_event_t *HplAtm128Timer0AsyncP$allocate_overflow(void );







static void HplAtm128Timer0AsyncP$configure_overflow(sim_event_t *evt);
#line 534
static inline void HplAtm128Timer0AsyncP$schedule_new_overflow(void );










static inline void HplAtm128Timer0AsyncP$cancel_overflow(void );
#line 561
static inline void HplAtm128Timer0AsyncP$TimerAsync$setTimer0Asynchronous(void );







static inline int HplAtm128Timer0AsyncP$TimerAsync$compareBusy(void );







static inline void HplAtm128Timer0AsyncP$cancel_compare(void );
# 67 "/opt/tinyos-2.1.2/tos/interfaces/TaskBasic.nc"
static error_t /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$fired$postTask(void );
# 109 "/opt/tinyos-2.1.2/tos/lib/timer/Alarm.nc"
static /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Alarm$size_type /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Alarm$getNow(void );
#line 103
static void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Alarm$startAt(/*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Alarm$size_type t0, /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Alarm$size_type dt);
#line 116
static /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Alarm$size_type /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Alarm$getAlarm(void );
#line 73
static void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Alarm$stop(void );
# 83 "/opt/tinyos-2.1.2/tos/lib/timer/Timer.nc"
static void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Timer$fired(void );
# 74 "/opt/tinyos-2.1.2/tos/lib/timer/AlarmToTimerC.nc"
enum /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$__nesc_unnamed4357 {
#line 74
  AlarmToTimerC$0$fired = 4U
};
#line 74
typedef int /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$__nesc_sillytask_fired[/*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$fired];
#line 55
uint32_t /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$m_dt[1000];
bool /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$m_oneshot[1000];

static inline void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$start(uint32_t t0, uint32_t dt, bool oneshot);
#line 71
static inline void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Timer$stop(void );


static inline void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$fired$runTask(void );






static inline void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Alarm$fired(void );
#line 93
static inline void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Timer$startOneShotAt(uint32_t t0, uint32_t dt);


static inline uint32_t /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Timer$getNow(void );
# 67 "/opt/tinyos-2.1.2/tos/interfaces/TaskBasic.nc"
static error_t /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$updateFromTimer$postTask(void );
# 136 "/opt/tinyos-2.1.2/tos/lib/timer/Timer.nc"
static uint32_t /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$TimerFrom$getNow(void );
#line 129
static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$TimerFrom$startOneShotAt(uint32_t t0, uint32_t dt);
#line 78
static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$TimerFrom$stop(void );




static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$fired(
# 48 "/opt/tinyos-2.1.2/tos/lib/timer/VirtualizeTimerC.nc"
uint8_t arg_0x40b67c70);
#line 71
enum /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$__nesc_unnamed4358 {
#line 71
  VirtualizeTimerC$0$updateFromTimer = 5U
};
#line 71
typedef int /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$__nesc_sillytask_updateFromTimer[/*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$updateFromTimer];
#line 53
enum /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$__nesc_unnamed4359 {

  VirtualizeTimerC$0$NUM_TIMERS = 4U, 
  VirtualizeTimerC$0$END_OF_LIST = 255
};








#line 59
typedef struct /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$__nesc_unnamed4360 {

  uint32_t t0;
  uint32_t dt;
  bool isoneshot : 1;
  bool isrunning : 1;
  bool _reserved : 6;
} /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer_t;

/*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer_t /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$m_timers[1000][/*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$NUM_TIMERS];




static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$fireTimers(uint32_t now);
#line 100
static inline void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$updateFromTimer$runTask(void );
#line 139
static inline void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$TimerFrom$fired(void );




static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$startTimer(uint8_t num, uint32_t t0, uint32_t dt, bool isoneshot);









static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$startPeriodic(uint8_t num, uint32_t dt);




static inline void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$startOneShot(uint8_t num, uint32_t dt);




static inline void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$stop(uint8_t num);




static inline bool /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$isRunning(uint8_t num);
#line 204
static inline void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$default$fired(uint8_t num);
# 58 "/opt/tinyos-2.1.2/tos/lib/timer/CounterToLocalTimeC.nc"
static inline void /*HilTimerMilliC.CounterToLocalTimeC*/CounterToLocalTimeC$0$Counter$overflow(void );
# 43 "../net/net_EER_sim/RootControl.nc"
static bool /*CtpP.Forwarder*/CtpForwardingEngineP$0$RootControl$isRoot(void );
# 80 "/opt/tinyos-2.1.2/tos/interfaces/AMSend.nc"
static error_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$SubSend$send(am_addr_t addr, 
#line 71
message_t * msg, 








uint8_t len);
#line 123
static uint8_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$SubSend$maxPayloadLength(void );
# 61 "../net/net_EER_sim/CollectionDebug.nc"
static error_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$CollectionDebug$logEvent(uint8_t type);
#line 73
static error_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$CollectionDebug$logEventMsg(uint8_t type, uint16_t msg, am_addr_t origin, am_addr_t node);
# 62 "../net/net_EER_sim/4bitle/LinkEstimator.nc"
static error_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$LinkEstimator$txAck(am_addr_t neighbor);



static error_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$LinkEstimator$txNoAck(am_addr_t neighbor);
#line 49
static uint16_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$LinkEstimator$getLinkQuality(uint16_t neighbor);
# 51 "/opt/tinyos-2.1.2/tos/interfaces/Cache.nc"
static void /*CtpP.Forwarder*/CtpForwardingEngineP$0$SentCache$insert(/*CtpP.Forwarder*/CtpForwardingEngineP$0$SentCache$t item);







static bool /*CtpP.Forwarder*/CtpForwardingEngineP$0$SentCache$lookup(/*CtpP.Forwarder*/CtpForwardingEngineP$0$SentCache$t item);
# 31 "/opt/tinyos-2.1.2/tos/interfaces/Intercept.nc"
static bool /*CtpP.Forwarder*/CtpForwardingEngineP$0$Intercept$forward(
# 122 "../net/net_EER_sim/eer/CtpForwardingEngineP.nc"
collection_id_t arg_0x40bec430, 
# 20 "/opt/tinyos-2.1.2/tos/interfaces/Intercept.nc"
message_t * msg, 

void * payload, 








uint8_t len);
# 78 "/opt/tinyos-2.1.2/tos/interfaces/Receive.nc"
static 
#line 74
message_t * 



/*CtpP.Forwarder*/CtpForwardingEngineP$0$Snoop$receive(
# 121 "../net/net_EER_sim/eer/CtpForwardingEngineP.nc"
collection_id_t arg_0x40bc5d68, 
# 71 "/opt/tinyos-2.1.2/tos/interfaces/Receive.nc"
message_t * msg, 
void * payload, 





uint8_t len);
# 52 "/opt/tinyos-2.1.2/tos/interfaces/Random.nc"
static uint16_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$Random$rand16(void );
# 100 "/opt/tinyos-2.1.2/tos/interfaces/Send.nc"
static void /*CtpP.Forwarder*/CtpForwardingEngineP$0$Send$sendDone(
# 119 "../net/net_EER_sim/eer/CtpForwardingEngineP.nc"
uint8_t arg_0x40bc6c58, 
# 96 "/opt/tinyos-2.1.2/tos/interfaces/Send.nc"
message_t * msg, 



error_t error);
# 92 "/opt/tinyos-2.1.2/tos/lib/timer/Timer.nc"
static bool /*CtpP.Forwarder*/CtpForwardingEngineP$0$RetxmitTimer$isRunning(void );
#line 73
static void /*CtpP.Forwarder*/CtpForwardingEngineP$0$RetxmitTimer$startOneShot(uint32_t dt);
# 67 "/opt/tinyos-2.1.2/tos/interfaces/TaskBasic.nc"
static error_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$sendTask$postTask(void );
# 73 "/opt/tinyos-2.1.2/tos/interfaces/Queue.nc"
static 
#line 71
/*CtpP.Forwarder*/CtpForwardingEngineP$0$SendQueue$t  

/*CtpP.Forwarder*/CtpForwardingEngineP$0$SendQueue$head(void );
#line 90
static error_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$SendQueue$enqueue(
#line 86
/*CtpP.Forwarder*/CtpForwardingEngineP$0$SendQueue$t  newVal);
#line 101
static 
#line 99
/*CtpP.Forwarder*/CtpForwardingEngineP$0$SendQueue$t  

/*CtpP.Forwarder*/CtpForwardingEngineP$0$SendQueue$element(uint8_t idx);
#line 81
static 
#line 79
/*CtpP.Forwarder*/CtpForwardingEngineP$0$SendQueue$t  

/*CtpP.Forwarder*/CtpForwardingEngineP$0$SendQueue$dequeue(void );
#line 50
static bool /*CtpP.Forwarder*/CtpForwardingEngineP$0$SendQueue$empty(void );







static uint8_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$SendQueue$size(void );
# 71 "../net/net_EER_sim/eer/CtpInfo.nc"
static void /*CtpP.Forwarder*/CtpForwardingEngineP$0$CtpInfo$recomputeRoutes(void );
#line 59
static void /*CtpP.Forwarder*/CtpForwardingEngineP$0$CtpInfo$triggerRouteUpdate(void );
#line 52
static error_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$CtpInfo$getEtx(uint16_t *etx);
#line 66
static void /*CtpP.Forwarder*/CtpForwardingEngineP$0$CtpInfo$triggerImmediateRouteUpdate(void );









static void /*CtpP.Forwarder*/CtpForwardingEngineP$0$CtpInfo$setNeighborCongested(am_addr_t n, bool congested);
#line 42
static error_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$CtpInfo$getParent(am_addr_t *parent);
#line 91
static uint16_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$CtpInfo$getNeighborEtx(am_addr_t n);
# 78 "/opt/tinyos-2.1.2/tos/interfaces/Packet.nc"
static uint8_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$SubPacket$payloadLength(
#line 74
message_t * msg);
#line 126
static 
#line 123
void * 


/*CtpP.Forwarder*/CtpForwardingEngineP$0$SubPacket$getPayload(
#line 121
message_t * msg, 




uint8_t len);
#line 106
static uint8_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$SubPacket$maxPayloadLength(void );
#line 94
static void /*CtpP.Forwarder*/CtpForwardingEngineP$0$SubPacket$setPayloadLength(
#line 90
message_t * msg, 



uint8_t len);
# 50 "../net/net_EER_sim/eer/EerInstrumentation.nc"
static error_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$EerInstrumentation$data_pktdup(void );


static error_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$EerInstrumentation$init(void );
#line 49
static error_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$EerInstrumentation$data_queuedrop(void );
#line 46
static error_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$EerInstrumentation$data_txpkt(void );
static error_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$EerInstrumentation$data_rxpkt(void );
static error_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$EerInstrumentation$data_rxack(void );


static error_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$EerInstrumentation$data_inconsistent(void );
# 78 "/opt/tinyos-2.1.2/tos/interfaces/Receive.nc"
static 
#line 74
message_t * 



/*CtpP.Forwarder*/CtpForwardingEngineP$0$Receive$receive(
# 120 "../net/net_EER_sim/eer/CtpForwardingEngineP.nc"
collection_id_t arg_0x40bc5680, 
# 71 "/opt/tinyos-2.1.2/tos/interfaces/Receive.nc"
message_t * msg, 
void * payload, 





uint8_t len);
# 49 "../net/net_EER_sim/UnicastNameFreeRouting.nc"
static bool /*CtpP.Forwarder*/CtpForwardingEngineP$0$UnicastNameFreeRouting$hasRoute(void );
#line 48
static am_addr_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$UnicastNameFreeRouting$nextHop(void );
# 59 "/opt/tinyos-2.1.2/tos/interfaces/PacketAcknowledgements.nc"
static error_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$PacketAcknowledgements$requestAck(
#line 53
message_t * msg);
#line 85
static bool /*CtpP.Forwarder*/CtpForwardingEngineP$0$PacketAcknowledgements$wasAcked(
#line 80
message_t * msg);
# 97 "/opt/tinyos-2.1.2/tos/interfaces/Pool.nc"
static 
#line 94
/*CtpP.Forwarder*/CtpForwardingEngineP$0$QEntryPool$t * 


/*CtpP.Forwarder*/CtpForwardingEngineP$0$QEntryPool$get(void );
#line 61
static bool /*CtpP.Forwarder*/CtpForwardingEngineP$0$QEntryPool$empty(void );
#line 89
static error_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$QEntryPool$put(
#line 85
/*CtpP.Forwarder*/CtpForwardingEngineP$0$QEntryPool$t * newVal);
# 48 "../net/net_EER_sim/eer/EerHealth.nc"
static error_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$EerHealth$get_hlth_forwarded(nx_uint16_t *fwd);
#line 47
static error_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$EerHealth$hlth_forwarded(void );
#line 42
static error_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$EerHealth$init(void );

static error_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$EerHealth$hlth_generated(void );
static error_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$EerHealth$get_hlth_generated(nx_uint16_t *gen);





static error_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$EerHealth$get_hlth_retx(nx_uint16_t *retx);




static error_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$EerHealth$get_hlth_psetSize(nx_uint8_t *psetSize);
#line 50
static error_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$EerHealth$hlth_retx(void );



static error_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$EerHealth$get_hlth_dropped(nx_uint16_t *drp);
#line 53
static error_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$EerHealth$hlth_dropped(void );
# 88 "/opt/tinyos-2.1.2/tos/interfaces/AMPacket.nc"
static am_addr_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$AMPacket$source(
#line 84
message_t * amsg);
#line 68
static am_addr_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$AMPacket$address(void );









static am_addr_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$AMPacket$destination(
#line 74
message_t * amsg);
# 97 "/opt/tinyos-2.1.2/tos/interfaces/Pool.nc"
static 
#line 94
/*CtpP.Forwarder*/CtpForwardingEngineP$0$MessagePool$t * 


/*CtpP.Forwarder*/CtpForwardingEngineP$0$MessagePool$get(void );
#line 61
static bool /*CtpP.Forwarder*/CtpForwardingEngineP$0$MessagePool$empty(void );
#line 89
static error_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$MessagePool$put(
#line 85
/*CtpP.Forwarder*/CtpForwardingEngineP$0$MessagePool$t * newVal);
# 46 "../net/net_EER_sim/CollectionId.nc"
static collection_id_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$CollectionId$fetch(
# 157 "../net/net_EER_sim/eer/CtpForwardingEngineP.nc"
uint8_t arg_0x40bfa010);
#line 300
enum /*CtpP.Forwarder*/CtpForwardingEngineP$0$__nesc_unnamed4361 {
#line 300
  CtpForwardingEngineP$0$sendTask = 6U
};
#line 300
typedef int /*CtpP.Forwarder*/CtpForwardingEngineP$0$__nesc_sillytask_sendTask[/*CtpP.Forwarder*/CtpForwardingEngineP$0$sendTask];
#line 223
static void /*CtpP.Forwarder*/CtpForwardingEngineP$0$startRetxmitTimer(uint16_t mask, uint16_t offset);
static inline void /*CtpP.Forwarder*/CtpForwardingEngineP$0$clearState(uint8_t state);
static inline bool /*CtpP.Forwarder*/CtpForwardingEngineP$0$hasState(uint8_t state);
static inline void /*CtpP.Forwarder*/CtpForwardingEngineP$0$setState(uint8_t state);


enum /*CtpP.Forwarder*/CtpForwardingEngineP$0$__nesc_unnamed4362 {
  CtpForwardingEngineP$0$QUEUE_CONGESTED = 0x1, 
  CtpForwardingEngineP$0$ROUTING_ON = 0x2, 
  CtpForwardingEngineP$0$RADIO_ON = 0x4, 
  CtpForwardingEngineP$0$ACK_PENDING = 0x8, 
  CtpForwardingEngineP$0$SENDING = 0x10
};


uint8_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$forwardingState[1000];




am_addr_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$lastParent[1000];



uint8_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$seqno[1000];

enum /*CtpP.Forwarder*/CtpForwardingEngineP$0$__nesc_unnamed4363 {
  CtpForwardingEngineP$0$CLIENT_COUNT = 1U
};






fe_queue_entry_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$clientEntries[1000][/*CtpP.Forwarder*/CtpForwardingEngineP$0$CLIENT_COUNT];
fe_queue_entry_t * /*CtpP.Forwarder*/CtpForwardingEngineP$0$clientPtrs[1000][/*CtpP.Forwarder*/CtpForwardingEngineP$0$CLIENT_COUNT];







message_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$loopbackMsg[1000];
message_t * /*CtpP.Forwarder*/CtpForwardingEngineP$0$loopbackMsgPtr[1000];


static inline error_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$Init$init(void );
#line 284
static inline error_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$StdControl$start(void );
#line 305
static inline void /*CtpP.Forwarder*/CtpForwardingEngineP$0$RadioControl$startDone(error_t err);









static void /*CtpP.Forwarder*/CtpForwardingEngineP$0$startRetxmitTimer(uint16_t window, uint16_t offset);
#line 328
static inline void /*CtpP.Forwarder*/CtpForwardingEngineP$0$UnicastNameFreeRouting$routeFound(void );




static inline void /*CtpP.Forwarder*/CtpForwardingEngineP$0$UnicastNameFreeRouting$noRoute(void );





static inline void /*CtpP.Forwarder*/CtpForwardingEngineP$0$RadioControl$stopDone(error_t err);





static inline ctp_data_header_t */*CtpP.Forwarder*/CtpForwardingEngineP$0$getHeader(message_t *m);
#line 360
static inline error_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$Send$send(uint8_t client, message_t *msg, uint8_t len);
#line 438
static inline uint8_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$Send$maxPayloadLength(uint8_t client);



static inline void */*CtpP.Forwarder*/CtpForwardingEngineP$0$Send$getPayload(uint8_t client, message_t *msg, uint8_t len);
#line 464
static inline void /*CtpP.Forwarder*/CtpForwardingEngineP$0$sendTask$runTask(void );
#line 670
static void /*CtpP.Forwarder*/CtpForwardingEngineP$0$packetComplete(fe_queue_entry_t *qe, message_t *msg, bool success);
#line 721
static void /*CtpP.Forwarder*/CtpForwardingEngineP$0$SubSend$sendDone(message_t *msg, error_t error);
#line 833
static inline message_t * /*CtpP.Forwarder*/CtpForwardingEngineP$0$forward(message_t * m);
#line 946
static inline message_t */*CtpP.Forwarder*/CtpForwardingEngineP$0$SubReceive$receive(message_t *msg, void *payload, uint8_t len);
#line 1218
static inline message_t */*CtpP.Forwarder*/CtpForwardingEngineP$0$SubSnoop$receive(message_t *msg, void *payload, uint8_t len);
#line 1235
static inline void /*CtpP.Forwarder*/CtpForwardingEngineP$0$RetxmitTimer$fired(void );






static inline bool /*CtpP.Forwarder*/CtpForwardingEngineP$0$CtpCongestion$isCongested(void );








static inline void /*CtpP.Forwarder*/CtpForwardingEngineP$0$LinkEstimator$evicted(am_addr_t neighbor);







static inline uint8_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$Packet$payloadLength(message_t *msg);



static inline void /*CtpP.Forwarder*/CtpForwardingEngineP$0$Packet$setPayloadLength(message_t *msg, uint8_t len);



static inline uint8_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$Packet$maxPayloadLength(void );



static void */*CtpP.Forwarder*/CtpForwardingEngineP$0$Packet$getPayload(message_t *msg, uint8_t len);








static am_addr_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$CollectionPacket$getOrigin(message_t *msg);

static uint8_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$CollectionPacket$getSequenceNumber(message_t *msg);





static inline uint8_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$CtpPacket$getType(message_t *msg);
static am_addr_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$CtpPacket$getOrigin(message_t *msg);
static inline uint16_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$CtpPacket$getEtx(message_t *msg);
static uint8_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$CtpPacket$getSequenceNumber(message_t *msg);
static uint8_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$CtpPacket$getThl(message_t *msg);
static inline void /*CtpP.Forwarder*/CtpForwardingEngineP$0$CtpPacket$setThl(message_t *msg, uint8_t thl);


static inline void /*CtpP.Forwarder*/CtpForwardingEngineP$0$CtpPacket$setEtx(message_t *msg, uint16_t e);

static bool /*CtpP.Forwarder*/CtpForwardingEngineP$0$CtpPacket$option(message_t *msg, ctp_options_t opt);


static inline void /*CtpP.Forwarder*/CtpForwardingEngineP$0$CtpPacket$setOption(message_t *msg, ctp_options_t opt);


static inline void /*CtpP.Forwarder*/CtpForwardingEngineP$0$CtpPacket$clearOption(message_t *msg, ctp_options_t opt);






static inline bool /*CtpP.Forwarder*/CtpForwardingEngineP$0$CtpPacket$matchInstance(message_t *m1, message_t *m2);
#line 1325
static inline void /*CtpP.Forwarder*/CtpForwardingEngineP$0$clearState(uint8_t state);


static inline bool /*CtpP.Forwarder*/CtpForwardingEngineP$0$hasState(uint8_t state);


static inline void /*CtpP.Forwarder*/CtpForwardingEngineP$0$setState(uint8_t state);






static inline 
#line 1337
void 
/*CtpP.Forwarder*/CtpForwardingEngineP$0$Send$default$sendDone(uint8_t client, message_t *msg, error_t error);



static inline 
#line 1341
bool 
/*CtpP.Forwarder*/CtpForwardingEngineP$0$Intercept$default$forward(collection_id_t collectid, message_t *msg, void *payload, 
uint8_t len);



static inline message_t *
/*CtpP.Forwarder*/CtpForwardingEngineP$0$Receive$default$receive(collection_id_t collectid, message_t *msg, void *payload, 
uint8_t len);



static inline message_t *
/*CtpP.Forwarder*/CtpForwardingEngineP$0$Snoop$default$receive(collection_id_t collectid, message_t *msg, void *payload, 
uint8_t len);



static inline collection_id_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$CollectionId$default$fetch(uint8_t client);







static inline error_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$CollectionDebug$default$logEvent(uint8_t type);








static inline error_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$CollectionDebug$default$logEventMsg(uint8_t type, uint16_t msg, am_addr_t origin, am_addr_t node);
# 60 "/opt/tinyos-2.1.2/tos/system/PoolP.nc"
uint8_t /*CtpP.MessagePoolP.PoolP*/PoolP$0$free[1000];
uint8_t /*CtpP.MessagePoolP.PoolP*/PoolP$0$index[1000];
/*CtpP.MessagePoolP.PoolP*/PoolP$0$pool_t * /*CtpP.MessagePoolP.PoolP*/PoolP$0$queue[1000][7];
/*CtpP.MessagePoolP.PoolP*/PoolP$0$pool_t /*CtpP.MessagePoolP.PoolP*/PoolP$0$pool[1000][7];

static inline error_t /*CtpP.MessagePoolP.PoolP*/PoolP$0$Init$init(void );









static inline bool /*CtpP.MessagePoolP.PoolP*/PoolP$0$Pool$empty(void );
#line 88
static inline /*CtpP.MessagePoolP.PoolP*/PoolP$0$pool_t */*CtpP.MessagePoolP.PoolP*/PoolP$0$Pool$get(void );
#line 103
static error_t /*CtpP.MessagePoolP.PoolP*/PoolP$0$Pool$put(/*CtpP.MessagePoolP.PoolP*/PoolP$0$pool_t *newVal);
#line 60
uint8_t /*CtpP.QEntryPoolP.PoolP*/PoolP$1$free[1000];
uint8_t /*CtpP.QEntryPoolP.PoolP*/PoolP$1$index[1000];
/*CtpP.QEntryPoolP.PoolP*/PoolP$1$pool_t * /*CtpP.QEntryPoolP.PoolP*/PoolP$1$queue[1000][7];
/*CtpP.QEntryPoolP.PoolP*/PoolP$1$pool_t /*CtpP.QEntryPoolP.PoolP*/PoolP$1$pool[1000][7];

static inline error_t /*CtpP.QEntryPoolP.PoolP*/PoolP$1$Init$init(void );









static inline bool /*CtpP.QEntryPoolP.PoolP*/PoolP$1$Pool$empty(void );
#line 88
static inline /*CtpP.QEntryPoolP.PoolP*/PoolP$1$pool_t */*CtpP.QEntryPoolP.PoolP*/PoolP$1$Pool$get(void );
#line 103
static error_t /*CtpP.QEntryPoolP.PoolP*/PoolP$1$Pool$put(/*CtpP.QEntryPoolP.PoolP*/PoolP$1$pool_t *newVal);
# 48 "/opt/tinyos-2.1.2/tos/system/QueueC.nc"
/*CtpP.SendQueueP*/QueueC$0$queue_t  /*CtpP.SendQueueP*/QueueC$0$queue[1000][8];
uint8_t /*CtpP.SendQueueP*/QueueC$0$head[1000];
uint8_t /*CtpP.SendQueueP*/QueueC$0$tail[1000];
uint8_t /*CtpP.SendQueueP*/QueueC$0$size[1000];

static inline bool /*CtpP.SendQueueP*/QueueC$0$Queue$empty(void );



static inline uint8_t /*CtpP.SendQueueP*/QueueC$0$Queue$size(void );



static inline uint8_t /*CtpP.SendQueueP*/QueueC$0$Queue$maxSize(void );



static inline /*CtpP.SendQueueP*/QueueC$0$queue_t /*CtpP.SendQueueP*/QueueC$0$Queue$head(void );



static void /*CtpP.SendQueueP*/QueueC$0$printQueue(void );
#line 85
static /*CtpP.SendQueueP*/QueueC$0$queue_t /*CtpP.SendQueueP*/QueueC$0$Queue$dequeue(void );
#line 97
static error_t /*CtpP.SendQueueP*/QueueC$0$Queue$enqueue(/*CtpP.SendQueueP*/QueueC$0$queue_t newVal);
#line 112
static inline /*CtpP.SendQueueP*/QueueC$0$queue_t /*CtpP.SendQueueP*/QueueC$0$Queue$element(uint8_t idx);
# 60 "../net/net_EER_sim/eer/CtpPacket.nc"
static am_addr_t /*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$CtpPacket$getOrigin(message_t *msg);
#line 54
static uint8_t /*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$CtpPacket$getThl(message_t *msg);








static uint8_t /*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$CtpPacket$getSequenceNumber(message_t *msg);


static uint8_t /*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$CtpPacket$getType(message_t *msg);
# 58 "../net/net_EER_sim/eer/LruCtpMsgCacheP.nc"
#line 53
typedef struct /*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$__nesc_unnamed4364 {
  am_addr_t origin;
  uint8_t seqno;
  collection_id_t type;
  uint8_t thl;
} /*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$ctp_packet_sig_t;

/*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$ctp_packet_sig_t /*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$cache[1000][4];
uint8_t /*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$first[1000];
uint8_t /*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$count[1000];

static inline error_t /*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$Init$init(void );
#line 84
static uint8_t /*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$lookup(message_t *m);
#line 100
static inline void /*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$remove(uint8_t i);
#line 116
static inline void /*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$Cache$insert(message_t *m);
#line 135
static inline bool /*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$Cache$lookup(message_t *m);
# 72 "../net/net_EER_sim/4bitle/LinkEstimator.nc"
static void LinkEstimatorP$LinkEstimator$evicted(am_addr_t neighbor);
# 80 "/opt/tinyos-2.1.2/tos/interfaces/AMSend.nc"
static error_t LinkEstimatorP$AMSend$send(am_addr_t addr, 
#line 71
message_t * msg, 








uint8_t len);
#line 110
static void LinkEstimatorP$Send$sendDone(
#line 103
message_t * msg, 






error_t error);
# 52 "/opt/tinyos-2.1.2/tos/interfaces/Random.nc"
static uint16_t LinkEstimatorP$Random$rand16(void );
# 78 "/opt/tinyos-2.1.2/tos/interfaces/Packet.nc"
static uint8_t LinkEstimatorP$SubPacket$payloadLength(
#line 74
message_t * msg);
#line 126
static 
#line 123
void * 


LinkEstimatorP$SubPacket$getPayload(
#line 121
message_t * msg, 




uint8_t len);
#line 106
static uint8_t LinkEstimatorP$SubPacket$maxPayloadLength(void );
# 88 "/opt/tinyos-2.1.2/tos/interfaces/AMPacket.nc"
static am_addr_t LinkEstimatorP$SubAMPacket$source(
#line 84
message_t * amsg);
#line 78
static am_addr_t LinkEstimatorP$SubAMPacket$destination(
#line 74
message_t * amsg);
# 78 "/opt/tinyos-2.1.2/tos/interfaces/Receive.nc"
static 
#line 74
message_t * 



LinkEstimatorP$Receive$receive(
#line 71
message_t * msg, 
void * payload, 





uint8_t len);
# 43 "../net/net_EER_sim/eer/CompareBit.nc"
static bool LinkEstimatorP$CompareBit$shouldInsert(message_t * msg, void * payload, uint8_t len);
# 47 "/opt/tinyos-2.1.2/tos/interfaces/LinkPacketMetadata.nc"
static bool LinkEstimatorP$LinkPacketMetadata$highChannelQuality(
#line 44
message_t * msg);
# 75 "../net/net_EER_sim/4bitle/LinkEstimatorP.nc"
enum LinkEstimatorP$__nesc_unnamed4365 {


  LinkEstimatorP$EVICT_ETX_THRESHOLD = 65, 


  LinkEstimatorP$MAX_PKT_GAP = 10, 
  LinkEstimatorP$BEST_ETX = 10, 
  LinkEstimatorP$INVALID_RVAL = 0xff, 
  LinkEstimatorP$INVALID_NEIGHBOR_ADDR = 0xff, 


  LinkEstimatorP$VERY_LARGE_ETX_VALUE = 0xffff, 


  LinkEstimatorP$ALPHA = 9, 


  LinkEstimatorP$DLQ_PKT_WINDOW = 5, 


  LinkEstimatorP$BLQ_PKT_WINDOW = 3, 



  LinkEstimatorP$LARGE_ETX_VALUE = 70
};


neighbor_table_entry_t LinkEstimatorP$NeighborTable[1000][14];

uint8_t LinkEstimatorP$linkEstSeq[1000];



uint8_t LinkEstimatorP$prevSentIdx[1000];


static inline linkest_header_t *LinkEstimatorP$getHeader(message_t *m);




static inline linkest_footer_t *LinkEstimatorP$getFooter(message_t *m, uint8_t len);







static inline uint8_t LinkEstimatorP$addLinkEstHeaderAndFooter(message_t *msg, uint8_t len);
#line 180
static void LinkEstimatorP$initNeighborIdx(uint8_t i, am_addr_t ll_addr);
#line 193
static uint8_t LinkEstimatorP$findIdx(am_addr_t ll_addr);
#line 206
static uint8_t LinkEstimatorP$findEmptyNeighborIdx(void );
#line 219
static uint8_t LinkEstimatorP$findWorstNeighborIdx(uint8_t thresholdETX);
#line 254
static inline uint8_t LinkEstimatorP$findRandomNeighborIdx(void );
#line 292
static void LinkEstimatorP$updateETX(neighbor_table_entry_t *ne, uint16_t newEst);





static void LinkEstimatorP$updateDETX(neighbor_table_entry_t *ne);
#line 317
static uint16_t LinkEstimatorP$computeETX(uint8_t q1);
#line 332
static inline void LinkEstimatorP$updateNeighborTableEst(am_addr_t n);
#line 373
static void LinkEstimatorP$updateNeighborEntryIdx(uint8_t idx, uint8_t seq);
#line 404
static inline void LinkEstimatorP$print_neighbor_table(void );
#line 427
static void LinkEstimatorP$print_packet(message_t *msg, uint8_t len);










static inline void LinkEstimatorP$initNeighborTable(void );







static inline error_t LinkEstimatorP$StdControl$start(void );









static inline error_t LinkEstimatorP$Init$init(void );






static uint16_t LinkEstimatorP$LinkEstimator$getLinkQuality(am_addr_t neighbor);
#line 507
static inline error_t LinkEstimatorP$LinkEstimator$insertNeighbor(am_addr_t neighbor);
#line 535
static error_t LinkEstimatorP$LinkEstimator$pinNeighbor(am_addr_t neighbor);









static inline error_t LinkEstimatorP$LinkEstimator$unpinNeighbor(am_addr_t neighbor);
#line 557
static inline error_t LinkEstimatorP$LinkEstimator$txAck(am_addr_t neighbor);
#line 574
static inline error_t LinkEstimatorP$LinkEstimator$txNoAck(am_addr_t neighbor);
#line 590
static inline error_t LinkEstimatorP$LinkEstimator$clearDLQ(am_addr_t neighbor);
#line 605
static inline error_t LinkEstimatorP$Send$send(am_addr_t addr, message_t *msg, uint8_t len);










static inline void LinkEstimatorP$AMSend$sendDone(message_t *msg, error_t error);








static inline uint8_t LinkEstimatorP$Send$maxPayloadLength(void );



static inline void *LinkEstimatorP$Send$getPayload(message_t *msg, uint8_t len);






static inline void LinkEstimatorP$processReceivedMessage(message_t * msg, void * payload, uint8_t len);
#line 734
static inline message_t *LinkEstimatorP$SubReceive$receive(message_t *msg, 
void *payload, 
uint8_t len);
#line 750
static uint8_t LinkEstimatorP$Packet$payloadLength(message_t *msg);
#line 769
static inline uint8_t LinkEstimatorP$Packet$maxPayloadLength(void );




static void *LinkEstimatorP$Packet$getPayload(message_t *msg, uint8_t len);
# 110 "/opt/tinyos-2.1.2/tos/interfaces/AMSend.nc"
static void /*CtpP.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$0$AMSend$sendDone(
#line 103
message_t * msg, 






error_t error);
# 75 "/opt/tinyos-2.1.2/tos/interfaces/Send.nc"
static error_t /*CtpP.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$0$Send$send(
#line 67
message_t * msg, 







uint8_t len);
#line 112
static uint8_t /*CtpP.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$0$Send$maxPayloadLength(void );
# 103 "/opt/tinyos-2.1.2/tos/interfaces/AMPacket.nc"
static void /*CtpP.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$0$AMPacket$setDestination(
#line 99
message_t * amsg, 



am_addr_t addr);
#line 162
static void /*CtpP.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$0$AMPacket$setType(
#line 158
message_t * amsg, 



am_id_t t);
# 53 "/opt/tinyos-2.1.2/tos/system/AMQueueEntryP.nc"
static inline error_t /*CtpP.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$0$AMSend$send(am_addr_t dest, 
message_t *msg, 
uint8_t len);









static inline void /*CtpP.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$0$Send$sendDone(message_t *m, error_t err);



static inline uint8_t /*CtpP.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$0$AMSend$maxPayloadLength(void );
# 80 "/opt/tinyos-2.1.2/tos/interfaces/AMSend.nc"
static error_t /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$AMSend$send(
# 48 "/opt/tinyos-2.1.2/tos/system/AMQueueImplP.nc"
am_id_t arg_0x40de7908, 
# 80 "/opt/tinyos-2.1.2/tos/interfaces/AMSend.nc"
am_addr_t addr, 
#line 71
message_t * msg, 








uint8_t len);
#line 123
static uint8_t /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$AMSend$maxPayloadLength(
# 48 "/opt/tinyos-2.1.2/tos/system/AMQueueImplP.nc"
am_id_t arg_0x40de7908);
# 100 "/opt/tinyos-2.1.2/tos/interfaces/Send.nc"
static void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Send$sendDone(
# 46 "/opt/tinyos-2.1.2/tos/system/AMQueueImplP.nc"
uint8_t arg_0x40deae70, 
# 96 "/opt/tinyos-2.1.2/tos/interfaces/Send.nc"
message_t * msg, 



error_t error);
# 78 "/opt/tinyos-2.1.2/tos/interfaces/Packet.nc"
static uint8_t /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Packet$payloadLength(
#line 74
message_t * msg);
#line 94
static void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Packet$setPayloadLength(
#line 90
message_t * msg, 



uint8_t len);
# 67 "/opt/tinyos-2.1.2/tos/interfaces/TaskBasic.nc"
static error_t /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$errorTask$postTask(void );
# 78 "/opt/tinyos-2.1.2/tos/interfaces/AMPacket.nc"
static am_addr_t /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$AMPacket$destination(
#line 74
message_t * amsg);
#line 147
static am_id_t /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$AMPacket$type(
#line 143
message_t * amsg);
# 126 "/opt/tinyos-2.1.2/tos/system/AMQueueImplP.nc"
enum /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$__nesc_unnamed4366 {
#line 126
  AMQueueImplP$0$CancelTask = 7U
};
#line 126
typedef int /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$__nesc_sillytask_CancelTask[/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$CancelTask];
#line 169
enum /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$__nesc_unnamed4367 {
#line 169
  AMQueueImplP$0$errorTask = 8U
};
#line 169
typedef int /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$__nesc_sillytask_errorTask[/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$errorTask];
#line 57
#line 55
typedef struct /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$__nesc_unnamed4368 {
  message_t * msg;
} /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$queue_entry_t;

uint8_t /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current[1000];
/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$queue_entry_t /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$queue[1000][2];
uint8_t /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$cancelMask[1000][2 / 8 + 1];

static void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$tryToSend(void );

static inline void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$nextPacket(void );
#line 90
static error_t /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Send$send(uint8_t clientId, message_t *msg, 
uint8_t len);
#line 126
static inline void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$CancelTask$runTask(void );
#line 163
static inline void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$sendDone(uint8_t last, message_t * msg, error_t err);





static inline void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$errorTask$runTask(void );




static void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$tryToSend(void );
#line 189
static void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$AMSend$sendDone(am_id_t id, message_t *msg, error_t err);
#line 207
static inline uint8_t /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Send$maxPayloadLength(uint8_t id);







static inline void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Send$default$sendDone(uint8_t id, message_t *msg, error_t err);
# 67 "/opt/tinyos-2.1.2/tos/interfaces/TaskBasic.nc"
static error_t /*CtpP.Router*/EerParentSetEngineP$0$updateRouteTask$postTask(void );
# 79 "../net/net_EER_sim/CollectionDebug.nc"
static error_t /*CtpP.Router*/EerParentSetEngineP$0$CollectionDebug$logEventRoute(uint8_t type, am_addr_t parent, uint8_t hopcount, uint16_t metric);
#line 67
static error_t /*CtpP.Router*/EerParentSetEngineP$0$CollectionDebug$logEventDbg(uint8_t type, uint16_t arg1, uint16_t arg2, uint16_t arg3);
# 55 "../net/net_EER_sim/4bitle/LinkEstimator.nc"
static error_t /*CtpP.Router*/EerParentSetEngineP$0$LinkEstimator$pinNeighbor(am_addr_t neighbor);
#line 52
static error_t /*CtpP.Router*/EerParentSetEngineP$0$LinkEstimator$insertNeighbor(am_addr_t neighbor);
#line 69
static error_t /*CtpP.Router*/EerParentSetEngineP$0$LinkEstimator$clearDLQ(am_addr_t neighbor);
#line 58
static error_t /*CtpP.Router*/EerParentSetEngineP$0$LinkEstimator$unpinNeighbor(am_addr_t neighbor);
#line 49
static uint16_t /*CtpP.Router*/EerParentSetEngineP$0$LinkEstimator$getLinkQuality(uint16_t neighbor);
# 52 "/opt/tinyos-2.1.2/tos/interfaces/Random.nc"
static uint16_t /*CtpP.Router*/EerParentSetEngineP$0$Random$rand16(void );
#line 46
static uint32_t /*CtpP.Router*/EerParentSetEngineP$0$Random$rand32(void );
# 43 "../net/net_EER_sim/eer_parentselection/EerParentSelectionConfig.nc"
static error_t /*CtpP.Router*/EerParentSetEngineP$0$EerParentSelectionConfig$addParentCandidate(routing_table_entry *entry, __nesc_nxbase_nx_uint16_t candETX);

static am_addr_t /*CtpP.Router*/EerParentSetEngineP$0$EerParentSelectionConfig$drawRandomParent(void );
#line 41
static void /*CtpP.Router*/EerParentSetEngineP$0$EerParentSelectionConfig$initializeParentSet(void );





static error_t /*CtpP.Router*/EerParentSetEngineP$0$EerParentSelectionConfig$getParentSetETX(nx_uint16_t *parentSetETX, nx_uint8_t *parentSetSize);

static __nesc_nxbase_nx_uint8_t /*CtpP.Router*/EerParentSetEngineP$0$EerParentSelectionConfig$getParentSetSize(void );
# 44 "../net/net_EER_sim/eer/EerInstrumentation.nc"
static error_t /*CtpP.Router*/EerParentSetEngineP$0$EerInstrumentation$ctrl_parentchange(void );
static error_t /*CtpP.Router*/EerParentSetEngineP$0$EerInstrumentation$ctrl_tricklereset(void );
#line 42
static error_t /*CtpP.Router*/EerParentSetEngineP$0$EerInstrumentation$ctrl_txpkt(void );
static error_t /*CtpP.Router*/EerParentSetEngineP$0$EerInstrumentation$ctrl_rxpkt(void );
# 80 "/opt/tinyos-2.1.2/tos/interfaces/AMSend.nc"
static error_t /*CtpP.Router*/EerParentSetEngineP$0$BeaconSend$send(am_addr_t addr, 
#line 71
message_t * msg, 








uint8_t len);
#line 135
static 
#line 133
void * 

/*CtpP.Router*/EerParentSetEngineP$0$BeaconSend$getPayload(
#line 132
message_t * msg, 


uint8_t len);
#line 123
static uint8_t /*CtpP.Router*/EerParentSetEngineP$0$BeaconSend$maxPayloadLength(void );
# 67 "/opt/tinyos-2.1.2/tos/interfaces/TaskBasic.nc"
static error_t /*CtpP.Router*/EerParentSetEngineP$0$sendBeaconTask$postTask(void );
# 73 "/opt/tinyos-2.1.2/tos/lib/timer/Timer.nc"
static void /*CtpP.Router*/EerParentSetEngineP$0$BeaconTimer$startOneShot(uint32_t dt);




static void /*CtpP.Router*/EerParentSetEngineP$0$BeaconTimer$stop(void );
#line 64
static void /*CtpP.Router*/EerParentSetEngineP$0$RouteTimer$startPeriodic(uint32_t dt);
# 7 "../net/net_EER_sim/eer/CtpCongestion.nc"
static bool /*CtpP.Router*/EerParentSetEngineP$0$CtpCongestion$isCongested(void );
# 88 "/opt/tinyos-2.1.2/tos/interfaces/AMPacket.nc"
static am_addr_t /*CtpP.Router*/EerParentSetEngineP$0$AMPacket$source(
#line 84
message_t * amsg);
#line 68
static am_addr_t /*CtpP.Router*/EerParentSetEngineP$0$AMPacket$address(void );
#line 147
static am_id_t /*CtpP.Router*/EerParentSetEngineP$0$AMPacket$type(
#line 143
message_t * amsg);
# 51 "../net/net_EER_sim/UnicastNameFreeRouting.nc"
static void /*CtpP.Router*/EerParentSetEngineP$0$Routing$routeFound(void );
static void /*CtpP.Router*/EerParentSetEngineP$0$Routing$noRoute(void );
# 278 "../net/net_EER_sim/eer/EerParentSetEngineP.nc"
enum /*CtpP.Router*/EerParentSetEngineP$0$__nesc_unnamed4369 {
#line 278
  EerParentSetEngineP$0$updateRouteTask = 9U
};
#line 278
typedef int /*CtpP.Router*/EerParentSetEngineP$0$__nesc_sillytask_updateRouteTask[/*CtpP.Router*/EerParentSetEngineP$0$updateRouteTask];
#line 528
enum /*CtpP.Router*/EerParentSetEngineP$0$__nesc_unnamed4370 {
#line 528
  EerParentSetEngineP$0$sendBeaconTask = 10U
};
#line 528
typedef int /*CtpP.Router*/EerParentSetEngineP$0$__nesc_sillytask_sendBeaconTask[/*CtpP.Router*/EerParentSetEngineP$0$sendBeaconTask];
#line 148
bool /*CtpP.Router*/EerParentSetEngineP$0$ECNOff[1000];



bool /*CtpP.Router*/EerParentSetEngineP$0$radioOn[1000];


bool /*CtpP.Router*/EerParentSetEngineP$0$running[1000];

bool /*CtpP.Router*/EerParentSetEngineP$0$sending[1000];


bool /*CtpP.Router*/EerParentSetEngineP$0$justEvicted[1000];

route_info_t /*CtpP.Router*/EerParentSetEngineP$0$routeInfo[1000];
bool /*CtpP.Router*/EerParentSetEngineP$0$state_is_root[1000];
am_addr_t /*CtpP.Router*/EerParentSetEngineP$0$my_ll_addr[1000];

message_t /*CtpP.Router*/EerParentSetEngineP$0$beaconMsgBuffer[1000];
ctp_routing_header_t */*CtpP.Router*/EerParentSetEngineP$0$beaconMsg[1000];


routing_table_entry /*CtpP.Router*/EerParentSetEngineP$0$routingTable[1000][14];
uint8_t /*CtpP.Router*/EerParentSetEngineP$0$routingTableActive[1000];


static inline void /*CtpP.Router*/EerParentSetEngineP$0$routingTableInit(void );
static uint8_t /*CtpP.Router*/EerParentSetEngineP$0$routingTableFind(am_addr_t arg_0x40e49128);
static inline error_t /*CtpP.Router*/EerParentSetEngineP$0$routingTableUpdateEntry(am_addr_t arg_0x40e496d0, am_addr_t arg_0x40e49888, uint16_t arg_0x40e49a38);
static inline error_t /*CtpP.Router*/EerParentSetEngineP$0$routingTableEvict(am_addr_t neighbor);

uint32_t /*CtpP.Router*/EerParentSetEngineP$0$currentInterval[1000];
uint32_t /*CtpP.Router*/EerParentSetEngineP$0$t[1000];
bool /*CtpP.Router*/EerParentSetEngineP$0$tHasPassed[1000];

static void /*CtpP.Router*/EerParentSetEngineP$0$chooseAdvertiseTime(void );








static void /*CtpP.Router*/EerParentSetEngineP$0$resetInterval(void );








static inline void /*CtpP.Router*/EerParentSetEngineP$0$decayInterval(void );







static inline void /*CtpP.Router*/EerParentSetEngineP$0$remainingInterval(void );






static inline error_t /*CtpP.Router*/EerParentSetEngineP$0$Init$init(void );
#line 235
static inline error_t /*CtpP.Router*/EerParentSetEngineP$0$StdControl$start(void );
#line 252
static inline void /*CtpP.Router*/EerParentSetEngineP$0$RadioControl$startDone(error_t error);










static inline void /*CtpP.Router*/EerParentSetEngineP$0$RadioControl$stopDone(error_t error);






static inline bool /*CtpP.Router*/EerParentSetEngineP$0$passLinkEtxThreshold(uint16_t etx);







static inline void /*CtpP.Router*/EerParentSetEngineP$0$updateRouteTask$runTask(void );
#line 528
static inline void /*CtpP.Router*/EerParentSetEngineP$0$sendBeaconTask$runTask(void );
#line 569
static void /*CtpP.Router*/EerParentSetEngineP$0$BeaconSend$sendDone(message_t *msg, error_t error);









static inline void /*CtpP.Router*/EerParentSetEngineP$0$RouteTimer$fired(void );





static inline void /*CtpP.Router*/EerParentSetEngineP$0$BeaconTimer$fired(void );
#line 600
static inline ctp_routing_header_t */*CtpP.Router*/EerParentSetEngineP$0$getHeader(message_t * m);






static inline message_t */*CtpP.Router*/EerParentSetEngineP$0$BeaconReceive$receive(message_t *msg, void *payload, uint8_t len);
#line 667
static void /*CtpP.Router*/EerParentSetEngineP$0$LinkEstimator$evicted(am_addr_t neighbor);
#line 680
static inline am_addr_t /*CtpP.Router*/EerParentSetEngineP$0$Routing$nextHop(void );








static inline bool /*CtpP.Router*/EerParentSetEngineP$0$Routing$hasRoute(void );




static error_t /*CtpP.Router*/EerParentSetEngineP$0$CtpInfo$getParent(am_addr_t *parent);








static error_t /*CtpP.Router*/EerParentSetEngineP$0$CtpInfo$getEtx(uint16_t *etx);
#line 717
static inline void /*CtpP.Router*/EerParentSetEngineP$0$CtpInfo$recomputeRoutes(void );



static inline void /*CtpP.Router*/EerParentSetEngineP$0$CtpInfo$triggerRouteUpdate(void );



static inline void /*CtpP.Router*/EerParentSetEngineP$0$CtpInfo$triggerImmediateRouteUpdate(void );



static void /*CtpP.Router*/EerParentSetEngineP$0$CtpInfo$setNeighborCongested(am_addr_t n, bool congested);
#line 759
static inline error_t /*CtpP.Router*/EerParentSetEngineP$0$RootControl$setRoot(void );
#line 784
static inline bool /*CtpP.Router*/EerParentSetEngineP$0$RootControl$isRoot(void );
#line 805
static inline bool /*CtpP.Router*/EerParentSetEngineP$0$CompareBit$shouldInsert(message_t *msg, void *payload, uint8_t len);
#line 854
static inline void /*CtpP.Router*/EerParentSetEngineP$0$routingTableInit(void );





static uint8_t /*CtpP.Router*/EerParentSetEngineP$0$routingTableFind(am_addr_t neighbor);
#line 872
static inline error_t /*CtpP.Router*/EerParentSetEngineP$0$routingTableUpdateEntry(am_addr_t from, am_addr_t parent, uint16_t etx);
#line 915
static inline error_t /*CtpP.Router*/EerParentSetEngineP$0$routingTableEvict(am_addr_t neighbor);
#line 938
static inline error_t /*CtpP.Router*/EerParentSetEngineP$0$CollectionDebug$default$logEventDbg(uint8_t type, uint16_t arg1, uint16_t arg2, uint16_t arg3);





static inline error_t /*CtpP.Router*/EerParentSetEngineP$0$CollectionDebug$default$logEventRoute(uint8_t type, am_addr_t parent, uint8_t hopcount, uint16_t etx);



static bool /*CtpP.Router*/EerParentSetEngineP$0$CtpRoutingPacket$getOption(message_t *msg, ctp_options_t opt);
#line 993
static inline uint16_t /*CtpP.Router*/EerParentSetEngineP$0$CtpInfo$getNeighborEtx(am_addr_t n);
# 52 "/opt/tinyos-2.1.2/tos/interfaces/Random.nc"
static uint16_t /*CtpP.ParentSelector*/EerParentSelectionP$0$Random$rand16(void );
# 55 "../net/net_EER_sim/eer_parentselection/EerParentSelectionP.nc"
am_addr_t /*CtpP.ParentSelector*/EerParentSelectionP$0$parentSetTable[1000][5];
nx_uint16_t /*CtpP.ParentSelector*/EerParentSelectionP$0$parentSetPathETX[1000][5];
parentSet /*CtpP.ParentSelector*/EerParentSelectionP$0$prntSet[1000];
am_addr_t /*CtpP.ParentSelector*/EerParentSelectionP$0$rand_prnt[1000];

bool /*CtpP.ParentSelector*/EerParentSelectionP$0$parent_init_flag[1000];


static void /*CtpP.ParentSelector*/EerParentSelectionP$0$EerParentSelectionConfig$initializeParentSet(void );
#line 78
static error_t /*CtpP.ParentSelector*/EerParentSelectionP$0$EerParentSelectionConfig$addParentCandidate(routing_table_entry *entry, __nesc_nxbase_nx_uint16_t candPathETX);
#line 136
static inline am_addr_t /*CtpP.ParentSelector*/EerParentSelectionP$0$EerParentSelectionConfig$drawRandomParent(void );
#line 175
static inline error_t /*CtpP.ParentSelector*/EerParentSelectionP$0$EerParentSelectionConfig$getParentSetETX(nx_uint16_t *parentSetETX, nx_uint8_t *parentSetSize);
#line 192
static inline __nesc_nxbase_nx_uint8_t /*CtpP.ParentSelector*/EerParentSelectionP$0$EerParentSelectionConfig$getParentSetSize(void );




static inline __nesc_nxbase_nx_uint8_t /*CtpP.ParentSelector*/EerParentSelectionP$0$EerParentSelectionHealth$getCandiateSetSize(void );
# 52 "/opt/tinyos-2.1.2/tos/system/RandomMlcgC.nc"
uint32_t RandomMlcgC$seed[1000];


static inline error_t RandomMlcgC$Init$init(void );
#line 69
static uint32_t RandomMlcgC$Random$rand32(void );
#line 89
static inline uint16_t RandomMlcgC$Random$rand16(void );
# 110 "/opt/tinyos-2.1.2/tos/interfaces/AMSend.nc"
static void /*CtpP.SendControl.SenderC.AMQueueEntryP*/AMQueueEntryP$1$AMSend$sendDone(
#line 103
message_t * msg, 






error_t error);
# 75 "/opt/tinyos-2.1.2/tos/interfaces/Send.nc"
static error_t /*CtpP.SendControl.SenderC.AMQueueEntryP*/AMQueueEntryP$1$Send$send(
#line 67
message_t * msg, 







uint8_t len);
# 103 "/opt/tinyos-2.1.2/tos/interfaces/AMPacket.nc"
static void /*CtpP.SendControl.SenderC.AMQueueEntryP*/AMQueueEntryP$1$AMPacket$setDestination(
#line 99
message_t * amsg, 



am_addr_t addr);
#line 162
static void /*CtpP.SendControl.SenderC.AMQueueEntryP*/AMQueueEntryP$1$AMPacket$setType(
#line 158
message_t * amsg, 



am_id_t t);
# 53 "/opt/tinyos-2.1.2/tos/system/AMQueueEntryP.nc"
static inline error_t /*CtpP.SendControl.SenderC.AMQueueEntryP*/AMQueueEntryP$1$AMSend$send(am_addr_t dest, 
message_t *msg, 
uint8_t len);









static inline void /*CtpP.SendControl.SenderC.AMQueueEntryP*/AMQueueEntryP$1$Send$sendDone(message_t *m, error_t err);
# 8 "../net/net_EER_sim/eer/DummyActiveMessageP.nc"
static inline bool DummyActiveMessageP$LinkPacketMetadata$highChannelQuality(message_t *msg);
# 67 "../net/net_EER_sim/eer/EerInstrumentationP.nc"
#line 47
typedef nx_struct EerInstrumentationP$StatCounters {
  nx_uint16_t ctrl_ntxpkt;
  nx_uint16_t ctrl_nrxpkt;
  nx_uint16_t ctrl_nparentchange;
  nx_uint16_t ctrl_ntricklereset;

  nx_uint16_t data_ntxpkt;
  nx_uint16_t data_nrxpkt;
  nx_uint16_t data_nrxacks;
  nx_uint16_t data_nqueuedrops;
  nx_uint16_t data_ndups;
  nx_uint16_t data_ninconsistencies;


  nx_uint32_t total_time;
} __attribute__((packed)) 




EerInstrumentationP$StatCounters;

EerInstrumentationP$StatCounters EerInstrumentationP$stats[1000];

static inline error_t EerInstrumentationP$EerInstrumentation$init(void );
#line 101
static inline error_t EerInstrumentationP$EerInstrumentation$ctrl_txpkt(void );




static inline error_t EerInstrumentationP$EerInstrumentation$ctrl_rxpkt(void );




static inline error_t EerInstrumentationP$EerInstrumentation$ctrl_parentchange(void );




static inline error_t EerInstrumentationP$EerInstrumentation$ctrl_tricklereset(void );




static inline error_t EerInstrumentationP$EerInstrumentation$data_txpkt(void );




static inline error_t EerInstrumentationP$EerInstrumentation$data_rxpkt(void );




static inline error_t EerInstrumentationP$EerInstrumentation$data_rxack(void );




static inline error_t EerInstrumentationP$EerInstrumentation$data_queuedrop(void );




static inline error_t EerInstrumentationP$EerInstrumentation$data_pktdup(void );




static inline error_t EerInstrumentationP$EerInstrumentation$data_inconsistent(void );
# 41 "../net/net_EER_sim/eer_parentselection/EerParentSelectionHealth.nc"
static __nesc_nxbase_nx_uint8_t EerHealthP$EerParentSelectionHealth$getCandiateSetSize(void );
# 53 "../net/net_EER_sim/eer/EerHealthP.nc"
#line 48
typedef nx_struct EerHealthP$HealthCounters {
  nx_uint16_t generated;
  nx_uint16_t forwarded;
  nx_uint16_t total_retx;
  nx_uint16_t dropped;
} __attribute__((packed)) EerHealthP$HealthCounters;

EerHealthP$HealthCounters EerHealthP$hlth[1000];

static inline error_t EerHealthP$EerHealth$init(void );







static inline error_t EerHealthP$EerHealth$hlth_generated(void );




static inline error_t EerHealthP$EerHealth$get_hlth_generated(nx_uint16_t *gen);




static inline error_t EerHealthP$EerHealth$hlth_forwarded(void );




static inline error_t EerHealthP$EerHealth$get_hlth_forwarded(nx_uint16_t *fwd);




static inline error_t EerHealthP$EerHealth$hlth_retx(void );




static inline error_t EerHealthP$EerHealth$get_hlth_retx(nx_uint16_t *retx);




static inline error_t EerHealthP$EerHealth$hlth_dropped(void );




static inline error_t EerHealthP$EerHealth$get_hlth_dropped(nx_uint16_t *drp);






static inline error_t EerHealthP$EerHealth$get_hlth_psetSize(nx_uint8_t *psetSize);
# 50 "../net/net_EER_sim/CollectionIdP.nc"
static inline collection_id_t /*LapTestAppC.CtpDataSenderC.CollectionSenderP.CollectionIdP*/CollectionIdP$0$CollectionId$fetch(void );
# 78 "/opt/tinyos-2.1.2/tos/lib/tossim/heap.c"
static inline void init_heap(heap_t *heap)
#line 78
{
  heap->size = 0;
  heap->private_size = STARTING_SIZE;
  heap->data = malloc(sizeof(node_t ) * heap->private_size);
}

#line 130
static inline void expand_heap(heap_t *heap)
#line 130
{
  int new_size = heap->private_size * 2 + 1;
  void *new_data = malloc(sizeof(node_t ) * new_size);



  memcpy(new_data, heap->data, sizeof(node_t ) * heap->private_size);
  free(heap->data);

  heap->data = new_data;
  heap->private_size = new_size;
}


static inline void heap_insert(heap_t *heap, void *data, long long int key)
#line 144
{
  int findex = heap->size;

#line 146
  if (findex == heap->private_size) {
      expand_heap(heap);
    }

  findex = heap->size;
  ((node_t *)heap->data)[findex].key = key;
  ((node_t *)heap->data)[findex].data = data;
  up_heap(heap, findex);

  heap->size++;
}

#line 88
static inline int is_empty(heap_t *heap)
#line 88
{
  return heap->size == 0;
}

static inline int heap_is_empty(heap_t *heap)
#line 92
{
  return is_empty(heap);
}

static inline long long int heap_get_min_key(heap_t *heap)
#line 96
{
  if (is_empty(heap)) {
      return -1;
    }
  else {
      return ((node_t *)heap->data)[0].key;
    }
}

# 317 "/opt/tinyos-2.1.2/tos/lib/tossim/sim_log.c"
inline static int sim_log_eq(void *key1, void *key2)
#line 317
{
  return strcmp((char *)key1, (char *)key2) == 0;
}

#line 306
inline static unsigned int sim_log_hash(void *key)
#line 306
{
  char *str = (char *)key;
  unsigned int hashVal = 0;
  int hashChar;

  while ((hashChar = * str++)) 
    hashVal = hashChar + (hashVal << 6) + (hashVal << 16) - hashVal;

  return hashVal;
}

#line 159
static inline void sim_log_init()
#line 159
{
  int i;

  channelTable = create_hashtable(128, sim_log_hash, sim_log_eq);

  for (i = 0; i < SIM_LOG_OUTPUT_COUNT; i++) {
      outputs[i].num = 1;
      outputs[i].files = (FILE **)malloc(sizeof(FILE *));
      outputs[i].files[0] = fdopen(1, "w");
    }
}

# 130 "/opt/tinyos-2.1.2/tos/lib/tossim/sim_noise.c"
inline static unsigned int sim_noise_hash(void *key)
#line 130
{
  char *pt = (char *)key;
  unsigned int hashVal = 0;
  int i;

#line 134
  for (i = 0; i < NOISE_HISTORY; i++) {
      hashVal = pt[i] + (hashVal << 6) + (hashVal << 16) - hashVal;
    }
  return hashVal;
}

inline static int sim_noise_eq(void *key1, void *key2)
#line 140
{
  return memcmp((void *)key1, (void *)key2, NOISE_HISTORY) == 0;
}

# 64 "/opt/tinyos-2.1.2/tos/lib/tossim/SimMoteP.nc"
static inline bool SimMoteP$SimMote$isOn(void )
#line 64
{
  return SimMoteP$isOn[sim_node()];
}

# 172 "/opt/tinyos-2.1.2/tos/lib/tossim/sim_log.c"
static inline void sim_log_add_channel(char *name, FILE *file)
#line 172
{
  sim_log_channel_t *channel;

#line 174
  channel = (sim_log_channel_t *)hashtable_search(channelTable, name);



  if (channel == (void *)0) {
      char *newName = (char *)malloc(strlen(name) + 1);

#line 180
      strcpy(newName, name);
      newName[strlen(name)] = 0;

      channel = (sim_log_channel_t *)malloc(sizeof(sim_log_channel_t ));
      channel->name = newName;
      channel->numOutputs = 0;
      channel->size = DEFAULT_CHANNEL_SIZE;
      channel->outputs = (FILE **)malloc(sizeof(FILE *) * channel->size);
      memset(channel->outputs, 0, sizeof(FILE *) * channel->size);
      hashtable_insert(channelTable, newName, channel);
    }



  if (channel->numOutputs == channel->size) {
      FILE **newOutputs;
      int newSize = channel->size * 2;

      newOutputs = (FILE **)malloc(sizeof(FILE *) * newSize);
      memcpy(newOutputs, channel->outputs, channel->size * sizeof(FILE **));

      free(channel->outputs);

      channel->outputs = newOutputs;
      channel->size = newSize;
    }

  channel->outputs[channel->numOutputs] = file;
  channel->numOutputs++;
  sim_log_commit_change();
}

static inline bool sim_log_remove_channel(char *output, FILE *file)
#line 212
{
  sim_log_channel_t *channel;
  int i;

#line 215
  channel = (sim_log_channel_t *)hashtable_search(channelTable, output);

  if (channel == (void *)0) {
      return FALSE;
    }


  for (i = 0; i < channel->numOutputs; i++) {
      FILE *f = channel->outputs[i];

#line 224
      if (file == f) {
          memcpy(&channel->outputs[i], &channel->outputs[i + 1], channel->numOutputs - (i + 1));
          channel->outputs[channel->numOutputs - 1] = (void *)0;
          channel->numOutputs--;
        }
    }

  return TRUE;
}

# 161 "/opt/tinyos-2.1.2/tos/lib/tossim/sim_gain.c"
static inline gain_entry_t *sim_gain_allocate_link(int mote)
#line 161
{
  gain_entry_t *newLink = (gain_entry_t *)malloc(sizeof(gain_entry_t ));

#line 163
  newLink->next = (void *)0;
  newLink->mote = mote;
  newLink->gain = -10000000.0;
  return newLink;
}

# 55 "/opt/tinyos-2.1.2/tos/lib/tossim/randomlib.c"
static inline void RandomInitialise(int ij, int kl)
{
  double s;
#line 57
  double t;
  int ii;
#line 58
  int i;
#line 58
  int j;
#line 58
  int k;
#line 58
  int l;
#line 58
  int jj;
#line 58
  int m;






  if (((ij < 0 || ij > 31328) || kl < 0) || kl > 30081) {
      ij = 1802;
      kl = 9373;
    }

  i = ij / 177 % 177 + 2;
  j = ij % 177 + 2;
  k = kl / 169 % 178 + 1;
  l = kl % 169;

  for (ii = 0; ii < 97; ii++) {
      s = 0.0;
      t = 0.5;
      for (jj = 0; jj < 24; jj++) {
          m = i * j % 179 * k % 179;
          i = j;
          j = k;
          k = m;
          l = (53 * l + 1) % 169;
          if (l * m % 64 >= 32) {
            s += t;
            }
#line 86
          t *= 0.5;
        }
      randU[ii] = s;
    }

  randC = 362436.0 / 16777216.0;
  randCD = 7654321.0 / 16777216.0;
  randCM = 16777213.0 / 16777216.0;
  i97 = 97;
  j97 = 33;
  test = TRUE;
}

# 284 "/opt/tinyos-2.1.2/tos/lib/tossim/sim_noise.c"
static inline void sim_noise_alarm()
#line 284
{
  dummy = 5;
}

# 50 "/opt/tinyos-2.1.2/tos/lib/tossim/sim_packet.c"
inline static tossim_header_t *getHeader(message_t *msg)
#line 50
{
  return (tossim_header_t *)(msg->data - sizeof(tossim_header_t ));
}

# 236 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimActiveMessageC.nc"
static inline void TossimActiveMessageC$active_message_deliver_handle(sim_event_t *evt)
#line 236
{
  message_t *m = (message_t *)evt->data;

#line 238
  sim_log_debug(117U, "Packet", "Delivering packet to %i at %s\n", (int )sim_node(), sim_time_string());
  TossimActiveMessageC$Model$receive(m);
}

static inline sim_event_t *TossimActiveMessageC$allocate_deliver_event(int node, message_t *msg, sim_time_t t)
#line 242
{
  sim_event_t *evt = (sim_event_t *)malloc(sizeof(sim_event_t ));

#line 244
  evt->mote = node;
  evt->time = t;
  evt->handle = TossimActiveMessageC$active_message_deliver_handle;
  evt->cleanup = sim_queue_cleanup_event;
  evt->cancelled = 0;
  evt->force = 0;
  evt->data = msg;
  return evt;
}

# 88 "/opt/tinyos-2.1.2/tos/lib/tossim/ActiveMessageAddressC.nc"
static inline am_addr_t ActiveMessageAddressC$amAddress(void )
#line 88
{
  return ActiveMessageAddressC$ActiveMessageAddress$amAddress();
}

# 57 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimActiveMessageC.nc"
inline static am_addr_t TossimActiveMessageC$amAddress(void ){
#line 57
  unsigned short __nesc_result;
#line 57

#line 57
  __nesc_result = ActiveMessageAddressC$amAddress();
#line 57

#line 57
  return __nesc_result;
#line 57
}
#line 57
#line 136
static inline am_addr_t TossimActiveMessageC$AMPacket$address(void )
#line 136
{
  return TossimActiveMessageC$amAddress();
}

#line 160
static inline bool TossimActiveMessageC$AMPacket$isForMe(message_t *amsg)
#line 160
{
  return TossimActiveMessageC$AMPacket$destination(amsg) == TossimActiveMessageC$AMPacket$address() || 
  TossimActiveMessageC$AMPacket$destination(amsg) == AM_BROADCAST_ADDR;
}

# 310 "/usr/local/lib/ncc/nesc_nx.h"
static __inline  uint16_t __nesc_ntoh_uint16(const void * source)
#line 310
{
  const uint8_t *base = source;

#line 312
  return ((uint16_t )base[0] << 8) | base[1];
}

#line 281
static __inline  uint8_t __nesc_ntoh_uint8(const void * source)
#line 281
{
  const uint8_t *base = source;

#line 283
  return base[0];
}

#line 315
static __inline  uint16_t __nesc_hton_uint16(void * target, uint16_t value)
#line 315
{
  uint8_t *base = target;

#line 317
  base[1] = value;
  base[0] = value >> 8;
  return value;
}

# 95 "../net/net_EER_sim/eer/EerHealthP.nc"
static inline error_t EerHealthP$EerHealth$hlth_dropped(void )
#line 95
{
  unsigned short __nesc_temp78;
  unsigned char *__nesc_temp77;

#line 96
  (__nesc_temp77 = EerHealthP$hlth[sim_node()].dropped.nxdata, __nesc_hton_uint16(__nesc_temp77, (__nesc_temp78 = __nesc_ntoh_uint16(__nesc_temp77)) + 1), __nesc_temp78);
  return SUCCESS;
}

# 53 "../net/net_EER_sim/eer/EerHealth.nc"
inline static error_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$EerHealth$hlth_dropped(void ){
#line 53
  unsigned char __nesc_result;
#line 53

#line 53
  __nesc_result = EerHealthP$EerHealth$hlth_dropped();
#line 53

#line 53
  return __nesc_result;
#line 53
}
#line 53
# 136 "../net/net_EER_sim/eer/EerInstrumentationP.nc"
static inline error_t EerInstrumentationP$EerInstrumentation$data_queuedrop(void )
#line 136
{
  unsigned short __nesc_temp66;
  unsigned char *__nesc_temp65;

#line 137
  (__nesc_temp65 = EerInstrumentationP$stats[sim_node()].data_nqueuedrops.nxdata, __nesc_hton_uint16(__nesc_temp65, (__nesc_temp66 = __nesc_ntoh_uint16(__nesc_temp65)) + 1), __nesc_temp66);
  return SUCCESS;
}

# 49 "../net/net_EER_sim/eer/EerInstrumentation.nc"
inline static error_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$EerInstrumentation$data_queuedrop(void ){
#line 49
  unsigned char __nesc_result;
#line 49

#line 49
  __nesc_result = EerInstrumentationP$EerInstrumentation$data_queuedrop();
#line 49

#line 49
  return __nesc_result;
#line 49
}
#line 49
# 1367 "../net/net_EER_sim/eer/CtpForwardingEngineP.nc"
static inline error_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$CollectionDebug$default$logEvent(uint8_t type)
#line 1367
{
  return SUCCESS;
}

# 61 "../net/net_EER_sim/CollectionDebug.nc"
inline static error_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$CollectionDebug$logEvent(uint8_t type){
#line 61
  unsigned char __nesc_result;
#line 61

#line 61
  __nesc_result = /*CtpP.Forwarder*/CtpForwardingEngineP$0$CollectionDebug$default$logEvent(type);
#line 61

#line 61
  return __nesc_result;
#line 61
}
#line 61
# 89 "/opt/tinyos-2.1.2/tos/interfaces/Pool.nc"
inline static error_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$QEntryPool$put(/*CtpP.Forwarder*/CtpForwardingEngineP$0$QEntryPool$t * newVal){
#line 89
  unsigned char __nesc_result;
#line 89

#line 89
  __nesc_result = /*CtpP.QEntryPoolP.PoolP*/PoolP$1$Pool$put(newVal);
#line 89

#line 89
  return __nesc_result;
#line 89
}
#line 89
inline static error_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$MessagePool$put(/*CtpP.Forwarder*/CtpForwardingEngineP$0$MessagePool$t * newVal){
#line 89
  unsigned char __nesc_result;
#line 89

#line 89
  __nesc_result = /*CtpP.MessagePoolP.PoolP*/PoolP$0$Pool$put(newVal);
#line 89

#line 89
  return __nesc_result;
#line 89
}
#line 89
# 67 "/opt/tinyos-2.1.2/tos/interfaces/TaskBasic.nc"
inline static error_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$sendTask$postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SimSchedulerBasicP$TaskBasic$postTask(/*CtpP.Forwarder*/CtpForwardingEngineP$0$sendTask);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
# 169 "/opt/tinyos-2.1.2/tos/lib/timer/VirtualizeTimerC.nc"
static inline bool /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$isRunning(uint8_t num)
{
  return /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$m_timers[sim_node()][num].isrunning;
}

# 92 "/opt/tinyos-2.1.2/tos/lib/timer/Timer.nc"
inline static bool /*CtpP.Forwarder*/CtpForwardingEngineP$0$RetxmitTimer$isRunning(void ){
#line 92
  unsigned char __nesc_result;
#line 92

#line 92
  __nesc_result = /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$isRunning(3U);
#line 92

#line 92
  return __nesc_result;
#line 92
}
#line 92
# 146 "../net/net_EER_sim/eer/EerInstrumentationP.nc"
static inline error_t EerInstrumentationP$EerInstrumentation$data_inconsistent(void )
#line 146
{
  unsigned short __nesc_temp70;
  unsigned char *__nesc_temp69;

#line 147
  (__nesc_temp69 = EerInstrumentationP$stats[sim_node()].data_ninconsistencies.nxdata, __nesc_hton_uint16(__nesc_temp69, (__nesc_temp70 = __nesc_ntoh_uint16(__nesc_temp69)) + 1), __nesc_temp70);
  return SUCCESS;
}

# 51 "../net/net_EER_sim/eer/EerInstrumentation.nc"
inline static error_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$EerInstrumentation$data_inconsistent(void ){
#line 51
  unsigned char __nesc_result;
#line 51

#line 51
  __nesc_result = EerInstrumentationP$EerInstrumentation$data_inconsistent();
#line 51

#line 51
  return __nesc_result;
#line 51
}
#line 51
# 78 "/opt/tinyos-2.1.2/tos/interfaces/AMPacket.nc"
inline static am_addr_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$AMPacket$destination(message_t * amsg){
#line 78
  unsigned short __nesc_result;
#line 78

#line 78
  __nesc_result = TossimActiveMessageC$AMPacket$destination(amsg);
#line 78

#line 78
  return __nesc_result;
#line 78
}
#line 78
# 1376 "../net/net_EER_sim/eer/CtpForwardingEngineP.nc"
static inline error_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$CollectionDebug$default$logEventMsg(uint8_t type, uint16_t msg, am_addr_t origin, am_addr_t node)
#line 1376
{
  return SUCCESS;
}

# 73 "../net/net_EER_sim/CollectionDebug.nc"
inline static error_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$CollectionDebug$logEventMsg(uint8_t type, uint16_t msg, am_addr_t origin, am_addr_t node){
#line 73
  unsigned char __nesc_result;
#line 73

#line 73
  __nesc_result = /*CtpP.Forwarder*/CtpForwardingEngineP$0$CollectionDebug$default$logEventMsg(type, msg, origin, node);
#line 73

#line 73
  return __nesc_result;
#line 73
}
#line 73
# 725 "../net/net_EER_sim/eer/EerParentSetEngineP.nc"
static inline void /*CtpP.Router*/EerParentSetEngineP$0$CtpInfo$triggerImmediateRouteUpdate(void )
#line 725
{
  /*CtpP.Router*/EerParentSetEngineP$0$resetInterval();
}

# 66 "../net/net_EER_sim/eer/CtpInfo.nc"
inline static void /*CtpP.Forwarder*/CtpForwardingEngineP$0$CtpInfo$triggerImmediateRouteUpdate(void ){
#line 66
  /*CtpP.Router*/EerParentSetEngineP$0$CtpInfo$triggerImmediateRouteUpdate();
#line 66
}
#line 66
# 189 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimActiveMessageC.nc"
static inline void *TossimActiveMessageC$Packet$getPayload(message_t *msg, uint8_t len)
#line 189
{
  if (len <= 100) {
      return msg->data;
    }
  else {
      return (void *)0;
    }
}

# 126 "/opt/tinyos-2.1.2/tos/interfaces/Packet.nc"
inline static void * /*CtpP.Forwarder*/CtpForwardingEngineP$0$SubPacket$getPayload(message_t * msg, uint8_t len){
#line 126
  void *__nesc_result;
#line 126

#line 126
  __nesc_result = TossimActiveMessageC$Packet$getPayload(msg, len);
#line 126

#line 126
  return __nesc_result;
#line 126
}
#line 126
# 345 "../net/net_EER_sim/eer/CtpForwardingEngineP.nc"
static inline ctp_data_header_t */*CtpP.Forwarder*/CtpForwardingEngineP$0$getHeader(message_t *m)
#line 345
{
  return (ctp_data_header_t *)/*CtpP.Forwarder*/CtpForwardingEngineP$0$SubPacket$getPayload(m, sizeof(ctp_data_header_t ));
}

#line 1290
static inline uint16_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$CtpPacket$getEtx(message_t *msg)
#line 1290
{
#line 1290
  return __nesc_ntoh_uint16(/*CtpP.Forwarder*/CtpForwardingEngineP$0$getHeader(msg)->etx.nxdata);
}

# 52 "../net/net_EER_sim/eer/CtpInfo.nc"
inline static error_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$CtpInfo$getEtx(uint16_t *etx){
#line 52
  unsigned char __nesc_result;
#line 52

#line 52
  __nesc_result = /*CtpP.Router*/EerParentSetEngineP$0$CtpInfo$getEtx(etx);
#line 52

#line 52
  return __nesc_result;
#line 52
}
#line 52
# 57 "/opt/tinyos-2.1.2/tos/system/QueueC.nc"
static inline uint8_t /*CtpP.SendQueueP*/QueueC$0$Queue$size(void )
#line 57
{
  return /*CtpP.SendQueueP*/QueueC$0$size[sim_node()];
}

# 58 "/opt/tinyos-2.1.2/tos/interfaces/Queue.nc"
inline static uint8_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$SendQueue$size(void ){
#line 58
  unsigned char __nesc_result;
#line 58

#line 58
  __nesc_result = /*CtpP.SendQueueP*/QueueC$0$Queue$size();
#line 58

#line 58
  return __nesc_result;
#line 58
}
#line 58
#line 90
inline static error_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$SendQueue$enqueue(/*CtpP.Forwarder*/CtpForwardingEngineP$0$SendQueue$t  newVal){
#line 90
  unsigned char __nesc_result;
#line 90

#line 90
  __nesc_result = /*CtpP.SendQueueP*/QueueC$0$Queue$enqueue(newVal);
#line 90

#line 90
  return __nesc_result;
#line 90
}
#line 90
# 88 "/opt/tinyos-2.1.2/tos/system/PoolP.nc"
static inline /*CtpP.MessagePoolP.PoolP*/PoolP$0$pool_t */*CtpP.MessagePoolP.PoolP*/PoolP$0$Pool$get(void )
#line 88
{
  if (/*CtpP.MessagePoolP.PoolP*/PoolP$0$free[sim_node()]) {
      /*CtpP.MessagePoolP.PoolP*/PoolP$0$pool_t *rval = /*CtpP.MessagePoolP.PoolP*/PoolP$0$queue[sim_node()][/*CtpP.MessagePoolP.PoolP*/PoolP$0$index[sim_node()]];

#line 91
      /*CtpP.MessagePoolP.PoolP*/PoolP$0$queue[sim_node()][/*CtpP.MessagePoolP.PoolP*/PoolP$0$index[sim_node()]] = (void *)0;
      /*CtpP.MessagePoolP.PoolP*/PoolP$0$free[sim_node()]--;
      /*CtpP.MessagePoolP.PoolP*/PoolP$0$index[sim_node()]++;
      if (/*CtpP.MessagePoolP.PoolP*/PoolP$0$index[sim_node()] == 7) {
          /*CtpP.MessagePoolP.PoolP*/PoolP$0$index[sim_node()] = 0;
        }
      sim_log_debug(227U, "PoolP", "%s size is %i\n", __FUNCTION__, (int )/*CtpP.MessagePoolP.PoolP*/PoolP$0$free[sim_node()]);
      return rval;
    }
  return (void *)0;
}

# 97 "/opt/tinyos-2.1.2/tos/interfaces/Pool.nc"
inline static /*CtpP.Forwarder*/CtpForwardingEngineP$0$MessagePool$t * /*CtpP.Forwarder*/CtpForwardingEngineP$0$MessagePool$get(void ){
#line 97
  nx_struct message_t *__nesc_result;
#line 97

#line 97
  __nesc_result = /*CtpP.MessagePoolP.PoolP*/PoolP$0$Pool$get();
#line 97

#line 97
  return __nesc_result;
#line 97
}
#line 97
# 88 "/opt/tinyos-2.1.2/tos/system/PoolP.nc"
static inline /*CtpP.QEntryPoolP.PoolP*/PoolP$1$pool_t */*CtpP.QEntryPoolP.PoolP*/PoolP$1$Pool$get(void )
#line 88
{
  if (/*CtpP.QEntryPoolP.PoolP*/PoolP$1$free[sim_node()]) {
      /*CtpP.QEntryPoolP.PoolP*/PoolP$1$pool_t *rval = /*CtpP.QEntryPoolP.PoolP*/PoolP$1$queue[sim_node()][/*CtpP.QEntryPoolP.PoolP*/PoolP$1$index[sim_node()]];

#line 91
      /*CtpP.QEntryPoolP.PoolP*/PoolP$1$queue[sim_node()][/*CtpP.QEntryPoolP.PoolP*/PoolP$1$index[sim_node()]] = (void *)0;
      /*CtpP.QEntryPoolP.PoolP*/PoolP$1$free[sim_node()]--;
      /*CtpP.QEntryPoolP.PoolP*/PoolP$1$index[sim_node()]++;
      if (/*CtpP.QEntryPoolP.PoolP*/PoolP$1$index[sim_node()] == 7) {
          /*CtpP.QEntryPoolP.PoolP*/PoolP$1$index[sim_node()] = 0;
        }
      sim_log_debug(231U, "PoolP", "%s size is %i\n", __FUNCTION__, (int )/*CtpP.QEntryPoolP.PoolP*/PoolP$1$free[sim_node()]);
      return rval;
    }
  return (void *)0;
}

# 97 "/opt/tinyos-2.1.2/tos/interfaces/Pool.nc"
inline static /*CtpP.Forwarder*/CtpForwardingEngineP$0$QEntryPool$t * /*CtpP.Forwarder*/CtpForwardingEngineP$0$QEntryPool$get(void ){
#line 97
  struct __nesc_unnamed4337 *__nesc_result;
#line 97

#line 97
  __nesc_result = /*CtpP.QEntryPoolP.PoolP*/PoolP$1$Pool$get();
#line 97

#line 97
  return __nesc_result;
#line 97
}
#line 97
# 75 "/opt/tinyos-2.1.2/tos/system/PoolP.nc"
static inline bool /*CtpP.QEntryPoolP.PoolP*/PoolP$1$Pool$empty(void )
#line 75
{
  sim_log_debug(229U, "PoolP", "%s size is %i\n", __FUNCTION__, (int )/*CtpP.QEntryPoolP.PoolP*/PoolP$1$free[sim_node()]);
  return /*CtpP.QEntryPoolP.PoolP*/PoolP$1$free[sim_node()] == 0;
}

# 61 "/opt/tinyos-2.1.2/tos/interfaces/Pool.nc"
inline static bool /*CtpP.Forwarder*/CtpForwardingEngineP$0$QEntryPool$empty(void ){
#line 61
  unsigned char __nesc_result;
#line 61

#line 61
  __nesc_result = /*CtpP.QEntryPoolP.PoolP*/PoolP$1$Pool$empty();
#line 61

#line 61
  return __nesc_result;
#line 61
}
#line 61
# 75 "/opt/tinyos-2.1.2/tos/system/PoolP.nc"
static inline bool /*CtpP.MessagePoolP.PoolP*/PoolP$0$Pool$empty(void )
#line 75
{
  sim_log_debug(225U, "PoolP", "%s size is %i\n", __FUNCTION__, (int )/*CtpP.MessagePoolP.PoolP*/PoolP$0$free[sim_node()]);
  return /*CtpP.MessagePoolP.PoolP*/PoolP$0$free[sim_node()] == 0;
}

# 61 "/opt/tinyos-2.1.2/tos/interfaces/Pool.nc"
inline static bool /*CtpP.Forwarder*/CtpForwardingEngineP$0$MessagePool$empty(void ){
#line 61
  unsigned char __nesc_result;
#line 61

#line 61
  __nesc_result = /*CtpP.MessagePoolP.PoolP*/PoolP$0$Pool$empty();
#line 61

#line 61
  return __nesc_result;
#line 61
}
#line 61
# 833 "../net/net_EER_sim/eer/CtpForwardingEngineP.nc"
static inline message_t * /*CtpP.Forwarder*/CtpForwardingEngineP$0$forward(message_t * m)
#line 833
{

  if (/*CtpP.Forwarder*/CtpForwardingEngineP$0$MessagePool$empty()) {
      sim_log_debug(218U, "Route", "%s cannot forward, message pool empty.\n", __FUNCTION__);

      /*CtpP.Forwarder*/CtpForwardingEngineP$0$CollectionDebug$logEvent(NET_C_FE_MSG_POOL_EMPTY);
    }
  else {
#line 840
    if (/*CtpP.Forwarder*/CtpForwardingEngineP$0$QEntryPool$empty()) {
        sim_log_debug(219U, "Route", "%s cannot forward, queue entry pool empty.\n", __FUNCTION__);


        /*CtpP.Forwarder*/CtpForwardingEngineP$0$CollectionDebug$logEvent(NET_C_FE_QENTRY_POOL_EMPTY);
      }
    else {
        message_t *newMsg;
        fe_queue_entry_t *qe;
        uint16_t gradient;

        uint16_t packetETX;

        qe = /*CtpP.Forwarder*/CtpForwardingEngineP$0$QEntryPool$get();
        if (qe == (void *)0) {
            /*CtpP.Forwarder*/CtpForwardingEngineP$0$CollectionDebug$logEvent(NET_C_FE_GET_MSGPOOL_ERR);
            return m;
          }

        newMsg = /*CtpP.Forwarder*/CtpForwardingEngineP$0$MessagePool$get();
        if (newMsg == (void *)0) {
            /*CtpP.Forwarder*/CtpForwardingEngineP$0$CollectionDebug$logEvent(NET_C_FE_GET_QEPOOL_ERR);
            return m;
          }

        memset(newMsg, 0, sizeof(message_t ));
        memset(m->metadata, 0, sizeof(message_metadata_t ));

        qe->msg = m;
        qe->client = 0xff;
        qe->retries = MAX_RETRIES;


        qe->eer_fwder = 0xFFFF;
        qe->eer_retxs = 0;
        qe->forcedParentDraw = FALSE;

        if (/*CtpP.Forwarder*/CtpForwardingEngineP$0$SendQueue$enqueue(qe) == SUCCESS) {
            sim_log_debug(220U, "Forwarder,Route", "%s forwarding packet %p with queue size %hhu\n", __FUNCTION__, m, /*CtpP.Forwarder*/CtpForwardingEngineP$0$SendQueue$size());


            if (/*CtpP.Forwarder*/CtpForwardingEngineP$0$CtpInfo$getEtx(&gradient) == SUCCESS) {



                packetETX = /*CtpP.Forwarder*/CtpForwardingEngineP$0$CtpPacket$getEtx(m);
                if (packetETX < 0xFFF4) {
                    packetETX += 10;
                  }

                if (packetETX < gradient) {

                    /*CtpP.Forwarder*/CtpForwardingEngineP$0$CtpInfo$triggerImmediateRouteUpdate();







                    /*CtpP.Forwarder*/CtpForwardingEngineP$0$CollectionDebug$logEventMsg(NET_C_FE_LOOP_DETECTED, 
                    /*CtpP.Forwarder*/CtpForwardingEngineP$0$CollectionPacket$getSequenceNumber(m), 
                    /*CtpP.Forwarder*/CtpForwardingEngineP$0$CollectionPacket$getOrigin(m), 
                    /*CtpP.Forwarder*/CtpForwardingEngineP$0$AMPacket$destination(m));

                    /*CtpP.Forwarder*/CtpForwardingEngineP$0$EerInstrumentation$data_inconsistent();
                  }
              }

            if (!/*CtpP.Forwarder*/CtpForwardingEngineP$0$RetxmitTimer$isRunning()) {

                sim_log_debug(221U, "FHangBug", "%s: posted sendTask.\n", __FUNCTION__);
                /*CtpP.Forwarder*/CtpForwardingEngineP$0$sendTask$postTask();
              }


            return newMsg;
          }
        else 
#line 917
          {

            if (/*CtpP.Forwarder*/CtpForwardingEngineP$0$MessagePool$put(newMsg) != SUCCESS) {
              /*CtpP.Forwarder*/CtpForwardingEngineP$0$CollectionDebug$logEvent(NET_C_FE_PUT_MSGPOOL_ERR);
              }
#line 921
            if (/*CtpP.Forwarder*/CtpForwardingEngineP$0$QEntryPool$put(qe) != SUCCESS) {
              /*CtpP.Forwarder*/CtpForwardingEngineP$0$CollectionDebug$logEvent(NET_C_FE_PUT_QEPOOL_ERR);
              }
          }
      }
    }



  /*CtpP.Forwarder*/CtpForwardingEngineP$0$CollectionDebug$logEvent(NET_C_FE_SEND_QUEUE_FULL);

  /*CtpP.Forwarder*/CtpForwardingEngineP$0$EerInstrumentation$data_queuedrop();
  /*CtpP.Forwarder*/CtpForwardingEngineP$0$EerHealth$hlth_dropped();

  return m;
}

# 75 "../net/net_EER_sim/eer/EerHealthP.nc"
static inline error_t EerHealthP$EerHealth$hlth_forwarded(void )
#line 75
{
  unsigned short __nesc_temp74;
  unsigned char *__nesc_temp73;

#line 76
  (__nesc_temp73 = EerHealthP$hlth[sim_node()].forwarded.nxdata, __nesc_hton_uint16(__nesc_temp73, (__nesc_temp74 = __nesc_ntoh_uint16(__nesc_temp73)) + 1), __nesc_temp74);
  return SUCCESS;
}

# 47 "../net/net_EER_sim/eer/EerHealth.nc"
inline static error_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$EerHealth$hlth_forwarded(void ){
#line 47
  unsigned char __nesc_result;
#line 47

#line 47
  __nesc_result = EerHealthP$EerHealth$hlth_forwarded();
#line 47

#line 47
  return __nesc_result;
#line 47
}
#line 47
# 1259 "../net/net_EER_sim/eer/CtpForwardingEngineP.nc"
static inline uint8_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$Packet$payloadLength(message_t *msg)
#line 1259
{
  return /*CtpP.Forwarder*/CtpForwardingEngineP$0$SubPacket$payloadLength(msg) - sizeof(ctp_data_header_t );
}

# 88 "/opt/tinyos-2.1.2/tos/interfaces/AMPacket.nc"
inline static am_addr_t LapTestC$AMPacket$source(message_t * amsg){
#line 88
  unsigned short __nesc_result;
#line 88

#line 88
  __nesc_result = TossimActiveMessageC$AMPacket$source(amsg);
#line 88

#line 88
  return __nesc_result;
#line 88
}
#line 88
# 54 "../net/net_EER_sim/eer/CtpPacket.nc"
inline static uint8_t LapTestC$CtpPacket$getThl(message_t *msg){
#line 54
  unsigned char __nesc_result;
#line 54

#line 54
  __nesc_result = /*CtpP.Forwarder*/CtpForwardingEngineP$0$CtpPacket$getThl(msg);
#line 54

#line 54
  return __nesc_result;
#line 54
}
#line 54
# 102 "LapTestC.nc"
static inline bool LapTestC$DataIntercept$forward(message_t *msg, void *payload, uint8_t len)
#line 102
{
  uint8_t hopCounter = LapTestC$CtpPacket$getThl(msg);
  uint16_t child = LapTestC$AMPacket$source(msg);
  data_msg_t *i_msg = (data_msg_t *)payload;


  if (hopCounter > 1 && hopCounter <= MAX_PATH_LEN) {

      __nesc_hton_uint16(i_msg->path[hopCounter - 2].nxdata, child);
    }
  else {
#line 111
    if (hopCounter == 1) {
        __nesc_hton_uint16(i_msg->path[hopCounter - 1].nxdata, 0);
      }
    }
  return TRUE;
}

# 1342 "../net/net_EER_sim/eer/CtpForwardingEngineP.nc"
static inline 
#line 1341
bool 
/*CtpP.Forwarder*/CtpForwardingEngineP$0$Intercept$default$forward(collection_id_t collectid, message_t *msg, void *payload, 
uint8_t len)
#line 1343
{
  return TRUE;
}

# 31 "/opt/tinyos-2.1.2/tos/interfaces/Intercept.nc"
inline static bool /*CtpP.Forwarder*/CtpForwardingEngineP$0$Intercept$forward(collection_id_t arg_0x40bec430, message_t * msg, void * payload, uint8_t len){
#line 31
  unsigned char __nesc_result;
#line 31

#line 31
  switch (arg_0x40bec430) {
#line 31
    case CTP_DATA_MSG:
#line 31
      __nesc_result = LapTestC$DataIntercept$forward(msg, payload, len);
#line 31
      break;
#line 31
    default:
#line 31
      __nesc_result = /*CtpP.Forwarder*/CtpForwardingEngineP$0$Intercept$default$forward(arg_0x40bec430, msg, payload, len);
#line 31
      break;
#line 31
    }
#line 31

#line 31
  return __nesc_result;
#line 31
}
#line 31
# 1347 "../net/net_EER_sim/eer/CtpForwardingEngineP.nc"
static inline message_t *
/*CtpP.Forwarder*/CtpForwardingEngineP$0$Receive$default$receive(collection_id_t collectid, message_t *msg, void *payload, 
uint8_t len)
#line 1349
{
  return msg;
}

# 78 "/opt/tinyos-2.1.2/tos/interfaces/Receive.nc"
inline static message_t * /*CtpP.Forwarder*/CtpForwardingEngineP$0$Receive$receive(collection_id_t arg_0x40bc5680, message_t * msg, void * payload, uint8_t len){
#line 78
  nx_struct message_t *__nesc_result;
#line 78

#line 78
  switch (arg_0x40bc5680) {
#line 78
    case CTP_DATA_MSG:
#line 78
      __nesc_result = LapTestC$DataReceive$receive(msg, payload, len);
#line 78
      break;
#line 78
    default:
#line 78
      __nesc_result = /*CtpP.Forwarder*/CtpForwardingEngineP$0$Receive$default$receive(arg_0x40bc5680, msg, payload, len);
#line 78
      break;
#line 78
    }
#line 78

#line 78
  return __nesc_result;
#line 78
}
#line 78
# 784 "../net/net_EER_sim/eer/EerParentSetEngineP.nc"
static inline bool /*CtpP.Router*/EerParentSetEngineP$0$RootControl$isRoot(void )
#line 784
{
  return /*CtpP.Router*/EerParentSetEngineP$0$state_is_root[sim_node()];
}

# 43 "../net/net_EER_sim/RootControl.nc"
inline static bool /*CtpP.Forwarder*/CtpForwardingEngineP$0$RootControl$isRoot(void ){
#line 43
  unsigned char __nesc_result;
#line 43

#line 43
  __nesc_result = /*CtpP.Router*/EerParentSetEngineP$0$RootControl$isRoot();
#line 43

#line 43
  return __nesc_result;
#line 43
}
#line 43
# 141 "../net/net_EER_sim/eer/EerInstrumentationP.nc"
static inline error_t EerInstrumentationP$EerInstrumentation$data_pktdup(void )
#line 141
{
  unsigned short __nesc_temp68;
  unsigned char *__nesc_temp67;

#line 142
  (__nesc_temp67 = EerInstrumentationP$stats[sim_node()].data_ndups.nxdata, __nesc_hton_uint16(__nesc_temp67, (__nesc_temp68 = __nesc_ntoh_uint16(__nesc_temp67)) + 1), __nesc_temp68);
  return SUCCESS;
}

# 50 "../net/net_EER_sim/eer/EerInstrumentation.nc"
inline static error_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$EerInstrumentation$data_pktdup(void ){
#line 50
  unsigned char __nesc_result;
#line 50

#line 50
  __nesc_result = EerInstrumentationP$EerInstrumentation$data_pktdup();
#line 50

#line 50
  return __nesc_result;
#line 50
}
#line 50
# 1288 "../net/net_EER_sim/eer/CtpForwardingEngineP.nc"
static inline uint8_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$CtpPacket$getType(message_t *msg)
#line 1288
{
#line 1288
  return __nesc_ntoh_uint8(/*CtpP.Forwarder*/CtpForwardingEngineP$0$getHeader(msg)->type.nxdata);
}

#line 1311
static inline bool /*CtpP.Forwarder*/CtpForwardingEngineP$0$CtpPacket$matchInstance(message_t *m1, message_t *m2)
#line 1311
{
  return /*CtpP.Forwarder*/CtpForwardingEngineP$0$CtpPacket$getOrigin(m1) == /*CtpP.Forwarder*/CtpForwardingEngineP$0$CtpPacket$getOrigin(m2) && 
  /*CtpP.Forwarder*/CtpForwardingEngineP$0$CtpPacket$getSequenceNumber(m1) == /*CtpP.Forwarder*/CtpForwardingEngineP$0$CtpPacket$getSequenceNumber(m2) && 
  /*CtpP.Forwarder*/CtpForwardingEngineP$0$CtpPacket$getThl(m1) == /*CtpP.Forwarder*/CtpForwardingEngineP$0$CtpPacket$getThl(m2) && 
  /*CtpP.Forwarder*/CtpForwardingEngineP$0$CtpPacket$getType(m1) == /*CtpP.Forwarder*/CtpForwardingEngineP$0$CtpPacket$getType(m2);
}

# 112 "/opt/tinyos-2.1.2/tos/system/QueueC.nc"
static inline /*CtpP.SendQueueP*/QueueC$0$queue_t /*CtpP.SendQueueP*/QueueC$0$Queue$element(uint8_t idx)
#line 112
{
  idx += /*CtpP.SendQueueP*/QueueC$0$head[sim_node()];
  if (idx >= 8) {
      idx -= 8;
    }
  return /*CtpP.SendQueueP*/QueueC$0$queue[sim_node()][idx];
}

# 101 "/opt/tinyos-2.1.2/tos/interfaces/Queue.nc"
inline static /*CtpP.Forwarder*/CtpForwardingEngineP$0$SendQueue$t  /*CtpP.Forwarder*/CtpForwardingEngineP$0$SendQueue$element(uint8_t idx){
#line 101
  struct __nesc_unnamed4337 *__nesc_result;
#line 101

#line 101
  __nesc_result = /*CtpP.SendQueueP*/QueueC$0$Queue$element(idx);
#line 101

#line 101
  return __nesc_result;
#line 101
}
#line 101
# 135 "../net/net_EER_sim/eer/LruCtpMsgCacheP.nc"
static inline bool /*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$Cache$lookup(message_t *m)
#line 135
{
  return /*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$lookup(m) < /*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$count[sim_node()];
}

# 59 "/opt/tinyos-2.1.2/tos/interfaces/Cache.nc"
inline static bool /*CtpP.Forwarder*/CtpForwardingEngineP$0$SentCache$lookup(/*CtpP.Forwarder*/CtpForwardingEngineP$0$SentCache$t item){
#line 59
  unsigned char __nesc_result;
#line 59

#line 59
  __nesc_result = /*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$Cache$lookup(item);
#line 59

#line 59
  return __nesc_result;
#line 59
}
#line 59
# 185 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimActiveMessageC.nc"
static inline uint8_t TossimActiveMessageC$Packet$maxPayloadLength(void )
#line 185
{
  return 100;
}

#line 91
static inline uint8_t TossimActiveMessageC$AMSend$maxPayloadLength(am_id_t id)
#line 91
{
  return TossimActiveMessageC$Packet$maxPayloadLength();
}

# 123 "/opt/tinyos-2.1.2/tos/interfaces/AMSend.nc"
inline static uint8_t /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$AMSend$maxPayloadLength(am_id_t arg_0x40de7908){
#line 123
  unsigned char __nesc_result;
#line 123

#line 123
  __nesc_result = TossimActiveMessageC$AMSend$maxPayloadLength(arg_0x40de7908);
#line 123

#line 123
  return __nesc_result;
#line 123
}
#line 123
# 207 "/opt/tinyos-2.1.2/tos/system/AMQueueImplP.nc"
static inline uint8_t /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Send$maxPayloadLength(uint8_t id)
#line 207
{
  return /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$AMSend$maxPayloadLength(0);
}

# 112 "/opt/tinyos-2.1.2/tos/interfaces/Send.nc"
inline static uint8_t /*CtpP.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$0$Send$maxPayloadLength(void ){
#line 112
  unsigned char __nesc_result;
#line 112

#line 112
  __nesc_result = /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Send$maxPayloadLength(0U);
#line 112

#line 112
  return __nesc_result;
#line 112
}
#line 112
# 69 "/opt/tinyos-2.1.2/tos/system/AMQueueEntryP.nc"
static inline uint8_t /*CtpP.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$0$AMSend$maxPayloadLength(void )
#line 69
{
  return /*CtpP.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$0$Send$maxPayloadLength();
}

# 123 "/opt/tinyos-2.1.2/tos/interfaces/AMSend.nc"
inline static uint8_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$SubSend$maxPayloadLength(void ){
#line 123
  unsigned char __nesc_result;
#line 123

#line 123
  __nesc_result = /*CtpP.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$0$AMSend$maxPayloadLength();
#line 123

#line 123
  return __nesc_result;
#line 123
}
#line 123
# 126 "../net/net_EER_sim/eer/EerInstrumentationP.nc"
static inline error_t EerInstrumentationP$EerInstrumentation$data_rxpkt(void )
#line 126
{
  unsigned short __nesc_temp62;
  unsigned char *__nesc_temp61;

#line 127
  (__nesc_temp61 = EerInstrumentationP$stats[sim_node()].data_nrxpkt.nxdata, __nesc_hton_uint16(__nesc_temp61, (__nesc_temp62 = __nesc_ntoh_uint16(__nesc_temp61)) + 1), __nesc_temp62);
  return SUCCESS;
}

# 47 "../net/net_EER_sim/eer/EerInstrumentation.nc"
inline static error_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$EerInstrumentation$data_rxpkt(void ){
#line 47
  unsigned char __nesc_result;
#line 47

#line 47
  __nesc_result = EerInstrumentationP$EerInstrumentation$data_rxpkt();
#line 47

#line 47
  return __nesc_result;
#line 47
}
#line 47
# 286 "/usr/local/lib/ncc/nesc_nx.h"
static __inline  uint8_t __nesc_hton_uint8(void * target, uint8_t value)
#line 286
{
  uint8_t *base = target;

#line 288
  base[0] = value;
  return value;
}

# 1293 "../net/net_EER_sim/eer/CtpForwardingEngineP.nc"
static inline void /*CtpP.Forwarder*/CtpForwardingEngineP$0$CtpPacket$setThl(message_t *msg, uint8_t thl)
#line 1293
{
#line 1293
  __nesc_hton_uint8(/*CtpP.Forwarder*/CtpForwardingEngineP$0$getHeader(msg)->thl.nxdata, thl);
}

#line 946
static inline message_t */*CtpP.Forwarder*/CtpForwardingEngineP$0$SubReceive$receive(message_t *msg, void *payload, uint8_t len)
#line 946
{
  collection_id_t collectid;
  bool duplicate = FALSE;
  fe_queue_entry_t *qe;
  uint8_t i;
#line 950
  uint8_t thl;







  collectid = /*CtpP.Forwarder*/CtpForwardingEngineP$0$CtpPacket$getType(msg);



  thl = /*CtpP.Forwarder*/CtpForwardingEngineP$0$CtpPacket$getThl(msg);
  thl++;
  /*CtpP.Forwarder*/CtpForwardingEngineP$0$CtpPacket$setThl(msg, thl);


  {
    if (thl == 1) 
      {
      }
#line 988
    /*CtpP.Forwarder*/CtpForwardingEngineP$0$EerInstrumentation$data_rxpkt();
  }

  /*CtpP.Forwarder*/CtpForwardingEngineP$0$CollectionDebug$logEventMsg(NET_C_FE_RCV_MSG, 
  /*CtpP.Forwarder*/CtpForwardingEngineP$0$CollectionPacket$getSequenceNumber(msg), 
  /*CtpP.Forwarder*/CtpForwardingEngineP$0$CollectionPacket$getOrigin(msg), 
  thl--);

  if (len > /*CtpP.Forwarder*/CtpForwardingEngineP$0$SubSend$maxPayloadLength()) {
      return msg;
    }



  if (/*CtpP.Forwarder*/CtpForwardingEngineP$0$SentCache$lookup(msg)) {
      /*CtpP.Forwarder*/CtpForwardingEngineP$0$CollectionDebug$logEvent(NET_C_FE_DUPLICATE_CACHE);


      /*CtpP.Forwarder*/CtpForwardingEngineP$0$EerInstrumentation$data_pktdup();
      return msg;
    }

  if (/*CtpP.Forwarder*/CtpForwardingEngineP$0$SendQueue$size() > 0) {
      for (i = /*CtpP.Forwarder*/CtpForwardingEngineP$0$SendQueue$size(); --i; ) {
          qe = /*CtpP.Forwarder*/CtpForwardingEngineP$0$SendQueue$element(i);
          if (/*CtpP.Forwarder*/CtpForwardingEngineP$0$CtpPacket$matchInstance(qe->msg, msg)) {
              duplicate = TRUE;
              break;
            }
        }
    }

  if (duplicate) {
      /*CtpP.Forwarder*/CtpForwardingEngineP$0$CollectionDebug$logEvent(NET_C_FE_DUPLICATE_QUEUE);


      /*CtpP.Forwarder*/CtpForwardingEngineP$0$EerInstrumentation$data_pktdup();
      return msg;
    }
  else {

    if (/*CtpP.Forwarder*/CtpForwardingEngineP$0$RootControl$isRoot()) {

        if (collectid == 205) {
#line 1109
            sim_log_debug(222U, "MN_Root", "Root.Msg: origin:%5u parent:%5u thl:%5u gen:%5u fwd:%5u retx:%5u dropped:%5u petx:%5u letx:%5u \n", __nesc_ntoh_uint16(/*CtpP.Forwarder*/CtpForwardingEngineP$0$getHeader(msg)->origin.nxdata), __nesc_ntoh_uint16(/*CtpP.Forwarder*/CtpForwardingEngineP$0$getHeader(msg)->stats_nexthop.nxdata), __nesc_ntoh_uint8(/*CtpP.Forwarder*/CtpForwardingEngineP$0$getHeader(msg)->thl.nxdata), __nesc_ntoh_uint16(/*CtpP.Forwarder*/CtpForwardingEngineP$0$getHeader(msg)->generated.nxdata), __nesc_ntoh_uint16(/*CtpP.Forwarder*/CtpForwardingEngineP$0$getHeader(msg)->forwarded.nxdata), __nesc_ntoh_uint16(/*CtpP.Forwarder*/CtpForwardingEngineP$0$getHeader(msg)->retx.nxdata), __nesc_ntoh_uint16(/*CtpP.Forwarder*/CtpForwardingEngineP$0$getHeader(msg)->dropped.nxdata), __nesc_ntoh_uint16(/*CtpP.Forwarder*/CtpForwardingEngineP$0$getHeader(msg)->stats_petx.nxdata), __nesc_ntoh_uint16(/*CtpP.Forwarder*/CtpForwardingEngineP$0$getHeader(msg)->stats_letx.nxdata));
          }
        else 









          {
          }
#line 1198
        return /*CtpP.Forwarder*/CtpForwardingEngineP$0$Receive$receive(collectid, msg, 
        /*CtpP.Forwarder*/CtpForwardingEngineP$0$Packet$getPayload(msg, /*CtpP.Forwarder*/CtpForwardingEngineP$0$Packet$payloadLength(msg)), 
        /*CtpP.Forwarder*/CtpForwardingEngineP$0$Packet$payloadLength(msg));
      }
    else {

      if (!/*CtpP.Forwarder*/CtpForwardingEngineP$0$Intercept$forward(collectid, msg, 
      /*CtpP.Forwarder*/CtpForwardingEngineP$0$Packet$getPayload(msg, /*CtpP.Forwarder*/CtpForwardingEngineP$0$Packet$payloadLength(msg)), 
      /*CtpP.Forwarder*/CtpForwardingEngineP$0$Packet$payloadLength(msg))) {
        return msg;
        }
      else 
#line 1208
        {
          sim_log_debug(223U, "Route", "Forwarding packet from %hu.\n", __nesc_ntoh_uint16(/*CtpP.Forwarder*/CtpForwardingEngineP$0$getHeader(msg)->origin.nxdata));


          /*CtpP.Forwarder*/CtpForwardingEngineP$0$EerHealth$hlth_forwarded();

          return /*CtpP.Forwarder*/CtpForwardingEngineP$0$forward(msg);
        }
      }
    }
}

# 721 "../net/net_EER_sim/eer/EerParentSetEngineP.nc"
static inline void /*CtpP.Router*/EerParentSetEngineP$0$CtpInfo$triggerRouteUpdate(void )
#line 721
{
  /*CtpP.Router*/EerParentSetEngineP$0$resetInterval();
}

#line 270
static inline bool /*CtpP.Router*/EerParentSetEngineP$0$passLinkEtxThreshold(uint16_t etx)
#line 270
{
  return etx < ETX_THRESHOLD;
}

# 49 "../net/net_EER_sim/4bitle/LinkEstimator.nc"
inline static uint16_t /*CtpP.Router*/EerParentSetEngineP$0$LinkEstimator$getLinkQuality(uint16_t neighbor){
#line 49
  unsigned short __nesc_result;
#line 49

#line 49
  __nesc_result = LinkEstimatorP$LinkEstimator$getLinkQuality(neighbor);
#line 49

#line 49
  return __nesc_result;
#line 49
}
#line 49
# 872 "../net/net_EER_sim/eer/EerParentSetEngineP.nc"
static inline error_t /*CtpP.Router*/EerParentSetEngineP$0$routingTableUpdateEntry(am_addr_t from, am_addr_t parent, uint16_t etx)
#line 872
{
  uint8_t idx;
  uint16_t linkEtx;

#line 875
  linkEtx = /*CtpP.Router*/EerParentSetEngineP$0$LinkEstimator$getLinkQuality(from);

  idx = /*CtpP.Router*/EerParentSetEngineP$0$routingTableFind(from);
  if (idx == 14) {




      sim_log_debug(302U, "TreeRouting", "%s FAIL, table full\n", __FUNCTION__);
      return FAIL;
    }
  else {
#line 886
    if (idx == /*CtpP.Router*/EerParentSetEngineP$0$routingTableActive[sim_node()]) {

        if (/*CtpP.Router*/EerParentSetEngineP$0$passLinkEtxThreshold(linkEtx)) {
            { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 889
              {
                /*CtpP.Router*/EerParentSetEngineP$0$routingTable[sim_node()][idx].neighbor = from;
                /*CtpP.Router*/EerParentSetEngineP$0$routingTable[sim_node()][idx].info.parent = parent;
                /*CtpP.Router*/EerParentSetEngineP$0$routingTable[sim_node()][idx].info.etx = etx;
                /*CtpP.Router*/EerParentSetEngineP$0$routingTable[sim_node()][idx].info.haveHeard = 1;
                /*CtpP.Router*/EerParentSetEngineP$0$routingTable[sim_node()][idx].info.congested = FALSE;
                /*CtpP.Router*/EerParentSetEngineP$0$routingTableActive[sim_node()]++;
              }
#line 896
              __nesc_atomic_end(__nesc_atomic); }
            sim_log_debug(303U, "TreeRouting", "%s OK, new entry\n", __FUNCTION__);
          }
        else 
#line 898
          {
            sim_log_debug(304U, "TreeRouting", "%s Fail, link quality (%hu) below threshold\n", __FUNCTION__, linkEtx);
          }
      }
    else 
#line 901
      {

        { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 903
          {
            /*CtpP.Router*/EerParentSetEngineP$0$routingTable[sim_node()][idx].neighbor = from;
            /*CtpP.Router*/EerParentSetEngineP$0$routingTable[sim_node()][idx].info.parent = parent;
            /*CtpP.Router*/EerParentSetEngineP$0$routingTable[sim_node()][idx].info.etx = etx;
            /*CtpP.Router*/EerParentSetEngineP$0$routingTable[sim_node()][idx].info.haveHeard = 1;
          }
#line 908
          __nesc_atomic_end(__nesc_atomic); }
        sim_log_debug(305U, "TreeRouting", "%s OK, updated entry\n", __FUNCTION__);
      }
    }
#line 911
  return SUCCESS;
}

# 55 "../net/net_EER_sim/4bitle/LinkEstimator.nc"
inline static error_t /*CtpP.Router*/EerParentSetEngineP$0$LinkEstimator$pinNeighbor(am_addr_t neighbor){
#line 55
  unsigned char __nesc_result;
#line 55

#line 55
  __nesc_result = LinkEstimatorP$LinkEstimator$pinNeighbor(neighbor);
#line 55

#line 55
  return __nesc_result;
#line 55
}
#line 55
# 1251 "../net/net_EER_sim/eer/CtpForwardingEngineP.nc"
static inline void /*CtpP.Forwarder*/CtpForwardingEngineP$0$LinkEstimator$evicted(am_addr_t neighbor)
#line 1251
{
}

# 72 "../net/net_EER_sim/4bitle/LinkEstimator.nc"
inline static void LinkEstimatorP$LinkEstimator$evicted(am_addr_t neighbor){
#line 72
  /*CtpP.Forwarder*/CtpForwardingEngineP$0$LinkEstimator$evicted(neighbor);
#line 72
  /*CtpP.Router*/EerParentSetEngineP$0$LinkEstimator$evicted(neighbor);
#line 72
}
#line 72
# 507 "../net/net_EER_sim/4bitle/LinkEstimatorP.nc"
static inline error_t LinkEstimatorP$LinkEstimator$insertNeighbor(am_addr_t neighbor)
#line 507
{
  uint8_t nidx;

  nidx = LinkEstimatorP$findIdx(neighbor);
  if (nidx != LinkEstimatorP$INVALID_RVAL) {
      sim_log_debug(263U, "LI", "insert: Found the entry, no need to insert\n");
      return SUCCESS;
    }

  nidx = LinkEstimatorP$findEmptyNeighborIdx();
  if (nidx != LinkEstimatorP$INVALID_RVAL) {
      sim_log_debug(264U, "LI", "insert: inserted into the empty slot\n");
      LinkEstimatorP$initNeighborIdx(nidx, neighbor);
      return SUCCESS;
    }
  else 
#line 521
    {
      nidx = LinkEstimatorP$findWorstNeighborIdx(LinkEstimatorP$BEST_ETX);
      if (nidx != LinkEstimatorP$INVALID_RVAL) {
          sim_log_debug(265U, "LI", "insert: inserted by replacing an entry for neighbor: %d\n", LinkEstimatorP$NeighborTable[sim_node()][nidx].ll_addr);

          LinkEstimatorP$LinkEstimator$evicted(LinkEstimatorP$NeighborTable[sim_node()][nidx].ll_addr);
          LinkEstimatorP$initNeighborIdx(nidx, neighbor);
          return SUCCESS;
        }
    }
  return FAIL;
}

# 52 "../net/net_EER_sim/4bitle/LinkEstimator.nc"
inline static error_t /*CtpP.Router*/EerParentSetEngineP$0$LinkEstimator$insertNeighbor(am_addr_t neighbor){
#line 52
  unsigned char __nesc_result;
#line 52

#line 52
  __nesc_result = LinkEstimatorP$LinkEstimator$insertNeighbor(neighbor);
#line 52

#line 52
  return __nesc_result;
#line 52
}
#line 52
# 88 "/opt/tinyos-2.1.2/tos/interfaces/AMPacket.nc"
inline static am_addr_t /*CtpP.Router*/EerParentSetEngineP$0$AMPacket$source(message_t * amsg){
#line 88
  unsigned short __nesc_result;
#line 88

#line 88
  __nesc_result = TossimActiveMessageC$AMPacket$source(amsg);
#line 88

#line 88
  return __nesc_result;
#line 88
}
#line 88
# 106 "../net/net_EER_sim/eer/EerInstrumentationP.nc"
static inline error_t EerInstrumentationP$EerInstrumentation$ctrl_rxpkt(void )
#line 106
{
  unsigned short __nesc_temp54;
  unsigned char *__nesc_temp53;

#line 107
  (__nesc_temp53 = EerInstrumentationP$stats[sim_node()].ctrl_nrxpkt.nxdata, __nesc_hton_uint16(__nesc_temp53, (__nesc_temp54 = __nesc_ntoh_uint16(__nesc_temp53)) + 1), __nesc_temp54);
  return SUCCESS;
}

# 43 "../net/net_EER_sim/eer/EerInstrumentation.nc"
inline static error_t /*CtpP.Router*/EerParentSetEngineP$0$EerInstrumentation$ctrl_rxpkt(void ){
#line 43
  unsigned char __nesc_result;
#line 43

#line 43
  __nesc_result = EerInstrumentationP$EerInstrumentation$ctrl_rxpkt();
#line 43

#line 43
  return __nesc_result;
#line 43
}
#line 43
# 607 "../net/net_EER_sim/eer/EerParentSetEngineP.nc"
static inline message_t */*CtpP.Router*/EerParentSetEngineP$0$BeaconReceive$receive(message_t *msg, void *payload, uint8_t len)
#line 607
{
  am_addr_t from;
  ctp_routing_header_t *rcvBeacon;
  bool congested;


  if (len != sizeof(ctp_routing_header_t )) {
      sim_log_debug(296U, "LITest", "%s, received beacon of size %hhu, expected %i\n", __FUNCTION__, len, (int )sizeof(ctp_routing_header_t ));




      return msg;
    }


  /*CtpP.Router*/EerParentSetEngineP$0$EerInstrumentation$ctrl_rxpkt();


  from = /*CtpP.Router*/EerParentSetEngineP$0$AMPacket$source(msg);
  rcvBeacon = (ctp_routing_header_t *)payload;

  congested = /*CtpP.Router*/EerParentSetEngineP$0$CtpRoutingPacket$getOption(msg, CTP_OPT_ECN);

  sim_log_debug(297U, "TreeRouting", "%s from: %d  [ parent: %d etx: %d]\n", __FUNCTION__, from, __nesc_ntoh_uint16(rcvBeacon->parent.nxdata), __nesc_ntoh_uint16(rcvBeacon->etx.nxdata));





  if (__nesc_ntoh_uint16(rcvBeacon->parent.nxdata) != INVALID_ADDR) {



      if (__nesc_ntoh_uint16(rcvBeacon->etx.nxdata) == 0) {
          sim_log_debug(298U, "TreeRouting", "from a root, inserting if not in table\n");
          /*CtpP.Router*/EerParentSetEngineP$0$LinkEstimator$insertNeighbor(from);
          /*CtpP.Router*/EerParentSetEngineP$0$LinkEstimator$pinNeighbor(from);
        }


      /*CtpP.Router*/EerParentSetEngineP$0$routingTableUpdateEntry(from, __nesc_ntoh_uint16(rcvBeacon->parent.nxdata), __nesc_ntoh_uint16(rcvBeacon->etx.nxdata));
      /*CtpP.Router*/EerParentSetEngineP$0$CtpInfo$setNeighborCongested(from, congested);
    }

  if (/*CtpP.Router*/EerParentSetEngineP$0$CtpRoutingPacket$getOption(msg, CTP_OPT_PULL)) {
      /*CtpP.Router*/EerParentSetEngineP$0$resetInterval();
    }


  if (__nesc_ntoh_uint16(rcvBeacon->etx.nxdata) > /*CtpP.Router*/EerParentSetEngineP$0$routeInfo[sim_node()].etx + 100) {
      /*CtpP.Router*/EerParentSetEngineP$0$CtpInfo$triggerRouteUpdate();
    }

  return msg;
}

# 78 "/opt/tinyos-2.1.2/tos/interfaces/Receive.nc"
inline static message_t * LinkEstimatorP$Receive$receive(message_t * msg, void * payload, uint8_t len){
#line 78
  nx_struct message_t *__nesc_result;
#line 78

#line 78
  __nesc_result = /*CtpP.Router*/EerParentSetEngineP$0$BeaconReceive$receive(msg, payload, len);
#line 78

#line 78
  return __nesc_result;
#line 78
}
#line 78
# 89 "/opt/tinyos-2.1.2/tos/system/RandomMlcgC.nc"
static inline uint16_t RandomMlcgC$Random$rand16(void )
#line 89
{
  return (uint16_t )RandomMlcgC$Random$rand32();
}

# 52 "/opt/tinyos-2.1.2/tos/interfaces/Random.nc"
inline static uint16_t LinkEstimatorP$Random$rand16(void ){
#line 52
  unsigned short __nesc_result;
#line 52

#line 52
  __nesc_result = RandomMlcgC$Random$rand16();
#line 52

#line 52
  return __nesc_result;
#line 52
}
#line 52
# 254 "../net/net_EER_sim/4bitle/LinkEstimatorP.nc"
static inline uint8_t LinkEstimatorP$findRandomNeighborIdx(void )
#line 254
{
  uint8_t i;
  uint8_t cnt;
  uint8_t num_eligible_eviction;

  num_eligible_eviction = 0;
  for (i = 0; i < 14; i++) {
      if (LinkEstimatorP$NeighborTable[sim_node()][i].flags & VALID_ENTRY) {
          if (LinkEstimatorP$NeighborTable[sim_node()][i].flags & PINNED_ENTRY || 
          LinkEstimatorP$NeighborTable[sim_node()][i].flags & MATURE_ENTRY) {
            }
          else 
#line 264
            {
              num_eligible_eviction++;
            }
        }
    }

  if (num_eligible_eviction == 0) {
      return LinkEstimatorP$INVALID_RVAL;
    }

  cnt = LinkEstimatorP$Random$rand16() % num_eligible_eviction;

  for (i = 0; i < 14; i++) {
      if (! LinkEstimatorP$NeighborTable[sim_node()][i].flags & VALID_ENTRY) {
        continue;
        }
#line 279
      if (LinkEstimatorP$NeighborTable[sim_node()][i].flags & PINNED_ENTRY || 
      LinkEstimatorP$NeighborTable[sim_node()][i].flags & MATURE_ENTRY) {
        continue;
        }
#line 282
      if (cnt-- == 0) {
        return i;
        }
    }
#line 285
  return LinkEstimatorP$INVALID_RVAL;
}

# 147 "/opt/tinyos-2.1.2/tos/interfaces/AMPacket.nc"
inline static am_id_t /*CtpP.Router*/EerParentSetEngineP$0$AMPacket$type(message_t * amsg){
#line 147
  unsigned char __nesc_result;
#line 147

#line 147
  __nesc_result = TossimActiveMessageC$AMPacket$type(amsg);
#line 147

#line 147
  return __nesc_result;
#line 147
}
#line 147
# 805 "../net/net_EER_sim/eer/EerParentSetEngineP.nc"
static inline bool /*CtpP.Router*/EerParentSetEngineP$0$CompareBit$shouldInsert(message_t *msg, void *payload, uint8_t len)
#line 805
{

  bool found = FALSE;
  uint16_t pathEtx;
  uint16_t neighEtx;
  int i;
  routing_table_entry *entry;
  ctp_routing_header_t *rcvBeacon;

  if (/*CtpP.Router*/EerParentSetEngineP$0$AMPacket$type(msg) != AM_CTP_ROUTING || 
  len != sizeof(ctp_routing_header_t )) {
    return FALSE;
    }

  rcvBeacon = (ctp_routing_header_t *)payload;

  if (__nesc_ntoh_uint16(rcvBeacon->parent.nxdata) == INVALID_ADDR) {
    return FALSE;
    }
  if (__nesc_ntoh_uint16(rcvBeacon->etx.nxdata) == 0) {
      return TRUE;
    }

  pathEtx = __nesc_ntoh_uint16(rcvBeacon->etx.nxdata);


  for (i = 0; i < /*CtpP.Router*/EerParentSetEngineP$0$routingTableActive[sim_node()] && !found; i++) {
      entry = &/*CtpP.Router*/EerParentSetEngineP$0$routingTable[sim_node()][i];

      if (entry->neighbor == /*CtpP.Router*/EerParentSetEngineP$0$routeInfo[sim_node()].parent) {
        continue;
        }
#line 836
      neighEtx = entry->info.etx;
      found |= pathEtx < neighEtx;
    }
  return found;
}

# 43 "../net/net_EER_sim/eer/CompareBit.nc"
inline static bool LinkEstimatorP$CompareBit$shouldInsert(message_t * msg, void * payload, uint8_t len){
#line 43
  unsigned char __nesc_result;
#line 43

#line 43
  __nesc_result = /*CtpP.Router*/EerParentSetEngineP$0$CompareBit$shouldInsert(msg, payload, len);
#line 43

#line 43
  return __nesc_result;
#line 43
}
#line 43
# 8 "../net/net_EER_sim/eer/DummyActiveMessageP.nc"
static inline bool DummyActiveMessageP$LinkPacketMetadata$highChannelQuality(message_t *msg)
#line 8
{
  return 0;
}

# 47 "/opt/tinyos-2.1.2/tos/interfaces/LinkPacketMetadata.nc"
inline static bool LinkEstimatorP$LinkPacketMetadata$highChannelQuality(message_t * msg){
#line 47
  unsigned char __nesc_result;
#line 47

#line 47
  __nesc_result = DummyActiveMessageP$LinkPacketMetadata$highChannelQuality(msg);
#line 47

#line 47
  return __nesc_result;
#line 47
}
#line 47
# 404 "../net/net_EER_sim/4bitle/LinkEstimatorP.nc"
static inline void LinkEstimatorP$print_neighbor_table(void )
#line 404
{
  uint8_t i;
  neighbor_table_entry_t *ne;

#line 407
  for (i = 0; i < 14; i++) {
      ne = &LinkEstimatorP$NeighborTable[sim_node()][i];
      if (ne->flags & VALID_ENTRY) {
          sim_log_debug(258U, "LI,LITest", "%d:%d inQ=%d, rcv=%d, fail=%d, Q=%d\n", i, ne->ll_addr, ne->inquality, ne->rcvcnt, ne->failcnt, LinkEstimatorP$computeETX(ne->inquality));
        }
    }
}

# 88 "/opt/tinyos-2.1.2/tos/interfaces/AMPacket.nc"
inline static am_addr_t LinkEstimatorP$SubAMPacket$source(message_t * amsg){
#line 88
  unsigned short __nesc_result;
#line 88

#line 88
  __nesc_result = TossimActiveMessageC$AMPacket$source(amsg);
#line 88

#line 88
  return __nesc_result;
#line 88
}
#line 88
# 126 "/opt/tinyos-2.1.2/tos/interfaces/Packet.nc"
inline static void * LinkEstimatorP$SubPacket$getPayload(message_t * msg, uint8_t len){
#line 126
  void *__nesc_result;
#line 126

#line 126
  __nesc_result = TossimActiveMessageC$Packet$getPayload(msg, len);
#line 126

#line 126
  return __nesc_result;
#line 126
}
#line 126
# 113 "../net/net_EER_sim/4bitle/LinkEstimatorP.nc"
static inline linkest_header_t *LinkEstimatorP$getHeader(message_t *m)
#line 113
{
  return (linkest_header_t *)LinkEstimatorP$SubPacket$getPayload(m, sizeof(linkest_header_t ));
}

# 78 "/opt/tinyos-2.1.2/tos/interfaces/AMPacket.nc"
inline static am_addr_t LinkEstimatorP$SubAMPacket$destination(message_t * amsg){
#line 78
  unsigned short __nesc_result;
#line 78

#line 78
  __nesc_result = TossimActiveMessageC$AMPacket$destination(amsg);
#line 78

#line 78
  return __nesc_result;
#line 78
}
#line 78
# 636 "../net/net_EER_sim/4bitle/LinkEstimatorP.nc"
static inline void LinkEstimatorP$processReceivedMessage(message_t * msg, void * payload, uint8_t len)
#line 636
{
  uint8_t nidx;
  uint8_t num_entries;

  sim_log_debug(268U, "LI", "LI receiving packet, buf addr: %x\n", payload);
  LinkEstimatorP$print_packet(msg, len);

  if (LinkEstimatorP$SubAMPacket$destination(msg) == AM_BROADCAST_ADDR) {
      linkest_header_t *hdr = LinkEstimatorP$getHeader(msg);
      am_addr_t ll_addr;

      ll_addr = LinkEstimatorP$SubAMPacket$source(msg);

      sim_log_debug(269U, "LI", "Got seq: %d from link: %d\n", __nesc_ntoh_uint8(hdr->seq.nxdata), ll_addr);

      num_entries = __nesc_ntoh_uint8(hdr->flags.nxdata) & NUM_ENTRIES_FLAG;
      LinkEstimatorP$print_neighbor_table();
#line 668
      nidx = LinkEstimatorP$findIdx(ll_addr);
      if (nidx != LinkEstimatorP$INVALID_RVAL) {
          sim_log_debug(270U, "LI", "Found the entry so updating\n");
          LinkEstimatorP$updateNeighborEntryIdx(nidx, __nesc_ntoh_uint8(hdr->seq.nxdata));
        }
      else 
#line 672
        {
          nidx = LinkEstimatorP$findEmptyNeighborIdx();
          if (nidx != LinkEstimatorP$INVALID_RVAL) {
              sim_log_debug(271U, "LI", "Found an empty entry\n");
              LinkEstimatorP$initNeighborIdx(nidx, ll_addr);
              LinkEstimatorP$NeighborTable[sim_node()][nidx].lastseq = __nesc_ntoh_uint8(hdr->seq.nxdata);
              LinkEstimatorP$updateNeighborEntryIdx(nidx, __nesc_ntoh_uint8(hdr->seq.nxdata));
            }
          else 
#line 679
            {
              nidx = LinkEstimatorP$findWorstNeighborIdx(LinkEstimatorP$EVICT_ETX_THRESHOLD);
              if (nidx != LinkEstimatorP$INVALID_RVAL) {
                  sim_log_debug(272U, "LI", "Evicted neighbor %d at idx %d\n", LinkEstimatorP$NeighborTable[sim_node()][nidx].ll_addr, nidx);

                  LinkEstimatorP$LinkEstimator$evicted(LinkEstimatorP$NeighborTable[sim_node()][nidx].ll_addr);
                  LinkEstimatorP$initNeighborIdx(nidx, ll_addr);
                }
              else 
#line 686
                {
                  sim_log_debug(273U, "LI", "No room in the table\n");





                  if (LinkEstimatorP$LinkPacketMetadata$highChannelQuality(msg)) {
                      if (LinkEstimatorP$CompareBit$shouldInsert(msg, 
                      LinkEstimatorP$Packet$getPayload(msg, LinkEstimatorP$Packet$payloadLength(msg)), 
                      LinkEstimatorP$Packet$payloadLength(msg))) {
                          nidx = LinkEstimatorP$findRandomNeighborIdx();
                          if (nidx != LinkEstimatorP$INVALID_RVAL) {
                              LinkEstimatorP$LinkEstimator$evicted(LinkEstimatorP$NeighborTable[sim_node()][nidx].ll_addr);
                              LinkEstimatorP$initNeighborIdx(nidx, ll_addr);
                            }
                        }
                    }
                }
            }
        }
    }
}

#line 734
static inline message_t *LinkEstimatorP$SubReceive$receive(message_t *msg, 
void *payload, 
uint8_t len)
#line 736
{
  sim_log_debug(274U, "LI", "Received upper packet. Will signal up\n");
  LinkEstimatorP$processReceivedMessage(msg, payload, len);
  return LinkEstimatorP$Receive$receive(msg, 
  LinkEstimatorP$Packet$getPayload(msg, LinkEstimatorP$Packet$payloadLength(msg)), 
  LinkEstimatorP$Packet$payloadLength(msg));
}

# 212 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimActiveMessageC.nc"
static inline message_t *TossimActiveMessageC$Receive$default$receive(am_id_t id, message_t *msg, void *payload, uint8_t len)
#line 212
{
  return msg;
}

# 78 "/opt/tinyos-2.1.2/tos/interfaces/Receive.nc"
inline static message_t * TossimActiveMessageC$Receive$receive(am_id_t arg_0x408ebe70, message_t * msg, void * payload, uint8_t len){
#line 78
  nx_struct message_t *__nesc_result;
#line 78

#line 78
  switch (arg_0x408ebe70) {
#line 78
    case 112:
#line 78
      __nesc_result = LinkEstimatorP$SubReceive$receive(msg, payload, len);
#line 78
      break;
#line 78
    case 113:
#line 78
      __nesc_result = /*CtpP.Forwarder*/CtpForwardingEngineP$0$SubReceive$receive(msg, payload, len);
#line 78
      break;
#line 78
    default:
#line 78
      __nesc_result = TossimActiveMessageC$Receive$default$receive(arg_0x408ebe70, msg, payload, len);
#line 78
      break;
#line 78
    }
#line 78

#line 78
  return __nesc_result;
#line 78
}
#line 78
# 332 "../net/net_EER_sim/4bitle/LinkEstimatorP.nc"
static inline void LinkEstimatorP$updateNeighborTableEst(am_addr_t n)
#line 332
{
  uint8_t i;
#line 333
  uint8_t totalPkt;
  neighbor_table_entry_t *ne;
  uint8_t newEst;
  uint8_t minPkt;

  minPkt = LinkEstimatorP$BLQ_PKT_WINDOW;
  sim_log_debug(251U, "LI", "%s\n", __FUNCTION__);
  for (i = 0; i < 14; i++) {
      ne = &LinkEstimatorP$NeighborTable[sim_node()][i];
      if (ne->ll_addr == n) {
          if (ne->flags & VALID_ENTRY) {
              sim_log_debug(252U, "LI", "Making link: %d mature\n", i);
              totalPkt = ne->rcvcnt + ne->failcnt;

              if (!(ne->flags & MATURE_ENTRY)) {
                  newEst = 250UL * ne->rcvcnt / totalPkt;
                  ne->inquality = newEst;
                  ne->etx = 
                  LinkEstimatorP$computeETX(ne->inquality);
                }

              ne->flags |= MATURE_ENTRY;
              sim_log_debug(253U, "LI", "MinPkt: %d, totalPkt: %d\n", minPkt, totalPkt);
              newEst = 250UL * ne->rcvcnt / totalPkt;
              sim_log_debug(254U, "LI,LITest", "  %hu: %hhu -> %hhu", ne->ll_addr, ne->inquality, (LinkEstimatorP$ALPHA * ne->inquality + (10 - LinkEstimatorP$ALPHA) * newEst) / 10);
              ne->inquality = (LinkEstimatorP$ALPHA * ne->inquality + (10 - LinkEstimatorP$ALPHA) * newEst) / 10;
              ne->rcvcnt = 0;
              ne->failcnt = 0;
              LinkEstimatorP$updateETX(ne, LinkEstimatorP$computeETX(ne->inquality));
            }
          else 
#line 362
            {
              sim_log_debug(255U, "LI", " - entry %i is invalid.\n", (int )i);
            }
        }
    }
}

# 915 "../net/net_EER_sim/eer/EerParentSetEngineP.nc"
static inline error_t /*CtpP.Router*/EerParentSetEngineP$0$routingTableEvict(am_addr_t neighbor)
#line 915
{
  uint8_t idx;
#line 916
  uint8_t i;

#line 917
  idx = /*CtpP.Router*/EerParentSetEngineP$0$routingTableFind(neighbor);
  if (idx == /*CtpP.Router*/EerParentSetEngineP$0$routingTableActive[sim_node()]) {
    return FAIL;
    }
#line 920
  /*CtpP.Router*/EerParentSetEngineP$0$routingTableActive[sim_node()]--;
  for (i = idx; i < /*CtpP.Router*/EerParentSetEngineP$0$routingTableActive[sim_node()]; i++) {
      /*CtpP.Router*/EerParentSetEngineP$0$routingTable[sim_node()][i] = /*CtpP.Router*/EerParentSetEngineP$0$routingTable[sim_node()][i + 1];
    }
  return SUCCESS;
}

# 139 "/opt/tinyos-2.1.2/tos/lib/tossim/SimSchedulerBasicP.nc"
static inline bool SimSchedulerBasicP$isWaiting(uint8_t id)
{
  return SimSchedulerBasicP$m_next[sim_node()][id] != SimSchedulerBasicP$NO_TASK || SimSchedulerBasicP$m_tail[sim_node()] == id;
}

static inline bool SimSchedulerBasicP$pushTask(uint8_t id)
{
  if (!SimSchedulerBasicP$isWaiting(id)) 
    {
      if (SimSchedulerBasicP$m_head[sim_node()] == SimSchedulerBasicP$NO_TASK) 
        {
          SimSchedulerBasicP$m_head[sim_node()] = id;
          SimSchedulerBasicP$m_tail[sim_node()] = id;
        }
      else 
        {
          SimSchedulerBasicP$m_next[sim_node()][SimSchedulerBasicP$m_tail[sim_node()]] = id;
          SimSchedulerBasicP$m_tail[sim_node()] = id;
        }
      return TRUE;
    }
  else 
    {
      return FALSE;
    }
}

#line 69
static inline int SimSchedulerBasicP$sim_config_task_latency(void )
#line 69
{
#line 69
  return 100;
}

# 65 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimActiveMessageC.nc"
static inline tossim_header_t *TossimActiveMessageC$getHeader(message_t *amsg)
#line 65
{
  return (tossim_header_t *)(amsg->data - sizeof(tossim_header_t ));
}

#line 177
static inline uint8_t TossimActiveMessageC$Packet$payloadLength(message_t *msg)
#line 177
{
  return __nesc_ntoh_uint8(TossimActiveMessageC$getHeader(msg)->length.nxdata);
}

# 78 "/opt/tinyos-2.1.2/tos/interfaces/Packet.nc"
inline static uint8_t LinkEstimatorP$SubPacket$payloadLength(message_t * msg){
#line 78
  unsigned char __nesc_result;
#line 78

#line 78
  __nesc_result = TossimActiveMessageC$Packet$payloadLength(msg);
#line 78

#line 78
  return __nesc_result;
#line 78
}
#line 78
#line 106
inline static uint8_t LinkEstimatorP$SubPacket$maxPayloadLength(void ){
#line 106
  unsigned char __nesc_result;
#line 106

#line 106
  __nesc_result = TossimActiveMessageC$Packet$maxPayloadLength();
#line 106

#line 106
  return __nesc_result;
#line 106
}
#line 106
# 769 "../net/net_EER_sim/4bitle/LinkEstimatorP.nc"
static inline uint8_t LinkEstimatorP$Packet$maxPayloadLength(void )
#line 769
{
  return LinkEstimatorP$SubPacket$maxPayloadLength() - sizeof(linkest_header_t );
}

#line 625
static inline uint8_t LinkEstimatorP$Send$maxPayloadLength(void )
#line 625
{
  return LinkEstimatorP$Packet$maxPayloadLength();
}

# 123 "/opt/tinyos-2.1.2/tos/interfaces/AMSend.nc"
inline static uint8_t /*CtpP.Router*/EerParentSetEngineP$0$BeaconSend$maxPayloadLength(void ){
#line 123
  unsigned char __nesc_result;
#line 123

#line 123
  __nesc_result = LinkEstimatorP$Send$maxPayloadLength();
#line 123

#line 123
  return __nesc_result;
#line 123
}
#line 123
# 629 "../net/net_EER_sim/4bitle/LinkEstimatorP.nc"
static inline void *LinkEstimatorP$Send$getPayload(message_t *msg, uint8_t len)
#line 629
{
  return LinkEstimatorP$Packet$getPayload(msg, len);
}

# 135 "/opt/tinyos-2.1.2/tos/interfaces/AMSend.nc"
inline static void * /*CtpP.Router*/EerParentSetEngineP$0$BeaconSend$getPayload(message_t * msg, uint8_t len){
#line 135
  void *__nesc_result;
#line 135

#line 135
  __nesc_result = LinkEstimatorP$Send$getPayload(msg, len);
#line 135

#line 135
  return __nesc_result;
#line 135
}
#line 135
# 600 "../net/net_EER_sim/eer/EerParentSetEngineP.nc"
static inline ctp_routing_header_t */*CtpP.Router*/EerParentSetEngineP$0$getHeader(message_t * m)
#line 600
{
  return (ctp_routing_header_t *)/*CtpP.Router*/EerParentSetEngineP$0$BeaconSend$getPayload(m, /*CtpP.Router*/EerParentSetEngineP$0$BeaconSend$maxPayloadLength());
}

# 46 "/opt/tinyos-2.1.2/tos/interfaces/Random.nc"
inline static uint32_t /*CtpP.Router*/EerParentSetEngineP$0$Random$rand32(void ){
#line 46
  unsigned int __nesc_result;
#line 46

#line 46
  __nesc_result = RandomMlcgC$Random$rand32();
#line 46

#line 46
  return __nesc_result;
#line 46
}
#line 46
# 164 "/opt/tinyos-2.1.2/tos/lib/timer/VirtualizeTimerC.nc"
static inline void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$stop(uint8_t num)
{
  /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$m_timers[sim_node()][num].isrunning = FALSE;
}

# 78 "/opt/tinyos-2.1.2/tos/lib/timer/Timer.nc"
inline static void /*CtpP.Router*/EerParentSetEngineP$0$BeaconTimer$stop(void ){
#line 78
  /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$stop(1U);
#line 78
}
#line 78
# 67 "/opt/tinyos-2.1.2/tos/interfaces/TaskBasic.nc"
inline static error_t /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$updateFromTimer$postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SimSchedulerBasicP$TaskBasic$postTask(/*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$updateFromTimer);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
# 61 "/opt/tinyos-2.1.2/tos/lib/tossim/SimMoteP.nc"
static inline long long int SimMoteP$SimMote$getStartTime(void )
#line 61
{
  return SimMoteP$startTime[sim_node()];
}

# 127 "/opt/tinyos-2.1.2/tos/chips/atm128/timer/sim/HplAtm128Timer0AsyncP.nc"
static inline sim_time_t HplAtm128Timer0AsyncP$notify_clockTicksPerSec(void )
#line 127
{
  return ATM128_TIMER0_TICKSPPS;
}

#line 154
static inline sim_time_t HplAtm128Timer0AsyncP$sim_to_clock(sim_time_t t)
#line 154
{
  t *= HplAtm128Timer0AsyncP$notify_clockTicksPerSec();
  t /= sim_ticks_per_sec();
  return t;
}

# 53 "/opt/tinyos-2.1.2/tos/chips/atm128/timer/HplAtm128TimerCtrl8.nc"
inline static Atm128_TIFR_t /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$TimerCtrl$getInterruptFlag(void ){
#line 53
  union __nesc_unnamed4317 __nesc_result;
#line 53

#line 53
  __nesc_result = HplAtm128Timer0AsyncP$Timer0Ctrl$getInterruptFlag();
#line 53

#line 53
  return __nesc_result;
#line 53
}
#line 53
# 116 "../net/net_EER_sim/eer/EerInstrumentationP.nc"
static inline error_t EerInstrumentationP$EerInstrumentation$ctrl_tricklereset(void )
#line 116
{
  unsigned short __nesc_temp58;
  unsigned char *__nesc_temp57;

#line 117
  (__nesc_temp57 = EerInstrumentationP$stats[sim_node()].ctrl_ntricklereset.nxdata, __nesc_hton_uint16(__nesc_temp57, (__nesc_temp58 = __nesc_ntoh_uint16(__nesc_temp57)) + 1), __nesc_temp58);
  return SUCCESS;
}

# 45 "../net/net_EER_sim/eer/EerInstrumentation.nc"
inline static error_t /*CtpP.Router*/EerParentSetEngineP$0$EerInstrumentation$ctrl_tricklereset(void ){
#line 45
  unsigned char __nesc_result;
#line 45

#line 45
  __nesc_result = EerInstrumentationP$EerInstrumentation$ctrl_tricklereset();
#line 45

#line 45
  return __nesc_result;
#line 45
}
#line 45
# 60 "../net/net_EER_sim/eer/CtpPacket.nc"
inline static am_addr_t LapTestC$CtpPacket$getOrigin(message_t *msg){
#line 60
  unsigned short __nesc_result;
#line 60

#line 60
  __nesc_result = /*CtpP.Forwarder*/CtpForwardingEngineP$0$CtpPacket$getOrigin(msg);
#line 60

#line 60
  return __nesc_result;
#line 60
}
#line 60



inline static uint8_t LapTestC$CtpPacket$getSequenceNumber(message_t *msg){
#line 63
  unsigned char __nesc_result;
#line 63

#line 63
  __nesc_result = /*CtpP.Forwarder*/CtpForwardingEngineP$0$CtpPacket$getSequenceNumber(msg);
#line 63

#line 63
  return __nesc_result;
#line 63
}
#line 63
# 61 "/opt/tinyos-2.1.2/tos/system/QueueC.nc"
static inline uint8_t /*CtpP.SendQueueP*/QueueC$0$Queue$maxSize(void )
#line 61
{
  return 8;
}

# 1353 "../net/net_EER_sim/eer/CtpForwardingEngineP.nc"
static inline message_t *
/*CtpP.Forwarder*/CtpForwardingEngineP$0$Snoop$default$receive(collection_id_t collectid, message_t *msg, void *payload, 
uint8_t len)
#line 1355
{
  return msg;
}

# 78 "/opt/tinyos-2.1.2/tos/interfaces/Receive.nc"
inline static message_t * /*CtpP.Forwarder*/CtpForwardingEngineP$0$Snoop$receive(collection_id_t arg_0x40bc5d68, message_t * msg, void * payload, uint8_t len){
#line 78
  nx_struct message_t *__nesc_result;
#line 78

#line 78
    __nesc_result = /*CtpP.Forwarder*/CtpForwardingEngineP$0$Snoop$default$receive(arg_0x40bc5d68, msg, payload, len);
#line 78

#line 78
  return __nesc_result;
#line 78
}
#line 78
# 76 "../net/net_EER_sim/eer/CtpInfo.nc"
inline static void /*CtpP.Forwarder*/CtpForwardingEngineP$0$CtpInfo$setNeighborCongested(am_addr_t n, bool congested){
#line 76
  /*CtpP.Router*/EerParentSetEngineP$0$CtpInfo$setNeighborCongested(n, congested);
#line 76
}
#line 76
#line 59
inline static void /*CtpP.Forwarder*/CtpForwardingEngineP$0$CtpInfo$triggerRouteUpdate(void ){
#line 59
  /*CtpP.Router*/EerParentSetEngineP$0$CtpInfo$triggerRouteUpdate();
#line 59
}
#line 59
# 88 "/opt/tinyos-2.1.2/tos/interfaces/AMPacket.nc"
inline static am_addr_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$AMPacket$source(message_t * amsg){
#line 88
  unsigned short __nesc_result;
#line 88

#line 88
  __nesc_result = TossimActiveMessageC$AMPacket$source(amsg);
#line 88

#line 88
  return __nesc_result;
#line 88
}
#line 88
# 1218 "../net/net_EER_sim/eer/CtpForwardingEngineP.nc"
static inline message_t */*CtpP.Forwarder*/CtpForwardingEngineP$0$SubSnoop$receive(message_t *msg, void *payload, uint8_t len)
#line 1218
{

  am_addr_t proximalSrc = /*CtpP.Forwarder*/CtpForwardingEngineP$0$AMPacket$source(msg);



  if (/*CtpP.Forwarder*/CtpForwardingEngineP$0$CtpPacket$option(msg, CTP_OPT_PULL)) {
      /*CtpP.Forwarder*/CtpForwardingEngineP$0$CtpInfo$triggerRouteUpdate();
    }


  /*CtpP.Forwarder*/CtpForwardingEngineP$0$CtpInfo$setNeighborCongested(proximalSrc, /*CtpP.Forwarder*/CtpForwardingEngineP$0$CtpPacket$option(msg, CTP_OPT_ECN));
  return /*CtpP.Forwarder*/CtpForwardingEngineP$0$Snoop$receive(/*CtpP.Forwarder*/CtpForwardingEngineP$0$CtpPacket$getType(msg), 
  msg, payload + sizeof(ctp_data_header_t ), 
  len - sizeof(ctp_data_header_t ));
}

# 216 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimActiveMessageC.nc"
static inline message_t *TossimActiveMessageC$Snoop$default$receive(am_id_t id, message_t *msg, void *payload, uint8_t len)
#line 216
{
  return msg;
}

# 78 "/opt/tinyos-2.1.2/tos/interfaces/Receive.nc"
inline static message_t * TossimActiveMessageC$Snoop$receive(am_id_t arg_0x408ea5b8, message_t * msg, void * payload, uint8_t len){
#line 78
  nx_struct message_t *__nesc_result;
#line 78

#line 78
  switch (arg_0x408ea5b8) {
#line 78
    case 113:
#line 78
      __nesc_result = /*CtpP.Forwarder*/CtpForwardingEngineP$0$SubSnoop$receive(msg, payload, len);
#line 78
      break;
#line 78
    default:
#line 78
      __nesc_result = TossimActiveMessageC$Snoop$default$receive(arg_0x408ea5b8, msg, payload, len);
#line 78
      break;
#line 78
    }
#line 78

#line 78
  return __nesc_result;
#line 78
}
#line 78
# 89 "/opt/tinyos-2.1.2/tos/chips/atm128/sim/atm128hardware.h"
static __inline void __nesc_disable_interrupt()
#line 89
{
  atm128RegFile[sim_node()][* (volatile uint8_t *)&atm128RegFile[sim_node()][0x3F]] &= ~(1 << 7);
}






#line 97
__inline  __nesc_atomic_t 
__nesc_atomic_start(void )
{
  __nesc_atomic_t result = * (volatile uint8_t *)&atm128RegFile[sim_node()][0x3F];

#line 101
  __nesc_disable_interrupt();
  return result;
}



#line 106
__inline  void 
__nesc_atomic_end(__nesc_atomic_t original_SREG)
{
  * (volatile uint8_t *)&atm128RegFile[sim_node()][0x3F] = original_SREG;
}

# 85 "/opt/tinyos-2.1.2/tos/lib/tossim/SimSchedulerBasicP.nc"
static inline void SimSchedulerBasicP$sim_scheduler_event_handle(sim_event_t *e)
#line 85
{
  SimSchedulerBasicP$sim_scheduler_event_pending[sim_node()] = FALSE;








  if (SimSchedulerBasicP$Scheduler$runNextTask()) {
      SimSchedulerBasicP$sim_scheduler_submit_event();
    }
}




static inline void SimSchedulerBasicP$sim_scheduler_event_init(sim_event_t *e)
#line 103
{
  e->mote = sim_node();
  e->force = 0;
  e->data = (void *)0;
  e->handle = SimSchedulerBasicP$sim_scheduler_event_handle;
  e->cleanup = sim_queue_cleanup_none;
}

#line 166
static inline void SimSchedulerBasicP$Scheduler$init(void )
{
  sim_log_debug(104U, "Scheduler", "Initializing scheduler.\n");
  /* atomic removed: atomic calls only */
  {
    memset(SimSchedulerBasicP$m_next[sim_node()], SimSchedulerBasicP$NO_TASK, sizeof SimSchedulerBasicP$m_next[sim_node()]);
    SimSchedulerBasicP$m_head[sim_node()] = SimSchedulerBasicP$NO_TASK;
    SimSchedulerBasicP$m_tail[sim_node()] = SimSchedulerBasicP$NO_TASK;

    SimSchedulerBasicP$sim_scheduler_event_pending[sim_node()] = FALSE;
    SimSchedulerBasicP$sim_scheduler_event_init(&SimSchedulerBasicP$sim_scheduler_event[sim_node()]);
  }
}

# 57 "/opt/tinyos-2.1.2/tos/interfaces/Scheduler.nc"
inline static void SimMainP$Scheduler$init(void ){
#line 57
  SimSchedulerBasicP$Scheduler$init();
#line 57
}
#line 57
# 120 "/opt/tinyos-2.1.2/tos/lib/tossim/SimSchedulerBasicP.nc"
static inline uint8_t SimSchedulerBasicP$popTask(void )
{
  if (SimSchedulerBasicP$m_head[sim_node()] != SimSchedulerBasicP$NO_TASK) 
    {
      uint8_t id = SimSchedulerBasicP$m_head[sim_node()];

#line 125
      SimSchedulerBasicP$m_head[sim_node()] = SimSchedulerBasicP$m_next[sim_node()][SimSchedulerBasicP$m_head[sim_node()]];
      if (SimSchedulerBasicP$m_head[sim_node()] == SimSchedulerBasicP$NO_TASK) 
        {
          SimSchedulerBasicP$m_tail[sim_node()] = SimSchedulerBasicP$NO_TASK;
        }
      SimSchedulerBasicP$m_next[sim_node()][id] = SimSchedulerBasicP$NO_TASK;
      return id;
    }
  else 
    {
      return SimSchedulerBasicP$NO_TASK;
    }
}

# 1328 "../net/net_EER_sim/eer/CtpForwardingEngineP.nc"
static inline bool /*CtpP.Forwarder*/CtpForwardingEngineP$0$hasState(uint8_t state)
#line 1328
{
  return /*CtpP.Forwarder*/CtpForwardingEngineP$0$forwardingState[sim_node()] & state;
}

# 70 "../net/net_EER_sim/eer/EerHealthP.nc"
static inline error_t EerHealthP$EerHealth$get_hlth_generated(nx_uint16_t *gen)
#line 70
{
  __nesc_hton_uint16((*gen).nxdata, __nesc_ntoh_uint16(EerHealthP$hlth[sim_node()].generated.nxdata));
  return SUCCESS;
}

# 45 "../net/net_EER_sim/eer/EerHealth.nc"
inline static error_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$EerHealth$get_hlth_generated(nx_uint16_t *gen){
#line 45
  unsigned char __nesc_result;
#line 45

#line 45
  __nesc_result = EerHealthP$EerHealth$get_hlth_generated(gen);
#line 45

#line 45
  return __nesc_result;
#line 45
}
#line 45
# 65 "../net/net_EER_sim/eer/EerHealthP.nc"
static inline error_t EerHealthP$EerHealth$hlth_generated(void )
#line 65
{
  unsigned short __nesc_temp72;
  unsigned char *__nesc_temp71;

#line 66
  (__nesc_temp71 = EerHealthP$hlth[sim_node()].generated.nxdata, __nesc_hton_uint16(__nesc_temp71, (__nesc_temp72 = __nesc_ntoh_uint16(__nesc_temp71)) + 1), __nesc_temp72);
  return SUCCESS;
}

# 44 "../net/net_EER_sim/eer/EerHealth.nc"
inline static error_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$EerHealth$hlth_generated(void ){
#line 44
  unsigned char __nesc_result;
#line 44

#line 44
  __nesc_result = EerHealthP$EerHealth$hlth_generated();
#line 44

#line 44
  return __nesc_result;
#line 44
}
#line 44
# 50 "../net/net_EER_sim/CollectionIdP.nc"
static inline collection_id_t /*LapTestAppC.CtpDataSenderC.CollectionSenderP.CollectionIdP*/CollectionIdP$0$CollectionId$fetch(void )
#line 50
{
  return 221;
}

# 1359 "../net/net_EER_sim/eer/CtpForwardingEngineP.nc"
static inline collection_id_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$CollectionId$default$fetch(uint8_t client)
#line 1359
{
  return 0;
}

# 46 "../net/net_EER_sim/CollectionId.nc"
inline static collection_id_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$CollectionId$fetch(uint8_t arg_0x40bfa010){
#line 46
  unsigned char __nesc_result;
#line 46

#line 46
  switch (arg_0x40bfa010) {
#line 46
    case 0U:
#line 46
      __nesc_result = /*LapTestAppC.CtpDataSenderC.CollectionSenderP.CollectionIdP*/CollectionIdP$0$CollectionId$fetch();
#line 46
      break;
#line 46
    default:
#line 46
      __nesc_result = /*CtpP.Forwarder*/CtpForwardingEngineP$0$CollectionId$default$fetch(arg_0x40bfa010);
#line 46
      break;
#line 46
    }
#line 46

#line 46
  return __nesc_result;
#line 46
}
#line 46
# 181 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimActiveMessageC.nc"
static inline void TossimActiveMessageC$Packet$setPayloadLength(message_t *msg, uint8_t len)
#line 181
{
  __nesc_hton_uint8(TossimActiveMessageC$getHeader(msg)->length.nxdata, len);
}

# 94 "/opt/tinyos-2.1.2/tos/interfaces/Packet.nc"
inline static void /*CtpP.Forwarder*/CtpForwardingEngineP$0$SubPacket$setPayloadLength(message_t * msg, uint8_t len){
#line 94
  TossimActiveMessageC$Packet$setPayloadLength(msg, len);
#line 94
}
#line 94
# 1263 "../net/net_EER_sim/eer/CtpForwardingEngineP.nc"
static inline void /*CtpP.Forwarder*/CtpForwardingEngineP$0$Packet$setPayloadLength(message_t *msg, uint8_t len)
#line 1263
{
  /*CtpP.Forwarder*/CtpForwardingEngineP$0$SubPacket$setPayloadLength(msg, len + sizeof(ctp_data_header_t ));
}

# 106 "/opt/tinyos-2.1.2/tos/interfaces/Packet.nc"
inline static uint8_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$SubPacket$maxPayloadLength(void ){
#line 106
  unsigned char __nesc_result;
#line 106

#line 106
  __nesc_result = TossimActiveMessageC$Packet$maxPayloadLength();
#line 106

#line 106
  return __nesc_result;
#line 106
}
#line 106
# 1267 "../net/net_EER_sim/eer/CtpForwardingEngineP.nc"
static inline uint8_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$Packet$maxPayloadLength(void )
#line 1267
{
  return /*CtpP.Forwarder*/CtpForwardingEngineP$0$SubPacket$maxPayloadLength() - sizeof(ctp_data_header_t );
}

#line 438
static inline uint8_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$Send$maxPayloadLength(uint8_t client)
#line 438
{
  return /*CtpP.Forwarder*/CtpForwardingEngineP$0$Packet$maxPayloadLength();
}

#line 360
static inline error_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$Send$send(uint8_t client, message_t *msg, uint8_t len)
#line 360
{
  ctp_data_header_t *hdr;
  fe_queue_entry_t *qe;

#line 363
  sim_log_debug(198U, "Forwarder", "%s: sending packet from client %hhu: %x, len %hhu\n", __FUNCTION__, client, msg, len);



  if (!/*CtpP.Forwarder*/CtpForwardingEngineP$0$hasState(/*CtpP.Forwarder*/CtpForwardingEngineP$0$ROUTING_ON)) {
      return EOFF;
    }

  if (len > /*CtpP.Forwarder*/CtpForwardingEngineP$0$Send$maxPayloadLength(client)) {
      return ESIZE;
    }


  /*CtpP.Forwarder*/CtpForwardingEngineP$0$Packet$setPayloadLength(msg, len);
  hdr = /*CtpP.Forwarder*/CtpForwardingEngineP$0$getHeader(msg);
  __nesc_hton_uint16(hdr->origin.nxdata, TOS_NODE_ID);
  __nesc_hton_uint8(hdr->originSeqNo.nxdata, /*CtpP.Forwarder*/CtpForwardingEngineP$0$seqno[sim_node()]++);
  __nesc_hton_uint8(hdr->type.nxdata, /*CtpP.Forwarder*/CtpForwardingEngineP$0$CollectionId$fetch(client));
  __nesc_hton_uint8(hdr->thl.nxdata, 0);

  if (/*CtpP.Forwarder*/CtpForwardingEngineP$0$clientPtrs[sim_node()][client] == (void *)0) {
      sim_log_debug(199U, "Forwarder", "%s: send failed as client is busy.\n", __FUNCTION__);
      return EBUSY;
    }

  /*CtpP.Forwarder*/CtpForwardingEngineP$0$EerHealth$hlth_generated();
  /*CtpP.Forwarder*/CtpForwardingEngineP$0$EerHealth$get_hlth_generated(& hdr->generated);


  qe = /*CtpP.Forwarder*/CtpForwardingEngineP$0$clientPtrs[sim_node()][client];
  qe->msg = msg;
  qe->client = client;
  qe->retries = MAX_RETRIES;


  qe->eer_fwder = 0xFFFF;
  qe->eer_retxs = 0;
  qe->forcedParentDraw = FALSE;

  sim_log_debug(200U, "Forwarder", "%s: queue entry for %hhu is %hhu deep\n", __FUNCTION__, client, /*CtpP.Forwarder*/CtpForwardingEngineP$0$SendQueue$size());


  if (/*CtpP.Forwarder*/CtpForwardingEngineP$0$SendQueue$enqueue(qe) == SUCCESS) {

      if (/*CtpP.Forwarder*/CtpForwardingEngineP$0$hasState(/*CtpP.Forwarder*/CtpForwardingEngineP$0$RADIO_ON) && !/*CtpP.Forwarder*/CtpForwardingEngineP$0$hasState(/*CtpP.Forwarder*/CtpForwardingEngineP$0$SENDING)) {
          sim_log_debug(201U, "FHangBug", "%s posted sendTask.\n", __FUNCTION__);
          /*CtpP.Forwarder*/CtpForwardingEngineP$0$sendTask$postTask();
        }
      else {
        }


      /*CtpP.Forwarder*/CtpForwardingEngineP$0$clientPtrs[sim_node()][client] = (void *)0;
      return SUCCESS;
    }
  else {
      sim_log_debug(202U, "Forwarder", "%s: send failed as packet could not be enqueued.\n", __FUNCTION__);


      /*CtpP.Forwarder*/CtpForwardingEngineP$0$CollectionDebug$logEvent(NET_C_FE_SEND_QUEUE_FULL);


      /*CtpP.Forwarder*/CtpForwardingEngineP$0$EerInstrumentation$data_queuedrop();


      return FAIL;
    }
}

# 75 "/opt/tinyos-2.1.2/tos/interfaces/Send.nc"
inline static error_t LapTestC$DataSend$send(message_t * msg, uint8_t len){
#line 75
  unsigned char __nesc_result;
#line 75

#line 75
  __nesc_result = /*CtpP.Forwarder*/CtpForwardingEngineP$0$Send$send(0U, msg, len);
#line 75

#line 75
  return __nesc_result;
#line 75
}
#line 75
# 42 "../net/net_EER_sim/eer/CtpInfo.nc"
inline static error_t LapTestC$CtpInfo$getParent(am_addr_t *parent){
#line 42
  unsigned char __nesc_result;
#line 42

#line 42
  __nesc_result = /*CtpP.Router*/EerParentSetEngineP$0$CtpInfo$getParent(parent);
#line 42

#line 42
  return __nesc_result;
#line 42
}
#line 42
# 442 "../net/net_EER_sim/eer/CtpForwardingEngineP.nc"
static inline void */*CtpP.Forwarder*/CtpForwardingEngineP$0$Send$getPayload(uint8_t client, message_t *msg, uint8_t len)
#line 442
{
  return /*CtpP.Forwarder*/CtpForwardingEngineP$0$Packet$getPayload(msg, len);
}

# 125 "/opt/tinyos-2.1.2/tos/interfaces/Send.nc"
inline static void * LapTestC$DataSend$getPayload(message_t * msg, uint8_t len){
#line 125
  void *__nesc_result;
#line 125

#line 125
  __nesc_result = /*CtpP.Forwarder*/CtpForwardingEngineP$0$Send$getPayload(0U, msg, len);
#line 125

#line 125
  return __nesc_result;
#line 125
}
#line 125
# 67 "LapTestC.nc"
static inline void LapTestC$sendDataMessage$runTask(void )
#line 67
{
  data_msg_t *d_msg = (data_msg_t *)LapTestC$DataSend$getPayload(&LapTestC$data_pkt[sim_node()], sizeof(data_msg_t ));

  __nesc_hton_uint16(d_msg->data.nxdata, LapTestC$counter[sim_node()]++);


  if (LapTestC$CtpInfo$getParent(&LapTestC$parent[sim_node()]) != SUCCESS) {
      sim_log_debug(48U, "CtpParent", "CtpParent: get parent fail\n");
    }
  __nesc_hton_uint16(d_msg->parent.nxdata, LapTestC$parent[sim_node()]);
  for (LapTestC$i[sim_node()] = 0; LapTestC$i[sim_node()] < MAX_PATH_LEN; LapTestC$i[sim_node()]++) {
      __nesc_hton_uint16(d_msg->path[LapTestC$i[sim_node()]].nxdata, 0);
    }

  if (LapTestC$DataSend$send(&LapTestC$data_pkt[sim_node()], sizeof(data_msg_t )) != SUCCESS) {
      sim_log_debug(49U, "DataSend", "DataSend: send data packet FAIL(len: %hu)\n", sizeof(data_msg_t ));
    }
  else 
#line 83
    {
      LapTestC$radioBusy[sim_node()] = TRUE;
      sim_log_debug(50U, "DataSend", "DataSend: send data packet (counter: %hu)\n", __nesc_ntoh_uint16(d_msg->data.nxdata));
    }
}

# 64 "/opt/tinyos-2.1.2/tos/lib/timer/Timer.nc"
inline static void LapTestC$DataTimer$startPeriodic(uint32_t dt){
#line 64
  /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$startPeriodic(0U, dt);
#line 64
}
#line 64
# 944 "../net/net_EER_sim/eer/EerParentSetEngineP.nc"
static inline error_t /*CtpP.Router*/EerParentSetEngineP$0$CollectionDebug$default$logEventRoute(uint8_t type, am_addr_t parent, uint8_t hopcount, uint16_t etx)
#line 944
{
  return SUCCESS;
}

# 79 "../net/net_EER_sim/CollectionDebug.nc"
inline static error_t /*CtpP.Router*/EerParentSetEngineP$0$CollectionDebug$logEventRoute(uint8_t type, am_addr_t parent, uint8_t hopcount, uint16_t metric){
#line 79
  unsigned char __nesc_result;
#line 79

#line 79
  __nesc_result = /*CtpP.Router*/EerParentSetEngineP$0$CollectionDebug$default$logEventRoute(type, parent, hopcount, metric);
#line 79

#line 79
  return __nesc_result;
#line 79
}
#line 79
# 328 "../net/net_EER_sim/eer/CtpForwardingEngineP.nc"
static inline void /*CtpP.Forwarder*/CtpForwardingEngineP$0$UnicastNameFreeRouting$routeFound(void )
#line 328
{
  sim_log_debug(197U, "FHangBug", "%s posted sendTask.\n", __FUNCTION__);
  /*CtpP.Forwarder*/CtpForwardingEngineP$0$sendTask$postTask();
}

# 51 "../net/net_EER_sim/UnicastNameFreeRouting.nc"
inline static void /*CtpP.Router*/EerParentSetEngineP$0$Routing$routeFound(void ){
#line 51
  /*CtpP.Forwarder*/CtpForwardingEngineP$0$UnicastNameFreeRouting$routeFound();
#line 51
}
#line 51
# 759 "../net/net_EER_sim/eer/EerParentSetEngineP.nc"
static inline error_t /*CtpP.Router*/EerParentSetEngineP$0$RootControl$setRoot(void )
#line 759
{
  bool route_found = FALSE;

#line 761
  route_found = /*CtpP.Router*/EerParentSetEngineP$0$routeInfo[sim_node()].parent == INVALID_ADDR;
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 762
    {
      /*CtpP.Router*/EerParentSetEngineP$0$state_is_root[sim_node()] = 1;
      /*CtpP.Router*/EerParentSetEngineP$0$routeInfo[sim_node()].parent = /*CtpP.Router*/EerParentSetEngineP$0$my_ll_addr[sim_node()];
      /*CtpP.Router*/EerParentSetEngineP$0$routeInfo[sim_node()].etx = 0;
    }
#line 766
    __nesc_atomic_end(__nesc_atomic); }
  if (route_found) {
    /*CtpP.Router*/EerParentSetEngineP$0$Routing$routeFound();
    }
#line 769
  sim_log_debug(300U, "TreeRouting", "%s I'm a root now!\n", __FUNCTION__);
  /*CtpP.Router*/EerParentSetEngineP$0$CollectionDebug$logEventRoute(NET_C_TREE_NEW_PARENT, /*CtpP.Router*/EerParentSetEngineP$0$routeInfo[sim_node()].parent, 0, /*CtpP.Router*/EerParentSetEngineP$0$routeInfo[sim_node()].etx);
  return SUCCESS;
}

# 41 "../net/net_EER_sim/RootControl.nc"
inline static error_t LapTestC$RootControl$setRoot(void ){
#line 41
  unsigned char __nesc_result;
#line 41

#line 41
  __nesc_result = /*CtpP.Router*/EerParentSetEngineP$0$RootControl$setRoot();
#line 41

#line 41
  return __nesc_result;
#line 41
}
#line 41
# 69 "/opt/tinyos-2.1.2/tos/types/TinyError.h"
static inline  error_t ecombine(error_t r1, error_t r2)




{
  return r1 == r2 ? r1 : FAIL;
}

# 446 "../net/net_EER_sim/4bitle/LinkEstimatorP.nc"
static inline error_t LinkEstimatorP$StdControl$start(void )
#line 446
{
  sim_log_debug(261U, "LI", "Link estimator start\n");
  return SUCCESS;
}

# 64 "/opt/tinyos-2.1.2/tos/lib/timer/Timer.nc"
inline static void /*CtpP.Router*/EerParentSetEngineP$0$RouteTimer$startPeriodic(uint32_t dt){
#line 64
  /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$startPeriodic(2U, dt);
#line 64
}
#line 64
# 235 "../net/net_EER_sim/eer/EerParentSetEngineP.nc"
static inline error_t /*CtpP.Router*/EerParentSetEngineP$0$StdControl$start(void )
#line 235
{

  if (!/*CtpP.Router*/EerParentSetEngineP$0$running[sim_node()]) {
      /*CtpP.Router*/EerParentSetEngineP$0$running[sim_node()] = TRUE;
      /*CtpP.Router*/EerParentSetEngineP$0$resetInterval();
      /*CtpP.Router*/EerParentSetEngineP$0$RouteTimer$startPeriodic(BEACON_INTERVAL);
      sim_log_debug(282U, "TreeRoutingCtl", "%s running: %d radioOn: %d\n", __FUNCTION__, /*CtpP.Router*/EerParentSetEngineP$0$running[sim_node()], /*CtpP.Router*/EerParentSetEngineP$0$radioOn[sim_node()]);
    }
  return SUCCESS;
}

# 1331 "../net/net_EER_sim/eer/CtpForwardingEngineP.nc"
static inline void /*CtpP.Forwarder*/CtpForwardingEngineP$0$setState(uint8_t state)
#line 1331
{
  /*CtpP.Forwarder*/CtpForwardingEngineP$0$forwardingState[sim_node()] = /*CtpP.Forwarder*/CtpForwardingEngineP$0$forwardingState[sim_node()] | state;
}

# 347 "/usr/local/lib/ncc/nesc_nx.h"
static __inline  uint32_t __nesc_hton_uint32(void * target, uint32_t value)
#line 347
{
  uint8_t *base = target;

#line 349
  base[3] = value;
  base[2] = value >> 8;
  base[1] = value >> 16;
  base[0] = value >> 24;
  return value;
}

# 71 "../net/net_EER_sim/eer/EerInstrumentationP.nc"
static inline error_t EerInstrumentationP$EerInstrumentation$init(void )
#line 71
{
  __nesc_hton_uint16(EerInstrumentationP$stats[sim_node()].ctrl_ntxpkt.nxdata, 0);
  __nesc_hton_uint16(EerInstrumentationP$stats[sim_node()].ctrl_nrxpkt.nxdata, 0);
  __nesc_hton_uint16(EerInstrumentationP$stats[sim_node()].ctrl_nparentchange.nxdata, 0);
  __nesc_hton_uint16(EerInstrumentationP$stats[sim_node()].ctrl_ntricklereset.nxdata, 0);

  __nesc_hton_uint16(EerInstrumentationP$stats[sim_node()].data_ntxpkt.nxdata, 0);
  __nesc_hton_uint16(EerInstrumentationP$stats[sim_node()].data_nrxpkt.nxdata, 0);
  __nesc_hton_uint16(EerInstrumentationP$stats[sim_node()].data_nrxacks.nxdata, 0);
  __nesc_hton_uint16(EerInstrumentationP$stats[sim_node()].data_nqueuedrops.nxdata, 0);
  __nesc_hton_uint16(EerInstrumentationP$stats[sim_node()].data_ndups.nxdata, 0);
  __nesc_hton_uint16(EerInstrumentationP$stats[sim_node()].data_ninconsistencies.nxdata, 0);

  __nesc_hton_uint32(EerInstrumentationP$stats[sim_node()].total_time.nxdata, 0);

  return SUCCESS;
}

# 53 "../net/net_EER_sim/eer/EerInstrumentation.nc"
inline static error_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$EerInstrumentation$init(void ){
#line 53
  unsigned char __nesc_result;
#line 53

#line 53
  __nesc_result = EerInstrumentationP$EerInstrumentation$init();
#line 53

#line 53
  return __nesc_result;
#line 53
}
#line 53
# 57 "../net/net_EER_sim/eer/EerHealthP.nc"
static inline error_t EerHealthP$EerHealth$init(void )
#line 57
{
  __nesc_hton_uint16(EerHealthP$hlth[sim_node()].generated.nxdata, 0);
  __nesc_hton_uint16(EerHealthP$hlth[sim_node()].forwarded.nxdata, 0);
  __nesc_hton_uint16(EerHealthP$hlth[sim_node()].total_retx.nxdata, 0);
  __nesc_hton_uint16(EerHealthP$hlth[sim_node()].dropped.nxdata, 0);
  return SUCCESS;
}

# 42 "../net/net_EER_sim/eer/EerHealth.nc"
inline static error_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$EerHealth$init(void ){
#line 42
  unsigned char __nesc_result;
#line 42

#line 42
  __nesc_result = EerHealthP$EerHealth$init();
#line 42

#line 42
  return __nesc_result;
#line 42
}
#line 42
# 284 "../net/net_EER_sim/eer/CtpForwardingEngineP.nc"
static inline error_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$StdControl$start(void )
#line 284
{

  /*CtpP.Forwarder*/CtpForwardingEngineP$0$EerHealth$init();
  /*CtpP.Forwarder*/CtpForwardingEngineP$0$EerInstrumentation$init();

  /*CtpP.Forwarder*/CtpForwardingEngineP$0$setState(/*CtpP.Forwarder*/CtpForwardingEngineP$0$ROUTING_ON);
  return SUCCESS;
}

# 95 "/opt/tinyos-2.1.2/tos/interfaces/StdControl.nc"
inline static error_t LapTestC$CtpControl$start(void ){
#line 95
  unsigned char __nesc_result;
#line 95

#line 95
  __nesc_result = /*CtpP.Forwarder*/CtpForwardingEngineP$0$StdControl$start();
#line 95
  __nesc_result = ecombine(__nesc_result, /*CtpP.Router*/EerParentSetEngineP$0$StdControl$start());
#line 95
  __nesc_result = ecombine(__nesc_result, LinkEstimatorP$StdControl$start());
#line 95

#line 95
  return __nesc_result;
#line 95
}
#line 95
# 104 "/opt/tinyos-2.1.2/tos/interfaces/SplitControl.nc"
inline static error_t LapTestC$RadioControl$start(void ){
#line 104
  unsigned char __nesc_result;
#line 104

#line 104
  __nesc_result = TossimPacketModelC$Control$start();
#line 104

#line 104
  return __nesc_result;
#line 104
}
#line 104
# 44 "LapTestC.nc"
static inline void LapTestC$RadioControl$startDone(error_t err)
#line 44
{
  if (err != SUCCESS) {
    LapTestC$RadioControl$start();
    }
  else 
#line 47
    {

      LapTestC$CtpControl$start();

      if (TOS_NODE_ID == SINK_ADDR) {
          LapTestC$RootControl$setRoot();
          sim_log_debug(47U, "Root", "Root: set root\n");
        }

      LapTestC$DataTimer$startPeriodic((uint32_t )DEF_INTERVAL);
    }
}

# 53 "/opt/tinyos-2.1.2/tos/system/QueueC.nc"
static inline bool /*CtpP.SendQueueP*/QueueC$0$Queue$empty(void )
#line 53
{
  return /*CtpP.SendQueueP*/QueueC$0$size[sim_node()] == 0;
}

# 50 "/opt/tinyos-2.1.2/tos/interfaces/Queue.nc"
inline static bool /*CtpP.Forwarder*/CtpForwardingEngineP$0$SendQueue$empty(void ){
#line 50
  unsigned char __nesc_result;
#line 50

#line 50
  __nesc_result = /*CtpP.SendQueueP*/QueueC$0$Queue$empty();
#line 50

#line 50
  return __nesc_result;
#line 50
}
#line 50
# 305 "../net/net_EER_sim/eer/CtpForwardingEngineP.nc"
static inline void /*CtpP.Forwarder*/CtpForwardingEngineP$0$RadioControl$startDone(error_t err)
#line 305
{
  if (err == SUCCESS) {
      /*CtpP.Forwarder*/CtpForwardingEngineP$0$setState(/*CtpP.Forwarder*/CtpForwardingEngineP$0$RADIO_ON);
      if (!/*CtpP.Forwarder*/CtpForwardingEngineP$0$SendQueue$empty()) {
          sim_log_debug(195U, "FHangBug", "%s posted sendTask.\n", __FUNCTION__);
          /*CtpP.Forwarder*/CtpForwardingEngineP$0$sendTask$postTask();
        }
    }
}

# 222 "/opt/tinyos-2.1.2/tos/chips/atm128/timer/Atm128AlarmAsyncP.nc"
static inline uint32_t /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Alarm$getNow(void )
#line 222
{
  return /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Counter$get();
}

# 109 "/opt/tinyos-2.1.2/tos/lib/timer/Alarm.nc"
inline static /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Alarm$size_type /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Alarm$getNow(void ){
#line 109
  unsigned int __nesc_result;
#line 109

#line 109
  __nesc_result = /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Alarm$getNow();
#line 109

#line 109
  return __nesc_result;
#line 109
}
#line 109
# 96 "/opt/tinyos-2.1.2/tos/lib/timer/AlarmToTimerC.nc"
static inline uint32_t /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Timer$getNow(void )
{
#line 97
  return /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Alarm$getNow();
}

# 136 "/opt/tinyos-2.1.2/tos/lib/timer/Timer.nc"
inline static uint32_t /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$TimerFrom$getNow(void ){
#line 136
  unsigned int __nesc_result;
#line 136

#line 136
  __nesc_result = /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Timer$getNow();
#line 136

#line 136
  return __nesc_result;
#line 136
}
#line 136
# 159 "/opt/tinyos-2.1.2/tos/lib/timer/VirtualizeTimerC.nc"
static inline void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$startOneShot(uint8_t num, uint32_t dt)
{
  /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$startTimer(num, /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$TimerFrom$getNow(), dt, TRUE);
}

# 73 "/opt/tinyos-2.1.2/tos/lib/timer/Timer.nc"
inline static void /*CtpP.Router*/EerParentSetEngineP$0$BeaconTimer$startOneShot(uint32_t dt){
#line 73
  /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$startOneShot(1U, dt);
#line 73
}
#line 73
# 52 "/opt/tinyos-2.1.2/tos/interfaces/Random.nc"
inline static uint16_t /*CtpP.Router*/EerParentSetEngineP$0$Random$rand16(void ){
#line 52
  unsigned short __nesc_result;
#line 52

#line 52
  __nesc_result = RandomMlcgC$Random$rand16();
#line 52

#line 52
  return __nesc_result;
#line 52
}
#line 52
# 252 "../net/net_EER_sim/eer/EerParentSetEngineP.nc"
static inline void /*CtpP.Router*/EerParentSetEngineP$0$RadioControl$startDone(error_t error)
#line 252
{
  /*CtpP.Router*/EerParentSetEngineP$0$radioOn[sim_node()] = TRUE;
  sim_log_debug(284U, "TreeRoutingCtl", "%s running: %d radioOn: %d\n", __FUNCTION__, /*CtpP.Router*/EerParentSetEngineP$0$running[sim_node()], /*CtpP.Router*/EerParentSetEngineP$0$radioOn[sim_node()]);
  if (/*CtpP.Router*/EerParentSetEngineP$0$running[sim_node()]) {
      uint16_t nextInt;

#line 257
      nextInt = /*CtpP.Router*/EerParentSetEngineP$0$Random$rand16() % BEACON_INTERVAL;
      nextInt += BEACON_INTERVAL >> 1;
      /*CtpP.Router*/EerParentSetEngineP$0$BeaconTimer$startOneShot(nextInt);
    }
}

# 113 "/opt/tinyos-2.1.2/tos/interfaces/SplitControl.nc"
inline static void TossimPacketModelC$Control$startDone(error_t error){
#line 113
  /*CtpP.Router*/EerParentSetEngineP$0$RadioControl$startDone(error);
#line 113
  /*CtpP.Forwarder*/CtpForwardingEngineP$0$RadioControl$startDone(error);
#line 113
  LapTestC$RadioControl$startDone(error);
#line 113
}
#line 113
# 96 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimPacketModelC.nc"
static inline void TossimPacketModelC$startDoneTask$runTask(void )
#line 96
{
  TossimPacketModelC$running[sim_node()] = TRUE;
  TossimPacketModelC$Control$startDone(SUCCESS);
}

# 169 "LapTestC.nc"
static inline void LapTestC$RadioControl$stopDone(error_t err)
#line 169
{
}

# 1325 "../net/net_EER_sim/eer/CtpForwardingEngineP.nc"
static inline void /*CtpP.Forwarder*/CtpForwardingEngineP$0$clearState(uint8_t state)
#line 1325
{
  /*CtpP.Forwarder*/CtpForwardingEngineP$0$forwardingState[sim_node()] = /*CtpP.Forwarder*/CtpForwardingEngineP$0$forwardingState[sim_node()] & ~state;
}

#line 339
static inline void /*CtpP.Forwarder*/CtpForwardingEngineP$0$RadioControl$stopDone(error_t err)
#line 339
{
  if (err == SUCCESS) {
      /*CtpP.Forwarder*/CtpForwardingEngineP$0$clearState(/*CtpP.Forwarder*/CtpForwardingEngineP$0$RADIO_ON);
    }
}

# 263 "../net/net_EER_sim/eer/EerParentSetEngineP.nc"
static inline void /*CtpP.Router*/EerParentSetEngineP$0$RadioControl$stopDone(error_t error)
#line 263
{
  /*CtpP.Router*/EerParentSetEngineP$0$radioOn[sim_node()] = FALSE;
  sim_log_debug(285U, "TreeRoutingCtl", "%s running: %d radioOn: %d\n", __FUNCTION__, /*CtpP.Router*/EerParentSetEngineP$0$running[sim_node()], /*CtpP.Router*/EerParentSetEngineP$0$radioOn[sim_node()]);
}

# 138 "/opt/tinyos-2.1.2/tos/interfaces/SplitControl.nc"
inline static void TossimPacketModelC$Control$stopDone(error_t error){
#line 138
  /*CtpP.Router*/EerParentSetEngineP$0$RadioControl$stopDone(error);
#line 138
  /*CtpP.Forwarder*/CtpForwardingEngineP$0$RadioControl$stopDone(error);
#line 138
  LapTestC$RadioControl$stopDone(error);
#line 138
}
#line 138
# 101 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimPacketModelC.nc"
static inline void TossimPacketModelC$stopDoneTask$runTask(void )
#line 101
{
  TossimPacketModelC$running[sim_node()] = FALSE;
  TossimPacketModelC$Control$stopDone(SUCCESS);
}

# 303 "/usr/local/lib/ncc/nesc_nx.h"
static __inline  int8_t __nesc_hton_int8(void * target, int8_t value)
#line 303
{
#line 303
  __nesc_hton_uint8(target, value);
#line 303
  return value;
}

# 110 "/opt/tinyos-2.1.2/tos/interfaces/AMSend.nc"
inline static void TossimActiveMessageC$AMSend$sendDone(am_id_t arg_0x408eb4b0, message_t * msg, error_t error){
#line 110
  /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$AMSend$sendDone(arg_0x408eb4b0, msg, error);
#line 110
}
#line 110
# 103 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimActiveMessageC.nc"
static inline void TossimActiveMessageC$Model$sendDone(message_t *msg, error_t result)
#line 103
{
  TossimActiveMessageC$AMSend$sendDone(TossimActiveMessageC$AMPacket$type(msg), msg, result);
}

# 76 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimPacketModel.nc"
inline static void TossimPacketModelC$Packet$sendDone(message_t *msg, error_t error){
#line 76
  TossimActiveMessageC$Model$sendDone(msg, error);
#line 76
}
#line 76
# 82 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimPacketModelC.nc"
static inline tossim_metadata_t *TossimPacketModelC$getMetadata(message_t *msg)
#line 82
{
  return (tossim_metadata_t *)& msg->metadata;
}

#line 145
static inline void TossimPacketModelC$sendDoneTask$runTask(void )
#line 145
{
  message_t *msg = TossimPacketModelC$sending[sim_node()];
  tossim_metadata_t *meta = TossimPacketModelC$getMetadata(msg);

#line 148
  __nesc_hton_uint8(meta->ack.nxdata, 0);
  __nesc_hton_int8(meta->strength.nxdata, 0);
  __nesc_hton_uint16(meta->time.nxdata, 0);
  TossimPacketModelC$sending[sim_node()] = FALSE;
  TossimPacketModelC$Packet$sendDone(msg, TossimPacketModelC$running[sim_node()] ? SUCCESS : EOFF);
}

# 139 "/opt/tinyos-2.1.2/tos/lib/timer/VirtualizeTimerC.nc"
static inline void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$TimerFrom$fired(void )
{
  /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$fireTimers(/*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$TimerFrom$getNow());
}

# 83 "/opt/tinyos-2.1.2/tos/lib/timer/Timer.nc"
inline static void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Timer$fired(void ){
#line 83
  /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$TimerFrom$fired();
#line 83
}
#line 83
# 226 "/opt/tinyos-2.1.2/tos/chips/atm128/timer/Atm128AlarmAsyncP.nc"
static inline uint32_t /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Alarm$getAlarm(void )
#line 226
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 227
    {
      unsigned int __nesc_temp = 
#line 227
      /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$t0[sim_node()] + /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$dt[sim_node()];

      {
#line 227
        __nesc_atomic_end(__nesc_atomic); 
#line 227
        return __nesc_temp;
      }
    }
#line 229
    __nesc_atomic_end(__nesc_atomic); }
}

# 116 "/opt/tinyos-2.1.2/tos/lib/timer/Alarm.nc"
inline static /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Alarm$size_type /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Alarm$getAlarm(void ){
#line 116
  unsigned int __nesc_result;
#line 116

#line 116
  __nesc_result = /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Alarm$getAlarm();
#line 116

#line 116
  return __nesc_result;
#line 116
}
#line 116
#line 103
inline static void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Alarm$startAt(/*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Alarm$size_type t0, /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Alarm$size_type dt){
#line 103
  /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Alarm$startAt(t0, dt);
#line 103
}
#line 103
# 58 "/opt/tinyos-2.1.2/tos/lib/timer/AlarmToTimerC.nc"
static inline void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$start(uint32_t t0, uint32_t dt, bool oneshot)
{
  /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$m_dt[sim_node()] = dt;
  /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$m_oneshot[sim_node()] = oneshot;
  /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Alarm$startAt(t0, dt);
}










static inline void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$fired$runTask(void )
{
  if (/*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$m_oneshot[sim_node()] == FALSE) {
    /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$start(/*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Alarm$getAlarm(), /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$m_dt[sim_node()], FALSE);
    }
#line 78
  /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Timer$fired();
}

#line 93
static inline void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Timer$startOneShotAt(uint32_t t0, uint32_t dt)
{
#line 94
  /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$start(t0, dt, TRUE);
}

# 129 "/opt/tinyos-2.1.2/tos/lib/timer/Timer.nc"
inline static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$TimerFrom$startOneShotAt(uint32_t t0, uint32_t dt){
#line 129
  /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Timer$startOneShotAt(t0, dt);
#line 129
}
#line 129
# 204 "/opt/tinyos-2.1.2/tos/chips/atm128/timer/Atm128AlarmAsyncP.nc"
static inline void /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Alarm$stop(void )
#line 204
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 205
    /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$set[sim_node()] = FALSE;
#line 205
    __nesc_atomic_end(__nesc_atomic); }
}

# 73 "/opt/tinyos-2.1.2/tos/lib/timer/Alarm.nc"
inline static void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Alarm$stop(void ){
#line 73
  /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Alarm$stop();
#line 73
}
#line 73
# 71 "/opt/tinyos-2.1.2/tos/lib/timer/AlarmToTimerC.nc"
static inline void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Timer$stop(void )
{
#line 72
  /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Alarm$stop();
}

# 78 "/opt/tinyos-2.1.2/tos/lib/timer/Timer.nc"
inline static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$TimerFrom$stop(void ){
#line 78
  /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Timer$stop();
#line 78
}
#line 78
# 100 "/opt/tinyos-2.1.2/tos/lib/timer/VirtualizeTimerC.nc"
static inline void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$updateFromTimer$runTask(void )
{




  uint32_t now = /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$TimerFrom$getNow();
  int32_t min_remaining = (1UL << 31) - 1;
  bool min_remaining_isset = FALSE;
  uint16_t num;

  /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$TimerFrom$stop();

  for (num = 0; num < /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$NUM_TIMERS; num++) 
    {
      /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer_t *timer = &/*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$m_timers[sim_node()][num];

      if (timer->isrunning) 
        {
          uint32_t elapsed = now - timer->t0;
          int32_t remaining = timer->dt - elapsed;

          if (remaining < min_remaining) 
            {
              min_remaining = remaining;
              min_remaining_isset = TRUE;
            }
        }
    }

  if (min_remaining_isset) 
    {
      if (min_remaining <= 0) {
        /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$fireTimers(now);
        }
      else {
#line 135
        /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$TimerFrom$startOneShotAt(now, min_remaining);
        }
    }
}

# 75 "/opt/tinyos-2.1.2/tos/interfaces/Send.nc"
inline static error_t /*CtpP.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$0$Send$send(message_t * msg, uint8_t len){
#line 75
  unsigned char __nesc_result;
#line 75

#line 75
  __nesc_result = /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Send$send(0U, msg, len);
#line 75

#line 75
  return __nesc_result;
#line 75
}
#line 75
# 162 "/opt/tinyos-2.1.2/tos/interfaces/AMPacket.nc"
inline static void /*CtpP.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$0$AMPacket$setType(message_t * amsg, am_id_t t){
#line 162
  TossimActiveMessageC$AMPacket$setType(amsg, t);
#line 162
}
#line 162
#line 103
inline static void /*CtpP.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$0$AMPacket$setDestination(message_t * amsg, am_addr_t addr){
#line 103
  TossimActiveMessageC$AMPacket$setDestination(amsg, addr);
#line 103
}
#line 103
# 53 "/opt/tinyos-2.1.2/tos/system/AMQueueEntryP.nc"
static inline error_t /*CtpP.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$0$AMSend$send(am_addr_t dest, 
message_t *msg, 
uint8_t len)
#line 55
{
  /*CtpP.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$0$AMPacket$setDestination(msg, dest);
  /*CtpP.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$0$AMPacket$setType(msg, 113);
  return /*CtpP.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$0$Send$send(msg, len);
}

# 80 "/opt/tinyos-2.1.2/tos/interfaces/AMSend.nc"
inline static error_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$SubSend$send(am_addr_t addr, message_t * msg, uint8_t len){
#line 80
  unsigned char __nesc_result;
#line 80

#line 80
  __nesc_result = /*CtpP.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$0$AMSend$send(addr, msg, len);
#line 80

#line 80
  return __nesc_result;
#line 80
}
#line 80
# 1301 "../net/net_EER_sim/eer/CtpForwardingEngineP.nc"
static inline void /*CtpP.Forwarder*/CtpForwardingEngineP$0$CtpPacket$setOption(message_t *msg, ctp_options_t opt)
#line 1301
{
  unsigned char *__nesc_temp42;

#line 1302
  (__nesc_temp42 = /*CtpP.Forwarder*/CtpForwardingEngineP$0$getHeader(msg)->options.nxdata, __nesc_hton_uint8(__nesc_temp42, __nesc_ntoh_uint8(__nesc_temp42) | opt));
}

# 128 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimPacketModelC.nc"
static inline error_t TossimPacketModelC$PacketAcknowledgements$requestAck(message_t *msg)
#line 128
{
  tossim_metadata_t *meta = TossimPacketModelC$getMetadata(msg);

#line 130
  __nesc_hton_uint8(meta->ack.nxdata, TRUE);
  return SUCCESS;
}

# 59 "/opt/tinyos-2.1.2/tos/interfaces/PacketAcknowledgements.nc"
inline static error_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$PacketAcknowledgements$requestAck(message_t * msg){
#line 59
  unsigned char __nesc_result;
#line 59

#line 59
  __nesc_result = TossimPacketModelC$PacketAcknowledgements$requestAck(msg);
#line 59

#line 59
  return __nesc_result;
#line 59
}
#line 59
# 1304 "../net/net_EER_sim/eer/CtpForwardingEngineP.nc"
static inline void /*CtpP.Forwarder*/CtpForwardingEngineP$0$CtpPacket$clearOption(message_t *msg, ctp_options_t opt)
#line 1304
{
  unsigned char *__nesc_temp43;

#line 1305
  (__nesc_temp43 = /*CtpP.Forwarder*/CtpForwardingEngineP$0$getHeader(msg)->options.nxdata, __nesc_hton_uint8(__nesc_temp43, __nesc_ntoh_uint8(__nesc_temp43) & ~opt));
}

#line 1296
static inline void /*CtpP.Forwarder*/CtpForwardingEngineP$0$CtpPacket$setEtx(message_t *msg, uint16_t e)
#line 1296
{
#line 1296
  __nesc_hton_uint16(/*CtpP.Forwarder*/CtpForwardingEngineP$0$getHeader(msg)->etx.nxdata, e);
}

# 42 "../net/net_EER_sim/eer/CtpInfo.nc"
inline static error_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$CtpInfo$getParent(am_addr_t *parent){
#line 42
  unsigned char __nesc_result;
#line 42

#line 42
  __nesc_result = /*CtpP.Router*/EerParentSetEngineP$0$CtpInfo$getParent(parent);
#line 42

#line 42
  return __nesc_result;
#line 42
}
#line 42
# 197 "../net/net_EER_sim/eer_parentselection/EerParentSelectionP.nc"
static inline __nesc_nxbase_nx_uint8_t /*CtpP.ParentSelector*/EerParentSelectionP$0$EerParentSelectionHealth$getCandiateSetSize(void )
#line 197
{
  return __nesc_ntoh_uint8(/*CtpP.ParentSelector*/EerParentSelectionP$0$prntSet[sim_node()].setSize.nxdata);
}

# 41 "../net/net_EER_sim/eer_parentselection/EerParentSelectionHealth.nc"
inline static __nesc_nxbase_nx_uint8_t EerHealthP$EerParentSelectionHealth$getCandiateSetSize(void ){
#line 41
  unsigned char __nesc_result;
#line 41

#line 41
  __nesc_result = /*CtpP.ParentSelector*/EerParentSelectionP$0$EerParentSelectionHealth$getCandiateSetSize();
#line 41

#line 41
  return __nesc_result;
#line 41
}
#line 41
# 107 "../net/net_EER_sim/eer/EerHealthP.nc"
static inline error_t EerHealthP$EerHealth$get_hlth_psetSize(nx_uint8_t *psetSize)
#line 107
{
  __nesc_hton_uint8((*psetSize).nxdata, EerHealthP$EerParentSelectionHealth$getCandiateSetSize());
  return SUCCESS;
}

# 56 "../net/net_EER_sim/eer/EerHealth.nc"
inline static error_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$EerHealth$get_hlth_psetSize(nx_uint8_t *psetSize){
#line 56
  unsigned char __nesc_result;
#line 56

#line 56
  __nesc_result = EerHealthP$EerHealth$get_hlth_psetSize(psetSize);
#line 56

#line 56
  return __nesc_result;
#line 56
}
#line 56
# 100 "../net/net_EER_sim/eer/EerHealthP.nc"
static inline error_t EerHealthP$EerHealth$get_hlth_dropped(nx_uint16_t *drp)
#line 100
{
  __nesc_hton_uint16((*drp).nxdata, __nesc_ntoh_uint16(EerHealthP$hlth[sim_node()].dropped.nxdata));
  return SUCCESS;
}

# 54 "../net/net_EER_sim/eer/EerHealth.nc"
inline static error_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$EerHealth$get_hlth_dropped(nx_uint16_t *drp){
#line 54
  unsigned char __nesc_result;
#line 54

#line 54
  __nesc_result = EerHealthP$EerHealth$get_hlth_dropped(drp);
#line 54

#line 54
  return __nesc_result;
#line 54
}
#line 54
# 90 "../net/net_EER_sim/eer/EerHealthP.nc"
static inline error_t EerHealthP$EerHealth$get_hlth_retx(nx_uint16_t *retx)
#line 90
{
  __nesc_hton_uint16((*retx).nxdata, __nesc_ntoh_uint16(EerHealthP$hlth[sim_node()].total_retx.nxdata));
  return SUCCESS;
}

# 51 "../net/net_EER_sim/eer/EerHealth.nc"
inline static error_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$EerHealth$get_hlth_retx(nx_uint16_t *retx){
#line 51
  unsigned char __nesc_result;
#line 51

#line 51
  __nesc_result = EerHealthP$EerHealth$get_hlth_retx(retx);
#line 51

#line 51
  return __nesc_result;
#line 51
}
#line 51
# 80 "../net/net_EER_sim/eer/EerHealthP.nc"
static inline error_t EerHealthP$EerHealth$get_hlth_forwarded(nx_uint16_t *fwd)
#line 80
{
  __nesc_hton_uint16((*fwd).nxdata, __nesc_ntoh_uint16(EerHealthP$hlth[sim_node()].forwarded.nxdata));
  return SUCCESS;
}

# 48 "../net/net_EER_sim/eer/EerHealth.nc"
inline static error_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$EerHealth$get_hlth_forwarded(nx_uint16_t *fwd){
#line 48
  unsigned char __nesc_result;
#line 48

#line 48
  __nesc_result = EerHealthP$EerHealth$get_hlth_forwarded(fwd);
#line 48

#line 48
  return __nesc_result;
#line 48
}
#line 48
# 993 "../net/net_EER_sim/eer/EerParentSetEngineP.nc"
static inline uint16_t /*CtpP.Router*/EerParentSetEngineP$0$CtpInfo$getNeighborEtx(am_addr_t n)
#line 993
{
  uint8_t i = /*CtpP.Router*/EerParentSetEngineP$0$routingTableFind(n);

#line 995
  if (i < /*CtpP.Router*/EerParentSetEngineP$0$routingTableActive[sim_node()]) {
      return (&/*CtpP.Router*/EerParentSetEngineP$0$routingTable[sim_node()][i])->info.etx;
    }
  else {
      return MAX_METRIC;
    }
}

# 91 "../net/net_EER_sim/eer/CtpInfo.nc"
inline static uint16_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$CtpInfo$getNeighborEtx(am_addr_t n){
#line 91
  unsigned short __nesc_result;
#line 91

#line 91
  __nesc_result = /*CtpP.Router*/EerParentSetEngineP$0$CtpInfo$getNeighborEtx(n);
#line 91

#line 91
  return __nesc_result;
#line 91
}
#line 91
# 49 "../net/net_EER_sim/4bitle/LinkEstimator.nc"
inline static uint16_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$LinkEstimator$getLinkQuality(uint16_t neighbor){
#line 49
  unsigned short __nesc_result;
#line 49

#line 49
  __nesc_result = LinkEstimatorP$LinkEstimator$getLinkQuality(neighbor);
#line 49

#line 49
  return __nesc_result;
#line 49
}
#line 49
# 52 "/opt/tinyos-2.1.2/tos/interfaces/Random.nc"
inline static uint16_t /*CtpP.ParentSelector*/EerParentSelectionP$0$Random$rand16(void ){
#line 52
  unsigned short __nesc_result;
#line 52

#line 52
  __nesc_result = RandomMlcgC$Random$rand16();
#line 52

#line 52
  return __nesc_result;
#line 52
}
#line 52
# 136 "../net/net_EER_sim/eer_parentselection/EerParentSelectionP.nc"
static inline am_addr_t /*CtpP.ParentSelector*/EerParentSelectionP$0$EerParentSelectionConfig$drawRandomParent(void )
#line 136
{

  uint16_t rnd;


  if (__nesc_ntoh_uint8(/*CtpP.ParentSelector*/EerParentSelectionP$0$prntSet[sim_node()].setSize.nxdata) == 0) {
      return INVALID_ADDR;
    }

  rnd = /*CtpP.ParentSelector*/EerParentSelectionP$0$Random$rand16();
  rnd = rnd % __nesc_ntoh_uint8(/*CtpP.ParentSelector*/EerParentSelectionP$0$prntSet[sim_node()].setSize.nxdata);

  /*CtpP.ParentSelector*/EerParentSelectionP$0$rand_prnt[sim_node()] = /*CtpP.ParentSelector*/EerParentSelectionP$0$parentSetTable[sim_node()][rnd];

  if (__nesc_ntoh_uint8(/*CtpP.ParentSelector*/EerParentSelectionP$0$prntSet[sim_node()].setSize.nxdata) == 1) {
      __nesc_hton_uint16(/*CtpP.ParentSelector*/EerParentSelectionP$0$prntSet[sim_node()].previousFwder.nxdata, INVALID_ADDR);
      return /*CtpP.ParentSelector*/EerParentSelectionP$0$rand_prnt[sim_node()];
    }
  else {
      if (__nesc_ntoh_uint16(/*CtpP.ParentSelector*/EerParentSelectionP$0$prntSet[sim_node()].previousFwder.nxdata) == INVALID_ADDR) {

          __nesc_hton_uint16(/*CtpP.ParentSelector*/EerParentSelectionP$0$prntSet[sim_node()].previousFwder.nxdata, /*CtpP.ParentSelector*/EerParentSelectionP$0$rand_prnt[sim_node()]);
          return /*CtpP.ParentSelector*/EerParentSelectionP$0$rand_prnt[sim_node()];
        }
      else {
          while (__nesc_ntoh_uint16(/*CtpP.ParentSelector*/EerParentSelectionP$0$prntSet[sim_node()].previousFwder.nxdata) == /*CtpP.ParentSelector*/EerParentSelectionP$0$rand_prnt[sim_node()]) {

              rnd = /*CtpP.ParentSelector*/EerParentSelectionP$0$Random$rand16();
              rnd = rnd % __nesc_ntoh_uint8(/*CtpP.ParentSelector*/EerParentSelectionP$0$prntSet[sim_node()].setSize.nxdata);
              /*CtpP.ParentSelector*/EerParentSelectionP$0$rand_prnt[sim_node()] = /*CtpP.ParentSelector*/EerParentSelectionP$0$parentSetTable[sim_node()][rnd];
            }

          __nesc_hton_uint16(/*CtpP.ParentSelector*/EerParentSelectionP$0$prntSet[sim_node()].previousFwder.nxdata, /*CtpP.ParentSelector*/EerParentSelectionP$0$rand_prnt[sim_node()]);
          return /*CtpP.ParentSelector*/EerParentSelectionP$0$rand_prnt[sim_node()];
        }
    }
}

# 45 "../net/net_EER_sim/eer_parentselection/EerParentSelectionConfig.nc"
inline static am_addr_t /*CtpP.Router*/EerParentSetEngineP$0$EerParentSelectionConfig$drawRandomParent(void ){
#line 45
  unsigned short __nesc_result;
#line 45

#line 45
  __nesc_result = /*CtpP.ParentSelector*/EerParentSelectionP$0$EerParentSelectionConfig$drawRandomParent();
#line 45

#line 45
  return __nesc_result;
#line 45
}
#line 45
# 192 "../net/net_EER_sim/eer_parentselection/EerParentSelectionP.nc"
static inline __nesc_nxbase_nx_uint8_t /*CtpP.ParentSelector*/EerParentSelectionP$0$EerParentSelectionConfig$getParentSetSize(void )
#line 192
{
  return __nesc_ntoh_uint8(/*CtpP.ParentSelector*/EerParentSelectionP$0$prntSet[sim_node()].setSize.nxdata);
}

# 49 "../net/net_EER_sim/eer_parentselection/EerParentSelectionConfig.nc"
inline static __nesc_nxbase_nx_uint8_t /*CtpP.Router*/EerParentSetEngineP$0$EerParentSelectionConfig$getParentSetSize(void ){
#line 49
  unsigned char __nesc_result;
#line 49

#line 49
  __nesc_result = /*CtpP.ParentSelector*/EerParentSelectionP$0$EerParentSelectionConfig$getParentSetSize();
#line 49

#line 49
  return __nesc_result;
#line 49
}
#line 49
# 680 "../net/net_EER_sim/eer/EerParentSetEngineP.nc"
static inline am_addr_t /*CtpP.Router*/EerParentSetEngineP$0$Routing$nextHop(void )
#line 680
{

  if (/*CtpP.Router*/EerParentSetEngineP$0$EerParentSelectionConfig$getParentSetSize() == 0) {
      return /*CtpP.Router*/EerParentSetEngineP$0$routeInfo[sim_node()].parent;
    }
  else {
      return /*CtpP.Router*/EerParentSetEngineP$0$EerParentSelectionConfig$drawRandomParent();
    }
}

# 48 "../net/net_EER_sim/UnicastNameFreeRouting.nc"
inline static am_addr_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$UnicastNameFreeRouting$nextHop(void ){
#line 48
  unsigned short __nesc_result;
#line 48

#line 48
  __nesc_result = /*CtpP.Router*/EerParentSetEngineP$0$Routing$nextHop();
#line 48

#line 48
  return __nesc_result;
#line 48
}
#line 48
# 81 "/opt/tinyos-2.1.2/tos/interfaces/Queue.nc"
inline static /*CtpP.Forwarder*/CtpForwardingEngineP$0$SendQueue$t  /*CtpP.Forwarder*/CtpForwardingEngineP$0$SendQueue$dequeue(void ){
#line 81
  struct __nesc_unnamed4337 *__nesc_result;
#line 81

#line 81
  __nesc_result = /*CtpP.SendQueueP*/QueueC$0$Queue$dequeue();
#line 81

#line 81
  return __nesc_result;
#line 81
}
#line 81
# 65 "/opt/tinyos-2.1.2/tos/system/QueueC.nc"
static inline /*CtpP.SendQueueP*/QueueC$0$queue_t /*CtpP.SendQueueP*/QueueC$0$Queue$head(void )
#line 65
{
  return /*CtpP.SendQueueP*/QueueC$0$queue[sim_node()][/*CtpP.SendQueueP*/QueueC$0$head[sim_node()]];
}

# 73 "/opt/tinyos-2.1.2/tos/interfaces/Queue.nc"
inline static /*CtpP.Forwarder*/CtpForwardingEngineP$0$SendQueue$t  /*CtpP.Forwarder*/CtpForwardingEngineP$0$SendQueue$head(void ){
#line 73
  struct __nesc_unnamed4337 *__nesc_result;
#line 73

#line 73
  __nesc_result = /*CtpP.SendQueueP*/QueueC$0$Queue$head();
#line 73

#line 73
  return __nesc_result;
#line 73
}
#line 73
# 689 "../net/net_EER_sim/eer/EerParentSetEngineP.nc"
static inline bool /*CtpP.Router*/EerParentSetEngineP$0$Routing$hasRoute(void )
#line 689
{
  return /*CtpP.Router*/EerParentSetEngineP$0$routeInfo[sim_node()].parent != INVALID_ADDR;
}

# 49 "../net/net_EER_sim/UnicastNameFreeRouting.nc"
inline static bool /*CtpP.Forwarder*/CtpForwardingEngineP$0$UnicastNameFreeRouting$hasRoute(void ){
#line 49
  unsigned char __nesc_result;
#line 49

#line 49
  __nesc_result = /*CtpP.Router*/EerParentSetEngineP$0$Routing$hasRoute();
#line 49

#line 49
  return __nesc_result;
#line 49
}
#line 49
# 464 "../net/net_EER_sim/eer/CtpForwardingEngineP.nc"
static inline void /*CtpP.Forwarder*/CtpForwardingEngineP$0$sendTask$runTask(void )
#line 464
{
  uint16_t gradient;

#line 466
  sim_log_debug(203U, "Forwarder", "%s: Trying to send a packet. Queue size is %hhu.\n", __FUNCTION__, /*CtpP.Forwarder*/CtpForwardingEngineP$0$SendQueue$size());


  if (/*CtpP.Forwarder*/CtpForwardingEngineP$0$hasState(/*CtpP.Forwarder*/CtpForwardingEngineP$0$SENDING) || /*CtpP.Forwarder*/CtpForwardingEngineP$0$SendQueue$empty()) {
      /*CtpP.Forwarder*/CtpForwardingEngineP$0$CollectionDebug$logEvent(NET_C_FE_SENDQUEUE_EMPTY);
      return;
    }
  else {
    if ((
#line 473
    !/*CtpP.Forwarder*/CtpForwardingEngineP$0$RootControl$isRoot() && 
    !/*CtpP.Forwarder*/CtpForwardingEngineP$0$UnicastNameFreeRouting$hasRoute()) || 
    /*CtpP.Forwarder*/CtpForwardingEngineP$0$CtpInfo$getEtx(&gradient) != SUCCESS) {








        sim_log_debug(204U, "Forwarder", "%s: no route, don't send, try again in %i.\n", __FUNCTION__, NO_ROUTE_RETRY);


        /*CtpP.Forwarder*/CtpForwardingEngineP$0$RetxmitTimer$startOneShot(NO_ROUTE_RETRY);
        /*CtpP.Forwarder*/CtpForwardingEngineP$0$CollectionDebug$logEvent(NET_C_FE_NO_ROUTE);
        return;
      }
    else {



        error_t subsendResult;
        fe_queue_entry_t *qe = /*CtpP.Forwarder*/CtpForwardingEngineP$0$SendQueue$head();
        uint8_t payloadLen = /*CtpP.Forwarder*/CtpForwardingEngineP$0$SubPacket$payloadLength(qe->msg);


        am_addr_t dest;


        if (/*CtpP.Forwarder*/CtpForwardingEngineP$0$SentCache$lookup(qe->msg)) {




            /*CtpP.Forwarder*/CtpForwardingEngineP$0$CollectionDebug$logEvent(NET_C_FE_DUPLICATE_CACHE_AT_SEND);


            /*CtpP.Forwarder*/CtpForwardingEngineP$0$EerInstrumentation$data_pktdup();

            /*CtpP.Forwarder*/CtpForwardingEngineP$0$SendQueue$dequeue();
            if (/*CtpP.Forwarder*/CtpForwardingEngineP$0$MessagePool$put(qe->msg) != SUCCESS) {
              /*CtpP.Forwarder*/CtpForwardingEngineP$0$CollectionDebug$logEvent(NET_C_FE_PUT_MSGPOOL_ERR);
              }
#line 516
            if (/*CtpP.Forwarder*/CtpForwardingEngineP$0$QEntryPool$put(qe) != SUCCESS) {
              /*CtpP.Forwarder*/CtpForwardingEngineP$0$CollectionDebug$logEvent(NET_C_FE_PUT_QEPOOL_ERR);
              }
            /*CtpP.Forwarder*/CtpForwardingEngineP$0$sendTask$postTask();
            return;
          }







        if (((qe->eer_retxs == 0 || qe->eer_fwder == 0xFFFF) || qe->forcedParentDraw) || qe->eer_retxs >= MAX_RETRIES / 2) {
            qe->eer_fwder = /*CtpP.Forwarder*/CtpForwardingEngineP$0$UnicastNameFreeRouting$nextHop();
            qe->eer_retxs = 0;
            qe->forcedParentDraw = FALSE;
          }
        dest = qe->eer_fwder;



        sim_log_debug(205U, "Forwarder", "Sending queue entry %p\n", qe);



        {
          ctp_data_header_t *datahdr = /*CtpP.Forwarder*/CtpForwardingEngineP$0$getHeader(qe->msg);
          am_addr_t eer_parent_temp = 0xFFFF;

#line 545
          if (__nesc_ntoh_uint8(datahdr->thl.nxdata) == 0) {
              __nesc_hton_uint16(datahdr->stats_nexthop.nxdata, dest);



              __nesc_hton_uint16(datahdr->stats_letx.nxdata, /*CtpP.Forwarder*/CtpForwardingEngineP$0$LinkEstimator$getLinkQuality(dest));
              __nesc_hton_uint16(datahdr->stats_petx.nxdata, /*CtpP.Forwarder*/CtpForwardingEngineP$0$CtpInfo$getNeighborEtx(dest) + __nesc_ntoh_uint16(datahdr->stats_letx.nxdata));




              /*CtpP.Forwarder*/CtpForwardingEngineP$0$EerHealth$get_hlth_forwarded(& datahdr->forwarded);
              /*CtpP.Forwarder*/CtpForwardingEngineP$0$EerHealth$get_hlth_retx(& datahdr->retx);
              /*CtpP.Forwarder*/CtpForwardingEngineP$0$EerHealth$get_hlth_dropped(& datahdr->dropped);



              /*CtpP.Forwarder*/CtpForwardingEngineP$0$EerHealth$get_hlth_psetSize(& datahdr->psetSize);


              /*CtpP.Forwarder*/CtpForwardingEngineP$0$CtpInfo$getParent(&eer_parent_temp);
              __nesc_hton_uint16(datahdr->eer_parent.nxdata, eer_parent_temp);


              __nesc_hton_uint8(datahdr->reTxs.nxdata, qe->eer_retxs);
            }
        }




        if (/*CtpP.Forwarder*/CtpForwardingEngineP$0$RootControl$isRoot()) {

            collection_id_t collectid = __nesc_ntoh_uint8(/*CtpP.Forwarder*/CtpForwardingEngineP$0$getHeader(qe->msg)->type.nxdata);
            uint8_t *payload;
            uint8_t payloadLength;

            memcpy(/*CtpP.Forwarder*/CtpForwardingEngineP$0$loopbackMsgPtr[sim_node()], qe->msg, sizeof(message_t ));

            payload = /*CtpP.Forwarder*/CtpForwardingEngineP$0$Packet$getPayload(/*CtpP.Forwarder*/CtpForwardingEngineP$0$loopbackMsgPtr[sim_node()], /*CtpP.Forwarder*/CtpForwardingEngineP$0$Packet$payloadLength(/*CtpP.Forwarder*/CtpForwardingEngineP$0$loopbackMsgPtr[sim_node()]));
            payloadLength = /*CtpP.Forwarder*/CtpForwardingEngineP$0$Packet$payloadLength(/*CtpP.Forwarder*/CtpForwardingEngineP$0$loopbackMsgPtr[sim_node()]);
            sim_log_debug(206U, "Forwarder", "%s: I'm a root, so loopback and signal receive.\n", __FUNCTION__);
            /*CtpP.Forwarder*/CtpForwardingEngineP$0$loopbackMsgPtr[sim_node()] = /*CtpP.Forwarder*/CtpForwardingEngineP$0$Receive$receive(collectid, /*CtpP.Forwarder*/CtpForwardingEngineP$0$loopbackMsgPtr[sim_node()], payload, payloadLength);

            /*CtpP.Forwarder*/CtpForwardingEngineP$0$SubSend$sendDone(qe->msg, SUCCESS);
          }
        else {

            /*CtpP.Forwarder*/CtpForwardingEngineP$0$CtpPacket$setEtx(qe->msg, gradient);
            /*CtpP.Forwarder*/CtpForwardingEngineP$0$CtpPacket$clearOption(qe->msg, CTP_OPT_ECN | CTP_OPT_PULL);


            if (/*CtpP.Forwarder*/CtpForwardingEngineP$0$PacketAcknowledgements$requestAck(qe->msg) == SUCCESS) {
                /*CtpP.Forwarder*/CtpForwardingEngineP$0$setState(/*CtpP.Forwarder*/CtpForwardingEngineP$0$ACK_PENDING);
              }

            if (/*CtpP.Forwarder*/CtpForwardingEngineP$0$hasState(/*CtpP.Forwarder*/CtpForwardingEngineP$0$QUEUE_CONGESTED)) {
                /*CtpP.Forwarder*/CtpForwardingEngineP$0$CtpPacket$setOption(qe->msg, CTP_OPT_ECN);
                /*CtpP.Forwarder*/CtpForwardingEngineP$0$clearState(/*CtpP.Forwarder*/CtpForwardingEngineP$0$QUEUE_CONGESTED);
              }

            subsendResult = /*CtpP.Forwarder*/CtpForwardingEngineP$0$SubSend$send(dest, qe->msg, payloadLen);


            if (subsendResult == SUCCESS) {

                /*CtpP.Forwarder*/CtpForwardingEngineP$0$setState(/*CtpP.Forwarder*/CtpForwardingEngineP$0$SENDING);
                qe->forcedParentDraw = FALSE;

                sim_log_debug(207U, "Forwarder", "%s: subsend succeeded with %p.\n", __FUNCTION__, qe->msg);
                return;
              }
            else {
              if (subsendResult == ESIZE || subsendResult == EINVAL) {
                  sim_log_debug(208U, "Forwarder", "%s: subsend failed from ESIZE: truncate packet.\n", __FUNCTION__);
                  qe->forcedParentDraw = FALSE;
                  /*CtpP.Forwarder*/CtpForwardingEngineP$0$Packet$setPayloadLength(qe->msg, /*CtpP.Forwarder*/CtpForwardingEngineP$0$Packet$maxPayloadLength());
                  /*CtpP.Forwarder*/CtpForwardingEngineP$0$sendTask$postTask();
                  /*CtpP.Forwarder*/CtpForwardingEngineP$0$CollectionDebug$logEvent(NET_C_FE_SUBSEND_SIZE);
                }
              else {
                if (subsendResult == EBUSY) {
                    sim_log_debug(209U, "Forwarder", "%s: subsend failed from EBUSY: truncate packet.\n", __FUNCTION__);

                    qe->forcedParentDraw = TRUE;






                    /*CtpP.Forwarder*/CtpForwardingEngineP$0$startRetxmitTimer(SENDDONE_FAIL_WINDOW, SENDDONE_FAIL_OFFSET);
                  }
                else 

                  {

                    sim_log_debug(210U, "Forwarder", "%s: subsend failed from %i\n", __FUNCTION__, (int )subsendResult);

                    qe->forcedParentDraw = TRUE;





                    /*CtpP.Forwarder*/CtpForwardingEngineP$0$startRetxmitTimer(SENDDONE_FAIL_WINDOW, SENDDONE_FAIL_OFFSET);
                  }
                }
              }
          }
      }
    }
}

# 110 "/opt/tinyos-2.1.2/tos/interfaces/AMSend.nc"
inline static void /*CtpP.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$0$AMSend$sendDone(message_t * msg, error_t error){
#line 110
  /*CtpP.Forwarder*/CtpForwardingEngineP$0$SubSend$sendDone(msg, error);
#line 110
}
#line 110
# 65 "/opt/tinyos-2.1.2/tos/system/AMQueueEntryP.nc"
static inline void /*CtpP.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$0$Send$sendDone(message_t *m, error_t err)
#line 65
{
  /*CtpP.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$0$AMSend$sendDone(m, err);
}

# 110 "/opt/tinyos-2.1.2/tos/interfaces/AMSend.nc"
inline static void LinkEstimatorP$Send$sendDone(message_t * msg, error_t error){
#line 110
  /*CtpP.Router*/EerParentSetEngineP$0$BeaconSend$sendDone(msg, error);
#line 110
}
#line 110
# 616 "../net/net_EER_sim/4bitle/LinkEstimatorP.nc"
static inline void LinkEstimatorP$AMSend$sendDone(message_t *msg, error_t error)
#line 616
{
  LinkEstimatorP$Send$sendDone(msg, error);
}

# 110 "/opt/tinyos-2.1.2/tos/interfaces/AMSend.nc"
inline static void /*CtpP.SendControl.SenderC.AMQueueEntryP*/AMQueueEntryP$1$AMSend$sendDone(message_t * msg, error_t error){
#line 110
  LinkEstimatorP$AMSend$sendDone(msg, error);
#line 110
}
#line 110
# 65 "/opt/tinyos-2.1.2/tos/system/AMQueueEntryP.nc"
static inline void /*CtpP.SendControl.SenderC.AMQueueEntryP*/AMQueueEntryP$1$Send$sendDone(message_t *m, error_t err)
#line 65
{
  /*CtpP.SendControl.SenderC.AMQueueEntryP*/AMQueueEntryP$1$AMSend$sendDone(m, err);
}

# 215 "/opt/tinyos-2.1.2/tos/system/AMQueueImplP.nc"
static inline void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Send$default$sendDone(uint8_t id, message_t *msg, error_t err)
#line 215
{
}

# 100 "/opt/tinyos-2.1.2/tos/interfaces/Send.nc"
inline static void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Send$sendDone(uint8_t arg_0x40deae70, message_t * msg, error_t error){
#line 100
  switch (arg_0x40deae70) {
#line 100
    case 0U:
#line 100
      /*CtpP.AMSenderC.SenderC.AMQueueEntryP*/AMQueueEntryP$0$Send$sendDone(msg, error);
#line 100
      break;
#line 100
    case 1U:
#line 100
      /*CtpP.SendControl.SenderC.AMQueueEntryP*/AMQueueEntryP$1$Send$sendDone(msg, error);
#line 100
      break;
#line 100
    default:
#line 100
      /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Send$default$sendDone(arg_0x40deae70, msg, error);
#line 100
      break;
#line 100
    }
#line 100
}
#line 100
# 163 "/opt/tinyos-2.1.2/tos/system/AMQueueImplP.nc"
static inline void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$sendDone(uint8_t last, message_t * msg, error_t err)
#line 163
{
  /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$queue[sim_node()][last].msg = (void *)0;
  /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$tryToSend();
  /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Send$sendDone(last, msg, err);
}

static inline void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$errorTask$runTask(void )
#line 169
{
  /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$sendDone(/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current[sim_node()], /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$queue[sim_node()][/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current[sim_node()]].msg, FAIL);
}

#line 126
static inline void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$CancelTask$runTask(void )
#line 126
{
  uint8_t i;
#line 127
  uint8_t j;
#line 127
  uint8_t mask;
#line 127
  uint8_t last;
  message_t *msg;

#line 129
  for (i = 0; i < 2 / 8 + 1; i++) {
      if (/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$cancelMask[sim_node()][i]) {
          for (mask = 1, j = 0; j < 8; j++) {
              if (/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$cancelMask[sim_node()][i] & mask) {
                  last = i * 8 + j;
                  msg = /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$queue[sim_node()][last].msg;
                  /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$queue[sim_node()][last].msg = (void *)0;
                  /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$cancelMask[sim_node()][i] &= ~mask;
                  /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Send$sendDone(last, msg, ECANCEL);
                }
              mask <<= 1;
            }
        }
    }
}

# 75 "/opt/tinyos-2.1.2/tos/interfaces/Send.nc"
inline static error_t /*CtpP.SendControl.SenderC.AMQueueEntryP*/AMQueueEntryP$1$Send$send(message_t * msg, uint8_t len){
#line 75
  unsigned char __nesc_result;
#line 75

#line 75
  __nesc_result = /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Send$send(1U, msg, len);
#line 75

#line 75
  return __nesc_result;
#line 75
}
#line 75
# 162 "/opt/tinyos-2.1.2/tos/interfaces/AMPacket.nc"
inline static void /*CtpP.SendControl.SenderC.AMQueueEntryP*/AMQueueEntryP$1$AMPacket$setType(message_t * amsg, am_id_t t){
#line 162
  TossimActiveMessageC$AMPacket$setType(amsg, t);
#line 162
}
#line 162
#line 103
inline static void /*CtpP.SendControl.SenderC.AMQueueEntryP*/AMQueueEntryP$1$AMPacket$setDestination(message_t * amsg, am_addr_t addr){
#line 103
  TossimActiveMessageC$AMPacket$setDestination(amsg, addr);
#line 103
}
#line 103
# 53 "/opt/tinyos-2.1.2/tos/system/AMQueueEntryP.nc"
static inline error_t /*CtpP.SendControl.SenderC.AMQueueEntryP*/AMQueueEntryP$1$AMSend$send(am_addr_t dest, 
message_t *msg, 
uint8_t len)
#line 55
{
  /*CtpP.SendControl.SenderC.AMQueueEntryP*/AMQueueEntryP$1$AMPacket$setDestination(msg, dest);
  /*CtpP.SendControl.SenderC.AMQueueEntryP*/AMQueueEntryP$1$AMPacket$setType(msg, 112);
  return /*CtpP.SendControl.SenderC.AMQueueEntryP*/AMQueueEntryP$1$Send$send(msg, len);
}

# 80 "/opt/tinyos-2.1.2/tos/interfaces/AMSend.nc"
inline static error_t LinkEstimatorP$AMSend$send(am_addr_t addr, message_t * msg, uint8_t len){
#line 80
  unsigned char __nesc_result;
#line 80

#line 80
  __nesc_result = /*CtpP.SendControl.SenderC.AMQueueEntryP*/AMQueueEntryP$1$AMSend$send(addr, msg, len);
#line 80

#line 80
  return __nesc_result;
#line 80
}
#line 80
# 118 "../net/net_EER_sim/4bitle/LinkEstimatorP.nc"
static inline linkest_footer_t *LinkEstimatorP$getFooter(message_t *m, uint8_t len)
#line 118
{

  return (linkest_footer_t *)(len + (uint8_t *)LinkEstimatorP$Packet$getPayload(m, len + sizeof(linkest_footer_t )));
}




static inline uint8_t LinkEstimatorP$addLinkEstHeaderAndFooter(message_t *msg, uint8_t len)
#line 126
{
  unsigned char *__nesc_temp44;
#line 127
  uint8_t newlen;
  linkest_header_t * hdr;
  linkest_footer_t * footer;
  uint8_t i;
#line 130
  uint8_t j;
#line 130
  uint8_t k;
  uint8_t maxEntries;
#line 131
  uint8_t newPrevSentIdx;

#line 132
  sim_log_debug(244U, "LI", "newlen1 = %d\n", len);
  hdr = LinkEstimatorP$getHeader(msg);
  footer = LinkEstimatorP$getFooter(msg, len);

  maxEntries = (LinkEstimatorP$SubPacket$maxPayloadLength() - len - sizeof(linkest_header_t ))
   / sizeof(linkest_footer_t );



  if (maxEntries > NUM_ENTRIES_FLAG) {
      maxEntries = NUM_ENTRIES_FLAG;
    }
  sim_log_debug(245U, "LI", "Max payload is: %d, maxEntries is: %d\n", LinkEstimatorP$SubPacket$maxPayloadLength(), maxEntries);

  j = 0;
  newPrevSentIdx = 0;
  for (i = 0; i < 14 && j < maxEntries; i++) {
      uint8_t neighborCount;
      neighbor_stat_entry_t * neighborLists;

#line 151
      if (maxEntries <= 14) {
        neighborCount = maxEntries;
        }
      else {
#line 154
        neighborCount = 14;
        }
      neighborLists = (neighbor_stat_entry_t * )footer->neighborList;
      k = (LinkEstimatorP$prevSentIdx[sim_node()] + i + 1) % 14;
      if (LinkEstimatorP$NeighborTable[sim_node()][k].flags & VALID_ENTRY && 
      LinkEstimatorP$NeighborTable[sim_node()][k].flags & MATURE_ENTRY) {
          __nesc_hton_uint16(neighborLists[j].ll_addr.nxdata, LinkEstimatorP$NeighborTable[sim_node()][k].ll_addr);
          __nesc_hton_uint8(neighborLists[j].inquality.nxdata, LinkEstimatorP$NeighborTable[sim_node()][k].inquality);
          newPrevSentIdx = k;
          sim_log_debug(246U, "LI", "Loaded on footer: %d %d %d\n", j, __nesc_ntoh_uint16(neighborLists[j].ll_addr.nxdata), __nesc_ntoh_uint8(neighborLists[j].inquality.nxdata));

          j++;
        }
    }
  LinkEstimatorP$prevSentIdx[sim_node()] = newPrevSentIdx;

  __nesc_hton_uint8(hdr->seq.nxdata, LinkEstimatorP$linkEstSeq[sim_node()]++);
  __nesc_hton_uint8(hdr->flags.nxdata, 0);
  (__nesc_temp44 = hdr->flags.nxdata, __nesc_hton_uint8(__nesc_temp44, __nesc_ntoh_uint8(__nesc_temp44) | (NUM_ENTRIES_FLAG & j)));
  newlen = sizeof(linkest_header_t ) + len + j * sizeof(linkest_footer_t );
  sim_log_debug(247U, "LI", "newlen2 = %d\n", newlen);
  return newlen;
}

#line 605
static inline error_t LinkEstimatorP$Send$send(am_addr_t addr, message_t *msg, uint8_t len)
#line 605
{
  uint8_t newlen;

#line 607
  newlen = LinkEstimatorP$addLinkEstHeaderAndFooter(msg, len);
  sim_log_debug(266U, "LITest", "%s packet of length %hhu became %hhu\n", __FUNCTION__, len, newlen);
  sim_log_debug(267U, "LI", "Sending seq: %d\n", LinkEstimatorP$linkEstSeq[sim_node()]);
  LinkEstimatorP$print_packet(msg, newlen);
  return LinkEstimatorP$AMSend$send(addr, msg, newlen);
}

# 80 "/opt/tinyos-2.1.2/tos/interfaces/AMSend.nc"
inline static error_t /*CtpP.Router*/EerParentSetEngineP$0$BeaconSend$send(am_addr_t addr, message_t * msg, uint8_t len){
#line 80
  unsigned char __nesc_result;
#line 80

#line 80
  __nesc_result = LinkEstimatorP$Send$send(addr, msg, len);
#line 80

#line 80
  return __nesc_result;
#line 80
}
#line 80
# 1242 "../net/net_EER_sim/eer/CtpForwardingEngineP.nc"
static inline bool /*CtpP.Forwarder*/CtpForwardingEngineP$0$CtpCongestion$isCongested(void )
#line 1242
{
  return FALSE;
}

# 7 "../net/net_EER_sim/eer/CtpCongestion.nc"
inline static bool /*CtpP.Router*/EerParentSetEngineP$0$CtpCongestion$isCongested(void ){
#line 7
  unsigned char __nesc_result;
#line 7

#line 7
  __nesc_result = /*CtpP.Forwarder*/CtpForwardingEngineP$0$CtpCongestion$isCongested();
#line 7

#line 7
  return __nesc_result;
#line 7
}
#line 7
# 528 "../net/net_EER_sim/eer/EerParentSetEngineP.nc"
static inline void /*CtpP.Router*/EerParentSetEngineP$0$sendBeaconTask$runTask(void )
#line 528
{
  unsigned char *__nesc_temp46;
  unsigned char *__nesc_temp45;
#line 529
  error_t eval;

#line 530
  if (/*CtpP.Router*/EerParentSetEngineP$0$sending[sim_node()]) {
      return;
    }

  __nesc_hton_uint8(/*CtpP.Router*/EerParentSetEngineP$0$beaconMsg[sim_node()]->options.nxdata, 0);


  if (/*CtpP.Router*/EerParentSetEngineP$0$CtpCongestion$isCongested()) {
      (__nesc_temp45 = /*CtpP.Router*/EerParentSetEngineP$0$beaconMsg[sim_node()]->options.nxdata, __nesc_hton_uint8(__nesc_temp45, __nesc_ntoh_uint8(__nesc_temp45) | CTP_OPT_ECN));
    }

  __nesc_hton_uint16(/*CtpP.Router*/EerParentSetEngineP$0$beaconMsg[sim_node()]->parent.nxdata, /*CtpP.Router*/EerParentSetEngineP$0$routeInfo[sim_node()].parent);
  if (/*CtpP.Router*/EerParentSetEngineP$0$state_is_root[sim_node()]) {
      __nesc_hton_uint16(/*CtpP.Router*/EerParentSetEngineP$0$beaconMsg[sim_node()]->etx.nxdata, /*CtpP.Router*/EerParentSetEngineP$0$routeInfo[sim_node()].etx);
    }
  else {
#line 545
    if (/*CtpP.Router*/EerParentSetEngineP$0$routeInfo[sim_node()].parent == INVALID_ADDR) {
        __nesc_hton_uint16(/*CtpP.Router*/EerParentSetEngineP$0$beaconMsg[sim_node()]->etx.nxdata, /*CtpP.Router*/EerParentSetEngineP$0$routeInfo[sim_node()].etx);
        (__nesc_temp46 = /*CtpP.Router*/EerParentSetEngineP$0$beaconMsg[sim_node()]->options.nxdata, __nesc_hton_uint8(__nesc_temp46, __nesc_ntoh_uint8(__nesc_temp46) | CTP_OPT_PULL));
      }
    else 
#line 548
      {
        __nesc_hton_uint16(/*CtpP.Router*/EerParentSetEngineP$0$beaconMsg[sim_node()]->etx.nxdata, /*CtpP.Router*/EerParentSetEngineP$0$routeInfo[sim_node()].etx + /*CtpP.Router*/EerParentSetEngineP$0$LinkEstimator$getLinkQuality(/*CtpP.Router*/EerParentSetEngineP$0$routeInfo[sim_node()].parent));
      }
    }
  sim_log_debug(293U, "TreeRouting", "%s parent: %d etx: %d\n", __FUNCTION__, __nesc_ntoh_uint16(/*CtpP.Router*/EerParentSetEngineP$0$beaconMsg[sim_node()]->parent.nxdata), __nesc_ntoh_uint16(/*CtpP.Router*/EerParentSetEngineP$0$beaconMsg[sim_node()]->etx.nxdata));



  /*CtpP.Router*/EerParentSetEngineP$0$CollectionDebug$logEventRoute(NET_C_TREE_SENT_BEACON, __nesc_ntoh_uint16(/*CtpP.Router*/EerParentSetEngineP$0$beaconMsg[sim_node()]->parent.nxdata), 0, __nesc_ntoh_uint16(/*CtpP.Router*/EerParentSetEngineP$0$beaconMsg[sim_node()]->etx.nxdata));

  eval = /*CtpP.Router*/EerParentSetEngineP$0$BeaconSend$send(AM_BROADCAST_ADDR, 
  &/*CtpP.Router*/EerParentSetEngineP$0$beaconMsgBuffer[sim_node()], 
  sizeof(ctp_routing_header_t ));
  if (eval == SUCCESS) {
      /*CtpP.Router*/EerParentSetEngineP$0$sending[sim_node()] = TRUE;
    }
  else {
#line 563
    if (eval == EOFF) {
        /*CtpP.Router*/EerParentSetEngineP$0$radioOn[sim_node()] = FALSE;
        sim_log_debug(294U, "TreeRoutingCtl", "%s running: %d radioOn: %d\n", __FUNCTION__, /*CtpP.Router*/EerParentSetEngineP$0$running[sim_node()], /*CtpP.Router*/EerParentSetEngineP$0$radioOn[sim_node()]);
      }
    }
}

# 333 "../net/net_EER_sim/eer/CtpForwardingEngineP.nc"
static inline void /*CtpP.Forwarder*/CtpForwardingEngineP$0$UnicastNameFreeRouting$noRoute(void )
#line 333
{
}

# 52 "../net/net_EER_sim/UnicastNameFreeRouting.nc"
inline static void /*CtpP.Router*/EerParentSetEngineP$0$Routing$noRoute(void ){
#line 52
  /*CtpP.Forwarder*/CtpForwardingEngineP$0$UnicastNameFreeRouting$noRoute();
#line 52
}
#line 52
# 43 "../net/net_EER_sim/eer_parentselection/EerParentSelectionConfig.nc"
inline static error_t /*CtpP.Router*/EerParentSetEngineP$0$EerParentSelectionConfig$addParentCandidate(routing_table_entry *entry, __nesc_nxbase_nx_uint16_t candETX){
#line 43
  unsigned char __nesc_result;
#line 43

#line 43
  __nesc_result = /*CtpP.ParentSelector*/EerParentSelectionP$0$EerParentSelectionConfig$addParentCandidate(entry, candETX);
#line 43

#line 43
  return __nesc_result;
#line 43
}
#line 43
#line 41
inline static void /*CtpP.Router*/EerParentSetEngineP$0$EerParentSelectionConfig$initializeParentSet(void ){
#line 41
  /*CtpP.ParentSelector*/EerParentSelectionP$0$EerParentSelectionConfig$initializeParentSet();
#line 41
}
#line 41
# 590 "../net/net_EER_sim/4bitle/LinkEstimatorP.nc"
static inline error_t LinkEstimatorP$LinkEstimator$clearDLQ(am_addr_t neighbor)
#line 590
{
  neighbor_table_entry_t *ne;
  uint8_t nidx = LinkEstimatorP$findIdx(neighbor);

#line 593
  if (nidx == LinkEstimatorP$INVALID_RVAL) {
      return FAIL;
    }
  ne = &LinkEstimatorP$NeighborTable[sim_node()][nidx];
  ne->data_total = 0;
  ne->data_success = 0;
  return SUCCESS;
}

# 69 "../net/net_EER_sim/4bitle/LinkEstimator.nc"
inline static error_t /*CtpP.Router*/EerParentSetEngineP$0$LinkEstimator$clearDLQ(am_addr_t neighbor){
#line 69
  unsigned char __nesc_result;
#line 69

#line 69
  __nesc_result = LinkEstimatorP$LinkEstimator$clearDLQ(neighbor);
#line 69

#line 69
  return __nesc_result;
#line 69
}
#line 69
# 545 "../net/net_EER_sim/4bitle/LinkEstimatorP.nc"
static inline error_t LinkEstimatorP$LinkEstimator$unpinNeighbor(am_addr_t neighbor)
#line 545
{
  uint8_t nidx = LinkEstimatorP$findIdx(neighbor);

#line 547
  if (nidx == LinkEstimatorP$INVALID_RVAL) {
      return FAIL;
    }
  LinkEstimatorP$NeighborTable[sim_node()][nidx].flags &= ~PINNED_ENTRY;
  return SUCCESS;
}

# 58 "../net/net_EER_sim/4bitle/LinkEstimator.nc"
inline static error_t /*CtpP.Router*/EerParentSetEngineP$0$LinkEstimator$unpinNeighbor(am_addr_t neighbor){
#line 58
  unsigned char __nesc_result;
#line 58

#line 58
  __nesc_result = LinkEstimatorP$LinkEstimator$unpinNeighbor(neighbor);
#line 58

#line 58
  return __nesc_result;
#line 58
}
#line 58
# 938 "../net/net_EER_sim/eer/EerParentSetEngineP.nc"
static inline error_t /*CtpP.Router*/EerParentSetEngineP$0$CollectionDebug$default$logEventDbg(uint8_t type, uint16_t arg1, uint16_t arg2, uint16_t arg3)
#line 938
{
  return SUCCESS;
}

# 67 "../net/net_EER_sim/CollectionDebug.nc"
inline static error_t /*CtpP.Router*/EerParentSetEngineP$0$CollectionDebug$logEventDbg(uint8_t type, uint16_t arg1, uint16_t arg2, uint16_t arg3){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = /*CtpP.Router*/EerParentSetEngineP$0$CollectionDebug$default$logEventDbg(type, arg1, arg2, arg3);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
# 111 "../net/net_EER_sim/eer/EerInstrumentationP.nc"
static inline error_t EerInstrumentationP$EerInstrumentation$ctrl_parentchange(void )
#line 111
{
  unsigned short __nesc_temp56;
  unsigned char *__nesc_temp55;

#line 112
  (__nesc_temp55 = EerInstrumentationP$stats[sim_node()].ctrl_nparentchange.nxdata, __nesc_hton_uint16(__nesc_temp55, (__nesc_temp56 = __nesc_ntoh_uint16(__nesc_temp55)) + 1), __nesc_temp56);
  return SUCCESS;
}

# 44 "../net/net_EER_sim/eer/EerInstrumentation.nc"
inline static error_t /*CtpP.Router*/EerParentSetEngineP$0$EerInstrumentation$ctrl_parentchange(void ){
#line 44
  unsigned char __nesc_result;
#line 44

#line 44
  __nesc_result = EerInstrumentationP$EerInstrumentation$ctrl_parentchange();
#line 44

#line 44
  return __nesc_result;
#line 44
}
#line 44
# 175 "../net/net_EER_sim/eer_parentselection/EerParentSelectionP.nc"
static inline error_t /*CtpP.ParentSelector*/EerParentSelectionP$0$EerParentSelectionConfig$getParentSetETX(nx_uint16_t *parentSetETX, nx_uint8_t *parentSetSize)
#line 175
{


  if (__nesc_ntoh_uint8(/*CtpP.ParentSelector*/EerParentSelectionP$0$prntSet[sim_node()].setSize.nxdata) == 0) {

      __nesc_hton_uint16((*parentSetETX).nxdata, MAX_METRIC);
      __nesc_hton_uint8((*parentSetSize).nxdata, __nesc_ntoh_uint8(/*CtpP.ParentSelector*/EerParentSelectionP$0$prntSet[sim_node()].setSize.nxdata));
      return FAIL;
    }
  else {

      __nesc_hton_uint16((*parentSetETX).nxdata, __nesc_ntoh_uint16(/*CtpP.ParentSelector*/EerParentSelectionP$0$prntSet[sim_node()].setETX.nxdata));
      __nesc_hton_uint8((*parentSetSize).nxdata, __nesc_ntoh_uint8(/*CtpP.ParentSelector*/EerParentSelectionP$0$prntSet[sim_node()].setSize.nxdata));
      return SUCCESS;
    }
}

# 47 "../net/net_EER_sim/eer_parentselection/EerParentSelectionConfig.nc"
inline static error_t /*CtpP.Router*/EerParentSetEngineP$0$EerParentSelectionConfig$getParentSetETX(nx_uint16_t *parentSetETX, nx_uint8_t *parentSetSize){
#line 47
  unsigned char __nesc_result;
#line 47

#line 47
  __nesc_result = /*CtpP.ParentSelector*/EerParentSelectionP$0$EerParentSelectionConfig$getParentSetETX(parentSetETX, parentSetSize);
#line 47

#line 47
  return __nesc_result;
#line 47
}
#line 47
# 278 "../net/net_EER_sim/eer/EerParentSetEngineP.nc"
static inline void /*CtpP.Router*/EerParentSetEngineP$0$updateRouteTask$runTask(void )
#line 278
{
  uint8_t i;
  routing_table_entry *entry;
  routing_table_entry *best;
  uint16_t minEtx;
  uint16_t currentEtx;
  uint16_t linkEtx;
#line 284
  uint16_t pathEtx;


  nx_uint16_t parentSetETX;
  nx_uint8_t parentSetSize;
  bool addedParentToSet = FALSE;

  if (/*CtpP.Router*/EerParentSetEngineP$0$state_is_root[sim_node()]) {
    return;
    }
  best = (void *)0;

  minEtx = MAX_METRIC;

  currentEtx = MAX_METRIC;

  sim_log_debug(286U, "TreeRouting", "%s\n", __FUNCTION__);


  /*CtpP.Router*/EerParentSetEngineP$0$EerParentSelectionConfig$initializeParentSet();



  i = /*CtpP.Router*/EerParentSetEngineP$0$routingTableFind(/*CtpP.Router*/EerParentSetEngineP$0$routeInfo[sim_node()].parent);
  if (i < /*CtpP.Router*/EerParentSetEngineP$0$routingTableActive[sim_node()]) {
      entry = &/*CtpP.Router*/EerParentSetEngineP$0$routingTable[sim_node()][i];
      linkEtx = /*CtpP.Router*/EerParentSetEngineP$0$LinkEstimator$getLinkQuality(entry->neighbor);


      if (entry->info.parent == INVALID_ADDR || 
      entry->info.parent == /*CtpP.Router*/EerParentSetEngineP$0$my_ll_addr[sim_node()]) {

          addedParentToSet = FALSE;
        }
      else {

          currentEtx = entry->info.etx + linkEtx;

          { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 322
            {
              /*CtpP.Router*/EerParentSetEngineP$0$routeInfo[sim_node()].etx = entry->info.etx;
              /*CtpP.Router*/EerParentSetEngineP$0$routeInfo[sim_node()].congested = entry->info.congested;
            }
#line 325
            __nesc_atomic_end(__nesc_atomic); }


          /*CtpP.Router*/EerParentSetEngineP$0$EerParentSelectionConfig$addParentCandidate(entry, currentEtx);
          addedParentToSet = TRUE;
        }
    }




  for (i = 0; i < /*CtpP.Router*/EerParentSetEngineP$0$routingTableActive[sim_node()]; i++) {
      entry = &/*CtpP.Router*/EerParentSetEngineP$0$routingTable[sim_node()][i];

      linkEtx = /*CtpP.Router*/EerParentSetEngineP$0$LinkEstimator$getLinkQuality(entry->neighbor);


      if (entry->neighbor == /*CtpP.Router*/EerParentSetEngineP$0$routeInfo[sim_node()].parent) {
          continue;
        }


      if (entry->info.parent == INVALID_ADDR || entry->info.parent == /*CtpP.Router*/EerParentSetEngineP$0$my_ll_addr[sim_node()]) {
          sim_log_debug(287U, "TreeRouting", "routingTable[%d]: neighbor: [id: %d parent: %d  etx: NO ROUTE]\n", i, entry->neighbor, entry->info.parent);



          continue;
        }


      if (entry->info.etx == MAX_METRIC) {
          continue;
        }

      sim_log_debug(288U, "TreeRouting", "routingTable[%d]: neighbor: [id: %d parent: %d etx: %d retx: %d]\n", i, entry->neighbor, entry->info.parent, linkEtx, entry->info.etx);





      pathEtx = linkEtx + entry->info.etx;



      if (entry->info.congested) {
          continue;
        }


      if (!/*CtpP.Router*/EerParentSetEngineP$0$passLinkEtxThreshold(linkEtx)) {
          sim_log_debug(289U, "TreeRouting", "   did not pass threshold.\n");
          continue;
        }


      if (pathEtx < minEtx) {
          sim_log_debug(290U, "TreeRouting", "   best is %d, setting to %d\n", pathEtx, entry->neighbor);
          minEtx = pathEtx;
          best = entry;
        }

      if (!addedParentToSet) {
          continue;
        }


      if (currentEtx == MAX_METRIC) {
          /*CtpP.Router*/EerParentSetEngineP$0$EerParentSelectionConfig$addParentCandidate(entry, pathEtx);
        }
      else {

          if (entry->info.etx < /*CtpP.Router*/EerParentSetEngineP$0$routeInfo[sim_node()].etx + 10 && pathEtx < currentEtx + 10) {
              /*CtpP.Router*/EerParentSetEngineP$0$EerParentSelectionConfig$addParentCandidate(entry, pathEtx);
            }
          else {
            }
        }
    }




  /*CtpP.Router*/EerParentSetEngineP$0$EerParentSelectionConfig$getParentSetETX(&parentSetETX, &parentSetSize);

  /*CtpP.Router*/EerParentSetEngineP$0$CollectionDebug$logEventDbg(NET_C_DBG_3, /*CtpP.Router*/EerParentSetEngineP$0$routeInfo[sim_node()].parent, currentEtx, minEtx);
#line 424
  if (minEtx != MAX_METRIC) 
    {


      if (((
#line 426
      currentEtx == MAX_METRIC || (
      /*CtpP.Router*/EerParentSetEngineP$0$routeInfo[sim_node()].congested && minEtx < /*CtpP.Router*/EerParentSetEngineP$0$routeInfo[sim_node()].etx + 10)) || 
      minEtx < currentEtx) || (best->info.etx == 0 && minEtx < currentEtx)) 
        {





          /*CtpP.Router*/EerParentSetEngineP$0$EerInstrumentation$ctrl_parentchange();

          sim_log_debug(291U, "TreeRouting", "Changed parent. from %d to %d\n", /*CtpP.Router*/EerParentSetEngineP$0$routeInfo[sim_node()].parent, best->neighbor);

          /*CtpP.Router*/EerParentSetEngineP$0$CollectionDebug$logEventDbg(NET_C_TREE_NEW_PARENT, best->neighbor, 
          best->info.etx, minEtx);

          /*CtpP.Router*/EerParentSetEngineP$0$LinkEstimator$unpinNeighbor(/*CtpP.Router*/EerParentSetEngineP$0$routeInfo[sim_node()].parent);
          /*CtpP.Router*/EerParentSetEngineP$0$LinkEstimator$pinNeighbor(best->neighbor);
          /*CtpP.Router*/EerParentSetEngineP$0$LinkEstimator$clearDLQ(best->neighbor);

          { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 446
            {
              /*CtpP.Router*/EerParentSetEngineP$0$routeInfo[sim_node()].parent = best->neighbor;
              /*CtpP.Router*/EerParentSetEngineP$0$routeInfo[sim_node()].etx = best->info.etx;
              /*CtpP.Router*/EerParentSetEngineP$0$routeInfo[sim_node()].congested = best->info.congested;
            }
#line 450
            __nesc_atomic_end(__nesc_atomic); }


          /*CtpP.Router*/EerParentSetEngineP$0$EerParentSelectionConfig$initializeParentSet();

          /*CtpP.Router*/EerParentSetEngineP$0$EerParentSelectionConfig$addParentCandidate(best, minEtx);

          for (i = 0; i < /*CtpP.Router*/EerParentSetEngineP$0$routingTableActive[sim_node()]; i++) {
              entry = &/*CtpP.Router*/EerParentSetEngineP$0$routingTable[sim_node()][i];
              linkEtx = /*CtpP.Router*/EerParentSetEngineP$0$LinkEstimator$getLinkQuality(entry->neighbor);


              if (entry->neighbor == /*CtpP.Router*/EerParentSetEngineP$0$routeInfo[sim_node()].parent) {
                  continue;
                }


              if (entry->info.parent == INVALID_ADDR || entry->info.parent == /*CtpP.Router*/EerParentSetEngineP$0$my_ll_addr[sim_node()]) {
                  continue;
                }


              if (entry->info.etx == MAX_METRIC) {
                  continue;
                }


              pathEtx = linkEtx + entry->info.etx;


              if (entry->info.congested) {
                  continue;
                }


              if (!/*CtpP.Router*/EerParentSetEngineP$0$passLinkEtxThreshold(linkEtx)) {
                  continue;
                }


              if (entry->info.etx < /*CtpP.Router*/EerParentSetEngineP$0$routeInfo[sim_node()].etx + 10 && pathEtx < minEtx + 10) {
                  /*CtpP.Router*/EerParentSetEngineP$0$EerParentSelectionConfig$addParentCandidate(entry, pathEtx);
                }
            }


          if (currentEtx - minEtx > 20) {
              /*CtpP.Router*/EerParentSetEngineP$0$CtpInfo$triggerRouteUpdate();
              sim_log_debug(292U, "XY_trickle", "trickle_reset better paths\n");
            }
        }
    }






  if (/*CtpP.Router*/EerParentSetEngineP$0$justEvicted[sim_node()] && /*CtpP.Router*/EerParentSetEngineP$0$routeInfo[sim_node()].parent == INVALID_ADDR) {
      /*CtpP.Router*/EerParentSetEngineP$0$Routing$noRoute();
    }
  else {




    if (
#line 515
    !/*CtpP.Router*/EerParentSetEngineP$0$justEvicted[sim_node()] && 
    currentEtx == MAX_METRIC && 
    minEtx != MAX_METRIC) {
        /*CtpP.Router*/EerParentSetEngineP$0$Routing$routeFound();
      }
    }
#line 520
  /*CtpP.Router*/EerParentSetEngineP$0$justEvicted[sim_node()] = FALSE;
}

# 221 "/opt/tinyos-2.1.2/tos/lib/tossim/SimSchedulerBasicP.nc"
static inline void SimSchedulerBasicP$TaskBasic$default$runTask(uint8_t id)
{
}

# 75 "/opt/tinyos-2.1.2/tos/interfaces/TaskBasic.nc"
inline static void SimSchedulerBasicP$TaskBasic$runTask(uint8_t arg_0x406e11b8){
#line 75
  switch (arg_0x406e11b8) {
#line 75
    case LapTestC$sendDataMessage:
#line 75
      LapTestC$sendDataMessage$runTask();
#line 75
      break;
#line 75
    case TossimPacketModelC$startDoneTask:
#line 75
      TossimPacketModelC$startDoneTask$runTask();
#line 75
      break;
#line 75
    case TossimPacketModelC$stopDoneTask:
#line 75
      TossimPacketModelC$stopDoneTask$runTask();
#line 75
      break;
#line 75
    case TossimPacketModelC$sendDoneTask:
#line 75
      TossimPacketModelC$sendDoneTask$runTask();
#line 75
      break;
#line 75
    case /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$fired:
#line 75
      /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$fired$runTask();
#line 75
      break;
#line 75
    case /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$updateFromTimer:
#line 75
      /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$updateFromTimer$runTask();
#line 75
      break;
#line 75
    case /*CtpP.Forwarder*/CtpForwardingEngineP$0$sendTask:
#line 75
      /*CtpP.Forwarder*/CtpForwardingEngineP$0$sendTask$runTask();
#line 75
      break;
#line 75
    case /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$CancelTask:
#line 75
      /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$CancelTask$runTask();
#line 75
      break;
#line 75
    case /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$errorTask:
#line 75
      /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$errorTask$runTask();
#line 75
      break;
#line 75
    case /*CtpP.Router*/EerParentSetEngineP$0$updateRouteTask:
#line 75
      /*CtpP.Router*/EerParentSetEngineP$0$updateRouteTask$runTask();
#line 75
      break;
#line 75
    case /*CtpP.Router*/EerParentSetEngineP$0$sendBeaconTask:
#line 75
      /*CtpP.Router*/EerParentSetEngineP$0$sendBeaconTask$runTask();
#line 75
      break;
#line 75
    default:
#line 75
      SimSchedulerBasicP$TaskBasic$default$runTask(arg_0x406e11b8);
#line 75
      break;
#line 75
    }
#line 75
}
#line 75
# 94 "/opt/tinyos-2.1.2/tos/interfaces/Packet.nc"
inline static void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Packet$setPayloadLength(message_t * msg, uint8_t len){
#line 94
  TossimActiveMessageC$Packet$setPayloadLength(msg, len);
#line 94
}
#line 94
# 147 "/opt/tinyos-2.1.2/tos/interfaces/AMPacket.nc"
inline static am_id_t /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$AMPacket$type(message_t * amsg){
#line 147
  unsigned char __nesc_result;
#line 147

#line 147
  __nesc_result = TossimActiveMessageC$AMPacket$type(amsg);
#line 147

#line 147
  return __nesc_result;
#line 147
}
#line 147
#line 78
inline static am_addr_t /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$AMPacket$destination(message_t * amsg){
#line 78
  unsigned short __nesc_result;
#line 78

#line 78
  __nesc_result = TossimActiveMessageC$AMPacket$destination(amsg);
#line 78

#line 78
  return __nesc_result;
#line 78
}
#line 78
# 80 "/opt/tinyos-2.1.2/tos/interfaces/AMSend.nc"
inline static error_t /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$AMSend$send(am_id_t arg_0x40de7908, am_addr_t addr, message_t * msg, uint8_t len){
#line 80
  unsigned char __nesc_result;
#line 80

#line 80
  __nesc_result = TossimActiveMessageC$AMSend$send(arg_0x40de7908, addr, msg, len);
#line 80

#line 80
  return __nesc_result;
#line 80
}
#line 80
# 483 "/opt/tinyos-2.1.2/tos/lib/tossim/CpmModelC.nc"
static inline void CpmModelC$free_receive_message(CpmModelC$receive_message_t *msg)
#line 483
{
  free(msg);
}

# 61 "/opt/tinyos-2.1.2/tos/lib/tossim/GainRadioModel.nc"
inline static bool CpmModelC$Model$shouldAck(message_t *msg){
#line 61
  unsigned char __nesc_result;
#line 61

#line 61
  __nesc_result = TossimPacketModelC$GainRadioModel$shouldAck(msg);
#line 61

#line 61
  return __nesc_result;
#line 61
}
#line 61
# 85 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimPacketModel.nc"
inline static void TossimPacketModelC$Packet$receive(message_t *msg){
#line 85
  TossimActiveMessageC$Model$receive(msg);
#line 85
}
#line 85
# 288 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimPacketModelC.nc"
static inline void TossimPacketModelC$GainRadioModel$receive(message_t *msg)
#line 288
{
  if (TossimPacketModelC$running[sim_node()] && !TossimPacketModelC$transmitting[sim_node()]) {
      TossimPacketModelC$Packet$receive(msg);
    }
}

# 60 "/opt/tinyos-2.1.2/tos/lib/tossim/GainRadioModel.nc"
inline static void CpmModelC$Model$receive(message_t *msg){
#line 60
  TossimPacketModelC$GainRadioModel$receive(msg);
#line 60
}
#line 60
# 260 "/opt/tinyos-2.1.2/tos/lib/tossim/CpmModelC.nc"
static inline bool CpmModelC$checkReceive(CpmModelC$receive_message_t *msg)
#line 260
{
  double noise = CpmModelC$noise_hash_generation();
  CpmModelC$receive_message_t *list = CpmModelC$outstandingReceptionHead[sim_node()];

#line 263
  noise = pow(10.0, noise / 10.0);
  while (list != (void *)0) {
      if (list != msg) {
          noise += pow(10.0, list->power / 10.0);
        }
      list = list->next;
    }
  noise = 10.0 * log(noise) / log(10.0);
  return CpmModelC$shouldReceive(msg->power - noise);
}

#line 296
static inline void CpmModelC$sim_gain_receive_handle(sim_event_t *evt)
#line 296
{
  CpmModelC$receive_message_t *mine = (CpmModelC$receive_message_t *)evt->data;
  CpmModelC$receive_message_t *predecessor = (void *)0;
  CpmModelC$receive_message_t *list = CpmModelC$outstandingReceptionHead[sim_node()];

  sim_log_debug(137U, "CpmModelC", "Handling reception event @ %s.\n", sim_time_string());
  while (list != (void *)0) {
      if (list->next == mine) {
          predecessor = list;
        }
      list = list->next;
    }
  if (predecessor) {
      predecessor->next = mine->next;
    }
  else {
#line 311
    if (mine == CpmModelC$outstandingReceptionHead[sim_node()]) {
        CpmModelC$outstandingReceptionHead[sim_node()] = mine->next;
      }
    else {
        sim_log_error(138U, "CpmModelC", "Incoming packet list structure is corrupted: entry is not the head and no entry points to it.\n");
      }
    }
#line 317
  sim_log_debug(139U, "CpmModelC,SNRLoss", "Packet from %i to %i\n", (int )mine->source, (int )sim_node());
  if (!CpmModelC$checkReceive(mine)) {
      sim_log_debug(140U, "CpmModelC,SNRLoss", " - lost packet from %i as SNR was too low.\n", (int )mine->source);
      mine->lost = 1;
    }
  if (! mine->lost) {



      tossim_metadata_t *meta = (tossim_metadata_t *)& mine->msg->metadata;

#line 327
      __nesc_hton_int8(meta->strength.nxdata, mine->strength);

      sim_log_debug_clear(141U, "CpmModelC,SNRLoss", "  -signaling reception\n");
      CpmModelC$Model$receive(mine->msg);
      if (mine->ack) {
          sim_log_debug_clear(142U, "CpmModelC", " acknowledgment requested, ");
        }
      else {
          sim_log_debug_clear(143U, "CpmModelC", " no acknowledgment requested.\n");
        }

      if (mine->ack && CpmModelC$Model$shouldAck(mine->msg)) {
          sim_log_debug_clear(144U, "CpmModelC", " scheduling ack.\n");
          CpmModelC$sim_gain_schedule_ack(mine->source, sim_time() + 1, mine);
        }
      else {
          CpmModelC$free_receive_message(mine);
        }

      CpmModelC$receiving[sim_node()] = 0;
    }
  else {
      if (RandomUniform() < 0.001) {
          sim_log_debug(145U, "CpmModelC,SNRLoss", "Packet was technically lost, but TOSSIM introduces an ack false positive rate.\n");
          if (mine->ack && CpmModelC$Model$shouldAck(mine->msg)) {
              sim_log_debug_clear(146U, "CpmModelC", " scheduling ack.\n");
              CpmModelC$sim_gain_schedule_ack(mine->source, sim_time() + 1, mine);
            }
          else {
              CpmModelC$free_receive_message(mine);
            }
        }
      else {
          CpmModelC$free_receive_message(mine);
        }
      CpmModelC$receiving[sim_node()] = 0;
      sim_log_debug_clear(147U, "CpmModelC,SNRLoss", "  -packet was lost.\n");
    }
}

#line 467
static inline sim_event_t *CpmModelC$allocate_receive_event(sim_time_t endTime, CpmModelC$receive_message_t *msg)
#line 467
{
  sim_event_t *evt = (sim_event_t *)malloc(sizeof(sim_event_t ));

#line 469
  evt->mote = sim_node();
  evt->time = endTime;
  evt->handle = CpmModelC$sim_gain_receive_handle;
  evt->cleanup = sim_queue_cleanup_event;
  evt->cancelled = 0;
  evt->force = 1;
  evt->data = msg;
  return evt;
}

static inline CpmModelC$receive_message_t *CpmModelC$allocate_receive_message(void )
#line 479
{
  return (CpmModelC$receive_message_t *)malloc(sizeof(CpmModelC$receive_message_t ));
}

#line 369
static inline void CpmModelC$enqueue_receive_event(int source, sim_time_t endTime, message_t *msg, bool receive, double power, double reversePower)
#line 369
{
  sim_event_t *evt;
  CpmModelC$receive_message_t *list;
  CpmModelC$receive_message_t *rcv = CpmModelC$allocate_receive_message();
  double noiseStr = CpmModelC$packetNoise(rcv);

#line 374
  rcv->source = source;
  rcv->start = sim_time();
  rcv->end = endTime;
  rcv->power = power;
  rcv->reversePower = reversePower;




  rcv->strength = (int8_t )floor(10.0 * log(pow(10.0, power / 10.0) + pow(10.0, noiseStr / 10.0)) / log(10.0));
  rcv->msg = msg;
  rcv->lost = 0;
  rcv->ack = receive;





  if (!sim_mote_is_on(sim_node())) {
      sim_log_debug(148U, "CpmModelC", "Lost packet from %i due to %i being off\n", source, sim_node());
      rcv->lost = 1;
    }
  else {
#line 396
    if (!CpmModelC$shouldReceive(power - noiseStr)) {
        sim_log_debug(149U, "CpmModelC,SNRLoss", "Lost packet from %i to %i due to SNR being too low (%i)\n", source, sim_node(), (int )(power - noiseStr));
        rcv->lost = 1;
      }
    else {
#line 400
      if (CpmModelC$receiving[sim_node()]) {
          sim_log_debug(150U, "CpmModelC,SNRLoss", "Lost packet from %i due to %i being mid-reception\n", source, sim_node());
          rcv->lost = 1;
        }
      else {
#line 404
        if (CpmModelC$transmitting[sim_node()] && rcv->start < CpmModelC$transmissionEndTime[sim_node()] && CpmModelC$transmissionEndTime[sim_node()] <= rcv->end) {
            sim_log_debug(151U, "CpmModelC,SNRLoss", "Lost packet from %i due to %i being mid-transmission, transmissionEndTime %llu\n", source, sim_node(), CpmModelC$transmissionEndTime[sim_node()]);
            rcv->lost = 1;
          }
        else {
            CpmModelC$receiving[sim_node()] = 1;
          }
        }
      }
    }
#line 412
  list = CpmModelC$outstandingReceptionHead[sim_node()];
  while (list != (void *)0) {
      if (!CpmModelC$shouldReceive(list->power - rcv->power)) {
          sim_log_debug(152U, "Gain,SNRLoss", "Going to lose packet from %i with signal %lf as am receiving a packet from %i with signal %lf\n", list->source, list->power, source, rcv->power);
          list->lost = 1;
        }
      list = list->next;
    }

  rcv->next = CpmModelC$outstandingReceptionHead[sim_node()];
  CpmModelC$outstandingReceptionHead[sim_node()] = rcv;
  evt = CpmModelC$allocate_receive_event(endTime, rcv);
  sim_queue_insert(evt);
}


static inline void CpmModelC$sim_gain_put(int dest, message_t *msg, sim_time_t endTime, bool receive, double power, double reversePower)
#line 428
{
  int prevNode = sim_node();

#line 430
  sim_log_debug(153U, "CpmModelC", "Enqueing reception event for %i at %llu with power %lf.\n", dest, endTime, power);
  sim_set_node(dest);
  CpmModelC$enqueue_receive_event(prevNode, endTime, msg, receive, power, reversePower);
  sim_set_node(prevNode);
}

static inline void CpmModelC$Model$putOnAirTo(int dest, message_t *msg, bool ack, sim_time_t endTime, double power, double reversePower)
#line 436
{
  CpmModelC$receive_message_t *list;
  gain_entry_t *neighborEntry = sim_gain_first(sim_node());

#line 439
  CpmModelC$requestAck[sim_node()] = ack;
  CpmModelC$outgoing[sim_node()] = msg;
  CpmModelC$transmissionEndTime[sim_node()] = endTime;
  sim_log_debug(154U, "CpmModelC", "Node %i transmitting to %i, finishes at %llu.\n", sim_node(), dest, endTime);

  while (neighborEntry != (void *)0) {
      int other = neighborEntry->mote;

#line 446
      CpmModelC$sim_gain_put(other, msg, endTime, ack, power + sim_gain_value(sim_node(), other), reversePower + sim_gain_value(other, sim_node()));
      neighborEntry = sim_gain_next(neighborEntry);
    }

  list = CpmModelC$outstandingReceptionHead[sim_node()];
  while (list != (void *)0) {
      list->lost = 1;
      sim_log_debug(155U, "CpmModelC,SNRLoss", "Lost packet from %i because %i has outstanding reception, startTime %llu endTime %llu\n", list->source, sim_node(), list->start, list->end);
      list = list->next;
    }
}

# 48 "/opt/tinyos-2.1.2/tos/lib/tossim/GainRadioModel.nc"
inline static void TossimPacketModelC$GainRadioModel$putOnAirTo(int dest, message_t *msg, bool ack, sim_time_t endTime, double gain, double reverseGain){
#line 48
  CpmModelC$Model$putOnAirTo(dest, msg, ack, endTime, gain, reverseGain);
#line 48
}
#line 48
# 280 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimPacketModelC.nc"
static inline void TossimPacketModelC$send_transmit_done(sim_event_t *evt)
#line 280
{
  message_t *rval = TossimPacketModelC$sending[sim_node()];

#line 282
  TossimPacketModelC$sending[sim_node()] = (void *)0;
  TossimPacketModelC$transmitting[sim_node()] = FALSE;
  sim_log_debug(129U, "TossimPacketModelC", "PACKET: Signaling send done at %llu.\n", sim_time());
  TossimPacketModelC$Packet$sendDone(rval, TossimPacketModelC$running[sim_node()] ? SUCCESS : EOFF);
}

#line 253
static inline void TossimPacketModelC$send_transmit(sim_event_t *evt)
#line 253
{
  sim_time_t duration;
  tossim_metadata_t *metadata = TossimPacketModelC$getMetadata(TossimPacketModelC$sending[sim_node()]);

  duration = 8 * TossimPacketModelC$sendingLength[sim_node()];
  duration /= sim_csma_bits_per_symbol();
  duration += sim_csma_preamble_length();

  if (__nesc_ntoh_uint8(metadata->ack.nxdata)) {
      duration += sim_csma_ack_time();
    }
  duration *= sim_ticks_per_sec() / sim_csma_symbols_per_sec();

  evt->time += duration;
  evt->handle = TossimPacketModelC$send_transmit_done;

  sim_log_debug(127U, "TossimPacketModelC", "PACKET: Broadcasting packet to everyone.\n");
  TossimPacketModelC$GainRadioModel$putOnAirTo(TossimPacketModelC$destNode[sim_node()], TossimPacketModelC$sending[sim_node()], __nesc_ntoh_uint8(metadata->ack.nxdata), evt->time, 0.0, 0.0);
  __nesc_hton_uint8(metadata->ack.nxdata, 0);

  evt->time += sim_csma_rxtx_delay() * (sim_ticks_per_sec() / sim_csma_symbols_per_sec());

  sim_log_debug(128U, "TossimPacketModelC", "PACKET: Send done at %llu.\n", evt->time);

  sim_queue_insert(evt);
}

# 459 "/opt/tinyos-2.1.2/tos/lib/tossim/CpmModelC.nc"
static inline void CpmModelC$Model$setPendingTransmission(void )
#line 459
{
  CpmModelC$transmitting[sim_node()] = TRUE;
  sim_log_debug(156U, "CpmModelC", "setPendingTransmission: transmitting %i @ %s\n", CpmModelC$transmitting[sim_node()], sim_time_string());
}

# 57 "/opt/tinyos-2.1.2/tos/lib/tossim/GainRadioModel.nc"
inline static void TossimPacketModelC$GainRadioModel$setPendingTransmission(void ){
#line 57
  CpmModelC$Model$setPendingTransmission();
#line 57
}
#line 57
# 211 "/opt/tinyos-2.1.2/tos/lib/tossim/CpmModelC.nc"
static inline bool CpmModelC$Model$clearChannel(void )
#line 211
{
  sim_log_debug(135U, "CpmModelC", "Checking clear channel @ %s: %f <= %f \n", sim_time_string(), (double )CpmModelC$packetNoise((void *)0), CpmModelC$clearThreshold[sim_node()]);
  return CpmModelC$packetNoise((void *)0) < CpmModelC$clearThreshold[sim_node()];
}

# 56 "/opt/tinyos-2.1.2/tos/lib/tossim/GainRadioModel.nc"
inline static bool TossimPacketModelC$GainRadioModel$clearChannel(void ){
#line 56
  unsigned char __nesc_result;
#line 56

#line 56
  __nesc_result = CpmModelC$Model$clearChannel();
#line 56

#line 56
  return __nesc_result;
#line 56
}
#line 56
# 211 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimPacketModelC.nc"
static inline void TossimPacketModelC$send_backoff(sim_event_t *evt)
#line 211
{
  TossimPacketModelC$backoffCount[sim_node()]++;
  if (TossimPacketModelC$GainRadioModel$clearChannel()) {
      TossimPacketModelC$neededFreeSamples[sim_node()]--;
    }
  else {
      TossimPacketModelC$neededFreeSamples[sim_node()] = sim_csma_min_free_samples();
    }
  if (TossimPacketModelC$neededFreeSamples[sim_node()] == 0) {
      sim_time_t delay;

#line 221
      delay = sim_csma_rxtx_delay();
      delay *= sim_ticks_per_sec() / sim_csma_symbols_per_sec();
      evt->time += delay;
      TossimPacketModelC$transmitting[sim_node()] = TRUE;
      TossimPacketModelC$GainRadioModel$setPendingTransmission();
      evt->handle = TossimPacketModelC$send_transmit;
      sim_queue_insert(evt);
    }
  else {
#line 229
    if (sim_csma_max_iterations() == 0 || 
    TossimPacketModelC$backoffCount[sim_node()] <= sim_csma_max_iterations()) {
        sim_time_t backoff = sim_random();
        sim_time_t modulo = sim_csma_high() - sim_csma_low();

#line 233
        modulo *= pow(sim_csma_exponent_base(), TossimPacketModelC$backoffCount[sim_node()]);
        backoff %= modulo;

        backoff += sim_csma_init_low();
        backoff *= sim_ticks_per_sec() / sim_csma_symbols_per_sec();
        evt->time += backoff;
        sim_queue_insert(evt);
      }
    else {
        message_t *rval = TossimPacketModelC$sending[sim_node()];

#line 243
        TossimPacketModelC$sending[sim_node()] = (void *)0;
        sim_log_debug(126U, "TossimPacketModelC", "PACKET: Failed to send packet due to busy channel.\n");
        TossimPacketModelC$Packet$sendDone(rval, EBUSY);
      }
    }
}

#line 187
static inline void TossimPacketModelC$start_csma(void )
#line 187
{
  sim_time_t first_sample;




  sim_time_t backoff = sim_random();

#line 194
  backoff %= sim_csma_init_high() - sim_csma_init_low();
  backoff += sim_csma_init_low();
  backoff *= sim_ticks_per_sec() / sim_csma_symbols_per_sec();
  sim_log_debug(125U, "TossimPacketModelC", "Starting CMSA with %lli.\n", backoff);
  first_sample = sim_time() + backoff;

  TossimPacketModelC$sendEvent[sim_node()].mote = sim_node();
  TossimPacketModelC$sendEvent[sim_node()].time = first_sample;
  TossimPacketModelC$sendEvent[sim_node()].force = 0;
  TossimPacketModelC$sendEvent[sim_node()].cancelled = 0;

  TossimPacketModelC$sendEvent[sim_node()].handle = TossimPacketModelC$send_backoff;
  TossimPacketModelC$sendEvent[sim_node()].cleanup = sim_queue_cleanup_none;
  sim_queue_insert(&TossimPacketModelC$sendEvent[sim_node()]);
}

#line 161
static inline error_t TossimPacketModelC$Packet$send(int dest, message_t *msg, uint8_t len)
#line 161
{
  if (!TossimPacketModelC$initialized[sim_node()]) {
      sim_log_error(123U, "TossimPacketModelC", "TossimPacketModelC: Send.send() called, but not initialized!\n");
      return EOFF;
    }
  if (!TossimPacketModelC$running[sim_node()]) {
      sim_log_error(124U, "TossimPacketModelC", "TossimPacketModelC: Send.send() called, but not running!\n");
      return EOFF;
    }

  if (TossimPacketModelC$sending[sim_node()] != (void *)0) {
      return EBUSY;
    }
  TossimPacketModelC$sendingLength[sim_node()] = len;
  TossimPacketModelC$sending[sim_node()] = msg;
  TossimPacketModelC$destNode[sim_node()] = dest;
  TossimPacketModelC$backoffCount[sim_node()] = 0;
  TossimPacketModelC$neededFreeSamples[sim_node()] = sim_csma_min_free_samples();
  TossimPacketModelC$start_csma();
  return SUCCESS;
}

# 57 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimPacketModel.nc"
inline static error_t TossimActiveMessageC$Model$send(int node, message_t *msg, uint8_t len){
#line 57
  unsigned char __nesc_result;
#line 57

#line 57
  __nesc_result = TossimPacketModelC$Packet$send(node, msg, len);
#line 57

#line 57
  return __nesc_result;
#line 57
}
#line 57
# 90 "/opt/tinyos-2.1.2/tos/lib/tossim/CpmModelC.nc"
static inline double CpmModelC$timeInMs(void )
#line 90
{
  sim_time_t ftime = sim_time();
  int hours;
#line 92
  int minutes;
#line 92
  int seconds;
  sim_time_t secondBillionths;
  int temp_time;
  double ms_time;

  secondBillionths = ftime % sim_ticks_per_sec();
  if (sim_ticks_per_sec() > (sim_time_t )1000000000) {
      secondBillionths /= sim_ticks_per_sec() / (sim_time_t )1000000000;
    }
  else {
      secondBillionths *= (sim_time_t )1000000000 / sim_ticks_per_sec();
    }
  temp_time = (int )(secondBillionths / 10000);

  if (temp_time % 10 >= 5) {
      temp_time += 10 - temp_time % 10;
    }
  else {
      temp_time -= temp_time % 10;
    }
  ms_time = (float )(temp_time / 100.0);

  seconds = (int )(ftime / sim_ticks_per_sec());
  minutes = seconds / 60;
  hours = minutes / 60;
  seconds %= 60;
  minutes %= 60;

  ms_time += (hours * 3600 + minutes * 60 + seconds) * 1000;

  return ms_time;
}

# 65 "/opt/tinyos-2.1.2/tos/system/AMQueueImplP.nc"
static inline void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$nextPacket(void )
#line 65
{
  uint8_t i;

#line 67
  /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current[sim_node()] = (/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current[sim_node()] + 1) % 2;
  for (i = 0; i < 2; i++) {
      if (/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$queue[sim_node()][/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current[sim_node()]].msg == (void *)0 || 
      /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$cancelMask[sim_node()][/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current[sim_node()] / 8] & (1 << /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current[sim_node()] % 8)) 
        {
          /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current[sim_node()] = (/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current[sim_node()] + 1) % 2;
        }
      else {
          break;
        }
    }
  if (i >= 2) {
#line 78
    /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current[sim_node()] = 2;
    }
}

# 78 "/opt/tinyos-2.1.2/tos/interfaces/Packet.nc"
inline static uint8_t /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Packet$payloadLength(message_t * msg){
#line 78
  unsigned char __nesc_result;
#line 78

#line 78
  __nesc_result = TossimActiveMessageC$Packet$payloadLength(msg);
#line 78

#line 78
  return __nesc_result;
#line 78
}
#line 78
# 67 "/opt/tinyos-2.1.2/tos/interfaces/TaskBasic.nc"
inline static error_t /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$errorTask$postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SimSchedulerBasicP$TaskBasic$postTask(/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$errorTask);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
# 101 "../net/net_EER_sim/eer/EerInstrumentationP.nc"
static inline error_t EerInstrumentationP$EerInstrumentation$ctrl_txpkt(void )
#line 101
{
  unsigned short __nesc_temp52;
  unsigned char *__nesc_temp51;

#line 102
  (__nesc_temp51 = EerInstrumentationP$stats[sim_node()].ctrl_ntxpkt.nxdata, __nesc_hton_uint16(__nesc_temp51, (__nesc_temp52 = __nesc_ntoh_uint16(__nesc_temp51)) + 1), __nesc_temp52);
  return SUCCESS;
}

# 42 "../net/net_EER_sim/eer/EerInstrumentation.nc"
inline static error_t /*CtpP.Router*/EerParentSetEngineP$0$EerInstrumentation$ctrl_txpkt(void ){
#line 42
  unsigned char __nesc_result;
#line 42

#line 42
  __nesc_result = EerInstrumentationP$EerInstrumentation$ctrl_txpkt();
#line 42

#line 42
  return __nesc_result;
#line 42
}
#line 42
# 52 "/opt/tinyos-2.1.2/tos/interfaces/Random.nc"
inline static uint16_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$Random$rand16(void ){
#line 52
  unsigned short __nesc_result;
#line 52

#line 52
  __nesc_result = RandomMlcgC$Random$rand16();
#line 52

#line 52
  return __nesc_result;
#line 52
}
#line 52
# 140 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimPacketModelC.nc"
static inline error_t TossimPacketModelC$PacketAcknowledgements$wasAcked(message_t *ack)
#line 140
{
  tossim_metadata_t *meta = TossimPacketModelC$getMetadata(ack);

#line 142
  return __nesc_ntoh_uint8(meta->ack.nxdata);
}

# 85 "/opt/tinyos-2.1.2/tos/interfaces/PacketAcknowledgements.nc"
inline static bool /*CtpP.Forwarder*/CtpForwardingEngineP$0$PacketAcknowledgements$wasAcked(message_t * msg){
#line 85
  unsigned char __nesc_result;
#line 85

#line 85
  __nesc_result = TossimPacketModelC$PacketAcknowledgements$wasAcked(msg);
#line 85

#line 85
  return __nesc_result;
#line 85
}
#line 85
# 574 "../net/net_EER_sim/4bitle/LinkEstimatorP.nc"
static inline error_t LinkEstimatorP$LinkEstimator$txNoAck(am_addr_t neighbor)
#line 574
{
  neighbor_table_entry_t *ne;
  uint8_t nidx = LinkEstimatorP$findIdx(neighbor);

#line 577
  if (nidx == LinkEstimatorP$INVALID_RVAL) {
      return FAIL;
    }

  ne = &LinkEstimatorP$NeighborTable[sim_node()][nidx];
  ne->data_total++;
  if (ne->data_total >= LinkEstimatorP$DLQ_PKT_WINDOW) {
      LinkEstimatorP$updateDETX(ne);
    }
  return SUCCESS;
}

# 66 "../net/net_EER_sim/4bitle/LinkEstimator.nc"
inline static error_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$LinkEstimator$txNoAck(am_addr_t neighbor){
#line 66
  unsigned char __nesc_result;
#line 66

#line 66
  __nesc_result = LinkEstimatorP$LinkEstimator$txNoAck(neighbor);
#line 66

#line 66
  return __nesc_result;
#line 66
}
#line 66
# 121 "../net/net_EER_sim/eer/EerInstrumentationP.nc"
static inline error_t EerInstrumentationP$EerInstrumentation$data_txpkt(void )
#line 121
{
  unsigned short __nesc_temp60;
  unsigned char *__nesc_temp59;

#line 122
  (__nesc_temp59 = EerInstrumentationP$stats[sim_node()].data_ntxpkt.nxdata, __nesc_hton_uint16(__nesc_temp59, (__nesc_temp60 = __nesc_ntoh_uint16(__nesc_temp59)) + 1), __nesc_temp60);
  return SUCCESS;
}

# 46 "../net/net_EER_sim/eer/EerInstrumentation.nc"
inline static error_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$EerInstrumentation$data_txpkt(void ){
#line 46
  unsigned char __nesc_result;
#line 46

#line 46
  __nesc_result = EerInstrumentationP$EerInstrumentation$data_txpkt();
#line 46

#line 46
  return __nesc_result;
#line 46
}
#line 46
# 67 "/opt/tinyos-2.1.2/tos/interfaces/TaskBasic.nc"
inline static error_t /*CtpP.Router*/EerParentSetEngineP$0$updateRouteTask$postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SimSchedulerBasicP$TaskBasic$postTask(/*CtpP.Router*/EerParentSetEngineP$0$updateRouteTask);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
# 717 "../net/net_EER_sim/eer/EerParentSetEngineP.nc"
static inline void /*CtpP.Router*/EerParentSetEngineP$0$CtpInfo$recomputeRoutes(void )
#line 717
{
  /*CtpP.Router*/EerParentSetEngineP$0$updateRouteTask$postTask();
}

# 71 "../net/net_EER_sim/eer/CtpInfo.nc"
inline static void /*CtpP.Forwarder*/CtpForwardingEngineP$0$CtpInfo$recomputeRoutes(void ){
#line 71
  /*CtpP.Router*/EerParentSetEngineP$0$CtpInfo$recomputeRoutes();
#line 71
}
#line 71
# 85 "../net/net_EER_sim/eer/EerHealthP.nc"
static inline error_t EerHealthP$EerHealth$hlth_retx(void )
#line 85
{
  unsigned short __nesc_temp76;
  unsigned char *__nesc_temp75;

#line 86
  (__nesc_temp75 = EerHealthP$hlth[sim_node()].total_retx.nxdata, __nesc_hton_uint16(__nesc_temp75, (__nesc_temp76 = __nesc_ntoh_uint16(__nesc_temp75)) + 1), __nesc_temp76);
  return SUCCESS;
}

# 50 "../net/net_EER_sim/eer/EerHealth.nc"
inline static error_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$EerHealth$hlth_retx(void ){
#line 50
  unsigned char __nesc_result;
#line 50

#line 50
  __nesc_result = EerHealthP$EerHealth$hlth_retx();
#line 50

#line 50
  return __nesc_result;
#line 50
}
#line 50
# 158 "LapTestC.nc"
static inline void LapTestC$DataSend$sendDone(message_t *msg, error_t err)
#line 158
{
  if (err != SUCCESS) {
      sim_log_debug(53U, "Mote", "Mote: sendDone FAIL\n");
    }
  else {
      sim_log_debug(54U, "Mote", "Mote: sendDone SUCCESS\n");
    }
  LapTestC$radioBusy[sim_node()] = FALSE;
}

# 1338 "../net/net_EER_sim/eer/CtpForwardingEngineP.nc"
static inline 
#line 1337
void 
/*CtpP.Forwarder*/CtpForwardingEngineP$0$Send$default$sendDone(uint8_t client, message_t *msg, error_t error)
#line 1338
{
}

# 100 "/opt/tinyos-2.1.2/tos/interfaces/Send.nc"
inline static void /*CtpP.Forwarder*/CtpForwardingEngineP$0$Send$sendDone(uint8_t arg_0x40bc6c58, message_t * msg, error_t error){
#line 100
  switch (arg_0x40bc6c58) {
#line 100
    case 0U:
#line 100
      LapTestC$DataSend$sendDone(msg, error);
#line 100
      break;
#line 100
    default:
#line 100
      /*CtpP.Forwarder*/CtpForwardingEngineP$0$Send$default$sendDone(arg_0x40bc6c58, msg, error);
#line 100
      break;
#line 100
    }
#line 100
}
#line 100
# 54 "../net/net_EER_sim/eer/CtpPacket.nc"
inline static uint8_t /*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$CtpPacket$getThl(message_t *msg){
#line 54
  unsigned char __nesc_result;
#line 54

#line 54
  __nesc_result = /*CtpP.Forwarder*/CtpForwardingEngineP$0$CtpPacket$getThl(msg);
#line 54

#line 54
  return __nesc_result;
#line 54
}
#line 54









inline static uint8_t /*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$CtpPacket$getSequenceNumber(message_t *msg){
#line 63
  unsigned char __nesc_result;
#line 63

#line 63
  __nesc_result = /*CtpP.Forwarder*/CtpForwardingEngineP$0$CtpPacket$getSequenceNumber(msg);
#line 63

#line 63
  return __nesc_result;
#line 63
}
#line 63
#line 60
inline static am_addr_t /*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$CtpPacket$getOrigin(message_t *msg){
#line 60
  unsigned short __nesc_result;
#line 60

#line 60
  __nesc_result = /*CtpP.Forwarder*/CtpForwardingEngineP$0$CtpPacket$getOrigin(msg);
#line 60

#line 60
  return __nesc_result;
#line 60
}
#line 60
# 100 "../net/net_EER_sim/eer/LruCtpMsgCacheP.nc"
static inline void /*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$remove(uint8_t i)
#line 100
{
  uint8_t j;

#line 102
  if (i >= /*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$count[sim_node()]) {
    return;
    }
#line 104
  if (i == 0) {

      /*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$first[sim_node()] = (/*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$first[sim_node()] + 1) % 4;
    }
  else 
#line 107
    {

      for (j = i; j < /*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$count[sim_node()]; j++) {
          memcpy(&/*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$cache[sim_node()][(j + /*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$first[sim_node()]) % 4], &/*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$cache[sim_node()][(j + /*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$first[sim_node()] + 1) % 4], sizeof(/*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$ctp_packet_sig_t ));
        }
    }
  /*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$count[sim_node()]--;
}

static inline void /*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$Cache$insert(message_t *m)
#line 116
{
  uint8_t i;

#line 118
  if (/*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$count[sim_node()] == 4) {





      i = /*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$lookup(m);
      /*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$remove(i % /*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$count[sim_node()]);
    }

  /*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$cache[sim_node()][(/*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$first[sim_node()] + /*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$count[sim_node()]) % 4].origin = /*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$CtpPacket$getOrigin(m);
  /*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$cache[sim_node()][(/*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$first[sim_node()] + /*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$count[sim_node()]) % 4].seqno = /*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$CtpPacket$getSequenceNumber(m);
  /*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$cache[sim_node()][(/*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$first[sim_node()] + /*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$count[sim_node()]) % 4].thl = /*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$CtpPacket$getThl(m);
  /*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$cache[sim_node()][(/*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$first[sim_node()] + /*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$count[sim_node()]) % 4].type = /*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$CtpPacket$getType(m);
  /*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$count[sim_node()]++;
}

# 51 "/opt/tinyos-2.1.2/tos/interfaces/Cache.nc"
inline static void /*CtpP.Forwarder*/CtpForwardingEngineP$0$SentCache$insert(/*CtpP.Forwarder*/CtpForwardingEngineP$0$SentCache$t item){
#line 51
  /*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$Cache$insert(item);
#line 51
}
#line 51
# 557 "../net/net_EER_sim/4bitle/LinkEstimatorP.nc"
static inline error_t LinkEstimatorP$LinkEstimator$txAck(am_addr_t neighbor)
#line 557
{
  neighbor_table_entry_t *ne;
  uint8_t nidx = LinkEstimatorP$findIdx(neighbor);

#line 560
  if (nidx == LinkEstimatorP$INVALID_RVAL) {
      return FAIL;
    }
  ne = &LinkEstimatorP$NeighborTable[sim_node()][nidx];
  ne->data_success++;
  ne->data_total++;
  if (ne->data_total >= LinkEstimatorP$DLQ_PKT_WINDOW) {
      LinkEstimatorP$updateDETX(ne);
    }
  return SUCCESS;
}

# 62 "../net/net_EER_sim/4bitle/LinkEstimator.nc"
inline static error_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$LinkEstimator$txAck(am_addr_t neighbor){
#line 62
  unsigned char __nesc_result;
#line 62

#line 62
  __nesc_result = LinkEstimatorP$LinkEstimator$txAck(neighbor);
#line 62

#line 62
  return __nesc_result;
#line 62
}
#line 62
# 131 "../net/net_EER_sim/eer/EerInstrumentationP.nc"
static inline error_t EerInstrumentationP$EerInstrumentation$data_rxack(void )
#line 131
{
  unsigned short __nesc_temp64;
  unsigned char *__nesc_temp63;

#line 132
  (__nesc_temp63 = EerInstrumentationP$stats[sim_node()].data_nrxacks.nxdata, __nesc_hton_uint16(__nesc_temp63, (__nesc_temp64 = __nesc_ntoh_uint16(__nesc_temp63)) + 1), __nesc_temp64);
  return SUCCESS;
}

# 48 "../net/net_EER_sim/eer/EerInstrumentation.nc"
inline static error_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$EerInstrumentation$data_rxack(void ){
#line 48
  unsigned char __nesc_result;
#line 48

#line 48
  __nesc_result = EerInstrumentationP$EerInstrumentation$data_rxack();
#line 48

#line 48
  return __nesc_result;
#line 48
}
#line 48
# 230 "/opt/tinyos-2.1.2/tos/lib/tossim/CpmModelC.nc"
static inline double CpmModelC$prr_estimate_from_snr(double SNR)
#line 230
{



  double beta1 = 0.9794;
  double beta2 = 2.3851;
  double X = SNR - beta2;
  double PSE = 0.5 * erfc(beta1 * X / sqrt(2));
  double prr_hat = pow(1 - PSE, 23 * 2);

#line 239
  sim_log_debug(136U, "CpmModelC,SNR", "SNR is %lf, PRR is %lf\n", SNR, prr_hat);
  if (prr_hat > 1) {
    prr_hat = 1.1;
    }
  else {
#line 242
    if (prr_hat < 0) {
      prr_hat = -0.1;
      }
    }
#line 245
  return prr_hat;
}

# 127 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimActiveMessageC.nc"
static inline bool TossimActiveMessageC$Model$shouldAck(message_t *msg)
#line 127
{
  tossim_header_t *header = TossimActiveMessageC$getHeader(msg);

#line 129
  if (__nesc_ntoh_uint16(header->dest.nxdata) == TossimActiveMessageC$amAddress()) {
      sim_log_debug(116U, "Acks", "Received packet addressed to me so ack it\n");
      return TRUE;
    }
  return FALSE;
}

# 87 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimPacketModel.nc"
inline static bool TossimPacketModelC$Packet$shouldAck(message_t *msg){
#line 87
  unsigned char __nesc_result;
#line 87

#line 87
  __nesc_result = TossimActiveMessageC$Model$shouldAck(msg);
#line 87

#line 87
  return __nesc_result;
#line 87
}
#line 87
# 296 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimPacketModelC.nc"
static inline void TossimPacketModelC$GainRadioModel$acked(message_t *msg)
#line 296
{
  if (TossimPacketModelC$running[sim_node()]) {
      tossim_metadata_t *metadata = TossimPacketModelC$getMetadata(TossimPacketModelC$sending[sim_node()]);

#line 299
      __nesc_hton_uint8(metadata->ack.nxdata, 1);
      if (msg != TossimPacketModelC$sending[sim_node()]) {
          TossimPacketModelC$error[sim_node()] = 1;
          sim_log_debug(130U, "TossimPacketModelC", "Requested ack for 0x%x, but outgoing packet is 0x%x.\n", msg, TossimPacketModelC$sending[sim_node()]);
        }
    }
}

# 59 "/opt/tinyos-2.1.2/tos/lib/tossim/GainRadioModel.nc"
inline static void CpmModelC$Model$acked(message_t *msg){
#line 59
  TossimPacketModelC$GainRadioModel$acked(msg);
#line 59
}
#line 59
# 151 "/opt/tinyos-2.1.2/tos/lib/tossim/CpmModelC.nc"
static inline double CpmModelC$arr_estimate_from_snr(double SNR)
#line 151
{
  double beta1 = 0.9794;
  double beta2 = 2.3851;
  double X = SNR - beta2;
  double PSE = 0.5 * erfc(beta1 * X / sqrt(2));
  double prr_hat = pow(1 - PSE, 23 * 2);

#line 157
  sim_log_debug(133U, "CpmModelC,SNRLoss", "SNR is %lf, ARR is %lf\n", SNR, prr_hat);
  if (prr_hat > 1) {
    prr_hat = 1.1;
    }
  else {
#line 160
    if (prr_hat < 0) {
      prr_hat = -0.1;
      }
    }
#line 163
  return prr_hat;
}

static inline int CpmModelC$shouldAckReceive(double snr)
#line 166
{
  double prr = CpmModelC$arr_estimate_from_snr(snr);
  double coin = RandomUniform();

#line 169
  if (prr >= 0 && prr <= 1) {
      if (coin < prr) {
        prr = 1.0;
        }
      else {
#line 173
        prr = 0.0;
        }
    }
#line 175
  return (int )prr;
}

static inline void CpmModelC$sim_gain_ack_handle(sim_event_t *evt)
#line 178
{






  if (
#line 184
  CpmModelC$requestAck[sim_node()] && 
  CpmModelC$outgoing[sim_node()] != (void *)0 && 
  sim_mote_is_on(sim_node())) {
      CpmModelC$receive_message_t *rcv = (CpmModelC$receive_message_t *)evt->data;
      double power = rcv->reversePower;
      double noise = CpmModelC$packetNoise(rcv);
      double snr = power - noise;

#line 191
      if (CpmModelC$shouldAckReceive(snr)) {
          CpmModelC$Model$acked(CpmModelC$outgoing[sim_node()]);
        }
    }
  CpmModelC$free_receive_message((CpmModelC$receive_message_t *)evt->data);
}

# 67 "/opt/tinyos-2.1.2/tos/interfaces/TaskBasic.nc"
inline static error_t LapTestC$sendDataMessage$postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SimSchedulerBasicP$TaskBasic$postTask(LapTestC$sendDataMessage);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
# 91 "LapTestC.nc"
static inline void LapTestC$DataTimer$fired(void )
#line 91
{
  LapTestC$rounds[sim_node()]++;
  if (TOS_NODE_ID != SINK_ADDR && !LapTestC$radioBusy[sim_node()]) {
      LapTestC$sendDataMessage$postTask();
    }
}

# 201 "../net/net_EER_sim/eer/EerParentSetEngineP.nc"
static inline void /*CtpP.Router*/EerParentSetEngineP$0$decayInterval(void )
#line 201
{
  /*CtpP.Router*/EerParentSetEngineP$0$currentInterval[sim_node()] *= 2;
  if (/*CtpP.Router*/EerParentSetEngineP$0$currentInterval[sim_node()] > 1843200) {
      /*CtpP.Router*/EerParentSetEngineP$0$currentInterval[sim_node()] = 1843200;
    }
  /*CtpP.Router*/EerParentSetEngineP$0$chooseAdvertiseTime();
}

static inline void /*CtpP.Router*/EerParentSetEngineP$0$remainingInterval(void )
#line 209
{
  uint32_t remaining = /*CtpP.Router*/EerParentSetEngineP$0$currentInterval[sim_node()];

#line 211
  remaining -= /*CtpP.Router*/EerParentSetEngineP$0$t[sim_node()];
  /*CtpP.Router*/EerParentSetEngineP$0$tHasPassed[sim_node()] = TRUE;
  /*CtpP.Router*/EerParentSetEngineP$0$BeaconTimer$startOneShot(remaining);
}

# 67 "/opt/tinyos-2.1.2/tos/interfaces/TaskBasic.nc"
inline static error_t /*CtpP.Router*/EerParentSetEngineP$0$sendBeaconTask$postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SimSchedulerBasicP$TaskBasic$postTask(/*CtpP.Router*/EerParentSetEngineP$0$sendBeaconTask);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
# 585 "../net/net_EER_sim/eer/EerParentSetEngineP.nc"
static inline void /*CtpP.Router*/EerParentSetEngineP$0$BeaconTimer$fired(void )
#line 585
{
  if (/*CtpP.Router*/EerParentSetEngineP$0$radioOn[sim_node()] && /*CtpP.Router*/EerParentSetEngineP$0$running[sim_node()]) {
      if (!/*CtpP.Router*/EerParentSetEngineP$0$tHasPassed[sim_node()]) {
          /*CtpP.Router*/EerParentSetEngineP$0$updateRouteTask$postTask();
          /*CtpP.Router*/EerParentSetEngineP$0$sendBeaconTask$postTask();
          sim_log_debug(295U, "RoutingTimer", "Beacon timer fired at %s\n", sim_time_string());
          /*CtpP.Router*/EerParentSetEngineP$0$remainingInterval();
        }
      else {
          /*CtpP.Router*/EerParentSetEngineP$0$decayInterval();
        }
    }
}

#line 579
static inline void /*CtpP.Router*/EerParentSetEngineP$0$RouteTimer$fired(void )
#line 579
{
  if (/*CtpP.Router*/EerParentSetEngineP$0$radioOn[sim_node()] && /*CtpP.Router*/EerParentSetEngineP$0$running[sim_node()]) {
      /*CtpP.Router*/EerParentSetEngineP$0$updateRouteTask$postTask();
    }
}

# 1235 "../net/net_EER_sim/eer/CtpForwardingEngineP.nc"
static inline void /*CtpP.Forwarder*/CtpForwardingEngineP$0$RetxmitTimer$fired(void )
#line 1235
{
  /*CtpP.Forwarder*/CtpForwardingEngineP$0$clearState(/*CtpP.Forwarder*/CtpForwardingEngineP$0$SENDING);
  sim_log_debug(224U, "FHangBug", "%s posted sendTask.\n", __FUNCTION__);
  /*CtpP.Forwarder*/CtpForwardingEngineP$0$sendTask$postTask();
}

# 204 "/opt/tinyos-2.1.2/tos/lib/timer/VirtualizeTimerC.nc"
static inline void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$default$fired(uint8_t num)
{
}

# 83 "/opt/tinyos-2.1.2/tos/lib/timer/Timer.nc"
inline static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$fired(uint8_t arg_0x40b67c70){
#line 83
  switch (arg_0x40b67c70) {
#line 83
    case 0U:
#line 83
      LapTestC$DataTimer$fired();
#line 83
      break;
#line 83
    case 1U:
#line 83
      /*CtpP.Router*/EerParentSetEngineP$0$BeaconTimer$fired();
#line 83
      break;
#line 83
    case 2U:
#line 83
      /*CtpP.Router*/EerParentSetEngineP$0$RouteTimer$fired();
#line 83
      break;
#line 83
    case 3U:
#line 83
      /*CtpP.Forwarder*/CtpForwardingEngineP$0$RetxmitTimer$fired();
#line 83
      break;
#line 83
    default:
#line 83
      /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$default$fired(arg_0x40b67c70);
#line 83
      break;
#line 83
    }
#line 83
}
#line 83
# 54 "/opt/tinyos-2.1.2/tos/chips/atm128/timer/HplAtm128Compare.nc"
inline static void /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Compare$set(/*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Compare$size_type t){
#line 54
  HplAtm128Timer0AsyncP$Compare$set(t);
#line 54
}
#line 54
# 61 "/opt/tinyos-2.1.2/tos/chips/atm128/timer/HplAtm128Timer.nc"
inline static /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Timer$timer_size /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Timer$get(void ){
#line 61
  unsigned char __nesc_result;
#line 61

#line 61
  __nesc_result = HplAtm128Timer0AsyncP$Timer0$get();
#line 61

#line 61
  return __nesc_result;
#line 61
}
#line 61
# 569 "/opt/tinyos-2.1.2/tos/chips/atm128/timer/sim/HplAtm128Timer0AsyncP.nc"
static inline int HplAtm128Timer0AsyncP$TimerAsync$compareBusy(void )
#line 569
{
  return (* (volatile uint8_t *)&atm128RegFile[sim_node()][0x30] & (1 << OCR0UB)) != 0;
}

# 44 "/opt/tinyos-2.1.2/tos/chips/atm128/timer/HplAtm128TimerAsync.nc"
inline static int /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$TimerAsync$compareBusy(void ){
#line 44
  int __nesc_result;
#line 44

#line 44
  __nesc_result = HplAtm128Timer0AsyncP$TimerAsync$compareBusy();
#line 44

#line 44
  return __nesc_result;
#line 44
}
#line 44
# 74 "/opt/tinyos-2.1.2/tos/chips/atm128/timer/Atm128AlarmAsyncP.nc"
static inline void /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$setOcr0(uint8_t n)
#line 74
{
  while (/*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$TimerAsync$compareBusy()) 
    ;
  if (n == /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Timer$get()) {
    n++;
    }


  if (/*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$base[sim_node()] + n + 1 < /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$base[sim_node()]) {
    n = -/*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$base[sim_node()] - 1;
    }
#line 84
  /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Compare$set(n);
}

# 577 "/opt/tinyos-2.1.2/tos/chips/atm128/timer/sim/HplAtm128Timer0AsyncP.nc"
static inline void HplAtm128Timer0AsyncP$cancel_compare(void )
#line 577
{
  sim_log_debug(193U, "HplAtm128CompareC", "Cancelling compare at 0x%p\n", HplAtm128Timer0AsyncP$compare[sim_node()]);
  if (HplAtm128Timer0AsyncP$compare[sim_node()] != (void *)0) {
      HplAtm128Timer0AsyncP$compare[sim_node()]->cancelled = 1;
      HplAtm128Timer0AsyncP$compare[sim_node()]->cleanup = sim_queue_cleanup_total;
    }
}

#line 116
static inline void HplAtm128Timer0AsyncP$notify_changed(void )
#line 116
{
  uint8_t newScale = HplAtm128Timer0AsyncP$Timer0$getScale();

#line 118
  if (newScale != AVR_CLOCK_OFF && 
  HplAtm128Timer0AsyncP$oldScale[sim_node()] == AVR_CLOCK_OFF) {
      HplAtm128Timer0AsyncP$lastZero[sim_node()] = sim_time();
    }
  HplAtm128Timer0AsyncP$oldScale[sim_node()] = newScale;

  HplAtm128Timer0AsyncP$schedule_new_compare();
}

#line 545
static inline void HplAtm128Timer0AsyncP$cancel_overflow(void )
#line 545
{
  if (HplAtm128Timer0AsyncP$overflow[sim_node()] != (void *)0) {
      HplAtm128Timer0AsyncP$overflow[sim_node()]->cancelled = 1;
      sim_log_debug(192U, "HplAtm128Timer0AsyncP", "Cancelling overflow %p.\n", HplAtm128Timer0AsyncP$overflow[sim_node()]);
      HplAtm128Timer0AsyncP$overflow[sim_node()]->cleanup = sim_queue_cleanup_total;
    }
}

#line 481
static inline void HplAtm128Timer0AsyncP$timer0_overflow_handle(sim_event_t *evt)
#line 481
{
  if (evt->cancelled) {
      return;
    }
  else {
      if ((atm128RegFile[sim_node()][ATM128_TIMSK] & (1 << TOIE0)) != 0) {
          atm128RegFile[sim_node()][ATM128_TIFR] &= ~(1 << TOV0);
          sim_log_debug(189U, "HplAtm128Timer0AsyncP", "Overflow interrupt at %s\n", sim_time_string());
          INTERRUPT_16();
        }
      else {
          sim_log_debug(190U, "HplAtm128Timer0AsyncP", "Setting overflow bit at %s\n", sim_time_string());
          atm128RegFile[sim_node()][ATM128_TIFR] |= 1 << TOV0;
        }
      HplAtm128Timer0AsyncP$configure_overflow(evt);
      sim_queue_insert(evt);
    }
}

static inline sim_event_t *HplAtm128Timer0AsyncP$allocate_overflow(void )
#line 500
{
  sim_event_t *newEvent = sim_queue_allocate_event();

  newEvent->handle = HplAtm128Timer0AsyncP$timer0_overflow_handle;
  newEvent->cleanup = sim_queue_cleanup_none;
  return newEvent;
}

#line 534
static inline void HplAtm128Timer0AsyncP$schedule_new_overflow(void )
#line 534
{
  sim_event_t *newEvent = HplAtm128Timer0AsyncP$allocate_overflow();

#line 536
  HplAtm128Timer0AsyncP$configure_overflow(newEvent);

  if (HplAtm128Timer0AsyncP$overflow[sim_node()] != (void *)0) {
      HplAtm128Timer0AsyncP$cancel_overflow();
    }
  HplAtm128Timer0AsyncP$overflow[sim_node()] = newEvent;
  sim_queue_insert(newEvent);
}

#line 148
static inline sim_time_t HplAtm128Timer0AsyncP$clock_to_sim(sim_time_t t)
#line 148
{
  t *= sim_ticks_per_sec();
  t /= HplAtm128Timer0AsyncP$notify_clockTicksPerSec();
  return t;
}

#line 297
static inline void HplAtm128Timer0AsyncP$Timer0$set(uint8_t newVal)
#line 297
{
  uint8_t curVal = HplAtm128Timer0AsyncP$Timer0$get();

#line 299
  sim_log_debug(182U, "HplAtm128Timer0AsyncP", "HplAtm128Timer0AsyncP: Setting timer: %hhu\n", newVal);
  if (newVal == curVal) {
      return;
    }
  else {
      sim_time_t adjustment = curVal - newVal;

#line 305
      adjustment = adjustment << HplAtm128Timer0AsyncP$shiftFromScale();
      adjustment = HplAtm128Timer0AsyncP$clock_to_sim(adjustment);

      if (newVal < curVal) {
          HplAtm128Timer0AsyncP$lastZero[sim_node()] += adjustment;
        }
      else {
          HplAtm128Timer0AsyncP$lastZero[sim_node()] -= adjustment;
        }

      HplAtm128Timer0AsyncP$schedule_new_overflow();
      HplAtm128Timer0AsyncP$notify_changed();
    }
}

#line 187
static inline void HplAtm128Timer0AsyncP$timer0_compare_handle(sim_event_t *evt)
#line 187
{
  sim_log_debug(172U, "HplAtm128Timer0AsyncP", "Beginning compare 0x%p at %s\n", evt, sim_time_string());
  if (evt->cancelled) {
      return;
    }
  else {
      char timeStr[128];

#line 194
      sim_print_now(timeStr, 128);
      sim_log_debug(173U, "HplAtm128Timer0AsyncP", "Handling compare at 0x%p @ %s\n", evt, sim_time_string());

      if ((atm128RegFile[sim_node()][ATM128_TCCR0] & (1 << WGM01)) != 0 && !((atm128RegFile[sim_node()][ATM128_TCCR0] & (1 << WGM00)) != 0)) {
          sim_log_debug(174U, "HplAtm128Timer0AsyncP", "%s: CTC is set, clear timer.\n", __FUNCTION__);
          HplAtm128Timer0AsyncP$Timer0$set(0);
        }
      else {
          sim_log_debug(175U, "HplAtm128Timer0AsyncP", "%s: TCCR is 0x%hhx, %i, %i\n", __FUNCTION__, * (volatile uint8_t *)&atm128RegFile[sim_node()][0x33], (int )((atm128RegFile[sim_node()][ATM128_TCCR0] & (1 << WGM01)) != 0), (int )((atm128RegFile[sim_node()][ATM128_TCCR0] & (1 << WGM00)) != 0));
        }

      if ((atm128RegFile[sim_node()][ATM128_TIMSK] & (1 << OCIE0)) != 0) {
          sim_log_debug(176U, "HplAtm128Timer0AsyncP", "TIFR is %hhx\n", * (volatile uint8_t *)&atm128RegFile[sim_node()][0x36]);
          atm128RegFile[sim_node()][ATM128_TIFR] &= ~(1 << OCF0);
          sim_log_debug(177U, "HplAtm128Timer0AsyncP", "TIFR is %hhx\n", * (volatile uint8_t *)&atm128RegFile[sim_node()][0x36]);
          sim_log_debug(178U, "HplAtm128Timer0AsyncP", "Compare interrupt @ %s\n", timeStr);
          INTERRUPT_15();
        }
      else {
          atm128RegFile[sim_node()][ATM128_TIFR] |= 1 << OCF0;
        }

      if (! evt->cancelled) {
          HplAtm128Timer0AsyncP$configure_compare(evt);
          sim_queue_insert(evt);
        }
    }
}

static inline sim_event_t *HplAtm128Timer0AsyncP$allocate_compare(void )
#line 223
{
  sim_event_t *newEvent = sim_queue_allocate_event();

#line 225
  sim_log_debug(179U, "HplAtm128Timer0AsyncP", "Allocated compare at 0x%p\n", newEvent);
  newEvent->handle = HplAtm128Timer0AsyncP$timer0_compare_handle;
  newEvent->cleanup = sim_queue_cleanup_none;
  return newEvent;
}

# 230 "/opt/tinyos-2.1.2/tos/chips/atm128/timer/Atm128AlarmAsyncP.nc"
static inline void /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Timer$overflow(void )
#line 230
{
}

# 70 "/opt/tinyos-2.1.2/tos/chips/atm128/timer/HplAtm128Timer.nc"
inline static void HplAtm128Timer0AsyncP$Timer0$overflow(void ){
#line 70
  /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Timer$overflow();
#line 70
}
#line 70
# 58 "/opt/tinyos-2.1.2/tos/lib/timer/CounterToLocalTimeC.nc"
static inline void /*HilTimerMilliC.CounterToLocalTimeC*/CounterToLocalTimeC$0$Counter$overflow(void )
{
}

# 82 "/opt/tinyos-2.1.2/tos/lib/timer/Counter.nc"
inline static void /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Counter$overflow(void ){
#line 82
  /*HilTimerMilliC.CounterToLocalTimeC*/CounterToLocalTimeC$0$Counter$overflow();
#line 82
}
#line 82
# 85 "/opt/tinyos-2.1.2/tos/chips/atm128/sim/atm128hardware.h"
static __inline void __nesc_enable_interrupt()
#line 85
{
  atm128RegFile[sim_node()][* (volatile uint8_t *)&atm128RegFile[sim_node()][0x3F]] |= 1 << 7;
}

# 48 "/opt/tinyos-2.1.2/tos/chips/atm128/timer/HplAtm128Compare.nc"
inline static /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Compare$size_type /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Compare$get(void ){
#line 48
  unsigned char __nesc_result;
#line 48

#line 48
  __nesc_result = HplAtm128Timer0AsyncP$Compare$get();
#line 48

#line 48
  return __nesc_result;
#line 48
}
#line 48
# 149 "/opt/tinyos-2.1.2/tos/chips/atm128/timer/Atm128AlarmAsyncP.nc"
static inline void /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Compare$fired(void )
#line 149
{
  int overflowed;


  /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$base[sim_node()] += /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Compare$get() + 1U;
  overflowed = !/*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$base[sim_node()];
  __nesc_enable_interrupt();
  /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$setInterrupt();
  if (overflowed) {
    /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Counter$overflow();
    }
}

# 58 "/opt/tinyos-2.1.2/tos/chips/atm128/timer/HplAtm128Compare.nc"
inline static void HplAtm128Timer0AsyncP$Compare$fired(void ){
#line 58
  /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Compare$fired();
#line 58
}
#line 58
# 67 "/opt/tinyos-2.1.2/tos/interfaces/TaskBasic.nc"
inline static error_t /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$fired$postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SimSchedulerBasicP$TaskBasic$postTask(/*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$fired);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
# 81 "/opt/tinyos-2.1.2/tos/lib/timer/AlarmToTimerC.nc"
static inline void /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Alarm$fired(void )
{
#line 82
  /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$fired$postTask();
}

# 78 "/opt/tinyos-2.1.2/tos/lib/timer/Alarm.nc"
inline static void /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Alarm$fired(void ){
#line 78
  /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$Alarm$fired();
#line 78
}
#line 78
# 67 "/opt/tinyos-2.1.2/tos/interfaces/TaskBasic.nc"
inline static error_t TossimPacketModelC$startDoneTask$postTask(void ){
#line 67
  unsigned char __nesc_result;
#line 67

#line 67
  __nesc_result = SimSchedulerBasicP$TaskBasic$postTask(TossimPacketModelC$startDoneTask);
#line 67

#line 67
  return __nesc_result;
#line 67
}
#line 67
# 61 "/opt/tinyos-2.1.2/tos/platforms/micaz/MotePlatformP.nc"
static inline error_t MotePlatformP$SubInit$default$init(void )
#line 61
{
  return SUCCESS;
}

# 62 "/opt/tinyos-2.1.2/tos/interfaces/Init.nc"
inline static error_t MotePlatformP$SubInit$init(void ){
#line 62
  unsigned char __nesc_result;
#line 62

#line 62
  __nesc_result = MotePlatformP$SubInit$default$init();
#line 62

#line 62
  return __nesc_result;
#line 62
}
#line 62
# 59 "/opt/tinyos-2.1.2/tos/chips/atm128/pins/sim/HplAtm128GeneralIOPinP.nc"
static __inline void /*HplAtm128GeneralIOC.PortA.Bit4*/HplAtm128GeneralIOPinP$4$IO$clr(void )
#line 59
{
#line 59
  atm128RegFile[sim_node()][27U] &= ~(1 << 4);
}

# 41 "/opt/tinyos-2.1.2/tos/interfaces/GeneralIO.nc"
inline static void MotePlatformP$SerialIdPin$clr(void ){
#line 41
  /*HplAtm128GeneralIOC.PortA.Bit4*/HplAtm128GeneralIOPinP$4$IO$clr();
#line 41
}
#line 41
# 62 "/opt/tinyos-2.1.2/tos/chips/atm128/pins/sim/HplAtm128GeneralIOPinP.nc"
static __inline void /*HplAtm128GeneralIOC.PortA.Bit4*/HplAtm128GeneralIOPinP$4$IO$makeInput(void )
#line 62
{
#line 62
  atm128RegFile[sim_node()][26U] &= ~(1 << 4);
}

# 44 "/opt/tinyos-2.1.2/tos/interfaces/GeneralIO.nc"
inline static void MotePlatformP$SerialIdPin$makeInput(void ){
#line 44
  /*HplAtm128GeneralIOC.PortA.Bit4*/HplAtm128GeneralIOPinP$4$IO$makeInput();
#line 44
}
#line 44
# 49 "/opt/tinyos-2.1.2/tos/platforms/micaz/MotePlatformP.nc"
static inline error_t MotePlatformP$PlatformInit$init(void )
#line 49
{

  * (volatile uint8_t *)&atm128RegFile[sim_node()][0x15] = 0;
  * (volatile uint8_t *)&atm128RegFile[sim_node()][0x14] = 0xff;


  MotePlatformP$SerialIdPin$makeInput();
  MotePlatformP$SerialIdPin$clr();

  return MotePlatformP$SubInit$init();
}

# 55 "/opt/tinyos-2.1.2/tos/chips/atm128/pins/sim/HplAtm128GeneralIOPinP.nc"
static __inline void /*HplAtm128GeneralIOC.PortA.Bit0*/HplAtm128GeneralIOPinP$0$IO$set(void )
#line 55
{
  sim_log_debug(55U, "Pins", "Setting bit %i of port %i.\n", (int )0, (int )27U);
  atm128RegFile[sim_node()][27U] |= 1 << 0;
}

# 40 "/opt/tinyos-2.1.2/tos/interfaces/GeneralIO.nc"
inline static void LedsP$Led2$set(void ){
#line 40
  /*HplAtm128GeneralIOC.PortA.Bit0*/HplAtm128GeneralIOPinP$0$IO$set();
#line 40
}
#line 40
# 55 "/opt/tinyos-2.1.2/tos/chips/atm128/pins/sim/HplAtm128GeneralIOPinP.nc"
static __inline void /*HplAtm128GeneralIOC.PortA.Bit1*/HplAtm128GeneralIOPinP$1$IO$set(void )
#line 55
{
  sim_log_debug(56U, "Pins", "Setting bit %i of port %i.\n", (int )1, (int )27U);
  atm128RegFile[sim_node()][27U] |= 1 << 1;
}

# 40 "/opt/tinyos-2.1.2/tos/interfaces/GeneralIO.nc"
inline static void LedsP$Led1$set(void ){
#line 40
  /*HplAtm128GeneralIOC.PortA.Bit1*/HplAtm128GeneralIOPinP$1$IO$set();
#line 40
}
#line 40
# 55 "/opt/tinyos-2.1.2/tos/chips/atm128/pins/sim/HplAtm128GeneralIOPinP.nc"
static __inline void /*HplAtm128GeneralIOC.PortA.Bit2*/HplAtm128GeneralIOPinP$2$IO$set(void )
#line 55
{
  sim_log_debug(57U, "Pins", "Setting bit %i of port %i.\n", (int )2, (int )27U);
  atm128RegFile[sim_node()][27U] |= 1 << 2;
}

# 40 "/opt/tinyos-2.1.2/tos/interfaces/GeneralIO.nc"
inline static void LedsP$Led0$set(void ){
#line 40
  /*HplAtm128GeneralIOC.PortA.Bit2*/HplAtm128GeneralIOPinP$2$IO$set();
#line 40
}
#line 40
# 63 "/opt/tinyos-2.1.2/tos/chips/atm128/pins/sim/HplAtm128GeneralIOPinP.nc"
static __inline void /*HplAtm128GeneralIOC.PortA.Bit0*/HplAtm128GeneralIOPinP$0$IO$makeOutput(void )
#line 63
{
#line 63
  atm128RegFile[sim_node()][26U] |= 1 << 0;
}

# 46 "/opt/tinyos-2.1.2/tos/interfaces/GeneralIO.nc"
inline static void LedsP$Led2$makeOutput(void ){
#line 46
  /*HplAtm128GeneralIOC.PortA.Bit0*/HplAtm128GeneralIOPinP$0$IO$makeOutput();
#line 46
}
#line 46
# 63 "/opt/tinyos-2.1.2/tos/chips/atm128/pins/sim/HplAtm128GeneralIOPinP.nc"
static __inline void /*HplAtm128GeneralIOC.PortA.Bit1*/HplAtm128GeneralIOPinP$1$IO$makeOutput(void )
#line 63
{
#line 63
  atm128RegFile[sim_node()][26U] |= 1 << 1;
}

# 46 "/opt/tinyos-2.1.2/tos/interfaces/GeneralIO.nc"
inline static void LedsP$Led1$makeOutput(void ){
#line 46
  /*HplAtm128GeneralIOC.PortA.Bit1*/HplAtm128GeneralIOPinP$1$IO$makeOutput();
#line 46
}
#line 46
# 63 "/opt/tinyos-2.1.2/tos/chips/atm128/pins/sim/HplAtm128GeneralIOPinP.nc"
static __inline void /*HplAtm128GeneralIOC.PortA.Bit2*/HplAtm128GeneralIOPinP$2$IO$makeOutput(void )
#line 63
{
#line 63
  atm128RegFile[sim_node()][26U] |= 1 << 2;
}

# 46 "/opt/tinyos-2.1.2/tos/interfaces/GeneralIO.nc"
inline static void LedsP$Led0$makeOutput(void ){
#line 46
  /*HplAtm128GeneralIOC.PortA.Bit2*/HplAtm128GeneralIOPinP$2$IO$makeOutput();
#line 46
}
#line 46
# 56 "/opt/tinyos-2.1.2/tos/system/LedsP.nc"
static inline error_t LedsP$Init$init(void )
#line 56
{
  /* atomic removed: atomic calls only */
#line 57
  {
    sim_log_debug(157U, "Init", "LEDS: initialized.\n");
    LedsP$Led0$makeOutput();
    LedsP$Led1$makeOutput();
    LedsP$Led2$makeOutput();
    LedsP$Led0$set();
    LedsP$Led1$set();
    LedsP$Led2$set();
  }
  return SUCCESS;
}

# 62 "/opt/tinyos-2.1.2/tos/interfaces/Init.nc"
inline static error_t PlatformP$MoteInit$init(void ){
#line 62
  unsigned char __nesc_result;
#line 62

#line 62
  __nesc_result = LedsP$Init$init();
#line 62
  __nesc_result = ecombine(__nesc_result, MotePlatformP$PlatformInit$init());
#line 62

#line 62
  return __nesc_result;
#line 62
}
#line 62
# 21 "/opt/tinyos-2.1.2/tos/platforms/mica/sim/MeasureClockC.nc"
static inline error_t MeasureClockC$Init$init(void )
#line 21
{
  return SUCCESS;
}

# 62 "/opt/tinyos-2.1.2/tos/interfaces/Init.nc"
inline static error_t PlatformP$MeasureClock$init(void ){
#line 62
  unsigned char __nesc_result;
#line 62

#line 62
  __nesc_result = MeasureClockC$Init$init();
#line 62

#line 62
  return __nesc_result;
#line 62
}
#line 62
# 51 "/opt/tinyos-2.1.2/tos/platforms/mica/PlatformP.nc"
static inline error_t PlatformP$Init$init(void )
{
  error_t ok;


  ok = PlatformP$MeasureClock$init();
  ok = ecombine(ok, PlatformP$MoteInit$init());

  return ok;
}

# 62 "/opt/tinyos-2.1.2/tos/interfaces/Init.nc"
inline static error_t SimMainP$PlatformInit$init(void ){
#line 62
  unsigned char __nesc_result;
#line 62

#line 62
  __nesc_result = PlatformP$Init$init();
#line 62

#line 62
  return __nesc_result;
#line 62
}
#line 62
# 65 "/opt/tinyos-2.1.2/tos/interfaces/Scheduler.nc"
inline static bool SimMainP$Scheduler$runNextTask(void ){
#line 65
  unsigned char __nesc_result;
#line 65

#line 65
  __nesc_result = SimSchedulerBasicP$Scheduler$runNextTask();
#line 65

#line 65
  return __nesc_result;
#line 65
}
#line 65
# 86 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimPacketModelC.nc"
static inline error_t TossimPacketModelC$Init$init(void )
#line 86
{
  sim_log_debug(118U, "TossimPacketModelC", "TossimPacketModelC: Init.init() called\n");
  TossimPacketModelC$initialized[sim_node()] = TRUE;



  TossimPacketModelC$sendEvent[sim_node()].cancelled = 1;
  return SUCCESS;
}

# 447 "/opt/tinyos-2.1.2/tos/chips/atm128/timer/sim/HplAtm128Timer0AsyncP.nc"
static inline void HplAtm128Timer0AsyncP$Compare$start(void )
#line 447
{
#line 447
  atm128RegFile[sim_node()][ATM128_TIMSK] |= 1 << OCIE0;
}

# 65 "/opt/tinyos-2.1.2/tos/chips/atm128/timer/HplAtm128Compare.nc"
inline static void /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Compare$start(void ){
#line 65
  HplAtm128Timer0AsyncP$Compare$start();
#line 65
}
#line 65
# 364 "/opt/tinyos-2.1.2/tos/chips/atm128/timer/sim/HplAtm128Timer0AsyncP.nc"
static inline void HplAtm128Timer0AsyncP$Timer0Ctrl$setControl(Atm128TimerControl_t x)
#line 364
{
  sim_log_debug(184U, "HplAtm128Timer0AsyncP", "Setting control to be 0x%hhx\n", x.flat);
  * (volatile uint8_t *)&atm128RegFile[sim_node()][0x33] = x.flat;
}

# 46 "/opt/tinyos-2.1.2/tos/chips/atm128/timer/HplAtm128TimerCtrl8.nc"
inline static void /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$TimerCtrl$setControl(Atm128TimerControl_t control){
#line 46
  HplAtm128Timer0AsyncP$Timer0Ctrl$setControl(control);
#line 46
}
#line 46
# 561 "/opt/tinyos-2.1.2/tos/chips/atm128/timer/sim/HplAtm128Timer0AsyncP.nc"
static inline void HplAtm128Timer0AsyncP$TimerAsync$setTimer0Asynchronous(void )
#line 561
{
  * (volatile uint8_t *)&atm128RegFile[sim_node()][0x30] |= 1 << AS0;
}

# 32 "/opt/tinyos-2.1.2/tos/chips/atm128/timer/HplAtm128TimerAsync.nc"
inline static void /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$TimerAsync$setTimer0Asynchronous(void ){
#line 32
  HplAtm128Timer0AsyncP$TimerAsync$setTimer0Asynchronous();
#line 32
}
#line 32
# 54 "/opt/tinyos-2.1.2/tos/chips/atm128/timer/Atm128AlarmAsyncP.nc"
static inline error_t /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Init$init(void )
#line 54
{
  /* atomic removed: atomic calls only */
  {
    Atm128TimerControl_t x;

    /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$TimerAsync$setTimer0Asynchronous();
    x.flat = 0;
    x.bits.cs = 3;
    x.bits.wgm1 = 1;
    /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$TimerCtrl$setControl(x);
    /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Compare$set(/*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$MAXT);
    /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Compare$start();
  }
  /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$setInterrupt();
  return SUCCESS;
}

# 438 "../net/net_EER_sim/4bitle/LinkEstimatorP.nc"
static inline void LinkEstimatorP$initNeighborTable(void )
#line 438
{
  uint8_t i;

  for (i = 0; i < 14; i++) {
      LinkEstimatorP$NeighborTable[sim_node()][i].flags = 0;
    }
}











static inline error_t LinkEstimatorP$Init$init(void )
#line 456
{
  sim_log_debug(262U, "LI", "Link estimator init\n");
  LinkEstimatorP$initNeighborTable();
  return SUCCESS;
}

# 68 "/opt/tinyos-2.1.2/tos/interfaces/AMPacket.nc"
inline static am_addr_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$AMPacket$address(void ){
#line 68
  unsigned short __nesc_result;
#line 68

#line 68
  __nesc_result = TossimActiveMessageC$AMPacket$address();
#line 68

#line 68
  return __nesc_result;
#line 68
}
#line 68
# 271 "../net/net_EER_sim/eer/CtpForwardingEngineP.nc"
static inline error_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$Init$init(void )
#line 271
{
  int i;

#line 273
  for (i = 0; i < /*CtpP.Forwarder*/CtpForwardingEngineP$0$CLIENT_COUNT; i++) {
      /*CtpP.Forwarder*/CtpForwardingEngineP$0$clientPtrs[sim_node()][i] = /*CtpP.Forwarder*/CtpForwardingEngineP$0$clientEntries[sim_node()] + i;
      sim_log_debug(194U, "Forwarder", "clientPtrs[%hhu] = %p\n", i, /*CtpP.Forwarder*/CtpForwardingEngineP$0$clientPtrs[sim_node()][i]);
    }
  /*CtpP.Forwarder*/CtpForwardingEngineP$0$loopbackMsgPtr[sim_node()] = &/*CtpP.Forwarder*/CtpForwardingEngineP$0$loopbackMsg[sim_node()];
  /*CtpP.Forwarder*/CtpForwardingEngineP$0$lastParent[sim_node()] = /*CtpP.Forwarder*/CtpForwardingEngineP$0$AMPacket$address();
  /*CtpP.Forwarder*/CtpForwardingEngineP$0$seqno[sim_node()] = 0;

  return SUCCESS;
}

# 68 "/opt/tinyos-2.1.2/tos/interfaces/AMPacket.nc"
inline static am_addr_t /*CtpP.Router*/EerParentSetEngineP$0$AMPacket$address(void ){
#line 68
  unsigned short __nesc_result;
#line 68

#line 68
  __nesc_result = TossimActiveMessageC$AMPacket$address();
#line 68

#line 68
  return __nesc_result;
#line 68
}
#line 68
# 854 "../net/net_EER_sim/eer/EerParentSetEngineP.nc"
static inline void /*CtpP.Router*/EerParentSetEngineP$0$routingTableInit(void )
#line 854
{
  /*CtpP.Router*/EerParentSetEngineP$0$routingTableActive[sim_node()] = 0;
}

# 26 "../net/net_EER_sim/eer/TreeRouting.h"
static __inline void routeInfoInit(route_info_t *ri)
#line 26
{
  ri->parent = INVALID_ADDR;
  ri->etx = MAX_METRIC;
  ri->haveHeard = 0;
  ri->congested = FALSE;
}

# 216 "../net/net_EER_sim/eer/EerParentSetEngineP.nc"
static inline error_t /*CtpP.Router*/EerParentSetEngineP$0$Init$init(void )
#line 216
{
  uint8_t maxLength;

  /*CtpP.Router*/EerParentSetEngineP$0$radioOn[sim_node()] = FALSE;
  /*CtpP.Router*/EerParentSetEngineP$0$running[sim_node()] = FALSE;

  /*CtpP.Router*/EerParentSetEngineP$0$state_is_root[sim_node()] = 0;
  routeInfoInit(&/*CtpP.Router*/EerParentSetEngineP$0$routeInfo[sim_node()]);
  /*CtpP.Router*/EerParentSetEngineP$0$routingTableInit();
  /*CtpP.Router*/EerParentSetEngineP$0$my_ll_addr[sim_node()] = /*CtpP.Router*/EerParentSetEngineP$0$AMPacket$address();
  /*CtpP.Router*/EerParentSetEngineP$0$beaconMsg[sim_node()] = /*CtpP.Router*/EerParentSetEngineP$0$BeaconSend$getPayload(&/*CtpP.Router*/EerParentSetEngineP$0$beaconMsgBuffer[sim_node()], 
  /*CtpP.Router*/EerParentSetEngineP$0$BeaconSend$maxPayloadLength());
  maxLength = /*CtpP.Router*/EerParentSetEngineP$0$BeaconSend$maxPayloadLength();
  sim_log_debug(281U, "TreeRoutingCtl", "TreeRouting initialized. (used payload:%d max payload:%d!\n", sizeof /*CtpP.Router*/EerParentSetEngineP$0$beaconMsg[sim_node()], maxLength);


  return SUCCESS;
}

# 65 "/opt/tinyos-2.1.2/tos/system/PoolP.nc"
static inline error_t /*CtpP.MessagePoolP.PoolP*/PoolP$0$Init$init(void )
#line 65
{
  int i;

#line 67
  for (i = 0; i < 7; i++) {
      /*CtpP.MessagePoolP.PoolP*/PoolP$0$queue[sim_node()][i] = &/*CtpP.MessagePoolP.PoolP*/PoolP$0$pool[sim_node()][i];
    }
  /*CtpP.MessagePoolP.PoolP*/PoolP$0$free[sim_node()] = 7;
  /*CtpP.MessagePoolP.PoolP*/PoolP$0$index[sim_node()] = 0;
  return SUCCESS;
}

#line 65
static inline error_t /*CtpP.QEntryPoolP.PoolP*/PoolP$1$Init$init(void )
#line 65
{
  int i;

#line 67
  for (i = 0; i < 7; i++) {
      /*CtpP.QEntryPoolP.PoolP*/PoolP$1$queue[sim_node()][i] = &/*CtpP.QEntryPoolP.PoolP*/PoolP$1$pool[sim_node()][i];
    }
  /*CtpP.QEntryPoolP.PoolP*/PoolP$1$free[sim_node()] = 7;
  /*CtpP.QEntryPoolP.PoolP*/PoolP$1$index[sim_node()] = 0;
  return SUCCESS;
}

# 64 "../net/net_EER_sim/eer/LruCtpMsgCacheP.nc"
static inline error_t /*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$Init$init(void )
#line 64
{
  /*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$first[sim_node()] = 0;
  /*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$count[sim_node()] = 0;
  return SUCCESS;
}

# 55 "/opt/tinyos-2.1.2/tos/system/RandomMlcgC.nc"
static inline error_t RandomMlcgC$Init$init(void )
#line 55
{
  /* atomic removed: atomic calls only */
#line 56
  RandomMlcgC$seed[sim_node()] = (uint32_t )(TOS_NODE_ID + 1);

  return SUCCESS;
}

# 62 "/opt/tinyos-2.1.2/tos/interfaces/Init.nc"
inline static error_t SimMainP$SoftwareInit$init(void ){
#line 62
  unsigned char __nesc_result;
#line 62

#line 62
  __nesc_result = RandomMlcgC$Init$init();
#line 62
  __nesc_result = ecombine(__nesc_result, /*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$Init$init());
#line 62
  __nesc_result = ecombine(__nesc_result, /*CtpP.QEntryPoolP.PoolP*/PoolP$1$Init$init());
#line 62
  __nesc_result = ecombine(__nesc_result, /*CtpP.MessagePoolP.PoolP*/PoolP$0$Init$init());
#line 62
  __nesc_result = ecombine(__nesc_result, /*CtpP.Router*/EerParentSetEngineP$0$Init$init());
#line 62
  __nesc_result = ecombine(__nesc_result, /*CtpP.Forwarder*/CtpForwardingEngineP$0$Init$init());
#line 62
  __nesc_result = ecombine(__nesc_result, LinkEstimatorP$Init$init());
#line 62
  __nesc_result = ecombine(__nesc_result, /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Init$init());
#line 62
  __nesc_result = ecombine(__nesc_result, TossimPacketModelC$Init$init());
#line 62

#line 62
  return __nesc_result;
#line 62
}
#line 62
# 38 "LapTestC.nc"
static inline void LapTestC$Boot$booted(void )
#line 38
{
  LapTestC$RadioControl$start();
  sim_log_debug(46U, "Boot", "Mote Booted!\n");
}

# 60 "/opt/tinyos-2.1.2/tos/interfaces/Boot.nc"
inline static void SimMainP$Boot$booted(void ){
#line 60
  LapTestC$Boot$booted();
#line 60
}
#line 60
# 55 "/opt/tinyos-2.1.2/tos/lib/tossim/SimMoteP.nc"
static inline long long int SimMoteP$SimMote$getEuid(void )
#line 55
{
  return SimMoteP$euid[sim_node()];
}

#line 58
static inline void SimMoteP$SimMote$setEuid(long long int e)
#line 58
{
  SimMoteP$euid[sim_node()] = e;
}







static inline int SimMoteP$SimMote$getVariableInfo(char *name, void **addr, size_t *size)
#line 68
{
  return __nesc_nido_resolve(sim_node(), name, (uintptr_t *)addr, (size_t *)size);
}

#line 85
static inline void SimMoteP$SimMote$turnOff(void )
#line 85
{
  SimMoteP$isOn[sim_node()] = FALSE;
}

#line 157
static inline void SimMoteP$sim_mote_boot_handle(sim_event_t *e)
#line 157
{
  char buf[128];

#line 159
  sim_print_now(buf, 128);

  SimMoteP$bootEvent[sim_node()] = (sim_event_t *)(void *)0;
  sim_log_debug(112U, "SimMoteP", "Turning on mote %i at time %s.\n", (int )sim_node(), buf);
  SimMoteP$SimMote$turnOn();
}

# 46 "/opt/tinyos-2.1.2/tos/lib/tossim/sim_event_queue.c"
  void sim_queue_init()
#line 46
{
  init_heap(&eventHeap);
}

  void sim_queue_insert(sim_event_t *event)
#line 50
{
  sim_log_debug(0U, "Queue", "Inserting 0x%p\n", event);
  heap_insert(&eventHeap, event, event->time);
}

# 246 "/opt/tinyos-2.1.2/tos/lib/tossim/sim_log.c"
static void sim_log_debug(uint16_t id, char *string, const char *format, ...)
#line 246
{
  va_list args;
  int i;

#line 249
  if (outputs[id].files == (void *)0) {
      fillInOutput(id, string);
    }
  for (i = 0; i < outputs[id].num; i++) {
      FILE *file = outputs[id].files[i];

#line 254
      __builtin_va_start(args, format);
      fprintf(file, "DEBUG (%i): ", (int )sim_node());
      vfprintf(file, format, args);
      fflush(file);
    }
}

#line 84
static void fillInOutput(int id, char *name)
#line 84
{
  char *termination = name;
  char *namePos = name;
  int count = 0;
  char *newName = (char *)malloc(strlen(name) + 1);

#line 89
  memset(newName, 0, strlen(name) + 1);

  while (termination != (void *)0) {
      sim_log_channel_t *channel;

      termination = strrchr(namePos, ',');

      if (termination == (void *)0) {
          strcpy(newName, namePos);
        }
      else 
        {
          memcpy(newName, namePos, termination - namePos);
          newName[termination - namePos] = 0;
        }

      channel = hashtable_search(channelTable, newName);
      if (channel != (void *)0) {
          count += channel->numOutputs;
        }

      namePos = termination + 1;
    }

  termination = name;
  namePos = name;


  outputs[id].files = (FILE **)malloc(sizeof(FILE *) * count);
  outputs[id].num = 0;


  while (termination != (void *)0) {
      sim_log_channel_t *channel;

      termination = strrchr(namePos, ',');

      if (termination == (void *)0) {
          strcpy(newName, namePos);
        }
      else 
        {
          memcpy(newName, namePos, termination - namePos);
          newName[termination - namePos] = 0;
        }

      channel = hashtable_search(channelTable, newName);
      if (channel != (void *)0) {
          int i;
#line 137
          int j;

#line 138
          for (i = 0; i < channel->numOutputs; i++) {
              int duplicate = 0;
              int outputCount = outputs[id].num;


              for (j = 0; j < outputCount; j++) {
                  if (fileno(outputs[id].files[j]) == fileno(channel->outputs[i])) {
                      duplicate = 1;
                      j = outputCount;
                    }
                }
              if (!duplicate) {
                  outputs[id].files[outputCount] = channel->outputs[i];
                  outputs[id].num++;
                }
            }
        }
      namePos = termination + 1;
    }
}

# 121 "/opt/tinyos-2.1.2/tos/lib/tossim/sim_tossim.c"
  unsigned long sim_node()
#line 121
{
  return current_node;
}

# 197 "/opt/tinyos-2.1.2/tos/lib/tossim/heap.c"
static void up_heap(heap_t *heap, int findex)
#line 197
{
  int parent_index;

#line 199
  if (findex == 0) {
      return;
    }

  parent_index = (findex - 1) / 2;

  if (((node_t *)heap->data)[parent_index].key > ((node_t *)heap->data)[findex].key) {
      swap(&((node_t *)heap->data)[findex], &((node_t *)heap->data)[parent_index]);
      up_heap(heap, parent_index);
    }
}

#line 158
static void swap(node_t *first, node_t *second)
#line 158
{
  long long int key;
  void *data;

  key = first->key;
  first->key = second->key;
  second->key = key;

  data = first->data;
  first->data = second->data;
  second->data = data;
}

# 55 "/opt/tinyos-2.1.2/tos/lib/tossim/sim_event_queue.c"
  sim_event_t *sim_queue_pop()
#line 55
{
  long long int key;

#line 57
  return (sim_event_t *)heap_pop_min_data(&eventHeap, &key);
}

# 114 "/opt/tinyos-2.1.2/tos/lib/tossim/heap.c"
static void *heap_pop_min_data(heap_t *heap, long long int *key)
#line 114
{
  int last_index = heap->size - 1;
  void *data = ((node_t *)heap->data)[0].data;

#line 117
  if (key != (void *)0) {
      *key = ((node_t *)heap->data)[0].key;
    }
  ((node_t *)heap->data)[0].data = ((node_t *)heap->data)[last_index].data;
  ((node_t *)heap->data)[0].key = ((node_t *)heap->data)[last_index].key;

  heap->size--;

  down_heap(heap, 0);

  return data;
}

#line 171
static void down_heap(heap_t *heap, int findex)
#line 171
{
  int right_index = (findex + 1) * 2;
  int left_index = findex * 2 + 1;

  if (right_index < heap->size) {
      long long int left_key = ((node_t *)heap->data)[left_index].key;
      long long int right_key = ((node_t *)heap->data)[right_index].key;
      int min_key_index = left_key < right_key ? left_index : right_index;

      if (((node_t *)heap->data)[min_key_index].key < ((node_t *)heap->data)[findex].key) {
          swap(&((node_t *)heap->data)[findex], &((node_t *)heap->data)[min_key_index]);
          down_heap(heap, min_key_index);
        }
    }
  else {
#line 185
    if (left_index >= heap->size) {
        return;
      }
    else {
        long long int left_key = ((node_t *)heap->data)[left_index].key;

#line 190
        if (left_key < ((node_t *)heap->data)[findex].key) {
            swap(&((node_t *)heap->data)[findex], &((node_t *)heap->data)[left_index]);
            return;
          }
      }
    }
}

# 60 "/opt/tinyos-2.1.2/tos/lib/tossim/sim_event_queue.c"
  bool sim_queue_is_empty()
#line 60
{
  return heap_is_empty(&eventHeap);
}

  long long int sim_queue_peek_time()
#line 64
{
  if (heap_is_empty(&eventHeap)) {
      return -1;
    }
  else {
      return heap_get_min_key(&eventHeap);
    }
}


  void sim_queue_cleanup_none(sim_event_t *event)
#line 74
{
  sim_log_debug(1U, "Queue", "cleanup_none: 0x%p\n", event);
}


  void sim_queue_cleanup_event(sim_event_t *event)
#line 79
{
  sim_log_debug(2U, "Queue", "cleanup_event: 0x%p\n", event);
  free(event);
}

  void sim_queue_cleanup_data(sim_event_t *event)
#line 84
{
  sim_log_debug(3U, "Queue", "cleanup_data: 0x%p\n", event);
  free(event->data);
  event->data = (void *)0;
}

  void sim_queue_cleanup_total(sim_event_t *event)
#line 90
{
  sim_log_debug(4U, "Queue", "cleanup_total: 0x%p\n", event);
  free(event->data);
  event->data = (void *)0;
  free(event);
}

# 57 "/opt/tinyos-2.1.2/tos/lib/tossim/sim_tossim.c"
  void sim_init()
#line 57
{
  sim_queue_init();
  sim_log_init();
  sim_log_commit_change();
  sim_noise_init();

  {
    struct timeval tv;

#line 65
    gettimeofday(&tv, (void *)0);





    if (tv.tv_usec != 0) {
        sim_random_seed(tv.tv_usec);
      }
    else {
        sim_random_seed(tv.tv_sec);
      }
  }
}

# 234 "/opt/tinyos-2.1.2/tos/lib/tossim/sim_log.c"
static void sim_log_commit_change()
#line 234
{
  int i;

#line 236
  for (i = 0; i < SIM_LOG_OUTPUT_COUNT; i++) {
      if (outputs[i].files != (void *)0) {
          outputs[i].num = 0;
          free(outputs[i].files);
          outputs[i].files = (void *)0;
        }
    }
}

# 67 "/opt/tinyos-2.1.2/tos/lib/tossim/sim_noise.c"
  void sim_noise_init()
{
  int j;



  for (j = 0; j < 1000; j++) {
      noiseData[j].noiseTable = create_hashtable(NOISE_HASHTABLE_SIZE, sim_noise_hash, sim_noise_eq);
      noiseData[j].noiseGenTime = 0;
      noiseData[j].noiseTrace = (char *)malloc(sizeof(char ) * NOISE_MIN_TRACE);
      noiseData[j].noiseTraceLen = NOISE_MIN_TRACE;
      noiseData[j].noiseTraceIndex = 0;
    }
}

# 102 "/opt/tinyos-2.1.2/tos/lib/tossim/sim_tossim.c"
  void sim_random_seed(int seed)
#line 102
{

  if (seed == 0) {
      seed = 1;
    }
  sim_seed = seed;
}

#line 80
  void sim_end()
#line 80
{
  sim_queue_init();
}



  int sim_random()
#line 86
{
  uint32_t mlcg;
#line 87
  uint32_t p;
#line 87
  uint32_t q;
  uint64_t tmpseed;

#line 89
  tmpseed = (uint64_t )33614U * (uint64_t )sim_seed;
  q = tmpseed;
  q = q >> 1;
  p = tmpseed >> 32;
  mlcg = p + q;
  if (mlcg & 0x80000000) {
      mlcg = mlcg & 0x7FFFFFFF;
      mlcg++;
    }
  sim_seed = mlcg;
  return mlcg;
}









  sim_time_t sim_time()
#line 110
{
  return sim_ticks;
}

#line 113
  void sim_set_time(sim_time_t t)
#line 113
{
  sim_ticks = t;
}

  sim_time_t sim_ticks_per_sec()
#line 117
{
  return 10000000000ULL;
}




  void sim_set_node(unsigned long node)
#line 124
{
  current_node = node;
  TOS_NODE_ID = node;
}

  bool sim_run_next_event()
#line 129
{
  bool result = FALSE;

#line 131
  if (!sim_queue_is_empty()) {
      sim_event_t *event = sim_queue_pop();

#line 133
      sim_set_time(event->time);
      sim_set_node(event->mote);



      sim_log_debug(5U, "Tossim", "CORE: popping event 0x%p for %i at %llu with handler %p... ", event, sim_node(), sim_time(), event->handle);
      if ((sim_mote_is_on(event->mote) || event->force) && 
      event->handle != (void *)0) {
          result = TRUE;
          sim_log_debug_clear(6U, "Tossim", " mote is on (or forced event), run it.\n");
          event->handle(event);
        }
      else {
          sim_log_debug_clear(7U, "Tossim", "\n");
        }
      if (event->cleanup != (void *)0) {
          event->cleanup(event);
        }
    }

  return result;
}

# 134 "/opt/tinyos-2.1.2/tos/lib/tossim/SimMoteP.nc"
  bool sim_mote_is_on(int mote)
#line 134
{
  bool result;
  int tmp = sim_node();

#line 137
  sim_set_node(mote);
  result = SimMoteP$SimMote$isOn();
  sim_set_node(tmp);
  return result;
}

# 276 "/opt/tinyos-2.1.2/tos/lib/tossim/sim_log.c"
static void sim_log_debug_clear(uint16_t id, char *string, const char *format, ...)
#line 276
{
  va_list args;
  int i;

#line 279
  if (outputs[id].files == (void *)0) {
      fillInOutput(id, string);
    }
  for (i = 0; i < outputs[id].num; i++) {
      FILE *file = outputs[id].files[i];

#line 284
      __builtin_va_start(args, format);
      vfprintf(file, format, args);
      fflush(file);
    }
}

# 156 "/opt/tinyos-2.1.2/tos/lib/tossim/sim_tossim.c"
  int sim_print_time(char *buf, int len, sim_time_t ftime)
#line 156
{
  int hours;
  int minutes;
  int seconds;
  sim_time_t secondBillionths;

  secondBillionths = ftime % sim_ticks_per_sec();
  if (sim_ticks_per_sec() > (sim_time_t )1000000000) {
      secondBillionths /= sim_ticks_per_sec() / (sim_time_t )1000000000;
    }
  else {
      secondBillionths *= (sim_time_t )1000000000 / sim_ticks_per_sec();
    }

  seconds = (int )(ftime / sim_ticks_per_sec());
  minutes = seconds / 60;
  hours = minutes / 60;
  seconds %= 60;
  minutes %= 60;
  buf[len - 1] = 0;
  return snprintf(buf, len - 1, "%i:%i:%i.%09llu", hours, minutes, seconds, secondBillionths);
}

  int sim_print_now(char *buf, int len)
#line 179
{
  return sim_print_time(buf, len, sim_time());
}


  char *sim_time_string()
#line 184
{
  sim_print_now(simTimeBuf, 128);
  return simTimeBuf;
}

  void sim_add_channel(char *channel, FILE *file)
#line 189
{
  sim_log_add_channel(channel, file);
}

  bool sim_remove_channel(char *channel, FILE *file)
#line 193
{
  return sim_log_remove_channel(channel, file);
}

# 57 "/opt/tinyos-2.1.2/tos/lib/tossim/sim_csma.c"
  int sim_csma_init_high()
#line 57
{
  return csmaInitHigh;
}

#line 60
  int sim_csma_init_low()
#line 60
{
  return csmaInitLow;
}

#line 63
  int sim_csma_high()
#line 63
{
  return csmaHigh;
}

#line 66
  int sim_csma_low()
#line 66
{
  return csmaLow;
}

#line 69
  int sim_csma_symbols_per_sec()
#line 69
{
  return csmaSymbolsPerSec;
}

#line 72
  int sim_csma_bits_per_symbol()
#line 72
{
  return csmaBitsPerSymbol;
}

#line 75
  int sim_csma_preamble_length()
#line 75
{
  return csmaPreambleLength;
}

#line 78
  int sim_csma_exponent_base()
#line 78
{
  return csmaExponentBase;
#line 79
  ;
}

#line 81
  int sim_csma_max_iterations()
#line 81
{
  return csmaMaxIterations;
}

#line 84
  int sim_csma_min_free_samples()
#line 84
{
  return csmaMinFreeSamples;
}

#line 87
  int sim_csma_rxtx_delay()
#line 87
{
  return csmaRxTxDelay;
}

#line 90
  int sim_csma_ack_time()
#line 90
{
  return csmaAckTime;
}



  void sim_csma_set_init_high(int val)
#line 96
{
  csmaInitHigh = val;
}

#line 99
  void sim_csma_set_init_low(int val)
#line 99
{
  csmaInitLow = val;
}

#line 102
  void sim_csma_set_high(int val)
#line 102
{
  csmaHigh = val;
}

#line 105
  void sim_csma_set_low(int val)
#line 105
{
  csmaLow = val;
}

#line 108
  void sim_csma_set_symbols_per_sec(int val)
#line 108
{
  csmaSymbolsPerSec = val;
}

#line 111
  void sim_csma_set_bits_per_symbol(int val)
#line 111
{
  csmaBitsPerSymbol = val;
}

#line 114
  void sim_csma_set_preamble_length(int val)
#line 114
{
  csmaPreambleLength = val;
}

#line 117
  void sim_csma_set_exponent_base(int val)
#line 117
{
  csmaExponentBase = val;
}

#line 120
  void sim_csma_set_max_iterations(int val)
#line 120
{
  csmaMaxIterations = val;
}

#line 123
  void sim_csma_set_min_free_samples(int val)
#line 123
{
  csmaMinFreeSamples = val;
}

#line 126
  void sim_csma_set_rxtx_delay(int val)
#line 126
{
  csmaRxTxDelay = val;
}

#line 129
  void sim_csma_set_ack_time(int val)
#line 129
{
  csmaAckTime = val;
}

# 16 "/opt/tinyos-2.1.2/tos/lib/tossim/sim_gain.c"
  gain_entry_t *sim_gain_first(int src)
#line 16
{
  if (src > 1000) {
      return connectivity[1000];
    }
  return connectivity[src];
}

  gain_entry_t *sim_gain_next(gain_entry_t *currentLink)
#line 23
{
  return currentLink->next;
}

  void sim_gain_add(int src, int dest, double gain)
#line 27
{
  gain_entry_t *current;
  int temp = sim_node();

#line 30
  if (src > 1000) {
      src = 1000;
    }
  sim_set_node(src);

  current = sim_gain_first(src);
  while (current != (void *)0) {
      if (current->mote == dest) {
          sim_set_node(temp);
          break;
        }
      current = current->next;
    }

  if (current == (void *)0) {
      current = sim_gain_allocate_link(dest);
      current->next = connectivity[src];
      connectivity[src] = current;
    }
  current->mote = dest;
  current->gain = gain;
  sim_log_debug(8U, "Gain", "Adding link from %i to %i with gain %f\n", src, dest, gain);
  sim_set_node(temp);
}

  double sim_gain_value(int src, int dest)
#line 55
{
  gain_entry_t *current;
  int temp = sim_node();

#line 58
  sim_set_node(src);
  current = sim_gain_first(src);
  while (current != (void *)0) {
      if (current->mote == dest) {
          sim_set_node(temp);
          sim_log_debug(9U, "Gain", "Getting link from %i to %i with gain %f\n", src, dest, current->gain);
          return current->gain;
        }
      current = current->next;
    }
  sim_set_node(temp);
  sim_log_debug(10U, "Gain", "Getting default link from %i to %i with gain %f\n", src, dest, 1.0);
  return 1.0;
}

  bool sim_gain_connected(int src, int dest)
#line 73
{
  gain_entry_t *current;
  int temp = sim_node();

#line 76
  sim_set_node(src);
  current = sim_gain_first(src);
  while (current != (void *)0) {
      if (current->mote == dest) {
          sim_set_node(temp);
          return TRUE;
        }
      current = current->next;
    }
  sim_set_node(temp);
  return FALSE;
}

  void sim_gain_remove(int src, int dest)
#line 89
{
  gain_entry_t *current;
  gain_entry_t *prevLink;
  int temp = sim_node();

  if (src > 1000) {
      src = 1000;
    }

  sim_set_node(src);

  current = sim_gain_first(src);
  prevLink = (void *)0;

  while (current != (void *)0) {
      gain_entry_t *tmp;

#line 105
      if (current->mote == dest) {
          if (prevLink == (void *)0) {
              connectivity[src] = current->next;
            }
          else {
              prevLink->next = current->next;
            }
          tmp = current->next;
          sim_gain_deallocate_link(current);
          current = tmp;
        }
      else {
          prevLink = current;
          current = current->next;
        }
    }
  sim_set_node(temp);
}

#line 169
  void sim_gain_deallocate_link(gain_entry_t *linkToDelete)
#line 169
{
  free(linkToDelete);
}

#line 124
  void sim_gain_set_noise_floor(int node, double mean, double range)
#line 124
{
  if (node > 1000) {
      node = 1000;
    }
  localNoise[node].mean = mean;
  localNoise[node].range = range;
}

#line 148
  double sim_gain_sample_noise(int node)
#line 148
{
  double val;
#line 149
  double adjust;

#line 150
  if (node > 1000) {
      node = 1000;
    }
  val = localNoise[node].mean;
  adjust = sim_random() % 2000000;
  adjust /= 1000000.0;
  adjust -= 1.0;
  adjust *= localNoise[node].range;
  return val + adjust;
}

#line 173
  void sim_gain_set_sensitivity(double s)
#line 173
{
  sensitivity = s;
}

  double sim_gain_sensitivity()
#line 177
{
  return sensitivity;
}

# 84 "/opt/tinyos-2.1.2/tos/lib/tossim/sim_noise.c"
  void sim_noise_create_model(uint16_t node_id)
#line 84
{
  makeNoiseModel(node_id);
  makePmfDistr(node_id);
}

#line 419
  void makeNoiseModel(uint16_t node_id)
#line 419
{
  int i;

#line 421
  for (i = 0; i < NOISE_HISTORY; i++) {
      noiseData[node_id].key[i] = search_bin_num(noiseData[node_id].noiseTrace[i]);
      sim_log_debug(44U, "Insert", "Setting history %i to be %i\n", (int )i, (int )noiseData[node_id].key[i]);
    }




  for (i = NOISE_HISTORY; i < noiseData[node_id].noiseTraceIndex; i++) {
      sim_noise_add(node_id, noiseData[node_id].noiseTrace[i]);
      arrangeKey(node_id);
      noiseData[node_id].key[NOISE_HISTORY - 1] = search_bin_num(noiseData[node_id].noiseTrace[i]);
    }
  noiseData[node_id].generated = 1;
}

#line 113
  uint8_t search_bin_num(char noise)
{
  uint8_t bin;

#line 116
  if (noise > NOISE_MAX || noise < NOISE_MIN) {
      noise = NOISE_MIN;
    }
  bin = (noise - NOISE_MIN) / NOISE_QUANTIZE_INTERVAL + 1;
  return bin;
}

#line 144
  void sim_noise_add(uint16_t node_id, char noise)
{
  int i;
  struct hashtable *pnoiseTable = noiseData[node_id].noiseTable;
  char *key = noiseData[node_id].key;
  sim_noise_hash_t *noise_hash;

#line 150
  noise_hash = (sim_noise_hash_t *)hashtable_search(pnoiseTable, key);
  sim_log_debug(13U, "Insert", "Adding noise value %hhi\n", noise);
  if (noise_hash == (void *)0) {
      noise_hash = (sim_noise_hash_t *)malloc(sizeof(sim_noise_hash_t ));
      memcpy((void *)noise_hash->key, (void *)key, NOISE_HISTORY);

      noise_hash->numElements = 0;
      noise_hash->size = NOISE_DEFAULT_ELEMENT_SIZE;
      noise_hash->elements = (char *)malloc(sizeof(char ) * noise_hash->size);
      memset((void *)noise_hash->elements, 0, sizeof(char ) * noise_hash->size);

      noise_hash->flag = 0;
      for (i = 0; i < NOISE_NUM_VALUES; i++) {
          noise_hash->dist[i] = 0;
        }
      hashtable_insert(pnoiseTable, key, noise_hash);
      sim_log_debug(14U, "Insert", "Inserting %p into table %p with key ", noise_hash, pnoiseTable);
      {
        int ctr;

#line 169
        for (ctr = 0; ctr < NOISE_HISTORY; ctr++) 
          sim_log_debug_clear(15U, "Insert", "%0.3hhi ", key[ctr]);
      }
      sim_log_debug_clear(16U, "Insert", "\n");
    }

  if (noise_hash->numElements == noise_hash->size) 
    {
      char *newElements;
      int newSize = noise_hash->size * 2;

      newElements = (char *)malloc(sizeof(char ) * newSize);
      memcpy(newElements, noise_hash->elements, noise_hash->size);
      free(noise_hash->elements);
      noise_hash->elements = newElements;
      noise_hash->size = newSize;
    }

  noise_hash->elements[noise_hash->numElements] = noise;

  noise_hash->numElements++;
}

#line 245
  void arrangeKey(uint16_t node_id)
{
  char *pKey = noiseData[node_id].key;

#line 248
  memcpy(pKey, pKey + 1, NOISE_HISTORY - 1);
}





  void makePmfDistr(uint16_t node_id)
{
  int i;
  char *pKey = noiseData[node_id].key;
  char *fKey = noiseData[node_id].freqKey;

  FreqKeyNum = 0;
  for (i = 0; i < NOISE_HISTORY; i++) {
      pKey[i] = search_bin_num(noiseData[node_id].noiseTrace[i]);
    }

  for (i = NOISE_HISTORY; i < noiseData[node_id].noiseTraceIndex; i++) {
      if (i == NOISE_HISTORY) {
        }

      sim_noise_dist(node_id);
      arrangeKey(node_id);
      pKey[NOISE_HISTORY - 1] = search_bin_num(noiseData[node_id].noiseTrace[i]);
    }

  sim_log_debug_clear(21U, "HASH", "FreqKey = ");
  for (i = 0; i < NOISE_HISTORY; i++) 
    {
      sim_log_debug_clear(22U, "HASH", "%d,", fKey[i]);
    }
  sim_log_debug_clear(23U, "HASH", "\n");
}

#line 192
  void sim_noise_dist(uint16_t node_id)
{
  int i;
  uint8_t bin;
  float cmf = 0;
  struct hashtable *pnoiseTable = noiseData[node_id].noiseTable;
  char *key = noiseData[node_id].key;
  char *freqKey = noiseData[node_id].freqKey;
  sim_noise_hash_t *noise_hash;

#line 201
  noise_hash = (sim_noise_hash_t *)hashtable_search(pnoiseTable, key);



  if (noise_hash->flag == 1) {
    return;
    }
  for (i = 0; i < NOISE_NUM_VALUES; i++) {
      noise_hash->dist[i] = 0.0;
    }

  for (i = 0; i < noise_hash->numElements; i++) 
    {
      float val;

#line 215
      sim_log_debug(17U, "Noise_output", "Noise is found to be %i\n", noise_hash->elements[i]);
      bin = noise_hash->elements[i] - NOISE_MIN_QUANTIZE;

      val = noise_hash->dist[bin];
      val += (float )1.0;
      noise_hash->dist[bin] = val;
    }

  for (i = 0; i < NOISE_NUM_VALUES; i++) 
    {
      noise_hash->dist[i] = noise_hash->dist[i] / noise_hash->numElements;
      cmf += noise_hash->dist[i];
      noise_hash->dist[i] = cmf;
    }
  noise_hash->flag = 1;


  if (noise_hash->numElements > FreqKeyNum) 
    {
      int j;

#line 235
      FreqKeyNum = noise_hash->numElements;
      memcpy((void *)freqKey, (void *)key, NOISE_HISTORY);
      sim_log_debug(18U, "HashZeroDebug", "Setting most frequent key (%i): ", (int )FreqKeyNum);
      for (j = 0; j < NOISE_HISTORY; j++) {
          sim_log_debug_clear(19U, "HashZeroDebug", "[%hhu] ", key[j]);
        }
      sim_log_debug_clear(20U, "HashZeroDebug", "\n");
    }
}

#line 97
  void sim_noise_trace_add(uint16_t node_id, char noiseVal)
#line 97
{

  if (noiseData[node_id].noiseTraceIndex == 
  noiseData[node_id].noiseTraceLen) {
      char *data = (char *)malloc(sizeof(char ) * noiseData[node_id].noiseTraceLen * 2);

#line 102
      memcpy(data, noiseData[node_id].noiseTrace, noiseData[node_id].noiseTraceLen);
      free(noiseData[node_id].noiseTrace);
      noiseData[node_id].noiseTraceLen *= 2;
      noiseData[node_id].noiseTrace = data;
    }
  noiseData[node_id].noiseTrace[noiseData[node_id].noiseTraceIndex] = noiseVal;
  noiseData[node_id].noiseTraceIndex++;
  sim_log_debug(12U, "Insert", "Adding noise value %i for %i of %i\n", (int )noiseData[node_id].noiseTraceIndex, (int )node_id, (int )noiseVal);
}

#line 123
  char search_noise_from_bin_num(int i)
{
  char noise;

#line 126
  noise = NOISE_MIN + (i - 1) * NOISE_QUANTIZE_INTERVAL;
  return noise;
}

#line 288
  char sim_noise_gen(uint16_t node_id)
{
  int i;
  int noiseIndex = 0;
  char noise;
  struct hashtable *pnoiseTable = noiseData[node_id].noiseTable;
  char *pKey = noiseData[node_id].key;
  char *fKey = noiseData[node_id].freqKey;
  double ranNum = RandomUniform();
  sim_noise_hash_t *noise_hash;

#line 298
  noise_hash = (sim_noise_hash_t *)hashtable_search(pnoiseTable, pKey);

  if (noise_hash == (void *)0) {

      sim_log_debug(24U, "Noise_c", "Did not pattern match");

      sim_noise_alarm();
      noise = 0;
      sim_log_debug_clear(25U, "HASH", "(N)Noise\n");
      sim_log_debug(26U, "HashZeroDebug", "Defaulting to common hash.\n");
      memcpy((void *)pKey, (void *)fKey, NOISE_HISTORY);
      noise_hash = (sim_noise_hash_t *)hashtable_search(pnoiseTable, pKey);
    }

  sim_log_debug_clear(27U, "HASH", "Key = ");
  for (i = 0; i < NOISE_HISTORY; i++) {
      sim_log_debug_clear(28U, "HASH", "%d,", pKey[i]);
    }
  sim_log_debug_clear(29U, "HASH", "\n");

  sim_log_debug(30U, "HASH", "Printing Key\n");
  sim_log_debug(31U, "HASH", "noise_hash->numElements=%d\n", noise_hash->numElements);


  numTotal++;


  if (noise_hash->numElements == 1) {
      noise = noise_hash->elements[0];
      sim_log_debug_clear(32U, "HASH", "(E)Noise = %d\n", noise);

      numCase1++;
      sim_log_debug(33U, "Noise_c", "In case 1: %i of %i\n", numCase1, numTotal);

      sim_log_debug(34U, "NoiseAudit", "Noise: %i\n", noise);
      return noise;
    }


  numCase2++;
  sim_log_debug(35U, "Noise_c", "In case 2: %i of %i\n", numCase2, numTotal);


  for (i = 0; i < NOISE_NUM_VALUES - 1; i++) {
      sim_log_debug(36U, "HASH", "IN:for i=%d\n", i);
      if (i == 0) {
          if (ranNum <= noise_hash->dist[i]) {
              noiseIndex = i;
              sim_log_debug_clear(37U, "HASH", "Selected Bin = %d -> ", i + 1);
              break;
            }
        }
      else {
#line 350
        if (noise_hash->dist[i - 1] < ranNum && 
        ranNum <= noise_hash->dist[i]) {
            noiseIndex = i;
            sim_log_debug_clear(38U, "HASH", "Selected Bin = %d -> ", i + 1);
            break;
          }
        }
    }
#line 357
  sim_log_debug(39U, "HASH", "OUT:for i=%d\n", i);

  noise = NOISE_MIN_QUANTIZE + i;
  sim_log_debug(40U, "NoiseAudit", "Noise: %i\n", noise);
  return noise;
}

# 103 "/opt/tinyos-2.1.2/tos/lib/tossim/randomlib.c"
static double RandomUniform(void )
{
  double uni;
  int seed1;
#line 106
  int seed2;


  if (!test) 
    {



      seed1 = sim_random() % 31329;
      seed2 = sim_random() % 30082;
      RandomInitialise(seed1, seed2);
    }

  uni = randU[i97 - 1] - randU[j97 - 1];
  if (uni <= 0.0) {
    uni++;
    }
#line 122
  randU[i97 - 1] = uni;
  i97--;
  if (i97 == 0) {
    i97 = 97;
    }
#line 126
  j97--;
  if (j97 == 0) {
    j97 = 97;
    }
#line 129
  randC -= randCD;
  if (randC < 0.0) {
    randC += randCM;
    }
#line 132
  uni -= randC;
  if (uni < 0.0) {
    uni++;
    }
  return uni;
}

# 364 "/opt/tinyos-2.1.2/tos/lib/tossim/sim_noise.c"
  char sim_noise_generate(uint16_t node_id, uint32_t cur_t)
#line 364
{
  uint32_t i;
  uint32_t prev_t;
  uint32_t delta_t;
  char *noiseG;
  char noise;

  prev_t = noiseData[node_id].noiseGenTime;

  if (noiseData[node_id].generated == 0) {
      sim_log_error(41U, "TOSSIM", "Tried to generate noise from an uninitialized radio model of node %hu.\n", node_id);
      return 127;
    }

  if (0 <= cur_t && cur_t < NOISE_HISTORY) {
      noiseData[node_id].noiseGenTime = cur_t;
      noiseData[node_id].key[cur_t] = search_bin_num(noiseData[node_id].noiseTrace[cur_t]);
      noiseData[node_id].lastNoiseVal = noiseData[node_id].noiseTrace[cur_t];
      return noiseData[node_id].noiseTrace[cur_t];
    }

  if (prev_t == 0) {
    delta_t = cur_t - (NOISE_HISTORY - 1);
    }
  else {
#line 388
    delta_t = cur_t - prev_t;
    }
  sim_log_debug_clear(42U, "HASH", "delta_t = %d\n", delta_t);

  if (delta_t == 0) {
    noise = noiseData[node_id].lastNoiseVal;
    }
  else 
#line 394
    {
      noiseG = (char *)malloc(sizeof(char ) * delta_t);

      for (i = 0; i < delta_t; i++) {
          noiseG[i] = sim_noise_gen(node_id);
          arrangeKey(node_id);
          noiseData[node_id].key[NOISE_HISTORY - 1] = search_bin_num(noiseG[i]);
        }
      noise = noiseG[delta_t - 1];
      noiseData[node_id].lastNoiseVal = noise;

      free(noiseG);
    }
  noiseData[node_id].noiseGenTime = cur_t;
  if (noise == 0) {
      sim_log_debug(43U, "HashZeroDebug", "Generated noise of zero.\n");
    }

  return noise;
}

# 261 "/opt/tinyos-2.1.2/tos/lib/tossim/sim_log.c"
static void sim_log_error(uint16_t id, char *string, const char *format, ...)
#line 261
{
  va_list args;
  int i;

#line 264
  if (outputs[id].files == (void *)0) {
      fillInOutput(id, string);
    }
  for (i = 0; i < outputs[id].num; i++) {
      FILE *file = outputs[id].files[i];

#line 269
      __builtin_va_start(args, format);
      fprintf(file, "ERROR (%i): ", (int )sim_node());
      vfprintf(file, format, args);
      fflush(file);
    }
}

# 54 "/opt/tinyos-2.1.2/tos/lib/tossim/sim_packet.c"
  void sim_packet_set_source(sim_packet_t *msg, uint16_t src)
#line 54
{
  tossim_header_t *hdr = getHeader((message_t *)msg);

#line 56
  __nesc_hton_uint16(hdr->src.nxdata, src);
}

  uint16_t sim_packet_source(sim_packet_t *msg)
#line 59
{
  tossim_header_t *hdr = getHeader((message_t *)msg);

#line 61
  return __nesc_ntoh_uint16(hdr->src.nxdata);
}

  void sim_packet_set_destination(sim_packet_t *msg, uint16_t dest)
#line 64
{
  tossim_header_t *hdr = getHeader((message_t *)msg);

#line 66
  __nesc_hton_uint16(hdr->dest.nxdata, dest);
}

  uint16_t sim_packet_destination(sim_packet_t *msg)
#line 69
{
  tossim_header_t *hdr = getHeader((message_t *)msg);

#line 71
  return __nesc_ntoh_uint16(hdr->dest.nxdata);
}

  void sim_packet_set_length(sim_packet_t *msg, uint8_t length)
#line 74
{
  tossim_header_t *hdr = getHeader((message_t *)msg);

#line 76
  __nesc_hton_uint8(hdr->length.nxdata, length);
}

#line 78
  uint16_t sim_packet_length(sim_packet_t *msg)
#line 78
{
  tossim_header_t *hdr = getHeader((message_t *)msg);

#line 80
  return __nesc_ntoh_uint8(hdr->length.nxdata);
}

  void sim_packet_set_type(sim_packet_t *msg, uint8_t type)
#line 83
{
  tossim_header_t *hdr = getHeader((message_t *)msg);

#line 85
  __nesc_hton_uint8(hdr->type.nxdata, type);
}

  uint8_t sim_packet_type(sim_packet_t *msg)
#line 88
{
  tossim_header_t *hdr = getHeader((message_t *)msg);

#line 90
  return __nesc_ntoh_uint8(hdr->type.nxdata);
}

  uint8_t *sim_packet_data(sim_packet_t *p)
#line 93
{
  message_t *msg = (message_t *)p;

#line 95
  return (uint8_t *)& msg->data;
}

#line 97
  void sim_packet_set_strength(sim_packet_t *p, uint16_t str)
#line 97
{
  message_t *msg = (message_t *)p;
  tossim_metadata_t *md = (tossim_metadata_t *)& msg->metadata;

#line 100
  __nesc_hton_int8(md->strength.nxdata, str);
}

#line 102
  void sim_packet_deliver(int node, sim_packet_t *msg, sim_time_t t)
#line 102
{
  if (t < sim_time()) {
      t = sim_time();
    }
  sim_log_debug(45U, "Packet", "sim_packet.c: Delivering packet %p to %i at %llu\n", msg, node, t);
  active_message_deliver(node, (message_t *)msg, t);
}

# 254 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimActiveMessageC.nc"
  void active_message_deliver(int node, message_t *msg, sim_time_t t)
#line 254
{
  sim_event_t *evt = TossimActiveMessageC$allocate_deliver_event(node, msg, t);

#line 256
  sim_queue_insert(evt);
}

#line 109
static void TossimActiveMessageC$Model$receive(message_t *msg)
#line 109
{
  uint8_t len;
  void *payload;

  memcpy(TossimActiveMessageC$bufferPointer[sim_node()], msg, sizeof(message_t ));
  len = TossimActiveMessageC$Packet$payloadLength(TossimActiveMessageC$bufferPointer[sim_node()]);
  payload = TossimActiveMessageC$Packet$getPayload(TossimActiveMessageC$bufferPointer[sim_node()], TossimActiveMessageC$Packet$maxPayloadLength());

  if (TossimActiveMessageC$AMPacket$isForMe(msg)) {
      sim_log_debug(114U, "AM", "Received active message (%p) of type %hhu and length %hhu for me @ %s.\n", TossimActiveMessageC$bufferPointer[sim_node()], TossimActiveMessageC$AMPacket$type(TossimActiveMessageC$bufferPointer[sim_node()]), len, sim_time_string());
      TossimActiveMessageC$bufferPointer[sim_node()] = TossimActiveMessageC$Receive$receive(TossimActiveMessageC$AMPacket$type(TossimActiveMessageC$bufferPointer[sim_node()]), TossimActiveMessageC$bufferPointer[sim_node()], payload, len);
    }
  else {
      sim_log_debug(115U, "AM", "Snooped on active message of type %hhu and length %hhu for %hu @ %s.\n", TossimActiveMessageC$AMPacket$type(TossimActiveMessageC$bufferPointer[sim_node()]), len, TossimActiveMessageC$AMPacket$destination(TossimActiveMessageC$bufferPointer[sim_node()]), sim_time_string());
      TossimActiveMessageC$bufferPointer[sim_node()] = TossimActiveMessageC$Snoop$receive(TossimActiveMessageC$AMPacket$type(TossimActiveMessageC$bufferPointer[sim_node()]), TossimActiveMessageC$bufferPointer[sim_node()], payload, len);
    }
}

#line 140
static am_addr_t TossimActiveMessageC$AMPacket$destination(message_t *amsg)
#line 140
{
  tossim_header_t *header = TossimActiveMessageC$getHeader(amsg);

#line 142
  return __nesc_ntoh_uint16(header->dest.nxdata);
}

# 76 "/opt/tinyos-2.1.2/tos/lib/tossim/ActiveMessageAddressC.nc"
static am_addr_t ActiveMessageAddressC$ActiveMessageAddress$amAddress(void )
#line 76
{
  if (!ActiveMessageAddressC$set[sim_node()]) {
      ActiveMessageAddressC$addr[sim_node()] = TOS_NODE_ID;
      ActiveMessageAddressC$set[sim_node()] = TRUE;
    }
  return ActiveMessageAddressC$addr[sim_node()];
}

# 165 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimActiveMessageC.nc"
static am_id_t TossimActiveMessageC$AMPacket$type(message_t *amsg)
#line 165
{
  tossim_header_t *header = TossimActiveMessageC$getHeader(amsg);

#line 167
  return __nesc_ntoh_uint8(header->type.nxdata);
}

# 427 "../net/net_EER_sim/4bitle/LinkEstimatorP.nc"
static void LinkEstimatorP$print_packet(message_t *msg, uint8_t len)
#line 427
{
  uint8_t i;
  uint8_t *b;

  b = (uint8_t *)msg->data;
  for (i = 0; i < len; i++) 
    sim_log_debug_clear(259U, "LI", "%x ", b[i]);
  sim_log_debug_clear(260U, "LI", "\n");
}

# 150 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimActiveMessageC.nc"
static am_addr_t TossimActiveMessageC$AMPacket$source(message_t *amsg)
#line 150
{
  tossim_header_t *header = TossimActiveMessageC$getHeader(amsg);

#line 152
  return __nesc_ntoh_uint16(header->src.nxdata);
}

# 317 "../net/net_EER_sim/4bitle/LinkEstimatorP.nc"
static uint16_t LinkEstimatorP$computeETX(uint8_t q1)
#line 317
{
  uint16_t q;

#line 319
  if (q1 > 0) {
      q = 2500 / q1;
      if (q > 250) {
          q = LinkEstimatorP$VERY_LARGE_ETX_VALUE;
        }
      return q;
    }
  else 
#line 325
    {
      return LinkEstimatorP$VERY_LARGE_ETX_VALUE;
    }
}

#line 193
static uint8_t LinkEstimatorP$findIdx(am_addr_t ll_addr)
#line 193
{
  uint8_t i;

#line 195
  for (i = 0; i < 14; i++) {
      if (LinkEstimatorP$NeighborTable[sim_node()][i].flags & VALID_ENTRY) {
          if (LinkEstimatorP$NeighborTable[sim_node()][i].ll_addr == ll_addr) {
              return i;
            }
        }
    }
  return LinkEstimatorP$INVALID_RVAL;
}

#line 373
static void LinkEstimatorP$updateNeighborEntryIdx(uint8_t idx, uint8_t seq)
#line 373
{
  uint8_t packetGap;

  if (LinkEstimatorP$NeighborTable[sim_node()][idx].flags & INIT_ENTRY) {
      sim_log_debug(256U, "LI", "Init entry update\n");
      LinkEstimatorP$NeighborTable[sim_node()][idx].flags &= ~INIT_ENTRY;
    }

  packetGap = seq - LinkEstimatorP$NeighborTable[sim_node()][idx].lastseq;
  sim_log_debug(257U, "LI", "updateNeighborEntryIdx: prevseq %d, curseq %d, gap %d\n", LinkEstimatorP$NeighborTable[sim_node()][idx].lastseq, seq, packetGap);

  LinkEstimatorP$NeighborTable[sim_node()][idx].lastseq = seq;
  LinkEstimatorP$NeighborTable[sim_node()][idx].rcvcnt++;
  if (packetGap > 0) {
      LinkEstimatorP$NeighborTable[sim_node()][idx].failcnt += packetGap - 1;
    }

  if (packetGap > LinkEstimatorP$MAX_PKT_GAP) {
      LinkEstimatorP$initNeighborIdx(idx, LinkEstimatorP$NeighborTable[sim_node()][idx].ll_addr);
      LinkEstimatorP$NeighborTable[sim_node()][idx].lastseq = seq;
      LinkEstimatorP$NeighborTable[sim_node()][idx].rcvcnt = 1;
    }
  else {
#line 395
    if (
#line 394
    LinkEstimatorP$NeighborTable[sim_node()][idx].rcvcnt + LinkEstimatorP$NeighborTable[sim_node()][idx].failcnt >= LinkEstimatorP$BLQ_PKT_WINDOW
     || packetGap >= LinkEstimatorP$BLQ_PKT_WINDOW) {
        LinkEstimatorP$updateNeighborTableEst(LinkEstimatorP$NeighborTable[sim_node()][idx].ll_addr);
      }
    }
}

#line 180
static void LinkEstimatorP$initNeighborIdx(uint8_t i, am_addr_t ll_addr)
#line 180
{
  neighbor_table_entry_t *ne;

#line 182
  ne = &LinkEstimatorP$NeighborTable[sim_node()][i];
  ne->ll_addr = ll_addr;
  ne->lastseq = 0;
  ne->rcvcnt = 0;
  ne->failcnt = 0;
  ne->flags = INIT_ENTRY | VALID_ENTRY;
  ne->inquality = 0;
  ne->etx = 0;
}

#line 292
static void LinkEstimatorP$updateETX(neighbor_table_entry_t *ne, uint16_t newEst)
#line 292
{
  ne->etx = (LinkEstimatorP$ALPHA * ne->etx + (10 - LinkEstimatorP$ALPHA) * newEst) / 10;
}

#line 206
static uint8_t LinkEstimatorP$findEmptyNeighborIdx(void )
#line 206
{
  uint8_t i;

#line 208
  for (i = 0; i < 14; i++) {
      if (LinkEstimatorP$NeighborTable[sim_node()][i].flags & VALID_ENTRY) {
        }
      else 
#line 210
        {
          return i;
        }
    }
  return LinkEstimatorP$INVALID_RVAL;
}



static uint8_t LinkEstimatorP$findWorstNeighborIdx(uint8_t thresholdETX)
#line 219
{
  uint8_t i;
#line 220
  uint8_t worstNeighborIdx;
  uint16_t worstETX;
#line 221
  uint16_t thisETX;

  worstNeighborIdx = LinkEstimatorP$INVALID_RVAL;
  worstETX = 0;
  for (i = 0; i < 14; i++) {
      if (!(LinkEstimatorP$NeighborTable[sim_node()][i].flags & VALID_ENTRY)) {
          sim_log_debug(248U, "LI", "Invalid so continuing\n");
          continue;
        }
      if (!(LinkEstimatorP$NeighborTable[sim_node()][i].flags & MATURE_ENTRY)) {
          sim_log_debug(249U, "LI", "Not mature, so continuing\n");
          continue;
        }
      if (LinkEstimatorP$NeighborTable[sim_node()][i].flags & PINNED_ENTRY) {
          sim_log_debug(250U, "LI", "Pinned entry, so continuing\n");
          continue;
        }
      thisETX = LinkEstimatorP$NeighborTable[sim_node()][i].etx;
      if (thisETX >= worstETX) {
          worstNeighborIdx = i;
          worstETX = thisETX;
        }
    }
  if (worstETX >= thresholdETX) {
      return worstNeighborIdx;
    }
  else 
#line 246
    {
      return LinkEstimatorP$INVALID_RVAL;
    }
}

# 667 "../net/net_EER_sim/eer/EerParentSetEngineP.nc"
static void /*CtpP.Router*/EerParentSetEngineP$0$LinkEstimator$evicted(am_addr_t neighbor)
#line 667
{
  /*CtpP.Router*/EerParentSetEngineP$0$routingTableEvict(neighbor);
  sim_log_debug(299U, "TreeRouting", "%s\n", __FUNCTION__);

  if (/*CtpP.Router*/EerParentSetEngineP$0$routeInfo[sim_node()].parent == neighbor) {
      routeInfoInit(&/*CtpP.Router*/EerParentSetEngineP$0$routeInfo[sim_node()]);
      /*CtpP.Router*/EerParentSetEngineP$0$justEvicted[sim_node()] = TRUE;
      /*CtpP.Router*/EerParentSetEngineP$0$updateRouteTask$postTask();
    }
}

#line 860
static uint8_t /*CtpP.Router*/EerParentSetEngineP$0$routingTableFind(am_addr_t neighbor)
#line 860
{
  uint8_t i;

#line 862
  if (neighbor == INVALID_ADDR) {
    return /*CtpP.Router*/EerParentSetEngineP$0$routingTableActive[sim_node()];
    }
#line 864
  for (i = 0; i < /*CtpP.Router*/EerParentSetEngineP$0$routingTableActive[sim_node()]; i++) {
      if (/*CtpP.Router*/EerParentSetEngineP$0$routingTable[sim_node()][i].neighbor == neighbor) {
        break;
        }
    }
#line 868
  return i;
}

# 205 "/opt/tinyos-2.1.2/tos/lib/tossim/SimSchedulerBasicP.nc"
static error_t SimSchedulerBasicP$TaskBasic$postTask(uint8_t id)
{
  error_t result;

#line 208
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 208
    {
      result = SimSchedulerBasicP$pushTask(id) ? SUCCESS : EBUSY;
    }
#line 210
    __nesc_atomic_end(__nesc_atomic); }
  if (result == SUCCESS) {
      sim_log_debug(107U, "Scheduler", "Posting task %hhu.\n", id);
      SimSchedulerBasicP$sim_scheduler_submit_event();
    }
  else {
      sim_log_debug(108U, "Scheduler", "Posting task %hhu, but already posted.\n", id);
    }
  return result;
}

#line 77
static void SimSchedulerBasicP$sim_scheduler_submit_event(void )
#line 77
{
  if (SimSchedulerBasicP$sim_scheduler_event_pending[sim_node()] == FALSE) {
      SimSchedulerBasicP$sim_scheduler_event[sim_node()].time = sim_time() + SimSchedulerBasicP$sim_config_task_latency();
      sim_queue_insert(&SimSchedulerBasicP$sim_scheduler_event[sim_node()]);
      SimSchedulerBasicP$sim_scheduler_event_pending[sim_node()] = TRUE;
    }
}

# 774 "../net/net_EER_sim/4bitle/LinkEstimatorP.nc"
static void *LinkEstimatorP$Packet$getPayload(message_t *msg, uint8_t len)
#line 774
{
  void *payload = LinkEstimatorP$SubPacket$getPayload(msg, len + sizeof(linkest_header_t ));

#line 776
  if (payload != (void *)0) {
      payload += sizeof(linkest_header_t );
    }
  return payload;
}

#line 750
static uint8_t LinkEstimatorP$Packet$payloadLength(message_t *msg)
#line 750
{
  linkest_header_t *hdr;

#line 752
  hdr = LinkEstimatorP$getHeader(msg);
  return LinkEstimatorP$SubPacket$payloadLength(msg)
   - sizeof(linkest_header_t )
   - sizeof(linkest_footer_t ) * (NUM_ENTRIES_FLAG & __nesc_ntoh_uint8(hdr->flags.nxdata));
}

# 69 "/opt/tinyos-2.1.2/tos/system/RandomMlcgC.nc"
static uint32_t RandomMlcgC$Random$rand32(void )
#line 69
{
  uint32_t mlcg;
#line 70
  uint32_t p;
#line 70
  uint32_t q;
  uint64_t tmpseed;

#line 72
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
    {
      tmpseed = (uint64_t )33614U * (uint64_t )RandomMlcgC$seed[sim_node()];
      q = tmpseed;
      q = q >> 1;
      p = tmpseed >> 32;
      mlcg = p + q;
      if (mlcg & 0x80000000) {
          mlcg = mlcg & 0x7FFFFFFF;
          mlcg++;
        }
      RandomMlcgC$seed[sim_node()] = mlcg;
    }
#line 84
    __nesc_atomic_end(__nesc_atomic); }
  return mlcg;
}

# 948 "../net/net_EER_sim/eer/EerParentSetEngineP.nc"
static bool /*CtpP.Router*/EerParentSetEngineP$0$CtpRoutingPacket$getOption(message_t *msg, ctp_options_t opt)
#line 948
{
  return (__nesc_ntoh_uint8(/*CtpP.Router*/EerParentSetEngineP$0$getHeader(msg)->options.nxdata) & opt) == opt ? TRUE : FALSE;
}

# 535 "../net/net_EER_sim/4bitle/LinkEstimatorP.nc"
static error_t LinkEstimatorP$LinkEstimator$pinNeighbor(am_addr_t neighbor)
#line 535
{
  uint8_t nidx = LinkEstimatorP$findIdx(neighbor);

#line 537
  if (nidx == LinkEstimatorP$INVALID_RVAL) {
      return FAIL;
    }
  LinkEstimatorP$NeighborTable[sim_node()][nidx].flags |= PINNED_ENTRY;
  return SUCCESS;
}

#line 463
static uint16_t LinkEstimatorP$LinkEstimator$getLinkQuality(am_addr_t neighbor)
#line 463
{
  uint8_t idx;

#line 465
  idx = LinkEstimatorP$findIdx(neighbor);
  if (idx == LinkEstimatorP$INVALID_RVAL) {
      return LinkEstimatorP$VERY_LARGE_ETX_VALUE;
    }
  else 
#line 468
    {
      if (LinkEstimatorP$NeighborTable[sim_node()][idx].flags & MATURE_ENTRY) {
          return LinkEstimatorP$NeighborTable[sim_node()][idx].etx;
        }
      else 
#line 471
        {
          return LinkEstimatorP$VERY_LARGE_ETX_VALUE;
        }
    }
}

# 729 "../net/net_EER_sim/eer/EerParentSetEngineP.nc"
static void /*CtpP.Router*/EerParentSetEngineP$0$CtpInfo$setNeighborCongested(am_addr_t n, bool congested)
#line 729
{
  uint8_t idx;

#line 731
  if (/*CtpP.Router*/EerParentSetEngineP$0$ECNOff[sim_node()]) {
    return;
    }
#line 733
  idx = /*CtpP.Router*/EerParentSetEngineP$0$routingTableFind(n);
  if (idx < /*CtpP.Router*/EerParentSetEngineP$0$routingTableActive[sim_node()]) {
      /*CtpP.Router*/EerParentSetEngineP$0$routingTable[sim_node()][idx].info.congested = congested;
    }
  if (/*CtpP.Router*/EerParentSetEngineP$0$routeInfo[sim_node()].congested && !congested) {
    /*CtpP.Router*/EerParentSetEngineP$0$updateRouteTask$postTask();
    }
  else {
#line 739
    if (/*CtpP.Router*/EerParentSetEngineP$0$routeInfo[sim_node()].parent == n && congested) {
      /*CtpP.Router*/EerParentSetEngineP$0$updateRouteTask$postTask();
      }
    }
}

#line 192
static void /*CtpP.Router*/EerParentSetEngineP$0$resetInterval(void )
#line 192
{
  /*CtpP.Router*/EerParentSetEngineP$0$currentInterval[sim_node()] = 128;
  /*CtpP.Router*/EerParentSetEngineP$0$chooseAdvertiseTime();


  /*CtpP.Router*/EerParentSetEngineP$0$EerInstrumentation$ctrl_tricklereset();
  sim_log_debug(280U, "XY_trickle", "trickle_reset all\n");
}

#line 183
static void /*CtpP.Router*/EerParentSetEngineP$0$chooseAdvertiseTime(void )
#line 183
{
  /*CtpP.Router*/EerParentSetEngineP$0$t[sim_node()] = /*CtpP.Router*/EerParentSetEngineP$0$currentInterval[sim_node()];
  /*CtpP.Router*/EerParentSetEngineP$0$t[sim_node()] /= 2;
  /*CtpP.Router*/EerParentSetEngineP$0$t[sim_node()] += /*CtpP.Router*/EerParentSetEngineP$0$Random$rand32() % /*CtpP.Router*/EerParentSetEngineP$0$t[sim_node()];
  /*CtpP.Router*/EerParentSetEngineP$0$tHasPassed[sim_node()] = FALSE;
  /*CtpP.Router*/EerParentSetEngineP$0$BeaconTimer$stop();
  /*CtpP.Router*/EerParentSetEngineP$0$BeaconTimer$startOneShot(/*CtpP.Router*/EerParentSetEngineP$0$t[sim_node()]);
}

# 144 "/opt/tinyos-2.1.2/tos/lib/timer/VirtualizeTimerC.nc"
static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$startTimer(uint8_t num, uint32_t t0, uint32_t dt, bool isoneshot)
{
  /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer_t *timer = &/*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$m_timers[sim_node()][num];

#line 147
  timer->t0 = t0;
  timer->dt = dt;
  timer->isoneshot = isoneshot;
  timer->isrunning = TRUE;
  /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$updateFromTimer$postTask();
}

# 161 "/opt/tinyos-2.1.2/tos/chips/atm128/timer/Atm128AlarmAsyncP.nc"
static uint32_t /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Counter$get(void )
#line 161
{
  uint32_t now;

  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
    {


      uint8_t now8 = /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Timer$get();

      if (/*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$TimerCtrl$getInterruptFlag().bits.ocf0) {


        now = /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$base[sim_node()] + /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Compare$get() + 1 + /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Timer$get();
        }
      else {

        now = /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$base[sim_node()] + now8;
        }
    }
#line 179
    __nesc_atomic_end(__nesc_atomic); }
#line 179
  return now;
}

# 282 "/opt/tinyos-2.1.2/tos/chips/atm128/timer/sim/HplAtm128Timer0AsyncP.nc"
static uint8_t HplAtm128Timer0AsyncP$Timer0$get(void )
#line 282
{
  uint8_t rval;
  sim_time_t elapsed = sim_time() - HplAtm128Timer0AsyncP$last_zero();

#line 285
  elapsed = HplAtm128Timer0AsyncP$sim_to_clock(elapsed);
  elapsed = elapsed >> HplAtm128Timer0AsyncP$shiftFromScale();
  rval = (uint8_t )(elapsed & 0xff);
  sim_log_debug(181U, "HplAtm128Timer0AsyncP", "HplAtm128Timer0AsyncP: Getting timer: %hhu\n", rval);
  return rval;
}

#line 108
static sim_time_t HplAtm128Timer0AsyncP$last_zero(void )
#line 108
{
  if (HplAtm128Timer0AsyncP$lastZero[sim_node()] == 0) {
      HplAtm128Timer0AsyncP$lastZero[sim_node()] = sim_mote_start_time(sim_node());
    }
  return HplAtm128Timer0AsyncP$lastZero[sim_node()];
}

# 106 "/opt/tinyos-2.1.2/tos/lib/tossim/SimMoteP.nc"
  long long int sim_mote_start_time(int mote)
#line 106
{
  long long int result;
  int tmp = sim_node();

#line 109
  sim_set_node(mote);
  result = SimMoteP$SimMote$getStartTime();
  sim_set_node(tmp);
  return result;
}

# 160 "/opt/tinyos-2.1.2/tos/chips/atm128/timer/sim/HplAtm128Timer0AsyncP.nc"
static uint16_t HplAtm128Timer0AsyncP$shiftFromScale(void )
#line 160
{
  uint8_t scale = HplAtm128Timer0AsyncP$Timer0$getScale();

#line 162
  switch (scale) {
      case 0: 
        return 0;
      case 1: 
        return 0;
      case 2: 
        return 3;
      case 3: 
        return 5;
      case 4: 
        return 6;
      case 5: 
        return 7;
      case 6: 
        return 8;
      case 7: 
        return 10;
      default: 
        return 255;
    }
}

#line 321
static uint8_t HplAtm128Timer0AsyncP$Timer0$getScale(void )
#line 321
{
  return * (volatile uint8_t *)&atm128RegFile[sim_node()][0x33] & 0x7;
}

#line 383
static Atm128_TIFR_t HplAtm128Timer0AsyncP$Timer0Ctrl$getInterruptFlag(void )
#line 383
{
  Atm128_TIFR_t at;

#line 385
  at.flat = * (volatile uint8_t *)&atm128RegFile[sim_node()][0x36];
  return at;
}

#line 457
static uint8_t HplAtm128Timer0AsyncP$Compare$get(void )
#line 457
{
  sim_log_debug(187U, "HplAtm128Timer0AsyncP", "HplAtm128Timer0AsyncP: Getting compare: %hhu\n", * (volatile uint8_t *)&atm128RegFile[sim_node()][0x31]);
  return * (volatile uint8_t *)&atm128RegFile[sim_node()][0x31];
}

# 1292 "../net/net_EER_sim/eer/CtpForwardingEngineP.nc"
static uint8_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$CtpPacket$getThl(message_t *msg)
#line 1292
{
#line 1292
  return __nesc_ntoh_uint8(/*CtpP.Forwarder*/CtpForwardingEngineP$0$getHeader(msg)->thl.nxdata);
}

#line 1282
static uint8_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$CollectionPacket$getSequenceNumber(message_t *msg)
#line 1282
{
#line 1282
  return __nesc_ntoh_uint8(/*CtpP.Forwarder*/CtpForwardingEngineP$0$getHeader(msg)->originSeqNo.nxdata);
}

#line 1280
static am_addr_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$CollectionPacket$getOrigin(message_t *msg)
#line 1280
{
#line 1280
  return __nesc_ntoh_uint16(/*CtpP.Forwarder*/CtpForwardingEngineP$0$getHeader(msg)->origin.nxdata);
}

# 84 "../net/net_EER_sim/eer/LruCtpMsgCacheP.nc"
static uint8_t /*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$lookup(message_t *m)
#line 84
{
  uint8_t i;
  uint8_t idx;

#line 87
  for (i = 0; i < /*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$count[sim_node()]; i++) {
      idx = (i + /*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$first[sim_node()]) % 4;


      if (
#line 89
      /*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$CtpPacket$getOrigin(m) == /*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$cache[sim_node()][idx].origin && 
      /*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$CtpPacket$getSequenceNumber(m) == /*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$cache[sim_node()][idx].seqno && 
      /*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$CtpPacket$getThl(m) == /*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$cache[sim_node()][idx].thl && 
      /*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$CtpPacket$getType(m) == /*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$cache[sim_node()][idx].type) {
          break;
        }
    }
  return i;
}

# 1289 "../net/net_EER_sim/eer/CtpForwardingEngineP.nc"
static am_addr_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$CtpPacket$getOrigin(message_t *msg)
#line 1289
{
#line 1289
  return __nesc_ntoh_uint16(/*CtpP.Forwarder*/CtpForwardingEngineP$0$getHeader(msg)->origin.nxdata);
}

#line 1291
static uint8_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$CtpPacket$getSequenceNumber(message_t *msg)
#line 1291
{
#line 1291
  return __nesc_ntoh_uint8(/*CtpP.Forwarder*/CtpForwardingEngineP$0$getHeader(msg)->originSeqNo.nxdata);
}

# 66 "../net/net_EER_sim/eer/CtpPacket.nc"
static uint8_t /*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$CtpPacket$getType(message_t *msg){
#line 66
  unsigned char __nesc_result;
#line 66

#line 66
  __nesc_result = /*CtpP.Forwarder*/CtpForwardingEngineP$0$CtpPacket$getType(msg);
#line 66

#line 66
  return __nesc_result;
#line 66
}
#line 66
# 121 "LapTestC.nc"
static message_t *LapTestC$DataReceive$receive(message_t *msg, void *payload, uint8_t len)
#line 121
{
  if (len != sizeof(data_msg_t )) {
      sim_log_debug(51U, "Root", "Root: the data msg payload length does not match\n");
    }
  else 
#line 124
    {
      uint16_t source;
      uint8_t hopCounter;
      uint8_t seqno;
      uint16_t child = LapTestC$AMPacket$source(msg);
      data_msg_t *rcm = (data_msg_t *)payload;

      source = LapTestC$CtpPacket$getOrigin(msg);
      seqno = LapTestC$CtpPacket$getSequenceNumber(msg);
      hopCounter = LapTestC$CtpPacket$getThl(msg);

      if (hopCounter > 1 && hopCounter <= MAX_PATH_LEN) {
          __nesc_hton_uint16(rcm->path[hopCounter - 2].nxdata, child);
          __nesc_hton_uint16(rcm->path[hopCounter - 1].nxdata, TOS_NODE_ID);
        }
      else {
#line 138
        if (hopCounter == 1) {
            __nesc_hton_uint16(rcm->path[hopCounter - 1].nxdata, TOS_NODE_ID);
          }
        }


      sim_log_debug(52U, "DATA", "data: %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n", LapTestC$rounds[sim_node()], source, seqno, hopCounter, __nesc_ntoh_uint16(rcm->parent.nxdata), __nesc_ntoh_uint16(rcm->path[1].nxdata), __nesc_ntoh_uint16(rcm->path[2].nxdata), __nesc_ntoh_uint16(rcm->path[3].nxdata), __nesc_ntoh_uint16(rcm->path[4].nxdata), __nesc_ntoh_uint16(rcm->path[5].nxdata), __nesc_ntoh_uint16(rcm->path[6].nxdata), __nesc_ntoh_uint16(rcm->path[7].nxdata), __nesc_ntoh_uint16(rcm->path[8].nxdata), __nesc_ntoh_uint16(rcm->path[9].nxdata), __nesc_ntoh_uint16(rcm->path[10].nxdata), __nesc_ntoh_uint16(rcm->path[11].nxdata), __nesc_ntoh_uint16(rcm->path[12].nxdata), __nesc_ntoh_uint16(rcm->path[13].nxdata), __nesc_ntoh_uint16(rcm->path[14].nxdata), __nesc_ntoh_uint16(rcm->path[15].nxdata), __nesc_ntoh_uint16(rcm->path[16].nxdata), __nesc_ntoh_uint16(rcm->path[17].nxdata), __nesc_ntoh_uint16(rcm->path[18].nxdata), __nesc_ntoh_uint16(rcm->path[19].nxdata), __nesc_ntoh_uint16(rcm->path[20].nxdata), __nesc_ntoh_uint16(rcm->path[21].nxdata), __nesc_ntoh_uint16(rcm->path[22].nxdata), __nesc_ntoh_uint16(rcm->path[23].nxdata), __nesc_ntoh_uint16(rcm->path[24].nxdata), __nesc_ntoh_uint16(rcm->path[25].nxdata), __nesc_ntoh_uint16(rcm->path[26].nxdata), __nesc_ntoh_uint16(rcm->path[27].nxdata), __nesc_ntoh_uint16(rcm->path[28].nxdata), __nesc_ntoh_uint16(rcm->path[29].nxdata), __nesc_ntoh_uint16(rcm->data.nxdata));
    }








  return msg;
}

# 1271 "../net/net_EER_sim/eer/CtpForwardingEngineP.nc"
static void */*CtpP.Forwarder*/CtpForwardingEngineP$0$Packet$getPayload(message_t *msg, uint8_t len)
#line 1271
{
  uint8_t *payload = /*CtpP.Forwarder*/CtpForwardingEngineP$0$SubPacket$getPayload(msg, len + sizeof(ctp_data_header_t ));

#line 1273
  if (payload != (void *)0) {
      payload += sizeof(ctp_data_header_t );
    }
  return payload;
}

# 78 "/opt/tinyos-2.1.2/tos/interfaces/Packet.nc"
static uint8_t /*CtpP.Forwarder*/CtpForwardingEngineP$0$SubPacket$payloadLength(message_t * msg){
#line 78
  unsigned char __nesc_result;
#line 78

#line 78
  __nesc_result = TossimActiveMessageC$Packet$payloadLength(msg);
#line 78

#line 78
  return __nesc_result;
#line 78
}
#line 78
# 97 "/opt/tinyos-2.1.2/tos/system/QueueC.nc"
static error_t /*CtpP.SendQueueP*/QueueC$0$Queue$enqueue(/*CtpP.SendQueueP*/QueueC$0$queue_t newVal)
#line 97
{
  if (/*CtpP.SendQueueP*/QueueC$0$Queue$size() < /*CtpP.SendQueueP*/QueueC$0$Queue$maxSize()) {
      sim_log_debug(239U, "QueueC", "%s: size is %hhu\n", __FUNCTION__, /*CtpP.SendQueueP*/QueueC$0$size[sim_node()]);
      /*CtpP.SendQueueP*/QueueC$0$queue[sim_node()][/*CtpP.SendQueueP*/QueueC$0$tail[sim_node()]] = newVal;
      /*CtpP.SendQueueP*/QueueC$0$tail[sim_node()]++;
      if (/*CtpP.SendQueueP*/QueueC$0$tail[sim_node()] == 8) {
#line 102
        /*CtpP.SendQueueP*/QueueC$0$tail[sim_node()] = 0;
        }
#line 103
      /*CtpP.SendQueueP*/QueueC$0$size[sim_node()]++;
      /*CtpP.SendQueueP*/QueueC$0$printQueue();
      return SUCCESS;
    }
  else {
      return FAIL;
    }
}

#line 69
static void /*CtpP.SendQueueP*/QueueC$0$printQueue(void )
#line 69
{

  int i;
#line 71
  int j;

#line 72
  sim_log_debug(233U, "QueueC", "head <-");
  for (i = /*CtpP.SendQueueP*/QueueC$0$head[sim_node()]; i < /*CtpP.SendQueueP*/QueueC$0$head[sim_node()] + /*CtpP.SendQueueP*/QueueC$0$size[sim_node()]; i++) {
      sim_log_debug_clear(234U, "QueueC", "[");
      for (j = 0; j < sizeof(/*CtpP.SendQueueP*/QueueC$0$queue_t ); j++) {
          uint8_t v = ((uint8_t *)&/*CtpP.SendQueueP*/QueueC$0$queue[sim_node()][i % 8])[j];

#line 77
          sim_log_debug_clear(235U, "QueueC", "%0.2hhx", v);
        }
      sim_log_debug_clear(236U, "QueueC", "] ");
    }
  sim_log_debug_clear(237U, "QueueC", "<- tail\n");
}

# 703 "../net/net_EER_sim/eer/EerParentSetEngineP.nc"
static error_t /*CtpP.Router*/EerParentSetEngineP$0$CtpInfo$getEtx(uint16_t *etx)
#line 703
{
  if (etx == (void *)0) {
    return FAIL;
    }
#line 706
  if (/*CtpP.Router*/EerParentSetEngineP$0$routeInfo[sim_node()].parent == INVALID_ADDR) {
    return FAIL;
    }
#line 708
  if (/*CtpP.Router*/EerParentSetEngineP$0$state_is_root[sim_node()] == 1) {
      *etx = 0;
    }
  else 
#line 710
    {
      *etx = /*CtpP.Router*/EerParentSetEngineP$0$routeInfo[sim_node()].etx + /*CtpP.Router*/EerParentSetEngineP$0$LinkEstimator$getLinkQuality(/*CtpP.Router*/EerParentSetEngineP$0$routeInfo[sim_node()].parent);
    }

  return SUCCESS;
}

# 103 "/opt/tinyos-2.1.2/tos/system/PoolP.nc"
static error_t /*CtpP.MessagePoolP.PoolP*/PoolP$0$Pool$put(/*CtpP.MessagePoolP.PoolP*/PoolP$0$pool_t *newVal)
#line 103
{
  if (/*CtpP.MessagePoolP.PoolP*/PoolP$0$free[sim_node()] >= 7) {
      return FAIL;
    }
  else {
      uint16_t emptyIndex = /*CtpP.MessagePoolP.PoolP*/PoolP$0$index[sim_node()] + /*CtpP.MessagePoolP.PoolP*/PoolP$0$free[sim_node()];

#line 109
      if (emptyIndex >= 7) {
          emptyIndex -= 7;
        }
      /*CtpP.MessagePoolP.PoolP*/PoolP$0$queue[sim_node()][emptyIndex] = newVal;
      /*CtpP.MessagePoolP.PoolP*/PoolP$0$free[sim_node()]++;
      sim_log_debug(228U, "PoolP", "%s size is %i\n", __FUNCTION__, (int )/*CtpP.MessagePoolP.PoolP*/PoolP$0$free[sim_node()]);
      return SUCCESS;
    }
}

#line 103
static error_t /*CtpP.QEntryPoolP.PoolP*/PoolP$1$Pool$put(/*CtpP.QEntryPoolP.PoolP*/PoolP$1$pool_t *newVal)
#line 103
{
  if (/*CtpP.QEntryPoolP.PoolP*/PoolP$1$free[sim_node()] >= 7) {
      return FAIL;
    }
  else {
      uint16_t emptyIndex = /*CtpP.QEntryPoolP.PoolP*/PoolP$1$index[sim_node()] + /*CtpP.QEntryPoolP.PoolP*/PoolP$1$free[sim_node()];

#line 109
      if (emptyIndex >= 7) {
          emptyIndex -= 7;
        }
      /*CtpP.QEntryPoolP.PoolP*/PoolP$1$queue[sim_node()][emptyIndex] = newVal;
      /*CtpP.QEntryPoolP.PoolP*/PoolP$1$free[sim_node()]++;
      sim_log_debug(232U, "PoolP", "%s size is %i\n", __FUNCTION__, (int )/*CtpP.QEntryPoolP.PoolP*/PoolP$1$free[sim_node()]);
      return SUCCESS;
    }
}

# 1298 "../net/net_EER_sim/eer/CtpForwardingEngineP.nc"
static bool /*CtpP.Forwarder*/CtpForwardingEngineP$0$CtpPacket$option(message_t *msg, ctp_options_t opt)
#line 1298
{
  return (__nesc_ntoh_uint8(/*CtpP.Forwarder*/CtpForwardingEngineP$0$getHeader(msg)->options.nxdata) & opt) == opt ? TRUE : FALSE;
}

# 110 "/opt/tinyos-2.1.2/tos/lib/tossim/sim_packet.c"
  uint8_t sim_packet_max_length(sim_packet_t *msg)
#line 110
{
  return 100;
}

  sim_packet_t *sim_packet_allocate()
#line 114
{
  return (sim_packet_t *)malloc(sizeof(message_t ));
}

  void sim_packet_free(sim_packet_t *p)
#line 118
{
  printf("sim_packet.c: Freeing packet %p\n", p);
  free(p);
}

# 51 "/opt/tinyos-2.1.2/tos/lib/tossim/SimMainP.nc"
  int sim_main_start_mote(void )
#line 51
{
  char timeBuf[128];

#line 53
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
#line 53
    {






      SimMainP$Scheduler$init();





      SimMainP$PlatformInit$init();
      while (SimMainP$Scheduler$runNextTask()) ;





      SimMainP$SoftwareInit$init();
      while (SimMainP$Scheduler$runNextTask()) ;
    }
#line 75
    __nesc_atomic_end(__nesc_atomic); }


  __nesc_enable_interrupt();

  sim_print_now(timeBuf, 128);
  sim_log_debug(103U, "SimMainP", "Mote %li signaling boot at time %s.\n", sim_node(), timeBuf);
  SimMainP$Boot$booted();





  return 0;
}

# 180 "/opt/tinyos-2.1.2/tos/lib/tossim/SimSchedulerBasicP.nc"
static bool SimSchedulerBasicP$Scheduler$runNextTask(void )
{
  uint8_t nextTask;

#line 183
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
    {
      nextTask = SimSchedulerBasicP$popTask();
      if (nextTask == SimSchedulerBasicP$NO_TASK) 
        {
          sim_log_debug(105U, "Scheduler", "Told to run next task, but no task to run.\n");
          {
            unsigned char __nesc_temp = 
#line 189
            FALSE;

            {
#line 189
              __nesc_atomic_end(__nesc_atomic); 
#line 189
              return __nesc_temp;
            }
          }
        }
    }
#line 193
    __nesc_atomic_end(__nesc_atomic); }
#line 192
  sim_log_debug(106U, "Scheduler", "Running task %hhu.\n", nextTask);
  SimSchedulerBasicP$TaskBasic$runTask(nextTask);
  return TRUE;
}

# 63 "../net/net_EER_sim/eer_parentselection/EerParentSelectionP.nc"
static void /*CtpP.ParentSelector*/EerParentSelectionP$0$EerParentSelectionConfig$initializeParentSet(void )
#line 63
{
  __nesc_hton_uint8(/*CtpP.ParentSelector*/EerParentSelectionP$0$prntSet[sim_node()].setSize.nxdata, 0);
  __nesc_hton_uint16(/*CtpP.ParentSelector*/EerParentSelectionP$0$prntSet[sim_node()].maxPathETX.nxdata, 0);
  __nesc_hton_uint16(/*CtpP.ParentSelector*/EerParentSelectionP$0$prntSet[sim_node()].setETX.nxdata, MAX_METRIC);
  __nesc_hton_uint16(/*CtpP.ParentSelector*/EerParentSelectionP$0$prntSet[sim_node()].bestNeighbor.nxdata, INVALID_ADDR);

  if (/*CtpP.ParentSelector*/EerParentSelectionP$0$parent_init_flag[sim_node()] == FALSE) {
      __nesc_hton_uint16(/*CtpP.ParentSelector*/EerParentSelectionP$0$prntSet[sim_node()].previousFwder.nxdata, INVALID_ADDR);
      /*CtpP.ParentSelector*/EerParentSelectionP$0$parent_init_flag[sim_node()] = TRUE;
    }

  /*CtpP.ParentSelector*/EerParentSelectionP$0$rand_prnt[sim_node()] = INVALID_ADDR;
}


static error_t /*CtpP.ParentSelector*/EerParentSelectionP$0$EerParentSelectionConfig$addParentCandidate(routing_table_entry *entry, __nesc_nxbase_nx_uint16_t candPathETX)
{
  unsigned char __nesc_temp50;
  unsigned char *__nesc_temp49;
#line 81
  nx_uint8_t i;

  if (5 > 1) {
      if (__nesc_ntoh_uint8(/*CtpP.ParentSelector*/EerParentSelectionP$0$prntSet[sim_node()].setSize.nxdata) < 5) {

          /*CtpP.ParentSelector*/EerParentSelectionP$0$parentSetTable[sim_node()][__nesc_ntoh_uint8(/*CtpP.ParentSelector*/EerParentSelectionP$0$prntSet[sim_node()].setSize.nxdata)] = entry->neighbor;
          __nesc_hton_uint16(/*CtpP.ParentSelector*/EerParentSelectionP$0$parentSetPathETX[sim_node()][__nesc_ntoh_uint8(/*CtpP.ParentSelector*/EerParentSelectionP$0$prntSet[sim_node()].setSize.nxdata)].nxdata, candPathETX);

          if (candPathETX > __nesc_ntoh_uint16(/*CtpP.ParentSelector*/EerParentSelectionP$0$prntSet[sim_node()].maxPathETX.nxdata)) {
              __nesc_hton_uint16(/*CtpP.ParentSelector*/EerParentSelectionP$0$prntSet[sim_node()].maxPathETX.nxdata, candPathETX);
              __nesc_hton_uint8(/*CtpP.ParentSelector*/EerParentSelectionP$0$prntSet[sim_node()].maxPathETXPos.nxdata, __nesc_ntoh_uint8(/*CtpP.ParentSelector*/EerParentSelectionP$0$prntSet[sim_node()].setSize.nxdata));
            }

          if (candPathETX < __nesc_ntoh_uint16(/*CtpP.ParentSelector*/EerParentSelectionP$0$prntSet[sim_node()].setETX.nxdata)) {
              __nesc_hton_uint16(/*CtpP.ParentSelector*/EerParentSelectionP$0$prntSet[sim_node()].setETX.nxdata, candPathETX);
              __nesc_hton_uint16(/*CtpP.ParentSelector*/EerParentSelectionP$0$prntSet[sim_node()].bestNeighbor.nxdata, entry->neighbor);
            }
          __nesc_hton_uint8(/*CtpP.ParentSelector*/EerParentSelectionP$0$prntSet[sim_node()].setSize.nxdata, __nesc_ntoh_uint8(/*CtpP.ParentSelector*/EerParentSelectionP$0$prntSet[sim_node()].setSize.nxdata) + 1);

          return SUCCESS;
        }
      else {

          if (candPathETX < __nesc_ntoh_uint16(/*CtpP.ParentSelector*/EerParentSelectionP$0$prntSet[sim_node()].maxPathETX.nxdata)) {

              /*CtpP.ParentSelector*/EerParentSelectionP$0$parentSetTable[sim_node()][__nesc_ntoh_uint8(/*CtpP.ParentSelector*/EerParentSelectionP$0$prntSet[sim_node()].maxPathETXPos.nxdata)] = entry->neighbor;
              __nesc_hton_uint16(/*CtpP.ParentSelector*/EerParentSelectionP$0$parentSetPathETX[sim_node()][__nesc_ntoh_uint8(/*CtpP.ParentSelector*/EerParentSelectionP$0$prntSet[sim_node()].maxPathETXPos.nxdata)].nxdata, candPathETX);


              __nesc_hton_uint16(/*CtpP.ParentSelector*/EerParentSelectionP$0$prntSet[sim_node()].maxPathETX.nxdata, 0);
              __nesc_hton_uint16(/*CtpP.ParentSelector*/EerParentSelectionP$0$prntSet[sim_node()].setETX.nxdata, MAX_METRIC);
              for (__nesc_hton_uint8(i.nxdata, 0); __nesc_ntoh_uint8(i.nxdata) < __nesc_ntoh_uint8(/*CtpP.ParentSelector*/EerParentSelectionP$0$prntSet[sim_node()].setSize.nxdata); (__nesc_temp49 = i.nxdata, __nesc_hton_uint8(__nesc_temp49, (__nesc_temp50 = __nesc_ntoh_uint8(__nesc_temp49)) + 1), __nesc_temp50)) {

                  if (__nesc_ntoh_uint16(/*CtpP.ParentSelector*/EerParentSelectionP$0$parentSetPathETX[sim_node()][__nesc_ntoh_uint8(i.nxdata)].nxdata) > __nesc_ntoh_uint16(/*CtpP.ParentSelector*/EerParentSelectionP$0$prntSet[sim_node()].maxPathETX.nxdata)) {
                      __nesc_hton_uint16(/*CtpP.ParentSelector*/EerParentSelectionP$0$prntSet[sim_node()].maxPathETX.nxdata, __nesc_ntoh_uint16(/*CtpP.ParentSelector*/EerParentSelectionP$0$parentSetPathETX[sim_node()][__nesc_ntoh_uint8(i.nxdata)].nxdata));
                      __nesc_hton_uint8(/*CtpP.ParentSelector*/EerParentSelectionP$0$prntSet[sim_node()].maxPathETXPos.nxdata, __nesc_ntoh_uint8(i.nxdata));
                    }
                  if (__nesc_ntoh_uint16(/*CtpP.ParentSelector*/EerParentSelectionP$0$parentSetPathETX[sim_node()][__nesc_ntoh_uint8(i.nxdata)].nxdata) < __nesc_ntoh_uint16(/*CtpP.ParentSelector*/EerParentSelectionP$0$prntSet[sim_node()].setETX.nxdata)) {

                      __nesc_hton_uint16(/*CtpP.ParentSelector*/EerParentSelectionP$0$prntSet[sim_node()].setETX.nxdata, __nesc_ntoh_uint16(/*CtpP.ParentSelector*/EerParentSelectionP$0$parentSetPathETX[sim_node()][__nesc_ntoh_uint8(i.nxdata)].nxdata));
                      __nesc_hton_uint16(/*CtpP.ParentSelector*/EerParentSelectionP$0$prntSet[sim_node()].bestNeighbor.nxdata, /*CtpP.ParentSelector*/EerParentSelectionP$0$parentSetTable[sim_node()][__nesc_ntoh_uint8(i.nxdata)]);
                    }
                }
            }
          else 
            {
            }
        }
    }


  return SUCCESS;
}

# 145 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimActiveMessageC.nc"
static void TossimActiveMessageC$AMPacket$setDestination(message_t *amsg, am_addr_t addr)
#line 145
{
  tossim_header_t *header = TossimActiveMessageC$getHeader(amsg);

#line 147
  __nesc_hton_uint16(header->dest.nxdata, addr);
}

#line 170
static void TossimActiveMessageC$AMPacket$setType(message_t *amsg, am_id_t t)
#line 170
{
  tossim_header_t *header = TossimActiveMessageC$getHeader(amsg);

#line 172
  __nesc_hton_uint8(header->type.nxdata, t);
}

# 90 "/opt/tinyos-2.1.2/tos/system/AMQueueImplP.nc"
static error_t /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Send$send(uint8_t clientId, message_t *msg, 
uint8_t len)
#line 91
{
  if (clientId >= 2) {
      return FAIL;
    }
  if (/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$queue[sim_node()][clientId].msg != (void *)0) {
      return EBUSY;
    }
  sim_log_debug(275U, "AMQueue", "AMQueue: request to send from %hhu (%p): passed checks\n", clientId, msg);

  /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$queue[sim_node()][clientId].msg = msg;
  /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Packet$setPayloadLength(msg, len);

  if (/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current[sim_node()] >= 2) {
      error_t err;
      am_id_t amId = /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$AMPacket$type(msg);
      am_addr_t dest = /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$AMPacket$destination(msg);

      sim_log_debug(276U, "AMQueue", "%s: request to send from %hhu (%p): queue empty\n", __FUNCTION__, clientId, msg);
      /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current[sim_node()] = clientId;

      err = /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$AMSend$send(amId, dest, msg, len);
      if (err != SUCCESS) {
          sim_log_debug(277U, "AMQueue", "%s: underlying send failed.\n", __FUNCTION__);
          /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current[sim_node()] = 2;
          /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$queue[sim_node()][clientId].msg = (void *)0;
        }

      return err;
    }
  else {
      sim_log_debug(278U, "AMQueue", "AMQueue: request to send from %hhu (%p): queue not empty\n", clientId, msg);
    }
  return SUCCESS;
}

# 73 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimActiveMessageC.nc"
static error_t TossimActiveMessageC$AMSend$send(am_id_t id, am_addr_t addr, 
message_t *amsg, 
uint8_t len)
#line 75
{
  error_t err;
  tossim_header_t *header = TossimActiveMessageC$getHeader(amsg);

#line 78
  sim_log_debug(113U, "AM", "AM: Sending packet (id=%hhu, len=%hhu) to %hu\n", id, len, addr);
  __nesc_hton_uint8(header->type.nxdata, id);
  __nesc_hton_uint16(header->dest.nxdata, addr);
  __nesc_hton_uint16(header->src.nxdata, TossimActiveMessageC$AMPacket$address());
  __nesc_hton_uint8(header->length.nxdata, len);
  err = TossimActiveMessageC$Model$send((int )addr, amsg, len + sizeof(tossim_header_t ) + sizeof(tossim_footer_t ));
  return err;
}

# 274 "/opt/tinyos-2.1.2/tos/lib/tossim/CpmModelC.nc"
static double CpmModelC$packetNoise(CpmModelC$receive_message_t *msg)
#line 274
{
  double noise = CpmModelC$noise_hash_generation();
  CpmModelC$receive_message_t *list = CpmModelC$outstandingReceptionHead[sim_node()];

#line 277
  noise = pow(10.0, noise / 10.0);
  while (list != (void *)0) {
      if (list != msg) {
          noise += pow(10.0, list->power / 10.0);
        }
      list = list->next;
    }
  noise = 10.0 * log(noise) / log(10.0);
  return noise;
}

#line 126
static double CpmModelC$noise_hash_generation(void )
#line 126
{
  double CT = CpmModelC$timeInMs();
  uint32_t quotient = (sim_time_t )(CT * 10) / 10;
  uint8_t remain = (uint8_t )((sim_time_t )(CT * 10) % 10);
  double noise_val;
  uint16_t node_id = sim_node();

  sim_log_debug(131U, "CpmModelC", "IN: noise_hash_generation()\n");
  if (5 <= remain && remain < 10) {
      noise_val = (double )sim_noise_generate(node_id, quotient + 1);
    }
  else {
      noise_val = (double )sim_noise_generate(node_id, quotient);
    }
  sim_log_debug(132U, "CpmModelC,Tal", "%s: OUT: noise_hash_generation(): %lf\n", sim_time_string(), noise_val);

  return noise_val;
}

# 189 "/opt/tinyos-2.1.2/tos/system/AMQueueImplP.nc"
static void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$AMSend$sendDone(am_id_t id, message_t *msg, error_t err)
#line 189
{





  if (/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current[sim_node()] >= 2) {
      return;
    }
  if (/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$queue[sim_node()][/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current[sim_node()]].msg == msg) {
      /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$sendDone(/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current[sim_node()], msg, err);
    }
  else {
      sim_log_debug(279U, "PointerBug", "%s received send done for %p, signaling for %p.\n", __FUNCTION__, msg, /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$queue[sim_node()][/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current[sim_node()]].msg);
    }
}

#line 174
static void /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$tryToSend(void )
#line 174
{
  /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$nextPacket();
  if (/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current[sim_node()] < 2) {
      error_t nextErr;
      message_t *nextMsg = /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$queue[sim_node()][/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current[sim_node()]].msg;
      am_id_t nextId = /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$AMPacket$type(nextMsg);
      am_addr_t nextDest = /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$AMPacket$destination(nextMsg);
      uint8_t len = /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$Packet$payloadLength(nextMsg);

#line 182
      nextErr = /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$AMSend$send(nextId, nextDest, nextMsg, len);
      if (nextErr != SUCCESS) {
          /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$errorTask$postTask();
        }
    }
}

# 569 "../net/net_EER_sim/eer/EerParentSetEngineP.nc"
static void /*CtpP.Router*/EerParentSetEngineP$0$BeaconSend$sendDone(message_t *msg, error_t error)
#line 569
{
  if (msg != &/*CtpP.Router*/EerParentSetEngineP$0$beaconMsgBuffer[sim_node()] || !/*CtpP.Router*/EerParentSetEngineP$0$sending[sim_node()]) {

      return;
    }

  /*CtpP.Router*/EerParentSetEngineP$0$EerInstrumentation$ctrl_txpkt();
  /*CtpP.Router*/EerParentSetEngineP$0$sending[sim_node()] = FALSE;
}

# 721 "../net/net_EER_sim/eer/CtpForwardingEngineP.nc"
static void /*CtpP.Forwarder*/CtpForwardingEngineP$0$SubSend$sendDone(message_t *msg, error_t error)
#line 721
{

  fe_queue_entry_t *qe = /*CtpP.Forwarder*/CtpForwardingEngineP$0$SendQueue$head();

#line 724
  sim_log_debug(215U, "Forwarder", "%s to %hu and %hhu\n", __FUNCTION__, /*CtpP.Forwarder*/CtpForwardingEngineP$0$AMPacket$destination(msg), error);

  if (error != SUCCESS) {

      sim_log_debug(216U, "Forwarder", "%s: send failed\n", __FUNCTION__);
      /*CtpP.Forwarder*/CtpForwardingEngineP$0$CollectionDebug$logEventMsg(NET_C_FE_SENDDONE_FAIL, 
      /*CtpP.Forwarder*/CtpForwardingEngineP$0$CollectionPacket$getSequenceNumber(msg), 
      /*CtpP.Forwarder*/CtpForwardingEngineP$0$CollectionPacket$getOrigin(msg), 
      /*CtpP.Forwarder*/CtpForwardingEngineP$0$AMPacket$destination(msg));

      qe->forcedParentDraw = TRUE;





      /*CtpP.Forwarder*/CtpForwardingEngineP$0$startRetxmitTimer(SENDDONE_FAIL_WINDOW, SENDDONE_FAIL_OFFSET);
    }
  else {
    if (/*CtpP.Forwarder*/CtpForwardingEngineP$0$hasState(/*CtpP.Forwarder*/CtpForwardingEngineP$0$ACK_PENDING) && !/*CtpP.Forwarder*/CtpForwardingEngineP$0$PacketAcknowledgements$wasAcked(msg)) {


        if (qe->eer_retxs < 1) {
          }
        else 
          {
            /*CtpP.Forwarder*/CtpForwardingEngineP$0$LinkEstimator$txNoAck(/*CtpP.Forwarder*/CtpForwardingEngineP$0$AMPacket$destination(msg));
          }


        /*CtpP.Forwarder*/CtpForwardingEngineP$0$EerInstrumentation$data_txpkt();

        /*CtpP.Forwarder*/CtpForwardingEngineP$0$CtpInfo$recomputeRoutes();
        if (-- qe->retries) {
            sim_log_debug(217U, "Forwarder", "%s: not acked, retransmit\n", __FUNCTION__);
            /*CtpP.Forwarder*/CtpForwardingEngineP$0$CollectionDebug$logEventMsg(NET_C_FE_SENDDONE_WAITACK, 
            /*CtpP.Forwarder*/CtpForwardingEngineP$0$CollectionPacket$getSequenceNumber(msg), 
            /*CtpP.Forwarder*/CtpForwardingEngineP$0$CollectionPacket$getOrigin(msg), 
            /*CtpP.Forwarder*/CtpForwardingEngineP$0$AMPacket$destination(msg));






            /*CtpP.Forwarder*/CtpForwardingEngineP$0$startRetxmitTimer(SENDDONE_NOACK_WINDOW, SENDDONE_NOACK_OFFSET);


            qe->eer_retxs = qe->eer_retxs + 1;
            /*CtpP.Forwarder*/CtpForwardingEngineP$0$EerHealth$hlth_retx();
          }
        else {

            /*CtpP.Forwarder*/CtpForwardingEngineP$0$SendQueue$dequeue();
            /*CtpP.Forwarder*/CtpForwardingEngineP$0$clearState(/*CtpP.Forwarder*/CtpForwardingEngineP$0$SENDING);





            /*CtpP.Forwarder*/CtpForwardingEngineP$0$startRetxmitTimer(SENDDONE_OK_WINDOW, SENDDONE_OK_OFFSET);


            /*CtpP.Forwarder*/CtpForwardingEngineP$0$EerHealth$hlth_dropped();

            /*CtpP.Forwarder*/CtpForwardingEngineP$0$packetComplete(qe, msg, FALSE);
          }
      }
    else {



        /*CtpP.Forwarder*/CtpForwardingEngineP$0$SendQueue$dequeue();
        /*CtpP.Forwarder*/CtpForwardingEngineP$0$clearState(/*CtpP.Forwarder*/CtpForwardingEngineP$0$SENDING);





        /*CtpP.Forwarder*/CtpForwardingEngineP$0$startRetxmitTimer(SENDDONE_OK_WINDOW, SENDDONE_OK_OFFSET);

        /*CtpP.Forwarder*/CtpForwardingEngineP$0$LinkEstimator$txAck(/*CtpP.Forwarder*/CtpForwardingEngineP$0$AMPacket$destination(msg));


        /*CtpP.Forwarder*/CtpForwardingEngineP$0$EerInstrumentation$data_txpkt();
        /*CtpP.Forwarder*/CtpForwardingEngineP$0$EerInstrumentation$data_rxack();
#line 822
        /*CtpP.Forwarder*/CtpForwardingEngineP$0$packetComplete(qe, msg, TRUE);
      }
    }
}

#line 315
static void /*CtpP.Forwarder*/CtpForwardingEngineP$0$startRetxmitTimer(uint16_t window, uint16_t offset)
#line 315
{
  uint16_t r = /*CtpP.Forwarder*/CtpForwardingEngineP$0$Random$rand16();

#line 317
  r %= window;
  r += offset;
  /*CtpP.Forwarder*/CtpForwardingEngineP$0$RetxmitTimer$startOneShot(r);
  sim_log_debug(196U, "Forwarder", "Rexmit timer will fire in %hu ms\n", r);
}

# 73 "/opt/tinyos-2.1.2/tos/lib/timer/Timer.nc"
static void /*CtpP.Forwarder*/CtpForwardingEngineP$0$RetxmitTimer$startOneShot(uint32_t dt){
#line 73
  /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$startOneShot(3U, dt);
#line 73
}
#line 73
# 298 "../net/net_EER_sim/4bitle/LinkEstimatorP.nc"
static void LinkEstimatorP$updateDETX(neighbor_table_entry_t *ne)
#line 298
{
  uint16_t estETX;

  if (ne->data_success == 0) {



      estETX = ne->data_total * 10;
    }
  else 
#line 306
    {
      estETX = 10 * ne->data_total / ne->data_success;
      ne->data_success = 0;
      ne->data_total = 0;
    }
  LinkEstimatorP$updateETX(ne, estETX);
}

# 85 "/opt/tinyos-2.1.2/tos/system/QueueC.nc"
static /*CtpP.SendQueueP*/QueueC$0$queue_t /*CtpP.SendQueueP*/QueueC$0$Queue$dequeue(void )
#line 85
{
  /*CtpP.SendQueueP*/QueueC$0$queue_t t = /*CtpP.SendQueueP*/QueueC$0$Queue$head();

#line 87
  sim_log_debug(238U, "QueueC", "%s: size is %hhu\n", __FUNCTION__, /*CtpP.SendQueueP*/QueueC$0$size[sim_node()]);
  if (!/*CtpP.SendQueueP*/QueueC$0$Queue$empty()) {
      /*CtpP.SendQueueP*/QueueC$0$head[sim_node()]++;
      if (/*CtpP.SendQueueP*/QueueC$0$head[sim_node()] == 8) {
#line 90
        /*CtpP.SendQueueP*/QueueC$0$head[sim_node()] = 0;
        }
#line 91
      /*CtpP.SendQueueP*/QueueC$0$size[sim_node()]--;
      /*CtpP.SendQueueP*/QueueC$0$printQueue();
    }
  return t;
}

# 670 "../net/net_EER_sim/eer/CtpForwardingEngineP.nc"
static void /*CtpP.Forwarder*/CtpForwardingEngineP$0$packetComplete(fe_queue_entry_t *qe, message_t *msg, bool success)
#line 670
{



  if (qe->client < /*CtpP.Forwarder*/CtpForwardingEngineP$0$CLIENT_COUNT) {
      /*CtpP.Forwarder*/CtpForwardingEngineP$0$clientPtrs[sim_node()][qe->client] = qe;
      /*CtpP.Forwarder*/CtpForwardingEngineP$0$Send$sendDone(qe->client, msg, SUCCESS);
      if (success) {
          sim_log_debug(211U, "CtpForwarder", "%s: packet %hu.%hhu for client %hhu acknowledged.\n", __FUNCTION__, /*CtpP.Forwarder*/CtpForwardingEngineP$0$CollectionPacket$getOrigin(msg), /*CtpP.Forwarder*/CtpForwardingEngineP$0$CollectionPacket$getSequenceNumber(msg), qe->client);


          /*CtpP.Forwarder*/CtpForwardingEngineP$0$CollectionDebug$logEventMsg(NET_C_FE_SENT_MSG, 
          /*CtpP.Forwarder*/CtpForwardingEngineP$0$CollectionPacket$getSequenceNumber(msg), 
          /*CtpP.Forwarder*/CtpForwardingEngineP$0$CollectionPacket$getOrigin(msg), 
          /*CtpP.Forwarder*/CtpForwardingEngineP$0$AMPacket$destination(msg));
        }
      else 
#line 685
        {
          sim_log_debug(212U, "CtpForwarder", "%s: packet %hu.%hhu for client %hhu dropped.\n", __FUNCTION__, /*CtpP.Forwarder*/CtpForwardingEngineP$0$CollectionPacket$getOrigin(msg), /*CtpP.Forwarder*/CtpForwardingEngineP$0$CollectionPacket$getSequenceNumber(msg), qe->client);


          /*CtpP.Forwarder*/CtpForwardingEngineP$0$CollectionDebug$logEventMsg(NET_C_FE_SENDDONE_FAIL_ACK_SEND, 
          /*CtpP.Forwarder*/CtpForwardingEngineP$0$CollectionPacket$getSequenceNumber(msg), 
          /*CtpP.Forwarder*/CtpForwardingEngineP$0$CollectionPacket$getOrigin(msg), 
          /*CtpP.Forwarder*/CtpForwardingEngineP$0$AMPacket$destination(msg));
        }
    }
  else {
      if (success) {
          /*CtpP.Forwarder*/CtpForwardingEngineP$0$SentCache$insert(qe->msg);
          sim_log_debug(213U, "CtpForwarder", "%s: forwarded packet %hu.%hhu acknowledged: insert in transmit queue.\n", __FUNCTION__, /*CtpP.Forwarder*/CtpForwardingEngineP$0$CollectionPacket$getOrigin(msg), /*CtpP.Forwarder*/CtpForwardingEngineP$0$CollectionPacket$getSequenceNumber(msg));

          /*CtpP.Forwarder*/CtpForwardingEngineP$0$CollectionDebug$logEventMsg(NET_C_FE_FWD_MSG, 
          /*CtpP.Forwarder*/CtpForwardingEngineP$0$CollectionPacket$getSequenceNumber(msg), 
          /*CtpP.Forwarder*/CtpForwardingEngineP$0$CollectionPacket$getOrigin(msg), 
          /*CtpP.Forwarder*/CtpForwardingEngineP$0$AMPacket$destination(msg));
        }
      else {
          sim_log_debug(214U, "CtpForwarder", "%s: forwarded packet %hu.%hhu dropped.\n", __FUNCTION__, /*CtpP.Forwarder*/CtpForwardingEngineP$0$CollectionPacket$getOrigin(msg), /*CtpP.Forwarder*/CtpForwardingEngineP$0$CollectionPacket$getSequenceNumber(msg));

          /*CtpP.Forwarder*/CtpForwardingEngineP$0$CollectionDebug$logEventMsg(NET_C_FE_SENDDONE_FAIL_ACK_FWD, 
          /*CtpP.Forwarder*/CtpForwardingEngineP$0$CollectionPacket$getSequenceNumber(msg), 
          /*CtpP.Forwarder*/CtpForwardingEngineP$0$CollectionPacket$getOrigin(msg), 
          /*CtpP.Forwarder*/CtpForwardingEngineP$0$AMPacket$destination(msg));
        }
      if (/*CtpP.Forwarder*/CtpForwardingEngineP$0$MessagePool$put(qe->msg) != SUCCESS) {
        /*CtpP.Forwarder*/CtpForwardingEngineP$0$CollectionDebug$logEvent(NET_C_FE_PUT_MSGPOOL_ERR);
        }
#line 715
      if (/*CtpP.Forwarder*/CtpForwardingEngineP$0$QEntryPool$put(qe) != SUCCESS) {
        /*CtpP.Forwarder*/CtpForwardingEngineP$0$CollectionDebug$logEvent(NET_C_FE_PUT_QEPOOL_ERR);
        }
    }
}

# 248 "/opt/tinyos-2.1.2/tos/lib/tossim/CpmModelC.nc"
static bool CpmModelC$shouldReceive(double SNR)
#line 248
{
  double prr = CpmModelC$prr_estimate_from_snr(SNR);
  double coin = RandomUniform();

#line 251
  if (prr >= 0 && prr <= 1) {
      if (coin < prr) {
        prr = 1.0;
        }
      else {
#line 255
        prr = 0.0;
        }
    }
#line 257
  return prr;
}

# 307 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimPacketModelC.nc"
static bool TossimPacketModelC$GainRadioModel$shouldAck(message_t *msg)
#line 307
{
  if (TossimPacketModelC$running[sim_node()] && !TossimPacketModelC$transmitting[sim_node()]) {
      return TossimPacketModelC$Packet$shouldAck(msg);
    }
  else {
      return FALSE;
    }
}

# 216 "/opt/tinyos-2.1.2/tos/lib/tossim/CpmModelC.nc"
static void CpmModelC$sim_gain_schedule_ack(int source, sim_time_t t, CpmModelC$receive_message_t *r)
#line 216
{
  sim_event_t *ackEvent = (sim_event_t *)malloc(sizeof(sim_event_t ));

  ackEvent->mote = source;
  ackEvent->force = 1;
  ackEvent->cancelled = 0;
  ackEvent->time = t;
  ackEvent->handle = CpmModelC$sim_gain_ack_handle;
  ackEvent->cleanup = sim_queue_cleanup_event;
  ackEvent->data = r;

  sim_queue_insert(ackEvent);
}

# 694 "../net/net_EER_sim/eer/EerParentSetEngineP.nc"
static error_t /*CtpP.Router*/EerParentSetEngineP$0$CtpInfo$getParent(am_addr_t *parent)
#line 694
{
  if (parent == (void *)0) {
    return FAIL;
    }
#line 697
  if (/*CtpP.Router*/EerParentSetEngineP$0$routeInfo[sim_node()].parent == INVALID_ADDR) {
    return FAIL;
    }
#line 699
  *parent = /*CtpP.Router*/EerParentSetEngineP$0$routeInfo[sim_node()].parent;
  return SUCCESS;
}

# 73 "/opt/tinyos-2.1.2/tos/lib/timer/VirtualizeTimerC.nc"
static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$fireTimers(uint32_t now)
{
  uint16_t num;

  for (num = 0; num < /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$NUM_TIMERS; num++) 
    {
      /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer_t *timer = &/*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$m_timers[sim_node()][num];

      if (timer->isrunning) 
        {
          uint32_t elapsed = now - timer->t0;

          if (elapsed >= timer->dt) 
            {
              if (timer->isoneshot) {
                timer->isrunning = FALSE;
                }
              else {
#line 90
                timer->t0 += timer->dt;
                }
              /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$fired(num);
              break;
            }
        }
    }
  /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$updateFromTimer$postTask();
}

# 212 "/opt/tinyos-2.1.2/tos/chips/atm128/timer/Atm128AlarmAsyncP.nc"
static void /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Alarm$startAt(uint32_t nt0, uint32_t ndt)
#line 212
{
  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
    {
      /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$set[sim_node()] = TRUE;
      /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$t0[sim_node()] = nt0;
      /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$dt[sim_node()] = ndt;
    }
#line 218
    __nesc_atomic_end(__nesc_atomic); }
  /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$setInterrupt();
}

#line 90
static void /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$setInterrupt(void )
#line 90
{
  bool fired = FALSE;

  { __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
    {



      uint8_t interrupt_in = 1 + /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Compare$get() - /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Timer$get();
      uint8_t newOcr0;
      uint8_t tifr = (uint8_t )/*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$TimerCtrl$getInterruptFlag().flat;

#line 101
      sim_log_debug(167U, "Atm128AlarmAsyncP", "Atm128AlarmAsyncP: TIFR is %hhx\n", tifr);
      if ((interrupt_in != 0 && interrupt_in < /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$MINDT) || tifr & (1 << OCF0)) {
          if (interrupt_in < /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$MINDT) {
              sim_log_debug(168U, "Atm128AlarmAsyncP", "Atm128AlarmAsyncP: under min: %hhu.\n", interrupt_in);
            }
          else {
              sim_log_debug(169U, "Atm128AlarmAsyncP", "Atm128AlarmAsyncP: OCF set.\n");
            }
          {
#line 109
            __nesc_atomic_end(__nesc_atomic); 
#line 109
            return;
          }
        }

      if (!/*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$set[sim_node()]) {
          newOcr0 = /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$MAXT;
          sim_log_debug(170U, "Atm128AlarmAsyncP", "Atm128AlarmAsyncP: no alarm set, set at max.\n");
        }
      else 
        {
          uint32_t now = /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Counter$get();

#line 120
          sim_log_debug(171U, "Atm128AlarmAsyncP", "Atm128AlarmAsyncP: now-t0 = %llu, dt = %llu\n", now - /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$t0[sim_node()], /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$dt[sim_node()]);

          if ((uint32_t )(now - /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$t0[sim_node()]) >= /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$dt[sim_node()]) 
            {
              /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$set[sim_node()] = FALSE;
              fired = TRUE;
              newOcr0 = /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$MAXT;
            }
          else 
            {


              uint32_t alarm_in = /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$t0[sim_node()] + /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$dt[sim_node()] - /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$base[sim_node()];

              if (alarm_in > /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$MAXT) {
                newOcr0 = /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$MAXT;
                }
              else {
#line 136
                if ((uint8_t )alarm_in < /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$MINDT) {
                  newOcr0 = /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$MINDT;
                  }
                else {
#line 139
                  newOcr0 = alarm_in;
                  }
                }
            }
        }
#line 142
      newOcr0--;
      /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$setOcr0(newOcr0);
    }
#line 144
    __nesc_atomic_end(__nesc_atomic); }
  if (fired) {
    /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$Alarm$fired();
    }
}

# 463 "/opt/tinyos-2.1.2/tos/chips/atm128/timer/sim/HplAtm128Timer0AsyncP.nc"
static void HplAtm128Timer0AsyncP$Compare$set(uint8_t t)
#line 463
{
  sim_log_debug(188U, "HplAtm128Timer0AsyncP", "HplAtm128Timer0AsyncP: Setting compare: %hhu\n", t);
  /* atomic removed: atomic calls only */
#line 465
  {




    if (t == 0 || t >= 0xfe) {
      t = 1;
      }
    if (t != * (volatile uint8_t *)&atm128RegFile[sim_node()][0x31]) {
        * (volatile uint8_t *)&atm128RegFile[sim_node()][0x31] = t;
        HplAtm128Timer0AsyncP$schedule_new_compare();
      }
  }
}

#line 267
static void HplAtm128Timer0AsyncP$schedule_new_compare(void )
#line 267
{
  if (HplAtm128Timer0AsyncP$compare[sim_node()] != (void *)0) {
      HplAtm128Timer0AsyncP$cancel_compare();
    }
  if (HplAtm128Timer0AsyncP$Timer0$getScale() != AVR_CLOCK_OFF) {
      sim_event_t *newEvent = HplAtm128Timer0AsyncP$allocate_compare();

#line 273
      HplAtm128Timer0AsyncP$configure_compare(newEvent);

      HplAtm128Timer0AsyncP$compare[sim_node()] = newEvent;
      sim_queue_insert(newEvent);
    }
}

# 97 "/opt/tinyos-2.1.2/tos/lib/tossim/sim_event_queue.c"
static sim_event_t *sim_queue_allocate_event()
#line 97
{
  sim_event_t *evt = (sim_event_t *)malloc(sizeof(sim_event_t ));

#line 99
  memset(evt, 0, sizeof(sim_event_t ));
  evt->mote = sim_node();
  return evt;
}

# 100 "/opt/tinyos-2.1.2/tos/chips/atm128/timer/sim/HplAtm128Timer0AsyncP.nc"
  void INTERRUPT_16(void )
#line 100
{
  HplAtm128Timer0AsyncP$inOverflow[sim_node()] = TRUE;
  HplAtm128Timer0AsyncP$Timer0$overflow();
  HplAtm128Timer0AsyncP$inOverflow[sim_node()] = FALSE;
}

#line 508
static void HplAtm128Timer0AsyncP$configure_overflow(sim_event_t *evt)
#line 508
{
  sim_time_t overflowTime = 0;
  uint8_t timerVal = HplAtm128Timer0AsyncP$Timer0$get();
  uint8_t overflowVal = 0;




  overflowTime = (overflowVal - timerVal) & 0xff;
  if (overflowTime == 0) {
      overflowTime = 256;
    }




  overflowTime = overflowTime << HplAtm128Timer0AsyncP$shiftFromScale();
  overflowTime = HplAtm128Timer0AsyncP$clock_to_sim(overflowTime);
  overflowTime += sim_time();
  overflowTime -= (sim_time() - HplAtm128Timer0AsyncP$last_zero()) % (1 << HplAtm128Timer0AsyncP$shiftFromScale());

  sim_log_debug(191U, "HplAtm128Timer0AsyncP", "Scheduling new overflow for %i at time %llu\n", sim_node(), overflowTime);

  evt->time = overflowTime;
}

#line 94
  void INTERRUPT_15(void )
#line 94
{

  HplAtm128Timer0AsyncP$Compare$fired();
}

#line 231
static void HplAtm128Timer0AsyncP$configure_compare(sim_event_t *evt)
#line 231
{
  sim_time_t compareTime = 0;
  sim_time_t phaseOffset = 0;
  uint8_t timerVal = HplAtm128Timer0AsyncP$Timer0$get();
  uint8_t compareVal = HplAtm128Timer0AsyncP$Compare$get();




  compareTime = (compareVal - timerVal) & 0xff;
  if (compareTime == 0) {
      compareTime = 256;
    }






  compareTime = (compareTime + 1) << HplAtm128Timer0AsyncP$shiftFromScale();
  compareTime = HplAtm128Timer0AsyncP$clock_to_sim(compareTime);
  compareTime += sim_time();




  phaseOffset = sim_time();
  phaseOffset -= HplAtm128Timer0AsyncP$last_zero();
  phaseOffset %= HplAtm128Timer0AsyncP$clock_to_sim(1 << HplAtm128Timer0AsyncP$shiftFromScale());
  compareTime -= phaseOffset;

  sim_log_debug(180U, "HplAtm128Timer0AsyncP", "Configuring new compare of %i for %i at time %llu  (@ %llu)\n", (int )compareVal, sim_node(), compareTime, sim_time());

  evt->time = compareTime;
}

# 106 "/opt/tinyos-2.1.2/tos/lib/tossim/TossimPacketModelC.nc"
static error_t TossimPacketModelC$Control$start(void )
#line 106
{
  if (!TossimPacketModelC$initialized[sim_node()]) {
      sim_log_error(119U, "TossimPacketModelC", "TossimPacketModelC: Control.start() called before initialization!\n");
      return FAIL;
    }
  sim_log_debug(120U, "TossimPacketModelC", "TossimPacketModelC: Control.start() called.\n");
  TossimPacketModelC$startDoneTask$postTask();
  return SUCCESS;
}

# 154 "/opt/tinyos-2.1.2/tos/lib/timer/VirtualizeTimerC.nc"
static void /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$Timer$startPeriodic(uint8_t num, uint32_t dt)
{
  /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$startTimer(num, /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$TimerFrom$getNow(), dt, FALSE);
}

# 90 "/opt/tinyos-2.1.2/tos/lib/tossim/SimMoteP.nc"
  long long int sim_mote_euid(int mote)
#line 90
{
  long long int result;
  int tmp = sim_node();

#line 93
  sim_set_node(mote);
  result = SimMoteP$SimMote$getEuid();
  sim_set_node(tmp);
  return result;
}

  void sim_mote_set_euid(int mote, long long int id)
#line 99
{
  int tmp = sim_node();

#line 101
  sim_set_node(mote);
  SimMoteP$SimMote$setEuid(id);
  sim_set_node(tmp);
}










  int sim_mote_get_variable_info(int mote, char *name, void **ptr, size_t *len)
#line 115
{
  int result;
  int tmpID = sim_node();

#line 118
  sim_set_node(mote);
  result = SimMoteP$SimMote$getVariableInfo(name, ptr, len);
  sim_log_debug(110U, "SimMoteP", "Fetched %s of %i to be %p with len %i (result %i)\n", name, mote, *ptr, *len, result);
  sim_set_node(tmpID);
  return result;
}

  void sim_mote_set_start_time(int mote, long long int t)
#line 125
{
  int tmpID = sim_node();

#line 127
  sim_set_node(mote);
  SimMoteP$startTime[sim_node()] = t;
  sim_log_debug(111U, "SimMoteP", "Setting start time to %llu\n", SimMoteP$startTime[sim_node()]);
  sim_set_node(tmpID);
  return;
}










  void sim_mote_turn_on(int mote)
#line 143
{
  int tmp = sim_node();

#line 145
  sim_set_node(mote);
  SimMoteP$SimMote$turnOn();
  sim_set_node(tmp);
}

#line 72
static void SimMoteP$SimMote$turnOn(void )
#line 72
{
  if (!SimMoteP$isOn[sim_node()]) {
      if (SimMoteP$bootEvent[sim_node()] != (void *)0) {
          SimMoteP$bootEvent[sim_node()]->cancelled = TRUE;
        }
      __nesc_nido_initialise(sim_node());
      SimMoteP$startTime[sim_node()] = sim_time();
      sim_log_debug(109U, "SimMoteP", "Setting start time to %llu\n", SimMoteP$startTime[sim_node()]);
      SimMoteP$isOn[sim_node()] = TRUE;
      sim_main_start_mote();
    }
}

#line 150
  void sim_mote_turn_off(int mote)
#line 150
{
  int tmp = sim_node();

#line 152
  sim_set_node(mote);
  SimMoteP$SimMote$turnOff();
  sim_set_node(tmp);
}










  void sim_mote_enqueue_boot_event(int mote)
#line 166
{
  int tmp = sim_node();

#line 168
  sim_set_node(mote);

  if (SimMoteP$bootEvent[sim_node()] != (void *)0) {
      if (SimMoteP$bootEvent[sim_node()]->time == SimMoteP$startTime[sim_node()]) {

          SimMoteP$bootEvent[sim_node()]->cancelled = FALSE;
          return;
        }
      else {
          SimMoteP$bootEvent[sim_node()]->cancelled = TRUE;
        }
    }

  SimMoteP$bootEvent[sim_node()] = (sim_event_t *)malloc(sizeof(sim_event_t ));
  SimMoteP$bootEvent[sim_node()]->time = SimMoteP$startTime[sim_node()];
  SimMoteP$bootEvent[sim_node()]->mote = mote;
  SimMoteP$bootEvent[sim_node()]->force = TRUE;
  SimMoteP$bootEvent[sim_node()]->data = (void *)0;
  SimMoteP$bootEvent[sim_node()]->handle = SimMoteP$sim_mote_boot_handle;
  SimMoteP$bootEvent[sim_node()]->cleanup = sim_queue_cleanup_event;
  sim_queue_insert(SimMoteP$bootEvent[sim_node()]);

  sim_set_node(tmp);
}

/* Nido variable resolver function */

static int __nesc_nido_resolve(int __nesc_mote,
                               char* varname,
                               uintptr_t* addr, size_t* size)
{
  /* Module LapTestC */
  if (!strcmp(varname, "LapTestC$data_pkt"))
  {
    *addr = (uintptr_t)&LapTestC$data_pkt[__nesc_mote];
    *size = sizeof(LapTestC$data_pkt[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "LapTestC$radioBusy"))
  {
    *addr = (uintptr_t)&LapTestC$radioBusy[__nesc_mote];
    *size = sizeof(LapTestC$radioBusy[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "LapTestC$rounds"))
  {
    *addr = (uintptr_t)&LapTestC$rounds[__nesc_mote];
    *size = sizeof(LapTestC$rounds[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "LapTestC$i"))
  {
    *addr = (uintptr_t)&LapTestC$i[__nesc_mote];
    *size = sizeof(LapTestC$i[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "LapTestC$counter"))
  {
    *addr = (uintptr_t)&LapTestC$counter[__nesc_mote];
    *size = sizeof(LapTestC$counter[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "LapTestC$parent"))
  {
    *addr = (uintptr_t)&LapTestC$parent[__nesc_mote];
    *size = sizeof(LapTestC$parent[__nesc_mote]);
    return 0;
  }

  /* Module PlatformP */

  /* Module MotePlatformP */

  /* Module HplAtm128GeneralIOPinP$0 */

  /* Module HplAtm128GeneralIOPinP$1 */

  /* Module HplAtm128GeneralIOPinP$2 */

  /* Module HplAtm128GeneralIOPinP$3 */

  /* Module HplAtm128GeneralIOPinP$4 */

  /* Module HplAtm128GeneralIOPinP$5 */

  /* Module HplAtm128GeneralIOPinP$6 */

  /* Module HplAtm128GeneralIOPinP$7 */

  /* Module HplAtm128GeneralIOPinP$8 */

  /* Module HplAtm128GeneralIOPinP$9 */

  /* Module HplAtm128GeneralIOPinP$10 */

  /* Module HplAtm128GeneralIOPinP$11 */

  /* Module HplAtm128GeneralIOPinP$12 */

  /* Module HplAtm128GeneralIOPinP$13 */

  /* Module HplAtm128GeneralIOPinP$14 */

  /* Module HplAtm128GeneralIOPinP$15 */

  /* Module HplAtm128GeneralIOPinP$16 */

  /* Module HplAtm128GeneralIOPinP$17 */

  /* Module HplAtm128GeneralIOPinP$18 */

  /* Module HplAtm128GeneralIOPinP$19 */

  /* Module HplAtm128GeneralIOPinP$20 */

  /* Module HplAtm128GeneralIOPinP$21 */

  /* Module HplAtm128GeneralIOPinP$22 */

  /* Module HplAtm128GeneralIOPinP$23 */

  /* Module HplAtm128GeneralIOPinP$24 */

  /* Module HplAtm128GeneralIOPinP$25 */

  /* Module HplAtm128GeneralIOPinP$26 */

  /* Module HplAtm128GeneralIOPinP$27 */

  /* Module HplAtm128GeneralIOPinP$28 */

  /* Module HplAtm128GeneralIOPinP$29 */

  /* Module HplAtm128GeneralIOPinP$30 */

  /* Module HplAtm128GeneralIOPinP$31 */

  /* Module HplAtm128GeneralIOPinP$32 */

  /* Module HplAtm128GeneralIOPinP$33 */

  /* Module HplAtm128GeneralIOPinP$34 */

  /* Module HplAtm128GeneralIOPinP$35 */

  /* Module HplAtm128GeneralIOPinP$36 */

  /* Module HplAtm128GeneralIOPinP$37 */

  /* Module HplAtm128GeneralIOPinP$38 */

  /* Module HplAtm128GeneralIOPinP$39 */

  /* Module HplAtm128GeneralIOPinP$40 */

  /* Module HplAtm128GeneralIOPinP$41 */

  /* Module HplAtm128GeneralIOPinP$42 */

  /* Module HplAtm128GeneralIOPinP$43 */

  /* Module HplAtm128GeneralIOPinP$44 */

  /* Module HplAtm128GeneralIOPinP$45 */

  /* Module HplAtm128GeneralIOPinP$46 */

  /* Module HplAtm128GeneralIOPinP$47 */

  /* Module HplAtm128GeneralIOSlowPinP$0 */

  /* Module HplAtm128GeneralIOSlowPinP$1 */

  /* Module HplAtm128GeneralIOSlowPinP$2 */

  /* Module HplAtm128GeneralIOSlowPinP$3 */

  /* Module HplAtm128GeneralIOSlowPinP$4 */

  /* Module HplAtm128GeneralIOSlowPinP$5 */

  /* Module HplAtm128GeneralIOSlowPinP$6 */

  /* Module HplAtm128GeneralIOSlowPinP$7 */

  /* Module HplAtm128GeneralIOSlowPinP$8 */

  /* Module HplAtm128GeneralIOSlowPinP$9 */

  /* Module HplAtm128GeneralIOSlowPinP$10 */

  /* Module HplAtm128GeneralIOSlowPinP$11 */

  /* Module HplAtm128GeneralIOSlowPinP$12 */

  /* Module MeasureClockC */

  /* Module SimMainP */

  /* Module SimSchedulerBasicP */
  if (!strcmp(varname, "SimSchedulerBasicP$m_head"))
  {
    *addr = (uintptr_t)&SimSchedulerBasicP$m_head[__nesc_mote];
    *size = sizeof(SimSchedulerBasicP$m_head[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "SimSchedulerBasicP$m_tail"))
  {
    *addr = (uintptr_t)&SimSchedulerBasicP$m_tail[__nesc_mote];
    *size = sizeof(SimSchedulerBasicP$m_tail[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "SimSchedulerBasicP$m_next"))
  {
    *addr = (uintptr_t)&SimSchedulerBasicP$m_next[__nesc_mote];
    *size = sizeof(SimSchedulerBasicP$m_next[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "SimSchedulerBasicP$sim_scheduler_event_pending"))
  {
    *addr = (uintptr_t)&SimSchedulerBasicP$sim_scheduler_event_pending[__nesc_mote];
    *size = sizeof(SimSchedulerBasicP$sim_scheduler_event_pending[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "SimSchedulerBasicP$sim_scheduler_event"))
  {
    *addr = (uintptr_t)&SimSchedulerBasicP$sim_scheduler_event[__nesc_mote];
    *size = sizeof(SimSchedulerBasicP$sim_scheduler_event[__nesc_mote]);
    return 0;
  }

  /* Module SimMoteP */
  if (!strcmp(varname, "SimMoteP$euid"))
  {
    *addr = (uintptr_t)&SimMoteP$euid[__nesc_mote];
    *size = sizeof(SimMoteP$euid[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "SimMoteP$startTime"))
  {
    *addr = (uintptr_t)&SimMoteP$startTime[__nesc_mote];
    *size = sizeof(SimMoteP$startTime[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "SimMoteP$isOn"))
  {
    *addr = (uintptr_t)&SimMoteP$isOn[__nesc_mote];
    *size = sizeof(SimMoteP$isOn[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "SimMoteP$bootEvent"))
  {
    *addr = (uintptr_t)&SimMoteP$bootEvent[__nesc_mote];
    *size = sizeof(SimMoteP$bootEvent[__nesc_mote]);
    return 0;
  }

  /* Module TossimActiveMessageC */
  if (!strcmp(varname, "TossimActiveMessageC$buffer"))
  {
    *addr = (uintptr_t)&TossimActiveMessageC$buffer[__nesc_mote];
    *size = sizeof(TossimActiveMessageC$buffer[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "TossimActiveMessageC$bufferPointer"))
  {
    *addr = (uintptr_t)&TossimActiveMessageC$bufferPointer[__nesc_mote];
    *size = sizeof(TossimActiveMessageC$bufferPointer[__nesc_mote]);
    return 0;
  }

  /* Module TossimPacketModelC */
  if (!strcmp(varname, "TossimPacketModelC$initialized"))
  {
    *addr = (uintptr_t)&TossimPacketModelC$initialized[__nesc_mote];
    *size = sizeof(TossimPacketModelC$initialized[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "TossimPacketModelC$running"))
  {
    *addr = (uintptr_t)&TossimPacketModelC$running[__nesc_mote];
    *size = sizeof(TossimPacketModelC$running[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "TossimPacketModelC$backoffCount"))
  {
    *addr = (uintptr_t)&TossimPacketModelC$backoffCount[__nesc_mote];
    *size = sizeof(TossimPacketModelC$backoffCount[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "TossimPacketModelC$neededFreeSamples"))
  {
    *addr = (uintptr_t)&TossimPacketModelC$neededFreeSamples[__nesc_mote];
    *size = sizeof(TossimPacketModelC$neededFreeSamples[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "TossimPacketModelC$sending"))
  {
    *addr = (uintptr_t)&TossimPacketModelC$sending[__nesc_mote];
    *size = sizeof(TossimPacketModelC$sending[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "TossimPacketModelC$transmitting"))
  {
    *addr = (uintptr_t)&TossimPacketModelC$transmitting[__nesc_mote];
    *size = sizeof(TossimPacketModelC$transmitting[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "TossimPacketModelC$sendingLength"))
  {
    *addr = (uintptr_t)&TossimPacketModelC$sendingLength[__nesc_mote];
    *size = sizeof(TossimPacketModelC$sendingLength[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "TossimPacketModelC$destNode"))
  {
    *addr = (uintptr_t)&TossimPacketModelC$destNode[__nesc_mote];
    *size = sizeof(TossimPacketModelC$destNode[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "TossimPacketModelC$sendEvent"))
  {
    *addr = (uintptr_t)&TossimPacketModelC$sendEvent[__nesc_mote];
    *size = sizeof(TossimPacketModelC$sendEvent[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "TossimPacketModelC$error"))
  {
    *addr = (uintptr_t)&TossimPacketModelC$error[__nesc_mote];
    *size = sizeof(TossimPacketModelC$error[__nesc_mote]);
    return 0;
  }

  /* Module CpmModelC */
  if (!strcmp(varname, "CpmModelC$outgoing"))
  {
    *addr = (uintptr_t)&CpmModelC$outgoing[__nesc_mote];
    *size = sizeof(CpmModelC$outgoing[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "CpmModelC$requestAck"))
  {
    *addr = (uintptr_t)&CpmModelC$requestAck[__nesc_mote];
    *size = sizeof(CpmModelC$requestAck[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "CpmModelC$receiving"))
  {
    *addr = (uintptr_t)&CpmModelC$receiving[__nesc_mote];
    *size = sizeof(CpmModelC$receiving[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "CpmModelC$transmitting"))
  {
    *addr = (uintptr_t)&CpmModelC$transmitting[__nesc_mote];
    *size = sizeof(CpmModelC$transmitting[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "CpmModelC$transmissionEndTime"))
  {
    *addr = (uintptr_t)&CpmModelC$transmissionEndTime[__nesc_mote];
    *size = sizeof(CpmModelC$transmissionEndTime[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "CpmModelC$outstandingReceptionHead"))
  {
    *addr = (uintptr_t)&CpmModelC$outstandingReceptionHead[__nesc_mote];
    *size = sizeof(CpmModelC$outstandingReceptionHead[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "CpmModelC$clearThreshold"))
  {
    *addr = (uintptr_t)&CpmModelC$clearThreshold[__nesc_mote];
    *size = sizeof(CpmModelC$clearThreshold[__nesc_mote]);
    return 0;
  }

  /* Module ActiveMessageAddressC */
  if (!strcmp(varname, "ActiveMessageAddressC$set"))
  {
    *addr = (uintptr_t)&ActiveMessageAddressC$set[__nesc_mote];
    *size = sizeof(ActiveMessageAddressC$set[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "ActiveMessageAddressC$addr"))
  {
    *addr = (uintptr_t)&ActiveMessageAddressC$addr[__nesc_mote];
    *size = sizeof(ActiveMessageAddressC$addr[__nesc_mote]);
    return 0;
  }

  /* Module LedsP */

  /* Module Atm128AlarmAsyncP$0 */
  if (!strcmp(varname, "/*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$set"))
  {
    *addr = (uintptr_t)&/*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$set[__nesc_mote];
    *size = sizeof(/*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$set[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$t0"))
  {
    *addr = (uintptr_t)&/*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$t0[__nesc_mote];
    *size = sizeof(/*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$t0[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$dt"))
  {
    *addr = (uintptr_t)&/*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$dt[__nesc_mote];
    *size = sizeof(/*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$dt[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$base"))
  {
    *addr = (uintptr_t)&/*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$base[__nesc_mote];
    *size = sizeof(/*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$base[__nesc_mote]);
    return 0;
  }

  /* Module HplAtm128Timer0AsyncP */
  if (!strcmp(varname, "HplAtm128Timer0AsyncP$inOverflow"))
  {
    *addr = (uintptr_t)&HplAtm128Timer0AsyncP$inOverflow[__nesc_mote];
    *size = sizeof(HplAtm128Timer0AsyncP$inOverflow[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "HplAtm128Timer0AsyncP$lastZero"))
  {
    *addr = (uintptr_t)&HplAtm128Timer0AsyncP$lastZero[__nesc_mote];
    *size = sizeof(HplAtm128Timer0AsyncP$lastZero[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "HplAtm128Timer0AsyncP$oldScale"))
  {
    *addr = (uintptr_t)&HplAtm128Timer0AsyncP$oldScale[__nesc_mote];
    *size = sizeof(HplAtm128Timer0AsyncP$oldScale[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "HplAtm128Timer0AsyncP$compare"))
  {
    *addr = (uintptr_t)&HplAtm128Timer0AsyncP$compare[__nesc_mote];
    *size = sizeof(HplAtm128Timer0AsyncP$compare[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "HplAtm128Timer0AsyncP$overflow"))
  {
    *addr = (uintptr_t)&HplAtm128Timer0AsyncP$overflow[__nesc_mote];
    *size = sizeof(HplAtm128Timer0AsyncP$overflow[__nesc_mote]);
    return 0;
  }

  /* Module AlarmToTimerC$0 */
  if (!strcmp(varname, "/*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$m_dt"))
  {
    *addr = (uintptr_t)&/*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$m_dt[__nesc_mote];
    *size = sizeof(/*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$m_dt[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$m_oneshot"))
  {
    *addr = (uintptr_t)&/*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$m_oneshot[__nesc_mote];
    *size = sizeof(/*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$m_oneshot[__nesc_mote]);
    return 0;
  }

  /* Module VirtualizeTimerC$0 */
  if (!strcmp(varname, "/*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$m_timers"))
  {
    *addr = (uintptr_t)&/*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$m_timers[__nesc_mote];
    *size = sizeof(/*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$m_timers[__nesc_mote]);
    return 0;
  }

  /* Module CounterToLocalTimeC$0 */

  /* Module CtpForwardingEngineP$0 */
  if (!strcmp(varname, "/*CtpP.Forwarder*/CtpForwardingEngineP$0$forwardingState"))
  {
    *addr = (uintptr_t)&/*CtpP.Forwarder*/CtpForwardingEngineP$0$forwardingState[__nesc_mote];
    *size = sizeof(/*CtpP.Forwarder*/CtpForwardingEngineP$0$forwardingState[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*CtpP.Forwarder*/CtpForwardingEngineP$0$lastParent"))
  {
    *addr = (uintptr_t)&/*CtpP.Forwarder*/CtpForwardingEngineP$0$lastParent[__nesc_mote];
    *size = sizeof(/*CtpP.Forwarder*/CtpForwardingEngineP$0$lastParent[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*CtpP.Forwarder*/CtpForwardingEngineP$0$seqno"))
  {
    *addr = (uintptr_t)&/*CtpP.Forwarder*/CtpForwardingEngineP$0$seqno[__nesc_mote];
    *size = sizeof(/*CtpP.Forwarder*/CtpForwardingEngineP$0$seqno[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*CtpP.Forwarder*/CtpForwardingEngineP$0$clientEntries"))
  {
    *addr = (uintptr_t)&/*CtpP.Forwarder*/CtpForwardingEngineP$0$clientEntries[__nesc_mote];
    *size = sizeof(/*CtpP.Forwarder*/CtpForwardingEngineP$0$clientEntries[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*CtpP.Forwarder*/CtpForwardingEngineP$0$clientPtrs"))
  {
    *addr = (uintptr_t)&/*CtpP.Forwarder*/CtpForwardingEngineP$0$clientPtrs[__nesc_mote];
    *size = sizeof(/*CtpP.Forwarder*/CtpForwardingEngineP$0$clientPtrs[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*CtpP.Forwarder*/CtpForwardingEngineP$0$loopbackMsg"))
  {
    *addr = (uintptr_t)&/*CtpP.Forwarder*/CtpForwardingEngineP$0$loopbackMsg[__nesc_mote];
    *size = sizeof(/*CtpP.Forwarder*/CtpForwardingEngineP$0$loopbackMsg[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*CtpP.Forwarder*/CtpForwardingEngineP$0$loopbackMsgPtr"))
  {
    *addr = (uintptr_t)&/*CtpP.Forwarder*/CtpForwardingEngineP$0$loopbackMsgPtr[__nesc_mote];
    *size = sizeof(/*CtpP.Forwarder*/CtpForwardingEngineP$0$loopbackMsgPtr[__nesc_mote]);
    return 0;
  }

  /* Module PoolP$0 */
  if (!strcmp(varname, "/*CtpP.MessagePoolP.PoolP*/PoolP$0$free"))
  {
    *addr = (uintptr_t)&/*CtpP.MessagePoolP.PoolP*/PoolP$0$free[__nesc_mote];
    *size = sizeof(/*CtpP.MessagePoolP.PoolP*/PoolP$0$free[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*CtpP.MessagePoolP.PoolP*/PoolP$0$index"))
  {
    *addr = (uintptr_t)&/*CtpP.MessagePoolP.PoolP*/PoolP$0$index[__nesc_mote];
    *size = sizeof(/*CtpP.MessagePoolP.PoolP*/PoolP$0$index[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*CtpP.MessagePoolP.PoolP*/PoolP$0$queue"))
  {
    *addr = (uintptr_t)&/*CtpP.MessagePoolP.PoolP*/PoolP$0$queue[__nesc_mote];
    *size = sizeof(/*CtpP.MessagePoolP.PoolP*/PoolP$0$queue[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*CtpP.MessagePoolP.PoolP*/PoolP$0$pool"))
  {
    *addr = (uintptr_t)&/*CtpP.MessagePoolP.PoolP*/PoolP$0$pool[__nesc_mote];
    *size = sizeof(/*CtpP.MessagePoolP.PoolP*/PoolP$0$pool[__nesc_mote]);
    return 0;
  }

  /* Module PoolP$1 */
  if (!strcmp(varname, "/*CtpP.QEntryPoolP.PoolP*/PoolP$1$free"))
  {
    *addr = (uintptr_t)&/*CtpP.QEntryPoolP.PoolP*/PoolP$1$free[__nesc_mote];
    *size = sizeof(/*CtpP.QEntryPoolP.PoolP*/PoolP$1$free[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*CtpP.QEntryPoolP.PoolP*/PoolP$1$index"))
  {
    *addr = (uintptr_t)&/*CtpP.QEntryPoolP.PoolP*/PoolP$1$index[__nesc_mote];
    *size = sizeof(/*CtpP.QEntryPoolP.PoolP*/PoolP$1$index[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*CtpP.QEntryPoolP.PoolP*/PoolP$1$queue"))
  {
    *addr = (uintptr_t)&/*CtpP.QEntryPoolP.PoolP*/PoolP$1$queue[__nesc_mote];
    *size = sizeof(/*CtpP.QEntryPoolP.PoolP*/PoolP$1$queue[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*CtpP.QEntryPoolP.PoolP*/PoolP$1$pool"))
  {
    *addr = (uintptr_t)&/*CtpP.QEntryPoolP.PoolP*/PoolP$1$pool[__nesc_mote];
    *size = sizeof(/*CtpP.QEntryPoolP.PoolP*/PoolP$1$pool[__nesc_mote]);
    return 0;
  }

  /* Module QueueC$0 */
  if (!strcmp(varname, "/*CtpP.SendQueueP*/QueueC$0$queue"))
  {
    *addr = (uintptr_t)&/*CtpP.SendQueueP*/QueueC$0$queue[__nesc_mote];
    *size = sizeof(/*CtpP.SendQueueP*/QueueC$0$queue[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*CtpP.SendQueueP*/QueueC$0$head"))
  {
    *addr = (uintptr_t)&/*CtpP.SendQueueP*/QueueC$0$head[__nesc_mote];
    *size = sizeof(/*CtpP.SendQueueP*/QueueC$0$head[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*CtpP.SendQueueP*/QueueC$0$tail"))
  {
    *addr = (uintptr_t)&/*CtpP.SendQueueP*/QueueC$0$tail[__nesc_mote];
    *size = sizeof(/*CtpP.SendQueueP*/QueueC$0$tail[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*CtpP.SendQueueP*/QueueC$0$size"))
  {
    *addr = (uintptr_t)&/*CtpP.SendQueueP*/QueueC$0$size[__nesc_mote];
    *size = sizeof(/*CtpP.SendQueueP*/QueueC$0$size[__nesc_mote]);
    return 0;
  }

  /* Module LruCtpMsgCacheP$0 */
  if (!strcmp(varname, "/*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$cache"))
  {
    *addr = (uintptr_t)&/*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$cache[__nesc_mote];
    *size = sizeof(/*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$cache[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$first"))
  {
    *addr = (uintptr_t)&/*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$first[__nesc_mote];
    *size = sizeof(/*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$first[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$count"))
  {
    *addr = (uintptr_t)&/*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$count[__nesc_mote];
    *size = sizeof(/*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$count[__nesc_mote]);
    return 0;
  }

  /* Module LinkEstimatorP */
  if (!strcmp(varname, "LinkEstimatorP$NeighborTable"))
  {
    *addr = (uintptr_t)&LinkEstimatorP$NeighborTable[__nesc_mote];
    *size = sizeof(LinkEstimatorP$NeighborTable[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "LinkEstimatorP$linkEstSeq"))
  {
    *addr = (uintptr_t)&LinkEstimatorP$linkEstSeq[__nesc_mote];
    *size = sizeof(LinkEstimatorP$linkEstSeq[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "LinkEstimatorP$prevSentIdx"))
  {
    *addr = (uintptr_t)&LinkEstimatorP$prevSentIdx[__nesc_mote];
    *size = sizeof(LinkEstimatorP$prevSentIdx[__nesc_mote]);
    return 0;
  }

  /* Module AMQueueEntryP$0 */

  /* Module AMQueueImplP$0 */
  if (!strcmp(varname, "/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current"))
  {
    *addr = (uintptr_t)&/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current[__nesc_mote];
    *size = sizeof(/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$queue"))
  {
    *addr = (uintptr_t)&/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$queue[__nesc_mote];
    *size = sizeof(/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$queue[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$cancelMask"))
  {
    *addr = (uintptr_t)&/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$cancelMask[__nesc_mote];
    *size = sizeof(/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$cancelMask[__nesc_mote]);
    return 0;
  }

  /* Module EerParentSetEngineP$0 */
  if (!strcmp(varname, "/*CtpP.Router*/EerParentSetEngineP$0$ECNOff"))
  {
    *addr = (uintptr_t)&/*CtpP.Router*/EerParentSetEngineP$0$ECNOff[__nesc_mote];
    *size = sizeof(/*CtpP.Router*/EerParentSetEngineP$0$ECNOff[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*CtpP.Router*/EerParentSetEngineP$0$radioOn"))
  {
    *addr = (uintptr_t)&/*CtpP.Router*/EerParentSetEngineP$0$radioOn[__nesc_mote];
    *size = sizeof(/*CtpP.Router*/EerParentSetEngineP$0$radioOn[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*CtpP.Router*/EerParentSetEngineP$0$running"))
  {
    *addr = (uintptr_t)&/*CtpP.Router*/EerParentSetEngineP$0$running[__nesc_mote];
    *size = sizeof(/*CtpP.Router*/EerParentSetEngineP$0$running[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*CtpP.Router*/EerParentSetEngineP$0$sending"))
  {
    *addr = (uintptr_t)&/*CtpP.Router*/EerParentSetEngineP$0$sending[__nesc_mote];
    *size = sizeof(/*CtpP.Router*/EerParentSetEngineP$0$sending[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*CtpP.Router*/EerParentSetEngineP$0$justEvicted"))
  {
    *addr = (uintptr_t)&/*CtpP.Router*/EerParentSetEngineP$0$justEvicted[__nesc_mote];
    *size = sizeof(/*CtpP.Router*/EerParentSetEngineP$0$justEvicted[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*CtpP.Router*/EerParentSetEngineP$0$routeInfo"))
  {
    *addr = (uintptr_t)&/*CtpP.Router*/EerParentSetEngineP$0$routeInfo[__nesc_mote];
    *size = sizeof(/*CtpP.Router*/EerParentSetEngineP$0$routeInfo[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*CtpP.Router*/EerParentSetEngineP$0$state_is_root"))
  {
    *addr = (uintptr_t)&/*CtpP.Router*/EerParentSetEngineP$0$state_is_root[__nesc_mote];
    *size = sizeof(/*CtpP.Router*/EerParentSetEngineP$0$state_is_root[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*CtpP.Router*/EerParentSetEngineP$0$my_ll_addr"))
  {
    *addr = (uintptr_t)&/*CtpP.Router*/EerParentSetEngineP$0$my_ll_addr[__nesc_mote];
    *size = sizeof(/*CtpP.Router*/EerParentSetEngineP$0$my_ll_addr[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*CtpP.Router*/EerParentSetEngineP$0$beaconMsgBuffer"))
  {
    *addr = (uintptr_t)&/*CtpP.Router*/EerParentSetEngineP$0$beaconMsgBuffer[__nesc_mote];
    *size = sizeof(/*CtpP.Router*/EerParentSetEngineP$0$beaconMsgBuffer[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*CtpP.Router*/EerParentSetEngineP$0$beaconMsg"))
  {
    *addr = (uintptr_t)&/*CtpP.Router*/EerParentSetEngineP$0$beaconMsg[__nesc_mote];
    *size = sizeof(/*CtpP.Router*/EerParentSetEngineP$0$beaconMsg[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*CtpP.Router*/EerParentSetEngineP$0$routingTable"))
  {
    *addr = (uintptr_t)&/*CtpP.Router*/EerParentSetEngineP$0$routingTable[__nesc_mote];
    *size = sizeof(/*CtpP.Router*/EerParentSetEngineP$0$routingTable[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*CtpP.Router*/EerParentSetEngineP$0$routingTableActive"))
  {
    *addr = (uintptr_t)&/*CtpP.Router*/EerParentSetEngineP$0$routingTableActive[__nesc_mote];
    *size = sizeof(/*CtpP.Router*/EerParentSetEngineP$0$routingTableActive[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*CtpP.Router*/EerParentSetEngineP$0$currentInterval"))
  {
    *addr = (uintptr_t)&/*CtpP.Router*/EerParentSetEngineP$0$currentInterval[__nesc_mote];
    *size = sizeof(/*CtpP.Router*/EerParentSetEngineP$0$currentInterval[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*CtpP.Router*/EerParentSetEngineP$0$t"))
  {
    *addr = (uintptr_t)&/*CtpP.Router*/EerParentSetEngineP$0$t[__nesc_mote];
    *size = sizeof(/*CtpP.Router*/EerParentSetEngineP$0$t[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*CtpP.Router*/EerParentSetEngineP$0$tHasPassed"))
  {
    *addr = (uintptr_t)&/*CtpP.Router*/EerParentSetEngineP$0$tHasPassed[__nesc_mote];
    *size = sizeof(/*CtpP.Router*/EerParentSetEngineP$0$tHasPassed[__nesc_mote]);
    return 0;
  }

  /* Module EerParentSelectionP$0 */
  if (!strcmp(varname, "/*CtpP.ParentSelector*/EerParentSelectionP$0$parentSetTable"))
  {
    *addr = (uintptr_t)&/*CtpP.ParentSelector*/EerParentSelectionP$0$parentSetTable[__nesc_mote];
    *size = sizeof(/*CtpP.ParentSelector*/EerParentSelectionP$0$parentSetTable[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*CtpP.ParentSelector*/EerParentSelectionP$0$parentSetPathETX"))
  {
    *addr = (uintptr_t)&/*CtpP.ParentSelector*/EerParentSelectionP$0$parentSetPathETX[__nesc_mote];
    *size = sizeof(/*CtpP.ParentSelector*/EerParentSelectionP$0$parentSetPathETX[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*CtpP.ParentSelector*/EerParentSelectionP$0$prntSet"))
  {
    *addr = (uintptr_t)&/*CtpP.ParentSelector*/EerParentSelectionP$0$prntSet[__nesc_mote];
    *size = sizeof(/*CtpP.ParentSelector*/EerParentSelectionP$0$prntSet[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*CtpP.ParentSelector*/EerParentSelectionP$0$rand_prnt"))
  {
    *addr = (uintptr_t)&/*CtpP.ParentSelector*/EerParentSelectionP$0$rand_prnt[__nesc_mote];
    *size = sizeof(/*CtpP.ParentSelector*/EerParentSelectionP$0$rand_prnt[__nesc_mote]);
    return 0;
  }
  if (!strcmp(varname, "/*CtpP.ParentSelector*/EerParentSelectionP$0$parent_init_flag"))
  {
    *addr = (uintptr_t)&/*CtpP.ParentSelector*/EerParentSelectionP$0$parent_init_flag[__nesc_mote];
    *size = sizeof(/*CtpP.ParentSelector*/EerParentSelectionP$0$parent_init_flag[__nesc_mote]);
    return 0;
  }

  /* Module RandomMlcgC */
  if (!strcmp(varname, "RandomMlcgC$seed"))
  {
    *addr = (uintptr_t)&RandomMlcgC$seed[__nesc_mote];
    *size = sizeof(RandomMlcgC$seed[__nesc_mote]);
    return 0;
  }

  /* Module AMQueueEntryP$1 */

  /* Module DummyActiveMessageP */

  /* Module EerInstrumentationP */
  if (!strcmp(varname, "EerInstrumentationP$stats"))
  {
    *addr = (uintptr_t)&EerInstrumentationP$stats[__nesc_mote];
    *size = sizeof(EerInstrumentationP$stats[__nesc_mote]);
    return 0;
  }

  /* Module EerHealthP */
  if (!strcmp(varname, "EerHealthP$hlth"))
  {
    *addr = (uintptr_t)&EerHealthP$hlth[__nesc_mote];
    *size = sizeof(EerHealthP$hlth[__nesc_mote]);
    return 0;
  }

  /* Module CollectionIdP$0 */

  return -1;
}
/* Invoke static initialisers for mote '__nesc_mote' */

static void __nesc_nido_initialise(int __nesc_mote)
{
  /* Module LapTestC */
  memset((void *)&LapTestC$data_pkt[__nesc_mote], 0, sizeof LapTestC$data_pkt[__nesc_mote]);
  LapTestC$radioBusy[__nesc_mote] = FALSE;
  LapTestC$rounds[__nesc_mote] = 0;
  LapTestC$i[__nesc_mote] = 0;
  LapTestC$counter[__nesc_mote] = 0;
  LapTestC$parent[__nesc_mote] = 0xFFFF;

  /* Module PlatformP */

  /* Module MotePlatformP */

  /* Module HplAtm128GeneralIOPinP$0 */

  /* Module HplAtm128GeneralIOPinP$1 */

  /* Module HplAtm128GeneralIOPinP$2 */

  /* Module HplAtm128GeneralIOPinP$3 */

  /* Module HplAtm128GeneralIOPinP$4 */

  /* Module HplAtm128GeneralIOPinP$5 */

  /* Module HplAtm128GeneralIOPinP$6 */

  /* Module HplAtm128GeneralIOPinP$7 */

  /* Module HplAtm128GeneralIOPinP$8 */

  /* Module HplAtm128GeneralIOPinP$9 */

  /* Module HplAtm128GeneralIOPinP$10 */

  /* Module HplAtm128GeneralIOPinP$11 */

  /* Module HplAtm128GeneralIOPinP$12 */

  /* Module HplAtm128GeneralIOPinP$13 */

  /* Module HplAtm128GeneralIOPinP$14 */

  /* Module HplAtm128GeneralIOPinP$15 */

  /* Module HplAtm128GeneralIOPinP$16 */

  /* Module HplAtm128GeneralIOPinP$17 */

  /* Module HplAtm128GeneralIOPinP$18 */

  /* Module HplAtm128GeneralIOPinP$19 */

  /* Module HplAtm128GeneralIOPinP$20 */

  /* Module HplAtm128GeneralIOPinP$21 */

  /* Module HplAtm128GeneralIOPinP$22 */

  /* Module HplAtm128GeneralIOPinP$23 */

  /* Module HplAtm128GeneralIOPinP$24 */

  /* Module HplAtm128GeneralIOPinP$25 */

  /* Module HplAtm128GeneralIOPinP$26 */

  /* Module HplAtm128GeneralIOPinP$27 */

  /* Module HplAtm128GeneralIOPinP$28 */

  /* Module HplAtm128GeneralIOPinP$29 */

  /* Module HplAtm128GeneralIOPinP$30 */

  /* Module HplAtm128GeneralIOPinP$31 */

  /* Module HplAtm128GeneralIOPinP$32 */

  /* Module HplAtm128GeneralIOPinP$33 */

  /* Module HplAtm128GeneralIOPinP$34 */

  /* Module HplAtm128GeneralIOPinP$35 */

  /* Module HplAtm128GeneralIOPinP$36 */

  /* Module HplAtm128GeneralIOPinP$37 */

  /* Module HplAtm128GeneralIOPinP$38 */

  /* Module HplAtm128GeneralIOPinP$39 */

  /* Module HplAtm128GeneralIOPinP$40 */

  /* Module HplAtm128GeneralIOPinP$41 */

  /* Module HplAtm128GeneralIOPinP$42 */

  /* Module HplAtm128GeneralIOPinP$43 */

  /* Module HplAtm128GeneralIOPinP$44 */

  /* Module HplAtm128GeneralIOPinP$45 */

  /* Module HplAtm128GeneralIOPinP$46 */

  /* Module HplAtm128GeneralIOPinP$47 */

  /* Module HplAtm128GeneralIOSlowPinP$0 */

  /* Module HplAtm128GeneralIOSlowPinP$1 */

  /* Module HplAtm128GeneralIOSlowPinP$2 */

  /* Module HplAtm128GeneralIOSlowPinP$3 */

  /* Module HplAtm128GeneralIOSlowPinP$4 */

  /* Module HplAtm128GeneralIOSlowPinP$5 */

  /* Module HplAtm128GeneralIOSlowPinP$6 */

  /* Module HplAtm128GeneralIOSlowPinP$7 */

  /* Module HplAtm128GeneralIOSlowPinP$8 */

  /* Module HplAtm128GeneralIOSlowPinP$9 */

  /* Module HplAtm128GeneralIOSlowPinP$10 */

  /* Module HplAtm128GeneralIOSlowPinP$11 */

  /* Module HplAtm128GeneralIOSlowPinP$12 */

  /* Module MeasureClockC */

  /* Module SimMainP */

  /* Module SimSchedulerBasicP */
  memset((void *)&SimSchedulerBasicP$m_head[__nesc_mote], 0, sizeof SimSchedulerBasicP$m_head[__nesc_mote]);
  memset((void *)&SimSchedulerBasicP$m_tail[__nesc_mote], 0, sizeof SimSchedulerBasicP$m_tail[__nesc_mote]);
  memset((void *)&SimSchedulerBasicP$m_next[__nesc_mote], 0, sizeof SimSchedulerBasicP$m_next[__nesc_mote]);
  SimSchedulerBasicP$sim_scheduler_event_pending[__nesc_mote] = FALSE;
  memset((void *)&SimSchedulerBasicP$sim_scheduler_event[__nesc_mote], 0, sizeof SimSchedulerBasicP$sim_scheduler_event[__nesc_mote]);

  /* Module SimMoteP */
  memset((void *)&SimMoteP$euid[__nesc_mote], 0, sizeof SimMoteP$euid[__nesc_mote]);
  memset((void *)&SimMoteP$startTime[__nesc_mote], 0, sizeof SimMoteP$startTime[__nesc_mote]);
  memset((void *)&SimMoteP$isOn[__nesc_mote], 0, sizeof SimMoteP$isOn[__nesc_mote]);
  memset((void *)&SimMoteP$bootEvent[__nesc_mote], 0, sizeof SimMoteP$bootEvent[__nesc_mote]);

  /* Module TossimActiveMessageC */
  memset((void *)&TossimActiveMessageC$buffer[__nesc_mote], 0, sizeof TossimActiveMessageC$buffer[__nesc_mote]);
  TossimActiveMessageC$bufferPointer[__nesc_mote] = &TossimActiveMessageC$buffer[__nesc_mote];

  /* Module TossimPacketModelC */
  TossimPacketModelC$initialized[__nesc_mote] = FALSE;
  TossimPacketModelC$running[__nesc_mote] = FALSE;
  memset((void *)&TossimPacketModelC$backoffCount[__nesc_mote], 0, sizeof TossimPacketModelC$backoffCount[__nesc_mote]);
  memset((void *)&TossimPacketModelC$neededFreeSamples[__nesc_mote], 0, sizeof TossimPacketModelC$neededFreeSamples[__nesc_mote]);
  TossimPacketModelC$sending[__nesc_mote] = (void *)0;
  TossimPacketModelC$transmitting[__nesc_mote] = FALSE;
  TossimPacketModelC$sendingLength[__nesc_mote] = 0;
  memset((void *)&TossimPacketModelC$destNode[__nesc_mote], 0, sizeof TossimPacketModelC$destNode[__nesc_mote]);
  memset((void *)&TossimPacketModelC$sendEvent[__nesc_mote], 0, sizeof TossimPacketModelC$sendEvent[__nesc_mote]);
  TossimPacketModelC$error[__nesc_mote] = 0;

  /* Module CpmModelC */
  memset((void *)&CpmModelC$outgoing[__nesc_mote], 0, sizeof CpmModelC$outgoing[__nesc_mote]);
  memset((void *)&CpmModelC$requestAck[__nesc_mote], 0, sizeof CpmModelC$requestAck[__nesc_mote]);
  CpmModelC$receiving[__nesc_mote] = 0;
  CpmModelC$transmitting[__nesc_mote] = 0;
  memset((void *)&CpmModelC$transmissionEndTime[__nesc_mote], 0, sizeof CpmModelC$transmissionEndTime[__nesc_mote]);
  CpmModelC$outstandingReceptionHead[__nesc_mote] = (void *)0;
  CpmModelC$clearThreshold[__nesc_mote] = -72.0;

  /* Module ActiveMessageAddressC */
  ActiveMessageAddressC$set[__nesc_mote] = FALSE;
  memset((void *)&ActiveMessageAddressC$addr[__nesc_mote], 0, sizeof ActiveMessageAddressC$addr[__nesc_mote]);

  /* Module LedsP */

  /* Module Atm128AlarmAsyncP$0 */
  memset((void *)&/*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$set[__nesc_mote], 0, sizeof /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$set[__nesc_mote]);
  memset((void *)&/*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$t0[__nesc_mote], 0, sizeof /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$t0[__nesc_mote]);
  memset((void *)&/*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$dt[__nesc_mote], 0, sizeof /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$dt[__nesc_mote]);
  memset((void *)&/*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$base[__nesc_mote], 0, sizeof /*AlarmCounterMilliP.Atm128AlarmAsyncC.Atm128AlarmAsyncP*/Atm128AlarmAsyncP$0$base[__nesc_mote]);

  /* Module HplAtm128Timer0AsyncP */
  HplAtm128Timer0AsyncP$inOverflow[__nesc_mote] = 0;
  HplAtm128Timer0AsyncP$lastZero[__nesc_mote] = 0;
  HplAtm128Timer0AsyncP$oldScale[__nesc_mote] = AVR_CLOCK_OFF;
  memset((void *)&HplAtm128Timer0AsyncP$compare[__nesc_mote], 0, sizeof HplAtm128Timer0AsyncP$compare[__nesc_mote]);
  memset((void *)&HplAtm128Timer0AsyncP$overflow[__nesc_mote], 0, sizeof HplAtm128Timer0AsyncP$overflow[__nesc_mote]);

  /* Module AlarmToTimerC$0 */
  memset((void *)&/*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$m_dt[__nesc_mote], 0, sizeof /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$m_dt[__nesc_mote]);
  memset((void *)&/*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$m_oneshot[__nesc_mote], 0, sizeof /*HilTimerMilliC.AlarmToTimerC*/AlarmToTimerC$0$m_oneshot[__nesc_mote]);

  /* Module VirtualizeTimerC$0 */
  memset((void *)&/*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$m_timers[__nesc_mote], 0, sizeof /*HilTimerMilliC.VirtualizeTimerC*/VirtualizeTimerC$0$m_timers[__nesc_mote]);

  /* Module CounterToLocalTimeC$0 */

  /* Module CtpForwardingEngineP$0 */
  /*CtpP.Forwarder*/CtpForwardingEngineP$0$forwardingState[__nesc_mote] = 0;
  memset((void *)&/*CtpP.Forwarder*/CtpForwardingEngineP$0$lastParent[__nesc_mote], 0, sizeof /*CtpP.Forwarder*/CtpForwardingEngineP$0$lastParent[__nesc_mote]);
  memset((void *)&/*CtpP.Forwarder*/CtpForwardingEngineP$0$seqno[__nesc_mote], 0, sizeof /*CtpP.Forwarder*/CtpForwardingEngineP$0$seqno[__nesc_mote]);
  memset((void *)&/*CtpP.Forwarder*/CtpForwardingEngineP$0$clientEntries[__nesc_mote], 0, sizeof /*CtpP.Forwarder*/CtpForwardingEngineP$0$clientEntries[__nesc_mote]);
  memset((void *)&/*CtpP.Forwarder*/CtpForwardingEngineP$0$clientPtrs[__nesc_mote], 0, sizeof /*CtpP.Forwarder*/CtpForwardingEngineP$0$clientPtrs[__nesc_mote]);
  memset((void *)&/*CtpP.Forwarder*/CtpForwardingEngineP$0$loopbackMsg[__nesc_mote], 0, sizeof /*CtpP.Forwarder*/CtpForwardingEngineP$0$loopbackMsg[__nesc_mote]);
  memset((void *)&/*CtpP.Forwarder*/CtpForwardingEngineP$0$loopbackMsgPtr[__nesc_mote], 0, sizeof /*CtpP.Forwarder*/CtpForwardingEngineP$0$loopbackMsgPtr[__nesc_mote]);

  /* Module PoolP$0 */
  memset((void *)&/*CtpP.MessagePoolP.PoolP*/PoolP$0$free[__nesc_mote], 0, sizeof /*CtpP.MessagePoolP.PoolP*/PoolP$0$free[__nesc_mote]);
  memset((void *)&/*CtpP.MessagePoolP.PoolP*/PoolP$0$index[__nesc_mote], 0, sizeof /*CtpP.MessagePoolP.PoolP*/PoolP$0$index[__nesc_mote]);
  memset((void *)&/*CtpP.MessagePoolP.PoolP*/PoolP$0$queue[__nesc_mote], 0, sizeof /*CtpP.MessagePoolP.PoolP*/PoolP$0$queue[__nesc_mote]);
  memset((void *)&/*CtpP.MessagePoolP.PoolP*/PoolP$0$pool[__nesc_mote], 0, sizeof /*CtpP.MessagePoolP.PoolP*/PoolP$0$pool[__nesc_mote]);

  /* Module PoolP$1 */
  memset((void *)&/*CtpP.QEntryPoolP.PoolP*/PoolP$1$free[__nesc_mote], 0, sizeof /*CtpP.QEntryPoolP.PoolP*/PoolP$1$free[__nesc_mote]);
  memset((void *)&/*CtpP.QEntryPoolP.PoolP*/PoolP$1$index[__nesc_mote], 0, sizeof /*CtpP.QEntryPoolP.PoolP*/PoolP$1$index[__nesc_mote]);
  memset((void *)&/*CtpP.QEntryPoolP.PoolP*/PoolP$1$queue[__nesc_mote], 0, sizeof /*CtpP.QEntryPoolP.PoolP*/PoolP$1$queue[__nesc_mote]);
  memset((void *)&/*CtpP.QEntryPoolP.PoolP*/PoolP$1$pool[__nesc_mote], 0, sizeof /*CtpP.QEntryPoolP.PoolP*/PoolP$1$pool[__nesc_mote]);

  /* Module QueueC$0 */
  memset((void *)&/*CtpP.SendQueueP*/QueueC$0$queue[__nesc_mote], 0, sizeof /*CtpP.SendQueueP*/QueueC$0$queue[__nesc_mote]);
  /*CtpP.SendQueueP*/QueueC$0$head[__nesc_mote] = 0;
  /*CtpP.SendQueueP*/QueueC$0$tail[__nesc_mote] = 0;
  /*CtpP.SendQueueP*/QueueC$0$size[__nesc_mote] = 0;

  /* Module LruCtpMsgCacheP$0 */
  memset((void *)&/*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$cache[__nesc_mote], 0, sizeof /*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$cache[__nesc_mote]);
  memset((void *)&/*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$first[__nesc_mote], 0, sizeof /*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$first[__nesc_mote]);
  memset((void *)&/*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$count[__nesc_mote], 0, sizeof /*CtpP.SentCacheP.CacheP*/LruCtpMsgCacheP$0$count[__nesc_mote]);

  /* Module LinkEstimatorP */
  memset((void *)&LinkEstimatorP$NeighborTable[__nesc_mote], 0, sizeof LinkEstimatorP$NeighborTable[__nesc_mote]);
  LinkEstimatorP$linkEstSeq[__nesc_mote] = 0;
  LinkEstimatorP$prevSentIdx[__nesc_mote] = 0;

  /* Module AMQueueEntryP$0 */

  /* Module AMQueueImplP$0 */
  /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$current[__nesc_mote] = 2;
  memset((void *)&/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$queue[__nesc_mote], 0, sizeof /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$queue[__nesc_mote]);
  memset((void *)&/*AMQueueP.AMQueueImplP*/AMQueueImplP$0$cancelMask[__nesc_mote], 0, sizeof /*AMQueueP.AMQueueImplP*/AMQueueImplP$0$cancelMask[__nesc_mote]);

  /* Module EerParentSetEngineP$0 */
  /*CtpP.Router*/EerParentSetEngineP$0$ECNOff[__nesc_mote] = TRUE;
  /*CtpP.Router*/EerParentSetEngineP$0$radioOn[__nesc_mote] = FALSE;
  /*CtpP.Router*/EerParentSetEngineP$0$running[__nesc_mote] = FALSE;
  /*CtpP.Router*/EerParentSetEngineP$0$sending[__nesc_mote] = FALSE;
  /*CtpP.Router*/EerParentSetEngineP$0$justEvicted[__nesc_mote] = FALSE;
  memset((void *)&/*CtpP.Router*/EerParentSetEngineP$0$routeInfo[__nesc_mote], 0, sizeof /*CtpP.Router*/EerParentSetEngineP$0$routeInfo[__nesc_mote]);
  memset((void *)&/*CtpP.Router*/EerParentSetEngineP$0$state_is_root[__nesc_mote], 0, sizeof /*CtpP.Router*/EerParentSetEngineP$0$state_is_root[__nesc_mote]);
  memset((void *)&/*CtpP.Router*/EerParentSetEngineP$0$my_ll_addr[__nesc_mote], 0, sizeof /*CtpP.Router*/EerParentSetEngineP$0$my_ll_addr[__nesc_mote]);
  memset((void *)&/*CtpP.Router*/EerParentSetEngineP$0$beaconMsgBuffer[__nesc_mote], 0, sizeof /*CtpP.Router*/EerParentSetEngineP$0$beaconMsgBuffer[__nesc_mote]);
  memset((void *)&/*CtpP.Router*/EerParentSetEngineP$0$beaconMsg[__nesc_mote], 0, sizeof /*CtpP.Router*/EerParentSetEngineP$0$beaconMsg[__nesc_mote]);
  memset((void *)&/*CtpP.Router*/EerParentSetEngineP$0$routingTable[__nesc_mote], 0, sizeof /*CtpP.Router*/EerParentSetEngineP$0$routingTable[__nesc_mote]);
  memset((void *)&/*CtpP.Router*/EerParentSetEngineP$0$routingTableActive[__nesc_mote], 0, sizeof /*CtpP.Router*/EerParentSetEngineP$0$routingTableActive[__nesc_mote]);
  /*CtpP.Router*/EerParentSetEngineP$0$currentInterval[__nesc_mote] = 128;
  memset((void *)&/*CtpP.Router*/EerParentSetEngineP$0$t[__nesc_mote], 0, sizeof /*CtpP.Router*/EerParentSetEngineP$0$t[__nesc_mote]);
  memset((void *)&/*CtpP.Router*/EerParentSetEngineP$0$tHasPassed[__nesc_mote], 0, sizeof /*CtpP.Router*/EerParentSetEngineP$0$tHasPassed[__nesc_mote]);

  /* Module EerParentSelectionP$0 */
  memset((void *)&/*CtpP.ParentSelector*/EerParentSelectionP$0$parentSetTable[__nesc_mote], 0, sizeof /*CtpP.ParentSelector*/EerParentSelectionP$0$parentSetTable[__nesc_mote]);
  memset((void *)&/*CtpP.ParentSelector*/EerParentSelectionP$0$parentSetPathETX[__nesc_mote], 0, sizeof /*CtpP.ParentSelector*/EerParentSelectionP$0$parentSetPathETX[__nesc_mote]);
  memset((void *)&/*CtpP.ParentSelector*/EerParentSelectionP$0$prntSet[__nesc_mote], 0, sizeof /*CtpP.ParentSelector*/EerParentSelectionP$0$prntSet[__nesc_mote]);
  memset((void *)&/*CtpP.ParentSelector*/EerParentSelectionP$0$rand_prnt[__nesc_mote], 0, sizeof /*CtpP.ParentSelector*/EerParentSelectionP$0$rand_prnt[__nesc_mote]);
  /*CtpP.ParentSelector*/EerParentSelectionP$0$parent_init_flag[__nesc_mote] = FALSE;

  /* Module RandomMlcgC */
  memset((void *)&RandomMlcgC$seed[__nesc_mote], 0, sizeof RandomMlcgC$seed[__nesc_mote]);

  /* Module AMQueueEntryP$1 */

  /* Module DummyActiveMessageP */

  /* Module EerInstrumentationP */
  memset((void *)&EerInstrumentationP$stats[__nesc_mote], 0, sizeof EerInstrumentationP$stats[__nesc_mote]);

  /* Module EerHealthP */
  memset((void *)&EerHealthP$hlth[__nesc_mote], 0, sizeof EerHealthP$hlth[__nesc_mote]);

  /* Module CollectionIdP$0 */

}
