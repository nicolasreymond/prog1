#!/bin/bash

# Function to print usage and exit
usage() {
    echo "Usage: $0 [-chrn] <labo_number>"
    echo "Options:"
    echo "  -c    Clean the project root directory"
    echo "  -h    Display this help message"
    echo "  -n    Copy the labo template to the next labo"
    echo "  -r    Run a specific labo"
    echo "Arguments:"
    echo "  <labo_number>  The number of the labo to run"
    exit 1
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

# Function to clean the project root directory
clean_project_root() {
    make clean
    echo "Cleaned project root directory"
    exit 0
}

# Function to run a specific labo
run_labo() {
    LABO_NUMBER=$1
    LABO_DIR="/home/nreymond/dev/heig-vd/prog1/labos/labo$LABO_NUMBER"
    LABO_SCRIPT="$LABO_DIR/reymond_labo$LABO_NUMBER"

    # Check if the labo directory exists
    if [ ! -d "$LABO_DIR" ]; then
        echo "Labo directory $LABO_DIR does not exist."
        exit 1
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
}

# Parse command line options
CLEAN_MODE=0
RUN_MODE=0

while getopts "chrn" opt; do
    case $opt in
        c)
            CLEAN_MODE=1
            ;;
        h)
            usage
            ;;
        n)
            copy_next_labo
            ;;
        r)
            RUN_MODE=1
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

# Clean the project root directory if -c flag is set but not the labo directory
if [ $CLEAN_MODE -eq 1 ]; then
    clean_project_root
fi

# Run the specific labo if -r flag is set
if [ $RUN_MODE -eq 1 ]; then
    run_labo $LABO_NUMBER
fi
