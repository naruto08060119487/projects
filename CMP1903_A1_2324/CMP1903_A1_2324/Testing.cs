using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CMP1903_A1_2324
{
    internal class Testing
    {
        /*
         * This class should test the Game and the Die class.
         * Create a Game object, call the methods and compare their output to expected output.
         */
        public void GameTest() //GameTest method
        {
            //CREATES TWO GAMES AND COMPARES THEIR METHODS
            Game game = new Game();
            Console.WriteLine("Test 1");
            int test1 = game.PLay(); //this uses the game class method


            Debug.Assert(test1 < 3 || test1 > 18, "Game test Failed"); //this compares the outcome of the game to see is the total is
            //within 3 - 18

            /* Create a Die object and call its method.
             * Use debug.assert() to make the comparisons and tests.*/


            //Method


            Die die = new Die();
            int outcome = die.Roll(); //creates a die to be tested

            Debug.Assert(outcome >= 1 && outcome <= 6, "Die test failed");// compares the output of the DieTEst
        } 
            
            
            
        

        
    }
}
