#!/bin/bash
set -euo pipefail

# Native Linux location (not the Windows mount)
WORK=/tmp/sotc-build
rm -rf "$WORK"
mkdir -p "$WORK"

# Copy everything the build needs (exclude heavy/generated dirs)
rsync -a --exclude='out' --exclude='.python3' --exclude='build' \
         --exclude='.git' /workspace/ "$WORK/"

cd "$WORK"

# Optional: make sure the old compiler is present
# (uncomment / adjust if you have a setup script)
# ./scripts/setup_compiler.sh || true

# Clean + configure + build + test
rm -rf out .python3 build
cmake --preset default
cmake --build out -j$(nproc)
ctest --test-dir out --output-on-failure

# Copy useful artefacts back to the Windows-visible folder
mkdir -p /workspace/out /workspace/build
cp -a out/. /workspace/out/ 2>/dev/null || true
cp -a build/. /workspace/build/ 2>/dev/null || true

echo "Build finished successfully"