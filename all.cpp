while true;
do
    echo "Enter file path:"
    read file
    echo "Enter destination path:"
    read dest

    cp "$file" "$dest"

    if [ $? -eq 0 ]
    then
        echo "File successfully copied."
        echo "List of directories:"
        ls -d */
    else
        echo "File not copied."
    fi

    echo "Do you want to copy any other file? (yes/no)"
    read ans
    if [ "$ans" != "yes" ]
    then 
        break
    fi
done
