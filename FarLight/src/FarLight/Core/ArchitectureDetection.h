#pragma once

#if defined(__x86_64__) || defined(_M_X64) || defined(__powerpc64__) || defined(__alpha__) || defined(__ia64__) || defined(__s390__) || defined(__s390x__) || defined(__arm64__) || defined(_aarch64_) || defined(__mips64) || defined(__mips64_)
#   define FL_ARCHITECTURE_X64
#else
#   define FL_ARCHITECTURE_X86
#endif
