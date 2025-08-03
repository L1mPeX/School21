#include "../s21_string.h"
#define ERRORS

typedef struct {
  int code;
  const char *message;
} errno_entry;

static const errno_entry common_errors[] = {
    {EPERM, "Operation not permitted"},
    {ENOENT, "No such file or directory"},
    {ESRCH, "No such process"},
    {EINTR, "Interrupted system call"},
    {EIO, "Input/output error"},
    {ENXIO, "No such device or address"},
    {E2BIG, "Argument list too long"},
    {ENOEXEC, "Exec format error"},
    {EBADF, "Bad file descriptor"},
    {ECHILD, "No child processes"},
    {EAGAIN, "Resource temporarily unavailable"},
    {ENOMEM, "Cannot allocate memory"},
    {EACCES, "Permission denied"},
    {EFAULT, "Bad address"},
    {EBUSY, "Resource busy"},
    {EEXIST, "File exists"},
    {EXDEV, "Cross-device link"},
    {ENODEV, "No such device"},
    {ENOTDIR, "Not a directory"},
    {EISDIR, "Is a directory"},
    {EINVAL, "Invalid argument"},
    {ENFILE, "Too many open files in system"},
    {EMFILE, "Too many open files"},
    {ENOTTY, "Inappropriate ioctl for device"},
    {ETXTBSY, "Text file busy"},
    {EFBIG, "File too large"},
    {ENOSPC, "No space left on device"},
    {ESPIPE, "Illegal seek"},
    {EROFS, "Read-only file system"},
    {EMLINK, "Too many links"},
    {EPIPE, "Broken pipe"},
    {EDOM, "Numerical argument out of domain"},
    {ERANGE, "Numerical result out of range"},
};

#if defined(__APPLE__)
static const errno_entry platform_errors[] = {
    {EDEADLK, "Resource deadlock avoided"},
    {ENAMETOOLONG, "File name too long"},
    {ENOLCK, "No locks available"},
    {ENOSYS, "Function not implemented"},
    {ENOTEMPTY, "Directory not empty"},
    {ELOOP, "Too many levels of symbolic links"},
    {EPROTOTYPE, "Protocol wrong type for socket"},
    {ENOPROTOOPT, "Protocol not available"},
    {EPROTONOSUPPORT, "Protocol not supported"},
    {ENOTSUP, "Operation not supported"},
    {EAFNOSUPPORT, "Address family not supported by protocol"},
    {EADDRINUSE, "Address already in use"},
    {EADDRNOTAVAIL, "Cannot assign requested address"},
    {ENETDOWN, "Network is down"},
    {ENETUNREACH, "Network is unreachable"},
    {ENETRESET, "Network dropped connection on reset"},
    {ECONNABORTED, "Software caused connection abort"},
    {ECONNRESET, "Connection reset by peer"},
    {ENOBUFS, "No buffer space available"},
    {EISCONN, "Transport endpoint is already connected"},
    {ENOTCONN, "Transport endpoint is not connected"},
    {ETIMEDOUT, "Connection timed out"},
    {ECONNREFUSED, "Connection refused"},
    {EHOSTUNREACH, "No route to host"},
    {EALREADY, "Operation already in progress"},
    {EINPROGRESS, "Operation now in progress"},
};
#else
static const errno_entry platform_errors[] = {
    {EPERM, "Operation not permitted"},
    {ENOENT, "No such file or directory"},
    {ESRCH, "No such process"},
    {EINTR, "Interrupted system call"},
    {EIO, "I/O error"},
    {ENXIO, "No such device or address"},
    {E2BIG, "Argument list too long"},
    {ENOEXEC, "Exec format error"},
    {EBADF, "Bad file descriptor"},
    {ECHILD, "No child process"},
    {EAGAIN, "Resource temporarily unavailable"},
    {ENOMEM, "Out of memory"},
    {EACCES, "Permission denied"},
    {EFAULT, "Bad address"},
    {EEXIST, "File exists"},
    {EXDEV, "Cross-device link"},
    {ENODEV, "No such device"},
    {ENOTDIR, "Not a directory"},
    {EISDIR, "Is a directory"},
    {ENFILE, "Too many open files in system"},
    {EMFILE, "No file descriptors available"},
    {ENOTTY, "Not a tty"},
    {ETXTBSY, "Text file busy"},
    {EFBIG, "File too large"},
    {ENOSPC, "No space left on device"},
    {ESPIPE, "Invalid seek"},
    {EROFS, "Read-only file system"},
    {EMLINK, "Too many links"},
    {EPIPE, "Broken pipe"},
    {EDOM, "Domain error"},
    {ERANGE, "Result not representable"},
    {EDEADLK, "Resource deadlock would occur"},
    {ENAMETOOLONG, "Filename too long"},
    {ENOLCK, "No locks available"},
    {ENOSYS, "Function not implemented"},
    {ENOTEMPTY, "Directory not empty"},
    {ELOOP, "Symbolic link loop"},
    {ENOMSG, "No message of desired type"},
    {EIDRM, "Identifier removed"},
    {EDEADLOCK, "Resource deadlock would occur"},
    {ENOSTR, "Device not a stream"},
    {ENODATA, "No data available"},
    {ETIME, "Device timeout"},
    {ENOSR, "Out of streams resources"},
    {ENOLINK, "Link has been severed"},
    {EPROTO, "Protocol error"},
    {EBADMSG, "Bad message"},
    {EOVERFLOW, "Value too large for data type"},
    {EILSEQ, "Illegal byte sequence"},
    {ENOTSOCK, "Not a socket"},
    {EDESTADDRREQ, "Destination address required"},
    {EMSGSIZE, "Message too large"},
    {EPROTOTYPE, "Protocol wrong type for socket"},
    {ENOPROTOOPT, "Protocol not available"},
    {EPROTONOSUPPORT, "Protocol not supported"},
    {EOPNOTSUPP, "Not supported"},
    {EAFNOSUPPORT, "Address family not supported by protocol"},
    {EADDRINUSE, "Address in use"},
    {EADDRNOTAVAIL, "Address not available"},
    {ENETDOWN, "Network is down"},
    {ENETUNREACH, "Network unreachable"},
    {ENETRESET, "Connection reset by network"},
    {ECONNABORTED, "Connection aborted"},
    {ECONNRESET, "Connection reset by peer"},
    {ENOBUFS, "No buffer space available"},
    {EISCONN, "Socket is connected"},
    {ENOTCONN, "Socket not connected"},
    {ETIMEDOUT, "Operation timed out"},
    {ECONNREFUSED, "Connection refused"},
    {EHOSTUNREACH, "Host is unreachable"},
    {EALREADY, "Operation already in progress"},
    {EINPROGRESS, "Operation in progress"},
    {ECANCELED, "Operation canceled"},
    {EOWNERDEAD, "Previous owner died"},
    {ENOTRECOVERABLE, "State not recoverable"},
    {15, "Block device required"},
    {72, "Multihop attempted"},
    {77, "File descriptor in bad state"},
    {94, "Socket type not supported"},
    {96, "Protocol family not supported"},
    {108, "Cannot send after socket shutdown"},
    {112, "Host is down"},
    {116, "Stale file handle"},
    {121, "Remote I/O error"},
    {122, "Quota exceeded"},
    {123, "No medium found"},
    {124, "Wrong medium type"},
    {126, "Required key not available"},
    {127, "Key has expired"},
    {128, "Key has been revoked"},
    {129, "Key was rejected by service"}};
#endif

char *s21_strerror(int errnum) {
  static char buffer[1024];

  char *res = S21_NULL;
  for (s21_size_t i = 0; i < sizeof(common_errors) / sizeof(common_errors[0]);
       i++) {
    if (common_errors[i].code == errnum) {
      res = (char *)common_errors[i].message;
      break;
    }
  }

  for (s21_size_t i = 0;
       i < sizeof(platform_errors) / sizeof(platform_errors[0]); i++) {
    if (platform_errors[i].code == errnum) {
      res = (char *)platform_errors[i].message;
      break;
    }
  }
  if (res == S21_NULL) {
#if defined(__APPLE__)
    if (errnum)
      snprintf(buffer, sizeof(buffer), "Unknown error: %d" errnum);
    else
      snprintf(buffer, sizeof(buffer), "Undefined error: %d" errnum);
#else
    snprintf(buffer, sizeof(buffer), "No error information");
#endif
    res = buffer;
  }
  return res;
}