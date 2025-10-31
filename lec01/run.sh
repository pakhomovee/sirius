#!/usr/bin/env bash
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "$SCRIPT_DIR"

if [[ $# -lt 1 ]]; then
  echo "Usage: ./run.sh <number> [program-args...]" 1>&2
  exit 1
fi

raw="$1"
shift || true
padded="$(printf "%02d" "$raw" 2>/dev/null || echo "$raw")"

file=""
for cand in "$raw" "$padded"; do
  for ext in cpp c; do
    for f in "$SCRIPT_DIR"/examples/${cand}_*.${ext}; do
      if [[ -f "$f" ]]; then
        file="$f"
        break 3
      fi
    done
  done
done

if [[ -z "$file" ]]; then
  echo "Error: example for number '$raw' not found under examples/." 1>&2
  exit 2
fi

ext="${file##*.}"
base="$(basename "$file")"
name="${base%.*}"
bin_dir="$SCRIPT_DIR/.bin"
mkdir -p "$bin_dir"
out="$bin_dir/$name"

echo "[build] $base -> ${out}"
if [[ "$ext" == "cpp" ]]; then
  g++ -std=gnu++17 -O2 -Wall -Wextra -pedantic "$file" -o "$out"
elif [[ "$ext" == "c" ]]; then
  cc -std=c11 -O2 -Wall -Wextra -pedantic "$file" -o "$out"
else
  echo "Error: unsupported extension: .$ext" 1>&2
  exit 3
fi

echo "[run] ./${name}" "$@"
"$out" "$@"


