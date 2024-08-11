# Array and Hashing

## Group Anagram
### Algorithm: to find the group of anagram we must following each step:
1. step1: count every character inside the string and store the count into a string distinguish by #  from a-z for example, bddddddddddd, we have 1(b) and 10(d) so the string is #0#1#0#10#0#0...#0
```c++
  vector<int> char_freq(26, 0); // 26 element, each element initalized value 0
  string ctn = "";
  for(char &c : my_string)
  {
      char_freq[c - 'a']++; //incerase the value of the char freq when count every character inside a string
  }
```
2. step2: store that string as a key and the string that contain that sub string as value into a map
```c++
for(auto it : char_freq)
{
    ctn += "#" + to_string(it); // add "#" to distinguish 
}
char_freq_ctn.push_back(ctn);
string_map.insert({ctn, my_string});
```
3. step3: find group of anagram in the map and group them into a vector then push to a vector
```c++
 for(int i = 0; i < char_freq_ctn.size(); i++)
{
    auto it = string_map.find(char_freq_ctn[i]);
    vector<string> temp_result;
    bool anagramFound = false;
    while(it != string_map.end()) // if find the anagram
    {
        anagramFound = true;
        temp_result.push_back(it->second); // group them and delete the anagram found
        string_map.erase(it);
        it = string_map.find(char_freq_ctn[i]);
    }
    if(anagramFound)
    {
        final_result.push_back(temp_result);
    }
}
```
### Time complexity: O(m x n)
4. step 4: return this vector;

