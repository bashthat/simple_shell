#ifndef SOURCE_H
#define SOURCE_H

#define EOF	(-1)
#define ERRCHAR  (0)

#define INIT_SRC_POS	(-2)

struct source_s
{
	char *buffer; //input text
	long bufsize; //size of input
	long curpos; //absolute char position
};

char next_char(struct source_s *src);
void unget_char(struct source_s *src);
char peek_char(struct source_s *src);
void skip_white_spaces(struct source_s *src);

//node 

char *search_path(char *file);
int do_exec_cmd(int argc, char **argv);
int do_simple_command(struct node_s *node);


#endif
