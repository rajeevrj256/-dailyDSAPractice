import java.util.*;

class TimeMap {

    HashMap<String, TreeMap<Integer, String>> map;

    public TimeMap() {
         map = new HashMap<>();
    }

    public void set(String key, String value, int timestamp) {

      map.putIfAbsent(key, new TreeMap<>());
        map.get(key).put(timestamp, value);
    }

    // private int findTimeStampTarget(ArrayList<Integer> arr, int target) {

    //     int ans = -1;

    //     int i = 0;
    //     int j = arr.size() - 1;

    //     while (i <= j) {

    //         int mid = i + (j - i) / 2;

    //         if (arr.get(mid) == target) {
    //             return target;
    //         }

    //         if (arr.get(mid) > target) {
    //             j = mid - 1;
    //         } else {
    //             ans = arr.get(mid);
    //             i = mid + 1;
    //         }
    //     }

    //     return ans;
    // }

    public String get(String key, int timestamp) {

        if (!map.containsKey(key))
            return "";


        TreeMap<Integer, String> tree = map.get(key);

       Map.Entry<Integer, String> entry = tree.floorEntry(timestamp);

        if (entry == null)
            return "";

        return entry.getValue();
    }
}

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap obj = new TimeMap();
 * obj.set(key, value, timestamp);
 * String param_2 = obj.get(key, timestamp);
 */