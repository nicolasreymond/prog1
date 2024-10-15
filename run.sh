#!/bin/bash

# Function to print usage and exit
usage() {
    echo "Usage: $0 [-chlarn] <labo_number>"
    echo "Options:"
    echo "  -c    Clean the project root directory"
    echo "  -h    Display this help message"
    echo "  -l    List all labos"
    echo "  -r    Run the last labo"
    echo "  -a    Run all labos"
    echo "  -n    Copy the labo template to the next labo"
    echo "Arguments:"
    echo "  <labo_number>  The number of the labo to run"
    exit 1
}

# Function to list all labos
list_labos() {
    ls -d /home/nreymond/dev/heig-vd/prog1/labos/labo* | xargs -n 1 basename
    exit 0
}

# Function to run the last labo
run_last_labo() {
    LAST_LABO=$(ls -d /home/nreymond/dev/heig-vd/prog1/labos/labo* | sort | tail -n 1 | xargs -n 1 basename | sed 's/labo//')
    $0 $LAST_LABO
    exit 0
}

# Function to run all labos
run_all_labos() {
    for LABO in $(ls -d /home/nreymond/dev/heig-vd/prog1/labos/labo* | sort); do
        LABO_NUMBER=$(basename $LABO | sed 's/labo//')
        $0 $LABO_NUMBER
    done
    exit 0
}

# Function to copy the labo template to the next labo and rename .cpp files
copy_next_labo() {
    LAST_LABO=$(ls -d /home/nreymond/dev/heig-vd/prog1/labos/labo* | sort -V | tail -n 1 | xargs -n 1 basename | sed 's/labo//')
    NEXT_LABO=$((LAST_LABO + 1))
    current_date=$(date +%d.%m.%Y)
    mkdir -p /home/nreymond/dev/heig-vd/prog1/labos/labo$NEXT_LABO
    cp -r /home/nreymond/dev/heig-vd/prog1/labos/labo0/* /home/nreymond/dev/heig-vd/prog1/labos/labo$NEXT_LABO
    for FILE in /home/nreymond/dev/heig-vd/prog1/labos/labo$NEXT_LABO/*.cpp; do
        mv "$FILE" "/home/nreymond/dev/heig-vd/prog1/labos/labo$NEXT_LABO/reymond_labo$NEXT_LABO.cpp"
        # Replace the date in the file from 00.00.0000 to the current date
        sed -i "s/00.00.0000/$current_date/g" "/home/nreymond/dev/heig-vd/prog1/labos/labo$NEXT_LABO/reymond_labo$NEXT_LABO.cpp"
    done
    echo "Copied labo template to labo$NEXT_LABO and renamed .cpp files"
    exit 0
}

# Parse command line options
CLEAN_MODE=0

while getopts "chlarn" opt; do
    case $opt in
        c)
            CLEAN_MODE=1
            ;;
        h)
            usage
            ;;
        l)
            list_labos
            ;;
        r)
            run_last_labo
            ;;
        a)
            run_all_labos
            ;;
        n)
            copy_next_labo
            ;;
        *)
            echo "Invalid option: -$opt" >&2
            usage
            ;;
    esac
done

# Shift the parsed options away
shift $((OPTIND - 1))

# Check if the labo number is provided
[ -z "$1" ] && usage

LABO_NUMBER=$1
LABO_DIR="/home/nreymond/dev/heig-vd/prog1/labos/labo$LABO_NUMBER"
LABO_SCRIPT="$LABO_DIR/reymond_labo$LABO_NUMBER"

# Check if the labo directory exists
if [ ! -d "$LABO_DIR" ]; then
    echo "Labo directory $LABO_DIR does not exist."
    exit 1
fi


# Function to clean the project root directory
clean_project_root() {
    make clean
    echo "Cleaned project root directory"
    exit 0
}

# Clean the project root directory if -c flag is set but not the labo directory
if [ $CLEAN_MODE -eq 1 ]; then
    clean_project_root
fi

# Run make in the labo directory
if make -C "$LABO_DIR"; then
    # Run the labo script if it exists and is executable
    if [ -x "$LABO_SCRIPT" ]; then
        "$LABO_SCRIPT"
    else
        echo "Labo script $LABO_SCRIPT not found or not executable."
        exit 1
    fi
else
    echo "Make failed in $LABO_DIR."
    exit 1
fi
