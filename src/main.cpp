/**
 *  CPSC 323 Compilers and Languages
 * 
 *  Dalton Caron, Teaching Associate
 *  dcaron@fullerton.edu, +1 949-616-2699
 *  Department of Computer Science
 */
#include <cstdio>
#include <argp.h>
#include <lexer.h>

#define ARG_NUM 1

const char *argp_program_version = "CPSC 323 Student Compiler";
const char *argp_program_bug_address = "dcaron@fullerton.edu";
static char doc[] = "A compiler program for students.";
static char args_doc[] = "<source code file>";
static struct argp_option options[] = {
    { 0 }
};

struct arguments {
    char *args[ARG_NUM];
};

struct arguments arguments;

static error_t parse_opt(int key, char *arg, struct argp_state *state) {
    struct arguments *arguments = (struct arguments *) state->input;
    switch (key) {
        case ARGP_KEY_ARG:
            if (state->arg_num >= ARG_NUM) {
                // Too many arguments.
                argp_usage(state);
            }
            arguments->args[state->arg_num] = arg;
            break;
        case ARGP_KEY_END:
            if (state->arg_num < ARG_NUM) {
                // Not enough arguments.
                argp_usage(state);
            }
            break;
        default:
            return ARGP_ERR_UNKNOWN;
    }
    return 0;
}

static struct argp argp = { options, parse_opt, args_doc, doc, 0, 0, 0 };

int main(int argc, char *argv[]) {

    argp_parse(&argp, argc, argv, 0, 0, &arguments);

    char *source_file = arguments.args[0];

    if (source_file == NULL) {
        (void) printf("Please provide a source file.\n");
        return EXIT_SUCCESS;
    }

    Lexer lexer;
    const token_stream_t tokens = lexer.lex(source_file);

    for (auto i = tokens.begin(); i != tokens.end(); i++) {
        token_t token = *i;
        printf("(%s, %d)\n", token.lexeme.c_str(), token.type);
    }

    return EXIT_SUCCESS;
}