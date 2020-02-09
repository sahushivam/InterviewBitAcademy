import java.io.*;
import java.util.*;

class Solution {

  static String getShortestUniqueSubstring(char[] arr, String str) {
    // your code goes here
    int min = 40;
    String shortest_sub = "";
    for(int i = 0; i < str.length(); i++) {
      boolean[] visited = new boolean[arr.length];
      int j = i;
      while(!allVisited(visited)) {
        if(j >= str.length()) {
          j = i;
          break;
        }
        checkCharInArray(str.charAt(j), arr, visited);
        j++;
      }
      String sub = str.substring(i,j);
      if(sub.length()!= 0 && sub.length() < min) {
        min = sub.length();
        shortest_sub = sub;
      }
    }
    return shortest_sub;
  }
  
  static void checkCharInArray(char ch, char [] arr, boolean[] visited) {
    for(int i = 0; i < arr.length; i++){
      if(ch == arr[i] && !visited[i]) {
        visited[i] = true;
      }
    }
  }
  
  static boolean allVisited(boolean[] visited){
    for(boolean b: visited){
      if(!b) return false;
    }
    return true;
  }

  public static void main(String[] args) {

  }

}
