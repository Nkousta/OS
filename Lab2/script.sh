#!/bin/bash
current_time=$(date +%s)
echo "Current Time: $current_time"
echo "Current Time * 2: $(($current_time * 2))"

for i in {1..20}
do
    echo $i
done

