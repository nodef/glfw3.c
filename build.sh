#!/usr/bin/env bash
# Fetch the latest version of the library
fetch() {
if [ -d "GLFW" ]; then return; fi
URL="https://github.com/glfw/glfw/releases/download/3.4/glfw-3.4.zip"
ZIP="${URL##*/}"
DIR="${ZIP%.zip}"
mkdir -p .build
cd .build

# Download the release
if [ ! -f "$ZIP" ]; then
  echo "Downloading $ZIP from $URL ..."
  curl -L "$URL" -o "$ZIP"
  echo ""
fi

# Unzip the release
if [ ! -d "$DIR" ]; then
  echo "Unzipping $ZIP to .build/$DIR ..."
  cp "$ZIP" "$ZIP.bak"
  unzip -q "$ZIP"
  rm "$ZIP"
  mv "$ZIP.bak" "$ZIP"
  echo ""
fi
cd ..

# Copy the libs to the package directory
echo "Copying libs to GLFW/ ..."
rm -rf GLFW
mkdir -p GLFW
cp -rf ".build/$DIR/include/GLFW"/* GLFW/
cp -rf ".build/$DIR/src/"* GLFW/
echo ""
}


# Test the project
test() {
echo "Running 01-basic-window.c ..."
clang -I. -o 01.exe examples/01-basic-window.c    && ./01.exe && echo -e "\n"
echo "Running 02-input-handling.c ..."
clang -I. -o 02.exe examples/02-input-handling.c    && ./02.exe && echo -e "\n"
echo "Running 03-opengl-rendering.c ..."
clang -I. -I"node_modules/glad.c" -o 03.exe examples/03-opengl-rendering.c  && ./03.exe && echo -e "\n"
}


# Main script
if [[ "$1" == "test" ]]; then test
elif [[ "$1" == "fetch" ]]; then fetch
else echo "Usage: $0 {fetch|test}"; fi
