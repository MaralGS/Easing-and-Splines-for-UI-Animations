## Easing-and-Splines-for-UI-Animations

Created by Alex Garcia Selma. [GitHub](https://github.com/MaralGS)

[GitHub Project](https://github.com/MaralGS/Easing-and-Splines-for-UI-Animations)

## Introduction
Hi, my name is Alex Garcia Selma student of the UPC at CITM, doing the degree of Devolopment and Design of Videogames. This Project is made for the second year’s subject Project 2. In this project im doing a research of what are the easing and splines for UI animations, what are they for, how many of them are and how to implement them in the project that we are doing for this subject.

## What is a Ui Easing?
A UI easing is an animation made by a mathematic function to made more smooth and clean the Ui interacctions like camera moves, switch buttons or diverse moves.
there are many types of functions that you can use and it depence on what you prefer and for what you want to use it, you can even create one if you want but mainly you will get them from the internet, in my case I got most of them from here [Easing Page](https://easings.net/#)

<p align="center">
<img src="https://github.com/MaralGS/Easing-and-Splines-for-UI-Animations/blob/main/docs/easingAnimation.gif">
</p>

```markdown
Exemple of a easing
```

Each easing function depends on four parameters:

- Current time (t) which is the moment where the object is.

- Beginning value (b) which the position where the object is at the moment t.

- Change in value (c) which is the difference of value between the current position and the final position.

- Duration (d) which is the total number of iterations that you want your animation to have, needs to be the current unit as the starting time.

There are three type of functions:

- Ease in function: describes the positive acceleration of the object.

- Ease out function: describes the negative acceleration (deacceleration) of the object.

- Ease in and out function: mixes both of the previous functions describing first and acceleration followed by a deacceleration.

## Code to implement the easing
First, you will have to create a funtion where u will send the four parameters explained previously:

```markdown
CubicEaseIn(currentTime, beginningValue, distanceToGoal, totalTime);
```
and a variable to save the float number:

```markdown
float currentValue;
currentValue = CubicEaseIn(currentTime, beginningValue, distanceToGoal, totalTime);
```
Now, you will have to know how many frames per second your program runs, in our case we will take for example 60 frames, then if you want the animation to take a total of 5 sec, wour total time would be the multiplication of those numers(300).

In case your program runs at 60 frames per second and you want the animation to take a total of 5 seconds, your total time would be 300 iterations (remember the units of the current and total time must be the same in order to work). Taking this into account the function would now look like this.

```markdown
float currentValue;
int totalIterations = 300;
```
You will need an initial Iteration value, it usally is initalitazed at 0:

```markdown
float currentValue;
int totalIterations = 300;
int initalIterations = 0;
```
Then you will need an starting point and and ending point that our object will travel, in our case it will be a cube and we only will move the X, we will need the distance between them too:

```markdown
float currentValue;
int totalIterations = 300;
int initalIterations = 0;
int FirstPosition = 100;
int SecondPosition = 500;
int distanceBetweenPoints = SecondPosition - FirstPosition;
```
Then you will have to do the function, in my case i will create a bool to activate or desactivate the easing:
```markdown
float currentValue;
bool easingActive;
int totalIterations = 300;
int initalIterations = 0;
int FirstPosition = 100;
int SecondPosition = 500;
int distanceBetweenPoints = SecondPosition - FirstPosition;
```
```markdown
if (yourCondition){
	easingActive = true;
}
if (easingActive){
	currentValue = CubicEaseIn(currentIteration, firstPoint, distanceBetweenPoints, totalIterations);
}
if (currentIteration < totalIterations {
	currentIteration++
}
else {
	currentIterations = 0;
	easingActive = false;
}
```
You can find all the functions that you can call here [EasingFunctions](http://www.gizma.com/easing/#sin1)
(CubeEaseIn is only an example, you can replace it for any easing you want).

## Splines

From a mathematical point of view, a spline is a curve that appears as a result of a function defined in parts by polynomials. Splines are commonly used in programming because they are easy to build and accurate besides their capability of aproximating complex shapes through an interactive curve design. A spline is built through various control points that define their slope and follows diverese knots.

There are a lot of different types of splines but here only the most common ones will be shown:

- Catmull-Rom Spline: is a type of cardinal splines that is continuous and the curve passes through all of the control points. It was formulated by Edwin Catmull and Raphael Rom.


- Cubic Hermite Spline: is a spline where each piece is a third degree polynomial, just like any Cubic Spline, and it's defined by its values and first derivatives at the end points, also called Hermite form. It's named after Charles Hermite.


- Linear Spline: is a continuous function defined by linear polynomials, which essentially means that is a continuous set of straight lines.


- B-Spline (Basic Spline): it's a spline defined as a linear combination of control points that has a minimal support given a degree, smoothness and domain. This spline is commonly used because it allows to express any spline of a certain degree by a linear combination of B-Splines of that degree. The term B-Spline was defined by Isaac Jacob Schoenberg.


- NURBS (Non-uniform rational B-Spline): is a mathematical model commonly used in computer graphics for generating and representing curves and surfaces. It is a type of B-spline that offers great flexibility and precision for handling both analytic (in mathematical form) and modeled shapes.


- Bézier Spline: is a continous splines defined picewise by different Bézier curves.



### Splines Usability

The main usage of splines in videogames are to create paths for the enemies to follow. These paths should be continuous to have a smooth motion and this is exactly what a spline has to offer. In addition, any game that requires the player to level up can take use of splines to define the necessary experience needed increasingly between levels.

A great example of how a spline defines the motion of a camera in 2D videogames is the game Sonic the hedgehog.

In 3D and VR videogames splines take a great importance in camera views, allowing the camera to move from a First Person point of view. A great example of this phenomenon is a simple rollercoaster where, if the camera follows the spline, the user can experience the view as if he were on that rollercoaster.
Here there's a video example of how a 3D camera following a spline creates a more realistic view:

### Relevant Links
[Easing Animation](https://www.kirupa.com/html5/animating_with_easing_functions_in_javascript.htm)

[Easing Preview](https://easings.net/)

[How UI Easing Works](https://www.youtube.com/watch?v=JXC3e52kcq0)

[Easing Functions for the code](http://www.gizma.com/easing/#sin1)
