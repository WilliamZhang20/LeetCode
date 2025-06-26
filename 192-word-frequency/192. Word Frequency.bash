# Read from the file words.txt and output the word frequency list to stdout.

declare -A word_count

while read line; do
    for word in $line; do
        if [[ -v word_count["$word"] ]]; then
            ((word_count["$word"]++))
        else
            word_count["$word"]=1
        fi
    done
done < "words.txt"

sortHash() {
    local IFS=$'\n'
    for word in $(sort -nr <<< "${word_count[*]}"); do
        for key in "${!word_count[@]}"; do
            if [[ "${word_count[$key]}" == "$word" ]]; then
                echo "$key ${word_count[$key]}"
                break
            fi
        done
    done
}

sortHash