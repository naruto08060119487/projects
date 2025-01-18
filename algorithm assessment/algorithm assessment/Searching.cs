using System;
using System.Collections.Generic;
using System.Diagnostics;


namespace algorithm_assessment
{
    internal class Searching
    {
       
        //my linear search algorithm
        public int finder(List<int> itemToFind, int value)
        {
            int stepCounter = 0;

            //timer `
            Stopwatch timer = Stopwatch.StartNew();


            //Here the the searcher is created
            for (int i = 0; i < itemToFind.Count; i++)
            {
                stepCounter++;
                if (itemToFind[i] == value)
                {
                    Console.WriteLine($"steps taken to search for value {stepCounter}");

                    timer.Stop();
                    // Print the time taken
                    Console.WriteLine($"Time taken t    o perform searching: {timer.ElapsedMilliseconds} milliseconds");
                    Console.WriteLine(" ");
                    
                    return i + 1;
                }
            }
            Console.WriteLine($"steps taken to search for value {stepCounter}");

            return -1;
        }
        public int FindingNearestValue(List<int> itemToFind, int value)
        {
            int stepCounter = 0;
            //this finds the nearest value if a requested value is not found 
            int closest = itemToFind[0];
            int difference = Math.Abs(value - closest);
            for (int i = 1; i < itemToFind.Count; i++)
            {
                stepCounter++;
                int currentDifference = Math.Abs(value - itemToFind[i]);
                if (currentDifference < difference)
                {
                    closest = itemToFind[i];
                    difference = currentDifference;
                    Console.WriteLine($"steps taken to search for value {stepCounter}");
                }
            }

            return itemToFind.IndexOf(closest);

        }

    }

    public class BinarySearch
    {
        public int BinSearch(List<int> itemToFind, int value)
        {
            int stepCounter = 0;
            Stopwatch timer = Stopwatch.StartNew();
            int low = 0;
            int high = itemToFind.Count - 1;

            while (low <= high)
            {
               
                int middle = low + (high - low) / 2;
                int index = itemToFind[middle];
                
                stepCounter++;
                Console.WriteLine("middle: " + index);

                if (index < value)
                {
                    low = middle + 1;
                }
                else if (index > value)
                {
                    high = middle - 1;
                }
                else
                {
                    return middle + 1; //makes the index start from 1 instead of 0
                }
                Console.WriteLine($"steps taken to search for value {stepCounter}");
                timer.Stop();
                // Print the time taken
                Console.WriteLine($"Time taken to perform searching: {timer.ElapsedMilliseconds} milliseconds");
            }


            return -1; //returns -1 if nothing is found
        }
    }

    
}