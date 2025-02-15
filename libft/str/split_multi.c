#include "libft.h"
#include <stdlib.h>

static size_t count_tokens(const char *s, const char *delimiters) {
    size_t count = 0;
    int in_token = 0;

    while (*s) {
        if (ft_strchr(delimiters, *s)) {
            in_token = 0;
        } else if (!in_token) {
            in_token = 1;
            count++;
        }
        s++;
    }
    return count;
}

static char *copy_token(const char *start, size_t length) {
    char *token = (char *)malloc(length + 1);
    if (token) {
        ft_strlcpy(token, start, length + 1);
    }
    return token;
}

static void extract_tokens(char **tokens, const char *s, const char *delimiters) {
    size_t token_index = 0;
    const char *token_start = NULL;

    while (*s) {
        if (ft_strchr(delimiters, *s)) {
            if (token_start) {
                tokens[token_index++] = copy_token(token_start, s - token_start);
                token_start = NULL;
            }
        } else if (!token_start) {
            token_start = s;
        }
        s++;
    }
    if (token_start) {
        tokens[token_index] = copy_token(token_start, s - token_start);
    }
}

char **split_multi(const char *s, const char *delimiters) {
    if (!s || !delimiters)
        return NULL;

    size_t num_tokens = count_tokens(s, delimiters);
    char **tokens = (char **)malloc((num_tokens + 1) * sizeof(char *));
    if (!tokens)
        return NULL;

    extract_tokens(tokens, s, delimiters);
    tokens[num_tokens] = NULL;
    return tokens;
}
