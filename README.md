# CS431: COMPILER DESIGN LAB
## LAB SCHEDULE

LIST OF PROGRAMS:
---

CYCLE 1: 
### AUTOMATA CONCEPTS –10 marks 
    1) Write program to find ε – closure of all states of any given NFA with ε transition ( 2 marks)
    
    2) Write program to convert NFA with ε transition to NFA without ε transition. ( 2 marks)
    
    3) Write program to convert NFA to DFA. ( 3 marks)
    
    4) Write program to minimize any given DFA. ( 3 marks)  
    - Cycle 1 should be completed before 16/08/2018.

CYCLE 2:  
### LEX AND YACC – 15 marks  
    5) Design and implement a lexical analyzer for given language using C and the lexical analyzer should ignore redundant spaces, tabs and new line. (2 marks)
    
    6) Implementation of Lexical Analyzer using Lex Tool. (5 marks)
    
    7) Generate YACC specification for a few syntactic categories. 
	    a) Program to recognize a valid arithmetic expression that uses operator +, – , * and /. (2 marks)
	    b) Program to recognize a valid variable which starts with a letter followed by any number of letters or digits. (2 marks)
	    c) Implementation of Calculator using LEX and YACC. (2 marks)
	    d) Convert the BNF rules into YACC form and write code to generate abstract. (2 marks)

    - Cycle 2 should be completed before 13/09/2018.

CYCLE 3:  
### PARSER IMPLEMENTATION – 15 marks 
    
    8) Develop an operator precedence parser for a given language. (5 marks)
    
    9) Write program to find Simulate First and Follow of any given grammar. (3 marks)
    
    10) Construct a recursive descent parser for an expression. (3 marks)
    
    11) Construct a Shift Reduce Parser for a given language. (4 marks) 
    
    - Cycle 3 should be completed before 04/10/2018

CYCLE 4:  

    11) In this lab we are going to construct a compiler|interpreter for a simple imperative programming language. The CFG is given below.
    
        1) Program-> PROG declarations BEGIN command_sequence END

        2) declarations -> e |INTEGER id_seq IDENTIFIER.

        3) id_seq → e | id_seq IDENTIFIER,

        4) command_sequence ->e | command_sequence command ;

        5) command -> e
        | IDENTIFIER : =expression
        | IF exp THEN command_sequence ELSE command_sequence ENDIF
        | WHILE exp DO command_sequence ENDWHILE
        | READ IDENTIFIER
        | WRITE expression

        6) expression -> NUMBER | IDENTIFIER | ( expression )
        | expression + expression | expression * expression
        | expression - expression | expression / expression
        | expression = expression
        | expression < expression
        | expression > expression

        where the non-terminal symbols are given in all lowercase and the terminal symbols are given in all caps or as literal symbols. The start symbol is program. There are two context sensitive requirements for the language, variables must be declared before they are referenced and a variable may be declared only once.

        An example program is given below.
        
        prog
        integer a,b.
        begin
        read n;
        if a < 10 then b := 1; else; endif;
        while a < 10 do b := 5*a; a:= a+1; endwhile;
        write a;
        write b;
        end

        Generation of lexical analyzer and parser for our language.
        
        Input: A program in our language.
        Output: Whether a valid program or not .
            
    12) Creating a symbol table for our language, (linked list implementation) 

        Input: A programming language.

        Output: The contents of the symbol table.
        
        Make modification to the parser module that we did in the first assignment by implementing the following functions whose prototype is given.
        Structure of the symbol table is

        struct sym_rec {

        char *name; //name of the symbol
        
        struct sym_rec next; //link field
        
        int data_offset;//will be used during code generation phase.
        
        }*sym_record; //points to the first record
        
        struct sym_rec * put_symbol(char * name); //puts an identifier into the table.
        
        struct sym_rec * get_symbol(char * name);returns a pointer to the symbol table entry or a NULL pointer if not found.
        
        void install(char *name);//installs a symbol into the symbol table if it is not in the symbol table using the above two functions. Reports appropriate error messages.
        
        void context_check(char *name);//checks the contest sensitive requirement of our language and if violated appropriate error messages.

    13) Code generation.

        Input: A program in our Language.
        
        Output: stack machine code written into a file.

        The code is generated from the implicitly created parse tree. Here we are generating code for a virtual machine called a stack machine. The virtual machine consists of three segments. A data segment,a code segment and an expression stack. The data segment contains the values associated with the variables. Each variable is assigned to a location in the data segment which holds the associated value. The code segment consists of a sequence of operations, i.e. the stack machine code. Program constants are incorporated in the code segment since their values do not change. The expression stack is a stack which is used to hold intermediate values in the evaluation of expressions.

        Instruction format for the stack machine

        opcode
        operand

        Instruction set
        (operand = 0 for opcodes with no operands. Eg. write, It, gt, etc.)

        eg:

        input:
        prog
        Integer a,b.
        begin
        Read a;
        if a < 10 then b := 1; else ; endif;
        while a < 10 do b :=5*a; a := a+1; endwhile;
        write a;
        write b;
        end

        output:
        0:res 2
        1:read 0
        2:load_var 0
        3:load_int 10
        4:It 0
        5:jmp_false 9
        6:Id_int 1
        7:store 1
        8:goto 9
        9:load_var 0
        10:load_int 10
        11:It 0
        12:jmp_false 22
        13:load_int 5
        14:load_var 0
        15:mul 0
        16:store 1
        17:load_var 0
        18:load_int 1
        19:add 0
        20:store 0
        21:goto 9
        22:load_var 0
        23:write 0
        24:load_var 1
        25:write 0
        26:halt 0