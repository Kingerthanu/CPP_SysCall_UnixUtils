// Benjamin R. Spitzauer
// mcat.cpp

#include <unistd.h>
#include <sys/syscall.h>


int main(int argc, char* argsv[]) {

    // If Provided Insufficient Arguments For mcat, Tell User
    if(argc == 1){

      syscall(SYS_write, STDERR_FILENO, "\nmcat: file [file ...]\n\n", sizeof("\nmcat: file [file ...]\n\n") - 1);
      return 1;

    }


    int flags = 0; // Open the file in read-only mode


    for(int fdIndex = 1; fdIndex < argc; fdIndex++){
        // Open file   (Signal, Char Buffer, Permission, Mode)
        int fd = syscall(SYS_open, argsv[fdIndex], flags, 0);

        // fd Defaults To -1 When Invalid File/Request
         if (fd == -1) {

            syscall(SYS_write, STDERR_FILENO, "\nmcat: cannot open file\n\n", sizeof("\nmcat: cannot open file\n\n") - 1);
            return 1;

        }


        // Store Our Read Buffer Character (One At A Time)
        char readChar; 

        //   Read File (Signal, Char Buffer, Store In, Size To) [If Less Than 0, Will Be Error Code Or End-Of-File If 0]
        while ((syscall(SYS_read, fd, &readChar, sizeof(char))) > 0) {

            // Write Character Out To STDOUT Stream
            syscall(SYS_write, STDOUT_FILENO, &readChar, sizeof(char)); 

        }


        // Close the file
        if (syscall(SYS_close, fd) == -1) {

            syscall(SYS_write, STDERR_FILENO, "\nmcat: cannot close file\n\n", sizeof("\nmcat: cannot close file\n\n") - 1);
            return 1;
            
        }

    }


    return 0;

}
