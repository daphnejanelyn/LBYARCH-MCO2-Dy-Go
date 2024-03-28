# x86-to-C interface programming project
#### Group Members: 
1. Dy, Sealtiel Bawar
2. Go, Daphne Janelyn

The program can be executed by choosing one of the three available inputs, 
1. Given Sample Input in the Specifications, 
2. Input from 1 to n Modulo 10<sup>6</sup>, and 
3. Randomized Values

This was done to ensure the program's correctness against all three scenarios.

The following section details the execution time of each input in C and x86-64 Assembly using 4 different array sizes, namely  **2<sup>20</sup>, 2<sup>24</sup>, 2<sup>28</sup>, and 2<sup>30</sup>**.

#### System Specifications
The program was run on a computer with the following CPU and RAM configurations:
- CPU: Ryzen 5 5600X
- RAM: 32GB 3200MHz

#### Performance in Debug Mode
The figure below details the execution times of running the program on the given sample input using the different array sizes in debug mode. For the chosen input, faster execution times in x86-64 Assembly have been identified across the average time obtained in 30 runs for all array sizes in comparison to C.

[![Debug-Version-1.png](https://i.postimg.cc/4xNVKzQc/Debug-Version-1.png)](https://postimg.cc/vckckxj8)

The figure below details the execution times of running the program on input from _1 to n modulo 1,000,000_ using the different array sizes in debug mode (with n denoting array size). Consistent with the first input, faster execution times in x86-64 Assembly compared to the C program have been identified across the average time obtained in 30 runs for all array sizes.

[![Debug-Version-2.png](https://i.postimg.cc/6QYrj8jR/Debug-Version-2.png)](https://postimg.cc/Ny22Ljwf)

To ensure consistency in performance for different sets of inputs, random values were used to run the program in debug mode. Consistent with the first two inputs, a faster execution in x86-64 Assembly still holds against execution times using the C program.

[![Debug-Version-3.png](https://i.postimg.cc/1z90rGHs/Debug-Version-3.png)](https://postimg.cc/rDPt8t3P)



#### Performance in Release Mode
The figure below details the execution times of running the program on the given sample input using the different array sizes in release mode. In contrast to the results obtained in debug mode, faster execution times were identified using the C program compared to x86-64 Assembly.

[![Release-Version-1.png](https://i.postimg.cc/xC9t4r3J/Release-Version-1.png)](https://postimg.cc/f3gcVrFD)

The figure below details the execution times of running the program on input from _1 to n modulo 1,000,000_ using the different array sizes in release mode (with n denoting array size). Consistent with the first input, faster execution times using the C program compared to the x86-64 Assembly program have been identified across the average time obtained in 30 runs for all array sizes.

[![Release-Version-2.png](https://i.postimg.cc/g0svrx3j/Release-Version-2.png)](https://postimg.cc/Tyyy4Y7v)

Random values were used to run the program in release mode. Consistent with the first two inputs, a faster execution using C still holds against execution times using the x86-64 Assembly program as shown in the figure below.

[![Release-Version-3.png](https://i.postimg.cc/kgd8cQcD/Release-Version-3.png)](https://postimg.cc/mt8tZFKG)


### Analysis and Discussion
[![Average-Debug-Version.png](https://i.postimg.cc/Vk9BtGXK/Average-Debug-Version.png)](https://postimg.cc/fVL9nv2d)
[![Average-Release-Version.png](https://i.postimg.cc/HxK87XnY/Average-Release-Version.png)](https://postimg.cc/r01wBd53)

The programs are executed in two modes, namely debug and release mode. The main difference between the two modes lies within its optimization. Debug mode comes with no optimization applied for both C and x86-64 Assembly. Whereas release mode comes with maximum optimization for high-level languages like C. With this in mind, a faster performance in C for the average times acquired in release mode is evidently seen in this specific mode as shown in the Figure above.

Nonetheless, x86-64 Assembly language inherently provides fine-grained control over registers, memory, and instructions - making it easier to optimize the program without the overhead of high-level instructions. Furthermore, programs written in Assembly are directly assembled into binary machine code unlike high-level languages like C that rely on compilers that translate programs to assembly-level or machine-level code. This is the reason why faster average execution times in the x86-64 Assembly program are evidently seen, without applying any optimizations to either language in debug mode as shown in the Figure above.

## Correctness Check for C and x86-64 Assembly Program Across All Three Inputs

### Debug Mode
**Program Run for 2<sup>20</sup>**

[![1.png](https://i.postimg.cc/76djh3GM/1.png)](https://postimg.cc/r0GfYt9K)
![Debug: 2^20, Mode 1](https://github.com/daphnejanelyn/LBYARCH-MCO2-Dy-Go/blob/master/media/D_1_1.png?raw=true)
![Debug: 2^20, Mode 2](https://github.com/daphnejanelyn/LBYARCH-MCO2-Dy-Go/blob/master/media/D_1_2.png?raw=true)
![Debug: 2^20, Mode 3](https://github.com/daphnejanelyn/LBYARCH-MCO2-Dy-Go/blob/master/media/D_1_3.png?raw=true)

**Program Run for 2<sup>24</sup>**

[![2.png](https://i.postimg.cc/WbTck7YX/2.png)](https://postimg.cc/t7Sc0Fjx)
![Debug: 2^24, Mode 1](https://github.com/daphnejanelyn/LBYARCH-MCO2-Dy-Go/blob/master/media/D_2_1.png?raw=true)
![Debug: 2^24, Mode 2](https://github.com/daphnejanelyn/LBYARCH-MCO2-Dy-Go/blob/master/media/D_2_2.png?raw=true)
![Debug: 2^24, Mode 3](https://github.com/daphnejanelyn/LBYARCH-MCO2-Dy-Go/blob/master/media/D_2_3.png?raw=true)

**Program Run for 2<sup>28</sup>**

[![3.png](https://i.postimg.cc/zBZc1J90/3.png)](https://postimg.cc/R3dR7zCH)
![Debug: 2^28, Mode 1](https://github.com/daphnejanelyn/LBYARCH-MCO2-Dy-Go/blob/master/media/D_3_1.png?raw=true)
![Debug: 2^28, Mode 2](https://github.com/daphnejanelyn/LBYARCH-MCO2-Dy-Go/blob/master/media/D_3_2.png?raw=true)
![Debug: 2^28, Mode 3](https://github.com/daphnejanelyn/LBYARCH-MCO2-Dy-Go/blob/master/media/D_3_3.png?raw=true)

**Program Run for 2<sup>30</sup>**

[![4.png](https://i.postimg.cc/PxyzFThL/4.png)](https://postimg.cc/XGZCrMr3)
![Debug: 2^30, Mode 1](https://github.com/daphnejanelyn/LBYARCH-MCO2-Dy-Go/blob/master/media/D_4_1.png?raw=true)
![Debug: 2^30, Mode 2](https://github.com/daphnejanelyn/LBYARCH-MCO2-Dy-Go/blob/master/media/D_4_2.png?raw=true)
![Debug: 2^30, Mode 3](https://github.com/daphnejanelyn/LBYARCH-MCO2-Dy-Go/blob/master/media/D_4_3.png?raw=true)


-----------------------------------------------------------------------------------------------------------------------------------------------
### Release Mode
**Program Run for 2<sup>20</sup>**

[![1.png](https://i.postimg.cc/G2RJ39zg/1.png)](https://postimg.cc/jW8JZxpy)
![Release: 2^20, Mode 1](https://github.com/daphnejanelyn/LBYARCH-MCO2-Dy-Go/blob/master/media/R_1_1.png?raw=true)
![Release: 2^20, Mode 2](https://github.com/daphnejanelyn/LBYARCH-MCO2-Dy-Go/blob/master/media/R_1_2.png?raw=true)
![Release: 2^20, Mode 3](https://github.com/daphnejanelyn/LBYARCH-MCO2-Dy-Go/blob/master/media/R_1_3.png?raw=true)


**Program Run for 2<sup>24</sup>**

[![2.png](https://i.postimg.cc/sDxPgk9z/2.png)](https://postimg.cc/Czynv6Qr)
![Release: 2^24, Mode 1](https://github.com/daphnejanelyn/LBYARCH-MCO2-Dy-Go/blob/master/media/R_2_1.png?raw=true)
![Release: 2^24, Mode 2](https://github.com/daphnejanelyn/LBYARCH-MCO2-Dy-Go/blob/master/media/R_2_2.png?raw=true)
![Release: 2^24, Mode 3](https://github.com/daphnejanelyn/LBYARCH-MCO2-Dy-Go/blob/master/media/R_2_3.png?raw=true)

**Program Run for 2<sup>28</sup>**

[![3.png](https://i.postimg.cc/tg3Wcpy3/3.png)](https://postimg.cc/Y4SvGcv0)
![Release: 2^28, Mode 1](https://github.com/daphnejanelyn/LBYARCH-MCO2-Dy-Go/blob/master/media/R_3_1.png?raw=true)
![Release: 2^28, Mode 2](https://github.com/daphnejanelyn/LBYARCH-MCO2-Dy-Go/blob/master/media/R_3_2.png?raw=true)
![Release: 2^28, Mode 3](https://github.com/daphnejanelyn/LBYARCH-MCO2-Dy-Go/blob/master/media/R_3_3.png?raw=true)

**Program Run for 2<sup>30</sup>**

[![4.png](https://i.postimg.cc/4NYtgzsN/4.png)](https://postimg.cc/pptyQ5mg)
![Release: 2^30, Mode 1](https://github.com/daphnejanelyn/LBYARCH-MCO2-Dy-Go/blob/master/media/R_4_1.png?raw=true)
![Release: 2^30, Mode 2](https://github.com/daphnejanelyn/LBYARCH-MCO2-Dy-Go/blob/master/media/R_4_2.png?raw=true)
![Release: 2^30, Mode 3](https://github.com/daphnejanelyn/LBYARCH-MCO2-Dy-Go/blob/master/media/R_4_3.png?raw=true)


