# Room Allocation Algorithm

This program is designed to allocate rooms for a given set of intervals.

## How to use

1. Create a text file with the intervals in the following format: 

      start_time end_time
   

   For example:

   [10,12]
   
   [11,13]

    [14,15]
   

3. Save the file with a .txt extension.

4. In the main.cpp file, change the value of the n variable to the number of intervals in the text file and the value of the inputFile variable to the path of the text file.

      int n = 3; // Change to the number of intervals in the text file
   
   std::string inputFile = "intervals.txt"; // Change to the path of the text file
   

5. Compile and run the program.

6. The program will output the number of rooms required and print the allocated rooms for each interval.

   [10,12] - 1
   
   [11,13] - 2
   
   [14,15] - 1
   2
   

7. The program will also create an output.txt file with the same information.

## Example

Suppose we have the following intervals:

[10,12]

[11,13]

[14,15]

We can see that two rooms are required to accommodate all the intervals.

The algorithm works as follows:

1. Sort the intervals by start time.
2. Initialize an empty map rooms to keep track of allocated rooms.
3. Initialize roomNumber to 1.
4. For each interval:
   - Find the first room that is available at or after the start time of the interval.
   - If no room is available, allocate a new room and assign it to the interval.
   - If a room is available, assign it to the interval.
5. Output the number of allocated rooms.

The output for the example intervals would be:

[10,12] - 1

[11,13] - 2

[14,15] - 1
2


We can see that the first and third intervals were assigned to room 1, while the second interval was assigned to room 2.

## Error handling

The program can handle the following errors:

- Negative hours: If an interval has negative hours, the program will return -1.
- Maximum hours: If an interval has more than 24 hours, the program will return -2.
- Incorrect format: If the text file has an incorrect format, the program will return -3.
- File not found: If the text file is not found, the program will return -4.

## Dependencies

The program requires the following libraries:

- iostream
- vector
- map
- fstream
## The time complexity

The time complexity of the room allocation algorithm is O(n log n), where n is the number of intervals. This is due to the sorting of the intervals by start time, which takes O(n log n) time using an efficient sorting algorithm such as quicksort or mergesort.

In addition, the algorithm uses a map to keep track of allocated rooms, which has a worst-case time complexity of O(log n) for insertion and retrieval operations. However, since the number of rooms is typically much smaller than the number of intervals, the actual time complexity is usually much lower.

Overall, the room allocation algorithm is efficient and can handle large numbers of intervals with reasonable performance.
