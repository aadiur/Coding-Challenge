class Solution {
    public double findMedianSortedArrays(int[] a, int[] b) {
        int[] merged = new int[a.length + b.length];
        int i=0, j=0, k=0;

        while (i < a.length && j < b.length) {
            if (a[i] < b[j]) merged[k++] = a[i++];
            else merged[k++] = b[j++];
        }

        while (i < a.length) merged[k++] = a[i++];
        while (j < b.length) merged[k++] = b[j++];

        int n = merged.length;
        if (n % 2 == 0)
            return (merged[n/2 - 1] + merged[n/2]) / 2.0;
        else
            return merged[n/2];
    }
}