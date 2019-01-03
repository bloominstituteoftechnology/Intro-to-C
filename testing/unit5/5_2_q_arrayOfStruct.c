// Activity: array of structures

// 1. You have defined a structure as follows:

struct point
{
    double x;
    double y;
};

// You would now like to declare an array of 5 such points (a pentagon!).

struct point pentagon[5];

// 2. You would like to assign the value 4.1 to the y-coordinate of the fifth point in pentagon.

// Which of the following are the correct ways to do so?

pentagon[4].y = 4.1;     // correct
(pentagon + 4)->y = 4.1; // correct