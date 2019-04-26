**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**
* Running: the process is actively running
* Sleeping/Waiting: the process is waiting for an event, such as terminal input or waiting on a child process
* Zombie: The child process has finished its execution, and is a zombie so the parent can access its exit status. Also, braiiins.


**2. What is a zombie process?**
* A zombie process is a child process that has completed execution but is still listed in the process table. The process is kept as a zombie so the parent can read its exit status.



**3. How does a zombie process get created? How does one get destroyed?**
* A zombie process gets created when a child exits. It gets destroyed when its parent(or, if it's orphaned, PID 1) waits() for it.


**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**
* Compiled languages are more reliable because the compiler will eliminate type errors. The compiled language will also have faster performance and better optimization because it's compiled into machine code.

