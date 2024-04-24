// mgrep.cpp

#include <unistd.h>
#include <string>
#include <sys/syscall.h>

int main(int argc, char* argsv[])
{

    // Ensure Proper Input Format.
    if(argc == 1){

      syscall(SYS_write, STDERR_FILENO, "\nmgrep: searchterm [file ...]\n\n", sizeof("\nmgrep: searchterm [file ...]\n\n") - 1);
      return 1;

    }
    // If We Are Given A Empty String ("") Return Nothing
    else if(argsv[1][0] == '\0'){

      return 0;

    }
    // If No Files Are Provided, Read From Standard Input
    else if (argc == 2) {   
      
      char readChar;              // Currently Read Char From File Directory
      std::string curLine = "";   // Current Line Being Read (Seperator is '\n').

      // Read input from standard input
      while (syscall(SYS_read, STDIN_FILENO, &readChar, sizeof(char)) > 0) {

          // If We Are Still Reading A Given Line
          if (readChar != '\n') {

            curLine += readChar;

          } else {

            // Line Break, So Check for the search term
            if (curLine.find(argsv[1]) != std::string::npos) {

                // Write The Line Containing The Search Term To Standard Output
                syscall(SYS_write, STDOUT_FILENO, curLine.c_str(), curLine.length());
                syscall(SYS_write, STDOUT_FILENO, "\n", 1);
                
            }

            // Clear Our Line
            curLine = "";

          }

      }

      /*
        // Check for search term in the last line ( Commented Out As STD IN Should Always Be Terminated With Exit Signal And Only Checks Lines By ENTER )
        if (curLine.find(argsv[1]) != std::string::npos) {
          syscall(SYS_write, STDOUT_FILENO, curLine.c_str(), curLine.length());
          syscall(SYS_write, STDOUT_FILENO, "\n", 1);
        }
      */

      return 0;

    }
    
    int flag = 0; // Open the file in read-only mode

    for(int fdIndex = 2; fdIndex < argc; fdIndex++){

      // Open file   (Signal, Char Buffer, Permission, Mode)
      int fd = syscall(SYS_open, argsv[fdIndex], flag, 0);

      
      if (fd == -1) {

        syscall(SYS_write, STDERR_FILENO, "\nmgrep: cannot open file\n\n", sizeof("\nmgrep: cannot open file\n\n") - 1);
        return 1;

      }

      char readChar;              // Currently Read Char From File Directory
      std::string curLine = "";   // Current Line Being Read (Seperator is '\n').
    
      //   Read File (Signal, Char Buffer, Store In, Size To) [If Less Than 0, Will Be Error Code]
      while ((syscall(SYS_read, fd, &readChar, sizeof(char))) > 0) {

          // If We Are Still Reading A Given Line
          if(readChar != '\n'){

            curLine += readChar;

          }
          // Else Line Break, So Reset Current Line Buffer.
          else{

            if(curLine.find(argsv[1]) != std::string::npos){

              // Write The Line Containing The Search Term To Standard Output
              syscall(SYS_write, STDOUT_FILENO, curLine.c_str(), curLine.length());
              syscall(SYS_write, STDOUT_FILENO, "\n", 1);

            }

            // Clear Our Line
            curLine = "";

          }

      }
      

      // Check for search term in the last line
      if (curLine.find(argsv[1]) != std::string::npos) {
        syscall(SYS_write, STDOUT_FILENO, curLine.c_str(), curLine.length());
        syscall(SYS_write, STDOUT_FILENO, "\n", 1);
      }


      // Close the file
      if (syscall(SYS_close, fd) == -1) {

        syscall(SYS_write, STDERR_FILENO, "\nmgrep: cannot close file\n\n", sizeof("\nmgrep: cannot close file\n\n") - 1);
        return 1;
          
      }

    }
    

    return 0;

};
