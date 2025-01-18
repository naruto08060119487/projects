using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CMP1903_A1_2324
{
    internal class Program
    {
        static void Main(string[] args)
        {
            /*
             * Create a Game object and call its methods.
             */
            Game dice= new Game();
            Console.WriteLine("original Game");
            dice.PLay();//initial games
            
             /* Create a Testing object to verify the output and operation of the other classes.
             */
            Testing test = new Testing();
            test.GameTest();// testing the game and Die
            Console.WriteLine(" ");
                
        }
    }
}
