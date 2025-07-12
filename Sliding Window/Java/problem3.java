class Solution {
    public int lengthOfLongestSubstring(String s) {
        Set<Character> c = new HashSet<>();
        int left = 0;
        int right = 1;
        int max_len = 0;
        if(s.length() == 1) {
            return 1;
        }
        String tmp = "";
        if(s.length() > 0) {
            tmp += s.charAt(left);
        }
        while(left < s.length()) {
            if(right < s.length() && 
            (c.contains(s.charAt(left)) && c.contains(s.charAt(right)))) {
                //clear the set:
                c.clear();
                tmp = "";
                left ++;
                tmp += s.charAt(left);
                right = left + 1;
            } else {
                if(right >= s.length()) break;
                c.add(s.charAt(left)); // add left first
                // check null of right
                if(right < s.length() && !c.contains(s.charAt(right))) {
                    c.add(s.charAt(right));
                    tmp += s.charAt(right);
                }
                //c.addAll(Arrays.asList(s.charAt(left), s.charAt(right)));
                right++;
            }

            if(tmp.length() >= max_len) {
                max_len = tmp.length();
            }
        }
        return max_len;
    }
}
