/*
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the"


*/



class Solution {
public:

    // function to reverse any part of string from i to j (just one word or entire string)
    void reverseword(string &s, int i, int j){
        while(i<j){
          char t=s[i];
          s[i++]=s[j];
          s[j--]=t;
        } 
    }
    
    void reverseWords(string &s) {
        
        int i=0, j=0;
        int l=0;
        int len=s.length();
        int wordcount=0;
        
        while(true){
            while(i<len && s[i] == ' ') i++;  // skip spaces in front of the word
            if(i==len) break;
            if(wordcount) s[j++]=' ';
            l=j;
            while(i<len && s[i] != ' ') {s[j]=s[i]; j++; i++;} 
            reverseword(s,l,j-1);                // reverse word in place
            wordcount++;
            
        }
        
        s.resize(j);                           // resize result string
        reverseword(s,0,j-1);                  // reverse whole string
    }
};



/*
Geeksforgeeks solution
*/

/*Function to reverse words*/
void reverseWords(char *s)
{
  char *word_begin = s;
  char *temp = s; /* temp is for word boundry */
 
  /*STEP 1 of the above algorithm */
  while( *temp )
  {
    temp++;
    if (*temp == '\0')
    {
      reverse(word_begin, temp-1);
    }
    else if(*temp == ' ')
    {
      reverse(word_begin, temp-1);
      word_begin = temp+1;
    }
  } /* End of while */
 
   /*STEP 2 of the above algorithm */
  reverse(s, temp-1);
}
 
/* UTILITY FUNCTIONS */
/*Function to reverse any sequence starting with pointer
  begin and ending with pointer end  */
void reverse(char *begin, char *end)
{
  char temp;
  while (begin < end)
  {
    temp = *begin;
    *begin++ = *end;
    *end-- = temp;
  }
}

