import os

# The root directory of your source files
root_dir = '../src/'
# The output file to write the source file paths to
output_file = 'source_files.cmake'

# List to hold all of the source file paths
source_files = []

SOURCES = "${SOURCES}"
CMAKE_CURRENT_SOURCE_DIR = "${CMAKE_CURRENT_SOURCE_DIR}"

# Walk through the directory
for root, dirs, files in os.walk(root_dir):
    for file in files:
        if file.endswith('.cpp') or file.endswith('.h'):  # Change this if you use different file extensions
            # Create a relative path from the root_dir to the file and replace backslashes with forward slashes
            relative_path = os.path.join(root, file).replace(root_dir, '').replace('\\', '/')
            source_files.append(relative_path)

# Write the source files to the output file
with open(output_file, 'w') as f:
    f.write("set(SOURCE_FILE\n")
    for file in source_files:
        f.write(f'\t{CMAKE_CURRENT_SOURCE_DIR}/src/{file}\n')
    f.write(")")
    print(f'Written {len(source_files)} source files to {output_file}')
