#include <stdio.h>                                                                                                              
#include <stdlib.h>                                                                                                             
#include <string.h>                                                                                                             
#include <unistd.h>                                                                                                             
#include <sys/wait.h>
#include "shell.h"                                                                                                           
/* #include "program_to_path.c" */                                                                                                    
extern char **environ;                                                                                                          
int main(void)                                                                                                                  
{                                                                                                                               
        char *line;                                                                                                             
        char *line_duplicate;                                                                                                   
        size_t n = 0;                                                                                                           
        ssize_t read_num;                                                                                                       
        char *token;                                                                                                            
        /* char *delim = " \n";  */
        char *delim = "\n";                                                                                                    
                                                                                                   
        int n_tokens = 0, token_index = 0;                                                                                      
        char **argv;                                                                                                            
        /* int argv_print_index = 0; */                                                                                               
        pid_t child_a;                                                                                                          
        int status; 

        (void) n_tokens;
        (void) token_index;
        writer("#cisfun$ ");                                                                                                    
        read_num = getline(&line, &n, stdin);                                                                                   
        if (read_num == -1)                                                                                                     
        {                                                                                                                       
/*                 writer("Exiting shell ....\n");                                                                                 
 */                return (-1);                                                                                                    
        }                                                                                                                       
        line_duplicate = malloc(read_num * sizeof(char));                                                                       
        _strcpy(line_duplicate, line);                                                                                           
        token = _strtok(line, delim);                                                                                            
        /* walk through other tokens */                                                                                         
        while(token != NULL)                                                                                                    
        {                                                                                                                       
                n_tokens++;                                                                                                     
                token = _strtok(NULL, delim);                                                                                    
        }                                                                                                                       
        n_tokens++;                                                                                                             
        argv = malloc(n_tokens * sizeof(char*));  
        argv[0] = line;                                                                              
        token = _strtok(line_duplicate, delim);                                                                                  
        while(token != NULL)
        {                                                                                                                       
                argv[token_index] = malloc(_strlen(token) * sizeof(char));                                                       
                _strcpy(argv[token_index], token);                                                                               
                token_index++;                                                                                                  
                token = _strtok(NULL, delim);                                                                                    
        }                                                                                                                       
        argv[token_index] = NULL;                                                                                               
        /*builtin_commands(argv[0]);                                                                                          
        argv[0] = progf_to_progp(argv[0]);                                                                                  
        writer("progf_to_progp(argv[0]) %s \n", progf_to_progp(argv[0]));*/                                                   
        child_a = fork();                                                                                                       
        if (child_a == -1)                                                                                                      
        {                                                                                                                       
                perror("Error:");                                                                                               
                return (1);                                                                                                     
        }                                                                                                                       
        if (child_a == 0)                                                                                                       
        {    
                if (execve(argv[0], argv, environ) == -1)                                                                       
                {
                    perror("./shell");                                                                                       
                }                                                                                                               
        }                                                                                                                       
        wait(&status);                                                                                                          
        main();                                                                                                                 
                                                                                                                                
        return(0);                                
}