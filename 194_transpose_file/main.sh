####################################################
##                    LeetCode                    ##
##              194. Transpose File               ##
##            Solution by Lorin Lange             ##
####################################################

#!/ bin/bash

# Read from the file file.txt and 
# print its transposed content to stdout.

cols=$(head -1 'file.txt' | wc -w)
for col in $(seq 1 $cols); do
    echo $(cut -d ' ' -f $col 'file.txt')
done

# awk
