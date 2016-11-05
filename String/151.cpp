//my code, not correct and not complete
class Solution {
public:
    void reverseWords(string &s) {
        if(s.empty()) {
            return ;
        }
        if(s[0] == ' ') {
            s.erase(s.begin());
            return ;
        }
        /*for(int i = 0; i < s.size(); ++i) {
            if(s[i] == ' ') {
                s.erase(s.begin());
            } else{
                break;
            }
        }*/
        reverse(s, 0, s.size() - 1);
        int begin = 0, end = 0;
        for(int i = 0; i < s.size() - 1; ++i) {
            if(s[i] == ' ') {
                reverse(s, begin, end);
                if(i + 1 <= s.size() - 1) {
                    begin = i + 1;
                    end = i + 1;
                }
            }
            if(s[i] != ' ') {
                end = i;
            }
        }
    }
    void reverse(string& s, int i, int j) {
        while(i < j) {
            swap(s[i], s[j]);
            ++i;
            --j;
        }
    }
};


//Find online, time: O(n), space: O(1)
class Solution {
public:
    void reverseword(string &s, int i, int j) {
        while(i < j) {
          char t = s[i];
          s[i++] = s[j];
          s[j--] = t;
        } 
    }

    void reverseWords(string &s) {
        int i = 0, j = 0;
        int temp = 0;
        int len = s.length();
        int wordcount = 0;
        
        while(true) {
            while(i < len && s[i] == ' ') {
                i++;  // skip spaces in front of the word
            }
            if(i == len) {
                break;
            }
            if(wordcount) {
                s[j++] = ' ';
            }
            temp = j;
            while(i < len && s[i] != ' ') {
                s[j] = s[i]; 
                j++; 
                i++;
            } 
            reverseword(s, temp, j - 1);                // reverse word in place
            wordcount++;
        }
        s.resize(j);                           // resize result string
        reverseword(s, 0, j - 1);                  // reverse whole string
    }
};



//Find online, time: O(n), space: O(n)
class Solution {
public:
    void reverseWords(string &s) {
        string r;
        int i = s.size() - 1, end;
        while (i >= 0) {
            while(s[i] == ' ' && i >= 0) {
                --i; //skip the trailing spaces
            }
            end = i + 1;
            if(i >= 0 && !r.empty()) {
                r += ' '; //add the space in the next loop to avoid the extra space in the tail
            }
            while(s[i] != ' ' && i >= 0) {
                --i;  //find the start of the word
            }
            for(int k = i + 1; k < end; ++k) {
                r += s[k]; // add chars for [k, end) to r
            }
        }
        s = r;
    }
};


//my code, similar above, 06/12/2016
class Solution {
public:
    void reverseWords(string &s) {
        string result = "";
        int begin = s.size() - 1;
        int end;
        while(begin >= 0) {
            while(s[begin] == ' ') {
                --begin;
            }
            end = begin;
            if(result.size() && begin >= 0) {
                result += ' ';
            }
            while(s[begin] != ' ' && begin >= 0) {
                --begin;
            }
            for(int i = begin + 1; i <= end; ++i) {
                result += s[i];
            }
        }
        s = result;
    }
};



class Solution {
public:
    void reverseWords(string &s) {
        int i = 0, j = 0;
        int words = 0;
        int temp = 0;
        int len = s.length();
        
        while(true) {
            while(i < len && s[i] == ' ') {
                ++i;
            }
            if(i == len) {
                break;
            }
            if(words) {
                s[j++] == ' ';
                //++j;
            }
            temp = j;
            while(i < len && s[i] != ' ') {
                s[j] = s[i];
                ++i;
                ++j;
            }
            reverse(s, temp, j - 1);
            ++words;
        }
        s.resize(j);
        reverse(s, 0, j - 1);
    }
    
    
    void reverse(string& s, int begin, int end) {
        while(begin < end) {
            swap(s[begin], s[end]);
            ++begin;
            --end;
            // char t = s[begin];
            // s[begin] = s[end];
            // ++begin;
            // s[end] = t;
            // --end;
        }
    }
};


//my code, 06/21/2016, time: O(n), space: O(n)
class Solution {
public:
    void reverseWords(string &s) {
        string result;
        int i = s.size() - 1;
        int begin = 0, end = 0;
        while(i >= 0) {
            while(i >= 0 && s[i] == ' ') {
                --i;
            }
            if(!result.empty() && i >= 0) {
                result += ' ';
            }
            end = i;
            while(i >= 0 && s[i] != ' ') {
                --i;
            }
            begin = i + 1;
            for(int j = begin; j <= end; ++j) {
                result += s[j];
            }
        }
        s = result;
    }
};


//my code, 06/21/2016, time: O(n), space: O(1)
class Solution {
public:
    void reverseWords(string &s) {
        int i = 0, j = 0;
        int words = 0;
        int temp = 0;
        while(true) {
            while(i < s.size() && s[i] == ' ') {
                ++i;
            }
            if(i == s.size()) {
                break;
            }
            if(words) {
                s[j] = ' ';
                ++j;
            }
            temp = j;
            while(i < s.size() && s[i] != ' ') {
                s[j] = s[i];
                ++i;
                ++j;
            }
            reverse(s, temp, j - 1);
            ++words;
        }
        s.resize(j);
        reverse(s, 0, s.size() - 1);
    }
    void reverse(string& s, int begin, int end) {
        while(begin < end) {
            swap(s[begin], s[end]);
            ++begin;
            --end;
        }
    }
}