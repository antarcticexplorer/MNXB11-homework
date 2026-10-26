# Homework 6 questions

### Q0: Header guards and `#pragma once`
Both methods prevent header files from being processed more than once during the preprocessing phase. The main difference is just the directives used.

### Q1: Difference between `class` and `struct`
The difference is whether variables and methods are public or private by default. In a class they are private whereas in a struct they are public.

### Q2: Why we derive from `TObject`
Because `TObject` provides the ROOT functionality to work with objects and allows us to use the `MovingObject` class with the ROOT interface.

### Q3: Compiling
Implemented the class interface and it compiles without errors using `.L MovingObject.cxx+`

### Q4: Initialising velocity
Already completed in previous step, getters and set velocity work when tested in root. 

### Q5: Implementing speed functions
The functions have been implemented, `A.speed()` gives 0.5 m/s and `B.speed()` gives ~0.71 m/s. `HorizantalSpeed()` gives 0.5 m/s for both A and B. $v_z$ only changes total speed by triviality.

### Q6: Generating measurements 
I generated the 10000 measurements and stored them into `tree_file.root`. The random seed was 12345, and the mean and the standard deviation was 0m/s and 0.3 m/s respectively for the gaussian. The number of entries was verified with `tree->GetEntries()`.

### Q7: 2D Histogram
Followed instructions and created the desired histogram, seen in `velocity_components.png`. The second `TTree::Draw()` plot which was also asked to be saved is displayed in `selected_velocities.png`. 

### Final Check
```.L MovingObject.cxx+`
.x write.C```
Read:
```.L MovingObject.cxx
.x read.C```
