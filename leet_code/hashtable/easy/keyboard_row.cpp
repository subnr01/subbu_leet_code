/*
Given a List of words, return the words that can be typed using letters of alphabet 
on only one row's of American keyboard like the image below.

Example 1:
Input: ["Hello", "Alaska", "Dad", "Peace"]
Output: ["Alaska", "Dad"]

*/

class Solution {
public:
	vector<string> findWords(vector<string>& words) {

		std::unordered_set<char> dict1 = { 'q','Q','w','W','e','E','r','R','t','T','y','Y','u','U','i','I','o','O','p','P' };
		std::unordered_set<char>  dict2 = { 'a','A','s','S','d','D','f','F','g','G','h','H','j','J','k','K','l','L'};
		std::unordered_set<char>  dict3 = { 'z','Z','x','X','c','C','v','V','b','B','n','N','m','M'};

		vector<string> res;

		for (auto &word : words)
		{
			bool d1 = true, d2 = true, d3 = true;

			for (auto & ch : word)
			{
				if (d1) {
					auto it = dict1.find(ch);
					if (it == dict1.end()) d1 = false;
				}

				if (d2) {
					auto it = dict2.find(ch);
					if (it == dict2.end()) d2 = false;
				}

				if (d3) {
					auto it = dict3.find(ch);
					if (it == dict3.end()) d3 = false;
				}
			}

			if (d1 || d2 || d3) res.push_back(word);
		}

		return res;
	}
};


//Another soln
class Solution {
public:

vector<string> findWords(vector<string>& words) 
{
    vector<string> res;
    
    for(auto str : words)
    {
        bool r1 = str.find_first_of("QWERTYUIOPqwertyuiop") == string::npos ? false : true;
        bool r2 = str.find_first_of("ASDFGHJKLasdfghjkl") == string::npos ? false : true;
        bool r3 = str.find_first_of("ZXCVBNMzxcvbnm") == string::npos ? false : true;
        
        if(r1 + r2 + r3 == 1)
            res.push_back(str);
    }
    
    return res;
}
    
};
