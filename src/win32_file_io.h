#ifndef SRC_WIN32_FILE_IO_H_
#define SRC_WIN32_FILE_IO_H_

#include <stdint.h>

struct FileResult {
  uint32_t file_size;
  void *content;
};

void FreeMemory(void **memory);
struct FileResult ReadEntireFile(char *file_path);

#endif  // SRC_WIN32_FILE_IO_H_
