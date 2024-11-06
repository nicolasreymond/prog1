#!/bin/bash

# Output file
output_file="results_1.csv"

# Clear the output file
> $output_file

# Write the CSV header
echo "k,Method,Result,Time" > $output_file

# Loop over different values of k
for k in {-6..-1}; do
    echo "Running labo16 with k=$k"
    result_gpt=$(./reymond_labo16 la_comedie_humaine.txt $k GPT | grep -o '[0-9,.]*' | tr '\n' ',')
    result_nre=$(./reymond_labo16 la_comedie_humaine.txt $k NRE | grep -o '[0-9,.]*' | tr '\n' ',')
    text_length_gpt=$(echo $result_gpt | cut -d',' -f1)
    time_gpt=$(echo $result_gpt | cut -d',' -f2)
    text_length_nre=$(echo $result_nre | cut -d',' -f1)
    time_nre=$(echo $result_nre | cut -d',' -f2)
    echo "$k,GPT,$text_length_gpt,$time_gpt" >> $output_file
    echo "$k,NRE,$text_length_nre,$time_nre" >> $output_file
done


echo "Results have been written to $output_file"

