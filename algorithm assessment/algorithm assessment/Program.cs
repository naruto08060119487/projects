using System;
using System.IO;

namespace algorithm_assessment
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            // Create an instance of FileReader to read files.
            fileReader reader = new fileReader();

            // Display the options for the user to choose from.
            Console.WriteLine("Select which file you want to be analyzed:");
            Console.WriteLine("1. Net_1_256.txt");
            Console.WriteLine("2. Net_2_256.txt");
            Console.WriteLine("3. Net_3_256.txt");
            Console.WriteLine("4. Net_1_2048.txt");
            Console.WriteLine("5. Net_2_2048.txt");
            Console.WriteLine("6. Net_3_2048.txt");

            string input = "";
            bool validInput = true;

            // Keep asking for input until a valid option is entered.
            while (validInput)
            {
                input = Console.ReadLine();

                // Check if the input is one of the valid options.
                if (input == "1" || input == "2" || input == "3" || input == "4" || input == "5" || input == "6")
                {
                    validInput = false;
                }
                else
                {
                    Console.WriteLine("Invalid input Please enter again.");
                }
            }

            // Changes the file name based on the user's input.
            string fileName = $"Net_{(input == "4" ? "1" : (input == "5" ? "2" : (input == "6" ? "3" : input)))}_{(input == "1" || input == "2" || input == "3" ? "256" : "2048")}.txt";
            string projectDirectory = Directory.GetParent(Environment.CurrentDirectory).Parent.FullName;  // Get the parent directory of the current directory, which should be the project directory.
            
            string filePath = Path.Combine(projectDirectory, fileName);// Combine the project directory path with the file name to get the full file path.

            try
            {
                // Read the selected file.
                reader.Reader(filePath);
            }
            catch (FileNotFoundException)
            {
                // Handle the case where the file is not found.
                Console.WriteLine($"Error: File '{fileName}' not found.");
            }
            catch (Exception ex)
            {
                // Handle other exceptions.
                Console.WriteLine($"Error: {ex.Message}");
            }
        }
    }
}
