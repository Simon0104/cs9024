#define MAXLEN 128

/**
 * @brief Calculates the length of the string.
 *
 * The mystrlen() function calculates the length of the string pointed to by s, 
 * excluding the terminating null byte ('\0').  If no null byte is found within
 * the first MAXLEN bytes of the string, the function returns MAXLEN.
 *
 * @param s Pointer to the first character of a string.
 * @return  The length of the string s, or MAXLEN if no null byte found within 
 *          MAXLEN characters.
 */
int mystrlen(char *s);