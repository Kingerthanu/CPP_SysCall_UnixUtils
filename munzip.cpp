// munzip.cpp

#include <unistd.h>
#include <sys/syscall.h>
#include <cstdint>          // For uint32_t

int main(int argc, char* argsv[]) {

    // Ensure Proper Input Format.
    if(argc ==  1){

        syscall(SYS_write, STDERR_FILENO, "\nmunzip: file1 [file2 ...]\n\n", sizeof("\nmunzip: file1 [file2 ...]\n\n") - 1);
        return 1;

    }


    int flag = 0; // Open the file in read-only mode

    for(int fdIndex = 1; fdIndex < argc; fdIndex++){

        // Open file   (Signal, Char Buffer, Permission, Mode)
        int fd = syscall(SYS_open, argsv[fdIndex], flag, 0);

        // fd Defaults To -1 When Invalid File/Request
        if (fd == -1) {

            syscall(SYS_write, STDERR_FILENO, "\nmunzip: cannot open file\n\n", sizeof("\nmunzip: cannot open file\n\n") - 1);
            return 1;

        }

    
        char curChar;       // The Currently Worked With Character To Write Out From Compressed File
        uint32_t count = 0;  // Amount Of Currently Worked With Character To Write Out From Compressed File

        // If Proper Format, Every Character Should Have A Count Next To It In RLE Compressed File
        while ((syscall(SYS_read, fd, &count, sizeof(uint32_t)) > 0) && (syscall(SYS_read, fd, &curChar, sizeof(char)) > 0)) { // Read subsequent characters
            
            // Write "count" Amount Of curChar
            for(uint32_t step = 0; step < count; step++){

               syscall(SYS_write, STDOUT_FILENO, &curChar, sizeof(char)); // Write character

            }

        }


      // Close the file
      if (syscall(SYS_close, fd) == -1) {

        syscall(SYS_write, STDERR_FILENO, "\nmunzip: cannot close file\n\n", sizeof("\nmunzip: cannot close file\n\n") - 1);
        return 0;
          
      }


    }

    
    
    return 0;

}
