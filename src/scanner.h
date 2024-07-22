#ifndef SRC_SCANNER_H_
#define SRC_SCANNER_H_

// clang-format off
#include <stdint.h>

enum TokenType {
  UNSET,

  LEFT_PAREN, RIGHT_PAREN,
  LEFT_BRACE, RIGHT_BRACE,

  COMMA, DOT, SEMICOLON,

  MINUS, PLUS, SLASH, STAR,
  BANG, BANG_EQUAL,
  EQUAL, EQUAL_EQUAL,
  GREATER, GREATER_EQUAL,
  LESS, LESS_EQUAL,

  IDENTIFIER, STRING, NUMBER,

  AND, CLASS, ELSE,
  BOOL_FALSE, BOOL_TRUE,
  FUNC, FOR, IF, NIL, OR,
  PRINT, RETURN, SUPER,
  SELF, VAR, WHILE,

  END_OF_FILE,

  ILLEGAL
};
// clang-format on

enum ResultStatus { RESULT_OK, RESULT_ERROR };

struct Lexeme {
  char *start;
  char *value;
  int length;
};

struct Token {
  struct Lexeme lexeme;
  enum TokenType type;
  float literal;
  int line;
};

struct Error {
  const char *where;
  const char *message;
  const char *chara;
  int line;
};

// TODO(bissakov):
// Need to think this one over
// if I choose to discard ILLEGAL tokens.
struct Result {
  struct Token token;
  struct Error error;
  enum ResultStatus status;
  int skip;
};

void ReportError(struct Error *error);

char *ConstructLexemeString(char *start, int length);
void GetToken(struct Token *token, enum TokenType type, float literal,
              int start, int current, char *source);

int IsAtEnd(int current, int source_length);
int Match(char expected_char, char *source, int source_length, int *current);
void ScanToken(struct Result *result, char *source, int source_length,
               int *line, int start, int *current);

void ScanTokens(char *source, int source_length, struct Token *tokens,
                int *current_token_idx);

void Run(char *source, uint32_t source_length);

#endif  // SRC_SCANNER_H_
