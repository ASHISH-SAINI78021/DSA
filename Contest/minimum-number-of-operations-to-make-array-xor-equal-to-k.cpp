class Solution {
        public int minOperations(int[] A, int k) {
        for (int a : A)
            k ^= a;
        return Integer.bitCount(k);
    }
}