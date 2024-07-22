#ifndef SRC_UTILS_H_
#define SRC_UTILS_H_

#include "../src/scanner.h"

#define ArraySize(arr) (sizeof(arr) / sizeof((arr)[0]))

// TODO(bissakov): Have DEV flags eventually.
#define Assert(expression) \
  if (!(expression)) {     \
    __debugbreak();        \
  }

const char *ToString(enum TokenType token_type);

#endif  // SRC_UTILS_H_
