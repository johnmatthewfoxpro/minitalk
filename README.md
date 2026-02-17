_This project has been created as part of the 42 curriculum by jfox_
# minitalk
The purpose of this project is to code a small data exchange program and to teach inter-process communication (IPC) using UNIX signals (SIGUSR1 and SIGUSR2). For school 42.
## DESCRIPTION
Minitalk tests our ability to create multiple executables from a single makefile but also have those executables interact with each other.

...

## INSTRUCTIONS

First open your terminal and use 'make' to build 2 executables, Server and Client.  
Next use './server' to print the servers pid (process number) and initialise the server.  
Now in a second terminal in the same directory you can use ./client to run the client.  
The executable MUST be formated like "./client 'server pid' 'string message'" 

Example: ./client 0420 "Hello World"  

If all has gone well, you should see your message string appear on the terminal window running the server!  
Use 'ctrl c' to shut down the server. Or you can run './client' multiple times with different messages.

## RESOURCES
AI has been used to build a clear and robust makefile, chat gpt specifically was used for adding colour and order to my make, clean, fclean and re rules.  
I followed a guide to better understand the requirements of minitalk [here](https://medium.com/@Kr1sNg/step-by-step-guide-to-minitalk-project-at-school-42-deacf16369ec)  
I also viewed this [guide](https://42-cursus.gitbook.io/guide/2-rank-02/minitalk)   
And this great [video](https://www.youtube.com/watch?v=XqhY9WHahJQ)  
A simply stack question for how to convert a char into binary [here](https://stackoverflow.com/questions/7863499/conversion-of-char-to-binary-in-c)
