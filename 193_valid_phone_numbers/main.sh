####################################################
##                    LeetCode                    ##
##            193. Valid Phone Numbers            ##
##            Solution by Lorin Lange             ##
####################################################

#!/ bin/bash

# Read from the file file.txt and output 
# all valid phone numbers to stdout.

# (xxx) xxx-xxxx 
# xxx-xxx-xxxx

grep -E "^[0-9]{3}-[0-9]{3}-[0-9]{4}$|^\([0-9]{3}\) [0-9]{3}-[0-9]{4}$" file.txt