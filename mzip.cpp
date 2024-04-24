// mzip.cpp

#include <unistd.h>
#include <sys/syscall.h>
#include <cstdint>


int main(int argc, char* argsv[]) {

    // Ensure Proper Input Format.
    if(argc ==  1){

        syscall(SYS_write, STDERR_FILENO, "\nmzip: file1 [file2 ...]\n\n", sizeof("\nmzip: file1 [file2 ...]\n\n") - 1);
        return 1;

    }


    int flag = 0; // Open the file in read-only mode

    for(int fdIndex = 1; fdIndex < argc; fdIndex++){

        // Open file   (Signal, Char Buffer, Permission, Mode)
        int fd = syscall(SYS_open, argsv[fdIndex], flag, 0);

        // fd Defaults To -1 When Invalid File/Request
        if (fd == -1) {

            syscall(SYS_write, STDERR_FILENO, "\nmzip: cannot open file\n\n", sizeof("\nmzip: cannot open file\n\n") - 1);
            return 1;

        }

       
        char prevChar, curChar;                           // Hold Previous Char (For Counting Amount In Compression File) As Well As Currently Read Char
        uint32_t count = 1;                                // We Currently Have One Of Our Char

        // Check if the file is empty (If Our Previous Character Read Operation Returns E.O.F)
        if (syscall(SYS_read, fd, &prevChar, sizeof(char)) == 0) {

            // Skip Zipping Of This File (Goto Next Step Of Loop)
            continue;
            
        }

        // Read subsequent characters
        while (syscall(SYS_read, fd, &curChar, sizeof(char)) > 0) { 

            // If We Have A Repeat Of A Character
            if (curChar == prevChar) {

                count++;

            } 
            // If We Have No Repeat, Print Count To Compressed Directory (STDOUT)
            else {

  
                syscall(SYS_write, STDOUT_FILENO, &count, sizeof(uint32_t)); // Write count
                syscall(SYS_write, STDOUT_FILENO, &prevChar, sizeof(char)); // Write character
                count = 1;                                                  // Reset Count
                prevChar = curChar;                                         // Set Previous As New Character

            }
        }

        syscall(SYS_write, STDOUT_FILENO, &count, sizeof(uint32_t)); // Write the count of the last character sequence
        syscall(SYS_write, STDOUT_FILENO, &prevChar, sizeof(char)); // Write the last character
        
        // Close the file
        if (syscall(SYS_close, fd) == -1) {

            syscall(SYS_write, STDERR_FILENO, "\nmzip: cannot close file\n\n", sizeof("\nmzip: cannot close file\n\n") - 1);
            return 1;
          
        }


    }


    return 0;

}
