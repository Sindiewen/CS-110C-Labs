//
//  main.cpp
//  Lab 4 - Practical Queue Application
//
//  Created by Rachel Vancleave on 11/9/16.
//  Copyright © 2016 Rachel Vancleave. All rights reserved.
//

#include <iostream>
#include "LinkedQueue.h"

using namespace std;

int main()
{
	// insert code here...
	cout << "Hello, World" << endl;

    LinkedQueue <int>myQueue;

    for (int i = 0; i < 10; i++)
    {
        myQueue.enqueue(i*3);
    }

    for (int i = 0; i < 10; i++)
    {
        cout << "Dequeue " << i << ": " << myQueue.peekFront() << endl;
        myQueue.dequeue();
    }






    // Ends program
    return 0;
}
