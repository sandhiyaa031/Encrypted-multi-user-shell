k#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define PEPPER "s3cure_shell_key"
#define MAX_LINE 2048
#define MAX_CMD 1024

// Build key exactly like in shell.c
void make_key(const char *username, char *out, size_t outsz) {
    snprintf(out, outsz, "%s:%s", username, PEPPER);
}

// XOR decrypt (same as encrypt)
void xor_crypt(const unsigned char *in, size_t len,
               const unsigned char *key, size_t keylen,
               unsigned char *out) {
    for (size_t i = 0; i < len; i++) {
        out[i] = in[i] ^ key[i % keylen];
    }
}

// Convert hex string to bytes
size_t hex_decode(const char *hex, unsigned char *out) {
    size_t len = strlen(hex);
    size_t out_len = 0;
    for (size_t i = 0; i < len; i += 2) {
        unsigned int byte;
        sscanf(hex + i, "%02x", &byte);
        out[out_len++] = (unsigned char)byte;
    }
    return out_len;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <username> <history_file>\n", argv[0]);
        return 1;
    }

    const char *username = argv[1];
    const char *filename = argv[2];

    FILE *f = fopen(filename, "r");
    if (!f) {
        perror("fopen");
        return 1;
    }

    char line[MAX_LINE];
    char key[256];
    make_key(username, key, sizeof(key));

    while (fgets(line, sizeof(line), f)) {
        char timestamp[64], hex[MAX_CMD];
        if (sscanf(line, "%63s %s", timestamp, hex) != 2) continue;

        unsigned char enc_bytes[MAX_CMD], dec_bytes[MAX_CMD];
        size_t enc_len = hex_decode(hex, enc_bytes);

        xor_crypt(enc_bytes, enc_len, (unsigned char *)key, strlen(key), dec_bytes);
        dec_bytes[enc_len] = '\0'; // null-terminate

        printf("%s %s\n", timestamp, dec_bytes);
    }

    fclose(f);
    return 0;
}

