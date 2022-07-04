The Source Codes for the paper by Gregory Gutin and Daniel Karapetyan "A Memetic Algorithm for the Generalized Traveling Salesman Problem."
http://dx.doi.org/10.1007/s11047-009-9111-6
http://arxiv.org/abs/0804.0722
---

The provided code contains two Visual Studio 2013 projects: a C# one and a C++ one.  The second one is a Dynamic Link Library (DLL) that implements the local improvement procedure.  The first one implements the memetic algorithm proposed in "G. Gutin, D. Karapetyan. A Memetic Algorithm for the Generalized Traveling Salesman Problem." (Algorithm.cs) and runs it (Program.cs) to produce experimental results like reported in the paper.

The FileLoader class is intended to load TSP and GTSP instances in the TSPLIB format.  It produces instances of the Task class.  The class Task stores all the information about a GTSP instance and is able to save it to either binary or text file of a simple format.  It can also load (see the constructor Task(string, bool)) and save instances in those formats.

The instance set can be downloaded in various formats from the GTSP Instances Library:
http://www.cs.nott.ac.uk/~dxk/gtsp.html

The code is provided for non-commercial purposes only.  Whenever used, the above reference has to be given.  The code can be used free of charge for non-commercial purposes.  In no event authors are liable for any damages or losses caused by using
this source code.

For any questions, please email Daniel Karapetyan: daniel.karapetyan@gmail.com