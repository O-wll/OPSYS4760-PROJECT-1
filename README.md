Project Author: Dat Nguyen

Course: Comp Sci 4760 

Date: 2/12/2025



Issues Ran Into:
- When printing out PID and PPID, PPID would not print due to my implementation using %p instead of %d, %p expects a pointer. RESOLVED
- When printing out the ./user output when forking, the result ends up with a mix of the two processess, I assume intentional due to them running concurrently.
- When trying to use execl(), at first I ran into a problem where it would not execute ./user, found out later it is because I was putting in an integer and not a string so I had to convert the iterations variable into a string for it to work. RESOLVED.
