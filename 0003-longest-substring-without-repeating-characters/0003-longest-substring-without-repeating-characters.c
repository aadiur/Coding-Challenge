int lengthOfLongestSubstring(char* s) {
    int maxLen = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        int len = 0;

        for (int j = i; s[j] != '\0'; j++) {
            int duplicate = 0;

            // Check if s[j] already exists
            // in the current substring
            for (int k = i; k < j; k++) {
                if (s[k] == s[j]) {
                    duplicate = 1;
                    break;
                }
            }

            if (duplicate == 1) {
                break;
            }

            len++;
        }

        if (len > maxLen) {
            maxLen = len;
        }
    }

    return maxLen;
}