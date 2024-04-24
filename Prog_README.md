~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

mgrep.cpp:

  - Application:
	  mgrep.cpp Is Used To Read In Given File(s) For A Specified Key Term, Printing The Lines Holding The Given Terms.
  
  - Capabilities:
	mgrep Will Read/Display Non-Special Characters Only (Whatever User WOULD See)
		- Won't Print "Hidden" Characters Visually Like "Lorem Ipsum\n", "Lorem Ipsum\0"

  - Inferences:
    - Exit Code 0 -> Proper Functionality
    - Exit Code 1 -> Improper Functionality
    - mgrep Cannot Search For Key Terms With Hidden/Special Characters
    - mgrep Will Search For Key Term Literal Only
    - mgrep Searches Case Sensitively
    - If mgrep Looks For "" Key Term Return Nothing (Exit Code 0)
    - If mgrep Supplied No Search File, Go In Standard Input Loop And mgrep S.I. Until User-Signalled (CTRL + D) Termination.

  - Behavior:
    - Displays ONLY Lines Containing The Specified Key Term
    - If Supplied Multiple Files Won't Specify File Found In
    - Returned Line With Key Term Won't Have Text Highlighted In Red
    - Key Term Can Be Multi-Worded ("Baked Bean Casserole" Is Valid)
    - Displays EXACT Contents Of Supplied File(s) Line
    - Can Invoke Parsing Of Multiple Files, Writes One-After-Another
    - Formatting Error Returns A Error Code Of 1
      - Formatting Error Handling On No File Provided
      - Formatting Error Handling On Improper File Provided
      - Formatting Error Handling On Unclosable File Provided
    - Parsing Files Until End Of File(s) Is Reached Or An Error Opening A File Is Reached
    - If Proper Functionality, Return Code Of 0

  - Call Format:
	  ./mgrep [key search term] [filesArgs]

  - Edge Cases:
    - Provided Empty String -> Return Nothing
    - Provided No Input File -> Parse Standard Input
    - Provided Special Character Check -> '\n' CHECKS For "\n" Where [ '\', 'n' ]
    - Provided Invalid Input File -> Early Exit

  - Exception Types:
    	mgrep: searchterm [file ...]
      		- Thrown If User Supplies No Search File Arguments
   	mgrep: cannot open file
      		- Thrown If User Supplies Unopenable File
    	mgrep: cannot close file
     		- Thrown If Cannot Close File

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

mcat.cpp:

  - Application:
	  mcat.cpp Is Used To Read In A Given File(s) Contents And Print Them To The Terminal For The User.
  
  - Capabilities:
    mcat Will Read/Display Non-Special Characters Only (Whatever User WOULD See)
      - Won't Print "Hidden" Characters Like "Lorem Ipsum\n", "Lorem Ipsum\0"

  - Inferences:
    - Exit Code 0 -> Proper Functionality
    - Exit Code 1 -> Improper Functionality

  - Behavior:
    - Displays EXACT Contents Of Supplied File(s)
    - Can Invoke Parsing Of Multiple Files, Writes One-After-Another
    - Formatting Error Returns A Error Code Of 1
      - Formatting Error Handling On No File Provided
      - Formatting Error Handling On Improper File Provided
      - Formatting Error Handling On Unclosable File Provided
    - Printed Out In Order Until End Of File Is Reached Or An Error Opening A File Is Reached
    - If Proper Functionality, Return Code Of 0

  - Call Format:
	  ./mcat [filesArgs]

  - Edge Cases:
  	- Provided Invalid Input File -> Early Exit
	  - Provided No Input File -> Early Exit

  - Formatting Error Types:
    	mcat: file [file ...]
      		- Thrown If User Supplies No Search File Arguments
    	mcat: cannot open file
      		- Thrown If User Supplies Unopenable File
    	mcat: cannot close file
      		- Thrown If Cannot Close File

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

mzip.cpp:

  - Application:
	  mzip.cpp Is Used To Read In A Given File(s) Contents And Compress Them Based Upon The Run-Length Encoding Compression Algorithm.
  
  - Capabilities:
    mzip Utilizes Run-Length Encoding For Compression
    mzip Will Compress All Characters Held Within The Passsed File_Path(s) To STDOUT

  - Inferences:
    - Exit Code 0 -> Proper Functionality
    - Exit Code 1 -> Improper Functionality
    - Not Compressing In Compressor
    - Cannot Zip A Zipped File

  - Behavior:
    - Can Invoke Parsing Of Multiple Files - Writes One-After-Another - In Which Will Be Zipped To One Single End File
    - Formatting Error Returns A Error Code Of 1
      - Formatting Error Handling On No File Provided
      - Formatting Error Handling On Improper File Provided
      - Formatting Error Handling On Unclosable File Provided
    - Printed Out In Order Until End Of File Is Reached Or An Error Opening A File Is Reached
    - If Proper Functionality, Return Code Of 0

  - Call Format:
	  ./mzip [filesArgs]

  - Edge Cases:
    - Provided Invalid Input File -> Early Exit
    - Provided No Input File -> Early Exit
    - Provided A Empty File -> Skip Zipping (Zip Nothing)

  - Formatting Error Types:
    	mzip: file1 [file2 ...]
      		- Thrown If User Supplies No Search File Arguments
    	mzip: cannot open file
      		- Thrown If User Supplies Unopenable File
    	mzip: cannot close file
      		- Thrown If Cannot Close File

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

munzip.cpp:

  - Application:
	munzip.cpp Is Used To Read In A Given RLE Compressed File(s) Contents And Uncompress Them Based Upon The Run-Length Encoding Compression Algorithm.
  
  - Capabilities:
	munzip Utilizes Run-Length Encoding For Uncompression
	munzip Will Uncompress All Characters Held Within The Passsed File_Path(s) To STDOUT

  - Inferences:
  	- Exit Code 0 -> Proper Functionality
	- Exit Code 1 -> Improper Functionality
	- The Compressed Files Provided Are Compressed With Run-Length Encoding Compression

  - Behavior:
	- Can Invoke Parsing Of Multiple Compressed Files  - Writes One-After-Another -  In Which Will Be Uncompressed To One Single End File
	- Formatting Error Returns A Error Code Of 1
		- Formatting Error Handling On No File Provided
		- Formatting Error Handling On Improper File Provided
		- Formatting Error Handling On Unclosable File Provided
	- Printed Out In Order Until End Of File Is Reached Or An Error Opening A File Is Reached
	- If Proper Functionality, Return Code Of 0

  - Call Format:
	./munzip [filesArgs]

  - Edge Cases:
    - Provided Invalid Input File -> Early Exit
	- Provided No Input File -> Early Exit

  - Formatting Error Types:
	munzip: file1 [file2 ...]
		- Thrown If User Supplies No Search File Arguments
	munzip: cannot open file
		- Thrown If User Supplies Unopenable File
	munzip: cannot close file
		- Thrown If Cannot Close File

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~