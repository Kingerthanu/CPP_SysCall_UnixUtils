# CPP_SysCall_UnixUtils
C++ Implementation Of UNIX Utility Scripts. This Includes grep, cat, unzip, and zip Where The Zip Functions Utilize Run-Length Encoding Compression.
______________________________________________________________________________________________

<img src="https://github.com/Kingerthanu/CPP_SysCall_UnixUtils/assets/76754592/1978b9cf-e37e-4f85-a846-19620eec0891" alt="Cornstarch <3" width="55" height="49"> <img src="https://github.com/Kingerthanu/CPP_SysCall_UnixUtils/assets/76754592/1978b9cf-e37e-4f85-a846-19620eec0891" alt="Cornstarch <3" width="55" height="49"> <img src="https://github.com/Kingerthanu/CPP_SysCall_UnixUtils/assets/76754592/1978b9cf-e37e-4f85-a846-19620eec0891" alt="Cornstarch <3" width="55" height="49"> <img src="https://github.com/Kingerthanu/CPP_SysCall_UnixUtils/assets/76754592/1978b9cf-e37e-4f85-a846-19620eec0891" alt="Cornstarch <3" width="55" height="49">




**The Breakdown:**

  This Program Works With C++ To Use The Terminal To Create Implementations Of Some UNIX Utilility Functions; Mainly grep, cat, unzip, and zip.

  Each Implementation Should Have The Same Calling Signature (I.E. Supply Our Source File To Parse) From The Normal UNIX Function. Also, To Dilineniate
  
  Between UNIX's Utilities And MY Utilities I Will Add A 'm' At The Start Of Each Util Name (I.E. mgrep, mcat, mzip, munzip).

  For Each Of The Implemented UNIX Utility Functions, This Is How They Will Be Utilized: 

  - mgrep: <br>
    └──  mgrep.cpp Is Used To Read In Given File(s) For A Specified Key Term, Printing The Lines Holding The Given Terms.

  - mcat: <br>
    └──  mcat.cpp Is Used To Read In A Given File(s) Contents And Print Them To The Terminal For The User.

  - mzip: <br>
    └──  mzip.cpp Is Used To Read In A Given File(s) Contents And Compress Them Based Upon The Run-Length Encoding Compression Algorithm.

  - munzip: <br>
    └──  munzip.cpp Is Used To Read In A Given RLE Compressed File(s) Contents And Uncompress Them Based Upon The Run-Length Encoding Compression Algorithm.

  In This, I Also Included The Program's ReadMe In Which Goes More In Depth To The Behavior And Differences Between This Implementation Of The Given UNIX Function Vs The Literal
Implementation; Including Error Codes And Restrictions.

  Overall This Was A Super Fun And Informational Project To Do. I Tried Making It Hard On Myself By Using Solely SysCall(...) Requests To Ensure I Knew Where/What I Was Doing And It Worked
  Very Well. The Implementation Of mzip, and munzip Taught Me A Lot About The Need For Context/Interpretation Of Raw Bytes And How, Again, Everything Is Just Ones And Zeros And We Need Ways Of Interpreting
  These To Get The "Right" Answer.

  Learning About File Parsing Also Was Intruiging And Helped Teach Me More How The OS Works As A Manager Of Our System; As Before I Knew OS Was A Big Deal But Not As Influential As I See It Now. More Direct Interrupting Seems
  Like A Powerful Tool I Will Utilize In Further Projects For Asynchronous Interrupt Handling As It Shows Me How We Don't Need To Poll All The Time For Actions We Expect In This Asynchronous Manner.





<img src="https://github.com/Kingerthanu/PythonSmallClicker/assets/76754592/540a38c0-344b-4f8b-8420-bdb88e6ae321" alt="Cornstarch <3" width="55" height="49"><img src="https://github.com/Kingerthanu/PythonSmallClicker/assets/76754592/540a38c0-344b-4f8b-8420-bdb88e6ae321" alt="Cornstarch <3" width="55" height="49"><img src="https://github.com/Kingerthanu/PythonSmallClicker/assets/76754592/540a38c0-344b-4f8b-8420-bdb88e6ae321" alt="Cornstarch <3" width="55" height="49"><img src="https://github.com/Kingerthanu/PythonSmallClicker/assets/76754592/540a38c0-344b-4f8b-8420-bdb88e6ae321" alt="Cornstarch <3" width="55" height="49">


______________________________________________________________________________________________

<img src="https://github.com/Kingerthanu/CPP_SysCall_UnixUtils/assets/76754592/4ac03ff7-17fd-4b2d-94bf-97aff934bd63" alt="Cornstarch <3" width="55" height="49"> <img src="https://github.com/Kingerthanu/CPP_SysCall_UnixUtils/assets/76754592/4ac03ff7-17fd-4b2d-94bf-97aff934bd63" alt="Cornstarch <3" width="55" height="49"> <img src="https://github.com/Kingerthanu/CPP_SysCall_UnixUtils/assets/76754592/4ac03ff7-17fd-4b2d-94bf-97aff934bd63" alt="Cornstarch <3" width="55" height="49"> <img src="https://github.com/Kingerthanu/CPP_SysCall_UnixUtils/assets/76754592/4ac03ff7-17fd-4b2d-94bf-97aff934bd63" alt="Cornstarch <3" width="55" height="49">


**Features:**

....


<img src="https://github.com/Kingerthanu/CPP_SysCall_UnixUtils/assets/76754592/a77148c3-22b2-446c-8bb0-c6deb2e81f07" alt="Cornstarch <3" width="55" height="49"> <img src="https://github.com/Kingerthanu/CPP_SysCall_UnixUtils/assets/76754592/a77148c3-22b2-446c-8bb0-c6deb2e81f07" alt="Cornstarch <3" width="55" height="49"> <img src="https://github.com/Kingerthanu/CPP_SysCall_UnixUtils/assets/76754592/a77148c3-22b2-446c-8bb0-c6deb2e81f07" alt="Cornstarch <3" width="55" height="49"> <img src="https://github.com/Kingerthanu/CPP_SysCall_UnixUtils/assets/76754592/a77148c3-22b2-446c-8bb0-c6deb2e81f07" alt="Cornstarch <3" width="55" height="49">
