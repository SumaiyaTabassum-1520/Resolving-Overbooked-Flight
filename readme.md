# Description
An overbooked flight is when an airline sells more tickets on theplane than there are seats. This is a way to avoid empty seats from no-show passengers or missed connections. The Project is about resolving the overbooked flight. Because A lot of passengers want to buy the ticket. So only prioritised passengers will get the ticket. So there is an airline company who uses a formula to determine the priority of passengers on the waiting list for overbooked flights.

## Using Data Structures to solve
The priority number can be calculated by = (A / 1000 + B – C )

where,

A is the customer’s total mileage in the past year

B is the number of years in his or her frequent flier program

C is a sequence number representing the customer’s arrival position when he or she booked the flight.

As per the instructions of the project, after calculating all the passenger’s priority numbers build a priority queue ( Binary Heap ) based on the priority number and build a Stack to store information of customers who will get flight tickets later. 

