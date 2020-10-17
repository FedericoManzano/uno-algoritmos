

#define A_MAY(X)((X) >= 'a' && (X) <= 'z' ? (X) - ' ' : (X))
#define A_MIN(X)((X) >= 'A' && (X) <= 'Z' ? (X) + ' ' : (X))
#define ES_MIN(X)((X) >= 'a' && (X) <= 'z')
#define ES_MAY(X)((X) >= 'A' && (X) <= 'Z')
#define ES_NUM(X)((X) >= '0' && (X) <= '9')
#define UPPER(X)(ES_MIN(X) ? (X) -= ' ' : (X))
#define LOWER(X)(ES_MAY(X) ? (X) += ' ' : (X))
#define ES_BLANCO(X)((X) == ' ' || (X) == '\t')


char * str_cpy(char *, const char *);
int str_cmp(const char *, const char *);
int str_len(const char *);
char * str_chr(const char *, const char);
char * str_rchr(const char *, const char );
void * mem_cpy(void *, const void *, size_t);
char * str_cat(char *, const char *);
int str_ncmp(const char *, const char *, int);
char *str_str(const char*, const char *);
char * str_ncat(char *, const char *, int);
int str_cmpi(const char *, const char *);
int str_ncmpi(const char *, const char *, int);
char *str_upper(char *);
char *str_lower(char *);
size_t str_spn(const char *, const char *);
size_t str_cspn(const char *, const char *);


