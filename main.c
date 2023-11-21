 /*
 ============================================================================
 Name        : main.c
 Author      : Austin Tian
 Revised by  :
 Version     :
 Copyright   : Copyright 2023
 Description : main code in C
 ============================================================================
 */
#include "header.h"

int main (int argc, char *argv[]) {
        char *mem = NULL;  //  memory space pointer.
        FILE *fp = NULL;
        int stopChar;

        // Step 1: Parse the ASM code.
        if (argc < 2) {
            puts("\nIncorrect number of arguments.");
            puts("Usage: ProgramName.exe MIPSCode.asm \n");
            stopChar = getchar();
            return EXIT_FAILURE;  // if the file cannot be found, then return.
        }
        if ((fp = fopen(argv[1], "r"))== NULL) {  // read the asm file.
            printf("Input file could not be opened.");
            stopChar = getchar();
            return EXIT_FAILURE;  // if the file cannot be read, then return.
        }
        parse_MIPS(fp);  // call this function to parse the code into
                                    // Data_storage, Instruction_Storage and labelTab

        /* The following code is for for lab 8 ~ lab 10.*/
        // IMPORTANT: When you initialize the memory, please fill in 0, not the random number
        // to all the memory locations.
        mem = init_memory();  // start the memory to hold the code.
        stopChar = getchar();

        // Step 3: Load the code into memory (lab 8)
        puts("----Lab 8 Code Starts to Parse the ASM Code----");
        loadCodeToMem(mem);
        stopChar = getchar();

        puts("----Lab 9_10 Code Starts to Fetch, Decode, and Execute the Code ----");
        // Step 4: CPU Fetch the machinecode (lab 9)
        // Step 5: CPU Decode the machine code (lab 9)
        // Step 6: Execute the code until the code is finished(lab 10)
        // CPU(mem);  // this is needed in lab 9 and later
        //stopChar = getchar();
        free_memory(mem);  // free the memory, this is for lab 8 and later
}
