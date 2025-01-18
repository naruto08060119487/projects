using System;
using System.Collections.Generic;
using System.IO;

namespace algorithm_assessment
{
    internal class fileReader

    {
         
        public void Reader(string filePath)
        {
            InsertionSort sorting = new InsertionSort();
            BinarySearch Search = new BinarySearch(); //the binary search method from the searching class was instantiated
            Searching find = new Searching(); //the linear search method from the searching class was instantiated
            Sort sorter = new Sort(); //instantiating the selection sort algorithm
            BubbleSort sort = new BubbleSort(); //instantiating the bubble sort algorithm
            
            List<int> List = new List<int>();  //creating  a list to store the values read from the filepath
            try
            {
                using (StreamReader reader = new StreamReader(filePath))
                {
                    string line = reader.ReadLine();
                    //Reading the values from the file
                    while (line != null)
                    {
                        //parsing the line as an integer                                               
                        if (int.TryParse(line, out int value))
                        {
                            List.Add(value);
                            
                        }
                        else
                        {
                            Console.WriteLine($"Unable to parse line: {line}");
                        }

                        line = reader.ReadLine();
                    }
                }

                bool response = true; //using a while true loop to ensure inputs 1
                
                //sorting algorithm selection
                while (response)
                {
                    Console.WriteLine("What Type Of sorting algorithm do you want to use");
                    Console.WriteLine("1. Selection Sort");
                    Console.WriteLine("2. Bubble Sort");
                    Console.WriteLine("3. Insertion Sort");
                    string convo = Console.ReadLine();

                    if (convo == "1") //initiates selection sort
                    {
                        bool ans = true;
                        while (ans)
                        {
                            Console.WriteLine("1. sort ascending order?");
                            Console.WriteLine("2. sort descending order?");
                            string reply = Console.ReadLine();

                            if (reply == "1")
                            {//sorting in ascending order
                                sorter.Sorter(List);
                                ans = false;
                            }
                            else if (reply == "2")
                            {//sorting in descending order
                                sorter.descendingOrder(List);
                                ans = false;
                            }
                            else
                            {
                                Console.WriteLine("invalid input");
                            }

                            response = false;

                        }
                    }
                    else if (convo == "2") //initiates bubble sort
                    {
                        bool ans = true;
                        while (ans)
                        {
                            Console.WriteLine("1. sort ascending order?");
                            Console.WriteLine("2. sort descending order?");
                            string reply = Console.ReadLine();

                            if (reply == "1")
                            {//sorting in ascending order
                                sort.AscendingOrder(List);
                                ans = false;
                            }
                            else if (reply == "2")
                            {// sorting in descending order
                                sort.DescendingOrder(List);
                                ans = false;
                            }
                            else
                            {
                                Console.WriteLine("invalid input");
                            }

                            response = false;

                        }
                    }
                    else if (convo =="3")
                    {
                        bool ans = true;
                        while (ans)
                        {
                            Console.WriteLine("1. sort ascending order?");
                            Console.WriteLine("2. sort descending order?");
                            string reply = Console.ReadLine();

                            if (reply == "1")
                            {//sorting in ascending order
                                sorting.InsertSort(List);
                                ans = false;
                            }
                            else if (reply == "2")
                            {// sorting in descending order
                                sorting.DescendingInsertSort(List);
                                ans = false;
                            }
                            else
                            {
                                Console.WriteLine("invalid input");
                            }

                            response = false;

                        }
                    }
                    else
                    {
                        Console.WriteLine("Invalid Input"); //if nothing is given
                    }
                }
                Console.WriteLine("Contents in List (Sorted):");//prints out the sorted list
                Console.WriteLine("");
                Console.WriteLine(string.Join(Environment.NewLine, List));

                Console.WriteLine("printing out values according to list size between the 256 path and 2048 path ");
                if (List.Count > 256)
                {
                    Console.WriteLine("\nEvery 50th value:");//EVERY 50TH VALUE IF THE ITEM IN THE LIST IS MORE THAN SPECIFED
                    for (int i = 49; i < List.Count; i += 50)
                    {
                        Console.WriteLine(List[i]);
                    }
                }
                else
                {
                    Console.WriteLine("\nEvery 10th value:");//EVERY 10TH VALUE IF THE ITEM IN THE LIST IS MORE THAN SPECIFED
                    for (int i = 9; i < List.Count; i += 10)
                    {
                        Console.WriteLine(List[i]);
                    }
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Error reading file: {ex.Message}"); //handles any error when reading the files
                throw;
            }

            bool verifyInput = true;
            while (verifyInput)//uses a while true loop to verify the input of the user
            {//searching algorithm selection
                Console.WriteLine("Do you want to find a value?");
                Console.WriteLine("1. YES");
                Console.WriteLine("2. NO");
                string response = Console.ReadLine();
                if (response == "1" || response == "YES".ToLower())
                {
                    Console.WriteLine("what searching algorithm do you want to use"); //user chooses the search algorithm he wants to use
                    Console.WriteLine("1. linear search");
                    Console.WriteLine("2. Binary search");
                    string ans = Console.ReadLine();
                    
                    if (ans == "1")//initiates linear search algorithm
                    {//this checks the input to verify that the input is an integer
                        Console.WriteLine("Enter the value to find :");

                        
                        int resp = 0; 
                        bool verify = true;
                        while (verify)
                        {
                            string answer = Console.ReadLine();

                            if (int.TryParse(answer, out resp))//parsing the users input into an integer
                            {
                                verify = false;
                            }
                            else
                            {
                                Console.WriteLine("invalid input");//shows this message if theres any errors in the input
                                Console.WriteLine("enter again");
                            }
                        }
                    
                        int sam = find.finder(List, resp); //here the linear search is used
                        if (sam != -1)
                        {
                            Console.WriteLine($"found {resp} at index {sam}");
                            verifyInput = false;
                        }
                        else if (sam == -1)
                        {
                            Console.WriteLine($"Value {resp} not found. Trying to find the nearest value.");

                            int nearestIndex = find.FindingNearestValue(List, resp);//here the nearestValue method is used if an input searched is not found
                            if (nearestIndex != -1)
                            {
                                int nearestValue = List[nearestIndex];
                                Console.WriteLine($"Nearest value to {resp} is {nearestValue} at index {nearestIndex}");
                            }
                            else
                            {
                                Console.WriteLine($"No nearest value found for {resp}. The list is either empty or no other values exist.");//prints out the nearest value and its index if an item is not found
                            }
                        }
                    }
                    else if (ans == "2")
                    {
                        Console.WriteLine("Enter the value to find :");

                        
                        int resp = 0; ;
                        bool verify = true;
                        while (verify)
                        {//this checks the input to verify that the input is an integer
                            string answer = Console.ReadLine();

                            if (int.TryParse(answer, out resp))//parsing the users input into an integer
                            {
                                verify = false;
                            }
                            else
                            {
                                Console.WriteLine("invalid input");//shows this message if theres any errors in the input
                                Console.WriteLine("enter again");
                            }
                        }
                    
                        int sam = Search.BinSearch(List, resp);//here the binary search is used
                        if (sam != -1)
                        {
                            Console.WriteLine($"found {resp} at index {sam}");
                            verifyInput = false;
                        }
                        else if (sam == -1)
                        {
                            Console.WriteLine($"Value {resp} not found. Trying to find the nearest value.");

                            int nearestIndex = find.FindingNearestValue(List, resp);//here the nearestValue method is used if an input searched is not found
                            if (nearestIndex != -1)
                            {
                                int nearestValue = List[nearestIndex];
                                Console.WriteLine($"Nearest value to {resp} is {nearestValue} at index {nearestIndex}");//prints out the nearest value and its index if an item is not found
                            }
                            else
                            {
                                Console.WriteLine($"No nearest value found for {resp}. The list is either empty or no other values exist.");
                            }
                        }
                        
                    }
                }
                
                else if (response == "2"|| response == "NO".ToLower())
                {
                    Console.WriteLine("ok Exiting");//exits the program if the user doesnt want to search for a value
                    verifyInput = false;
                    
                }
                else
                {
                    Console.WriteLine("invalid pick Try again");
                }
            }
        }
    }
}

