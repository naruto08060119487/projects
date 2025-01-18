using System;
using System.Collections.Generic;
using System.Diagnostics;

namespace algorithm_assessment
{
    //SELECTION SORT
    public class Sort
    {
        public void Sorter(List<int>itemToSort)
        {
            int steps = 0;//step counter
            //timer 
            Stopwatch timer = Stopwatch.StartNew();
            
            
            //here the class for sorting would be made
            for (int i = 0; i < itemToSort.Count - 1; i++)
            {
                int minimum = i;
                for (int j = i + 1; j < itemToSort.Count; j++)
                {
                    steps++;//increment the steps or each comparison made
                    if (itemToSort[minimum] > itemToSort[j])
                    {
                        minimum = j;
                    }
                }

                int temporaryHoldValue = itemToSort[i];
                itemToSort[i] = itemToSort[minimum];
                itemToSort[minimum] = temporaryHoldValue;
                steps += 3;// Increment step count for three assigning in the swap

            }

            Console.WriteLine($"number os steps it took to sort = {steps}");
            timer.Stop();
            // Print the time taken
            Console.WriteLine($"Time taken to perform sorting: {timer.ElapsedMilliseconds} milliseconds");
        }
        
        public void descendingOrder(List<int>itemToSort)
        {
            int steps = 0;//step counter
            //timer
            Stopwatch timer = Stopwatch.StartNew();
            //here the class for sorting would be made
            for (int i = 0; i < itemToSort.Count - 1; i++)
            {
                int minimum = i;
                for (int j = i + 1; j < itemToSort.Count; j++)
                {
                    steps++;//increment the steps or each comparison made

                    if (itemToSort[minimum] < itemToSort[j])
                    {
                        minimum = j;
                    }
                }

                int temporaryHoldValue = itemToSort[i];
                itemToSort[i] = itemToSort[minimum];
                itemToSort[minimum] = temporaryHoldValue;
                steps += 3;// Increment step count for three assigning in the swap

            }
            Console.WriteLine($"number os steps it took to sort = {steps}");

            timer.Stop();
            Console.WriteLine($"Time taken to perform sorting: {timer.ElapsedMilliseconds} milliseconds");

        }
        
        
    }

    public class BubbleSort
    {
        public void AscendingOrder(List<int>itemToSort)
        {
            int steps = 0;//step counter
            Stopwatch timer = Stopwatch.StartNew();
            for (int i = 0; i < itemToSort.Count -1; i++)
            {
                for (int j = 0; j < itemToSort.Count - i - 1; j++)
                {
                    steps++;//increment the steps or each comparison made

                    if (itemToSort[j] > itemToSort[j+1])
                    {
                        int temp = itemToSort[j];
                        
                        itemToSort[j] = itemToSort[j + 1];
                        
                        itemToSort[j + 1] = temp;
                    }
                }
            }
            Console.WriteLine($"number os steps it took to sort = {steps}");

            timer.Stop();
            Console.WriteLine($"Time taken to perform sorting: {timer.ElapsedMilliseconds} milliseconds");

        }
        
        public void DescendingOrder(List<int>itemToSort)
        {
            int steps = 0;//step counter
            Stopwatch timer = Stopwatch.StartNew();
            for (int i = 0; i < itemToSort.Count -1; i++)
            {
                for (int j = 0; j < itemToSort.Count - i - 1; j++)
                {
                    steps++;//increment the steps or each comparison made

                    if (itemToSort[j] < itemToSort[j+1])
                    {
                        int temp = itemToSort[j];
                        
                        itemToSort[j] = itemToSort[j + 1];
                        
                        itemToSort[j + 1] = temp;
                    }
                }
            }
            Console.WriteLine($"number os steps it took to sort = {steps}");

            timer.Stop();
            Console.WriteLine($"Time taken to perform sorting: {timer.ElapsedMilliseconds} milliseconds");
            

        }
        
    }
    
    internal class InsertionSort
    {
        int steps = 0;//step counter
        public void InsertSort(List<int> ItemToFind)
        {
            Stopwatch timer = Stopwatch.StartNew();
            int numSorted = 1; // number of values in place
            int index; // general index

            while (numSorted < ItemToFind.Count)
            {
                // take the first unsorted value
                int temp = ItemToFind[numSorted];

                // ... and insert it among the sorted
                for (index = numSorted; index > 0; index--)
                {
                    steps++;//increment the steps or each comparison made

                    if (temp < ItemToFind[index - 1])
                    {
                        ItemToFind[index] = ItemToFind[index - 1];
                    }
                    else
                    {
                        break;
                    }
                }

                // reinsert value
                ItemToFind[index] = temp;

                numSorted++;

                timer.Stop();
            
            }
            Console.WriteLine($"number os steps it took to sort = {steps}");
            Console.WriteLine($"Time taken to perform sorting: {timer.ElapsedMilliseconds} milliseconds");


        }
        
        public void DescendingInsertSort(List<int> ItemToFind)
        {
            int steps = 0;//step counter
            Stopwatch timer = Stopwatch.StartNew();
            int numSorted = 1; // number of values in place
            int index; // general index

            while (numSorted < ItemToFind.Count)
            {
                // take the first unsorted value
                int temp = ItemToFind[numSorted];

                // ... and insert it among the sorted
                for (index = numSorted; index > 0; index--)
                {
                    steps++;//increment the steps or each comparison made

                    if (temp > ItemToFind[index - 1])
                    {
                        ItemToFind[index] = ItemToFind[index - 1];
                    }
                    else
                    {
                        break;
                    }
                }

                // reinsert value
                ItemToFind[index] = temp;

                numSorted++;
                timer.Stop();
            }
            Console.WriteLine($"number os steps it took to sort = {steps}");
            Console.WriteLine($"Time taken to perform sorting: {timer.ElapsedMilliseconds} milliseconds");


        }
    }
}