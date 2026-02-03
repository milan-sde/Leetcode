// Print 1 to n mentioned using recursion
import java.util.*;
import java.lang.*;
import java.io.*;

class 1_PrintNums
{
    public static void print(int n){
        if(n == 0){
            return;
        }
        
        print(n-1);
        System.out.print(n + " ");
    }
	public static void main (String[] args) throws java.lang.Exception
	{
		
        int n = 5;
        print(n);
	}
}
