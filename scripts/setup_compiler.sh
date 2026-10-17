#!/bin/bash

# Define variables
BASE_DIR="tools"
TARGET_DIR="$BASE_DIR/cc/ee-gcc2.96"
FILE_URL="https://github.com/decompme/compilers/releases/download/compilers/ee-gcc2.96.tar.xz"
TAR_FILE="ee-gcc2.96.tar.xz"

# v4.1: second compiler for the Sony SDK segments (yaml option `cc=ee-gcc2.9-991111`, see configure.py)
CC2_DIR="$BASE_DIR/cc/ee-gcc2.9-991111"
CC2_URL="https://github.com/decompme/compilers/releases/download/compilers/ee-gcc2.9-991111.tar.xz"
CC2_TAR="ee-gcc2.9-991111.tar.xz"

# Create destination directory if it does not exist
mkdir -p "$TARGET_DIR"

echo "Downloading $FILE_URL..."
curl -L -o "$TAR_FILE" "$FILE_URL"

# Extract the file
tar -xf "$TAR_FILE" -C "$TARGET_DIR"

# Set executable permissions for binaries in the cc directory
chmod +x -R "$TARGET_DIR"

# Clean up by removing the downloaded file
rm "$TAR_FILE"

mkdir -p "$CC2_DIR"
echo "Downloading $CC2_URL..."
curl -L -o "$CC2_TAR" "$CC2_URL"
tar -xf "$CC2_TAR" -C "$CC2_DIR"
chmod +x -R "$CC2_DIR"
rm "$CC2_TAR"

echo "Download and extraction completed."
