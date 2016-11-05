//Find online
import java.util.*;
public class BinaryWatch401 {

    final int[] watch = {1, 2, 4, 8, 1, 2, 4, 8, 16, 32};
    
    public List<String> readBinaryWatch(int num) {
        List<String> list = new ArrayList<String>();
            if(num >= 0) {
                read_recursion(num, 0, list, 0 , 0);
            }
            return list;
    }

    private void read_recursion(int num, int start, List<String> list, int hour, int minute) {
    	if(num <= 0) {
    	    if(hour < 12 && minute < 60) {
    	        if(minute < 10) {
    	            list.add(hour + ":0" + minute); 
    	        } else {
    	            list.add(hour + ":" + minute);
    	        } 
        	}
    	} else {
            for(int i = start; i < watch.length; i++) {
	    		if(i < 4) {
	    		    read_recursion(num - 1, i + 1, list, hour + watch[i], minute);
	    		} else {
	    		    read_recursion(num - 1, i + 1, list, hour, minute + watch[i]);
	    		}
            }
        }
    }

     public static void main(String[] args){
        System.out.println("Hello World");
    }
}




 