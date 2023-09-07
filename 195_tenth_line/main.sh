####################################################
##                    LeetCode                    ##
##                195. Tenth Line                 ##
##            Solution by Lorin Lange             ##
####################################################

#!/ bin/bash

# Read from the file file.txt and 
# output the tenth line to stdout.

# check if file exists
if [ ! -f file.txt ]; then
  echo "The file file.txt doesn't exist."
  exit 1
fi

# check if the file contains at least 10 lines
line_num=$(cat file.txt | wc -l )
if [ $line_num -lt 10 ]; then
    exit 1
fi

# print the 10h line
i=1  
while read line; do
    if [[ $i -eq 10 ]]; then
        echo $line
    fi
i=$((i+1))  
done < 'file.txt'

# sed -n '10p' file.txt
# head -n 10 file.txt | tail -n +10
# awk '{if (NR == 10) print $0}' file.txt