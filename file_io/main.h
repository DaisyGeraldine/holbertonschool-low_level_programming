#ifndef MAIN_H
#define MAIN_H
ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
int messagges_Error(int codError, char *file, int filedes);
int safe_close(int filedes);
#endif
