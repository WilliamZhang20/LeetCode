# Read from the file file.txt and print its transposed content to stdout.
awk '{
    for(i=1; i<=NF; i++) {
        if(NR == 1) {
            col_data[i] = $i
        } else {
            col_data[i] = col_data[i] " " $i
        }
    }
}
END {
    {
        for(i=1; i<=NF; i++) {
            print col_data[i]
        }
    }
}' file.txt