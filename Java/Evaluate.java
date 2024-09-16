import java.util.Scanner;
import java.util.Stack;

public class Evaluate
 {
   public static void main(String[] args)
   {
      Stack<String> ops  = new Stack<>();
      Stack<Double> vals = new Stack<>();
      Scanner scanner = new Scanner(System.in);

      while (scanner.hasNext()) {
        String s = scanner.next();

         if      (s.equals("("))               ;
         else if (s.equals("+"))    ops.push(s);
         else if (s.equals("*"))    ops.push(s);
         else if (s.equals(")"))
         {
            String op = ops.pop();
            if      (op.equals("+")) vals.push(vals.pop() + vals.pop());
            else if (op.equals("*")) vals.push(vals.pop() * vals.pop());
         }
         else vals.push(Double.valueOf(s));
      }

      
      System.out.println(vals.pop());
      scanner.close();
   }
 }