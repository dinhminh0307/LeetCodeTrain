import java.util.HashMap;
import java.util.Map;

class Solution {
    public int singleNumber(int[] nums) {
        HashMap<Integer, Integer> m = new HashMap<>();

        for(int i : nums) {
            if(!m.containsKey(i)) {
                m.put(i, 1);
            } else {
                m.put(i, m.get(i) + 1);
            }
        }

        for(Map.Entry<Integer, Integer> s : m.entrySet()) {
            if(s.getValue() == 1) {
                return s.getKey();
            }
        }
        return 0;
    }
}