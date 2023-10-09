#!/bin/bash

# Name of the folder to compile
folder="/apps/binary/tfel/behaviors/"

# List of compilation options
compile_options=("FullChabocheMemory" "LinearIsotropic" "LinearKinematic")

# Check if the folder exists
if [ -d "$folder" ]; then
  echo "Entering folder: $folder..."
  cd "$folder" || { echo "Failed to change directory to $folder"; exit 1; }

  # Loop through each compilation option and compile
  for option in "${compile_options[@]}"; do
    echo "Compiling with option: $option..."
    
    # Run the compilation command with the current option
    # Replace 'your_compilation_command' with the actual compilation command
    # Example: make $option
    mfront --obuild $option/$option.mfront --interface=aster

    # Check if the compilation was successful
    if [ $? -eq 0 ]; then
      echo "Compilation with option $option successful."
    else
      echo "Compilation with option $option failed."
      exit 1  # Exit the script if compilation fails with any option
    fi
  done

  # Return to the original directory
  cd ..
else
  echo "Folder $folder does not exist."
  exit 1
fi
